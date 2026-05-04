
/* <<AT&T C++ Language System <3.0.3> 05/05/94>> */
extern char __cfront_version_303_xxxxxxxx;

#pragma lib "ape/libap.a"

void *__vec_new(void *, int, int, void *);

void __vec_delete(void *, int, int, void *, int, int);
typedef int (*__vptp)(void);
struct __mptr {
    short d;
    short i;
    __vptp f;
};

extern struct __mptr *__ptbl_vec___[];

#include <stddef.h>

typedef int (*GPT)(int, char *);

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

typedef size_t Bits_chunk;

struct Block_Bits_chunk;

struct Block_Bits_chunk { /* sizeof Block_Bits_chunk == 16 */

    Bits_chunk *p__16Block_Bits_chunk;

    size_t n__16Block_Bits_chunk;
};

void move__16Block_Bits_chunkFPUlUl(struct Block_Bits_chunk *__0this, Bits_chunk *, size_t);

extern void *__nw__FUl(size_t);

void copy__16Block_Bits_chunkFRC16Block_Bits_chunk(struct Block_Bits_chunk *__0this,
                                                   const struct Block_Bits_chunk *);

extern void __dl__FPv(void *);

size_t grow__16Block_Bits_chunkFUl(struct Block_Bits_chunk *__0this, size_t);
struct Bits;

struct Bits { /* sizeof Bits == 24 */

    struct Block_Bits_chunk b__4Bits;
    size_t n__4Bits;
};

size_t signif__4BitsCFv(const struct Bits *const __0this);

size_t size__4BitsFUl(struct Bits *__0this, size_t);

int compare__4BitsCFRC4Bits(const struct Bits *const __0this, const struct Bits *);
int equal__4BitsCFRC4Bits(const struct Bits *const __0this, const struct Bits *);

static Bits_chunk Block_Bits_chunk_def;

void clear__16Block_Bits_chunkFPUlUl(struct Block_Bits_chunk *__0this, Bits_chunk *__1v,
                                     size_t __1k) {
    Bits_chunk *__1p;

    Bits_chunk *__1lim;

    __1p = __1v;

    __1lim = (__1v + __1k);

    while (__1p < __1lim)
        ((*(__1p++))) = Block_Bits_chunk_def;
}

void transfer__16Block_Bits_chunkFPUlUl(struct Block_Bits_chunk *__0this, Bits_chunk *, size_t);

void copy__16Block_Bits_chunkFRC16Block_Bits_chunk(register struct Block_Bits_chunk *__0this,
                                                   const struct Block_Bits_chunk *__1b) {
    __0this->p__16Block_Bits_chunk = (((size_t *)__nw__FUl(
        (unsigned long)((sizeof(unsigned long)) * ((*__1b)).n__16Block_Bits_chunk))));

    if (__0this->p__16Block_Bits_chunk) {
        __0this->n__16Block_Bits_chunk = ((*__1b)).n__16Block_Bits_chunk;

        transfer__16Block_Bits_chunkFPUlUl(__0this, (Bits_chunk *)((*__1b)).p__16Block_Bits_chunk,
                                           __0this->n__16Block_Bits_chunk);

    } else
        __0this->n__16Block_Bits_chunk = 0;
}

size_t grow__16Block_Bits_chunkFUl(register struct Block_Bits_chunk *__0this, size_t __1k) {
    size_t __1nn;

    __1nn = __0this->n__16Block_Bits_chunk;

    if (__1nn == 0)
        __1nn++;

    while (__1nn <= __1k)
        __1nn += ((__1nn >> 1) + 1);

    {
        Bits_chunk *__1np;

        __1np = (((size_t *)__nw__FUl((size_t)((sizeof(size_t)) * __1nn))));

        if (!__1np) {
            __1nn = (__1k + 1);

            __1np = (((size_t *)__nw__FUl((size_t)((sizeof(size_t)) * __1nn))));
        }

        move__16Block_Bits_chunkFPUlUl(__0this, __1np, __1nn);

        return __0this->n__16Block_Bits_chunk;
    }
}

void transfer__16Block_Bits_chunkFPUlUl(register struct Block_Bits_chunk *__0this,
                                        Bits_chunk *__1source, size_t __1len) {
    Bits_chunk *__1plim;

    Bits_chunk *__1pp;

    Bits_chunk *__1q;

    __1pp = __0this->p__16Block_Bits_chunk;

    __1q = __1source;

    if (__0this->n__16Block_Bits_chunk > __1len) {
        __1plim = (__0this->p__16Block_Bits_chunk + __1len);

        clear__16Block_Bits_chunkFPUlUl(__0this, __1plim, __0this->n__16Block_Bits_chunk - __1len);

    } else
        __1plim = (__0this->p__16Block_Bits_chunk + __0this->n__16Block_Bits_chunk);

    while (__1pp < __1plim)
        ((*(__1pp++))) = ((*(__1q++)));
}

void move__16Block_Bits_chunkFPUlUl(register struct Block_Bits_chunk *__0this, Bits_chunk *__1np,
                                    size_t __1nn) {
    Bits_chunk *__1oldp;

    size_t __1oldn;

    __1oldp = __0this->p__16Block_Bits_chunk;

    __1oldn = __0this->n__16Block_Bits_chunk;

    __0this->p__16Block_Bits_chunk = __1np;

    if (__1np) {
        __0this->n__16Block_Bits_chunk = __1nn;

        transfer__16Block_Bits_chunkFPUlUl(__0this, __1oldp, __1oldn);

    } else
        __0this->n__16Block_Bits_chunk = 0;

    __dl__FPv((void *)__1oldp);
}

void swap__16Block_Bits_chunkFR16Block_Bits_chunk(register struct Block_Bits_chunk *__0this,
                                                  struct Block_Bits_chunk *__1b) {
    Bits_chunk *__1bp;

    size_t __1bn;

    __1bp = ((*__1b)).p__16Block_Bits_chunk;

    __1bn = ((*__1b)).n__16Block_Bits_chunk;

    ((*__1b)).p__16Block_Bits_chunk = __0this->p__16Block_Bits_chunk;

    ((*__1b)).n__16Block_Bits_chunk = __0this->n__16Block_Bits_chunk;

    __0this->p__16Block_Bits_chunk = __1bp;

    __0this->n__16Block_Bits_chunk = __1bn;
}

struct Bits *__ct__4BitsFUlT1(register struct Bits *__0this, Bits_chunk __1val, size_t __1ct) {
    struct Block_Bits_chunk *__0__X21;

    struct Block_Bits_chunk *__0__X22;

    if (__0this || (__0this = (struct Bits *)__nw__FUl((size_t)(sizeof(struct Bits))))) {
        ((__0__X21 = (&__0this->b__4Bits)),
         (((__0__X21 || (__0__X21 = (struct Block_Bits_chunk *)__nw__FUl(
                             (size_t)(sizeof(struct Block_Bits_chunk)))))
               ? ((__0__X21->n__16Block_Bits_chunk = 0), (__0__X21->p__16Block_Bits_chunk = 0))
               : 0),
          __0__X21));
        if (__1ct < 32) {
            Bits_chunk __2mask;

            __2mask = ((~(((unsigned long)0))) << __1ct);
            while (__1val & __2mask) {
                __1ct++;
                __2mask <<= 1;
            }
        }
        if (size__4BitsFUl(__0this, __1ct))
            ((*((__0__X22 = (&__0this->b__4Bits)), (__0__X22->p__16Block_Bits_chunk)))) = __1val;
    }
    return __0this;
}

size_t size__4BitsFUl(register struct Bits *__0this, size_t __1x) {
    size_t __1newsize;

    const struct Block_Bits_chunk *__0__X23;

    struct Block_Bits_chunk *__0__X24;

    const struct Block_Bits_chunk *__0__X25;

    int __2__Xct00qunsoejpvcdp;

    unsigned long __2__X6;

    struct Block_Bits_chunk *__0__X7;

    int __2__X8;

    __1newsize = ((((__1x + 32) - 1) >> 5));
    if (((__0__X23 = (const struct Block_Bits_chunk *)(&__0this->b__4Bits)),
         (__0__X23->n__16Block_Bits_chunk)) != __1newsize)
        ((__0__X24 = (&__0this->b__4Bits)),
         (move__16Block_Bits_chunkFPUlUl(__0__X24,
                                         (Bits_chunk *)(((unsigned long *)__nw__FUl(
                                             (size_t)((sizeof(unsigned long)) * __1newsize)))),
                                         __1newsize),
          __0__X24->n__16Block_Bits_chunk));
    __0this->n__4Bits = (((__0__X25 = (const struct Block_Bits_chunk *)(&__0this->b__4Bits)),
                          (__0__X25->n__16Block_Bits_chunk))
                             ? __1x
                             : (((unsigned long)0)));

    (((__2__Xct00qunsoejpvcdp = (__0this->n__4Bits & 31)),
      (__2__Xct00qunsoejpvcdp
           ? (((*((__0__X7 = (&__0this->b__4Bits)),
                  ((__2__X8 = ((__2__X6 = __0this->n__4Bits), ((__2__X6 >> 5)))),
                   ((((Bits_chunk *)(&(__0__X7->p__16Block_Bits_chunk[__2__X8]))))))))) &=
              (~((~(((unsigned long)0))) << __2__Xct00qunsoejpvcdp)))
           : 0)),
     (((void)0)));

    return __0this->n__4Bits;
}

struct Bits *__aad__4BitsFRC4Bits(register struct Bits *__0this, const struct Bits *__1x) {
    if ((((const struct Bits *)__0this)->n__4Bits) < (((const struct Bits *)__1x)->n__4Bits))
        size__4BitsFUl(__0this, (((const struct Bits *)__1x)->n__4Bits));

    {
        Bits_chunk *__1p;
        const Bits_chunk *__1q;
        const Bits_chunk *__1lim;

        struct Block_Bits_chunk *__0__X2;

        unsigned long __2__X3;

        struct Block_Bits_chunk *__0__X26;

        const struct Block_Bits_chunk *__0__X27;

        const struct Block_Bits_chunk *__0__X4;

        unsigned long __2__X5;

        __1p = ((__0__X26 = (&__0this->b__4Bits)), (__0__X26->p__16Block_Bits_chunk));
        __1q = ((__0__X27 = (const struct Block_Bits_chunk *)(&((*__1x)).b__4Bits)),
                (__0__X27->p__16Block_Bits_chunk));
        __1lim = ((
            ((__0__X4 = (const struct Block_Bits_chunk *)(&((const struct Bits *)__1x)->b__4Bits)),
             (__0__X4->p__16Block_Bits_chunk)) +
            ((__2__X5 = ((const struct Bits *)__1x)->n__4Bits), ((((__2__X5 + 32) - 1) >> 5)))));

        while (__1q < __1lim)
            ((*(__1p++))) &= ((*(__1q++)));

        __1lim = (const Bits_chunk *)((
            ((__0__X2 = (&__0this->b__4Bits)), (__0__X2->p__16Block_Bits_chunk)) +
            ((__2__X3 = __0this->n__4Bits), ((((__2__X3 + 32) - 1) >> 5)))));
        while (__1p < (Bits_chunk *)__1lim)
            ((*(__1p++))) = 0;

        return (struct Bits *)__0this;
    }
}

struct Bits *__aor__4BitsFRC4Bits(register struct Bits *__0this, const struct Bits *__1x) {
    if ((((const struct Bits *)__0this)->n__4Bits) < (((const struct Bits *)__1x)->n__4Bits))
        size__4BitsFUl(__0this, (((const struct Bits *)__1x)->n__4Bits));

    {
        Bits_chunk *__1p;
        const Bits_chunk *__1q;
        const Bits_chunk *__1lim;

        struct Block_Bits_chunk *__0__X28;

        const struct Block_Bits_chunk *__0__X29;

        const struct Block_Bits_chunk *__0__X4;

        unsigned long __2__X5;

        __1p = ((__0__X28 = (&__0this->b__4Bits)), (__0__X28->p__16Block_Bits_chunk));
        __1q = ((__0__X29 = (const struct Block_Bits_chunk *)(&((*__1x)).b__4Bits)),
                (__0__X29->p__16Block_Bits_chunk));
        __1lim = ((
            ((__0__X4 = (const struct Block_Bits_chunk *)(&((const struct Bits *)__1x)->b__4Bits)),
             (__0__X4->p__16Block_Bits_chunk)) +
            ((__2__X5 = ((const struct Bits *)__1x)->n__4Bits), ((((__2__X5 + 32) - 1) >> 5)))));

        while (__1q < __1lim)
            ((*(__1p++))) |= ((*(__1q++)));

        return (struct Bits *)__0this;
    }
}

struct Bits *__aer__4BitsFRC4Bits(register struct Bits *__0this, const struct Bits *__1x) {
    if ((((const struct Bits *)__0this)->n__4Bits) < (((const struct Bits *)__1x)->n__4Bits))
        size__4BitsFUl(__0this, (((const struct Bits *)__1x)->n__4Bits));

    {
        Bits_chunk *__1p;
        const Bits_chunk *__1q;
        const Bits_chunk *__1lim;

        struct Block_Bits_chunk *__0__X30;

        const struct Block_Bits_chunk *__0__X31;

        const struct Block_Bits_chunk *__0__X4;

        unsigned long __2__X5;

        __1p = ((__0__X30 = (&__0this->b__4Bits)), (__0__X30->p__16Block_Bits_chunk));
        __1q = ((__0__X31 = (const struct Block_Bits_chunk *)(&((*__1x)).b__4Bits)),
                (__0__X31->p__16Block_Bits_chunk));
        __1lim = ((
            ((__0__X4 = (const struct Block_Bits_chunk *)(&((const struct Bits *)__1x)->b__4Bits)),
             (__0__X4->p__16Block_Bits_chunk)) +
            ((__2__X5 = ((const struct Bits *)__1x)->n__4Bits), ((((__2__X5 + 32) - 1) >> 5)))));

        while (__1q < __1lim)
            ((*(__1p++))) ^= ((*(__1q++)));

        return (struct Bits *)__0this;
    }
}

struct Bits *compl4__4BitsFv(register struct Bits *__0this) {
    Bits_chunk *__1p;
    const Bits_chunk *__1lim;

    int __2__Xct00qunsoejpvcdp;

    unsigned long __2__X6;

    struct Block_Bits_chunk *__0__X7;

    int __2__X8;

    struct Block_Bits_chunk *__0__X32;

    struct Block_Bits_chunk *__0__X2;

    unsigned long __2__X3;

    __1p = ((__0__X32 = (&__0this->b__4Bits)), (__0__X32->p__16Block_Bits_chunk));
    __1lim =
        (const Bits_chunk *)((((__0__X2 = (&__0this->b__4Bits)), (__0__X2->p__16Block_Bits_chunk)) +
                              ((__2__X3 = __0this->n__4Bits), ((((__2__X3 + 32) - 1) >> 5)))));

    while (__1p < (Bits_chunk *)__1lim) {
        ((*__1p)) = (~((*__1p)));
        __1p++;
    }

    (((__2__Xct00qunsoejpvcdp = (__0this->n__4Bits & 31)),
      (__2__Xct00qunsoejpvcdp
           ? (((*((__0__X7 = (&__0this->b__4Bits)),
                  ((__2__X8 = ((__2__X6 = __0this->n__4Bits), ((__2__X6 >> 5)))),
                   ((((Bits_chunk *)(&(__0__X7->p__16Block_Bits_chunk[__2__X8]))))))))) &=
              (~((~(((unsigned long)0))) << __2__Xct00qunsoejpvcdp)))
           : 0)),
     (((void)0)));

    return (struct Bits *)__0this;
}

size_t count__4BitsCFv(register const struct Bits *const __0this) {
    const Bits_chunk *__1p;
    const Bits_chunk *__1lim;
    size_t __1r;

    const struct Block_Bits_chunk *__0__X33;

    const struct Block_Bits_chunk *__0__X4;

    unsigned long __2__X5;

    __1p = ((__0__X33 = (const struct Block_Bits_chunk *)(&__0this->b__4Bits)),
            (__0__X33->p__16Block_Bits_chunk));
    __1lim = ((((__0__X4 = (const struct Block_Bits_chunk *)(&__0this->b__4Bits)),
                (__0__X4->p__16Block_Bits_chunk)) +
               ((__2__X5 = __0this->n__4Bits), ((((__2__X5 + 32) - 1) >> 5)))));
    __1r = 0;

    while (__1p < __1lim) {
        size_t __2x;
        int __2i;

        __2x = ((*(__1p++)));
        __2i = 32;

        while ((--__2i) >= 0) {
            if (__2x & 1)
                __1r++;
            __2x >>= 1;
        }
    }

    return __1r;
}

void __co__FRC4Bits(struct Bits *__0_result, const struct Bits *__1x) {
    struct Block_Bits_chunk *__0__X35;

    const struct Block_Bits_chunk *__2__X36;

    ((((((__0__X35 = (&__0_result->b__4Bits)),
         ((__2__X36 = (const struct Block_Bits_chunk *)(&((*__1x)).b__4Bits)),
          (((__0__X35 || (__0__X35 = (struct Block_Bits_chunk *)__nw__FUl(
                              (size_t)(sizeof(struct Block_Bits_chunk)))))
                ? (((void)copy__16Block_Bits_chunkFRC16Block_Bits_chunk(__0__X35, __2__X36)))
                : (((void)0))),
           __0__X35))),
        (__0_result->n__4Bits = ((*__1x)).n__4Bits)),
       0)),
     __0_result);
    compl4__4BitsFv(__0_result);
    {
        ;

        return;
    }
}

int compare__4BitsCFRC4Bits(register const struct Bits *const __0this, const struct Bits *__1x) {
    int __1w;
    int __1xw;
    int __1len;

    int __1r;
    const Bits_chunk *__1p;
    const Bits_chunk *__1q;
    const Bits_chunk *__1lim;

    const struct Block_Bits_chunk *__0__X41;

    const struct Block_Bits_chunk *__0__X42;

    const struct Block_Bits_chunk *__0__X43;

    unsigned long __2__X44;

    unsigned long __2__X45;

    __1w = ((__2__X44 = (__0this->n__4Bits)), ((((__2__X44 + 32) - 1) >> 5)));

    __1xw = ((__2__X45 = (((const struct Bits *)__1x)->n__4Bits)), ((((__2__X45 + 32) - 1) >> 5)));

    if ((__1w == 0) && (__1xw == 0))
        return 0;

    if (__1w == 0)
        return -1;
    if (__1xw == 0)
        return 1;

    if (__1w != __1xw) {
        if (__1w > __1xw) {
            const struct Block_Bits_chunk *__0__X37;

            const struct Block_Bits_chunk *__0__X38;

            __1len = __1xw;
            __1p = (((__0__X37 = (const struct Block_Bits_chunk *)(&__0this->b__4Bits)),
                     ((((const Bits_chunk *)(&(__0__X37->p__16Block_Bits_chunk[__1len])))))));
            __1q = (((__0__X38 = (const struct Block_Bits_chunk *)(&__0this->b__4Bits)),
                     ((((const Bits_chunk *)(&(__0__X38->p__16Block_Bits_chunk[__1w])))))));
            __1r = 1;
        } else {
            const struct Block_Bits_chunk *__0__X39;

            const struct Block_Bits_chunk *__0__X40;

            __1len = __1w;
            __1p = (((__0__X39 = (const struct Block_Bits_chunk *)(&((*__1x)).b__4Bits)),
                     ((((const Bits_chunk *)(&(__0__X39->p__16Block_Bits_chunk[__1len])))))));
            __1q = (((__0__X40 = (const struct Block_Bits_chunk *)(&((*__1x)).b__4Bits)),
                     ((((const Bits_chunk *)(&(__0__X40->p__16Block_Bits_chunk[__1xw])))))));
            __1r = -1;
        }

        do {
            if ((*(__1p++)))
                return __1r;
        } while (__1p < __1q);

    } else
        __1len = __1w;

    __1p = (((__0__X41 = (const struct Block_Bits_chunk *)(&__0this->b__4Bits)),
             (__0__X41->p__16Block_Bits_chunk)) +
            __1len);

    __1q = (((__0__X42 = (const struct Block_Bits_chunk *)(&((*__1x)).b__4Bits)),
             (__0__X42->p__16Block_Bits_chunk)) +
            __1len);

    __1lim = ((__0__X43 = (const struct Block_Bits_chunk *)(&__0this->b__4Bits)),
              (__0__X43->p__16Block_Bits_chunk));
    while (__1p > __1lim) {
        if (((*(--__1p))) != ((*(--__1q))))
            return ((((*__1p)) < ((*__1q))) ? -1 : 1);
    }

    return ((((int)(__0this->n__4Bits))) - (((int)(((const struct Bits *)__1x)->n__4Bits))));
}

int equal__4BitsCFRC4Bits(register const struct Bits *const __0this, const struct Bits *__1x) {
    if ((__0this->n__4Bits) != (((const struct Bits *)__1x)->n__4Bits))
        return 0;

    if ((__0this->n__4Bits) == 0)
        return 1;

    return (compare__4BitsCFRC4Bits(__0this, __1x) == 0);
}

struct Bits *__ars__4BitsFi(struct Bits *__0this, int);

struct Bits *__als__4BitsFi(register struct Bits *__0this, int __1k) {
    if (__1k <= 0) {
        if (__1k < 0)
            __ars__4BitsFi(__0this, -__1k);
        return (struct Bits *)__0this;
    }

    if (size__4BitsFUl(__0this, (((const struct Bits *)__0this)->n__4Bits) + __1k) == 0)
        return (struct Bits *)__0this;

    {
        Bits_chunk *__1lim;

        int __1chunkoffset;

        struct Block_Bits_chunk *__0__X46;

        __1lim = ((__0__X46 = (&__0this->b__4Bits)), (__0__X46->p__16Block_Bits_chunk));

        __1chunkoffset = (__1k >> 5);
        if (__1chunkoffset) {
            Bits_chunk *__2dest;
            Bits_chunk *__2src;

            struct Block_Bits_chunk *__0__X2;

            unsigned long __2__X3;

            __2dest = ((((__0__X2 = (&__0this->b__4Bits)), (__0__X2->p__16Block_Bits_chunk)) +
                        ((__2__X3 = __0this->n__4Bits), ((((__2__X3 + 32) - 1) >> 5)))));
            __2src = (__2dest - __1chunkoffset);

            do
                ((*(--__2dest))) = ((*(--__2src)));
            while (__2src > __1lim);

            do
                ((*(--__2dest))) = 0;
            while (__2dest > __1lim);
        }

        {
            int __1bitoffset;

            int __2__Xct00qunsoejpvcdp;

            unsigned long __2__X6;

            struct Block_Bits_chunk *__0__X7;

            int __2__X8;

            __1bitoffset = (__1k & 31);
            if (__1bitoffset) {
                Bits_chunk *__2p;
                int __2compoffset;

                struct Block_Bits_chunk *__0__X2;

                unsigned long __2__X3;

                __2p = ((((__0__X2 = (&__0this->b__4Bits)), (__0__X2->p__16Block_Bits_chunk)) +
                         ((__2__X3 = __0this->n__4Bits), ((((__2__X3 + 32) - 1) >> 5)))));
                __2compoffset = (32 - __1bitoffset);

                while ((--__2p) > __1lim)
                    ((*__2p)) = ((((*__2p)) << __1bitoffset) | (((*(__2p - 1))) >> __2compoffset));

                ((*__1lim)) <<= __1bitoffset;
            }

            (((__2__Xct00qunsoejpvcdp = (__0this->n__4Bits & 31)),
              (__2__Xct00qunsoejpvcdp
                   ? (((*((__0__X7 = (&__0this->b__4Bits)),
                          ((__2__X8 = ((__2__X6 = __0this->n__4Bits), ((__2__X6 >> 5)))),
                           ((((Bits_chunk *)(&(__0__X7->p__16Block_Bits_chunk[__2__X8]))))))))) &=
                      (~((~(((unsigned long)0))) << __2__Xct00qunsoejpvcdp)))
                   : 0)),
             (((void)0)));

            return (struct Bits *)__0this;
        }
    }
}

struct Bits *__ars__4BitsFi(register struct Bits *__0this, int __1k) {
    if (__1k <= 0) {
        if (__1k < 0)
            __als__4BitsFi(__0this, -__1k);
        return (struct Bits *)__0this;
    }

    {
        int __1newsize;

        __1newsize = ((((const struct Bits *)__0this)->n__4Bits) - __1k);
        if (__1newsize <= 0) {
            size__4BitsFUl(__0this, (unsigned long)0);
            return (struct Bits *)__0this;
        }

        {
            int __1chunkoffset;

            __1chunkoffset = (__1k >> 5);
            if (__1chunkoffset) {
                Bits_chunk *__2dest;
                Bits_chunk *__2src;
                const Bits_chunk *__2lim;

                struct Block_Bits_chunk *__0__X47;

                struct Block_Bits_chunk *__0__X2;

                unsigned long __2__X3;

                __2dest = ((__0__X47 = (&__0this->b__4Bits)), (__0__X47->p__16Block_Bits_chunk));
                __2src = (__2dest + __1chunkoffset);
                __2lim = (const Bits_chunk *)((
                    ((__0__X2 = (&__0this->b__4Bits)), (__0__X2->p__16Block_Bits_chunk)) +
                    ((__2__X3 = __0this->n__4Bits), ((((__2__X3 + 32) - 1) >> 5)))));

                do
                    ((*(__2dest++))) = ((*(__2src++)));
                while (__2src < (Bits_chunk *)__2lim);
            }

            {
                int __1bitoffset;

                __1bitoffset = (__1k & 31);
                if (__1bitoffset) {
                    Bits_chunk *__2p;
                    Bits_chunk *__2lim;
                    int __2compoffset;

                    struct Block_Bits_chunk *__0__X2;

                    unsigned long __2__X3;

                    struct Block_Bits_chunk *__0__X48;

                    __2p = ((__0__X48 = (&__0this->b__4Bits)), (__0__X48->p__16Block_Bits_chunk));
                    __2lim = (__2p + ((((unsigned long)(__1newsize - 1)) >> 5)));
                    __2compoffset = (32 - __1bitoffset);

                    while (__2p < __2lim) {
                        ((*__2p)) =
                            ((((*__2p)) >> __1bitoffset) | (((*(__2p + 1))) << __2compoffset));
                        __2p++;
                    }

                    ((*__2lim)) >>= __1bitoffset;
                    if ((__2lim + 1) <
                        ((((__0__X2 = (&__0this->b__4Bits)), (__0__X2->p__16Block_Bits_chunk)) +
                          ((__2__X3 = __0this->n__4Bits), ((((__2__X3 + 32) - 1) >> 5))))))
                        ((*__2lim)) |= (((*(__2lim + 1))) << __2compoffset);
                }

                size__4BitsFUl(__0this, (unsigned long)__1newsize);

                return (struct Bits *)__0this;
            }
        }
    }
}

size_t signif__4BitsCFv(register const struct Bits *const __0this) {
    if ((__0this->n__4Bits) == 0)
        return (unsigned long)0;

    {
        const Bits_chunk *__1p;
        const Bits_chunk *__1lim;

        const struct Block_Bits_chunk *__0__X4;

        unsigned long __2__X5;

        const struct Block_Bits_chunk *__0__X49;

        __1p = ((((__0__X4 = (const struct Block_Bits_chunk *)(&__0this->b__4Bits)),
                  (__0__X4->p__16Block_Bits_chunk)) +
                 ((__2__X5 = __0this->n__4Bits), ((((__2__X5 + 32) - 1) >> 5)))));
        __1lim = ((__0__X49 = (const struct Block_Bits_chunk *)(&__0this->b__4Bits)),
                  (__0__X49->p__16Block_Bits_chunk));

        while ((--__1p) >= __1lim) {
            if ((*__1p)) {
                Bits_chunk __3x;
                int __3k;

                __3x = ((*__1p));
                __3k = 32;

                while ((--__3k) >= 0) {
                    if (__3x & ((((unsigned long)1)) << __3k))
                        return (unsigned long)((__3k + 1) + (32 * (__1p - __1lim)));
                }
            }
        }

        return (unsigned long)0;
    }
}

struct Bits *concat__4BitsFRC4Bits(register struct Bits *__0this, const struct Bits *__1x) {
    __als__4BitsFi(__0this, (int)(((const struct Bits *)__1x)->n__4Bits));
    __aor__4BitsFRC4Bits(__0this, __1x);
    return (struct Bits *)__0this;
}

/* the end */
