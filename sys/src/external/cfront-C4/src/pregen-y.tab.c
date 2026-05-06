
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

struct rangeforstmt;

struct rangeforstmt { /* sizeof rangeforstmt == 80 — same layout as forstmt */

    TOK base__4node;
    bit permanent__4node;
    bit baseclass__4node;

    Pstmt s__4stmt;
    Pstmt s_list__4stmt;
    Pstmt gt__4stmt;
    struct loc where__4stmt;

    union __Q2_4stmt4__C1 __O1__4stmt; /* d = range variable Pname */

    union __Q2_4stmt4__C2 __O2__4stmt; /* e = range expression Pexpr */
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

int in_friend = 0;
int must_be_friend = 0;
int dont_instantiate = 0;
static int explicit_template_definition = 0;
Pname righttname = 0;
struct parstate;

struct parstate { /* sizeof parstate == 32 */
    Ptype intypedef__8parstate;
    int infriend__8parstate;
    int defercheck__8parstate;
    Pname intag__8parstate;
    int cid__8parstate;
};

static struct parstate pstate[128];
static int px;
extern int classid;

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

const char *whereami__6ktableFv(struct ktable *__0this);

static void SAVE_STATE__Fv(void) {
    const void *__2__X27;

    if (px >= 128) {
        struct ea __0__V26;

        error__FiPCcRC2eaN33(
            (int)'i', (const char *)"parsing state stack overflow -- current table %s",
            (const struct ea *)((__2__X27 = (const void *)whereami__6ktableFv(Ctbl)),
                                (((&__0__V26)->__O1__2ea.p = __2__X27), (&__0__V26))),
            (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
    }
    (pstate[px]).intypedef__8parstate = in_typedef;
    (pstate[px]).infriend__8parstate = in_friend;
    in_typedef = 0;
    in_friend = 0;
    (pstate[px]).defercheck__8parstate = defer_check;
    defer_check = 0;
    (pstate[px]).intag__8parstate = in_tag;
    in_tag = 0;
    (pstate[px]).cid__8parstate = classid;
    classid = 0;
    ++px;
}

static void RESTORE_STATE__Fv(void) {
    const void *__2__X29;

    if ((--px) < 0) {
        struct ea __0__V28;

        error__FiPCcRC2eaN33(
            (int)'i', (const char *)"parsing state stack underflow -- current table %s",
            (const struct ea *)((__2__X29 = (const void *)whereami__6ktableFv(Ctbl)),
                                (((&__0__V28)->__O1__2ea.p = __2__X29), (&__0__V28))),
            (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
    }
    in_typedef = (pstate[px]).intypedef__8parstate;
    in_friend = (pstate[px]).infriend__8parstate;
    defer_check = (pstate[px]).defercheck__8parstate;
    in_tag = (pstate[px]).intag__8parstate;
    classid = (pstate[px]).cid__8parstate;
}

struct ktable *__ct__6ktableFiP6ktableP4name(struct ktable *__0this, int, Pktab, Pname);

Pclass classtype__4typeFv(struct type *__0this);

void expand__6ktableFi(struct ktable *__0this, int);

void __dt__6ktableFv(struct ktable *__0this, int);
struct pcontext;

struct pcontext { /* sizeof pcontext == 16 */
    Pktab ktbl__8pcontext;
    int saved_template__8pcontext;
};
static struct pcontext scopestack[128];
static int scopex = 0;

static struct ea *__ct__2eaFPCv(struct ea *__0this, const void *__2pp);

Pname SET_SCOPE__FP4name(Pname __1n) {
    Pktab __1ntb;

    const void *__2__X32;

    if (__1n == 0)
        __1ntb = 0;
    else if (__1n == sta_name)
        __1ntb = Gtbl;
    else if (__1n->n_template_arg__4name == 1) {
        ;
        return __1n;
    } else if (__1n->__O1__4expr.tp) {
        Ptype __2t;

        __2t = skiptypedefs__4typeFv(__1n->__O1__4expr.tp);
        if (__2t->base__4node == 119)
            __1ntb = classtype__4typeFv(__2t)->k_tbl__8classdef;
        else
            __1ntb = 0;
    } else
        __1ntb = 0;
    ;
    if (__1ntb == 0)
        return (struct name *)0;
    if (scopex >= 128) {
        struct ea __0__V30;

        struct ea __0__V31;

        error__FiPCcRC2eaN33(
            (int)'i',
            (const char *)"set scope %s: parsing scope stack overflow -- current table %s",
            (const struct ea *)((__2__X32 = (const void *)whereami__6ktableFv(__1ntb)),
                                (((&__0__V30)->__O1__2ea.p = __2__X32), (&__0__V30))),
            (const struct ea *)__ct__2eaFPCv(&__0__V31, (const void *)whereami__6ktableFv(Ctbl)),
            (const struct ea *)ea0, (const struct ea *)ea0);
    }
    {
        Pktab __1tt;

        __1tt = Ctbl;
        if (Ctbl->k_id__6ktable == 185) {
            Ctbl = Ctbl->k_next__6ktable;
            __1tt->k_next__6ktable = __1ntb->k_next__6ktable;
            __1ntb->k_next__6ktable = __1tt;
            (scopestack[scopex]).saved_template__8pcontext = 1;
        } else if ((Ctbl->k_id__6ktable == 136) && (Ctbl->k_next__6ktable->k_id__6ktable == 185)) {
            Ctbl = Ctbl->k_next__6ktable->k_next__6ktable;
            __1tt->k_next__6ktable->k_next__6ktable = __1ntb->k_next__6ktable;
            __1ntb->k_next__6ktable = __1tt->k_next__6ktable;
            __1tt->k_next__6ktable = __1ntb;
            (scopestack[scopex]).saved_template__8pcontext = 1;
            __1ntb = __1tt;
        }
        (scopestack[(scopex++)]).ktbl__8pcontext = Ctbl;
        Ctbl = __1ntb;
        return __1n;
    }
}

void UNSET_SCOPE__Fv(void) {
    Pktab __1tt;

    const void *__2__X35;

    __1tt = 0;
    if ((--scopex) < 0) {
        struct ea __0__V33;

        error__FiPCcRC2eaN33(
            (int)'i', (const char *)"parsing scope stack underflow -- current scope %s",
            (const struct ea *)((__2__X35 = (const void *)whereami__6ktableFv(Ctbl)),
                                (((&__0__V33)->__O1__2ea.p = __2__X35), (&__0__V33))),
            (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
    }
    if ((scopestack[scopex]).saved_template__8pcontext) {
        const void *__2__X36;

        (scopestack[scopex]).saved_template__8pcontext = 0;
        if ((Ctbl->k_next__6ktable == 0) || (Ctbl->k_next__6ktable->k_id__6ktable != 185)) {
            struct ea __0__V34;

            error__FiPCcRC2eaN33(
                (int)'i',
                (const char *)"set scope failed restoring template table -- current table %s",
                (const struct ea *)((__2__X36 = (const void *)whereami__6ktableFv(Ctbl)),
                                    (((&__0__V34)->__O1__2ea.p = __2__X36), (&__0__V34))),
                (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
        }
        __1tt = Ctbl->k_next__6ktable;
        Ctbl->k_next__6ktable = __1tt->k_next__6ktable;
    };
    Ctbl = (scopestack[scopex]).ktbl__8pcontext;
    if (__1tt) {
        __1tt->k_next__6ktable = Ctbl;

        Ctbl = __1tt;
    }
}

static int init_seen = 0;
static int cdi = 0;
static Pnlist cd = 0;

static Pnlist cd_vec[128];
static char stmt_seen = 0;

static char stmt_vec[128];
static Pnlist scd[128];
static int scdp = -1;

static Pname memptr_pn;
static TOK memptr_tok;

static Pname err_name = 0;

static Pcons templ_friends;

Pname is_cl_obj__4typeFv(struct type *__0this);

static bit decl_with_init__FP5nlist(Pnlist __1cd) {
    {
        {
            Pname __1n;

            __1n = __1cd->head__5nlist;

            for (; __1n; __1n = __1n->__O1__4name.n_list) {
                if (__1n->__O3__4expr.n_initializer)
                    return (unsigned char)1;
                {
                    Pname __2cln;

                    __2cln = is_cl_obj__4typeFv(__1n->__O1__4expr.tp);
                    if (__2cln &&
                        (((struct classdef *)(((struct classdef *)__2cln->__O1__4expr.tp))))
                            ->c_ctor__8classdef)
                        return (unsigned char)1;
                }
            }
            return (unsigned char)0;
        }
    }
}

extern size_t strlen(const char *);

extern int sprintf(char *, const char *, ...);

extern int strncmp(const char *, const char *, size_t);

static char *get_classname__FPCc(const char *__1s) {
    char *__1r;

    __1r = (((char *)__nw__FUl((size_t)((sizeof(char)) * (strlen(__1s) + 1)))));
    sprintf(__1r, (const char *)"%s", __1s);
    {
        char *__1s2;

        const char *__1s1;

        __1s2 = __1r;

        __1s1 = __1s;
        while ((*__1s)) {
            for (; (__1s[0]) && (((__1s[0]) != '_') || ((__1s[1]) && ((__1s[1]) != '_'))); __1s++)
                __1s1++;

            ;
            if ((*__1s)) {
                if (strncmp(__1s, (const char *)"___pt__", (unsigned long)7) == 0) {
                    ((*__1s2)) = 0;
                    return __1r;
                }
                if (strncmp(__1s, (const char *)"__pt__", (unsigned long)6) == 0) {
                    ((*__1s2)) = '\0';
                    return __1r;
                }
            }
            return __1r;
        }
        return __1r;
    }
}

extern int error__FPCcRC2eaN32(const char *, const struct ea *, const struct ea *,
                               const struct ea *, const struct ea *);

static Pptr doptr__FUcT1(TOK __1p, TOK __1t) {
    Pptr __1r;

    __1r = __ct__3ptrFUcP4type((struct ptr *)0, __1p, (struct type *)0);
    switch (__1t) {
    case 26:
        __1r->b_const__4type = 1;

        break;
    case 170:
        error__FiPCc((int)'w', (const char *)"\"volatile\" not implemented (ignored)");
        break;
    default: {
        struct ea __0__V41;

        error__FPCcRC2eaN32(
            (const char *)"syntax error: *%k",
            (const struct ea *)(((((&__0__V41)->__O1__2ea.i = ((unsigned long)__1t)), 0)),
                                (&__0__V41)),
            (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
    }
    }
    return __1r;
}

extern Pname k_find_name__FPCcP6ktableUc(const char *, Pktab, TOK);

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

static Pbcl dobase__FUcP4nameT1(TOK __1pr, Pname __1n, TOK __1v) {
    Pbcl __1b;

    register struct basecl *__0__X46;

    struct basecl *__2__X47;

    struct node *__0__X9;

    __1b =
        ((__0__X46 = 0),
         ((__2__X47 = 0),
          (((__0__X46 ||
             (__0__X46 = (struct basecl *)__nw__FUl((unsigned long)(sizeof(struct basecl)))))
                ? ((__0__X46 = (struct basecl *)((__0__X9 = (((struct node *)__0__X46))),
                                                 (((__0__X9 || (__0__X9 = (struct node *)__nw__FUl(
                                                                    (size_t)(sizeof(struct node)))))
                                                       ? (((__0__X9->base__4node = 0),
                                                           (__0__X9->permanent__4node = 0)),
                                                          (__0__X9->baseclass__4node = 0))
                                                       : 0),
                                                  __0__X9))),
                   ((__0__X46->baseclass__4node = 1),
                    ((__0__X46->bclass__6basecl = ((struct classdef *)0)),
                     ((__0__X46->next__6basecl = __2__X47),
                      ((__0__X46->promoted__6basecl = 0),
                       ((__0__X46->init__6basecl = 0),
                        ((__0__X46->obj_offset__6basecl = (__0__X46->ptr_offset__6basecl = 0)),
                         (__0__X46->allocated__6basecl = 0))))))))
                : 0),
           __0__X46)));
    __1b->ppp__6basecl = __1pr;

    if (__1n) {
        if (__1n->base__4node != 123) {
            Pname __3nn;

            __3nn = k_find_name__FPCcP6ktableUc(__1n->__O2__4expr.string, Ctbl, (unsigned char)159);
            if (__3nn == 0) {
                {
                    struct ea __0__V42;

                    error__FPCcRC2eaN32(
                        (const char *)"BN%n not aTN",
                        (const struct ea *)(((&__0__V42)->__O1__2ea.p = ((const void *)__1n)),
                                            (&__0__V42)),
                        (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
                    return (struct basecl *)0;
                }
            } else
                __1n = __3nn;
        }

        {
            Pbase __2bt;

            __2bt = (((struct basetype *)(((struct basetype *)__1n->__O1__4expr.tp))));
            while (__2bt->base__4node == 97)
                __2bt = (((struct basetype *)((
                    (struct basetype *)__2bt->b_name__8basetype->__O1__4expr.tp))));

            if (__2bt->base__4node != 119) {
                if ((in_progress__17templ_compilation == 1) && (__2bt->base__4node == 141)) {
                    struct ea __0__V43;

                    error__FiPCcRC2eaN33(
                        (int)'s', (const char *)"formalTZ%n used asBC ofY",
                        (const struct ea *)(((&__0__V43)->__O1__2ea.p = ((const void *)__1n)),
                                            (&__0__V43)),
                        (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
                } else {
                    struct ea __0__V44;

                    error__FPCcRC2eaN32(
                        (const char *)"BN%n not aCN",
                        (const struct ea *)(((&__0__V44)->__O1__2ea.p = ((const void *)__1n)),
                                            (&__0__V44)),
                        (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
                }
                return (struct basecl *)0;
            }

            if (__1v) {
                if (__1v != 77) {
                    struct ea __0__V45;

                    error__FPCcRC2eaN32(
                        (const char *)"syntax error:%k inBCD",
                        (const struct ea *)(((((&__0__V45)->__O1__2ea.i = ((unsigned long)__1v)),
                                              0)),
                                            (&__0__V45)),
                        (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
                }
                __1b->base__4node = 77;
            } else
                __1b->base__4node = 85;

            __1b->bclass__6basecl = (((
                struct classdef *)(((struct classdef *)__2bt->b_name__8basetype->__O1__4expr.tp))));
        }
    }

    return __1b;
}
union YYSTYPE;

typedef union YYSTYPE YYSTYPE;

union YYSTYPE { /* sizeof YYSTYPE == 8 */
    const char *s__7YYSTYPE;
    TOK t__7YYSTYPE;
    int i__7YYSTYPE;
    struct loc l__7YYSTYPE;
    Pname pn__7YYSTYPE;
    Ptype pt__7YYSTYPE;
    Pexpr pe__7YYSTYPE;
    Pstmt ps__7YYSTYPE;
    Pbase pb__7YYSTYPE;
    Pnlist nl__7YYSTYPE;
    Pslist sl__7YYSTYPE;
    Pelist el__7YYSTYPE;
    Pbcl pbc__7YYSTYPE;
    Pptr pp__7YYSTYPE;
    PP p__7YYSTYPE;
    Plist pl__7YYSTYPE;
    struct toknode *q__7YYSTYPE;
};

void *__nw__7toknodeSFUl(size_t);
void __dl__7toknodeSFPvUl(void *, size_t);

extern struct toknode *front;

extern int yychar;
extern union YYSTYPE yylval;

extern union YYSTYPE yylval;

extern union YYSTYPE yyval;

extern int declTag;
int in_sizeof = 0;
int in_new = 0;
Ptype in_typedef = 0;
Pname in_tag = 0;
extern int defer_check;

extern int must_be_id;
int DECL_TYPE = 0;
int in_arg_list = 0;
static int in_binit_list = 0;
int in_class_decl = 0;
int parsing_class_members = 0;
int in_mem_fct = 0;
Ptempl_inst pti = 0;

extern int yyparse__Fv(void);

Pname syn__Fv(void) {
ll:
    switch (yyparse__Fv()) {
    case 0:
        return (struct name *)0;
    case 1:
        goto ll;
    default:
        return yyval.pn__7YYSTYPE;
    }
}

typedef int YYINT;
static const YYINT yylhs[416] = {                           -1,
    0,    0,    0,    0,    0,    0,   83,   85,   86,   82,
   66,   66,   66,   66,   66,   72,   72,    1,    1,    1,
    1,    1,    2,    2,   88,    4,    4,    4,   89,    3,
    3,    3,   90,   71,   87,   91,    6,    6,    7,    7,
    8,    8,    5,    5,   24,   92,   24,   24,   93,   24,
   25,   25,    9,    9,   94,   95,   64,   64,   64,   13,
   13,   13,   13,   13,   13,   13,   12,   12,   12,   12,
   12,   12,   57,   81,   81,   56,   56,   56,   56,   56,
   55,   80,   80,   19,   19,   19,   96,   14,   97,   14,
   14,   15,   15,   84,   84,   84,   98,   98,   48,   48,
   48,   48,   48,   16,   99,   16,   16,  101,   21,   21,
   21,   21,  100,  100,   74,   74,   75,   75,   76,   76,
   76,   76,   76,   20,   20,   20,   17,   17,   18,   18,
   22,   22,   22,   23,   23,   23,   23,   23,   23,   23,
   23,   26,   26,   26,   26,   69,   69,   69,   69,   69,
   69,   69,   69,   69,   69,   69,   69,   69,   69,   69,
   69,   69,   69,   69,   69,   69,   69,   69,   69,   69,
   69,   69,   69,   62,   60,   60,   63,   63,   77,   77,
   77,   79,   79,   27,   27,   27,   27,   27,   27,   27,
   27,   27,   27,   27,   27,   27,   27,   27,   27,   27,
   27,   47,   47,   47,   47,   47,   47,   47,   53,   53,
   53,   42,   42,   42,   42,   42,   44,   44,   29,   29,
   29,   30,   31,   58,  102,   32,   32,   32,   34,   34,
   34,   34,  103,   34,   34,  105,  104,   33,   33,   33,
   33,   33,   33,   33,   33,   33,   33,  106,   33,  107,
   33,  108,   33,  109,   33,  110,   33,  111,   33,   33,
   33,   67,   67,   68,   73,   73,   36,   35,   35,   28,
   28,   38,   38,   38,   38,   38,   38,   38,   38,   38,
   38,   38,   38,   38,   38,   38,   38,   38,   38,   38,
   38,   38,   38,   38,   38,   38,   37,   37,   37,   37,
   37,   37,   37,   37,   37,   37,   37,   37,   37,   37,
   37,   37,   37,   37,   37,   37,   37,   37,   37,   37,
   37,   37,   39,   39,   39,   39,   39,   39,   39,   39,
   39,   39,   39,   39,   39,   39,   39,   39,   39,   39,
   39,   39,   39,   39,   39,   39,   39,   39,   39,   39,
   39,   39,   39,   39,   39,   39,   39,   39,   39,   39,
   39,   39,   61,   61,   61,   61,   61,   61,   61,   61,
   41,   41,   41,   41,   41,   41,   41,   65,   59,   59,
   59,   40,   40,   40,   43,  112,   46,   46,   46,   46,
   45,   54,   50,  113,   50,   78,   51,   52,   52,   49,
   49,   70,   70,   70,   11,   11,   11,   11,   11,   11,
   11,   11,   11,   10,   10,
};

static const YYINT yylen[416] = {                            2,
    1,    1,    1,    2,    1,    1,    0,    0,    0,    8,
    1,    1,    1,    1,    2,    1,    1,    1,    1,    1,
    1,    5,    4,    2,    0,    7,    5,    5,    0,    6,
    4,    4,    0,    4,    0,    0,    3,    0,    1,    3,
    3,    4,    2,    0,    1,    0,    4,    2,    0,    4,
    1,    3,    3,    2,    1,    1,    1,    4,    4,    1,
    1,    1,    2,    1,    1,    1,    1,    2,    2,    2,
    2,    2,    1,    3,    1,    0,    3,    2,    2,    2,
    2,    1,    1,    1,    1,    2,    0,    5,    0,    6,
    2,    1,    3,    3,    1,    0,    2,    2,    1,    2,
    2,    2,    3,    1,    0,    4,    0,    0,    5,    2,
    5,    2,    0,    2,    2,    0,    1,    3,    1,    2,
    2,    3,    3,    2,    4,    7,    1,    1,    1,    1,
    2,    0,    2,    1,    2,    2,    1,    1,    1,    2,
    3,    1,    2,    2,    2,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    2,
    2,    1,    1,    1,    1,    1,    1,    3,    1,    3,
    1,    1,    1,    1,    1,    2,    2,    1,    0,    2,
    5,    1,    3,    2,    4,    2,    4,    6,    6,    4,
    4,    6,    1,    3,    2,    4,    2,    2,    2,    2,
    3,    1,    2,    0,    2,    2,    2,    3,    0,    2,
    2,    0,    2,    2,    4,    4,    0,    2,    0,    2,
    2,    2,    0,    3,    0,    4,    2,    3,    1,    1,
    1,    2,    0,    5,    4,    0,    2,    2,    1,    3,
    3,    1,    1,    1,    3,    5,    3,    0,    9,    0,
    4,    0,    4,    0,    4,    0,    5,    0,    4,    3,
    8,    0,    2,    3,    4,    3,    1,    1,    3,    1,
    3,    3,    3,    3,    3,    3,    3,    3,    3,    3,
    3,    3,    3,    3,    3,    3,    3,    3,    5,    3,
    2,    5,    3,    6,    1,    2,    3,    3,    3,    3,
    3,    3,    3,    3,    3,    3,    3,    3,    3,    3,
    3,    3,    3,    5,    3,    2,    5,    3,    6,    1,
    2,    0,    2,    2,    3,    3,    2,    2,    2,    2,
    2,    2,    2,    2,    2,    2,    2,    4,    3,    4,
    4,    3,    4,    4,    3,    4,    4,    3,    4,    4,
    1,    2,    3,    3,    1,    3,    1,    1,    1,    1,
    1,    1,    2,    3,    4,    2,    4,    3,    3,    3,
    4,    4,    5,    5,    6,    6,    4,    4,    1,    1,
    2,    1,    2,    2,    4,    1,    1,    1,    2,    2,
    2,    2,    2,    0,    5,    1,    5,    3,    1,    1,
    0,    0,    1,    2,    1,    1,    2,    2,    2,    2,
    1,    3,    2,    3,    1,
};

static const YYINT yydefred[717] = {                         0,
    3,    0,    0,    0,  396,    0,    0,    0,    2,    5,
    0,    0,   60,  178,    0,  380,    0,  379,   66,    0,
    7,    0,    0,    1,   21,   20,   19,   18,    0,    0,
   67,   65,  132,   64,  193,    0,  175,    0,    0,    0,
    0,    0,    0,    6,    0,   87,  127,   85,   84,    0,
    0,  128,    0,    0,    0,    0,    0,  171,  162,  163,
  148,  149,  146,  147,  156,  157,  151,  150,  158,  159,
  166,  172,  165,  155,  153,  154,  152,  164,  387,  173,
  145,    0,    0,  388,  144,  143,  407,  409,    0,   55,
    0,  124,  112,    0,    0,  413,    4,    0,    0,  408,
    0,    0,    0,    0,   54,    0,   68,   72,   71,   70,
   51,    0,    0,    0,    0,    0,    0,  415,    0,   24,
    0,  200,  184,    0,  177,   63,  176,    0,  195,    0,
    0,  199,  186,    0,    0,  381,    0,    0,    0,    0,
   89,   86,    0,    0,  160,  161,  389,    0,  391,  390,
  142,  194,    0,    0,    0,    0,  362,  386,    0,    0,
    0,    0,    0,    0,  382,  360,  358,  359,  361,  357,
    0,    0,    0,    0,   61,    0,    0,    0,  351,  355,
    0,   82,    0,    0,    0,   75,    0,    0,    0,    0,
    0,    8,    0,    0,    0,    0,    0,   46,    0,   53,
   49,    0,  108,    0,  139,    0,    0,  134,  131,    0,
  133,  179,    0,    0,    0,    0,   43,    0,    0,   62,
    0,    0,  268,    0,    0,  399,  400,    0,    0,    0,
  179,    0,    0,    0,    0,  412,  201,    0,    0,    0,
   92,    0,  170,  168,  218,    0,    0,    0,    0,    0,
  323,  324,    0,  384,  383,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   69,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  327,    0,    0,  352,    0,
   56,   73,    0,   59,    0,    0,  129,    0,    0,  119,
  130,    0,  117,  125,    0,    0,  378,    0,   52,    0,
    0,    0,  113,  140,  136,  135,    0,    0,  414,    0,
   23,   31,   32,    0,  202,    0,    0,    0,    0,  187,
    0,  403,    0,  196,   58,    0,    0,    0,    0,  190,
   22,    0,    0,   88,    0,    0,    0,    0,    0,    0,
    0,    0,  325,  326,    0,    0,   80,   79,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  315,    0,    0,
    0,    0,    0,  339,    0,  342,    0,    0,  345,  348,
    0,  354,  353,    0,   74,    0,    0,    0,  356,    0,
  121,    0,  120,    0,    0,    0,    0,    0,   95,    0,
   50,   27,   28,    0,    0,  141,  180,    0,  271,   36,
    0,    0,  203,  394,  206,  207,    0,  269,  404,  398,
  179,    0,    0,    0,    0,   93,   90,    0,    0,  211,
    0,  371,    0,    0,   77,    0,  377,  338,  366,  363,
    0,    0,  341,  340,    0,  344,  343,  347,  346,  350,
  349,  372,    0,    0,  385,  214,  123,  122,  118,    0,
    0,    0,   97,   99,    0,    0,    0,    9,    0,    0,
   33,  114,    0,    0,    0,   30,    0,  208,    0,  188,
  189,  192,    0,    0,  373,  374,    0,    0,    0,    0,
    0,  368,  364,  370,  369,    0,  126,    0,  101,  102,
    0,    0,   94,   26,    0,  182,    0,    0,    0,   39,
    0,    0,  227,  219,  395,    0,  375,  376,  365,  367,
  216,  215,  103,   14,   13,   12,   11,    0,   10,    0,
  181,    0,    0,    0,    0,  228,    0,   15,   34,  183,
   41,   40,    0,  226,  220,  221,    0,   42,    0,  230,
  256,  231,    0,    0,  233,    0,    0,    0,    0,  250,
    0,  239,    0,    0,    0,    0,    0,    0,    0,  243,
  242,  244,  222,  236,    0,    0,    0,    0,  258,    0,
    0,  223,  248,  232,    0,  223,    0,    0,  223,  252,
    0,    0,  262,    0,  254,    0,  238,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  223,
    0,    0,  223,    0,    0,  240,  223,  247,  223,  241,
    0,    0,  223,    0,    0,  237,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  290,  235,  223,  259,    0,    0,
    0,  224,  223,  251,  253,    0,  263,    0,  255,    0,
    0,  257,    0,  234,    0,  246,    0,    0,    0,    0,
    0,    0,    0,    0,  264,    0,    0,    0,    0,  266,
    0,  223,  223,  265,  261,  249,
};

static const YYINT yydgoto[114] = {                         23,
   24,   25,   26,   27,  121,  431,  529,  530,  217,  122,
   29,  176,   31,   32,  240,  241,   94,  310,   50,   33,
   34,  115,  209,  111,  112,   35,   36,  223,  557,  566,
  567,  496,  593,  594,  224,  225,  216,  595,  178,  179,
  180,  408,  181,  149,   81,   82,  337,  486,  226,  227,
  123,  228,  358,  252,  182,  270,  303,  606,   37,  196,
  396,  184,   40,  197,   53,  549,  651,  687,   85,  343,
  492,  483,  698,  190,  312,  313,  328,  134,  527,  186,
  187,   44,   98,  418,  316,  522,  221,  424,  334,  525,
  494,  318,  321,  191,  304,  140,  242,  419,  352,  425,
  323,  534,  602,  617,  618,  643,  608,  649,  653,  598,
  640,  188,  497,
};

static const YYINT yysindex[717] = {                      1700,
    0,    2,  860, 1054,    0, -110,  -65,   -1,    0,    0,
   29,   63,    0,    0, 1015,    0,   30,    0,    0,   37,
    0,   63,    0,    0,    0,    0,    0,    0,  679, 4091,
    0,    0,    0,    0,    0, 1095,    0,  663,   99,   63,
  733,  120, 1646,    0,  105,    0,    0,    0,    0,  139,
  904,    0,   82,  203,  270,  295,  313,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0, 1581,  130,    0,    0,    0,    0,    0,  231,    0,
 2016,    0,    0,  308,   63,    0,    0,  310, 2016,    0,
  748,  130,  733, 2177,    0,  -11,    0,    0,    0,    0,
    0,  -23,  669,  733, 3733,  349, 2177,    0, 2107,    0,
  407,    0,    0, 1925,    0,    0,    0,  351,    0, 2016,
 2311,    0,    0,  407,  306,    0, 1025,  733,  371,  363,
    0,    0,  405,  430,    0,    0,    0,   55,    0,    0,
    0,    0, 4617, 2123, 1054, 4885,    0,    0, 4885, 4885,
 4885, 4885, 4885, 4885,    0,    0,    0,    0,    0,    0,
 4885,  438, 4885,   80,    0, 2925, 2877,  885,    0,    0,
 4885,    0,  503,   67,  441,    0,   68, 2016, 1083,  449,
 2016,    0,   68,  438, 7610,  -36,  441,    0, 4090,    0,
    0,  407,    0,  442,    0,  461,  465,    0,    0,   99,
    0,    0, 6771, 2107,  474, 7610,    0, 4091,  663,    0,
  395, 1790,    0,  443,  488,    0,    0,  -15,  231,   68,
    0, 4949, 5019, 1646,  510,    0,    0,  476,    0,  209,
    0,  363,    0,    0,    0,  383, 2177,  541,  885,  680,
    0,    0, 1925,    0,    0,  885, 5083,  885,  885,  885,
  885,  885,  885,  885, 2107,  885, 4681, 2123,  114, 1030,
    0,  109, 2177, 2177, 2177, 2177, 2177, 2177, 2177, 2177,
 2177, 2177, 2177, 2177, 2177, 2177, 2177, 2177, 2177, 2177,
 2177, 2107, 2177,  576, 1632,    0,  885,  869,    0, 2107,
    0,    0, 2016,    0, 4449, 6526,    0, 1658, 1699,    0,
    0,  498,    0,    0,   68,  994,    0, 2177,    0,  669,
 2107,  494,    0,    0,    0,    0,  499,   75,    0,  529,
    0,    0,    0,  512,    0, 2043,  902,  404, 2107,    0,
  666,    0,  552,    0,    0,   75,  573,  581, 1144,    0,
    0,  554,  363,    0,  259, 6817,   55,  309,  586,  588,
 2177,  885,    0,    0, 1925, 1030,    0,    0, 1185,  431,
 1158,  -32,  -32,   -9,   -9, 3952, 1997, 4538, 2734, 7337,
 7610, 7610, 7610,   -9,  824,  431,   21,    0,  597, 6862,
 1267,  501,  205,    0,   79,    0,   40,  507,    0,    0,
  156,    0,    0,  607,    0,  435,  424,   36,    0,  590,
    0,  590,    0, 1083,  308, 1381, 4483,  149,    0, 7610,
    0,    0,    0,  512,  553,    0,    0,  618,    0,    0,
  610, 1030,    0,    0,    0,    0, 1213,    0,    0,    0,
    0,  646,  646,  646, 2177,    0,    0, 4885,  309,    0,
 2123,    0, 6914,  657,    0, 2177,    0,    0,    0,    0,
  670, 1311,    0,    0, 2169,    0,    0,    0,    0,    0,
    0,    0,  364,  309,    0,    0,    0,    0,    0,  629,
    0,   63,    0,    0,  343, 1030,  876,    0,  994,  610,
    0,    0,  379,  357,  -31,    0, 2107,    0,   75,    0,
    0,    0, 7610,  885,    0,    0,  407, 4885, 2123, 2616,
 2189,    0,    0,    0,    0, 1030,    0, 1030,    0,    0,
 1363, 4293,    0,    0,  512,    0,   65, 2107,  652,    0,
  693,  664,    0,    0,    0,  885,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  674,    0,  610,
    0,  379,  708,  357, 2107,    0,  -27,    0,    0,    0,
    0,    0,  719,    0,    0,    0, 1524,    0,  730,    0,
    0,    0,  713, 4751,    0,  758,  721,  771, 2177,    0,
  771,    0,  762,   13, 4885,  610,  803,  777,  258,    0,
    0,    0,    0,    0, 7565,  885,  768, 2177,    0, 2177,
  885,    0,    0,    0, 2177,    0, 7383,  771,    0,    0,
  610,  885,    0,  407,    0, 4815,    0,  783, 2241, 2241,
 2241, 2241, 2241, 2241, 2241, 2241, 2241, 2241, 2241, 2241,
 2241, 2241, 2241, 2241, 2241, 2241, 2241,  815, 7428,    0,
 6959,  821,    0, 6573,  849,    0,    0,    0,    0,    0,
  767, 1790,    0, 2177,  885,    0,  686, 1942,   52,   52,
    5,    5, 4385, 4829, 4695, 3018, 7474, 7656, 7656, 7656,
    5, 1147,  686,   58,    0,    0,    0,    0, 4885,  771,
 2177,    0,    0,    0,    0,  829,    0,  655,    0, 7005,
 2241,    0,  885,    0, 7519,    0,  718,  610,  407, 2177,
 4885, 7675, 2177,  835,    0, 1790, 6618,  885, 6664,    0,
 1398,    0,    0,    0,    0,    0,
};

static const YYINT yyrindex[717] = {                         0,
    0,    0,    0,    0,    0,    0, 2387, 2533,    0,    0,
 1086,    0,    0,    0,    0,    0, 2679,    0,    0, 4115,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0, 2059,    0,  314,    0, 2825,
 4307,    0,    0,    0,    0,    0,    0,    0,    0, 3117,
    0,    0,    0, 3487, 3563,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0, 5243,    0,    0,    0,    0,    0,    0,    0,    0,
 7693,    0,    0, 3191, 3265,    0,    0,    0, 7693,    0,
 2430,  314, 2576, 2458,    0, 4025,    0,    0,    0,    0,
    0,    0,  672, 4351,    0, 1834, 7019,    0, 2458,    0,
  372,    0,    0, 6679,    0,    0,    0, 1086,    0, 7693,
 5281,    0,    0,   -5, 2971,    0,    0,    0,    0,  394,
    0,    0,    0,    0,    0,    0,    0, 5144,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0, 3790,    0,   39,    0,  550,  275, 5751,    0,    0,
    0,    0,   87,    0, 3679,    0,    0, 5182,    0,    0,
 7693,    0,    0,    0,  570,   87,    0,    0,    0,    0,
    0,  372,    0,    0,    0, 3774, 3877,    0,    0,    0,
    0,    0,    0, 4616,    0,  796,    0,    0,    0,    0,
  204,  792,    0,   27,    0,    0,    0,  836,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  531,    0,
    0,  394,    0,    0,    0,    0, 7019,   15, 5805, 5410,
    0,    0, 5182,    0,    0, 5850, 5706, 5904, 5949, 6003,
 6048, 6102, 6147, 6201, 5182, 6246,    0,    0,  519,  304,
    0,  630, 6481, 6481, 6481, 6481, 6481, 6481, 6481, 6481,
 6481, 6481, 5319, 6481, 6481, 6481, 6481, 6481, 6481, 6481,
 6481, 5182, 7019,    0,    0,    0, 6300,    0,    0, 5182,
    0,    0, 7693,    0,  725,    0,    0,    0,    0,    0,
    0,  807,    0,    0,    0,  311,    0, 2458,    0,  594,
 2458,  389,    0,    0,    0,    0, 2777, 3924,    0,    0,
    0,    0,    0,  839,    0,  457,   26,  778, 5080,    0,
  142,    0,    0,    0,    0, 3945, 5650, 5650,    0,    0,
    0,    0,  394,    0,    0,    0, 5410, 5466,    0,    0,
 7019, 6345,    0,    0, 5182,  299,    0,    0,    0, 7739,
 3812, 7837, 7892, 7964, 7999, 5021, 2466, 5597,  985,    0,
  278,  504,  563, 8034, 3050, 7794, 7929,    0,    0,    0,
    0,    0,    0,    0,  163,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  725,  725,    0,    0,    0,
    0,    0,    0,    0, 3339,    0,    0,    0,    0,  606,
    0,    0,    0,  839, 3413,    0,    0,    0,    0,    0,
    0,  598,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0, 4616,    0,    0,    0, 5533,    0,
    0,    0,    0,    0,    0, 6481,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  868,    0,    0,    0,    0,    0,    0,
 4156, 4159,    0,    0,    0,  400,    0,    0,    0,    0,
    0,    0,    0,    0, 1413,    0, 6718,    0, 3637,    0,
    0,    0,  417, 6399,    0,    0,    0,    0,    0, 2333,
    0,    0,    0,    0,    0,    0,    0,  302,    0,    0,
    0,    0,    0,    0,  839,    0,    0, 5182,  840,    0,
    0,    0,    0,    0,    0, 6444,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0, 4441,    0,    0,
    0,    0,    0,    0, 5182,    0, 1635,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0, 2458,    0,
    0,    0, 5589, 4372,    0,    0,    0, 4233,   39,    0,
    0,    0,    0,    0,  842, 7064,    0, 5319,    0, 7019,
 7110,    0,    0,    0, 5182,    0,    0,    0,    0,    0,
    0, 7155,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0, 1302,    0,    0,    0,    0,    0,
  951,  388,    0, 7019, 7201,    0, 8101, 2711, 8189, 8230,
 8300, 8329, 2565, 2424, 2346, 1872,    0,  580,  620,  865,
 8358, 1696, 8146, 8265,    0,    0,    0,    0,    0,    0,
 2458,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0, 7246,    0,    0,    0, 1406,    0,    0, 5182,
    0,  924, 5182,    0,    0,  778,    0, 7292,    0,    0,
    0,    0,    0,    0,    0,    0,
};

static const YYINT yygindex[114] = {                         0,
    0, -115, -103, -106,  806, -416,    0,  368,    3,  288,
  177,   73,    0,    8,  682,  578,    7, -280,    0,    0,
  -16,    0,    0,  739,    0,  -19,   -3, -117,    0, 4345,
    0, -433,    0,    0,    0, -124,  617, 7508,  654, -151,
    0,  385, -135,  793,  788,    0, -321,   -8,  604,    0,
  262,    0,  589, -243,    0,  181,    0, -311,  -14,    1,
  658,   50,  319,  233,   22,    0,    0,    0,  810,    0,
    0,    0,    0,  547,    0,  555, -225,  271,    0,  665,
  -76,  867,    0,    0,    0,    0,  784,    0,    0,    0,
    0,    0,    0,  280, -158,    0,    0,  500,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  -73,    0,
};

static const YYINT yytable[8451] = {                        205,
   38,  215,   28,   51,   83,  346,  235,  490,  207,   49,
  298,  206,   86,  110,  432,   83,  437,  273,  251,  129,
  257,   42,  193,  127,  364,  101,  113,  411,  413,  102,
  102,   87,  299,   89,  317,  401,  127,  109,  380,  137,
  273,   45,  533,  102,  275,  276,  564,  199,  200,   39,
   42,   42,  265,  230,  619,  341,  524,  198,  621,  622,
  289,  380,  380,  155,   42,  401,  393,  267,  127,  152,
  273,  345,   30,   89,  275,  276,  475,  117,   39,   39,
  253,  118,   83,  289,  290,  380,  125,  127,  267,  330,
  155,  183,   39,  611,  380,   88,  393,  635,  636,  183,
  267,  619,  268,   42,    7,  551,    8,  619,  550,   97,
  174,  621,  622,  289,  315,   38,  559,  208,  380,  165,
   90,  219,    4,   16,  183,  465,   96,  301,  359,  477,
  183,  478,  363,  592,  219,  552,   42,  380,  302,  342,
  360,   18,  394,  399,  635,    6,  165,  291,    5,  401,
  635,  100,  613,    5,  219,   83,  415,  565,    7,  110,
    8,  380,  466,    7,  210,    8,  174,  389,  127,  246,
  291,  427,   22,  428,  380,  404,   83,  650,  128,  155,
  393,  127,  401,  109,  637,  139,  174,   30,  183,   83,
  327,  183,  380,  218,  365,  320,  222,   42,  380,  102,
  291,  110,  219,  421,  127,  110,  222,  506,  488,  344,
  100,  141,  401,  531,  320,  499,  380,  380,  102,  489,
   42,  438,   83,  380,  532,  109,  250,   17,  155,  109,
  349,  637,   41,  110,  102,  165,   84,  637,   16,   42,
  454,  464,  174,   42,  143,  467,  469,  380,   39,  471,
   83,  462,  125,  183,    4,   42,   18,  109,  148,  136,
  305,  103,  114,   22,  705,  538,  616,   39,  219,  609,
   43,   42,   29,  531,  218,  138,   29,    6,  470,  353,
  268,   17,  354,   39,  165,  174,   17,   22,  110,   16,
  246,   91,  135,  246,  395,  395,  647,  136,   83,   43,
   43,   99,  133,  183,  403,   83,  124,   18,   83,   83,
  151,  144,  109,   43,  150,  505,  219,   22,  297,  130,
  297,   52,   22,  185,  148,  305,   42,  463,  132,  353,
  688,  185,  447,   95,   83,  145,   83,  174,   22,   78,
  250,  219,  100,  397,  401,   83,  297,   41,  297,  297,
  117,  297,  269,  220,  118,  146,  185,   42,   78,  246,
  174,  100,  185,   81,  133,  183,  220,  192,  694,   78,
   96,  124,  100,  537,   81,  133,  189,  507,  246,  535,
  127,   96,    5,  124,  711,   43,  220,   84,  417,  212,
  132,   83,    7,  174,    8,  229,  528,  460,  336,  133,
  110,  132,  236,  553,  516,  117,  544,  124,  271,  118,
   83,  238,   83,  222,   83,  546,   83,   83,  545,    3,
  185,  311,  484,  185,  109,  132,  357,  246,  246,  204,
  563,  138,  297,  204,  220,  507,  307,  305,   42,  100,
   35,   12,  239,    5,   35,  269,  272,  243,  269,  366,
  114,  219,  369,    7,  271,    8,  204,   25,   47,   98,
  590,   25,   83,  406,  107,   83,  138,  107,  513,   43,
   98,  515,  244,    7,  406,    8,  518,  265,  521,   14,
  300,  407,  271,  335,    7,  185,    8,  106,   43,  219,
  106,   12,  338,   83,   83,   35,   35,  204,  204,  526,
  220,   14,  204,   13,   43,  548,  246,  219,  246,  219,
  324,   83,  336,  339,  336,   17,   16,  540,  332,  333,
  100,  314,   38,  250,  547,  204,  204,  204,  340,   14,
  155,  368,  325,  357,   18,  185,  326,  271,   16,  272,
  311,  311,  272,   42,  313,  331,  313,  351,  220,  298,
  350,   22,   83,  462,   83,  135,   18,  367,  560,   76,
   76,  417,   15,  268,   76,   22,   16,  183,  414,  591,
  426,   39,  313,  220,  313,  313,   17,  313,   76,  305,
  430,  250,  407,  407,   18,   19,  165,   22,  175,   76,
  124,   76,  441,  485,   30,   76,   17,  185,  436,  155,
  105,  104,  429,  312,  104,  312,  338,   17,  338,   76,
  291,  204,   22,  442,  219,   22,   52,  422,  423,  124,
   76,  443,  391,  445,  435,  125,  451,  368,  452,  468,
  368,  312,   22,  312,  312,  110,  312,  457,  205,   30,
   48,   48,  311,   22,  311,  450,  311,  472,  272,  271,
  272,  272,   83,  367,  433,  165,  367,  493,  313,  109,
  461,  485,   16,  485,   45,   45,  205,  205,  205,  307,
   76,   76,  392,   42,   12,   76,   47,   47,    3,  491,
   18,  126,  495,  220,   44,    5,  652,  487,  288,  110,
  288,  288,    3,  436,    5,  476,  117,  509,  436,  219,
  118,  517,    4,  500,  501,  502,   83,  177,  116,   52,
  117,   22,   14,  109,  118,  177,  511,  312,    5,  435,
  195,  220,  554,  700,  435,    6,  311,   42,    7,    7,
    8,    8,  555,  213,  482,   16,  450,  556,  201,  220,
   44,  220,   45,   45,   44,  558,  177,  520,  561,   16,
   12,  393,  205,   18,   41,  487,   44,  487,   11,  568,
  476,  476,   13,   12,   12,  212,  212,   18,   44,  597,
  212,  706,  131,  519,  117,  100,  107,  542,  118,  520,
   52,  599,  520,   52,   22,  125,  311,  116,   14,  117,
  473,  474,   43,  118,   44,   44,   44,  603,   22,  185,
  604,   14,   14,  541,  306,  519,  249,  177,  519,  256,
  605,   52,  258,  259,  260,  261,  262,  263,  204,  204,
  439,   15,   16,  204,  264,   16,  266,   44,  336,   52,
  610,   44,  204,  204,  297,   15,  270,  204,   16,   16,
   18,  126,  614,   18,   19,  615,  220,  175,  638,   44,
   44,   17,   17,   44,  656,  676,   18,   18,  108,  680,
  683,  204,  204,  356,  686,  637,  270,  270,  697,  270,
   52,   22,  704,  273,   22,  710,  402,  275,  276,  115,
   44,  277,  336,  278,  271,  260,  261,   22,   22,  370,
  371,  372,  373,  374,  375,  376,  377,  378,  379,  380,
  381,  382,  383,  384,  385,  386,  387,  388,  213,  390,
  297,   38,   37,  229,  287,    5,  289,  290,  202,  177,
  362,  562,  338,  355,  292,    7,  293,    8,  294,  295,
  446,  220,   46,  287,  420,  287,  287,  319,  271,   47,
  245,    5,  254,  117,  440,  449,  204,  118,   47,  436,
  270,  260,  400,  260,  260,  484,  699,  260,  260,  260,
  260,  480,  260,  260,  255,  402,  260,  405,  479,  260,
  260,  434,  436,  260,  260,  435,  338,  453,  260,  296,
  260,  211,   14,  260,  260,  322,    0,    0,  523,  260,
  260,   14,  289,  289,  289,  289,  260,  260,  435,    0,
  260,    0,  260,  291,  260,  260,    3,    0,  260,    0,
  260,    0,    0,  289,  260,  260,  260,  260,  260,   16,
  260,  260,  260,  260,  260,  311,  125,  311,   16,    0,
  260,  260,  260,  260,  260,  260,  260,   18,   48,    0,
  260,  260,  260,  260,  260,  260,   18,  260,   17,  260,
  260,  311,  311,  311,  311,  311,  311,    0,  311,    0,
    0,  503,   54,   16,  116,  237,  117,    0,   22,    5,
  118,  117,  510,  260,  311,  118,   55,   22,   12,    0,
    0,   18,  142,    0,   22,    0,    0,   92,    0,    0,
   13,    0,    0,   56,   47,   57,    0,   58,  142,   59,
   60,  504,    0,   61,    0,   62,  260,   63,   64,    0,
  260,   65,   22,   66,    0,    0,   14,   67,   68,   69,
   70,    0,    0,   71,   72,  142,  142,  142,  260,  260,
  260,  142,  260,    0,  116,  260,  117,   14,   12,  311,
  118,    0,    0,   73,   74,   75,   76,   77,   78,  416,
   79,    0,    0,   16,  142,  142,  142,  142,  142,  260,
    0,  536,  307,    0,  119,  260,  120,   12,    0,    0,
  142,   18,   19,    0,   16,  175,   14,    0,    0,  308,
    0,    0,  142,  116,  444,  117,    0,    0,    0,  118,
    0,    0,   18,   93,    0,  607,  619,    0,    0,    0,
  621,  622,   22,    0,  623,   14,  624,  273,  142,  142,
  142,  275,  276,   16,  639,  277,  641,  278,    0,    0,
  596,  644,    0,   22,    5,  455,  117,  601,    0,    0,
  118,   18,    0,   80,    0,    0,    0,  633,  612,  635,
  636,  142,   16,    0,    0,  142,    0,    0,  287,  288,
  289,  290,    5,  498,  117,    0,    0,  309,  118,    0,
   18,    0,   22,  142,  142,    0,    0,  142,    0,  655,
  690,    0,  596,  596,  596,  596,  596,  596,  596,  596,
  596,  596,  596,  596,  596,  596,  596,  596,  596,  596,
  596,   22,    0,    0,  142,    0,    0,  695,    0,    0,
    0,    0,  245,    0,  245,  245,    0,    0,  245,  245,
  245,  245,    0,    0,  245,    0,  707,  245,    0,  709,
  245,  245,    0,    0,  245,  245,  637,    0,    0,  245,
    0,  245,  693,    0,  245,  245,    0,  291,    0,    0,
  245,  245,    0,    0,  596,    0,   47,  245,  245,    0,
    0,  245,    0,  245,  708,  245,  245,    0,    0,  245,
    0,  245,    0,  459,    0,  245,  245,  245,  245,  245,
    0,  245,  245,  245,  245,  245,    0,    0,    0,    0,
    0,  245,  245,  245,  245,  245,  245,  245,    0,   14,
   47,  245,  245,  245,  245,  245,  245,    0,  245,    0,
  245,  245,    5,  543,  117,    0,    0,  512,  118,    0,
    0,    0,    0,  225,    0,  225,  225,    0,  396,  225,
  225,  225,  225,    0,  245,  225,   16,    0,  225,    0,
    0,  225,  225,   14,    0,  225,  225,    5,  714,  117,
  225,    0,  225,  118,   18,  225,  225,    0,    0,    0,
    0,  225,  225,   92,    0,    0,    0,  245,  225,  225,
  481,  245,  225,    0,  225,    0,  225,  225,    0,    0,
   16,    0,    0,    0,    0,   22,    0,    0,    0,  245,
  245,  245,    0,  245,  225,  225,  245,    0,   18,    0,
  396,    0,  225,  225,  225,  225,  225,  225,  225,    0,
    0,    0,  396,   14,    0,    0,    0,  225,    0,  225,
  245,  225,  225,    0,    0,    0,  245,    0,    0,   22,
    0,    0,    0,    0,  569,    0,  570,  571,  396,    0,
  572,  573,  574,  575,    0,  225,    3,    0,    0,  576,
   16,    0,  577,  578,    0,    0,  154,  155,    0,    0,
    0,  579,    0,  156,    0,    0,  580,  157,   18,   93,
    0,  396,  581,  158,    0,  396,    0,    0,  225,  159,
  160,    0,  225,  161,    0,  162,    0,  163,  164,    0,
    0,    0,    0,  396,  396,    0,    0,  396,    0,   22,
  225,  225,    0,    0,  225,  582,  495,  225,    0,    0,
    0,    0,    0,  583,  166,  167,  168,  169,   12,  170,
    0,    0,    0,    0,  396,    0,    0,    0,  171,    0,
  584,  225,  585,  586,    0,    0,    0,  225,    0,    0,
    7,    0,    8,    0,    0,  223,    0,  223,  223,    0,
    0,  223,  223,  223,  223,    0,  588,  223,    0,    0,
  223,    0,    0,  223,  223,  155,    0,  223,  223,    0,
    0,    0,  223,    0,  223,   12,    0,  223,  223,    4,
    0,    0,    0,  223,  223,    0,    0,  147,  391,   15,
  223,  223,    0,  589,  223,    5,  223,    0,  223,  223,
    0,    0,    6,    0,    0,    7,    0,    8,    0,    1,
    2,   18,   19,   14,    0,  175,  223,  223,    0,    0,
    0,  165,    3,    0,  223,  223,  223,  223,  223,  223,
  223,    0,    0,    4,    0,   11,    0,    0,  392,  223,
   12,  223,   22,  223,  223,    0,    0,  307,  587,    5,
   16,    0,   12,    0,    0,    0,    6,  280,    0,    7,
    0,    8,    0,   17,    0,    0,    0,  223,   18,  280,
  280,  280,  280,  280,  280,  280,  280,  280,   14,    0,
    0,    9,    0,   10,    0,    0,    0,    0,  307,   11,
   14,    0,    0,   12,   12,  280,    0,  280,    0,   22,
  223,   16,    0,    0,  223,  412,   13,    0,    0,    0,
    0,    0,    3,    0,    0,   16,    0,  398,    0,   18,
    0,    0,  223,  223,    0,    0,  223,   16,   17,    0,
    0,   14,   14,   18,    0,    0,    0,    0,    0,    5,
    0,    0,  410,    0,    0,   18,    0,    0,    0,    7,
   22,    8,  396,  223,    0,    0,  396,    0,    0,  223,
    0,    0,    0,    0,   22,   15,  396,  396,   16,   16,
    0,    0,    0,  396,    0,    0,   22,  396,    0,  335,
    0,    0,   17,  396,   12,    0,   18,   18,   19,  396,
  396,   20,    0,  396,   21,  396,  107,  396,  396,    0,
    0,  396,    0,  396,    0,    0,    0,  396,  396,  396,
  396,  396,    0,  396,  396,    0,  396,   22,   22,    0,
    0,    0,   14,  396,  396,  396,  396,  396,  396,  396,
    0,    0,    0,  396,  396,  396,  396,  396,  396,    0,
  396,    0,  396,  153,    0,    0,    0,    3,  286,  286,
  286,  286,  286,  286,    0,   15,    0,  154,  155,   16,
    0,    0,    0,    0,  156,    0,  396,    0,  157,    0,
    0,  286,   17,    0,  158,    0,    0,   18,  108,    0,
  159,  160,    0,    0,  161,    0,  162,    0,  163,  164,
    0,    0,    0,    0,    0,    0,    0,    0,  396,  396,
    0,  619,    0,  396,    0,  621,  622,  214,   22,  623,
    0,  624,    0,    0,  165,  166,  167,  168,  169,   12,
  170,  396,  396,  396,    0,  396,    0,    0,    0,  171,
    0,  172,    0,  173,  153,    0,    0,    0,    3,    0,
    0,    0,  633,  634,  635,  636,    0,    0,  154,  155,
    0,    0,  396,    0,    0,  156,  273,   14,  274,  157,
  275,  276,    0,    0,  277,  158,  278,    0,    0,    0,
  279,  159,  160,    0,    0,  161,    0,  162,    0,  163,
  164,   44,    0,    0,    0,    0,    0,    0,    0,    0,
   15,    0,    5,    0,  174,    0,    0,  287,  288,  289,
  290,    0,    7,    0,    8,  165,  166,  167,  168,  169,
   12,  170,   18,   19,    0,    0,  175,    0,    0,    0,
  171,    0,  172,    0,  173,  153,    0,    0,    0,    0,
    0,  637,  335,    0,    0,    0,    0,   44,    0,  154,
  155,   44,    0,   22,    0,    3,  156,    0,   14,  100,
  157,    0,    0,   44,    0,    0,  158,    0,    0,    0,
    0,    0,  159,  160,    0,   44,  161,    0,  162,    0,
  163,  164,  158,    0,    0,   14,    0,    0,    0,    0,
    0,   15,    0,    0,    0,  174,  291,    0,    0,  214,
    0,   44,   44,   44,    0,  153,  165,  166,  167,  168,
  169,   12,  170,   18,   19,    0,    0,  175,    0,  154,
  155,  171,   16,  194,    0,  173,  156,   12,    0,    0,
  157,    0,    0,    0,   44,   17,  158,    0,   44,   13,
   18,    0,  159,  160,   22,    0,  161,    0,  162,   14,
  163,  164,    0,    0,    0,    0,   44,   44,    0,    0,
   44,    0,    0,    0,    0,   14,    0,    0,   47,  574,
    0,   22,    0,    0,    0,    0,  165,  166,  167,  168,
  169,   12,  170,  154,  155,  514,  174,   44,   47,    0,
  156,  171,    0,  194,  157,  173,    0,    0,   15,    0,
  158,    0,   16,    0,   18,  539,  159,  160,    0,    0,
  161,   14,  162,    0,  163,  164,    0,    0,    0,   14,
   18,   19,    0,    0,  175,    0,    0,    0,    0,    0,
    0,   14,    0,    0,    0,   22,    0,    0,    0,  153,
  165,  166,  167,  168,  169,   12,  170,    0,   16,    0,
    0,   22,    0,  154,  155,  171,  174,  194,    0,  585,
  156,    0,    0,    0,  157,    0,   18,    0,   16,    0,
  158,  231,    0,    0,   18,    0,  159,  160,    0,    0,
  232,    0,  233,   14,  163,  164,   18,    0,    0,    0,
    0,    0,    0,  314,    0,  314,    0,   22,    0,    0,
    0,    0,    0,  214,    0,   22,    0,    0,    0,    0,
  165,  166,  167,  168,  169,   12,  170,   22,    0,  405,
  589,  314,  314,  314,  314,  171,  314,    0,    0,  173,
  405,  285,  285,  285,  285,  285,  285,  285,   18,    0,
    0,    0,  314,    0,    0,    0,  405,  405,  405,  405,
  405,  405,  405,  405,    0,  285,  405,    0,  405,    0,
  405,  405,  197,    0,  405,    0,  405,    0,    0,   22,
  405,  405,  405,  405,  405,  405,  405,  405,  405,  405,
  405,    0,    0,    0,    0,    0,  405,    0,    0,    0,
  197,  405,    0,    0,    0,    0,  405,  405,  405,  405,
  405,  405,    0,  234,    0,    0,    0,  314,  277,  277,
  277,  277,  277,  277,  277,  277,    0,    0,  197,  197,
  197,  197,  197,    0,    0,    0,  302,    0,  302,  405,
  405,  405,    0,  277,  197,  322,    0,  322,    0,   22,
    0,  322,  322,  322,  322,  322,  197,  322,  322,  322,
  302,  302,  302,  302,  302,  302,  302,  302,    0,  302,
    0,  405,  405,    0,    0,  406,  405,  322,  322,  322,
  322,  322,  197,  197,  197,  302,  406,    0,    0,  405,
    0,    0,    0,    0,  405,  405,  405,    0,  405,    0,
    0,    0,  406,  406,  406,  406,  406,  406,  406,  406,
    0,    0,  406,    0,  406,  197,  406,  406,  198,  197,
  406,    0,  406,    0,    0,  405,  406,  406,  406,  406,
  406,  406,  406,  406,  406,  406,  406,  197,  197,    0,
    0,  197,  406,    0,    0,    0,  198,  406,    0,    0,
  302,    0,  406,  406,  406,  406,  406,  406,  278,  278,
  278,  278,  278,  278,  278,  278,  278,  322,  197,    0,
    0,    0,    0,    0,  198,  198,  198,  198,  198,    0,
    0,    0,    0,    0,  278,  406,  406,  406,    0,    0,
  198,    0,    0,    0,    0,  273,    0,  274,    0,  275,
  276,    0,  198,  277,    0,  278,    0,    0,    0,  279,
  280,  281,  282,  283,    0,    0,    0,  406,  406,    0,
    0,  411,  406,    0,    0,    0,    0,    0,  198,  198,
  198,    0,  411,    0,    0,  406,  287,  288,  289,  290,
  406,  406,  406,    0,  406,    0,    0,    0,  411,  411,
  411,  411,  411,  411,  411,  411,    0,    0,  411,    0,
  411,  198,  411,  411,    0,  198,  411,    0,  411,    0,
    0,  406,  411,  411,  411,  411,  411,  411,  411,  411,
  411,  411,  411,  198,  198,    0,    0,  198,  411,    0,
    0,    0,  276,  411,    0,    0,    0,    0,  411,  411,
  411,  411,  411,  411,  276,  276,  276,  276,  276,  276,
  276,  276,  276,  273,  198,  274,    0,  275,  276,  195,
    0,  277,    0,  278,    0,  291,    0,  279,  280,  281,
  276,  411,  411,  411,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  195,    0,  195,    0,
    0,    0,  195,    0,  287,  288,  289,  290,    0,    0,
    0,    0,    0,  411,  411,    0,    0,   57,  411,    0,
    0,    0,    0,    0,    0,  195,  195,    0,   57,  195,
    0,  411,    0,    0,    0,    0,  411,  411,  411,    0,
  411,  195,    0,    0,   57,   57,   57,   57,   57,   57,
   57,   57,    0,  195,   57,    0,   57,    0,   57,   57,
    0,    0,    0,    0,   57,    0,    0,  411,   57,   57,
   57,   57,   57,   57,   57,   57,   57,   57,   57,  195,
  195,  195,    0,    0,   57,    0,    0,    0,    0,   57,
    0,    0,    0,  291,   57,   57,   57,   57,   57,   57,
    0,   57,    0,    0,    0,    0,  273,    0,  274,    0,
  275,  276,  195,    0,  277,    0,  195,    3,    0,    0,
  279,  280,  281,  282,  283,    0,  284,   57,   57,   57,
    0,    0,    0,    0,  195,  195,    0,    0,  195,    0,
    0,    0,    0,    0,    5,    0,  286,  287,  288,  289,
  290,    0,    0,    0,    7,    0,    8,    0,    0,   57,
   57,    0,    0,  410,   57,  195,    0,    0,    0,    0,
    0,    0,    0,    0,  410,    0,    0,   57,    0,    0,
    0,    0,   57,   57,   57,    0,   57,    0,    0,   12,
  410,  410,  410,  410,  410,  410,  410,  410,    0,    0,
  410,  107,  410,    0,  410,  410,    0,    0,  410,    0,
  410,    0,    0,   57,  410,  410,  410,  410,  410,  410,
  410,  410,  410,  410,  410,    0,    0,   14,    0,    0,
  410,    0,    0,    0,    0,  410,  291,    0,    0,    0,
  410,  410,  410,  410,  410,  410,    0,  619,    0,  620,
    0,  621,  622,    0,    0,  623,    0,  624,    0,    0,
   15,  625,  626,  627,   16,    0,    0,    0,    0,    0,
  305,    0,  305,  410,  410,  410,    0,   17,    0,    0,
    0,  305,   18,  108,    0,    0,    0,    0,  633,  634,
  635,  636,    0,  305,  305,  305,  305,  305,  305,  305,
  305,  305,    0,  305,    0,  410,  410,    0,    0,   91,
  410,    0,    0,   22,    0,    0,    0,    0,    0,  305,
   91,  305,    0,  410,    0,    0,    0,    0,  410,  410,
  410,    0,  410,    0,    0,    0,   91,   91,   91,   91,
   91,   91,   91,   91,    0,    0,   91,    0,   91,    0,
   91,   91,    0,    0,   91,    0,   91,    0,    0,  410,
   91,   91,   91,   91,   91,   91,   91,   91,   91,    0,
   91,    0,    0,    0,    0,    0,   91,  637,    0,    0,
    0,   91,    0,  110,  305,    0,   91,   91,   91,   91,
   91,   91,    0,   91,  110,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  110,  110,  110,  110,  110,  110,  110,  110,    0,   91,
  110,    0,  110,    0,  110,  110,    0,    0,  110,    0,
  110,    0,    0,    0,  110,  110,  110,  110,  110,    0,
  110,  110,  110,  116,  110,    0,    0,    0,    0,    0,
  110,   91,   91,    0,    0,  110,   91,  128,    0,    0,
  110,  110,  110,  110,  110,  110,    0,  110,  128,   91,
    0,    0,    0,    0,   91,   91,   91,    0,    0,    0,
    0,    0,    0,    0,  128,  128,  128,  128,  128,  128,
  128,  128,    0,  110,  128,    0,  128,    0,  128,  128,
    0,    0,    0,    0,  128,   91,    0,    0,  128,  128,
  128,  128,  128,  128,  128,  128,  128,  128,  128,    0,
    0,    0,    0,    0,  128,  110,  110,    0,    0,  128,
  110,  111,    0,    0,  128,  128,  128,  128,  128,  128,
    0,  128,  111,  110,    0,    0,    0,    0,  110,  110,
  110,    0,    0,    0,    0,    0,    0,    0,  111,  111,
  111,  111,  111,  111,  111,  111,    0,  128,  111,    0,
  111,    0,  111,  111,    0,    0,  111,    0,  111,  110,
    0,    0,  111,  111,  111,  111,  111,    0,  111,  111,
  111,  116,  111,    0,    0,    0,    0,    0,  111,  128,
  128,    0,    0,  111,  128,  109,    0,    0,  111,  111,
  111,  111,  111,  111,    0,  111,  109,  128,    0,    0,
    0,    0,  128,  128,  128,    0,    0,    0,    0,    0,
    0,    0,  109,  109,  109,  109,  109,  109,  109,  109,
    0,  111,  109,    0,  109,    0,  109,  109,    0,    0,
  109,    0,  109,  128,    0,    0,  109,  109,  109,  109,
  109,  109,  109,  109,  109,    0,  109,    0,    0,    0,
    0,    0,  109,  111,  111,    0,    0,  109,  111,  169,
    0,    0,  109,  109,  109,  109,  109,  109,    0,  109,
    0,  111,    0,    0,    0,    0,  111,  111,  111,    0,
    0,    0,    0,    0,    0,    0,  169,  169,    0,  169,
  169,  169,  169,    0,    0,  109,  169,    0,  169,    0,
  169,  169,    0,    0,  169,    0,  169,  111,    0,    0,
  169,  169,  169,  169,  169,  169,  169,  169,  169,  169,
  169,    0,    0,    0,    0,    0,    0,  109,  109,    0,
    0,  169,  109,    0,    0,  167,  169,  169,  169,  169,
  169,  169,    0,  169,    0,  109,    0,    0,    0,    0,
  109,  109,  109,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  167,  167,    0,  167,  167,  167,  167,  169,
  169,  169,  167,    0,  167,    0,  167,  167,    0,    0,
  167,  109,  167,    0,    0,    0,  167,  167,  167,  167,
  167,  167,  167,  167,  167,  167,  167,    0,    0,    0,
    0,  169,  169,    0,    0,    0,  169,  167,    0,  397,
    0,    0,  167,  167,  167,  167,  167,  167,    0,  167,
    0,    0,    0,    0,  169,  169,  169,    0,  169,    0,
    0,    0,    0,    0,    0,    0,  397,  397,  397,    0,
    0,    0,  397,    0,    0,  167,  167,  167,    0,    0,
    0,   62,    0,    0,    0,  169,  397,    0,    0,    0,
    0,    0,   62,    0,    0,  397,  397,  397,  397,  397,
    0,    0,    0,    0,    0,    0,    0,  167,  167,   62,
   62,  397,  167,    0,   62,   62,    0,    0,   62,    0,
   62,    0,    0,    0,    0,    0,    0,    0,   62,    0,
  167,  167,  167,    0,  167,    3,    0,   62,   62,   62,
   62,    0,    0,    0,    0,    0,    4,    0,   62,  397,
  397,  397,    0,   62,    0,    0,    0,    0,    0,    0,
    0,  167,    5,    0,    0,   62,    0,    0,    0,    6,
    0,    0,    7,    0,    8,    0,  137,    0,    0,    0,
    0,  397,  397,    0,    0,    0,  397,  137,    0,    0,
    0,   62,   60,    0,    0,    0,  203,    0,    0,    0,
    0,    0,   11,  137,  397,  397,    0,   12,  397,    0,
  137,    0,    0,  137,    0,  137,    0,    0,    0,   13,
   60,   60,    0,   62,   62,   60,    0,    0,   62,   60,
    0,   60,    0,    0,    0,  397,    0,  137,    0,   60,
    0,   62,  301,  137,  301,   14,   62,   62,  137,   60,
   60,    0,    0,  301,    0,    0,    0,    0,    0,   60,
  137,    0,    0,    0,   60,  301,  301,  301,  301,  301,
  301,  301,  301,  301,    0,  301,   60,   62,   15,  138,
    0,    0,   16,    0,    0,    0,  137,    0,    0,    0,
  138,  301,    0,    0,    0,   17,    0,  204,    0,    0,
   18,   19,   60,    0,  175,    0,  138,   21,    0,    0,
    0,    0,    0,  138,    0,    0,  138,    0,  138,  137,
    0,    0,    0,  137,    0,    0,  185,    0,    0,    0,
    0,   22,    0,    0,   60,   60,  137,    0,  137,   60,
  138,  137,  137,    0,    0,  137,  138,  191,  137,    0,
    0,  138,   60,  185,  185,  185,  301,   60,   60,  185,
    0,    0,    0,  138,    0,    0,    0,    0,    0,    0,
    0,    0,  137,    0,  191,  191,  191,    0,    0,    0,
  191,    0,  185,  185,  185,  185,  185,    0,   60,  138,
    0,  273,    0,  274,    0,  275,  276,    0,  185,  277,
    0,  278,    0,  191,  191,  191,  191,  191,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  191,
    0,    0,  138,    0,    0,    0,  138,  142,    0,    0,
    0,    0,  287,  288,  289,  290,  185,  185,  185,  138,
    0,  138,    0,    0,  138,  138,    0,    0,  138,    0,
    0,  138,    0,    0,  142,    0,  142,  191,  191,  191,
  142,    0,    0,    0,    0,    0,    0,    0,    0,  185,
    0,    0,    0,  185,    0,  138,    0,    0,    0,    0,
    0,    0,    0,    0,  142,  142,  142,  142,    0,    0,
  191,  185,  185,    3,  191,  185,    0,    0,    0,  142,
    0,    0,    0,    4,    4,    0,    0,    0,    0,    0,
    0,  142,  191,  191,    0,    0,  191,   61,    0,    5,
    5,  291,  185,    0,    0,    0,    6,    6,   61,    7,
    7,    8,    8,    0,    0,    0,    0,  142,  142,  142,
    0,    0,    0,  191,   61,    0,    0,    0,  104,  104,
    0,   61,  105,    0,   61,    0,   61,    0,  127,  106,
  106,  128,    0,    0,   12,   12,    0,    0,    0,    0,
  142,    0,    0,   61,  142,    0,   61,  107,    0,    0,
    0,    0,    0,    0,   61,  127,    0,    0,  128,   61,
    0,    0,  142,  142,    0,  127,  142,  127,  128,    0,
  128,   61,   14,   14,    0,   16,    0,    0,   17,    0,
    0,    0,    0,    0,  127,    0,   16,  128,  127,   17,
    0,  128,    0,  142,    0,  127,    0,   61,  128,    0,
  127,    0,    0,  128,    0,  178,   15,    0,    0,   16,
   16,    0,  127,    0,    0,  128,  178,    0,    0,    0,
    0,    0,   17,   17,    0,    0,    0,   18,   18,  108,
   61,    0,  178,    0,   61,    0,    0,    0,  127,  178,
    0,  128,  178,    0,  178,    0,    0,   61,    0,    0,
  178,    0,   61,   61,    0,    0,    0,    0,   22,   22,
    0,    0,    0,    0,  178,    3,    0,    0,    0,    0,
    0,  127,  178,    0,  128,  127,    4,  178,  128,   62,
    0,    0,    0,   61,    0,    0,    0,    0,  127,  178,
   62,  128,    5,  127,  127,    0,  128,  128,    0,    6,
    0,    0,    7,    0,    8,    0,    0,    0,    0,    0,
    0,    0,    0,   62,    0,  178,   62,    0,   62,    0,
    0,    0,    0,   69,  127,    0,    0,  128,    0,    0,
    0,    0,   11,    0,   69,   62,    0,   12,   62,    0,
    0,    0,    0,    0,   60,    0,   62,    0,  178,   13,
    0,   62,  178,    0,    0,   60,    0,   69,    0,    0,
   69,    0,   69,   62,    0,  178,    0,    0,    0,    0,
  178,  178,    0,    0,    0,   14,    0,    0,   60,   69,
    0,   60,   69,   60,    0,    0,    0,    0,    0,   62,
   69,    0,    0,    0,  619,   69,  620,    0,  621,  622,
   60,  178,  623,   60,  624,    0,    0,   69,   15,    0,
    0,   60,   16,   64,    0,    0,   60,    0,    0,    0,
    0,    3,   62,    0,   64,   17,   62,    0,   60,    0,
   18,   19,    0,   69,  175,  633,  634,  635,  636,   62,
   64,    0,    0,    0,   62,   62,    0,   64,  406,    0,
   64,    0,   64,    0,   60,    3,    0,    0,    7,    0,
    8,   22,    0,    0,    0,    0,   69,    0,    0,   64,
   69,    0,    0,    0,    0,   62,    0,    0,    0,    0,
   64,    0,    5,   69,    0,   64,    0,   60,   69,   69,
    0,   60,    7,   12,    8,    0,    0,   64,    0,    0,
    0,    0,    0,    0,   60,  107,    0,    0,    0,   60,
   60,    0,    0,    0,    0,    0,    0,    0,    0,   69,
    0,    0,  484,   64,  637,    0,    0,   12,    0,    0,
    0,   14,    0,    0,    0,    0,    0,    0,    0,  107,
   60,    0,    0,    0,    0,    0,    0,  273,    0,  274,
    0,  275,  276,    0,    0,  277,   64,  278,    0,    0,
   64,  279,  280,    0,   15,   14,    0,    0,   16,    0,
    0,    0,    0,   64,    0,    0,    0,    0,   64,   64,
    0,   17,    0,    0,    0,    0,   18,  108,  287,  288,
  289,  290,    0,    0,    0,    0,    0,    0,   15,  154,
  155,    0,   16,    0,    0,    0,  156,    0,    0,   64,
  157,    0,    0,    0,    0,   17,  158,   22,  247,    0,
   18,  108,  159,  160,    0,    0,  161,    0,  162,    0,
  163,  164,    0,  322,    0,  322,    0,    0,    0,  322,
  322,  322,  322,  322,    0,  322,  322,    0,    0,  322,
    0,   22,    0,    0,    0,    0,  165,  166,  167,  168,
  169,   12,  170,  154,  155,  322,  322,  322,  322,  322,
  156,  171,    0,  194,  157,    0,    0,  291,    0,    0,
  158,    0,  361,    0,    0,    0,  159,  160,    0,    0,
  161,    0,  162,    0,  163,  164,    0,    0,    0,   14,
    0,    0,    0,    0,  619,    0,  620,    0,  621,  622,
    0,    0,  623,    0,  624,    0,    0,    0,  625,  626,
  165,  166,  167,  168,  169,   12,  170,    0,    0,    0,
    0,    0,    0,  154,  155,  171,  248,  194,    0,    0,
  156,    0,    0,    0,  157,  633,  634,  635,  636,    0,
  158,    0,  600,    0,   18,  322,  159,  160,    0,    0,
  161,    0,  162,   14,  163,  164,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   22,    0,    0,    0,    0,
  165,  166,  167,  168,  169,   12,  170,  154,  155,    0,
  248,    0,    0,    0,  156,  171,    0,  194,  157,    0,
    0,    0,    0,    0,  158,    0,  654,    0,   18,    0,
  159,  160,    0,    0,  161,    0,  162,    0,  163,  164,
    0,    0,    0,   14,  637,    0,    0,    0,  619,    0,
  620,    0,  621,  622,    0,    0,  623,    0,  624,   22,
    0,    0,  625,    0,  165,  166,  167,  168,  169,   12,
  170,    0,    0,    0,    0,    0,    0,  154,  155,  171,
  248,  194,    0,    0,  156,    0,    0,    0,  157,  633,
  634,  635,  636,    0,  158,    0,    0,    0,   18,    0,
  159,  160,    0,    0,  161,    0,  162,   14,  163,  164,
    0,    0,    0,    0,    0,    0,  642,    0,    0,    0,
  645,    0,    0,  648,    0,    0,    0,    0,    0,   22,
    0,    0,    0,    0,  165,  166,  167,  168,  169,   12,
  170,  154,  155,    0,  248,    0,    0,    0,  156,  171,
    0,  194,  157,    0,  678,    0,    0,  681,  158,    0,
    0,  684,   18,  685,  159,  160,    0,  689,  161,    0,
  162,    0,  163,  164,    0,    0,    0,   14,  637,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  692,    0,   22,    0,    0,    0,  696,  347,  166,
  167,  168,  169,   12,  170,    0,    0,    0,    0,    0,
    0,  154,  155,  171,  248,  194,    0,    0,  156,    0,
    0,    0,  157,    0,    0,    0,  715,  716,  158,    0,
    0,  303,   18,  303,  159,  160,    0,    0,  161,    0,
  162,   14,  163,  164,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  303,  303,  303,  303,  303,  303,
  303,  303,  303,   22,  303,    0,    0,    0,  348,  166,
  167,  168,  169,   12,  170,  154,  155,    0,  248,    0,
  303,    0,  156,  171,    0,  194,  157,    0,    0,    0,
  322,    0,  158,    0,    0,    0,   18,    0,  159,  160,
    0,    0,    0,    0,    0,    0,    0,  322,    0,  322,
    0,   14,    0,  322,  322,  322,  322,  322,    0,  322,
  322,    0,    0,  322,    0,    0,  217,   22,    0,    0,
    0,    0,  165,  166,  167,  168,  169,   12,  170,  322,
  322,  322,  322,  322,    0,  303,    0,  171,  248,  194,
    0,    0,    0,  217,  217,  217,  217,  217,  217,  217,
    0,    0,    0,    0,    0,    0,   18,  217,  217,    0,
    0,  217,    0,  217,    0,   14,    0,  217,  217,  217,
  217,  217,  217,  217,  217,  217,  217,  217,    0,    0,
    0,    0,  322,    0,    0,    0,    0,   22,  217,    0,
    0,    0,    0,  217,  217,  217,  217,  217,  217,  322,
    0,  322,  248,    0,    0,  322,  322,  322,  322,  322,
    0,  322,  322,    0,    0,  217,    0,    0,    0,  322,
   18,    0,    0,    0,    0,    0,  217,  217,  217,    0,
    0,  322,  322,  322,  322,  322,    0,    0,    0,    0,
    0,    0,  217,  217,  217,  217,  217,  217,  217,    0,
    0,   22,    0,  396,    0,    0,  217,  217,  217,  217,
  217,    0,  217,  217,    0,    0,  217,  217,  217,  217,
  217,  217,  217,  217,  217,  217,  217,    0,    0,    0,
    0,  217,  217,  217,    0,  217,    0,    0,    0,    0,
    0,    0,  217,  217,  217,  217,  217,  217,  322,    0,
  322,    0,    0,    0,  322,  322,  322,  322,  322,    0,
  322,  322,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  322,    0,    0,    0,    0,  217,  217,    0,    0,
  322,  322,  322,  322,  322,    0,  322,  396,  322,    0,
    0,    0,  322,  322,  322,  322,  322,  322,  322,  322,
    0,    0,    0,    0,    0,    0,    0,  217,  217,    0,
    0,    0,    0,  396,    0,    0,    0,    0,  322,  322,
  322,  322,  322,    0,    0,    0,    0,    0,    0,    0,
    0,  217,  217,    0,  217,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  396,  396,    0,    0,    0,
  396,    0,    0,    0,    0,    0,    0,    0,    0,  209,
  209,  209,  209,  209,  209,  209,    0,    0,  396,  396,
  322,    0,  396,  209,  209,    0,    0,  209,    0,  209,
    0,    0,    0,  209,  209,  209,  209,  209,  209,  209,
  209,  209,    0,  209,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  322,  209,
  209,  209,  209,  209,  209,  392,  392,    0,  392,  392,
  392,    0,    0,    0,    0,  392,    0,  392,    0,  392,
  392,    0,    0,  392,    0,  392,    0,    0,    0,  392,
  392,  392,  392,  392,  392,  392,  392,  392,    0,  392,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  392,  392,  392,  392,  392,
  392,    0,    0,    0,  209,    0,    0,    0,    0,    0,
    0,    0,  210,  210,    0,  210,  210,  210,    0,    0,
    0,    0,  210,    0,  210,    0,  210,  210,    0,  209,
  210,    0,  210,    0,    0,    0,  210,  210,  210,  210,
  210,  210,  210,  210,  210,    0,  210,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  392,    0,  210,  210,  210,  210,  210,  210,  382,    0,
  382,    0,  382,  382,    0,    0,    0,  310,  382,  310,
  382,    0,  382,  382,    0,  392,  382,    0,  382,    0,
    0,    0,  382,  382,  382,  382,  382,    0,  382,  382,
  382,    0,  310,  310,  310,  310,  310,  310,  310,    0,
  310,    0,    0,    0,    0,    0,    0,    0,  382,  382,
  382,  382,  382,  382,    0,    0,  310,  210,    0,  382,
    0,  382,    0,  382,  382,    0,    0,    0,    0,  382,
    0,  382,    0,  382,  382,    0,    0,  382,    0,  382,
    0,    0,  210,  382,  382,  382,  382,  382,    0,  382,
  382,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  382,
  382,  382,  382,  382,  382,    0,  337,  337,  337,  337,
  337,  310,    0,    0,    0,  337,    0,  337,    0,  337,
  337,    0,    0,  337,    0,  337,    0,    0,  382,  337,
  337,  337,  337,  337,  337,  337,  337,  337,    0,  337,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  320,    0,  320,    0,  337,  337,  337,  337,  337,
  320,    0,  320,    0,  320,  320,    0,    0,  320,    0,
  320,    0,    0,    0,  320,  320,  320,  320,  320,  320,
  320,  320,  320,    0,  320,    0,    0,    0,    0,  382,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  320,  320,  320,  320,  320,  316,    0,  316,    0,    0,
    0,    0,    0,    0,  316,    0,  316,    0,  316,  316,
  337,    0,  316,    0,  316,    0,    0,    0,  316,  316,
  316,  316,  316,  316,  316,  316,  316,    0,  316,    0,
    0,    0,    0,    0,    0,  337,    0,    0,    0,    0,
  336,    0,  336,    0,  316,  316,  316,  316,  316,  336,
    0,  336,    0,  336,  336,  320,    0,  336,    0,  336,
    0,    0,    0,  336,  336,  336,  336,  336,  336,  336,
  336,  336,    0,  336,    0,    0,    0,    0,    0,    0,
  320,    0,    0,    0,    0,    0,    0,    0,    0,  336,
  336,  336,  336,  336,  333,    0,  333,    0,    0,    0,
    0,    0,    0,  333,    0,  333,    0,  333,  333,  316,
    0,  333,    0,  333,    0,    0,    0,  333,  333,  333,
  333,  333,  333,  333,  333,  333,    0,  333,    0,    0,
    0,    0,    0,    0,  316,    0,    0,    0,    0,  334,
    0,  334,    0,  333,  333,  333,  333,  333,  334,    0,
  334,    0,  334,  334,  336,    0,  334,    0,  334,    0,
    0,    0,  334,  334,  334,  334,  334,  334,  334,  334,
  334,    0,  334,    0,    0,    0,    0,    0,    0,  336,
    0,    0,    0,    0,    0,    0,    0,    0,  334,  334,
  334,  334,  334,  329,    0,  329,    0,    0,    0,    0,
    0,    0,  329,    0,  329,    0,  329,  329,  333,    0,
  329,    0,  329,    0,    0,    0,  329,  329,  329,  329,
  329,  329,  329,  329,  329,    0,  329,    0,    0,    0,
    0,    0,    0,  333,    0,    0,    0,    0,  330,    0,
  330,    0,  329,  329,  329,  329,  329,  330,    0,  330,
    0,  330,  330,  334,    0,  330,    0,  330,    0,    0,
    0,  330,  330,  330,  330,  330,  330,  330,  330,  330,
    0,  330,    0,    0,    0,    0,    0,    0,  334,    0,
    0,    0,    0,    0,    0,    0,    0,  330,  330,  330,
  330,  330,  332,    0,  332,    0,    0,    0,    0,    0,
    0,  332,    0,  332,    0,  332,  332,  329,    0,  332,
    0,  332,    0,    0,    0,  332,  332,  332,  332,  332,
  332,  332,  332,  332,    0,  332,    0,    0,    0,    0,
    0,    0,  329,    0,    0,    0,    0,  331,    0,  331,
    0,  332,  332,  332,  332,  332,  331,    0,  331,    0,
  331,  331,  330,    0,  331,    0,  331,    0,    0,    0,
  331,  331,  331,  331,  331,  331,  331,  331,  331,    0,
  331,    0,    0,    0,    0,    0,    0,  330,    0,    0,
    0,    0,    0,    0,    0,    0,  331,  331,  331,  331,
  331,  335,    0,  335,    0,    0,    0,    0,    0,    0,
  335,    0,  335,    0,  335,  335,  332,    0,  335,    0,
  335,    0,    0,    0,  335,  335,  335,  335,  335,  335,
  335,  335,  335,    0,  335,    0,    0,    0,    0,    0,
    0,  332,    0,    0,    0,    0,  321,    0,  321,    0,
  335,  335,  335,  335,  335,  321,    0,  321,    0,  321,
  321,  331,    0,  321,    0,  321,    0,    0,    0,  321,
  321,  321,  321,  321,  321,  321,  321,  321,    0,  321,
    0,    0,    0,    0,    0,    0,  331,    0,    0,    0,
    0,    0,    0,    0,    0,  321,  321,  321,  321,  321,
  328,    0,  328,    0,    0,    0,    0,    0,    0,  328,
    0,  328,    0,  328,  328,  335,    0,  328,    0,  328,
    0,    0,    0,  328,  328,  328,  328,  328,  328,  328,
  328,  328,    0,  328,    0,    0,    0,    0,    0,    0,
  335,    0,    0,    0,    0,  318,    0,  318,    0,  328,
  328,  328,  328,  328,  318,    0,  318,    0,  318,  318,
  321,    0,  318,    0,  318,    0,    0,    0,  318,  318,
  318,  318,  318,  318,  318,  318,  318,    0,  318,    0,
    0,    0,    0,    0,    0,  321,    0,    0,    0,    0,
    0,    0,    0,    0,  318,  318,  318,  318,  318,  317,
    0,  317,    0,    0,    0,    0,    0,    0,  317,    0,
  317,    0,  317,  317,  328,    0,  317,    0,  317,    0,
    0,    0,  317,  317,  317,  317,  317,  317,  317,  317,
  317,    0,  317,    0,    0,    0,    0,    0,    0,  328,
    0,    0,    0,    0,  319,    0,  319,    0,  317,  317,
  317,  317,  317,  319,    0,  319,    0,  319,  319,  318,
    0,  319,    0,  319,    0,    0,    0,  319,  319,  319,
  319,  319,  319,  319,  319,  319,    0,  319,    0,    0,
    0,  322,    0,  322,  318,    0,    0,    0,    0,    0,
    0,    0,    0,  319,  319,  319,  319,  319,  322,    0,
  322,    0,    0,    0,  322,  322,  322,  322,  322,  322,
  322,  322,  322,  317,  322,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  409,    0,    0,    0,
  322,  322,  322,  322,  322,  273,    0,  274,  317,  275,
  276,    0,    0,  277,    0,  278,    0,    0,    0,  279,
  280,  281,  282,  283,    0,  284,  285,    0,  319,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  682,    0,  286,  287,  288,  289,  290,
    0,    0,  273,  319,  274,    0,  275,  276,    0,    0,
  277,    0,  278,    0,    0,  322,  279,  280,  281,  282,
  283,    0,  284,  285,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  712,    0,
  322,    0,  286,  287,  288,  289,  290,  273,    0,  274,
    0,  275,  276,    0,    0,  277,    0,  278,    0,    0,
    0,  279,  280,  281,  282,  283,    0,  284,  285,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  713,  291,    0,  286,  287,  288,
  289,  290,    0,  273,    0,  274,    0,  275,  276,  322,
    0,  277,    0,  278,    0,    0,    0,  279,  280,  281,
  282,  283,    0,  284,  285,    0,  322,    0,  322,    0,
    0,    0,  322,  322,  322,  322,  322,    0,  322,  322,
    0,    0,  291,  286,  287,  288,  289,  290,  322,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  322,  322,
  322,  322,  322,    0,    0,  322,    0,  322,    0,    0,
    0,  322,  322,  322,  322,  322,    0,  322,  322,    0,
    0,    0,    0,    0,    0,    0,    0,  291,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  322,  322,  322,
  322,  322,    0,  329,    0,    0,    0,    0,    0,    0,
  273,    0,  274,    0,  275,  276,    0,    0,  277,    0,
  278,    0,    0,  401,  279,  280,  281,  282,  283,    0,
  284,  285,    0,  291,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  322,  448,
  286,  287,  288,  289,  290,    0,  273,    0,  274,    0,
  275,  276,  322,    0,  277,    0,  278,    0,    0,    0,
  279,  280,  281,  282,  283,    0,  284,  285,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  322,    0,    0,
    0,    0,    0,    0,  458,    0,  286,  287,  288,  289,
  290,  273,    0,  274,    0,  275,  276,    0,    0,  277,
    0,  278,    0,    0,    0,  279,  280,  281,  282,  283,
    0,  284,  285,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  291,  286,  287,  288,  289,  290,  508,    0,    0,    0,
    0,    0,    0,  273,    0,  274,    0,  275,  276,    0,
    0,  277,    0,  278,    0,    0,    0,  279,  280,  281,
  282,  283,    0,  284,  285,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  291,    0,    0,    0,
    0,  679,    0,  286,  287,  288,  289,  290,  273,    0,
  274,    0,  275,  276,    0,    0,  277,    0,  278,    0,
    0,    0,  279,  280,  281,  282,  283,    0,  284,  285,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  291,    0,    0,    0,    0,    0,  701,  286,  287,
  288,  289,  290,    0,  273,    0,  274,    0,  275,  276,
    0,  322,  277,    0,  278,    0,    0,    0,  279,  280,
  281,  282,  283,    0,  284,  285,  322,    0,  322,    0,
    0,    0,  322,  322,  322,  322,  322,    0,  322,  322,
    0,    0,    0,  291,  286,  287,  288,  289,  290,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  322,  322,
  322,  322,  322,  295,    0,  295,    0,  295,  295,    0,
    0,  295,    0,  295,    0,    0,    0,  295,  295,  295,
  295,  295,  295,  295,  295,  295,    0,    0,  291,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  295,  295,  295,  295,  295,    0,  291,
    0,  291,    0,  291,  291,    0,    0,  291,    0,  291,
    0,    0,    0,  291,  291,  291,  291,  291,  291,  291,
  291,  291,    0,    0,  291,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  322,  291,
  291,  291,  291,  291,  296,    0,  296,    0,  296,  296,
    0,    0,  296,    0,  296,    0,    0,    0,  296,  296,
  296,  296,  296,  296,  296,  296,  296,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  295,  296,  296,  296,  296,  296,    0,
  293,    0,  293,    0,  293,  293,    0,    0,  293,    0,
  293,    0,    0,    0,  293,  293,  293,  293,  293,  293,
  293,  293,  293,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  291,
  293,  293,  293,  293,  293,  292,    0,  292,    0,  292,
  292,    0,    0,  292,    0,  292,    0,    0,    0,  292,
  292,  292,  292,  292,  292,  292,  292,  292,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  296,  292,  292,  292,  292,  292,
    0,  294,    0,  294,    0,  294,  294,    0,    0,  294,
    0,  294,    0,    0,    0,  294,  294,  294,  294,  294,
  294,  294,  294,  294,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  293,  294,  294,  294,  294,  294,  273,    0,  274,    0,
  275,  276,    0,    0,  277,    0,  278,    0,    0,    0,
  279,  280,  281,  282,  283,  456,  284,  285,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  292,  286,  287,  288,  289,
  290,    0,  273,    0,  274,    0,  275,  276,    0,    0,
  277,    0,  278,    0,    0,    0,  279,  280,  281,  282,
  283,    0,  284,  285,  646,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  294,  286,  287,  288,  289,  290,  273,    0,  274,
    0,  275,  276,    0,    0,  277,    0,  278,    0,    0,
    0,  279,  280,  281,  282,  283,  677,  284,  285,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  291,  286,  287,  288,
  289,  290,    0,  619,    0,  620,    0,  621,  622,    0,
    0,  623,    0,  624,    0,    0,    0,  625,  626,  627,
  628,  629,  691,  630,  631,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  291,  632,  633,  634,  635,  636,  273,    0,
  274,    0,  275,  276,    0,    0,  277,    0,  278,    0,
    0,    0,  279,  280,  281,  282,  283,    0,  284,  285,
  703,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  291,  286,  287,
  288,  289,  290,    0,  619,    0,  620,    0,  621,  622,
    0,    0,  623,    0,  624,    0,    0,    0,  625,  626,
  627,  628,  629,    0,  630,  631,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  637,  632,  633,  634,  635,  636,  273,
    0,  274,    0,  275,  276,    0,    0,  277,    0,  278,
    0,    0,    0,  279,  280,  281,  282,  283,    0,  284,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  291,  286,
  287,  288,  289,  290,    0,  619,    0,  620,    0,  621,
  622,    0,    0,  623,    0,  624,    0,    0,    0,  625,
  626,  627,  628,  629,  619,  630,  620,    0,  621,  622,
    0,    0,  623,    0,  624,    0,    0,    0,  625,  626,
  627,  628,  629,    0,  637,  632,  633,  634,  635,  636,
  322,    0,  322,    0,    0,    0,  322,  322,  322,  322,
  322,    0,  322,  322,    0,  633,  634,  635,  636,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  300,
    0,  300,  322,  322,  322,  322,  322,    0,  300,  291,
  300,    0,  300,  300,    0,    0,  300,    0,  300,    0,
    0,    0,  300,  300,  300,  300,  300,  300,  300,  300,
  300,    0,  300,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  300,  300,
  300,  300,  300,    0,  306,  637,  306,    0,    0,    0,
    0,    0,    0,  306,    0,  306,    0,  306,  306,    0,
    0,  306,    0,  306,  637,    0,    0,  306,  306,  306,
  306,  306,  306,  306,  306,  306,    0,  306,    0,    0,
    0,    0,  322,    0,    0,    0,    0,  298,    0,  298,
    0,    0,    0,  306,  306,  306,  306,  306,  298,    0,
  298,  298,    0,  300,  298,    0,  298,    0,    0,    0,
  298,  298,  298,  298,  298,  298,  298,  298,  298,    0,
  298,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  298,  298,  298,    0,
  298,    0,  299,    0,  299,    0,    0,    0,    0,    0,
    0,    0,    0,  299,    0,  299,  299,    0,  306,  299,
    0,  299,    0,    0,    0,  299,  299,  299,  299,  299,
  299,  299,  299,  299,    0,  299,    0,    0,    0,  304,
    0,  304,    0,    0,    0,    0,    0,    0,    0,    0,
  304,  299,  299,  299,    0,  299,  304,    0,  304,    0,
    0,  298,  304,  304,  304,  304,  304,  304,  304,  304,
  304,    0,  304,    0,  308,    0,  308,    0,    0,    0,
    0,    0,    0,    0,    0,  308,    0,    0,  304,  304,
  304,  308,  304,  308,    0,    0,    0,  308,  308,  308,
  308,  308,  308,  308,  308,  308,    0,  308,    0,  309,
    0,  309,    0,    0,    0,    0,  299,    0,    0,    0,
  309,    0,    0,  308,  308,  308,  309,    0,  309,    0,
    0,    0,  309,  309,  309,  309,  309,  309,  309,  309,
  309,    0,  309,    0,  307,    0,  307,    0,    0,    0,
    0,    0,    0,  304,    0,  307,    0,    0,  309,  309,
  309,  307,    0,  307,    0,    0,    0,  307,  307,  307,
  307,  307,  307,  307,  307,  307,    0,  307,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  308,    0,
    0,    0,    0,  307,  307,  307,  657,  658,  659,  660,
  661,  662,  663,  664,  665,  666,  667,  668,  669,  670,
  671,  672,  673,  674,  675,    0,    0,    0,    0,    0,
  275,    0,  275,  309,  275,  275,    0,    0,  275,    0,
  275,    0,    0,    0,  275,  275,  275,  275,  275,  275,
  275,  275,  275,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  307,    0,
  275,  275,  275,  275,  275,  281,    0,  281,  702,  281,
  281,    0,    0,  281,    0,  281,    0,    0,    0,  281,
  281,  281,  281,  281,  281,  281,  281,  281,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  281,  281,  281,  281,  281,
  273,    0,  273,  273,    0,    0,  273,    0,  273,    0,
    0,    0,  273,  273,  273,  273,  273,  273,  273,  273,
  273,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  273,  273,
  273,  274,  273,  274,  274,    0,    0,  274,    0,  274,
    0,    0,    0,  274,  274,  274,  274,  274,  274,  274,
  274,  274,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  279,    0,    0,  274,
  274,  274,  279,  274,  279,    0,    0,    0,  279,  279,
  279,  279,  279,  279,  279,  279,  279,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  284,    0,    0,  279,  279,  279,  284,  279,  284,
    0,    0,    0,  284,  284,  284,  284,  284,  284,  284,
  284,  284,    0,    0,    0,    0,    0,    0,    0,    0,
  283,    0,    0,    0,    0,    0,  283,    0,  283,  284,
  284,  284,  283,  283,  283,  283,  283,  283,  283,  283,
  283,    0,    0,    0,    0,    0,    0,    0,    0,  282,
    0,    0,    0,    0,    0,  282,    0,  282,  283,  283,
  283,  282,  282,  282,  282,  282,  282,  282,  282,  282,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  282,  282,  282,
};

static const YYINT yycheck[8451] = {                        115,
    0,  119,    0,    3,    4,  231,  131,  424,  115,    3,
   47,  115,  123,   30,  336,   15,  338,   50,  154,   39,
  156,    0,   99,   38,  268,   29,   30,  308,  309,   29,
   30,   97,  184,   45,  193,   41,   51,   30,   24,   43,
   50,   40,   74,   43,   54,   55,   74,   71,   72,    0,
   29,   30,   40,  130,   50,   71,  490,   69,   54,   55,
   93,   47,   24,   24,   43,   71,   41,   41,   83,   89,
   50,  230,    0,   45,   54,   55,   41,   42,   29,   30,
  154,   46,   82,   93,   94,   47,  123,  102,    9,  214,
   24,   91,   43,   81,   80,   97,   71,   93,   94,   99,
   74,   50,   23,   82,   50,   41,   52,   50,  525,   73,
   24,   54,   55,   93,  191,  115,  550,  115,   80,   80,
   58,  121,   24,  160,  124,   47,   97,   60,  253,  410,
  130,  412,  268,  567,  134,   71,  115,  123,   71,  155,
  265,  178,  294,  295,   93,   47,   80,  180,   40,  155,
   93,   97,  586,   40,  154,  155,  315,  185,   50,  176,
   52,  123,  123,   50,  115,   52,   80,  292,  183,  148,
  180,   97,  209,   99,  160,  300,  176,  611,   80,   24,
  155,  196,   41,  176,  180,   81,   24,  115,  188,  189,
  210,  191,  178,  121,  268,  199,  124,  176,  160,  199,
  180,  218,  202,  321,  219,  222,  134,  451,   60,  229,
   97,   73,   71,  494,  218,  441,  178,  179,  218,   71,
  199,  339,  222,  209,  256,  218,  154,  173,   24,  222,
  234,  180,    0,  250,  234,   80,    4,  180,  160,  218,
  365,  393,   80,  222,   42,  397,  398,  209,  199,  401,
  250,   47,  123,  253,   24,  234,  178,  250,   82,  178,
  188,   29,   30,  209,  698,  509,    9,  218,  268,  581,
    0,  250,   69,  554,  202,   43,   73,   47,  123,   71,
   23,  173,   74,  234,   80,  123,  173,  209,  305,  160,
  269,   12,  173,  272,  294,  295,  608,  178,  298,   29,
   30,   22,   41,  303,  298,  305,   36,  178,  308,  309,
   80,   42,  305,   43,   82,  451,  316,  209,   41,   40,
   43,    3,  209,   91,  148,  253,  305,  123,   41,   71,
  652,   99,   74,   15,   60,   41,  336,   24,  209,   41,
  268,  341,   41,  294,  295,   71,   69,  115,   71,   72,
   42,   74,  176,  121,   46,   43,  124,  336,   60,  338,
   47,   60,  130,   60,  103,  365,  134,   58,  680,   71,
   60,  101,   71,  509,   71,  114,   69,  451,  357,  497,
  395,   71,   40,  113,  706,  115,  154,  155,  316,   41,
  103,  391,   50,   80,   52,   45,   40,  391,  222,  138,
  417,  114,   97,  528,   41,   42,  522,  137,  176,   46,
  410,   41,  412,  341,  414,  522,  416,  417,  522,   13,
  188,  189,   80,  191,  417,  138,  250,  406,  407,   42,
  555,  199,  155,   46,  202,  509,   80,  365,  417,   97,
   69,   85,   80,   40,   73,  269,  176,   43,  272,  269,
  218,  451,  272,   50,  222,   52,   69,   69,   80,   60,
  567,   73,  462,   40,   71,  465,  234,   74,  462,  199,
   71,  465,   43,   50,   40,   52,  485,   40,  487,  123,
   40,  305,  250,   80,   50,  253,   52,   71,  218,  489,
   74,   85,  222,  493,  494,  124,  125,   41,   42,  493,
  268,  123,   46,   97,  234,  522,  485,  507,  487,  509,
   69,  511,  336,   71,  338,  173,  160,  511,  124,  125,
   97,   73,  522,  451,  522,   69,   70,   71,   41,  123,
   24,  270,   72,  357,  178,  303,   72,  305,  160,  269,
  308,  309,  272,  522,   41,   72,   43,   72,  316,   47,
   41,  209,  552,   47,  554,  173,  178,  270,  552,   41,
   42,  489,  156,   23,   46,  209,  160,  567,   71,  567,
   72,  522,   69,  341,   71,   72,  173,   74,   60,  507,
   69,  509,  406,  407,  178,  179,   80,  209,  182,   71,
  320,   42,   41,  417,  522,   46,  173,  365,  337,   24,
   70,   71,   74,   41,   74,   43,  336,  173,  338,   60,
  180,  155,  209,   41,  614,  209,  298,  124,  125,  349,
   71,   41,   47,   70,  337,  123,   41,  366,   41,  123,
  369,   69,  209,   71,   72,  652,   74,   41,   41,  567,
   71,   72,  410,  209,  412,  358,  414,   41,   69,  417,
   71,   72,  652,  366,  336,   80,  369,   40,  155,  652,
  160,  485,  160,  487,   71,   72,   69,   70,   71,   80,
   41,   42,   97,  652,   85,   46,   71,   72,   13,  127,
  178,  179,   73,  451,   13,   40,  614,  417,   69,  706,
   71,   72,   13,  432,   40,  408,   42,   41,  437,  699,
   46,   73,   24,  442,  443,  444,  706,   91,   40,  391,
   42,  209,  123,  706,   46,   99,   47,  155,   40,  432,
  104,  489,   71,   69,  437,   47,  494,  706,   50,   50,
   52,   52,   40,  117,  416,  160,  449,   74,   70,  507,
   69,  509,   71,   72,   73,   72,  130,  486,   41,  160,
   85,  176,  155,  178,  522,  485,   85,  487,   80,   41,
  473,  474,   97,   85,   85,   41,   42,  178,   97,   40,
   46,  699,   40,  486,   42,   97,   97,  516,   46,  518,
  462,   69,  521,  465,  209,  123,  554,   40,  123,   42,
  406,  407,  522,   46,  123,  124,  125,   40,  209,  567,
   80,  123,  123,  516,  188,  518,  153,  191,  521,  156,
   40,  493,  159,  160,  161,  162,  163,  164,   41,   42,
  155,  156,  160,   46,  171,  160,  173,  156,  652,  511,
   69,  160,   41,   42,  181,  156,   41,   46,  160,  160,
  178,  179,   40,  178,  179,   69,  614,  182,   81,  178,
  179,  173,  173,  182,   72,   41,  178,  178,  179,   39,
   12,   70,   71,  247,   98,  180,   71,   72,   40,   74,
  552,  209,  155,   50,  209,   41,   41,   54,   55,   73,
  209,   58,  706,   60,  652,  232,  233,  209,  209,  273,
  274,  275,  276,  277,  278,  279,  280,  281,  282,  283,
  284,  285,  286,  287,  288,  289,  290,  291,   41,  293,
  257,   73,   73,   72,   91,   40,   93,   94,  113,  303,
  267,  554,  652,  242,   40,   50,   42,   52,   44,   45,
  353,  699,   73,   69,  318,   71,   72,  199,  706,   80,
  148,   40,  155,   42,  341,  357,  155,   46,   80,  688,
  155,    1,  295,    3,    4,   80,  686,    7,    8,    9,
   10,  415,   12,   13,  155,   97,   16,  303,  414,   19,
   20,   70,  711,   23,   24,  688,  706,  361,   28,   95,
   30,  115,  123,   33,   34,  202,   -1,   -1,  489,   39,
   40,  123,   69,   70,   71,   72,   46,   47,  711,   -1,
   50,   -1,   52,  180,   54,   55,   13,   -1,   58,   -1,
   60,   -1,   -1,   90,   64,   65,   66,   67,   68,  160,
   70,   71,   72,   73,   74,   41,  123,   43,  160,   -1,
   80,   81,   82,   83,   84,   85,   86,  178,  179,   -1,
   90,   91,   92,   93,   94,   95,  178,   97,  173,   99,
  100,   67,   68,   69,   70,   71,   72,   -1,   74,   -1,
   -1,  445,    9,  160,   40,   41,   42,   -1,  209,   40,
   46,   42,  456,  123,   90,   46,   23,  209,   85,   -1,
   -1,  178,  179,   -1,  209,   -1,   -1,   73,   -1,   -1,
   97,   -1,   -1,   40,   80,   42,   -1,   44,   13,   46,
   47,  448,   -1,   50,   -1,   52,  156,   54,   55,   -1,
  160,   58,  209,   60,   -1,   -1,  123,   64,   65,   66,
   67,   -1,   -1,   70,   71,   40,   41,   42,  178,  179,
  180,   46,  182,   -1,   40,  185,   42,  123,   85,  155,
   46,   -1,   -1,   90,   91,   92,   93,   94,   95,  156,
   97,   -1,   -1,  160,   69,   70,   71,   72,   73,  209,
   -1,  508,   80,   -1,   70,  215,   72,   85,   -1,   -1,
   85,  178,  179,   -1,  160,  182,  123,   -1,   -1,   97,
   -1,   -1,   97,   40,   41,   42,   -1,   -1,   -1,   46,
   -1,   -1,  178,  179,   -1,  579,   50,   -1,   -1,   -1,
   54,   55,  209,   -1,   58,  123,   60,   50,  123,  124,
  125,   54,   55,  160,  598,   58,  600,   60,   -1,   -1,
  567,  605,   -1,  209,   40,   41,   42,  574,   -1,   -1,
   46,  178,   -1,  180,   -1,   -1,   -1,   91,  585,   93,
   94,  156,  160,   -1,   -1,  160,   -1,   -1,   91,   92,
   93,   94,   40,   41,   42,   -1,   -1,  175,   46,   -1,
  178,   -1,  209,  178,  179,   -1,   -1,  182,   -1,  616,
  654,   -1,  619,  620,  621,  622,  623,  624,  625,  626,
  627,  628,  629,  630,  631,  632,  633,  634,  635,  636,
  637,  209,   -1,   -1,  209,   -1,   -1,  681,   -1,   -1,
   -1,   -1,    1,   -1,    3,    4,   -1,   -1,    7,    8,
    9,   10,   -1,   -1,   13,   -1,  700,   16,   -1,  703,
   19,   20,   -1,   -1,   23,   24,  180,   -1,   -1,   28,
   -1,   30,  679,   -1,   33,   34,   -1,  180,   -1,   -1,
   39,   40,   -1,   -1,  691,   -1,   80,   46,   47,   -1,
   -1,   50,   -1,   52,  701,   54,   55,   -1,   -1,   58,
   -1,   60,   -1,   97,   -1,   64,   65,   66,   67,   68,
   -1,   70,   71,   72,   73,   74,   -1,   -1,   -1,   -1,
   -1,   80,   81,   82,   83,   84,   85,   86,   -1,  123,
   80,   90,   91,   92,   93,   94,   95,   -1,   97,   -1,
   99,  100,   40,   41,   42,   -1,   -1,   97,   46,   -1,
   -1,   -1,   -1,    1,   -1,    3,    4,   -1,   13,    7,
    8,    9,   10,   -1,  123,   13,  160,   -1,   16,   -1,
   -1,   19,   20,  123,   -1,   23,   24,   40,   41,   42,
   28,   -1,   30,   46,  178,   33,   34,   -1,   -1,   -1,
   -1,   39,   40,   73,   -1,   -1,   -1,  156,   46,   47,
   80,  160,   50,   -1,   52,   -1,   54,   55,   -1,   -1,
  160,   -1,   -1,   -1,   -1,  209,   -1,   -1,   -1,  178,
  179,  180,   -1,  182,   72,   73,  185,   -1,  178,   -1,
   85,   -1,   80,   81,   82,   83,   84,   85,   86,   -1,
   -1,   -1,   97,  123,   -1,   -1,   -1,   95,   -1,   97,
  209,   99,  100,   -1,   -1,   -1,  215,   -1,   -1,  209,
   -1,   -1,   -1,   -1,    1,   -1,    3,    4,  123,   -1,
    7,    8,    9,   10,   -1,  123,   13,   -1,   -1,   16,
  160,   -1,   19,   20,   -1,   -1,   23,   24,   -1,   -1,
   -1,   28,   -1,   30,   -1,   -1,   33,   34,  178,  179,
   -1,  156,   39,   40,   -1,  160,   -1,   -1,  156,   46,
   47,   -1,  160,   50,   -1,   52,   -1,   54,   55,   -1,
   -1,   -1,   -1,  178,  179,   -1,   -1,  182,   -1,  209,
  178,  179,   -1,   -1,  182,   72,   73,  185,   -1,   -1,
   -1,   -1,   -1,   80,   81,   82,   83,   84,   85,   86,
   -1,   -1,   -1,   -1,  209,   -1,   -1,   -1,   95,   -1,
   97,  209,   99,  100,   -1,   -1,   -1,  215,   -1,   -1,
   50,   -1,   52,   -1,   -1,    1,   -1,    3,    4,   -1,
   -1,    7,    8,    9,   10,   -1,  123,   13,   -1,   -1,
   16,   -1,   -1,   19,   20,   24,   -1,   23,   24,   -1,
   -1,   -1,   28,   -1,   30,   85,   -1,   33,   34,   24,
   -1,   -1,   -1,   39,   40,   -1,   -1,   97,   47,  156,
   46,   47,   -1,  160,   50,   40,   52,   -1,   54,   55,
   -1,   -1,   47,   -1,   -1,   50,   -1,   52,   -1,    0,
    1,  178,  179,  123,   -1,  182,   72,   73,   -1,   -1,
   -1,   80,   13,   -1,   80,   81,   82,   83,   84,   85,
   86,   -1,   -1,   24,   -1,   80,   -1,   -1,   97,   95,
   85,   97,  209,   99,  100,   -1,   -1,   80,  215,   40,
  160,   -1,   85,   -1,   -1,   -1,   47,   52,   -1,   50,
   -1,   52,   -1,  173,   -1,   -1,   -1,  123,  178,   64,
   65,   66,   67,   68,   69,   70,   71,   72,  123,   -1,
   -1,   72,   -1,   74,   -1,   -1,   -1,   -1,   80,   80,
  123,   -1,   -1,   85,   85,   90,   -1,   92,   -1,  209,
  156,  160,   -1,   -1,  160,   97,   97,   -1,   -1,   -1,
   -1,   -1,   13,   -1,   -1,  160,   -1,  176,   -1,  178,
   -1,   -1,  178,  179,   -1,   -1,  182,  160,  173,   -1,
   -1,  123,  123,  178,   -1,   -1,   -1,   -1,   -1,   40,
   -1,   -1,  175,   -1,   -1,  178,   -1,   -1,   -1,   50,
  209,   52,    9,  209,   -1,   -1,   13,   -1,   -1,  215,
   -1,   -1,   -1,   -1,  209,  156,   23,   24,  160,  160,
   -1,   -1,   -1,   30,   -1,   -1,  209,   34,   -1,   80,
   -1,   -1,  173,   40,   85,   -1,  178,  178,  179,   46,
   47,  182,   -1,   50,  185,   52,   97,   54,   55,   -1,
   -1,   58,   -1,   60,   -1,   -1,   -1,   64,   65,   66,
   67,   68,   -1,   70,   71,   -1,   73,  209,  209,   -1,
   -1,   -1,  123,   80,   81,   82,   83,   84,   85,   86,
   -1,   -1,   -1,   90,   91,   92,   93,   94,   95,   -1,
   97,   -1,   99,    9,   -1,   -1,   -1,   13,   67,   68,
   69,   70,   71,   72,   -1,  156,   -1,   23,   24,  160,
   -1,   -1,   -1,   -1,   30,   -1,  123,   -1,   34,   -1,
   -1,   90,  173,   -1,   40,   -1,   -1,  178,  179,   -1,
   46,   47,   -1,   -1,   50,   -1,   52,   -1,   54,   55,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  155,  156,
   -1,   50,   -1,  160,   -1,   54,   55,   73,  209,   58,
   -1,   60,   -1,   -1,   80,   81,   82,   83,   84,   85,
   86,  178,  179,  180,   -1,  182,   -1,   -1,   -1,   95,
   -1,   97,   -1,   99,    9,   -1,   -1,   -1,   13,   -1,
   -1,   -1,   91,   92,   93,   94,   -1,   -1,   23,   24,
   -1,   -1,  209,   -1,   -1,   30,   50,  123,   52,   34,
   54,   55,   -1,   -1,   58,   40,   60,   -1,   -1,   -1,
   64,   46,   47,   -1,   -1,   50,   -1,   52,   -1,   54,
   55,   13,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  156,   -1,   40,   -1,  160,   -1,   -1,   91,   92,   93,
   94,   -1,   50,   -1,   52,   80,   81,   82,   83,   84,
   85,   86,  178,  179,   -1,   -1,  182,   -1,   -1,   -1,
   95,   -1,   97,   -1,   99,    9,   -1,   -1,   -1,   -1,
   -1,  180,   80,   -1,   -1,   -1,   -1,   69,   -1,   23,
   24,   73,   -1,  209,   -1,   13,   30,   -1,  123,   97,
   34,   -1,   -1,   85,   -1,   -1,   40,   -1,   -1,   -1,
   -1,   -1,   46,   47,   -1,   97,   50,   -1,   52,   -1,
   54,   55,   40,   -1,   -1,  123,   -1,   -1,   -1,   -1,
   -1,  156,   -1,   -1,   -1,  160,  180,   -1,   -1,   73,
   -1,  123,  124,  125,   -1,    9,   80,   81,   82,   83,
   84,   85,   86,  178,  179,   -1,   -1,  182,   -1,   23,
   24,   95,  160,   97,   -1,   99,   30,   85,   -1,   -1,
   34,   -1,   -1,   -1,  156,  173,   40,   -1,  160,   97,
  178,   -1,   46,   47,  209,   -1,   50,   -1,   52,  123,
   54,   55,   -1,   -1,   -1,   -1,  178,  179,   -1,   -1,
  182,   -1,   -1,   -1,   -1,  123,   -1,   -1,   80,    9,
   -1,  209,   -1,   -1,   -1,   -1,   80,   81,   82,   83,
   84,   85,   86,   23,   24,   97,  160,  209,   80,   -1,
   30,   95,   -1,   97,   34,   99,   -1,   -1,  156,   -1,
   40,   -1,  160,   -1,  178,   97,   46,   47,   -1,   -1,
   50,  123,   52,   -1,   54,   55,   -1,   -1,   -1,  123,
  178,  179,   -1,   -1,  182,   -1,   -1,   -1,   -1,   -1,
   -1,  123,   -1,   -1,   -1,  209,   -1,   -1,   -1,    9,
   80,   81,   82,   83,   84,   85,   86,   -1,  160,   -1,
   -1,  209,   -1,   23,   24,   95,  160,   97,   -1,   99,
   30,   -1,   -1,   -1,   34,   -1,  178,   -1,  160,   -1,
   40,   41,   -1,   -1,  178,   -1,   46,   47,   -1,   -1,
   50,   -1,   52,  123,   54,   55,  178,   -1,   -1,   -1,
   -1,   -1,   -1,   41,   -1,   43,   -1,  209,   -1,   -1,
   -1,   -1,   -1,   73,   -1,  209,   -1,   -1,   -1,   -1,
   80,   81,   82,   83,   84,   85,   86,  209,   -1,   13,
  160,   69,   70,   71,   72,   95,   74,   -1,   -1,   99,
   24,   66,   67,   68,   69,   70,   71,   72,  178,   -1,
   -1,   -1,   90,   -1,   -1,   -1,   40,   41,   42,   43,
   44,   45,   46,   47,   -1,   90,   50,   -1,   52,   -1,
   54,   55,   13,   -1,   58,   -1,   60,   -1,   -1,  209,
   64,   65,   66,   67,   68,   69,   70,   71,   72,   73,
   74,   -1,   -1,   -1,   -1,   -1,   80,   -1,   -1,   -1,
   41,   85,   -1,   -1,   -1,   -1,   90,   91,   92,   93,
   94,   95,   -1,  173,   -1,   -1,   -1,  155,   65,   66,
   67,   68,   69,   70,   71,   72,   -1,   -1,   69,   70,
   71,   72,   73,   -1,   -1,   -1,   41,   -1,   43,  123,
  124,  125,   -1,   90,   85,   58,   -1,   60,   -1,  209,
   -1,   64,   65,   66,   67,   68,   97,   70,   71,   72,
   65,   66,   67,   68,   69,   70,   71,   72,   -1,   74,
   -1,  155,  156,   -1,   -1,   13,  160,   90,   91,   92,
   93,   94,  123,  124,  125,   90,   24,   -1,   -1,  173,
   -1,   -1,   -1,   -1,  178,  179,  180,   -1,  182,   -1,
   -1,   -1,   40,   41,   42,   43,   44,   45,   46,   47,
   -1,   -1,   50,   -1,   52,  156,   54,   55,   13,  160,
   58,   -1,   60,   -1,   -1,  209,   64,   65,   66,   67,
   68,   69,   70,   71,   72,   73,   74,  178,  179,   -1,
   -1,  182,   80,   -1,   -1,   -1,   41,   85,   -1,   -1,
  155,   -1,   90,   91,   92,   93,   94,   95,   64,   65,
   66,   67,   68,   69,   70,   71,   72,  180,  209,   -1,
   -1,   -1,   -1,   -1,   69,   70,   71,   72,   73,   -1,
   -1,   -1,   -1,   -1,   90,  123,  124,  125,   -1,   -1,
   85,   -1,   -1,   -1,   -1,   50,   -1,   52,   -1,   54,
   55,   -1,   97,   58,   -1,   60,   -1,   -1,   -1,   64,
   65,   66,   67,   68,   -1,   -1,   -1,  155,  156,   -1,
   -1,   13,  160,   -1,   -1,   -1,   -1,   -1,  123,  124,
  125,   -1,   24,   -1,   -1,  173,   91,   92,   93,   94,
  178,  179,  180,   -1,  182,   -1,   -1,   -1,   40,   41,
   42,   43,   44,   45,   46,   47,   -1,   -1,   50,   -1,
   52,  156,   54,   55,   -1,  160,   58,   -1,   60,   -1,
   -1,  209,   64,   65,   66,   67,   68,   69,   70,   71,
   72,   73,   74,  178,  179,   -1,   -1,  182,   80,   -1,
   -1,   -1,   52,   85,   -1,   -1,   -1,   -1,   90,   91,
   92,   93,   94,   95,   64,   65,   66,   67,   68,   69,
   70,   71,   72,   50,  209,   52,   -1,   54,   55,   13,
   -1,   58,   -1,   60,   -1,  180,   -1,   64,   65,   66,
   90,  123,  124,  125,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   40,   -1,   42,   -1,
   -1,   -1,   46,   -1,   91,   92,   93,   94,   -1,   -1,
   -1,   -1,   -1,  155,  156,   -1,   -1,   13,  160,   -1,
   -1,   -1,   -1,   -1,   -1,   69,   70,   -1,   24,   73,
   -1,  173,   -1,   -1,   -1,   -1,  178,  179,  180,   -1,
  182,   85,   -1,   -1,   40,   41,   42,   43,   44,   45,
   46,   47,   -1,   97,   50,   -1,   52,   -1,   54,   55,
   -1,   -1,   -1,   -1,   60,   -1,   -1,  209,   64,   65,
   66,   67,   68,   69,   70,   71,   72,   73,   74,  123,
  124,  125,   -1,   -1,   80,   -1,   -1,   -1,   -1,   85,
   -1,   -1,   -1,  180,   90,   91,   92,   93,   94,   95,
   -1,   97,   -1,   -1,   -1,   -1,   50,   -1,   52,   -1,
   54,   55,  156,   -1,   58,   -1,  160,   13,   -1,   -1,
   64,   65,   66,   67,   68,   -1,   70,  123,  124,  125,
   -1,   -1,   -1,   -1,  178,  179,   -1,   -1,  182,   -1,
   -1,   -1,   -1,   -1,   40,   -1,   90,   91,   92,   93,
   94,   -1,   -1,   -1,   50,   -1,   52,   -1,   -1,  155,
  156,   -1,   -1,   13,  160,  209,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   24,   -1,   -1,  173,   -1,   -1,
   -1,   -1,  178,  179,  180,   -1,  182,   -1,   -1,   85,
   40,   41,   42,   43,   44,   45,   46,   47,   -1,   -1,
   50,   97,   52,   -1,   54,   55,   -1,   -1,   58,   -1,
   60,   -1,   -1,  209,   64,   65,   66,   67,   68,   69,
   70,   71,   72,   73,   74,   -1,   -1,  123,   -1,   -1,
   80,   -1,   -1,   -1,   -1,   85,  180,   -1,   -1,   -1,
   90,   91,   92,   93,   94,   95,   -1,   50,   -1,   52,
   -1,   54,   55,   -1,   -1,   58,   -1,   60,   -1,   -1,
  156,   64,   65,   66,  160,   -1,   -1,   -1,   -1,   -1,
   41,   -1,   43,  123,  124,  125,   -1,  173,   -1,   -1,
   -1,   52,  178,  179,   -1,   -1,   -1,   -1,   91,   92,
   93,   94,   -1,   64,   65,   66,   67,   68,   69,   70,
   71,   72,   -1,   74,   -1,  155,  156,   -1,   -1,   13,
  160,   -1,   -1,  209,   -1,   -1,   -1,   -1,   -1,   90,
   24,   92,   -1,  173,   -1,   -1,   -1,   -1,  178,  179,
  180,   -1,  182,   -1,   -1,   -1,   40,   41,   42,   43,
   44,   45,   46,   47,   -1,   -1,   50,   -1,   52,   -1,
   54,   55,   -1,   -1,   58,   -1,   60,   -1,   -1,  209,
   64,   65,   66,   67,   68,   69,   70,   71,   72,   -1,
   74,   -1,   -1,   -1,   -1,   -1,   80,  180,   -1,   -1,
   -1,   85,   -1,   13,  155,   -1,   90,   91,   92,   93,
   94,   95,   -1,   97,   24,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   40,   41,   42,   43,   44,   45,   46,   47,   -1,  123,
   50,   -1,   52,   -1,   54,   55,   -1,   -1,   58,   -1,
   60,   -1,   -1,   -1,   64,   65,   66,   67,   68,   -1,
   70,   71,   72,   73,   74,   -1,   -1,   -1,   -1,   -1,
   80,  155,  156,   -1,   -1,   85,  160,   13,   -1,   -1,
   90,   91,   92,   93,   94,   95,   -1,   97,   24,  173,
   -1,   -1,   -1,   -1,  178,  179,  180,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   40,   41,   42,   43,   44,   45,
   46,   47,   -1,  123,   50,   -1,   52,   -1,   54,   55,
   -1,   -1,   -1,   -1,   60,  209,   -1,   -1,   64,   65,
   66,   67,   68,   69,   70,   71,   72,   73,   74,   -1,
   -1,   -1,   -1,   -1,   80,  155,  156,   -1,   -1,   85,
  160,   13,   -1,   -1,   90,   91,   92,   93,   94,   95,
   -1,   97,   24,  173,   -1,   -1,   -1,   -1,  178,  179,
  180,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   40,   41,
   42,   43,   44,   45,   46,   47,   -1,  123,   50,   -1,
   52,   -1,   54,   55,   -1,   -1,   58,   -1,   60,  209,
   -1,   -1,   64,   65,   66,   67,   68,   -1,   70,   71,
   72,   73,   74,   -1,   -1,   -1,   -1,   -1,   80,  155,
  156,   -1,   -1,   85,  160,   13,   -1,   -1,   90,   91,
   92,   93,   94,   95,   -1,   97,   24,  173,   -1,   -1,
   -1,   -1,  178,  179,  180,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   40,   41,   42,   43,   44,   45,   46,   47,
   -1,  123,   50,   -1,   52,   -1,   54,   55,   -1,   -1,
   58,   -1,   60,  209,   -1,   -1,   64,   65,   66,   67,
   68,   69,   70,   71,   72,   -1,   74,   -1,   -1,   -1,
   -1,   -1,   80,  155,  156,   -1,   -1,   85,  160,   13,
   -1,   -1,   90,   91,   92,   93,   94,   95,   -1,   97,
   -1,  173,   -1,   -1,   -1,   -1,  178,  179,  180,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   40,   41,   -1,   43,
   44,   45,   46,   -1,   -1,  123,   50,   -1,   52,   -1,
   54,   55,   -1,   -1,   58,   -1,   60,  209,   -1,   -1,
   64,   65,   66,   67,   68,   69,   70,   71,   72,   73,
   74,   -1,   -1,   -1,   -1,   -1,   -1,  155,  156,   -1,
   -1,   85,  160,   -1,   -1,   13,   90,   91,   92,   93,
   94,   95,   -1,   97,   -1,  173,   -1,   -1,   -1,   -1,
  178,  179,  180,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   40,   41,   -1,   43,   44,   45,   46,  123,
  124,  125,   50,   -1,   52,   -1,   54,   55,   -1,   -1,
   58,  209,   60,   -1,   -1,   -1,   64,   65,   66,   67,
   68,   69,   70,   71,   72,   73,   74,   -1,   -1,   -1,
   -1,  155,  156,   -1,   -1,   -1,  160,   85,   -1,   13,
   -1,   -1,   90,   91,   92,   93,   94,   95,   -1,   97,
   -1,   -1,   -1,   -1,  178,  179,  180,   -1,  182,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   40,   41,   42,   -1,
   -1,   -1,   46,   -1,   -1,  123,  124,  125,   -1,   -1,
   -1,   13,   -1,   -1,   -1,  209,   60,   -1,   -1,   -1,
   -1,   -1,   24,   -1,   -1,   69,   70,   71,   72,   73,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  155,  156,   41,
   42,   85,  160,   -1,   46,   47,   -1,   -1,   50,   -1,
   52,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   60,   -1,
  178,  179,  180,   -1,  182,   13,   -1,   69,   70,   71,
   72,   -1,   -1,   -1,   -1,   -1,   24,   -1,   80,  123,
  124,  125,   -1,   85,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  209,   40,   -1,   -1,   97,   -1,   -1,   -1,   47,
   -1,   -1,   50,   -1,   52,   -1,   13,   -1,   -1,   -1,
   -1,  155,  156,   -1,   -1,   -1,  160,   24,   -1,   -1,
   -1,  123,   13,   -1,   -1,   -1,   74,   -1,   -1,   -1,
   -1,   -1,   80,   40,  178,  179,   -1,   85,  182,   -1,
   47,   -1,   -1,   50,   -1,   52,   -1,   -1,   -1,   97,
   41,   42,   -1,  155,  156,   46,   -1,   -1,  160,   50,
   -1,   52,   -1,   -1,   -1,  209,   -1,   74,   -1,   60,
   -1,  173,   41,   80,   43,  123,  178,  179,   85,   70,
   71,   -1,   -1,   52,   -1,   -1,   -1,   -1,   -1,   80,
   97,   -1,   -1,   -1,   85,   64,   65,   66,   67,   68,
   69,   70,   71,   72,   -1,   74,   97,  209,  156,   13,
   -1,   -1,  160,   -1,   -1,   -1,  123,   -1,   -1,   -1,
   24,   90,   -1,   -1,   -1,  173,   -1,  175,   -1,   -1,
  178,  179,  123,   -1,  182,   -1,   40,  185,   -1,   -1,
   -1,   -1,   -1,   47,   -1,   -1,   50,   -1,   52,  156,
   -1,   -1,   -1,  160,   -1,   -1,   13,   -1,   -1,   -1,
   -1,  209,   -1,   -1,  155,  156,  173,   -1,  175,  160,
   74,  178,  179,   -1,   -1,  182,   80,   13,  185,   -1,
   -1,   85,  173,   40,   41,   42,  155,  178,  179,   46,
   -1,   -1,   -1,   97,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  209,   -1,   40,   41,   42,   -1,   -1,   -1,
   46,   -1,   69,   70,   71,   72,   73,   -1,  209,  123,
   -1,   50,   -1,   52,   -1,   54,   55,   -1,   85,   58,
   -1,   60,   -1,   69,   70,   71,   72,   73,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   85,
   -1,   -1,  156,   -1,   -1,   -1,  160,   13,   -1,   -1,
   -1,   -1,   91,   92,   93,   94,  123,  124,  125,  173,
   -1,  175,   -1,   -1,  178,  179,   -1,   -1,  182,   -1,
   -1,  185,   -1,   -1,   40,   -1,   42,  123,  124,  125,
   46,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  156,
   -1,   -1,   -1,  160,   -1,  209,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   70,   71,   72,   73,   -1,   -1,
  156,  178,  179,   13,  160,  182,   -1,   -1,   -1,   85,
   -1,   -1,   -1,   24,   24,   -1,   -1,   -1,   -1,   -1,
   -1,   97,  178,  179,   -1,   -1,  182,   13,   -1,   40,
   40,  180,  209,   -1,   -1,   -1,   47,   47,   24,   50,
   50,   52,   52,   -1,   -1,   -1,   -1,  123,  124,  125,
   -1,   -1,   -1,  209,   40,   -1,   -1,   -1,   69,   69,
   -1,   47,   72,   -1,   50,   -1,   52,   -1,   13,   80,
   80,   13,   -1,   -1,   85,   85,   -1,   -1,   -1,   -1,
  156,   -1,   -1,   69,  160,   -1,   72,   97,   -1,   -1,
   -1,   -1,   -1,   -1,   80,   40,   -1,   -1,   40,   85,
   -1,   -1,  178,  179,   -1,   50,  182,   52,   50,   -1,
   52,   97,  123,  123,   -1,   60,   -1,   -1,   60,   -1,
   -1,   -1,   -1,   -1,   69,   -1,   71,   69,   73,   71,
   -1,   73,   -1,  209,   -1,   80,   -1,  123,   80,   -1,
   85,   -1,   -1,   85,   -1,   13,  156,   -1,   -1,  160,
  160,   -1,   97,   -1,   -1,   97,   24,   -1,   -1,   -1,
   -1,   -1,  173,  173,   -1,   -1,   -1,  178,  178,  179,
  156,   -1,   40,   -1,  160,   -1,   -1,   -1,  123,   47,
   -1,  123,   50,   -1,   52,   -1,   -1,  173,   -1,   -1,
   58,   -1,  178,  179,   -1,   -1,   -1,   -1,  209,  209,
   -1,   -1,   -1,   -1,   72,   13,   -1,   -1,   -1,   -1,
   -1,  156,   80,   -1,  156,  160,   24,   85,  160,   13,
   -1,   -1,   -1,  209,   -1,   -1,   -1,   -1,  173,   97,
   24,  173,   40,  178,  179,   -1,  178,  179,   -1,   47,
   -1,   -1,   50,   -1,   52,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   47,   -1,  123,   50,   -1,   52,   -1,
   -1,   -1,   -1,   13,  209,   -1,   -1,  209,   -1,   -1,
   -1,   -1,   80,   -1,   24,   69,   -1,   85,   72,   -1,
   -1,   -1,   -1,   -1,   13,   -1,   80,   -1,  156,   97,
   -1,   85,  160,   -1,   -1,   24,   -1,   47,   -1,   -1,
   50,   -1,   52,   97,   -1,  173,   -1,   -1,   -1,   -1,
  178,  179,   -1,   -1,   -1,  123,   -1,   -1,   47,   69,
   -1,   50,   72,   52,   -1,   -1,   -1,   -1,   -1,  123,
   80,   -1,   -1,   -1,   50,   85,   52,   -1,   54,   55,
   69,  209,   58,   72,   60,   -1,   -1,   97,  156,   -1,
   -1,   80,  160,   13,   -1,   -1,   85,   -1,   -1,   -1,
   -1,   13,  156,   -1,   24,  173,  160,   -1,   97,   -1,
  178,  179,   -1,  123,  182,   91,   92,   93,   94,  173,
   40,   -1,   -1,   -1,  178,  179,   -1,   47,   40,   -1,
   50,   -1,   52,   -1,  123,   13,   -1,   -1,   50,   -1,
   52,  209,   -1,   -1,   -1,   -1,  156,   -1,   -1,   69,
  160,   -1,   -1,   -1,   -1,  209,   -1,   -1,   -1,   -1,
   80,   -1,   40,  173,   -1,   85,   -1,  156,  178,  179,
   -1,  160,   50,   85,   52,   -1,   -1,   97,   -1,   -1,
   -1,   -1,   -1,   -1,  173,   97,   -1,   -1,   -1,  178,
  179,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  209,
   -1,   -1,   80,  123,  180,   -1,   -1,   85,   -1,   -1,
   -1,  123,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   97,
  209,   -1,   -1,   -1,   -1,   -1,   -1,   50,   -1,   52,
   -1,   54,   55,   -1,   -1,   58,  156,   60,   -1,   -1,
  160,   64,   65,   -1,  156,  123,   -1,   -1,  160,   -1,
   -1,   -1,   -1,  173,   -1,   -1,   -1,   -1,  178,  179,
   -1,  173,   -1,   -1,   -1,   -1,  178,  179,   91,   92,
   93,   94,   -1,   -1,   -1,   -1,   -1,   -1,  156,   23,
   24,   -1,  160,   -1,   -1,   -1,   30,   -1,   -1,  209,
   34,   -1,   -1,   -1,   -1,  173,   40,  209,   42,   -1,
  178,  179,   46,   47,   -1,   -1,   50,   -1,   52,   -1,
   54,   55,   -1,   58,   -1,   60,   -1,   -1,   -1,   64,
   65,   66,   67,   68,   -1,   70,   71,   -1,   -1,   74,
   -1,  209,   -1,   -1,   -1,   -1,   80,   81,   82,   83,
   84,   85,   86,   23,   24,   90,   91,   92,   93,   94,
   30,   95,   -1,   97,   34,   -1,   -1,  180,   -1,   -1,
   40,   -1,   42,   -1,   -1,   -1,   46,   47,   -1,   -1,
   50,   -1,   52,   -1,   54,   55,   -1,   -1,   -1,  123,
   -1,   -1,   -1,   -1,   50,   -1,   52,   -1,   54,   55,
   -1,   -1,   58,   -1,   60,   -1,   -1,   -1,   64,   65,
   80,   81,   82,   83,   84,   85,   86,   -1,   -1,   -1,
   -1,   -1,   -1,   23,   24,   95,  160,   97,   -1,   -1,
   30,   -1,   -1,   -1,   34,   91,   92,   93,   94,   -1,
   40,   -1,   42,   -1,  178,  180,   46,   47,   -1,   -1,
   50,   -1,   52,  123,   54,   55,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  209,   -1,   -1,   -1,   -1,
   80,   81,   82,   83,   84,   85,   86,   23,   24,   -1,
  160,   -1,   -1,   -1,   30,   95,   -1,   97,   34,   -1,
   -1,   -1,   -1,   -1,   40,   -1,   42,   -1,  178,   -1,
   46,   47,   -1,   -1,   50,   -1,   52,   -1,   54,   55,
   -1,   -1,   -1,  123,  180,   -1,   -1,   -1,   50,   -1,
   52,   -1,   54,   55,   -1,   -1,   58,   -1,   60,  209,
   -1,   -1,   64,   -1,   80,   81,   82,   83,   84,   85,
   86,   -1,   -1,   -1,   -1,   -1,   -1,   23,   24,   95,
  160,   97,   -1,   -1,   30,   -1,   -1,   -1,   34,   91,
   92,   93,   94,   -1,   40,   -1,   -1,   -1,  178,   -1,
   46,   47,   -1,   -1,   50,   -1,   52,  123,   54,   55,
   -1,   -1,   -1,   -1,   -1,   -1,  602,   -1,   -1,   -1,
  606,   -1,   -1,  609,   -1,   -1,   -1,   -1,   -1,  209,
   -1,   -1,   -1,   -1,   80,   81,   82,   83,   84,   85,
   86,   23,   24,   -1,  160,   -1,   -1,   -1,   30,   95,
   -1,   97,   34,   -1,  640,   -1,   -1,  643,   40,   -1,
   -1,  647,  178,  649,   46,   47,   -1,  653,   50,   -1,
   52,   -1,   54,   55,   -1,   -1,   -1,  123,  180,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  677,   -1,  209,   -1,   -1,   -1,  683,   80,   81,
   82,   83,   84,   85,   86,   -1,   -1,   -1,   -1,   -1,
   -1,   23,   24,   95,  160,   97,   -1,   -1,   30,   -1,
   -1,   -1,   34,   -1,   -1,   -1,  712,  713,   40,   -1,
   -1,   41,  178,   43,   46,   47,   -1,   -1,   50,   -1,
   52,  123,   54,   55,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   64,   65,   66,   67,   68,   69,
   70,   71,   72,  209,   74,   -1,   -1,   -1,   80,   81,
   82,   83,   84,   85,   86,   23,   24,   -1,  160,   -1,
   90,   -1,   30,   95,   -1,   97,   34,   -1,   -1,   -1,
   41,   -1,   40,   -1,   -1,   -1,  178,   -1,   46,   47,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   58,   -1,   60,
   -1,  123,   -1,   64,   65,   66,   67,   68,   -1,   70,
   71,   -1,   -1,   74,   -1,   -1,   13,  209,   -1,   -1,
   -1,   -1,   80,   81,   82,   83,   84,   85,   86,   90,
   91,   92,   93,   94,   -1,  155,   -1,   95,  160,   97,
   -1,   -1,   -1,   40,   41,   42,   43,   44,   45,   46,
   -1,   -1,   -1,   -1,   -1,   -1,  178,   54,   55,   -1,
   -1,   58,   -1,   60,   -1,  123,   -1,   64,   65,   66,
   67,   68,   69,   70,   71,   72,   73,   74,   -1,   -1,
   -1,   -1,   41,   -1,   -1,   -1,   -1,  209,   85,   -1,
   -1,   -1,   -1,   90,   91,   92,   93,   94,   95,   58,
   -1,   60,  160,   -1,   -1,   64,   65,   66,   67,   68,
   -1,   70,   71,   -1,   -1,   13,   -1,   -1,   -1,  180,
  178,   -1,   -1,   -1,   -1,   -1,  123,  124,  125,   -1,
   -1,   90,   91,   92,   93,   94,   -1,   -1,   -1,   -1,
   -1,   -1,   40,   41,   42,   43,   44,   45,   46,   -1,
   -1,  209,   -1,   13,   -1,   -1,   54,   55,  155,  156,
   58,   -1,   60,  160,   -1,   -1,   64,   65,   66,   67,
   68,   69,   70,   71,   72,   73,   74,   -1,   -1,   -1,
   -1,  178,  179,  180,   -1,  182,   -1,   -1,   -1,   -1,
   -1,   -1,   90,   91,   92,   93,   94,   95,   58,   -1,
   60,   -1,   -1,   -1,   64,   65,   66,   67,   68,   -1,
   70,   71,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  180,   -1,   -1,   -1,   -1,  124,  125,   -1,   -1,
   90,   91,   92,   93,   94,   -1,   58,   97,   60,   -1,
   -1,   -1,   64,   65,   66,   67,   68,   69,   70,   71,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  155,  156,   -1,
   -1,   -1,   -1,  123,   -1,   -1,   -1,   -1,   90,   91,
   92,   93,   94,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  179,  180,   -1,  182,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  155,  156,   -1,   -1,   -1,
  160,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   40,
   41,   42,   43,   44,   45,   46,   -1,   -1,  178,  179,
  180,   -1,  182,   54,   55,   -1,   -1,   58,   -1,   60,
   -1,   -1,   -1,   64,   65,   66,   67,   68,   69,   70,
   71,   72,   -1,   74,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  180,   90,
   91,   92,   93,   94,   95,   40,   41,   -1,   43,   44,
   45,   -1,   -1,   -1,   -1,   50,   -1,   52,   -1,   54,
   55,   -1,   -1,   58,   -1,   60,   -1,   -1,   -1,   64,
   65,   66,   67,   68,   69,   70,   71,   72,   -1,   74,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   90,   91,   92,   93,   94,
   95,   -1,   -1,   -1,  155,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   40,   41,   -1,   43,   44,   45,   -1,   -1,
   -1,   -1,   50,   -1,   52,   -1,   54,   55,   -1,  180,
   58,   -1,   60,   -1,   -1,   -1,   64,   65,   66,   67,
   68,   69,   70,   71,   72,   -1,   74,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  155,   -1,   90,   91,   92,   93,   94,   95,   40,   -1,
   42,   -1,   44,   45,   -1,   -1,   -1,   41,   50,   43,
   52,   -1,   54,   55,   -1,  180,   58,   -1,   60,   -1,
   -1,   -1,   64,   65,   66,   67,   68,   -1,   70,   71,
   72,   -1,   66,   67,   68,   69,   70,   71,   72,   -1,
   74,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   90,   91,
   92,   93,   94,   95,   -1,   -1,   90,  155,   -1,   40,
   -1,   42,   -1,   44,   45,   -1,   -1,   -1,   -1,   50,
   -1,   52,   -1,   54,   55,   -1,   -1,   58,   -1,   60,
   -1,   -1,  180,   64,   65,   66,   67,   68,   -1,   70,
   71,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   90,
   91,   92,   93,   94,   95,   -1,   41,   42,   43,   44,
   45,  155,   -1,   -1,   -1,   50,   -1,   52,   -1,   54,
   55,   -1,   -1,   58,   -1,   60,   -1,   -1,  180,   64,
   65,   66,   67,   68,   69,   70,   71,   72,   -1,   74,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   41,   -1,   43,   -1,   90,   91,   92,   93,   94,
   50,   -1,   52,   -1,   54,   55,   -1,   -1,   58,   -1,
   60,   -1,   -1,   -1,   64,   65,   66,   67,   68,   69,
   70,   71,   72,   -1,   74,   -1,   -1,   -1,   -1,  180,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   90,   91,   92,   93,   94,   41,   -1,   43,   -1,   -1,
   -1,   -1,   -1,   -1,   50,   -1,   52,   -1,   54,   55,
  155,   -1,   58,   -1,   60,   -1,   -1,   -1,   64,   65,
   66,   67,   68,   69,   70,   71,   72,   -1,   74,   -1,
   -1,   -1,   -1,   -1,   -1,  180,   -1,   -1,   -1,   -1,
   41,   -1,   43,   -1,   90,   91,   92,   93,   94,   50,
   -1,   52,   -1,   54,   55,  155,   -1,   58,   -1,   60,
   -1,   -1,   -1,   64,   65,   66,   67,   68,   69,   70,
   71,   72,   -1,   74,   -1,   -1,   -1,   -1,   -1,   -1,
  180,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   90,
   91,   92,   93,   94,   41,   -1,   43,   -1,   -1,   -1,
   -1,   -1,   -1,   50,   -1,   52,   -1,   54,   55,  155,
   -1,   58,   -1,   60,   -1,   -1,   -1,   64,   65,   66,
   67,   68,   69,   70,   71,   72,   -1,   74,   -1,   -1,
   -1,   -1,   -1,   -1,  180,   -1,   -1,   -1,   -1,   41,
   -1,   43,   -1,   90,   91,   92,   93,   94,   50,   -1,
   52,   -1,   54,   55,  155,   -1,   58,   -1,   60,   -1,
   -1,   -1,   64,   65,   66,   67,   68,   69,   70,   71,
   72,   -1,   74,   -1,   -1,   -1,   -1,   -1,   -1,  180,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   90,   91,
   92,   93,   94,   41,   -1,   43,   -1,   -1,   -1,   -1,
   -1,   -1,   50,   -1,   52,   -1,   54,   55,  155,   -1,
   58,   -1,   60,   -1,   -1,   -1,   64,   65,   66,   67,
   68,   69,   70,   71,   72,   -1,   74,   -1,   -1,   -1,
   -1,   -1,   -1,  180,   -1,   -1,   -1,   -1,   41,   -1,
   43,   -1,   90,   91,   92,   93,   94,   50,   -1,   52,
   -1,   54,   55,  155,   -1,   58,   -1,   60,   -1,   -1,
   -1,   64,   65,   66,   67,   68,   69,   70,   71,   72,
   -1,   74,   -1,   -1,   -1,   -1,   -1,   -1,  180,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   90,   91,   92,
   93,   94,   41,   -1,   43,   -1,   -1,   -1,   -1,   -1,
   -1,   50,   -1,   52,   -1,   54,   55,  155,   -1,   58,
   -1,   60,   -1,   -1,   -1,   64,   65,   66,   67,   68,
   69,   70,   71,   72,   -1,   74,   -1,   -1,   -1,   -1,
   -1,   -1,  180,   -1,   -1,   -1,   -1,   41,   -1,   43,
   -1,   90,   91,   92,   93,   94,   50,   -1,   52,   -1,
   54,   55,  155,   -1,   58,   -1,   60,   -1,   -1,   -1,
   64,   65,   66,   67,   68,   69,   70,   71,   72,   -1,
   74,   -1,   -1,   -1,   -1,   -1,   -1,  180,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   90,   91,   92,   93,
   94,   41,   -1,   43,   -1,   -1,   -1,   -1,   -1,   -1,
   50,   -1,   52,   -1,   54,   55,  155,   -1,   58,   -1,
   60,   -1,   -1,   -1,   64,   65,   66,   67,   68,   69,
   70,   71,   72,   -1,   74,   -1,   -1,   -1,   -1,   -1,
   -1,  180,   -1,   -1,   -1,   -1,   41,   -1,   43,   -1,
   90,   91,   92,   93,   94,   50,   -1,   52,   -1,   54,
   55,  155,   -1,   58,   -1,   60,   -1,   -1,   -1,   64,
   65,   66,   67,   68,   69,   70,   71,   72,   -1,   74,
   -1,   -1,   -1,   -1,   -1,   -1,  180,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   90,   91,   92,   93,   94,
   41,   -1,   43,   -1,   -1,   -1,   -1,   -1,   -1,   50,
   -1,   52,   -1,   54,   55,  155,   -1,   58,   -1,   60,
   -1,   -1,   -1,   64,   65,   66,   67,   68,   69,   70,
   71,   72,   -1,   74,   -1,   -1,   -1,   -1,   -1,   -1,
  180,   -1,   -1,   -1,   -1,   41,   -1,   43,   -1,   90,
   91,   92,   93,   94,   50,   -1,   52,   -1,   54,   55,
  155,   -1,   58,   -1,   60,   -1,   -1,   -1,   64,   65,
   66,   67,   68,   69,   70,   71,   72,   -1,   74,   -1,
   -1,   -1,   -1,   -1,   -1,  180,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   90,   91,   92,   93,   94,   41,
   -1,   43,   -1,   -1,   -1,   -1,   -1,   -1,   50,   -1,
   52,   -1,   54,   55,  155,   -1,   58,   -1,   60,   -1,
   -1,   -1,   64,   65,   66,   67,   68,   69,   70,   71,
   72,   -1,   74,   -1,   -1,   -1,   -1,   -1,   -1,  180,
   -1,   -1,   -1,   -1,   41,   -1,   43,   -1,   90,   91,
   92,   93,   94,   50,   -1,   52,   -1,   54,   55,  155,
   -1,   58,   -1,   60,   -1,   -1,   -1,   64,   65,   66,
   67,   68,   69,   70,   71,   72,   -1,   74,   -1,   -1,
   -1,   41,   -1,   43,  180,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   90,   91,   92,   93,   94,   58,   -1,
   60,   -1,   -1,   -1,   64,   65,   66,   67,   68,   69,
   70,   71,   72,  155,   74,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   41,   -1,   -1,   -1,
   90,   91,   92,   93,   94,   50,   -1,   52,  180,   54,
   55,   -1,   -1,   58,   -1,   60,   -1,   -1,   -1,   64,
   65,   66,   67,   68,   -1,   70,   71,   -1,  155,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   41,   -1,   90,   91,   92,   93,   94,
   -1,   -1,   50,  180,   52,   -1,   54,   55,   -1,   -1,
   58,   -1,   60,   -1,   -1,  155,   64,   65,   66,   67,
   68,   -1,   70,   71,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   41,   -1,
  180,   -1,   90,   91,   92,   93,   94,   50,   -1,   52,
   -1,   54,   55,   -1,   -1,   58,   -1,   60,   -1,   -1,
   -1,   64,   65,   66,   67,   68,   -1,   70,   71,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   41,  180,   -1,   90,   91,   92,
   93,   94,   -1,   50,   -1,   52,   -1,   54,   55,   41,
   -1,   58,   -1,   60,   -1,   -1,   -1,   64,   65,   66,
   67,   68,   -1,   70,   71,   -1,   58,   -1,   60,   -1,
   -1,   -1,   64,   65,   66,   67,   68,   -1,   70,   71,
   -1,   -1,  180,   90,   91,   92,   93,   94,   41,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   90,   91,
   92,   93,   94,   -1,   -1,   58,   -1,   60,   -1,   -1,
   -1,   64,   65,   66,   67,   68,   -1,   70,   71,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  180,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   90,   91,   92,
   93,   94,   -1,   43,   -1,   -1,   -1,   -1,   -1,   -1,
   50,   -1,   52,   -1,   54,   55,   -1,   -1,   58,   -1,
   60,   -1,   -1,  155,   64,   65,   66,   67,   68,   -1,
   70,   71,   -1,  180,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  180,   43,
   90,   91,   92,   93,   94,   -1,   50,   -1,   52,   -1,
   54,   55,  155,   -1,   58,   -1,   60,   -1,   -1,   -1,
   64,   65,   66,   67,   68,   -1,   70,   71,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  180,   -1,   -1,
   -1,   -1,   -1,   -1,   43,   -1,   90,   91,   92,   93,
   94,   50,   -1,   52,   -1,   54,   55,   -1,   -1,   58,
   -1,   60,   -1,   -1,   -1,   64,   65,   66,   67,   68,
   -1,   70,   71,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  180,   90,   91,   92,   93,   94,   43,   -1,   -1,   -1,
   -1,   -1,   -1,   50,   -1,   52,   -1,   54,   55,   -1,
   -1,   58,   -1,   60,   -1,   -1,   -1,   64,   65,   66,
   67,   68,   -1,   70,   71,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  180,   -1,   -1,   -1,
   -1,   43,   -1,   90,   91,   92,   93,   94,   50,   -1,
   52,   -1,   54,   55,   -1,   -1,   58,   -1,   60,   -1,
   -1,   -1,   64,   65,   66,   67,   68,   -1,   70,   71,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  180,   -1,   -1,   -1,   -1,   -1,   43,   90,   91,
   92,   93,   94,   -1,   50,   -1,   52,   -1,   54,   55,
   -1,   43,   58,   -1,   60,   -1,   -1,   -1,   64,   65,
   66,   67,   68,   -1,   70,   71,   58,   -1,   60,   -1,
   -1,   -1,   64,   65,   66,   67,   68,   -1,   70,   71,
   -1,   -1,   -1,  180,   90,   91,   92,   93,   94,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   90,   91,
   92,   93,   94,   50,   -1,   52,   -1,   54,   55,   -1,
   -1,   58,   -1,   60,   -1,   -1,   -1,   64,   65,   66,
   67,   68,   69,   70,   71,   72,   -1,   -1,  180,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   90,   91,   92,   93,   94,   -1,   50,
   -1,   52,   -1,   54,   55,   -1,   -1,   58,   -1,   60,
   -1,   -1,   -1,   64,   65,   66,   67,   68,   69,   70,
   71,   72,   -1,   -1,  180,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  180,   90,
   91,   92,   93,   94,   50,   -1,   52,   -1,   54,   55,
   -1,   -1,   58,   -1,   60,   -1,   -1,   -1,   64,   65,
   66,   67,   68,   69,   70,   71,   72,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  180,   90,   91,   92,   93,   94,   -1,
   50,   -1,   52,   -1,   54,   55,   -1,   -1,   58,   -1,
   60,   -1,   -1,   -1,   64,   65,   66,   67,   68,   69,
   70,   71,   72,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  180,
   90,   91,   92,   93,   94,   50,   -1,   52,   -1,   54,
   55,   -1,   -1,   58,   -1,   60,   -1,   -1,   -1,   64,
   65,   66,   67,   68,   69,   70,   71,   72,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  180,   90,   91,   92,   93,   94,
   -1,   50,   -1,   52,   -1,   54,   55,   -1,   -1,   58,
   -1,   60,   -1,   -1,   -1,   64,   65,   66,   67,   68,
   69,   70,   71,   72,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  180,   90,   91,   92,   93,   94,   50,   -1,   52,   -1,
   54,   55,   -1,   -1,   58,   -1,   60,   -1,   -1,   -1,
   64,   65,   66,   67,   68,   69,   70,   71,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  180,   90,   91,   92,   93,
   94,   -1,   50,   -1,   52,   -1,   54,   55,   -1,   -1,
   58,   -1,   60,   -1,   -1,   -1,   64,   65,   66,   67,
   68,   -1,   70,   71,   72,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  180,   90,   91,   92,   93,   94,   50,   -1,   52,
   -1,   54,   55,   -1,   -1,   58,   -1,   60,   -1,   -1,
   -1,   64,   65,   66,   67,   68,   69,   70,   71,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  180,   90,   91,   92,
   93,   94,   -1,   50,   -1,   52,   -1,   54,   55,   -1,
   -1,   58,   -1,   60,   -1,   -1,   -1,   64,   65,   66,
   67,   68,   69,   70,   71,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  180,   90,   91,   92,   93,   94,   50,   -1,
   52,   -1,   54,   55,   -1,   -1,   58,   -1,   60,   -1,
   -1,   -1,   64,   65,   66,   67,   68,   -1,   70,   71,
   72,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  180,   90,   91,
   92,   93,   94,   -1,   50,   -1,   52,   -1,   54,   55,
   -1,   -1,   58,   -1,   60,   -1,   -1,   -1,   64,   65,
   66,   67,   68,   -1,   70,   71,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  180,   90,   91,   92,   93,   94,   50,
   -1,   52,   -1,   54,   55,   -1,   -1,   58,   -1,   60,
   -1,   -1,   -1,   64,   65,   66,   67,   68,   -1,   70,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  180,   90,
   91,   92,   93,   94,   -1,   50,   -1,   52,   -1,   54,
   55,   -1,   -1,   58,   -1,   60,   -1,   -1,   -1,   64,
   65,   66,   67,   68,   50,   70,   52,   -1,   54,   55,
   -1,   -1,   58,   -1,   60,   -1,   -1,   -1,   64,   65,
   66,   67,   68,   -1,  180,   90,   91,   92,   93,   94,
   58,   -1,   60,   -1,   -1,   -1,   64,   65,   66,   67,
   68,   -1,   70,   71,   -1,   91,   92,   93,   94,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   41,
   -1,   43,   90,   91,   92,   93,   94,   -1,   50,  180,
   52,   -1,   54,   55,   -1,   -1,   58,   -1,   60,   -1,
   -1,   -1,   64,   65,   66,   67,   68,   69,   70,   71,
   72,   -1,   74,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   90,   91,
   92,   93,   94,   -1,   41,  180,   43,   -1,   -1,   -1,
   -1,   -1,   -1,   50,   -1,   52,   -1,   54,   55,   -1,
   -1,   58,   -1,   60,  180,   -1,   -1,   64,   65,   66,
   67,   68,   69,   70,   71,   72,   -1,   74,   -1,   -1,
   -1,   -1,  180,   -1,   -1,   -1,   -1,   41,   -1,   43,
   -1,   -1,   -1,   90,   91,   92,   93,   94,   52,   -1,
   54,   55,   -1,  155,   58,   -1,   60,   -1,   -1,   -1,
   64,   65,   66,   67,   68,   69,   70,   71,   72,   -1,
   74,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   90,   91,   92,   -1,
   94,   -1,   41,   -1,   43,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   52,   -1,   54,   55,   -1,  155,   58,
   -1,   60,   -1,   -1,   -1,   64,   65,   66,   67,   68,
   69,   70,   71,   72,   -1,   74,   -1,   -1,   -1,   41,
   -1,   43,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   52,   90,   91,   92,   -1,   94,   58,   -1,   60,   -1,
   -1,  155,   64,   65,   66,   67,   68,   69,   70,   71,
   72,   -1,   74,   -1,   41,   -1,   43,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   52,   -1,   -1,   90,   91,
   92,   58,   94,   60,   -1,   -1,   -1,   64,   65,   66,
   67,   68,   69,   70,   71,   72,   -1,   74,   -1,   41,
   -1,   43,   -1,   -1,   -1,   -1,  155,   -1,   -1,   -1,
   52,   -1,   -1,   90,   91,   92,   58,   -1,   60,   -1,
   -1,   -1,   64,   65,   66,   67,   68,   69,   70,   71,
   72,   -1,   74,   -1,   41,   -1,   43,   -1,   -1,   -1,
   -1,   -1,   -1,  155,   -1,   52,   -1,   -1,   90,   91,
   92,   58,   -1,   60,   -1,   -1,   -1,   64,   65,   66,
   67,   68,   69,   70,   71,   72,   -1,   74,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  155,   -1,
   -1,   -1,   -1,   90,   91,   92,  619,  620,  621,  622,
  623,  624,  625,  626,  627,  628,  629,  630,  631,  632,
  633,  634,  635,  636,  637,   -1,   -1,   -1,   -1,   -1,
   50,   -1,   52,  155,   54,   55,   -1,   -1,   58,   -1,
   60,   -1,   -1,   -1,   64,   65,   66,   67,   68,   69,
   70,   71,   72,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  155,   -1,
   90,   91,   92,   93,   94,   50,   -1,   52,  691,   54,
   55,   -1,   -1,   58,   -1,   60,   -1,   -1,   -1,   64,
   65,   66,   67,   68,   69,   70,   71,   72,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   90,   91,   92,   93,   94,
   52,   -1,   54,   55,   -1,   -1,   58,   -1,   60,   -1,
   -1,   -1,   64,   65,   66,   67,   68,   69,   70,   71,
   72,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   90,   91,
   92,   52,   94,   54,   55,   -1,   -1,   58,   -1,   60,
   -1,   -1,   -1,   64,   65,   66,   67,   68,   69,   70,
   71,   72,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   52,   -1,   -1,   90,
   91,   92,   58,   94,   60,   -1,   -1,   -1,   64,   65,
   66,   67,   68,   69,   70,   71,   72,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   52,   -1,   -1,   90,   91,   92,   58,   94,   60,
   -1,   -1,   -1,   64,   65,   66,   67,   68,   69,   70,
   71,   72,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   52,   -1,   -1,   -1,   -1,   -1,   58,   -1,   60,   90,
   91,   92,   64,   65,   66,   67,   68,   69,   70,   71,
   72,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   52,
   -1,   -1,   -1,   -1,   -1,   58,   -1,   60,   90,   91,
   92,   64,   65,   66,   67,   68,   69,   70,   71,   72,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   90,   91,   92,
};

int yyerrflag = 0;
int yychar = 0;
union YYSTYPE yyval = {0};
union YYSTYPE yylval = {0};
int yynerrs = 0;
struct __C1;

typedef struct YYSTACKDATA YYSTACKDATA;

struct YYSTACKDATA { /* sizeof YYSTACKDATA == 48 */

    unsigned int stacksize__11YYSTACKDATA;
    int *s_base__11YYSTACKDATA;
    int *s_mark__11YYSTACKDATA;
    int *s_last__11YYSTACKDATA;
    union YYSTYPE *l_base__11YYSTACKDATA;
    union YYSTYPE *l_mark__11YYSTACKDATA;
};

static struct YYSTACKDATA yystack;

extern int strcmp(const char *, const char *);

static Pname enumcheck__FP4name(Pname __1n) {
    Ptype __1tx;

    __1tx = __1n->__O1__4expr.tp;
    if (__1tx->base__4node == 97) {
        Pname __2bn;

        __2bn = (((struct basetype *)(((struct basetype *)__1tx))))->b_name__8basetype;
        __1tx = __2bn->__O1__4expr.tp;
        if ((__1tx->base__4node != 121) ||
            strcmp(__2bn->__O2__4expr.string, __1n->__O2__4expr.string)) {
            struct ea __0__V48;

            struct ea __0__V49;

            error__FPCcRC2eaN32(
                (const char *)"%n ofT%t redeclared as enum.",
                (const struct ea *)(((&__0__V48)->__O1__2ea.p = ((const void *)__1n)), (&__0__V48)),
                (const struct ea *)(((&__0__V49)->__O1__2ea.p = ((const void *)__1tx)),
                                    (&__0__V49)),
                (const struct ea *)ea0, (const struct ea *)ea0);
        }
        __1n = __2bn;
    } else if (__1tx->base__4node != 121) {
        struct ea __0__V50;

        struct ea __0__V51;

        error__FPCcRC2eaN32(
            (const char *)"%n ofT%t redeclared as enum",
            (const struct ea *)(((&__0__V50)->__O1__2ea.p = ((const void *)__1n)), (&__0__V50)),
            (const struct ea *)(((&__0__V51)->__O1__2ea.p = ((const void *)__1tx)), (&__0__V51)),
            (const struct ea *)ea0, (const struct ea *)ea0);
    }
    return __1n;
}

extern TOK lalex__Fv(void);

static void check_tag__Fv(void) {
    switch ((yychar == -1) ? ((yychar = lalex__Fv()), yychar) : yychar) {
    case 72:
    case 69:
    case 73:
        declTag = 1;
        break;
    default:
        declTag = 0;
        break;
    }
}

void hoist__6ktableFv(struct ktable *__0this);

static void hoist_al__Fv(void) {
    if (Ctbl->k_id__6ktable != 136) {
        Pktab __2otbl;

        const void *__2__X38;

        struct ea __0__X__V3700atejpkkfwcgn;

        struct ktable *__1__X52;

        const void *__2__X40;

        struct ea __0__X__V3900qmejpkkfwcpm;

        __2otbl = Ctbl;
        Ctbl =
            ((((scopex - 1) < 0)
                  ? error__FiPCcRC2eaN33(
                        (int)'i', (const char *)"parsing scope stack underflow -- current table %s",
                        (const struct ea *)((__2__X38 = (const void *)whereami__6ktableFv(Ctbl)),
                                            (((&__0__X__V3700atejpkkfwcgn)->__O1__2ea.p = __2__X38),
                                             (&__0__X__V3700atejpkkfwcgn))),
                        (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0)
                  : 0),
             (scopestack[(scopex - 1)]).ktbl__8pcontext);
        if (Ctbl->k_id__6ktable != 136)
            error__FiPCc((int)'i', (const char *)"hoist_al: noA table");

        {
            ;

            if (Ctbl == Gtbl)
                error__FiPCc((int)'i', (const char *)"bad parsing table");

            {
                Pktab __1b;

                __1b = Ctbl;

                Ctbl = Ctbl->k_next__6ktable;

                if ((__1b->k_id__6ktable == 136) || 0)
                    __dt__6ktableFv(__1b, 3);
            }
        }

        ((__1__X52 = Ctbl),
         (((((scopex - 1) < 0)
                ? error__FiPCcRC2eaN33(
                      (int)'i', (const char *)"parsing scope stack underflow -- current table %s",
                      (const struct ea *)((__2__X40 = (const void *)whereami__6ktableFv(Ctbl)),
                                          (((&__0__X__V3900qmejpkkfwcpm)->__O1__2ea.p = __2__X40),
                                           (&__0__X__V3900qmejpkkfwcpm))),
                      (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0)
                : 0),
           ((scopestack[(scopex - 1)]).ktbl__8pcontext = __1__X52)),
          (((void)0))));
        Ctbl = __2otbl;
        return;
    }
    if ((!in_typedef) && (!in_friend))
        hoist__6ktableFv(Ctbl);

    {
        ;

        if (Ctbl == Gtbl)
            error__FiPCc((int)'i', (const char *)"bad parsing table");

        {
            Pktab __1b;

            __1b = Ctbl;

            Ctbl = Ctbl->k_next__6ktable;

            if ((__1b->k_id__6ktable == 136) || 0)
                __dt__6ktableFv(__1b, 3);
        }
    }
}

extern Pname insert_name__FP4nameP6ktable(Pname, Pktab);

static void arg_redec__FP4name(Pname __1fn) {
    if ((__1fn == 0) || (__1fn->__O1__4expr.tp->base__4node != 108)) {
        struct ea __0__V53;

        struct ea __0__V54;

        error__FiPCcRC2eaN33(
            (int)'i', (const char *)"bad inline rewrite! --%n %t",
            (const struct ea *)(((&__0__V53)->__O1__2ea.p = ((const void *)__1fn)), (&__0__V53)),
            (const struct ea *)__ct__2eaFPCv(
                &__0__V54, (const void *)(__1fn ? __1fn->__O1__4expr.tp : (((struct type *)0)))),
            (const struct ea *)ea0, (const struct ea *)ea0);
    }
    if (Ctbl->k_id__6ktable != 136) {
        struct ea __0__V55;

        error__FiPCcRC2eaN33(
            (int)'i', (const char *)"arg_redec(%n ) -- noA table",
            (const struct ea *)(((&__0__V55)->__O1__2ea.p = ((const void *)__1fn)), (&__0__V55)),
            (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
    }
    {
        Pname __1al;
        Pname __1n;

        __1al = (((struct fct *)(((struct fct *)__1fn->__O1__4expr.tp))))->argtype__3fct;
        __1n = 0;
        for (; __1al; __1al = __1al->__O1__4name.n_list) {
            ;
            __1n = __ct__4nameFPCc((struct name *)0, __1al->__O2__4expr.string);
            insert_name__FP4nameP6ktable(__1n, Ctbl);
            ;
        }
    }
}

extern int error__FPCc(const char *);

struct fct *__ct__3fctFP4typeP4nameUc(struct fct *__0this, Ptype, Pname, TOK);

static Pname dummy_dtor__FUcT1(TOK __1q, TOK __1d) {
    if (__1q != __1d) {
        error__FPCc((const char *)"syntax error: inconsistent destructor notation");
        __1q = __1d;
    }
    {
        Pname __1dt;

        __1dt = __ct__4nameFPCc((struct name *)0, (const char *)"type destructor");
        __1dt->base__4node = 162;
        __1dt->__O1__4expr.tp = (struct type *)__ct__3fctFP4typeP4nameUc(
            (struct fct *)0, (struct type *)void_type, (struct name *)0, (unsigned char)1);

        __1dt->n_dcl_printed__4name = 1;
        switch (__1d) {
        default:
            error__FPCc((const char *)"syntax error: illegal destructor notation");
            __1dt->__O4__4expr.tp2 = (struct type *)any_type;
            break;
        case 5:
            __1dt->__O4__4expr.tp2 = (__1dt->__O3__4expr.tpdef = (struct type *)char_type);
            break;
        case 29:
            __1dt->__O4__4expr.tp2 = (__1dt->__O3__4expr.tpdef = (struct type *)short_type);
            break;
        case 171:
        case 21:
            __1dt->__O4__4expr.tp2 = (__1dt->__O3__4expr.tpdef = (struct type *)int_type);
            break;
        case 37:
            __1dt->__O4__4expr.tp2 = (__1dt->__O3__4expr.tpdef = (struct type *)uint_type);
            break;
        case 22:
            __1dt->__O4__4expr.tp2 = (__1dt->__O3__4expr.tpdef = (struct type *)long_type);
            break;
        case 15:
            __1dt->__O4__4expr.tp2 = (__1dt->__O3__4expr.tpdef = (struct type *)float_type);
            break;
        case 11:
            __1dt->__O4__4expr.tp2 = (__1dt->__O3__4expr.tpdef = (struct type *)double_type);
            break;
        case 38:
            __1dt->__O4__4expr.tp2 = (__1dt->__O3__4expr.tpdef = (struct type *)void_type);
            break;
        }
        return __1dt;
    }
}

static Pname dummy_dtor__Fv(void) {
    Pname __1dt;

    __1dt = __ct__4nameFPCc((struct name *)0, (const char *)"type destructor");
    __1dt->base__4node = 162;
    __1dt->__O1__4expr.tp = (struct type *)__ct__3fctFP4typeP4nameUc(
        (struct fct *)0, (struct type *)void_type, (struct name *)0, (unsigned char)1);

    __1dt->n_dcl_printed__4name = 1;
    __1dt->__O4__4expr.tp2 = 0;
    __1dt->__O3__4expr.tpdef = 0;
    return __1dt;
}

static bit check_if_base__FP8classdefT1(Pclass __1c1, Pclass __1c2);

static bit check_if_base__FP8classdefT1(Pclass __1c1, Pclass __1c2) {
    struct classdef *__1__X56;

    struct classdef *__1__X57;

    if (((__1__X56 = __1c1),
         ((__1__X57 = __1c2),
          (((__1__X56 == __1__X57)
                ? 1
                : ((__1__X56 && __1__X57)
                       ? (((int)same_class__8classdefFP8classdefi(__1__X56, __1__X57, 0)))
                       : 0))))))
        return (unsigned char)1;
    {
        {
            Pbcl __1b;

            __1b = __1c1->baselist__8classdef;

            for (; __1b; __1b = __1b->next__6basecl) {
                struct classdef *__1__X58;

                struct classdef *__1__X59;

                if (((__1__X58 = __1b->bclass__6basecl),
                     ((__1__X59 = __1c2),
                      (((__1__X58 == __1__X59)
                            ? 1
                            : ((__1__X58 && __1__X59) ? (((int)same_class__8classdefFP8classdefi(
                                                            __1__X58, __1__X59, 0)))
                                                      : 0))))))
                    return (unsigned char)1;
                if (check_if_base__FP8classdefT1(__1b->bclass__6basecl, __1c2))
                    return (unsigned char)1;
            }
            return (unsigned char)0;
        }
    }
}

extern void *realloc(void *, size_t);

static int yygrowstack__FP11YYSTACKDATA(struct YYSTACKDATA *__1data) {
    int __1i;
    unsigned int __1newsize;
    int *__1newss;
    union YYSTYPE *__1newvs;

    if ((__1newsize = __1data->stacksize__11YYSTACKDATA) == 0)
        __1newsize = 200;
    else if (__1newsize >= 600)
        return -2;
    else if ((__1newsize *= 2) > 600)
        __1newsize = 600;

    __1i = (((int)(__1data->s_mark__11YYSTACKDATA - __1data->s_base__11YYSTACKDATA)));
    __1newss = (((int *)realloc((void *)__1data->s_base__11YYSTACKDATA,
                                __1newsize * (sizeof((*__1newss))))));
    if (__1newss == 0)
        return -2;

    __1data->s_base__11YYSTACKDATA = __1newss;
    __1data->s_mark__11YYSTACKDATA = (__1newss + __1i);

    __1newvs = (((union YYSTYPE *)(((union YYSTYPE *)realloc(
        (void *)__1data->l_base__11YYSTACKDATA, __1newsize * (sizeof((*__1newvs))))))));
    if (__1newvs == 0)
        return -2;

    __1data->l_base__11YYSTACKDATA = __1newvs;
    __1data->l_mark__11YYSTACKDATA = (__1newvs + __1i);

    __1data->stacksize__11YYSTACKDATA = __1newsize;
    __1data->s_last__11YYSTACKDATA = ((__1data->s_base__11YYSTACKDATA + __1newsize) - 1);
    return 0;
}

extern void yyerror__FPCc(const char *);

extern void *memset(void *, int, size_t);

extern void set_linkage__FPCc(const char *);

struct templ_state *__ct__11templ_stateFv(struct templ_state *__0this);

void start__17templ_compilationFv(struct templ_compilation *__0this);

void enter_parameters__17templ_compilationFv(struct templ_compilation *__0this);

void end__17templ_compilationFP4name(struct templ_compilation *__0this, Pname __1class_name);

void reinit__5tableFv(struct table *__0this);

Pname aggr__8basetypeFv(struct basetype *__0this);

extern char *make_name__FUc(TOK);

struct basetype *__ct__8basetypeFUcP4name(struct basetype *__0this, TOK, Pname);

Pname normalize__4nameFP8basetypeP5blockUc(struct name *__0this, Pbase, Pblock, bit);

void argdcl__3fctFP4nameT1(struct fct *__0this, Pname, Pname);

extern Pname name_unlist__FP5nlist(struct nlist *);

struct toknode { /* sizeof toknode == 48 */
    TOK tok__7toknode;
    bit used__7toknode;
    union YYSTYPE retval__7toknode;
    Pname idname__7toknode;
    struct loc place__7toknode;
    struct toknode *next__7toknode;
    struct toknode *last__7toknode;
};

extern struct toknode *free_toks__7toknode;

extern int error__FP3locPCcRC2eaN33(struct loc *, const char *, const struct ea *,
                                    const struct ea *, const struct ea *, const struct ea *);

extern void la_backup__FUc7YYSTYPE(TOK, union YYSTYPE);

extern struct toknode *save_text__Fv(void);

void add_list__5nlistFP4name(struct nlist *__0this, Pname);

struct nlist *__ct__5nlistFP4name(struct nlist *__0this, Pname);

extern TOK la_look__Fv(void);

extern void check_decl__Fv(void);

Pname check_tname__17templ_compilationFP4name(struct templ_compilation *__0this, Pname __1p);

extern Pexpr expr_unlist__FP5elist(struct elist *);

extern Pname parametrized_typename__FP4nameP4exprUc(Pname __0p, Pexpr __0actuals, bit);

Pname tdef__4nameFv(struct name *__0this);

void del__4typeFv(struct type *__0this);

Pbase type_adj__8basetypeFUc(struct basetype *__0this, TOK);

Pbase name_adj__8basetypeFP4name(struct basetype *__0this, Pname);

Pbase base_adj__8basetypeFP8basetype(struct basetype *__0this, Pbase);

extern Pbase end_enum__FP4nameP5nlist(Pname, struct nlist *);

void collect__17templ_compilationFUcP4name(struct templ_compilation *__0this, TOK __1parm_type,
                                           Pname __1namep);
void collect__17templ_compilationFP4name(struct templ_compilation *__0this, Pname);

extern void restore_text__Fv(void);

void explicit_inst__10templ_instFv(struct templ_inst *__0this);

extern void end_cl__Fv(void);

Ptempl is_template__17templ_compilationFP4name(struct templ_compilation *__0this, Pname);

int check_actual_args__5templFP4expr(struct templ *__0this, Pexpr);

Ptempl_inst get_match__5templFP4exprP10templ_inst4bool(struct templ *__0this, Pexpr, Ptempl_inst,
                                                       int);

struct templ_inst *__ct__10templ_instFP4exprP5templUc(struct templ_inst *__0this, Pexpr __1act,
                                                      Ptempl __1owner, TOK __1csu);

extern Pname start_cl__FUcP4nameP6basecl(TOK, Pname, Pbcl);

extern void sig_name__FP4name(Pname);

extern const char *oper_name__FUc(TOK);

void hide__4nameFv(struct name *__0this);

extern void memptrdcl__FP4nameT1P4typeT1(Pname, Pname, Ptype, Pname);

extern Pstmt stmt_unlist__FP5slist(struct slist *);

extern char *strdup(const char *);

extern Ptype tok_to_type__FUc(TOK);

Pname look__6ktableFPCcUc(struct ktable *__0this, const char *, TOK);

extern void check_cast__Fv(void);

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

struct templ_state { /* sizeof templ_state == 56 */

    Plist param_end__11templ_state;
    Plist params__11templ_state;
    Pcons templ_refs__11templ_state;
    Pcons friend_templ_refs__11templ_state;
    Pcons last_cons__11templ_state;
    Pcons last_friend_cons__11templ_state;
    Ptempl owner__11templ_state;
};

void __dt__11templ_stateFv(struct templ_state *__0this, int);

int yyparse__Fv(void) {
    int __1yym;

    int __1yyn;

    int __1yystate;

    yynerrs = 0;
    yyerrflag = 0;
    yychar = -1;
    __1yystate = 0;

    if ((yystack.s_base__11YYSTACKDATA == 0) && (yygrowstack__FP11YYSTACKDATA(&yystack) == -2))
        goto yyoverflow;
    yystack.s_mark__11YYSTACKDATA = yystack.s_base__11YYSTACKDATA;
    yystack.l_mark__11YYSTACKDATA = yystack.l_base__11YYSTACKDATA;
    __1yystate = 0;
    ((*yystack.s_mark__11YYSTACKDATA)) = 0;

yyloop:
    if ((__1yyn = (yydefred[__1yystate])) != 0)
        goto yyreduce;
    if (yychar < 0) {
        yychar = lalex__Fv();
        if (yychar < 0)
            yychar = 0;
    }
    if (((((__1yyn = (yysindex[__1yystate])) != 0) && ((__1yyn += yychar) >= 0)) &&
         (__1yyn <= 8450)) &&
        ((yycheck[__1yyn]) == (((int)yychar)))) {
        if ((yystack.s_mark__11YYSTACKDATA >= yystack.s_last__11YYSTACKDATA) &&
            (yygrowstack__FP11YYSTACKDATA(&yystack) == -2))
            goto yyoverflow;
        __1yystate = (yytable[__1yyn]);
        ((*(++yystack.s_mark__11YYSTACKDATA))) = (yytable[__1yyn]);
        ((*(++yystack.l_mark__11YYSTACKDATA))) = yylval;
        yychar = -1;
        if (yyerrflag > 0)
            --yyerrflag;
        goto yyloop;
    }
    if (((((__1yyn = (yyrindex[__1yystate])) != 0) && ((__1yyn += yychar) >= 0)) &&
         (__1yyn <= 8450)) &&
        ((yycheck[__1yyn]) == (((int)yychar)))) {
        __1yyn = (yytable[__1yyn]);

        goto yyreduce;
    }
    if (yyerrflag != 0)
        goto yyinrecovery;

    yyerror__FPCc((const char *)"syntax error");

    goto yyerrlab;
yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3) {
        yyerrflag = 3;
        for (;;) {
            if (((((__1yyn = (yysindex[((*yystack.s_mark__11YYSTACKDATA))])) != 0) &&
                  ((__1yyn += 256) >= 0)) &&
                 (__1yyn <= 8450)) &&
                ((yycheck[__1yyn]) == (((int)256)))) {
                if ((yystack.s_mark__11YYSTACKDATA >= yystack.s_last__11YYSTACKDATA) &&
                    (yygrowstack__FP11YYSTACKDATA(&yystack) == -2))
                    goto yyoverflow;
                __1yystate = (yytable[__1yyn]);
                ((*(++yystack.s_mark__11YYSTACKDATA))) = (yytable[__1yyn]);
                ((*(++yystack.l_mark__11YYSTACKDATA))) = yylval;
                goto yyloop;
            } else {
                if (yystack.s_mark__11YYSTACKDATA <= yystack.s_base__11YYSTACKDATA)
                    goto yyabort;
                --yystack.s_mark__11YYSTACKDATA;
                --yystack.l_mark__11YYSTACKDATA;
            }
        }
    } else {
        if (yychar == 0)
            goto yyabort;

        yychar = -1;
        goto yyloop;
    }

yyreduce:
    __1yym = (yylen[__1yyn]);
    if (__1yym > 0)
        yyval = yystack.l_mark__11YYSTACKDATA[(1 - __1yym)];
    else
        memset((void *)(&yyval), 0, sizeof yyval);

    switch (__1yyn) {
    case 1: {
        ;

        return 2;

    }

    break;
    case 2: {
        ;

        return 1;

    }

    break;
    case 3: {
        ;

        return 0;

    }

    break;
    case 4: {
        set_linkage__FPCc((yystack.l_mark__11YYSTACKDATA[-1]).s__7YYSTYPE);
        bl_level--;
        ;

        return 1;
    }

    break;
    case 5: {
        set_linkage__FPCc((const char *)0);
        bl_level++;
        ;

        return 1;
    }

    break;
    case 6: {
        ;

        return 1;

    }

    break;
    case 7: {
        ((((Ctbl = __ct__6ktableFiP6ktableP4name((struct ktable *)0, 0, Ctbl, (struct name *)0)),
           (Ctbl->k_id__6ktable = 185))),
         (((void)0)));

        if (in_class_decl) {
            must_be_friend = 1;
            if (in_progress__17templ_compilation == 1)
                save_templ__17templ_compilation = __ct__11templ_stateFv((struct templ_state *)0);
        } else
            must_be_friend = 0;
        start__17templ_compilationFv(templp);
        formals_in_progress__17templ_compilation = 1;
    }

    break;
    case 8: {
        in_arg_list = 2;

    }

    break;
    case 9: {
        enter_parameters__17templ_compilationFv(templp);
        formals_in_progress__17templ_compilation = 0;
        in_arg_list = 0;
    }

    break;
    case 10: {
        end__17templ_compilationFP4name(templp, (yystack.l_mark__11YYSTACKDATA[0]).pn__7YYSTYPE);

        {
            ;

            if (Ctbl == Gtbl)
                error__FiPCc((int)'i', (const char *)"bad parsing table");

            {
                Pktab __1b;

                __1b = Ctbl;

                Ctbl = Ctbl->k_next__6ktable;

                if ((__1b->k_id__6ktable == 136) || 0)
                    __dt__6ktableFv(__1b, 3);
            }
        }

        if (in_class_decl && save_templ__17templ_compilation) {
            __dt__11templ_stateFv(save_templ__17templ_compilation, 3);
            save_templ__17templ_compilation = 0;
        } else {
            in_progress__17templ_compilation = 0;
            reinit__5tableFv(bound_expr_tbl);
        }

    }

    break;
    case 12: {
        goto mod;

    }

    break;
    case 13: {
        goto mod;

    }

    break;
    case 15: {
        Pname __3pn;

        __3pn = aggr__8basetypeFv((yystack.l_mark__11YYSTACKDATA[-1]).pb__7YYSTYPE);

        yyval.p__7YYSTYPE = (struct node *)(__3pn ? __3pn
                                                  : (yystack.l_mark__11YYSTACKDATA[-1])
                                                        .pb__7YYSTYPE->b_name__8basetype);
        DECL_TYPE = 0;
    }

    break;
    case 17: {
        struct name *__1__X101;

        struct name *__1__Xnn00qycjpkkfwcaj;

        yyval.pn__7YYSTYPE = ((__1__X101 = (yystack.l_mark__11YYSTACKDATA[0]).pn__7YYSTYPE),
                              (((__1__X101->base__4node != 123)
                                    ? ((__1__Xnn00qycjpkkfwcaj = __1__X101), 0)
                                    : ((__1__Xnn00qycjpkkfwcaj = __ct__4nameFPCc(
                                            (struct name *)0, __1__X101->__O2__4expr.string)),
                                       (__1__Xnn00qycjpkkfwcaj->n_template_arg__4name =
                                            __1__X101->n_template_arg__4name))),
                               __1__Xnn00qycjpkkfwcaj));

    }

    break;
    case 18: {
        if ((yystack.l_mark__11YYSTACKDATA[0]).pn__7YYSTYPE == 0)
            yyval.i__7YYSTYPE = 1;
    }

    break;
    case 19: {
        goto mod;

    }

    break;
    case 20: {
    mod: {
        Pname __3n;

        __3n = (yystack.l_mark__11YYSTACKDATA[0]).pn__7YYSTYPE;
        if (__3n && __3n->__O2__4name.n_qualifier) {
            if (__3n->__O2__4name.n_qualifier->n_template_arg__4name != 1)
                UNSET_SCOPE__Fv();
            if (__3n->__O2__4name.n_qualifier == sta_name)
                __3n->__O2__4name.n_qualifier = 0;
        }
    }
    }

    break;
    case 22: {
        Pname __3n;

        __3n = __ct__4nameFPCc((struct name *)0, (const char *)make_name__FUc((unsigned char)'A'));
        __3n->__O1__4expr.tp = (struct type *)__ct__8basetypeFUcP4name(
            (struct basetype *)0, (unsigned char)1, (struct name *)0);
        (((struct basetype *)(((struct basetype *)__3n->__O1__4expr.tp))))->b_name__8basetype =
            (((struct name *)(((struct name *)(yystack.l_mark__11YYSTACKDATA[-2]).s__7YYSTYPE))));
        yyval.p__7YYSTYPE = (struct node *)__3n;
    }

    break;
    case 23: {
        err_name = (yystack.l_mark__11YYSTACKDATA[-3]).pn__7YYSTYPE;
        if (err_name)
            err_name->__O3__4expr.n_initializer = (yystack.l_mark__11YYSTACKDATA[-1]).pe__7YYSTYPE;
        goto fix;
    }

    break;
    case 24: {
        Ptype __3t;
        err_name = (yystack.l_mark__11YYSTACKDATA[-1]).pn__7YYSTYPE;
    fix:
        if (err_name == 0) {
            error__FPCc((const char *)"syntax error:TX");
            yyval.p__7YYSTYPE = (struct node *)normalize__4nameFP8basetypeP5blockUc(
                err_name, ((struct basetype *)(((struct basetype *)defa_type))), (struct block *)0,
                (unsigned char)0);

        } else if ((__3t = err_name->__O1__4expr.tp) == 0) {
            const void *__2__X102;

            {
                struct ea __0__V60;

                error__FPCcRC2eaN32(
                    (const char *)"TX for%n",
                    (const struct ea *)((__2__X102 = (const void *)err_name),
                                        (((&__0__V60)->__O1__2ea.p = __2__X102), (&__0__V60))),
                    (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
                yyval.p__7YYSTYPE = (struct node *)normalize__4nameFP8basetypeP5blockUc(
                    err_name, ((struct basetype *)(((struct basetype *)defa_type))),
                    (struct block *)0, (unsigned char)0);
            }
        } else if (__3t->base__4node == 108) {
            if ((((struct fct *)(((struct fct *)__3t))))->returns__3fct == 0)
                yyval.p__7YYSTYPE = (struct node *)normalize__4nameFP8basetypeP5blockUc(
                    err_name, ((struct basetype *)(((struct basetype *)defa_type))),
                    ((struct block *)0), (unsigned char)0);
            else
                yyval.p__7YYSTYPE = (struct node *)normalize__4nameFP8basetypeP5blockUc(
                    err_name, ((struct basetype *)0), (struct block *)0, (unsigned char)0);

        } else {
            unsigned long __2__X103;

            const void *__2__X104;

            {
                struct ea __0__V61;

                struct ea __0__V62;

                error__FPCcRC2eaN32(
                    (const char *)"syntax error:TX for%k%n",
                    (const struct ea *)((__2__X103 = __3t->base__4node),
                                        (((((&__0__V61)->__O1__2ea.i = __2__X103), 0)),
                                         (&__0__V61))),
                    (const struct ea *)((__2__X104 = (const void *)err_name),
                                        (((&__0__V62)->__O1__2ea.p = __2__X104), (&__0__V62))),
                    (const struct ea *)ea0, (const struct ea *)ea0);
                yyval.p__7YYSTYPE = (struct node *)normalize__4nameFP8basetypeP5blockUc(
                    err_name, ((struct basetype *)(((struct basetype *)defa_type))),
                    (struct block *)0, (unsigned char)0);
            }
        }
        if (err_name && err_name->__O2__4name.n_qualifier) {
            if (err_name->__O2__4name.n_qualifier->n_template_arg__4name != 1)
                UNSET_SCOPE__Fv();
            if (err_name->__O2__4name.n_qualifier == sta_name)
                err_name->__O2__4name.n_qualifier = 0;
        }
    }

    break;
    case 25: {
        if (yychar == 73)
            --bl_level;
        {
            Pname __3n;

            __3n = normalize__4nameFP8basetypeP5blockUc(
                (yystack.l_mark__11YYSTACKDATA[-2]).pn__7YYSTYPE,
                ((struct basetype *)((
                    (struct basetype *)(yystack.l_mark__11YYSTACKDATA[-3]).p__7YYSTYPE))),
                ((struct block *)(((struct block *)dummy))), (unsigned char)0);
            argdcl__3fctFP4nameT1(
                ((struct fct *)(((struct fct *)__3n->__O1__4expr.tp))),
                name_unlist__FP5nlist((yystack.l_mark__11YYSTACKDATA[-1]).nl__7YYSTYPE), __3n);
            arg_redec__FP4name((yystack.l_mark__11YYSTACKDATA[-2]).pn__7YYSTYPE);
            yyval.pn__7YYSTYPE = __3n;
            if (yychar == 73)
                ++bl_level;
            Ctbl->k_name__6ktable = __3n;
        }
    }

    break;
    case 26: {
        Pname __3n;

        __3n = (yystack.l_mark__11YYSTACKDATA[-2]).pn__7YYSTYPE;
        if (!in_typedef) {
            (((struct fct *)(((struct fct *)__3n->__O1__4expr.tp))))->body__3fct = (((
                struct block *)(((struct block *)(yystack.l_mark__11YYSTACKDATA[0]).p__7YYSTYPE))));
            (((struct fct *)(((struct fct *)__3n->__O1__4expr.tp))))->f_init__3fct =
                (yystack.l_mark__11YYSTACKDATA[-1]).pn__7YYSTYPE;
        }
        yyval.p__7YYSTYPE = (struct node *)__3n;
        must_be_id = 0;
    }

    break;
    case 27: {
        Pname __3n;

        __3n = normalize__4nameFP8basetypeP5blockUc(
            (yystack.l_mark__11YYSTACKDATA[-3]).pn__7YYSTYPE,
            ((struct basetype *)((
                (struct basetype *)(yystack.l_mark__11YYSTACKDATA[-4]).p__7YYSTYPE))),
            ((struct block *)(((struct block *)dummy))), (unsigned char)0);
        argdcl__3fctFP4nameT1(
            ((struct fct *)(((struct fct *)__3n->__O1__4expr.tp))),
            name_unlist__FP5nlist((yystack.l_mark__11YYSTACKDATA[-2]).nl__7YYSTYPE), __3n);
        (yystack.l_mark__11YYSTACKDATA[0]).q__7YYSTYPE->retval__7toknode.pn__7YYSTYPE = __3n;
        yyval.p__7YYSTYPE = (struct node *)__3n;
        must_be_id = 0;
    }

    break;
    case 28: {
        if (!in_progress__17templ_compilation)
            error__FP3locPCcRC2eaN33(
                &(yystack.l_mark__11YYSTACKDATA[-3]).pn__7YYSTYPE->where__4name,
                (const char *)"syntax error -- did you forget a ';'?", (const struct ea *)ea0,
                (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
        {
            Pname __3n;

            __3n = normalize__4nameFP8basetypeP5blockUc(
                (yystack.l_mark__11YYSTACKDATA[-3]).pn__7YYSTYPE,
                ((struct basetype *)((
                    (struct basetype *)(yystack.l_mark__11YYSTACKDATA[-4]).p__7YYSTYPE))),
                ((struct block *)0), (unsigned char)0);
            yyval.p__7YYSTYPE = (struct node *)__3n;
            must_be_id = 0;
        }
    }

    break;
    case 29: {
        if (yychar == 73)
            --bl_level;
        {
            Pname __3n;

            __3n = normalize__4nameFP8basetypeP5blockUc(
                (yystack.l_mark__11YYSTACKDATA[-2]).pn__7YYSTYPE,
                ((struct basetype *)(((struct basetype *)defa_type))),
                ((struct block *)(((struct block *)dummy))), (unsigned char)0);
            argdcl__3fctFP4nameT1(
                ((struct fct *)(((struct fct *)__3n->__O1__4expr.tp))),
                name_unlist__FP5nlist((yystack.l_mark__11YYSTACKDATA[-1]).nl__7YYSTYPE), __3n);
            arg_redec__FP4name((yystack.l_mark__11YYSTACKDATA[-2]).pn__7YYSTYPE);
            yyval.pn__7YYSTYPE = __3n;
            if (yychar == 73)
                ++bl_level;
            Ctbl->k_name__6ktable = __3n;
        }
    }

    break;
    case 30: {
        Pname __3n;

        const void *__2__X105;

        __3n = (yystack.l_mark__11YYSTACKDATA[-2]).pn__7YYSTYPE;
        (((struct fct *)(((struct fct *)__3n->__O1__4expr.tp))))->body__3fct =
            (((struct block *)(((struct block *)(yystack.l_mark__11YYSTACKDATA[0]).p__7YYSTYPE))));
        if ((((yystack.l_mark__11YYSTACKDATA[-1]).pn__7YYSTYPE &&
              (yystack.l_mark__11YYSTACKDATA[-1]).pn__7YYSTYPE->__O1__4name.n_list) &&
             ccl) &&
            (ccl->csu__8classdef == 36)) {
            struct ea __0__V63;

            struct ea __0__V64;

            error__FPCcRC2eaN32(
                (const char *)"multiple initializers in unionK %s::%n",
                (const struct ea *)((__2__X105 = (const void *)(yystack.l_mark__11YYSTACKDATA[-5])
                                                     .pn__7YYSTYPE->__O2__4expr.string),
                                    (((&__0__V63)->__O1__2ea.p = __2__X105), (&__0__V63))),
                (const struct ea *)__ct__2eaFPCv(
                    &__0__V64, (const void *)(yystack.l_mark__11YYSTACKDATA[-5]).pn__7YYSTYPE),
                (const struct ea *)ea0, (const struct ea *)ea0);
        }
        (((struct fct *)(((struct fct *)__3n->__O1__4expr.tp))))->f_init__3fct =
            (yystack.l_mark__11YYSTACKDATA[-1]).pn__7YYSTYPE;
        yyval.p__7YYSTYPE = (struct node *)__3n;
        must_be_id = 0;
    }

    break;
    case 31: {
        Pname __3n;

        __3n = normalize__4nameFP8basetypeP5blockUc(
            (yystack.l_mark__11YYSTACKDATA[-3]).pn__7YYSTYPE,
            ((struct basetype *)(((struct basetype *)defa_type))),
            ((struct block *)(((struct block *)dummy))), (unsigned char)0);
        argdcl__3fctFP4nameT1(
            ((struct fct *)(((struct fct *)__3n->__O1__4expr.tp))),
            name_unlist__FP5nlist((yystack.l_mark__11YYSTACKDATA[-2]).nl__7YYSTYPE), __3n);
        (yystack.l_mark__11YYSTACKDATA[0]).q__7YYSTYPE->retval__7toknode.pn__7YYSTYPE = __3n;
        yyval.p__7YYSTYPE = (struct node *)__3n;
        must_be_id = 0;
    }

    break;
    case 32: {
        const void *__2__X106;

        if (explicit_template_definition == 0) {
            struct ea __0__V65;

            error__FP3locPCcRC2eaN33(
                &(yystack.l_mark__11YYSTACKDATA[-3]).pn__7YYSTYPE->where__4name,
                (const char *)"badD of%n -- did you forget a ';'?",
                (const struct ea *)((__2__X106 = (const void *)(yystack.l_mark__11YYSTACKDATA[-3])
                                                     .pn__7YYSTYPE),
                                    (((&__0__V65)->__O1__2ea.p = __2__X106), (&__0__V65))),
                (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
        } else {
            Pname __4n;

            struct basic_inst *__0__X107;

            __4n = ((__0__X107 = (struct basic_inst *)pti), (__0__X107->tname__10basic_inst));
            if ((yystack.l_mark__11YYSTACKDATA[-3]).pn__7YYSTYPE->n_oper__4name == 162) {
                struct ea __0__V66;

                error__FiPCcRC2eaN33(
                    (int)'s',
                    (const char *)"explicitYZL for destructor of specializedYC%n -- please drop "
                                  "the parameter list",
                    (const struct ea *)(((&__0__V66)->__O1__2ea.p = ((const void *)__4n)),
                                        (&__0__V66)),
                    (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
            } else {
                struct ea __0__V67;

                struct ea __0__V68;

                error__FiPCcRC2eaN33(
                    (int)'i', (const char *)"specialializedYC%n: declaration problem: %s",
                    (const struct ea *)(((&__0__V67)->__O1__2ea.p = ((const void *)__4n)),
                                        (&__0__V67)),
                    (const struct ea *)__ct__2eaFPCv(
                        &__0__V68, (const void *)(yystack.l_mark__11YYSTACKDATA[-3])
                                       .pn__7YYSTYPE->__O2__4expr.string),
                    (const struct ea *)ea0, (const struct ea *)ea0);
            }
            error__FiPCc((int)'i', (const char *)"cannot recover from previous error");
        }
        {
            Pname __3n;

            __3n = normalize__4nameFP8basetypeP5blockUc(
                (yystack.l_mark__11YYSTACKDATA[-3]).pn__7YYSTYPE,
                ((struct basetype *)(((struct basetype *)defa_type))), ((struct block *)0),
                (unsigned char)0);

            yyval.p__7YYSTYPE = (struct node *)__3n;
            must_be_id = 0;
        }
    }

    break;
    case 33: {
        ((((Ctbl = __ct__6ktableFiP6ktableP4name((struct ktable *)0, 0, Ctbl, (struct name *)0)),
           (Ctbl->k_id__6ktable = 136))),
         (((void)0)));
        arg_redec__FP4name((yystack.l_mark__11YYSTACKDATA[0]).pn__7YYSTYPE);
        Ctbl->k_name__6ktable = (yystack.l_mark__11YYSTACKDATA[0]).pn__7YYSTYPE;
    }

    break;
    case 34: {
        (((struct fct *)((
             (struct fct *)(yystack.l_mark__11YYSTACKDATA[-3]).pn__7YYSTYPE->__O1__4expr.tp))))
            ->f_init__3fct = (yystack.l_mark__11YYSTACKDATA[-1]).pn__7YYSTYPE;
        (((struct fct *)((
             (struct fct *)(yystack.l_mark__11YYSTACKDATA[-3]).pn__7YYSTYPE->__O1__4expr.tp))))
            ->body__3fct =
            (((struct block *)(((struct block *)(yystack.l_mark__11YYSTACKDATA[0]).p__7YYSTYPE))));
        yyval.pn__7YYSTYPE = (yystack.l_mark__11YYSTACKDATA[-3]).pn__7YYSTYPE;
        must_be_id = 0;
    }

    break;
    case 35: {
        if (Ctbl->k_id__6ktable != 136)
            error__FiPCc((int)'i', (const char *)"expectingA table in check_inline!");
        switch ((yychar == -1) ? ((yychar = lalex__Fv()), yychar) : yychar) {
        case 73:
        case 69:
            if (in_class_decl) {
                la_backup__FUc7YYSTYPE((unsigned char)yychar, yylval);

                la_backup__FUc7YYSTYPE((unsigned char)127, yylval);
                if (yylval.q__7YYSTYPE = save_text__Fv()) {
                    yychar = 124;

                    {
                        ;

                        if (Ctbl == Gtbl)
                            error__FiPCc((int)'i', (const char *)"bad parsing table");

                        {
                            Pktab __1b;

                            __1b = Ctbl;

                            Ctbl = Ctbl->k_next__6ktable;

                            if ((__1b->k_id__6ktable == 136) || 0)
                                __dt__6ktableFv(__1b, 3);
                        }
                    }

                } else {
                    lalex__Fv();
                    lalex__Fv();
                    yychar = 125;
                    hoist_al__Fv();
                }
            }

            break;
        default:
            la_backup__FUc7YYSTYPE((unsigned char)yychar, yylval);
            yychar = 125;
            hoist_al__Fv();
            break;
        }
    }

    break;
    case 36: {
        ++in_binit_list;

    }

    break;
    case 37: {
        yyval.p__7YYSTYPE = (yystack.l_mark__11YYSTACKDATA[0]).p__7YYSTYPE;
        in_arg_list = 0;
        --in_binit_list;
    }

    break;
    case 38: {
        yyval.p__7YYSTYPE = 0;

    }

    break;
    case 39: {
        yyval.p__7YYSTYPE = (yystack.l_mark__11YYSTACKDATA[0]).p__7YYSTYPE;

    }

    break;
    case 40: {
        yyval.pn__7YYSTYPE = (yystack.l_mark__11YYSTACKDATA[0]).pn__7YYSTYPE;

        yyval.pn__7YYSTYPE->__O1__4name.n_list = (yystack.l_mark__11YYSTACKDATA[-2]).pn__7YYSTYPE;

    }

    break;
    case 41: {
        yyval.pn__7YYSTYPE = __ct__4nameFPCc((struct name *)0, (const char *)0);
        yyval.pn__7YYSTYPE->__O3__4expr.n_initializer =
            (yystack.l_mark__11YYSTACKDATA[-1]).pe__7YYSTYPE;
    }

    break;
    case 42: {
        Pname __3n;

        struct name *__1__X108;

        struct name *__1__Xnn00qycjpkkfwcaj;

        __3n = ((__1__X108 = (yystack.l_mark__11YYSTACKDATA[-3]).pn__7YYSTYPE),
                (((__1__X108->base__4node != 123)
                      ? ((__1__Xnn00qycjpkkfwcaj = __1__X108), 0)
                      : ((__1__Xnn00qycjpkkfwcaj =
                              __ct__4nameFPCc((struct name *)0, __1__X108->__O2__4expr.string)),
                         (__1__Xnn00qycjpkkfwcaj->n_template_arg__4name =
                              __1__X108->n_template_arg__4name))),
                 __1__Xnn00qycjpkkfwcaj));
        __3n->base__4node = (yystack.l_mark__11YYSTACKDATA[-3]).pn__7YYSTYPE->base__4node;
        __3n->__O1__4expr.tp = (yystack.l_mark__11YYSTACKDATA[-3]).pn__7YYSTYPE->__O1__4expr.tp;
        __3n->__O3__4expr.n_initializer = (yystack.l_mark__11YYSTACKDATA[-1]).pe__7YYSTYPE;
        yyval.pn__7YYSTYPE = __3n;
    }

    break;
    case 43: {
        const void *__2__X109;

        if ((yystack.l_mark__11YYSTACKDATA[0]).pn__7YYSTYPE == 0)
            error__FPCc((const char *)"badAD");
        else if ((yystack.l_mark__11YYSTACKDATA[0]).pn__7YYSTYPE->__O1__4expr.tp->base__4node ==
                 108) {
            struct ea __0__V69;

            error__FPCcRC2eaN32(
                (const char *)"FD inAL (%n)",
                (const struct ea *)((__2__X109 = (const void *)(yystack.l_mark__11YYSTACKDATA[0])
                                                     .pn__7YYSTYPE),
                                    (((&__0__V69)->__O1__2ea.p = __2__X109), (&__0__V69))),
                (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
        } else if ((yystack.l_mark__11YYSTACKDATA[-1]).p__7YYSTYPE)
            add_list__5nlistFP4name((yystack.l_mark__11YYSTACKDATA[-1]).nl__7YYSTYPE,
                                    (yystack.l_mark__11YYSTACKDATA[0]).pn__7YYSTYPE);
        else
            yyval.nl__7YYSTYPE = __ct__5nlistFP4name(
                (struct nlist *)0, (yystack.l_mark__11YYSTACKDATA[0]).pn__7YYSTYPE);
    }

    break;
    case 44: {
        ((((Ctbl = __ct__6ktableFiP6ktableP4name((struct ktable *)0, 0, Ctbl, (struct name *)0)),
           (Ctbl->k_id__6ktable = 136))),
         (((void)0)));
        yyval.p__7YYSTYPE = 0;
    }

    break;
    case 46: {
        if (in_typedef) {
            error__FPCc((const char *)"Tdef field");
            in_typedef = 0;
        }

    }

    break;
    case 47: {
        yyval.p__7YYSTYPE = (struct node *)(yystack.l_mark__11YYSTACKDATA[-3]).pn__7YYSTYPE;
        yyval.pn__7YYSTYPE->__O1__4expr.tp = (struct type *)__ct__8basetypeFUcP4name(
            (struct basetype *)0, (unsigned char)114,
            (yystack.l_mark__11YYSTACKDATA[0]).pn__7YYSTYPE);

    }

    break;
    case 48: {
        yyval.p__7YYSTYPE = (struct node *)__ct__4nameFPCc((struct name *)0, (const char *)0);
        yyval.pn__7YYSTYPE->__O1__4expr.tp = (struct type *)__ct__8basetypeFUcP4name(
            (struct basetype *)0, (unsigned char)114,
            (yystack.l_mark__11YYSTACKDATA[0]).pn__7YYSTYPE);

        if (in_typedef) {
            error__FPCc((const char *)"Tdef field");
            in_typedef = 0;
        }
    }

    break;
    case 49: {
    }

    break;
    case 50: {
        Pexpr __3e;

        __3e = (yystack.l_mark__11YYSTACKDATA[0]).pe__7YYSTYPE;
        if (__3e == dummy)
            error__FPCc((const char *)"emptyIr");
        (yystack.l_mark__11YYSTACKDATA[-3]).pn__7YYSTYPE->__O3__4expr.n_initializer = __3e;
        init_seen = 0;
    }

    break;
    case 51: {
        Pname __3n;

        __3n = (yystack.l_mark__11YYSTACKDATA[0]).pn__7YYSTYPE;
        if (__3n) {
            yyval.nl__7YYSTYPE = __ct__5nlistFP4name((struct nlist *)0, __3n);
            if (__3n->__O2__4name.n_qualifier) {
                if (__3n->__O2__4name.n_qualifier->n_template_arg__4name != 1)
                    UNSET_SCOPE__Fv();
                if (__3n->__O2__4name.n_qualifier == sta_name)
                    __3n->__O2__4name.n_qualifier = 0;
            }
        }
        if ((((yychar == -1) ? ((yychar = lalex__Fv()), yychar) : yychar) == 71) &&
            (la_look__Fv() == 123))
            must_be_id = 1;
    }

    break;
    case 52: {
        Pname __3n;

        register struct nlist *__0__X110;

        __3n = (yystack.l_mark__11YYSTACKDATA[0]).pn__7YYSTYPE;
        if ((yystack.l_mark__11YYSTACKDATA[-2]).p__7YYSTYPE)
            if (__3n)
                ((__0__X110 = (yystack.l_mark__11YYSTACKDATA[-2]).nl__7YYSTYPE),
                 (((__0__X110->tail__5nlist->__O1__4name.n_list = __3n),
                   (__0__X110->tail__5nlist = __3n)),
                  (((void)0))));
            else
                error__FPCc((const char *)"DL syntax");
        else {
            if (__3n)
                yyval.nl__7YYSTYPE = __ct__5nlistFP4name((struct nlist *)0, __3n);
            error__FPCc((const char *)"DL syntax");
        }
        if (__3n) {
            if (__3n->__O2__4name.n_qualifier) {
                if (__3n->__O2__4name.n_qualifier->n_template_arg__4name != 1)
                    UNSET_SCOPE__Fv();
                if (__3n->__O2__4name.n_qualifier == sta_name)
                    __3n->__O2__4name.n_qualifier = 0;
            }
        }
        if ((((yychar == -1) ? ((yychar = lalex__Fv()), yychar) : yychar) == 71) &&
            (la_look__Fv() == 123))
            must_be_id = 1;
    }

    break;
    case 53: {
        extern int co_hack;
        co_hack = 1;

        {
            Pname __3n;

            __3n = normalize__4nameFP8basetypeP5blockUc(
                name_unlist__FP5nlist((yystack.l_mark__11YYSTACKDATA[-1]).nl__7YYSTYPE),
                ((struct basetype *)((
                    (struct basetype *)(yystack.l_mark__11YYSTACKDATA[-2]).p__7YYSTYPE))),
                (struct block *)0, (unsigned char)0);

            in_typedef = 0;
            in_friend = 0;
            in_tag = 0;
            co_hack = 0;
            DECL_TYPE = 0;
            yyval.p__7YYSTYPE = (struct node *)__3n;
        }
    }

    break;
    case 54: {
        yyval.p__7YYSTYPE =
            (struct node *)aggr__8basetypeFv((yystack.l_mark__11YYSTACKDATA[-1]).pb__7YYSTYPE);
        in_typedef = 0;
        in_friend = 0;
        in_tag = 0;
        DECL_TYPE = 0;
    }

    break;
    case 55: {
        parameters_in_progress__17templ_compilation++;
        in_arg_list = 2;
        check_decl__Fv();
    }

    break;
    case 56: {
        parameters_in_progress__17templ_compilation--;
        if (!parameters_in_progress__17templ_compilation)
            in_arg_list = 0;
    }

    break;
    case 57: {
        yyval.pn__7YYSTYPE = check_tname__17templ_compilationFP4name(
            templp, (yystack.l_mark__11YYSTACKDATA[0]).pn__7YYSTYPE);

    }

    break;
    case 58: {
        int __3sm;

        __3sm = (((yychar == -1) ? ((yychar = lalex__Fv()), yychar) : yychar) == 72);
        if (in_friend)
            in_friend += __3sm;
        {
            bit __3flag;

            __3flag = 0;
            if (((dtpt_opt && in_typedef) && (!parameters_in_progress__17templ_compilation)) &&
                (curloc.file__3loc == first_file))
                __3flag = 1;

            yyval.pn__7YYSTYPE = parametrized_typename__FP4nameP4exprUc(
                (yystack.l_mark__11YYSTACKDATA[-3]).pn__7YYSTYPE,
                expr_unlist__FP5elist((yystack.l_mark__11YYSTACKDATA[-1]).el__7YYSTYPE),
                (unsigned char)in_friend);
            if (__3flag)
                righttname = yyval.pn__7YYSTYPE;
        }
    }

    break;
    case 59: {
        extern Pbase any_type;

        const void *__2__X111;

        {
            struct ea __0__V70;

            error__FPCcRC2eaN32(
                (const char *)"%n was not aZizedT.",
                (const struct ea *)((__2__X111 = (const void *)yyval.pn__7YYSTYPE),
                                    (((&__0__V70)->__O1__2ea.p = __2__X111), (&__0__V70))),
                (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
            yyval.pn__7YYSTYPE = tdef__4nameFv((yystack.l_mark__11YYSTACKDATA[-3]).pn__7YYSTYPE);
            yyval.pn__7YYSTYPE->__O1__4expr.tp = (struct type *)any_type;
        }
    }

    break;
    case 60: {
        yyval.p__7YYSTYPE = (struct node *)__ct__8basetypeFUcP4name(
            (struct basetype *)0, (yystack.l_mark__11YYSTACKDATA[0]).t__7YYSTYPE, (struct name *)0);

        if ((yystack.l_mark__11YYSTACKDATA[0]).t__7YYSTYPE == 35) {
            in_typedef = yyval.pt__7YYSTYPE;

        } else if ((yystack.l_mark__11YYSTACKDATA[0]).t__7YYSTYPE == 18) {
            in_friend = 1;
            must_be_friend = 0;
        }
        if (DECL_TYPE == -1)
            DECL_TYPE = 0;
    }

    break;
    case 61: {
        yyval.p__7YYSTYPE = (struct node *)__ct__8basetypeFUcP4name(
            (struct basetype *)0, (unsigned char)14, (struct name *)0);

        yyval.pb__7YYSTYPE->__O1__8basetype.b_linkage =
            (yystack.l_mark__11YYSTACKDATA[0]).s__7YYSTYPE;
        if (DECL_TYPE == -1)
            DECL_TYPE = 0;
    }

    break;
    case 62: {
        yyval.p__7YYSTYPE = (struct node *)__ct__8basetypeFUcP4name(
            (struct basetype *)0, (unsigned char)97,
            (yystack.l_mark__11YYSTACKDATA[0]).pn__7YYSTYPE);
        if (DECL_TYPE == -1)
            DECL_TYPE = 0;
    }

    break;
    case 63: {
        yyval.p__7YYSTYPE = (struct node *)__ct__8basetypeFUcP4name(
            (struct basetype *)0, (unsigned char)97,
            (yystack.l_mark__11YYSTACKDATA[0]).pn__7YYSTYPE);

        if (DECL_TYPE == -1)
            DECL_TYPE = 0;
    }

    break;
    case 66: {
        if (DECL_TYPE == 123)
            yyval.p__7YYSTYPE = (struct node *)__ct__8basetypeFUcP4name(
                (struct basetype *)0, (unsigned char)97,
                (yystack.l_mark__11YYSTACKDATA[0]).pn__7YYSTYPE);
        else if ((DECL_TYPE == 0) &&
                 ((yystack.l_mark__11YYSTACKDATA[0]).p__7YYSTYPE->base__4node == 123))
            yyval.p__7YYSTYPE = (struct node *)__ct__8basetypeFUcP4name(
                (struct basetype *)0, (unsigned char)97,
                (yystack.l_mark__11YYSTACKDATA[0]).pn__7YYSTYPE);
        else
            yyval.p__7YYSTYPE = (struct node *)__ct__8basetypeFUcP4name(
                (struct basetype *)0, (yystack.l_mark__11YYSTACKDATA[0]).t__7YYSTYPE,
                (struct name *)0);
        DECL_TYPE = -1;
    }

    break;
    case 68: {
        if (DECL_TYPE != -1) {
            switch ((yystack.l_mark__11YYSTACKDATA[-1]).pb__7YYSTYPE->base__4node) {
            case 119:
            case 121: {
                Pbase __5bt;

                __5bt = __ct__8basetypeFUcP4name((struct basetype *)0, (unsigned char)0,
                                                 (struct name *)0);
                ((*__5bt)) = (*(yystack.l_mark__11YYSTACKDATA[-1]).pb__7YYSTYPE);
                if ((yystack.l_mark__11YYSTACKDATA[-1]).pb__7YYSTYPE &&
                    ((yystack.l_mark__11YYSTACKDATA[-1]).pb__7YYSTYPE->permanent__4node == 0))
                    del__4typeFv((struct type *)(yystack.l_mark__11YYSTACKDATA[-1]).pb__7YYSTYPE);

                (yystack.l_mark__11YYSTACKDATA[-1]).pb__7YYSTYPE = __5bt;
            }
            }
            yyval.p__7YYSTYPE = (struct node *)type_adj__8basetypeFUc(
                (yystack.l_mark__11YYSTACKDATA[-1]).pb__7YYSTYPE,
                (yystack.l_mark__11YYSTACKDATA[0]).t__7YYSTYPE);
        }
        DECL_TYPE = 0;
    }

    break;
    case 69: {
        if (DECL_TYPE != -1)
            yyval.p__7YYSTYPE = (struct node *)name_adj__8basetypeFP4name(
                (yystack.l_mark__11YYSTACKDATA[-1]).pb__7YYSTYPE,
                (yystack.l_mark__11YYSTACKDATA[0]).pn__7YYSTYPE);
        else if ((yystack.l_mark__11YYSTACKDATA[-1]).pb__7YYSTYPE == 0)
            yyval.p__7YYSTYPE = (struct node *)__ct__8basetypeFUcP4name(
                (struct basetype *)0, (unsigned char)97,
                (yystack.l_mark__11YYSTACKDATA[0]).pn__7YYSTYPE);
        DECL_TYPE = 0;
    }

    break;
    case 70: {
        yyval.p__7YYSTYPE = (struct node *)base_adj__8basetypeFP8basetype(
            (yystack.l_mark__11YYSTACKDATA[-1]).pb__7YYSTYPE,
            (yystack.l_mark__11YYSTACKDATA[0]).pb__7YYSTYPE);

    }

    break;
    case 71: {
        yyval.p__7YYSTYPE = (struct node *)base_adj__8basetypeFP8basetype(
            (yystack.l_mark__11YYSTACKDATA[-1]).pb__7YYSTYPE,
            (yystack.l_mark__11YYSTACKDATA[0]).pb__7YYSTYPE);

    }

    break;
    case 72: {
        if (DECL_TYPE == 97) {
            switch ((yystack.l_mark__11YYSTACKDATA[-1]).pb__7YYSTYPE->base__4node) {
            case 119:
            case 121: {
                Pbase __6bt;

                __6bt = __ct__8basetypeFUcP4name((struct basetype *)0, (unsigned char)0,
                                                 (struct name *)0);
                ((*__6bt)) = (*(yystack.l_mark__11YYSTACKDATA[-1]).pb__7YYSTYPE);
                if ((yystack.l_mark__11YYSTACKDATA[-1]).pb__7YYSTYPE &&
                    ((yystack.l_mark__11YYSTACKDATA[-1]).pb__7YYSTYPE->permanent__4node == 0))
                    del__4typeFv((struct type *)(yystack.l_mark__11YYSTACKDATA[-1]).pb__7YYSTYPE);

                (yystack.l_mark__11YYSTACKDATA[-1]).pb__7YYSTYPE = __6bt;
            }
            }
            yyval.p__7YYSTYPE = (struct node *)type_adj__8basetypeFUc(
                (yystack.l_mark__11YYSTACKDATA[-1]).pb__7YYSTYPE,
                (yystack.l_mark__11YYSTACKDATA[0]).t__7YYSTYPE);
        } else if (DECL_TYPE == 178) {
            error__FiPCc((int)'i', (const char *)"T decl_marker(tscope)");

        } else
            yyval.p__7YYSTYPE = (struct node *)name_adj__8basetypeFP4name(
                (yystack.l_mark__11YYSTACKDATA[-1]).pb__7YYSTYPE,
                (yystack.l_mark__11YYSTACKDATA[0]).pn__7YYSTYPE);
        DECL_TYPE = -1;
    }

    break;
    case 73: {
        in_arg_list = 2;

        check_decl__Fv();

    }

    break;
    case 74: {
        register struct elist *__0__X112;

        struct expr *__2__X113;

        ((__0__X112 = (yystack.l_mark__11YYSTACKDATA[-2]).el__7YYSTYPE),
         ((__2__X113 = __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)140,
                                              (yystack.l_mark__11YYSTACKDATA[0]).pe__7YYSTYPE,
                                              (struct expr *)0)),
          (((__0__X112->tail__5elist->__O3__4expr.e2 = __2__X113),
            (__0__X112->tail__5elist = __2__X113)),
           (((void)0)))));

    }

    break;
    case 75: {
        struct elist *__0__X114;

        struct expr *__2__X115;

        in_arg_list = 0;

        yyval.el__7YYSTYPE =
            ((__0__X114 = 0),
             ((__2__X115 = __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)140,
                                                  (yystack.l_mark__11YYSTACKDATA[0]).pe__7YYSTYPE,
                                                  (struct expr *)0)),
              (((__0__X114 ||
                 (__0__X114 = (struct elist *)__nw__FUl((size_t)(sizeof(struct elist)))))
                    ? ((__0__X114->head__5elist = (__0__X114->tail__5elist = __2__X115)), 0)
                    : 0),
               __0__X114)));

    }

    break;
    case 76: {
        yyval.p__7YYSTYPE = (struct node *)__ct__4nameFPCc((struct name *)0, (const char *)0);
    }

    break;
    case 77: {
        yyval.p__7YYSTYPE = (yystack.l_mark__11YYSTACKDATA[-1]).p__7YYSTYPE;
        in_arg_list = 0;
        hoist_al__Fv();
    }

    break;
    case 78: {
        (((struct ptr *)(((struct ptr *)(yystack.l_mark__11YYSTACKDATA[-1]).p__7YYSTYPE))))
            ->typ__5pvtyp = (yystack.l_mark__11YYSTACKDATA[0]).pn__7YYSTYPE->__O1__4expr.tp;
        (yystack.l_mark__11YYSTACKDATA[0]).pn__7YYSTYPE->__O1__4expr.tp =
            (((struct type *)(((struct type *)(yystack.l_mark__11YYSTACKDATA[-1]).p__7YYSTYPE))));
        yyval.p__7YYSTYPE = (yystack.l_mark__11YYSTACKDATA[0]).p__7YYSTYPE;
        must_be_id = 0;
    }

    break;
    case 79: {
        (((struct fct *)(((struct fct *)(yystack.l_mark__11YYSTACKDATA[0]).p__7YYSTYPE))))
            ->returns__3fct = (yystack.l_mark__11YYSTACKDATA[-1]).pn__7YYSTYPE->__O1__4expr.tp;
        (yystack.l_mark__11YYSTACKDATA[-1]).pn__7YYSTYPE->__O1__4expr.tp =
            (((struct type *)(((struct type *)(yystack.l_mark__11YYSTACKDATA[0]).p__7YYSTYPE))));
    }

    break;
    case 80: {
        (((struct vec *)(((struct vec *)(yystack.l_mark__11YYSTACKDATA[0]).p__7YYSTYPE))))
            ->typ__5pvtyp = (yystack.l_mark__11YYSTACKDATA[-1]).pn__7YYSTYPE->__O1__4expr.tp;
        (yystack.l_mark__11YYSTACKDATA[-1]).pn__7YYSTYPE->__O1__4expr.tp =
            (((struct type *)(((struct type *)(yystack.l_mark__11YYSTACKDATA[0]).p__7YYSTYPE))));
    }

    break;
    case 81: {
        yyval.p__7YYSTYPE = (struct node *)normalize__4nameFP8basetypeP5blockUc(
            (yystack.l_mark__11YYSTACKDATA[0]).pn__7YYSTYPE,
            ((struct basetype *)((
                (struct basetype *)(yystack.l_mark__11YYSTACKDATA[-1]).p__7YYSTYPE))),
            (struct block *)0, (unsigned char)1);

    }

    break;
    case 82: {
        (yystack.l_mark__11YYSTACKDATA[0]).pn__7YYSTYPE->n_template_arg__4name = 3;
        yyval.pe__7YYSTYPE = (struct expr *)(yystack.l_mark__11YYSTACKDATA[0]).pn__7YYSTYPE;
    }

    break;
    case 83: {
        if ((yystack.l_mark__11YYSTACKDATA[0]).pe__7YYSTYPE == dummy)
            error__FPCc((const char *)"emptyYZL");
        yyval.pe__7YYSTYPE = (yystack.l_mark__11YYSTACKDATA[0]).pe__7YYSTYPE;
    }

    break;
    case 84: {
        yyval.p__7YYSTYPE =
            (struct node *)enumcheck__FP4name((yystack.l_mark__11YYSTACKDATA[0]).pn__7YYSTYPE);

    }

    break;
    case 85: {
        if (DECL_TYPE != 123) {
            unsigned long __2__X116;

            {
                struct ea __0__V71;

                error__FPCcRC2eaN32(
                    (const char *)"syntax error -- enum%k",
                    (const struct ea *)((__2__X116 =
                                             (yystack.l_mark__11YYSTACKDATA[0]).t__7YYSTYPE),
                                        (((((&__0__V71)->__O1__2ea.i = __2__X116), 0)),
                                         (&__0__V71))),
                    (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
                yyval.p__7YYSTYPE = 0;
            }
        } else
            yyval.p__7YYSTYPE =
                (struct node *)enumcheck__FP4name((yystack.l_mark__11YYSTACKDATA[0]).pn__7YYSTYPE);
    }

    break;
    case 86: {
        if (DECL_TYPE != 123) {
            error__FPCc((const char *)"enum declaration syntax");

            yyval.p__7YYSTYPE = 0;
        } else
            yyval.pn__7YYSTYPE =
                enumcheck__FP4name((yystack.l_mark__11YYSTACKDATA[0]).pn__7YYSTYPE);
        if (in_typedef && (in_typedef->base__4node == 0))
            in_typedef->defined__4type = 040;

    }

    break;
    case 87: {
        ++in_class_decl;

    }

    break;
    case 88: {
        --in_class_decl;

        yyval.p__7YYSTYPE = (struct node *)end_enum__FP4nameP5nlist(
            (struct name *)0, (yystack.l_mark__11YYSTACKDATA[-1]).nl__7YYSTYPE);

    }

    break;
    case 89: {
        ++in_class_decl;

    }

    break;
    case 90: {
        --in_class_decl;

        yyval.p__7YYSTYPE = (struct node *)end_enum__FP4nameP5nlist(
            (yystack.l_mark__11YYSTACKDATA[-4]).pn__7YYSTYPE,
            (yystack.l_mark__11YYSTACKDATA[-1]).nl__7YYSTYPE);

    }

    break;
    case 91: {
        yyval.pb__7YYSTYPE = (((struct basetype *)((
            (struct basetype *)(yystack.l_mark__11YYSTACKDATA[0]).pn__7YYSTYPE->__O1__4expr.tp))));

    }

    break;
    case 92: {
        if ((yystack.l_mark__11YYSTACKDATA[0]).p__7YYSTYPE)
            yyval.nl__7YYSTYPE = __ct__5nlistFP4name(
                (struct nlist *)0, (yystack.l_mark__11YYSTACKDATA[0]).pn__7YYSTYPE);
    }

    break;
    case 93: {
        register struct nlist *__0__X117;

        struct name *__2__X118;

        if ((yystack.l_mark__11YYSTACKDATA[0]).p__7YYSTYPE)
            if ((yystack.l_mark__11YYSTACKDATA[-2]).p__7YYSTYPE)
                ((__0__X117 = (yystack.l_mark__11YYSTACKDATA[-2]).nl__7YYSTYPE),
                 ((__2__X118 = (yystack.l_mark__11YYSTACKDATA[0]).pn__7YYSTYPE),
                  (((__0__X117->tail__5nlist->__O1__4name.n_list = __2__X118),
                    (__0__X117->tail__5nlist = __2__X118)),
                   (((void)0)))));
            else
                yyval.nl__7YYSTYPE = __ct__5nlistFP4name(
                    (struct nlist *)0, (yystack.l_mark__11YYSTACKDATA[0]).pn__7YYSTYPE);
    }

    break;
    case 96: {
        yyval.pn__7YYSTYPE = 0;
        error__FPCc((const char *)"emptyYZL");
    }

    break;
    case 97: {
        collect__17templ_compilationFUcP4name(templp,
                                              (yystack.l_mark__11YYSTACKDATA[-1]).t__7YYSTYPE,
                                              (yystack.l_mark__11YYSTACKDATA[0]).pn__7YYSTYPE);

    }

    break;
    case 98: {
        collect__17templ_compilationFP4name(
            templp, normalize__4nameFP8basetypeP5blockUc(
                        (yystack.l_mark__11YYSTACKDATA[0]).pn__7YYSTYPE,
                        ((struct basetype *)((
                            (struct basetype *)(yystack.l_mark__11YYSTACKDATA[-1]).p__7YYSTYPE))),
                        (struct block *)0, (unsigned char)0));

    }

    break;
    case 99: {
        yyval.p__7YYSTYPE = (struct node *)(yystack.l_mark__11YYSTACKDATA[0]).pn__7YYSTYPE;

    }

    break;
    case 100: {
        (((struct ptr *)(((struct ptr *)(yystack.l_mark__11YYSTACKDATA[-1]).p__7YYSTYPE))))
            ->typ__5pvtyp = (yystack.l_mark__11YYSTACKDATA[0]).pn__7YYSTYPE->__O1__4expr.tp;
        (yystack.l_mark__11YYSTACKDATA[0]).pn__7YYSTYPE->__O1__4expr.tp =
            (((struct type *)(((struct type *)(yystack.l_mark__11YYSTACKDATA[-1]).p__7YYSTYPE))));
        yyval.p__7YYSTYPE = (yystack.l_mark__11YYSTACKDATA[0]).p__7YYSTYPE;
    }

    break;
    case 101: {
        (((struct vec *)(((struct vec *)(yystack.l_mark__11YYSTACKDATA[0]).p__7YYSTYPE))))
            ->typ__5pvtyp = (yystack.l_mark__11YYSTACKDATA[-1]).pn__7YYSTYPE->__O1__4expr.tp;
        (yystack.l_mark__11YYSTACKDATA[-1]).pn__7YYSTYPE->__O1__4expr.tp =
            (((struct type *)(((struct type *)(yystack.l_mark__11YYSTACKDATA[0]).p__7YYSTYPE))));
    }

    break;
    case 102: {
        (((struct fct *)(((struct fct *)(yystack.l_mark__11YYSTACKDATA[0]).p__7YYSTYPE))))
            ->returns__3fct = (yystack.l_mark__11YYSTACKDATA[-1]).pn__7YYSTYPE->__O1__4expr.tp;
        (yystack.l_mark__11YYSTACKDATA[-1]).pn__7YYSTYPE->__O1__4expr.tp =
            (((struct type *)(((struct type *)(yystack.l_mark__11YYSTACKDATA[0]).p__7YYSTYPE))));
    }

    break;
    case 103: {
        yyval.p__7YYSTYPE = (yystack.l_mark__11YYSTACKDATA[-1]).p__7YYSTYPE;
        in_arg_list = 0;
        hoist_al__Fv();
    }

    break;
    case 104: {
        if ((yystack.l_mark__11YYSTACKDATA[0]).pn__7YYSTYPE->n_oper__4name != 123)
            insert_name__FP4nameP6ktable((yystack.l_mark__11YYSTACKDATA[0]).pn__7YYSTYPE, Ctbl);
        yyval.p__7YYSTYPE = (struct node *)(yystack.l_mark__11YYSTACKDATA[0]).pn__7YYSTYPE;
        yyval.pn__7YYSTYPE->__O1__4expr.tp = (struct type *)moe_type;
    }

    break;
    case 105: {
        if ((yystack.l_mark__11YYSTACKDATA[0]).pn__7YYSTYPE->n_oper__4name != 123)
            insert_name__FP4nameP6ktable((yystack.l_mark__11YYSTACKDATA[0]).pn__7YYSTYPE, Ctbl);
    }

    break;
    case 106: {
        yyval.p__7YYSTYPE = (struct node *)(yystack.l_mark__11YYSTACKDATA[-3]).pn__7YYSTYPE;
        yyval.pn__7YYSTYPE->__O1__4expr.tp = (struct type *)moe_type;
        yyval.pn__7YYSTYPE->__O3__4expr.n_initializer =
            (yystack.l_mark__11YYSTACKDATA[0]).pe__7YYSTYPE;
    }

    break;
    case 107: {
        yyval.p__7YYSTYPE = 0;

    }

    break;
    case 108: {
        parsing_class_members = 0;
        RESTORE_STATE__Fv();
        switch ((yychar == -1) ? ((yychar = lalex__Fv()), yychar) : yychar) {
        case 97:
        case 156:
        case 13:
        case 0:
            error__FPCc((const char *)"`;' or declaratorX afterCD");
            la_backup__FUc7YYSTYPE((unsigned char)yychar, yylval);
            yychar = 72;
            break;
        }
        la_backup__FUc7YYSTYPE((unsigned char)yychar, yylval);
        yychar = -1;
        restore_text__Fv();
        ++bl_level;
        ++in_mem_fct;
    }

    break;
    case 109: {
        --in_mem_fct;
        --bl_level;
        if (yychar == 80) {
            --yylval.pn__7YYSTYPE->lex_level__4name;
        }
        ccl->mem_list__8classdef =
            name_unlist__FP5nlist((yystack.l_mark__11YYSTACKDATA[-3]).nl__7YYSTYPE);

        ccl->templ_friends__8classdef = templ_friends;

        templ_friends = 0;
        if (--in_class_decl)
            parsing_class_members = 1;

        {
            ;

            if (Ctbl == Gtbl)
                error__FiPCc((int)'i', (const char *)"bad parsing table");

            {
                Pktab __1b;

                __1b = Ctbl;

                Ctbl = Ctbl->k_next__6ktable;

                if ((__1b->k_id__6ktable == 136) || 0)
                    __dt__6ktableFv(__1b, 3);
            }
        }

        if (Ctbl->k_id__6ktable == 185) {
            ccl->k_tbl__8classdef->k_next__6ktable = Ctbl->k_next__6ktable;
        }

        if (pti) {
            explicit_inst__10templ_instFv(pti);
            {
                Pname __4nnn;

                struct type *__0__X119;

                __4nnn =
                    ((__0__X119 = yyval.pt__7YYSTYPE),
                     ((((struct basetype *)(((struct basetype *)__0__X119))))->b_name__8basetype));

                __4nnn->__O2__4expr.string = ccl->string__8classdef;
                explicit_template_definition = 0;
                pti = 0;
            }
        }

        end_cl__Fv();
        declTag = 1;
    }

    break;
    case 110: {
        const void *__2__X124;

        unsigned long __2__X125;

    aggrcheck:
        yyval.pb__7YYSTYPE = (((struct basetype *)((
            (struct basetype *)(yystack.l_mark__11YYSTACKDATA[0]).pn__7YYSTYPE->__O1__4expr.tp))));
        if (yyval.p__7YYSTYPE == 0) {
            const void *__2__X120;

            const void *__2__X121;

            if (parameters_in_progress__17templ_compilation) {
                struct ea __0__V72;

                error__FPCcRC2eaN32(
                    (const char *)"TX for%n -- did you misdeclare aY?",
                    (const struct ea *)((__2__X120 =
                                             (const void *)(yystack.l_mark__11YYSTACKDATA[0])
                                                 .pn__7YYSTYPE),
                                        (((&__0__V72)->__O1__2ea.p = __2__X120), (&__0__V72))),
                    (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
            } else {
                struct ea __0__V73;

                error__FPCcRC2eaN32(
                    (const char *)"TX for %n",
                    (const struct ea *)((__2__X121 =
                                             (const void *)(yystack.l_mark__11YYSTACKDATA[0])
                                                 .pn__7YYSTYPE),
                                        (((&__0__V73)->__O1__2ea.p = __2__X121), (&__0__V73))),
                    (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
            }
            error__FiPCc((int)'i', (const char *)"cannot recover from previous error");
        }

        if (yyval.p__7YYSTYPE->base__4node == 97) {
            Pname __4nx;

            const void *__2__X122;

            unsigned long __2__X123;

            __4nx = yyval.pb__7YYSTYPE->b_name__8basetype;
            yyval.pb__7YYSTYPE =
                (((struct basetype *)(((struct basetype *)__4nx->__O1__4expr.tp))));
            if ((yyval.p__7YYSTYPE->base__4node != 119) ||
                strcmp(__4nx->__O2__4expr.string,
                       (yystack.l_mark__11YYSTACKDATA[0]).pn__7YYSTYPE->__O2__4expr.string)) {
                struct ea __0__V74;

                struct ea __0__V75;

                struct ea __0__V76;

                error__FPCcRC2eaN32(
                    (const char *)"%n of type%t redeclared as%k.",
                    (const struct ea *)((__2__X122 =
                                             (const void *)(yystack.l_mark__11YYSTACKDATA[0])
                                                 .pn__7YYSTYPE),
                                        (((&__0__V74)->__O1__2ea.p = __2__X122), (&__0__V74))),
                    (const struct ea *)__ct__2eaFPCv(&__0__V75, (const void *)yyval.pb__7YYSTYPE),
                    (const struct ea *)((__2__X123 =
                                             (yystack.l_mark__11YYSTACKDATA[-1]).t__7YYSTYPE),
                                        (((((&__0__V76)->__O1__2ea.i = __2__X123), 0)),
                                         (&__0__V76))),
                    (const struct ea *)ea0);
            }
        } else if (yyval.p__7YYSTYPE->base__4node != 119) {
            struct ea __0__V77;

            struct ea __0__V78;

            struct ea __0__V79;

            error__FPCcRC2eaN32(
                (const char *)"%n of type%t redeclared as%k",
                (const struct ea *)((__2__X124 = (const void *)(yystack.l_mark__11YYSTACKDATA[0])
                                                     .pn__7YYSTYPE),
                                    (((&__0__V77)->__O1__2ea.p = __2__X124), (&__0__V77))),
                (const struct ea *)__ct__2eaFPCv(&__0__V78, (const void *)yyval.pb__7YYSTYPE),
                (const struct ea *)((__2__X125 = (yystack.l_mark__11YYSTACKDATA[-1]).t__7YYSTYPE),
                                    (((((&__0__V79)->__O1__2ea.i = __2__X125), 0)), (&__0__V79))),
                (const struct ea *)ea0);
        }
        check_tag__Fv();
    }

    break;
    case 111: {
        dont_instantiate = (((yychar == -1) ? ((yychar = lalex__Fv()), yychar) : yychar) == 72);
        {
            Pexpr __3e;

            __3e = 0;
            if (dont_instantiate && (in_friend == 0)) {
                Ptempl __4t;

                const void *__2__X129;

                struct basic_inst *__0__X130;

                const void *__2__X131;

                const void *__2__X132;

                __4t = is_template__17templ_compilationFP4name(
                    templp, (yystack.l_mark__11YYSTACKDATA[-3]).pn__7YYSTYPE);

                if (__4t == 0) {
                    const void *__2__X126;

                    {
                        struct ea __0__V80;

                        error__FPCcRC2eaN32(
                            (const char *)"explicitC instance of a nonYC%n",
                            (const struct ea
                                 *)((__2__X126 = (const void *)(yystack.l_mark__11YYSTACKDATA[-3])
                                                     .pn__7YYSTYPE),
                                    (((&__0__V80)->__O1__2ea.p = __2__X126), (&__0__V80))),
                            (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
                        error__FiPCc((int)'i', (const char *)"cannot recover from previous error");
                    }
                }

                __3e = expr_unlist__FP5elist((yystack.l_mark__11YYSTACKDATA[-1]).el__7YYSTYPE);
                check_actual_args__5templFP4expr(__4t, __3e);

                pti = get_match__5templFP4exprP10templ_inst4bool(__4t, __3e, (struct templ_inst *)0,
                                                                 0);
                if (pti) {
                    register struct templ_inst *__0__X127;

                    const void *__2__X128;

                    if (((__0__X127 = pti),
                         ((((struct classdef *)((
                             (struct classdef *)(((struct basetype *)((
                                                     (struct basetype *)__0__X127
                                                         ->tname__10basic_inst->__O1__4expr.tp))))
                                 ->b_name__8basetype->__O1__4expr.tp))))))
                            ->class_base__8classdef == 4) {
                        struct ea __0__V81;

                        error__FPCcRC2eaN32(
                            (const char *)"ZC%n multiply instantiated",
                            (const struct ea
                                 *)((__2__X128 = (const void *)(yystack.l_mark__11YYSTACKDATA[-3])
                                                     .pn__7YYSTYPE),
                                    (((&__0__V81)->__O1__2ea.p = __2__X128), (&__0__V81))),
                            (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
                    }
                } else
                    pti = __ct__10templ_instFP4exprP5templUc(
                        (struct templ_inst *)0, __3e, __4t,
                        (yystack.l_mark__11YYSTACKDATA[-4]).t__7YYSTYPE);
                pti->inst_formals__10basic_inst =
                    (((struct basic_template *)__4t)->formals__14basic_template);

                {
                    struct ea __0__V82;

                    error__FiPCcRC2eaN33(
                        (int)'s', (const char *)"forwardD of a specialized version ofY%n",
                        (const struct ea *)((__2__X129 =
                                                 (const void *)(yystack.l_mark__11YYSTACKDATA[-3])
                                                     .pn__7YYSTYPE),
                                            (((&__0__V82)->__O1__2ea.p = __2__X129), (&__0__V82))),
                        (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
                    {
                        struct ea __0__V83;

                        error__FiPCcRC2eaN33(
                            (int)'C', (const char *)"\tclass %n",
                            (const struct ea
                                 *)((__2__X131 =
                                         (const void *)((__0__X130 = (struct basic_inst *)pti),
                                                        (__0__X130->tname__10basic_inst))),
                                    (((&__0__V83)->__O1__2ea.p = __2__X131), (&__0__V83))),
                            (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
                        error__FiPCc(
                            (int)'c',
                            (const char
                                 *)" -- did you mean a general forward declaration of theY?\n");
                        {
                            struct ea __0__V84;

                            error__FiPCcRC2eaN33(
                                (int)'C',
                                (const char
                                     *)"\tif so, use:  template <formal-parameters> class %n;\n",
                                (const struct ea
                                     *)((__2__X132 =
                                             (const void *)(yystack.l_mark__11YYSTACKDATA[-3])
                                                 .pn__7YYSTYPE),
                                        (((&__0__V84)->__O1__2ea.p = __2__X132), (&__0__V84))),
                                (const struct ea *)ea0, (const struct ea *)ea0,
                                (const struct ea *)ea0);
                        }
                    }
                }
            }

            if (!__3e) {
                __3e = expr_unlist__FP5elist((yystack.l_mark__11YYSTACKDATA[-1]).el__7YYSTYPE);
            }
            {
                Pname __3p;

                __3p = parametrized_typename__FP4nameP4exprUc(
                    (yystack.l_mark__11YYSTACKDATA[-3]).pn__7YYSTYPE, __3e,
                    (unsigned char)in_friend);
                dont_instantiate = 0;
                yyval.pb__7YYSTYPE =
                    (((struct basetype *)(((struct basetype *)__3p->__O1__4expr.tp))));
                check_tag__Fv();
            }
        }
    }

    break;
    case 112: {
        goto aggrcheck;
    }

    break;
    case 115: {
        yyval.pbc__7YYSTYPE = (yystack.l_mark__11YYSTACKDATA[0]).pbc__7YYSTYPE;

    }

    break;
    case 116: {
        yyval.pbc__7YYSTYPE = 0;

    }

    break;
    case 118: {
        if ((yystack.l_mark__11YYSTACKDATA[0]).pbc__7YYSTYPE) {
            yyval.pbc__7YYSTYPE = (yystack.l_mark__11YYSTACKDATA[0]).pbc__7YYSTYPE;

            yyval.pbc__7YYSTYPE->next__6basecl = (yystack.l_mark__11YYSTACKDATA[-2]).pbc__7YYSTYPE;
        }

    }

    break;
    case 119: {
        yyval.pbc__7YYSTYPE = dobase__FUcP4nameT1(
            (unsigned char)0, (yystack.l_mark__11YYSTACKDATA[0]).pn__7YYSTYPE, (unsigned char)0);

    }

    break;
    case 120: {
        yyval.pbc__7YYSTYPE =
            dobase__FUcP4nameT1((yystack.l_mark__11YYSTACKDATA[-1]).t__7YYSTYPE,
                                (yystack.l_mark__11YYSTACKDATA[0]).pn__7YYSTYPE, (unsigned char)0);

    }

    break;
    case 121: {
        yyval.pbc__7YYSTYPE =
            dobase__FUcP4nameT1((unsigned char)0, (yystack.l_mark__11YYSTACKDATA[0]).pn__7YYSTYPE,
                                (yystack.l_mark__11YYSTACKDATA[-1]).t__7YYSTYPE);

    }

    break;
    case 122: {
        yyval.pbc__7YYSTYPE = dobase__FUcP4nameT1((yystack.l_mark__11YYSTACKDATA[-2]).t__7YYSTYPE,
                                                  (yystack.l_mark__11YYSTACKDATA[0]).pn__7YYSTYPE,
                                                  (yystack.l_mark__11YYSTACKDATA[-1]).t__7YYSTYPE);

    }

    break;
    case 123: {
        yyval.pbc__7YYSTYPE = dobase__FUcP4nameT1((yystack.l_mark__11YYSTACKDATA[-1]).t__7YYSTYPE,
                                                  (yystack.l_mark__11YYSTACKDATA[0]).pn__7YYSTYPE,
                                                  (yystack.l_mark__11YYSTACKDATA[-2]).t__7YYSTYPE);

    }

    break;
    case 124: {
        Pname __3n;

        __3n = start_cl__FUcP4nameP6basecl((yystack.l_mark__11YYSTACKDATA[-1]).t__7YYSTYPE,
                                           (struct name *)0, (struct basecl *)0);

        {
            ;

            {
                Pclass __1cl;

                __1cl = classtype__4typeFv(__3n->__O1__4expr.tp);

                __1cl->k_tbl__8classdef->k_next__6ktable = Ctbl;

                Ctbl = __1cl->k_tbl__8classdef;

                expand__6ktableFi(Ctbl, 12);
            }
        }

        ccl->k_tbl__8classdef = Ctbl;
        yyval.p__7YYSTYPE =
            (struct node *)(((struct basetype *)(((struct basetype *)__3n->__O1__4expr.tp))));
        parsing_class_members = 1;

        in_class_decl++;
        SAVE_STATE__Fv();
    }

    break;
    case 125: {
        Pname __3n;

        __3n = start_cl__FUcP4nameP6basecl((yystack.l_mark__11YYSTACKDATA[-3]).t__7YYSTYPE,
                                           (yystack.l_mark__11YYSTACKDATA[-2]).pn__7YYSTYPE,
                                           (yystack.l_mark__11YYSTACKDATA[-1]).pbc__7YYSTYPE);

        {
            ;

            {
                Pclass __1cl;

                __1cl = classtype__4typeFv(__3n->__O1__4expr.tp);

                __1cl->k_tbl__8classdef->k_next__6ktable = Ctbl;

                Ctbl = __1cl->k_tbl__8classdef;

                expand__6ktableFi(Ctbl, 12);
            }
        }

        ccl->k_tbl__8classdef = Ctbl;
        yyval.p__7YYSTYPE =
            (struct node *)(((struct basetype *)(((struct basetype *)__3n->__O1__4expr.tp))));
        parsing_class_members = 1;

        in_class_decl++;
        SAVE_STATE__Fv();
    }

    break;
    case 126: {
        const void *__2__X133;

        if (bl_level > 1) {
            struct ea __0__V85;

            error__FiPCcRC2eaN33(
                (int)'s', (const char *)"specializedY%n not at global scope",
                (const struct ea *)((__2__X133 = (const void *)(yystack.l_mark__11YYSTACKDATA[-5])
                                                     .pn__7YYSTYPE),
                                    (((&__0__V85)->__O1__2ea.p = __2__X133), (&__0__V85))),
                (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
        }
        explicit_template_definition = 1;
        {
            Ptempl __3t;

            __3t = is_template__17templ_compilationFP4name(
                templp, (yystack.l_mark__11YYSTACKDATA[-5]).pn__7YYSTYPE);

            if ((__3t == 0) || (!__3t->defined__5templ)) {
                const void *__2__X134;

                {
                    struct ea __0__V86;

                    error__FPCcRC2eaN32(
                        (const char *)"YC%n must be defined prior to an explicitC instance",
                        (const struct ea *)((__2__X134 =
                                                 (const void *)(yystack.l_mark__11YYSTACKDATA[-5])
                                                     .pn__7YYSTYPE),
                                            (((&__0__V86)->__O1__2ea.p = __2__X134), (&__0__V86))),
                        (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
                    error__FiPCc((int)'i', (const char *)"cannot recover from previous error");
                }
            }

            {
                Pexpr __3e;

                __3e = expr_unlist__FP5elist((yystack.l_mark__11YYSTACKDATA[-3]).el__7YYSTYPE);
                check_actual_args__5templFP4expr(__3t, __3e);

                pti = get_match__5templFP4exprP10templ_inst4bool(__3t, __3e, (struct templ_inst *)0,
                                                                 0);
                if (pti) {
                    register struct templ_inst *__0__X135;

                    const void *__2__X136;

                    if (((__0__X135 = pti),
                         ((((struct classdef *)((
                             (struct classdef *)(((struct basetype *)((
                                                     (struct basetype *)__0__X135
                                                         ->tname__10basic_inst->__O1__4expr.tp))))
                                 ->b_name__8basetype->__O1__4expr.tp))))))
                            ->class_base__8classdef == 4) {
                        struct ea __0__V87;

                        error__FPCcRC2eaN32(
                            (const char *)"ZC%n multiply instantiated",
                            (const struct ea
                                 *)((__2__X136 = (const void *)(yystack.l_mark__11YYSTACKDATA[-5])
                                                     .pn__7YYSTYPE),
                                    (((&__0__V87)->__O1__2ea.p = __2__X136), (&__0__V87))),
                            (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
                    }
                } else
                    pti = __ct__10templ_instFP4exprP5templUc(
                        (struct templ_inst *)0, __3e, __3t,
                        (yystack.l_mark__11YYSTACKDATA[-6]).t__7YYSTYPE);

                {
                    Pname __3n;

                    struct basic_inst *__0__X137;

                    __3n = start_cl__FUcP4nameP6basecl(
                        (yystack.l_mark__11YYSTACKDATA[-6]).t__7YYSTYPE,
                        ((__0__X137 = (struct basic_inst *)pti), (__0__X137->tname__10basic_inst)),
                        (yystack.l_mark__11YYSTACKDATA[-1]).pbc__7YYSTYPE);
                    (((struct basetype *)(((struct basetype *)__3n->__O1__4expr.tp))))
                        ->b_name__8basetype->n_redefined__4name = 1;

                    {
                        ;

                        {
                            Pclass __1cl;

                            __1cl = classtype__4typeFv(__3n->__O1__4expr.tp);

                            __1cl->k_tbl__8classdef->k_next__6ktable = Ctbl;

                            Ctbl = __1cl->k_tbl__8classdef;

                            expand__6ktableFi(Ctbl, 12);
                        }
                    }

                    ccl->k_tbl__8classdef = Ctbl;
                    yyval.p__7YYSTYPE = (struct node *)((
                        (struct basetype *)(((struct basetype *)__3n->__O1__4expr.tp))));
                    parsing_class_members = 1;
                    in_class_decl++;
                    SAVE_STATE__Fv();
                }
            }
        }
    }

    break;
    case 127: {
        yyval.p__7YYSTYPE = (struct node *)(yystack.l_mark__11YYSTACKDATA[0]).pn__7YYSTYPE;

    }

    break;
    case 128: {
        yyval.p__7YYSTYPE = (yystack.l_mark__11YYSTACKDATA[0]).p__7YYSTYPE;

    }

    break;
    case 129: {
        yyval.p__7YYSTYPE = (struct node *)(yystack.l_mark__11YYSTACKDATA[0]).pn__7YYSTYPE;

    }

    break;
    case 130: {
        yyval.p__7YYSTYPE = (yystack.l_mark__11YYSTACKDATA[0]).p__7YYSTYPE;

    }

    break;
    case 131: {
        if ((yystack.l_mark__11YYSTACKDATA[0]).p__7YYSTYPE) {
            if ((yystack.l_mark__11YYSTACKDATA[-1]).p__7YYSTYPE)
                add_list__5nlistFP4name((yystack.l_mark__11YYSTACKDATA[-1]).nl__7YYSTYPE,
                                        (yystack.l_mark__11YYSTACKDATA[0]).pn__7YYSTYPE);
            else
                yyval.nl__7YYSTYPE = __ct__5nlistFP4name(
                    (struct nlist *)0, (yystack.l_mark__11YYSTACKDATA[0]).pn__7YYSTYPE);
        }
        in_friend = 0;
    }

    break;
    case 132: {
        yyval.p__7YYSTYPE = 0;

    }

    break;
    case 133: {
        struct cons *__0__X138;

        struct cons *__2__X139;

        if (must_be_friend) {
            error__FPCc((const char *)"non-friend ZizedTD must be atG, notC scope");
            error__FiPCc((int)'i', (const char *)"cannot recover from previous error");
        }
        templ_friends =
            ((__0__X138 = 0),
             ((__2__X139 = templ_friends),
              (((__0__X138 ||
                 (__0__X138 = (struct cons *)__nw__FUl((unsigned long)(sizeof(struct cons)))))
                    ? ((__0__X138->car__4cons = ((void *)parsed_template__17templ_compilation)),
                       (__0__X138->cdr__4cons = __2__X139))
                    : 0),
               __0__X138)));
        parsed_template__17templ_compilation = 0;
    }

    break;
    case 135: {
    fct_friend1:
        if (((in_friend && (yystack.l_mark__11YYSTACKDATA[-1]).pn__7YYSTYPE) &&
             (yystack.l_mark__11YYSTACKDATA[-1]).pn__7YYSTYPE->__O2__4name.n_qualifier) &&
            ((yystack.l_mark__11YYSTACKDATA[-1])
                 .pn__7YYSTYPE->__O2__4name.n_qualifier->n_template_arg__4name != 1))
            UNSET_SCOPE__Fv();
    }

    break;
    case 136: {
        goto fct_friend1;
    }

    break;
    case 137: {
    fct_friend2:
        if (((in_friend && (yystack.l_mark__11YYSTACKDATA[0]).pn__7YYSTYPE) &&
             (yystack.l_mark__11YYSTACKDATA[0]).pn__7YYSTYPE->__O2__4name.n_qualifier) &&
            ((yystack.l_mark__11YYSTACKDATA[0])
                 .pn__7YYSTYPE->__O2__4name.n_qualifier->n_template_arg__4name != 1))
            UNSET_SCOPE__Fv();
    }

    break;
    case 138: {
        goto fct_friend2;
    }

    break;
    case 140: {
        yyval.p__7YYSTYPE = (struct node *)__ct__4nameFPCc((struct name *)0, (const char *)0);
        yyval.pn__7YYSTYPE->base__4node = (yystack.l_mark__11YYSTACKDATA[-1]).t__7YYSTYPE;
    }

    break;
    case 141: {
        Pname __3n;

        struct name *__1__X140;

        struct name *__1__Xnn00qycjpkkfwcaj;

        __3n = ((__1__X140 = (yystack.l_mark__11YYSTACKDATA[-1]).pn__7YYSTYPE),
                (((__1__X140->base__4node != 123)
                      ? ((__1__Xnn00qycjpkkfwcaj = __1__X140), 0)
                      : ((__1__Xnn00qycjpkkfwcaj =
                              __ct__4nameFPCc((struct name *)0, __1__X140->__O2__4expr.string)),
                         (__1__Xnn00qycjpkkfwcaj->n_template_arg__4name =
                              __1__X140->n_template_arg__4name))),
                 __1__Xnn00qycjpkkfwcaj));
        if (__3n->n_oper__4name == 97) {
            error__FiPCc((int)'s', (const char *)"visibilityD for conversion operator");

            __3n->__O1__4expr.tp = (((struct type *)(((struct type *)__3n->__O4__4expr.cond))));
            __3n->__O4__4expr.cond = 0;

            __3n->n_oper__4name = 0;
            sig_name__FP4name(__3n);
        }
        __3n->__O2__4name.n_qualifier = (yystack.l_mark__11YYSTACKDATA[-2]).pn__7YYSTYPE;
        __3n->base__4node = 175;
        yyval.p__7YYSTYPE = (struct node *)__3n;
        if ((yystack.l_mark__11YYSTACKDATA[-2]).pn__7YYSTYPE &&
            ((yystack.l_mark__11YYSTACKDATA[-2]).pn__7YYSTYPE->n_template_arg__4name != 1))
            UNSET_SCOPE__Fv();
    }

    break;
    case 142: {
        yyval.p__7YYSTYPE = (struct node *)(yystack.l_mark__11YYSTACKDATA[0]).pn__7YYSTYPE;

    }

    break;
    case 143: {
        struct name *__1__X141;

        struct name *__1__Xnn00qycjpkkfwcaj;

        yyval.p__7YYSTYPE =
            (struct node *)((__1__X141 = (yystack.l_mark__11YYSTACKDATA[0]).pn__7YYSTYPE),
                            (((__1__X141->base__4node != 123)
                                  ? ((__1__Xnn00qycjpkkfwcaj = __1__X141), 0)
                                  : ((__1__Xnn00qycjpkkfwcaj = __ct__4nameFPCc(
                                          (struct name *)0, __1__X141->__O2__4expr.string)),
                                     (__1__Xnn00qycjpkkfwcaj->n_template_arg__4name =
                                          __1__X141->n_template_arg__4name))),
                             __1__Xnn00qycjpkkfwcaj));
        yyval.pn__7YYSTYPE->n_oper__4name = 162;
    }

    break;
    case 144: {
        yyval.p__7YYSTYPE = (struct node *)__ct__4nameFPCc(
            (struct name *)0, oper_name__FUc((yystack.l_mark__11YYSTACKDATA[0]).t__7YYSTYPE));

        yyval.pn__7YYSTYPE->n_oper__4name = (yystack.l_mark__11YYSTACKDATA[0]).t__7YYSTYPE;
    }

    break;
    case 145: {
        Pname __3n;

        __3n = (yystack.l_mark__11YYSTACKDATA[0]).pn__7YYSTYPE;
        __3n->__O2__4expr.string = (const char *)"_type";
        __3n->n_oper__4name = 97;
        __3n->__O4__4expr.cond = (((struct expr *)(((struct expr *)__3n->__O1__4expr.tp))));

        __3n->__O1__4expr.tp = 0;
        yyval.p__7YYSTYPE = (struct node *)__3n;
    }

    break;
    case 160: {
        yyval.t__7YYSTYPE = 109;

    }

    break;
    case 161: {
        yyval.t__7YYSTYPE = 111;

    }

    break;
    case 167: {
        yyval.t__7YYSTYPE = 23;

        --in_new;

    }

    break;
    case 168: {
        yyval.t__7YYSTYPE = 213;

        --in_new;

    }

    break;
    case 169: {
        yyval.t__7YYSTYPE = 9;

    }

    break;
    case 170: {
        yyval.t__7YYSTYPE = 212;

    }

    break;
    case 171: {
        yyval.t__7YYSTYPE = 44;

    }

    break;
    case 172: {
        yyval.t__7YYSTYPE = 71;

    }

    break;
    case 173: {
        yyval.t__7YYSTYPE = 180;
        if ((yystack.l_mark__11YYSTACKDATA[0]).t__7YYSTYPE == 45)
            error__FPCc((const char *)".* cannot be overloaded");
    }

    break;
    case 174: {
        yyval.pn__7YYSTYPE = SET_SCOPE__FP4name((yystack.l_mark__11YYSTACKDATA[0]).pn__7YYSTYPE);

    }

    break;
    case 175: {
        if ((yystack.l_mark__11YYSTACKDATA[0]).pn__7YYSTYPE != sta_name) {
            Pname __4n;
            const char *__4str;

            const char *__4str2;

            const char *__4s;

            __4n = (yystack.l_mark__11YYSTACKDATA[0]).pn__7YYSTYPE;
            __4str = 0;

            __4str2 = 0;

            __4s = __4n->__O2__4expr.string;
            if (__4n->n_template_arg__4name != 1) {
                __4n = is_cl_obj__4typeFv(__4n->__O1__4expr.tp);
                if (__4n)
                    __4str = (__4s = (const char *)get_classname__FPCc(__4n->__O2__4expr.string));
            }
            if ((__4n && (((yychar == -1) ? ((yychar = lalex__Fv()), yychar) : yychar) == 123)) &&
                (strcmp(__4s, __4str2 = (const char *)get_classname__FPCc(
                                  yylval.pn__7YYSTYPE->__O2__4expr.string)) == 0)) {
                struct name *__1__X142;

                struct name *__1__Xnn00qycjpkkfwcaj;

                yychar = 80;
                yylval.pn__7YYSTYPE =
                    ((__1__X142 = yylval.pn__7YYSTYPE),
                     (((__1__X142->base__4node != 123)
                           ? ((__1__Xnn00qycjpkkfwcaj = __1__X142), 0)
                           : ((__1__Xnn00qycjpkkfwcaj = __ct__4nameFPCc(
                                   (struct name *)0, __1__X142->__O2__4expr.string)),
                              (__1__Xnn00qycjpkkfwcaj->n_template_arg__4name =
                                   __1__X142->n_template_arg__4name))),
                      __1__Xnn00qycjpkkfwcaj));
                yylval.pn__7YYSTYPE->n_oper__4name = 123;
            }
            if (__4str)
                __dl__FPv((void *)(((char *)__4str)));
            if (__4str2)
                __dl__FPv((void *)(((char *)__4str2)));
        }
        yyval.pn__7YYSTYPE = (yystack.l_mark__11YYSTACKDATA[0]).pn__7YYSTYPE;
    }

    break;
    case 176: {
        yyval.pn__7YYSTYPE = (yystack.l_mark__11YYSTACKDATA[0]).pn__7YYSTYPE;
        if ((yystack.l_mark__11YYSTACKDATA[0]).pn__7YYSTYPE == sta_name) {
            error__FPCc((const char *)"scope qualifier syntax");

        } else {
            Pname __4cn;
            const char *__4str;

            const char *__4str2;

            const char *__4s;

            __4cn = (yystack.l_mark__11YYSTACKDATA[0]).pn__7YYSTYPE;
            __4str = 0;

            __4str2 = 0;

            __4s = __4cn->__O2__4expr.string;
            if (__4cn->n_template_arg__4name != 1) {
                __4cn = is_cl_obj__4typeFv(
                    (yystack.l_mark__11YYSTACKDATA[0]).pn__7YYSTYPE->__O1__4expr.tp);
                if (__4cn)
                    __4str = (__4s = (const char *)get_classname__FPCc(__4cn->__O2__4expr.string));
            }
            if ((__4cn && (((yychar == -1) ? ((yychar = lalex__Fv()), yychar) : yychar) == 123)) &&
                (strcmp(__4s, __4str2 = (const char *)get_classname__FPCc(
                                  yylval.pn__7YYSTYPE->__O2__4expr.string)) == 0)) {
                struct name *__1__X143;

                struct name *__1__Xnn00qycjpkkfwcaj;

                yychar = 80;
                yylval.pn__7YYSTYPE =
                    ((__1__X143 = yylval.pn__7YYSTYPE),
                     (((__1__X143->base__4node != 123)
                           ? ((__1__Xnn00qycjpkkfwcaj = __1__X143), 0)
                           : ((__1__Xnn00qycjpkkfwcaj = __ct__4nameFPCc(
                                   (struct name *)0, __1__X143->__O2__4expr.string)),
                              (__1__Xnn00qycjpkkfwcaj->n_template_arg__4name =
                                   __1__X143->n_template_arg__4name))),
                      __1__Xnn00qycjpkkfwcaj));
                yylval.pn__7YYSTYPE->n_oper__4name = 123;
            }
            if (__4str)
                __dl__FPv((void *)(((char *)__4str)));
            if (__4str2)
                __dl__FPv((void *)(((char *)__4str2)));
            if (((yystack.l_mark__11YYSTACKDATA[-1]).pn__7YYSTYPE != sta_name) &&
                ((yystack.l_mark__11YYSTACKDATA[-1]).pn__7YYSTYPE->n_template_arg__4name != 1)) {
                Pname __5cx;

                __5cx = is_cl_obj__4typeFv(
                    (yystack.l_mark__11YYSTACKDATA[-1]).pn__7YYSTYPE->__O1__4expr.tp);
                if (__5cx)
                    if (check_if_base__FP8classdefT1(
                            ((struct classdef *)(((struct classdef *)__5cx->__O1__4expr.tp))),
                            ((struct classdef *)(((struct classdef *)__4cn->__O1__4expr.tp))))) {
                        struct ea __0__V88;

                        struct ea __0__V89;

                        struct ea __0__V90;

                        struct ea __0__V91;

                        error__FPCcRC2eaN32(
                            (const char *)"%n ::%n :: --%n not aM of%n",
                            (const struct ea *)(((&__0__V88)->__O1__2ea.p = ((const void *)__5cx)),
                                                (&__0__V88)),
                            (const struct ea *)(((&__0__V89)->__O1__2ea.p = ((const void *)__4cn)),
                                                (&__0__V89)),
                            (const struct ea *)(((&__0__V90)->__O1__2ea.p = ((const void *)__4cn)),
                                                (&__0__V90)),
                            (const struct ea *)(((&__0__V91)->__O1__2ea.p = ((const void *)__5cx)),
                                                (&__0__V91)));
                    }
            }
        }
    }

    break;
    case 177: {
        yyval.pn__7YYSTYPE = (yystack.l_mark__11YYSTACKDATA[0]).pn__7YYSTYPE;
        if (in_typedef && (in_typedef->base__4node == 0))
            in_typedef->defined__4type = 040;

    }

    break;
    case 178: {
        yyval.pn__7YYSTYPE = (yystack.l_mark__11YYSTACKDATA[0]).pn__7YYSTYPE;
        if (in_typedef && (in_typedef->base__4node == 0))
            in_typedef->defined__4type = 040;

    }

    break;
    case 179: {
        yyval.i__7YYSTYPE = 0;

    }

    break;
    case 180: {
        switch ((yystack.l_mark__11YYSTACKDATA[0]).t__7YYSTYPE) {
            unsigned long __2__X145;

        case 170:
            error__FiPCc((int)'s', (const char *)"volatile functions");
            break;
        case 26:
            yyval.i__7YYSTYPE = ((yystack.l_mark__11YYSTACKDATA[-1]).i__7YYSTYPE | 1);
            break;
        default:
            if (((((yychar == -1) ? ((yychar = lalex__Fv()), yychar) : yychar) != 72) &&
                 (yychar != 69)) &&
                (yychar != 73)) {
                unsigned long __2__X144;

                la_backup__FUc7YYSTYPE((unsigned char)yychar, yylval);
                yylval.t__7YYSTYPE = (yystack.l_mark__11YYSTACKDATA[0]).t__7YYSTYPE;
                la_backup__FUc7YYSTYPE((unsigned char)97, yylval);
                yylval.t__7YYSTYPE = 72;
                yychar = 72;
                {
                    struct ea __0__V92;

                    error__FPCcRC2eaN32(
                        (const char *)"syntax error: unexpected%k (did you forget a `;'?)",
                        (const struct ea *)((__2__X144 =
                                                 (yystack.l_mark__11YYSTACKDATA[0]).t__7YYSTYPE),
                                            (((((&__0__V92)->__O1__2ea.i = __2__X144), 0)),
                                             (&__0__V92))),
                        (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
                }
            } else {
                struct ea __0__V93;

                error__FPCcRC2eaN32(
                    (const char *)"FD syntax: unexpected%k",
                    (const struct ea *)((__2__X145 =
                                             (yystack.l_mark__11YYSTACKDATA[0]).t__7YYSTYPE),
                                        (((((&__0__V93)->__O1__2ea.i = __2__X145), 0)),
                                         (&__0__V93))),
                    (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
            }
            break;
        }
    }

    break;
    case 181: {
        yyval.i__7YYSTYPE = (yystack.l_mark__11YYSTACKDATA[-4]).i__7YYSTYPE;

    }

    break;
    case 182: {
        yyval.pl__7YYSTYPE = 0;

    }

    break;
    case 183: {
        yyval.pl__7YYSTYPE = 0;

    }

    break;
    case 184: {
        (((struct fct *)(((struct fct *)(yystack.l_mark__11YYSTACKDATA[0]).p__7YYSTYPE))))
            ->returns__3fct = (yystack.l_mark__11YYSTACKDATA[-1]).pn__7YYSTYPE->__O1__4expr.tp;
        (yystack.l_mark__11YYSTACKDATA[-1]).pn__7YYSTYPE->__O1__4expr.tp =
            (yystack.l_mark__11YYSTACKDATA[0]).pt__7YYSTYPE;
    }

    break;
    case 185: {
        (yystack.l_mark__11YYSTACKDATA[-3]).pn__7YYSTYPE->__O1__4expr.tp =
            (struct type *)__ct__3fctFP4typeP4nameUc(
                (struct fct *)0, (yystack.l_mark__11YYSTACKDATA[-3]).pn__7YYSTYPE->__O1__4expr.tp,
                (struct name *)0, (unsigned char)1);
        (((struct fct *)((
             (struct fct *)(yystack.l_mark__11YYSTACKDATA[-3]).pn__7YYSTYPE->__O1__4expr.tp))))
            ->f_const__3fct = ((yystack.l_mark__11YYSTACKDATA[0]).i__7YYSTYPE & 1);
    }

    break;
    case 186: {
        Pname __3n;

        struct name *__1__Xnn00qycjpkkfwcaj;

        __3n = (yystack.l_mark__11YYSTACKDATA[-1]).pn__7YYSTYPE;
        yyval.p__7YYSTYPE =
            (struct node *)(((__3n->base__4node != 123)
                                 ? ((__1__Xnn00qycjpkkfwcaj = __3n), 0)
                                 : ((__1__Xnn00qycjpkkfwcaj = __ct__4nameFPCc(
                                         (struct name *)0, __3n->__O2__4expr.string)),
                                    (__1__Xnn00qycjpkkfwcaj->n_template_arg__4name =
                                         __3n->n_template_arg__4name))),
                            __1__Xnn00qycjpkkfwcaj);

        if ((!in_typedef) &&
            ((ccl == 0) || strcmp(__3n->__O2__4expr.string, ccl->string__8classdef)))
            hide__4nameFv(__3n);
        yyval.pn__7YYSTYPE->n_oper__4name = 123;
        (((struct fct *)(((struct fct *)(yystack.l_mark__11YYSTACKDATA[0]).p__7YYSTYPE))))
            ->returns__3fct = yyval.pn__7YYSTYPE->__O1__4expr.tp;
        yyval.pn__7YYSTYPE->__O1__4expr.tp = (yystack.l_mark__11YYSTACKDATA[0]).pt__7YYSTYPE;
    }

    break;
    case 187: {
        (yystack.l_mark__11YYSTACKDATA[-3]).pn__7YYSTYPE->__O1__4expr.tp =
            (struct type *)__ct__3fctFP4typeP4nameUc(
                (struct fct *)0, (yystack.l_mark__11YYSTACKDATA[-3]).pn__7YYSTYPE->__O1__4expr.tp,
                (yystack.l_mark__11YYSTACKDATA[-1]).pn__7YYSTYPE, (unsigned char)1);
        in_arg_list = 0;

        {
            ;

            if (Ctbl == Gtbl)
                error__FiPCc((int)'i', (const char *)"bad parsing table");

            {
                Pktab __1b;

                __1b = Ctbl;

                Ctbl = Ctbl->k_next__6ktable;

                if ((__1b->k_id__6ktable == 136) || 0)
                    __dt__6ktableFv(__1b, 3);
            }
        }

    }

    break;
    case 188: {
        Pptr __3p;

        __3p = __ct__3ptrFUcP4type((struct ptr *)0, (unsigned char)125, (struct type *)0);
        (((struct ptr *)(((struct ptr *)__3p))))->typ__5pvtyp =
            (struct type *)__ct__8basetypeFUcP4name(
                (struct basetype *)0, (unsigned char)97,
                (yystack.l_mark__11YYSTACKDATA[-5]).pn__7YYSTYPE);
        (((struct fct *)(((struct fct *)(yystack.l_mark__11YYSTACKDATA[0]).p__7YYSTYPE))))
            ->returns__3fct = (((struct type *)(((struct type *)__3p))));
        (yystack.l_mark__11YYSTACKDATA[-2]).pn__7YYSTYPE->__O1__4expr.tp =
            (yystack.l_mark__11YYSTACKDATA[0]).pt__7YYSTYPE;

        if (((yystack.l_mark__11YYSTACKDATA[-2]).pn__7YYSTYPE->n_oper__4name != 123) &&
            (!in_typedef)) {
            insert_name__FP4nameP6ktable((yystack.l_mark__11YYSTACKDATA[-2]).pn__7YYSTYPE, Ctbl);
        }
        yyval.p__7YYSTYPE = (struct node *)(yystack.l_mark__11YYSTACKDATA[-2]).pn__7YYSTYPE;
        if (DECL_TYPE == -1)
            DECL_TYPE = 0;
    }

    break;
    case 189: {
        Pptr __3p;

        __3p = __ct__3ptrFUcP4type((struct ptr *)0, (unsigned char)158, (struct type *)0);
        (((struct ptr *)(((struct ptr *)__3p))))->typ__5pvtyp =
            (struct type *)__ct__8basetypeFUcP4name(
                (struct basetype *)0, (unsigned char)97,
                (yystack.l_mark__11YYSTACKDATA[-5]).pn__7YYSTYPE);
        (((struct fct *)(((struct fct *)(yystack.l_mark__11YYSTACKDATA[0]).p__7YYSTYPE))))
            ->returns__3fct = (((struct type *)(((struct type *)__3p))));
        (yystack.l_mark__11YYSTACKDATA[-2]).pn__7YYSTYPE->__O1__4expr.tp =
            (yystack.l_mark__11YYSTACKDATA[0]).pt__7YYSTYPE;

        if (((yystack.l_mark__11YYSTACKDATA[-2]).pn__7YYSTYPE->n_oper__4name != 123) &&
            (!in_typedef)) {
            insert_name__FP4nameP6ktable((yystack.l_mark__11YYSTACKDATA[-2]).pn__7YYSTYPE, Ctbl);
        }
        yyval.p__7YYSTYPE = (struct node *)(yystack.l_mark__11YYSTACKDATA[-2]).pn__7YYSTYPE;
        if (DECL_TYPE == -1)
            DECL_TYPE = 0;
    }

    break;
    case 190: {
        Pname __3n;

        struct name *__1__X146;

        struct name *__1__Xnn00qycjpkkfwcaj;

        __3n = (yystack.l_mark__11YYSTACKDATA[-3]).pn__7YYSTYPE;
        yyval.p__7YYSTYPE =
            (struct node *)((__1__X146 = (yystack.l_mark__11YYSTACKDATA[-3]).pn__7YYSTYPE),
                            (((__1__X146->base__4node != 123)
                                  ? ((__1__Xnn00qycjpkkfwcaj = __1__X146), 0)
                                  : ((__1__Xnn00qycjpkkfwcaj = __ct__4nameFPCc(
                                          (struct name *)0, __1__X146->__O2__4expr.string)),
                                     (__1__Xnn00qycjpkkfwcaj->n_template_arg__4name =
                                          __1__X146->n_template_arg__4name))),
                             __1__Xnn00qycjpkkfwcaj));

        if ((!in_typedef) &&
            ((ccl == 0) || strcmp(__3n->__O2__4expr.string, ccl->string__8classdef)))
            hide__4nameFv(__3n);
        yyval.pn__7YYSTYPE->n_oper__4name = 123;
        yyval.pn__7YYSTYPE->__O1__4expr.tp = (struct type *)__ct__3fctFP4typeP4nameUc(
            (struct fct *)0, (struct type *)0, (yystack.l_mark__11YYSTACKDATA[-1]).pn__7YYSTYPE,
            (unsigned char)1);
    }

    break;
    case 191: {
        Pname __3n;

        struct name *__1__X147;

        struct name *__1__Xnn00qycjpkkfwcaj;

        __3n = (yystack.l_mark__11YYSTACKDATA[-3]).pn__7YYSTYPE;
        yyval.p__7YYSTYPE =
            (struct node *)((__1__X147 = (yystack.l_mark__11YYSTACKDATA[-3]).pn__7YYSTYPE),
                            (((__1__X147->base__4node != 123)
                                  ? ((__1__Xnn00qycjpkkfwcaj = __1__X147), 0)
                                  : ((__1__Xnn00qycjpkkfwcaj = __ct__4nameFPCc(
                                          (struct name *)0, __1__X147->__O2__4expr.string)),
                                     (__1__Xnn00qycjpkkfwcaj->n_template_arg__4name =
                                          __1__X147->n_template_arg__4name))),
                             __1__Xnn00qycjpkkfwcaj));

        if ((!in_typedef) &&
            ((ccl == 0) || strcmp(__3n->__O2__4expr.string, ccl->string__8classdef)))
            hide__4nameFv(__3n);
        yyval.pn__7YYSTYPE->n_oper__4name = 123;
        yyval.pn__7YYSTYPE->__O1__4expr.tp = (struct type *)__ct__3fctFP4typeP4nameUc(
            (struct fct *)0, (struct type *)0, (struct name *)0, (unsigned char)1);
        (((struct fct *)(((struct fct *)yyval.pn__7YYSTYPE->__O1__4expr.tp))))->f_const__3fct =
            ((yystack.l_mark__11YYSTACKDATA[0]).i__7YYSTYPE & 1);
    }

    break;
    case 192: {
        memptrdcl__FP4nameT1P4typeT1((yystack.l_mark__11YYSTACKDATA[-3]).pn__7YYSTYPE,
                                     (yystack.l_mark__11YYSTACKDATA[-5]).pn__7YYSTYPE,
                                     (yystack.l_mark__11YYSTACKDATA[0]).pt__7YYSTYPE,
                                     (yystack.l_mark__11YYSTACKDATA[-2]).pn__7YYSTYPE);
        yyval.p__7YYSTYPE = (yystack.l_mark__11YYSTACKDATA[-2]).p__7YYSTYPE;
    }

    break;
    case 193: {
        if ((((yystack.l_mark__11YYSTACKDATA[0]).pn__7YYSTYPE->n_oper__4name == 0) &&
             (!in_typedef)) &&
            (!in_friend)) {
            if (((ccl == 0) || (parsing_class_members == 0)) ||
                strcmp(ccl->string__8classdef,
                       (yystack.l_mark__11YYSTACKDATA[0]).pn__7YYSTYPE->__O2__4expr.string)) {
                Pname __5n;

                __5n = __ct__4nameFPCc((struct name *)0, (const char *)0);

                ((*__5n)) = (*(yystack.l_mark__11YYSTACKDATA[0]).pn__7YYSTYPE);
                insert_name__FP4nameP6ktable(__5n, Ctbl);
            }
        }
    }

    break;
    case 194: {
        struct name *__1__X148;

        struct name *__1__Xnn00qycjpkkfwcaj;

        yyval.p__7YYSTYPE =
            (struct node *)((__1__X148 = (yystack.l_mark__11YYSTACKDATA[0]).pn__7YYSTYPE),
                            (((__1__X148->base__4node != 123)
                                  ? ((__1__Xnn00qycjpkkfwcaj = __1__X148), 0)
                                  : ((__1__Xnn00qycjpkkfwcaj = __ct__4nameFPCc(
                                          (struct name *)0, __1__X148->__O2__4expr.string)),
                                     (__1__Xnn00qycjpkkfwcaj->n_template_arg__4name =
                                          __1__X148->n_template_arg__4name))),
                             __1__Xnn00qycjpkkfwcaj));

        error__FPCc((const char *)"`.' used for qualification; please use `::'");
    }

    break;
    case 195: {
        const void *__2__X149;

        yyval.p__7YYSTYPE = (yystack.l_mark__11YYSTACKDATA[0]).p__7YYSTYPE;

        if (((yystack.l_mark__11YYSTACKDATA[-1]).pn__7YYSTYPE == sta_name) &&
            (yyval.pn__7YYSTYPE->n_oper__4name == 162)) {
            struct ea __0__V94;

            error__FPCcRC2eaN32(
                (const char *)"bad syntax for destructor ::%n",
                (const struct ea *)((__2__X149 = (const void *)yyval.pn__7YYSTYPE),
                                    (((&__0__V94)->__O1__2ea.p = __2__X149), (&__0__V94))),
                (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
        }
        yyval.pn__7YYSTYPE->__O2__4name.n_qualifier =
            (yystack.l_mark__11YYSTACKDATA[-1]).pn__7YYSTYPE;

    }

    break;
    case 196: {
        struct name *__1__X150;

        struct name *__1__Xnn00qycjpkkfwcaj;

        const void *__2__X151;

        yyval.p__7YYSTYPE =
            (struct node *)((__1__X150 = (yystack.l_mark__11YYSTACKDATA[0]).pn__7YYSTYPE),
                            (((__1__X150->base__4node != 123)
                                  ? ((__1__Xnn00qycjpkkfwcaj = __1__X150), 0)
                                  : ((__1__Xnn00qycjpkkfwcaj = __ct__4nameFPCc(
                                          (struct name *)0, __1__X150->__O2__4expr.string)),
                                     (__1__Xnn00qycjpkkfwcaj->n_template_arg__4name =
                                          __1__X150->n_template_arg__4name))),
                             __1__Xnn00qycjpkkfwcaj));

        error__FPCc((const char *)"`.' used for qualification; please use `::'");
        {
            struct ea __0__V95;

            error__FPCcRC2eaN32(
                (const char *)"non-type qualifier%n",
                (const struct ea *)((__2__X151 = (const void *)(yystack.l_mark__11YYSTACKDATA[-2])
                                                     .pn__7YYSTYPE),
                                    (((&__0__V95)->__O1__2ea.p = __2__X151), (&__0__V95))),
                (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
        }
    }

    break;
    case 197: {
        (((struct ptr *)(((struct ptr *)(yystack.l_mark__11YYSTACKDATA[-1]).p__7YYSTYPE))))
            ->typ__5pvtyp = (yystack.l_mark__11YYSTACKDATA[0]).pn__7YYSTYPE->__O1__4expr.tp;
        (yystack.l_mark__11YYSTACKDATA[0]).pn__7YYSTYPE->__O1__4expr.tp =
            (yystack.l_mark__11YYSTACKDATA[-1]).pt__7YYSTYPE;
        yyval.p__7YYSTYPE = (yystack.l_mark__11YYSTACKDATA[0]).p__7YYSTYPE;
    }

    break;
    case 198: {
        struct name *__1__X152;

        struct name *__1__Xnn00qycjpkkfwcaj;

        yyval.p__7YYSTYPE =
            (struct node *)((__1__X152 = (yystack.l_mark__11YYSTACKDATA[0]).pn__7YYSTYPE),
                            (((__1__X152->base__4node != 123)
                                  ? ((__1__Xnn00qycjpkkfwcaj = __1__X152), 0)
                                  : ((__1__Xnn00qycjpkkfwcaj = __ct__4nameFPCc(
                                          (struct name *)0, __1__X152->__O2__4expr.string)),
                                     (__1__Xnn00qycjpkkfwcaj->n_template_arg__4name =
                                          __1__X152->n_template_arg__4name))),
                             __1__Xnn00qycjpkkfwcaj));

        yyval.pn__7YYSTYPE->n_oper__4name = 123;

        if (!in_typedef)
            hide__4nameFv((yystack.l_mark__11YYSTACKDATA[0]).pn__7YYSTYPE);
        else
            in_tag = (yystack.l_mark__11YYSTACKDATA[0]).pn__7YYSTYPE;
        yyval.pn__7YYSTYPE->__O1__4expr.tp = (yystack.l_mark__11YYSTACKDATA[-1]).pt__7YYSTYPE;
    }

    break;
    case 199: {
        struct name *__1__X153;

        struct name *__1__Xnn00qycjpkkfwcaj;

        yyval.p__7YYSTYPE =
            (struct node *)((__1__X153 = (yystack.l_mark__11YYSTACKDATA[-1]).pn__7YYSTYPE),
                            (((__1__X153->base__4node != 123)
                                  ? ((__1__Xnn00qycjpkkfwcaj = __1__X153), 0)
                                  : ((__1__Xnn00qycjpkkfwcaj = __ct__4nameFPCc(
                                          (struct name *)0, __1__X153->__O2__4expr.string)),
                                     (__1__Xnn00qycjpkkfwcaj->n_template_arg__4name =
                                          __1__X153->n_template_arg__4name))),
                             __1__Xnn00qycjpkkfwcaj));

        yyval.pn__7YYSTYPE->n_oper__4name = 123;
        if (!in_typedef)
            hide__4nameFv((yystack.l_mark__11YYSTACKDATA[-1]).pn__7YYSTYPE);
        else
            in_tag = (yystack.l_mark__11YYSTACKDATA[-1]).pn__7YYSTYPE;
        yyval.pn__7YYSTYPE->__O1__4expr.tp = (yystack.l_mark__11YYSTACKDATA[0]).pt__7YYSTYPE;
    }

    break;
    case 200: {
        (((struct vec *)(((struct vec *)(yystack.l_mark__11YYSTACKDATA[0]).p__7YYSTYPE))))
            ->typ__5pvtyp = (yystack.l_mark__11YYSTACKDATA[-1]).pn__7YYSTYPE->__O1__4expr.tp;
        (yystack.l_mark__11YYSTACKDATA[-1]).pn__7YYSTYPE->__O1__4expr.tp =
            (yystack.l_mark__11YYSTACKDATA[0]).pt__7YYSTYPE;
    }

    break;
    case 201: {
        yyval.p__7YYSTYPE = (yystack.l_mark__11YYSTACKDATA[-1]).p__7YYSTYPE;
        in_arg_list = 0;
        hoist_al__Fv();

    }

    break;
    case 202: {
        if ((yystack.l_mark__11YYSTACKDATA[0]).pn__7YYSTYPE->n_oper__4name != 123) {
            Pname __4n;

            __4n = __ct__4nameFPCc((struct name *)0, (const char *)0);

            ((*__4n)) = (*(yystack.l_mark__11YYSTACKDATA[0]).pn__7YYSTYPE);
            insert_name__FP4nameP6ktable(__4n, Ctbl);
        }
        yyval.p__7YYSTYPE = (struct node *)(yystack.l_mark__11YYSTACKDATA[0]).pn__7YYSTYPE;
    }

    break;
    case 203: {
        struct name *__1__X154;

        struct name *__1__Xnn00qycjpkkfwcaj;

        yyval.p__7YYSTYPE =
            (struct node *)((__1__X154 = (yystack.l_mark__11YYSTACKDATA[0]).pn__7YYSTYPE),
                            (((__1__X154->base__4node != 123)
                                  ? ((__1__Xnn00qycjpkkfwcaj = __1__X154), 0)
                                  : ((__1__Xnn00qycjpkkfwcaj = __ct__4nameFPCc(
                                          (struct name *)0, __1__X154->__O2__4expr.string)),
                                     (__1__Xnn00qycjpkkfwcaj->n_template_arg__4name =
                                          __1__X154->n_template_arg__4name))),
                             __1__Xnn00qycjpkkfwcaj));
        yyval.pn__7YYSTYPE->n_oper__4name = 123;
        hide__4nameFv((yystack.l_mark__11YYSTACKDATA[0]).pn__7YYSTYPE);
        yyval.pn__7YYSTYPE->__O1__4expr.tp = (yystack.l_mark__11YYSTACKDATA[-1]).pt__7YYSTYPE;
    }

    break;
    case 204: {
        yyval.p__7YYSTYPE = (struct node *)__ct__4nameFPCc((struct name *)0, (const char *)0);
        must_be_id = 0;
    }

    break;
    case 205: {
        (((struct ptr *)(((struct ptr *)(yystack.l_mark__11YYSTACKDATA[-1]).p__7YYSTYPE))))
            ->typ__5pvtyp = (yystack.l_mark__11YYSTACKDATA[0]).pn__7YYSTYPE->__O1__4expr.tp;
        (yystack.l_mark__11YYSTACKDATA[0]).pn__7YYSTYPE->__O1__4expr.tp =
            (((struct type *)(((struct type *)(yystack.l_mark__11YYSTACKDATA[-1]).p__7YYSTYPE))));
        yyval.p__7YYSTYPE = (yystack.l_mark__11YYSTACKDATA[0]).p__7YYSTYPE;
    }

    break;
    case 206: {
        (((struct vec *)(((struct vec *)(yystack.l_mark__11YYSTACKDATA[0]).p__7YYSTYPE))))
            ->typ__5pvtyp = (yystack.l_mark__11YYSTACKDATA[-1]).pn__7YYSTYPE->__O1__4expr.tp;
        (yystack.l_mark__11YYSTACKDATA[-1]).pn__7YYSTYPE->__O1__4expr.tp =
            (((struct type *)(((struct type *)(yystack.l_mark__11YYSTACKDATA[0]).p__7YYSTYPE))));
    }

    break;
    case 207: {
        (((struct fct *)(((struct fct *)(yystack.l_mark__11YYSTACKDATA[0]).p__7YYSTYPE))))
            ->returns__3fct = (yystack.l_mark__11YYSTACKDATA[-1]).pn__7YYSTYPE->__O1__4expr.tp;
        (yystack.l_mark__11YYSTACKDATA[-1]).pn__7YYSTYPE->__O1__4expr.tp =
            (((struct type *)(((struct type *)(yystack.l_mark__11YYSTACKDATA[0]).p__7YYSTYPE))));
    }

    break;
    case 208: {
        yyval.p__7YYSTYPE = (yystack.l_mark__11YYSTACKDATA[-1]).p__7YYSTYPE;
        in_arg_list = 0;
        hoist_al__Fv();

    }

    break;
    case 209: {
        yyval.p__7YYSTYPE = (struct node *)__ct__4nameFPCc((struct name *)0, (const char *)0);

    }

    break;
    case 210: {
        (((struct ptr *)(((struct ptr *)(yystack.l_mark__11YYSTACKDATA[-1]).p__7YYSTYPE))))
            ->typ__5pvtyp = (yystack.l_mark__11YYSTACKDATA[0]).pn__7YYSTYPE->__O1__4expr.tp;
        (yystack.l_mark__11YYSTACKDATA[0]).pn__7YYSTYPE->__O1__4expr.tp =
            (((struct type *)(((struct type *)(yystack.l_mark__11YYSTACKDATA[-1]).p__7YYSTYPE))));
        yyval.p__7YYSTYPE = (yystack.l_mark__11YYSTACKDATA[0]).p__7YYSTYPE;
        must_be_id = 0;
    }

    break;
    case 211: {
        (((struct vec *)(((struct vec *)(yystack.l_mark__11YYSTACKDATA[0]).p__7YYSTYPE))))
            ->typ__5pvtyp = (yystack.l_mark__11YYSTACKDATA[-1]).pn__7YYSTYPE->__O1__4expr.tp;
        (yystack.l_mark__11YYSTACKDATA[-1]).pn__7YYSTYPE->__O1__4expr.tp =
            (((struct type *)(((struct type *)(yystack.l_mark__11YYSTACKDATA[0]).p__7YYSTYPE))));
    }

    break;
    case 212: {
        yyval.p__7YYSTYPE = (struct node *)__ct__4nameFPCc((struct name *)0, (const char *)0);

    }

    break;
    case 213: {
        (((struct ptr *)(((struct ptr *)(yystack.l_mark__11YYSTACKDATA[-1]).p__7YYSTYPE))))
            ->typ__5pvtyp = (yystack.l_mark__11YYSTACKDATA[0]).pn__7YYSTYPE->__O1__4expr.tp;
        (yystack.l_mark__11YYSTACKDATA[0]).pn__7YYSTYPE->__O1__4expr.tp =
            (((struct type *)(((struct type *)(yystack.l_mark__11YYSTACKDATA[-1]).p__7YYSTYPE))));
        yyval.p__7YYSTYPE = (yystack.l_mark__11YYSTACKDATA[0]).p__7YYSTYPE;
        must_be_id = 0;
    }

    break;
    case 214: {
        (((struct vec *)(((struct vec *)(yystack.l_mark__11YYSTACKDATA[0]).p__7YYSTYPE))))
            ->typ__5pvtyp = (yystack.l_mark__11YYSTACKDATA[-1]).pn__7YYSTYPE->__O1__4expr.tp;
        (yystack.l_mark__11YYSTACKDATA[-1]).pn__7YYSTYPE->__O1__4expr.tp =
            (((struct type *)(((struct type *)(yystack.l_mark__11YYSTACKDATA[0]).p__7YYSTYPE))));
    }

    break;
    case 215: {
        (((struct fct *)(((struct fct *)(yystack.l_mark__11YYSTACKDATA[0]).p__7YYSTYPE))))
            ->returns__3fct = (yystack.l_mark__11YYSTACKDATA[-2]).pn__7YYSTYPE->__O1__4expr.tp;
        (yystack.l_mark__11YYSTACKDATA[-2]).pn__7YYSTYPE->__O1__4expr.tp =
            (yystack.l_mark__11YYSTACKDATA[0]).pt__7YYSTYPE;
        yyval.p__7YYSTYPE = (yystack.l_mark__11YYSTACKDATA[-2]).p__7YYSTYPE;
    }

    break;
    case 216: {
        (((struct vec *)(((struct vec *)(yystack.l_mark__11YYSTACKDATA[0]).p__7YYSTYPE))))
            ->typ__5pvtyp = (yystack.l_mark__11YYSTACKDATA[-2]).pn__7YYSTYPE->__O1__4expr.tp;
        (yystack.l_mark__11YYSTACKDATA[-2]).pn__7YYSTYPE->__O1__4expr.tp =
            (yystack.l_mark__11YYSTACKDATA[0]).pt__7YYSTYPE;
        yyval.p__7YYSTYPE = (yystack.l_mark__11YYSTACKDATA[-2]).p__7YYSTYPE;
    }

    break;
    case 217: {
        yyval.p__7YYSTYPE = (struct node *)__ct__4nameFPCc((struct name *)0, (const char *)0);

    }

    break;
    case 218: {
        (((struct ptr *)(((struct ptr *)(yystack.l_mark__11YYSTACKDATA[-1]).p__7YYSTYPE))))
            ->typ__5pvtyp = (yystack.l_mark__11YYSTACKDATA[0]).pn__7YYSTYPE->__O1__4expr.tp;
        (yystack.l_mark__11YYSTACKDATA[0]).pn__7YYSTYPE->__O1__4expr.tp =
            (((struct type *)(((struct type *)(yystack.l_mark__11YYSTACKDATA[-1]).p__7YYSTYPE))));
        yyval.p__7YYSTYPE = (yystack.l_mark__11YYSTACKDATA[0]).p__7YYSTYPE;
    }

    break;
    case 219: {
        yyval.p__7YYSTYPE = 0;
    }

    break;
    case 220: {
        error__FPCc((const char *)"ZizedTD must be atG, not local scope");
        error__FiPCc((int)'i', (const char *)"cannot recover from previous error");
    }

    break;
    case 221: {
        register struct slist *__0__X155;

        struct stmt *__2__X156;

        if ((yystack.l_mark__11YYSTACKDATA[0]).p__7YYSTYPE)
            if ((yystack.l_mark__11YYSTACKDATA[-1]).p__7YYSTYPE)
                ((__0__X155 = (yystack.l_mark__11YYSTACKDATA[-1]).sl__7YYSTYPE),
                 ((__2__X156 = (yystack.l_mark__11YYSTACKDATA[0]).ps__7YYSTYPE),
                  (((__0__X155->tail__5slist->s_list__4stmt = __2__X156),
                    (__0__X155->tail__5slist = __2__X156)),
                   (((void)0)))));
            else {
                struct slist *__0__X157;

                struct stmt *__2__X158;

                yyval.sl__7YYSTYPE =
                    ((__0__X157 = 0),
                     ((__2__X158 = (yystack.l_mark__11YYSTACKDATA[0]).ps__7YYSTYPE),
                      (((__0__X157 ||
                         (__0__X157 = (struct slist *)__nw__FUl((size_t)(sizeof(struct slist)))))
                            ? ((__0__X157->head__5slist = (__0__X157->tail__5slist = __2__X158)), 0)
                            : 0),
                       __0__X157)));
                stmt_seen = 1;
            }
    }

    break;
    case 222: {
        yyval.p__7YYSTYPE = (yystack.l_mark__11YYSTACKDATA[0]).p__7YYSTYPE;
        if ((yystack.l_mark__11YYSTACKDATA[0]).p__7YYSTYPE)
            stmt_seen = 1;
    }

    break;
    case 223: {
        yyval.p__7YYSTYPE = 0;
        check_decl__Fv();
    }

    break;
    case 224: {
        yyval.p__7YYSTYPE = (yystack.l_mark__11YYSTACKDATA[-1]).p__7YYSTYPE;

        stmt_seen = 1;
    }

    break;
    case 225: {
        (((((Ctbl->k_id__6ktable == 136)
                ? (((void)expand__6ktableFi(Ctbl, 20)))
                : (((void)(Ctbl = __ct__6ktableFiP6ktableP4name((struct ktable *)0, 20, Ctbl,
                                                                Ctbl->k_name__6ktable))))),
           ((Ctbl->k_id__6ktable = 116),
            ((((Ctbl->k_next__6ktable == Gtbl) || (Ctbl->k_next__6ktable->k_id__6ktable == 116)) ||
              (Ctbl->k_next__6ktable->k_id__6ktable == 6))
                 ? ((Ctbl->__O1__6ktable.k_t->next__5table =
                         Ctbl->k_next__6ktable->__O1__6ktable.k_t),
                    0)
                 : 0)))),
         (((void)0)));
        (cd_vec[cdi]) = cd;
        (stmt_vec[cdi]) = stmt_seen;
        ++cdi;
        cd = 0;
        stmt_seen = 0;

    }

    break;
    case 226: {
        Pname __3n;
        Pstmt __3ss;

        register struct block *__0__X159;

        struct loc __2__X160;

        struct loc __2__X161;

        unsigned long __2__X162;

        __3n = name_unlist__FP5nlist(cd);
        __3ss = stmt_unlist__FP5slist((yystack.l_mark__11YYSTACKDATA[-1]).sl__7YYSTYPE);
        yyval.p__7YYSTYPE =
            (struct node *)((__0__X159 = 0),
                            ((__2__X160 = (yystack.l_mark__11YYSTACKDATA[-3]).l__7YYSTYPE),
                             ((__2__X161 = (yystack.l_mark__11YYSTACKDATA[0]).l__7YYSTYPE),
                              (((__0__X159 || (__0__X159 = (struct block *)__nw__4stmtSFUl(
                                                   (size_t)(sizeof(struct block)))))
                                    ? (((void)((__0__X159 =
                                                    (struct block *)__ct__4stmtFUc3locP4stmt(
                                                        ((struct stmt *)__0__X159),
                                                        (unsigned char)116, __2__X160, __3ss)),
                                               ((__0__X159->__O1__4stmt.d = __3n),
                                                (__0__X159->__O3__4stmt.where2 = __2__X161)))))
                                    : (((void)0))),
                               __0__X159))));

        cd = (cd_vec[(--cdi)]);
        stmt_seen = (stmt_vec[cdi]);
        if (cdi < 0) {
            struct ea __0__V96;

            error__FiPCcRC2eaN33(
                (int)'i', (const char *)"block level(%d)",
                (const struct ea *)((__2__X162 = cdi),
                                    (((((&__0__V96)->__O1__2ea.i = __2__X162), 0)), (&__0__V96))),
                (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
        }
        must_be_id = 0;
        yyval.ps__7YYSTYPE->k_tbl__4stmt = Ctbl;

        {
            ;

            if (Ctbl == Gtbl)
                error__FiPCc((int)'i', (const char *)"bad parsing table");

            {
                Pktab __1b;

                __1b = Ctbl;

                Ctbl = Ctbl->k_next__6ktable;

                if ((__1b->k_id__6ktable == 136) || 0)
                    __dt__6ktableFv(__1b, 3);
            }
        }

    }

    break;
    case 227: {
        register struct block *__0__X163;

        struct loc __2__X164;

        struct loc __2__X165;

        yyval.p__7YYSTYPE =
            (struct node
                 *)((__0__X163 = 0),
                    ((__2__X164 = (yystack.l_mark__11YYSTACKDATA[-1]).l__7YYSTYPE),
                     ((__2__X165 = (yystack.l_mark__11YYSTACKDATA[0]).l__7YYSTYPE),
                      (((__0__X163 || (__0__X163 = (struct block *)__nw__4stmtSFUl(
                                           (size_t)(sizeof(struct block)))))
                            ? (((void)((__0__X163 = (struct block *)__ct__4stmtFUc3locP4stmt(
                                            ((struct stmt *)__0__X163), (unsigned char)116,
                                            __2__X164, ((struct stmt *)0))),
                                       ((__0__X163->__O1__4stmt.d = ((struct name *)0)),
                                        (__0__X163->__O3__4stmt.where2 = __2__X165)))))
                            : (((void)0))),
                       __0__X163))));

        must_be_id = 0;
        if (Ctbl->k_id__6ktable == 136) {
            ;

            if (Ctbl == Gtbl)
                error__FiPCc((int)'i', (const char *)"bad parsing table");

            {
                Pktab __1b;

                __1b = Ctbl;

                Ctbl = Ctbl->k_next__6ktable;

                if ((__1b->k_id__6ktable == 136) || 0)
                    __dt__6ktableFv(__1b, 3);
            }
        }

    }

    break;
    case 228: {
        register struct block *__0__X166;

        struct loc __2__X167;

        struct loc __2__X168;

        yyval.p__7YYSTYPE =
            (struct node
                 *)((__0__X166 = 0),
                    ((__2__X167 = (yystack.l_mark__11YYSTACKDATA[-2]).l__7YYSTYPE),
                     ((__2__X168 = (yystack.l_mark__11YYSTACKDATA[0]).l__7YYSTYPE),
                      (((__0__X166 || (__0__X166 = (struct block *)__nw__4stmtSFUl(
                                           (size_t)(sizeof(struct block)))))
                            ? (((void)((__0__X166 = (struct block *)__ct__4stmtFUc3locP4stmt(
                                            ((struct stmt *)__0__X166), (unsigned char)116,
                                            __2__X167, ((struct stmt *)0))),
                                       ((__0__X166->__O1__4stmt.d = ((struct name *)0)),
                                        (__0__X166->__O3__4stmt.where2 = __2__X168)))))
                            : (((void)0))),
                       __0__X166))));

        must_be_id = 0;
        if (Ctbl->k_id__6ktable == 136) {
            ;

            if (Ctbl == Gtbl)
                error__FiPCc((int)'i', (const char *)"bad parsing table");

            {
                Pktab __1b;

                __1b = Ctbl;

                Ctbl = Ctbl->k_next__6ktable;

                if ((__1b->k_id__6ktable == 136) || 0)
                    __dt__6ktableFv(__1b, 3);
            }
        }

    }

    break;
    case 229: {
        struct estmt *__0__X169;

        struct loc __2__X170;

        struct expr *__2__X171;

        yyval.p__7YYSTYPE =
            (struct node *)((__0__X169 = 0),
                            ((__2__X170 = curloc),
                             ((__2__X171 = (yystack.l_mark__11YYSTACKDATA[0]).pe__7YYSTYPE),
                              (((__0__X169 || (__0__X169 = (struct estmt *)__nw__4stmtSFUl(
                                                   (size_t)(sizeof(struct estmt)))))
                                    ? ((__0__X169 = (struct estmt *)__ct__4stmtFUc3locP4stmt(
                                            ((struct stmt *)__0__X169), ((unsigned char)72),
                                            __2__X170, ((struct stmt *)0))),
                                       (__0__X169->__O2__4stmt.e = __2__X171))
                                    : 0),
                               __0__X169))));

    }

    break;
    case 230: {
        yyval.p__7YYSTYPE = (struct node *)__ct__4stmtFUc3locP4stmt(
            (struct stmt *)0, (unsigned char)3, (yystack.l_mark__11YYSTACKDATA[0]).l__7YYSTYPE,
            (struct stmt *)0);

    }

    break;
    case 231: {
        yyval.p__7YYSTYPE = (struct node *)__ct__4stmtFUc3locP4stmt(
            (struct stmt *)0, (unsigned char)7, (yystack.l_mark__11YYSTACKDATA[0]).l__7YYSTYPE,
            (struct stmt *)0);

    }

    break;
    case 232: {
        struct lstmt *__0__X172;

        struct loc __2__X173;

        struct name *__2__X174;

        yyval.p__7YYSTYPE =
            (struct node *)((__0__X172 = 0),
                            ((__2__X173 = (yystack.l_mark__11YYSTACKDATA[-1]).l__7YYSTYPE),
                             ((__2__X174 = (yystack.l_mark__11YYSTACKDATA[0]).pn__7YYSTYPE),
                              (((__0__X172 || (__0__X172 = (struct lstmt *)__nw__4stmtSFUl(
                                                   (size_t)(sizeof(struct lstmt)))))
                                    ? ((__0__X172 = (struct lstmt *)__ct__4stmtFUc3locP4stmt(
                                            ((struct stmt *)__0__X172), ((unsigned char)19),
                                            __2__X173, ((struct stmt *)0))),
                                       (__0__X172->__O1__4stmt.d = __2__X174))
                                    : 0),
                               __0__X172))));

    }

    break;
    case 233: {
        stmt_seen = 1;

    }

    break;
    case 234: {
        struct estmt *__0__X175;

        struct loc __2__X176;

        struct expr *__2__X177;

        struct stmt *__2__X178;

        yyval.p__7YYSTYPE =
            (struct node *)((__0__X175 = 0),
                            ((__2__X176 = (yystack.l_mark__11YYSTACKDATA[-4]).l__7YYSTYPE),
                             ((__2__X177 = (yystack.l_mark__11YYSTACKDATA[0]).pe__7YYSTYPE),
                              ((__2__X178 = (yystack.l_mark__11YYSTACKDATA[-2]).ps__7YYSTYPE),
                               (((__0__X175 || (__0__X175 = (struct estmt *)__nw__4stmtSFUl(
                                                    (unsigned long)(sizeof(struct estmt)))))
                                     ? ((__0__X175 = (struct estmt *)__ct__4stmtFUc3locP4stmt(
                                             ((struct stmt *)__0__X175), ((unsigned char)10),
                                             __2__X176, __2__X178)),
                                        (__0__X175->__O2__4stmt.e = __2__X177))
                                     : 0),
                                __0__X175)))));

    }

    break;
    case 235: {
        struct estmt *__0__X179;

        struct loc __2__X180;

        struct expr *__2__X181;

        if (stmt_seen)
            yyval.p__7YYSTYPE =
                (struct node
                     *)((__0__X179 = 0),
                        ((__2__X180 = curloc),
                         ((__2__X181 = (((struct expr *)((
                               (struct expr *)(yystack.l_mark__11YYSTACKDATA[-1]).s__7YYSTYPE))))),
                          (((__0__X179 || (__0__X179 = (struct estmt *)__nw__4stmtSFUl(
                                               (size_t)(sizeof(struct estmt)))))
                                ? ((__0__X179 = (struct estmt *)__ct__4stmtFUc3locP4stmt(
                                        ((struct stmt *)__0__X179), ((unsigned char)1), __2__X180,
                                        ((struct stmt *)0))),
                                   (__0__X179->__O2__4stmt.e = __2__X181))
                                : 0),
                           __0__X179))));
        else {
            Pname __4n;

            __4n =
                __ct__4nameFPCc((struct name *)0, (const char *)make_name__FUc((unsigned char)'A'));
            __4n->__O1__4expr.tp = (struct type *)__ct__8basetypeFUcP4name(
                (struct basetype *)0, (unsigned char)1,
                ((struct name *)((
                    (struct name *)(yystack.l_mark__11YYSTACKDATA[-1]).s__7YYSTYPE))));
            if (cd)
                add_list__5nlistFP4name(cd, __4n);
            else
                cd = __ct__5nlistFP4name((struct nlist *)0, __4n);
            yyval.p__7YYSTYPE = 0;
        }
    }

    break;
    case 236: {
        if (((yychar == -1) ? ((yychar = lalex__Fv()), yychar) : yychar) != 72) {
            error__FPCc((const char *)"`;' missing afterS");
            la_backup__FUc7YYSTYPE((unsigned char)yychar, yylval);
            yychar = 72;
        }
    }

    break;
    case 239: {
        struct estmt *__0__X182;

        struct loc __2__X183;

        struct expr *__2__X184;

        yyval.p__7YYSTYPE =
            (struct node *)((__0__X182 = 0),
                            ((__2__X183 = curloc),
                             ((__2__X184 = dummy),
                              (((__0__X182 || (__0__X182 = (struct estmt *)__nw__4stmtSFUl(
                                                   (size_t)(sizeof(struct estmt)))))
                                    ? ((__0__X182 = (struct estmt *)__ct__4stmtFUc3locP4stmt(
                                            ((struct stmt *)__0__X182), ((unsigned char)72),
                                            __2__X183, ((struct stmt *)0))),
                                       (__0__X182->__O2__4stmt.e = __2__X184))
                                    : 0),
                               __0__X182))));

    }

    break;
    case 240: {
        struct estmt *__0__X185;

        struct loc __2__X186;

        struct expr *__2__X187;

        yyval.p__7YYSTYPE =
            (struct node *)((__0__X185 = 0),
                            ((__2__X186 = (yystack.l_mark__11YYSTACKDATA[-2]).l__7YYSTYPE),
                             ((__2__X187 = (yystack.l_mark__11YYSTACKDATA[-1]).pe__7YYSTYPE),
                              (((__0__X185 || (__0__X185 = (struct estmt *)__nw__4stmtSFUl(
                                                   (size_t)(sizeof(struct estmt)))))
                                    ? ((__0__X185 = (struct estmt *)__ct__4stmtFUc3locP4stmt(
                                            ((struct stmt *)__0__X185), ((unsigned char)28),
                                            __2__X186, ((struct stmt *)0))),
                                       (__0__X185->__O2__4stmt.e = __2__X187))
                                    : 0),
                               __0__X185))));

    }

    break;
    case 241: {
        error__FPCc((const char *)"local linkage specification");
        yyval.p__7YYSTYPE = (struct node *)(yystack.l_mark__11YYSTACKDATA[0]).pn__7YYSTYPE;
    }

    break;
    case 242: {
        Pname __3n;

        __3n = (yystack.l_mark__11YYSTACKDATA[0]).pn__7YYSTYPE;
        if (__3n) {
            if (stmt_seen) {
                register struct block *__0__X188;

                struct loc __2__X189;

                struct loc __2__X190;

                yyval.p__7YYSTYPE =
                    (struct node
                         *)((__0__X188 = 0),
                            ((__2__X189 = __3n->where__4name),
                             ((__2__X190 = noloc),
                              (((__0__X188 || (__0__X188 = (struct block *)__nw__4stmtSFUl(
                                                   (size_t)(sizeof(struct block)))))
                                    ? (((void)((__0__X188 =
                                                    (struct block *)__ct__4stmtFUc3locP4stmt(
                                                        ((struct stmt *)__0__X188),
                                                        (unsigned char)116, __2__X189,
                                                        ((struct stmt *)0))),
                                               ((__0__X188->__O1__4stmt.d = __3n),
                                                (__0__X188->__O3__4stmt.where2 = __2__X190)))))
                                    : (((void)0))),
                               __0__X188))));
                yyval.ps__7YYSTYPE->base__4node = 118;
                yyval.ps__7YYSTYPE->k_tbl__4stmt = Ctbl;
            } else {
                if (cd)
                    add_list__5nlistFP4name(cd, __3n);
                else
                    cd = __ct__5nlistFP4name((struct nlist *)0, __3n);
                yyval.p__7YYSTYPE = 0;
            }
        } else if (stmt_seen) {
            register struct block *__0__X191;

            struct loc __2__X192;

            struct loc __2__X193;

            yyval.p__7YYSTYPE =
                (struct node
                     *)((__0__X191 = 0),
                        ((__2__X192 = curloc),
                         ((__2__X193 = noloc),
                          (((__0__X191 || (__0__X191 = (struct block *)__nw__4stmtSFUl(
                                               (size_t)(sizeof(struct block)))))
                                ? (((void)((__0__X191 = (struct block *)__ct__4stmtFUc3locP4stmt(
                                                ((struct stmt *)__0__X191), (unsigned char)116,
                                                __2__X192, ((struct stmt *)0))),
                                           ((__0__X191->__O1__4stmt.d = ((struct name *)0)),
                                            (__0__X191->__O3__4stmt.where2 = __2__X193)))))
                                : (((void)0))),
                           __0__X191))));
            yyval.ps__7YYSTYPE->base__4node = 117;
        }
    }

    break;
    case 243: {
        Pname __3n;

        __3n = (yystack.l_mark__11YYSTACKDATA[0]).pn__7YYSTYPE;
        if (!in_progress__17templ_compilation) {
            struct ea __0__V97;

            error__FP3locPCcRC2eaN33(
                &__3n->where__4name,
                (const char *)"%n's definition is nested (did you forget a ``}''?)",
                (const struct ea *)(((&__0__V97)->__O1__2ea.p = ((const void *)__3n)), (&__0__V97)),
                (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
        }
        if (cd)
            add_list__5nlistFP4name(cd, __3n);
        else
            cd = __ct__5nlistFP4name((struct nlist *)0, __3n);
        yyval.p__7YYSTYPE = 0;
    }

    break;
    case 245: {
        register struct ifstmt *__0__X194;

        struct loc __2__X195;

        struct expr *__2__X196;

        struct stmt *__2__X197;

        struct stmt *__2__X198;

        yyval.p__7YYSTYPE =
            (struct node *)((__0__X194 = 0),
                            ((__2__X195 = (yystack.l_mark__11YYSTACKDATA[-2]).l__7YYSTYPE),
                             ((__2__X196 = (yystack.l_mark__11YYSTACKDATA[-1]).pe__7YYSTYPE),
                              ((__2__X197 = (yystack.l_mark__11YYSTACKDATA[0]).ps__7YYSTYPE),
                               ((__2__X198 = 0),
                                (((__0__X194 || (__0__X194 = (struct ifstmt *)__nw__4stmtSFUl(
                                                     (size_t)(sizeof(struct ifstmt)))))
                                      ? ((__0__X194 = (struct ifstmt *)__ct__4stmtFUc3locP4stmt(
                                              ((struct stmt *)__0__X194), (unsigned char)20,
                                              __2__X195, __2__X197)),
                                         ((__0__X194->__O2__4stmt.e = __2__X196),
                                          (__0__X194->__O3__4stmt.else_stmt = __2__X198)))
                                      : 0),
                                 __0__X194))))));

    }

    break;
    case 246: {
        register struct ifstmt *__0__X199;

        struct loc __2__X200;

        struct expr *__2__X201;

        struct stmt *__2__X202;

        struct stmt *__2__X203;

        yyval.p__7YYSTYPE =
            (struct node *)((__0__X199 = 0),
                            ((__2__X200 = (yystack.l_mark__11YYSTACKDATA[-4]).l__7YYSTYPE),
                             ((__2__X201 = (yystack.l_mark__11YYSTACKDATA[-3]).pe__7YYSTYPE),
                              ((__2__X202 = (yystack.l_mark__11YYSTACKDATA[-2]).ps__7YYSTYPE),
                               ((__2__X203 = (yystack.l_mark__11YYSTACKDATA[0]).ps__7YYSTYPE),
                                (((__0__X199 || (__0__X199 = (struct ifstmt *)__nw__4stmtSFUl(
                                                     (size_t)(sizeof(struct ifstmt)))))
                                      ? ((__0__X199 = (struct ifstmt *)__ct__4stmtFUc3locP4stmt(
                                              ((struct stmt *)__0__X199), (unsigned char)20,
                                              __2__X200, __2__X202)),
                                         ((__0__X199->__O2__4stmt.e = __2__X201),
                                          (__0__X199->__O3__4stmt.else_stmt = __2__X203)))
                                      : 0),
                                 __0__X199))))));

    }

    break;
    case 247: {
        struct estmt *__0__X204;

        struct loc __2__X205;

        struct expr *__2__X206;

        struct stmt *__2__X207;

        yyval.p__7YYSTYPE =
            (struct node *)((__0__X204 = 0),
                            ((__2__X205 = (yystack.l_mark__11YYSTACKDATA[-2]).l__7YYSTYPE),
                             ((__2__X206 = (yystack.l_mark__11YYSTACKDATA[-1]).pe__7YYSTYPE),
                              ((__2__X207 = (yystack.l_mark__11YYSTACKDATA[0]).ps__7YYSTYPE),
                               (((__0__X204 || (__0__X204 = (struct estmt *)__nw__4stmtSFUl(
                                                    (unsigned long)(sizeof(struct estmt)))))
                                     ? ((__0__X204 = (struct estmt *)__ct__4stmtFUc3locP4stmt(
                                             ((struct stmt *)__0__X204), ((unsigned char)39),
                                             __2__X205, __2__X207)),
                                        (__0__X204->__O2__4stmt.e = __2__X206))
                                     : 0),
                                __0__X204)))));

    }

    break;
    case 248: {
        stmt_seen = 1;

    }

    break;
    case 249: {
        register struct forstmt *__0__X208;

        struct loc __2__X209;

        struct stmt *__2__X210;

        struct expr *__2__X211;

        struct expr *__2__X212;

        struct stmt *__2__X213;

        yyval.p__7YYSTYPE =
            (struct node *)((__0__X208 = 0),
                            ((__2__X209 = (yystack.l_mark__11YYSTACKDATA[-8]).l__7YYSTYPE),
                             ((__2__X210 = (yystack.l_mark__11YYSTACKDATA[-5]).ps__7YYSTYPE),
                              ((__2__X211 = (yystack.l_mark__11YYSTACKDATA[-4]).pe__7YYSTYPE),
                               ((__2__X212 = (yystack.l_mark__11YYSTACKDATA[-2]).pe__7YYSTYPE),
                                ((__2__X213 = (yystack.l_mark__11YYSTACKDATA[0]).ps__7YYSTYPE),
                                 (((__0__X208 || (__0__X208 = (struct forstmt *)__nw__4stmtSFUl(
                                                      (size_t)(sizeof(struct forstmt)))))
                                       ? ((__0__X208 = (struct forstmt *)__ct__4stmtFUc3locP4stmt(
                                               ((struct stmt *)__0__X208), (unsigned char)16,
                                               __2__X209, __2__X213)),
                                          ((__0__X208->__O3__4stmt.for_init = __2__X210),
                                           ((__0__X208->__O2__4stmt.e = __2__X211),
                                            (__0__X208->__O1__4stmt.e2 = __2__X212))))
                                       : 0),
                                  __0__X208)))))));

    }

    break;
    case 250: {
        (scd[(++scdp)]) = cd;

    }

    break;
    case 251: {
        struct estmt *__0__X214;

        struct loc __2__X215;

        struct expr *__2__X216;

        struct stmt *__2__X217;

        --scdp;
        yyval.p__7YYSTYPE =
            (struct node *)((__0__X214 = 0),
                            ((__2__X215 = (yystack.l_mark__11YYSTACKDATA[-3]).l__7YYSTYPE),
                             ((__2__X216 = (yystack.l_mark__11YYSTACKDATA[-1]).pe__7YYSTYPE),
                              ((__2__X217 = (yystack.l_mark__11YYSTACKDATA[0]).ps__7YYSTYPE),
                               (((__0__X214 || (__0__X214 = (struct estmt *)__nw__4stmtSFUl(
                                                    (unsigned long)(sizeof(struct estmt)))))
                                     ? ((__0__X214 = (struct estmt *)__ct__4stmtFUc3locP4stmt(
                                             ((struct stmt *)__0__X214), ((unsigned char)33),
                                             __2__X215, __2__X217)),
                                        (__0__X214->__O2__4stmt.e = __2__X216))
                                     : 0),
                                __0__X214)))));
    }

    break;
    case 252: {
        yyval.pn__7YYSTYPE = (yystack.l_mark__11YYSTACKDATA[-1]).pn__7YYSTYPE;

        stmt_seen = 1;

    }

    break;
    case 253: {
        Pname __3n;

        struct lstmt *__0__X218;

        struct loc __2__X219;

        struct stmt *__2__X220;

        __3n = (yystack.l_mark__11YYSTACKDATA[-1]).pn__7YYSTYPE;
        yyval.p__7YYSTYPE =
            (struct node *)((__0__X218 = 0),
                            ((__2__X219 = __3n->where__4name),
                             ((__2__X220 = (yystack.l_mark__11YYSTACKDATA[0]).ps__7YYSTYPE),
                              (((__0__X218 || (__0__X218 = (struct lstmt *)__nw__4stmtSFUl(
                                                   (size_t)(sizeof(struct lstmt)))))
                                    ? ((__0__X218 = (struct lstmt *)__ct__4stmtFUc3locP4stmt(
                                            ((struct stmt *)__0__X218), ((unsigned char)115),
                                            __2__X219, __2__X220)),
                                       (__0__X218->__O1__4stmt.d = __3n))
                                    : 0),
                               __0__X218))));
    }

    break;
    case 254: {
        yyval.pn__7YYSTYPE = __ct__4nameFPCc(
            (struct name *)0, (yystack.l_mark__11YYSTACKDATA[-1]).pn__7YYSTYPE->__O2__4expr.string);

        stmt_seen = 1;

    }

    break;
    case 255: {
        Pname __3n;

        struct lstmt *__0__X221;

        struct loc __2__X222;

        struct stmt *__2__X223;

        __3n = (yystack.l_mark__11YYSTACKDATA[-1]).pn__7YYSTYPE;
        yyval.p__7YYSTYPE =
            (struct node *)((__0__X221 = 0),
                            ((__2__X222 = __3n->where__4name),
                             ((__2__X223 = (yystack.l_mark__11YYSTACKDATA[0]).ps__7YYSTYPE),
                              (((__0__X221 || (__0__X221 = (struct lstmt *)__nw__4stmtSFUl(
                                                   (size_t)(sizeof(struct lstmt)))))
                                    ? ((__0__X221 = (struct lstmt *)__ct__4stmtFUc3locP4stmt(
                                            ((struct stmt *)__0__X221), ((unsigned char)115),
                                            __2__X222, __2__X223)),
                                       (__0__X221->__O1__4stmt.d = __3n))
                                    : 0),
                               __0__X221))));
    }

    break;
    case 256: {
        stmt_seen = 1;

    }

    break;
    case 257: {
        struct estmt *__0__X224;

        struct loc __2__X225;

        struct expr *__2__X226;

        struct stmt *__2__X227;

        if ((((scdp >= 0) && ((scd[scdp]) != cd)) && cd) && decl_with_init__FP5nlist(cd))
            error__FPCc((const char *)"jump past initializer (did you forget a '{ }'?)");
        if ((yystack.l_mark__11YYSTACKDATA[-2]).pe__7YYSTYPE == dummy)
            error__FPCc((const char *)"empty case label");
        yyval.p__7YYSTYPE =
            (struct node *)((__0__X224 = 0),
                            ((__2__X225 = (yystack.l_mark__11YYSTACKDATA[-4]).l__7YYSTYPE),
                             ((__2__X226 = (yystack.l_mark__11YYSTACKDATA[-2]).pe__7YYSTYPE),
                              ((__2__X227 = (yystack.l_mark__11YYSTACKDATA[0]).ps__7YYSTYPE),
                               (((__0__X224 || (__0__X224 = (struct estmt *)__nw__4stmtSFUl(
                                                    (unsigned long)(sizeof(struct estmt)))))
                                     ? ((__0__X224 = (struct estmt *)__ct__4stmtFUc3locP4stmt(
                                             ((struct stmt *)__0__X224), ((unsigned char)4),
                                             __2__X225, __2__X227)),
                                        (__0__X224->__O2__4stmt.e = __2__X226))
                                     : 0),
                                __0__X224)))));
    }

    break;
    case 258: {
        stmt_seen = 1;

    }

    break;
    case 259: {
        if (((((scdp >= 0) && ((scd[scdp]) != cd)) && cd) &&
             (yystack.l_mark__11YYSTACKDATA[-1]).pe__7YYSTYPE) &&
            decl_with_init__FP5nlist(cd))
            error__FPCc((const char *)"jump past initializer (did you forget a '{ }'?)");
        yyval.p__7YYSTYPE = (struct node *)__ct__4stmtFUc3locP4stmt(
            (struct stmt *)0, (unsigned char)8, (yystack.l_mark__11YYSTACKDATA[-3]).l__7YYSTYPE,
            (yystack.l_mark__11YYSTACKDATA[0]).ps__7YYSTYPE);
    }

    break;
    case 260: {
        register struct handler *__0__X228;

        struct stmt *__2__X229;

        struct stmt *__2__X230;

        yyval.p__7YYSTYPE =
            (struct node
                 *)((__0__X228 = 0),
                    ((__2__X229 = (yystack.l_mark__11YYSTACKDATA[-1]).ps__7YYSTYPE),
                     ((__2__X230 =
                           stmt_unlist__FP5slist((yystack.l_mark__11YYSTACKDATA[0]).sl__7YYSTYPE)),
                      (((__0__X228 || (__0__X228 = (struct handler *)__nw__4stmtSFUl(
                                           (size_t)(sizeof(struct handler)))))
                            ? (((void)((__0__X228 = (struct handler *)__ct__4stmtFUc3locP4stmt(
                                            ((struct stmt *)__0__X228), (unsigned char)100,
                                            __2__X229 ? __2__X229->where__4stmt : curloc,
                                            __2__X229)),
                                       ((__0__X228->__O1__4stmt.d = 0),
                                        ((__0__X228->s__4stmt->s_list__4stmt = __2__X230),
                                         (__0__X228->__O3__4stmt.where2 = curloc))))))
                            : (((void)0))),
                       __0__X228))));

    }

    break;
    case 261: {
        /* RANGE_FOR LP type arg_decl COLON e RP caselab_stmt */
        /* stack: [-7]=RANGE_FOR [-6]=LP [-5]=type [-4]=arg_decl [-3]=COLON [-2]=e [-1]=RP [0]=caselab_stmt */
        register struct rangeforstmt *__0__X261;

        struct loc __2__loc261;

        struct name *__2__var261;

        struct expr *__2__range261;

        struct stmt *__2__body261;

        stmt_seen = 1;

        yyval.p__7YYSTYPE =
            (struct node *)((__0__X261 = 0),
                            ((__2__loc261 = (yystack.l_mark__11YYSTACKDATA[-7]).l__7YYSTYPE),
                             ((__2__var261 = normalize__4nameFP8basetypeP5blockUc(
                                                (yystack.l_mark__11YYSTACKDATA[-4]).pn__7YYSTYPE,
                                                ((struct basetype *)((struct basetype *)(yystack.l_mark__11YYSTACKDATA[-5]).p__7YYSTYPE)),
                                                (struct block *)0, (unsigned char)0)),
                              ((__2__range261 = (yystack.l_mark__11YYSTACKDATA[-2]).pe__7YYSTYPE),
                               ((__2__body261 = (yystack.l_mark__11YYSTACKDATA[0]).ps__7YYSTYPE),
                                (((__0__X261 || (__0__X261 = (struct rangeforstmt *)__nw__4stmtSFUl(
                                                     (size_t)(sizeof(struct rangeforstmt)))))
                                      ? ((__0__X261 = (struct rangeforstmt *)__ct__4stmtFUc3locP4stmt(
                                              ((struct stmt *)__0__X261), (unsigned char)215,
                                              __2__loc261, __2__body261)),
                                         ((__0__X261->__O1__4stmt.d = __2__var261),
                                          (__0__X261->__O2__4stmt.e = __2__range261)))
                                      : 0),
                                 __0__X261))))));

    }

    break;
    case 262: {
        yyval.sl__7YYSTYPE = 0;

    }

    break;
    case 263: {
        register struct slist *__0__X231;

        struct stmt *__2__X232;

        if ((yystack.l_mark__11YYSTACKDATA[0]).ps__7YYSTYPE)
            if ((yystack.l_mark__11YYSTACKDATA[-1]).sl__7YYSTYPE)
                ((__0__X231 = (yystack.l_mark__11YYSTACKDATA[-1]).sl__7YYSTYPE),
                 ((__2__X232 = (yystack.l_mark__11YYSTACKDATA[0]).ps__7YYSTYPE),
                  (((__0__X231->tail__5slist->s_list__4stmt = __2__X232),
                    (__0__X231->tail__5slist = __2__X232)),
                   (((void)0)))));
            else {
                struct slist *__0__X233;

                struct stmt *__2__X234;

                yyval.sl__7YYSTYPE =
                    ((__0__X233 = 0),
                     ((__2__X234 = (yystack.l_mark__11YYSTACKDATA[0]).ps__7YYSTYPE),
                      (((__0__X233 ||
                         (__0__X233 = (struct slist *)__nw__FUl((size_t)(sizeof(struct slist)))))
                            ? ((__0__X233->head__5slist = (__0__X233->tail__5slist = __2__X234)), 0)
                            : 0),
                       __0__X233)));
                stmt_seen = 1;
            }
    }

    break;
    case 264: {
        if ((yystack.l_mark__11YYSTACKDATA[-1]).pn__7YYSTYPE) {
            (yystack.l_mark__11YYSTACKDATA[-1]).pn__7YYSTYPE->__O1__4name.n_list =
                (yystack.l_mark__11YYSTACKDATA[0]).ps__7YYSTYPE->__O1__4stmt.d;

            (yystack.l_mark__11YYSTACKDATA[0]).ps__7YYSTYPE->__O1__4stmt.d =
                (yystack.l_mark__11YYSTACKDATA[-1]).pn__7YYSTYPE;
        }
        yyval.ps__7YYSTYPE = (yystack.l_mark__11YYSTACKDATA[0]).ps__7YYSTYPE;
    }

    break;
    case 265: {
        in_arg_list = 0;
        yyval.pn__7YYSTYPE = normalize__4nameFP8basetypeP5blockUc(
            (yystack.l_mark__11YYSTACKDATA[-1]).pn__7YYSTYPE,
            ((struct basetype *)((
                (struct basetype *)(yystack.l_mark__11YYSTACKDATA[-2]).p__7YYSTYPE))),
            (struct block *)0, (unsigned char)0);
        if (yyval.pn__7YYSTYPE->__O2__4expr.string == 0)
            yyval.pn__7YYSTYPE = 0;
        else
            yyval.pn__7YYSTYPE->base__4node = 98;
    }

    break;
    case 266: {
        yyval.pn__7YYSTYPE = 0;

    }

    break;
    case 267: {
        Pexpr __3e;

        __3e = expr_unlist__FP5elist((yystack.l_mark__11YYSTACKDATA[0]).el__7YYSTYPE);
        while (__3e && (__3e->__O2__4expr.e1 == dummy)) {
            Pexpr __4ee2;

            __4ee2 = __3e->__O3__4expr.e2;
            if (__4ee2)
                error__FPCc((const char *)"EX inEL");
            ((__3e ? (((void)(__3e ? (((void)(((void)__dl__4exprSFPvUl(
                                         (void *)__3e, (size_t)(sizeof(struct expr)))))))
                                   : (((void)0)))))
                   : (((void)0))));
            __3e = __4ee2;
        }
        yyval.p__7YYSTYPE = (struct node *)__3e;
    }

    break;
    case 268: {
        struct elist *__0__X235;

        struct expr *__2__X236;

        yyval.el__7YYSTYPE =
            ((__0__X235 = 0),
             ((__2__X236 = __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)140,
                                                  (yystack.l_mark__11YYSTACKDATA[0]).pe__7YYSTYPE,
                                                  (struct expr *)0)),
              (((__0__X235 ||
                 (__0__X235 = (struct elist *)__nw__FUl((size_t)(sizeof(struct elist)))))
                    ? ((__0__X235->head__5elist = (__0__X235->tail__5elist = __2__X236)), 0)
                    : 0),
               __0__X235)));

    }

    break;
    case 269: {
        register struct elist *__0__X237;

        struct expr *__2__X238;

        ((__0__X237 = (yystack.l_mark__11YYSTACKDATA[-2]).el__7YYSTYPE),
         ((__2__X238 = __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)140,
                                              (yystack.l_mark__11YYSTACKDATA[0]).pe__7YYSTYPE,
                                              (struct expr *)0)),
          (((__0__X237->tail__5elist->__O3__4expr.e2 = __2__X238),
            (__0__X237->tail__5elist = __2__X238)),
           (((void)0)))));

    }

    break;
    case 271: {
        if (in_arg_list)
            error__FPCc((const char *)"syntax error: IrL not permitted in AL");
        else if (in_binit_list)
            error__FPCc((const char *)"syntax error: IrL not permitted inMIr");
        else
            init_seen = 1;
        {
            Pexpr __3e;
            if ((yystack.l_mark__11YYSTACKDATA[-1]).p__7YYSTYPE)
                __3e = (yystack.l_mark__11YYSTACKDATA[-1]).pe__7YYSTYPE;
            else
                __3e = __ct__4exprFUcP4exprT2((struct expr *)0, (unsigned char)140, dummy,
                                              (struct expr *)0);
            yyval.p__7YYSTYPE = (struct node *)__ct__4exprFUcP4exprT2(
                (struct expr *)0, (unsigned char)124, __3e, (struct expr *)0);
        }
    }

    break;
    case 272: {
    bbinop:
        yyval.p__7YYSTYPE = (struct node *)__ct__4exprFUcP4exprT2(
            (struct expr *)0, (yystack.l_mark__11YYSTACKDATA[-1]).t__7YYSTYPE,
            (yystack.l_mark__11YYSTACKDATA[-2]).pe__7YYSTYPE,
            (yystack.l_mark__11YYSTACKDATA[0]).pe__7YYSTYPE);

    }

    break;
    case 273: {
        goto bbinop;

    }

    break;
    case 274: {
        goto bbinop;

    }

    break;
    case 275: {
        goto bbinop;

    }

    break;
    case 276: {
        goto bbinop;

    }

    break;
    case 277: {
        goto bbinop;

    }

    break;
    case 278: {
        goto bbinop;

    }

    break;
    case 279: {
        goto bbinop;

    }

    break;
    case 280: {
        goto bbinop;

    }

    break;
    case 281: {
        goto bbinop;

    }

    break;
    case 282: {
        goto bbinop;

    }

    break;
    case 283: {
        goto bbinop;

    }

    break;
    case 284: {
        goto bbinop;

    }

    break;
    case 285: {
        goto bbinop;

    }

    break;
    case 286: {
        goto bbinop;

    }

    break;
    case 287: {
        goto bbinop;

    }

    break;
    case 288: {
        goto bbinop;

    }

    break;
    case 289: {
        struct qexpr *__0__X239;

        struct expr *__2__X240;

        struct expr *__2__X241;

        struct expr *__2__X242;

        yyval.p__7YYSTYPE =
            (struct node *)((__0__X239 = 0),
                            ((__2__X240 = (yystack.l_mark__11YYSTACKDATA[-4]).pe__7YYSTYPE),
                             ((__2__X241 = (yystack.l_mark__11YYSTACKDATA[-2]).pe__7YYSTYPE),
                              ((__2__X242 = (yystack.l_mark__11YYSTACKDATA[0]).pe__7YYSTYPE),
                               (((__0__X239 || (__0__X239 = (struct qexpr *)__nw__4exprSFUl(
                                                    (unsigned long)(sizeof(struct qexpr)))))
                                     ? ((__0__X239 = (struct qexpr *)__ct__4exprFUcP4exprT2(
                                             ((struct expr *)__0__X239), (unsigned char)68,
                                             __2__X241, __2__X242)),
                                        (__0__X239->__O4__4expr.cond = __2__X240))
                                     : 0),
                                __0__X239)))));

    }

    break;
    case 290: {
        yyval.p__7YYSTYPE = (struct node *)__ct__4exprFUcP4exprT2(
            (struct expr *)0, (yystack.l_mark__11YYSTACKDATA[-1]).t__7YYSTYPE,
            (yystack.l_mark__11YYSTACKDATA[-2]).pe__7YYSTYPE,
            (yystack.l_mark__11YYSTACKDATA[0]).pe__7YYSTYPE);

    }

    break;
    case 291: {
        yyval.p__7YYSTYPE = (struct node *)__ct__4exprFUcP4exprT2(
            (struct expr *)0, (unsigned char)9, (yystack.l_mark__11YYSTACKDATA[0]).pe__7YYSTYPE,
            (struct expr *)0);

    }

    break;
    case 292: {
        if ((yystack.l_mark__11YYSTACKDATA[-2]).pe__7YYSTYPE != dummy) {
            if (warning_opt || strict_opt)
                error__FiPCc(
                    strict_opt ? 0 : 119,
                    (const char
                         *)"v in `delete[v]' is redundant; use `delete[] instead (anachronism)");
        }
        yyval.p__7YYSTYPE = (struct node *)__ct__4exprFUcP4exprT2(
            (struct expr *)0, (unsigned char)9, (yystack.l_mark__11YYSTACKDATA[0]).pe__7YYSTYPE,
            (yystack.l_mark__11YYSTACKDATA[-2]).pe__7YYSTYPE);
    }

    break;
    case 293: {
        yyval.p__7YYSTYPE = (struct node *)__ct__4exprFUcP4exprT2(
            (struct expr *)0, (unsigned char)188, (yystack.l_mark__11YYSTACKDATA[0]).pe__7YYSTYPE,
            (struct expr *)0);

    }

    break;
    case 294: {
        if ((yystack.l_mark__11YYSTACKDATA[-2]).pe__7YYSTYPE != dummy) {
            if (warning_opt || strict_opt)
                error__FiPCc(strict_opt ? 0 : 119,
                             (const char *)"v in `::delete[v]' is redundant; use `::delete[] "
                                           "instead (anachronism)");
        }
        yyval.p__7YYSTYPE = (struct node *)__ct__4exprFUcP4exprT2(
            (struct expr *)0, (unsigned char)9, (yystack.l_mark__11YYSTACKDATA[0]).pe__7YYSTYPE,
            (yystack.l_mark__11YYSTACKDATA[-2]).pe__7YYSTYPE);
    }

    break;
    case 296: {
        yyval.p__7YYSTYPE = (struct node *)__ct__4exprFUcP4exprT2(
            (struct expr *)0, (unsigned char)99, (yystack.l_mark__11YYSTACKDATA[0]).pe__7YYSTYPE,
            (struct expr *)0);

    }

    break;
    case 297: {
    binop:
        yyval.p__7YYSTYPE = (struct node *)__ct__4exprFUcP4exprT2(
            (struct expr *)0, (yystack.l_mark__11YYSTACKDATA[-1]).t__7YYSTYPE,
            (yystack.l_mark__11YYSTACKDATA[-2]).pe__7YYSTYPE,
            (yystack.l_mark__11YYSTACKDATA[0]).pe__7YYSTYPE);

    }

    break;
    case 298: {
        goto binop;

    }

    break;
    case 299: {
        goto binop;

    }

    break;
    case 300: {
        goto binop;

    }

    break;
    case 301: {
        goto binop;

    }

    break;
    case 302: {
        goto binop;

    }

    break;
    case 303: {
        goto binop;

    }

    break;
    case 304: {
        goto binop;

    }

    break;
    case 305: {
        goto binop;

    }

    break;
    case 306: {
        goto binop;

    }

    break;
    case 307: {
        goto binop;

    }

    break;
    case 308: {
        goto binop;

    }

    break;
    case 309: {
        goto binop;

    }

    break;
    case 310: {
        goto binop;

    }

    break;
    case 311: {
        goto binop;

    }

    break;
    case 312: {
        goto binop;

    }

    break;
    case 313: {
        goto binop;

    }

    break;
    case 314: {
        struct qexpr *__0__X243;

        struct expr *__2__X244;

        struct expr *__2__X245;

        struct expr *__2__X246;

        yyval.p__7YYSTYPE =
            (struct node *)((__0__X243 = 0),
                            ((__2__X244 = (yystack.l_mark__11YYSTACKDATA[-4]).pe__7YYSTYPE),
                             ((__2__X245 = (yystack.l_mark__11YYSTACKDATA[-2]).pe__7YYSTYPE),
                              ((__2__X246 = (yystack.l_mark__11YYSTACKDATA[0]).pe__7YYSTYPE),
                               (((__0__X243 || (__0__X243 = (struct qexpr *)__nw__4exprSFUl(
                                                    (unsigned long)(sizeof(struct qexpr)))))
                                     ? ((__0__X243 = (struct qexpr *)__ct__4exprFUcP4exprT2(
                                             ((struct expr *)__0__X243), (unsigned char)68,
                                             __2__X245, __2__X246)),
                                        (__0__X243->__O4__4expr.cond = __2__X244))
                                     : 0),
                                __0__X243)))));

    }

    break;
    case 315: {
        yyval.p__7YYSTYPE = (struct node *)__ct__4exprFUcP4exprT2(
            (struct expr *)0, (yystack.l_mark__11YYSTACKDATA[-1]).t__7YYSTYPE,
            (yystack.l_mark__11YYSTACKDATA[-2]).pe__7YYSTYPE,
            (yystack.l_mark__11YYSTACKDATA[0]).pe__7YYSTYPE);

    }

    break;
    case 316: {
        yyval.p__7YYSTYPE = (struct node *)__ct__4exprFUcP4exprT2(
            (struct expr *)0, (unsigned char)9, (yystack.l_mark__11YYSTACKDATA[0]).pe__7YYSTYPE,
            (struct expr *)0);

    }

    break;
    case 317: {
        if ((yystack.l_mark__11YYSTACKDATA[-2]).pe__7YYSTYPE != dummy) {
            if (warning_opt || strict_opt)
                error__FiPCc(
                    strict_opt ? 0 : 119,
                    (const char
                         *)"v in `delete[v]' is redundant; use `delete[] instead (anachronism)");
        }
        yyval.p__7YYSTYPE = (struct node *)__ct__4exprFUcP4exprT2(
            (struct expr *)0, (unsigned char)9, (yystack.l_mark__11YYSTACKDATA[0]).pe__7YYSTYPE,
            (yystack.l_mark__11YYSTACKDATA[-2]).pe__7YYSTYPE);
    }

    break;
    case 318: {
        yyval.p__7YYSTYPE = (struct node *)__ct__4exprFUcP4exprT2(
            (struct expr *)0, (unsigned char)188, (yystack.l_mark__11YYSTACKDATA[0]).pe__7YYSTYPE,
            (struct expr *)0);

    }

    break;
    case 319: {
        if ((yystack.l_mark__11YYSTACKDATA[-2]).pe__7YYSTYPE != dummy) {
            if (warning_opt || strict_opt)
                error__FiPCc(strict_opt ? 0 : 119,
                             (const char *)"v in `::delete[v]' is redundant; use `::delete[] "
                                           "instead (anachronism)");
        }
        yyval.p__7YYSTYPE = (struct node *)__ct__4exprFUcP4exprT2(
            (struct expr *)0, (unsigned char)9, (yystack.l_mark__11YYSTACKDATA[0]).pe__7YYSTYPE,
            (yystack.l_mark__11YYSTACKDATA[-2]).pe__7YYSTYPE);
    }

    break;
    case 320: {
        init_seen = 0;
    }

    break;
    case 321: {
        yyval.p__7YYSTYPE = (struct node *)__ct__4exprFUcP4exprT2(
            (struct expr *)0, (unsigned char)99, (yystack.l_mark__11YYSTACKDATA[0]).pe__7YYSTYPE,
            (struct expr *)0);

    }

    break;
    case 322: {
        yyval.p__7YYSTYPE = (struct node *)dummy;

    }

    break;
    case 323: {
        goto new1;

    }

    break;
    case 324: {
    new1: {
        Ptype __3t;

        struct texpr *__0__X247;

        __3t = (yystack.l_mark__11YYSTACKDATA[0]).pn__7YYSTYPE->__O1__4expr.tp;
        yyval.p__7YYSTYPE =
            (struct node *)((__0__X247 = 0),
                            (((__0__X247 || (__0__X247 = (struct texpr *)__nw__4exprSFUl(
                                                 (size_t)(sizeof(struct texpr)))))
                                  ? ((__0__X247 = (struct texpr *)__ct__4exprFUcP4exprT2(
                                          ((struct expr *)__0__X247), ((unsigned char)23),
                                          ((struct expr *)0), (struct expr *)0)),
                                     (__0__X247->__O4__4expr.tp2 = __3t))
                                  : 0),
                             __0__X247));
        --in_new;
    }
    }

    break;
    case 325: {
        goto new3;

    }

    break;
    case 326: {
    new3: {
        Ptype __3t;

        struct texpr *__0__X248;

        __3t = (yystack.l_mark__11YYSTACKDATA[0]).pn__7YYSTYPE->__O1__4expr.tp;
        yyval.p__7YYSTYPE =
            (struct node *)((__0__X248 = 0),
                            (((__0__X248 || (__0__X248 = (struct texpr *)__nw__4exprSFUl(
                                                 (size_t)(sizeof(struct texpr)))))
                                  ? ((__0__X248 = (struct texpr *)__ct__4exprFUcP4exprT2(
                                          ((struct expr *)__0__X248), ((unsigned char)184),
                                          ((struct expr *)0), (struct expr *)0)),
                                     (__0__X248->__O4__4expr.tp2 = __3t))
                                  : 0),
                             __0__X248));
        --in_new;
    }
    }

    break;
    case 327: {
        yyval.p__7YYSTYPE = (struct node *)__ct__4exprFUcP4exprT2(
            (struct expr *)0, (yystack.l_mark__11YYSTACKDATA[0]).t__7YYSTYPE,
            (yystack.l_mark__11YYSTACKDATA[-1]).pe__7YYSTYPE, (struct expr *)0);

    }

    break;
    case 328: {
        struct texpr *__0__X249;

        struct type *__2__X250;

        struct expr *__2__X251;

        yyval.p__7YYSTYPE =
            (struct node *)((__0__X249 = 0),
                            ((__2__X250 =
                                  (yystack.l_mark__11YYSTACKDATA[-1]).pn__7YYSTYPE->__O1__4expr.tp),
                             ((__2__X251 = (yystack.l_mark__11YYSTACKDATA[0]).pe__7YYSTYPE),
                              (((__0__X249 || (__0__X249 = (struct texpr *)__nw__4exprSFUl(
                                                   (size_t)(sizeof(struct texpr)))))
                                    ? ((__0__X249 = (struct texpr *)__ct__4exprFUcP4exprT2(
                                            ((struct expr *)__0__X249), ((unsigned char)113),
                                            __2__X251, (struct expr *)0)),
                                       (__0__X249->__O4__4expr.tp2 = __2__X250))
                                    : 0),
                               __0__X249))));
    }

    break;
    case 329: {
        yyval.p__7YYSTYPE = (struct node *)__ct__4exprFUcP4exprT2(
            (struct expr *)0, (unsigned char)111, (yystack.l_mark__11YYSTACKDATA[0]).pe__7YYSTYPE,
            (struct expr *)0);

    }

    break;
    case 330: {
        yyval.p__7YYSTYPE = (struct node *)__ct__4exprFUcP4exprT2(
            (struct expr *)0, (unsigned char)112, (struct expr *)0,
            (yystack.l_mark__11YYSTACKDATA[0]).pe__7YYSTYPE);

    }

    break;
    case 331: {
        yyval.p__7YYSTYPE = (struct node *)__ct__4exprFUcP4exprT2(
            (struct expr *)0, (unsigned char)107, (struct expr *)0,
            (yystack.l_mark__11YYSTACKDATA[0]).pe__7YYSTYPE);

    }

    break;
    case 332: {
        yyval.p__7YYSTYPE = (struct node *)__ct__4exprFUcP4exprT2(
            (struct expr *)0, (unsigned char)172, (struct expr *)0,
            (yystack.l_mark__11YYSTACKDATA[0]).pe__7YYSTYPE);

    }

    break;
    case 333: {
        yyval.p__7YYSTYPE = (struct node *)__ct__4exprFUcP4exprT2(
            (struct expr *)0, (unsigned char)46, (struct expr *)0,
            (yystack.l_mark__11YYSTACKDATA[0]).pe__7YYSTYPE);

    }

    break;
    case 334: {
        yyval.p__7YYSTYPE = (struct node *)__ct__4exprFUcP4exprT2(
            (struct expr *)0, (unsigned char)47, (struct expr *)0,
            (yystack.l_mark__11YYSTACKDATA[0]).pe__7YYSTYPE);

    }

    break;
    case 335: {
        yyval.p__7YYSTYPE = (struct node *)__ct__4exprFUcP4exprT2(
            (struct expr *)0, (yystack.l_mark__11YYSTACKDATA[-1]).t__7YYSTYPE, (struct expr *)0,
            (yystack.l_mark__11YYSTACKDATA[0]).pe__7YYSTYPE);

    }

    break;
    case 336: {
        struct texpr *__0__X252;

        struct expr *__2__X253;

        yyval.p__7YYSTYPE =
            (struct node *)((__0__X252 = 0),
                            ((__2__X253 = (yystack.l_mark__11YYSTACKDATA[0]).pe__7YYSTYPE),
                             (((__0__X252 || (__0__X252 = (struct texpr *)__nw__4exprSFUl(
                                                  (size_t)(sizeof(struct texpr)))))
                                   ? ((__0__X252 = (struct texpr *)__ct__4exprFUcP4exprT2(
                                           ((struct expr *)__0__X252), ((unsigned char)30),
                                           __2__X253, (struct expr *)0)),
                                      (__0__X252->__O4__4expr.tp2 = ((struct type *)0)))
                                   : 0),
                              __0__X252)));

        --in_sizeof;
    }

    break;
    case 337: {
        struct texpr *__0__X254;

        struct type *__2__X255;

        yyval.p__7YYSTYPE =
            (struct node *)((__0__X254 = 0),
                            ((__2__X255 =
                                  (yystack.l_mark__11YYSTACKDATA[0]).pn__7YYSTYPE->__O1__4expr.tp),
                             (((__0__X254 || (__0__X254 = (struct texpr *)__nw__4exprSFUl(
                                                  (size_t)(sizeof(struct texpr)))))
                                   ? ((__0__X254 = (struct texpr *)__ct__4exprFUcP4exprT2(
                                           ((struct expr *)__0__X254), ((unsigned char)30),
                                           ((struct expr *)0), (struct expr *)0)),
                                      (__0__X254->__O4__4expr.tp2 = __2__X255))
                                   : 0),
                              __0__X254)));
        --in_sizeof;
    }

    break;
    case 338: {
        yyval.p__7YYSTYPE = (struct node *)__ct__4exprFUcP4exprT2(
            (struct expr *)0, (unsigned char)111, (yystack.l_mark__11YYSTACKDATA[-3]).pe__7YYSTYPE,
            (yystack.l_mark__11YYSTACKDATA[-1]).pe__7YYSTYPE);

    }

    break;
    case 339: {
        struct ref *__0__X256;

        struct expr *__2__X257;

        struct expr *__2__X258;

        yyval.p__7YYSTYPE =
            (struct node *)((__0__X256 = 0),
                            ((__2__X257 = (yystack.l_mark__11YYSTACKDATA[-2]).pe__7YYSTYPE),
                             ((__2__X258 =
                                   (struct expr *)(yystack.l_mark__11YYSTACKDATA[0]).pn__7YYSTYPE),
                              (((__0__X256 || (__0__X256 = (struct ref *)__nw__4exprSFUl(
                                                   (size_t)(sizeof(struct ref)))))
                                    ? ((__0__X256 = (struct ref *)__ct__4exprFUcP4exprT2(
                                            ((struct expr *)__0__X256), ((unsigned char)44),
                                            __2__X257, (struct expr *)0)),
                                       (__0__X256->__O4__4expr.mem = __2__X258))
                                    : 0),
                               __0__X256))));

    }

    break;
    case 340: {
        struct ref *__0__X259;

        struct expr *__2__X260;

        struct expr *__2__X261;

        (yystack.l_mark__11YYSTACKDATA[0]).pn__7YYSTYPE->__O2__4name.n_qualifier =
            (yystack.l_mark__11YYSTACKDATA[-1]).pn__7YYSTYPE;
        yyval.p__7YYSTYPE =
            (struct node *)((__0__X259 = 0),
                            ((__2__X260 = (yystack.l_mark__11YYSTACKDATA[-3]).pe__7YYSTYPE),
                             ((__2__X261 =
                                   (struct expr *)(yystack.l_mark__11YYSTACKDATA[0]).pn__7YYSTYPE),
                              (((__0__X259 || (__0__X259 = (struct ref *)__nw__4exprSFUl(
                                                   (size_t)(sizeof(struct ref)))))
                                    ? ((__0__X259 = (struct ref *)__ct__4exprFUcP4exprT2(
                                            ((struct expr *)__0__X259), ((unsigned char)44),
                                            __2__X260, (struct expr *)0)),
                                       (__0__X259->__O4__4expr.mem = __2__X261))
                                    : 0),
                               __0__X259))));
    }

    break;
    case 341: {
        struct ref *__0__X262;

        struct expr *__2__X263;

        struct expr *__2__X264;

        (yystack.l_mark__11YYSTACKDATA[0]).pn__7YYSTYPE = __ct__4nameFPCc(
            (struct name *)0, (yystack.l_mark__11YYSTACKDATA[0]).pn__7YYSTYPE->__O2__4expr.string);
        (yystack.l_mark__11YYSTACKDATA[0]).pn__7YYSTYPE->__O2__4name.n_qualifier =
            (yystack.l_mark__11YYSTACKDATA[-1]).pn__7YYSTYPE;
        yyval.p__7YYSTYPE =
            (struct node *)((__0__X262 = 0),
                            ((__2__X263 = (yystack.l_mark__11YYSTACKDATA[-3]).pe__7YYSTYPE),
                             ((__2__X264 =
                                   (struct expr *)(yystack.l_mark__11YYSTACKDATA[0]).pn__7YYSTYPE),
                              (((__0__X262 || (__0__X262 = (struct ref *)__nw__4exprSFUl(
                                                   (size_t)(sizeof(struct ref)))))
                                    ? ((__0__X262 = (struct ref *)__ct__4exprFUcP4exprT2(
                                            ((struct expr *)__0__X262), ((unsigned char)44),
                                            __2__X263, (struct expr *)0)),
                                       (__0__X262->__O4__4expr.mem = __2__X264))
                                    : 0),
                               __0__X262))));
    }

    break;
    case 342: {
        struct ref *__0__X265;

        struct expr *__2__X266;

        struct expr *__2__X267;

        yyval.p__7YYSTYPE =
            (struct node *)((__0__X265 = 0),
                            ((__2__X266 = (yystack.l_mark__11YYSTACKDATA[-2]).pe__7YYSTYPE),
                             ((__2__X267 =
                                   (struct expr *)(yystack.l_mark__11YYSTACKDATA[0]).pn__7YYSTYPE),
                              (((__0__X265 || (__0__X265 = (struct ref *)__nw__4exprSFUl(
                                                   (size_t)(sizeof(struct ref)))))
                                    ? ((__0__X265 = (struct ref *)__ct__4exprFUcP4exprT2(
                                            ((struct expr *)__0__X265), ((unsigned char)44),
                                            __2__X266, (struct expr *)0)),
                                       (__0__X265->__O4__4expr.mem = __2__X267))
                                    : 0),
                               __0__X265))));

    }

    break;
    case 343: {
        struct ref *__0__X268;

        struct expr *__2__X269;

        struct expr *__2__X270;

        (yystack.l_mark__11YYSTACKDATA[0]).pn__7YYSTYPE->__O2__4name.n_qualifier =
            (yystack.l_mark__11YYSTACKDATA[-1]).pn__7YYSTYPE;
        yyval.p__7YYSTYPE =
            (struct node *)((__0__X268 = 0),
                            ((__2__X269 = (yystack.l_mark__11YYSTACKDATA[-3]).pe__7YYSTYPE),
                             ((__2__X270 =
                                   (struct expr *)(yystack.l_mark__11YYSTACKDATA[0]).pn__7YYSTYPE),
                              (((__0__X268 || (__0__X268 = (struct ref *)__nw__4exprSFUl(
                                                   (size_t)(sizeof(struct ref)))))
                                    ? ((__0__X268 = (struct ref *)__ct__4exprFUcP4exprT2(
                                            ((struct expr *)__0__X268), ((unsigned char)44),
                                            __2__X269, (struct expr *)0)),
                                       (__0__X268->__O4__4expr.mem = __2__X270))
                                    : 0),
                               __0__X268))));
        if ((yystack.l_mark__11YYSTACKDATA[-1]).pn__7YYSTYPE &&
            ((yystack.l_mark__11YYSTACKDATA[-1]).pn__7YYSTYPE->n_template_arg__4name != 1))
            UNSET_SCOPE__Fv();
    }

    break;
    case 344: {
        struct ref *__0__X271;

        struct expr *__2__X272;

        struct expr *__2__X273;

        (yystack.l_mark__11YYSTACKDATA[0]).pn__7YYSTYPE = __ct__4nameFPCc(
            (struct name *)0, (yystack.l_mark__11YYSTACKDATA[0]).pn__7YYSTYPE->__O2__4expr.string);
        (yystack.l_mark__11YYSTACKDATA[0]).pn__7YYSTYPE->__O2__4name.n_qualifier =
            (yystack.l_mark__11YYSTACKDATA[-1]).pn__7YYSTYPE;
        yyval.p__7YYSTYPE =
            (struct node *)((__0__X271 = 0),
                            ((__2__X272 = (yystack.l_mark__11YYSTACKDATA[-3]).pe__7YYSTYPE),
                             ((__2__X273 =
                                   (struct expr *)(yystack.l_mark__11YYSTACKDATA[0]).pn__7YYSTYPE),
                              (((__0__X271 || (__0__X271 = (struct ref *)__nw__4exprSFUl(
                                                   (size_t)(sizeof(struct ref)))))
                                    ? ((__0__X271 = (struct ref *)__ct__4exprFUcP4exprT2(
                                            ((struct expr *)__0__X271), ((unsigned char)44),
                                            __2__X272, (struct expr *)0)),
                                       (__0__X271->__O4__4expr.mem = __2__X273))
                                    : 0),
                               __0__X271))));
        if ((yystack.l_mark__11YYSTACKDATA[-1]).pn__7YYSTYPE &&
            ((yystack.l_mark__11YYSTACKDATA[-1]).pn__7YYSTYPE->n_template_arg__4name != 1))
            UNSET_SCOPE__Fv();
    }

    break;
    case 345: {
        struct ref *__0__X274;

        struct expr *__2__X275;

        struct expr *__2__X276;

        yyval.p__7YYSTYPE =
            (struct node *)((__0__X274 = 0),
                            ((__2__X275 = (yystack.l_mark__11YYSTACKDATA[-2]).pe__7YYSTYPE),
                             ((__2__X276 =
                                   (struct expr *)(yystack.l_mark__11YYSTACKDATA[0]).pn__7YYSTYPE),
                              (((__0__X274 || (__0__X274 = (struct ref *)__nw__4exprSFUl(
                                                   (size_t)(sizeof(struct ref)))))
                                    ? ((__0__X274 = (struct ref *)__ct__4exprFUcP4exprT2(
                                            ((struct expr *)__0__X274), ((unsigned char)45),
                                            __2__X275, (struct expr *)0)),
                                       (__0__X274->__O4__4expr.mem = __2__X276))
                                    : 0),
                               __0__X274))));

    }

    break;
    case 346: {
        struct ref *__0__X277;

        struct expr *__2__X278;

        struct expr *__2__X279;

        (yystack.l_mark__11YYSTACKDATA[0]).pn__7YYSTYPE->__O2__4name.n_qualifier =
            (yystack.l_mark__11YYSTACKDATA[-1]).pn__7YYSTYPE;
        yyval.p__7YYSTYPE =
            (struct node *)((__0__X277 = 0),
                            ((__2__X278 = (yystack.l_mark__11YYSTACKDATA[-3]).pe__7YYSTYPE),
                             ((__2__X279 =
                                   (struct expr *)(yystack.l_mark__11YYSTACKDATA[0]).pn__7YYSTYPE),
                              (((__0__X277 || (__0__X277 = (struct ref *)__nw__4exprSFUl(
                                                   (size_t)(sizeof(struct ref)))))
                                    ? ((__0__X277 = (struct ref *)__ct__4exprFUcP4exprT2(
                                            ((struct expr *)__0__X277), ((unsigned char)45),
                                            __2__X278, (struct expr *)0)),
                                       (__0__X277->__O4__4expr.mem = __2__X279))
                                    : 0),
                               __0__X277))));
    }

    break;
    case 347: {
        struct ref *__0__X280;

        struct expr *__2__X281;

        struct expr *__2__X282;

        (yystack.l_mark__11YYSTACKDATA[0]).pn__7YYSTYPE = __ct__4nameFPCc(
            (struct name *)0, (yystack.l_mark__11YYSTACKDATA[0]).pn__7YYSTYPE->__O2__4expr.string);
        (yystack.l_mark__11YYSTACKDATA[0]).pn__7YYSTYPE->__O2__4name.n_qualifier =
            (yystack.l_mark__11YYSTACKDATA[-1]).pn__7YYSTYPE;
        yyval.p__7YYSTYPE =
            (struct node *)((__0__X280 = 0),
                            ((__2__X281 = (yystack.l_mark__11YYSTACKDATA[-3]).pe__7YYSTYPE),
                             ((__2__X282 =
                                   (struct expr *)(yystack.l_mark__11YYSTACKDATA[0]).pn__7YYSTYPE),
                              (((__0__X280 || (__0__X280 = (struct ref *)__nw__4exprSFUl(
                                                   (size_t)(sizeof(struct ref)))))
                                    ? ((__0__X280 = (struct ref *)__ct__4exprFUcP4exprT2(
                                            ((struct expr *)__0__X280), ((unsigned char)45),
                                            __2__X281, (struct expr *)0)),
                                       (__0__X280->__O4__4expr.mem = __2__X282))
                                    : 0),
                               __0__X280))));
    }

    break;
    case 348: {
        struct ref *__0__X283;

        struct expr *__2__X284;

        struct expr *__2__X285;

        yyval.p__7YYSTYPE =
            (struct node *)((__0__X283 = 0),
                            ((__2__X284 = (yystack.l_mark__11YYSTACKDATA[-2]).pe__7YYSTYPE),
                             ((__2__X285 =
                                   (struct expr *)(yystack.l_mark__11YYSTACKDATA[0]).pn__7YYSTYPE),
                              (((__0__X283 || (__0__X283 = (struct ref *)__nw__4exprSFUl(
                                                   (size_t)(sizeof(struct ref)))))
                                    ? ((__0__X283 = (struct ref *)__ct__4exprFUcP4exprT2(
                                            ((struct expr *)__0__X283), ((unsigned char)45),
                                            __2__X284, (struct expr *)0)),
                                       (__0__X283->__O4__4expr.mem = __2__X285))
                                    : 0),
                               __0__X283))));

    }

    break;
    case 349: {
        struct ref *__0__X286;

        struct expr *__2__X287;

        struct expr *__2__X288;

        (yystack.l_mark__11YYSTACKDATA[0]).pn__7YYSTYPE->__O2__4name.n_qualifier =
            (yystack.l_mark__11YYSTACKDATA[-1]).pn__7YYSTYPE;
        yyval.p__7YYSTYPE =
            (struct node *)((__0__X286 = 0),
                            ((__2__X287 = (yystack.l_mark__11YYSTACKDATA[-3]).pe__7YYSTYPE),
                             ((__2__X288 =
                                   (struct expr *)(yystack.l_mark__11YYSTACKDATA[0]).pn__7YYSTYPE),
                              (((__0__X286 || (__0__X286 = (struct ref *)__nw__4exprSFUl(
                                                   (size_t)(sizeof(struct ref)))))
                                    ? ((__0__X286 = (struct ref *)__ct__4exprFUcP4exprT2(
                                            ((struct expr *)__0__X286), ((unsigned char)45),
                                            __2__X287, (struct expr *)0)),
                                       (__0__X286->__O4__4expr.mem = __2__X288))
                                    : 0),
                               __0__X286))));
        if ((yystack.l_mark__11YYSTACKDATA[-1]).pn__7YYSTYPE &&
            ((yystack.l_mark__11YYSTACKDATA[-1]).pn__7YYSTYPE->n_template_arg__4name != 1))
            UNSET_SCOPE__Fv();
    }

    break;
    case 350: {
        struct ref *__0__X289;

        struct expr *__2__X290;

        struct expr *__2__X291;

        (yystack.l_mark__11YYSTACKDATA[0]).pn__7YYSTYPE = __ct__4nameFPCc(
            (struct name *)0, (yystack.l_mark__11YYSTACKDATA[0]).pn__7YYSTYPE->__O2__4expr.string);
        (yystack.l_mark__11YYSTACKDATA[0]).pn__7YYSTYPE->__O2__4name.n_qualifier =
            (yystack.l_mark__11YYSTACKDATA[-1]).pn__7YYSTYPE;
        yyval.p__7YYSTYPE =
            (struct node *)((__0__X289 = 0),
                            ((__2__X290 = (yystack.l_mark__11YYSTACKDATA[-3]).pe__7YYSTYPE),
                             ((__2__X291 =
                                   (struct expr *)(yystack.l_mark__11YYSTACKDATA[0]).pn__7YYSTYPE),
                              (((__0__X289 || (__0__X289 = (struct ref *)__nw__4exprSFUl(
                                                   (size_t)(sizeof(struct ref)))))
                                    ? ((__0__X289 = (struct ref *)__ct__4exprFUcP4exprT2(
                                            ((struct expr *)__0__X289), ((unsigned char)45),
                                            __2__X290, (struct expr *)0)),
                                       (__0__X289->__O4__4expr.mem = __2__X291))
                                    : 0),
                               __0__X289))));
        if ((yystack.l_mark__11YYSTACKDATA[-1]).pn__7YYSTYPE &&
            ((yystack.l_mark__11YYSTACKDATA[-1]).pn__7YYSTYPE->n_template_arg__4name != 1))
            UNSET_SCOPE__Fv();
    }

    break;
    case 352: {
        struct name *__1__X292;

        struct name *__1__Xnn00qycjpkkfwcaj;

        yyval.p__7YYSTYPE =
            (struct node *)((__1__X292 = (yystack.l_mark__11YYSTACKDATA[0]).pn__7YYSTYPE),
                            (((__1__X292->base__4node != 123)
                                  ? ((__1__Xnn00qycjpkkfwcaj = __1__X292), 0)
                                  : ((__1__Xnn00qycjpkkfwcaj = __ct__4nameFPCc(
                                          (struct name *)0, __1__X292->__O2__4expr.string)),
                                     (__1__Xnn00qycjpkkfwcaj->n_template_arg__4name =
                                          __1__X292->n_template_arg__4name))),
                             __1__Xnn00qycjpkkfwcaj));
        yyval.pn__7YYSTYPE->__O2__4name.n_qualifier =
            (yystack.l_mark__11YYSTACKDATA[-1]).pn__7YYSTYPE;
        if ((yystack.l_mark__11YYSTACKDATA[-1]).pn__7YYSTYPE &&
            ((yystack.l_mark__11YYSTACKDATA[-1]).pn__7YYSTYPE->n_template_arg__4name != 1))
            UNSET_SCOPE__Fv();
    }

    break;
    case 353: {
        yyval.p__7YYSTYPE = (struct node *)dummy_dtor__Fv();
        yyval.pn__7YYSTYPE->__O2__4name.n_qualifier =
            (yystack.l_mark__11YYSTACKDATA[-2]).pn__7YYSTYPE;
        yyval.pn__7YYSTYPE->__O1__4name.n_dtag = (yystack.l_mark__11YYSTACKDATA[0]).pn__7YYSTYPE;
    }

    break;
    case 354: {
        yyval.p__7YYSTYPE =
            (struct node *)dummy_dtor__FUcT1((yystack.l_mark__11YYSTACKDATA[0]).t__7YYSTYPE,
                                             (yystack.l_mark__11YYSTACKDATA[0]).t__7YYSTYPE);
        yyval.pn__7YYSTYPE->__O2__4name.n_qualifier =
            (yystack.l_mark__11YYSTACKDATA[-2]).pn__7YYSTYPE;
    }

    break;
    case 355: {
        if (init_seen)
            error__FPCc((const char *)"syntax error:IrL illegal within ()");
    }

    break;
    case 356: {
        if ((yystack.l_mark__11YYSTACKDATA[-1]).p__7YYSTYPE == (((struct node *)dummy)))
            error__FPCc((const char *)"syntax error: nullE");
        yyval.p__7YYSTYPE = (yystack.l_mark__11YYSTACKDATA[-1]).p__7YYSTYPE;
    }

    break;
    case 357: {
        yyval.p__7YYSTYPE = (struct node *)zero;

    }

    break;
    case 358: {
        yyval.p__7YYSTYPE = (struct node *)__ct__4exprFUcP4exprT2(
            (struct expr *)0, (unsigned char)82, (struct expr *)0, (struct expr *)0);
        yyval.pe__7YYSTYPE->__O2__4expr.string =
            ((in_progress__17templ_compilation || parameters_in_progress__17templ_compilation)
                 ? (((const char *)strdup((yystack.l_mark__11YYSTACKDATA[0]).s__7YYSTYPE)))
                 : (yystack.l_mark__11YYSTACKDATA[0]).s__7YYSTYPE);
    }

    break;
    case 359: {
        yyval.p__7YYSTYPE = (struct node *)__ct__4exprFUcP4exprT2(
            (struct expr *)0, (unsigned char)83, (struct expr *)0, (struct expr *)0);
        yyval.pe__7YYSTYPE->__O2__4expr.string =
            ((in_progress__17templ_compilation || parameters_in_progress__17templ_compilation)
                 ? (((const char *)strdup((yystack.l_mark__11YYSTACKDATA[0]).s__7YYSTYPE)))
                 : (yystack.l_mark__11YYSTACKDATA[0]).s__7YYSTYPE);
    }

    break;
    case 360: {
        yyval.p__7YYSTYPE = (struct node *)__ct__4exprFUcP4exprT2(
            (struct expr *)0, (unsigned char)81, (struct expr *)0, (struct expr *)0);
        yyval.pe__7YYSTYPE->__O2__4expr.string =
            ((in_progress__17templ_compilation || parameters_in_progress__17templ_compilation)
                 ? (((const char *)strdup((yystack.l_mark__11YYSTACKDATA[0]).s__7YYSTYPE)))
                 : (yystack.l_mark__11YYSTACKDATA[0]).s__7YYSTYPE);
    }

    break;
    case 361: {
        yyval.p__7YYSTYPE = (struct node *)__ct__4exprFUcP4exprT2(
            (struct expr *)0, (unsigned char)84, (struct expr *)0, (struct expr *)0);
        yyval.pe__7YYSTYPE->__O2__4expr.string =
            ((in_progress__17templ_compilation || parameters_in_progress__17templ_compilation)
                 ? (((const char *)strdup((yystack.l_mark__11YYSTACKDATA[0]).s__7YYSTYPE)))
                 : (yystack.l_mark__11YYSTACKDATA[0]).s__7YYSTYPE);
    }

    break;
    case 362: {
        yyval.p__7YYSTYPE = (struct node *)__ct__4exprFUcP4exprT2(
            (struct expr *)0, (unsigned char)34, (struct expr *)0, (struct expr *)0);

    }

    break;
    case 363: {
        yyval.p__7YYSTYPE = (struct node *)dummy_dtor__Fv();
        yyval.pn__7YYSTYPE->__O1__4name.n_dtag = (yystack.l_mark__11YYSTACKDATA[0]).pn__7YYSTYPE;
    }

    break;
    case 364: {
        yyval.p__7YYSTYPE = (struct node *)dummy_dtor__Fv();
        yyval.pn__7YYSTYPE->__O2__4name.n_qualifier =
            (yystack.l_mark__11YYSTACKDATA[-2]).pn__7YYSTYPE;
        yyval.pn__7YYSTYPE->__O1__4name.n_dtag = (yystack.l_mark__11YYSTACKDATA[0]).pn__7YYSTYPE;
    }

    break;
    case 365: {
        yyval.p__7YYSTYPE =
            (struct node *)dummy_dtor__FUcT1((yystack.l_mark__11YYSTACKDATA[-3]).t__7YYSTYPE,
                                             (yystack.l_mark__11YYSTACKDATA[0]).t__7YYSTYPE);

    }

    break;
    case 366: {
        yyval.p__7YYSTYPE =
            (struct node *)dummy_dtor__FUcT1((yystack.l_mark__11YYSTACKDATA[0]).t__7YYSTYPE,
                                             (yystack.l_mark__11YYSTACKDATA[0]).t__7YYSTYPE);

    }

    break;
    case 367: {
        yyval.p__7YYSTYPE =
            (struct node *)dummy_dtor__FUcT1((yystack.l_mark__11YYSTACKDATA[-3]).t__7YYSTYPE,
                                             (yystack.l_mark__11YYSTACKDATA[-3]).t__7YYSTYPE);
        yyval.pn__7YYSTYPE->__O1__4name.n_dtag = (yystack.l_mark__11YYSTACKDATA[0]).pn__7YYSTYPE;
    }

    break;
    case 368: {
        yyval.p__7YYSTYPE =
            (struct node *)dummy_dtor__FUcT1((yystack.l_mark__11YYSTACKDATA[0]).t__7YYSTYPE,
                                             (yystack.l_mark__11YYSTACKDATA[0]).t__7YYSTYPE);
        yyval.pn__7YYSTYPE->__O2__4name.n_qualifier =
            (yystack.l_mark__11YYSTACKDATA[-2]).pn__7YYSTYPE;
    }

    break;
    case 369: {
        yyval.p__7YYSTYPE = (struct node *)dummy_dtor__Fv();
        yyval.pn__7YYSTYPE->__O2__4name.n_qualifier =
            (yystack.l_mark__11YYSTACKDATA[-2]).pn__7YYSTYPE;
        yyval.pn__7YYSTYPE->__O1__4name.n_dtag = (yystack.l_mark__11YYSTACKDATA[0]).pn__7YYSTYPE;
    }

    break;
    case 370: {
        yyval.p__7YYSTYPE =
            (struct node *)dummy_dtor__FUcT1((yystack.l_mark__11YYSTACKDATA[0]).t__7YYSTYPE,
                                             (yystack.l_mark__11YYSTACKDATA[0]).t__7YYSTYPE);
        yyval.pn__7YYSTYPE->__O2__4name.n_qualifier =
            (yystack.l_mark__11YYSTACKDATA[-2]).pn__7YYSTYPE;
    }

    break;
    case 371: {
        struct texpr *__0__X293;

        struct type *__2__X294;

        struct expr *__2__X295;

        yyval.p__7YYSTYPE =
            (struct node *)((__0__X293 = 0),
                            ((__2__X294 = tok_to_type__FUc(
                                  (yystack.l_mark__11YYSTACKDATA[-3]).t__7YYSTYPE)),
                             ((__2__X295 = (yystack.l_mark__11YYSTACKDATA[-1]).pe__7YYSTYPE),
                              (((__0__X293 || (__0__X293 = (struct texpr *)__nw__4exprSFUl(
                                                   (size_t)(sizeof(struct texpr)))))
                                    ? ((__0__X293 = (struct texpr *)__ct__4exprFUcP4exprT2(
                                            ((struct expr *)__0__X293), ((unsigned char)157),
                                            __2__X295, (struct expr *)0)),
                                       (__0__X293->__O4__4expr.tp2 = __2__X294))
                                    : 0),
                               __0__X293))));

    }

    break;
    case 372: {
        struct texpr *__0__X296;

        struct type *__2__X297;

        struct expr *__2__X298;

        struct name *__0__X299;

        yyval.p__7YYSTYPE =
            (struct node *)((__0__X296 = 0),
                            ((__2__X297 =
                                  (yystack.l_mark__11YYSTACKDATA[-3]).pn__7YYSTYPE->__O1__4expr.tp),
                             ((__2__X298 = (yystack.l_mark__11YYSTACKDATA[-1]).pe__7YYSTYPE),
                              (((__0__X296 || (__0__X296 = (struct texpr *)__nw__4exprSFUl(
                                                   (size_t)(sizeof(struct texpr)))))
                                    ? ((__0__X296 = (struct texpr *)__ct__4exprFUcP4exprT2(
                                            ((struct expr *)__0__X296), ((unsigned char)157),
                                            __2__X298, (struct expr *)0)),
                                       (__0__X296->__O4__4expr.tp2 = __2__X297))
                                    : 0),
                               __0__X296))));
        if (((__0__X299 = (yystack.l_mark__11YYSTACKDATA[-3]).pn__7YYSTYPE),
             ((((unsigned char)(__0__X299->n_template_arg__4name == 1))))) &&
            ((yystack.l_mark__11YYSTACKDATA[-3]).pn__7YYSTYPE->__O1__4expr.tp->base__4node ==
             141)) {
            yyval.pe__7YYSTYPE->__O4__4expr.tp2 = (struct type *)__ct__8basetypeFUcP4name(
                (struct basetype *)0, (unsigned char)97,
                (yystack.l_mark__11YYSTACKDATA[-3]).pn__7YYSTYPE);
        }
    }

    break;
    case 373: {
        goto new2;

    }

    break;
    case 374: {
    new2: {
        Ptype __3t;

        struct texpr *__0__X300;

        __3t = (yystack.l_mark__11YYSTACKDATA[0]).pn__7YYSTYPE->__O1__4expr.tp;
        yyval.p__7YYSTYPE =
            (struct node *)((__0__X300 = 0),
                            (((__0__X300 || (__0__X300 = (struct texpr *)__nw__4exprSFUl(
                                                 (size_t)(sizeof(struct texpr)))))
                                  ? ((__0__X300 = (struct texpr *)__ct__4exprFUcP4exprT2(
                                          ((struct expr *)__0__X300), ((unsigned char)23),
                                          ((struct expr *)0), (struct expr *)0)),
                                     (__0__X300->__O4__4expr.tp2 = __3t))
                                  : 0),
                             __0__X300));
        yyval.pe__7YYSTYPE->__O3__4expr.e2 = (yystack.l_mark__11YYSTACKDATA[-2]).pe__7YYSTYPE;
        --in_new;
    }
    }

    break;
    case 375: {
        goto new4;

    }

    break;
    case 376: {
    new4: {
        Ptype __3t;

        struct texpr *__0__X301;

        __3t = (yystack.l_mark__11YYSTACKDATA[0]).pn__7YYSTYPE->__O1__4expr.tp;
        yyval.p__7YYSTYPE =
            (struct node *)((__0__X301 = 0),
                            (((__0__X301 || (__0__X301 = (struct texpr *)__nw__4exprSFUl(
                                                 (size_t)(sizeof(struct texpr)))))
                                  ? ((__0__X301 = (struct texpr *)__ct__4exprFUcP4exprT2(
                                          ((struct expr *)__0__X301), ((unsigned char)184),
                                          ((struct expr *)0), (struct expr *)0)),
                                     (__0__X301->__O4__4expr.tp2 = __3t))
                                  : 0),
                             __0__X301));
        yyval.pe__7YYSTYPE->__O3__4expr.e2 = (yystack.l_mark__11YYSTACKDATA[-2]).pe__7YYSTYPE;
        --in_new;
    }
    }

    break;
    case 377: {
        Pexpr __3ee;
        Pexpr __3e;

        struct call *__0__X302;

        struct expr *__2__X303;

        struct expr *__2__X304;

        __3ee = (yystack.l_mark__11YYSTACKDATA[-1]).pe__7YYSTYPE;
        __3e = (yystack.l_mark__11YYSTACKDATA[-3]).pe__7YYSTYPE;
        if ((__3e->base__4node == 23) || (__3e->base__4node == 184))
            __3e->__O2__4expr.e1 = __3ee;
        else
            yyval.p__7YYSTYPE =
                (struct node *)((__0__X302 = 0),
                                ((__2__X303 = __3e),
                                 ((__2__X304 = __3ee),
                                  (((__0__X302 || (__0__X302 = (struct call *)__nw__4exprSFUl(
                                                       (size_t)(sizeof(struct call)))))
                                        ? (__0__X302 = (struct call *)__ct__4exprFUcP4exprT2(
                                               ((struct expr *)__0__X302), (unsigned char)109,
                                               __2__X303, __2__X304))
                                        : 0),
                                   __0__X302))));
    }

    break;
    case 378: {
        yyval.pn__7YYSTYPE = parametrized_typename__FP4nameP4exprUc(
            (yystack.l_mark__11YYSTACKDATA[-3]).pn__7YYSTYPE,
            expr_unlist__FP5elist((yystack.l_mark__11YYSTACKDATA[-1]).el__7YYSTYPE),
            (unsigned char)0);
    }

    break;
    case 379: {
        yyval.pn__7YYSTYPE = (yystack.l_mark__11YYSTACKDATA[0]).pn__7YYSTYPE;

    }

    break;
    case 380: {
        yyval.pn__7YYSTYPE = sta_name;

    }

    break;
    case 381: {
        yyval.pn__7YYSTYPE = (yystack.l_mark__11YYSTACKDATA[-1]).pn__7YYSTYPE;

    }

    break;
    case 382: {
        if (in_arg_list && (!in_binit_list)) {
            Pktab __4tb;

            __4tb = Ctbl;
            for (; __4tb && (__4tb->k_id__6ktable == 136); __4tb = __4tb->k_next__6ktable) {
                if (look__6ktableFPCcUc(
                        __4tb, (yystack.l_mark__11YYSTACKDATA[0]).pn__7YYSTYPE->__O2__4expr.string,
                        (unsigned char)0)) {
                    const void *__2__X305;

                    {
                        struct ea __0__V98;

                        error__FPCcRC2eaN32(
                            (const char *)"illegalR toA%n in defaultA",
                            (const struct ea
                                 *)((__2__X305 = (const void *)(yystack.l_mark__11YYSTACKDATA[0])
                                                     .pn__7YYSTYPE),
                                    (((&__0__V98)->__O1__2ea.p = __2__X305), (&__0__V98))),
                            (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
                        (yystack.l_mark__11YYSTACKDATA[0]).pe__7YYSTYPE = dummy;
                        break;
                    }
                }
            }
        }
        yyval.p__7YYSTYPE = (struct node *)(yystack.l_mark__11YYSTACKDATA[0]).pn__7YYSTYPE;
    }

    break;
    case 383: {
        yyval.p__7YYSTYPE = (struct node *)__ct__4nameFPCc(
            (struct name *)0, oper_name__FUc((yystack.l_mark__11YYSTACKDATA[0]).t__7YYSTYPE));

        yyval.pn__7YYSTYPE->n_oper__4name = (yystack.l_mark__11YYSTACKDATA[0]).t__7YYSTYPE;
    }

    break;
    case 384: {
        yyval.p__7YYSTYPE = (yystack.l_mark__11YYSTACKDATA[0]).p__7YYSTYPE;
        sig_name__FP4name(yyval.pn__7YYSTYPE);
    }

    break;
    case 385: {
        yyval.p__7YYSTYPE = (struct node *)normalize__4nameFP8basetypeP5blockUc(
            (yystack.l_mark__11YYSTACKDATA[-1]).pn__7YYSTYPE,
            ((struct basetype *)((
                (struct basetype *)(yystack.l_mark__11YYSTACKDATA[-2]).p__7YYSTYPE))),
            (struct block *)0, (unsigned char)1);
    }

    break;
    case 386: {
        check_cast__Fv();

    }

    break;
    case 387: {
        TOK __3t;

        __3t = (yystack.l_mark__11YYSTACKDATA[0]).t__7YYSTYPE;

        switch (__3t) {
        case 18:
        case 76:
        case 27:
        case 31:
        case 14:
        case 2:
        case 77: {
            struct ea __0__V99;

            error__FPCcRC2eaN32(
                (const char *)"%k in operatorT",
                (const struct ea *)(((((&__0__V99)->__O1__2ea.i = ((unsigned long)__3t)), 0)),
                                    (&__0__V99)),
                (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
            __3t = 21;
        }
        }

        yyval.p__7YYSTYPE =
            (struct node *)__ct__8basetypeFUcP4name((struct basetype *)0, __3t, (struct name *)0);

    }

    break;
    case 388: {
        yyval.p__7YYSTYPE = (struct node *)__ct__8basetypeFUcP4name(
            (struct basetype *)0, (unsigned char)97,
            (yystack.l_mark__11YYSTACKDATA[0]).pn__7YYSTYPE);

    }

    break;
    case 389: {
        if (DECL_TYPE != -1) {
            switch ((yystack.l_mark__11YYSTACKDATA[-1]).pb__7YYSTYPE->base__4node) {
            case 119:
            case 121: {
                Pbase __6bt;

                __6bt = __ct__8basetypeFUcP4name((struct basetype *)0, (unsigned char)0,
                                                 (struct name *)0);
                ((*__6bt)) = (*(yystack.l_mark__11YYSTACKDATA[-1]).pb__7YYSTYPE);
                if ((yystack.l_mark__11YYSTACKDATA[-1]).pb__7YYSTYPE &&
                    ((yystack.l_mark__11YYSTACKDATA[-1]).pb__7YYSTYPE->permanent__4node == 0))
                    del__4typeFv((struct type *)(yystack.l_mark__11YYSTACKDATA[-1]).pb__7YYSTYPE);

                (yystack.l_mark__11YYSTACKDATA[-1]).pb__7YYSTYPE = __6bt;
            }
            }
            yyval.p__7YYSTYPE = (struct node *)type_adj__8basetypeFUc(
                (yystack.l_mark__11YYSTACKDATA[-1]).pb__7YYSTYPE,
                (yystack.l_mark__11YYSTACKDATA[0]).t__7YYSTYPE);
        }
        DECL_TYPE = 0;
    }

    break;
    case 390: {
        if (DECL_TYPE != -1)
            yyval.p__7YYSTYPE = (struct node *)name_adj__8basetypeFP4name(
                (yystack.l_mark__11YYSTACKDATA[-1]).pb__7YYSTYPE,
                (yystack.l_mark__11YYSTACKDATA[0]).pn__7YYSTYPE);
        DECL_TYPE = 0;
    }

    break;
    case 391: {
        yyval.p__7YYSTYPE = (struct node *)normalize__4nameFP8basetypeP5blockUc(
            (yystack.l_mark__11YYSTACKDATA[0]).pn__7YYSTYPE,
            ((struct basetype *)((
                (struct basetype *)(yystack.l_mark__11YYSTACKDATA[-1]).p__7YYSTYPE))),
            (struct block *)0, (unsigned char)1);

    }

    break;
    case 392: {
        yyval.p__7YYSTYPE = (struct node *)normalize__4nameFP8basetypeP5blockUc(
            (yystack.l_mark__11YYSTACKDATA[0]).pn__7YYSTYPE,
            ((struct basetype *)((
                (struct basetype *)(yystack.l_mark__11YYSTACKDATA[-1]).p__7YYSTYPE))),
            (struct block *)0, (unsigned char)1);

    }

    break;
    case 393: {
        yyval.p__7YYSTYPE = (struct node *)normalize__4nameFP8basetypeP5blockUc(
            (yystack.l_mark__11YYSTACKDATA[0]).pn__7YYSTYPE,
            ((struct basetype *)((
                (struct basetype *)(yystack.l_mark__11YYSTACKDATA[-1]).p__7YYSTYPE))),
            (struct block *)0, (unsigned char)0);
    }

    break;
    case 394: {
    }

    break;
    case 395: {
        yyval.p__7YYSTYPE = (struct node *)normalize__4nameFP8basetypeP5blockUc(
            (yystack.l_mark__11YYSTACKDATA[-3]).pn__7YYSTYPE,
            ((struct basetype *)((
                (struct basetype *)(yystack.l_mark__11YYSTACKDATA[-4]).p__7YYSTYPE))),
            (struct block *)0, (unsigned char)0);
        yyval.pn__7YYSTYPE->__O3__4expr.n_initializer =
            (yystack.l_mark__11YYSTACKDATA[0]).pe__7YYSTYPE;
    }

    break;
    case 396: {
        ((((Ctbl = __ct__6ktableFiP6ktableP4name((struct ktable *)0, 0, Ctbl, (struct name *)0)),
           (Ctbl->k_id__6ktable = 136))),
         (((void)0)));

        in_arg_list = 1;
        check_decl__Fv();
        yyval.pl__7YYSTYPE = 0;

    }

    break;
    case 397: {
        yyval.p__7YYSTYPE = (struct node *)__ct__3fctFP4typeP4nameUc(
            (struct fct *)0, (struct type *)0,
            name_unlist__FP5nlist((yystack.l_mark__11YYSTACKDATA[-3]).nl__7YYSTYPE),
            (yystack.l_mark__11YYSTACKDATA[-2]).t__7YYSTYPE);
        if (((yychar == -1) ? ((yychar = lalex__Fv()), yychar) : yychar) != 69)
            in_arg_list = 0;

        (((struct fct *)(((struct fct *)yyval.pt__7YYSTYPE))))->f_const__3fct =
            ((yystack.l_mark__11YYSTACKDATA[0]).i__7YYSTYPE & 1);

        {
            ;

            if (Ctbl == Gtbl)
                error__FiPCc((int)'i', (const char *)"bad parsing table");

            {
                Pktab __1b;

                __1b = Ctbl;

                Ctbl = Ctbl->k_next__6ktable;

                if ((__1b->k_id__6ktable == 136) || 0)
                    __dt__6ktableFv(__1b, 3);
            }
        }

    }

    break;
    case 398: {
        register struct nlist *__0__X306;

        struct name *__2__X307;

        if ((yystack.l_mark__11YYSTACKDATA[0]).p__7YYSTYPE)
            if ((yystack.l_mark__11YYSTACKDATA[-2]).p__7YYSTYPE)
                ((__0__X306 = (yystack.l_mark__11YYSTACKDATA[-2]).nl__7YYSTYPE),
                 ((__2__X307 = (yystack.l_mark__11YYSTACKDATA[0]).pn__7YYSTYPE),
                  (((__0__X306->tail__5nlist->__O1__4name.n_list = __2__X307),
                    (__0__X306->tail__5nlist = __2__X307)),
                   (((void)0)))));
            else {
                error__FPCc((const char *)"AD syntax");
                yyval.nl__7YYSTYPE = __ct__5nlistFP4name(
                    (struct nlist *)0, (yystack.l_mark__11YYSTACKDATA[0]).pn__7YYSTYPE);
            }
        else
            error__FPCc((const char *)"AD syntax");
    }

    break;
    case 399: {
        if ((yystack.l_mark__11YYSTACKDATA[0]).p__7YYSTYPE)
            yyval.nl__7YYSTYPE = __ct__5nlistFP4name(
                (struct nlist *)0, (yystack.l_mark__11YYSTACKDATA[0]).pn__7YYSTYPE);

    }

    break;
    case 401: {
        yyval.p__7YYSTYPE = 0;

    }

    break;
    case 402: {
        yyval.t__7YYSTYPE = 1;

    }

    break;
    case 403: {
        yyval.t__7YYSTYPE = 155;

    }

    break;
    case 404: {
        yyval.t__7YYSTYPE = 155;

    }

    break;
    case 405: {
        yyval.p__7YYSTYPE = (struct node *)__ct__3ptrFUcP4type((struct ptr *)0, (unsigned char)125,
                                                               (struct type *)0);

        must_be_id = 1;
    }

    break;
    case 406: {
        yyval.p__7YYSTYPE = (struct node *)__ct__3ptrFUcP4type((struct ptr *)0, (unsigned char)158,
                                                               (struct type *)0);

        must_be_id = 1;
    }

    break;
    case 407: {
        yyval.p__7YYSTYPE = (struct node *)doptr__FUcT1(
            (unsigned char)125, (yystack.l_mark__11YYSTACKDATA[0]).t__7YYSTYPE);

    }

    break;
    case 408: {
        switch ((yystack.l_mark__11YYSTACKDATA[0]).t__7YYSTYPE) {
            unsigned long __2__X308;

        case 26:
            (yystack.l_mark__11YYSTACKDATA[-1]).pp__7YYSTYPE->b_const__4type = 1;

            break;
        case 170:
            error__FiPCc((int)'w', (const char *)"\"volatile\" not implemented (ignored)");
            break;
        default: {
            struct ea __0__V100;

            error__FPCcRC2eaN32(
                (const char *)"syntax error: *%k",
                (const struct ea *)((__2__X308 = (yystack.l_mark__11YYSTACKDATA[0]).t__7YYSTYPE),
                                    (((((&__0__V100)->__O1__2ea.i = __2__X308), 0)), (&__0__V100))),
                (const struct ea *)ea0, (const struct ea *)ea0, (const struct ea *)ea0);
        }
        }
        yyval.p__7YYSTYPE = (struct node *)(yystack.l_mark__11YYSTACKDATA[-1]).pp__7YYSTYPE;
    }

    break;
    case 409: {
        yyval.p__7YYSTYPE = (struct node *)doptr__FUcT1(
            (unsigned char)158, (yystack.l_mark__11YYSTACKDATA[0]).t__7YYSTYPE);

    }

    break;
    case 410: {
        memptr_pn = (yystack.l_mark__11YYSTACKDATA[-1]).pn__7YYSTYPE;
        memptr_tok = 0;
        goto memptr1;
    }

    break;
    case 411: {
        memptr_pn = (yystack.l_mark__11YYSTACKDATA[0]).pn__7YYSTYPE;
        memptr_tok = 0;
    memptr1:
        if (memptr_tok)
            yyval.p__7YYSTYPE = (struct node *)doptr__FUcT1((unsigned char)125, memptr_tok);
        else
            yyval.p__7YYSTYPE = (struct node *)__ct__3ptrFUcP4type(
                (struct ptr *)0, (unsigned char)125, (struct type *)0);
        {
            Pname __3n;

            __3n = memptr_pn;
            if (((((unsigned char)(__3n->n_template_arg__4name == 1)))) == 0) {
                if (skiptypedefs__4typeFv(__3n->__O1__4expr.tp)->base__4node != 119) {
                    yyval.pp__7YYSTYPE->memof__3ptr = 0;
                    error__FPCc((const char *)"P toM of nonCT");
                } else
                    yyval.pp__7YYSTYPE->memof__3ptr =
                        classtype__4typeFv(skiptypedefs__4typeFv(__3n->__O1__4expr.tp));
            } else {
                yyval.pp__7YYSTYPE->memof__3ptr = 0;
                yyval.pp__7YYSTYPE->ptname__3ptr = __3n;
            }
            must_be_id = 1;
        }
    }

    break;
    case 412: {
        memptr_pn = (yystack.l_mark__11YYSTACKDATA[-2]).pn__7YYSTYPE;
        memptr_tok = (yystack.l_mark__11YYSTACKDATA[0]).t__7YYSTYPE;
        goto memptr1;
    }

    break;
    case 413: {
        memptr_pn = (yystack.l_mark__11YYSTACKDATA[-1]).pn__7YYSTYPE;
        memptr_tok = (yystack.l_mark__11YYSTACKDATA[0]).t__7YYSTYPE;
        goto memptr1;
    }

    break;
    case 414: {
        yyval.p__7YYSTYPE = (struct node *)__ct__3vecFP4typeP4expr(
            (struct vec *)0, (struct type *)0,
            ((yystack.l_mark__11YYSTACKDATA[-1]).pe__7YYSTYPE != dummy)
                ? (yystack.l_mark__11YYSTACKDATA[-1]).pe__7YYSTYPE
                : (((struct expr *)0)));

    }

    break;
    case 415: {
        yyval.p__7YYSTYPE = (struct node *)__ct__3vecFP4typeP4expr(
            (struct vec *)0, (struct type *)0, (struct expr *)0);

    }

    break;
    }
    yystack.s_mark__11YYSTACKDATA -= __1yym;
    __1yystate = ((*yystack.s_mark__11YYSTACKDATA));
    yystack.l_mark__11YYSTACKDATA -= __1yym;
    __1yym = (yylhs[__1yyn]);
    if ((__1yystate == 0) && (__1yym == 0)) {
        __1yystate = 23;
        ((*(++yystack.s_mark__11YYSTACKDATA))) = 23;
        ((*(++yystack.l_mark__11YYSTACKDATA))) = yyval;
        if (yychar < 0) {
            yychar = lalex__Fv();
            if (yychar < 0)
                yychar = 0;
        }
        if (yychar == 0)
            goto yyaccept;
        goto yyloop;
    }
    if (((((__1yyn = (yygindex[__1yym])) != 0) && ((__1yyn += __1yystate) >= 0)) &&
         (__1yyn <= 8450)) &&
        ((yycheck[__1yyn]) == (((int)__1yystate))))
        __1yystate = (yytable[__1yyn]);
    else
        __1yystate = (yydgoto[__1yym]);

    if ((yystack.s_mark__11YYSTACKDATA >= yystack.s_last__11YYSTACKDATA) &&
        (yygrowstack__FP11YYSTACKDATA(&yystack) == -2))
        goto yyoverflow;
    ((*(++yystack.s_mark__11YYSTACKDATA))) = (((int)__1yystate));
    ((*(++yystack.l_mark__11YYSTACKDATA))) = yyval;
    goto yyloop;

yyoverflow:
    yyerror__FPCc((const char *)"yacc stack overflow");

yyabort:;
    return 1;

yyaccept:;
    return 0;
}

static struct ea *__ct__2eaFPCv(struct ea *__0this, const void *__2pp) {
    if (__0this || (__0this = (struct ea *)__nw__FUl((unsigned long)(sizeof(struct ea)))))
        __0this->__O1__2ea.p = __2pp;

    return __0this;
}

extern struct toknode *free_toks__7toknode;

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
