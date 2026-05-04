# 1 ""

/* <<AT&T C++ Language System <3.0.3> 05/05/94>> */
extern char __cfront_version_303_xxxxxxxx;

#pragma lib "ape/libap.a"

# 1 ""
void *__vec_new (void *, int , int , void *);

# 1 ""
void __vec_delete (void *, int , int , void *, int , int );
typedef int (*__vptp)(void);
struct __mptr {short d; short i; __vptp f; };

# 1 ""
extern struct __mptr* __ptbl_vec___[];

# 1 ""

# 20 "/home/claude/incl-linux32/generic.h"
typedef int (*GPT )(int , char *);

# 19 "/home/claude/cfront-3/src/typedef.h"
typedef unsigned char TOK ;
typedef unsigned char bit ;
struct node;
typedef struct node *PP ;
typedef int (*PFI )(void );
typedef void (*PFV )(void );
typedef struct node *Pnode ;
struct key;
typedef struct key *Pkey ;
struct name;
typedef struct name *Pname ;
struct basetype;
typedef struct basetype *Pbase ;
struct basecl;
typedef struct basecl *Pbcl ;
struct type;
typedef struct type *Ptype ;
struct fct;
typedef struct fct *Pfct ;
struct field;
typedef struct field *Pfield ;
struct expr;
typedef struct expr *Pexpr ;
struct qexpr;
typedef struct qexpr *Pqexpr ;
struct texpr;
typedef struct texpr *Ptexpr ;
struct classdef;
typedef struct classdef *Pclass ;
struct enumdef;
typedef struct enumdef *Penum ;
struct stmt;
typedef struct stmt *Pstmt ;
struct estmt;
typedef struct estmt *Pestmt ;
struct tstmt;
typedef struct tstmt *Ptstmt ;
struct vec;
typedef struct vec *Pvec ;
struct ptr;
typedef struct ptr *Pptr ;
struct block;
typedef struct block *Pblock ;
struct table;
typedef struct table *Ptable ;
struct ktable;
typedef struct ktable *Pktab ;
struct loc;
typedef struct loc Loc ;
struct call;
typedef struct call *Pcall ;
struct gen;
typedef struct gen *Pgen ;
struct ref;
typedef struct ref *Pref ;
struct name_list;
typedef struct name_list *Plist ;
struct iline;
typedef struct iline *Pin ;
struct ia;
typedef struct ia *Pia ;
struct nlist;
typedef struct nlist *Pnlist ;
struct slist;
typedef struct slist *Pslist ;
struct elist;
typedef struct elist *Pelist ;
struct virt;
typedef struct virt *Pvirt ;
typedef char *Pchar ;
typedef const char *CPchar ;

# 18 "/home/claude/incl-linux32/stddef.h"
typedef long ssize_t ;
typedef unsigned long size_t ;

# 22 "/home/claude/cfront-3/src/Bits.h"
typedef size_t Bits_chunk ;

# 24 "/home/claude/cfront-3/src/Bits.h"

# 25 "/home/claude/cfront-3/src/Bits.h"
struct Block_Bits_chunk;

# 27 "/home/claude/cfront-3/src/Bits.h"
struct Block_Bits_chunk {	/* sizeof Block_Bits_chunk == 16 */

# 27 "/home/claude/cfront-3/src/Bits.h"
Bits_chunk *p__16Block_Bits_chunk ;

# 27 "/home/claude/cfront-3/src/Bits.h"
size_t n__16Block_Bits_chunk ;
};

# 27 "/home/claude/cfront-3/src/Bits.h"
void move__16Block_Bits_chunkFPUlUl (struct Block_Bits_chunk *__0this , Bits_chunk *, size_t );

# 1 ""
extern void *__nw__FUl (size_t );

# 27 "/home/claude/cfront-3/src/Bits.h"
void copy__16Block_Bits_chunkFRC16Block_Bits_chunk (struct Block_Bits_chunk *__0this , const struct Block_Bits_chunk *);

# 1 ""
extern void __dl__FPv (void *);

# 27 "/home/claude/cfront-3/src/Bits.h"
size_t grow__16Block_Bits_chunkFUl (struct Block_Bits_chunk *__0this , size_t );
struct Bits;

# 29 "/home/claude/cfront-3/src/Bits.h"
struct Bits {	/* sizeof Bits == 24 */

# 31 "/home/claude/cfront-3/src/Bits.h"
struct Block_Bits_chunk b__4Bits ;
size_t n__4Bits ;
};

# 27 "/home/claude/cfront-3/src/Bits.h"

# 40 "/home/claude/cfront-3/src/Bits.h"

# 27 "/home/claude/cfront-3/src/Bits.h"

# 40 "/home/claude/cfront-3/src/Bits.h"

# 35 "/home/claude/cfront-3/src/Bits.h"

# 27 "/home/claude/cfront-3/src/Bits.h"

# 35 "/home/claude/cfront-3/src/Bits.h"

# 27 "/home/claude/cfront-3/src/Bits.h"

# 35 "/home/claude/cfront-3/src/Bits.h"

# 27 "/home/claude/cfront-3/src/Bits.h"

# 35 "/home/claude/cfront-3/src/Bits.h"

# 27 "/home/claude/cfront-3/src/Bits.h"

# 35 "/home/claude/cfront-3/src/Bits.h"

# 27 "/home/claude/cfront-3/src/Bits.h"

# 35 "/home/claude/cfront-3/src/Bits.h"

# 27 "/home/claude/cfront-3/src/Bits.h"

# 121 "/home/claude/cfront-3/src/Bits.h"
size_t signif__4BitsCFv (const struct Bits *const __0this );

# 67 "/home/claude/cfront-3/src/Bits.h"
size_t size__4BitsFUl (struct Bits *__0this , size_t );

# 27 "/home/claude/cfront-3/src/Bits.h"

# 60 "/home/claude/cfront-3/src/Bits.h"
int compare__4BitsCFRC4Bits (const struct Bits *const __0this , const struct Bits *);
int equal__4BitsCFRC4Bits (const struct Bits *const __0this , const struct Bits *);

# 26 "/home/claude/cfront-3/src/Bits.cpp"
static Bits_chunk Block_Bits_chunk_def ;

# 26 "/home/claude/cfront-3/src/Bits.cpp"
void clear__16Block_Bits_chunkFPUlUl (struct Block_Bits_chunk *__0this , Bits_chunk *__1v , size_t __1k ){ Bits_chunk *__1p ;

# 26 "/home/claude/cfront-3/src/Bits.cpp"
Bits_chunk *__1lim ;

# 26 "/home/claude/cfront-3/src/Bits.cpp"
__1p = __1v ;

# 26 "/home/claude/cfront-3/src/Bits.cpp"
__1lim = (__1v + __1k );

# 26 "/home/claude/cfront-3/src/Bits.cpp"
while (__1p < __1lim )((*(__1p ++ )))= Block_Bits_chunk_def ;

# 26 "/home/claude/cfront-3/src/Bits.cpp"
}

# 27 "/home/claude/cfront-3/src/Bits.h"
void transfer__16Block_Bits_chunkFPUlUl (struct Block_Bits_chunk *__0this , Bits_chunk *, size_t );

# 26 "/home/claude/cfront-3/src/Bits.cpp"
void copy__16Block_Bits_chunkFRC16Block_Bits_chunk (register struct Block_Bits_chunk *__0this , const struct Block_Bits_chunk *__1b ){ __0this -> p__16Block_Bits_chunk = (((unsigned long *)__nw__FUl ( (unsigned long
# 26 "/home/claude/cfront-3/src/Bits.cpp"
)((sizeof (unsigned long ))* ((*__1b )). n__16Block_Bits_chunk )) ));

# 26 "/home/claude/cfront-3/src/Bits.cpp"
if (__0this -> p__16Block_Bits_chunk ){ __0this -> n__16Block_Bits_chunk = ((*__1b )). n__16Block_Bits_chunk ;

# 26 "/home/claude/cfront-3/src/Bits.cpp"
transfer__16Block_Bits_chunkFPUlUl ( __0this , (Bits_chunk *)((*__1b )). p__16Block_Bits_chunk , __0this -> n__16Block_Bits_chunk ) ;

# 26 "/home/claude/cfront-3/src/Bits.cpp"
}
else 
# 26 "/home/claude/cfront-3/src/Bits.cpp"
__0this -> n__16Block_Bits_chunk = 0 ;

# 26 "/home/claude/cfront-3/src/Bits.cpp"
}

# 26 "/home/claude/cfront-3/src/Bits.cpp"
size_t grow__16Block_Bits_chunkFUl (register struct Block_Bits_chunk *__0this , size_t __1k ){ size_t __1nn ;

# 26 "/home/claude/cfront-3/src/Bits.cpp"
__1nn = __0this -> n__16Block_Bits_chunk ;

# 26 "/home/claude/cfront-3/src/Bits.cpp"
if (__1nn == 0 )__1nn ++ ;

# 26 "/home/claude/cfront-3/src/Bits.cpp"
while (__1nn <= __1k )__1nn += ((__1nn >> 1 )+ 1 );

# 26 "/home/claude/cfront-3/src/Bits.cpp"
{ Bits_chunk *__1np ;

# 26 "/home/claude/cfront-3/src/Bits.cpp"
__1np = (((unsigned long *)__nw__FUl ( (size_t)((sizeof (unsigned long ))* __1nn )) ));

# 26 "/home/claude/cfront-3/src/Bits.cpp"
if (! __1np ){ __1nn = (__1k + 1 );

# 26 "/home/claude/cfront-3/src/Bits.cpp"
__1np = (((unsigned long *)__nw__FUl ( (size_t)((sizeof (unsigned long ))* __1nn )) ));

# 26 "/home/claude/cfront-3/src/Bits.cpp"
}

# 26 "/home/claude/cfront-3/src/Bits.cpp"
move__16Block_Bits_chunkFPUlUl ( __0this , __1np , __1nn ) ;

# 26 "/home/claude/cfront-3/src/Bits.cpp"
return __0this -> n__16Block_Bits_chunk ;

# 26 "/home/claude/cfront-3/src/Bits.cpp"
}

# 26 "/home/claude/cfront-3/src/Bits.cpp"
}

# 26 "/home/claude/cfront-3/src/Bits.cpp"
void transfer__16Block_Bits_chunkFPUlUl (register struct Block_Bits_chunk *__0this , Bits_chunk *__1source , size_t __1len ){ Bits_chunk *__1plim ;

# 26 "/home/claude/cfront-3/src/Bits.cpp"
Bits_chunk *__1pp ;

# 26 "/home/claude/cfront-3/src/Bits.cpp"
Bits_chunk *__1q ;

# 26 "/home/claude/cfront-3/src/Bits.cpp"
__1pp = __0this -> p__16Block_Bits_chunk ;

# 26 "/home/claude/cfront-3/src/Bits.cpp"
__1q = __1source ;

# 26 "/home/claude/cfront-3/src/Bits.cpp"
if (__0this -> n__16Block_Bits_chunk > __1len ){ __1plim = (__0this -> p__16Block_Bits_chunk + __1len );

# 26 "/home/claude/cfront-3/src/Bits.cpp"
clear__16Block_Bits_chunkFPUlUl ( __0this , __1plim , __0this -> n__16Block_Bits_chunk - __1len ) ;

# 26 "/home/claude/cfront-3/src/Bits.cpp"
}
else 
# 26 "/home/claude/cfront-3/src/Bits.cpp"
__1plim = (__0this -> p__16Block_Bits_chunk + __0this -> n__16Block_Bits_chunk );

# 26 "/home/claude/cfront-3/src/Bits.cpp"
while (__1pp < __1plim )((*(__1pp ++ )))= ((*(__1q ++ )));

# 26 "/home/claude/cfront-3/src/Bits.cpp"
}

# 26 "/home/claude/cfront-3/src/Bits.cpp"
void move__16Block_Bits_chunkFPUlUl (register struct Block_Bits_chunk *__0this , Bits_chunk *__1np , size_t __1nn ){ Bits_chunk *__1oldp ;

# 26 "/home/claude/cfront-3/src/Bits.cpp"
size_t __1oldn ;

# 26 "/home/claude/cfront-3/src/Bits.cpp"
__1oldp = __0this -> p__16Block_Bits_chunk ;

# 26 "/home/claude/cfront-3/src/Bits.cpp"
__1oldn = __0this -> n__16Block_Bits_chunk ;

# 26 "/home/claude/cfront-3/src/Bits.cpp"
__0this -> p__16Block_Bits_chunk = __1np ;

# 26 "/home/claude/cfront-3/src/Bits.cpp"
if (__1np ){ __0this -> n__16Block_Bits_chunk = __1nn ;

# 26 "/home/claude/cfront-3/src/Bits.cpp"
transfer__16Block_Bits_chunkFPUlUl ( __0this , __1oldp , __1oldn ) ;

# 26 "/home/claude/cfront-3/src/Bits.cpp"
}
else 
# 26 "/home/claude/cfront-3/src/Bits.cpp"
__0this -> n__16Block_Bits_chunk = 0 ;

# 26 "/home/claude/cfront-3/src/Bits.cpp"
__dl__FPv ( (void *)__1oldp ) ;

# 26 "/home/claude/cfront-3/src/Bits.cpp"
}

# 26 "/home/claude/cfront-3/src/Bits.cpp"
void swap__16Block_Bits_chunkFR16Block_Bits_chunk (register struct Block_Bits_chunk *__0this , struct Block_Bits_chunk *__1b ){ Bits_chunk *__1bp ;

# 26 "/home/claude/cfront-3/src/Bits.cpp"
size_t __1bn ;

# 26 "/home/claude/cfront-3/src/Bits.cpp"
__1bp = ((*__1b )). p__16Block_Bits_chunk ;

# 26 "/home/claude/cfront-3/src/Bits.cpp"
__1bn = ((*__1b )). n__16Block_Bits_chunk ;

# 26 "/home/claude/cfront-3/src/Bits.cpp"
((*__1b )). p__16Block_Bits_chunk = __0this -> p__16Block_Bits_chunk ;

# 26 "/home/claude/cfront-3/src/Bits.cpp"
((*__1b )). n__16Block_Bits_chunk = __0this -> n__16Block_Bits_chunk ;

# 26 "/home/claude/cfront-3/src/Bits.cpp"
__0this -> p__16Block_Bits_chunk = __1bp ;

# 26 "/home/claude/cfront-3/src/Bits.cpp"
__0this -> n__16Block_Bits_chunk = __1bn ;

# 26 "/home/claude/cfront-3/src/Bits.cpp"
}

# 27 "/home/claude/cfront-3/src/Bits.h"

# 28 "/home/claude/cfront-3/src/Bits.cpp"
struct Bits *__ct__4BitsFUlT1 (register struct Bits *__0this , Bits_chunk __1val , size_t __1ct )
# 29 "/home/claude/cfront-3/src/Bits.cpp"
{ 
# 29 "/home/claude/cfront-3/src/Bits.cpp"
struct Block_Bits_chunk *__0__X21 ;

# 29 "/home/claude/cfront-3/src/Bits.cpp"
struct Block_Bits_chunk *__0__X22 ;

# 29 "/home/claude/cfront-3/src/Bits.cpp"
if (__0this || (__0this = (struct Bits *)__nw__FUl ( (size_t )(sizeof (struct Bits))) )){ ( (__0__X21 = (& __0this ->
# 29 "/home/claude/cfront-3/src/Bits.cpp"
b__4Bits )), ( ((__0__X21 || (__0__X21 = (struct Block_Bits_chunk *)__nw__FUl ( (size_t )(sizeof (struct Block_Bits_chunk))) ))?( (__0__X21 -> n__16Block_Bits_chunk = 0 ),
# 29 "/home/claude/cfront-3/src/Bits.cpp"
(__0__X21 -> p__16Block_Bits_chunk = 0 )) :0 ), __0__X21 ) ) ;
if (__1ct < 32){ 
# 31 "/home/claude/cfront-3/src/Bits.cpp"
Bits_chunk __2mask ;

# 31 "/home/claude/cfront-3/src/Bits.cpp"
__2mask = ((~ (((unsigned long )0 )))<< __1ct );
while (__1val & __2mask ){ 
# 33 "/home/claude/cfront-3/src/Bits.cpp"
__1ct ++ ;
__2mask <<= 1 ;
}
}
if (size__4BitsFUl ( __0this , __1ct ) )
# 38 "/home/claude/cfront-3/src/Bits.cpp"
((*( (__0__X22 = (& __0this -> b__4Bits )), ( __0__X22 -> p__16Block_Bits_chunk ) ) ))=
# 38 "/home/claude/cfront-3/src/Bits.cpp"
__1val ;
} 
# 37 "/home/claude/cfront-3/src/Bits.cpp"
return __0this ;

# 39 "/home/claude/cfront-3/src/Bits.cpp"
}

# 40 "/home/claude/cfront-3/src/Bits.h"

# 27 "/home/claude/cfront-3/src/Bits.h"

# 54 "/home/claude/cfront-3/src/Bits.h"

# 42 "/home/claude/cfront-3/src/Bits.cpp"
size_t size__4BitsFUl (register struct Bits *__0this , size_t __1x )
# 43 "/home/claude/cfront-3/src/Bits.cpp"
{ 
# 44 "/home/claude/cfront-3/src/Bits.cpp"
size_t __1newsize ;

# 45 "/home/claude/cfront-3/src/Bits.cpp"
const struct Block_Bits_chunk *__0__X23 ;

# 45 "/home/claude/cfront-3/src/Bits.cpp"
struct Block_Bits_chunk *__0__X24 ;

# 45 "/home/claude/cfront-3/src/Bits.cpp"
const struct Block_Bits_chunk *__0__X25 ;

# 45 "/home/claude/cfront-3/src/Bits.cpp"
int __2__Xct00qunsoejpvcdp ;

# 45 "/home/claude/cfront-3/src/Bits.cpp"
unsigned long __2__X6 ;

# 45 "/home/claude/cfront-3/src/Bits.cpp"
struct Block_Bits_chunk *__0__X7 ;

# 45 "/home/claude/cfront-3/src/Bits.cpp"
int __2__X8 ;

# 44 "/home/claude/cfront-3/src/Bits.cpp"
__1newsize = ( (((__1x + 32)- 1 )>> 5)) ;
if (( (__0__X23 = (const struct Block_Bits_chunk *)(& __0this -> b__4Bits )), ( __0__X23 -> n__16Block_Bits_chunk ) ) != __1newsize )
# 46 "/home/claude/cfront-3/src/Bits.cpp"
(
# 46 "/home/claude/cfront-3/src/Bits.cpp"
(__0__X24 = (& __0this -> b__4Bits )), ( move__16Block_Bits_chunkFPUlUl ( __0__X24 , (Bits_chunk *)(((unsigned long *)__nw__FUl ( (size_t)((sizeof (unsigned
# 46 "/home/claude/cfront-3/src/Bits.cpp"
long ))* __1newsize )) )), __1newsize ) , __0__X24 -> n__16Block_Bits_chunk ) ) ;
__0this -> n__4Bits = (( (__0__X25 = (const struct Block_Bits_chunk *)(& __0this -> b__4Bits )), ( __0__X25 -> n__16Block_Bits_chunk ) ) ?__1x :(((unsigned
# 47 "/home/claude/cfront-3/src/Bits.cpp"
long )0 )));

# 49 "/home/claude/cfront-3/src/Bits.cpp"
( ( (__2__Xct00qunsoejpvcdp = (__0this -> n__4Bits & 31)), (__2__Xct00qunsoejpvcdp ?(((*( (__0__X7 = (& __0this -> b__4Bits )), ( (__2__X8 = (
# 49 "/home/claude/cfront-3/src/Bits.cpp"
(__2__X6 = __0this -> n__4Bits ), ( (__2__X6 >> 5)) ) ), ( (((Bits_chunk *)(& (__0__X7 -> p__16Block_Bits_chunk [__2__X8 ]))))) ) )
# 49 "/home/claude/cfront-3/src/Bits.cpp"
))&= (~ ((~ (((unsigned long )0 )))<< __2__Xct00qunsoejpvcdp ))):0 )) , (((void )0 ))) ;

# 51 "/home/claude/cfront-3/src/Bits.cpp"
return __0this -> n__4Bits ;
}

# 66 "/home/claude/cfront-3/src/Bits.h"

# 27 "/home/claude/cfront-3/src/Bits.h"

# 49 "/home/claude/cfront-3/src/Bits.h"

# 46 "/home/claude/cfront-3/src/Bits.h"

# 55 "/home/claude/cfront-3/src/Bits.cpp"
struct Bits *__aad__4BitsFRC4Bits (register struct Bits *__0this , const struct Bits *__1x )
# 56 "/home/claude/cfront-3/src/Bits.cpp"
{ 
# 57 "/home/claude/cfront-3/src/Bits.cpp"
if (( ((const struct Bits *)__0this )-> n__4Bits ) <
# 57 "/home/claude/cfront-3/src/Bits.cpp"
( ((const struct Bits *)__1x )-> n__4Bits ) )
# 58 "/home/claude/cfront-3/src/Bits.cpp"
size__4BitsFUl ( __0this , ( ((const struct Bits *)__1x )-> n__4Bits ) ) ;
# 58 "/home/claude/cfront-3/src/Bits.cpp"

# 60 "/home/claude/cfront-3/src/Bits.cpp"
{ Bits_chunk *__1p ;
const Bits_chunk *__1q ;
const Bits_chunk *__1lim ;

# 63 "/home/claude/cfront-3/src/Bits.cpp"
struct Block_Bits_chunk *__0__X2 ;

# 63 "/home/claude/cfront-3/src/Bits.cpp"
unsigned long __2__X3 ;

# 63 "/home/claude/cfront-3/src/Bits.cpp"
struct Block_Bits_chunk *__0__X26 ;

# 63 "/home/claude/cfront-3/src/Bits.cpp"
const struct Block_Bits_chunk *__0__X27 ;

# 63 "/home/claude/cfront-3/src/Bits.cpp"
const struct Block_Bits_chunk *__0__X4 ;

# 63 "/home/claude/cfront-3/src/Bits.cpp"
unsigned long __2__X5 ;

# 60 "/home/claude/cfront-3/src/Bits.cpp"
__1p = ( (__0__X26 = (& __0this -> b__4Bits )), ( __0__X26 -> p__16Block_Bits_chunk ) ) ;
__1q = ( (__0__X27 = (const struct Block_Bits_chunk *)(& ((*__1x )). b__4Bits )), ( __0__X27 -> p__16Block_Bits_chunk ) ) ;
__1lim = ( (( (__0__X4 = (const struct Block_Bits_chunk *)(& ((const struct Bits *)__1x )-> b__4Bits )), ( __0__X4 -> p__16Block_Bits_chunk )
# 62 "/home/claude/cfront-3/src/Bits.cpp"
) + ( (__2__X5 = ((const struct Bits *)__1x )-> n__4Bits ), ( (((__2__X5 + 32)- 1 )>> 5)) )
# 62 "/home/claude/cfront-3/src/Bits.cpp"
)) ;

# 64 "/home/claude/cfront-3/src/Bits.cpp"
while (__1q < __1lim )
# 65 "/home/claude/cfront-3/src/Bits.cpp"
((*(__1p ++ )))&= ((*(__1q ++ )));

# 67 "/home/claude/cfront-3/src/Bits.cpp"
__1lim = (const Bits_chunk *)( (( (__0__X2 = (& __0this -> b__4Bits )), ( __0__X2 -> p__16Block_Bits_chunk ) ) + (
# 67 "/home/claude/cfront-3/src/Bits.cpp"
(__2__X3 = __0this -> n__4Bits ), ( (((__2__X3 + 32)- 1 )>> 5)) ) )) ;
while (__1p < (Bits_chunk *)__1lim )
# 69 "/home/claude/cfront-3/src/Bits.cpp"
((*(__1p ++ )))= 0 ;

# 71 "/home/claude/cfront-3/src/Bits.cpp"
return (struct Bits *)__0this ;

# 71 "/home/claude/cfront-3/src/Bits.cpp"
}
}

# 66 "/home/claude/cfront-3/src/Bits.h"

# 27 "/home/claude/cfront-3/src/Bits.h"

# 49 "/home/claude/cfront-3/src/Bits.h"

# 75 "/home/claude/cfront-3/src/Bits.cpp"
struct Bits *__aor__4BitsFRC4Bits (register struct Bits *__0this , const struct Bits *__1x )
# 76 "/home/claude/cfront-3/src/Bits.cpp"
{ 
# 77 "/home/claude/cfront-3/src/Bits.cpp"
if (( ((const struct Bits *)__0this )-> n__4Bits ) <
# 77 "/home/claude/cfront-3/src/Bits.cpp"
( ((const struct Bits *)__1x )-> n__4Bits ) )
# 78 "/home/claude/cfront-3/src/Bits.cpp"
size__4BitsFUl ( __0this , ( ((const struct Bits *)__1x )-> n__4Bits ) ) ;
# 78 "/home/claude/cfront-3/src/Bits.cpp"

# 80 "/home/claude/cfront-3/src/Bits.cpp"
{ Bits_chunk *__1p ;
const Bits_chunk *__1q ;
const Bits_chunk *__1lim ;

# 83 "/home/claude/cfront-3/src/Bits.cpp"
struct Block_Bits_chunk *__0__X28 ;

# 83 "/home/claude/cfront-3/src/Bits.cpp"
const struct Block_Bits_chunk *__0__X29 ;

# 83 "/home/claude/cfront-3/src/Bits.cpp"
const struct Block_Bits_chunk *__0__X4 ;

# 83 "/home/claude/cfront-3/src/Bits.cpp"
unsigned long __2__X5 ;

# 80 "/home/claude/cfront-3/src/Bits.cpp"
__1p = ( (__0__X28 = (& __0this -> b__4Bits )), ( __0__X28 -> p__16Block_Bits_chunk ) ) ;
__1q = ( (__0__X29 = (const struct Block_Bits_chunk *)(& ((*__1x )). b__4Bits )), ( __0__X29 -> p__16Block_Bits_chunk ) ) ;
__1lim = ( (( (__0__X4 = (const struct Block_Bits_chunk *)(& ((const struct Bits *)__1x )-> b__4Bits )), ( __0__X4 -> p__16Block_Bits_chunk )
# 82 "/home/claude/cfront-3/src/Bits.cpp"
) + ( (__2__X5 = ((const struct Bits *)__1x )-> n__4Bits ), ( (((__2__X5 + 32)- 1 )>> 5)) )
# 82 "/home/claude/cfront-3/src/Bits.cpp"
)) ;

# 84 "/home/claude/cfront-3/src/Bits.cpp"
while (__1q < __1lim )
# 85 "/home/claude/cfront-3/src/Bits.cpp"
((*(__1p ++ )))|= ((*(__1q ++ )));

# 87 "/home/claude/cfront-3/src/Bits.cpp"
return (struct Bits *)__0this ;

# 87 "/home/claude/cfront-3/src/Bits.cpp"
}
}

# 66 "/home/claude/cfront-3/src/Bits.h"

# 27 "/home/claude/cfront-3/src/Bits.h"

# 49 "/home/claude/cfront-3/src/Bits.h"

# 91 "/home/claude/cfront-3/src/Bits.cpp"
struct Bits *__aer__4BitsFRC4Bits (register struct Bits *__0this , const struct Bits *__1x )
# 92 "/home/claude/cfront-3/src/Bits.cpp"
{ 
# 93 "/home/claude/cfront-3/src/Bits.cpp"
if (( ((const struct Bits *)__0this )-> n__4Bits ) <
# 93 "/home/claude/cfront-3/src/Bits.cpp"
( ((const struct Bits *)__1x )-> n__4Bits ) )
# 94 "/home/claude/cfront-3/src/Bits.cpp"
size__4BitsFUl ( __0this , ( ((const struct Bits *)__1x )-> n__4Bits ) ) ;
# 94 "/home/claude/cfront-3/src/Bits.cpp"

# 96 "/home/claude/cfront-3/src/Bits.cpp"
{ Bits_chunk *__1p ;
const Bits_chunk *__1q ;
const Bits_chunk *__1lim ;

# 99 "/home/claude/cfront-3/src/Bits.cpp"
struct Block_Bits_chunk *__0__X30 ;

# 99 "/home/claude/cfront-3/src/Bits.cpp"
const struct Block_Bits_chunk *__0__X31 ;

# 99 "/home/claude/cfront-3/src/Bits.cpp"
const struct Block_Bits_chunk *__0__X4 ;

# 99 "/home/claude/cfront-3/src/Bits.cpp"
unsigned long __2__X5 ;

# 96 "/home/claude/cfront-3/src/Bits.cpp"
__1p = ( (__0__X30 = (& __0this -> b__4Bits )), ( __0__X30 -> p__16Block_Bits_chunk ) ) ;
__1q = ( (__0__X31 = (const struct Block_Bits_chunk *)(& ((*__1x )). b__4Bits )), ( __0__X31 -> p__16Block_Bits_chunk ) ) ;
__1lim = ( (( (__0__X4 = (const struct Block_Bits_chunk *)(& ((const struct Bits *)__1x )-> b__4Bits )), ( __0__X4 -> p__16Block_Bits_chunk )
# 98 "/home/claude/cfront-3/src/Bits.cpp"
) + ( (__2__X5 = ((const struct Bits *)__1x )-> n__4Bits ), ( (((__2__X5 + 32)- 1 )>> 5)) )
# 98 "/home/claude/cfront-3/src/Bits.cpp"
)) ;

# 100 "/home/claude/cfront-3/src/Bits.cpp"
while (__1q < __1lim )
# 101 "/home/claude/cfront-3/src/Bits.cpp"
((*(__1p ++ )))^= ((*(__1q ++ )));

# 103 "/home/claude/cfront-3/src/Bits.cpp"
return (struct Bits *)__0this ;

# 103 "/home/claude/cfront-3/src/Bits.cpp"
}
}

# 27 "/home/claude/cfront-3/src/Bits.h"

# 46 "/home/claude/cfront-3/src/Bits.h"

# 54 "/home/claude/cfront-3/src/Bits.h"

# 107 "/home/claude/cfront-3/src/Bits.cpp"
struct Bits *compl4__4BitsFv (register struct Bits *__0this )
# 108 "/home/claude/cfront-3/src/Bits.cpp"
{ 
# 109 "/home/claude/cfront-3/src/Bits.cpp"
Bits_chunk *__1p ;
const Bits_chunk *__1lim ;

# 111 "/home/claude/cfront-3/src/Bits.cpp"
int __2__Xct00qunsoejpvcdp ;

# 111 "/home/claude/cfront-3/src/Bits.cpp"
unsigned long __2__X6 ;

# 111 "/home/claude/cfront-3/src/Bits.cpp"
struct Block_Bits_chunk *__0__X7 ;

# 111 "/home/claude/cfront-3/src/Bits.cpp"
int __2__X8 ;

# 111 "/home/claude/cfront-3/src/Bits.cpp"
struct Block_Bits_chunk *__0__X32 ;

# 111 "/home/claude/cfront-3/src/Bits.cpp"
struct Block_Bits_chunk *__0__X2 ;

# 111 "/home/claude/cfront-3/src/Bits.cpp"
unsigned long __2__X3 ;

# 109 "/home/claude/cfront-3/src/Bits.cpp"
__1p = ( (__0__X32 = (& __0this -> b__4Bits )), ( __0__X32 -> p__16Block_Bits_chunk ) ) ;
__1lim = (const Bits_chunk *)( (( (__0__X2 = (& __0this -> b__4Bits )), ( __0__X2 -> p__16Block_Bits_chunk ) ) + (
# 110 "/home/claude/cfront-3/src/Bits.cpp"
(__2__X3 = __0this -> n__4Bits ), ( (((__2__X3 + 32)- 1 )>> 5)) ) )) ;

# 112 "/home/claude/cfront-3/src/Bits.cpp"
while (__1p < (Bits_chunk *)__1lim ){ 
# 113 "/home/claude/cfront-3/src/Bits.cpp"
((*__1p ))= (~ ((*__1p )));
__1p ++ ;
}

# 117 "/home/claude/cfront-3/src/Bits.cpp"
( ( (__2__Xct00qunsoejpvcdp = (__0this -> n__4Bits & 31)), (__2__Xct00qunsoejpvcdp ?(((*( (__0__X7 = (& __0this -> b__4Bits )), ( (__2__X8 = (
# 117 "/home/claude/cfront-3/src/Bits.cpp"
(__2__X6 = __0this -> n__4Bits ), ( (__2__X6 >> 5)) ) ), ( (((Bits_chunk *)(& (__0__X7 -> p__16Block_Bits_chunk [__2__X8 ]))))) ) )
# 117 "/home/claude/cfront-3/src/Bits.cpp"
))&= (~ ((~ (((unsigned long )0 )))<< __2__Xct00qunsoejpvcdp ))):0 )) , (((void )0 ))) ;

# 119 "/home/claude/cfront-3/src/Bits.cpp"
return (struct Bits *)__0this ;
}

# 27 "/home/claude/cfront-3/src/Bits.h"

# 49 "/home/claude/cfront-3/src/Bits.h"

# 123 "/home/claude/cfront-3/src/Bits.cpp"
size_t count__4BitsCFv (register const struct Bits *const __0this )
# 124 "/home/claude/cfront-3/src/Bits.cpp"
{ 
# 125 "/home/claude/cfront-3/src/Bits.cpp"
const Bits_chunk *__1p ;
const Bits_chunk *__1lim ;
size_t __1r ;

# 128 "/home/claude/cfront-3/src/Bits.cpp"
const struct Block_Bits_chunk *__0__X33 ;

# 128 "/home/claude/cfront-3/src/Bits.cpp"
const struct Block_Bits_chunk *__0__X4 ;

# 128 "/home/claude/cfront-3/src/Bits.cpp"
unsigned long __2__X5 ;

# 125 "/home/claude/cfront-3/src/Bits.cpp"
__1p = ( (__0__X33 = (const struct Block_Bits_chunk *)(& __0this -> b__4Bits )), ( __0__X33 -> p__16Block_Bits_chunk ) ) ;
__1lim = ( (( (__0__X4 = (const struct Block_Bits_chunk *)(& __0this -> b__4Bits )), ( __0__X4 -> p__16Block_Bits_chunk ) ) +
# 126 "/home/claude/cfront-3/src/Bits.cpp"
( (__2__X5 = __0this -> n__4Bits ), ( (((__2__X5 + 32)- 1 )>> 5)) ) )) ;
__1r = 0 ;

# 129 "/home/claude/cfront-3/src/Bits.cpp"
while (__1p < __1lim ){ 
# 130 "/home/claude/cfront-3/src/Bits.cpp"
size_t __2x ;
int __2i ;

# 130 "/home/claude/cfront-3/src/Bits.cpp"
__2x = ((*(__1p ++ )));
__2i = 32;

# 133 "/home/claude/cfront-3/src/Bits.cpp"
while ((-- __2i )>= 0 ){ 
# 134 "/home/claude/cfront-3/src/Bits.cpp"
if (__2x & 1 )
# 135 "/home/claude/cfront-3/src/Bits.cpp"
__1r ++ ;
__2x >>= 1 ;
}
}

# 140 "/home/claude/cfront-3/src/Bits.cpp"
return __1r ;
}

# 123 "/home/claude/cfront-3/src/Bits.h"

# 27 "/home/claude/cfront-3/src/Bits.h"

# 183 "/home/claude/cfront-3/src/Bits.cpp"
void __co__FRC4Bits (
# 188 "/home/claude/cfront-3/src/Bits.cpp"
struct Bits *__0_result , 
# 183 "/home/claude/cfront-3/src/Bits.cpp"
const struct Bits *__1x )
# 184 "/home/claude/cfront-3/src/Bits.cpp"
{ 
# 184 "/home/claude/cfront-3/src/Bits.cpp"
struct Block_Bits_chunk *__0__X35 ;

# 184 "/home/claude/cfront-3/src/Bits.cpp"
const struct Block_Bits_chunk *__2__X36 ;

# 185 "/home/claude/cfront-3/src/Bits.cpp"
( (( ( ( (__0__X35 = (& __0_result -> b__4Bits )), ( (__2__X36 = (const struct Block_Bits_chunk *)(& ((*__1x )).
# 185 "/home/claude/cfront-3/src/Bits.cpp"
b__4Bits )), ( ((__0__X35 || (__0__X35 = (struct Block_Bits_chunk *)__nw__FUl ( (size_t )(sizeof (struct Block_Bits_chunk))) ))?(((void )copy__16Block_Bits_chunkFRC16Block_Bits_chunk ( __0__X35 , __2__X36 )
# 185 "/home/claude/cfront-3/src/Bits.cpp"
)):(((void )0 ))), __0__X35 ) ) ) , (__0_result -> n__4Bits = ((*__1x )). n__4Bits )) , 0 ) ), __0_result )
# 185 "/home/claude/cfront-3/src/Bits.cpp"
;
compl4__4BitsFv ( __0_result ) ;
{ ;

# 187 "/home/claude/cfront-3/src/Bits.cpp"
return ;
} }

# 40 "/home/claude/cfront-3/src/Bits.h"

# 66 "/home/claude/cfront-3/src/Bits.h"

# 40 "/home/claude/cfront-3/src/Bits.h"

# 66 "/home/claude/cfront-3/src/Bits.h"

# 40 "/home/claude/cfront-3/src/Bits.h"

# 27 "/home/claude/cfront-3/src/Bits.h"

# 66 "/home/claude/cfront-3/src/Bits.h"

# 209 "/home/claude/cfront-3/src/Bits.cpp"
int compare__4BitsCFRC4Bits (register const struct Bits *const __0this , const struct Bits *__1x )
# 210 "/home/claude/cfront-3/src/Bits.cpp"
{ 
# 211 "/home/claude/cfront-3/src/Bits.cpp"
int __1w ;
int __1xw ;
int __1len ;

# 213 "/home/claude/cfront-3/src/Bits.cpp"
int __1r ;
const Bits_chunk *__1p ;
const Bits_chunk *__1q ;
const Bits_chunk *__1lim ;

# 217 "/home/claude/cfront-3/src/Bits.cpp"
const struct Block_Bits_chunk *__0__X41 ;

# 217 "/home/claude/cfront-3/src/Bits.cpp"
const struct Block_Bits_chunk *__0__X42 ;

# 217 "/home/claude/cfront-3/src/Bits.cpp"
const struct Block_Bits_chunk *__0__X43 ;

# 217 "/home/claude/cfront-3/src/Bits.cpp"
unsigned long __2__X44 ;

# 217 "/home/claude/cfront-3/src/Bits.cpp"
unsigned long __2__X45 ;

# 211 "/home/claude/cfront-3/src/Bits.cpp"
__1w = ( (__2__X44 = ( __0this -> n__4Bits ) ), ( (((__2__X44 + 32)- 1 )>> 5)) ) ;
# 211 "/home/claude/cfront-3/src/Bits.cpp"

# 212 "/home/claude/cfront-3/src/Bits.cpp"
__1xw = ( (__2__X45 = ( ((const struct Bits *)__1x )-> n__4Bits ) ), ( (((__2__X45 + 32)- 1 )>> 5))
# 212 "/home/claude/cfront-3/src/Bits.cpp"
) ;

# 219 "/home/claude/cfront-3/src/Bits.cpp"
if ((__1w == 0 )&& (__1xw == 0 ))
# 220 "/home/claude/cfront-3/src/Bits.cpp"
return 0 ;

# 223 "/home/claude/cfront-3/src/Bits.cpp"
if (__1w == 0 )
# 224 "/home/claude/cfront-3/src/Bits.cpp"
return -1;
if (__1xw == 0 )
# 226 "/home/claude/cfront-3/src/Bits.cpp"
return 1 ;

# 231 "/home/claude/cfront-3/src/Bits.cpp"
if (__1w != __1xw ){ 
# 232 "/home/claude/cfront-3/src/Bits.cpp"
if (__1w > __1xw ){ 
# 232 "/home/claude/cfront-3/src/Bits.cpp"
const struct Block_Bits_chunk *__0__X37 ;

# 232 "/home/claude/cfront-3/src/Bits.cpp"
const struct Block_Bits_chunk *__0__X38 ;

# 233 "/home/claude/cfront-3/src/Bits.cpp"
__1len = __1xw ;
__1p = (( (__0__X37 = (const struct Block_Bits_chunk *)(& __0this -> b__4Bits )), ( (((const Bits_chunk *)(& (__0__X37 -> p__16Block_Bits_chunk [__1len ]))))) )
# 234 "/home/claude/cfront-3/src/Bits.cpp"
);
__1q = (( (__0__X38 = (const struct Block_Bits_chunk *)(& __0this -> b__4Bits )), ( (((const Bits_chunk *)(& (__0__X38 -> p__16Block_Bits_chunk [__1w ]))))) )
# 235 "/home/claude/cfront-3/src/Bits.cpp"
);
__1r = 1 ;
}
else 
# 237 "/home/claude/cfront-3/src/Bits.cpp"
{ 
# 237 "/home/claude/cfront-3/src/Bits.cpp"
const struct Block_Bits_chunk *__0__X39 ;

# 237 "/home/claude/cfront-3/src/Bits.cpp"
const struct Block_Bits_chunk *__0__X40 ;

# 238 "/home/claude/cfront-3/src/Bits.cpp"
__1len = __1w ;
__1p = (( (__0__X39 = (const struct Block_Bits_chunk *)(& ((*__1x )). b__4Bits )), ( (((const Bits_chunk *)(& (__0__X39 -> p__16Block_Bits_chunk [__1len ]))))) )
# 239 "/home/claude/cfront-3/src/Bits.cpp"
);
__1q = (( (__0__X40 = (const struct Block_Bits_chunk *)(& ((*__1x )). b__4Bits )), ( (((const Bits_chunk *)(& (__0__X40 -> p__16Block_Bits_chunk [__1xw ]))))) )
# 240 "/home/claude/cfront-3/src/Bits.cpp"
);
__1r = -1;
}

# 244 "/home/claude/cfront-3/src/Bits.cpp"
do { 
# 245 "/home/claude/cfront-3/src/Bits.cpp"
if ((*(__1p ++ )))
# 246 "/home/claude/cfront-3/src/Bits.cpp"
return __1r ;
}
while (__1p < __1q );

# 248 "/home/claude/cfront-3/src/Bits.cpp"
}
else __1len = __1w ;

# 253 "/home/claude/cfront-3/src/Bits.cpp"
__1p = (( (__0__X41 = (const struct Block_Bits_chunk *)(& __0this -> b__4Bits )), ( __0__X41 -> p__16Block_Bits_chunk ) ) + __1len );
# 253 "/home/claude/cfront-3/src/Bits.cpp"

# 254 "/home/claude/cfront-3/src/Bits.cpp"
__1q = (( (__0__X42 = (const struct Block_Bits_chunk *)(& ((*__1x )). b__4Bits )), ( __0__X42 -> p__16Block_Bits_chunk ) ) + __1len );
# 254 "/home/claude/cfront-3/src/Bits.cpp"

# 255 "/home/claude/cfront-3/src/Bits.cpp"
__1lim = ( (__0__X43 = (const struct Block_Bits_chunk *)(& __0this -> b__4Bits )), ( __0__X43 -> p__16Block_Bits_chunk ) ) ;
while (__1p > __1lim ){ 
# 257 "/home/claude/cfront-3/src/Bits.cpp"
if (((*(-- __1p )))!= ((*(-- __1q ))))
# 258 "/home/claude/cfront-3/src/Bits.cpp"
return ((((*__1p ))< ((*__1q )))?-1:1 );
}

# 262 "/home/claude/cfront-3/src/Bits.cpp"
return ((((int )( __0this -> n__4Bits ) ))- (((int )( ((const struct Bits *)__1x )-> n__4Bits ) )));
}

# 66 "/home/claude/cfront-3/src/Bits.h"

# 267 "/home/claude/cfront-3/src/Bits.cpp"
int equal__4BitsCFRC4Bits (register const struct Bits *const __0this , const struct Bits *__1x )
# 268 "/home/claude/cfront-3/src/Bits.cpp"
{ 
# 270 "/home/claude/cfront-3/src/Bits.cpp"
if (( __0this -> n__4Bits ) != (
# 270 "/home/claude/cfront-3/src/Bits.cpp"
((const struct Bits *)__1x )-> n__4Bits ) )
# 271 "/home/claude/cfront-3/src/Bits.cpp"
return 0 ;

# 274 "/home/claude/cfront-3/src/Bits.cpp"
if (( __0this -> n__4Bits ) == 0 )
# 275 "/home/claude/cfront-3/src/Bits.cpp"
return 1 ;

# 278 "/home/claude/cfront-3/src/Bits.cpp"
return (compare__4BitsCFRC4Bits ( __0this , __1x ) == 0 );
}

# 84 "/home/claude/cfront-3/src/Bits.h"
struct Bits *__ars__4BitsFi (struct Bits *__0this , int );

# 66 "/home/claude/cfront-3/src/Bits.h"

# 27 "/home/claude/cfront-3/src/Bits.h"

# 46 "/home/claude/cfront-3/src/Bits.h"

# 54 "/home/claude/cfront-3/src/Bits.h"

# 293 "/home/claude/cfront-3/src/Bits.cpp"
struct Bits *__als__4BitsFi (register struct Bits *__0this , int __1k )
# 294 "/home/claude/cfront-3/src/Bits.cpp"
{ 
# 296 "/home/claude/cfront-3/src/Bits.cpp"
if (__1k <= 0 ){ 
# 297 "/home/claude/cfront-3/src/Bits.cpp"
if (__1k < 0 )
# 298 "/home/claude/cfront-3/src/Bits.cpp"
__ars__4BitsFi ( __0this , -
# 298 "/home/claude/cfront-3/src/Bits.cpp"
__1k ) ;
return (struct Bits *)__0this ;
}

# 303 "/home/claude/cfront-3/src/Bits.cpp"
if (size__4BitsFUl ( __0this , ( ((const struct Bits *)__0this )-> n__4Bits ) + __1k ) == 0 )
# 304 "/home/claude/cfront-3/src/Bits.cpp"
return (struct Bits *)__0this ;
# 304 "/home/claude/cfront-3/src/Bits.cpp"

# 306 "/home/claude/cfront-3/src/Bits.cpp"
{ Bits_chunk *__1lim ;

# 309 "/home/claude/cfront-3/src/Bits.cpp"
int __1chunkoffset ;

# 310 "/home/claude/cfront-3/src/Bits.cpp"
struct Block_Bits_chunk *__0__X46 ;

# 306 "/home/claude/cfront-3/src/Bits.cpp"
__1lim = ( (__0__X46 = (& __0this -> b__4Bits )), ( __0__X46 -> p__16Block_Bits_chunk ) ) ;

# 309 "/home/claude/cfront-3/src/Bits.cpp"
__1chunkoffset = (__1k >> 5);
if (__1chunkoffset ){ 
# 311 "/home/claude/cfront-3/src/Bits.cpp"
Bits_chunk *__2dest ;
Bits_chunk *__2src ;

# 313 "/home/claude/cfront-3/src/Bits.cpp"
struct Block_Bits_chunk *__0__X2 ;

# 313 "/home/claude/cfront-3/src/Bits.cpp"
unsigned long __2__X3 ;

# 311 "/home/claude/cfront-3/src/Bits.cpp"
__2dest = ( (( (__0__X2 = (& __0this -> b__4Bits )), ( __0__X2 -> p__16Block_Bits_chunk ) ) + ( (__2__X3 =
# 311 "/home/claude/cfront-3/src/Bits.cpp"
__0this -> n__4Bits ), ( (((__2__X3 + 32)- 1 )>> 5)) ) )) ;
__2src = (__2dest - __1chunkoffset );

# 314 "/home/claude/cfront-3/src/Bits.cpp"
do ((*(-- __2dest )))= ((*(-- __2src )));
while (__2src > __1lim );

# 317 "/home/claude/cfront-3/src/Bits.cpp"
do ((*(-- __2dest )))= 0 ;
while (__2dest > __1lim );
}

# 322 "/home/claude/cfront-3/src/Bits.cpp"
{ int __1bitoffset ;

# 323 "/home/claude/cfront-3/src/Bits.cpp"
int __2__Xct00qunsoejpvcdp ;

# 323 "/home/claude/cfront-3/src/Bits.cpp"
unsigned long __2__X6 ;

# 323 "/home/claude/cfront-3/src/Bits.cpp"
struct Block_Bits_chunk *__0__X7 ;

# 323 "/home/claude/cfront-3/src/Bits.cpp"
int __2__X8 ;

# 322 "/home/claude/cfront-3/src/Bits.cpp"
__1bitoffset = (__1k & 31);
if (__1bitoffset ){ 
# 324 "/home/claude/cfront-3/src/Bits.cpp"
Bits_chunk *__2p ;
int __2compoffset ;

# 326 "/home/claude/cfront-3/src/Bits.cpp"
struct Block_Bits_chunk *__0__X2 ;

# 326 "/home/claude/cfront-3/src/Bits.cpp"
unsigned long __2__X3 ;

# 324 "/home/claude/cfront-3/src/Bits.cpp"
__2p = ( (( (__0__X2 = (& __0this -> b__4Bits )), ( __0__X2 -> p__16Block_Bits_chunk ) ) + ( (__2__X3 =
# 324 "/home/claude/cfront-3/src/Bits.cpp"
__0this -> n__4Bits ), ( (((__2__X3 + 32)- 1 )>> 5)) ) )) ;
__2compoffset = (32- __1bitoffset );

# 327 "/home/claude/cfront-3/src/Bits.cpp"
while ((-- __2p )> __1lim )
# 328 "/home/claude/cfront-3/src/Bits.cpp"
((*__2p ))= ((((*__2p ))<< __1bitoffset )| (((*(__2p - 1 )))>> __2compoffset ));

# 331 "/home/claude/cfront-3/src/Bits.cpp"
((*__1lim ))<<= __1bitoffset ;
}

# 334 "/home/claude/cfront-3/src/Bits.cpp"
( ( (__2__Xct00qunsoejpvcdp = (__0this -> n__4Bits & 31)), (__2__Xct00qunsoejpvcdp ?(((*( (__0__X7 = (& __0this -> b__4Bits )), ( (__2__X8 = (
# 334 "/home/claude/cfront-3/src/Bits.cpp"
(__2__X6 = __0this -> n__4Bits ), ( (__2__X6 >> 5)) ) ), ( (((Bits_chunk *)(& (__0__X7 -> p__16Block_Bits_chunk [__2__X8 ]))))) ) )
# 334 "/home/claude/cfront-3/src/Bits.cpp"
))&= (~ ((~ (((unsigned long )0 )))<< __2__Xct00qunsoejpvcdp ))):0 )) , (((void )0 ))) ;

# 336 "/home/claude/cfront-3/src/Bits.cpp"
return (struct Bits *)__0this ;

# 336 "/home/claude/cfront-3/src/Bits.cpp"
}

# 336 "/home/claude/cfront-3/src/Bits.cpp"
}
}

# 66 "/home/claude/cfront-3/src/Bits.h"

# 27 "/home/claude/cfront-3/src/Bits.h"

# 46 "/home/claude/cfront-3/src/Bits.h"

# 27 "/home/claude/cfront-3/src/Bits.h"

# 35 "/home/claude/cfront-3/src/Bits.h"

# 46 "/home/claude/cfront-3/src/Bits.h"

# 340 "/home/claude/cfront-3/src/Bits.cpp"
struct Bits *__ars__4BitsFi (register struct Bits *__0this , int __1k )
# 341 "/home/claude/cfront-3/src/Bits.cpp"
{ 
# 343 "/home/claude/cfront-3/src/Bits.cpp"
if (__1k <= 0 ){ 
# 344 "/home/claude/cfront-3/src/Bits.cpp"
if (__1k < 0 )
# 345 "/home/claude/cfront-3/src/Bits.cpp"
__als__4BitsFi ( __0this , -
# 345 "/home/claude/cfront-3/src/Bits.cpp"
__1k ) ;
return (struct Bits *)__0this ;
}

# 350 "/home/claude/cfront-3/src/Bits.cpp"
{ int __1newsize ;

# 350 "/home/claude/cfront-3/src/Bits.cpp"
__1newsize = (( ((const struct Bits *)__0this )-> n__4Bits ) - __1k );
if (__1newsize <= 0 ){ 
# 352 "/home/claude/cfront-3/src/Bits.cpp"
size__4BitsFUl ( __0this , (unsigned long )0 ) ;
return (struct Bits *)__0this ;
}

# 358 "/home/claude/cfront-3/src/Bits.cpp"
{ int __1chunkoffset ;

# 358 "/home/claude/cfront-3/src/Bits.cpp"
__1chunkoffset = (__1k >> 5);
if (__1chunkoffset ){ 
# 360 "/home/claude/cfront-3/src/Bits.cpp"
Bits_chunk *__2dest ;
Bits_chunk *__2src ;
const Bits_chunk *__2lim ;

# 363 "/home/claude/cfront-3/src/Bits.cpp"
struct Block_Bits_chunk *__0__X47 ;

# 363 "/home/claude/cfront-3/src/Bits.cpp"
struct Block_Bits_chunk *__0__X2 ;

# 363 "/home/claude/cfront-3/src/Bits.cpp"
unsigned long __2__X3 ;

# 360 "/home/claude/cfront-3/src/Bits.cpp"
__2dest = ( (__0__X47 = (& __0this -> b__4Bits )), ( __0__X47 -> p__16Block_Bits_chunk ) ) ;
__2src = (__2dest + __1chunkoffset );
__2lim = (const Bits_chunk *)( (( (__0__X2 = (& __0this -> b__4Bits )), ( __0__X2 -> p__16Block_Bits_chunk ) ) + (
# 362 "/home/claude/cfront-3/src/Bits.cpp"
(__2__X3 = __0this -> n__4Bits ), ( (((__2__X3 + 32)- 1 )>> 5)) ) )) ;

# 364 "/home/claude/cfront-3/src/Bits.cpp"
do ((*(__2dest ++ )))= ((*(__2src ++ )));
while (__2src < (Bits_chunk *)__2lim );
}

# 369 "/home/claude/cfront-3/src/Bits.cpp"
{ int __1bitoffset ;

# 369 "/home/claude/cfront-3/src/Bits.cpp"
__1bitoffset = (__1k & 31);
if (__1bitoffset ){ 
# 371 "/home/claude/cfront-3/src/Bits.cpp"
Bits_chunk *__2p ;
Bits_chunk *__2lim ;
int __2compoffset ;

# 374 "/home/claude/cfront-3/src/Bits.cpp"
struct Block_Bits_chunk *__0__X2 ;

# 374 "/home/claude/cfront-3/src/Bits.cpp"
unsigned long __2__X3 ;

# 374 "/home/claude/cfront-3/src/Bits.cpp"
struct Block_Bits_chunk *__0__X48 ;

# 371 "/home/claude/cfront-3/src/Bits.cpp"
__2p = ( (__0__X48 = (& __0this -> b__4Bits )), ( __0__X48 -> p__16Block_Bits_chunk ) ) ;
__2lim = (__2p + ( (((unsigned long )(__1newsize - 1 ))>> 5)) );
__2compoffset = (32- __1bitoffset );

# 375 "/home/claude/cfront-3/src/Bits.cpp"
while (__2p < __2lim ){ 
# 376 "/home/claude/cfront-3/src/Bits.cpp"
((*__2p ))= ((((*__2p ))>> __1bitoffset )| (((*(__2p + 1 )))<< __2compoffset ));
__2p ++ ;
}

# 381 "/home/claude/cfront-3/src/Bits.cpp"
((*__2lim ))>>= __1bitoffset ;
if ((__2lim + 1 )< ( (( (__0__X2 = (& __0this -> b__4Bits )), ( __0__X2 -> p__16Block_Bits_chunk ) ) +
# 382 "/home/claude/cfront-3/src/Bits.cpp"
( (__2__X3 = __0this -> n__4Bits ), ( (((__2__X3 + 32)- 1 )>> 5)) ) )) )
# 383 "/home/claude/cfront-3/src/Bits.cpp"
((*__2lim ))|= (((*(__2lim + 1 )))<<
# 383 "/home/claude/cfront-3/src/Bits.cpp"
__2compoffset );
}

# 387 "/home/claude/cfront-3/src/Bits.cpp"
size__4BitsFUl ( __0this , (unsigned long )__1newsize ) ;

# 389 "/home/claude/cfront-3/src/Bits.cpp"
return (struct Bits *)__0this ;

# 389 "/home/claude/cfront-3/src/Bits.cpp"
}

# 389 "/home/claude/cfront-3/src/Bits.cpp"
}

# 389 "/home/claude/cfront-3/src/Bits.cpp"
}
}

# 66 "/home/claude/cfront-3/src/Bits.h"

# 49 "/home/claude/cfront-3/src/Bits.h"

# 27 "/home/claude/cfront-3/src/Bits.h"

# 394 "/home/claude/cfront-3/src/Bits.cpp"
size_t signif__4BitsCFv (register const struct Bits *const __0this )
# 395 "/home/claude/cfront-3/src/Bits.cpp"
{ 
# 396 "/home/claude/cfront-3/src/Bits.cpp"
if (( __0this -> n__4Bits ) == 0 )
# 397 "/home/claude/cfront-3/src/Bits.cpp"
return (unsigned long )0 ;

# 399 "/home/claude/cfront-3/src/Bits.cpp"
{ const Bits_chunk *__1p ;
const Bits_chunk *__1lim ;

# 401 "/home/claude/cfront-3/src/Bits.cpp"
const struct Block_Bits_chunk *__0__X4 ;

# 401 "/home/claude/cfront-3/src/Bits.cpp"
unsigned long __2__X5 ;

# 401 "/home/claude/cfront-3/src/Bits.cpp"
const struct Block_Bits_chunk *__0__X49 ;

# 399 "/home/claude/cfront-3/src/Bits.cpp"
__1p = ( (( (__0__X4 = (const struct Block_Bits_chunk *)(& __0this -> b__4Bits )), ( __0__X4 -> p__16Block_Bits_chunk ) ) +
# 399 "/home/claude/cfront-3/src/Bits.cpp"
( (__2__X5 = __0this -> n__4Bits ), ( (((__2__X5 + 32)- 1 )>> 5)) ) )) ;
__1lim = ( (__0__X49 = (const struct Block_Bits_chunk *)(& __0this -> b__4Bits )), ( __0__X49 -> p__16Block_Bits_chunk ) ) ;

# 402 "/home/claude/cfront-3/src/Bits.cpp"
while ((-- __1p )>= __1lim ){ 
# 403 "/home/claude/cfront-3/src/Bits.cpp"
if ((*__1p )){ 
# 404 "/home/claude/cfront-3/src/Bits.cpp"
Bits_chunk __3x ;
int __3k ;

# 404 "/home/claude/cfront-3/src/Bits.cpp"
__3x = ((*__1p ));
__3k = 32;

# 407 "/home/claude/cfront-3/src/Bits.cpp"
while ((-- __3k )>= 0 ){ 
# 408 "/home/claude/cfront-3/src/Bits.cpp"
if (__3x & ((((unsigned long )1 ))<< __3k ))
# 409 "/home/claude/cfront-3/src/Bits.cpp"
return (unsigned long )((__3k + 1 )+
# 409 "/home/claude/cfront-3/src/Bits.cpp"
(32* (__1p - __1lim )));
}
}
}

# 414 "/home/claude/cfront-3/src/Bits.cpp"
return (unsigned long )0 ;

# 414 "/home/claude/cfront-3/src/Bits.cpp"
}
}

# 66 "/home/claude/cfront-3/src/Bits.h"

# 418 "/home/claude/cfront-3/src/Bits.cpp"
struct Bits *concat__4BitsFRC4Bits (register struct Bits *__0this , const struct Bits *__1x )
# 419 "/home/claude/cfront-3/src/Bits.cpp"
{ 
# 420 "/home/claude/cfront-3/src/Bits.cpp"
__als__4BitsFi ( __0this , (int )( ((const struct Bits *)__1x )->
# 420 "/home/claude/cfront-3/src/Bits.cpp"
n__4Bits ) ) ;
__aor__4BitsFRC4Bits ( __0this , __1x ) ;
return (struct Bits *)__0this ;
}

# 423 "/home/claude/cfront-3/src/Bits.cpp"

/* the end */
