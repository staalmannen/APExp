
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

Pbase short_type = 0;
Pbase int_type = 0;
Pbase char_type = 0;
Pbase long_type = 0;
Pbase llong_type = 0;

Pbase uchar_type = 0;
Pbase ushort_type = 0;
Pbase uint_type = 0;
Pbase ulong_type = 0;
Pbase ullong_type = 0;

Pbase zero_type = 0;
Pbase float_type = 0;
Pbase double_type = 0;
Pbase ldouble_type = 0;
Pbase void_type = 0;
Pbase any_type = 0;

Ptype Pint_type = 0;
Ptype Pchar_type = 0;
Ptype Pvoid_type = 0;
Ptype Pfctvec_type = 0;

Ptable gtbl = 0;
Ptable ptbl = 0;

Pname Cdcl = 0;
Pstmt Cstmt = 0;

bit new_type = 0;

Pclass classtype__4typeFv(register struct type *__0this) {
    unsigned long __2__X18;

    {
        struct ea __0__V17;

        return ((__0this->base__4node == 119)
                    ? (((struct classdef *)((
                          (struct classdef *)(((struct basetype *)(((struct basetype *)__0this))))
                              ->b_name__8basetype->__O1__4expr.tp))))
                    : (error__FiPCcRC2eaN33(
                           (int)'i', (const char *)"T::classtype(): %k cobjX",
                           (const struct ea *)((__2__X18 = __0this->base__4node),
                                               (((((&__0__V17)->__O1__2ea.i = __2__X18), 0)),
                                                (&__0__V17))),
                           (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0),
                       (((struct classdef *)0))));
    }
}

Pbase arit_conv__8basetypeFP8basetype(struct basetype *__0this, Pbase);

extern int error__FPCcRC2eaN32(const char *, const struct ea *, const struct ea *,
                               const struct ea *, const struct ea *);

bit check__4typeFP4typeUcT2(struct type *__0this, Ptype, TOK, bit);

Pptr is_ptr__4typeFv(struct type *__0this);

bit baseof__8classdefFP8classdef(struct classdef *__0this, Pclass);

Pname is_cl_obj__4typeFv(struct type *__0this);

extern int error__FPCc(const char *);

Pfct memptr__4typeFv(struct type *__0this);

Ptype np_promote__FUcN21P4typeT4N21(TOK __1oper, TOK __1r1, TOK __1r2, Ptype __1t1, Ptype __1t2,
                                    TOK __1p, bit __1perr) {
    if (__1r2 == 'A')
        return __1t1;

    switch (__1r1) {
    case 'A':
        return __1t2;
    case 'Z':
        switch (__1oper) {
        case 130:
        case 131:
        case 132:
        case 134:
        case 135:
        case 126:
        case 127:
            return (struct type *)any_type;
        }
        switch (__1r2) {
        case 'Z':
            return (struct type *)int_type;
        case 'F':
            switch (__1oper) {
            case 53:
            case 52:
            case 64:
            case 65:
            case 56:
            case 57:
                return (struct type *)any_type;
            }

        case 'I':
            switch (__1oper) {
            case 111:
                return (struct type *)any_type;
            case 56:
            case 57:
                return (struct type *)int_type;
            }
            return (struct type *)(__1p ? arit_conv__8basetypeFP8basetype(
                                              ((struct basetype *)(((
                                                  struct basetype *)skiptypedefs__4typeFv(__1t2)))),
                                              (struct basetype *)0)
                                        : (((struct basetype *)0)));

        case 'P':
            switch (__1oper) {
            case 53:
            case 52:
            case 64:
            case 65:
            case 56:
            case 57:
            case 61:
            case 60:
            case 59:
            case 58:
                return (struct type *)any_type;
            case 54:
            case 126:
                if (__1t2 != Pvoid_type)
                    break;
            case 62:
            case 63:
            case 68:
                break;
            default:
                return (struct type *)any_type;
            }
            return __1t2;
        case 108:
            switch (__1oper) {
            case 68:
                return (struct type *)any_type;
            case 62:
            case 63:
                return __1t2;
            }
            if (__1perr) {
                struct ea __0__V19;

                error__FPCcRC2eaN32(
                    (const char *)"zero%kF",
                    (const struct ea *)(((((&__0__V19)->__O1__2ea.i = ((unsigned long)__1oper)),
                                          0)),
                                        (&__0__V19)),
                    (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
            }
            return (struct type *)any_type;
        default: {
            struct ea __0__V20;

            error__FiPCcRC2eaN33(
                (int)'i', (const char *)"zero(%d)",
                (const struct ea *)(((((&__0__V20)->__O1__2ea.i = ((unsigned long)__1r2)), 0)),
                                    (&__0__V20)),
                (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
        }
        }
    case 'I':
        switch (__1r2) {
        case 'Z':
            __1t2 = 0;
            switch (__1oper) {
            case 111:
                return (struct type *)any_type;
            }
            return (struct type *)(__1p ? arit_conv__8basetypeFP8basetype(
                                              ((struct basetype *)(((
                                                  struct basetype *)skiptypedefs__4typeFv(__1t1)))),
                                              ((struct basetype *)(((struct basetype *)__1t2))))
                                        : (((struct basetype *)0)));

        case 'F':
            switch (__1oper) {
            case 53:
            case 52:
            case 64:
            case 65:
            case 56:
            case 57:
            case 130:
            case 131:
            case 132:
            case 134:
            case 135:
                return (struct type *)any_type;
            }

        case 'I':
            switch (__1oper) {
            case 111:
                return (struct type *)any_type;
            case 56:
            case 57:
                return (
                    struct type *)(__1p ? arit_conv__8basetypeFP8basetype(
                                              ((struct basetype *)(((
                                                  struct basetype *)skiptypedefs__4typeFv(__1t1)))),
                                              ((struct basetype *)0))
                                        : (((struct basetype *)0)));
            }
            return (struct type *)(__1p ? arit_conv__8basetypeFP8basetype(
                                              ((struct basetype *)(((
                                                  struct basetype *)skiptypedefs__4typeFv(__1t1)))),
                                              ((struct basetype *)(((struct basetype *)__1t2))))
                                        : (((struct basetype *)0)));

        case 'P':
            switch (__1oper) {
            case 111:
                break;
            case 54:
            case 126:
                if (__1t2 != Pvoid_type)
                    break;
            default:
                if (__1perr) {
                    struct ea __0__V21;

                    error__FPCcRC2eaN32(
                        (const char *)"int%kP",
                        (const struct ea *)(((((&__0__V21)->__O1__2ea.i = ((unsigned long)__1oper)),
                                              0)),
                                            (&__0__V21)),
                        (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
                }
                return (struct type *)any_type;
            }
            return __1t2;
        case 108:
            if (__1perr) {
                struct ea __0__V22;

                error__FPCcRC2eaN32(
                    (const char *)"int%kF",
                    (const struct ea *)(((((&__0__V22)->__O1__2ea.i = ((unsigned long)__1oper)),
                                          0)),
                                        (&__0__V22)),
                    (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
            }
            return (struct type *)any_type;
        default: {
            struct ea __0__V23;

            error__FiPCcRC2eaN33(
                (int)'i', (const char *)"int(%d)",
                (const struct ea *)(((((&__0__V23)->__O1__2ea.i = ((unsigned long)__1r2)), 0)),
                                    (&__0__V23)),
                (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
            return (struct type *)any_type;
        }
        }
    case 'F':
        switch (__1oper) {
        case 53:
        case 130:
        case 52:
        case 64:
        case 65:
        case 131:
        case 132:
        case 56:
        case 57:
        case 134:
        case 135:
            return (struct type *)any_type;
        }
        switch (__1r2) {
        case 'Z':
            __1t2 = 0;
        case 'I':
        case 'F':
            if (__1oper == 111)
                return (struct type *)any_type;
            return (struct type *)(__1p ? arit_conv__8basetypeFP8basetype(
                                              ((struct basetype *)(((
                                                  struct basetype *)skiptypedefs__4typeFv(__1t1)))),
                                              ((struct basetype *)(((struct basetype *)__1t2))))
                                        : (((struct basetype *)0)));

        case 'P':
            if (__1perr) {
                struct ea __0__V24;

                error__FPCcRC2eaN32(
                    (const char *)"float%kP",
                    (const struct ea *)(((((&__0__V24)->__O1__2ea.i = ((unsigned long)__1oper)),
                                          0)),
                                        (&__0__V24)),
                    (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
            }
            return (struct type *)any_type;
        case 108:
            if (__1perr) {
                struct ea __0__V25;

                error__FPCcRC2eaN32(
                    (const char *)"float%kF",
                    (const struct ea *)(((((&__0__V25)->__O1__2ea.i = ((unsigned long)__1oper)),
                                          0)),
                                        (&__0__V25)),
                    (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
            }
            return (struct type *)any_type;
        default: {
            struct ea __0__V26;

            error__FiPCcRC2eaN33(
                (int)'i', (const char *)"float(%d)",
                (const struct ea *)(((((&__0__V26)->__O1__2ea.i = ((unsigned long)__1r2)), 0)),
                                    (&__0__V26)),
                (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
            return (struct type *)any_type;
        }
        }
    case 'P':
        switch (__1oper) {
        case 56:
        case 57:
        case 134:
        case 135:
        case 53:
        case 130:
        case 64:
        case 65:
        case 132:
        case 52:
        case 131:
        case 51:
        case 50:
            return (struct type *)any_type;
        }
        switch (__1r2) {
        case 'Z':
            switch (__1oper) {
            case 61:
            case 60:
            case 59:
            case 58:
                return (struct type *)any_type;
            }
            return __1t1;
        case 'I':
            switch (__1oper) {
            case 111:
            case 54:
            case 55:
            case 126:
            case 127:
                if (check__4typeFP4typeUcT2(__1t1, Pvoid_type, (unsigned char)0,
                                            (unsigned char)0) == 0) {
                    return (struct type *)any_type;
                }
                break;
            default:
                if (__1perr) {
                    struct ea __0__V27;

                    error__FPCcRC2eaN32(
                        (const char *)"P%k int",
                        (const struct ea *)(((((&__0__V27)->__O1__2ea.i = ((unsigned long)__1oper)),
                                              0)),
                                            (&__0__V27)),
                        (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
                }
                return (struct type *)any_type;
            }
            return __1t1;
        case 'F':
            if (__1perr) {
                struct ea __0__V28;

                error__FPCcRC2eaN32(
                    (const char *)"P%k float",
                    (const struct ea *)(((((&__0__V28)->__O1__2ea.i = ((unsigned long)__1oper)),
                                          0)),
                                        (&__0__V28)),
                    (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
            }
            return (struct type *)any_type;
        case 'P':
            if (check__4typeFP4typeUcT2(__1t1, __1t2, (unsigned char)70, (unsigned char)0)) {
                Ptype __4tt1;
                Ptype __4tt2;

                __4tt1 = skiptypedefs__4typeFv(is_ptr__4typeFv(__1t1)->typ__5pvtyp);
                __4tt2 = skiptypedefs__4typeFv(is_ptr__4typeFv(__1t2)->typ__5pvtyp);
                switch (__1oper) {
                case 62:
                case 63:
                case 59:
                case 61:
                case 60:
                case 58:
                case 55:
                case 68:
                    if (((__4tt1 && __4tt2) && (__4tt1->base__4node == 119)) &&
                        (__4tt2->base__4node == 119)) {
                        Pclass __6c1;
                        Pclass __6c2;

                        __6c1 = classtype__4typeFv(__4tt1);
                        __6c2 = classtype__4typeFv(__4tt2);
                        if (((__6c1 && __6c2) && baseof__8classdefFP8classdef(__6c1, __6c2)) ||
                            baseof__8classdefFP8classdef(__6c2, __6c1))
                            goto zz;
                    }
                    if (check__4typeFP4typeUcT2(__1t2, __1t1, (unsigned char)70,
                                                (unsigned char)0) == 0) {
                        if (__1oper == 68)
                            return __1t2;
                        goto zz;
                    }
                    break;
                case 180: {
                    Pname __6cn;

                    struct classdef *__1__X39;

                    struct classdef *__1__X40;

                    __6cn = is_cl_obj__4typeFv(__4tt1);
                    if ((__6cn && (__4tt2->base__4node == 108)) &&
                        ((__1__X39 =
                              (((struct classdef *)(((struct classdef *)__6cn->__O1__4expr.tp))))),
                         ((__1__X40 = (((struct fct *)(((struct fct *)__4tt2))))->memof__3fct),
                          (((__1__X39 == __1__X40)
                                ? 1
                                : ((__1__X39 && __1__X40)
                                       ? (((int)same_class__8classdefFP8classdefi(__1__X39,
                                                                                  __1__X40, 0)))
                                       : 0))))))
                        return __1t2;
                }
                }
                if (__1perr) {
                    struct ea __0__V29;

                    struct ea __0__V30;

                    struct ea __0__V31;

                    error__FPCcRC2eaN32(
                        (const char *)"T mismatch:%t %k%t",
                        (const struct ea *)(((&__0__V29)->__O1__2ea.p = ((const void *)__1t1)),
                                            (&__0__V29)),
                        (const struct ea *)(((((&__0__V30)->__O1__2ea.i = ((unsigned long)__1oper)),
                                              0)),
                                            (&__0__V30)),
                        (const struct ea *)(((&__0__V31)->__O1__2ea.p = ((const void *)__1t2)),
                                            (&__0__V31)),
                        (const struct ea *)ea0);
                }
                return (struct type *)any_type;
            }
        zz:
            switch (__1oper) {
            case 55:
                return (struct type *)((__1t2 != Pvoid_type) ? int_type : any_type);

            case 127:
                if (__1perr)
                    error__FPCc((const char *)"P -=P");
                return (struct type *)any_type;
            case 54:
                if (__1perr)
                    error__FPCc((const char *)"P +P");
                return (struct type *)any_type;
            case 126:
                if (__1perr)
                    error__FPCc((const char *)"P +=P");
                return (struct type *)any_type;
            case 53:
            case 130:
            case 52:
            case 64:
            case 65:
            case 131:
            case 132:
            case 134:
            case 135:
            case 56:
            case 57:
            case 111:
                return (struct type *)any_type;
            default:
                return __1t1;
            }
        case 108:
            return __1t1;
        default: {
            struct ea __0__V32;

            error__FiPCcRC2eaN33(
                (int)'i', (const char *)"P(%d)",
                (const struct ea *)(((((&__0__V32)->__O1__2ea.i = ((unsigned long)__1r2)), 0)),
                                    (&__0__V32)),
                (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
        }
        }
    case 108:
        if (__1oper == 68) {
            switch (__1r2) {
            case 'Z':
                return (struct type *)any_type;
            case 'P':
                return __1t2;
            case 'I':
            case 'F':
                if (__1perr) {
                    struct ea __0__V33;

                    struct ea __0__V34;

                    error__FPCcRC2eaN32(
                        (const char *)"F%k%t",
                        (const struct ea *)(((((&__0__V33)->__O1__2ea.i = ((unsigned long)__1oper)),
                                              0)),
                                            (&__0__V33)),
                        (const struct ea *)(((&__0__V34)->__O1__2ea.p = ((const void *)__1t2)),
                                            (&__0__V34)),
                        (const struct ea *)ea0, (const struct ea *)ea0);
                }
            default:
                return __1t1;
            }
        }
        if (((((struct fct *)(((struct fct *)__1t1))))->memof__3fct && (__1r2 == 'P')) &&
            memptr__4typeFv(__1t2))
            return __1t2;
        if (((__1oper == 62) || (__1oper == 63)) && (__1r2 == 'Z'))
            return __1t1;
        if (__1perr) {
            struct ea __0__V35;

            struct ea __0__V36;

            error__FPCcRC2eaN32(
                (const char *)"F%k%t",
                (const struct ea *)(((((&__0__V35)->__O1__2ea.i = ((unsigned long)__1oper)), 0)),
                                    (&__0__V35)),
                (const struct ea *)(((&__0__V36)->__O1__2ea.p = ((const void *)__1t2)),
                                    (&__0__V36)),
                (const struct ea *)ea0, (const struct ea *)ea0);
        }
        return (struct type *)any_type;
    default: {
        struct ea __0__V37;

        struct ea __0__V38;

        error__FiPCcRC2eaN33(
            (int)'i', (const char *)"np_promote(%d,%d)",
            (const struct ea *)(((((&__0__V37)->__O1__2ea.i = ((unsigned long)__1r1)), 0)),
                                (&__0__V37)),
            (const struct ea *)(((((&__0__V38)->__O1__2ea.i = ((unsigned long)__1r2)), 0)),
                                (&__0__V38)),
            (const struct ea *)ea0, (const struct ea *)ea0);
        return (struct type *)0;
    }
    }
}

int tsizeof__4typeFi(struct type *__0this, int);

TOK kind__4typeFUcN21(register struct type *__0this, TOK __1oper, TOK __1v, bit __1perr) {
    Ptype __1t;

    __1t = __0this;
    if (__0this == 0)
        error__FiPCc((int)'i', (const char *)"type::kind(): this==0");

    __1t = skiptypedefs__4typeFv(__1t);

    switch (__1t->base__4node) {
        unsigned long __2__X54;

    case 141:
        return (unsigned char)'A';
    case 138:
        return (unsigned char)'Z';
    case 114:
    case 5:
    case 29:
    case 21:
    case 22:
    case 122:
    case 121:
        return (unsigned char)'I';
    case 15:
    case 181:
    case 11:
        if (__1v == 'I')
            if (__1perr) {
                struct ea __0__V41;

                error__FPCcRC2eaN32(
                    (const char *)"float operand for %k",
                    (const struct ea *)(((((&__0__V41)->__O1__2ea.i = ((unsigned long)__1oper)),
                                          0)),
                                        (&__0__V41)),
                    (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
            }
        return (unsigned char)'F';
    case 110:
    case 125:
        if (__1v != 'P')
            if (__1perr) {
                struct ea __0__V42;

                error__FPCcRC2eaN32(
                    (const char *)"P operand for %k",
                    (const struct ea *)(((((&__0__V42)->__O1__2ea.i = ((unsigned long)__1oper)),
                                          0)),
                                        (&__0__V42)),
                    (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
            }
        switch (__1oper) {
        case 48:
        case 49:
        case 55:
        case 54:
        case 127:
        case 126:
            if ((__1t->base__4node == 125) &&
                ((((struct ptr *)(((struct ptr *)__1t))))->memof__3ptr ||
                 ((((struct ptr *)(((struct ptr *)__1t))))->typ__5pvtyp->base__4node == 108))) {
                if (__1perr) {
                    struct ea __0__V43;

                    struct ea __0__V44;

                    error__FPCcRC2eaN32(
                        (const char *)"%t operand of%k",
                        (const struct ea *)(((&__0__V43)->__O1__2ea.p = ((const void *)__0this)),
                                            (&__0__V43)),
                        (const struct ea *)(((((&__0__V44)->__O1__2ea.i = ((unsigned long)__1oper)),
                                              0)),
                                            (&__0__V44)),
                        (const struct ea *)ea0, (const struct ea *)ea0);
                }
            } else {
                tsizeof__4typeFi((((struct ptr *)(((struct ptr *)__1t))))->typ__5pvtyp, 0);
            }
            break;
        default:
            if ((__1t->base__4node == 125) &&
                ((((struct ptr *)(((struct ptr *)__1t))))->memof__3ptr ||
                 ((((struct ptr *)(((struct ptr *)__1t))))->typ__5pvtyp->base__4node == 108)))
                if (__1perr) {
                    struct ea __0__V45;

                    struct ea __0__V46;

                    error__FPCcRC2eaN32(
                        (const char *)"%t operand of%k",
                        (const struct ea *)(((&__0__V45)->__O1__2ea.p = ((const void *)__0this)),
                                            (&__0__V45)),
                        (const struct ea *)(((((&__0__V46)->__O1__2ea.i = ((unsigned long)__1oper)),
                                              0)),
                                            (&__0__V46)),
                        (const struct ea *)ea0, (const struct ea *)ea0);
                }
        case 58:
        case 59:
        case 60:
        case 61:
        case 66:
        case 67:
        case 70:
        case 63:
        case 62:
        case 20:
        case 39:
        case 10:
        case 16:
        case 68:
        case 46:
            break;
        }
        return (unsigned char)'P';
    case 158:
        if (__1perr) {
            struct ea __0__V47;

            error__FPCcRC2eaN32(
                (const char *)"R operand for %k",
                (const struct ea *)(((((&__0__V47)->__O1__2ea.i = ((unsigned long)__1oper)), 0)),
                                    (&__0__V47)),
                (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
        }
        return (unsigned char)'A';
    case 108:
        if (__1v != 'P')
            if (__1perr) {
                struct ea __0__V48;

                error__FPCcRC2eaN32(
                    (const char *)"F operand for %k",
                    (const struct ea *)(((((&__0__V48)->__O1__2ea.i = ((unsigned long)__1oper)),
                                          0)),
                                        (&__0__V48)),
                    (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
            }
        return (unsigned char)108;
    case 76:
        if (__1perr) {
            struct ea __0__V49;

            error__FPCcRC2eaN32(
                (const char *)"overloaded operand for %k",
                (const struct ea *)(((((&__0__V49)->__O1__2ea.i = ((unsigned long)__1oper)), 0)),
                                    (&__0__V49)),
                (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
        }
        return (unsigned char)'A';
    case 6:
    case 13:
        if (__1perr) {
            struct ea __0__V50;

            struct ea __0__V51;

            error__FPCcRC2eaN32(
                (const char *)"%k operand for %k",
                (const struct ea *)((__2__X54 = __0this->base__4node),
                                    (((((&__0__V50)->__O1__2ea.i = __2__X54), 0)), (&__0__V50))),
                (const struct ea *)(((((&__0__V51)->__O1__2ea.i = ((unsigned long)__1oper)), 0)),
                                    (&__0__V51)),
                (const struct ea *)ea0, (const struct ea *)ea0);
        }
        return (unsigned char)'A';
    default:
        if (__1perr) {
            struct ea __0__V52;

            struct ea __0__V53;

            error__FPCcRC2eaN32(
                (const char *)"%t operand for %k",
                (const struct ea *)(((&__0__V52)->__O1__2ea.p = ((const void *)__0this)),
                                    (&__0__V52)),
                (const struct ea *)(((((&__0__V53)->__O1__2ea.i = ((unsigned long)__1oper)), 0)),
                                    (&__0__V53)),
                (const struct ea *)ea0, (const struct ea *)ea0);
        }
        return (unsigned char)'A';
    }
}

Pexpr typ__4exprFP5table(struct expr *__0this, Ptable);

extern Pexpr check_cond__FP4exprUcP5table(Pexpr, TOK, Ptable);

long long eval__4exprFv(struct expr *__0this);

void del__4exprFv(struct expr *__0this);

extern void dargs__FP4nameP3fctP5table(Pname, Pfct, Ptable);

void dcl__4typeFP5table(struct type *__0this, Ptable __1tbl);

extern void make_res__FP3fct(Pfct);

void dcl__4typeFP5table(register struct type *__0this, Ptable __1tbl) {
    Ptype __1t;

    int __1os;

    unsigned long __2__X60;

    __1t = __0this;

    __1os = processing_sizeof;
    processing_sizeof = 0;

    if (__0this == 0)
        error__FiPCc((int)'i', (const char *)"T::dcl(this==0)");
    if (__1tbl->base__4node != 142) {
        struct ea __0__V55;

        error__FiPCcRC2eaN33(
            (int)'i', (const char *)"T::dcl(%d)",
            (const struct ea *)((__2__X60 = __1tbl->base__4node),
                                (((((&__0__V55)->__O1__2ea.i = __2__X60), 0)), (&__0__V55))),
            (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
    }
xx:
    switch (__1t->base__4node) {
    case 97:
        __1t =
            (((struct basetype *)(((struct basetype *)__1t))))->b_name__8basetype->__O1__4expr.tp;
        goto xx;
    case 125:
    case 158: {
        Pptr __3p;

        __3p = (((struct ptr *)(((struct ptr *)__1t))));
        if ((__3p->memof__3ptr == 0) && __3p->ptname__3ptr) {
            Ptype __4tp;

            __4tp = skiptypedefs__4typeFv(__3p->ptname__3ptr->__O1__4expr.tp);
            switch (__4tp->base__4node) {
            case 119: {
                __3p->memof__3ptr = classtype__4typeFv(__4tp);
                if (__3p->typ__5pvtyp) {
                    Ptype __7t;

                    __7t = skiptypedefs__4typeFv(__3p->typ__5pvtyp);
                    if (__7t && (__7t->base__4node == 108)) {
                        (((struct fct *)(((struct fct *)__7t))))->memof__3fct = __3p->memof__3ptr;
                    }
                }
                break;
            }
            case 6: {
                __3p->memof__3ptr = (((struct classdef *)(((struct classdef *)__4tp))));
                {
                    Ptype __6t;
                    Pfct __6f;

                    __6t = skiptypedefs__4typeFv(__3p->typ__5pvtyp);
                    __6f = (((struct fct *)(((struct fct *)__6t))));
                    __6f->memof__3fct = __3p->memof__3ptr;
                    break;
                }
            }
            default: {
                struct ea __0__V56;

                error__FPCcRC2eaN32(
                    (const char *)"illegalZizedP toM %t::*",
                    (const struct ea *)(((&__0__V56)->__O1__2ea.p = ((const void *)__4tp)),
                                        (&__0__V56)),
                    (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
                break;
            }
            }
        }
        __1t = __3p->typ__5pvtyp;
        if (__1t->base__4node == 97) {
            Ptype __4tt;

            __4tt = (((struct basetype *)(((struct basetype *)__1t))))
                        ->b_name__8basetype->__O1__4expr.tp;
            if (__4tt->base__4node == 108)
                __3p->typ__5pvtyp = __4tt;
            goto done;
        }
        goto xx;
    }

    case 110: {
        Pvec __3v;
        Pexpr __3e;

        __3v = (((struct vec *)(((struct vec *)__1t))));
        __3e = __3v->dim__3vec;
        if (__3e) {
            Ptype __4et;
            __3v->dim__3vec = (__3e = typ__4exprFP5table(__3e, __1tbl));
            if (skiptypedefs__4typeFv(__3e->__O1__4expr.tp)->base__4node == 119) {
                __3e = check_cond__FP4exprUcP5table(__3e, (unsigned char)111, __1tbl);
                __3v->dim__3vec = __3e;
            }
            __4et = __3e->__O1__4expr.tp;
            if ((kind__4typeFUcN21(__4et, ((unsigned char)0), (unsigned char)'I',
                                   (unsigned char)1)) == 'A') {
                error__FPCc((const char *)"UN in array dimension");
            } else {
                long long __5i;
                Neval = 0;
                __5i = eval__4exprFv(__3e);
                if (Neval == 0) {
                    if (largest_int < __5i)
                        error__FPCc((const char *)"array dimension too large");

                    __3v->size__3vec = (((int)__5i));

                    if (__3v->dim__3vec && (__3v->dim__3vec->permanent__4node == 0))
                        del__4exprFv(__3v->dim__3vec);
                    __3v->dim__3vec = 0;
                }

                if (new_type) {
                    if (Neval)
                        ;
                    else if (__5i == 0)
                        __3v->dim__3vec = zero;
                    else if (__5i < 0) {
                        error__FPCc((const char *)"negative array dimension");
                        __5i = 1;
                    }
                } else {
                    const void *__2__X61;

                    if (Neval) {
                        struct ea __0__V57;

                        error__FPCcRC2eaN32(
                            (const char *)"%s",
                            (const struct ea *)((__2__X61 = (const void *)Neval),
                                                (((&__0__V57)->__O1__2ea.p = __2__X61),
                                                 (&__0__V57))),
                            (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
                    } else if (__5i == 0) {
                        error__FPCc((const char *)"array dimension == 0");

                        __3v->dim__3vec = __3e;
                    } else if (__5i < 0) {
                        error__FPCc((const char *)"negative array dimension");
                        __5i = 1;
                    }
                }
            }
        }
        __1t = __3v->typ__5pvtyp;
    llx:
        switch (__1t->base__4node) {
        case 97:
            __1t = (((struct basetype *)(((struct basetype *)__1t))))
                       ->b_name__8basetype->__O1__4expr.tp;
            goto llx;
        case 108:
            __3v->typ__5pvtyp = __1t;
            break;
        case 110:
            if (((((struct vec *)(((struct vec *)__1t))))->dim__3vec == 0) &&
                ((((struct vec *)(((struct vec *)__1t))))->size__3vec == 0))
                error__FPCc((const char *)"null dimension (something like [][] seen)");
        }
        goto xx;
    }

    case 108: {
        Pfct __3f;

        __3f = (((struct fct *)(((struct fct *)__1t))));

        if (__3f->argtype__3fct)
            dargs__FP4nameP3fctP5table((struct name *)0, __3f, __1tbl);
        {
            {
                Pname __3n;

                __3n = __3f->argtype__3fct;

                for (; __3n; __3n = __3n->__O1__4name.n_list) {
                    Ptype __4t;

                    __4t = __3n->__O1__4expr.tp;
                    dcl__4typeFP5table(__3n->__O1__4expr.tp, __1tbl);
                    while (__4t->base__4node == 97)
                        __4t = (((struct basetype *)(((struct basetype *)__4t))))
                                   ->b_name__8basetype->__O1__4expr.tp;
                    if (__4t->base__4node == 110)
                        __3n->__O1__4expr.tp = (struct type *)__ct__3ptrFUcP4type(
                            (struct ptr *)0, (unsigned char)125,
                            (((struct vec *)(((struct vec *)__4t))))->typ__5pvtyp);
                }
                {
                    Pname __3cn;

                    struct classdef *__0__X62;

                    __3cn = is_cl_obj__4typeFv(__3f->returns__3fct);
                    if (__3cn &&
                        ((__0__X62 =
                              (((struct classdef *)(((struct classdef *)__3cn->__O1__4expr.tp))))),
                         (__0__X62->c_itor__8classdef)))
                        make_res__FP3fct(__3f);
                    else if (__3f->f_this__3fct == 0)
                        __3f->f_args__3fct = __3f->argtype__3fct;

                    __1t = __3f->returns__3fct;
                    goto xx;
                }
            }
        }
    }

    case 114: {
        Pbase __3f;
        Pexpr __3e;
        long long __3i;
        Ptype __3et;

        __3f = (((struct basetype *)(((struct basetype *)__1t))));
        __3e = (((struct expr *)(((struct expr *)__3f->b_name__8basetype))));

        __3e = typ__4exprFP5table(__3e, __1tbl);
        __3f->b_name__8basetype = (((struct name *)(((struct name *)__3e))));
        __3et = __3e->__O1__4expr.tp;
        if ((kind__4typeFUcN21(__3et, ((unsigned char)0), (unsigned char)'I', (unsigned char)1)) ==
            'A') {
            error__FPCc((const char *)"UN in field size");
            __3i = 1;
        } else {
            const void *__2__X63;

            const void *__2__X64;

            Neval = 0;
            __3i = eval__4exprFv(__3e);
            if (Neval) {
                struct ea __0__V58;

                error__FPCcRC2eaN32(
                    (const char *)"%s",
                    (const struct ea *)((__2__X63 = (const void *)Neval),
                                        (((&__0__V58)->__O1__2ea.p = __2__X63), (&__0__V58))),
                    (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
            } else if (__3i < 0) {
                error__FPCc((const char *)"negative field size");

                __3i = 1;
            } else if ((tsizeof__4typeFi(__3f->__O1__8basetype.b_fieldtype, 0) * BI_IN_BYTE) <
                       __3i) {
                struct ea __0__V59;

                error__FPCcRC2eaN32(
                    (const char *)"field size > sizeof(%t)",
                    (const struct ea *)((__2__X64 =
                                             (const void *)__3f->__O1__8basetype.b_fieldtype),
                                        (((&__0__V59)->__O1__2ea.p = __2__X64), (&__0__V59))),
                    (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
            }
            if (__3e && (__3e->permanent__4node == 0))
                del__4exprFv(__3e);
        }
        __3f->b_bits__8basetype = (((int)__3i));
        __3f->b_name__8basetype = 0;
        break;
    }
    }
done:
    processing_sizeof = __1os;
    return;
}

extern int strcmp(const char *, const char *);

static bit fm_same_class__FP8classdefT1(Pclass __1c1, Pclass __1c2) {
    struct classdef *__1__X65;

    struct classdef *__1__X66;

    if (((__1__X65 = __1c1),
         ((__1__X66 = __1c2),
          (((__1__X65 == __1__X66)
                ? 1
                : ((__1__X65 && __1__X66)
                       ? (((int)same_class__8classdefFP8classdefi(__1__X65, __1__X66, 0)))
                       : 0))))))
        return (unsigned char)1;

    {
        int __1t1;
        int __1t2;

        __1t1 = __1c1->class_base__8classdef;
        __1t2 = __1c2->class_base__8classdef;

        if ((((__1t1 == 5) || (__1t1 == 2)) && ((__1t2 == 5) || (__1t2 == 2))) &&
            (strcmp(__1c1->string__8classdef, __1c2->string__8classdef) == 0))
            return (unsigned char)1;

        return (unsigned char)0;
    }
}

bit const_problem = 0;
bit return_error = 0;
static bit pt_ptm;
static bit pt_over;
int Vcheckerror = 0;
extern int template_hier;

Ptype skiptypedefs__4typeFRUc(struct type *__0this, bit *__1isconst);

Pptr is_ref__4typeFv(struct type *__0this);

Pptr is_ptr_or_ref__4typeFv(struct type *__0this);

bit has_base__8classdefFP8classdefiT2(struct classdef *__0this, Pclass __1cl, int __1level,
                                      int __1ccflag);

Pclass is_base__8classdefFPCcPUci(struct classdef *__0this, const char *, TOK *, int __1level);

bit check__4typeFP4typeUcT2(register struct type *__0this, Ptype __1t, TOK __1oper, bit __1level) {
    Ptype __1t1;

    Ptype __1t2;
    bit __1cnst1;

    bit __1cnst2;
    TOK __1b1;

    TOK __1b2;
    bit __1vv;

    bit __1over;

    bit __1strict_any_check;
    TOK __1rec_oper;

    TOK __1rec_oper0;

    __1t1 = __0this;

    __1t2 = __1t;
    __1cnst1 = 0;

    __1cnst2 = 0;

    __1vv = 0;

    __1over = 0;

    __1strict_any_check = 0;

    if ((__1t1 == 0) || (__1t2 == 0)) {
        struct ea __0__V67;

        struct ea __0__V68;

        struct ea __0__V69;

        error__FiPCcRC2eaN33(
            (int)'i', (const char *)"check(%p,%p,%d)",
            (const struct ea *)(((&__0__V67)->__O1__2ea.p = ((const void *)__1t1)), (&__0__V67)),
            (const struct ea *)(((&__0__V68)->__O1__2ea.p = ((const void *)__1t2)), (&__0__V68)),
            (const struct ea *)(((((&__0__V69)->__O1__2ea.i = ((unsigned long)__1oper)), 0)),
                                (&__0__V69)),
            (const struct ea *)ea0);
    }
    if (__1t1 == __1t2)
        return (unsigned char)0;

    switch (__1oper) {
    case 77:
        __1vv = 1;
        Vcheckerror = 0;
        __1oper = 0;
        break;
    case 76:
        __1over = 1;
        __1oper = 0;
        break;
    case 204:
        __1over = 1;

    case 255:
        __1oper = 0;
        __1strict_any_check = 1;
        break;
    }

    if (__1level == 0) {
        const_problem = 0;
        return_error = 0;
        pt_ptm = 0;
        pt_over = __1over;
    }

    __1rec_oper =
        (__1strict_any_check ? (((unsigned int)(__1over ? 204 : 255))) : (((unsigned int)__1oper)));
    __1rec_oper0 = (__1strict_any_check ? (__1over ? 204 : 255) : 0);

    __1t1 = skiptypedefs__4typeFRUc(__1t1, (bit *)(&__1cnst1));

    if ((__1t1->base__4node == 141) || (__1t2->base__4node == 141))
        if ((__1over == 0) || (__1strict_any_check == 0))
            return (unsigned char)(__1strict_any_check ? (__1t1 != __1t2) : 0);

    __1t2 = skiptypedefs__4typeFRUc(__1t2, (bit *)(&__1cnst2));

    if (__1t1 == __1t2)
        goto const_check;

    __1b1 = __1t1->base__4node;
    __1b2 = __1t2->base__4node;

    if (__1b1 != __1b2) {
        switch (__1b1) {
        case 125:
            switch (__1b2) {
            case 110:
                if (((((__1level > 0) ||
                       (((__1oper == 0) || (__1oper == 254)) && (__1over == 0))) ||
                      (((struct ptr *)(((struct ptr *)__1t1))))->memof__3ptr) ||
                     (((struct ptr *)(((struct ptr *)__1t1))))->ptname__3ptr) ||
                    check__4typeFP4typeUcT2((((struct ptr *)(((struct ptr *)__1t1))))->typ__5pvtyp,
                                            (((struct vec *)(((struct vec *)__1t2))))->typ__5pvtyp,
                                            __1rec_oper, (unsigned char)(__1level + 1)))
                    return (unsigned char)1;

                goto const_check;

            case 108:
                if ((__1level > 0) ||
                    check__4typeFP4typeUcT2((((struct ptr *)(((struct ptr *)__1t1))))->typ__5pvtyp,
                                            __1t2, __1rec_oper, (unsigned char)(__1level + 1)))
                    return (unsigned char)1;
                goto const_check;
            }
            break;

        case 108:
            if (__1b2 == 125) {
                if ((__1level > 0) ||
                    check__4typeFP4typeUcT2(__1t1,
                                            (((struct ptr *)(((struct ptr *)__1t2))))->typ__5pvtyp,
                                            __1rec_oper, (unsigned char)(__1level + 1)))
                    return (unsigned char)1;
                goto const_check;
            }
            break;

        case 110:
            if (__1b2 == 125) {
                if (((((__1level > 0) ||
                       (((__1oper == 0) || (__1oper == 254)) && (__1over == 0))) ||
                      (((struct ptr *)(((struct ptr *)__1t2))))->memof__3ptr) ||
                     (((struct ptr *)(((struct ptr *)__1t2))))->ptname__3ptr) ||
                    check__4typeFP4typeUcT2((((struct vec *)(((struct vec *)__1t1))))->typ__5pvtyp,
                                            (((struct ptr *)(((struct ptr *)__1t2))))->typ__5pvtyp,
                                            __1rec_oper, (unsigned char)(__1level + 1)))
                    return (unsigned char)1;

                goto const_check;
            }
            break;
        }

        if (__1level > 0) {
            if ((((__1oper != 0) && (__1oper != 254)) && (__1b1 == 38)) && (__1level == 1)) {
                if (__1b2 == 108) {
                    Pfct __5f;

                    __5f = (((struct fct *)(((struct fct *)__1t2))));
                    if (__5f->memof__3fct && (__5f->f_static__3fct == 0))
                        return (unsigned char)1;
                }
                goto const_check;
            }
            return (unsigned char)1;
        }

        switch (__1oper) {
        case 0:
        case 254:
            if ((((__1b2 == 138) && (__1b1 == 21)) &&
                 ((((struct basetype *)(((struct basetype *)__1t1))))->b_unsigned__8basetype ==
                  0)) ||
                (((__1b1 == 138) && (__1b2 == 21)) &&
                 ((((struct basetype *)(((struct basetype *)__1t2))))->b_unsigned__8basetype == 0)))
                goto const_check;
            return (unsigned char)1;
        case 136:
        case 70:
        case 28:
        case 78:
            switch (__1b1) {
            case 138:
            case 5:
            case 29:
            case 21:
            case 22:
            case 122:
            case 15:
            case 11:
            case 181:
            case 114:
                switch (__1b2) {
                case 22:
                case 122:
                case 15:
                case 11:
                case 181:
                case 121:
                case 138:
                case 5:
                case 29:
                case 21:
                case 114:
                    if (__1oper == 78)
                        Nstd++;
                    goto const_check;
                }
                return (unsigned char)1;
            case 125:
            case 110:
                if (__1b2 == 138) {
                    if (__1oper == 78)
                        Nstd++;
                    goto const_check;
                }
            case 158:
            case 119:
            case 108:
            case 121:
            default:
                return (unsigned char)1;
            }
        }
        goto const_check;
    }

    switch (__1b1) {
    case 110:
        if (((((struct vec *)(((struct vec *)__1t1))))->size__3vec !=
             (((struct vec *)(((struct vec *)__1t2))))->size__3vec) &&
            ((__1level > 0) ||
             (((((__1oper == 0) || (__1oper == 254)) && (__1strict_any_check == 0)) &&
               (((struct vec *)(((struct vec *)__1t1))))->size__3vec) &&
              (((struct vec *)(((struct vec *)__1t2))))->size__3vec)))
            return (unsigned char)1;

        if (check__4typeFP4typeUcT2((((struct vec *)(((struct vec *)__1t1))))->typ__5pvtyp,
                                    (((struct vec *)(((struct vec *)__1t2))))->typ__5pvtyp,
                                    __1rec_oper, (unsigned char)(__1level + 1)))
            return (unsigned char)1;
        break;

    case 125:
    case 158: {
        Pptr __3p1;
        Pptr __3p2;

        struct classdef *__1__X74;

        struct classdef *__1__X75;

        __3p1 = (((struct ptr *)(((struct ptr *)__1t1))));
        __3p2 = (((struct ptr *)(((struct ptr *)__1t2))));

        if ((__3p1->ptname__3ptr && __3p2->ptname__3ptr) &&
            ((!__3p1->memof__3ptr) || (!__3p2->memof__3ptr)))
            return (unsigned char)1;

        if (!((__1__X74 = __3p1->memof__3ptr),
              ((__1__X75 = __3p2->memof__3ptr),
               (((__1__X74 == __1__X75)
                     ? 1
                     : ((__1__X74 && __1__X75)
                            ? (((int)same_class__8classdefFP8classdefi(__1__X74, __1__X75, 0)))
                            : 0)))))) {
            struct classdef *__1__X76;

            struct classdef *__1__X77;

            struct classdef *__1__X78;

            struct classdef *__1__X79;

            if (((__3p1->memof__3ptr == 0) && __3p1->ptname__3ptr) ||
                ((__3p2->memof__3ptr == 0) && __3p2->ptname__3ptr))
                pt_ptm = 1;
            else if (((__3p1->memof__3ptr == 0) || (__3p2->memof__3ptr == 0)) ||
                     ((baseof__8classdefFP8classdef(__3p1->memof__3ptr, __3p2->memof__3ptr) == 0) &&
                      (((__1__X76 = __3p1->memof__3ptr),
                        ((__1__X77 = __3p2->memof__3ptr),
                         (((__1__X76 == __1__X77)
                               ? 1
                               : ((__1__X76 && __1__X77) ? (((int)same_class__8classdefFP8classdefi(
                                                               __1__X76, __1__X77, 1)))
                                                         : 0))))) == 0)))
                return (unsigned char)1;

            if (((pt_ptm == 0) && ((__1oper == 0) || (__1oper == 254))) &&
                (((__1__X78 = __3p1->memof__3ptr),
                  ((__1__X79 = __3p2->memof__3ptr),
                   (((__1__X78 == __1__X79)
                         ? 1
                         : ((__1__X78 && __1__X79)
                                ? (((int)same_class__8classdefFP8classdefi(__1__X78, __1__X79, 0)))
                                : 0))))) == 0))
                return (unsigned char)1;

            if (__1oper == 78)
                Nstd++;
        }

        if (check__4typeFP4typeUcT2(__3p1->typ__5pvtyp, __3p2->typ__5pvtyp, __1rec_oper,
                                    (unsigned char)(__1level + 1)))
            return (unsigned char)1;

        break;
    }

    case 108: {
        Pfct __3f1;
        Pfct __3f2;
        Pname __3a1;
        Pname __3a2;
        TOK __3k1;
        TOK __3k2;
        int __3n1;
        int __3n2;

        struct classdef *__1__X80;

        struct classdef *__1__X81;

        __3f1 = (((struct fct *)(((struct fct *)__1t1))));
        __3f2 = (((struct fct *)(((struct fct *)__1t2))));
        __3a1 = __3f1->argtype__3fct;
        __3a2 = __3f2->argtype__3fct;
        __3k1 = __3f1->nargs_known__3fct;
        __3k2 = __3f2->nargs_known__3fct;
        __3n1 = __3f1->nargs__3fct;
        __3n2 = __3f2->nargs__3fct;

        if ((!((__1__X80 = __3f1->memof__3fct),
               ((__1__X81 = __3f2->memof__3fct),
                (((__1__X80 == __1__X81)
                      ? 1
                      : ((__1__X80 && __1__X81)
                             ? (((int)same_class__8classdefFP8classdefi(__1__X80, __1__X81, 0)))
                             : 0)))))) &&
            (pt_ptm == 0)) {
            struct classdef *__1__X82;

            struct classdef *__1__X83;

            if ((__3f1->memof__3fct == 0) && __3f2->f_static__3fct)
                goto sss;
            if (__1vv == 0)
                if (((__3f1->memof__3fct == 0) || (__3f2->memof__3fct == 0)) ||
                    (((__1level > 1) || (baseof__8classdefFP8classdef(__3f1->memof__3fct,
                                                                      __3f2->memof__3fct) == 0)) &&
                     (((__1__X82 = __3f1->memof__3fct),
                       ((__1__X83 = __3f2->memof__3fct),
                        (((__1__X82 == __1__X83)
                              ? 1
                              : ((__1__X82 && __1__X83) ? (((int)same_class__8classdefFP8classdefi(
                                                              __1__X82, __1__X83, 0)))
                                                        : 0))))) == 0)))
                    return (unsigned char)1;

            if (__1oper == 78)
                Nstd++;
        sss:;
        }

        if (__3k1 != __3k2)
            return (unsigned char)1;

        if (((__3n1 != __3n2) && __3k1) && __3k2) {
            goto aaa;
        } else if (__3a1 && __3a2) {
            while (__3a1 && __3a2) {
                if (check__4typeFP4typeUcT2(__3a1->__O1__4expr.tp, __3a2->__O1__4expr.tp,
                                            __1rec_oper0, (unsigned char)(__1level + 1)))
                    return (unsigned char)1;
                __3a1 = __3a1->__O1__4name.n_list;
                __3a2 = __3a2->__O1__4name.n_list;
            }
            if (__3a1 || __3a2)
                goto aaa;
        } else if (__3a1 || __3a2) {
        aaa:
            if (__3k1 == 155) {
                switch (__1oper) {
                case 0:
                case 254:
                    if (__3a2 && (__3k2 == 0))
                        break;
                    return (unsigned char)1;
                case 70:
                    if (__3a2 && (__3k2 == 0))
                        break;
                    return (unsigned char)1;
                case 136:
                    if (__3a1)
                        return (unsigned char)1;
                    break;
                case 78:
                    return (unsigned char)1;
                }
            } else if (__3k2 == 155) {
                return (unsigned char)1;
            } else if (__3k1 || __3k2) {
                return (unsigned char)1;
            }
        }

        __1cnst1 = __3f2->f_const__3fct;
        __1cnst2 = __3f1->f_const__3fct;

        if (check__4typeFP4typeUcT2(__3f1->returns__3fct, __3f2->returns__3fct, __1rec_oper0,
                                    (unsigned char)(__1level + 1))) {
            if (__1vv && (__1cnst1 == __1cnst2)) {
                bit __5fail;
                Ptype __5t1;
                Ptype __5t2;

                __5fail = 1;
                __5t1 = __3f1->returns__3fct;
                __5t2 = __3f2->returns__3fct;
                if ((is_ptr__4typeFv(__5t1) && is_ptr__4typeFv(__5t2)) ||
                    (is_ref__4typeFv(__5t1) && is_ref__4typeFv(__5t2))) {
                    __5t1 = (((struct ptr *)(((struct ptr *)is_ptr_or_ref__4typeFv(__5t1)))))
                                ->typ__5pvtyp;
                    __5t2 = (((struct ptr *)(((struct ptr *)is_ptr_or_ref__4typeFv(__5t2)))))
                                ->typ__5pvtyp;
                    if ((!is_ptr_or_ref__4typeFv(__5t1)) && (!is_ptr_or_ref__4typeFv(__5t2))) {
                        __5t1 = skiptypedefs__4typeFv(__5t1);
                        __5t2 = skiptypedefs__4typeFv(__5t2);
                        if ((__5t1->base__4node == 119) && (__5t2->base__4node == 119)) {
                            Pclass __8c1;
                            Pclass __8c2;

                            __8c1 = classtype__4typeFv(__5t1);
                            __8c2 = classtype__4typeFv(__5t2);
                            Nvis = 0;
                            if (has_base__8classdefFP8classdefiT2(__8c2, __8c1, 0, 1) && (!Nvis))
                                __5fail = 0;
                        }
                    }
                }
                if (__5fail)
                    Vcheckerror = 1;
                else
                    break;
            }
            if ((__1rec_oper0 == 204) && (__1level == 0))
                return_error = 1;
            return (unsigned char)1;
        }

        break;
    }

    case 114:
        switch (__1oper) {
        case 0:
        case 254:
        case 136:
            error__FiPCc((int)'i', (const char *)"check field?");
        }
        return (unsigned char)0;

    case 15:
    case 11:
    case 181:
    case 5:
    case 29:
    case 21:
    case 22:
    case 122:
        if ((((struct basetype *)(((struct basetype *)__1t1))))->b_unsigned__8basetype !=
            (((struct basetype *)(((struct basetype *)__1t2))))->b_unsigned__8basetype) {
            if ((__1level > 0) || ((__1oper == 0) || (__1oper == 254)))
                return (unsigned char)1;
            if (__1oper == 78)
                Nstd++;
        }
        goto const_check;

    case 121:
        if ((((struct basetype *)(((struct basetype *)__1t1))))
                ->b_name__8basetype->__O1__4expr.tp !=
            (((struct basetype *)(((struct basetype *)__1t2))))->b_name__8basetype->__O1__4expr.tp)
            return (unsigned char)1;
        goto const_check;

    case 6:
    case 119: {
        Pname __3n1;

        Pname __3n2;
        if (__1b1 == 119) {
            __3n1 = (((struct basetype *)(((struct basetype *)__1t1))))->b_name__8basetype;
            __3n2 = (((struct basetype *)(((struct basetype *)__1t2))))->b_name__8basetype;
            if (__3n1 == __3n2)
                goto const_check;
        }

        {
            extern int is_arg;
            int __3access;

            struct classdef *__1__X84;

            struct classdef *__1__X85;

            __3access = (template_hier || pt_over);
            if (((__1__X84 = (((struct classdef *)((
                      (struct classdef *)((__1b1 == 119) ? __3n1->__O1__4expr.tp : __1t1)))))),
                 ((__1__X85 = (((struct classdef *)((
                       (struct classdef *)((__1b1 == 119) ? __3n2->__O1__4expr.tp : __1t2)))))),
                  (((__1__X84 == __1__X85)
                        ? 1
                        : ((__1__X84 && __1__X85) ? (((int)same_class__8classdefFP8classdefi(
                                                        __1__X84, __1__X85, (__3access || is_arg))))
                                                  : 0))))) ||
                ((__1rec_oper == 204) &&
                 fm_same_class__FP8classdefT1(
                     ((struct classdef *)((
                         (struct classdef *)((__1b1 == 119) ? __3n1->__O1__4expr.tp : __1t1)))),
                     ((struct classdef *)((
                         (struct classdef *)((__1b1 == 119) ? __3n2->__O1__4expr.tp : __1t2)))))))
                goto const_check;

            if (template_hier != 0)
                goto pt_hack;

            switch (__1oper) {
            case 136:
            case 70:
            case 28:
            case 78: {
            pt_hack:
                ppbase = 25;
                if ((__1level <= 1) &&
                    is_base__8classdefFPCcPUci(
                        ((struct classdef *)((
                            (struct classdef *)((__1b1 == 119) ? __3n2->__O1__4expr.tp : __1t2)))),
                        (__1b1 == 119) ? __3n1->__O2__4expr.string
                                       : (((struct classdef *)(((struct classdef *)__1t1))))
                                             ->string__8classdef,
                        (TOK *)0, 0)) {
                    if (ppbase != 25) {
                        const_problem = 0;
                        return (unsigned char)1;
                    }
                    if (__1oper == 78)
                        Nstd++;
                    goto const_check;
                }
            }

            case 0:
            case 254:
                const_problem = 0;
                return (unsigned char)1;
            }

            goto const_check;
        }
    }

    case 138:
    case 38:
        goto const_check;
    default: {
        struct ea __0__V70;

        struct ea __0__V71;

        struct ea __0__V72;

        error__FiPCcRC2eaN33(
            (int)'i', (const char *)"T::check(o=%d %d %d)",
            (const struct ea *)(((((&__0__V70)->__O1__2ea.i = ((unsigned long)__1oper)), 0)),
                                (&__0__V70)),
            (const struct ea *)(((((&__0__V71)->__O1__2ea.i = ((unsigned long)__1b1)), 0)),
                                (&__0__V71)),
            (const struct ea *)(((((&__0__V72)->__O1__2ea.i = ((unsigned long)__1b2)), 0)),
                                (&__0__V72)),
            (const struct ea *)ea0);
    }
    }

const_check:
    if (__1cnst1 == __1cnst2)
        return (unsigned char)0;

    switch (__1oper) {
    case 254:
        return (unsigned char)0;

    case 0:
        const_problem = 1;
        return (unsigned char)1;

    case 70:
    case 78:
    case 136:
    case 28:
        if (__1level > 0) {
            if (__1cnst2)
                const_problem = 1;
            return __1cnst2;
        }
        return (unsigned char)0;
    default: {
        struct ea __0__V73;

        error__FiPCcRC2eaN33(
            (int)'i', (const char *)"oper = %k in type::check()",
            (const struct ea *)(((((&__0__V73)->__O1__2ea.i = ((unsigned long)__1oper)), 0)),
                                (&__0__V73)),
            (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
    }
    }
    return (unsigned char)0;
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
