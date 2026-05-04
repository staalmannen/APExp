
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

extern int chars_in_largest;

extern int chars_in_largestl;

extern int chars_in_largestll;
int largest_int = 0;

extern size_t strlen(const char *);

extern long long str_to_llong__FPCc(const char *);

struct basetype *__ct__8basetypeFUcP4name(struct basetype *__0this, TOK, Pname);

Pbase check__8basetypeFP4name(struct basetype *__0this, Pname);

Pbase type_adj__8basetypeFUc(struct basetype *__0this, TOK);

struct fct *__ct__3fctFP4typeP4nameUc(struct fct *__0this, Ptype, Pname, TOK);

struct table *__ct__5tableFsP5tableP4name(struct table *__0this, short, Ptable, Pname);

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

void typ_init__Fv(void) {
    struct type *__0__X26;

    struct type *__0__X27;

    struct type *__0__X28;

    struct type *__0__X29;

    struct type *__0__X30;

    chars_in_largest = strlen(LARGEST_INT);
    chars_in_largestl = strlen(LARGEST_LONG);
    chars_in_largestll = strlen(LARGEST_LLONG);
    largest_int = (((int)str_to_llong__FPCc(LARGEST_INT)));

    defa_type = __ct__8basetypeFUcP4name((struct basetype *)0, (unsigned char)21, (struct name *)0);
    int_type = __ct__8basetypeFUcP4name((struct basetype *)0, (unsigned char)21, (struct name *)0);

    int_type->permanent__4node = 1;

    int_type->defined__4type = 01;
    defa_type->permanent__4node = 1;

    defa_type->defined__4type = 01;

    moe_type = __ct__8basetypeFUcP4name((struct basetype *)0, (unsigned char)21, (struct name *)0);
    moe_type->permanent__4node = 1;

    moe_type->defined__4type = 01;
    moe_type->b_const__4type = 1;
    check__8basetypeFP4name(moe_type, (struct name *)0);

    uint_type = __ct__8basetypeFUcP4name((struct basetype *)0, (unsigned char)21, (struct name *)0);
    uint_type->permanent__4node = 1;

    uint_type->defined__4type = 01;
    type_adj__8basetypeFUc(uint_type, (unsigned char)37);
    check__8basetypeFP4name(uint_type, (struct name *)0);

    long_type = __ct__8basetypeFUcP4name((struct basetype *)0, (unsigned char)22, (struct name *)0);
    long_type->permanent__4node = 1;

    long_type->defined__4type = 01;
    check__8basetypeFP4name(long_type, (struct name *)0);

    ulong_type =
        __ct__8basetypeFUcP4name((struct basetype *)0, (unsigned char)22, (struct name *)0);
    ulong_type->permanent__4node = 1;

    ulong_type->defined__4type = 01;
    type_adj__8basetypeFUc(ulong_type, (unsigned char)37);
    check__8basetypeFP4name(ulong_type, (struct name *)0);

    llong_type =
        __ct__8basetypeFUcP4name((struct basetype *)0, (unsigned char)122, (struct name *)0);
    llong_type->permanent__4node = 1;

    llong_type->defined__4type = 01;
    check__8basetypeFP4name(llong_type, (struct name *)0);

    ullong_type =
        __ct__8basetypeFUcP4name((struct basetype *)0, (unsigned char)122, (struct name *)0);
    ullong_type->permanent__4node = 1;

    ullong_type->defined__4type = 01;
    type_adj__8basetypeFUc(ullong_type, (unsigned char)37);
    check__8basetypeFP4name(ullong_type, (struct name *)0);

    short_type =
        __ct__8basetypeFUcP4name((struct basetype *)0, (unsigned char)29, (struct name *)0);
    short_type->permanent__4node = 1;

    short_type->defined__4type = 01;
    check__8basetypeFP4name(short_type, (struct name *)0);

    ushort_type =
        __ct__8basetypeFUcP4name((struct basetype *)0, (unsigned char)29, (struct name *)0);
    ushort_type->permanent__4node = 1;

    ushort_type->defined__4type = 01;
    type_adj__8basetypeFUc(ushort_type, (unsigned char)37);
    check__8basetypeFP4name(ushort_type, (struct name *)0);

    float_type =
        __ct__8basetypeFUcP4name((struct basetype *)0, (unsigned char)15, (struct name *)0);
    float_type->permanent__4node = 1;

    float_type->defined__4type = 01;

    double_type =
        __ct__8basetypeFUcP4name((struct basetype *)0, (unsigned char)11, (struct name *)0);
    double_type->permanent__4node = 1;

    double_type->defined__4type = 01;

    ldouble_type =
        __ct__8basetypeFUcP4name((struct basetype *)0, (unsigned char)181, (struct name *)0);
    ldouble_type->permanent__4node = 1;

    ldouble_type->defined__4type = 01;

    zero_type =
        __ct__8basetypeFUcP4name((struct basetype *)0, (unsigned char)138, (struct name *)0);
    zero_type->permanent__4node = 1;

    zero_type->defined__4type = 01;
    zero->__O1__4expr.tp = (struct type *)zero_type;

    void_type = __ct__8basetypeFUcP4name((struct basetype *)0, (unsigned char)38, (struct name *)0);
    void_type->permanent__4node = 1;

    void_type->defined__4type = 01;

    char_type = __ct__8basetypeFUcP4name((struct basetype *)0, (unsigned char)5, (struct name *)0);
    char_type->permanent__4node = 1;

    char_type->defined__4type = 01;

    uchar_type = __ct__8basetypeFUcP4name((struct basetype *)0, (unsigned char)5, (struct name *)0);
    uchar_type->permanent__4node = 1;

    uchar_type->defined__4type = 01;
    type_adj__8basetypeFUc(uchar_type, (unsigned char)37);
    check__8basetypeFP4name(uchar_type, (struct name *)0);

    Pchar_type =
        (struct type *)((__0__X26 = (struct type *)char_type),
                        (__ct__3ptrFUcP4type((struct ptr *)0, (unsigned char)125, __0__X26)));
    Pchar_type->permanent__4node = 1;

    Pchar_type->defined__4type = 01;

    Pint_type =
        (struct type *)((__0__X27 = (struct type *)int_type),
                        (__ct__3ptrFUcP4type((struct ptr *)0, (unsigned char)125, __0__X27)));
    Pint_type->permanent__4node = 1;

    Pint_type->defined__4type = 01;

    Pvoid_type =
        (struct type *)((__0__X28 = (struct type *)void_type),
                        (__ct__3ptrFUcP4type((struct ptr *)0, (unsigned char)125, __0__X28)));
    Pvoid_type->permanent__4node = 1;

    Pvoid_type->defined__4type = 01;

    Pfctvec_type = (struct type *)__ct__3fctFP4typeP4nameUc(
        (struct fct *)0, (struct type *)int_type, (struct name *)0, (unsigned char)0);
    Pfctvec_type =
        (struct type *)((__0__X29 = Pfctvec_type),
                        (__ct__3ptrFUcP4type((struct ptr *)0, (unsigned char)125, __0__X29)));
    Pfctvec_type =
        (struct type *)((__0__X30 = Pfctvec_type),
                        (__ct__3ptrFUcP4type((struct ptr *)0, (unsigned char)125, __0__X30)));
    Pfctvec_type->permanent__4node = 1;

    Pfctvec_type->defined__4type = 01;

    gtbl = __ct__5tableFsP5tableP4name((struct table *)0, (short)257, (struct table *)0,
                                       (struct name *)0);
    gtbl->t_name__5table = __ct__4nameFPCc((struct name *)0, (const char *)"global");
    ptbl = __ct__5tableFsP5tableP4name((struct table *)0, (short)12, (struct table *)0,
                                       (struct name *)0);
    ptbl->t_name__5table = __ct__4nameFPCc((struct name *)0, (const char *)"ptbl");

    templates__17templ_compilation = __ct__5tableFsP5tableP4name(
        (struct table *)0, (short)128, (struct table *)0, (struct name *)0);
    bound_expr_tbl = __ct__5tableFsP5tableP4name((struct table *)0, (short)12, (struct table *)0,
                                                 (struct name *)0);
}

Pbase arit_conv__8basetypeFP8basetype(register struct basetype *__0this, Pbase __1t) {
    bit __1l;

    bit __1ll;
    bit __1u;
    bit __1f;
    bit __1l1;
    bit __1ll1;
    bit __1u1;
    bit __1f1;

    __1l1 = (__0this->base__4node == 22);
    __1ll1 = (__0this->base__4node == 122);
    __1u1 = __0this->b_unsigned__8basetype;
    __1f1 = (((__0this->base__4node == 15) || (__0this->base__4node == 11)) ||
             (__0this->base__4node == 181));
    if (__1t) {
        __1t = ((
            (struct basetype *)(((struct basetype *)skiptypedefs__4typeFv((struct type *)__1t)))));

        {
            bit __2l2;
            bit __2ll2;
            bit __2u2;
            bit __2f2;

            __2l2 = (__1t->base__4node == 22);
            __2ll2 = (__1t->base__4node == 122);
            __2u2 = __1t->b_unsigned__8basetype;
            __2f2 = (((__1t->base__4node == 15) || (__1t->base__4node == 11)) ||
                     (__1t->base__4node == 181));
            __1l = (__1l1 || __2l2);
            __1ll = (__1ll1 || __2ll2);
            __1u = (__1u1 || __2u2);
            __1f = (__1f1 || __2f2);
        }
    } else {
        __1l = __1l1;
        __1ll = __1ll1;
        __1u = __1u1;
        __1f = __1f1;
    }

    if (__1f) {
        if ((__0this->base__4node == 181) || (__1t && (__1t->base__4node == 181)))
            return ldouble_type;
        if ((__0this->base__4node == 11) || (__1t && (__1t->base__4node == 11)))
            return double_type;
        return float_type;
    }
    if (__1l && __1u)
        return ulong_type;
    if (__1l && (!__1u))
        return long_type;
    if (__1ll && __1u)
        return ullong_type;
    if (__1ll && (!__1u))
        return llong_type;
    if (__1u) {
        if ((__0this->base__4node == 21) || (__1t && (__1t->base__4node == 21)))
            return uint_type;
        if (SZ_SHORT == SZ_INT)
            if ((__0this->base__4node == 29) || (__1t && (__1t->base__4node == 29)))
                return uint_type;
        return int_type;
    }

    return int_type;
}

bit vec_const = 0;
bit fct_const = 0;

bit tconst__4typeFv(register struct type *__0this) {
    Ptype __1t;

    __1t = __0this;
    vec_const = 0;
    fct_const = 0;

xxx:
    switch (__1t->base__4node) {
    case 97:
        if ((((struct basetype *)(((struct basetype *)__1t))))->b_const__4type)
            return (unsigned char)1;
        __1t =
            (((struct basetype *)(((struct basetype *)__1t))))->b_name__8basetype->__O1__4expr.tp;
        goto xxx;
    case 110:
        vec_const = 1;
        return (unsigned char)1;
    case 125:
    case 158:
        return (((struct ptr *)(((struct ptr *)__1t))))->b_const__4type;
    case 108:
    case 76:
        fct_const = 1;
        return (unsigned char)1;
    default:
        return (((struct basetype *)(((struct basetype *)__1t))))->b_const__4type;
    }
}

bit is_const_object__4typeFv(register struct type *__0this) {
    int __1cc;
    Ptype __1tt;

    __1cc = tconst__4typeFv(__0this);
    __1tt = skiptypedefs__4typeFv(__0this);
    while (__1cc && (__1tt->base__4node == 110)) {
        __1tt = (((struct vec *)(((struct vec *)__1tt))))->typ__5pvtyp;
        __1cc = tconst__4typeFv(__1tt);
        __1tt = skiptypedefs__4typeFv(__1tt);
    }
    return (unsigned char)__1cc;
}

TOK set_const__4typeFUc(register struct type *__0this, bit __1mode) {
    Ptype __1t;
    int __1m;

    __1t = __0this;

xxx:
    switch (__1t->base__4node) {
    case 97:
        __1m = (((struct basetype *)(((struct basetype *)__1t))))->b_const__4type;
        (((struct basetype *)(((struct basetype *)__1t))))->b_const__4type = __1mode;
        __1t =
            (((struct basetype *)(((struct basetype *)__1t))))->b_name__8basetype->__O1__4expr.tp;
        goto xxx;
    case 141:
    case 158:
    case 110:
        return __1t->base__4node;
    case 125:
        __1m = (((struct ptr *)(((struct ptr *)__1t))))->b_const__4type;
        (((struct ptr *)(((struct ptr *)__1t))))->b_const__4type = __1mode;
        return (unsigned char)__1m;
    default:
        __1m = (((struct basetype *)(((struct basetype *)__1t))))->b_const__4type;
        (((struct basetype *)(((struct basetype *)__1t))))->b_const__4type = __1mode;
        return (unsigned char)__1m;
    }
}

Pptr is_ref__4typeFv(register struct type *__0this) {
    Ptype __1t;

    __1t = skiptypedefs__4typeFv(__0this);

    switch (__1t->base__4node) {
    case 158:
        return (((struct ptr *)(((struct ptr *)__1t))));
    default:
        return (struct ptr *)0;
    }
}

Pclass Mptr = 0;

Pptr is_ptr__4typeFv(register struct type *__0this) {
    Ptype __1t;

    __1t = skiptypedefs__4typeFv(__0this);

    switch (__1t->base__4node) {
    case 125:
    case 110:
        Mptr = (((struct ptr *)(((struct ptr *)__1t))))->memof__3ptr;
        return (((struct ptr *)(((struct ptr *)__1t))));
    default:
        return (struct ptr *)0;
    }
}

Pptr is_ptr_or_ref__4typeFv(register struct type *__0this) {
    Ptype __1t;

    __1t = skiptypedefs__4typeFv(__0this);

    switch (__1t->base__4node) {
    case 125:
    case 158:
    case 110:
        Mptr = (((struct ptr *)(((struct ptr *)__1t))))->memof__3ptr;
        return (((struct ptr *)(((struct ptr *)__1t))));
    default:
        return (struct ptr *)0;
    }
}

int align__4typeFv(struct type *__0this);

extern int error__FPCc(const char *);

int align__4typeFv(register struct type *__0this) {
    Ptype __1t;

    __1t = skiptypedefs__4typeFv(__0this);

    switch (__1t->base__4node) {
        unsigned long __2__X33;

    case 119:
        return align__4typeFv((
            (((struct basetype *)(((struct basetype *)__1t))))->b_name__8basetype->__O1__4expr.tp));
    case 110:
        return align__4typeFv((((struct vec *)(((struct vec *)__1t))))->typ__5pvtyp);
    case 141:
        return 1;
    case 5:
        return AL_CHAR;
    case 29:
        return AL_SHORT;
    case 21:
        return AL_INT;
    case 22:
        return AL_LONG;
    case 122:
        return AL_LLONG;
    case 15:
        return AL_FLOAT;
    case 11:
        return AL_DOUBLE;
    case 181:
        return AL_LDOUBLE;
    case 125:
    case 158:
        return AL_WPTR;
    case 6:
        return (int)(((struct classdef *)(((struct classdef *)__1t))))->obj_align__8classdef;
    case 13:
    case 121:
        return AL_INT;
    case 38:
        error__FPCc((const char *)"illegal use of void");

        return AL_INT;
    default: {
        struct ea __0__V31;

        struct ea __0__V32;

        error__FiPCcRC2eaN33(
            (int)'i', (const char *)"(%d,%k)->type::align",
            (const struct ea *)(((&__0__V31)->__O1__2ea.p = ((const void *)__1t)), (&__0__V31)),
            (const struct ea *)((__2__X33 = __1t->base__4node),
                                (((((&__0__V32)->__O1__2ea.i = __2__X33), 0)), (&__0__V32))),
            (const struct ea *)ea0, (const struct ea *)ea0);

        return 0;
    }
    }
}

bit fake_sizeof = 0;

int tsizeof__4typeFi(struct type *__0this, int __1ptmc);

extern int error__FPCcRC2eaN32(const char *, const struct ea *, const struct ea *,
                               const struct ea *, const struct ea *);

void dcl_print__8classdefFP4name(struct classdef *__0this, Pname);

int tsizeof__4typeFi(register struct type *__0this, int __1ptmc) {
    Ptype __1t;

    __1t = skiptypedefs__4typeFv(__0this);

    if (__1t == 0)
        error__FiPCc((int)'i', (const char *)"typ.tsizeof(t==0)");
    switch (__1t->base__4node) {
        unsigned long __2__X13;

        struct ea __0__X__V1200anpqmjkjwchn;

        const void *__2__X38;

    case 119:
        __1t =
            ((((struct basetype *)(((struct basetype *)__1t))))->b_name__8basetype->__O1__4expr.tp);
        if (__1t == 0)
            return 0;
        return tsizeof__4typeFi(__1t, __1ptmc);

    case 141:
        return 1;
    case 38:
        return 0;
    case 138:
        return SZ_WPTR;
    case 5:
        return SZ_CHAR;
    case 29:
        return SZ_SHORT;
    case 21:
        return SZ_INT;
    case 22:
        return SZ_LONG;
    case 122:
        return SZ_LLONG;
    case 15:
        return SZ_FLOAT;
    case 11:
        return SZ_DOUBLE;
    case 181:
        return SZ_LDOUBLE;

    case 110: {
        Pvec __3v;

        __3v = (((struct vec *)(((struct vec *)__1t))));
        if (__3v->size__3vec == 0) {
            if (fake_sizeof == 0)
                error__FPCc((const char *)"sizeof array with undeclared dimension");
            return SZ_WPTR;
        }
        return (__3v->size__3vec * tsizeof__4typeFi(__3v->typ__5pvtyp, 0));
    }
    case 158:
    case 125: {
        int __3k;

        __3k = (((((struct ptr *)(((struct ptr *)__1t))))->memof__3ptr && (!__1ptmc))
                    ? ((sizeof(short)) + (sizeof(short)))
                    : (((unsigned long)0)));

        __1t = skiptypedefs__4typeFv((((struct ptr *)(((struct ptr *)__1t))))->typ__5pvtyp);

        switch (__1t->base__4node) {
        default:
            return SZ_WPTR;
        case 5:
            return SZ_BPTR;
        case 108:
            return (SZ_WPTR + __3k);
        }
    }
    case 114:
        error__FPCc((const char *)"sizeof(field)");
        return (((((int)(((struct basetype *)(((struct basetype *)__1t))))->b_bits__8basetype)) /
                 BI_IN_BYTE) +
                1);
    case 76:
    case 108:
        error__FPCc((const char *)"sizeof(function)");
        return 0;

    case 6: {
        Pclass __3cl;

        __3cl = (((struct classdef *)(((struct classdef *)__1t))));
        if ((__3cl->defined__4type & 3) == 0) {
            if ((__3cl->class_base__8classdef == 2) || (__3cl->class_base__8classdef == 5)) {
                struct ea __0__V34;

                struct ea __0__V35;

                error__FPCcRC2eaN32(
                    (const char *)"YC%t not yet instantiated; please add an explicit instantiation "
                                  "(Tdef%t<Ts>)",
                    (const struct ea *)(((&__0__V34)->__O1__2ea.p = ((const void *)__3cl)),
                                        (&__0__V34)),
                    (const struct ea *)(((&__0__V35)->__O1__2ea.p = ((const void *)__3cl)),
                                        (&__0__V35)),
                    (const struct ea *)ea0, (const struct ea *)ea0);
            } else {
                struct ea __0__V36;

                error__FPCcRC2eaN32(
                    (const char *)"%tU, size not known",
                    (const struct ea *)(((&__0__V36)->__O1__2ea.p = ((const void *)__3cl)),
                                        (&__0__V36)),
                    (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
            }
            return SZ_INT;
        }
        if (__3cl->c_body__8classdef == 1)
            dcl_print__8classdefFP4name(__3cl, (struct name *)0);
        return __3cl->obj_size__8classdef;
    }

    case 121:
        if (((((__1t->base__4node == 121)
                   ? (((struct enumdef *)((
                         (struct enumdef *)(((struct basetype *)(((struct basetype *)__1t))))
                             ->b_name__8basetype->__O1__4expr.tp))))
                   : (error__FiPCcRC2eaN33(
                          (int)'i', (const char *)"T::enumtype(): %k eobjX",
                          (const struct ea
                               *)((__2__X13 = __1t->base__4node),
                                  (((((&__0__X__V1200anpqmjkjwchn)->__O1__2ea.i = __2__X13), 0)),
                                   (&__0__X__V1200anpqmjkjwchn))),
                          (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0),
                      (((struct enumdef *)0)))))
                 ->defined__4type &
             3) == 0) {
            struct ea __0__V37;

            error__FPCcRC2eaN32(
                (const char *)"%tU, size not known",
                (const struct ea
                     *)((__2__X38 = (const void *)((
                             (__1t->base__4node == 121)
                                 ? (((struct enumdef *)((
                                       (struct enumdef *)(((struct basetype *)((
                                                              (struct basetype *)__1t))))
                                           ->b_name__8basetype->__O1__4expr.tp))))
                                 : (error__FiPCcRC2eaN33(
                                        (int)'i', (const char *)"T::enumtype(): %k eobjX",
                                        (const struct ea *)((__2__X13 = __1t->base__4node),
                                                            (((((&__0__X__V1200anpqmjkjwchn)
                                                                    ->__O1__2ea.i = __2__X13),
                                                               0)),
                                                             (&__0__X__V1200anpqmjkjwchn))),
                                        (const struct ea *)ea0, (const struct ea *)ea0,
                                        (const struct ea *)ea0),
                                    (((struct enumdef *)0)))))),
                        (((&__0__V37)->__O1__2ea.p = __2__X38), (&__0__V37))),
                (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
        }
    case 13:
        return SZ_INT;

    default:
        return 0;
    }
}

bit vec_type__4typeFv(register struct type *__0this) {
    Ptype __1t;

    __1t = skiptypedefs__4typeFv(__0this);

    switch (__1t->base__4node) {
    case 141:
    case 110:
    case 125:
    case 158:
        return (unsigned char)1;
    default:
        return (unsigned char)0;
    }
}

int ref_initializer = 0;

Ptype deref__4typeFv(register struct type *__0this) {
    Ptype __1t;

    __1t = skiptypedefs__4typeFv(__0this);

    switch (__1t->base__4node) {
    case 125:
    case 158:
    case 110: {
        if (__1t == Pvoid_type)
            error__FPCc((const char *)"void* dereferenced");
        __1t = (((struct vec *)(((struct vec *)__1t))))->typ__5pvtyp;
        if (ref_initializer == 0) {
            Ptype __4tt;

            __4tt = skiptypedefs__4typeFv(__1t);
            if (__4tt->base__4node == 119) {
                __4tt = ((((struct basetype *)(((struct basetype *)__4tt))))
                             ->b_name__8basetype->__O1__4expr.tp);
                if (__4tt &&
                    ((((struct classdef *)(((struct classdef *)__4tt))))->defined__4type & 3))
                    ((void)tsizeof__4typeFi(__1t, 0));
            }
        }
    }
    case 141:
        return __1t;
    default:
        error__FPCc((const char *)"nonP dereferenced");
        return (struct type *)any_type;
    }
}

Pfct memptr__4typeFv(register struct type *__0this) {
    if (__0this == 0)
        return (struct fct *)0;
    {
        Ptype __1t;

        __1t = skiptypedefs__4typeFv(__0this);
        if ((__1t->base__4node != 125) ||
            ((((struct ptr *)(((struct ptr *)__1t))))->memof__3ptr == 0))
            return (struct fct *)0;

        __1t = skiptypedefs__4typeFv((((struct ptr *)(((struct ptr *)__1t))))->typ__5pvtyp);
        return ((__1t->base__4node == 108) ? (((struct fct *)(((struct fct *)__1t))))
                                           : (((struct fct *)0)));
    }
}

Ptype skiptypedefs__4typeFv(register struct type *__0this) {
    Ptype __1t;

    __1t = __0this;
    if (__1t == 0)
        return __1t;
    while (__1t && (__1t->base__4node == 97)) {
        __1t =
            ((((struct basetype *)(((struct basetype *)__1t))))->b_name__8basetype->__O1__4expr.tp);
    }
    return __1t;
}

Ptype skiptypedefs__4typeFRUc(register struct type *__0this, bit *__1isconst) {
    Ptype __1t;

    __1t = __0this;
    ((*__1isconst)) = 0;
    if (__1t == 0)
        return __1t;
    while (__1t->base__4node == 97) {
        ((*__1isconst)) |= (((struct basetype *)(((struct basetype *)__1t))))->b_const__4type;
        __1t =
            ((((struct basetype *)(((struct basetype *)__1t))))->b_name__8basetype->__O1__4expr.tp);
    }
    ((*__1isconst)) |= (((struct basetype *)(((struct basetype *)__1t))))->b_const__4type;
    return __1t;
}

Ptype mkconst__4typeFv(struct type *__0this);

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

Ptype mkconst__4typeFv(register struct type *__0this) {
    Ptype __1r;

    __1r = __0this;

    switch (__0this->base__4node) {
    case 97: {
        Ptype __3t;

        __3t = skiptypedefs__4typeFv(__0this);
        if (__3t->base__4node == 110)
            return mkconst__4typeFv(__3t);
    }
    case 21:
    case 5:
    case 29:
    case 22:
    case 122:
    case 15:
    case 11:
    case 181:
    case 114:
    case 138:
    case 119:
    case 121:
        if (__0this->b_const__4type == 0) {
            __1r = (struct type *)__ct__8basetypeFUcP4name((struct basetype *)0,
                                                           __0this->base__4node, (struct name *)0);
            __1r->permanent__4node = 1;
            ((*(((struct basetype *)(((struct basetype *)__1r)))))) =
                (*(((struct basetype *)(((struct basetype *)__0this)))));
            __1r->b_const__4type = 1;
        }
        break;
    case 125:
    case 158:
        if (__0this->b_const__4type == 0) {
            __1r = (struct type *)__ct__3ptrFUcP4type((struct ptr *)0, __0this->base__4node,
                                                      (struct type *)0);
            __1r->permanent__4node = 1;
            ((*(((struct ptr *)(((struct ptr *)__1r)))))) =
                (*(((struct ptr *)(((struct ptr *)__0this)))));
            __1r->b_const__4type = 1;
        }
        break;
    case 110: {
        Ptype __3t;

        __3t = mkconst__4typeFv((((struct vec *)(((struct vec *)__0this))))->typ__5pvtyp);
        if (__3t != (((struct vec *)(((struct vec *)__0this))))->typ__5pvtyp) {
            __1r = (struct type *)__ct__3vecFP4typeP4expr(
                (struct vec *)0, (((struct vec *)(((struct vec *)__0this))))->typ__5pvtyp,
                (struct expr *)0);
            __1r->permanent__4node = 1;
            ((*(((struct vec *)(((struct vec *)__1r)))))) =
                (*(((struct vec *)(((struct vec *)__0this)))));
            (((struct vec *)(((struct vec *)__1r))))->typ__5pvtyp = __3t;
        }
        break;
    }

    default: {
        struct ea __0__V39;

        error__FiPCcRC2eaN33(
            (int)'i', (const char *)"mkconst for %t",
            (const struct ea *)(((&__0__V39)->__O1__2ea.p = ((const void *)__0this)), (&__0__V39)),
            (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
    }
    }

    return __1r;
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
