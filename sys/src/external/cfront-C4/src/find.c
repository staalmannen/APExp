
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

extern int error__FPCcRC2eaN32(const char *, const struct ea *, const struct ea *,
                               const struct ea *, const struct ea *);

struct fct *__ct__3fctFP4typeP4nameUc(struct fct *__0this, Ptype, Pname, TOK);

Pname undef__FP4nameP5tableUc(Pname __1n, Ptable __1tbl, TOK __1f) {
    switch (__1f) {
        const void *__2__X31;

    case 84: {
        struct ea __0__V26;

        error__FPCcRC2eaN32(
            (const char *)"illegalF call: explicit call ofK %s()",
            (const struct ea *)((__2__X31 = (const void *)__1n->__O2__4expr.string),
                                (((&__0__V26)->__O1__2ea.p = __2__X31), (&__0__V26))),
            (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
        break;
    case 0: {
        struct ea __0__V27;

        error__FPCcRC2eaN32(
            (const char *)"%nU",
            (const struct ea *)(((&__0__V27)->__O1__2ea.p = ((const void *)__1n)), (&__0__V27)),
            (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);

        break;
    case 109: {
        struct ea __0__V28;

        error__FPCcRC2eaN32(
            (const char *)"UF%n called",
            (const struct ea *)(((&__0__V28)->__O1__2ea.p = ((const void *)__1n)), (&__0__V28)),
            (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);

        break;
    case 44:
    case 45: {
        struct ea __0__V29;

        error__FPCcRC2eaN32(
            (const char *)"M%nU",
            (const struct ea *)(((&__0__V29)->__O1__2ea.p = ((const void *)__1n)), (&__0__V29)),
            (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);

        break;
    case 112: {
        struct ea __0__V30;

        error__FPCcRC2eaN32(
            (const char *)"address ofU%n",
            (const struct ea *)(((&__0__V30)->__O1__2ea.p = ((const void *)__1n)), (&__0__V30)),
            (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);

        break;
    }
    }
    }
    }
    }
    }

    if (__1tbl == gtbl) {
        Pname __2nn;

        __2nn = insert__5tableFP4nameUc(__1tbl, __1n, (unsigned char)0);
        if (__1f == 109) {
            __2nn->__O1__4expr.tp = (struct type *)__ct__3fctFP4typeP4nameUc(
                (struct fct *)0, (struct type *)defa_type, (struct name *)0, (unsigned char)0);
            __2nn->n_sto__4name = (__2nn->n_scope__4name = 14);
        } else
            __2nn->__O1__4expr.tp = (struct type *)any_type;
        ((__1n ? (((void)(__1n ? (((void)((((((struct expr *)__1n))
                                                ? (((void)((((struct expr *)__1n))
                                                               ? (((void)(((void)0))))
                                                               : (((void)0)))))
                                                : (((void)0)))),
                                          (((void)__dl__4nameSFPvUl(
                                              (void *)__1n, (size_t)(sizeof(struct name))))))))
                               : (((void)0)))))
               : (((void)0))));
        return __2nn;
    }

    __1n->__O4__4expr.n_table = __1tbl;
    __1n->__O1__4expr.tp = (struct type *)any_type;
    return __1n;
}

static int mptr;
static Pname me;
static Pfct mef;
Pclass tcl = 0;
Pclass mec = 0;
int mex = 0;

extern int error__FP3locPCcRC2eaN33(struct loc *, const char *, const struct ea *,
                                    const struct ea *, const struct ea *, const struct ea *);

bit is_const_object__4typeFv(struct type *__0this);

static void check_local_nested_ref__FP4nameUc3loc(Pname __1nn, TOK __1f, struct loc __1where) {
    if (processing_sizeof)
        return;

    switch (__1nn->n_scope__4name) {
    case 136: {
        struct ea __0__V32;

        error__FP3locPCcRC2eaN33(
            &__1where, (const char *)"automatic variable%n referenced in localC",
            (const struct ea *)(((&__0__V32)->__O1__2ea.p = ((const void *)__1nn)), (&__0__V32)),
            (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
        break;
    case 108:
        if (((__1nn->n_sto__4name != 31) && (__1nn->n_sto__4name != 14)) &&
            (__1nn->n_stclass__4name != 13)) {
            switch (skiptypedefs__4typeFv(__1nn->__O1__4expr.tp)->base__4node) {
            case 108:
            case 76:
                break;
            default:
                if (!is_const_object__4typeFv(__1nn->__O1__4expr.tp)) {
                    struct ea __0__V33;

                    error__FP3locPCcRC2eaN33(
                        &__1where, (const char *)"automatic variable%n referenced in localC",
                        (const struct ea *)(((&__0__V33)->__O1__2ea.p = ((const void *)__1nn)),
                                            (&__0__V33)),
                        (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
                } else if (__1f == 112) {
                    struct ea __0__V34;

                    error__FP3locPCcRC2eaN33(
                        &__1where, (const char *)"address of local const%n in localC",
                        (const struct ea *)(((&__0__V34)->__O1__2ea.p = ((const void *)__1nn)),
                                            (&__0__V34)),
                        (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
                }
            }
        }
        break;
    case 0:
    case 25:
        break;
    }
    }
}

extern int strcmp(const char *, const char *);

Pname look__5tableFPCcUc(struct table *__0this, const char *, TOK);

Pexpr contents__4exprFv(struct expr *__0this);

extern int error__FiP3locPCcRC2eaN34(int, struct loc *, const char *, const struct ea *,
                                     const struct ea *, const struct ea *, const struct ea *);

Pclass is_base__8classdefFPCcPUci(struct classdef *__0this, const char *, TOK *, int __1level);

Pexpr find_name__8classdefFPCcP8classdefiT3(struct classdef *__0this, const char *, Pclass, int,
                                            int);

Pptr is_ref__4typeFv(struct type *__0this);

void del__4nameFv(struct name *__0this);

const char *whatami__5tableFv(struct table *__0this);

static struct ea *__ct__2eaFPCv(struct ea *__0this, const void *__2pp);

Pexpr find_name__FP4nameP8classdefP5tableiT1(Pname __1n, Pclass __1cl, Ptable __1tbl, int __1f,
                                             Pname __1m) {
    if (__1n == 0) {
        struct ea __0__V35;

        struct ea __0__V36;

        struct ea __0__V37;

        struct ea __0__V38;

        error__FiPCcRC2eaN33(
            (int)'i', (const char *)"find_name(n==0,cl==%t,tbl==%d,f==%k,m==%n)",
            (const struct ea *)(((&__0__V35)->__O1__2ea.p = ((const void *)__1cl)), (&__0__V35)),
            (const struct ea *)(((&__0__V36)->__O1__2ea.p = ((const void *)__1tbl)), (&__0__V36)),
            (const struct ea *)(((((&__0__V37)->__O1__2ea.i = ((unsigned long)__1f)), 0)),
                                (&__0__V37)),
            (const struct ea *)(((&__0__V38)->__O1__2ea.p = ((const void *)__1m)), (&__0__V38)));
    }
    {
        Pname __1q;
        const char *__1s;
        Pfct __1mf;
        Pname __1tnrv;

        Pexpr __1ee;

        unsigned long __2__X16;

        struct ea __0__X__V1400qm5kwanawcnm;

        struct ea __0__X__V1500qm5kwanawcnm;

        __1q = __1n->__O2__4name.n_qualifier;
        __1s = __1n->__O2__4expr.string;
        __1mf =
            (__1m ? (((__1m->__O1__4expr.tp->base__4node == 108)
                          ? (((struct fct *)(((struct fct *)__1m->__O1__4expr.tp))))
                          : (error__FiPCcRC2eaN33(
                                 (int)'i', (const char *)"N::fct_type():%n is %k notF",
                                 (const struct ea *)(((&__0__X__V1400qm5kwanawcnm)->__O1__2ea.p =
                                                          ((const void *)__1m)),
                                                     (&__0__X__V1400qm5kwanawcnm)),
                                 (const struct ea *)((__2__X16 = __1m->__O1__4expr.tp->base__4node),
                                                     (((((&__0__X__V1500qm5kwanawcnm)->__O1__2ea.i =
                                                             __2__X16),
                                                        0)),
                                                      (&__0__X__V1500qm5kwanawcnm))),
                                 (const struct ea *)ea0, (const struct ea *)ea0),
                             (((struct fct *)0)))))
                  : (((struct fct *)0)));

        if ((((((__1mf && __1mf->nrv__3fct) && (!__1q)) && (__1f != 45)) && (__1f != 44)) &&
             (strcmp(__1mf->nrv__3fct->__O2__4expr.string, __1s) == 0)) &&
            (((__1tnrv = look__5tableFPCcUc(__1tbl, __1s, (unsigned char)0)) == 0) ||
             (__1tnrv->__O4__4expr.n_table == gtbl)))
            return contents__4exprFv((struct expr *)__1mf->f_result__3fct);

        ;

        ;

        tcl = __1cl;

        mex = 1;
        if (me = __1m) {
            const void *__2__X76;

            unsigned long __2__X77;

            mef = (((struct fct *)(((struct fct *)me->__O1__4expr.tp))));
            if (mef->base__4node != 108) {
                struct ea __0__V39;

                struct ea __0__V40;

                error__FiPCcRC2eaN33(
                    (int)'i', (const char *)"mef %d %k",
                    (const struct ea *)((__2__X76 = (const void *)mef),
                                        (((&__0__V39)->__O1__2ea.p = __2__X76), (&__0__V39))),
                    (const struct ea *)((__2__X77 = mef->base__4node),
                                        (((((&__0__V40)->__O1__2ea.i = __2__X77), 0)),
                                         (&__0__V40))),
                    (const struct ea *)ea0, (const struct ea *)ea0);
            }
            if (cc->cot__11dcl_context &&
                (cc->cot__11dcl_context->lex_level__4type > __1m->lex_level__4name))
                mec = cc->cot__11dcl_context;
            else
                mec = mef->memof__3fct;
        } else {
            mef = 0;
            if ((!__1tbl) && ((__1f == 45) || (__1f == 44)))
                mec = cc->cot__11dcl_context;
            else {
                if (((((__1q == 0) && (__1cl == 0)) && __1tbl) && (__1tbl != gtbl)) &&
                    __1tbl->t_name__5table) {
                    __1cl = (((struct classdef *)((
                        (struct classdef *)__1tbl->t_name__5table->__O1__4expr.tp))));
                    if (__1cl->base__4node != 6) {
                        struct ea __0__V41;

                        struct ea __0__V42;

                        struct ea __0__V43;

                        error__FiP3locPCcRC2eaN34(
                            (int)'i', &__1n->where__4name,
                            (const char *)"find_name(%n, 0, %d,%k, 0 ) --CTX for table",
                            (const struct ea *)(((&__0__V41)->__O1__2ea.p = ((const void *)__1n)),
                                                (&__0__V41)),
                            (const struct ea *)(((&__0__V42)->__O1__2ea.p = ((const void *)__1tbl)),
                                                (&__0__V42)),
                            (const struct ea *)(((((&__0__V43)->__O1__2ea.i =
                                                       ((unsigned long)__1f)),
                                                  0)),
                                                (&__0__V43)),
                            (const struct ea *)ea0);
                    }
                }
                mec = __1cl;
            }
        }

        if (__1n->base__4node == 177) {
            struct ea __0__V44;

            error__FiPCcRC2eaN33(
                (int)'i', (const char *)"find (mdot%n)",
                (const struct ea *)(((&__0__V44)->__O1__2ea.p = ((const void *)__1n)), (&__0__V44)),
                (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
        }
        if (__1n->__O4__4expr.n_table) {
            me = 0;

            return (struct expr *)__1n;
        }

        if ((me == 0) && ((__1tbl == gtbl) || (cc->nof__11dcl_context == 0)))
            me = dummy_fct;

        if (__1q) {
            if (__1q == sta_name) {
                Pname __3nn;

                __3nn = look__5tableFPCcUc(gtbl, __1s, (unsigned char)0);
                if (__3nn == 0) {
                    me = 0;

                    return (struct expr *)undef__FP4nameP5tableUc(__1n, gtbl, (unsigned char)__1f);
                }
                ((__3nn->n_used__4name++), (((void)0)));
                ((__1n ? (((void)(__1n ? (((void)((((((struct expr *)__1n))
                                                        ? (((void)((((struct expr *)__1n))
                                                                       ? (((void)(((void)0))))
                                                                       : (((void)0)))))
                                                        : (((void)0)))),
                                                  (((void)__dl__4nameSFPvUl(
                                                      (void *)__1n,
                                                      (size_t)(sizeof(struct name))))))))
                                       : (((void)0)))))
                       : (((void)0))));
                me = 0;
                return (struct expr *)__3nn;
            }

            {
                Pname __3aq;

                __3aq = __1q;
                while (__3aq->__O1__4expr.tp->base__4node == 97)
                    __3aq = (((struct basetype *)(((struct basetype *)__3aq->__O1__4expr.tp))))
                                ->b_name__8basetype;
                if (__3aq->__O1__4expr.tp->base__4node != 119) {
                    if (__3aq->n_template_arg__4name == 1) {
                        struct ea __0__V45;

                        struct ea __0__V46;

                        error__FiPCcRC2eaN33(
                            (int)'s', (const char *)"use of %n::%sW formalYTZ",
                            (const struct ea *)(((&__0__V45)->__O1__2ea.p = ((const void *)__3aq)),
                                                (&__0__V45)),
                            (const struct ea *)(((&__0__V46)->__O1__2ea.p = ((const void *)__1s)),
                                                (&__0__V46)),
                            (const struct ea *)ea0, (const struct ea *)ea0);
                    } else {
                        struct ea __0__V47;

                        error__FPCcRC2eaN32(
                            (const char *)"Qr%n not aCN",
                            (const struct ea *)(((&__0__V47)->__O1__2ea.p = ((const void *)__1q)),
                                                (&__0__V47)),
                            (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
                    }
                    me = 0;
                    return (struct expr *)undef__FP4nameP5tableUc(__1n, gtbl, (unsigned char)__1f);
                }
                __1q = __3aq;
            }
            {
                Pclass __2qcl;

                Pclass __2bcl;

                struct classdef *__1__X82;

                struct classdef *__1__X83;

                const void *__2__X84;

                __2qcl = (((struct classdef *)((
                    (struct classdef *)(((struct basetype *)((
                                            (struct basetype *)__1q->__O1__4expr.tp))))
                        ->b_name__8basetype->__O1__4expr.tp))));

                __2bcl = __1cl;

                if ((__1cl == 0) || (__1f == 112))
                    __2bcl = (__1cl = __2qcl);
                else {
                    struct classdef *__1__X78;

                    struct classdef *__1__X79;

                    if (!((__1__X78 = __2qcl),
                          ((__1__X79 = __1cl),
                           (((__1__X78 == __1__X79)
                                 ? 1
                                 : ((__1__X78 && __1__X79)
                                        ? (((int)same_class__8classdefFP8classdefi(__1__X78,
                                                                                   __1__X79, 0)))
                                        : 0)))))) {
                        struct classdef *__1__X80;

                        struct classdef *__1__X81;

                        __2bcl = is_base__8classdefFPCcPUci(__1cl, __2qcl->string__8classdef,
                                                            (TOK *)0, 0);
                        if ((__2bcl == 0) ||
                            (!((__1__X80 = __2bcl),
                               ((__1__X81 = __2qcl),
                                (((__1__X80 == __1__X81)
                                      ? 1
                                      : ((__1__X80 && __1__X81)
                                             ? (((int)same_class__8classdefFP8classdefi(
                                                   __1__X80, __1__X81, 0)))
                                             : 0))))))) {
                            if ((__1f == 44) || (__1f == 45)) {
                                {

                                    struct ea __0__V48;

                                    struct ea __0__V49;

                                    error__FPCcRC2eaN32(
                                        (const char *)"%t is not aBC of%t",
                                        (const struct ea *)(((&__0__V48)->__O1__2ea.p =
                                                                 ((const void *)__2qcl)),
                                                            (&__0__V48)),
                                        (const struct ea *)(((&__0__V49)->__O1__2ea.p =
                                                                 ((const void *)__1cl)),
                                                            (&__0__V49)),
                                        (const struct ea *)ea0, (const struct ea *)ea0);
                                    me = 0;
                                    return (struct expr *)undef__FP4nameP5tableUc(
                                        __1n, __1cl->memtbl__8classdef, (unsigned char)7);
                                }
                            }
                            goto sss;
                        }
                    }
                }

                if (__1f == 112)
                    mptr = 1;
                __1ee = find_name__8classdefFPCcP8classdefiT3(
                    __1cl, __1s,
                    ((__1__X82 = __2bcl),
                     ((__1__X83 = __1cl),
                      (((__1__X82 == __1__X83)
                            ? 1
                            : ((__1__X82 && __1__X83) ? (((int)same_class__8classdefFP8classdefi(
                                                            __1__X82, __1__X83, 0)))
                                                      : 0)))))
                        ? (((struct classdef *)0))
                        : __2bcl,
                    0, 0);

                if (((__1ee && (__1ee->base__4node == 85)) &&
                     ((((struct name *)(((struct name *)__1ee))))->n_stclass__4name != 31)) &&
                    is_ref__4typeFv(__1ee->__O1__4expr.tp)) {

                    struct ea __0__V50;

                    struct ea __0__V51;

                    error__FPCcRC2eaN32(
                        (const char *)"P toRM: %s::%s",
                        (const struct ea *)((__2__X84 = (const void *)__1cl->string__8classdef),
                                            (((&__0__V50)->__O1__2ea.p = __2__X84), (&__0__V50))),
                        (const struct ea *)__ct__2eaFPCv(
                            &__0__V51, (const void *)(((struct name *)(((struct name *)__1ee))))
                                           ->__O2__4expr.string),
                        (const struct ea *)ea0, (const struct ea *)ea0);
                }
                mptr = 0;

                if (__1ee == 0) {
                sss: {
                    Pname __3nn;

                    __3nn = look__5tableFPCcUc(__2qcl->memtbl__8classdef, __1s, (unsigned char)0);

                    if ((((__1f == 0) && ((((__3nn && __3nn->__O1__4expr.tp) &&
                                            (__3nn->__O1__4expr.tp->base__4node != 121)) &&
                                           (__3nn->__O1__4expr.tp->base__4node != 108)) &&
                                          (__3nn->__O1__4expr.tp->base__4node != 76))) &&
                         (__3nn->n_stclass__4name != 31)) &&
                        (((__1q && __1q->__O1__4expr.tp) &&
                          (__1q->__O1__4expr.tp->base__4node != 108)) &&
                         (__1q->__O1__4expr.tp->base__4node != 76))) {
                        {
                            struct ea __0__V52;

                            error__FPCcRC2eaN32((const char *)"O missing for%n",
                                                (const struct ea *)(((&__0__V52)->__O1__2ea.p =
                                                                         ((const void *)__1q)),
                                                                    (&__0__V52)),
                                                (const struct ea *)ea0, (const struct ea *)ea0,
                                                (const struct ea *)ea0);
                            if (__1n)
                                ((__1n
                                      ? (((void)(__1n
                                                     ? (((void)((((((struct expr *)__1n))
                                                                      ? (((void)((((struct expr *)
                                                                                       __1n))
                                                                                     ? (((void)(((
                                                                                           void)0))))
                                                                                     : (((void)0)))))
                                                                      : (((void)0)))),
                                                                (((void)__dl__4nameSFPvUl(
                                                                    (void *)__1n,
                                                                    (size_t)(sizeof(
                                                                        struct name))))))))
                                                     : (((void)0)))))
                                      : (((void)0))));

                            me = 0;
                            return (struct expr *)__1q;
                        }
                    }

                    if ((__1f != 44) && (__1f != 45)) {
                        Pclass __4qcl;

                        __4qcl = (((struct classdef *)((
                            (struct classdef *)(((struct basetype *)((
                                                    (struct basetype *)__1q->__O1__4expr.tp))))
                                ->b_name__8basetype->__O1__4expr.tp))));
                        mptr = 1;
                        if (__1cl && (__1cl->csu__8classdef == 167)) {
                            mec = (cc - 1)->cot__11dcl_context;
                            __1ee =
                                find_name__8classdefFPCcP8classdefiT3(__4qcl, __1s, __4qcl, 0, 0);
                        } else
                            __1ee =
                                find_name__8classdefFPCcP8classdefiT3(__4qcl, __1s, __4qcl, 0, 0);
                        mptr = 0;
                        if (__1ee && (__1ee->base__4node == 85)) {
                            if (__1n && (__1n->permanent__4node == 0))
                                del__4nameFv(__1n);
                            me = 0;
                            return __1ee;
                        }

                        if ((__1ee == 0) && (__4qcl->class_base__8classdef == 2)) {
                            {
                                struct ea __0__V53;

                                struct ea __0__V54;

                                struct ea __0__V55;

                                struct ea __0__V56;

                                error__FPCcRC2eaN32(
                                    (const char *)"YCM %t::%n requires %t<instance>::%n",
                                    (const struct ea *)(((&__0__V53)->__O1__2ea.p =
                                                             ((const void *)__4qcl)),
                                                        (&__0__V53)),
                                    (const struct ea *)(((&__0__V54)->__O1__2ea.p =
                                                             ((const void *)__1n)),
                                                        (&__0__V54)),
                                    (const struct ea *)(((&__0__V55)->__O1__2ea.p =
                                                             ((const void *)__4qcl)),
                                                        (&__0__V55)),
                                    (const struct ea *)(((&__0__V56)->__O1__2ea.p =
                                                             ((const void *)__1n)),
                                                        (&__0__V56)));
                                goto finishing_up;
                            }
                        }
                    }
                    {
                        struct ea __0__V57;

                        struct ea __0__V58;

                        struct ea __0__V59;

                        error__FPCcRC2eaN32(
                            (const char *)"QdN%n::%n not found in %t",
                            (const struct ea *)(((&__0__V57)->__O1__2ea.p = ((const void *)__1q)),
                                                (&__0__V57)),
                            (const struct ea *)(((&__0__V58)->__O1__2ea.p = ((const void *)__1n)),
                                                (&__0__V58)),
                            (const struct ea *)(((&__0__V59)->__O1__2ea.p = ((const void *)__1cl)),
                                                (&__0__V59)),
                            (const struct ea *)ea0);
                    finishing_up:
                        me = 0;
                        return (struct expr *)undef__FP4nameP5tableUc(
                            __1n, __2bcl ? __2bcl->memtbl__8classdef : __1cl->memtbl__8classdef,
                            (unsigned char)7);
                    }
                }
                }

                if ((__1ee->base__4node == 44) && (__1ee->__O2__4expr.e1 == 0)) {
                    switch (__1f) {
                    case 0:
                    case 109: {
                        Pexpr __5mm;
                        __5mm = __1ee->__O4__4expr.mem;
                        while ((__5mm->base__4node == 44) || (__5mm->base__4node == 177))
                            __5mm = __5mm->__O4__4expr.mem;
                        if (__5mm->base__4node == 85)
                            switch (__5mm->__O1__4expr.tp->base__4node) {
                            case 108:
                            case 76:
                                goto addrof;
                            default:
                                if ((((struct name *)(((struct name *)__5mm))))->n_stclass__4name ==
                                    31)
                                    goto addrof;
                            }
                    }
                        {
                            struct ea __0__V60;

                            error__FPCcRC2eaN32((const char *)"O orOP missing forM%n",
                                                (const struct ea *)(((&__0__V60)->__O1__2ea.p =
                                                                         ((const void *)__1n)),
                                                                    (&__0__V60)),
                                                (const struct ea *)ea0, (const struct ea *)ea0,
                                                (const struct ea *)ea0);

                        case 112:
                        addrof: {
                            Pexpr __5x;

                            __5x = __1ee;
                            __1ee = __1ee->__O4__4expr.mem;
                            ((__5x ? (((void)(__5x ? (((void)(((void)__dl__4exprSFPvUl(
                                                         (void *)__5x,
                                                         (size_t)(sizeof(struct expr)))))))
                                                   : (((void)0)))))
                                   : (((void)0))));
                        }
                        case 44:
                        case 45:
                            break;
                        default: {
                            struct ea __0__V61;

                            struct ea __0__V62;

                            error__FPCcRC2eaN32((const char *)"QdN%n::%n used in nonC context",
                                                (const struct ea *)(((&__0__V61)->__O1__2ea.p =
                                                                         ((const void *)__1q)),
                                                                    (&__0__V61)),
                                                (const struct ea *)(((&__0__V62)->__O1__2ea.p =
                                                                         ((const void *)__1n)),
                                                                    (&__0__V62)),
                                                (const struct ea *)ea0, (const struct ea *)ea0);
                        }
                        }
                    }
                }

                ((__1n ? (((void)(__1n ? (((void)((((((struct expr *)__1n))
                                                        ? (((void)((((struct expr *)__1n))
                                                                       ? (((void)(((void)0))))
                                                                       : (((void)0)))))
                                                        : (((void)0)))),
                                                  (((void)__dl__4nameSFPvUl(
                                                      (void *)__1n,
                                                      (size_t)(sizeof(struct name))))))))
                                       : (((void)0)))))
                       : (((void)0))));
                me = 0;
                return __1ee;
            }
        }

        if ((__1f != 45) && (__1f != 44)) {
            Pname __2save_this;
            Pname __2fn;
            Pfct __2ft;
            Pclass __2dc;
            Pname __2global_nn;
            int __2new_context;

            struct classdef *__1__X85;

            struct classdef *__1__X86;

            __2save_this = cc->c_this__11dcl_context;
            __2fn = me;
            __2ft = mef;
            __2dc = (__2ft ? __2ft->def_context__3fct : (((struct classdef *)0)));
            __2global_nn = 0;
            __2new_context = 0;
            if (__1cl &&
                (!((__1__X85 = __1cl),
                   ((__1__X86 = mec),
                    (((__1__X85 == __1__X86)
                          ? 1
                          : ((__1__X85 && __1__X86)
                                 ? (((int)same_class__8classdefFP8classdefi(__1__X85, __1__X86, 0)))
                                 : 0))))))) {
                Pclass __3cx;

                __3cx = __1cl;
                for (; __3cx && (__3cx->c_context__8classdef == 0); __3cx = __3cx->in_class__4type)
                    ;
                if (__3cx) {
                    __2fn = __3cx->in_fct__4type;

                    __2ft = (((struct fct *)(((struct fct *)__2fn->__O1__4expr.tp))));

                } else {
                    __2fn = 0;

                    __2ft = 0;
                }
                __1tbl = __1cl->memtbl__8classdef;
                cc->c_this__11dcl_context = 0;
            }
            while (mec && (mec->csu__8classdef == 167))
                mec = mec->in_class__4type;
            for (;;) {
                Pclass __3cx;
                Pname __3oth;
                Pexpr __3ee;

                __3oth = cc->c_this__11dcl_context;

                if (__1cl) {
                    struct classdef *__1__X87;

                    struct classdef *__1__X88;

                    if (__1tbl == __1cl->memtbl__8classdef) {
                        cc->c_this__11dcl_context = 0;
                    } else if ((__2ft == 0) ||
                               (!((__1__X87 = __1cl),
                                  ((__1__X88 = __2ft->memof__3fct),
                                   (((__1__X87 == __1__X88)
                                         ? 1
                                         : ((__1__X87 && __1__X88)
                                                ? (((int)same_class__8classdefFP8classdefi(
                                                      __1__X87, __1__X88, 0)))
                                                : 0))))))) {
                        {
                            struct ea __0__V63;

                            struct ea __0__V64;

                            struct ea __0__V65;

                            struct ea __0__V66;

                            error__FiP3locPCcRC2eaN34(
                                (int)'i', &__1n->where__4name,
                                (const char *)"find_name%n: confused context cl%t fn%n tbl %s",
                                (const struct ea *)(((&__0__V63)->__O1__2ea.p =
                                                         ((const void *)__1n)),
                                                    (&__0__V63)),
                                (const struct ea *)(((&__0__V64)->__O1__2ea.p =
                                                         ((const void *)__1cl)),
                                                    (&__0__V64)),
                                (const struct ea *)(((&__0__V65)->__O1__2ea.p =
                                                         ((const void *)__2fn)),
                                                    (&__0__V65)),
                                (const struct ea *)__ct__2eaFPCv(
                                    &__0__V66, (const void *)whatami__5tableFv(__1tbl)));
                        }
                    } else {
                        Pname __5nn;

                        __5nn = look__5tableFPCcUc(__1tbl, __1s, (unsigned char)0);
                        if (__5nn && (__5nn->base__4node == 123))
                            __5nn = 0;
                        if (__5nn) {
                            if (__5nn->__O4__4expr.n_table != gtbl) {
                                if (__1m == 0) {
                                    struct ea __0__V67;

                                    error__FiP3locPCcRC2eaN34(
                                        (int)'i', &__1n->where__4name,
                                        (const char *)"find_name%n: local scope but missing m",
                                        (const struct ea *)(((&__0__V67)->__O1__2ea.p =
                                                                 ((const void *)__1n)),
                                                            (&__0__V67)),
                                        (const struct ea *)ea0, (const struct ea *)ea0,
                                        (const struct ea *)ea0);
                                }
                                ((__5nn->n_used__4name++), (((void)0)));
                                if (__1n && (__1n->permanent__4node == 0))
                                    del__4nameFv(__1n);
                                me = 0;
                                cc->c_this__11dcl_context = __2save_this;
                                return (struct expr *)__5nn;
                            }

                            __2global_nn = __5nn;
                        }
                    }
                    if (__2dc) {
                        cc->c_this__11dcl_context = 0;
                        __3cx = __2dc;
                        __3ee = find_name__8classdefFPCcP8classdefiT3(__2dc, __1s,
                                                                      (struct classdef *)0, 0, 0);
                        while (__3ee == 0) {
                            struct classdef *__1__X89;

                            struct classdef *__1__X90;

                            if (__3cx->c_context__8classdef)
                                break;
                            __3cx = __3cx->in_class__4type;
                            if (__3cx == 0)
                                break;
                            if (((__1__X89 = __3cx),
                                 ((__1__X90 = __1cl),
                                  (((__1__X89 == __1__X90)
                                        ? 1
                                        : ((__1__X89 && __1__X90)
                                               ? (((int)same_class__8classdefFP8classdefi(
                                                     __1__X89, __1__X90, 0)))
                                               : 0))))))
                                break;
                            __3ee = find_name__8classdefFPCcP8classdefiT3(
                                __3cx, __1s, (struct classdef *)0, 0, 0);
                        }
                        cc->c_this__11dcl_context = __3oth;
                        __2dc = 0;
                        if (__3ee)
                            goto eee;
                    }
                    __3cx = __1cl;
                    __3ee = find_name__8classdefFPCcP8classdefiT3(__1cl, __1s, (struct classdef *)0,
                                                                  0, 0);
                    while (__3ee == 0) {
                        if (__3cx->c_context__8classdef)
                            break;
                        __3cx = __3cx->in_class__4type;
                        if (__3cx == 0)
                            break;

                        cc->c_this__11dcl_context = 0;
                        __3ee = find_name__8classdefFPCcP8classdefiT3(__3cx, __1s,
                                                                      (struct classdef *)0, 0, 0);
                    }
                    cc->c_this__11dcl_context = __3oth;
                    if (__3ee) {
                    eee:
                        if (__2new_context) {
                            Pname __6nx;
                            Pname __6nn;

                            __6nx = (((struct name *)(((struct name *)__3ee))));
                            __6nn = __2global_nn;
                            if ((__6nn || ((__6nn = look__5tableFPCcUc(gtbl, __1s,
                                                                       (unsigned char)0)) != 0)) &&
                                __6nn->n_oper__4name) {
                                while (__6nx->base__4node == 44)
                                    __6nx = ((
                                        (struct name *)(((struct name *)__6nx->__O4__4expr.mem))));
                                {
                                    struct ea __0__V68;

                                    struct ea __0__V69;

                                    struct ea __0__V70;

                                    struct ea __0__V71;

                                    error__FiPCcRC2eaN33(
                                        (int)'w',
                                        (const char
                                             *)"%n andG%n are both visible within%t -- usingG%n",
                                        (const struct ea *)(((&__0__V68)->__O1__2ea.p =
                                                                 ((const void *)__6nx)),
                                                            (&__0__V68)),
                                        (const struct ea *)(((&__0__V69)->__O1__2ea.p =
                                                                 ((const void *)__6nn)),
                                                            (&__0__V69)),
                                        (const struct ea *)__ct__2eaFPCv(&__0__V70,
                                                                         (const void *)mec),
                                        (const struct ea *)(((&__0__V71)->__O1__2ea.p =
                                                                 ((const void *)__6nn)),
                                                            (&__0__V71)));

                                    ((__6nn->n_used__4name++), (((void)0)));
                                    if (__1n && (__1n->permanent__4node == 0))
                                        del__4nameFv(__1n);
                                    me = 0;
                                    cc->c_this__11dcl_context = __2save_this;
                                    return (struct expr *)__6nn;
                                }
                            }
                        }
                        if ((__3ee->base__4node == 44) && (__3ee->__O2__4expr.e1 == 0)) {
                            Pexpr __6mm;

                            __6mm = __3ee->__O4__4expr.mem;
                            while ((__6mm->base__4node == 44) || (__6mm->base__4node == 177))
                                __6mm = __6mm->__O4__4expr.mem;
                            if (__6mm->base__4node == 85)
                                switch (__6mm->__O1__4expr.tp->base__4node) {
                                default:
                                    if ((((struct name *)(((struct name *)__6mm))))
                                            ->n_stclass__4name != 31) {

                                        struct ea __0__V72;

                                        error__FPCcRC2eaN32(
                                            (const char *)"O orOP missing for%n",
                                            (const struct ea *)(((&__0__V72)->__O1__2ea.p =
                                                                     ((const void *)__6mm)),
                                                                (&__0__V72)),
                                            (const struct ea *)ea0, (const struct ea *)ea0,
                                            (const struct ea *)ea0);
                                    }
                                case 108:
                                case 76:
                                    if (__1n && (__1n->permanent__4node == 0))
                                        del__4nameFv(__1n);
                                    me = 0;
                                    cc->c_this__11dcl_context = __2save_this;
                                    return __6mm;
                                }
                        }
                        if (__1n && (__1n->permanent__4node == 0))
                            del__4nameFv(__1n);
                        me = 0;
                        cc->c_this__11dcl_context = __2save_this;
                        return __3ee;
                    }

                    __1tbl = (__3cx ? __3cx->c_context__8classdef : gtbl);

                    if (__1tbl == 0) {
                        struct ea __0__V73;

                        struct ea __0__V74;

                        error__FiPCcRC2eaN33(
                            (int)'i', (const char *)"missing context table for cl%t/cx%t",
                            (const struct ea *)(((&__0__V73)->__O1__2ea.p = ((const void *)__1cl)),
                                                (&__0__V73)),
                            (const struct ea *)(((&__0__V74)->__O1__2ea.p = ((const void *)__3cx)),
                                                (&__0__V74)),
                            (const struct ea *)ea0, (const struct ea *)ea0);
                    }
                    if (((__1tbl == gtbl) && __2global_nn) && (!__2dc)) {
                        ((__2global_nn->n_used__4name++), (((void)0)));

                        if (__1n && (__1n->permanent__4node == 0))
                            del__4nameFv(__1n);
                        me = 0;
                        cc->c_this__11dcl_context = __2save_this;
                        return (struct expr *)__2global_nn;
                    }
                    __2new_context = 1;
                }

                {
                    Pname __3nn;

                    __3nn = look__5tableFPCcUc(__1tbl, __1s, (unsigned char)0);
                    if (__3nn && (__3nn->base__4node == 123))
                        __3nn = 0;
                    if (__3nn) {
                        if (__3nn->__O4__4expr.n_table != gtbl) {
                            if (__1m == 0) {
                                struct ea __0__V75;

                                error__FiP3locPCcRC2eaN34(
                                    (int)'i', &__1n->where__4name,
                                    (const char *)"find_name%n: local scope but missing m",
                                    (const struct ea *)(((&__0__V75)->__O1__2ea.p =
                                                             ((const void *)__1n)),
                                                        (&__0__V75)),
                                    (const struct ea *)ea0, (const struct ea *)ea0,
                                    (const struct ea *)ea0);
                            }
                            if (__2new_context) {
                                check_local_nested_ref__FP4nameUc3loc(__3nn, (unsigned char)__1f,
                                                                      __1n->where__4name);
                            }
                        } else if (__2ft && (__2ft->memof__3fct || __2dc)) {
                            __2global_nn = __3nn;
                            goto nxt;
                        }
                        ((__3nn->n_used__4name++), (((void)0)));
                        if (__1n && (__1n->permanent__4node == 0))
                            del__4nameFv(__1n);
                        me = 0;
                        cc->c_this__11dcl_context = __2save_this;
                        return (struct expr *)__3nn;
                    }
                nxt:
                    if (__2dc) {
                        cc->c_this__11dcl_context = 0;
                        __3cx = __2dc;
                        __3ee = find_name__8classdefFPCcP8classdefiT3(__2dc, __1s,
                                                                      (struct classdef *)0, 0, 0);
                        while (__3ee == 0) {
                            if (__3cx->c_context__8classdef)
                                break;
                            __3cx = __3cx->in_class__4type;
                            if (__3cx == 0)
                                break;
                            __3ee = find_name__8classdefFPCcP8classdefiT3(
                                __3cx, __1s, (struct classdef *)0, 0, 0);
                        }
                        cc->c_this__11dcl_context = __3oth;
                        if (__3ee)
                            goto eee;
                    }
                    __2new_context = 1;
                    __1cl = (__2ft ? __2ft->memof__3fct : (((struct classdef *)0)));
                    if (__1cl == 0) {
                        if (__2global_nn) {
                            ((__2global_nn->n_used__4name++), (((void)0)));
                            if (__1n && (__1n->permanent__4node == 0))
                                del__4nameFv(__1n);
                            me = 0;
                            cc->c_this__11dcl_context = __2save_this;
                            return (struct expr *)__2global_nn;
                        }
                        break;
                    }

                    __1tbl = __1cl->memtbl__8classdef;
                    __2fn = (__3cx ? __3cx->in_fct__4type : (((struct name *)0)));
                    if (__2fn) {
                        __2ft = (((struct fct *)(((struct fct *)__2fn->__O1__4expr.tp))));

                        cc->c_this__11dcl_context = __2ft->f_this__3fct;

                    } else {
                        __2ft = 0;

                        cc->c_this__11dcl_context = 0;
                    }
                    __2dc = (__2ft ? __2ft->def_context__3fct : (((struct classdef *)0)));
                }
            }
            me = 0;
            cc->c_this__11dcl_context = __2save_this;
            return (struct expr *)undef__FP4nameP5tableUc(__1n, gtbl, (unsigned char)__1f);
        }

        if (__1ee = find_name__8classdefFPCcP8classdefiT3(__1cl, __1s, __1cl, 0, 0)) {
            if (__1n && (__1n->permanent__4node == 0))
                del__4nameFv(__1n);
            me = 0;
            return __1ee;
        }

        if (!strcmp(__1s, __1cl->string__8classdef)) {
            me = 0;
            return (struct expr *)undef__FP4nameP5tableUc(__1n, gtbl, (unsigned char)84);
        }

        me = 0;
        return (struct expr *)undef__FP4nameP5tableUc(__1n, gtbl, (unsigned char)__1f);
    }
}

int check_dup__8classdefFP8classdefUc(struct classdef *__0this, Pclass __1cl, TOK __1bb);

int check_dup__8classdefFP8classdefUc(register struct classdef *__0this, Pclass __1cl, TOK __1bb) {
    {
        {
            Pbcl __1b;

            __1b = __0this->baselist__8classdef;

            for (; __1b; __1b = __1b->next__6basecl) {
                struct classdef *__1__X100;

                struct classdef *__1__X101;

                if (((__1__X100 = __1cl),
                     ((__1__X101 = __1b->bclass__6basecl),
                      (((__1__X100 == __1__X101)
                            ? 1
                            : ((__1__X100 && __1__X101) ? (((int)same_class__8classdefFP8classdefi(
                                                              __1__X100, __1__X101, 0)))
                                                        : 0)))))) {
                    if (__1bb != 77) {
                        if (__1b->base__4node == 77) {
                            struct ea __0__V91;

                            struct ea __0__V92;

                            struct ea __0__V93;

                            error__FiPCcRC2eaN33(
                                (int)'w', (const char *)"%t inaccessible because of virtual%t in%t",
                                (const struct ea *)(((&__0__V91)->__O1__2ea.p =
                                                         ((const void *)__1cl)),
                                                    (&__0__V91)),
                                (const struct ea *)(((&__0__V92)->__O1__2ea.p =
                                                         ((const void *)__1cl)),
                                                    (&__0__V92)),
                                (const struct ea *)(((&__0__V93)->__O1__2ea.p =
                                                         ((const void *)__0this)),
                                                    (&__0__V93)),
                                (const struct ea *)ea0);
                        } else {
                            struct ea __0__V94;

                            struct ea __0__V95;

                            struct ea __0__V96;

                            error__FiPCcRC2eaN33((int)'w',
                                                 (const char *)"%t inaccessible because of%t in%t",
                                                 (const struct ea *)(((&__0__V94)->__O1__2ea.p =
                                                                          ((const void *)__1cl)),
                                                                     (&__0__V94)),
                                                 (const struct ea *)(((&__0__V95)->__O1__2ea.p =
                                                                          ((const void *)__1cl)),
                                                                     (&__0__V95)),
                                                 (const struct ea *)(((&__0__V96)->__O1__2ea.p =
                                                                          ((const void *)__0this)),
                                                                     (&__0__V96)),
                                                 (const struct ea *)ea0);
                        }
                        return 1;
                    } else if (__1b->base__4node != 77) {
                        {
                            struct ea __0__V97;

                            struct ea __0__V98;

                            struct ea __0__V99;

                            error__FiPCcRC2eaN33(
                                (int)'w', (const char *)"virtual %t inaccessible because of%t in%t",
                                (const struct ea *)(((&__0__V97)->__O1__2ea.p =
                                                         ((const void *)__1cl)),
                                                    (&__0__V97)),
                                (const struct ea *)(((&__0__V98)->__O1__2ea.p =
                                                         ((const void *)__1cl)),
                                                    (&__0__V98)),
                                (const struct ea *)(((&__0__V99)->__O1__2ea.p =
                                                         ((const void *)__0this)),
                                                    (&__0__V99)),
                                (const struct ea *)ea0);
                            return 1;
                        }
                    }
                }
                if (check_dup__8classdefFP8classdefUc(__1b->bclass__6basecl, __1cl, __1bb))
                    return 1;
            }
            return 0;
        }
    }
}

TOK Nvis = 0;
TOK Nvirt = 0;
TOK ppbase = 0;

bit has_friend__8classdefFP3fct(struct classdef *__0this, Pfct);

Pclass is_base__8classdefFPCcPUci(register struct classdef *__0this, const char *__1s, TOK *__1pptr,
                                  int __1level) {
    TOK __1pp;
    TOK __1ppaccum;

    __1pp = ppbase;

    {
        {
            Pbcl __1b;

            __1b = __0this->baselist__8classdef;

            for (; __1b; __1b = __1b->next__6basecl) {
                if (__1b->promoted__6basecl)
                    continue;
                {
                    const char *__2str;

                    register struct templ_classdef *__0__X102;

                    __2str = 0;
                    if (__1b->bclass__6basecl->class_base__8classdef == 4)
                        __2str =
                            ((__0__X102 = (((struct templ_classdef *)((
                                  (struct templ_classdef *)__1b->bclass__6basecl))))),
                             (__0__X102->inst__14templ_classdef->def__10templ_inst->namep__5templ))
                                ->__O2__4expr.string;

                    if ((strcmp(__1s, __1b->bclass__6basecl->string__8classdef) == 0) ||
                        (__2str && (strcmp(__1s, __2str) == 0))) {

                        struct classdef *__1__X103;

                        struct classdef *__1__X104;

                        __1ppaccum = 25;
                        if (((__1b->ppp__6basecl != 25) &&
                             (!((__1__X103 = cc->cot__11dcl_context),
                                ((__1__X104 = __0this),
                                 (((__1__X103 == __1__X104)
                                       ? 1
                                       : ((__1__X103 && __1__X104)
                                              ? (((int)same_class__8classdefFP8classdefi(
                                                    __1__X103, __1__X104, 0)))
                                              : 0))))))) &&
                            ((cc->nof__11dcl_context == 0) ||
                             (has_friend__8classdefFP3fct(
                                  __0this, ((struct fct *)(((struct fct *)cc->nof__11dcl_context
                                                                ->__O1__4expr.tp)))) == 0)))
                            __1ppaccum = __1b->ppp__6basecl;

                        Nvirt = __1b->base__4node;

                        if (__1pptr)
                            ((*__1pptr)) = __1ppaccum;
                        if (__1level == 0)
                            ppbase = __1ppaccum;
                        return __1b->bclass__6basecl;
                    } else {
                        TOK __3prot;
                        Pclass __3bc;

                        __3bc = is_base__8classdefFPCcPUci(__1b->bclass__6basecl, __1s, &__3prot,
                                                           __1level + 1);
                        if (__3bc) {
                            struct classdef *__1__X105;

                            struct classdef *__1__X106;

                            __1ppaccum = __3prot;
                            if (((__1b->ppp__6basecl != 25) &&
                                 (!((__1__X105 = cc->cot__11dcl_context),
                                    ((__1__X106 = __0this),
                                     (((__1__X105 == __1__X106)
                                           ? 1
                                           : ((__1__X105 && __1__X106)
                                                  ? (((int)same_class__8classdefFP8classdefi(
                                                        __1__X105, __1__X106, 0)))
                                                  : 0))))))) &&
                                ((cc->nof__11dcl_context == 0) ||
                                 (has_friend__8classdefFP3fct(
                                      __0this, ((struct fct *)(((struct fct *)cc->nof__11dcl_context
                                                                    ->__O1__4expr.tp)))) == 0)))
                                __1ppaccum = ((__1b->ppp__6basecl > __1ppaccum) ? __1b->ppp__6basecl
                                                                                : __1ppaccum);

                            if (__1ppaccum == 25) {
                                if (__1pptr)
                                    ((*__1pptr)) = __1ppaccum;
                                if (__1level == 0)
                                    ppbase = __1ppaccum;
                                return __3bc;
                            }
                        }
                    }
                }
            }
            ppbase = __1pp;
            return (struct classdef *)0;
        }
    }
}

bit has_friend__8classdefFP8classdef(struct classdef *__0this, Pclass);

bit has_base__8classdefFP8classdefiT2(struct classdef *__0this, Pclass __1cl, int __1level,
                                      int __1ccflag);

bit has_base__8classdefFP8classdefiT2(register struct classdef *__0this, Pclass __1cl, int __1level,
                                      int __1ccflag) {
    if (__0this == 0)
        return (unsigned char)0;

    {
        static int __1found = 0;
        if (__1level == 0)
            __1found = 0;

        {
            {
                Pbcl __1b;

                __1b = __0this->baselist__8classdef;

                for (; __1b; __1b = __1b->next__6basecl) {
                    struct classdef *__1__X107;

                    struct classdef *__1__X108;

                    if (((__1__X107 = __1b->bclass__6basecl),
                         ((__1__X108 = __1cl),
                          (((__1__X107 == __1__X108)
                                ? 1
                                : ((__1__X107 && __1__X108)
                                       ? (((int)same_class__8classdefFP8classdefi(__1__X107,
                                                                                  __1__X108, 1)))
                                       : 0)))))) {
                        struct classdef *__1__X109;

                        struct classdef *__1__X110;

                        if ((((__1b->ppp__6basecl != 25) &&
                              (__1ccflag ||
                               (!((__1__X109 = cc->cot__11dcl_context),
                                  ((__1__X110 = __0this),
                                   (((__1__X109 == __1__X110)
                                         ? 1
                                         : ((__1__X109 && __1__X110)
                                                ? (((int)same_class__8classdefFP8classdefi(
                                                      __1__X109, __1__X110, 0)))
                                                : 0)))))))) &&
                             ((cc->nof__11dcl_context == 0) ||
                              (has_friend__8classdefFP3fct(
                                   __0this, ((struct fct *)(((struct fct *)cc->nof__11dcl_context
                                                                 ->__O1__4expr.tp)))) == 0))) &&
                            ((cc->cot__11dcl_context == 0) ||
                             (has_friend__8classdefFP8classdef(__0this, cc->cot__11dcl_context) ==
                              0)))
                            Nvis = __1b->ppp__6basecl;
                        Nvirt = __1b->base__4node;

                        if (((__1level == 0) && (__1b->base__4node == 77)) && (__1found == 1)) {
                            if (__1b->ppp__6basecl != Nvis)
                                Nvis =
                                    ((__1b->ppp__6basecl == 25) ? 0 : (((int)__1b->ppp__6basecl)));
                        }
                        return (unsigned char)1;
                    }
                    if (has_base__8classdefFP8classdefiT2(__1b->bclass__6basecl, __1cl,
                                                          __1level + 1, __1ccflag)) {
                        if ((__1level == 0) && (Nvirt == 77)) {

                            __1found = 1;

                            continue;
                        }
                        return (unsigned char)1;
                    }
                }
                return (unsigned char)0;
            }
        }
    }
}

int Noffset = 0;
Pexpr Nptr = 0;
const char *Nalloc_base = 0;
struct clist *vcllist = 0;

int onlist__5clistFP8classdef(register struct clist *__0this, Pclass __1c) {
    {
        {
            struct clist *__1p;

            struct classdef *__1__X111;

            struct classdef *__1__X112;

            __1p = __0this;

            for (; __1p; __1p = __1p->next__5clist)
                if (((__1__X111 = __1p->cl__5clist),
                     ((__1__X112 = __1c),
                      (((__1__X111 == __1__X112)
                            ? 1
                            : ((__1__X111 && __1__X112) ? (((int)same_class__8classdefFP8classdefi(
                                                              __1__X111, __1__X112, 0)))
                                                        : 0))))))
                    return 1;
            return 0;
        }
    }
}

void clear__5clistFv(register struct clist *__0this) {
    if (__0this == 0)
        return;
    {
        struct clist *__1p;

        __1p = __0this->next__5clist;
        while (__1p) {
            struct clist *__2q;

            __2q = __1p->next__5clist;
            __dl__FPv((void *)__1p);
            __1p = __2q;
        }

        ;
        __dl__FPv((void *)__0this);
    }
}

Pbcl Nvbc_alloc = 0;

const char *has_allocated_base__8classdefFPCc(struct classdef *__0this, const char *);

int is_unique_base__FP8classdefPCciT3T1(Pclass __1cl, const char *__1s, int __1offset,
                                        int __1in_base, Pclass __1priSeen);

static int same_class__FP8classdefT1i(Pclass __1c1, Pclass __1c2, int __1dummy);

int is_unique_base__FP8classdefPCciT3T1(Pclass __1cl, const char *__1s, int __1offset,
                                        int __1in_base, Pclass __1priSeen) {
    int __1i;

    __1i = 0;

    {
        {
            Pbcl __1b;

            __1b = __1cl->baselist__8classdef;

            for (; __1b; __1b = __1b->next__6basecl) {
                int __2no;

                __2no = 0;
                if (__1b->base__4node != 77)
                    __2no = (__1offset + __1b->obj_offset__6basecl);
                else if (__1in_base)
                    continue;
                if (strcmp(__1s, __1b->bclass__6basecl->string__8classdef) == 0) {
                    struct classdef *__1__X113;

                    struct classdef *__1__X114;

                    Noffset = __2no;
                    __1i++;
                    if (((((__1b->ppp__6basecl != 25) || __1priSeen) &&
                          ((!((__1__X113 = cc->cot__11dcl_context),
                              ((__1__X114 = __1cl),
                               (((__1__X113 == __1__X114)
                                     ? 1
                                     : ((__1__X113 && __1__X114)
                                            ? (((int)same_class__8classdefFP8classdefi(
                                                  __1__X113, __1__X114, 0)))
                                            : 0)))))) ||
                           (!same_class__FP8classdefT1i(cc->cot__11dcl_context, __1priSeen, 0)))) &&
                         ((cc->nof__11dcl_context == 0) ||
                          (has_friend__8classdefFP3fct(
                               __1cl, ((struct fct *)(((struct fct *)cc->nof__11dcl_context
                                                           ->__O1__4expr.tp)))) == 0))) ||
                        (__1priSeen &&
                         (has_friend__8classdefFP3fct(
                              __1priSeen,
                              ((struct fct *)((
                                  (struct fct *)cc->nof__11dcl_context->__O1__4expr.tp)))) == 0)))
                        Nvis = __1b->ppp__6basecl;

                    if (__1b->base__4node == 77) {
                        register struct mdot *__0__X115;

                        Nptr = (struct expr
                                    *)((__0__X115 = 0),
                                       (((__0__X115 || (__0__X115 = (struct mdot *)__nw__4exprSFUl(
                                                            (size_t)(sizeof(struct mdot)))))
                                             ? ((__0__X115 = (struct mdot *)__ct__4exprFUcP4exprT2(
                                                     ((struct expr *)__0__X115), (unsigned char)177,
                                                     (struct expr *)0, (struct expr *)0)),
                                                ((__0__X115->__O3__4expr.string2 = __1s),
                                                 (__0__X115->__O4__4expr.mem = ((struct expr *)0))))
                                             : 0),
                                        __0__X115));

                        if (__1b->allocated__6basecl != 1) {
                            Nvbc_alloc = 0;
                            Nalloc_base = has_allocated_base__8classdefFPCc(__1cl, __1s);
                        }
                    }
                } else {
                    if (__1b->base__4node == 77) {
                        struct clist *__0__X116;

                        struct classdef *__2__X117;

                        struct clist *__2__X118;

                        if (vcllist && onlist__5clistFP8classdef(vcllist, __1b->bclass__6basecl))
                            continue;
                        vcllist = ((__0__X116 = 0),
                                   ((__2__X117 = __1b->bclass__6basecl),
                                    ((__2__X118 = vcllist),
                                     (((__0__X116 || (__0__X116 = (struct clist *)__nw__FUl(
                                                          (size_t)(sizeof(struct clist)))))
                                           ? ((__0__X116->cl__5clist = __2__X117),
                                              (__0__X116->next__5clist = __2__X118))
                                           : 0),
                                      __0__X116))));
                    }

                    {
                        Pclass __3clscope;

                        __3clscope = 0;
                        if (cc && cc->c_this__11dcl_context) {
                            Ptype __4t;

                            __4t = (((struct ptr *)((
                                        (struct ptr *)cc->c_this__11dcl_context->__O1__4expr.tp))))
                                       ->typ__5pvtyp;
                            __3clscope = (((struct classdef *)((
                                (struct classdef *)(((struct basetype *)((
                                                        (struct basetype *)__4t))))
                                    ->b_name__8basetype->__O1__4expr.tp))));
                        }

                        {
                            Pclass __3new_priSeen;

                            struct classdef *__1__X119;

                            struct classdef *__1__X120;

                            __3new_priSeen = __1priSeen;
                            if (((__1b->ppp__6basecl != 25) &&
                                 (!((__1__X119 = __1cl),
                                    ((__1__X120 = __3clscope),
                                     (((__1__X119 == __1__X120)
                                           ? 1
                                           : ((__1__X119 && __1__X120)
                                                  ? (((int)same_class__8classdefFP8classdefi(
                                                        __1__X119, __1__X120, 0)))
                                                  : 0))))))) &&
                                (__1priSeen == 0))
                                __3new_priSeen = __1cl;

                            {
                                int __3ii;

                                __3ii = is_unique_base__FP8classdefPCciT3T1(
                                    __1b->bclass__6basecl, __1s, __2no, 1, __3new_priSeen);

                                __1i += __3ii;
                                if ((__3ii == 1) && (__1b->base__4node == 77)) {
                                    register struct mdot *__0__X121;

                                    const char *__2__X122;

                                    Nptr = (struct expr
                                                *)((__0__X121 = 0),
                                                   ((__2__X122 =
                                                         __1b->bclass__6basecl->string__8classdef),
                                                    (((__0__X121 ||
                                                       (__0__X121 = (struct mdot *)__nw__4exprSFUl(
                                                            (size_t)(sizeof(struct mdot)))))
                                                          ? ((__0__X121 = (struct mdot *)
                                                                  __ct__4exprFUcP4exprT2(
                                                                      ((struct expr *)__0__X121),
                                                                      (unsigned char)177,
                                                                      (struct expr *)0,
                                                                      (struct expr *)0)),
                                                             ((__0__X121->__O3__4expr.string2 =
                                                                   __2__X122),
                                                              (__0__X121->__O4__4expr.mem =
                                                                   ((struct expr *)0))))
                                                          : 0),
                                                     __0__X121)));

                                    if (__1b->allocated__6basecl != 1) {
                                        Nvbc_alloc = 0;
                                        Nalloc_base = has_allocated_base__8classdefFPCc(
                                            __1cl, __1b->bclass__6basecl->string__8classdef);
                                    }
                                }
                            }
                        }
                    }
                }
            }

            return __1i;
        }
    }
}

int link_compat_hack = 0;
int has_allocated_base__8classdefFP8classdefUc(struct classdef *__0this, Pclass __1bcl,
                                               bit __1first);

int has_allocated_base__8classdefFP8classdefUc(register struct classdef *__0this, Pclass __1bcl,
                                               bit __1first) {
    {
        {
            Pbcl __1l;

            __1l = __0this->baselist__8classdef;

            for (; __1l; __1l = __1l->next__6basecl) {
                struct classdef *__1__X123;

                struct classdef *__1__X124;

                if ((__1l->base__4node == 77) &&
                    ((__1__X123 = __1l->bclass__6basecl),
                     ((__1__X124 = __1bcl),
                      (((__1__X123 == __1__X124)
                            ? 1
                            : ((__1__X123 && __1__X124) ? (((int)same_class__8classdefFP8classdefi(
                                                              __1__X123, __1__X124, 0)))
                                                        : 0)))))) {
                    if (__1l->obj_offset__6basecl && (__1first == 0))
                        return __1l->obj_offset__6basecl;

                    {
                        {
                            Pbcl __3ll;

                            __3ll = __0this->baselist__8classdef;

                            for (; __3ll != __1l; __3ll = __3ll->next__6basecl) {
                                if (__3ll->base__4node == 77)
                                    continue;
                                {
                                    int __4i;

                                    __4i = has_allocated_base__8classdefFP8classdefUc(
                                        __3ll->bclass__6basecl, __1bcl,
                                        (unsigned char)(__3ll == __0this->baselist__8classdef));

                                    if (__4i) {
                                        link_compat_hack = 1;

                                        return 0;
                                    }
                                }
                            }
                        }
                    }
                }

                if ((__1l->base__4node == 77) || (__1l != __0this->baselist__8classdef)) {
                    int __3i;

                    __3i = has_allocated_base__8classdefFP8classdefUc(__1l->bclass__6basecl, __1bcl,
                                                                      (unsigned char)0);
                    if (__3i)
                        return (__1l->obj_offset__6basecl + __3i);
                }
            }
            return 0;
        }
    }
}

extern bit Vvtab;
extern bit Vvbc_inher;
extern bit Vvbc_alloc;

const char *has_allocated_base__8classdefFPCc(register struct classdef *__0this,
                                              const char *__1str) {
    {
        {
            Pbcl __1l;

            __1l = __0this->baselist__8classdef;

            for (; __1l; __1l = __1l->next__6basecl) {
                if (__1l->base__4node == 77) {
                    if (__1l->allocated__6basecl == 1)
                        Nvbc_alloc = __1l;
                    else if (strcmp(__1str, __1l->bclass__6basecl->string__8classdef) == 0) {
                        Vvbc_inher = 1;
                        return (const char *)0;
                    }
                    continue;
                }

                {
                    Pclass __2bc;

                    __2bc = __1l->bclass__6basecl;
                    {
                        {
                            Pbcl __2ll;

                            __2ll = __2bc->baselist__8classdef;

                            for (; __2ll; __2ll = __2ll->next__6basecl) {
                                if (__2ll->base__4node != 77)
                                    continue;

                                if ((__2ll->allocated__6basecl == 1) &&
                                    (strcmp(__1str, __2ll->bclass__6basecl->string__8classdef) ==
                                     0)) {
                                    struct classdef *__1__X125;

                                    struct classdef *__1__X126;

                                    if (((__1__X125 = __2bc),
                                         ((__1__X126 =
                                               __0this->baselist__8classdef->bclass__6basecl),
                                          (((__1__X125 == __1__X126)
                                                ? 1
                                                : ((__1__X125 && __1__X126)
                                                       ? (((int)same_class__8classdefFP8classdefi(
                                                             __1__X125, __1__X126, 0)))
                                                       : 0)))))) {
                                        Vvtab = __2ll->bclass__6basecl->has_vvtab__8classdef;
                                        return (const char *)0;
                                    }
                                    return __2bc->string__8classdef;
                                }
                            }
                        }
                    }
                }
            }
            if (Nvbc_alloc == 0)
                Vvbc_alloc = 1;
            return (const char *)0;
        }
    }
}

Pname vfct__FP8classdefPc(Pclass __1cl, char *__1s);

Pname vfct__FP8classdefPc(Pclass __1cl, char *__1s) {
    Pname __1n;

    __1n = look__5tableFPCcUc(__1cl->memtbl__8classdef, (const char *)__1s, (unsigned char)0);
    if (__1n)
        return __1n;

    {
        {
            Pbcl __1b;

            __1b = __1cl->baselist__8classdef;

            for (; __1b; __1b = __1b->next__6basecl) {
                Pname __2nn;

                __2nn = vfct__FP8classdefPc(__1b->bclass__6basecl, __1s);
                if (__2nn) {
                    if (__1n && (__1n != __2nn)) {
                        Pclass __4ncl;
                        Pclass __4nncl;

                        __4ncl =
                            (((struct classdef *)(((struct classdef *)__1n->__O4__4expr.n_table
                                                       ->t_name__5table->__O1__4expr.tp))));
                        __4nncl =
                            (((struct classdef *)(((struct classdef *)__2nn->__O4__4expr.n_table
                                                       ->t_name__5table->__O1__4expr.tp))));

                        if (is_base__8classdefFPCcPUci(__4nncl, __4ncl->string__8classdef, (TOK *)0,
                                                       0))
                            __1n = __2nn;
                    } else
                        __1n = __2nn;
                }
            }

            return __1n;
        }
    }
}

Pexpr rptr__FP4typeP4expri(Ptype __1t, Pexpr __1p, int __1offset) {
    if (__1t == 0)
        error__FiPCc((int)'i', (const char *)"rptr(), t==0 (type passed for cast)");
    {
        Pexpr __1pp;

        register struct cast *__0__X130;

        __1pp = __1p;

        if (__1offset) {
            Pexpr __2i;

            register struct cast *__0__X127;

            struct type *__2__X128;

            struct ival *__0__X129;

            __2i = (struct expr *)((__0__X129 = 0),
                                   (((__0__X129 || (__0__X129 = (struct ival *)__nw__4exprSFUl(
                                                        (size_t)(sizeof(struct ival)))))
                                         ? ((__0__X129 = (struct ival *)__ct__4exprFUcP4exprT2(
                                                 ((struct expr *)__0__X129), (unsigned char)150,
                                                 (struct expr *)0, (struct expr *)0)),
                                            (__0__X129->__O2__4expr.i1 = ((long long)__1offset)))
                                         : 0),
                                    __0__X129));

            __1pp = (struct expr *)((__0__X127 = 0),
                                    ((__2__X128 = Pchar_type),
                                     (((__0__X127 || (__0__X127 = (struct cast *)__nw__4exprSFUl(
                                                          (unsigned long)(sizeof(struct cast)))))
                                           ? ((__0__X127 = (struct cast *)__ct__4exprFUcP4exprT2(
                                                   ((struct expr *)__0__X127), (unsigned char)191,
                                                   __1pp, (struct expr *)0)),
                                              (__0__X127->__O1__4expr.tp =
                                                   (__0__X127->__O4__4expr.tp2 = __2__X128)))
                                           : 0),
                                      __0__X127)));
            __1pp = __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)54, __1pp, __2i);
        }
        __1pp = (struct expr *)((__0__X130 = 0),
                                (((__0__X130 || (__0__X130 = (struct cast *)__nw__4exprSFUl(
                                                     (size_t)(sizeof(struct cast)))))
                                      ? ((__0__X130 = (struct cast *)__ct__4exprFUcP4exprT2(
                                              ((struct expr *)__0__X130), (unsigned char)191, __1pp,
                                              (struct expr *)0)),
                                         (__0__X130->__O1__4expr.tp =
                                              (__0__X130->__O4__4expr.tp2 = __1t)))
                                      : 0),
                                 __0__X130));
        return __1pp;
    }
}

int friend_check__FP8classdefT1P3fct(Pclass __1start, Pclass __1stop, Pfct __1f);

int friend_check__FP8classdefT1P3fct(Pclass __1start, Pclass __1stop, Pfct __1f) {
    if (has_friend__8classdefFP3fct(__1start, __1f))
        return 1;
    if (__1stop == __1start)
        return 0;
    {
        {
            Pbcl __1b;

            __1b = __1start->baselist__8classdef;

            for (; __1b; __1b = __1b->next__6basecl) {
                if (has_friend__8classdefFP3fct(__1b->bclass__6basecl, __1f))
                    return 1;
                if (friend_check__FP8classdefT1P3fct(__1b->bclass__6basecl, __1stop, __1f))
                    return 1;
            }
            return 0;
        }
    }
}

int has_friend__17function_templateFP4name(register struct function_template *__0this,
                                           Pname __1ifn) {
    Ptype __1t;

    __1t = __1ifn->__O1__4expr.tp;

    switch (__1t->base__4node) {
    case 108: {
        Pfct __3f;
        Pname __3ftn;

        __3f = (((struct fct *)(((struct fct *)__1t))));
        __3ftn = ((__3f->fct_base__3fct == 0)
                      ? __1ifn
                      : ((((struct templ_fct *)(((struct templ_fct *)__3f))))
                             ->inst__9templ_fct->def__10funct_inst->fn__17function_template));

        return (strcmp(__3ftn->__O2__4expr.string,
                       __0this->fn__17function_template->__O2__4expr.string) == 0);
    }
    }

    return 0;
}

Pclass classtype__4typeFv(struct type *__0this);

int has_friend__5templFP4name(register struct templ *__0this, Pname __1cn) {
    if (__1cn->__O1__4expr.tp->base__4node != 108) {
        Pclass __2cl;
        Pname __2ptn;

        __2cl = classtype__4typeFv(__1cn->__O1__4expr.tp);
        __2ptn = ((((struct templ_classdef *)(((struct templ_classdef *)__2cl))))
                      ->inst__14templ_classdef->def__10templ_inst->namep__5templ);

        return (strcmp(__2ptn->__O2__4expr.string, __0this->namep__5templ->__O2__4expr.string) ==
                0);
    }
    return 0;
}

struct data_template { /* sizeof data_template == 64 */

    Plist formals__14basic_template;
    Pcons templ_refs__14basic_template;

    Pname Cdcl__14basic_template;
    Pstmt Cstmt__14basic_template;

    int open_instantiations__14basic_template;
    int extrapolated__14basic_template;

    struct __mptr *__vptr__14basic_template;

    Pname dat_mem__13data_template;
    Pdata next__13data_template;
};

int has_friend__13data_templateFP4name(struct data_template *__0this, Pname __1__A131) { return 0; }

int has_friend__14basic_templateFP4name(struct basic_template *__0this, Pname);

bit has_friend__8classdefFP3fct(register struct classdef *__0this, Pfct __1f) {
    struct classdef *__1__X133;

    struct classdef *__1__X134;

    if (((__1__X133 = __1f->memof__3fct),
         ((__1__X134 = __0this),
          (((__1__X133 == __1__X134)
                ? 1
                : ((__1__X133 && __1__X134)
                       ? (((int)same_class__8classdefFP8classdefi(__1__X133, __1__X134, 0)))
                       : 0))))))
        return (unsigned char)1;
    {
        {
            Plist __1l;

            __1l = __0this->friend_list__8classdef;

            for (; __1l; __1l = __1l->l__9name_list) {
                Pname __2fr;
                Ptype __2frt;

                __2fr = __1l->f__9name_list;
                __2frt = __2fr->__O1__4expr.tp;

                switch (__2frt->base__4node) {
                    unsigned long __2__X135;

                case 108:
                    if ((((struct type *)__1f)) == __2frt)
                        return (unsigned char)1;
                    break;
                case 76:
                    __1l->f__9name_list = (__2fr = (((struct gen *)(((struct gen *)__2frt))))
                                                       ->fct_list__3gen->f__9name_list);
                    if (__2fr->__O1__4expr.tp == (((struct type *)__1f)))
                        return (unsigned char)1;
                case 6:
                    break;
                default: {
                    struct ea __0__V132;

                    error__FiPCcRC2eaN33(
                        (int)'i', (const char *)"bad friend %k",
                        (const struct ea *)((__2__X135 = __2fr->__O1__4expr.tp->base__4node),
                                            (((((&__0__V132)->__O1__2ea.i = __2__X135), 0)),
                                             (&__0__V132))),
                        (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
                }
                }
            }

            {
                Pname __1fn;

                __1fn = (me ? me
                            : ((cc->nof__11dcl_context &&
                                (cc->nof__11dcl_context->__O1__4expr.tp == (((struct type *)__1f))))
                                   ? cc->nof__11dcl_context
                                   : (((struct name *)0))));

                if (__1fn) {
                    {
                        {
                            Pcons __2p;

                            __2p = __0this->templ_friends__8classdef;

                            for (; __2p; __2p = __2p->cdr__4cons) {
                                Ptempl_base __3ptb;

                                __3ptb = (((struct basic_template *)((
                                    (struct basic_template *)__2p->car__4cons))));
                                if (__3ptb &&
                                    ((*(((int (*)(struct basic_template *__0this, Pname))(
                                             __3ptb->__vptr__14basic_template[2])
                                             .f))))(
                                        ((struct basic_template
                                              *)((((char *)__3ptb)) +
                                                 (__3ptb->__vptr__14basic_template[2]).d)),
                                        __1fn))
                                    return (unsigned char)1;
                            }
                        }
                    }
                }

                if (__1f->memof__3fct)
                    return has_friend__8classdefFP8classdef(__0this, __1f->memof__3fct);
                return (unsigned char)0;
            }
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

bit has_friend__8classdefFP8classdef(register struct classdef *__0this, Pclass __1cl) {
    {
        {
            Plist __1l;

            int __1__Xt00a3glwanawcnm;

            __1l = __0this->friend_list__8classdef;

            for (; __1l; __1l = __1l->l__9name_list) {
                Pname __2fr;
                Ptype __2frt;

                __2fr = __1l->f__9name_list;
                __2frt = __2fr->__O1__4expr.tp;
                switch (__2frt->base__4node) {
                    struct classdef *__1__X137;

                    struct classdef *__1__X138;

                case 6:
                    if (((__1__X137 = __1cl),
                         ((__1__X138 = (((struct classdef *)(((struct classdef *)__2frt))))),
                          (((__1__X137 == __1__X138)
                                ? 1
                                : ((__1__X137 && __1__X138)
                                       ? (((int)same_class__8classdefFP8classdefi(__1__X137,
                                                                                  __1__X138, 1)))
                                       : 0))))))
                        return (unsigned char)1;
                case 108:
                case 76:
                    break;
                default: {
                    unsigned long __2__X139;

                    {
                        struct ea __0__V136;

                        error__FiPCcRC2eaN33(
                            (int)'i', (const char *)"bad friend %k",
                            (const struct ea *)((__2__X139 = __2frt->base__4node),
                                                (((((&__0__V136)->__O1__2ea.i = __2__X139), 0)),
                                                 (&__0__V136))),
                            (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
                    }
                }
                }
            }

            if (((__1__Xt00a3glwanawcnm =
                      ((((struct type *)__1cl)->base__4node == 108)
                           ? (((struct fct *)(((struct fct *)((struct type *)__1cl)))))
                                 ->fct_base__3fct
                           : ((((struct type *)__1cl)->base__4node == 6)
                                  ? (((struct classdef *)((
                                         (struct classdef *)((struct type *)__1cl)))))
                                        ->class_base__8classdef
                                  : (((int)0))))),
                 (((unsigned char)((__1__Xt00a3glwanawcnm == 4) ||
                                   (__1__Xt00a3glwanawcnm == 5)))))) {
                Pname __2tn;
                __2tn = find_cn__6ktableFPCc(__1cl->k_tbl__8classdef, __1cl->string__8classdef);

                {
                    {
                        Pcons __2p;

                        __2p = __0this->templ_friends__8classdef;

                        for (; __2p; __2p = __2p->cdr__4cons) {
                            Ptempl_base __3ptb;

                            __3ptb = (((struct basic_template *)((
                                (struct basic_template *)__2p->car__4cons))));
                            if (__3ptb &&
                                ((*(((int (*)(struct basic_template *__0this, Pname))(
                                         __3ptb->__vptr__14basic_template[2])
                                         .f))))(((struct basic_template
                                                      *)((((char *)__3ptb)) +
                                                         (__3ptb->__vptr__14basic_template[2]).d)),
                                                __2tn))
                                return (unsigned char)1;
                        }
                    }
                }
            }

            if (__1cl->in_fct__4type)
                return has_friend__8classdefFP3fct(
                    __0this,
                    ((struct fct *)(((struct fct *)__1cl->in_fct__4type->__O1__4expr.tp))));
            if (__1cl->in_class__4type)
                return has_friend__8classdefFP8classdef(__0this, __1cl->in_class__4type);
            return (unsigned char)0;
        }
    }
}

bit check__4typeFP4typeUcT2(struct type *__0this, Ptype, TOK, bit);

Pname find_virtual__FP8classdefP4name(Pclass __1cl, Pname __1s);

Pname find_virtual__FP8classdefP4name(Pclass __1cl, Pname __1s) {
    {
        {
            Pbcl __1b;

            __1b = __1cl->baselist__8classdef;

            for (; __1b; __1b = __1b->next__6basecl) {
                Pclass __2bcl;
                Pname __2n;

                __2bcl = __1b->bclass__6basecl;

                if (__2n = look__5tableFPCcUc(__2bcl->memtbl__8classdef, __1s->__O2__4expr.string,
                                              (unsigned char)0)) {
                    if (__2n->base__4node == 25)
                        continue;
                    {
                        Pfct __3f;

                        __3f = (((struct fct *)(((struct fct *)__2n->__O1__4expr.tp))));
                        if (__3f->base__4node == 76) {
                            {
                                {
                                    Plist __4gl;

                                    __4gl =
                                        (((struct gen *)(((struct gen *)__3f))))->fct_list__3gen;

                                    for (; __4gl; __4gl = __4gl->l__9name_list) {
                                        __2n = __4gl->f__9name_list;

                                        if (check__4typeFP4typeUcT2(
                                                __2n->__O1__4expr.tp, __1s->__O1__4expr.tp,
                                                (unsigned char)77, (unsigned char)0))
                                            continue;

                                        if ((((struct fct *)(((struct fct *)__2n->__O1__4expr.tp))))
                                                ->f_virtual__3fct)
                                            return __2n;
                                    }
                                }
                            }
                        } else if (__3f->f_virtual__3fct &&
                                   (check__4typeFP4typeUcT2(__2n->__O1__4expr.tp,
                                                            __1s->__O1__4expr.tp, (unsigned char)77,
                                                            (unsigned char)0) == 0))
                            return __2n;
                    }
                } else if (__2n = find_virtual__FP8classdefP4name(__2bcl, __1s))
                    return __2n;
            }
            return (struct name *)0;
        }
    }
}

Pname dummy_fct = 0;

static int is_accessible__FP4nameP8classdefUc(Pname __1n, Pclass __1this_class, bit __1noCdcl) {
    struct classdef *__1__X140;

    struct classdef *__1__X141;

    struct classdef *__1__X142;

    struct classdef *__1__X143;

    if (((__1__X140 = __1this_class),
         ((__1__X141 = mec),
          (((__1__X140 == __1__X141)
                ? 1
                : ((__1__X140 && __1__X141)
                       ? (((int)same_class__8classdefFP8classdefi(__1__X140, __1__X141, 0)))
                       : 0))))) ||
        (mec && has_friend__8classdefFP8classdef(__1this_class, mec)))
        return 1;
    if ((mef &&
         ((mec == 0) ||
          ((__1__X142 = mec),
           ((__1__X143 = mef->memof__3fct),
            (((__1__X142 == __1__X143)
                  ? 1
                  : ((__1__X142 && __1__X143)
                         ? (((int)same_class__8classdefFP8classdefi(__1__X142, __1__X143, 0)))
                         : 0))))))) &&
        has_friend__8classdefFP3fct(__1this_class, mef))
        return 1;

    if (__1n->n_protect__4name && tcl) {
        struct classdef *__1__X146;

        struct classdef *__1__X147;

        if (mec) {
            struct classdef *__1__X144;

            struct classdef *__1__X145;

            if (has_friend__8classdefFP8classdef(tcl, mec) ||
                (has_base__8classdefFP8classdefiT2(mec, __1this_class, 0, 0) &&
                 (((__1__X144 = tcl),
                   ((__1__X145 = mec),
                    (((__1__X144 == __1__X145)
                          ? 1
                          : ((__1__X144 && __1__X145) ? (((int)same_class__8classdefFP8classdefi(
                                                            __1__X144, __1__X145, 0)))
                                                      : 0))))) ||
                  has_base__8classdefFP8classdefiT2(tcl, mec, 0, 0))))
                return 1;
        }

        if (mef &&
            ((mec == 0) ||
             ((__1__X146 = mec),
              ((__1__X147 = mef->memof__3fct),
               (((__1__X146 == __1__X147)
                     ? 1
                     : ((__1__X146 && __1__X147)
                            ? (((int)same_class__8classdefFP8classdefi(__1__X146, __1__X147, 0)))
                            : 0))))))) {
            if (has_base__8classdefFP8classdefiT2(tcl, __1this_class, 0, 0) &&
                friend_check__FP8classdefT1P3fct(tcl, __1this_class, mef))
                return 1;
        }
    }

    if (__1noCdcl)
        return 0;

    if ((((Cdcl && (Cdcl->base__4node == 85)) && (Cdcl->n_stclass__4name == 31)) &&
         ((!Cdcl->__O1__4expr.tp) ||
          (skiptypedefs__4typeFv(Cdcl->__O1__4expr.tp)->base__4node != 108))) &&
        Cdcl->__O2__4name.n_qualifier) {
        Pbase __2bn;
        Pclass __2cl;

        struct classdef *__1__X148;

        struct classdef *__1__X149;

        __2bn = (((struct basetype *)((
            (struct basetype *)Cdcl->__O2__4name.n_qualifier->__O1__4expr.tp))));
        __2cl =
            (((struct classdef *)(((struct classdef *)__2bn->b_name__8basetype->__O1__4expr.tp))));

        if ((((__1__X148 = __2cl),
              ((__1__X149 = __1this_class),
               (((__1__X148 == __1__X149)
                     ? 1
                     : ((__1__X148 && __1__X149)
                            ? (((int)same_class__8classdefFP8classdefi(__1__X148, __1__X149, 0)))
                            : 0))))) ||
             (__1n->n_protect__4name &&
              has_base__8classdefFP8classdefiT2(__2cl, __1this_class, 0, 0))) ||
            has_friend__8classdefFP8classdef(__1this_class, __2cl))
            return 1;
    }

    return 0;
}

void dcl_print__4nameFUc(struct name *__0this, TOK);

void dcl_print__8classdefFP4name(struct classdef *__0this, Pname);

Pexpr find_in_base__8classdefFPCcP8classdefiT3(struct classdef *__0this, const char *, Pclass, int,
                                               int);

Pname is_cl_obj__4typeFv(struct type *__0this);

extern int make_assignment__FP4name(Pname);

Pexpr find_name__8classdefFPCcP8classdefiT3(register struct classdef *__0this, const char *__1s,
                                            Pclass __1cl, int __1access_only, int __1newflag) {
    Pname __1n;

    struct classdef *__1__X205;

    struct classdef *__1__X206;

    __1n = look__5tableFPCcUc(__0this->memtbl__8classdef, __1s, (unsigned char)0);
    if (__1n == 0) {
        if ((__0this->in_class__4type && (__0this->templ_base__4type == 0)) &&
            (__0this->in_class__4type->class_base__8classdef == 4)) {
            Pname __3nn;
            __3nn = look__5tableFPCcUc(__0this->in_class__4type->memtbl__8classdef,
                                       __0this->string__8classdef, (unsigned char)6);
            if (__3nn) {
                Pclass __4cl;

                __4cl = (((struct classdef *)(((struct classdef *)__3nn->__O1__4expr.tp))));
                __1n = look__5tableFPCcUc(__4cl->memtbl__8classdef, __1s, (unsigned char)0);
            }
        }
    }

    if (__1n) {
        struct classdef *__1__X190;

        struct classdef *__1__X191;

        if (__1n->__O1__4expr.tp && (!__1access_only)) {
            switch (__1n->__O1__4expr.tp->base__4node) {
            case 76:
                break;
            case 108:
                if ((((struct fct *)(((struct fct *)__1n->__O1__4expr.tp))))->f_virtual__3fct ==
                    0) {
                    if (__1n->n_dcl_printed__4name == 0)
                        dcl_print__4nameFUc(__1n, (unsigned char)0);
                    break;
                }
            default:
                if (__0this->class_base__8classdef == 4) {
                    current_instantiation = __0this;
                }
                dcl_print__8classdefFP4name(__0this, (struct name *)0);
                if (__0this->class_base__8classdef == 4) {
                    current_instantiation = 0;
                }
            }
        }

        if (__1n->base__4node == 25) {
            if (mex && (__1n->n_scope__4name == 0)) {
                if (is_accessible__FP4nameP8classdefUc(__1n, __0this, (unsigned char)0) == 0) {
                    struct classdef *__1__X186;

                    struct classdef *__1__X187;

                    const void *__2__X188;

                    const void *__2__X189;

                    if (me == dummy_fct) {
                        const void *__2__X185;

                        if (mec) {
                            struct ea __0__V150;

                            struct ea __0__V151;

                            struct ea __0__V152;

                            error__FPCcRC2eaN32(
                                (const char *)"%t cannot access%n: %sM",
                                (const struct ea *)((__2__X185 = (const void *)mec),
                                                    (((&__0__V150)->__O1__2ea.p = __2__X185),
                                                     (&__0__V150))),
                                (const struct ea *)(((&__0__V151)->__O1__2ea.p =
                                                         ((const void *)__1n)),
                                                    (&__0__V151)),
                                (const struct ea *)__ct__2eaFPCv(
                                    &__0__V152,
                                    (const void *)(__1n->n_protect__4name ? "protected"
                                                                          : (((char *)"private")))),
                                (const struct ea *)ea0);
                        } else {
                            struct ea __0__V153;

                            struct ea __0__V154;

                            error__FPCcRC2eaN32(
                                (const char *)"G scope cannot access%n: %sM",
                                (const struct ea *)(((&__0__V153)->__O1__2ea.p =
                                                         ((const void *)__1n)),
                                                    (&__0__V153)),
                                (const struct ea *)__ct__2eaFPCv(
                                    &__0__V154,
                                    (const void *)(__1n->n_protect__4name ? "protected"
                                                                          : (((char *)"private")))),
                                (const struct ea *)ea0, (const struct ea *)ea0);
                        }
                    } else if (mec && ((mef == 0) ||
                                       (!((__1__X186 = mec),
                                          ((__1__X187 = mef->memof__3fct),
                                           (((__1__X186 == __1__X187)
                                                 ? 1
                                                 : ((__1__X186 && __1__X187)
                                                        ? (((int)same_class__8classdefFP8classdefi(
                                                              __1__X186, __1__X187, 0)))
                                                        : 0)))))))) {
                        struct ea __0__V155;

                        struct ea __0__V156;

                        struct ea __0__V157;

                        error__FPCcRC2eaN32(
                            (const char *)"%t cannot access%n: %sM",
                            (const struct ea *)((__2__X188 = (const void *)mec),
                                                (((&__0__V155)->__O1__2ea.p = __2__X188),
                                                 (&__0__V155))),
                            (const struct ea *)(((&__0__V156)->__O1__2ea.p = ((const void *)__1n)),
                                                (&__0__V156)),
                            (const struct ea *)__ct__2eaFPCv(
                                &__0__V157,
                                (const void *)(__1n->n_protect__4name ? "protected"
                                                                      : (((char *)"private")))),
                            (const struct ea *)ea0);
                    } else {
                        struct ea __0__V158;

                        struct ea __0__V159;

                        struct ea __0__V160;

                        error__FPCcRC2eaN32(
                            (const char *)"%n cannot access%n: %sM",
                            (const struct ea *)((__2__X189 = (const void *)me),
                                                (((&__0__V158)->__O1__2ea.p = __2__X189),
                                                 (&__0__V158))),
                            (const struct ea *)(((&__0__V159)->__O1__2ea.p = ((const void *)__1n)),
                                                (&__0__V159)),
                            (const struct ea *)__ct__2eaFPCv(
                                &__0__V160,
                                (const void *)(__1n->n_protect__4name ? "protected"
                                                                      : (((char *)"private")))),
                            (const struct ea *)ea0);
                    }
                    mex = 0;
                }
            }
            mex = 0;
            return find_in_base__8classdefFPCcP8classdefiT3(__0this, __1s, __1cl, __1access_only,
                                                            __1newflag);
        }

        if ((__1cl == 0) ||
            ((__1__X190 = __1cl),
             ((__1__X191 = __0this),
              (((__1__X190 == __1__X191)
                    ? 1
                    : ((__1__X190 && __1__X191)
                           ? (((int)same_class__8classdefFP8classdefi(__1__X190, __1__X191, 0)))
                           : 0)))))) {
            if (((mptr == 0) && (__1n->n_stclass__4name != 31)) && (__1n->n_stclass__4name != 13)) {
                Ptype __4t;

                __4t = __1n->__O1__4expr.tp;

                if ((mex && (__1n->n_scope__4name == 0)) &&
                    (__1n->__O1__4expr.tp->base__4node != 76)) {
                    if (is_accessible__FP4nameP8classdefUc(__1n, __0this, (unsigned char)0) == 0) {
                        struct classdef *__1__X193;

                        struct classdef *__1__X194;

                        const void *__2__X195;

                        const void *__2__X196;

                        if (me == dummy_fct) {
                            const void *__2__X192;

                            if (mec) {
                                struct ea __0__V161;

                                struct ea __0__V162;

                                struct ea __0__V163;

                                error__FPCcRC2eaN32(
                                    (const char *)"%t cannot access%n: %sM",
                                    (const struct ea *)((__2__X192 = (const void *)mec),
                                                        (((&__0__V161)->__O1__2ea.p = __2__X192),
                                                         (&__0__V161))),
                                    (const struct ea *)(((&__0__V162)->__O1__2ea.p =
                                                             ((const void *)__1n)),
                                                        (&__0__V162)),
                                    (const struct ea *)__ct__2eaFPCv(
                                        &__0__V163, (const void *)(__1n->n_protect__4name
                                                                       ? "protected"
                                                                       : (((char *)"private")))),
                                    (const struct ea *)ea0);
                            } else {
                                struct ea __0__V164;

                                struct ea __0__V165;

                                error__FPCcRC2eaN32(
                                    (const char *)"G scope cannot access%n: %sM",
                                    (const struct ea *)(((&__0__V164)->__O1__2ea.p =
                                                             ((const void *)__1n)),
                                                        (&__0__V164)),
                                    (const struct ea *)__ct__2eaFPCv(
                                        &__0__V165, (const void *)(__1n->n_protect__4name
                                                                       ? "protected"
                                                                       : (((char *)"private")))),
                                    (const struct ea *)ea0, (const struct ea *)ea0);
                            }
                        } else if (mec &&
                                   ((mef == 0) ||
                                    (!((__1__X193 = mec),
                                       ((__1__X194 = mef->memof__3fct),
                                        (((__1__X193 == __1__X194)
                                              ? 1
                                              : ((__1__X193 && __1__X194)
                                                     ? (((int)same_class__8classdefFP8classdefi(
                                                           __1__X193, __1__X194, 0)))
                                                     : 0)))))))) {
                            struct ea __0__V166;

                            struct ea __0__V167;

                            struct ea __0__V168;

                            error__FPCcRC2eaN32(
                                (const char *)"%t cannot access%n: %sM",
                                (const struct ea *)((__2__X195 = (const void *)mec),
                                                    (((&__0__V166)->__O1__2ea.p = __2__X195),
                                                     (&__0__V166))),
                                (const struct ea *)(((&__0__V167)->__O1__2ea.p =
                                                         ((const void *)__1n)),
                                                    (&__0__V167)),
                                (const struct ea *)__ct__2eaFPCv(
                                    &__0__V168,
                                    (const void *)(__1n->n_protect__4name ? "protected"
                                                                          : (((char *)"private")))),
                                (const struct ea *)ea0);
                        } else {
                            struct ea __0__V169;

                            struct ea __0__V170;

                            struct ea __0__V171;

                            error__FPCcRC2eaN32(
                                (const char *)"%n cannot access%n: %sM",
                                (const struct ea *)((__2__X196 = (const void *)me),
                                                    (((&__0__V169)->__O1__2ea.p = __2__X196),
                                                     (&__0__V169))),
                                (const struct ea *)(((&__0__V170)->__O1__2ea.p =
                                                         ((const void *)__1n)),
                                                    (&__0__V170)),
                                (const struct ea *)__ct__2eaFPCv(
                                    &__0__V171,
                                    (const void *)(__1n->n_protect__4name ? "protected"
                                                                          : (((char *)"private")))),
                                (const struct ea *)ea0);
                        }
                        mex = 0;
                    }
                }

                if (__1n->base__4node == 123)
                    return (struct expr *)0;
                if (__1access_only)
                    return (struct expr *)__1n;

                {
                    Pname __4th;
                    Pexpr __4r;

                    struct ref *__0__X197;

                    struct expr *__2__X198;

                    struct expr *__2__X199;

                    __4th = cc->c_this__11dcl_context;
                    __4r = (struct expr
                                *)((__0__X197 = 0),
                                   ((__2__X198 = (struct expr *)__4th),
                                    ((__2__X199 = (struct expr *)__1n),
                                     (((__0__X197 || (__0__X197 = (struct ref *)__nw__4exprSFUl(
                                                          (size_t)(sizeof(struct ref)))))
                                           ? ((__0__X197 = (struct ref *)__ct__4exprFUcP4exprT2(
                                                   ((struct expr *)__0__X197), ((unsigned char)44),
                                                   __2__X198, (struct expr *)0)),
                                              (__0__X197->__O4__4expr.mem = __2__X199))
                                           : 0),
                                      __0__X197))));
                    if (__4th)
                        ((__4th->n_used__4name++), (((void)0)));
                    ((__1n->n_used__4name++), (((void)0)));
                    __4r->__O1__4expr.tp = __4t;
                    return __4r;
                }
            }

            if ((mex && (__1n->n_scope__4name == 0)) && (__1n->__O1__4expr.tp->base__4node != 76)) {
                if (is_accessible__FP4nameP8classdefUc(__1n, __0this, (unsigned char)0) == 0) {
                    struct classdef *__1__X201;

                    struct classdef *__1__X202;

                    const void *__2__X203;

                    const void *__2__X204;

                    if (me == dummy_fct) {
                        const void *__2__X200;

                        if (mec) {
                            struct ea __0__V172;

                            struct ea __0__V173;

                            struct ea __0__V174;

                            error__FPCcRC2eaN32(
                                (const char *)"%t cannot access%n: %sM",
                                (const struct ea *)((__2__X200 = (const void *)mec),
                                                    (((&__0__V172)->__O1__2ea.p = __2__X200),
                                                     (&__0__V172))),
                                (const struct ea *)(((&__0__V173)->__O1__2ea.p =
                                                         ((const void *)__1n)),
                                                    (&__0__V173)),
                                (const struct ea *)__ct__2eaFPCv(
                                    &__0__V174,
                                    (const void *)(__1n->n_protect__4name ? "protected"
                                                                          : (((char *)"private")))),
                                (const struct ea *)ea0);
                        } else {
                            struct ea __0__V175;

                            struct ea __0__V176;

                            error__FPCcRC2eaN32(
                                (const char *)"G scope cannot access%n: %sM",
                                (const struct ea *)(((&__0__V175)->__O1__2ea.p =
                                                         ((const void *)__1n)),
                                                    (&__0__V175)),
                                (const struct ea *)__ct__2eaFPCv(
                                    &__0__V176,
                                    (const void *)(__1n->n_protect__4name ? "protected"
                                                                          : (((char *)"private")))),
                                (const struct ea *)ea0, (const struct ea *)ea0);
                        }
                    } else if (mec && ((mef == 0) ||
                                       (!((__1__X201 = mec),
                                          ((__1__X202 = mef->memof__3fct),
                                           (((__1__X201 == __1__X202)
                                                 ? 1
                                                 : ((__1__X201 && __1__X202)
                                                        ? (((int)same_class__8classdefFP8classdefi(
                                                              __1__X201, __1__X202, 0)))
                                                        : 0)))))))) {
                        struct ea __0__V177;

                        struct ea __0__V178;

                        struct ea __0__V179;

                        error__FPCcRC2eaN32(
                            (const char *)"%t cannot access%n: %sM",
                            (const struct ea *)((__2__X203 = (const void *)mec),
                                                (((&__0__V177)->__O1__2ea.p = __2__X203),
                                                 (&__0__V177))),
                            (const struct ea *)(((&__0__V178)->__O1__2ea.p = ((const void *)__1n)),
                                                (&__0__V178)),
                            (const struct ea *)__ct__2eaFPCv(
                                &__0__V179,
                                (const void *)(__1n->n_protect__4name ? "protected"
                                                                      : (((char *)"private")))),
                            (const struct ea *)ea0);
                    } else {
                        struct ea __0__V180;

                        struct ea __0__V181;

                        struct ea __0__V182;

                        error__FPCcRC2eaN32(
                            (const char *)"%n cannot access%n: %sM",
                            (const struct ea *)((__2__X204 = (const void *)me),
                                                (((&__0__V180)->__O1__2ea.p = __2__X204),
                                                 (&__0__V180))),
                            (const struct ea *)(((&__0__V181)->__O1__2ea.p = ((const void *)__1n)),
                                                (&__0__V181)),
                            (const struct ea *)__ct__2eaFPCv(
                                &__0__V182,
                                (const void *)(__1n->n_protect__4name ? "protected"
                                                                      : (((char *)"private")))),
                            (const struct ea *)ea0);
                    }
                    mex = 0;
                }
            }
            ((__1n->n_used__4name++), (((void)0)));
            return (struct expr *)__1n;
        }
    }

    if (((((__1cl == 0) ||
           ((__1__X205 = __1cl),
            ((__1__X206 = __0this),
             (((__1__X205 == __1__X206)
                   ? 1
                   : ((__1__X205 && __1__X206)
                          ? (((int)same_class__8classdefFP8classdefi(__1__X205, __1__X206, 0)))
                          : 0)))))) &&
          (__0this->csu__8classdef != 36)) &&
         (__0this->csu__8classdef != 167)) &&
        (strcmp(__1s, (const char *)"__as") == 0)) {
        if ((__0this->baselist__8classdef == 0) ||
            (__0this->baselist__8classdef->bclass__6basecl->obj_size__8classdef !=
             __0this->obj_size__8classdef)) {
            Pname __3cn;

            const void *__2__X207;

            __3cn = find_cn__6ktableFPCc(__0this->k_tbl__8classdef, __0this->string__8classdef);
            if (__3cn == 0) {
                struct ea __0__V183;

                struct ea __0__V184;

                error__FiPCcRC2eaN33(
                    (int)'i', (const char *)"CN %s missing inCdef::find_name(%s)",
                    (const struct ea *)((__2__X207 = (const void *)__0this->string__8classdef),
                                        (((&__0__V183)->__O1__2ea.p = __2__X207), (&__0__V183))),
                    (const struct ea *)(((&__0__V184)->__O1__2ea.p = ((const void *)__1s)),
                                        (&__0__V184)),
                    (const struct ea *)ea0, (const struct ea *)ea0);
            }
            if (__3cn->__O1__4expr.tp->base__4node == 119)
                __3cn = (((struct basetype *)(((struct basetype *)__3cn->__O1__4expr.tp))))
                            ->b_name__8basetype;
            {
                Pname __3x;

                __3x = look__5tableFPCcUc(gtbl, (const char *)"__as", (unsigned char)0);

                if (__3x) {
                    Pfct __4f;

                    __4f = (((struct fct *)(((struct fct *)__3x->__O1__4expr.tp))));
                    if (__4f->base__4node == 108) {
                        Pptr __5r;

                        __5r = is_ref__4typeFv(__4f->argtype__3fct->__O1__4expr.tp);
                        if (__5r) {
                            Pname __6cnn;

                            __6cnn = is_cl_obj__4typeFv(__5r->typ__5pvtyp);
                            if (__6cnn && (__3cn == __6cnn))
                                return (struct expr *)0;
                        }
                    } else {
                        {
                            {
                                Plist __5gl;

                                __5gl = (((struct gen *)(((struct gen *)__4f))))->fct_list__3gen;

                                for (; __5gl; __5gl = __5gl->l__9name_list) {
                                    Pptr __6r;

                                    __6r = is_ref__4typeFv(
                                        (((struct fct *)(((struct fct *)__5gl->f__9name_list))))
                                            ->argtype__3fct->__O1__4expr.tp);
                                    if (__6r) {
                                        Pname __7cnn;

                                        __7cnn = is_cl_obj__4typeFv(__6r->typ__5pvtyp);
                                        if (__7cnn && (__3cn == __7cnn))
                                            return (struct expr *)0;
                                    }
                                }
                            }
                        }
                    }
                }
                return (make_assignment__FP4name(__3cn)
                            ? find_name__8classdefFPCcP8classdefiT3(__0this, __1s, __1cl, 0, 0)
                            : (((struct expr *)0)));
            }
        }
    }

    return find_in_base__8classdefFPCcP8classdefiT3(__0this, __1s, __1cl, __1access_only,
                                                    __1newflag);
}

static Pclass rootClass;
static Pbcl pubVClass;
struct PendingMessage;

static struct PendingMessage *pM;

struct PendingMessage { /* sizeof PendingMessage == 24 */
    Pbcl bc__14PendingMessage;
    Pname mf__14PendingMessage;
    const char *nm__14PendingMessage;
};

extern const char *name_oper__FPCc(const char *);

Pexpr find_in_base__8classdefFPCcP8classdefiT3(register struct classdef *__0this, const char *__1s,
                                               Pclass __1cl, int __1access_only, int __1newflag) {
    int __1statflag;
    Pbcl __1e_bc;

    Pbcl __1bc;
    Pexpr __1e;

    static Pbcl __1bc_found_in = 0;
    __1statflag = 0;
    __1e_bc = 0;

    __1bc = 0;
    __1e = 0;

    if (me == 0)
        mef = 0;

    if (rootClass == 0) {
        rootClass = __0this;
        __1bc_found_in = 0;
    }

    {
        {
            Pbcl __1b;

            struct classdef *__1__X253;

            struct classdef *__1__X254;

            struct classdef *__1__X273;

            struct classdef *__1__X274;

            __1b = __0this->baselist__8classdef;

            for (; __1b; __1b = __1b->next__6basecl) {
                Pclass __2ccl;

                Pexpr __2ee;

                struct classdef *__1__X251;

                struct classdef *__1__X252;

                __2ccl =
                    (((__1__X251 = __1cl),
                      ((__1__X252 = __0this),
                       (((__1__X251 == __1__X252)
                             ? 1
                             : ((__1__X251 && __1__X252) ? (((int)same_class__8classdefFP8classdefi(
                                                               __1__X251, __1__X252, 0)))
                                                         : 0)))))
                         ? (((struct classdef *)0))
                         : __1cl);

                __2ee = find_name__8classdefFPCcP8classdefiT3(__1b->bclass__6basecl, __1s, __2ccl,
                                                              __1access_only, __1newflag);

                if (__2ee) {
                    if (!__1access_only) {
                        if ((__1b != __0this->baselist__8classdef) || (__1b->base__4node == 77))
                            dcl_print__8classdefFP4name(__0this, (struct name *)0);
                        else {
                            Pexpr __5ex;

                            __5ex = __2ee;
                            while (((__5ex->base__4node == 177) && (__5ex->__O2__4expr.i1 == 1)) ||
                                   ((__5ex->base__4node == 44) &&
                                    (__5ex->__O2__4expr.e1 ==
                                     (((struct expr *)cc->c_this__11dcl_context)))))
                                __5ex = __5ex->__O4__4expr.mem;
                            switch (__5ex->__O1__4expr.tp->base__4node) {
                            case 76:
                                break;
                            case 108:
                                if ((((struct fct *)(((struct fct *)__5ex->__O1__4expr.tp))))
                                        ->f_virtual__3fct == 0)
                                    break;
                            default:
                                dcl_print__8classdefFP4name(__0this, (struct name *)0);
                            }
                        }
                    }

                    if (__1e) {
                        Pexpr __4ex;
                        int __4evb;

                        __4ex = __1e;
                        __4evb = 0;

                        while ((__4ex->base__4node == 177) ||
                               ((__4ex->base__4node == 44) &&
                                (__4ex->__O2__4expr.e1 ==
                                 (((struct expr *)cc->c_this__11dcl_context))))) {
                            if (__4ex->base__4node == 177)
                                __4evb += (((int)__4ex->__O2__4expr.i1));
                            __4ex = __4ex->__O4__4expr.mem;
                        }

                        {
                            Pexpr __4eex;
                            int __4eevb;

                            struct classdef *__1__X245;

                            struct classdef *__1__X246;

                            struct classdef *__1__X247;

                            struct classdef *__1__X248;

                            __4eex = __2ee;
                            __4eevb = (__1b->base__4node == 77);

                            while ((__4eex->base__4node == 177) ||
                                   ((__4eex->base__4node == 44) &&
                                    (__4eex->__O2__4expr.e1 ==
                                     (((struct expr *)cc->c_this__11dcl_context))))) {
                                if (__4eex->base__4node == 177)
                                    __4eevb += (((int)__4eex->__O2__4expr.i1));
                                __4eex = __4eex->__O4__4expr.mem;
                            }

                            if (__4ex != __4eex) {
                                Pclass __5ocl;

                                Pclass __5ncl;
                                if (__4ex->__O1__4expr.tp->base__4node == 108)
                                    __5ocl =
                                        (((struct fct *)(((struct fct *)__4ex->__O1__4expr.tp))))
                                            ->memof__3fct;
                                else if (__4ex->__O1__4expr.tp->base__4node == 76)
                                    __5ocl =
                                        (((struct fct *)((
                                             (struct fct *)(((struct gen *)((
                                                                (struct gen *)
                                                                    __4ex->__O1__4expr.tp))))
                                                 ->fct_list__3gen->f__9name_list->__O1__4expr.tp))))
                                            ->memof__3fct;
                                else
                                    __5ocl = (((struct classdef *)((
                                        (struct classdef *)__4ex->__O4__4expr.n_table
                                            ->t_name__5table->__O1__4expr.tp))));

                                if (__4eex->__O1__4expr.tp->base__4node == 108)
                                    __5ncl =
                                        (((struct fct *)(((struct fct *)__4eex->__O1__4expr.tp))))
                                            ->memof__3fct;
                                else if (__4eex->__O1__4expr.tp->base__4node == 76)
                                    __5ncl =
                                        (((struct fct *)((
                                             (struct fct *)(((struct gen *)((
                                                                (struct gen *)
                                                                    __4eex->__O1__4expr.tp))))
                                                 ->fct_list__3gen->f__9name_list->__O1__4expr.tp))))
                                            ->memof__3fct;
                                else
                                    __5ncl = (((struct classdef *)((
                                        (struct classdef *)__4eex->__O4__4expr.n_table
                                            ->t_name__5table->__O1__4expr.tp))));

                                {
                                    int __5eb;
                                    int __5eeb;

                                    __5eb = (__5ocl ? (((int)has_base__8classdefFP8classdefiT2(
                                                          __5ocl, __5ncl, 0, 0)))
                                                    : 0);
                                    __5eeb = (__5ncl ? (((int)has_base__8classdefFP8classdefiT2(
                                                           __5ncl, __5ocl, 0, 0)))
                                                     : 0);

                                    if (((__5eb == 0) && (__5eeb == 0)) && (!__1newflag)) {
                                        {
                                            struct ea __0__V208;

                                            struct ea __0__V209;

                                            error__FPCcRC2eaN32(
                                                (const char *)"ambiguous%n and%n",
                                                (const struct ea *)(((&__0__V208)->__O1__2ea.p =
                                                                         ((const void *)__4ex)),
                                                                    (&__0__V208)),
                                                (const struct ea *)(((&__0__V209)->__O1__2ea.p =
                                                                         ((const void *)__4eex)),
                                                                    (&__0__V209)),
                                                (const struct ea *)ea0, (const struct ea *)ea0);
                                            break;
                                        }
                                    } else if (__5eb) {
                                        struct classdef *__1__X243;

                                        struct classdef *__1__X244;

                                        if ((__4eevb < __4evb) && (!__1newflag)) {
                                            struct ea __0__V210;

                                            struct ea __0__V211;

                                            error__FPCcRC2eaN32(
                                                (const char
                                                     *)"ambiguous%n and%n (different sub-objects)",
                                                (const struct ea *)(((&__0__V210)->__O1__2ea.p =
                                                                         ((const void *)__4ex)),
                                                                    (&__0__V210)),
                                                (const struct ea *)(((&__0__V211)->__O1__2ea.p =
                                                                         ((const void *)__4eex)),
                                                                    (&__0__V211)),
                                                (const struct ea *)ea0, (const struct ea *)ea0);
                                        } else if (
                                            (((__4eevb &&
                                               ((__1__X243 = rootClass),
                                                ((__1__X244 = __0this),
                                                 (((__1__X243 == __1__X244)
                                                       ? 1
                                                       : ((__1__X243 && __1__X244)
                                                              ? (((int)
                                                                      same_class__8classdefFP8classdefi(
                                                                          __1__X243, __1__X244, 0)))
                                                              : 0)))))) &&
                                              (__1b->ppp__6basecl == 25)) &&
                                             pM) &&
                                            (strcmp(__1b->bclass__6basecl->string__8classdef,
                                                    pM->bc__14PendingMessage->bclass__6basecl
                                                        ->string__8classdef) == 0)) {
                                            __dl__FPv((void *)pM);
                                            pM = 0;
                                            pubVClass = __1bc;
                                        }
                                    } else {
                                        __1e = __2ee;
                                        __1bc = __1b;
                                        if ((__4evb < __4eevb) && (!__1newflag)) {
                                            struct ea __0__V212;

                                            struct ea __0__V213;

                                            error__FPCcRC2eaN32(
                                                (const char
                                                     *)"ambiguous%n and%n (different sub-objects)",
                                                (const struct ea *)(((&__0__V212)->__O1__2ea.p =
                                                                         ((const void *)__4ex)),
                                                                    (&__0__V212)),
                                                (const struct ea *)(((&__0__V213)->__O1__2ea.p =
                                                                         ((const void *)__4eex)),
                                                                    (&__0__V213)),
                                                (const struct ea *)ea0, (const struct ea *)ea0);
                                        }
                                    }
                                    if (((__4evb == 0) && (__4eevb == 0)) && (!__1newflag)) {
                                        {
                                            struct ea __0__V214;

                                            struct ea __0__V215;

                                            error__FPCcRC2eaN32(
                                                (const char
                                                     *)"ambiguous%n and%n (different sub-objects)",
                                                (const struct ea *)(((&__0__V214)->__O1__2ea.p =
                                                                         ((const void *)__4ex)),
                                                                    (&__0__V214)),
                                                (const struct ea *)(((&__0__V215)->__O1__2ea.p =
                                                                         ((const void *)__4eex)),
                                                                    (&__0__V215)),
                                                (const struct ea *)ea0, (const struct ea *)ea0);
                                        }
                                    }
                                }
                            } else if ((__4ex->base__4node == 85) &&
                                       ((((((struct name *)(((struct name *)__4ex))))
                                              ->n_evaluated__4name ||
                                          ((((struct name *)(((struct name *)__4ex))))
                                               ->n_sto__4name == 14)) ||
                                         ((((struct name *)(((struct name *)__4ex))))
                                              ->n_stclass__4name == 31)) ||
                                        ((__4ex->__O1__4expr.tp &&
                                          (__4ex->__O1__4expr.tp->base__4node == 108)) &&
                                         (((struct fct *)(((struct fct *)__4ex->__O1__4expr.tp))))
                                             ->f_static__3fct))) {
                            } else if ((__4evb == 0) && (__4eevb == 0)) {
                                {
                                    struct ea __0__V216;

                                    struct ea __0__V217;

                                    error__FPCcRC2eaN32(
                                        (const char *)"ambiguous%n and%n (no virtualB)",
                                        (const struct ea *)(((&__0__V216)->__O1__2ea.p =
                                                                 ((const void *)__4ex)),
                                                            (&__0__V216)),
                                        (const struct ea *)(((&__0__V217)->__O1__2ea.p =
                                                                 ((const void *)__4eex)),
                                                            (&__0__V217)),
                                        (const struct ea *)ea0, (const struct ea *)ea0);
                                    break;
                                }
                            } else if ((__4evb && (__4eevb == 0)) || (__4eevb && (__4evb == 0))) {
                                {
                                    struct ea __0__V218;

                                    struct ea __0__V219;

                                    error__FPCcRC2eaN32(
                                        (const char *)"ambiguous%n and%n (one not in virtualB)",
                                        (const struct ea *)(((&__0__V218)->__O1__2ea.p =
                                                                 ((const void *)__4ex)),
                                                            (&__0__V218)),
                                        (const struct ea *)(((&__0__V219)->__O1__2ea.p =
                                                                 ((const void *)__4eex)),
                                                            (&__0__V219)),
                                        (const struct ea *)ea0, (const struct ea *)ea0);
                                    break;
                                }
                            } else if (((__1e_bc && __1bc_found_in) &&
                                        ((__1__X245 = __1e_bc->bclass__6basecl),
                                         ((__1__X246 = __1bc_found_in->bclass__6basecl),
                                          (((__1__X245 == __1__X246)
                                                ? 1
                                                : ((__1__X245 && __1__X246)
                                                       ? (((int)same_class__8classdefFP8classdefi(
                                                             __1__X245, __1__X246, 0)))
                                                       : 0)))))) &&
                                       (__1e_bc->base__4node != __1bc_found_in->base__4node)) {
                                {
                                    struct ea __0__V220;

                                    struct ea __0__V221;

                                    struct ea __0__V222;

                                    struct ea __0__V223;

                                    error__FPCcRC2eaN32(
                                        (const char *)"ambiguous%n: (%t both %s and %s)",
                                        (const struct ea *)(((&__0__V220)->__O1__2ea.p =
                                                                 ((const void *)__4ex)),
                                                            (&__0__V220)),
                                        (const struct ea *)__ct__2eaFPCv(
                                            &__0__V221, (const void *)__1e_bc->bclass__6basecl),
                                        (const struct ea *)__ct__2eaFPCv(
                                            &__0__V222,
                                            (const void *)((__1e_bc->base__4node == 77)
                                                               ? "virtual"
                                                               : (((char *)"nonvirtual")))),
                                        (const struct ea *)__ct__2eaFPCv(
                                            &__0__V223,
                                            (const void *)((__1bc_found_in->base__4node == 77)
                                                               ? "virtual"
                                                               : (((char *)"nonvirtual")))));
                                    __1e_bc = 0;
                                }
                            }

                            if ((((__4eevb &&
                                   ((__1__X247 = rootClass),
                                    ((__1__X248 = __0this),
                                     (((__1__X247 == __1__X248)
                                           ? 1
                                           : ((__1__X247 && __1__X248)
                                                  ? (((int)same_class__8classdefFP8classdefi(
                                                        __1__X247, __1__X248, 0)))
                                                  : 0)))))) &&
                                  (__1b->ppp__6basecl == 25)) &&
                                 pM) &&
                                (!strcmp(__1b->bclass__6basecl->string__8classdef,
                                         pM->bc__14PendingMessage->bclass__6basecl
                                             ->string__8classdef))) {
                                __dl__FPv((void *)pM);
                                pM = 0;
                                pubVClass = __1bc;
                            }
                        }
                    } else {
                        struct classdef *__1__X249;

                        struct classdef *__1__X250;

                        __1e = __2ee;
                        __1bc = __1b;
                        if (__1bc_found_in == 0)
                            __1bc_found_in = __1b;
                        if (((__1__X249 = rootClass),
                             ((__1__X250 = __0this),
                              (((__1__X249 == __1__X250)
                                    ? 1
                                    : ((__1__X249 && __1__X250)
                                           ? (((int)same_class__8classdefFP8classdefi(
                                                 __1__X249, __1__X250, 0)))
                                           : 0)))))) {
                            __1e_bc = __1bc_found_in;
                            __1bc_found_in = 0;
                        }
                    }

                    if ((((((__2ee->__O1__4expr.tp->base__4node == 108) &&
                            (((struct fct *)(((struct fct *)__2ee->__O1__4expr.tp))))
                                ->f_static__3fct) &&
                           __1cl) &&
                          (((struct fct *)(((struct fct *)__2ee->__O1__4expr.tp))))->memof__3fct) &&
                         (strcmp(__1cl->string__8classdef,
                                 (((struct fct *)(((struct fct *)__2ee->__O1__4expr.tp))))
                                     ->memof__3fct->string__8classdef) == 0)) ||
                        ((__2ee->base__4node == 85) &&
                         ((((struct name *)(((struct name *)__2ee))))->n_stclass__4name == 31)))
                        __1statflag = 1;
                }
            }

            if (((__1__X253 = rootClass),
                 ((__1__X254 = __0this),
                  (((__1__X253 == __1__X254)
                        ? 1
                        : ((__1__X253 && __1__X254)
                               ? (((int)same_class__8classdefFP8classdefi(__1__X253, __1__X254, 0)))
                               : 0)))))) {
                if (pM) {
                    Pbcl __3b;
                    const char *__3str;

                    const void *__2__X255;

                    unsigned long __2__X256;

                    __3b = pM->bc__14PendingMessage;
                    __3str = __3b->bclass__6basecl->string__8classdef;
                    {
                        struct ea __0__V224;

                        struct ea __0__V225;

                        struct ea __0__V226;

                        struct ea __0__V227;

                        error__FPCcRC2eaN32(
                            (const char *)"%n cannot access %s: %s is a%kBC",
                            (const struct ea *)((__2__X255 =
                                                     (const void *)pM->mf__14PendingMessage),
                                                (((&__0__V224)->__O1__2ea.p = __2__X255),
                                                 (&__0__V224))),
                            (const struct ea *)__ct__2eaFPCv(
                                &__0__V225,
                                (const void *)name_oper__FPCc(pM->nm__14PendingMessage)),
                            (const struct ea *)(((&__0__V226)->__O1__2ea.p =
                                                     ((const void *)__3str)),
                                                (&__0__V226)),
                            (const struct ea *)((__2__X256 = __3b->ppp__6basecl),
                                                (((((&__0__V227)->__O1__2ea.i = __2__X256), 0)),
                                                 (&__0__V227))));
                        __dl__FPv((void *)pM);

                        pM = 0;
                    }
                }

                if (__1e == 0) {
                    rootClass = 0;
                    pubVClass = 0;
                }
            }

            if (__1e == 0)
                return (struct expr *)0;

            if (mex) {
                if ((__1bc->ppp__6basecl == 174) || (__1bc->ppp__6basecl == 79)) {
                    struct classdef *__1__X257;

                    struct classdef *__1__X258;

                    struct classdef *__1__X259;

                    struct classdef *__1__X260;

                    if (((((__1__X257 = __0this),
                           ((__1__X258 = mec),
                            (((__1__X257 == __1__X258)
                                  ? 1
                                  : ((__1__X257 && __1__X258)
                                         ? (((int)same_class__8classdefFP8classdefi(__1__X257,
                                                                                    __1__X258, 0)))
                                         : 0))))) ||
                          (mec && has_friend__8classdefFP8classdef(__0this, mec))) ||
                         (mef && has_friend__8classdefFP3fct(__0this, mef))) ||
                        (((mec && (__1bc->ppp__6basecl == 79)) &&
                          is_base__8classdefFPCcPUci(mec, __0this->string__8classdef, (TOK *)0,
                                                     0)) &&
                         (ppbase != 174)))
                        ;
                    else if ((__1bc->base__4node == 77) &&
                             (!((__1__X259 = rootClass),
                                ((__1__X260 = __0this),
                                 (((__1__X259 == __1__X260)
                                       ? 1
                                       : ((__1__X259 && __1__X260)
                                              ? (((int)same_class__8classdefFP8classdefi(
                                                    __1__X259, __1__X260, 0)))
                                              : 0))))))) {
                        if ((pubVClass == 0) ||
                            strcmp(pubVClass->bclass__6basecl->string__8classdef,
                                   __1bc->bclass__6basecl->string__8classdef)) {
                            struct classdef *__1__X261;

                            struct classdef *__1__X262;

                            pM = (((struct PendingMessage *)((
                                (char *)__nw__FUl((size_t)(24 * (sizeof(char))))))));
                            pM->bc__14PendingMessage = __1bc;

                            pM->nm__14PendingMessage = __1s;
                            if (me == dummy_fct)
                                pM->mf__14PendingMessage =
                                    (mec ? mec->k_tbl__8classdef->k_name__6ktable : me);
                            else if (mec &&
                                     ((mef == 0) ||
                                      (!((__1__X261 = mec),
                                         ((__1__X262 = mef->memof__3fct),
                                          (((__1__X261 == __1__X262)
                                                ? 1
                                                : ((__1__X261 && __1__X262)
                                                       ? (((int)same_class__8classdefFP8classdefi(
                                                             __1__X261, __1__X262, 0)))
                                                       : 0))))))))
                                pM->mf__14PendingMessage = mec->k_tbl__8classdef->k_name__6ktable;
                            else
                                pM->mf__14PendingMessage = me;
                        }
                    } else {
                        if (me == dummy_fct) {
                            const void *__2__X263;

                            unsigned long __2__X264;

                            const void *__2__X265;

                            unsigned long __2__X266;

                            if (mec) {
                                struct ea __0__V228;

                                struct ea __0__V229;

                                struct ea __0__V230;

                                struct ea __0__V231;

                                error__FPCcRC2eaN32(
                                    (const char *)"%t cannot access %s: %s is a %k BC",
                                    (const struct ea *)((__2__X263 = (const void *)mec),
                                                        (((&__0__V228)->__O1__2ea.p = __2__X263),
                                                         (&__0__V228))),
                                    (const struct ea *)__ct__2eaFPCv(
                                        &__0__V229, (const void *)name_oper__FPCc(__1s)),
                                    (const struct ea *)__ct__2eaFPCv(
                                        &__0__V230,
                                        (const void *)__1bc->bclass__6basecl->string__8classdef),
                                    (const struct ea *)((__2__X264 = __1bc->ppp__6basecl),
                                                        (((((&__0__V231)->__O1__2ea.i = __2__X264),
                                                           0)),
                                                         (&__0__V231))));
                            } else {
                                struct ea __0__V232;

                                struct ea __0__V233;

                                struct ea __0__V234;

                                error__FPCcRC2eaN32(
                                    (const char *)"G scope cannot access %s: %s is a %k BC",
                                    (const struct ea *)((__2__X265 =
                                                             (const void *)name_oper__FPCc(__1s)),
                                                        (((&__0__V232)->__O1__2ea.p = __2__X265),
                                                         (&__0__V232))),
                                    (const struct ea *)__ct__2eaFPCv(
                                        &__0__V233,
                                        (const void *)__1bc->bclass__6basecl->string__8classdef),
                                    (const struct ea *)((__2__X266 = __1bc->ppp__6basecl),
                                                        (((((&__0__V234)->__O1__2ea.i = __2__X266),
                                                           0)),
                                                         (&__0__V234))),
                                    (const struct ea *)ea0);
                            }
                        } else if (((__1statflag == 0) ||
                                    (strcmp(__1s, (const char *)"__nw") == 0)) ||
                                   (strcmp(__1s, (const char *)"__dl") == 0)) {
                            struct classdef *__1__X267;

                            struct classdef *__1__X268;

                            const void *__2__X269;

                            unsigned long __2__X270;

                            const void *__2__X271;

                            unsigned long __2__X272;

                            if (mec && ((mef == 0) ||
                                        (!((__1__X267 = mec),
                                           ((__1__X268 = mef->memof__3fct),
                                            (((__1__X267 == __1__X268)
                                                  ? 1
                                                  : ((__1__X267 && __1__X268)
                                                         ? (((int)same_class__8classdefFP8classdefi(
                                                               __1__X267, __1__X268, 0)))
                                                         : 0)))))))) {
                                struct ea __0__V235;

                                struct ea __0__V236;

                                struct ea __0__V237;

                                struct ea __0__V238;

                                error__FPCcRC2eaN32(
                                    (const char *)"%t cannot access %s: %s is a %k BC",
                                    (const struct ea *)((__2__X269 = (const void *)mec),
                                                        (((&__0__V235)->__O1__2ea.p = __2__X269),
                                                         (&__0__V235))),
                                    (const struct ea *)__ct__2eaFPCv(
                                        &__0__V236, (const void *)name_oper__FPCc(__1s)),
                                    (const struct ea *)__ct__2eaFPCv(
                                        &__0__V237,
                                        (const void *)__1bc->bclass__6basecl->string__8classdef),
                                    (const struct ea *)((__2__X270 = __1bc->ppp__6basecl),
                                                        (((((&__0__V238)->__O1__2ea.i = __2__X270),
                                                           0)),
                                                         (&__0__V238))));
                            } else {
                                struct ea __0__V239;

                                struct ea __0__V240;

                                struct ea __0__V241;

                                struct ea __0__V242;

                                error__FPCcRC2eaN32(
                                    (const char *)"%n cannot access %s: %s is a %k BC",
                                    (const struct ea *)((__2__X271 = (const void *)me),
                                                        (((&__0__V239)->__O1__2ea.p = __2__X271),
                                                         (&__0__V239))),
                                    (const struct ea *)__ct__2eaFPCv(
                                        &__0__V240, (const void *)name_oper__FPCc(__1s)),
                                    (const struct ea *)__ct__2eaFPCv(
                                        &__0__V241,
                                        (const void *)__1bc->bclass__6basecl->string__8classdef),
                                    (const struct ea *)((__2__X272 = __1bc->ppp__6basecl),
                                                        (((((&__0__V242)->__O1__2ea.i = __2__X272),
                                                           0)),
                                                         (&__0__V242))));
                            }
                        }
                        mex = 0;
                    }
                } else {
                    if (__1bc->base__4node == 77) {
                        if (pM &&
                            (strcmp(__1bc->bclass__6basecl->string__8classdef,
                                    pM->bc__14PendingMessage->bclass__6basecl->string__8classdef) ==
                             0)) {
                            __dl__FPv((void *)pM);
                            pM = 0;
                            pubVClass = __1bc;
                        } else
                            pubVClass = __1bc;
                    }
                }
            }

            if (((__1__X273 = rootClass),
                 ((__1__X274 = __0this),
                  (((__1__X273 == __1__X274)
                        ? 1
                        : ((__1__X273 && __1__X274)
                               ? (((int)same_class__8classdefFP8classdefi(__1__X273, __1__X274, 0)))
                               : 0)))))) {
                rootClass = 0;
                pubVClass = 0;
            }

            if ((__1e->base__4node == 85) &&
                ((((struct name *)(((struct name *)__1e))))->n_stclass__4name == 31)) {
                (((((struct name *)(((struct name *)__1e))))->n_used__4name++), (((void)0)));
                return __1e;
            }
            if (__1e->base__4node != 85)
                if (__1bc->base__4node == 77) {
                    register struct mdot *__0__X275;

                    const char *__2__X276;

                    struct expr *__2__X277;

                    __1e->__O4__4expr.mem =
                        (struct expr
                             *)((__0__X275 = 0),
                                ((__2__X276 = __1bc->bclass__6basecl->string__8classdef),
                                 ((__2__X277 = __1e->__O4__4expr.mem),
                                  (((__0__X275 || (__0__X275 = (struct mdot *)__nw__4exprSFUl(
                                                       (size_t)(sizeof(struct mdot)))))
                                        ? ((__0__X275 = (struct mdot *)__ct__4exprFUcP4exprT2(
                                                ((struct expr *)__0__X275), (unsigned char)177,
                                                (struct expr *)0, (struct expr *)0)),
                                           ((__0__X275->__O3__4expr.string2 = __2__X276),
                                            (__0__X275->__O4__4expr.mem = __2__X277)))
                                        : 0),
                                   __0__X275))));
                    __1e->__O4__4expr.mem->__O2__4expr.i1 = 1;
                    __1e->__O4__4expr.mem->__O1__4expr.tp =
                        __1e->__O4__4expr.mem->__O4__4expr.mem->__O1__4expr.tp;
                } else if (__1bc != __0this->baselist__8classdef) {
                    if (__1e->__O2__4expr.e1 == (((struct expr *)cc->c_this__11dcl_context))) {
                        register struct mdot *__0__X278;

                        const char *__2__X279;

                        struct expr *__2__X280;

                        __1e->__O4__4expr.mem =
                            (struct expr
                                 *)((__0__X278 = 0),
                                    ((__2__X279 = __1bc->bclass__6basecl->string__8classdef),
                                     ((__2__X280 = __1e->__O4__4expr.mem),
                                      (((__0__X278 || (__0__X278 = (struct mdot *)__nw__4exprSFUl(
                                                           (size_t)(sizeof(struct mdot)))))
                                            ? ((__0__X278 = (struct mdot *)__ct__4exprFUcP4exprT2(
                                                    ((struct expr *)__0__X278), (unsigned char)177,
                                                    (struct expr *)0, (struct expr *)0)),
                                               ((__0__X278->__O3__4expr.string2 = __2__X279),
                                                (__0__X278->__O4__4expr.mem = __2__X280)))
                                            : 0),
                                       __0__X278))));
                        __1e->__O4__4expr.mem->__O1__4expr.tp =
                            __1e->__O4__4expr.mem->__O4__4expr.mem->__O1__4expr.tp;
                    } else {
                        Pexpr __3ee;

                        register struct mdot *__0__X281;

                        const char *__2__X282;

                        struct expr *__2__X283;

                        __3ee = __1e;
                        while (__3ee->__O2__4expr.e1->base__4node == 44)
                            __3ee = __3ee->__O2__4expr.e1;
                        __3ee->__O4__4expr.mem =
                            (struct expr
                                 *)((__0__X281 = 0),
                                    ((__2__X282 = __1bc->bclass__6basecl->string__8classdef),
                                     ((__2__X283 = __3ee->__O4__4expr.mem),
                                      (((__0__X281 || (__0__X281 = (struct mdot *)__nw__4exprSFUl(
                                                           (size_t)(sizeof(struct mdot)))))
                                            ? ((__0__X281 = (struct mdot *)__ct__4exprFUcP4exprT2(
                                                    ((struct expr *)__0__X281), (unsigned char)177,
                                                    (struct expr *)0, (struct expr *)0)),
                                               ((__0__X281->__O3__4expr.string2 = __2__X282),
                                                (__0__X281->__O4__4expr.mem = __2__X283)))
                                            : 0),
                                       __0__X281))));
                        __3ee->__O4__4expr.mem->__O1__4expr.tp =
                            __3ee->__O4__4expr.mem->__O4__4expr.mem->__O1__4expr.tp;
                    }
                }

            return __1e;
        }
    }
}

int has_virt__FP8classdef(Pclass __1cl);

int has_virt__FP8classdef(Pclass __1cl) {
    if (__1cl->virt_count__8classdef)
        return 1;
    {
        {
            Pbcl __1b;

            __1b = __1cl->baselist__8classdef;

            for (; __1b; __1b = __1b->next__6basecl)
                if (__1b->bclass__6basecl->virt_count__8classdef ||
                    has_virt__FP8classdef(__1b->bclass__6basecl))
                    return 1;
            return 0;
        }
    }
}

Pname find_vptr__FP8classdef(Pclass __1cl) {
    while (__1cl) {
        Pname __2vp;

        __2vp =
            look__5tableFPCcUc(__1cl->memtbl__8classdef, (const char *)"__vptr", (unsigned char)0);
        if (__2vp)
            return __2vp;
        {
            Pbcl __2b;

            __2b = __1cl->baselist__8classdef;
            __1cl = 0;
            for (; __2b; __2b = __2b->next__6basecl)
                if (__2b->base__4node == 85) {
                    __1cl = __2b->bclass__6basecl;
                    break;
                }
        }
    }

    return (struct name *)0;
}

Pname dcl__4nameFP5tableUc(struct name *__0this, Ptable, TOK);

void make_dummy__Fv(void) {
    Pname __1x;

    __1x = __ct__4nameFPCc((struct name *)0, (const char *)"..");
    __1x->__O1__4expr.tp = (struct type *)__ct__3fctFP4typeP4nameUc(
        (struct fct *)0, Pvoid_type, (struct name *)0, (unsigned char)1);
    dummy_fct = dcl__4nameFP5tableUc(__1x, gtbl, (unsigned char)14);

    ((__1x
          ? (((void)(__1x
                         ? (((void)((((((struct expr *)__1x))
                                          ? (((void)((((struct expr *)__1x)) ? (((void)(((void)0))))
                                                                             : (((void)0)))))
                                          : (((void)0)))),
                                    (((void)__dl__4nameSFPvUl((void *)__1x,
                                                              (size_t)(sizeof(struct name))))))))
                         : (((void)0)))))
          : (((void)0))));
}

void check_visibility__FP4nameT1P8classdefP5tableT1(Pname __1n, Pname __1q, Pclass __1cl,
                                                    Ptable __1tbl, Pname __1fn) {
    if (__1fn == 0) {
        if (dummy_fct == 0)
            make_dummy__Fv();

        __1fn = dummy_fct;
    }
    {
        Pname __1nn;
        const char *__1s;

        __1nn = __ct__4nameFPCc((struct name *)0, (const char *)0);
        __1s = __1n->n_gen_fct_name__4name;
        __1nn->__O2__4expr.string = (__1s ? __1s : __1n->__O2__4expr.string);
        __1nn->__O2__4name.n_qualifier = __1q;
        {
            Pname __1nx;

            __1nx = (((struct name *)(((struct name *)find_name__FP4nameP8classdefP5tableiT1(
                __1nn, __1cl, __1tbl, 44, __1fn)))));
            if (__1nx->__O1__4expr.tp->base__4node != 76)
                return;

            {
                {
                    Plist __1gl;

                    __1gl =
                        (((struct gen *)(((struct gen *)__1nx->__O1__4expr.tp))))->fct_list__3gen;

                    for (; __1gl; __1gl = __1gl->l__9name_list) {
                        Pname __2nn;

                        __2nn = __1gl->f__9name_list;
                        if (__1n == __2nn) {
                            if (__2nn->n_scope__4name)
                                return;

                            {
                                Pname __3ome;
                                Pfct __3omef;
                                Pclass __3omec;
                                Pclass __3otcl;

                                Pclass __3ncl;
                                Pname __3fncn;

                                __3ome = me;
                                __3omef = mef;
                                __3omec = mec;
                                __3otcl = tcl;

                                __3ncl = (((struct classdef *)((
                                    (struct classdef *)__2nn->__O4__4expr.n_table->t_name__5table
                                        ->__O1__4expr.tp))));
                                __3fncn = __1fn->__O4__4expr.n_table->t_name__5table;

                                me = __1fn;
                                mec = (__3fncn ? (((struct classdef *)((
                                                     (struct classdef *)__3fncn->__O1__4expr.tp))))
                                               : (((struct classdef *)0)));
                                if (cc->cot__11dcl_context &&
                                    (cc->cot__11dcl_context->lex_level__4type >
                                     __1fn->lex_level__4name))
                                    mec = cc->cot__11dcl_context;
                                {
                                    Pfct __3f;

                                    __3f = (mef = (((struct fct *)((
                                                (struct fct *)__1fn->__O1__4expr.tp)))));
                                    tcl = __1cl;

                                    {
                                        int __3ok;

                                        struct classdef *__1__X298;

                                        struct classdef *__1__X299;

                                        const void *__2__X300;

                                        __3ok = is_accessible__FP4nameP8classdefUc(
                                            __1n, __3ncl, (unsigned char)1);

                                        mef = __3omef;

                                        mec = __3omec;

                                        tcl = __3otcl;

                                        me = __3ome;

                                        if (__3ok)
                                            return;

                                        if ((((Cdcl && (Cdcl->base__4node == 85)) &&
                                              (Cdcl->n_stclass__4name == 31)) &&
                                             Cdcl->__O3__4expr.n_initializer) &&
                                            Cdcl->__O2__4name.n_qualifier) {
                                            Pbase __4bn;
                                            Pclass __4ccl;

                                            struct classdef *__1__X295;

                                            struct classdef *__1__X296;

                                            __4bn = (((struct basetype *)((
                                                (struct basetype *)Cdcl->__O2__4name.n_qualifier
                                                    ->__O1__4expr.tp))));
                                            __4ccl = (((struct classdef *)((
                                                (struct classdef *)
                                                    __4bn->b_name__8basetype->__O1__4expr.tp))));

                                            if ((((__1__X295 = __4ccl),
                                                  ((__1__X296 = __1cl),
                                                   (((__1__X295 == __1__X296)
                                                         ? 1
                                                         : ((__1__X295 && __1__X296)
                                                                ? (((int)
                                                                        same_class__8classdefFP8classdefi(
                                                                            __1__X295, __1__X296,
                                                                            0)))
                                                                : 0))))) ||
                                                 has_friend__8classdefFP3fct(__4ccl, __3f)) ||
                                                (__1n->n_protect__4name &&
                                                 has_base__8classdefFP8classdefiT2(__4ccl, __3ncl,
                                                                                   0, 0)))
                                                return;
                                        }

                                        if (__1fn == dummy_fct) {
                                            const void *__2__X297;

                                            if (mec) {
                                                struct ea __0__V284;

                                                struct ea __0__V285;

                                                struct ea __0__V286;

                                                error__FPCcRC2eaN32(
                                                    (const char *)"%t cannot access%a: %sM",
                                                    (const struct ea
                                                         *)((__2__X297 = (const void *)mec),
                                                            (((&__0__V284)->__O1__2ea.p =
                                                                  __2__X297),
                                                             (&__0__V284))),
                                                    (const struct ea *)(((&__0__V285)->__O1__2ea.p =
                                                                             ((const void *)__2nn)),
                                                                        (&__0__V285)),
                                                    (const struct ea *)__ct__2eaFPCv(
                                                        &__0__V286,
                                                        (const void
                                                             *)(__2nn->n_protect__4name
                                                                    ? "protected"
                                                                    : (((char *)"private")))),
                                                    (const struct ea *)ea0);
                                            } else {
                                                struct ea __0__V287;

                                                struct ea __0__V288;

                                                error__FPCcRC2eaN32(
                                                    (const char *)"G scope cannot access%n: %sM",
                                                    (const struct ea *)(((&__0__V287)->__O1__2ea.p =
                                                                             ((const void *)__2nn)),
                                                                        (&__0__V287)),
                                                    (const struct ea *)__ct__2eaFPCv(
                                                        &__0__V288,
                                                        (const void
                                                             *)(__2nn->n_protect__4name
                                                                    ? "protected"
                                                                    : (((char *)"private")))),
                                                    (const struct ea *)ea0, (const struct ea *)ea0);
                                            }
                                        } else if (
                                            mec &&
                                            ((mef == 0) ||
                                             (!((__1__X298 = mec),
                                                ((__1__X299 = mef->memof__3fct),
                                                 (((__1__X298 == __1__X299)
                                                       ? 1
                                                       : ((__1__X298 && __1__X299)
                                                              ? (((int)
                                                                      same_class__8classdefFP8classdefi(
                                                                          __1__X298, __1__X299, 0)))
                                                              : 0)))))))) {
                                            struct ea __0__V289;

                                            struct ea __0__V290;

                                            struct ea __0__V291;

                                            error__FPCcRC2eaN32(
                                                (const char *)"%t cannot access%a: %sM",
                                                (const struct ea *)((__2__X300 = (const void *)mec),
                                                                    (((&__0__V289)->__O1__2ea.p =
                                                                          __2__X300),
                                                                     (&__0__V289))),
                                                (const struct ea *)(((&__0__V290)->__O1__2ea.p =
                                                                         ((const void *)__2nn)),
                                                                    (&__0__V290)),
                                                (const struct ea *)__ct__2eaFPCv(
                                                    &__0__V291,
                                                    (const void *)(__2nn->n_protect__4name
                                                                       ? "protected"
                                                                       : (((char *)"private")))),
                                                (const struct ea *)ea0);
                                        } else {
                                            struct ea __0__V292;

                                            struct ea __0__V293;

                                            struct ea __0__V294;

                                            error__FPCcRC2eaN32(
                                                (const char *)"%a cannot access%a: %sM",
                                                (const struct ea *)(((&__0__V292)->__O1__2ea.p =
                                                                         ((const void *)__1fn)),
                                                                    (&__0__V292)),
                                                (const struct ea *)(((&__0__V293)->__O1__2ea.p =
                                                                         ((const void *)__2nn)),
                                                                    (&__0__V293)),
                                                (const struct ea *)__ct__2eaFPCv(
                                                    &__0__V294,
                                                    (const void *)(__2nn->n_protect__4name
                                                                       ? "protected"
                                                                       : (((char *)"private")))),
                                                (const struct ea *)ea0);
                                        }
                                        return;
                                    }
                                }
                            }
                        }
                    }
                    error__FiPCc((int)'i', (const char *)"visibility check failed");
                }
            }
        }
    }
}
void dummy__14basic_templateFv(struct basic_template *__0this);
struct __mptr __vtbl__13data_template[] = {0, 0, 0,
                                           0, 0, (__vptp)dummy__14basic_templateFv,
                                           0, 0, (__vptp)has_friend__13data_templateFP4name,
                                           0, 0, 0};
struct __mptr __vtbl__5templ[] = {
    0, 0, 0, 0, 0, (__vptp)dummy__14basic_templateFv, 0, 0, (__vptp)has_friend__5templFP4name,
    0, 0, 0};
struct __mptr __vtbl__17function_template[] = {0, 0, 0,
                                               0, 0, (__vptp)dummy__14basic_templateFv,
                                               0, 0, (__vptp)has_friend__17function_templateFP4name,
                                               0, 0, 0};

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
