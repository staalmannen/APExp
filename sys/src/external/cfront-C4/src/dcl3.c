
/* <<AT&T C++ Language System <3.0.3> 05/05/94>> pragma*/

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

Pblock top_block = 0;
int New_in_arg_list = 0;

static int is_zero__FP4expr(Pexpr __1e) {
    if (!__1e)
        return 0;
    if (__1e->base__4node == 86)
        return 1;
    if ((__1e->base__4node != 113) && (__1e->base__4node != 191))
        return 0;
    return (__1e->__O2__4expr.e1->base__4node == 86);
}

static void vbase_pointers__FP4nameP8classdef(Pname __1fn, Pclass __1cl) {
    Pfct __1f;

    __1f = (((struct fct *)(((struct fct *)__1fn->__O1__4expr.tp))));
    if (__1fn->n_oper__4name == 161) {
        Pname __2d;

        __2d = 0;
        {
            {
                Pbcl __2b;

                __2b = __1cl->baselist__8classdef;

                for (; __2b; __2b = __2b->next__6basecl) {
                    if (__2b->base__4node != 77)
                        continue;
                    {
                        Pname __3a;

                        __3a = __ct__4nameFPCc((struct name *)0,
                                               __2b->bclass__6basecl->string__8classdef);
                        __3a->__O1__4expr.tp = __2b->bclass__6basecl->this_type__8classdef;
                        __3a->__O1__4name.n_list = __2d;
                        __3a->__O4__4expr.n_table =
                            (__1f->body__3fct ? __1f->body__3fct->memtbl__4stmt
                                              : (((struct table *)0)));
                        __3a->where__4name = __1fn->where__4name;
                        __2d = __3a;
                    }
                }

                if (__2d) {
                    Pname __3dd;

                    __3dd = __2d;
                    for (;;) {
                        if (__2d->__O1__4name.n_list == 0) {
                            __2d->__O1__4name.n_list = __1f->f_args__3fct->__O1__4name.n_list;
                            break;
                        }
                        __2d = __2d->__O1__4name.n_list;
                    }
                    __1f->f_args__3fct->__O1__4name.n_list = __3dd;
                }
            }
        }
    }
    if (__1fn->n_oper__4name == 162) {
        Pname __2fa;

        __2fa = __ct__4nameFPCc((struct name *)0, (const char *)0);
        __2fa->__O1__4expr.tp = (struct type *)int_type;
        __2fa->n_scope__4name = 136;
        __2fa->where__4name = __1fn->where__4name;

        {
            Pname __2a;

            __2a = __1f->f_args__3fct;
            if (__2a == 0)
                __1f->f_args__3fct = __2fa;
            else {
                for (;; __2a = __2a->__O1__4name.n_list) {
                    if (__2a->__O1__4name.n_list == 0) {
                        __2a->__O1__4name.n_list = __2fa;
                        break;
                    }
                }
            }
        }
    }
}

Pname is_cl_obj__4typeFv(struct type *__0this);

void make_res__FP3fct(Pfct __1f) {
    Pname __1cl;

    struct classdef *__0__X26;

    __1cl = is_cl_obj__4typeFv(__1f->returns__3fct);
    if ((__1cl == 0) ||
        (((__0__X26 = (((struct classdef *)(((struct classdef *)__1cl->__O1__4expr.tp))))),
          (__0__X26->c_itor__8classdef)) == 0))
        return;

    {
        Pname __1rv;

        struct type *__0__X27;

        __1rv = __ct__4nameFPCc((struct name *)0, (const char *)"_result");
        __1rv->__O1__4expr.tp =
            (struct type *)((__0__X27 = __1f->returns__3fct),
                            (__ct__3ptrFUcP4type((struct ptr *)0, (unsigned char)125, __0__X27)));
        __1rv->permanent__4node = 1;
        __1rv->__O1__4expr.tp->permanent__4node = 1;
        __1rv->n_scope__4name = 108;
        __1rv->n_used__4name = 1;
        __1rv->__O1__4name.n_list = __1f->argtype__3fct;
        if (__1f->f_this__3fct)
            __1f->f_this__3fct->__O1__4name.n_list = __1rv;
        else
            __1f->f_args__3fct = __1rv;
        __1f->f_result__3fct = __1rv;
        __1f->s_returns__3fct = (struct type *)void_type;
    }
}

extern int error__FPCcRC2eaN32(const char *, const struct ea *, const struct ea *,
                               const struct ea *, const struct ea *);

extern int strcmp(const char *, const char *);

struct fct *__ct__3fctFP4typeP4nameUc(struct fct *__0this, Ptype, Pname, TOK);

void del__4typeFv(struct type *__0this);

char *signature__4typeFPci(struct type *__0this, char *, int);

extern char *strcpy(char *, const char *);

static struct ea *__ct__2eaFPCv(struct ea *__0this, const void *__2pp);

void check_oper__4nameFP4name(register struct name *__0this, Pname __1cn) {
    ;
    switch (__0this->n_oper__4name) {
        const void *__2__X62;

        unsigned long __2__X64;

        register struct templ_classdef *__0__X67;

        register struct templ_classdef *__0__X70;

    case 109:
    case 111:
    case 44:
        if (__1cn == 0) {
            struct ea __0__V28;

            error__FPCcRC2eaN32(
                (const char *)"operator%s must be aM",
                (const struct ea *)((__2__X62 = (const void *)(keys[__0this->n_oper__4name])),
                                    (((&__0__V28)->__O1__2ea.p = __2__X62), (&__0__V28))),
                (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
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
        if (warning_opt) {
            const void *__2__X63;

            if ((__1cn == 0) ||
                (((struct fct *)(((struct fct *)__0this->__O1__4expr.tp))))->f_static__3fct) {
                struct ea __0__V29;

                error__FiPCcRC2eaN33(
                    (int)'w', (const char *)"operator%s should be a non-staticMF",
                    (const struct ea *)((__2__X63 = (const void *)(keys[__0this->n_oper__4name])),
                                        (((&__0__V29)->__O1__2ea.p = __2__X63), (&__0__V29))),
                    (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
            }
        }
        break;
    case 70:
        if (__1cn == 0) {
            struct ea __0__V30;

            error__FPCcRC2eaN32(
                (const char *)"non-member operator%k()",
                (const struct ea *)((__2__X64 = __0this->n_oper__4name),
                                    (((((&__0__V30)->__O1__2ea.i = __2__X64), 0)), (&__0__V30))),
                (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
        }
        break;
    case 58:
    case 59:
    case 60:
    case 61:
    case 62:
    case 63:
        if (__1cn && (((struct fct *)(((struct fct *)__0this->__O1__4expr.tp))))->f_static__3fct) {
            const void *__2__X65;

            {
                struct ea __0__V31;

                error__FPCcRC2eaN32(
                    (const char *)"operator%s cannot be static",
                    (const struct ea *)((__2__X65 = (const void *)(keys[__0this->n_oper__4name])),
                                        (((&__0__V31)->__O1__2ea.p = __2__X65), (&__0__V31))),
                    (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
                (((struct fct *)(((struct fct *)__0this->__O1__4expr.tp))))->f_static__3fct = 0;
            }
        }
        break;
    case 46:
    case 47: {
        Pfct __3f;

        __3f = (((struct fct *)(((struct fct *)__0this->__O1__4expr.tp))));
        if (__1cn && __3f->argtype__3fct) {
            struct ea __0__V32;

            struct ea __0__V33;

            error__FPCcRC2eaN32(
                (const char *)"%n::%n takes noAs",
                (const struct ea *)(((&__0__V32)->__O1__2ea.p = ((const void *)__1cn)),
                                    (&__0__V32)),
                (const struct ea *)(((&__0__V33)->__O1__2ea.p = ((const void *)__0this)),
                                    (&__0__V33)),
                (const struct ea *)ea0, (const struct ea *)ea0);
        } else if (__3f->nargs__3fct == 2) {
            struct ea __0__V34;

            error__FPCcRC2eaN32(
                (const char *)"%n takes 1A only",
                (const struct ea *)(((&__0__V34)->__O1__2ea.p = ((const void *)__0this)),
                                    (&__0__V34)),
                (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
        }
        if (__1cn && (((struct fct *)(((struct fct *)__0this->__O1__4expr.tp))))->f_static__3fct) {
            const void *__2__X66;

            {
                struct ea __0__V35;

                error__FPCcRC2eaN32(
                    (const char *)"operator%s cannot be static",
                    (const struct ea *)((__2__X66 = (const void *)(keys[__0this->n_oper__4name])),
                                        (((&__0__V35)->__O1__2ea.p = __2__X66), (&__0__V35))),
                    (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
                (((struct fct *)(((struct fct *)__0this->__O1__4expr.tp))))->f_static__3fct = 0;
            }
        }
        break;
    }
    case 48:
    case 49: {
        Pfct __3f;

        __3f = (((struct fct *)(((struct fct *)__0this->__O1__4expr.tp))));
        if (__1cn) {
            if (__3f->argtype__3fct && (__3f->nargs__3fct == 1)) {
                Pname __5n;
                Ptype __5at;

                __5n = __3f->argtype__3fct;
                __5at = skiptypedefs__4typeFv(__5n->__O1__4expr.tp);
                if ((__5at->base__4node != 21) ||
                    (((struct basetype *)(((struct basetype *)__5at))))->b_unsigned__8basetype) {
                    struct ea __0__V36;

                    struct ea __0__V37;

                    error__FPCcRC2eaN32(
                        (const char *)"%n must takeA ofT int, not %t",
                        (const struct ea *)(((&__0__V36)->__O1__2ea.p = ((const void *)__0this)),
                                            (&__0__V36)),
                        (const struct ea *)__ct__2eaFPCv(&__0__V37,
                                                         (const void *)__5n->__O1__4expr.tp),
                        (const struct ea *)ea0, (const struct ea *)ea0);
                }
            }
        } else if (__3f->nargs__3fct == 2) {
            Pname __4n;
            Ptype __4at;

            __4n = __3f->argtype__3fct->__O1__4name.n_list;
            __4at = skiptypedefs__4typeFv(__4n->__O1__4expr.tp);
            if ((__4at->base__4node != 21) ||
                (((struct basetype *)(((struct basetype *)__4at))))->b_unsigned__8basetype) {
                struct ea __0__V38;

                struct ea __0__V39;

                error__FPCcRC2eaN32(
                    (const char *)"%n must takeA ofT int, not %t",
                    (const struct ea *)(((&__0__V38)->__O1__2ea.p = ((const void *)__0this)),
                                        (&__0__V38)),
                    (const struct ea *)__ct__2eaFPCv(&__0__V39, (const void *)__4n->__O1__4expr.tp),
                    (const struct ea *)ea0, (const struct ea *)ea0);
            }
        }
        break;
    }
    case 0:
    case 123:
        if (__1cn &&
            ((strcmp(__1cn->__O2__4expr.string, __0this->__O2__4expr.string) == 0) ||
             (((((struct classdef *)(((struct classdef *)__1cn->__O1__4expr.tp))))
                   ->class_base__8classdef == 4) &&
              (strcmp(__0this->__O2__4expr.string,
                      ((__0__X67 = (((struct templ_classdef *)((
                            (struct templ_classdef *)__1cn->__O1__4expr.tp))))),
                       (__0__X67->inst__14templ_classdef->def__10templ_inst->namep__5templ))
                          ->__O2__4expr.string) == 0)))) {
            if (__0this->__O1__4expr.tp->base__4node == 108) {
                Pfct __4f;

                const void *__2__X68;

                __4f = (((struct fct *)(((struct fct *)__0this->__O1__4expr.tp))));
                if (__4f->returns__3fct != (((struct type *)defa_type))) {
                    struct ea __0__V40;

                    struct ea __0__V41;

                    error__FPCcRC2eaN32(
                        (const char *)"%s::%s()W returnT",
                        (const struct ea *)((__2__X68 = (const void *)__0this->__O2__4expr.string),
                                            (((&__0__V40)->__O1__2ea.p = __2__X68), (&__0__V40))),
                        (const struct ea *)__ct__2eaFPCv(&__0__V41,
                                                         (const void *)__0this->__O2__4expr.string),
                        (const struct ea *)ea0, (const struct ea *)ea0);
                }
                __4f->returns__3fct = (struct type *)void_type;
                __0this->__O2__4expr.string = (const char *)"__ct";
                __0this->n_oper__4name = 161;
            } else {
                struct ea __0__V42;

                struct ea __0__V43;

                error__FiPCcRC2eaN33(
                    (int)'s', (const char *)"struct%nM%n",
                    (const struct ea *)(((&__0__V42)->__O1__2ea.p = ((const void *)__1cn)),
                                        (&__0__V42)),
                    (const struct ea *)(((&__0__V43)->__O1__2ea.p = ((const void *)__1cn)),
                                        (&__0__V43)),
                    (const struct ea *)ea0, (const struct ea *)ea0);
            }
        } else
            __0this->n_oper__4name = 0;
        break;

    case 162:
        if (__1cn == 0) {
            const void *__2__X69;

            __0this->n_oper__4name = 0;
            {
                struct ea __0__V44;

                error__FPCcRC2eaN32(
                    (const char *)"destructor ~%s() not inC",
                    (const struct ea *)((__2__X69 = (const void *)__0this->__O2__4expr.string),
                                        (((&__0__V44)->__O1__2ea.p = __2__X69), (&__0__V44))),
                    (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
            }
        } else if ((strcmp(__1cn->__O2__4expr.string, __0this->__O2__4expr.string) == 0) ||
                   (((((struct classdef *)(((struct classdef *)__1cn->__O1__4expr.tp))))
                         ->class_base__8classdef == 4) &&
                    (strcmp(__0this->__O2__4expr.string,
                            ((__0__X70 = (((struct templ_classdef *)((
                                  (struct templ_classdef *)__1cn->__O1__4expr.tp))))),
                             (__0__X70->inst__14templ_classdef->def__10templ_inst->namep__5templ))
                                ->__O2__4expr.string) == 0))) {
        dto: {
            Pfct __3f;

            __3f = (((struct fct *)(((struct fct *)__0this->__O1__4expr.tp))));
            __0this->__O2__4expr.string = (const char *)"__dt";
            if (__0this->__O1__4expr.tp->base__4node != 108) {
                const void *__2__X71;

                {
                    struct ea __0__V45;

                    struct ea __0__V46;

                    error__FPCcRC2eaN32(
                        (const char *)"%s::~%s notF",
                        (const struct ea *)((__2__X71 = (const void *)__1cn->__O2__4expr.string),
                                            (((&__0__V45)->__O1__2ea.p = __2__X71), (&__0__V45))),
                        (const struct ea *)__ct__2eaFPCv(&__0__V46,
                                                         (const void *)__1cn->__O2__4expr.string),
                        (const struct ea *)ea0, (const struct ea *)ea0);

                    __0this->__O1__4expr.tp = (struct type *)__ct__3fctFP4typeP4nameUc(
                        (struct fct *)0, (struct type *)void_type, (struct name *)0,
                        (unsigned char)1);
                }
            } else if (__3f->returns__3fct != (((struct type *)defa_type))) {
                const void *__2__X72;

                if (((__3f->returns__3fct != (((struct type *)void_type))) ||
                     (__3f->body__3fct != 0)) ||
                    (friend_in_class == 0)) {
                    struct ea __0__V47;

                    struct ea __0__V48;

                    error__FPCcRC2eaN32(
                        (const char *)"%s::~%s()W returnT",
                        (const struct ea *)((__2__X72 = (const void *)__1cn->__O2__4expr.string),
                                            (((&__0__V47)->__O1__2ea.p = __2__X72), (&__0__V47))),
                        (const struct ea *)__ct__2eaFPCv(&__0__V48,
                                                         (const void *)__1cn->__O2__4expr.string),
                        (const struct ea *)ea0, (const struct ea *)ea0);
                }
            }

            if (__3f->argtype__3fct || (__3f->nargs_known__3fct == 155)) {
                const void *__2__X73;

                {
                    struct ea __0__V49;

                    struct ea __0__V50;

                    error__FPCcRC2eaN32(
                        (const char *)"%s::~%s()WAs",
                        (const struct ea *)((__2__X73 = (const void *)__1cn->__O2__4expr.string),
                                            (((&__0__V49)->__O1__2ea.p = __2__X73), (&__0__V49))),
                        (const struct ea *)__ct__2eaFPCv(&__0__V50,
                                                         (const void *)__1cn->__O2__4expr.string),
                        (const struct ea *)ea0, (const struct ea *)ea0);

                    __3f->nargs__3fct = 0;
                    __3f->nargs_known__3fct = 1;
                    __3f->argtype__3fct = 0;
                }
            }
            __3f->returns__3fct = (struct type *)void_type;
        }
        } else {
            const void *__2__X74;

            if (strcmp(__0this->__O2__4expr.string, (const char *)"__dt") == 0)
                goto dto;

            {
                struct ea __0__V51;

                struct ea __0__V52;

                error__FPCcRC2eaN32(
                    (const char *)"~%s in %s",
                    (const struct ea *)((__2__X74 = (const void *)__0this->__O2__4expr.string),
                                        (((&__0__V51)->__O1__2ea.p = __2__X74), (&__0__V51))),
                    (const struct ea *)__ct__2eaFPCv(&__0__V52,
                                                     (const void *)__1cn->__O2__4expr.string),
                    (const struct ea *)ea0, (const struct ea *)ea0);

                __0this->n_oper__4name = 0;
            }
        }
        break;

    case 97:
        if (__1cn == 0) {
            const void *__2__X75;

            {
                struct ea __0__V53;

                error__FPCcRC2eaN32(
                    (const char *)"operator%t() not aM",
                    (const struct ea *)((__2__X75 = (const void *)(((struct type *)((
                                             (struct type *)__0this->__O4__4expr.cond))))),
                                        (((&__0__V53)->__O1__2ea.p = __2__X75), (&__0__V53))),
                    (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
                __0this->n_oper__4name = 0;
                __0this->__O4__4expr.cond = 0;
            }
        } else if (__0this->__O4__4expr.cond) {
            Pfct __3f;
            Ptype __3tx;

            __3f = (((struct fct *)(((struct fct *)__0this->__O1__4expr.tp))));
            __3tx = (((struct type *)(((struct type *)__0this->__O4__4expr.cond))));
            __0this->__O4__4expr.cond = 0;
            if (skiptypedefs__4typeFv(__3tx)->base__4node == 108) {
                struct ea __0__V54;

                struct ea __0__V55;

                error__FPCcRC2eaN32(
                    (const char *)"badT for%n::operator%t() - cannot return aF",
                    (const struct ea *)(((&__0__V54)->__O1__2ea.p = ((const void *)__1cn)),
                                        (&__0__V54)),
                    (const struct ea *)(((&__0__V55)->__O1__2ea.p = ((const void *)__3tx)),
                                        (&__0__V55)),
                    (const struct ea *)ea0, (const struct ea *)ea0);
            }
            if (__3f->base__4node != 108) {
                struct ea __0__V56;

                struct ea __0__V57;

                error__FPCcRC2eaN32(
                    (const char *)"badT for%n::operator%t()",
                    (const struct ea *)(((&__0__V56)->__O1__2ea.p = ((const void *)__1cn)),
                                        (&__0__V56)),
                    (const struct ea *)(((&__0__V57)->__O1__2ea.p = ((const void *)__3tx)),
                                        (&__0__V57)),
                    (const struct ea *)ea0, (const struct ea *)ea0);
            }
            if (__3f->returns__3fct != (((struct type *)defa_type))) {
                {
                    struct ea __0__V58;

                    struct ea __0__V59;

                    error__FPCcRC2eaN32(
                        (const char *)"resultT for%n::operator%t()",
                        (const struct ea *)(((&__0__V58)->__O1__2ea.p = ((const void *)__1cn)),
                                            (&__0__V58)),
                        (const struct ea *)(((&__0__V59)->__O1__2ea.p = ((const void *)__3tx)),
                                            (&__0__V59)),
                        (const struct ea *)ea0, (const struct ea *)ea0);
                    if (__3f->returns__3fct && (__3f->returns__3fct->permanent__4node == 0))
                        del__4typeFv(__3f->returns__3fct);
                }
            }
            if (__3f->argtype__3fct || (__3f->nargs_known__3fct == 155)) {
                {
                    struct ea __0__V60;

                    struct ea __0__V61;

                    error__FPCcRC2eaN32(
                        (const char *)"%n::operator%t()WAs",
                        (const struct ea *)(((&__0__V60)->__O1__2ea.p = ((const void *)__1cn)),
                                            (&__0__V60)),
                        (const struct ea *)(((&__0__V61)->__O1__2ea.p = ((const void *)__3tx)),
                                            (&__0__V61)),
                        (const struct ea *)ea0, (const struct ea *)ea0);
                    __3f->argtype__3fct = 0;
                }
            }
            __3f->returns__3fct = __3tx;
            {
                char __3buf[1024];
                char *__3bb;
                int __3l2;

                __3bb = signature__4typeFPci(__3tx, (char *)__3buf, 0);
                __3l2 = (__3bb - __3buf);
                if (1023 < __3l2)
                    error__FiPCc((int)'i', (const char *)"N::check_oper():N buffer overflow");
                {
                    char *__3p;

                    __3p = (((char *)__nw__FUl((size_t)((sizeof(char)) * (__3l2 + 5)))));
                    (__3p[0]) = '_';
                    (__3p[1]) = '_';
                    (__3p[2]) = 'o';
                    (__3p[3]) = 'p';
                    strcpy(__3p + 4, (const char *)__3buf);
                    __0this->__O2__4expr.string = (const char *)__3p;
                }
            }
        }
        break;
    }
}

Pexpr vbase_args__FP3fctP4name(Pfct __1a, Pname __1bn) {
    Pfct __1b;

    Pexpr __1args;
    Pexpr __1tail;

    __1b = (((struct fct *)(((struct fct *)__1bn->__O1__4expr.tp))));

    __1args = 0;
    __1tail = 0;
    if (__1b->base__4node == 76)
        __1b = (((struct fct *)(((struct fct *)(((struct gen *)(((struct gen *)__1b))))
                                     ->fct_list__3gen->f__9name_list->__O1__4expr.tp))));
    {
        {
            Pname __1d;

            __1d = __1b->f_args__3fct->__O1__4name.n_list;

            for (; __1d != __1b->argtype__3fct; __1d = __1d->__O1__4name.n_list) {
                Pname __2dd;

                __2dd = __1a->f_args__3fct->__O1__4name.n_list;
                for (; __2dd; __2dd = __2dd->__O1__4name.n_list)
                    if (strcmp(__2dd->__O2__4expr.string, __1d->__O2__4expr.string) == 0)
                        break;

                {
                    Pexpr __2aa;

                    __2aa = __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)140,
                                                   (struct expr *)__2dd, (struct expr *)0);
                    if (__1args == 0)
                        __1args = __2aa;
                    else
                        __1tail->__O3__4expr.e2 = __2aa;
                    __1tail = __2aa;
                }
            }
            return __1args;
        }
    }
}

extern int error__FP3locPCcRC2eaN33(struct loc *, const char *, const struct ea *,
                                    const struct ea *, const struct ea *, const struct ea *);

Pname look__5tableFPCcUc(struct table *__0this, const char *, TOK);

Pexpr base_init__3fctFP8classdefP4exprP5tablei(struct fct *__0this, Pclass, Pexpr, Ptable, int);
Pexpr mem_init__3fctFP4nameP4exprP5table(struct fct *__0this, Pname, Pexpr, Ptable);

extern int error__FPCc(const char *);

extern int error__FiP3locPCcRC2eaN34(int, struct loc *, const char *, const struct ea *,
                                     const struct ea *, const struct ea *, const struct ea *);

void init_bases__3fctFP8classdefP4expr(register struct fct *__0this, Pclass __1cl, Pexpr __1__A76) {
    Ptable __1ftbl;

    const void *__2__X90;

    __1ftbl = __0this->body__3fct->memtbl__4stmt;
    ;

    if (((__1cl && (__1cl->csu__8classdef == 36)) && __0this->f_init__3fct) &&
        __0this->f_init__3fct->__O1__4name.n_list) {
        struct ea __0__V77;

        struct ea __0__V78;

        error__FP3locPCcRC2eaN33(
            &__0this->f_init__3fct->where__4name, (const char *)"multipleIrs in unionK %s:: %s",
            (const struct ea *)((__2__X90 = (const void *)__1cl->string__8classdef),
                                (((&__0__V77)->__O1__2ea.p = __2__X90), (&__0__V77))),
            (const struct ea *)__ct__2eaFPCv(&__0__V78, (const void *)__1cl->string__8classdef),
            (const struct ea *)ea0, (const struct ea *)ea0);
    }
    {
        {
            Pname __1nx;

            Pname __1nn;

            __1nn = __0this->f_init__3fct;

            for (; __1nn;
                 (((__1nn ? (((void)(__1nn ? (((void)((((((struct expr *)__1nn))
                                                            ? (((void)((((struct expr *)__1nn))
                                                                           ? (((void)(((void)0))))
                                                                           : (((void)0)))))
                                                            : (((void)0)))),
                                                      (((void)__dl__4nameSFPvUl(
                                                          (void *)__1nn,
                                                          (size_t)(sizeof(struct name))))))))
                                           : (((void)0)))))
                          : (((void)0)))),
                  (__1nn = __1nx))) {
                Pexpr __2i;

                __2i = __1nn->__O3__4expr.n_initializer;
                __1nn->__O3__4expr.n_initializer = 0;
                __1nx = __1nn->__O1__4name.n_list;

                if (__1nn->__O2__4expr.string) {
                    {
                        Pname __4mmm;

                        __4mmm = look__5tableFPCcUc(__1cl->memtbl__8classdef,
                                                    __1nn->__O2__4expr.string, (unsigned char)0);
                        if (__4mmm)
                            __1nn->base__4node = __4mmm->base__4node;
                    }
                    if (__1nn->base__4node == 123) {
                        const char *__4bn;
                        while (__1nn->__O1__4expr.tp && (__1nn->__O1__4expr.tp->base__4node == 97))
                            __1nn->__O1__4expr.tp =
                                (((struct basetype *)(((struct basetype *)__1nn->__O1__4expr.tp))))
                                    ->b_name__8basetype->__O1__4expr.tp;

                        if (__1nn->__O1__4expr.tp && (__1nn->__O1__4expr.tp->base__4node == 119))
                            __4bn =
                                (((struct basetype *)(((struct basetype *)__1nn->__O1__4expr.tp))))
                                    ->b_name__8basetype->__O2__4expr.string;
                        else
                            __4bn = __1nn->__O2__4expr.string;
                        {
                            {
                                Pbcl __4l;

                                const void *__2__X92;

                                __4l = __1cl->baselist__8classdef;

                                for (; __4l; __4l = __4l->next__6basecl) {
                                    Pclass __5bcl;

                                    register struct templ *__0__X91;

                                    __5bcl = __4l->bclass__6basecl;
                                    if ((strcmp(__5bcl->string__8classdef, __4bn) == 0) ||
                                        ((__5bcl->class_base__8classdef == 4) &&
                                         (strcmp(
                                              ((__0__X91 = (((struct templ_classdef *)((
                                                                (struct templ_classdef *)__5bcl))))
                                                               ->inst__14templ_classdef
                                                               ->def__10templ_inst),
                                               ((((struct classdef *)((
                                                   (struct classdef *)__0__X91->basep__5templ
                                                       ->b_name__8basetype->__O1__4expr.tp))))))
                                                  ->string__8classdef,
                                              __4bn) == 0))) {
                                        if (__4l->init__6basecl && (error_count == 0)) {
                                            struct ea __0__V79;

                                            error__FPCcRC2eaN32(
                                                (const char *)"twoIrs for%t",
                                                (const struct ea *)(((&__0__V79)->__O1__2ea.p =
                                                                         ((const void *)__5bcl)),
                                                                    (&__0__V79)),
                                                (const struct ea *)ea0, (const struct ea *)ea0,
                                                (const struct ea *)ea0);
                                        } else
                                            __4l->init__6basecl =
                                                base_init__3fctFP8classdefP4exprP5tablei(
                                                    __0this, __5bcl, __2i, __1ftbl,
                                                    __4l->obj_offset__6basecl);
                                        goto con;
                                    }
                                }
                                if (((__1nn->base__4node == 123) && (!__1nn->__O3__4expr.tpdef)) &&
                                    ((!__1nn->__O1__4expr.tp) ||
                                     ((__1nn->__O1__4expr.tp->base__4node != 119) &&
                                      (__1nn->__O1__4expr.tp->base__4node != 121)))) {
                                    struct ea __0__V80;

                                    error__FP3locPCcRC2eaN33(
                                        &__1nn->where__4name, (const char *)"unexpectedAL: noBC %s",
                                        (const struct ea *)((__2__X92 = (const void *)__1nn
                                                                            ->__O2__4expr.string),
                                                            (((&__0__V80)->__O1__2ea.p = __2__X92),
                                                             (&__0__V80))),
                                        (const struct ea *)ea0, (const struct ea *)ea0,
                                        (const struct ea *)ea0);
                                } else {
                                    struct ea __0__V81;

                                    error__FP3locPCcRC2eaN33(
                                        &__1nn->where__4name, (const char *)"unexpectedAL: noBC%n",
                                        (const struct ea *)(((&__0__V81)->__O1__2ea.p =
                                                                 ((const void *)__1nn)),
                                                            (&__0__V81)),
                                        (const struct ea *)ea0, (const struct ea *)ea0,
                                        (const struct ea *)ea0);
                                }
                            con:
                                continue;
                            }
                        }
                    } else {
                        Pname __4m;

                        __4m = look__5tableFPCcUc(__1cl->memtbl__8classdef,
                                                  __1nn->__O2__4expr.string, (unsigned char)0);
                        if (__4m && (__4m->__O4__4expr.n_table == __1cl->memtbl__8classdef))
                            __4m->__O3__4expr.n_initializer =
                                mem_init__3fctFP4nameP4exprP5table(__0this, __4m, __2i, __1ftbl);
                        else {
                            struct ea __0__V82;

                            struct ea __0__V83;

                            error__FP3locPCcRC2eaN33(
                                &__1nn->where__4name, (const char *)"%n not inC %s",
                                (const struct ea *)(((&__0__V82)->__O1__2ea.p =
                                                         ((const void *)__1nn)),
                                                    (&__0__V82)),
                                (const struct ea *)__ct__2eaFPCv(
                                    &__0__V83, (const void *)__1cl->string__8classdef),
                                (const struct ea *)ea0, (const struct ea *)ea0);
                        }
                    }
                } else {
                    Pbcl __3l;

                    const void *__2__X93;

                    __3l = __1cl->baselist__8classdef;
                    if (__3l == 0) {
                        error__FPCc((const char *)"unexpectedAL: noBC called");
                        continue;
                    }

                    if (__3l->next__6basecl) {
                        bit __4cnt;

                        bit __4rvb;

                        __4cnt = 0;

                        __4rvb = 0;
                        {
                            {
                                Pbcl __4ll;

                                __4ll = __3l;

                                for (; __4ll; ((__4ll = __4ll->next__6basecl), (++__4cnt)))
                                    if ((__4ll->base__4node == 77) && __4ll->promoted__6basecl)
                                        ++__4rvb;

                                if (__4rvb) {
                                    struct ea __0__V84;

                                    struct ea __0__V85;

                                    struct ea __0__V86;

                                    error__FPCcRC2eaN32(
                                        (const char
                                             *)"unnamedBCIr: %dBCes(%d non-explicit virtualBC%s)",
                                        (const struct ea *)(((((&__0__V84)->__O1__2ea.i =
                                                                   ((unsigned long)__4cnt)),
                                                              0)),
                                                            (&__0__V84)),
                                        (const struct ea *)(((((&__0__V85)->__O1__2ea.i =
                                                                   ((unsigned long)__4rvb)),
                                                              0)),
                                                            (&__0__V85)),
                                        (const struct ea
                                             *)(((&__0__V86)->__O1__2ea.p =
                                                     ((const void *)((__4rvb == 1)
                                                                         ? ""
                                                                         : (((char *)"es"))))),
                                                (&__0__V86)),
                                        (const struct ea *)ea0);
                                } else {
                                    struct ea __0__V87;

                                    error__FPCcRC2eaN32(
                                        (const char *)"unnamedBCIr: %dBCes",
                                        (const struct ea *)(((((&__0__V87)->__O1__2ea.i =
                                                                   ((unsigned long)__4cnt)),
                                                              0)),
                                                            (&__0__V87)),
                                        (const struct ea *)ea0, (const struct ea *)ea0,
                                        (const struct ea *)ea0);
                                }
                                continue;
                            }
                        }
                    }
                    if (__3l->init__6basecl) {
                        struct ea __0__V88;

                        error__FPCcRC2eaN32(
                            (const char *)"twoIrs for%t",
                            (const struct ea *)((__2__X93 = (const void *)__3l->bclass__6basecl),
                                                (((&__0__V88)->__O1__2ea.p = __2__X93),
                                                 (&__0__V88))),
                            (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
                    } else {
                        const void *__2__X94;

                        {
                            struct ea __0__V89;

                            error__FiP3locPCcRC2eaN34(
                                strict_opt ? 0 : 119, &__1nn->where__4name,
                                (const char *)"N ofBC%t missing from BCIr (anachronism)",
                                (const struct ea *)((__2__X94 =
                                                         (const void *)__3l->bclass__6basecl),
                                                    (((&__0__V89)->__O1__2ea.p = __2__X94),
                                                     (&__0__V89))),
                                (const struct ea *)ea0, (const struct ea *)ea0,
                                (const struct ea *)ea0);
                            __3l->init__6basecl = base_init__3fctFP8classdefP4exprP5tablei(
                                __0this, __3l->bclass__6basecl, __2i, __1ftbl,
                                __3l->obj_offset__6basecl);
                        }
                    }
                }
            }

            {
                {
                    Pbcl __1l;

                    __1l = __1cl->baselist__8classdef;

                    for (; __1l; __1l = __1l->next__6basecl) {
                        Pname __2ctor;
                        Pclass __2bcl;

                        __2bcl = __1l->bclass__6basecl;
                        if ((__1l->init__6basecl == 0) && (__2ctor = (__2bcl->c_ctor__8classdef)))
                            __1l->init__6basecl = base_init__3fctFP8classdefP4exprP5tablei(
                                __0this, __2bcl, (struct expr *)0, __1ftbl,
                                __1l->obj_offset__6basecl);
                    }
                }
            }
        }
    }
}

int inline_restr = 0;

struct table *__ct__5tableFsP5tableP4name(struct table *__0this, short, Ptable, Pname);

extern void for_check_delete__Fv(void);

void print_all_vtbls__8classdefFP8classdef(struct classdef *__0this, Pclass);

int tsizeof__4typeFi(struct type *__0this, int);

Pname dcl__4nameFP5tableUc(struct name *__0this, Ptable, TOK);

void dcl_print__4nameFUc(struct name *__0this, TOK);

bit inst_body__4nameFv(struct name *__0this);
bit finst_body__4nameFv(struct name *__0this);

void dcl__5blockFP5table(struct block *__0this, Ptable);

void simpl__4nameFv(struct name *__0this);

struct name_list *__ct__9name_listFP4nameP9name_list(struct name_list *__0this, Pname __1ff,
                                                     Plist __1ll);

void dcl__3fctFP4name(register struct fct *__0this, Pname __1n) {
    int __1nmem;
    Pname __1a;
    Pname __1ll;
    Ptable __1ftbl;

    int __1const_old;

    int __1bit_old;
    int __1byte_old;
    int __1max_old;

    unsigned long __2__X102;

    const void *__2__X103;

    unsigned long __2__X104;

    struct dcl_context *__0__X105;

    __1nmem = 20;

    __1const_old = const_save;

    __1bit_old = bit_offset;
    __1byte_old = byte_offset;
    __1max_old = max_align;

    if (__0this->base__4node != 108) {
        struct ea __0__V95;

        error__FiPCcRC2eaN33(
            (int)'i', (const char *)"F::dcl(%d)",
            (const struct ea *)((__2__X102 = __0this->base__4node),
                                (((((&__0__V95)->__O1__2ea.i = __2__X102), 0)), (&__0__V95))),
            (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
    }
    if (__0this->body__3fct == 0) {
        struct ea __0__V96;

        error__FiPCcRC2eaN33(
            (int)'i', (const char *)"F::dcl(body=%d)",
            (const struct ea *)((__2__X103 = (const void *)__0this->body__3fct),
                                (((&__0__V96)->__O1__2ea.p = __2__X103), (&__0__V96))),
            (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
    }
    if ((__1n == 0) || (__1n->base__4node != 85)) {
        struct ea __0__V97;

        struct ea __0__V98;

        error__FiPCcRC2eaN33(
            (int)'i', (const char *)"F::dcl(N=%d %d)",
            (const struct ea *)(((&__0__V97)->__O1__2ea.p = ((const void *)__1n)), (&__0__V97)),
            (const struct ea *)((__2__X104 = (__1n ? (((int)__1n->base__4node)) : 0)),
                                (((((&__0__V98)->__O1__2ea.i = __2__X104), 0)), (&__0__V98))),
            (const struct ea *)ea0, (const struct ea *)ea0);
    };
    if (__0this->body__3fct->__O2__4stmt.own_tbl)
        return;

    if (__0this->body__3fct->memtbl__4stmt == 0)
        __0this->body__3fct->memtbl__4stmt = __ct__5tableFsP5tableP4name(
            (struct table *)0, (short)(__1nmem + 3), gtbl, (struct name *)0);
    __0this->body__3fct->__O2__4stmt.own_tbl = 1;
    __1ftbl = __0this->body__3fct->memtbl__4stmt;
    __1ftbl->real_block__5table = (struct stmt *)__0this->body__3fct;
    ;
    for_check_delete__Fv();

    max_align = 0;
    bit_offset = 0;

    ((((cc++),
       (((cc >= ccvec_end) ? error__FiPCc((int)'i', (const char *)"ccvec buffer overflow") : 0),
        (((*cc)) = (*(cc - 1))))),
      (((void)0))));
    cc->nof__11dcl_context = __1n;
    cc->ftbl__11dcl_context = __1ftbl;

    switch (__1n->n_scope__4name) {
    case 0:
    case 25: {
        cc->not4__11dcl_context = __1n->__O4__4expr.n_table->t_name__5table;
        cc->cot__11dcl_context =
            (((struct classdef *)(((struct classdef *)cc->not4__11dcl_context->__O1__4expr.tp))));
        cc->tot__11dcl_context = cc->cot__11dcl_context->this_type__8classdef;
        if (__0this->f_this__3fct)
            __0this->f_this__3fct->__O4__4expr.n_table = __1ftbl;
        cc->c_this__11dcl_context = __0this->f_this__3fct;

        {
            Pclass __3cl;

            __3cl = ((
                (struct classdef *)(((struct classdef *)cc->not4__11dcl_context->__O1__4expr.tp))));

            if ((((((__3cl->c_body__8classdef == 3) && (__1n->__O3__4expr.n_initializer == 0)) &&
                   (__1n->n_sto__4name != 31)) &&
                  (__0this->f_inline__3fct == 0)) &&
                 (__0this->f_imeasure__3fct == 0)) &&
                (__0this->f_virtual__3fct != 0)) {
                int __4i;
                {
                    {
                        Pname __4nn;

                        struct table *__0__X106;

                        int __2__X107;

                        struct table *__0__X108;

                        int __2__X109;

                        __4nn =
                            ((__0__X108 = __3cl->memtbl__8classdef),
                             ((__2__X109 = (__4i = 1)),
                              ((((__2__X109 <= 0) || (__0__X108->free_slot__5table <= __2__X109))
                                    ? (((struct name *)0))
                                    : (__0__X108->entries__5table[__2__X109])))));

                        for (; __4nn;
                             __4nn =
                                 (__4nn->n_tbl_list__4name
                                      ? __4nn->n_tbl_list__4name
                                      : ((__0__X106 = __3cl->memtbl__8classdef),
                                         ((__2__X107 = (++__4i)),
                                          ((((__2__X107 <= 0) ||
                                             (__0__X106->free_slot__5table <= __2__X107))
                                                ? (((struct name *)0))
                                                : (__0__X106->entries__5table[__2__X107]))))))) {
                            if (__4nn->base__4node == 123)
                                continue;

                            {
                                Ptype __5t;

                                __5t = __4nn->__O1__4expr.tp;

                                if (__5t == 0)
                                    continue;

                                switch (__5t->base__4node) {
                                case 108:
                                    if (__4nn == __1n)
                                        goto prnt;
                                    if ((((__4nn->__O3__4expr.n_initializer ||
                                           (__4nn->n_sto__4name == 31)) ||
                                          (((struct fct *)(((struct fct *)__4nn->__O1__4expr.tp))))
                                              ->f_inline__3fct) ||
                                         (((struct fct *)(((struct fct *)__4nn->__O1__4expr.tp))))
                                             ->f_imeasure__3fct) ||
                                        ((((struct fct *)(((struct fct *)__4nn->__O1__4expr.tp))))
                                             ->f_virtual__3fct == 0))
                                        break;
                                    goto zaq;

                                case 76: {
                                    {
                                        {
                                            Plist __7gl;

                                            __7gl = (((struct gen *)(((struct gen *)__5t))))
                                                        ->fct_list__3gen;

                                            for (; __7gl; __7gl = __7gl->l__9name_list) {
                                                Pname __8nn;

                                                __8nn = __7gl->f__9name_list;
                                                if (__8nn == __1n)
                                                    goto prnt;
                                                if ((((__8nn->__O3__4expr.n_initializer ||
                                                       (__8nn->n_sto__4name == 31)) ||
                                                      (((struct fct *)((
                                                           (struct fct *)__8nn->__O1__4expr.tp))))
                                                          ->f_inline__3fct) ||
                                                     (((struct fct *)((
                                                          (struct fct *)__8nn->__O1__4expr.tp))))
                                                         ->f_imeasure__3fct) ||
                                                    ((((struct fct *)((
                                                          (struct fct *)__8nn->__O1__4expr.tp))))
                                                         ->f_virtual__3fct == 0))
                                                    continue;
                                                goto zaq;
                                            }
                                        }
                                    }
                                }
                                }
                            }
                        }
                        goto zaq;
                    prnt:
                        print_all_vtbls__8classdefFP8classdef(__3cl, __3cl);
                        goto zaq;
                    }
                }
            }
        }
    }
    }
zaq:
    if (__0this->f_result__3fct == 0)
        make_res__FP3fct(__0this);
    if (__0this->f_result__3fct)
        __0this->f_result__3fct->__O4__4expr.n_table = __1ftbl;

    tsizeof__4typeFi(__0this->returns__3fct, 0);

    {
        Pname __1ax;

        struct dcl_context *__0__X110;

        for (((__1a = __0this->argtype__3fct), (__1ll = 0)); __1a; __1a = __1ax) {
            __1ax = __1a->__O1__4name.n_list;
            {
                Pname __2nn;

                __2nn = dcl__4nameFP5tableUc(__1a, __1ftbl, (unsigned char)136);
                ++__2nn->lex_level__4name;
                {
                    Pname __2cn;

                    __2cn = is_cl_obj__4typeFv(__2nn->__O1__4expr.tp);
                    if (__2cn == 0)
                        __2cn = cl_obj_vec;
                    if (__2cn)
                        ((void)tsizeof__4typeFi(__2cn->__O1__4expr.tp, 0));
                    __2nn->n_assigned_to__4name =
                        (__2nn->n_used__4name = (__2nn->n_addr_taken__4name = 0));
                    __2nn->__O1__4name.n_list = 0;

                    switch (__2nn->__O1__4expr.tp->base__4node) {
                    case 6:
                    case 13:
                        dcl_print__4nameFUc(__2nn, (unsigned char)0);
                        break;
                    default:
                        if (__1ll)
                            __1ll->__O1__4name.n_list = __2nn;
                        else
                            __0this->f_args__3fct = (__0this->argtype__3fct = __2nn);
                        __1ll = __2nn;
                    }
                    ((__1a ? (((void)(__1a ? (((void)((((((struct expr *)__1a))
                                                            ? (((void)((((struct expr *)__1a))
                                                                           ? (((void)(((void)0))))
                                                                           : (((void)0)))))
                                                            : (((void)0)))),
                                                      (((void)__dl__4nameSFPvUl(
                                                          (void *)__1a,
                                                          (size_t)(sizeof(struct name))))))))
                                           : (((void)0)))))
                           : (((void)0))));
                }
            }
        }

        if (__0this->f_result__3fct) {
            __0this->f_args__3fct = __0this->f_result__3fct;
            __0this->f_result__3fct->__O1__4name.n_list = __0this->argtype__3fct;
        }

        if (__0this->f_this__3fct) {
            if (__0this->body__3fct)
                __0this->f_this__3fct->where__4name.line__3loc = __1n->where__4name.line__3loc;
            __0this->f_args__3fct = __0this->f_this__3fct;
            __0this->f_this__3fct->__O1__4name.n_list =
                (__0this->f_result__3fct ? __0this->f_result__3fct : __0this->argtype__3fct);
        }

        if ((__1n->n_oper__4name == 161) || (__1n->n_oper__4name == 162))
            vbase_pointers__FP4nameP8classdef(__1n, cc->cot__11dcl_context);

        if (__1n->n_oper__4name == 161) {
            const_save = 1;
            init_bases__3fctFP8classdefP4expr(__0this, cc->cot__11dcl_context,
                                              (struct expr *)__0this->f_init__3fct);
        } else if (__0this->f_init__3fct)
            error__FP3locPCcRC2eaN33(&__0this->f_init__3fct->where__4name,
                                     (const char *)"unexpectedAL: not aK", (const struct ea *)ea0,
                                     (const struct ea *)ea0, (const struct ea *)ea0,
                                     (const struct ea *)ea0);

        __0this->returns__3fct->permanent__4node = 1;
        const_save = (__0this->f_inline__3fct && (debug_opt == 0));
        inline_restr = 0;
        top_block = __0this->body__3fct;

        if (se_opt && ((inst_body__4nameFv(__1n) == 0) || (finst_body__4nameFv(__1n) == 0)))
            suppress_error++;

        dcl__5blockFP5table(__0this->body__3fct, __1ftbl);

        if (se_opt && ((inst_body__4nameFv(__1n) == 0) || (finst_body__4nameFv(__1n) == 0)))
            suppress_error--;

        __0this->defined__4type |= 01;
        if ((__0this->f_inline__3fct && inline_restr) &&
            (__0this->returns__3fct->base__4node != 38)) {
            __0this->f_inline__3fct = 0;
            {
                const char *__2s;

                __2s =
                    (const char
                         *)((inline_restr & 32)
                                ? "continue"
                                : (((char
                                         *)((inline_restr & 16)
                                                ? "break"
                                                : (((char
                                                         *)((inline_restr & 8)
                                                                ? "loop"
                                                                : (((char
                                                                         *)((inline_restr & 4)
                                                                                ? "switch"
                                                                                : (((char
                                                                                         *)((inline_restr &
                                                                                             2)
                                                                                                ? "goto"
                                                                                                : (((char
                                                                                                         *)((inline_restr &
                                                                                                             1)
                                                                                                                ? "label"
                                                                                                                : (((char
                                                                                                                         *)""))))))))))))))))));

                if (warning_opt) {
                    {
                        struct ea __0__V99;

                        struct ea __0__V100;

                        error__FiPCcRC2eaN33(
                            (int)'w', (const char *)"\"inline\" ignored,%n contains %s",
                            (const struct ea *)(((&__0__V99)->__O1__2ea.p = ((const void *)__1n)),
                                                (&__0__V99)),
                            (const struct ea *)(((&__0__V100)->__O1__2ea.p = ((const void *)__2s)),
                                                (&__0__V100)),
                            (const struct ea *)ea0, (const struct ea *)ea0);
                        {
                            struct ea __0__V101;

                            error__FiPCcRC2eaN33((int)'w',
                                                 (const char *)"out-of-line copy of%n created",
                                                 (const struct ea *)(((&__0__V101)->__O1__2ea.p =
                                                                          ((const void *)__1n)),
                                                                     (&__0__V101)),
                                                 (const struct ea *)ea0, (const struct ea *)ea0,
                                                 (const struct ea *)ea0);
                        }
                    }
                }
                simpl__4nameFv(__1n);
                if ((cc->cot__11dcl_context &&
                     (cc->cot__11dcl_context->class_base__8classdef == 4)) &&
                    (cc->cot__11dcl_context->c_body__8classdef == 1)) {
                    current_instantiation = cc->cot__11dcl_context;

                    dcl_print__4nameFUc(cc->not4__11dcl_context, (unsigned char)0);
                    current_instantiation = 0;
                }
                dcl_print__4nameFUc(__1n, (unsigned char)0);
            }
        }
        const_save = __1const_old;

        if (__0this->f_inline__3fct && (debug_opt == 0)) {
            if (dtpt_opt && (inst_body__4nameFv(__1n) == 0)) {
                unsigned long __2__X16;

                struct ea __0__X__V1400qmhxl1b4vcnm;

                struct ea __0__X__V1500qmhxl1b4vcnm;

                __0this->f_inline__3fct = 0;
                (((__1n->__O1__4expr.tp->base__4node == 108)
                      ? (((struct fct *)(((struct fct *)__1n->__O1__4expr.tp))))
                      : (error__FiPCcRC2eaN33(
                             (int)'i', (const char *)"N::fct_type():%n is %k notF",
                             (const struct ea *)(((&__0__X__V1400qmhxl1b4vcnm)->__O1__2ea.p =
                                                      ((const void *)__1n)),
                                                 (&__0__X__V1400qmhxl1b4vcnm)),
                             (const struct ea
                                  *)((__2__X16 = __1n->__O1__4expr.tp->base__4node),
                                     (((((&__0__X__V1500qmhxl1b4vcnm)->__O1__2ea.i = __2__X16), 0)),
                                      (&__0__X__V1500qmhxl1b4vcnm))),
                             (const struct ea *)ea0, (const struct ea *)ea0),
                         (((struct fct *)0)))))
                    ->body__3fct = 0;
            }
            isf_list = __ct__9name_listFP4nameP9name_list((struct name_list *)0, __1n, isf_list);
        }

        bit_offset = __1bit_old;
        byte_offset = __1byte_old;
        max_align = __1max_old;
        (((cc--), (((void)0))));
    }
}

Pexpr this_handler = 0;

extern Pexpr rptr__FP4typeP4expri(Ptype, Pexpr, int);

Pexpr typ__4exprFP5table(struct expr *__0this, Ptable);

bit has_base__8classdefFP8classdefiT2(struct classdef *__0this, Pclass __1cl, int __1level,
                                      int __1ccflag);

Pexpr contents__4exprFv(struct expr *__0this);

extern Pexpr call_ctor__FP5tableP4exprN22iT2(Ptable, Pexpr __0p, Pexpr __0ctor, Pexpr __0args,
                                             int __0d, Pexpr __0vb_args);

Pexpr base_init__3fctFP8classdefP4exprP5tablei(register struct fct *__0this, Pclass __1bcl,
                                               Pexpr __1i, Ptable __1ftbl, int __1offset) {
    Ptype __1ty;
    Pexpr __1th;
    Pname __1ctor;

    Pexpr __1ii;

    Pname __1icn;

    __1ty = __1bcl->this_type__8classdef;
    __1th = rptr__FP4typeP4expri(__1ty, (struct expr *)__0this->f_this__3fct, __1offset);
    __1ctor = (__1bcl->c_ctor__8classdef);

    __1ii = ((__1i && (__1i->base__4node == 140)) ? __1i->__O2__4expr.e1 : __1i);

    if (((__1ii && (__1ii->base__4node == 111)) && ((__1ii->__O2__4expr.e1->base__4node == 113) ||
                                                    (__1ii->__O2__4expr.e1->base__4node == 191))) &&
        ((__1th->base__4node == 113) || (__1th->base__4node == 191)))
        __1th->__O3__4expr.i2 = __1ii->__O2__4expr.e1->__O3__4expr.i2;

    if (__1ctor == 0) {
        if (__1i && (__1i->base__4node != 140))
            __1i = __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)140, __1i,
                                          (struct expr *)0);

        {
            Pexpr __2v;

            struct texpr *__0__X113;

            __2v = (struct expr *)((__0__X113 = 0),
                                   (((__0__X113 || (__0__X113 = (struct texpr *)__nw__4exprSFUl(
                                                        (size_t)(sizeof(struct texpr)))))
                                         ? ((__0__X113 = (struct texpr *)__ct__4exprFUcP4exprT2(
                                                 ((struct expr *)__0__X113), ((unsigned char)157),
                                                 __1i, (struct expr *)0)),
                                            (__0__X113->__O4__4expr.tp2 = ((struct type *)__1bcl)))
                                         : 0),
                                    __0__X113));
            __2v->__O3__4expr.e2 = __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)111,
                                                          __1th, (struct expr *)0);
            __2v = typ__4exprFP5table(__2v, __1ftbl);

            switch (__2v->base__4node) {
                struct texpr *__0__X111;

                struct expr *__2__X112;

            case 111:
                return __2v->__O2__4expr.e1;
            case 70:
                __1th =
                    (struct expr *)((__0__X111 = 0),
                                    ((__2__X112 = (struct expr *)__0this->f_this__3fct),
                                     (((__0__X111 || (__0__X111 = (struct texpr *)__nw__4exprSFUl(
                                                          (size_t)(sizeof(struct texpr)))))
                                           ? ((__0__X111 = (struct texpr *)__ct__4exprFUcP4exprT2(
                                                   ((struct expr *)__0__X111), ((unsigned char)191),
                                                   __2__X112, (struct expr *)0)),
                                              (__0__X111->__O4__4expr.tp2 = __1ty))
                                           : 0),
                                      __0__X111)));
                __2v = __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)71, __2v, __1th);
                return typ__4exprFP5table(__2v, __1ftbl);
            default:
                return (struct expr *)0;
            }
        }
    }

    ;
    if (__1i) {
        int __2na;

        struct classdef *__1__X114;

        struct classdef *__1__X115;

        __2na = ((__1i->base__4node != 140) ? 1 : ((__1i->__O3__4expr.e2 != 0) ? 2 : 1));
        __1ii = typ__4exprFP5table(__1ii, __1ftbl);
        if (((((__1bcl->c_itor__8classdef) == 0) &&
              (__1icn = is_cl_obj__4typeFv(__1ii->__O1__4expr.tp))) &&
             (__2na == 1)) &&
            (((__1__X114 = (((struct classdef *)(((struct classdef *)__1icn->__O1__4expr.tp))))),
              ((__1__X115 = __1bcl),
               (((__1__X114 == __1__X115)
                     ? 1
                     : ((__1__X114 && __1__X115)
                            ? (((int)same_class__8classdefFP8classdefi(__1__X114, __1__X115, 0)))
                            : 0))))) ||
             has_base__8classdefFP8classdefiT2(
                 ((struct classdef *)(((struct classdef *)__1icn->__O1__4expr.tp))), __1bcl, 0,
                 0))) {
            struct texpr *__0__X116;

            struct expr *__2__X117;

            struct classdef *__1__X118;

            struct classdef *__1__X119;

            this_handler = __1th;
            __1th = (struct expr *)((__0__X116 = 0),
                                    ((__2__X117 = (struct expr *)__0this->f_this__3fct),
                                     (((__0__X116 || (__0__X116 = (struct texpr *)__nw__4exprSFUl(
                                                          (size_t)(sizeof(struct texpr)))))
                                           ? ((__0__X116 = (struct texpr *)__ct__4exprFUcP4exprT2(
                                                   ((struct expr *)__0__X116), ((unsigned char)191),
                                                   __2__X117, (struct expr *)0)),
                                              (__0__X116->__O4__4expr.tp2 = __1ty))
                                           : 0),
                                      __0__X116)));
            __1th = contents__4exprFv(__1th);
            __1th = typ__4exprFP5table(__1th, __1ftbl);
            if (!((__1__X118 =
                       (((struct classdef *)(((struct classdef *)__1icn->__O1__4expr.tp))))),
                  ((__1__X119 = __1bcl),
                   (((__1__X118 == __1__X119)
                         ? 1
                         : ((__1__X118 && __1__X119) ? (((int)same_class__8classdefFP8classdefi(
                                                           __1__X118, __1__X119, 0)))
                                                     : 0)))))) {
                Pptr __4r;

                struct texpr *__0__X120;

                __4r = __ct__3ptrFUcP4type((struct ptr *)0, (unsigned char)158,
                                           (((struct ptr *)(((struct ptr *)__1ty))))->typ__5pvtyp);
                __1ii =
                    (struct expr *)((__0__X120 = 0),
                                    (((__0__X120 || (__0__X120 = (struct texpr *)__nw__4exprSFUl(
                                                         (size_t)(sizeof(struct texpr)))))
                                          ? ((__0__X120 = (struct texpr *)__ct__4exprFUcP4exprT2(
                                                  ((struct expr *)__0__X120), ((unsigned char)191),
                                                  __1ii, (struct expr *)0)),
                                             (__0__X120->__O4__4expr.tp2 = ((struct type *)__4r)))
                                          : 0),
                                     __0__X120));
                __1ii = typ__4exprFP5table(__1ii, __1ftbl);
            }
            __1ii = __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)70, __1th, __1ii);
            __1ii->__O1__4expr.tp = __1th->__O1__4expr.tp;

            __1ii =
                __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)71, __1ii, this_handler);
            this_handler = 0;
            __1ii->__O1__4expr.tp = __1ty;

            return __1ii;
        }
        if (__1i->base__4node == 140)
            __1i->__O2__4expr.e1 = __1ii;
    }

    return call_ctor__FP5tableP4exprN22iT2(__1ftbl, __1th, (struct expr *)__1ctor, __1i, 44,
                                           vbase_args__FP3fctP4name(__0this, __1ctor));
}

void assign__4nameFv(struct name *__0this);

Pptr is_ref__4typeFv(struct type *__0this);

bit tconst__4typeFv(struct type *__0this);

extern Pexpr ptr_init__FP3ptrP4exprP5table(Pptr, Pexpr, Ptable);

extern Pexpr ref_init__FP3ptrP4exprP5table(Pptr, Pexpr, Ptable);

Pexpr mem_init__3fctFP4nameP4exprP5table(register struct fct *__0this, Pname __1mn, Pexpr __1i,
                                         Ptable __1ftbl) {
    switch (__1mn->n_stclass__4name) {
    case 31: {
        struct ea __0__V121;

        error__FPCcRC2eaN32(
            (const char *)"MIr for static%n",
            (const struct ea *)(((&__0__V121)->__O1__2ea.p = ((const void *)__1mn)), (&__0__V121)),
            (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
        break;
    case 13: {
        struct ea __0__V122;

        error__FPCcRC2eaN32(
            (const char *)"MIr for enumeration constant%n",
            (const struct ea *)(((&__0__V122)->__O1__2ea.p = ((const void *)__1mn)), (&__0__V122)),
            (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
        break;
    }
    }
    }

    {
        Pname __1member;

        __1member = (((__1mn->base__4node == 25) && __1mn->__O2__4name.n_qualifier)
                         ? __1mn->__O2__4name.n_qualifier
                         : __1mn);

        if (__1i)
            __1i = typ__4exprFP5table(__1i, __1ftbl);

        {
            Pname __1cn;
            Pref __1tn;

            Pptr __1pt;

            struct ref *__0__X136;

            struct expr *__2__X137;

            struct expr *__2__X138;

            __1cn = is_cl_obj__4typeFv(__1member->__O1__4expr.tp);
            __1tn = ((__0__X136 = 0),
                     ((__2__X137 = (struct expr *)__0this->f_this__3fct),
                      ((__2__X138 = (struct expr *)__1member),
                       (((__0__X136 ||
                          (__0__X136 = (struct ref *)__nw__4exprSFUl((size_t)(sizeof(struct ref)))))
                             ? ((__0__X136 = (struct ref *)__ct__4exprFUcP4exprT2(
                                     ((struct expr *)__0__X136), ((unsigned char)44), __2__X137,
                                     (struct expr *)0)),
                                (__0__X136->__O4__4expr.mem = __2__X138))
                             : 0),
                        __0__X136))));

            __1tn->__O1__4expr.tp = __1member->__O1__4expr.tp;

            if (__1cn) {
                Pclass __2mcl;
                Pname __2ctor;
                Pname __2icn;

                struct classdef *__1__X132;

                struct classdef *__1__X133;

                __2mcl = (((struct classdef *)(((struct classdef *)__1cn->__O1__4expr.tp))));
                __2ctor = (__2mcl->c_ctor__8classdef);

                if (((__1i && ((__2mcl->c_itor__8classdef) == 0)) &&
                     (__2icn = is_cl_obj__4typeFv(__1i->__O1__4expr.tp))) &&
                    ((__1__X132 =
                          (((struct classdef *)(((struct classdef *)__2icn->__O1__4expr.tp))))),
                     ((__1__X133 = __2mcl),
                      (((__1__X132 == __1__X133)
                            ? 1
                            : ((__1__X132 && __1__X133) ? (((int)same_class__8classdefFP8classdefi(
                                                              __1__X132, __1__X133, 0)))
                                                        : 0)))))) {
                    Pexpr __3init;

                    __3init = __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)70,
                                                     (struct expr *)__1tn, __1i);
                    __3init->__O1__4expr.tp = __1tn->__O1__4expr.tp;
                    assign__4nameFv(__1member);
                    return __3init;
                }

                if (__2ctor)
                    return call_ctor__FP5tableP4exprN22iT2(__1ftbl, (struct expr *)__1tn,
                                                           (struct expr *)__2ctor, __1i, 45,
                                                           (struct expr *)0);

                {
                    struct ea __0__V123;

                    error__FPCcRC2eaN32(
                        (const char *)"Ir forM%nW noK",
                        (const struct ea *)(((&__0__V123)->__O1__2ea.p = ((const void *)__1member)),
                                            (&__0__V123)),
                        (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
                    return (struct expr *)0;
                }
            }

            if (cl_obj_vec) {
                const void *__2__X134;

                const void *__2__X135;

                if (__1i && (__1i->base__4node == 140)) {
                    struct ea __0__V124;

                    struct ea __0__V125;

                    error__FPCcRC2eaN32(
                        (const char *)"illegalIrL for %t%nWinM initializationL",
                        (const struct ea *)((__2__X134 = (const void *)__1mn->__O1__4expr.tp),
                                            (((&__0__V124)->__O1__2ea.p = __2__X134),
                                             (&__0__V124))),
                        (const struct ea *)(((&__0__V125)->__O1__2ea.p = ((const void *)__1mn)),
                                            (&__0__V125)),
                        (const struct ea *)ea0, (const struct ea *)ea0);
                } else {
                    struct ea __0__V126;

                    struct ea __0__V127;

                    error__FiPCcRC2eaN33(
                        (int)'s', (const char *)"Ir forCM %t%nWK",
                        (const struct ea *)((__2__X135 = (const void *)__1mn->__O1__4expr.tp),
                                            (((&__0__V126)->__O1__2ea.p = __2__X135),
                                             (&__0__V126))),
                        (const struct ea *)(((&__0__V127)->__O1__2ea.p = ((const void *)__1mn)),
                                            (&__0__V127)),
                        (const struct ea *)ea0, (const struct ea *)ea0);
                }
                return (struct expr *)0;
            }

            if (__1i && (__1i->base__4node == 140)) {
                if (__1i->__O3__4expr.e2) {
                    struct ea __0__V128;

                    error__FPCcRC2eaN32(
                        (const char *)"Ir for%n not a simpleE",
                        (const struct ea *)(((&__0__V128)->__O1__2ea.p = ((const void *)__1member)),
                                            (&__0__V128)),
                        (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
                }
                __1i = __1i->__O2__4expr.e1;
            }

            if (is_ref__4typeFv(__1member->__O1__4expr.tp) && (__1i == 0)) {
                {
                    struct ea __0__V129;

                    error__FPCcRC2eaN32(
                        (const char *)"emptyIr for reference%n",
                        (const struct ea *)(((&__0__V129)->__O1__2ea.p = ((const void *)__1member)),
                                            (&__0__V129)),
                        (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
                    return (struct expr *)0;
                }
            }

            switch (__1member->__O1__4expr.tp->base__4node) {
            case 110:
            case 108:
            case 76: {
                struct ea __0__V130;

                struct ea __0__V131;

                error__FPCcRC2eaN32(
                    (const char *)"Ir for%n ofT %t",
                    (const struct ea *)(((&__0__V130)->__O1__2ea.p = ((const void *)__1member)),
                                        (&__0__V130)),
                    (const struct ea *)__ct__2eaFPCv(&__0__V131,
                                                     (const void *)__1member->__O1__4expr.tp),
                    (const struct ea *)ea0, (const struct ea *)ea0);
                return (struct expr *)0;
            }
            }

            if (tconst__4typeFv(__1member->__O1__4expr.tp)) {
                ignore_const++;
                __1i = __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)70,
                                              (struct expr *)__1tn, __1i);
                __1i = typ__4exprFP5table(__1i, __1ftbl);
                ignore_const--;
                return __1i;
            }

            ;
            if (__1pt = is_ref__4typeFv(__1member->__O1__4expr.tp)) {
                switch (__1pt->typ__5pvtyp->base__4node) {
                case 108:
                case 76:
                    __1i = ptr_init__FP3ptrP4exprP5table(__1pt, __1i, __1ftbl);
                    break;
                default:
                    __1i = ref_init__FP3ptrP4exprP5table(__1pt, __1i, __1ftbl);
                }
                __1i = __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)70,
                                              (struct expr *)__1tn, __1i);
                __1i->__O1__4expr.tp = __1tn->__O1__4expr.tp;
                assign__4nameFv(__1member);
                return __1i;
            }

            __1i = __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)70, (struct expr *)__1tn,
                                          __1i);
            return typ__4exprFP5table(__1i, __1ftbl);
        }
    }
}

Pexpr replace_temp__FP4exprT1(Pexpr __1e, Pexpr __1n) {
    Pexpr __1c;
    Pexpr __1ff;
    Pexpr __1a;
    Pexpr __1tmp;

    __1c = __1e->__O2__4expr.e1;
    __1ff = __1c->__O2__4expr.e1;
    __1a = __1c->__O3__4expr.e2;
    __1tmp = __1e->__O3__4expr.e2;

    if (__1tmp->base__4node == 111)
        __1tmp = __1tmp->__O2__4expr.e1;
    if ((__1tmp->base__4node == 113) || (__1tmp->base__4node == 191))
        __1tmp = __1tmp->__O2__4expr.e1;
    if ((__1tmp->base__4node == 112) || (__1tmp->base__4node == 145))
        __1tmp = __1tmp->__O3__4expr.e2;
    if (__1tmp->base__4node != 85)
        return __1e;
    __1tmp->__O1__4expr.tp = (struct type *)any_type;

    switch (__1ff->base__4node) {
    case 44:
        if ((__1ff->__O2__4expr.e1->base__4node == 145) &&
            (__1ff->__O2__4expr.e1->__O3__4expr.e2 == __1tmp))
            __1a = __1ff;

        break;
    case 45:
        if ((__1ff->__O2__4expr.e1->base__4node == 85) && (__1ff->__O2__4expr.e1 == __1tmp)) {
            __1a = __1ff;
            __1a->base__4node = 44;
        }
        break;
    }
    __1a->__O2__4expr.e1 = __1n;
    return __1c;
}

Pname has_ictor__8classdefFv(register struct classdef *__0this) {
    Pname __1c;

    __1c = (__0this->c_ctor__8classdef);
    if (__1c == 0)
        return (struct name *)0;

    {
        Pfct __1f;

        __1f = (((struct fct *)(((struct fct *)__1c->__O1__4expr.tp))));

        switch (__1f->base__4node) {
            const void *__2__X141;

            unsigned long __2__X142;

        default: {
            struct ea __0__V139;

            struct ea __0__V140;

            error__FiPCcRC2eaN33(
                (int)'i', (const char *)"%s: badK (%k)",
                (const struct ea *)((__2__X141 = (const void *)__0this->string__8classdef),
                                    (((&__0__V139)->__O1__2ea.p = __2__X141), (&__0__V139))),
                (const struct ea *)((__2__X142 = __1c->__O1__4expr.tp->base__4node),
                                    (((((&__0__V140)->__O1__2ea.i = __2__X142), 0)), (&__0__V140))),
                (const struct ea *)ea0, (const struct ea *)ea0);

        case 108:
            switch (__1f->nargs__3fct) {
            case 0:
                return __1c;
            default:
                if (__1f->argtype__3fct->__O3__4expr.n_initializer)
                    return __1c;
            }
            return (struct name *)0;

        case 76: {
            {
                {
                    Plist __3l;

                    __3l = (((struct gen *)(((struct gen *)__1f))))->fct_list__3gen;

                    for (; __3l; __3l = __3l->l__9name_list) {
                        Pname __4n;

                        __4n = __3l->f__9name_list;
                        __1f = (((struct fct *)(((struct fct *)__4n->__O1__4expr.tp))));
                        switch (__1f->nargs__3fct) {
                        case 0:
                            return __4n;
                        default:
                            if (__1f->argtype__3fct->__O3__4expr.n_initializer)
                                return __4n;
                        }
                    }
                    return (struct name *)0;
                }
            }
        }
        }
        }
    }
}

int add_first = 0;
static int add_without_find;

Pname find__3genFP3fctUc(struct gen *__0this, Pfct, bit);

void sign__3fctFv(struct fct *__0this);

Pname add__3genFP4name(register struct gen *__0this, Pname __1n) {
    Pfct __1f;
    Pname __1nx;

    __1f = (((struct fct *)(((struct fct *)__1n->__O1__4expr.tp))));

    if (__1f->base__4node != 108) {
        struct ea __0__V143;

        error__FPCcRC2eaN32(
            (const char *)"%n: overloaded nonF",
            (const struct ea *)(((&__0__V143)->__O1__2ea.p = ((const void *)__1n)), (&__0__V143)),
            (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
    }
    if (((__1f->fct_base__3fct != 0))) {
        if (!((__0this->holds_templ__3gen != 0))) {

            if (__0this->fct_list__3gen)
                __0this->holds_templ__3gen = 1;
            else
                __0this->holds_templ__3gen = 2;
        }
    } else {
        if (((__0this->holds_templ__3gen == 2)))
            __0this->holds_templ__3gen = 1;
    }

    if ((__0this->fct_list__3gen && (add_without_find == 0)) &&
        (__1nx = find__3genFP3fctUc(__0this, __1f, (unsigned char)1))) {
        int __2l1;
        int __2l2;

        __2l1 = (((struct fct *)(((struct fct *)__1nx->__O1__4expr.tp))))->f_linkage__3fct;
        __2l2 = __1f->f_linkage__3fct;
        if ((__2l2 != 0) && (__2l1 != __2l2)) {
            struct ea __0__V144;

            error__FPCcRC2eaN32(
                (const char *)"inconsistent linkage specifications for%n",
                (const struct ea *)(((&__0__V144)->__O1__2ea.p = ((const void *)__1n)),
                                    (&__0__V144)),
                (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
        }
        Nold = 1;
    } else {
        if (((add_first == 0) && (__1f->f_signature__3fct == 0)) && (__1f->fct_base__3fct != 1))
            sign__3fctFv(__1f);

        __1nx = __ct__4nameFPCc((struct name *)0, (const char *)0);
        ((*__1nx)) = (*__1n);
        __1nx->n_gen_fct_name__4name = __1n->__O2__4expr.string;
        __1nx->permanent__4node = 1;
        Nold = 0;
        if (__0this->fct_list__3gen) {
            int __3clink;
            Plist __3gl;

            __3clink = (__1f->f_linkage__3fct == 1);
            __3gl = __0this->fct_list__3gen;
            for (;;) {
                if (__3clink &&
                    ((((struct fct *)(((struct fct *)__3gl->f__9name_list->__O1__4expr.tp))))
                         ->f_linkage__3fct == 1)) {
                    {
                        struct ea __0__V145;

                        error__FPCcRC2eaN32(
                            (const char *)"two%ns with c linkage",
                            (const struct ea *)(((&__0__V145)->__O1__2ea.p = ((const void *)__1n)),
                                                (&__0__V145)),
                            (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
                        if (__1f->f_signature__3fct == 0)
                            sign__3fctFv(__1f);
                    }
                }
                if (__3gl->l__9name_list)
                    __3gl = __3gl->l__9name_list;
                else
                    break;
            }
            __3gl->l__9name_list = __ct__9name_listFP4nameP9name_list((struct name_list *)0, __1nx,
                                                                      (struct name_list *)0);
        } else
            __0this->fct_list__3gen = __ct__9name_listFP4nameP9name_list(
                (struct name_list *)0, __1nx, (struct name_list *)0);
        __1nx->__O1__4name.n_list = 0;
    }
    return __1nx;
}

void sign__3fctFv(register struct fct *__0this) {
    switch (__0this->f_linkage__3fct) {
    case 1:
        __0this->f_signature__3fct = (const char *)"";

        return;
    case 2:
    case 0:
        break;
    }
    {
        char __1buf[1024];
        char *__1bb;
        int __1ll;

        __1bb = signature__4typeFPci((struct type *)__0this, (char *)__1buf, 0);
        __1ll = (__1bb - __1buf);
        if (1023 < __1ll)
            error__FiPCc((int)'i', (const char *)"gen::add():N buffer overflow");
        {
            char *__1p;

            __1p = (((char *)__nw__FUl((size_t)((sizeof(char)) * (__1ll + 1)))));
            strcpy(__1p, (const char *)__1buf);
            __0this->f_signature__3fct = (const char *)__1p;
        }
    }
}

Pname match__3genFP4nameP3fctUc(struct gen *__0this, Pname, Pfct, bit);

Pname find__3genFP3fctUc(register struct gen *__0this, Pfct __1f, bit __1warn) {
    {
        {
            Plist __1gl;

            __1gl = __0this->fct_list__3gen;

            for (; __1gl; __1gl = __1gl->l__9name_list) {
                Pname __2n;

                __2n = match__3genFP4nameP3fctUc(__0this, __1gl->f__9name_list, __1f, __1warn);
                if (__2n)
                    return __2n;
            }
            return (struct name *)0;
        }
    }
}

bit check__4typeFP4typeUcT2(struct type *__0this, Ptype, TOK, bit);

Pptr is_ptr__4typeFv(struct type *__0this);

Pname match__3genFP4nameP3fctUc(register struct gen *__0this, Pname __1nx, Pfct __1f, bit __1warn) {
    Pfct __1fx;
    Pname __1a;

    Pname __1ax;
    int __1op;

    __1fx = (((struct fct *)(((struct fct *)__1nx->__O1__4expr.tp))));

    __1op = 0;

    if (((__1f->fct_base__3fct != 0)))
        return (struct name *)0;
    if (((__1fx->fct_base__3fct != 0)))
        return (struct name *)0;

    if (__1f->nargs_known__3fct != __1fx->nargs_known__3fct)
        return (struct name *)0;

    if (__1f->f_const__3fct != __1fx->f_const__3fct)
        return (struct name *)0;

    if (((__1fx->nargs__3fct != __1f->nargs__3fct) && (__1fx->nargs_known__3fct == 1)) &&
        (__1f->nargs_known__3fct == 1))
        return (struct name *)0;

    for (((__1ax = __1fx->argtype__3fct), (__1a = __1f->argtype__3fct)); __1a && __1ax;
         ((__1ax = __1ax->__O1__4name.n_list), (__1a = __1a->__O1__4name.n_list))) {
        Ptype __2at;
        Ptype __2atp;

        __2at = __1ax->__O1__4expr.tp;
        __2atp = __1a->__O1__4expr.tp;

        if (check__4typeFP4typeUcT2(__2at, __2atp, (unsigned char)204, (unsigned char)0) == 0) {
            continue;
        }

        if (__1warn == 0)
            goto xx;

        __2at = skiptypedefs__4typeFv(__2at);
        __2atp = skiptypedefs__4typeFv(__2atp);

        if (const_problem) {
            if ((is_ptr__4typeFv(__2at) && is_ptr__4typeFv(__2atp)) ||
                (is_ref__4typeFv(__2at) && is_ref__4typeFv(__2atp))) {
                Ptype __4ap;
                Ptype __4app;

                __4ap = (((struct ptr *)(((struct ptr *)__2at))))->typ__5pvtyp;
                __4app = (((struct ptr *)(((struct ptr *)__2atp))))->typ__5pvtyp;
                if (check__4typeFP4typeUcT2(__4ap, __4app, (unsigned char)204, (unsigned char)0) !=
                    0)
                    return (struct name *)0;
            }
            __1op++;
            continue;
        }

        if (__2atp->base__4node == 158) {
            if ((check__4typeFP4typeUcT2((((struct ptr *)(((struct ptr *)__2atp))))->typ__5pvtyp,
                                         __2at, (unsigned char)255, (unsigned char)0) == 0) ||
                (const_problem &&
                 ((is_ptr__4typeFv(__2at) == 0) ||
                  (tconst__4typeFv(__2at) !=
                   tconst__4typeFv((((struct ptr *)(((struct ptr *)__2atp))))->typ__5pvtyp))))) {
                __1op++;
                continue;
            }
        }

        if (__2at->base__4node == 158) {
            if ((check__4typeFP4typeUcT2((((struct ptr *)(((struct ptr *)__2at))))->typ__5pvtyp,
                                         __2atp, (unsigned char)255, (unsigned char)0) == 0) ||
                (const_problem &&
                 ((is_ptr__4typeFv(__2atp) == 0) ||
                  (tconst__4typeFv(__2atp) !=
                   tconst__4typeFv((((struct ptr *)(((struct ptr *)__2at))))->typ__5pvtyp))))) {
                __1op++;
                continue;
            }
            break;
        }

        return (struct name *)0;
    }

    if (__1a || __1ax)
        return (struct name *)0;

    if (__1op == 0) {
        if (__1warn && check__4typeFP4typeUcT2(__1fx->returns__3fct, __1f->returns__3fct,
                                               (unsigned char)255, (unsigned char)0)) {
            struct ea __0__V146;

            struct ea __0__V147;

            struct ea __0__V148;

            error__FPCcRC2eaN32(
                (const char *)"two different return valueTs for%n: %t and %t",
                (const struct ea *)(((&__0__V146)->__O1__2ea.p = ((const void *)__1nx)),
                                    (&__0__V146)),
                (const struct ea *)__ct__2eaFPCv(&__0__V147, (const void *)__1fx->returns__3fct),
                (const struct ea *)__ct__2eaFPCv(&__0__V148, (const void *)__1f->returns__3fct),
                (const struct ea *)ea0);
        }
        return __1nx;
    }
xx:
    if (__1warn && __1op) {
        struct ea __0__V149;

        struct ea __0__V150;

        error__FPCcRC2eaN32(
            (const char *)"the overloading mechanism cannot tell a%t from a%t",
            (const struct ea *)(((&__0__V149)->__O1__2ea.p = ((const void *)__1fx)), (&__0__V149)),
            (const struct ea *)(((&__0__V150)->__O1__2ea.p = ((const void *)__1f)), (&__0__V150)),
            (const struct ea *)ea0, (const struct ea *)ea0);
    }
    return (struct name *)0;
}

int no_of_names__4nameFv(struct name *__0this) {
    int __1i;
    Pname __1n;

    __1i = 0;

    for (__1n = __0this; __1n; __1n = __1n->__O1__4name.n_list)
        __1i++;
    return __1i;
}

static Pexpr lvec[20];

static Pexpr *lll;

static Pexpr *curr_e;
static Pexpr last_il = 0;
static Pexpr list_back = 0;
static Pexpr last_el = 0;

static Pexpr *last_lll;

void new_list__FP4expr(Pexpr __1lx) {
    if (__1lx->base__4node != 124)
        error__FiPCc((int)'i', (const char *)"IrLX");

    lll = (last_lll = lvec);
    lll++;
    ((*lll)) = (last_el = __1lx->__O2__4expr.e1);
}

Pfct memptr__4typeFv(struct type *__0this);

extern int need_sti__FP4exprP5tableUc(Pexpr __0e, Ptable __0tbl, bit __0is_static_ok);

Pexpr next_elem__Fv(void) {
    Pexpr __1e;
    Pexpr __1lx;

    if (lll == lvec)
        return (struct expr *)0;

    __1lx = ((*lll));

    if (list_back) {
        __1e = list_back;
        list_back = 0;
        return __1e;
    }

    if (__1lx == 0) {
        lll--;
        return (struct expr *)0;
    }

    switch (__1lx->base__4node) {
        unsigned long __2__X152;

    case 140:
        __1e = __1lx->__O2__4expr.e1;
        curr_e = (&__1lx->__O2__4expr.e1);
        last_el = __1lx;
        last_lll = lll;
        ((*lll)) = __1lx->__O3__4expr.e2;
        switch (__1e->base__4node) {
        case 124:
            if (__1e->__O1__4expr.tp && memptr__4typeFv(__1e->__O1__4expr.tp))
                return __1e;
            lll++;
            ((*lll)) = __1e->__O2__4expr.e1;
            last_il = __1e;
            return (((struct expr *)1));
        case 140:
            error__FPCc((const char *)"nestedEL");
            return (struct expr *)0;
        default: {
            if (need_sti__FP4exprP5tableUc(__1e, (struct table *)0, (unsigned char)0))
                error__FiPCc((int)'s', (const char *)"generalIr inIrL");
            return __1e;
        }
        }
    case 150:
    case 86:
        lll--;
        return (struct expr *)0;
    default: {
        struct ea __0__V151;

        error__FiPCcRC2eaN33(
            (int)'i', (const char *)"IrL %k",
            (const struct ea *)((__2__X152 = __1lx->base__4node),
                                (((((&__0__V151)->__O1__2ea.i = __2__X152), 0)), (&__0__V151))),
            (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
        return (struct expr *)0;
    }
    }
}

static Pexpr insert_init__FP4expr(Pexpr __1newval) {
    Pexpr __1t;

    __1t = __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)140, last_el->__O2__4expr.e1,
                                  last_el->__O3__4expr.e2);

    last_el->__O2__4expr.e1 = __1newval;
    last_el->__O3__4expr.e2 = __1t;
    lll = last_lll;
    ((*lll)) = last_el;
    return next_elem__Fv();
}

void skip_ilist__Fv(void) {
    Pexpr __1e;

    __1e = next_elem__Fv();
    __1e = next_elem__Fv();
}

static int pts_to_templ__FP4type(Ptype __1t) {
    Ptype __1tt;

    __1tt = skiptypedefs__4typeFv(__1t);
    if (__1tt->base__4node != 125)
        return 0;
    __1tt = skiptypedefs__4typeFv((((struct ptr *)(((struct ptr *)__1tt))))->typ__5pvtyp);
    return ((__1tt->base__4node == 108) &&
            ((((struct fct *)(((struct fct *)__1tt))))->fct_base__3fct == 1));
}

static void grab_braces__FPP4expri(Pexpr *__1base, int __1lst) {
    int __1flag;

    __1flag = 0;

    while (lll > (__1base - __1lst)) {
        if (next_elem__Fv() && (!(__1flag++)))
            error__FPCc((const char *)"IrL too long");
    }
}

void list_check__FP4nameP4typeP4exprP5table(Pname __1nn, Ptype __1t, Pexpr __1il, Ptable __1tbl);

extern Pexpr ptof__FP3fctP4exprP5table(Pfct, Pexpr, Ptable);

void dcl_print__8classdefFP4name(struct classdef *__0this, Pname);

static struct ea *__ct__2eaFUl(struct ea *__0this, size_t __2ii);

void list_check__FP4nameP4typeP4exprP5table(Pname __1nn, Ptype __1t, Pexpr __1il, Ptable __1tbl) {
    Pexpr __1e;
    bit __1lst;
    int __1i;
    Pclass __1cl;
    int __1tdef;

    __1lst = 0;

    __1tdef = 0;

    if (__1il == (((struct expr *)1))) {
        __1lst = 1;
        __1e = __1il;
    } else if (__1il)
        list_back = __1il;

zzz:
    switch (__1t->base__4node) {
    case 97:
        __1t =
            (((struct basetype *)(((struct basetype *)__1t))))->b_name__8basetype->__O1__4expr.tp;
        __1tdef = 1;
        goto zzz;

    case 110: {
        Pvec __3v;
        Ptype __3vt;

        __3v = (((struct vec *)(((struct vec *)__1t))));
        __3vt = skiptypedefs__4typeFv(__3v->typ__5pvtyp);

        if (__3v->size__3vec) {
            if (__3vt->base__4node == 5) {
                __1e = next_elem__Fv();
                if (__1e->base__4node == 81) {
                    int __6isz;

                    __6isz = (((struct vec *)(((struct vec *)__1e->__O1__4expr.tp))))->size__3vec;
                    if (__3v->size__3vec < __6isz) {
                        struct ea __0__V153;

                        struct ea __0__V154;

                        struct ea __0__V155;

                        error__FPCcRC2eaN32(
                            (const char *)"Ir too long (%d characters) for%n[%d]",
                            (const struct ea *)(((((&__0__V153)->__O1__2ea.i =
                                                       ((unsigned long)__6isz)),
                                                  0)),
                                                (&__0__V153)),
                            (const struct ea *)(((&__0__V154)->__O1__2ea.p = ((const void *)__1nn)),
                                                (&__0__V154)),
                            (const struct ea *)__ct__2eaFUl(&__0__V155,
                                                            (unsigned long)__3v->size__3vec),
                            (const struct ea *)ea0);
                    }
                    break;
                } else
                    list_back = __1e;
            }
            {
                Pexpr *__4lllsave_vec;

                __4lllsave_vec = lll;
                for (__1i = 0; __1i < __3v->size__3vec; __1i++) {
                    Pfct __5MP;

                    __5MP = 0;
                ee:
                    __1e = next_elem__Fv();
                    if (__1e == 0) {
                        if (!ansi_opt)
                            goto xsw;
                        if (lll < __4lllsave_vec)
                            goto xsw;
                        goto ee;
                    }

                    if (((lll - __4lllsave_vec) >= 2) && ansi_opt)
                        error__FPCc((const char *)"unexpectedIrL");
                vtz:
                    switch (__3vt->base__4node) {
                        register struct type *__0__X188;

                        struct type *__1__Xt00anhgl1b4vcog;

                    case 97:
                        __3vt = (((struct basetype *)(((struct basetype *)__3vt))))
                                    ->b_name__8basetype->__O1__4expr.tp;
                        goto vtz;
                    case 110:
                    case 119:
                        list_check__FP4nameP4typeP4exprP5table(__1nn, __3vt, __1e,
                                                               (struct table *)0);
                        if ((lll < __4lllsave_vec) && ansi_opt)
                            return;
                        break;
                    case 125:
                        if ((__5MP = memptr__4typeFv(__3vt)) && (__1e == (((struct expr *)1)))) {
                            if (check__4typeFP4typeUcT2(__3vt, last_il->__O1__4expr.tp,
                                                        (unsigned char)70, (unsigned char)0)) {
                                struct ea __0__V156;

                                struct ea __0__V157;

                                struct ea __0__V158;

                                error__FPCcRC2eaN32(
                                    (const char *)"badIrT for%n:%t (%tX)",
                                    (const struct ea *)(((&__0__V156)->__O1__2ea.p =
                                                             ((const void *)__3v)),
                                                        (&__0__V156)),
                                    (const struct ea *)__ct__2eaFPCv(
                                        &__0__V157, (const void *)last_il->__O1__4expr.tp),
                                    (const struct ea *)(((&__0__V158)->__O1__2ea.p =
                                                             ((const void *)__3vt)),
                                                        (&__0__V158)),
                                    (const struct ea *)ea0);
                            }
                            skip_ilist__Fv();
                            break;
                        }
                        if (__5MP && is_zero__FP4expr(__1e)) {
                            ((*curr_e)) = __ct__4exprFUcP4exprT2((struct expr *)0,
                                                                 (unsigned char)140, zero, zero);
                            ((*curr_e)) = __ct__4exprFUcP4exprT2(
                                (struct expr *)0, (unsigned char)124, (*curr_e), zero);
                            ((*curr_e))->__O1__4expr.tp = (struct type *)zero_type;
                            break;
                        }
                        if ((__1e && (__1e != (((struct expr *)1)))) &&
                            (((__0__X188 = __1e->__O1__4expr.tp),
                              ((__1__Xt00anhgl1b4vcog = skiptypedefs__4typeFv(__0__X188)),
                               (((__1__Xt00anhgl1b4vcog->base__4node == 125)
                                     ? ((__1__Xt00anhgl1b4vcog = skiptypedefs__4typeFv(
                                             (((struct ptr *)((
                                                  (struct ptr *)__1__Xt00anhgl1b4vcog))))
                                                 ->typ__5pvtyp)),
                                        0)
                                     : 0),
                                (((unsigned char)((__1__Xt00anhgl1b4vcog->base__4node ==
                                                   ((unsigned char)76))
                                                      ? 1
                                                      : 0)))))) ||
                             pts_to_templ__FP4type(__1e->__O1__4expr.tp))) {
                            Pexpr __7op;
                            __7op = ptof__FP3fctP4exprP5table(
                                ((struct fct *)((
                                    (struct fct *)(((struct ptr *)(((struct ptr *)__3vt))))
                                        ->typ__5pvtyp))),
                                __1e, __1tbl);
                            if (__7op &&
                                check__4typeFP4typeUcT2(__3vt, __7op->__O1__4expr.tp,
                                                        (unsigned char)70, (unsigned char)0)) {
                                struct ea __0__V159;

                                struct ea __0__V160;

                                struct ea __0__V161;

                                error__FPCcRC2eaN32(
                                    (const char *)"badIrT for%n:%t (%tX)",
                                    (const struct ea *)(((&__0__V159)->__O1__2ea.p =
                                                             ((const void *)__1nn)),
                                                        (&__0__V159)),
                                    (const struct ea *)__ct__2eaFPCv(
                                        &__0__V160, (const void *)__7op->__O1__4expr.tp),
                                    (const struct ea *)(((&__0__V161)->__O1__2ea.p =
                                                             ((const void *)__3vt)),
                                                        (&__0__V161)),
                                    (const struct ea *)ea0);
                            }
                            if (__7op) {
                                ((*curr_e)) = __7op;
                                break;
                            }
                        }

                    default: {
                        if (__1e == (((struct expr *)1))) {
                            if (!ansi_opt)
                                error__FPCc((const char *)"unexpectedIrL");
                            goto ee;
                        }

                        if (check__4typeFP4typeUcT2(__3vt, __1e->__O1__4expr.tp, (unsigned char)70,
                                                    (unsigned char)0)) {
                            struct ea __0__V162;

                            struct ea __0__V163;

                            struct ea __0__V164;

                            error__FPCcRC2eaN32((const char *)"badIrT for%n:%t (%tX)",
                                                (const struct ea *)(((&__0__V162)->__O1__2ea.p =
                                                                         ((const void *)__1nn)),
                                                                    (&__0__V162)),
                                                (const struct ea *)__ct__2eaFPCv(
                                                    &__0__V163, (const void *)__1e->__O1__4expr.tp),
                                                (const struct ea *)(((&__0__V164)->__O1__2ea.p =
                                                                         ((const void *)__3vt)),
                                                                    (&__0__V164)),
                                                (const struct ea *)ea0);
                        }
                        {
                            Pptr __7p;
                            if (((check__4typeFP4typeUcT2(__3vt, __1e->__O1__4expr.tp,
                                                          (unsigned char)0, (unsigned char)0) &&
                                  (__7p = is_ptr__4typeFv(__3vt))) &&
                                 ((((struct type *)(((struct type *)__7p)))) !=
                                  (((struct type *)zero_type)))) &&
                                (__7p->typ__5pvtyp != (((struct type *)char_type)))) {
                                Pexpr __8te;
                                Ptype __8t;

                                register struct cast *__0__X189;

                                __8te = __1e;
                                __8t = __7p->typ__5pvtyp;
                                while (__8t->base__4node == 97)
                                    __8t = (((struct basetype *)(((struct basetype *)__8t))))
                                               ->b_name__8basetype->__O1__4expr.tp;
                                if (__8t->base__4node == 119)
                                    __8te = ptr_init__FP3ptrP4exprP5table(__7p, __1e, __1tbl);
                                if (__8te == __1e)
                                    ((*curr_e)) =
                                        (struct expr
                                             *)((__0__X189 = 0),
                                                (((__0__X189 ||
                                                   (__0__X189 = (struct cast *)__nw__4exprSFUl(
                                                        (unsigned long)(sizeof(struct cast)))))
                                                      ? ((__0__X189 =
                                                              (struct cast *)__ct__4exprFUcP4exprT2(
                                                                  ((struct expr *)__0__X189),
                                                                  (unsigned char)191, __1e,
                                                                  (struct expr *)0)),
                                                         (__0__X189->__O1__4expr.tp =
                                                              (__0__X189->__O4__4expr.tp2 = __3vt)))
                                                      : 0),
                                                 __0__X189));
                                else
                                    ((*curr_e)) = __8te;
                            }
                        }
                    }
                    }
                }
                if (ansi_opt) {
                    grab_braces__FPP4expri(__4lllsave_vec, (int)__1lst);
                } else {
                    if (__1lst && (__1e = next_elem__Fv()))
                        error__FPCc((const char *)"end ofIrLX after array");
                }
            xsw:;
            }
        } else {
            __1i = 0;
            ((void)tsizeof__4typeFi(__3v->typ__5pvtyp, 0));
            {
                Pexpr *__4lllsave_vec2;

                __4lllsave_vec2 = lll;
            xx: {
                Pfct __4MP;

                __4MP = 0;
                __1i++;
            xx2:
                __1e = next_elem__Fv();
                if (__1e == 0) {
                    if ((!ansi_opt) || (lll < __4lllsave_vec2)) {
                        __1i--;
                        goto done;
                    }
                    goto xx2;
                }
                if (((lll - __4lllsave_vec2) >= 2) && ansi_opt)
                    error__FPCc((const char *)"unexpectedIrL");
            vtzz:
                switch (__3vt->base__4node) {
                    register struct type *__0__X190;

                    struct type *__1__Xt00anhgl1b4vcog;

                case 97:
                    __3vt = (((struct basetype *)(((struct basetype *)__3vt))))
                                ->b_name__8basetype->__O1__4expr.tp;
                    goto vtzz;
                case 110:
                case 119:
                    list_check__FP4nameP4typeP4exprP5table(__1nn, __3vt, __1e, (struct table *)0);
                    break;
                case 125:
                    if ((__4MP = memptr__4typeFv(__3vt)) && (__1e == (((struct expr *)1)))) {
                        if (check__4typeFP4typeUcT2(__3vt, last_il->__O1__4expr.tp,
                                                    (unsigned char)70, (unsigned char)0)) {
                            struct ea __0__V165;

                            struct ea __0__V166;

                            struct ea __0__V167;

                            error__FPCcRC2eaN32(
                                (const char *)"badIrT for%n:%t (%tX)",
                                (const struct ea *)(((&__0__V165)->__O1__2ea.p =
                                                         ((const void *)__3v)),
                                                    (&__0__V165)),
                                (const struct ea *)__ct__2eaFPCv(
                                    &__0__V166, (const void *)last_il->__O1__4expr.tp),
                                (const struct ea *)(((&__0__V167)->__O1__2ea.p =
                                                         ((const void *)__3vt)),
                                                    (&__0__V167)),
                                (const struct ea *)ea0);
                        }
                        skip_ilist__Fv();
                        break;
                    }
                    if (__4MP && is_zero__FP4expr(__1e)) {
                        ((*curr_e)) = __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)140,
                                                             zero, zero);
                        ((*curr_e)) = __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)124,
                                                             (*curr_e), zero);
                        ((*curr_e))->__O1__4expr.tp = (struct type *)zero_type;
                        break;
                    }

                    if ((__1e && (__1e != (((struct expr *)1)))) &&
                        (((__0__X190 = __1e->__O1__4expr.tp),
                          ((__1__Xt00anhgl1b4vcog = skiptypedefs__4typeFv(__0__X190)),
                           (((__1__Xt00anhgl1b4vcog->base__4node == 125)
                                 ? ((__1__Xt00anhgl1b4vcog = skiptypedefs__4typeFv(
                                         (((struct ptr *)(((struct ptr *)__1__Xt00anhgl1b4vcog))))
                                             ->typ__5pvtyp)),
                                    0)
                                 : 0),
                            (((unsigned char)((__1__Xt00anhgl1b4vcog->base__4node ==
                                               ((unsigned char)76))
                                                  ? 1
                                                  : 0)))))) ||
                         pts_to_templ__FP4type(__1e->__O1__4expr.tp))) {
                        Pexpr __6op;
                        __6op = ptof__FP3fctP4exprP5table(
                            ((struct fct *)(((struct fct *)(((struct ptr *)(((struct ptr *)__3vt))))
                                                 ->typ__5pvtyp))),
                            __1e, __1tbl);
                        if (__6op && check__4typeFP4typeUcT2(__3vt, __6op->__O1__4expr.tp,
                                                             (unsigned char)70, (unsigned char)0)) {
                            struct ea __0__V168;

                            struct ea __0__V169;

                            struct ea __0__V170;

                            error__FPCcRC2eaN32(
                                (const char *)"badIrT for%n:%t (%tX)",
                                (const struct ea *)(((&__0__V168)->__O1__2ea.p =
                                                         ((const void *)__1nn)),
                                                    (&__0__V168)),
                                (const struct ea *)__ct__2eaFPCv(
                                    &__0__V169, (const void *)__6op->__O1__4expr.tp),
                                (const struct ea *)(((&__0__V170)->__O1__2ea.p =
                                                         ((const void *)__3vt)),
                                                    (&__0__V170)),
                                (const struct ea *)ea0);
                        }
                        if (__6op) {
                            ((*curr_e)) = __6op;
                            break;
                        }
                    }

                default: {
                    if (__1e == (((struct expr *)1))) {
                        if (!ansi_opt) {
                            error__FPCc((const char *)"unexpectedIrL");
                            goto xx;
                        }
                        goto xx2;
                    }

                    if (check__4typeFP4typeUcT2(__3vt, __1e->__O1__4expr.tp, (unsigned char)70,
                                                (unsigned char)0)) {
                        struct ea __0__V171;

                        struct ea __0__V172;

                        struct ea __0__V173;

                        error__FPCcRC2eaN32(
                            (const char *)"badIrT for%n:%t (%tX)",
                            (const struct ea *)(((&__0__V171)->__O1__2ea.p = ((const void *)__1nn)),
                                                (&__0__V171)),
                            (const struct ea *)__ct__2eaFPCv(&__0__V172,
                                                             (const void *)__1e->__O1__4expr.tp),
                            (const struct ea *)(((&__0__V173)->__O1__2ea.p = ((const void *)__3vt)),
                                                (&__0__V173)),
                            (const struct ea *)ea0);
                    }
                    {
                        Pptr __6p;
                        if (((check__4typeFP4typeUcT2(__3vt, __1e->__O1__4expr.tp, (unsigned char)0,
                                                      (unsigned char)0) &&
                              (__6p = is_ptr__4typeFv(__3vt))) &&
                             ((((struct type *)(((struct type *)__6p)))) !=
                              (((struct type *)zero_type)))) &&
                            (__6p->typ__5pvtyp != (((struct type *)char_type)))) {
                            Pexpr __7te;
                            Ptype __7t;

                            register struct cast *__0__X191;

                            __7te = __1e;
                            __7t = __6p->typ__5pvtyp;
                            while (__7t->base__4node == 97)
                                __7t = (((struct basetype *)(((struct basetype *)__7t))))
                                           ->b_name__8basetype->__O1__4expr.tp;
                            if (__7t->base__4node == 119)
                                __7te = ptr_init__FP3ptrP4exprP5table(__6p, __1e, __1tbl);
                            if (__7te == __1e)
                                ((*curr_e)) =
                                    (struct expr
                                         *)((__0__X191 = 0),
                                            (((__0__X191 ||
                                               (__0__X191 = (struct cast *)__nw__4exprSFUl(
                                                    (unsigned long)(sizeof(struct cast)))))
                                                  ? ((__0__X191 =
                                                          (struct cast *)__ct__4exprFUcP4exprT2(
                                                              ((struct expr *)__0__X191),
                                                              (unsigned char)191, __1e,
                                                              (struct expr *)0)),
                                                     (__0__X191->__O1__4expr.tp =
                                                          (__0__X191->__O4__4expr.tp2 = __3vt)))
                                                  : 0),
                                             __0__X191));
                            else
                                ((*curr_e)) = __7te;
                        }
                    }
                }
                }
                goto xx;
            done:
                if (ansi_opt) {
                    grab_braces__FPP4expri(__4lllsave_vec2, (int)__1lst);
                }
                if (__1tdef == 0)
                    __3v->size__3vec = __1i;
            }
            }
        }
        break;
    }

    case 6:
        __1cl = (((struct classdef *)(((struct classdef *)__1t))));
        goto ccc;

    case 119: {
        __1cl = (((struct classdef *)((
            (struct classdef *)(((struct basetype *)(((struct basetype *)__1t))))
                ->b_name__8basetype->__O1__4expr.tp))));
    ccc:
        if (__1cl->defined__4type == 0) {
            lll = lvec;
            return;
        }

        if (__1cl->c_body__8classdef == 1)
            dcl_print__8classdefFP4name(__1cl, (struct name *)0);

        {
            Ptable __3tbl;
            Pname __3m;

            __3tbl = __1cl->memtbl__8classdef;

            if ((ansi_opt == 0) && (__1cl->csu__8classdef == 36))
                error__FiPCc((int)'s', (const char *)"initialization of union withIL");

            {
                Pexpr *__3lllsave_cobj;

                int __2__X192;

                int __2__X193;

                __3lllsave_cobj = lll;

                if (__1cl->baselist__8classdef) {
                    if (__1cl->baselist__8classdef->next__6basecl)
                        error__FPCc((const char *)"IrL forO ofC with multipleBCs");
                    list_check__FP4nameP4typeP4exprP5table(
                        __1nn, (struct type *)__1cl->baselist__8classdef->bclass__6basecl,
                        (struct expr *)0, (struct table *)0);
                    if ((lll < __3lllsave_cobj) && ansi_opt)
                        return;
                }

                for (__3m = ((__2__X192 = (__1i = 1)),
                             ((((__2__X192 <= 0) || (__3tbl->free_slot__5table <= __2__X192))
                                   ? (((struct name *)0))
                                   : (__3tbl->entries__5table[__2__X192]))));
                     __3m;
                     __3m = (__3m->n_tbl_list__4name
                                 ? __3m->n_tbl_list__4name
                                 : ((__2__X193 = (++__1i)),
                                    ((((__2__X193 <= 0) || (__3tbl->free_slot__5table <= __2__X193))
                                          ? (((struct name *)0))
                                          : (__3tbl->entries__5table[__2__X193])))))) {
                    if (__3m->base__4node == 123)
                        continue;
                    {
                        Ptype __4mt;
                        Pfct __4MP;

                        __4mt = __3m->__O1__4expr.tp;
                        __4MP = 0;
                        if (__4mt == 0)
                            continue;
                        switch (__4mt->base__4node) {
                        case 108:
                        case 76:
                        case 6:
                            if (__4mt->base__4node == 6) {
                                Pclass __6cl;

                                __6cl = (((struct classdef *)(((struct classdef *)__4mt))));
                                if (!((((unsigned char)((__6cl->csu__8classdef == 6)
                                                            ? 0
                                                            : (((int)__6cl->csu__8classdef))))))) {
                                    struct ea __0__V174;

                                    struct ea __0__V175;

                                    error__FPCcRC2eaN32(
                                        (const char *)"cannotI%nWIrL because class %s has private "
                                                      "or protected members",
                                        (const struct ea *)(((&__0__V174)->__O1__2ea.p =
                                                                 ((const void *)__1nn)),
                                                            (&__0__V174)),
                                        (const struct ea *)__ct__2eaFPCv(
                                            &__0__V175, (const void *)__6cl->string__8classdef),
                                        (const struct ea *)ea0, (const struct ea *)ea0);
                                }
                            }
                        case 13:
                            continue;
                        }
                        if ((__3m->n_stclass__4name == 31) || (__3m->n_stclass__4name == 13))
                            continue;

                    dd:
                        while (__4mt->base__4node == 97)
                            __4mt = (((struct basetype *)(((struct basetype *)__4mt))))
                                        ->b_name__8basetype->__O1__4expr.tp;

                        if (((lll - __3lllsave_cobj) >= 2) && ansi_opt)
                            error__FPCc((const char *)"unexpectedIrL");

                        if (((__4MP = memptr__4typeFv(__4mt)) && (__1e == (((struct expr *)1)))) &&
                            (last_il->__O1__4expr.tp->base__4node == 125)) {
                            if (__1i == 1)
                                __1lst = 0;
                        } else
                            __1e = next_elem__Fv();

                        if (__1e == 0) {
                            if ((!ansi_opt) || (lll < __3lllsave_cobj))
                                return;
                            goto dd;
                        }

                        if ((((__4mt->base__4node == 114) &&
                              ((__3m->__O2__4expr.string[0]) == '_')) &&
                             ((__3m->__O2__4expr.string[1]) == '_')) &&
                            ((__3m->__O2__4expr.string[2]) == 'F')) {
                            __1e = insert_init__FP4expr(zero);
                        }

                        switch (__4mt->base__4node) {
                            register struct type *__0__X194;

                            struct type *__1__Xt00anhgl1b4vcog;

                        case 6:
                        case 13:
                            break;
                        case 110:
                        case 119:
                            list_check__FP4nameP4typeP4exprP5table(__1nn, __3m->__O1__4expr.tp,
                                                                   __1e, (struct table *)0);
                            if ((lll < __3lllsave_cobj) && ansi_opt)
                                return;
                            break;
                        case 125:
                            if (__4MP && (__1e == (((struct expr *)1)))) {
                                if (check__4typeFP4typeUcT2(__4mt, last_il->__O1__4expr.tp,
                                                            (unsigned char)70, (unsigned char)0)) {
                                    struct ea __0__V176;

                                    struct ea __0__V177;

                                    struct ea __0__V178;

                                    error__FPCcRC2eaN32(
                                        (const char *)"badIrT for%n:%t (%tX)",
                                        (const struct ea *)(((&__0__V176)->__O1__2ea.p =
                                                                 ((const void *)__3m)),
                                                            (&__0__V176)),
                                        (const struct ea *)__ct__2eaFPCv(
                                            &__0__V177, (const void *)last_il->__O1__4expr.tp),
                                        (const struct ea *)(((&__0__V178)->__O1__2ea.p =
                                                                 ((const void *)__4mt)),
                                                            (&__0__V178)),
                                        (const struct ea *)ea0);
                                }
                                skip_ilist__Fv();
                                break;
                            }
                            if (__4MP && is_zero__FP4expr(__1e)) {
                                ((*curr_e)) = __ct__4exprFUcP4exprT2(
                                    (struct expr *)0, (unsigned char)140, zero, zero);
                                ((*curr_e)) = __ct__4exprFUcP4exprT2(
                                    (struct expr *)0, (unsigned char)124, (*curr_e), zero);
                                ((*curr_e))->__O1__4expr.tp = (struct type *)zero_type;
                                break;
                            }

                            if ((__1e && (__1e != (((struct expr *)1)))) &&
                                (((__0__X194 = __1e->__O1__4expr.tp),
                                  ((__1__Xt00anhgl1b4vcog = skiptypedefs__4typeFv(__0__X194)),
                                   (((__1__Xt00anhgl1b4vcog->base__4node == 125)
                                         ? ((__1__Xt00anhgl1b4vcog = skiptypedefs__4typeFv(
                                                 (((struct ptr *)((
                                                      (struct ptr *)__1__Xt00anhgl1b4vcog))))
                                                     ->typ__5pvtyp)),
                                            0)
                                         : 0),
                                    (((unsigned char)((__1__Xt00anhgl1b4vcog->base__4node ==
                                                       ((unsigned char)76))
                                                          ? 1
                                                          : 0)))))) ||
                                 pts_to_templ__FP4type(__1e->__O1__4expr.tp))) {
                                Pexpr __6op;
                                __6op = ptof__FP3fctP4exprP5table(
                                    ((struct fct *)((
                                        (struct fct *)(((struct ptr *)(((struct ptr *)__4mt))))
                                            ->typ__5pvtyp))),
                                    __1e, __3tbl);
                                if (__6op &&
                                    check__4typeFP4typeUcT2(__4mt, __6op->__O1__4expr.tp,
                                                            (unsigned char)70, (unsigned char)0)) {
                                    struct ea __0__V179;

                                    struct ea __0__V180;

                                    struct ea __0__V181;

                                    error__FPCcRC2eaN32(
                                        (const char *)"badIrT for%n:%t (%tX)",
                                        (const struct ea *)(((&__0__V179)->__O1__2ea.p =
                                                                 ((const void *)__1nn)),
                                                            (&__0__V179)),
                                        (const struct ea *)__ct__2eaFPCv(
                                            &__0__V180, (const void *)__6op->__O1__4expr.tp),
                                        (const struct ea *)(((&__0__V181)->__O1__2ea.p =
                                                                 ((const void *)__4mt)),
                                                            (&__0__V181)),
                                        (const struct ea *)ea0);
                                }
                                if (__6op) {
                                    ((*curr_e)) = __6op;
                                    break;
                                }
                            }

                        default: {
                            if (__1e == (((struct expr *)1))) {
                                if (!ansi_opt)
                                    error__FPCc((const char *)"unexpectedIrL");
                                goto dd;
                            }

                            if (check__4typeFP4typeUcT2(__4mt, __1e->__O1__4expr.tp,
                                                        (unsigned char)70, (unsigned char)0)) {
                                struct ea __0__V182;

                                struct ea __0__V183;

                                struct ea __0__V184;

                                error__FPCcRC2eaN32(
                                    (const char *)"badIrT for%n:%t (%tX)",
                                    (const struct ea *)(((&__0__V182)->__O1__2ea.p =
                                                             ((const void *)__3m)),
                                                        (&__0__V182)),
                                    (const struct ea *)__ct__2eaFPCv(
                                        &__0__V183, (const void *)__1e->__O1__4expr.tp),
                                    (const struct ea *)__ct__2eaFPCv(
                                        &__0__V184, (const void *)__3m->__O1__4expr.tp),
                                    (const struct ea *)ea0);
                            }
                            if ((__4MP && __1e) &&
                                ((__1e->base__4node == 113) || (__1e->base__4node == 191)))
                                ((*curr_e)) = __1e->__O2__4expr.e1;

                            {
                                Pptr __6p;

                                register struct cast *__0__X195;

                                if (((check__4typeFP4typeUcT2(__4mt, __1e->__O1__4expr.tp,
                                                              (unsigned char)0, (unsigned char)0) &&
                                      (__6p = is_ptr__4typeFv(__4mt))) &&
                                     ((((struct type *)(((struct type *)__6p)))) !=
                                      (((struct type *)zero_type)))) &&
                                    (__6p->typ__5pvtyp != (((struct type *)char_type))))
                                    ((*curr_e)) =
                                        (struct expr
                                             *)((__0__X195 = 0),
                                                (((__0__X195 ||
                                                   (__0__X195 = (struct cast *)__nw__4exprSFUl(
                                                        (size_t)(sizeof(struct cast)))))
                                                      ? ((__0__X195 =
                                                              (struct cast *)__ct__4exprFUcP4exprT2(
                                                                  ((struct expr *)__0__X195),
                                                                  (unsigned char)191, __1e,
                                                                  (struct expr *)0)),
                                                         (__0__X195->__O1__4expr.tp =
                                                              (__0__X195->__O4__4expr.tp2 = __4mt)))
                                                      : 0),
                                                 __0__X195));
                            }
                        }
                        }
                        if (__1cl->csu__8classdef == 36)
                            break;
                    }
                }
                if (ansi_opt) {
                    grab_braces__FPP4expri(__3lllsave_cobj, (int)__1lst);
                } else {
                    if (__1lst && (__1e = next_elem__Fv()))
                        error__FPCc((const char *)"end ofIrLX afterCO");
                }
                break;
            }
        }
    }

    default:
        __1e = next_elem__Fv();

        if (__1e == 0) {
            error__FPCc((const char *)"noIr forO");
            break;
        }

        if (__1e == (((struct expr *)1))) {
            error__FPCc((const char *)"unexpectedIrL");
            break;
        }

        if (check__4typeFP4typeUcT2(__1t, __1e->__O1__4expr.tp, (unsigned char)70,
                                    (unsigned char)0)) {
            struct ea __0__V185;

            struct ea __0__V186;

            struct ea __0__V187;

            error__FPCcRC2eaN32(
                (const char *)"badIrT for%n:%t (%tX)",
                (const struct ea *)(((&__0__V185)->__O1__2ea.p = ((const void *)__1nn)),
                                    (&__0__V185)),
                (const struct ea *)__ct__2eaFPCv(&__0__V186, (const void *)__1e->__O1__4expr.tp),
                (const struct ea *)(((&__0__V187)->__O1__2ea.p = ((const void *)__1t)),
                                    (&__0__V187)),
                (const struct ea *)ea0);
        }
        {
            Pptr __2p;

            register struct cast *__0__X196;

            if (((check__4typeFP4typeUcT2(__1t, __1e->__O1__4expr.tp, (unsigned char)0,
                                          (unsigned char)0) &&
                  (__2p = is_ptr__4typeFv(__1t))) &&
                 ((((struct type *)(((struct type *)__2p)))) != (((struct type *)zero_type)))) &&
                (__2p->typ__5pvtyp != (((struct type *)char_type))))
                ((*curr_e)) =
                    (struct expr *)((__0__X196 = 0),
                                    (((__0__X196 || (__0__X196 = (struct cast *)__nw__4exprSFUl(
                                                         (size_t)(sizeof(struct cast)))))
                                          ? ((__0__X196 = (struct cast *)__ct__4exprFUcP4exprT2(
                                                  ((struct expr *)__0__X196), (unsigned char)191,
                                                  __1e, (struct expr *)0)),
                                             (__0__X196->__O1__4expr.tp =
                                                  (__0__X196->__O4__4expr.tp2 = __1t)))
                                          : 0),
                                     __0__X196));
            if (__1lst && (__1e = next_elem__Fv()))
                error__FPCc((const char *)"end ofIrLX afterO");

            break;
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

Pname find_cn__6ktableFPCc(struct ktable *__0this, const char *);

void dcl__8classdefFP4nameP5table(struct classdef *__0this, Pname, Ptable);

Pname dclass__FP4nameP5table(Pname __1n, Ptable __1tbl) {
    Pclass __1cl;
    Pbase __1bt;
    Pname __1bn;
    Pname __1ntbl;

    __1ntbl = __1tbl->t_name__5table;

    if ((__1n->__O1__4expr.tp == 0) || (__1n->__O1__4expr.tp->base__4node != 6)) {
        struct ea __0__V197;

        error__FiP3locPCcRC2eaN34(
            (int)'i', &__1n->where__4name, (const char *)"dclass%n: non-class",
            (const struct ea *)(((&__0__V197)->__O1__2ea.p = ((const void *)__1n)), (&__0__V197)),
            (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
    }
    {
        Pname __1nx;

        __1nx = find_cn__6ktableFPCc(
            (((struct classdef *)(((struct classdef *)__1n->__O1__4expr.tp))))->k_tbl__8classdef,
            __1n->__O2__4expr.string);
        if ((__1nx == 0) || (__1nx->base__4node != 123)) {
            struct ea __0__V198;

            error__FiP3locPCcRC2eaN34(
                (int)'i', &__1n->where__4name, (const char *)"dclass%n: missingTN",
                (const struct ea *)(((&__0__V198)->__O1__2ea.p = ((const void *)__1n)),
                                    (&__0__V198)),
                (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
        };

        __1bt = 0;

        __1bn = 0;

        __1cl = 0;

        if (__1nx) {
            __1bt = (((struct basetype *)(((struct basetype *)__1nx->__O1__4expr.tp))));
            if (__1bt->base__4node != 119) {
                {
                    struct ea __0__V199;

                    error__FiP3locPCcRC2eaN34(
                        (int)'i', &__1n->where__4name, (const char *)"%n is not aCN",
                        (const struct ea *)(((&__0__V199)->__O1__2ea.p = ((const void *)__1n)),
                                            (&__0__V199)),
                        (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
                }
            }
            __1bn = __1bt->b_name__8basetype;
        } else {
            {
                struct ea __0__V200;

                error__FiP3locPCcRC2eaN34(
                    (int)'i', &__1n->where__4name, (const char *)"%n is not aCN",
                    (const struct ea *)(((&__0__V200)->__O1__2ea.p = ((const void *)__1n)),
                                        (&__0__V200)),
                    (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
            }
        }

        if ((((struct classdef *)(((struct classdef *)__1bn->__O1__4expr.tp))))
                ->class_base__8classdef == 4)
            __1nx->where__4name = __1n->where__4name;
        __1bn->where__4name = __1nx->where__4name;

        {
            Pname __1bnn;

            __1bnn = insert__5tableFP4nameUc(__1tbl, __1bn, (unsigned char)6);
            __1cl = (((struct classdef *)(((struct classdef *)__1bn->__O1__4expr.tp))));

            if ((!__1cl->in_class__4type) && (__1cl->class_base__8classdef == 2)) {
                struct ea __0__V201;

                error__FPCcRC2eaN32(
                    (const char *)"C%n defined previously asYC",
                    (const struct ea *)(((&__0__V201)->__O1__2ea.p = ((const void *)__1bn)),
                                        (&__0__V201)),
                    (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
            }
            {
                bit __1no_err;

                __1no_err = ((__1cl->in_class__4type &&
                              (__1cl->in_class__4type->class_base__8classdef == 2)) &&
                             (__1tbl != gtbl));

                if ((__1cl->defined__4type & 3) && (__1no_err == 0)) {
                    if (__1nx->n_key__4name == 159) {
                        struct ea __0__V202;

                        error__FPCcRC2eaN32(
                            (const char *)"hiddenC%t defined twice",
                            (const struct ea *)(((&__0__V202)->__O1__2ea.p = ((const void *)__1cl)),
                                                (&__0__V202)),
                            (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
                    } else {
                        if (__1cl->in_class__4type &&
                            (__1cl->in_class__4type->class_base__8classdef == 2)) {
                            struct ea __0__V203;

                            struct ea __0__V204;

                            error__FPCcRC2eaN32(
                                (const char *)"cannot provide a specialized instance ofC%t "
                                              "nestedWinYC%t<>",
                                (const struct ea *)(((&__0__V203)->__O1__2ea.p =
                                                         ((const void *)__1cl)),
                                                    (&__0__V203)),
                                (const struct ea *)__ct__2eaFPCv(
                                    &__0__V204, (const void *)__1cl->in_class__4type),
                                (const struct ea *)ea0, (const struct ea *)ea0);
                        } else {
                            struct ea __0__V205;

                            error__FPCcRC2eaN32((const char *)"C%t defined twice",
                                                (const struct ea *)(((&__0__V205)->__O1__2ea.p =
                                                                         ((const void *)__1cl)),
                                                                    (&__0__V205)),
                                                (const struct ea *)ea0, (const struct ea *)ea0,
                                                (const struct ea *)ea0);
                        }
                    }
                } else {
                    if (__1bn->n_scope__4name == 136)
                        __1bn->n_scope__4name = 139;
                    {
                        Pktab __2otbl;

                        __2otbl = Ctbl;
                        Ctbl = __1cl->k_tbl__8classdef;
                        dcl__8classdefFP4nameP5table(__1cl, __1bn, __1tbl);
                        Ctbl = __2otbl;
                    }
                }
                __1n->__O1__4expr.tp = (struct type *)__1cl;
                return __1bnn;
            }
        }
    }
}

extern Pname k_find_name__FPCcP6ktableUc(const char *, Pktab, TOK);

void dcl__7enumdefFP4nameP5table(struct enumdef *__0this, Pname, Ptable);

Pname denum__FP4nameP5table(Pname __1n, Ptable __1tbl) {
    Penum __1en;
    Pbase __1bt;
    Pname __1bn;
    Pname __1ntbl;

    Pktab __1tb;
    Pname __1nx;

    __1ntbl = __1tbl->t_name__5table;

    __1tb = ((__1n->__O1__4expr.tp->in_class__4type && __1n->__O1__4expr.tp->nested_sig__4type)
                 ? __1n->__O1__4expr.tp->in_class__4type->k_tbl__8classdef
                 : (((struct ktable *)0)));
    __1nx = k_find_name__FPCcP6ktableUc(__1n->__O2__4expr.string, __1tb ? __1tb : Ctbl,
                                        (unsigned char)159);

    if (__1nx) {
        if ((__1nx->__O1__4expr.tp == 0) || (__1nx->__O1__4expr.tp->base__4node != 121)) {
            __1nx = __1nx->__O1__4name.n_hidden;
            if (((__1nx == 0) || (__1nx->n_key__4name != 38)) ||
                (__1nx->__O1__4expr.tp->base__4node != 121)) {
                struct ea __0__V206;

                error__FiP3locPCcRC2eaN34(
                    (int)'i', &__1n->where__4name, (const char *)"%n is not an enum",
                    (const struct ea *)(((&__0__V206)->__O1__2ea.p = ((const void *)__1n)),
                                        (&__0__V206)),
                    (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
            }
        }
        __1bt = (((struct basetype *)(((struct basetype *)__1nx->__O1__4expr.tp))));
        __1bn = __1bt->b_name__8basetype;
        __1en = (((struct enumdef *)(((struct enumdef *)__1bn->__O1__4expr.tp))));
    } else {
        {
            struct ea __0__V207;

            error__FiP3locPCcRC2eaN34(
                (int)'i', &__1n->where__4name, (const char *)"%n is not an enum",
                (const struct ea *)(((&__0__V207)->__O1__2ea.p = ((const void *)__1n)),
                                    (&__0__V207)),
                (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
        }
    }

    {
        Pname __1bnn;

        __1bnn = insert__5tableFP4nameUc(__1tbl, __1bn, (unsigned char)6);

        if (__1en->defined__4type & 3) {
            if (__1nx->n_key__4name == 159) {
                struct ea __0__V208;

                error__FPCcRC2eaN32(
                    (const char *)"hidden enum%n defined twice",
                    (const struct ea *)(((&__0__V208)->__O1__2ea.p = ((const void *)__1n)),
                                        (&__0__V208)),
                    (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
            } else {
                struct ea __0__V209;

                error__FPCcRC2eaN32(
                    (const char *)"enum%n defined twice",
                    (const struct ea *)(((&__0__V209)->__O1__2ea.p = ((const void *)__1n)),
                                        (&__0__V209)),
                    (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
            }
        } else {
            if (__1bn->n_scope__4name == 136)
                __1bn->n_scope__4name = 139;
            dcl__7enumdefFP4nameP5table(__1en, __1bn, __1tbl);
        }
        __1n->__O1__4expr.tp = (struct type *)__1en;
        return __1bnn;
    }
}

extern int isdigit(int);

int is_probably_temp__FPCc(const char *__1str) {
    if (((__1str[0]) != '_') || ((__1str[1]) != '_'))
        return 0;

    switch (__1str[2]) {
    default:
        return 0;
    case 'A':
    case 'C':
    case 'D':
    case 'E':
    case 'F':
    case 'I':
    case 'K':
    case 'L':
    case 'M':
    case 'N':
    case 'Q':
    case 'R':
    case 'S':
    case 'T':
    case 'U':
    case 'V':
    case 'W':
        if (isdigit((int)(__1str[3])))
            return 1;
        return 0;
    case 'X':
        return 1;
    }
}

static int illegal_local_ref__FP4name(Pname __1nn) {
    switch (__1nn->n_scope__4name) {
    default:
        return 0;
    case 136:
        return 1;
    case 108:
        if ((__1nn->n_sto__4name == 31) || (__1nn->n_sto__4name == 14))
            return 0;
        else {
            int __3cc;
            Ptype __3tt;

            __3cc = tconst__4typeFv(__1nn->__O1__4expr.tp);
            __3tt = skiptypedefs__4typeFv(__1nn->__O1__4expr.tp);
            while (__3cc && (__3tt->base__4node == 110)) {
                __3tt = (((struct vec *)(((struct vec *)__3tt))))->typ__5pvtyp;
                __3cc = tconst__4typeFv(__3tt);
                __3tt = skiptypedefs__4typeFv(__3tt);
            }
            if (!__3cc) {
                switch (__3tt->base__4node) {
                case 108:
                case 76:
                    break;
                default:
                    return 1;
                }
            }
        }
        return 0;
    }
}

static int size_t_check__FP4type(Ptype __1tp) {
    if (check__4typeFP4typeUcT2(__1tp, size_t_type, (unsigned char)0, (unsigned char)0) == 0)
        return 0;
    {
        int __1size_t_size;

        __1size_t_size = tsizeof__4typeFi(size_t_type, 0);
        if ((__1size_t_size == tsizeof__4typeFi((struct type *)ulong_type, 0)) &&
            (check__4typeFP4typeUcT2(__1tp, (struct type *)ulong_type, (unsigned char)0,
                                     (unsigned char)0) == 0))
            return 0;
        if ((__1size_t_size == tsizeof__4typeFi((struct type *)ullong_type, 0)) &&
            (check__4typeFP4typeUcT2(__1tp, (struct type *)ullong_type, (unsigned char)0,
                                     (unsigned char)0) == 0))
            return 0;
        if ((__1size_t_size == tsizeof__4typeFi((struct type *)ushort_type, 0)) &&
            (check__4typeFP4typeUcT2(__1tp, (struct type *)ushort_type, (unsigned char)0,
                                     (unsigned char)0) == 0))
            return 0;
        return 1;
    }
}

static void check_for_local__FP4expr(Pexpr __1ee);

static void check_for_local__FP4expr(Pexpr __1ee) {
    static Pname __1n[2] = {((struct name *)0), ((struct name *)0)};
    static int __1index = 0;

    if (__1ee == 0)
        return;

    switch (__1ee->base__4node) {
    case 85: {
        Pname __3nn;

        __3nn = (((struct name *)(((struct name *)__1ee))));
        if ((((((__3nn->n_scope__4name == 108) || (__3nn->n_scope__4name == 136)) &&
               illegal_local_ref__FP4name(__3nn)) &&
              (is_probably_temp__FPCc(__3nn->__O2__4expr.string) == 0)) &&
             ((__1n[0]) != __3nn)) &&
            ((__1n[1]) != __3nn)) {
            {
                struct ea __0__V210;

                error__FPCcRC2eaN32(
                    (const char *)"local%n used in defaultA",
                    (const struct ea *)(((&__0__V210)->__O1__2ea.p = ((const void *)__3nn)),
                                        (&__0__V210)),
                    (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
                (__1n[__1index]) = __3nn;
                __1index = ((__1index == 0) ? 1 : 0);
            }
        }
    }
    case 123:
    case 81:
    case 150:
    case 82:
    case 84:
    case 83:
    case 86:
    case 144:
    case 162:
    case 30:
    case 116:
    case 165:
    case 169:
        return;
    case 68:
        check_for_local__FP4expr(__1ee->__O4__4expr.cond);
        break;
    case 177:
        check_for_local__FP4expr(__1ee->__O4__4expr.mem);
        return;
    }

    check_for_local__FP4expr(__1ee->__O2__4expr.e1);
    check_for_local__FP4expr(__1ee->__O3__4expr.e2);
}

extern size_t strlen(const char *);

Pclass classtype__4typeFv(struct type *__0this);

extern Pexpr class_init__FP4exprP4typeT1P5table(Pexpr, Ptype, Pexpr, Ptable);

extern void dosimpl__FP4exprP4name(Pexpr, Pname);

extern bit can_coerce__FP4typeT1(Ptype, Ptype);

void del__4exprFv(struct expr *__0this);

long long eval__4exprFv(struct expr *__0this);

void dargs__FP4nameP3fctP5table(Pname __1__A211, Pfct __1f, Ptable __1tbl) {
    int __1argnamesize;
    int __1oo;

    __1argnamesize = 0;
    __1oo = const_save;

    if (__1f->memof__3fct) {
        struct dcl_context *__0__X220;

        ((((cc++),
           (((cc >= ccvec_end) ? error__FiPCc((int)'i', (const char *)"ccvec buffer overflow") : 0),
            (((*cc)) = (*(cc - 1))))),
          (((void)0))));
        cc->cot__11dcl_context = __1f->memof__3fct;
        cc->not4__11dcl_context = __1f->memof__3fct->memtbl__8classdef->t_name__5table;
        cc->tot__11dcl_context = __1f->memof__3fct->this_type__8classdef;
        __1tbl = __1f->memof__3fct->memtbl__8classdef;
    }

    const_save = 1;
    if (ansi_opt) {
        Pname __2th;

        __2th = __1f->f_this__3fct;
        if (__2th && __2th->__O2__4expr.string)
            __1argnamesize += (strlen(__2th->__O2__4expr.string) + 1);
        __2th = __1f->f_result__3fct;
        if (__2th && __2th->__O2__4expr.string)
            __1argnamesize += (strlen(__2th->__O2__4expr.string) + 1);
    }

    {
        {
            Pname __1a;

            struct dcl_context *__0__X231;

            __1a = __1f->argtype__3fct;

            for (; __1a; __1a = __1a->__O1__4name.n_list) {
                Pexpr __2init;

                if (__1a->__O1__4expr.tp == 0) {
                    error__FPCc((const char *)"A has noT");
                    __1a->__O1__4expr.tp = (struct type *)any_type;
                    __1a->__O1__4name.n_list = 0;
                    continue;
                }
                if (ansi_opt && __1a->__O2__4expr.string)
                    __1argnamesize += (strlen(__1a->__O2__4expr.string) + 1);

                {
                    Pname __2cln;

                    struct classdef *__0__X222;

                    __2cln = is_cl_obj__4typeFv(__1a->__O1__4expr.tp);

                    {
                        Ptype __3t;
                        Pclass __3cl;

                        __3t = skiptypedefs__4typeFv(__1a->__O1__4expr.tp);
                        __3cl = ((__3t->base__4node == 119) ? classtype__4typeFv(__3t)
                                                            : (((struct classdef *)0)));
                        if ((__3cl && __3cl->c_abstract__8classdef) &&
                            (__3cl->defined__4type & 01)) {
                            const void *__2__X221;

                            {
                                struct ea __0__V212;

                                error__FPCcRC2eaN32(
                                    (const char *)"abstractC%t cannot be used as anAT",
                                    (const struct ea *)(((&__0__V212)->__O1__2ea.p =
                                                             ((const void *)__3cl)),
                                                        (&__0__V212)),
                                    (const struct ea *)ea0, (const struct ea *)ea0,
                                    (const struct ea *)ea0);
                                {
                                    struct ea __0__V213;

                                    struct ea __0__V214;

                                    error__FiPCcRC2eaN33(
                                        (int)'C', (const char *)"\t%a is a pure virtualF ofC%t\n",
                                        (const struct ea
                                             *)((__2__X221 =
                                                     (const void *)__3cl->c_abstract__8classdef),
                                                (((&__0__V213)->__O1__2ea.p = __2__X221),
                                                 (&__0__V213))),
                                        (const struct ea *)(((&__0__V214)->__O1__2ea.p =
                                                                 ((const void *)__3cl)),
                                                            (&__0__V214)),
                                        (const struct ea *)ea0, (const struct ea *)ea0);
                                }
                            }
                        }
                    }

                    if (__2cln &&
                        ((__0__X222 =
                              (((struct classdef *)(((struct classdef *)__2cln->__O1__4expr.tp))))),
                         (__0__X222->c_itor__8classdef)))
                        __1a->n_xref__4name = 1;
                    else {
                        Ptype __3t;

                        __3t = __1a->__O1__4expr.tp;
                        while (__3t->base__4node == 97)
                            __3t = (((struct basetype *)(((struct basetype *)__3t))))
                                       ->b_name__8basetype->__O1__4expr.tp;
                        if (__3t->base__4node == 108)
                            __1a->__O1__4expr.tp = (struct type *)__ct__3ptrFUcP4type(
                                (struct ptr *)0, (unsigned char)125, __1a->__O1__4expr.tp);
                    }

                    if (__2init = __1a->__O3__4expr.n_initializer) {
                        Pptr __3pt;
                        if (__2init == dummy) {
                            error__FPCc((const char *)"emptyIr");
                            __1a->__O3__4expr.n_initializer = 0;
                            continue;
                        }
                        if (__2cln) {
                            if (__2init->base__4node == 157) {
                                switch (__2init->__O4__4expr.tp2->base__4node) {
                                    struct classdef *__1__X223;

                                    struct classdef *__1__X224;

                                case 6:
                                    if (!((__1__X223 = (((struct classdef *)((
                                               (struct classdef *)__2init->__O4__4expr.tp2))))),
                                          ((__1__X224 = (((struct classdef *)((
                                                (struct classdef *)__2cln->__O1__4expr.tp))))),
                                           (((__1__X223 == __1__X224)
                                                 ? 1
                                                 : ((__1__X223 && __1__X224)
                                                        ? (((int)same_class__8classdefFP8classdefi(
                                                              __1__X223, __1__X224, 0)))
                                                        : 0))))))
                                        goto inin2;

                                    break;
                                default: {
                                    Pname __7n2;

                                    struct classdef *__1__X225;

                                    struct classdef *__1__X226;

                                    __7n2 = is_cl_obj__4typeFv(__2init->__O4__4expr.tp2);
                                    if ((__7n2 == 0) ||
                                        (!((__1__X225 = (((struct classdef *)((
                                                (struct classdef *)__7n2->__O1__4expr.tp))))),
                                           ((__1__X226 = (((struct classdef *)((
                                                 (struct classdef *)__2cln->__O1__4expr.tp))))),
                                            (((__1__X225 == __1__X226)
                                                  ? 1
                                                  : ((__1__X225 && __1__X226)
                                                         ? (((int)same_class__8classdefFP8classdefi(
                                                               __1__X225, __1__X226, 0)))
                                                         : 0)))))))
                                        goto inin2;
                                }
                                }

                                __1a->__O3__4expr.n_initializer = (__2init = 0);
                                error__FiPCc((int)'s', (const char *)"K as defaultA");
                            } else {
                            inin2:
                                if (__2init->base__4node == 124)
                                    error__FPCc((const char *)"list as AIr");

                                {
                                    Pexpr __5i;

                                    __5i = typ__4exprFP5table(__2init, __1tbl);
                                    __2init = class_init__FP4exprP4typeT1P5table(
                                        (struct expr *)__1a, __1a->__O1__4expr.tp, __5i, __1tbl);
                                    if ((__5i != __2init) && (__2init->base__4node == 111)) {
                                        error__FiPCc((int)'s', (const char *)"K needed forAIr");
                                        __2init = 0;
                                    } else {
                                        dosimpl__FP4exprP4name(__2init, cc->nof__11dcl_context);
                                        __2init->permanent__4node = 2;
                                    }
                                    __1a->__O3__4expr.n_initializer = __2init;
                                }
                            }
                        } else if (__3pt = is_ref__4typeFv(__1a->__O1__4expr.tp)) {
                            ref_initializer++;
                            __2init = typ__4exprFP5table(__2init, __1tbl);
                            ref_initializer--;
                            {
                                int __4tcount;

                                __4tcount = stcount;
                                __2init = ref_init__FP3ptrP4exprP5table(__3pt, __2init, __1tbl);
                                if (__4tcount != stcount) {
                                    error__FiPCc((int)'s',
                                                 (const char *)"needs temporaryV to evaluateAIr");

                                    __2init = 0;
                                } else {
                                    dosimpl__FP4exprP4name(__2init, cc->nof__11dcl_context);
                                    __2init->permanent__4node = 2;
                                }
                                __1a->__O3__4expr.n_initializer = __2init;
                            }
                        } else {
                            Pptr __4p;

                            __4p = is_ptr__4typeFv(__1a->__O1__4expr.tp);
                            if (perf_opt &&
                                ((__2init->base__4node == 23) || (__2init->base__4node == 184)))
                                New_in_arg_list = 1;
                            __2init = typ__4exprFP5table(__2init, __1tbl);
                            if (__4p)
                                __2init = ptr_init__FP3ptrP4exprP5table(__4p, __2init, __1tbl);

                            if (check__4typeFP4typeUcT2(__1a->__O1__4expr.tp,
                                                        __2init->__O1__4expr.tp, (unsigned char)136,
                                                        (unsigned char)0)) {
                                int __5i;

                                __5i = can_coerce__FP4typeT1(__1a->__O1__4expr.tp,
                                                             __2init->__O1__4expr.tp);

                                switch (__5i) {
                                    const void *__2__X230;

                                case 1:
                                    if (Ncoerce) {
                                        Pname __7cn;
                                        Pname __7xx;
                                        Pref __7r;

                                        struct ref *__0__X227;

                                        struct expr *__2__X228;

                                        struct expr *__2__X229;

                                        __7cn = is_cl_obj__4typeFv(__2init->__O1__4expr.tp);
                                        __7xx = __ct__4nameFPCc((struct name *)0,
                                                                Ncoerce->__O2__4expr.string);
                                        __7r =
                                            ((__0__X227 = 0),
                                             ((__2__X228 = __2init),
                                              ((__2__X229 = (struct expr *)__7xx),
                                               (((__0__X227 ||
                                                  (__0__X227 = (struct ref *)__nw__4exprSFUl(
                                                       (size_t)(sizeof(struct ref)))))
                                                     ? ((__0__X227 =
                                                             (struct ref *)__ct__4exprFUcP4exprT2(
                                                                 ((struct expr *)__0__X227),
                                                                 ((unsigned char)45), __2__X228,
                                                                 (struct expr *)0)),
                                                        (__0__X227->__O4__4expr.mem = __2__X229))
                                                     : 0),
                                                __0__X227))));

                                        __2init = __ct__4exprFUcP4exprT2(
                                            (struct expr *)0, (unsigned char)146,
                                            (struct expr *)__7r, (struct expr *)0);
                                        __2init = typ__4exprFP5table(__2init, __1tbl);
                                    }
                                    break;
                                default: {
                                    struct ea __0__V215;

                                    error__FPCcRC2eaN32(
                                        (const char *)"%d possible conversions for defaultA",
                                        (const struct ea *)(((((&__0__V215)->__O1__2ea.i =
                                                                   ((unsigned long)__5i)),
                                                              0)),
                                                            (&__0__V215)),
                                        (const struct ea *)ea0, (const struct ea *)ea0,
                                        (const struct ea *)ea0);
                                case 0: {
                                    struct ea __0__V216;

                                    struct ea __0__V217;

                                    struct ea __0__V218;

                                    error__FPCcRC2eaN32(
                                        (const char *)"badIrT%t forA%n (%tX)",
                                        (const struct ea
                                             *)((__2__X230 = (const void *)__2init->__O1__4expr.tp),
                                                (((&__0__V216)->__O1__2ea.p = __2__X230),
                                                 (&__0__V216))),
                                        (const struct ea *)(((&__0__V217)->__O1__2ea.p =
                                                                 ((const void *)__1a)),
                                                            (&__0__V217)),
                                        (const struct ea *)__ct__2eaFPCv(
                                            &__0__V218, (const void *)__1a->__O1__4expr.tp),
                                        (const struct ea *)ea0);
                                    if (__2init && (__2init->permanent__4node == 0))
                                        del__4exprFv(__2init);
                                    __1a->__O3__4expr.n_initializer = (__2init = 0);
                                }
                                }
                                }
                            }

                            if (__2init && (__2init->__O1__4expr.tp->base__4node != 141)) {
                                dosimpl__FP4exprP4name(__2init, cc->nof__11dcl_context);
                                __2init->permanent__4node = 2;
                                __1a->__O3__4expr.n_initializer = __2init;
                                Neval = 0;
                                {
                                    long long __5i;

                                    __5i = eval__4exprFv(__2init);
                                    if (Neval == 0) {
                                        __1a->n_evaluated__4name = 1;
                                        __1a->n_val__4name = __5i;
                                    }
                                }
                            }
                        }
                        if (__1a->__O3__4expr.n_initializer)
                            check_for_local__FP4expr(__1a->__O3__4expr.n_initializer);
                    }
                }
            }
            if (ansi_opt && __1argnamesize) {
                char *__2ps;
                Pname __2a;

                __2ps = (((char *)__nw__FUl((size_t)((sizeof(char)) * __1argnamesize))));
                __2a = __1f->f_this__3fct;
                if (__2a && __2a->__O2__4expr.string) {
                    int __3i;

                    __3i = (strlen(__2a->__O2__4expr.string) + 1);
                    if ((__1argnamesize -= __3i) < 0)
                        goto bad;
                    strcpy(__2ps, __2a->__O2__4expr.string);
                    __2a->__O2__4expr.string = (const char *)__2ps;
                    __2ps += __3i;
                }
                __2a = __1f->f_result__3fct;
                if (__2a && __2a->__O2__4expr.string) {
                    int __3i;

                    __3i = (strlen(__2a->__O2__4expr.string) + 1);
                    if ((__1argnamesize -= __3i) < 0)
                        goto bad;
                    strcpy(__2ps, __2a->__O2__4expr.string);
                    __2a->__O2__4expr.string = (const char *)__2ps;
                    __2ps += __3i;
                }
                for (__2a = __1f->argtype__3fct; __2a; __2a = __2a->__O1__4name.n_list) {
                    if (__2a->__O2__4expr.string == 0)
                        continue;
                    {
                        int __3i;

                        __3i = (strlen(__2a->__O2__4expr.string) + 1);
                        if ((__1argnamesize -= __3i) < 0)
                            goto bad;
                        strcpy(__2ps, __2a->__O2__4expr.string);
                        __2a->__O2__4expr.string = (const char *)__2ps;
                        __2ps += __3i;
                    }
                }
                if (__1argnamesize)
                bad: {
                    struct ea __0__V219;

                    error__FiPCcRC2eaN33(
                        (int)'i', (const char *)"bad argN size for%t",
                        (const struct ea *)(((&__0__V219)->__O1__2ea.p = ((const void *)__1f)),
                                            (&__0__V219)),
                        (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
                }
            }
            const_save = __1oo;
            if (__1f->memof__3fct)
                (((cc--), (((void)0))));
        }
    }
}

void merge_init__FP4nameP3fctT2(Pname __1nn, Pfct __1f, Pfct __1nf) {
    Pname __1a1;
    Pname __1a2;

    __1a1 = __1f->argtype__3fct;
    __1a2 = __1nf->argtype__3fct;

    for (; __1a1; ((__1a1 = __1a1->__O1__4name.n_list), (__1a2 = __1a2->__O1__4name.n_list))) {
        int __2i1;
        int __2i2;

        __2i1 = (__1a1->__O3__4expr.n_initializer || __1a1->n_evaluated__4name);
        __2i2 = (__1a2->__O3__4expr.n_initializer || __1a2->n_evaluated__4name);

        if (__2i1 && __2i2)
            if (__1a1->__O2__4expr.string == 0) {
                struct ea __0__V232;

                error__FP3locPCcRC2eaN33(
                    &__1a1->where__4name, (const char *)"twoIrs for%nA",
                    (const struct ea *)(((&__0__V232)->__O1__2ea.p = ((const void *)__1nn)),
                                        (&__0__V232)),
                    (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
            } else {
                struct ea __0__V233;

                struct ea __0__V234;

                error__FP3locPCcRC2eaN33(
                    &__1a1->where__4name, (const char *)"twoIrs for%nA%n",
                    (const struct ea *)(((&__0__V233)->__O1__2ea.p = ((const void *)__1nn)),
                                        (&__0__V233)),
                    (const struct ea *)(((&__0__V234)->__O1__2ea.p = ((const void *)__1a1)),
                                        (&__0__V234)),
                    (const struct ea *)ea0, (const struct ea *)ea0);
            }
        if (__2i1) {
            __1a2->__O3__4expr.n_initializer = __1a1->__O3__4expr.n_initializer;
            __1a2->n_evaluated__4name = __1a1->n_evaluated__4name;
            __1a2->n_val__4name = __1a1->n_val__4name;
        }
        if (__2i2) {
            __1a1->__O3__4expr.n_initializer = __1a2->__O3__4expr.n_initializer;
            __1a1->n_evaluated__4name = __1a2->n_evaluated__4name;
            __1a1->n_val__4name = __1a2->n_val__4name;
        }
    }
}

Pexpr try_to_coerce__FP4typeP4exprPCcP5table(Ptype __1rt, Pexpr __1e, const char *__1s,
                                             Ptable __1tbl) {
    int __1i;
    Pname __1cn;

    __1cn = 0;

    if (((__1e->__O1__4expr.tp && (__1cn = is_cl_obj__4typeFv(__1e->__O1__4expr.tp))) &&
         (__1i = can_coerce__FP4typeT1(__1rt, __1e->__O1__4expr.tp))) &&
        Ncoerce) {
        if (1 < __1i) {
            struct ea __0__V235;

            struct ea __0__V236;

            error__FPCcRC2eaN32(
                (const char *)"%d possible conversions for %s",
                (const struct ea *)(((((&__0__V235)->__O1__2ea.i = ((unsigned long)__1i)), 0)),
                                    (&__0__V235)),
                (const struct ea *)(((&__0__V236)->__O1__2ea.p = ((const void *)__1s)),
                                    (&__0__V236)),
                (const struct ea *)ea0, (const struct ea *)ea0);
        }
        {
            Pname __2xx;
            Pref __2r;
            Pexpr __2c;

            struct ref *__0__X237;

            struct expr *__2__X238;

            struct expr *__2__X239;

            __2xx = __ct__4nameFPCc((struct name *)0, Ncoerce->__O2__4expr.string);
            __2r = ((__0__X237 = 0),
                    ((__2__X238 = __1e),
                     ((__2__X239 = (struct expr *)__2xx),
                      (((__0__X237 ||
                         (__0__X237 = (struct ref *)__nw__4exprSFUl((size_t)(sizeof(struct ref)))))
                            ? ((__0__X237 = (struct ref *)__ct__4exprFUcP4exprT2(
                                    ((struct expr *)__0__X237), ((unsigned char)45), __2__X238,
                                    (struct expr *)0)),
                               (__0__X237->__O4__4expr.mem = __2__X239))
                            : 0),
                       __0__X237))));

            __2c = __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)146, (struct expr *)__2r,
                                          (struct expr *)0);
            __2c = typ__4exprFP5table(__2c, __1tbl);

            return __2c;
        }
    }

    return (struct expr *)0;
}

int in_class_dcl = 0;

void dcl__4typeFP5table(struct type *__0this, Ptable);

extern Pname find_virtual__FP8classdefP4name(Pclass, Pname);

Pname has_oper__8classdefFUc(struct classdef *__0this, TOK);

static struct gen *__ct__3genFv(struct gen *__0this) {
    struct type *__0__X5;

    struct node *__0__X1;

    if (__0this || (__0this = (struct gen *)__nw__FUl((size_t)(sizeof(struct gen))))) {
        (((__0this =
               (struct gen
                    *)((__0__X5 = (((struct type *)__0this))),
                       (((__0__X5 ||
                          (__0__X5 = (struct type *)__nw__FUl((size_t)(sizeof(struct type)))))
                             ? (((((((((__0__X5 =
                                            (struct type
                                                 *)((__0__X1 = (((struct node *)__0__X5))),
                                                    (((__0__X1 ||
                                                       (__0__X1 = (struct node *)__nw__FUl(
                                                            (size_t)(sizeof(struct node)))))
                                                          ? (((__0__X1->base__4node = 0),
                                                              (__0__X1->permanent__4node = 0)),
                                                             (__0__X1->baseclass__4node = 0))
                                                          : 0),
                                                     __0__X1))),
                                       (__0__X5->defined__4type = 0)),
                                      (__0__X5->lex_level__4type = 0)),
                                     (__0__X5->templ_base__4type = 0)),
                                    (__0__X5->in_class__4type = 0)),
                                   (__0__X5->nested_sig__4type = 0)),
                                  (__0__X5->local_sig__4type = 0)),
                                 (__0__X5->b_const__4type = 0)),
                                (__0__X5->ansi_const__4type = 0))
                             : 0),
                        __0__X5))),
          (__0this->fct_list__3gen = 0)),
         (__0this->holds_templ__3gen = 0));

        __0this->base__4node = 76;
    }
    return __0this;
}

void take_addr__4nameFv(struct name *__0this);

struct basetype *__ct__8basetypeFUcP4name(struct basetype *__0this, TOK, Pname);

Pname dofct__4nameFP5tableUc(register struct name *__0this, Ptable __1tbl, TOK __1scope) {
    Pfct __1f;
    Pname __1class_name;
    Ptable __1etbl;
    int __1old_in_class_dcl;
    int __1just_made;

    __1f = (((struct fct *)(((struct fct *)__0this->__O1__4expr.tp))));

    __1old_in_class_dcl = in_class_dcl;
    __1just_made = 0;

    ;

    in_class_dcl = (cc->not4__11dcl_context != 0);

    if (__1f->f_inline__3fct)
        __0this->n_sto__4name = 31;

    if (__0this->n_stclass__4name)
        switch (__0this->n_stclass__4name) {
            unsigned long __2__X310;

        case 14:
        case 31:
        case 76:
            break;
        default: {
            struct ea __0__V240;

            struct ea __0__V241;

            error__FPCcRC2eaN32(
                (const char *)"%n declared%k",
                (const struct ea *)(((&__0__V240)->__O1__2ea.p = ((const void *)__0this)),
                                    (&__0__V240)),
                (const struct ea *)((__2__X310 = __0this->n_stclass__4name),
                                    (((((&__0__V241)->__O1__2ea.i = __2__X310), 0)), (&__0__V241))),
                (const struct ea *)ea0, (const struct ea *)ea0);
            __0this->n_stclass__4name = 14;
        }
        }

    if (__0this->__O2__4name.n_qualifier) {
        __1class_name = (((struct basetype *)((
                             (struct basetype *)__0this->__O2__4name.n_qualifier->__O1__4expr.tp))))
                            ->b_name__8basetype;
        __1etbl = (((struct classdef *)(((struct classdef *)__1class_name->__O1__4expr.tp))))
                      ->memtbl__8classdef;
    } else {
        __1class_name = cc->not4__11dcl_context;

        if (__1class_name && (__1tbl != cc->cot__11dcl_context->memtbl__8classdef)) {
            __1class_name = 0;
            in_class_dcl = 0;
        }
    }
    if (__1class_name)
        __1f->memof__3fct =
            (((struct classdef *)(((struct classdef *)__1class_name->__O1__4expr.tp))));

    dcl__4typeFP5table(__0this->__O1__4expr.tp, __1tbl);

    {
        Ptype __2tt;
        Pclass __2cl;

        __2tt = skiptypedefs__4typeFv(
            (((struct fct *)(((struct fct *)__0this->__O1__4expr.tp))))->returns__3fct);
        __2cl =
            ((__2tt->base__4node == 119) ? classtype__4typeFv(__2tt) : (((struct classdef *)0)));
        if ((__2cl && __2cl->c_abstract__8classdef) && (__2cl->defined__4type & 01)) {
            const void *__2__X311;

            {
                struct ea __0__V242;

                error__FPCcRC2eaN32(
                    (const char *)"abstractC%t cannot be used as aF returnT",
                    (const struct ea *)(((&__0__V242)->__O1__2ea.p = ((const void *)__2cl)),
                                        (&__0__V242)),
                    (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
                {
                    struct ea __0__V243;

                    struct ea __0__V244;

                    error__FiPCcRC2eaN33(
                        (int)'C', (const char *)"\t%a is a pure virtualF ofC%t\n",
                        (const struct ea *)((__2__X311 =
                                                 (const void *)__2cl->c_abstract__8classdef),
                                            (((&__0__V243)->__O1__2ea.p = __2__X311),
                                             (&__0__V243))),
                        (const struct ea *)(((&__0__V244)->__O1__2ea.p = ((const void *)__2cl)),
                                            (&__0__V244)),
                        (const struct ea *)ea0, (const struct ea *)ea0);
                }
            }
        }
    }

    if (__0this->__O2__4name.n_qualifier) {
        if (__1f->f_virtual__3fct) {
            {
                struct ea __0__V245;

                struct ea __0__V246;

                error__FPCcRC2eaN32(
                    (const char *)"virtual specifier illegal outsideCD(%n::%s())",
                    (const struct ea *)(((&__0__V245)->__O1__2ea.p = ((const void *)__1class_name)),
                                        (&__0__V245)),
                    (const struct ea *)__ct__2eaFPCv(&__0__V246,
                                                     (const void *)__0this->__O2__4expr.string),
                    (const struct ea *)ea0, (const struct ea *)ea0);
                __1f->f_virtual__3fct = 0;
            }
        }

        if ((__0this->n_sto__4name && (__0this->n_sto__4name != 18)) &&
            (__1f->f_inline__3fct == 0)) {
            unsigned long __2__X312;

            {
                struct ea __0__V247;

                struct ea __0__V248;

                error__FPCcRC2eaN32(
                    (const char *)"%k specified for QdN%n",
                    (const struct ea *)((__2__X312 = __0this->n_sto__4name),
                                        (((((&__0__V247)->__O1__2ea.i = __2__X312), 0)),
                                         (&__0__V247))),
                    (const struct ea *)(((&__0__V248)->__O1__2ea.p = ((const void *)__0this)),
                                        (&__0__V248)),
                    (const struct ea *)ea0, (const struct ea *)ea0);
                __0this->n_sto__4name = 0;
            }
        }
    } else {
        if (__1f->f_static__3fct && __1f->f_virtual__3fct) {
            error__FPCc((const char *)"virtual staticM");
            __1f->f_virtual__3fct = 0;
        }

        if (__0this->n_oper__4name)
            check_oper__4nameFP4name(__0this, __1class_name);
        __1etbl = __1tbl;
    }

    if (__1class_name) {
        Pclass __2cl;

        __2cl = (((struct classdef *)(((struct classdef *)__1class_name->__O1__4expr.tp))));
        if ((__1f->f_virtual__3fct == 0) &&
            find_virtual__FP8classdefP4name(__1f->memof__3fct, __0this))
            __1f->f_virtual__3fct = 22222;

        if (__1f->f_static__3fct && __1f->f_virtual__3fct) {
            error__FPCc((const char *)"virtual staticM");

            __1f->f_virtual__3fct = 0;
        }

        if ((__2cl->csu__8classdef == 36) && __1f->f_virtual__3fct) {
            Ptable __3tt;

            __3tt = __0this->__O4__4expr.n_table;
            __0this->__O4__4expr.n_table = __1etbl;
            {
                struct ea __0__V249;

                error__FPCcRC2eaN32(
                    (const char *)"%n: cannot declare a virtualFWin union",
                    (const struct ea *)(((&__0__V249)->__O1__2ea.p = ((const void *)__0this)),
                                        (&__0__V249)),
                    (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
                __0this->__O4__4expr.n_table = __3tt;
            }
        }
    }

    if (__1f->f_const__3fct && (__1f->memof__3fct == 0)) {
        error__FPCc((const char *)"onlyMFs can be constant");
    }

    if ((__1etbl == 0) || (__1etbl->base__4node != 142)) {
        struct ea __0__V250;

        error__FiPCcRC2eaN33(
            (int)'i', (const char *)"N::dcl: etbl=%d",
            (const struct ea *)(((&__0__V250)->__O1__2ea.p = ((const void *)__1etbl)),
                                (&__0__V250)),
            (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
    }
    switch (__0this->n_oper__4name) {
        Pclass __2cl;

    case 161:
        if (__1f->f_virtual__3fct) {
            error__FPCc((const char *)"virtualK");
            __1f->f_virtual__3fct = 0;
        }
        if (__1f->f_const__3fct) {
            error__FPCc((const char *)"constructors cannot be const");
            __1f->f_const__3fct = 0;
        }
        break;
    case 162:
        if (__1f->f_const__3fct) {
            error__FPCc((const char *)"destructors cannot be const");
            __1f->f_const__3fct = 0;
        }
        break;
    case 44:
        if (__1f->argtype__3fct) {
            struct ea __0__V251;

            error__FPCcRC2eaN32(
                (const char *)"%n takes noAs",
                (const struct ea *)(((&__0__V251)->__O1__2ea.p = ((const void *)__0this)),
                                    (&__0__V251)),
                (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
        }
        if (is_ptr__4typeFv(__1f->returns__3fct) == 0) {
            Pname __3cn;

            __3cn = is_cl_obj__4typeFv(__1f->returns__3fct);
            if ((__3cn == 0) && (__1f->returns__3fct->base__4node == 158))
                __3cn = is_cl_obj__4typeFv(
                    (((struct ptr *)(((struct ptr *)__1f->returns__3fct))))->typ__5pvtyp);

            if ((__3cn == 0) ||
                (has_oper__8classdefFUc(
                     ((struct classdef *)(((struct classdef *)__3cn->__O1__4expr.tp))),
                     (unsigned char)44) == 0)) {
                const void *__2__X313;

                if ((__3cn && __1class_name) &&
                    (strcmp(__3cn->__O2__4expr.string, __1class_name->__O2__4expr.string) == 0)) {
                    struct ea __0__V252;

                    struct ea __0__V253;

                    struct ea __0__V254;

                    error__FPCcRC2eaN32(
                        (const char *)"%s::%n cannot return aR orCO ofC%n",
                        (const struct ea *)((__2__X313 = (const void *)__3cn->__O2__4expr.string),
                                            (((&__0__V252)->__O1__2ea.p = __2__X313),
                                             (&__0__V252))),
                        (const struct ea *)(((&__0__V253)->__O1__2ea.p = ((const void *)__0this)),
                                            (&__0__V253)),
                        (const struct ea *)(((&__0__V254)->__O1__2ea.p = ((const void *)__3cn)),
                                            (&__0__V254)),
                        (const struct ea *)ea0);
                } else {
                    struct ea __0__V255;

                    error__FPCcRC2eaN32(
                        (const char *)"%n must return aP toCO, aR toCO, or aCO",
                        (const struct ea *)(((&__0__V255)->__O1__2ea.p = ((const void *)__0this)),
                                            (&__0__V255)),
                        (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
                }
                __0this->__O1__4expr.tp = (struct type *)any_type;
            }
        } else {
            Pname __3cn;

            __3cn = is_cl_obj__4typeFv(is_ptr__4typeFv(__1f->returns__3fct)->typ__5pvtyp);
            if (__3cn == 0) {
                struct ea __0__V256;

                error__FPCcRC2eaN32(
                    (const char *)"%n must return aP toCO, aR toCO, or aCO",
                    (const struct ea *)(((&__0__V256)->__O1__2ea.p = ((const void *)__0this)),
                                        (&__0__V256)),
                    (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
            }
        }

        break;

    case 213:
    case 23:
        if (__1f->f_virtual__3fct) {
            struct ea __0__V257;

            error__FPCcRC2eaN32(
                (const char *)"virtual%n (operator new() is static)",
                (const struct ea *)(((&__0__V257)->__O1__2ea.p = ((const void *)__0this)),
                                    (&__0__V257)),
                (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
        }
        if (__1class_name)
            __1f->f_static__3fct = 1;
        if (__1f->nargs_known__3fct != 1) {
            struct ea __0__V258;

            error__FPCcRC2eaN32(
                (const char *)"ATs must be fully specified for%n",
                (const struct ea *)(((&__0__V258)->__O1__2ea.p = ((const void *)__0this)),
                                    (&__0__V258)),
                (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
        } else if (__1f->nargs__3fct < 1) {
            struct ea __0__V259;

            error__FPCcRC2eaN32(
                (const char *)"%n requires a firstA ofT size_t",
                (const struct ea *)(((&__0__V259)->__O1__2ea.p = ((const void *)__0this)),
                                    (&__0__V259)),
                (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
        } else if (size_t_check__FP4type(__1f->argtype__3fct->__O1__4expr.tp)) {
            {
                struct ea __0__V260;

                error__FPCcRC2eaN32(
                    (const char *)"%n requires a firstA ofT size_t",
                    (const struct ea *)(((&__0__V260)->__O1__2ea.p = ((const void *)__0this)),
                                        (&__0__V260)),
                    (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
                __1f->argtype__3fct->__O1__4expr.tp = size_t_type;
                if (__1f->f_signature__3fct)
                    sign__3fctFv(__1f);
            }
        } else {
            Ptype __3t;

            __3t = (__1f->s_returns__3fct ? __1f->s_returns__3fct : __1f->returns__3fct);
            if (check__4typeFP4typeUcT2(__3t, Pvoid_type, (unsigned char)0, (unsigned char)0)) {
                struct ea __0__V261;

                error__FPCcRC2eaN32(
                    (const char *)"bad returnT for%n",
                    (const struct ea *)(((&__0__V261)->__O1__2ea.p = ((const void *)__0this)),
                                        (&__0__V261)),
                    (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
            }
        }
        break;

    case 212:
    case 9:
        if (__1f->f_virtual__3fct) {
            struct ea __0__V262;

            error__FPCcRC2eaN32(
                (const char *)"virtual%n (operator delete() is static)",
                (const struct ea *)(((&__0__V262)->__O1__2ea.p = ((const void *)__0this)),
                                    (&__0__V262)),
                (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
        };
        if (__1class_name) {
            __1f->f_static__3fct = 1;
            __2cl = (((struct classdef *)(((struct classdef *)__1class_name->__O1__4expr.tp))));
            if (in_class_dcl && look__5tableFPCcUc(__2cl->memtbl__8classdef, (const char *)"__dl",
                                                   (unsigned char)0))
                error__FPCc((const char *)"operator delete() cannot be overloaded");
        }

        if (__1f->nargs_known__3fct != 1) {
            struct ea __0__V263;

            error__FPCcRC2eaN32(
                (const char *)"ATs must be fully specified for%n",
                (const struct ea *)(((&__0__V263)->__O1__2ea.p = ((const void *)__0this)),
                                    (&__0__V263)),
                (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
        } else {
            Ptype __3t;

            __3t = (__1f->s_returns__3fct ? __1f->s_returns__3fct : __1f->returns__3fct);
            if (check__4typeFP4typeUcT2(__3t, (struct type *)void_type, (unsigned char)0,
                                        (unsigned char)0)) {
                struct ea __0__V264;

                error__FPCcRC2eaN32(
                    (const char *)"bad returnT for%n",
                    (const struct ea *)(((&__0__V264)->__O1__2ea.p = ((const void *)__0this)),
                                        (&__0__V264)),
                    (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
            } else {
                switch (__1f->nargs__3fct) {
                default: {
                    struct ea __0__V265;

                    error__FPCcRC2eaN32(
                        (const char *)"%n takes 1 or 2As",
                        (const struct ea *)(((&__0__V265)->__O1__2ea.p = ((const void *)__0this)),
                                            (&__0__V265)),
                        (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
                    break;
                case 1:
                case 2: {
                    Pname __6a;

                    __6a = __1f->argtype__3fct;
                    if (check__4typeFP4typeUcT2(__6a->__O1__4expr.tp, Pvoid_type, (unsigned char)0,
                                                (unsigned char)0)) {
                        struct ea __0__V266;

                        error__FPCcRC2eaN32((const char *)"%n's 1stA must be a void*",
                                            (const struct ea *)(((&__0__V266)->__O1__2ea.p =
                                                                     ((const void *)__0this)),
                                                                (&__0__V266)),
                                            (const struct ea *)ea0, (const struct ea *)ea0,
                                            (const struct ea *)ea0);
                    } else if (__6a = __6a->__O1__4name.n_list) {
                        if ((__1class_name == 0) && (__0this->n_oper__4name != 212)) {
                            struct ea __0__V267;

                            error__FPCcRC2eaN32((const char *)"%n takes only oneA",
                                                (const struct ea *)(((&__0__V267)->__O1__2ea.p =
                                                                         ((const void *)__0this)),
                                                                    (&__0__V267)),
                                                (const struct ea *)ea0, (const struct ea *)ea0,
                                                (const struct ea *)ea0);
                        } else if (check__4typeFP4typeUcT2(__6a->__O1__4expr.tp, size_t_type,
                                                           (unsigned char)0, (unsigned char)0)) {

                            {
                                struct ea __0__V268;

                                error__FPCcRC2eaN32(
                                    (const char *)"%n's 2ndA must be a size_t",
                                    (const struct ea *)(((&__0__V268)->__O1__2ea.p =
                                                             ((const void *)__0this)),
                                                        (&__0__V268)),
                                    (const struct ea *)ea0, (const struct ea *)ea0,
                                    (const struct ea *)ea0);
                                __6a->__O1__4expr.tp = size_t_type;
                                if (__1f->f_signature__3fct)
                                    sign__3fctFv(__1f);
                            }
                        }
                    }
                }
                }
                }
            }
        }
        break;

    case 70:
        if (__1class_name && (__1f->nargs__3fct == 1)) {
            Ptype __3t;
            Pname __3an;

            __3t = __1f->argtype__3fct->__O1__4expr.tp;
            __3an = is_cl_obj__4typeFv(__3t);
            if ((__3an == 0) && (__3t = (struct type *)is_ref__4typeFv(__3t))) {
                __3t = (((struct ptr *)(((struct ptr *)__3t))))->typ__5pvtyp;
            rx1:
                switch (__3t->base__4node) {
                case 97:
                    if (warning_opt &&
                        ((((struct basetype *)(((struct basetype *)__3t))))->b_const__4type == 0)) {
                        struct ea __0__V269;

                        struct ea __0__V270;

                        error__FiPCcRC2eaN33(
                            (int)'w',
                            (const char *)"assignment operators should take a const %t& not a %t&",
                            (const struct ea *)(((&__0__V269)->__O1__2ea.p = ((const void *)__3t)),
                                                (&__0__V269)),
                            (const struct ea *)(((&__0__V270)->__O1__2ea.p = ((const void *)__3t)),
                                                (&__0__V270)),
                            (const struct ea *)ea0, (const struct ea *)ea0);
                    }
                    __3t = (((struct basetype *)(((struct basetype *)__3t))))
                               ->b_name__8basetype->__O1__4expr.tp;
                    goto rx1;
                case 119:
                    __3an = (((struct basetype *)(((struct basetype *)__3t))))->b_name__8basetype;
                }
            }
            if (__3an && (__3an == __1class_name))
                (((struct classdef *)(((struct classdef *)__3an->__O1__4expr.tp))))
                    ->c_xref__8classdef |= 4;
        } else if (__1f->nargs__3fct == 2) {
            Ptype __3t;
            Pname __3an1;

            __3t = __1f->argtype__3fct->__O1__4expr.tp;

            if (__3t = (struct type *)is_ref__4typeFv(__3t)) {
                __3t = (((struct ptr *)(((struct ptr *)__3t))))->typ__5pvtyp;
            rx2:
                switch (__3t->base__4node) {
                case 97:
                    __3t = (((struct basetype *)(((struct basetype *)__3t))))
                               ->b_name__8basetype->__O1__4expr.tp;
                    goto rx2;
                case 119:
                    __3an1 = (((struct basetype *)(((struct basetype *)__3t))))->b_name__8basetype;
                }
            }
            __3t = __1f->argtype__3fct->__O1__4name.n_list->__O1__4expr.tp;
            {
                Pname __3an2;

                __3an2 = is_cl_obj__4typeFv(__3t);
                if ((__3an2 == 0) && (__3t = (struct type *)is_ref__4typeFv(__3t))) {
                    __3t = (((struct ptr *)(((struct ptr *)__3t))))->typ__5pvtyp;
                rx3:
                    switch (__3t->base__4node) {
                    case 97:
                        __3t = (((struct basetype *)(((struct basetype *)__3t))))
                                   ->b_name__8basetype->__O1__4expr.tp;
                        goto rx3;
                    case 119:
                        __3an2 =
                            (((struct basetype *)(((struct basetype *)__3t))))->b_name__8basetype;
                    }
                }
                if (__3an1 && (__3an1 == __3an2))
                    (((struct classdef *)(((struct classdef *)__3an1->__O1__4expr.tp))))
                        ->c_xref__8classdef |= 4;
            }
        }
    }

    switch (__1scope) {
    case 108:
    case 136:
        if (__0this->n_sto__4name == 31)
            error__FPCc((const char *)"D of staticF in aF");
        else {
            Pname __3nx;

            __3nx = look__5tableFPCcUc(gtbl, __0this->__O2__4expr.string, (unsigned char)0);
            if (__3nx) {
                switch (__3nx->__O1__4expr.tp->base__4node) {
                case 108:
                    if (check__4typeFP4typeUcT2(__0this->__O1__4expr.tp, __3nx->__O1__4expr.tp,
                                                (unsigned char)0, (unsigned char)0) &&
                        (__0this->n_sto__4name != 14)) {
                        struct ea __0__V271;

                        struct ea __0__V272;

                        error__FiPCcRC2eaN33((int)'w',
                                             (const char *)"%n has been locally re-declared as%t",
                                             (const struct ea *)(((&__0__V271)->__O1__2ea.p =
                                                                      ((const void *)__0this)),
                                                                 (&__0__V271)),
                                             (const struct ea *)__ct__2eaFPCv(
                                                 &__0__V272, (const void *)__0this->__O1__4expr.tp),
                                             (const struct ea *)ea0, (const struct ea *)ea0);
                    } else {
                        if ((((struct fct *)(((struct fct *)__3nx->__O1__4expr.tp))))
                                ->f_signature__3fct == 0)
                            sign__3fctFv(((struct fct *)(((struct fct *)__3nx->__O1__4expr.tp))));
                        if ((((struct fct *)(((struct fct *)__0this->__O1__4expr.tp))))
                                ->f_signature__3fct == 0)
                            sign__3fctFv(((struct fct *)(((struct fct *)__0this->__O1__4expr.tp))));
                        if ((((struct fct *)(((struct fct *)__3nx->__O1__4expr.tp))))
                                ->f_linkage__3fct !=
                            (((struct fct *)(((struct fct *)__0this->__O1__4expr.tp))))
                                ->f_linkage__3fct) {
                            struct ea __0__V273;

                            struct ea __0__V274;

                            error__FiPCcRC2eaN33(
                                (int)'w',
                                (const char *)"%n of type %t has been locally re-declared with "
                                              "different linkage",
                                (const struct ea *)(((&__0__V273)->__O1__2ea.p =
                                                         ((const void *)__0this)),
                                                    (&__0__V273)),
                                (const struct ea *)__ct__2eaFPCv(
                                    &__0__V274, (const void *)__0this->__O1__4expr.tp),
                                (const struct ea *)ea0, (const struct ea *)ea0);
                        }
                    }
                    break;
                case 76: {
                    Pname __6ny;

                    __6ny =
                        find__3genFP3fctUc(((struct gen *)(((struct gen *)__3nx->__O1__4expr.tp))),
                                           __1f, (unsigned char)0);
                    if (__6ny == 0) {
                        struct ea __0__V275;

                        struct ea __0__V276;

                        error__FiPCcRC2eaN33(
                            (int)'w', (const char *)"overloadedF%n has been locally declared as%t",
                            (const struct ea *)(((&__0__V275)->__O1__2ea.p =
                                                     ((const void *)__0this)),
                                                (&__0__V275)),
                            (const struct ea *)__ct__2eaFPCv(&__0__V276,
                                                             (const void *)__0this->__O1__4expr.tp),
                            (const struct ea *)ea0, (const struct ea *)ea0);
                    } else {
                        if ((((struct fct *)(((struct fct *)__6ny->__O1__4expr.tp))))
                                ->f_signature__3fct == 0)
                            sign__3fctFv(((struct fct *)(((struct fct *)__6ny->__O1__4expr.tp))));
                        if ((((struct fct *)(((struct fct *)__0this->__O1__4expr.tp))))
                                ->f_signature__3fct == 0)
                            sign__3fctFv(((struct fct *)(((struct fct *)__0this->__O1__4expr.tp))));
                        if ((((struct fct *)(((struct fct *)__6ny->__O1__4expr.tp))))
                                ->f_linkage__3fct !=
                            (((struct fct *)(((struct fct *)__0this->__O1__4expr.tp))))
                                ->f_linkage__3fct) {
                            struct ea __0__V277;

                            struct ea __0__V278;

                            error__FiPCcRC2eaN33(
                                (int)'w',
                                (const char *)"overloadedF%n of type %t has been locally "
                                              "re-declared with different linkage",
                                (const struct ea *)(((&__0__V277)->__O1__2ea.p =
                                                         ((const void *)__0this)),
                                                    (&__0__V277)),
                                (const struct ea *)__ct__2eaFPCv(
                                    &__0__V278, (const void *)__0this->__O1__4expr.tp),
                                (const struct ea *)ea0, (const struct ea *)ea0);
                        }
                    }
                } break;
                }
            }
        }
    }

    {
        Pname __1nn;
        if (__0this->n_sto__4name == 14) {
            __1nn = insert__5tableFP4nameUc(gtbl, __0this, (unsigned char)0);
            __1nn->lex_level__4name = 0;
        } else
            __1nn = insert__5tableFP4nameUc(__1etbl, __0this, (unsigned char)0);
        if (__1f->body__3fct)
            __1nn->where__4name = __0this->where__4name;
        assign__4nameFv(__1nn);
        if (__1nn->__O1__4expr.tp->base__4node == 108) {
            Pfct __2nnf;

            __2nnf = (((struct fct *)(((struct fct *)__1nn->__O1__4expr.tp))));
            if (__2nnf->f_this__3fct)
                __2nnf->f_this__3fct->where__4name = __0this->where__4name;
        }
        __0this->__O4__4expr.n_table = __1etbl;

        if (__0this->__O3__4expr.n_initializer) {
            if (__1f->f_virtual__3fct == 0) {
                struct ea __0__V279;

                error__FPCcRC2eaN32(
                    (const char *)"Ir for non-virtualF%n",
                    (const struct ea *)(((&__0__V279)->__O1__2ea.p = ((const void *)__0this)),
                                        (&__0__V279)),
                    (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
            }
            if (__0this->__O3__4expr.n_initializer != zero)
                error__FPCc((const char *)"virtualFIr must be 0");
        }

        if (Nold && (__1f->fct_base__3fct != 4)) {
            Pfct __2nf;

            __2nf = (((struct fct *)(((struct fct *)__1nn->__O1__4expr.tp))));

            if ((__2nf->base__4node == 141) || (__1f->base__4node == 141))
                ;
            else if (__2nf->base__4node == 76) {
                __0this->__O2__4expr.string = __1nn->__O2__4expr.string;
                __1nn = add__3genFP4name(((struct gen *)(((struct gen *)__2nf))), __0this);
                __1nn->where__4name = __0this->where__4name;
                if ((((struct fct *)(((struct fct *)__1nn->__O1__4expr.tp))))->f_this__3fct != 0)
                    (((struct fct *)(((struct fct *)__1nn->__O1__4expr.tp))))
                        ->f_this__3fct->where__4name = __0this->where__4name;

                if (Nold == 0) {
                    if (__1f->body__3fct && __0this->__O2__4name.n_qualifier) {
                        {
                            struct ea __0__V280;

                            error__FPCcRC2eaN32((const char *)"badAL for%n",
                                                (const struct ea *)(((&__0__V280)->__O1__2ea.p =
                                                                         ((const void *)__0this)),
                                                                    (&__0__V280)),
                                                (const struct ea *)ea0, (const struct ea *)ea0,
                                                (const struct ea *)ea0);
                            return (struct name *)0;
                        }
                    }
                    goto thth;
                }
                __2nf = (((struct fct *)(((struct fct *)__1nn->__O1__4expr.tp))));
                if (__1f->body__3fct && __2nf->body__3fct) {
                    if (((__1class_name == 0) ||
                         ((((struct classdef *)((
                               (struct classdef *)__1class_name->__O1__4expr.tp))))
                              ->class_base__8classdef != 4)) ||
                        (__1nn->n_redefined__4name == 0)) {
                        {
                            struct ea __0__V281;

                            error__FPCcRC2eaN32((const char *)"two definitions of%n",
                                                (const struct ea *)(((&__0__V281)->__O1__2ea.p =
                                                                         ((const void *)__1nn)),
                                                                    (&__0__V281)),
                                                (const struct ea *)ea0, (const struct ea *)ea0,
                                                (const struct ea *)ea0);
                            __1f->body__3fct = 0;
                        }
                    }
                    return (struct name *)0;
                }
                if (__1f->body__3fct)
                    goto bdbd;
                goto stst;
            } else if (__2nf->base__4node != 108) {
                {
                    struct ea __0__V282;

                    struct ea __0__V283;

                    error__FPCcRC2eaN32(
                        (const char *)"%n declared both as%t and asF",
                        (const struct ea *)(((&__0__V282)->__O1__2ea.p = ((const void *)__0this)),
                                            (&__0__V282)),
                        (const struct ea *)(((&__0__V283)->__O1__2ea.p = ((const void *)__2nf)),
                                            (&__0__V283)),
                        (const struct ea *)ea0, (const struct ea *)ea0);
                    __1f->body__3fct = 0;
                }
            } else {
                {
                    TOK __4t;

                    bit __4both_templs;
                    bit __4sp_templ;

                    __4t =
                        (((__2nf->fct_base__3fct == 1) || (__1f->fct_base__3fct == 1)) ? 204 : 76);

                    __4both_templs = (__2nf->fct_base__3fct && __1f->fct_base__3fct);
                    __4sp_templ =
                        (__4both_templs ? 0 : (__2nf->fct_base__3fct + __1f->fct_base__3fct));

                    if (check__4typeFP4typeUcT2((struct type *)__2nf, (struct type *)__1f, __4t,
                                                (unsigned char)0) ||
                        __4sp_templ) {
                        if (__1f->body__3fct && __0this->__O2__4name.n_qualifier) {
                            {
                                struct ea __0__V284;

                                struct ea __0__V285;

                                struct ea __0__V286;

                                error__FPCcRC2eaN32(
                                    (const char *)"%nT mismatch: %a and %a",
                                    (const struct ea *)(((&__0__V284)->__O1__2ea.p =
                                                             ((const void *)__1nn)),
                                                        (&__0__V284)),
                                    (const struct ea *)(((&__0__V285)->__O1__2ea.p =
                                                             ((const void *)__1nn)),
                                                        (&__0__V285)),
                                    (const struct ea *)(((&__0__V286)->__O1__2ea.p =
                                                             ((const void *)__0this)),
                                                        (&__0__V286)),
                                    (const struct ea *)ea0);
                                return (struct name *)0;
                            }
                        }
                        if (!strcmp(__1nn->__O2__4expr.string, (const char *)"main"))
                            error__FPCc((const char *)"cannot overload main()!");
                        {
                            Pgen __5g;

                            __5g = __ct__3genFv((struct gen *)0);
                            add_first = 1;
                            {
                                Pname __5n1;

                                __5n1 = add__3genFP4name(__5g, __1nn);
                                add_first = 0;
                                __0this->__O2__4expr.string = __1nn->__O2__4expr.string;
                                add_without_find = __4sp_templ;
                                {
                                    Pname __5n2;

                                    __5n2 = add__3genFP4name(__5g, __0this);
                                    add_without_find = 0;
                                    __1nn->__O1__4expr.tp = (struct type *)__5g;
                                    __1nn = __5n2;
                                    goto thth;
                                }
                            }
                        }
                    }
                }

                if (in_class_dcl) {
                } else if ((__2nf->f_static__3fct && (__1f->f_inline__3fct == 0)) &&
                           (__0this->n_sto__4name == 31)) {
                    __0this->n_sto__4name = 0;
                } else if (__0this->n_sto__4name &&
                           (__0this->n_sto__4name != __1nn->n_scope__4name)) {
                    if ((__0this->n_sto__4name == 14) && (__1nn->n_scope__4name == 31)) {
                        struct ea __0__V287;

                        error__FiPCcRC2eaN33(
                            (int)'w',
                            (const char *)"%n declared extern after being declared static",
                            (const struct ea *)(((&__0__V287)->__O1__2ea.p =
                                                     ((const void *)__0this)),
                                                (&__0__V287)),
                            (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
                    } else if ((__2nf->f_inline__3fct == 0) && (__1f->f_inline__3fct == 0)) {
                        unsigned long __2__X314;

                        if ((__1nn->__O1__4expr.tp == new_fct->__O1__4expr.tp) ||
                            (__1nn->__O1__4expr.tp == del_fct->__O1__4expr.tp))
                            __1nn->n_sto__4name = __0this->n_sto__4name;
                        else {
                            struct ea __0__V288;

                            struct ea __0__V289;

                            struct ea __0__V290;

                            error__FPCcRC2eaN32(
                                (const char *)"%n declared as both%k and%k",
                                (const struct ea *)(((&__0__V288)->__O1__2ea.p =
                                                         ((const void *)__0this)),
                                                    (&__0__V288)),
                                (const struct ea *)((__2__X314 = __0this->n_sto__4name),
                                                    (((((&__0__V289)->__O1__2ea.i = __2__X314), 0)),
                                                     (&__0__V289))),
                                (const struct ea *)__ct__2eaFUl(
                                    &__0__V290,
                                    (unsigned long)(__1nn->n_sto__4name
                                                        ? (((unsigned int)__1nn->n_sto__4name))
                                                        : (((unsigned int)14)))),
                                (const struct ea *)ea0);
                        }
                    }
                }

                {
                    int __4l1;
                    int __4l2;

                    __4l1 = __2nf->f_linkage__3fct;
                    __4l2 = __1f->f_linkage__3fct;
                    if ((__4l2 != 0) && (__4l1 != __4l2)) {
                        struct ea __0__V291;

                        error__FPCcRC2eaN32(
                            (const char *)"inconsistent linkage specifications for%n",
                            (const struct ea *)(((&__0__V291)->__O1__2ea.p =
                                                     ((const void *)__0this)),
                                                (&__0__V291)),
                            (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
                    }
                }
                if (__2nf->body__3fct && __1f->body__3fct) {
                    if (((__1class_name == 0) ||
                         ((((struct classdef *)((
                               (struct classdef *)__1class_name->__O1__4expr.tp))))
                              ->class_base__8classdef != 4)) ||
                        (__1nn->n_redefined__4name == 0)) {
                        {
                            struct ea __0__V292;

                            error__FPCcRC2eaN32((const char *)"two definitions of%n",
                                                (const struct ea *)(((&__0__V292)->__O1__2ea.p =
                                                                         ((const void *)__0this)),
                                                                    (&__0__V292)),
                                                (const struct ea *)ea0, (const struct ea *)ea0,
                                                (const struct ea *)ea0);
                            __1f->body__3fct = 0;
                        }
                    }
                    return (struct name *)0;
                }

                if (__1f->body__3fct)
                    goto bdbd;

                goto stst;

            bdbd:
                if (__1f->nargs_known__3fct && __2nf->nargs_known__3fct)
                    if (__0this->n_sto__4name == 14)
                        __2nf->argtype__3fct = __1f->argtype__3fct;
                    else
                        merge_init__FP4nameP3fctT2(__1nn, __1f, __2nf);
                __1f->f_virtual__3fct = __2nf->f_virtual__3fct;
                __1f->f_this__3fct = __2nf->f_this__3fct;
                __1f->f_result__3fct = __2nf->f_result__3fct;
                __1f->s_returns__3fct = __2nf->s_returns__3fct;
                __1f->f_args__3fct = __2nf->f_args__3fct;
                __1f->f_signature__3fct = __2nf->f_signature__3fct;
                __1f->f_const__3fct = __2nf->f_const__3fct;
                __1f->f_static__3fct = __2nf->f_static__3fct;
                __1nn->__O1__4expr.tp = (struct type *)__1f;
                if (__1f->f_inline__3fct) {
                    if (__2nf->f_inline__3fct == 0) {
                        if (__1nn->n_used__4name && (__1nn->n_sto__4name != 31)) {
                            struct ea __0__V293;

                            error__FPCcRC2eaN32((const char *)"%n declared with external linkage "
                                                              "and called before defined as inline",
                                                (const struct ea *)(((&__0__V293)->__O1__2ea.p =
                                                                         ((const void *)__1nn)),
                                                                    (&__0__V293)),
                                                (const struct ea *)ea0, (const struct ea *)ea0,
                                                (const struct ea *)ea0);
                        } else if (__1nn->n_used__4name) {
                            take_addr__4nameFv(__1nn);
                            if (warning_opt) {
                                struct ea __0__V294;

                                error__FiPCcRC2eaN33(
                                    (int)'w', (const char *)"%n called before defined as inline",
                                    (const struct ea *)(((&__0__V294)->__O1__2ea.p =
                                                             ((const void *)__1nn)),
                                                        (&__0__V294)),
                                    (const struct ea *)ea0, (const struct ea *)ea0,
                                    (const struct ea *)ea0);
                            }
                        }
                    }
                    __2nf->f_inline__3fct = 1;
                    __1nn->n_sto__4name = 31;
                } else if (__2nf->f_inline__3fct) {
                    __1f->f_inline__3fct = 1;
                }
                goto stst2;

            stst:
                if (__1f->nargs_known__3fct && __2nf->nargs_known__3fct)
                    if ((__0this->n_sto__4name == 14) || __1f->f_inline__3fct)
                        __2nf->argtype__3fct = __1f->argtype__3fct;
                    else
                        merge_init__FP4nameP3fctT2(__1nn, __1f, __2nf);
                __1f->f_args__3fct = __2nf->f_args__3fct;
            stst2:
                if (__1f->f_inline__3fct)
                    __0this->n_sto__4name = 31;
                if (((__0this->n_sto__4name == 31) && (__1nn->n_sto__4name == 14)) &&
                    ((strcmp(__0this->__O2__4expr.string, (const char *)"__nw") == 0) ||
                     (strcmp(__0this->__O2__4expr.string, (const char *)"__dl") == 0)))
                    __1nn->n_sto__4name = 31;
                __0this->n_scope__4name = __1nn->n_scope__4name;
                __0this->n_sto__4name = __1nn->n_sto__4name;
            }
        } else {
        thth:
            __1just_made = 1;
            if (__1f->f_inline__3fct)
                __1nn->n_sto__4name = 31;
            else if (((__1class_name == 0) && (__0this->n_sto__4name == 0)) &&
                     (__1f->body__3fct == 0))
                __1nn->n_sto__4name = 14;

            if (__1f->f_static__3fct)
                switch (__0this->n_oper__4name) {
                case 161:
                case 162:
                case 97:
                case 109:
                case 111:
                case 44:
                case 70: {
                    struct ea __0__V295;

                    error__FPCcRC2eaN32(
                        (const char *)"%n cannot be a staticMF",
                        (const struct ea *)(((&__0__V295)->__O1__2ea.p = ((const void *)__1nn)),
                                            (&__0__V295)),
                        (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
                    __1f->f_static__3fct = 0;
                }
                }

            if ((((((__1class_name && (__1f->f_static__3fct == 0)) &&
                    (__0this->n_oper__4name != 23)) &&
                   (__0this->n_oper__4name != 213)) &&
                  (__0this->n_oper__4name != 9)) &&
                 (__0this->n_oper__4name != 212)) &&
                (__1etbl != gtbl)) {
                Pname __3tt;

                __3tt = __ct__4nameFPCc((struct name *)0, (const char *)"this");
                __3tt->n_scope__4name = 136;
                __3tt->where__4name = __0this->where__4name;
                __3tt->__O1__4expr.tp =
                    (((struct classdef *)(((struct classdef *)__1class_name->__O1__4expr.tp))))
                        ->this_type__8classdef;
                __3tt->permanent__4node = 1;

                (((struct fct *)(((struct fct *)__1nn->__O1__4expr.tp))))->f_this__3fct =
                    (__1f->f_this__3fct =
                         ((((struct fct *)(((struct fct *)__1nn->__O1__4expr.tp))))->f_args__3fct =
                              (__1f->f_args__3fct = __3tt)));
                __3tt->__O1__4name.n_list = __1f->argtype__3fct;

                if (__1f->f_const__3fct) {
                    Pbase __4x;
                    Pbase __4y;

                    __4x = (((struct basetype *)((
                        (struct basetype *)(((struct ptr *)(((struct ptr *)__3tt->__O1__4expr.tp))))
                            ->typ__5pvtyp))));
                    __4y = __ct__8basetypeFUcP4name((struct basetype *)0, (unsigned char)119,
                                                    (struct name *)0);
                    ((*__4y)) = (*__4x);
                    __4y->b_const__4type = 1;
                    __3tt->__O1__4expr.tp = (struct type *)__ct__3ptrFUcP4type(
                        (struct ptr *)0, (unsigned char)125, (struct type *)__4y);
                    (((struct ptr *)(((struct ptr *)__3tt->__O1__4expr.tp))))->b_const__4type = 1;
                    __3tt->__O1__4expr.tp->permanent__4node = 1;
                }
            } else {
                (((struct fct *)(((struct fct *)__1nn->__O1__4expr.tp))))->f_args__3fct =
                    (__1f->f_args__3fct =
                         (__1f->f_result__3fct ? __1f->f_result__3fct : __1f->argtype__3fct));
                (((struct fct *)(((struct fct *)__1nn->__O1__4expr.tp))))->f_signature__3fct =
                    __1f->f_signature__3fct;
                (((struct fct *)(((struct fct *)__1nn->__O1__4expr.tp))))->f_const__3fct =
                    __1f->f_const__3fct;
                (((struct fct *)(((struct fct *)__1nn->__O1__4expr.tp))))->f_static__3fct =
                    __1f->f_static__3fct;
            }

            if ((((struct fct *)(((struct fct *)__1nn->__O1__4expr.tp))))->f_signature__3fct == 0)
                sign__3fctFv(((struct fct *)(((struct fct *)__1nn->__O1__4expr.tp))));

            if (__1f->f_result__3fct == 0) {
                make_res__FP3fct(__1f);
            } else if (__1f->f_this__3fct)
                __1f->f_this__3fct->__O1__4name.n_list = __1f->f_result__3fct;

            if ((__1nn->n_oper__4name == 161) || (__1nn->n_oper__4name == 162))
                vbase_pointers__FP4nameP8classdef(
                    __1nn,
                    ((struct classdef *)(((struct classdef *)__1class_name->__O1__4expr.tp))));

            if (__1f->f_virtual__3fct) {
                switch (__1nn->n_scope__4name) {
                default: {
                    struct ea __0__V296;

                    error__FPCcRC2eaN32(
                        (const char *)"nonC virtual%n",
                        (const struct ea *)(((&__0__V296)->__O1__2ea.p = ((const void *)__0this)),
                                            (&__0__V296)),
                        (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
                    break;
                case 0:
                case 25:
                    cc->cot__11dcl_context->virt_count__8classdef = 1;
                    (((struct fct *)(((struct fct *)__1nn->__O1__4expr.tp))))->f_virtual__3fct =
                        __1f->f_virtual__3fct;
                    break;
                }
                }
            }
        }

        if (__1just_made)
            switch (__0this->n_oper__4name) {
            case 161:
                switch (__1f->nargs__3fct) {
                case 0:
                    break;
                default: {
                    Pname __4n2;

                    __4n2 = __1f->argtype__3fct->__O1__4name.n_list;
                    if ((__4n2->__O3__4expr.n_initializer == 0) && (__4n2->n_evaluated__4name == 0))
                        break;
                }
                case 1: {
                    Ptype __4t;

                    __4t = __1f->argtype__3fct->__O1__4expr.tp;
                clll:
                    switch (__4t->base__4node) {
                    case 97:
                        __4t = (((struct basetype *)(((struct basetype *)__4t))))
                                   ->b_name__8basetype->__O1__4expr.tp;
                        goto clll;
                    case 158:
                        __4t = (((struct ptr *)(((struct ptr *)__4t))))->typ__5pvtyp;
                    cxll:
                        switch (__4t->base__4node) {
                        case 97:
                            if (warning_opt && ((((struct basetype *)(((struct basetype *)__4t))))
                                                    ->b_const__4type == 0)) {
                                struct ea __0__V297;

                                struct ea __0__V298;

                                error__FiPCcRC2eaN33(
                                    (int)'w',
                                    (const char
                                         *)"copy constructors should take a const %t& not a %t&",
                                    (const struct ea *)(((&__0__V297)->__O1__2ea.p =
                                                             ((const void *)__4t)),
                                                        (&__0__V297)),
                                    (const struct ea *)(((&__0__V298)->__O1__2ea.p =
                                                             ((const void *)__4t)),
                                                        (&__0__V298)),
                                    (const struct ea *)ea0, (const struct ea *)ea0);
                            }
                            __4t = (((struct basetype *)(((struct basetype *)__4t))))
                                       ->b_name__8basetype->__O1__4expr.tp;
                            goto cxll;
                        case 119:
                            if (__1class_name == (((struct basetype *)(((struct basetype *)__4t))))
                                                     ->b_name__8basetype)
                                (((struct classdef *)((
                                     (struct classdef *)__1class_name->__O1__4expr.tp))))
                                    ->c_itor__8classdef = __1nn;
                        }
                        break;
                    case 119:
                        if (__1class_name ==
                            (((struct basetype *)(((struct basetype *)__4t))))->b_name__8basetype) {
                            const void *__2__X315;

                            {
                                struct ea __0__V299;

                                struct ea __0__V300;

                                struct ea __0__V301;

                                struct ea __0__V302;

                                error__FPCcRC2eaN32(
                                    (const char *)"badK %s(%s) use %s(%s&)",
                                    (const struct ea *)((__2__X315 = (const void *)__1class_name
                                                                         ->__O2__4expr.string),
                                                        (((&__0__V299)->__O1__2ea.p = __2__X315),
                                                         (&__0__V299))),
                                    (const struct ea *)__ct__2eaFPCv(
                                        &__0__V300,
                                        (const void *)__1class_name->__O2__4expr.string),
                                    (const struct ea *)__ct__2eaFPCv(
                                        &__0__V301,
                                        (const void *)__1class_name->__O2__4expr.string),
                                    (const struct ea *)__ct__2eaFPCv(
                                        &__0__V302,
                                        (const void *)__1class_name->__O2__4expr.string));

                                __1f->argtype__3fct->__O1__4expr.tp = (struct type *)any_type;
                            }
                        }
                    }
                }
                }
                if ((((struct classdef *)(((struct classdef *)__1class_name->__O1__4expr.tp))))
                        ->c_ctor__8classdef == 0)
                    (((struct classdef *)(((struct classdef *)__1class_name->__O1__4expr.tp))))
                        ->c_ctor__8classdef = __1nn;
                break;

            case 97:
                __1nn->__O1__4name.n_list =
                    (((struct classdef *)(((struct classdef *)__1class_name->__O1__4expr.tp))))
                        ->conv__8classdef;
                (((struct classdef *)(((struct classdef *)__1class_name->__O1__4expr.tp))))
                    ->conv__8classdef = __1nn;
                break;

            case 162:
                (((struct classdef *)(((struct classdef *)__1class_name->__O1__4expr.tp))))
                    ->c_dtor__8classdef = __1nn;
                break;

            case 23:
            case 213:
            case 9:
            case 212:
            case 109:
            case 0:
                break;

            default: {
                Pname __3a;

                __3a = __1f->argtype__3fct;
                for (; __3a; __3a = __3a->__O1__4name.n_list) {
                    if (__3a->__O3__4expr.n_initializer) {
                        struct ea __0__V303;

                        error__FPCcRC2eaN32((const char *)"%n: operatorFs cannot take defaultA",
                                            (const struct ea *)(((&__0__V303)->__O1__2ea.p =
                                                                     ((const void *)__0this)),
                                                                (&__0__V303)),
                                            (const struct ea *)ea0, (const struct ea *)ea0,
                                            (const struct ea *)ea0);
                    }
                }

                if (__1f->nargs_known__3fct != 1) {
                    {
                        struct ea __0__V304;

                        error__FPCcRC2eaN32(
                            (const char *)"ATs must be fully specified for%n",
                            (const struct ea *)(((&__0__V304)->__O1__2ea.p = ((const void *)__1nn)),
                                                (&__0__V304)),
                            (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
                    }
                }
                if (__1class_name == 0) {
                    __3a = __1f->argtype__3fct;
                    __3a = __1f->argtype__3fct;
                    for (; __3a; __3a = __3a->__O1__4name.n_list) {
                        Ptype __5tx;

                        __5tx = skiptypedefs__4typeFv(__3a->__O1__4expr.tp);
                        if (is_ref__4typeFv(__5tx))
                            __5tx = (((struct ptr *)(((struct ptr *)__5tx))))->typ__5pvtyp;
                        if (is_cl_obj__4typeFv(__5tx))
                            break;
                    }
                    if (!__3a) {
                        struct ea __0__V305;

                        error__FPCcRC2eaN32(
                            (const char *)"%n must take at least oneCTA",
                            (const struct ea *)(((&__0__V305)->__O1__2ea.p = ((const void *)__1nn)),
                                                (&__0__V305)),
                            (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
                    }
                }

                {
                    bit __3memberonly;

                    __3memberonly = 0;
                    switch (__0this->n_oper__4name) {
                    case 47:
                    case 46:
                        if (((!__1class_name) && (__1f->nargs__3fct == 1)) || __1class_name)
                            ;
                        else {
                            struct ea __0__V306;

                            error__FPCcRC2eaN32((const char *)"%n takes 1A",
                                                (const struct ea *)(((&__0__V306)->__O1__2ea.p =
                                                                         ((const void *)__1nn)),
                                                                    (&__0__V306)),
                                                (const struct ea *)ea0, (const struct ea *)ea0,
                                                (const struct ea *)ea0);
                        }
                        break;
                    case 111:
                    case 70:
                        __3memberonly = 1;
                    case 180:
                    case 173:
                    case 51:
                    case 53:
                    case 56:
                    case 57:
                    case 58:
                    case 59:
                    case 60:
                    case 61:
                    case 62:
                    case 63:
                    case 64:
                    case 65:
                    case 66:
                    case 67:
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
                    case 71:
                        if (((!__1class_name) && (__3memberonly || (__1f->nargs__3fct == 2))) ||
                            (__1class_name && (__1f->nargs__3fct == 1)))
                            ;
                        else {
                            struct ea __0__V307;

                            error__FPCcRC2eaN32((const char *)(__1class_name
                                                                   ? "%n takes 1A"
                                                                   : (((char *)"%n takes 2As"))),
                                                (const struct ea *)(((&__0__V307)->__O1__2ea.p =
                                                                         ((const void *)__1nn)),
                                                                    (&__0__V307)),
                                                (const struct ea *)ea0, (const struct ea *)ea0,
                                                (const struct ea *)ea0);
                        }
                        break;

                    case 50:
                    case 52:
                    case 54:
                    case 55:
                    case 48:
                    case 49:
                        if (((!__1class_name) &&
                             ((__1f->nargs__3fct == 1) || (__1f->nargs__3fct == 2))) ||
                            (__1class_name && (__1f->nargs__3fct <= 1)))
                            ;
                        else {
                            struct ea __0__V308;

                            error__FPCcRC2eaN32(
                                (const char *)(__1class_name ? "%n takes 0 or 1A"
                                                             : (((char *)"%n takes 1 or 2As"))),
                                (const struct ea *)(((&__0__V308)->__O1__2ea.p =
                                                         ((const void *)__1nn)),
                                                    (&__0__V308)),
                                (const struct ea *)ea0, (const struct ea *)ea0,
                                (const struct ea *)ea0);
                        }
                        break;
                    }
                }
            }
            }

        {
            int __1i;

            __1i = 0;

            {
                {
                    Pname __1a;

                    __1a = __1f->f_args__3fct;

                    for (; __1a; __1a = __1a->__O1__4name.n_list) {
                        if (__1a->__O3__4expr.n_initializer)
                            __1i = 1;
                        else if (__1i)
                            if (__1a) {
                                struct ea __0__V309;

                                error__FPCcRC2eaN32((const char *)"trailingA%n withoutIr",
                                                    (const struct ea *)(((&__0__V309)->__O1__2ea.p =
                                                                             ((const void *)__1a)),
                                                                        (&__0__V309)),
                                                    (const struct ea *)ea0, (const struct ea *)ea0,
                                                    (const struct ea *)ea0);
                            } else
                                error__FPCc((const char *)"trailingA withoutIr");
                    }

                    if (__1f->body__3fct)
                        dcl__3fctFP4name(__1f, __1nn);

                    in_class_dcl = __1old_in_class_dcl;
                    return __1nn;
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
