/*
 * Common declarations emitted into most cfront-translated C files.
 *
 * Keep this header in translated-C form: the surrounding .c files are not
 * including the original C++ headers, and Plan 9 APE must be able to compile
 * this as plain C.
 */
#ifndef CFRONT_TRANSLATED_H
#define CFRONT_TRANSLATED_H

#include <stddef.h>
#ifdef __linux__
/* APE's <stddef.h> defines ssize_t; the Linux host header does not. */
typedef long ssize_t;
#endif

void *__vec_new(void *, int, int, void *);
void __vec_delete(void *, int, int, void *, int, int);

typedef int (*__vptp)(void);
struct __mptr {
    short d;
    short i;
    __vptp f;
};

extern struct __mptr *__ptbl_vec___[];

extern char *sys_errlist[];
extern int sys_nerr;
extern unsigned char *_bufendtab[];

typedef int (*GPT)(int, char *);

extern const char *keys[256];

typedef unsigned char TOK;
typedef unsigned char bit;
struct node;
typedef struct node *PP;
typedef int (*PFI)(void);
typedef void (*PFV)(void);
typedef struct node *Pnode;
struct key;
typedef struct key *Pkey;
struct name;
typedef struct name *Pname;
struct basetype;
typedef struct basetype *Pbase;
struct basecl;
typedef struct basecl *Pbcl;
struct type;
typedef struct type *Ptype;
struct fct;
typedef struct fct *Pfct;
struct field;
typedef struct field *Pfield;
struct expr;
typedef struct expr *Pexpr;
struct qexpr;
typedef struct qexpr *Pqexpr;
struct texpr;
typedef struct texpr *Ptexpr;
struct classdef;
typedef struct classdef *Pclass;
struct enumdef;
typedef struct enumdef *Penum;
struct stmt;
typedef struct stmt *Pstmt;
struct estmt;
typedef struct estmt *Pestmt;
struct tstmt;
typedef struct tstmt *Ptstmt;
struct vec;
typedef struct vec *Pvec;
struct ptr;
typedef struct ptr *Pptr;
struct block;
typedef struct block *Pblock;
struct table;
typedef struct table *Ptable;
struct ktable;
typedef struct ktable *Pktab;
struct loc;
typedef struct loc Loc;
struct call;
typedef struct call *Pcall;
struct gen;
typedef struct gen *Pgen;
struct ref;
typedef struct ref *Pref;
struct name_list;
typedef struct name_list *Plist;
struct iline;
typedef struct iline *Pin;
struct ia;
typedef struct ia *Pia;
struct nlist;
typedef struct nlist *Pnlist;
struct slist;
typedef struct slist *Pslist;
struct elist;
typedef struct elist *Pelist;
struct virt;
typedef struct virt *Pvirt;
typedef char *Pchar;
typedef const char *CPchar;

extern const char *prog_name;
extern int inline_restr;

extern Pname dummy_fct;

struct loc { /* sizeof loc == 4 */
    short file__3loc;
    short line__3loc;
};

extern struct loc curloc;
extern int curr_file;

extern const char *src_file_name;
extern struct loc noloc;
extern bit binary_val;
extern bit stmtno;
extern Ptable tmp_tbl;
extern Ptable bound_expr_tbl;
struct ea;
union __Q2_2ea4__C1;

union __Q2_2ea4__C1 { /* sizeof __Q2_2ea4__C1 == 8 */
    const void *p;
    size_t i;
};

struct ea { /* sizeof ea == 8 */
    union __Q2_2ea4__C1 __O1__2ea;
};

extern void *__nw__FUl(size_t);

extern struct ea *ea0;

extern char emode;

extern int error_count;
extern int vtbl_opt;
extern int debug_opt;
extern int warning_opt;
extern int ansi_opt;
extern int pt_opt;
extern int perf_opt;
extern int dtpt_opt;
extern int se_opt;
extern int strict_opt;
extern void *out_file;
extern void *in_file;
extern void *pt_file;
extern void *dtpt_file;
extern char scan_started;

extern int bl_level;

extern Pktab Gtbl;
extern Pktab Ctbl;

extern Ptable gtbl;
extern Ptable ptbl;

extern Pname def_name;
extern Pname pdef_name;
extern Pclass ccl;
extern Pbase defa_type;
extern Pbase moe_type;
extern Pbase mptr_type;

extern Pstmt Cstmt;
extern Pname Cdcl;

extern int largest_int;

extern Pbase any_type;
extern Pbase int_type;
extern Pbase char_type;
extern Pbase short_type;
extern Pbase long_type;
extern Pbase llong_type;
extern Pbase uint_type;
extern Pbase float_type;
extern Pbase double_type;
extern Pbase ldouble_type;
extern Pbase void_type;

extern Pbase uchar_type;
extern Pbase ushort_type;
extern Pbase ulong_type;
extern Pbase ullong_type;
extern Ptype Pchar_type;
extern Ptype Pint_type;
extern Ptype Pvptr_type;
extern Ptype Pfctvec_type;
extern Ptype Pvoid_type;
extern Pbase zero_type;
extern Ptype size_t_type;

extern int byte_offset;
extern int bit_offset;
extern int max_align;
extern int const_save;
extern bit const_problem;

extern Pexpr dummy;
extern Pexpr zero;
extern Pexpr one;
extern Pname sta_name;

#endif
