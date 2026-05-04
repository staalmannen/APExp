
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

struct tree_copy_info { /* sizeof tree_copy_info == 24 */

    void (*node_hook__14tree_copy_info)(void *__1info, Pnode *, int, int *, int *);

    char *(*malloc_hook__14tree_copy_info)(void *__1info, size_t);
    void *hook_info__14tree_copy_info;
};
union __C1__copy_walker__FRP4node10node_classPvR16tree_node_actioniP4nodeR14tree_walk_treeRi__L29;

union
    __C1__copy_walker__FRP4node10node_classPvR16tree_node_actioniP4nodeR14tree_walk_treeRi__L29 { /* sizeof __C1__copy_walker__FRP4node10node_classPvR16tree_node_actioniP4nodeR14tree_walk_treeRi__L29 == 8 */
    Pnode node;
    Pvirt vr;
    Plist list;
    Pgen g;
    Pvec vc;
    Pfct f;
    Ptable t;
    Pktab kt;
    Pbase bt;
    Pexpr x;
    Pstmt s;
    Ptype tp;
    Penum e;
    Pclass c;
    Pbcl bcl;
    Pin iline;
    Pia ia;
    Pname n;
    Pptr p;
};

extern size_t strlen(const char *);

extern char *strcpy(char *, const char *);

void add__10patch_treeSFP4node(Pnode);

extern void *memcpy(void *, const void *, size_t);

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

int discriminator__8basetypeFi(struct basetype *__0this, int);

int discriminator__4exprFi(struct expr *__0this, int);

extern Pname k_find_name__FPCcP6ktableUc(const char *, Pktab, TOK);

Pname look__5tableFPCcUc(struct table *__0this, const char *, TOK);

extern int strcmp(const char *, const char *);

Pname is_cl_obj__4typeFv(struct type *__0this);

void copy_walker__FRP4node10node_classPvR16tree_node_actioniP4nodeR14tree_walk_treeRi(
    Pnode *__1node, int __1cl, void *__1info, int *__1action, int __1__A26, Pnode __1__A27,
    struct tree_walk_tree *__1__A28, int *__1register_in_hash) {

    union __C1__copy_walker__FRP4node10node_classPvR16tree_node_actioniP4nodeR14tree_walk_treeRi__L29
        __1n;
    Pnode __1original_node;

    struct tree_copy_info *__1tci;

    __1original_node = ((*__1node));

    __1tci = (((struct tree_copy_info *)(((struct tree_copy_info *)__1info))));
    ((*__1action)) = 0;

    ((__1tci->node_hook__14tree_copy_info ? (((void)(*(__1tci->node_hook__14tree_copy_info))(
                                                __1tci->hook_info__14tree_copy_info, __1node, __1cl,
                                                __1action, __1register_in_hash)))
                                          : (((void)0))));

    if (((*__1action)) != 0)
        return;

    if (((*__1node)) != __1original_node) {
        __1n.node = ((*__1node));
    } else
        switch (__1cl) {
            unsigned long __2__X31;

            unsigned long __2__X32;

        case 0:
            break;
        case 1:
            __1n.node = (((struct node *)(((
                struct node *)((__1tci->malloc_hook__14tree_copy_info
                                    ? (*(__1tci->malloc_hook__14tree_copy_info))(
                                          __1tci->hook_info__14tree_copy_info, (sizeof((*__1node))))
                                    : (((char *)(((char *)__nw__FUl((
                                          size_t)((sizeof(char)) * (sizeof((*__1node)))))))))))))));
            ((*__1n.node)) = (*((*__1node)));
            goto Replace;

        case 2:
            __1n.vr = (((struct virt *)(((struct virt *)((
                __1tci->malloc_hook__14tree_copy_info
                    ? (*(__1tci->malloc_hook__14tree_copy_info))(
                          __1tci->hook_info__14tree_copy_info, (sizeof(struct virt)))
                    : (((char *)(((char *)__nw__FUl(
                          (size_t)((sizeof(char)) * (sizeof(struct virt))))))))))))));
            ((*__1n.vr)) = (*(((struct virt *)(((struct virt *)((*__1node)))))));
            goto Replace;

        case 3:
            __1n.list = (((struct name_list *)(((struct name_list *)((
                __1tci->malloc_hook__14tree_copy_info
                    ? (*(__1tci->malloc_hook__14tree_copy_info))(
                          __1tci->hook_info__14tree_copy_info, (sizeof(struct name_list)))
                    : (((char *)(((char *)__nw__FUl(
                          (size_t)((sizeof(char)) * (sizeof(struct name_list))))))))))))));
            ((*__1n.list)) = (*(((struct name_list *)(((struct name_list *)((*__1node)))))));
            goto Replace;

        case 4:
            __1n.g = (((struct gen *)((
                (struct gen *)((__1tci->malloc_hook__14tree_copy_info
                                    ? (*(__1tci->malloc_hook__14tree_copy_info))(
                                          __1tci->hook_info__14tree_copy_info, (sizeof(struct gen)))
                                    : (((char *)(((char *)__nw__FUl((
                                          size_t)((sizeof(char)) * (sizeof(struct gen))))))))))))));
            ((*__1n.g)) = (*(((struct gen *)(((struct gen *)((*__1node)))))));
            goto Replace;

        case 5:
            __1n.vc = (((struct vec *)((
                (struct vec *)((__1tci->malloc_hook__14tree_copy_info
                                    ? (*(__1tci->malloc_hook__14tree_copy_info))(
                                          __1tci->hook_info__14tree_copy_info, (sizeof(struct vec)))
                                    : (((char *)(((char *)__nw__FUl((
                                          size_t)((sizeof(char)) * (sizeof(struct vec))))))))))))));
            ((*__1n.vc)) = (*(((struct vec *)(((struct vec *)((*__1node)))))));
            goto Replace;

        case 6:
            __1n.p = (((struct ptr *)((
                (struct ptr *)((__1tci->malloc_hook__14tree_copy_info
                                    ? (*(__1tci->malloc_hook__14tree_copy_info))(
                                          __1tci->hook_info__14tree_copy_info, (sizeof(struct ptr)))
                                    : (((char *)(((char *)__nw__FUl((
                                          size_t)((sizeof(char)) * (sizeof(struct ptr))))))))))))));
            ((*__1n.p)) = (*(((struct ptr *)(((struct ptr *)((*__1node)))))));
            goto Replace;

        case 7:
            __1n.f = (((struct fct *)((
                (struct fct *)((__1tci->malloc_hook__14tree_copy_info
                                    ? (*(__1tci->malloc_hook__14tree_copy_info))(
                                          __1tci->hook_info__14tree_copy_info, (sizeof(struct fct)))
                                    : (((char *)(((char *)__nw__FUl((
                                          size_t)((sizeof(char)) * (sizeof(struct fct))))))))))))));
            ((*__1n.f)) = (*(((struct fct *)(((struct fct *)((*__1node)))))));
            if (__1n.f->f_signature__3fct) {
                char *__3str_tmp;

                unsigned long __2__X30;

                __3str_tmp =
                    (((char *)((__2__X30 = (strlen((((struct fct *)(((struct fct *)((*__1node))))))
                                                       ->f_signature__3fct) +
                                            1)),
                               ((__1tci->malloc_hook__14tree_copy_info
                                     ? (*(__1tci->malloc_hook__14tree_copy_info))(
                                           __1tci->hook_info__14tree_copy_info, __2__X30)
                                     : (((char *)(((char *)__nw__FUl(
                                           (size_t)((sizeof(char)) * __2__X30)))))))))));

                strcpy(__3str_tmp,
                       (((struct fct *)(((struct fct *)((*__1node))))))->f_signature__3fct);

                __1n.f->f_signature__3fct = (const char *)__3str_tmp;
            }

            ;
            goto Replace;

        case 8:
            __1n.t = (((struct table *)(((struct table *)((
                __1tci->malloc_hook__14tree_copy_info
                    ? (*(__1tci->malloc_hook__14tree_copy_info))(
                          __1tci->hook_info__14tree_copy_info, (sizeof(struct table)))
                    : (((char *)(((char *)__nw__FUl(
                          (size_t)((sizeof(char)) * (sizeof(struct table))))))))))))));
            ((*__1n.t)) = (*(((struct table *)(((struct table *)((*__1node)))))));
            add__10patch_treeSFP4node(__1n.node);
            __1n.t->entries__5table =
                (((Pname *)((__2__X31 = ((sizeof(Pname)) * __1n.t->size__5table)),
                            ((__1tci->malloc_hook__14tree_copy_info
                                  ? (*(__1tci->malloc_hook__14tree_copy_info))(
                                        __1tci->hook_info__14tree_copy_info, __2__X31)
                                  : (((char *)(((char *)__nw__FUl(
                                        (size_t)((sizeof(char)) * __2__X31)))))))))));
            memcpy(
                (void *)(((char *)__1n.t->entries__5table)),
                (const void *)((
                    (char *)(((struct table *)(((struct table *)((*__1node))))))->entries__5table)),
                __1n.t->size__5table * (sizeof(Pname)));
            __1n.t->hashtbl__5table =
                (((short *)((__2__X32 = ((sizeof(short)) * __1n.t->hashsize__5table)),
                            ((__1tci->malloc_hook__14tree_copy_info
                                  ? (*(__1tci->malloc_hook__14tree_copy_info))(
                                        __1tci->hook_info__14tree_copy_info, __2__X32)
                                  : (((char *)(((char *)__nw__FUl(
                                        (size_t)((sizeof(char)) * __2__X32)))))))))));
            memcpy(
                (void *)(((char *)__1n.t->hashtbl__5table)),
                (const void *)((
                    (char *)(((struct table *)(((struct table *)((*__1node))))))->hashtbl__5table)),
                __1n.t->hashsize__5table * (sizeof(short)));
            goto Replace;

        case 19:
            __1n.kt = (((struct ktable *)(((struct ktable *)((
                __1tci->malloc_hook__14tree_copy_info
                    ? (*(__1tci->malloc_hook__14tree_copy_info))(
                          __1tci->hook_info__14tree_copy_info, (sizeof(struct ktable)))
                    : (((char *)(((char *)__nw__FUl(
                          (size_t)((sizeof(char)) * (sizeof(struct ktable))))))))))))));
            ((*__1n.kt)) = (*(((struct ktable *)(((struct ktable *)((*__1node)))))));
            add__10patch_treeSFP4node(__1n.node);
            goto Replace;

        case 9:
            if ((((((struct type *)(((struct type *)((*__1node))))))->defined__4type & 65))) {
                ((*__1action)) = 1;
                return;
            }
            __1n.bt = (((struct basetype *)(((struct basetype *)((
                __1tci->malloc_hook__14tree_copy_info
                    ? (*(__1tci->malloc_hook__14tree_copy_info))(
                          __1tci->hook_info__14tree_copy_info, (sizeof(struct basetype)))
                    : (((char *)(((char *)__nw__FUl(
                          (size_t)((sizeof(char)) * (sizeof(struct basetype))))))))))))));
            ((*__1n.bt)) = (*(((struct basetype *)(((struct basetype *)((*__1node)))))));
            __1n.bt->defined__4type |= 0100;
            if ((discriminator__8basetypeFi(__1n.bt, 0) == 2) &&
                __1n.bt->__O1__8basetype.b_linkage) {
                char *__3str_tmp;

                unsigned long __2__X33;

                __3str_tmp = ((__2__X33 = (strlen(__1n.bt->__O1__8basetype.b_linkage) + 1)),
                              ((__1tci->malloc_hook__14tree_copy_info
                                    ? (*(__1tci->malloc_hook__14tree_copy_info))(
                                          __1tci->hook_info__14tree_copy_info, __2__X33)
                                    : (((char *)(((char *)__nw__FUl(
                                          (size_t)((sizeof(char)) * __2__X33)))))))));

                strcpy(__3str_tmp, (((struct basetype *)(((struct basetype *)((*__1node))))))
                                       ->__O1__8basetype.b_linkage);

                __1n.bt->__O1__8basetype.b_linkage = (const char *)__3str_tmp;
            }
            goto Replace;

        case 11:
            if ((((*__1node)) == (((struct node *)dummy))) ||
                (((*__1node)) == (((struct node *)zero)))) {
                ((*__1action)) = 1;
                return;
            }
            __1n.x = (((struct expr *)(((struct expr *)((
                __1tci->malloc_hook__14tree_copy_info
                    ? (*(__1tci->malloc_hook__14tree_copy_info))(
                          __1tci->hook_info__14tree_copy_info, (sizeof(struct expr)))
                    : (((char *)(((char *)__nw__FUl(
                          (size_t)((sizeof(char)) * (sizeof(struct expr))))))))))))));
            ((*__1n.x)) = (*(((struct expr *)(((struct expr *)((*__1node)))))));
            if ((discriminator__4exprFi(__1n.x, 1) == 3) && __1n.x->__O2__4expr.string) {
                char *__3str_tmp;

                unsigned long __2__X34;

                __3str_tmp = ((__2__X34 = (strlen(__1n.x->__O2__4expr.string) + 1)),
                              ((__1tci->malloc_hook__14tree_copy_info
                                    ? (*(__1tci->malloc_hook__14tree_copy_info))(
                                          __1tci->hook_info__14tree_copy_info, __2__X34)
                                    : (((char *)(((char *)__nw__FUl(
                                          (size_t)((sizeof(char)) * __2__X34)))))))));

                strcpy(__3str_tmp,
                       (((struct expr *)(((struct expr *)((*__1node))))))->__O2__4expr.string);

                __1n.x->__O2__4expr.string = (const char *)__3str_tmp;
            }
            if ((discriminator__4exprFi(__1n.x, 2) == 3) && __1n.x->__O3__4expr.string2) {
                char *__3str_tmp;

                unsigned long __2__X35;

                __3str_tmp = ((__2__X35 = (strlen(__1n.x->__O3__4expr.string2) + 1)),
                              ((__1tci->malloc_hook__14tree_copy_info
                                    ? (*(__1tci->malloc_hook__14tree_copy_info))(
                                          __1tci->hook_info__14tree_copy_info, __2__X35)
                                    : (((char *)(((char *)__nw__FUl(
                                          (size_t)((sizeof(char)) * __2__X35)))))))));

                strcpy(__3str_tmp,
                       (((struct expr *)(((struct expr *)((*__1node))))))->__O3__4expr.string2);

                __1n.x->__O3__4expr.string2 = (const char *)__3str_tmp;
            }
            goto Replace;

        case 12:
            __1n.s = (((struct stmt *)(((struct stmt *)((
                __1tci->malloc_hook__14tree_copy_info
                    ? (*(__1tci->malloc_hook__14tree_copy_info))(
                          __1tci->hook_info__14tree_copy_info, (sizeof(struct stmt)))
                    : (((char *)(((char *)__nw__FUl(
                          (size_t)((sizeof(char)) * (sizeof(struct stmt))))))))))))));
            ((*__1n.s)) = (*(((struct stmt *)(((struct stmt *)((*__1node)))))));
            goto Replace;

        case 13:
            if ((((((struct type *)(((struct type *)((*__1node))))))->defined__4type & 65))) {
                ((*__1action)) = 1;
                return;
            }
            __1n.e = (((struct enumdef *)(((struct enumdef *)((
                __1tci->malloc_hook__14tree_copy_info
                    ? (*(__1tci->malloc_hook__14tree_copy_info))(
                          __1tci->hook_info__14tree_copy_info, (sizeof(struct enumdef)))
                    : (((char *)(((char *)__nw__FUl(
                          (size_t)((sizeof(char)) * (sizeof(struct enumdef))))))))))))));
            ((*__1n.e)) = (*(((struct enumdef *)(((struct enumdef *)((*__1node)))))));
            __1n.e->defined__4type |= 0100;
            if (__1n.e->string__7enumdef) {
                char *__3str_tmp;

                unsigned long __2__X36;

                __3str_tmp = ((__2__X36 = (__1n.e->e_strlen__7enumdef + 1)),
                              ((__1tci->malloc_hook__14tree_copy_info
                                    ? (*(__1tci->malloc_hook__14tree_copy_info))(
                                          __1tci->hook_info__14tree_copy_info, __2__X36)
                                    : (((char *)(((char *)__nw__FUl(
                                          (size_t)((sizeof(char)) * __2__X36)))))))));
                strcpy(__3str_tmp,
                       (((struct enumdef *)(((struct enumdef *)((*__1node))))))->string__7enumdef);

                __1n.e->string__7enumdef = (const char *)__3str_tmp;
            }
            if (__1n.e->nested_sig__4type) {
                __1n.e->nested_sig__4type = 0;
            }
            goto Replace;

        case 14:
            if ((((((struct type *)(((struct type *)((*__1node))))))->defined__4type & 65))) {
                ((*__1action)) = 1;
                return;
            }
            __1n.c = (((struct classdef *)(((struct classdef *)((
                __1tci->malloc_hook__14tree_copy_info
                    ? (*(__1tci->malloc_hook__14tree_copy_info))(
                          __1tci->hook_info__14tree_copy_info, (sizeof(struct classdef)))
                    : (((char *)(((char *)__nw__FUl(
                          (size_t)((sizeof(char)) * (sizeof(struct classdef))))))))))))));
            ((*__1n.c)) = (*(((struct classdef *)(((struct classdef *)((*__1node)))))));
            __1n.c->defined__4type |= 0100;
            if (__1n.c->string__8classdef) {
                char *__3str_tmp;

                unsigned long __2__X37;

                __3str_tmp = ((__2__X37 = (strlen(__1n.c->string__8classdef) + 1)),
                              ((__1tci->malloc_hook__14tree_copy_info
                                    ? (*(__1tci->malloc_hook__14tree_copy_info))(
                                          __1tci->hook_info__14tree_copy_info, __2__X37)
                                    : (((char *)(((char *)__nw__FUl(
                                          (size_t)((sizeof(char)) * __2__X37)))))))));

                strcpy(
                    __3str_tmp,
                    (((struct classdef *)(((struct classdef *)((*__1node))))))->string__8classdef);

                __1n.c->string__8classdef = (const char *)__3str_tmp;
            }
            if (__1n.c->nested_sig__4type) {
                unsigned long __2__X38;

                __1n.c->nested_sig__4type =
                    ((__2__X38 = (strlen((const char *)__1n.c->nested_sig__4type) + 1)),
                     ((__1tci->malloc_hook__14tree_copy_info
                           ? (*(__1tci->malloc_hook__14tree_copy_info))(
                                 __1tci->hook_info__14tree_copy_info, __2__X38)
                           : (((char *)((
                                 (char *)__nw__FUl((size_t)((sizeof(char)) * __2__X38)))))))));
                strcpy(__1n.c->nested_sig__4type,
                       (const char *)(((struct classdef *)(((struct classdef *)((*__1node))))))
                           ->nested_sig__4type);
            }
            goto Replace;

        case 15:
            __1n.bcl = (((struct basecl *)(((struct basecl *)((
                __1tci->malloc_hook__14tree_copy_info
                    ? (*(__1tci->malloc_hook__14tree_copy_info))(
                          __1tci->hook_info__14tree_copy_info, (sizeof(struct basecl)))
                    : (((char *)(((char *)__nw__FUl(
                          (size_t)((sizeof(char)) * (sizeof(struct basecl))))))))))))));
            ((*__1n.bcl)) = (*(((struct basecl *)(((struct basecl *)((*__1node)))))));
            goto Replace;

        case 18:
            __1n.tp = (((struct type *)(((struct type *)((
                __1tci->malloc_hook__14tree_copy_info
                    ? (*(__1tci->malloc_hook__14tree_copy_info))(
                          __1tci->hook_info__14tree_copy_info, (sizeof(struct type)))
                    : (((char *)(((char *)__nw__FUl(
                          (size_t)((sizeof(char)) * (sizeof(struct type))))))))))))));
            ((*__1n.tp)) = (*(((struct type *)(((struct type *)((*__1node)))))));
            if (__1n.tp->nested_sig__4type) {
                unsigned long __2__X39;

                __1n.tp->nested_sig__4type =
                    ((__2__X39 = (strlen((const char *)__1n.tp->nested_sig__4type) + 1)),
                     ((__1tci->malloc_hook__14tree_copy_info
                           ? (*(__1tci->malloc_hook__14tree_copy_info))(
                                 __1tci->hook_info__14tree_copy_info, __2__X39)
                           : (((char *)((
                                 (char *)__nw__FUl((size_t)((sizeof(char)) * __2__X39)))))))));
                strcpy(__1n.tp->nested_sig__4type,
                       (const char *)(((struct type *)(((struct type *)((*__1node))))))
                           ->nested_sig__4type);
            }
            goto Replace;

        case 16:
            __1n.iline = (((struct iline *)(((struct iline *)((
                __1tci->malloc_hook__14tree_copy_info
                    ? (*(__1tci->malloc_hook__14tree_copy_info))(
                          __1tci->hook_info__14tree_copy_info, (sizeof(struct iline)))
                    : (((char *)(((char *)__nw__FUl(
                          (size_t)((sizeof(char)) * (sizeof(struct iline))))))))))))));
            ((*__1n.iline)) = (*(((struct iline *)(((struct iline *)((*__1node)))))));
            goto Replace;

        case 17:
            __1n.ia = (((struct ia *)((
                (struct ia *)((__1tci->malloc_hook__14tree_copy_info
                                   ? (*(__1tci->malloc_hook__14tree_copy_info))(
                                         __1tci->hook_info__14tree_copy_info, (sizeof(struct ia)))
                                   : (((char *)(((char *)__nw__FUl(
                                         (size_t)((sizeof(char)) * (sizeof(struct ia))))))))))))));
            ((*__1n.ia)) = (*(((struct ia *)(((struct ia *)((*__1node)))))));
            goto Replace;

        case 10:
            if ((((struct name *)(((struct name *)((*__1node))))))->__O2__4expr.string) {
                Pname __3n;
                if (((*__1node))->base__4node == 123) {
                    __3n = k_find_name__FPCcP6ktableUc(
                        (((struct name *)(((struct name *)((*__1node))))))->__O2__4expr.string,
                        Gtbl, (unsigned char)0);
                    if (__3n && (__3n->base__4node == 85))
                        __3n = 0;
                } else
                    __3n = look__5tableFPCcUc(
                        gtbl,
                        (((struct name *)(((struct name *)((*__1node))))))->__O2__4expr.string,
                        (unsigned char)0);
                if ((((struct name *)(((struct name *)((*__1node)))))) == __3n) {
                    ((*__1action)) = 1;
                    return;
                }
            }
            __1n.n = (((struct name *)(((struct name *)((
                __1tci->malloc_hook__14tree_copy_info
                    ? (*(__1tci->malloc_hook__14tree_copy_info))(
                          __1tci->hook_info__14tree_copy_info, (sizeof(struct name)))
                    : (((char *)(((char *)__nw__FUl(
                          (size_t)((sizeof(char)) * (sizeof(struct name))))))))))))));
            ((*__1n.n)) = (*(((struct name *)(((struct name *)((*__1node)))))));
            if (__1n.n->n_ktable__4name)
                add__10patch_treeSFP4node(__1n.node);

            {
                int __3done;

                __3done = 0;
                if ((__1n.n->base__4node == 176) && __1n.n->__O2__4expr.string) {
                    Pbase_inst __4bi;

                    __4bi = (((struct basic_inst *)((
                        (struct basic_inst *)__1tci->hook_info__14tree_copy_info))));
                    {
                        {
                            Plist __4formal;

                            __4formal = __4bi->inst_formals__10basic_inst;

                            for (; __4formal; __4formal = __4formal->l__9name_list) {
                                if (__4formal->f__9name_list->n_template_arg__4name != 1)
                                    continue;
                                if (strcmp(__4formal->f__9name_list->__O2__4expr.string,
                                           __1n.n->__O2__4expr.string) == 0) {
                                    Ptype __6t;
                                    Pname __6cn;

                                    __6t = __4formal->f__9name_list->__O1__4expr.tp;
                                    __6cn = is_cl_obj__4typeFv(__6t);
                                    if (__6cn || eobj) {
                                        char *__7str_tmp;

                                        unsigned long __2__X40;

                                        __7str_tmp =
                                            ((__2__X40 =
                                                  (strlen(eobj ? (((struct enumdef *)((
                                                                      (struct enumdef *)
                                                                          eobj->__O1__4expr.tp))))
                                                                     ->string__7enumdef
                                                               : (((struct classdef *)((
                                                                      (struct classdef *)
                                                                          __6cn->__O1__4expr.tp))))
                                                                     ->string__8classdef) +
                                                   1)),
                                             ((__1tci->malloc_hook__14tree_copy_info
                                                   ? (*(__1tci->malloc_hook__14tree_copy_info))(
                                                         __1tci->hook_info__14tree_copy_info,
                                                         __2__X40)
                                                   : (((char *)(((char *)__nw__FUl((
                                                         size_t)((sizeof(char)) * __2__X40)))))))));
                                        strcpy(
                                            __7str_tmp,
                                            eobj ? (((struct enumdef *)((
                                                        (struct enumdef *)eobj->__O1__4expr.tp))))
                                                       ->string__7enumdef
                                                 : (((struct classdef *)((
                                                        (struct classdef *)__6cn->__O1__4expr.tp))))
                                                       ->string__8classdef);

                                        __1n.n->__O2__4expr.string = (const char *)__7str_tmp;
                                    } else {
                                        __1n.n->__O2__4expr.string = 0;
                                    }
                                    __3done = 1;
                                    break;
                                }
                            }
                        }
                    }
                } else if (((!__3done) && (discriminator__4exprFi(__1n.x, 1) == 3)) &&
                           __1n.n->__O2__4expr.string) {
                    char *__4str_tmp;

                    unsigned long __2__X41;

                    __4str_tmp = ((__2__X41 = (strlen(__1n.n->__O2__4expr.string) + 1)),
                                  ((__1tci->malloc_hook__14tree_copy_info
                                        ? (*(__1tci->malloc_hook__14tree_copy_info))(
                                              __1tci->hook_info__14tree_copy_info, __2__X41)
                                        : (((char *)(((char *)__nw__FUl(
                                              (size_t)((sizeof(char)) * __2__X41)))))))));

                    strcpy(__4str_tmp,
                           (((struct expr *)(((struct expr *)((*__1node))))))->__O2__4expr.string);

                    __1n.n->__O2__4expr.string = (const char *)__4str_tmp;
                }
            }
            if ((discriminator__4exprFi(__1n.x, 2) == 3) && __1n.n->__O3__4expr.string2) {
                char *__3str_tmp;

                unsigned long __2__X42;

                __3str_tmp = ((__2__X42 = (strlen(__1n.n->__O3__4expr.string2) + 1)),
                              ((__1tci->malloc_hook__14tree_copy_info
                                    ? (*(__1tci->malloc_hook__14tree_copy_info))(
                                          __1tci->hook_info__14tree_copy_info, __2__X42)
                                    : (((char *)(((char *)__nw__FUl(
                                          (size_t)((sizeof(char)) * __2__X42)))))))));

                strcpy(__3str_tmp,
                       (((struct expr *)(((struct expr *)((*__1node))))))->__O3__4expr.string2);

                __1n.n->__O3__4expr.string2 = (const char *)__3str_tmp;
            }
            if (__1n.n->n_anon__4name) {
                char *__3str_tmp;

                unsigned long __2__X43;

                __3str_tmp = ((__2__X43 = (strlen(__1n.n->n_anon__4name) + 1)),
                              ((__1tci->malloc_hook__14tree_copy_info
                                    ? (*(__1tci->malloc_hook__14tree_copy_info))(
                                          __1tci->hook_info__14tree_copy_info, __2__X43)
                                    : (((char *)(((char *)__nw__FUl(
                                          (size_t)((sizeof(char)) * __2__X43)))))))));

                strcpy(__3str_tmp,
                       (((struct name *)(((struct name *)((*__1node))))))->n_anon__4name);

                __1n.n->n_anon__4name = (const char *)__3str_tmp;
            }
            if (__1n.n->n_template_arg_string__4name) {
                unsigned long __2__X44;

                __1n.n->n_template_arg_string__4name =
                    ((__2__X44 = (strlen((const char *)__1n.n->n_template_arg_string__4name) + 1)),
                     ((__1tci->malloc_hook__14tree_copy_info
                           ? (*(__1tci->malloc_hook__14tree_copy_info))(
                                 __1tci->hook_info__14tree_copy_info, __2__X44)
                           : (((char *)((
                                 (char *)__nw__FUl((size_t)((sizeof(char)) * __2__X44)))))))));
                strcpy(__1n.n->n_template_arg_string__4name,
                       (const char *)(((struct name *)(((struct name *)((*__1node))))))
                           ->n_template_arg_string__4name);
            }
        }
Replace:
    ((*__1node)) = __1n.node;
    ((*__1action)) = 0;
    return;
}

static int call_error__FiPCc(int __1i, const char *__1s) { return error__FiPCc(__1i, __1s); }

extern int walk_tree__FR17tree_walk_controlRP4node(struct tree_walk_control *__0c, Pnode *__0n);

void copy_tree__FRP4nodeR14tree_copy_infoP4Hash(Pnode *__1node, struct tree_copy_info *__1tci,
                                                struct Hash *__1cht) {
    struct tree_walk_control __1twc;

    (((((&__1twc)->version__17tree_walk_control = 1),
       (((&__1twc)->callback_info__17tree_walk_control = 0),
        (((&__1twc)->fetcher__17tree_walk_control = null_tfp),
         (((&__1twc)->call_i_error__17tree_walk_control = 0),
          (((&__1twc)->nodes_seen_hash__17tree_walk_control = 0),
           (((&__1twc)->resolve_by_name__17tree_walk_control = 1),
            (((&__1twc)->alloc_stack_bytes__17tree_walk_control = 0),
             (((&__1twc)->post_action_proc__17tree_walk_control = 0),
              ((&__1twc)->dont_chase_lists_top__17tree_walk_control = 0)))))))))),
     (&__1twc));

    __1twc.call_i_error__17tree_walk_control = 1;
    __1twc.i_error__17tree_walk_control = (call_error__FiPCc);
    __1twc.action_proc__17tree_walk_control =
        (copy_walker__FRP4node10node_classPvR16tree_node_actioniP4nodeR14tree_walk_treeRi);
    __1twc.nodes_seen_hash__17tree_walk_control = __1cht;
    __1twc.callback_info__17tree_walk_control = (((void *)(__1tci)));

    walk_tree__FR17tree_walk_controlRP4node((struct tree_walk_control *)(&__1twc), __1node);
}

extern struct Hash *ht__10patch_tree;

extern Ppatch_tree head__10patch_tree;

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
