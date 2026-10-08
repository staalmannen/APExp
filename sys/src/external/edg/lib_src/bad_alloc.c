/* Translated by the Edison Design Group C++/C front end (version 7.0) */
/* Thu Oct  8 07:53:17 2026 */
extern int __EDGCPFE__7_0;
void *memcpy(void *,const void *,unsigned long long);
void *memset(void *,int,unsigned long long);

#line 1 "lib_src/bad_alloc.c"
struct __C1; struct __C2; struct __EDG_type_info; struct __class_type_info; struct __si_class_type_info; struct __C4; struct __C5; union __C6; struct __C7; struct __C8;
#line 22 "include_c++/exception.stdh"
struct _ZSt9exception;
#line 41 "include_c++/new.stdh"
struct _ZSt9bad_alloc;
#line 50
struct _ZSt20bad_array_new_length; struct __C2 { struct __C8 *regions; void **obj_table; struct __C1 *array_table; unsigned short saved_region_number;char __dummy[6];}; struct __EDG_type_info { const long long *__vptr; const char *__name;}; struct __class_type_info { struct __EDG_type_info base;}; 
#line 50
struct __si_class_type_info { struct __class_type_info base; const struct __class_type_info *base_type;}; struct __C5 { long setjmp_buffer[25]; struct __C4 *catch_entries; void *rtinfo; unsigned short region_number;char __dummy[6];}; union __C6 { struct __C5 try_block; struct __C2 function; struct 
#line 50
__C4 *throw_spec;}; struct __C7 { struct __C7 *next; unsigned char kind; union __C6 variant;}; struct __C8 { void (*dtor)(); unsigned short handle; unsigned short next; unsigned char flags;char __dummy[3];};
#line 10 "ape-arch/stddef_arch.h"
typedef unsigned long long size_t;
#line 22 "include_c++/exception.stdh"
struct _ZSt9exception { const long long *__vptr;};
#line 41 "include_c++/new.stdh"
struct _ZSt9bad_alloc { struct _ZSt9exception __b_St9exception;};
#line 50
struct _ZSt20bad_array_new_length { struct _ZSt9bad_alloc __b_St9bad_alloc;};
#line 125
extern void _ZdlPvy(void *, size_t);
#line 24 "include_c++/exception.stdh"
extern void _ZNSt9exceptionC1Ev(struct _ZSt9exception *const); extern void _ZNSt9exceptionC2Ev(struct _ZSt9exception *const);
extern void _ZNSt9exceptionC1ERKS_(struct _ZSt9exception *const, const struct _ZSt9exception *); extern void _ZNSt9exceptionC2ERKS_(struct _ZSt9exception *const, const struct _ZSt9exception *);
extern struct _ZSt9exception *_ZNSt9exceptionaSERKS_(struct _ZSt9exception *const, const struct _ZSt9exception *);
extern void _ZNSt9exceptionD1Ev(struct _ZSt9exception *const); extern void _ZNSt9exceptionD2Ev(struct _ZSt9exception *const);
#line 35 "lib_src/bad_alloc.c"
extern void _ZNSt9bad_allocC1Ev(struct _ZSt9bad_alloc *const); extern void _ZNSt9bad_allocC2Ev(struct _ZSt9bad_alloc *const);
#line 43
extern void _ZNSt9bad_allocC1ERKS_(struct _ZSt9bad_alloc *const, const struct _ZSt9bad_alloc *rhs); extern void _ZNSt9bad_allocC2ERKS_(struct _ZSt9bad_alloc *const, const struct _ZSt9bad_alloc *);
#line 51
extern struct _ZSt9bad_alloc *_ZNSt9bad_allocaSERKS_(struct _ZSt9bad_alloc *const, const struct _ZSt9bad_alloc *rhs);
#line 62
extern void _ZNSt9bad_allocD1Ev(struct _ZSt9bad_alloc *const); extern void _ZNSt9bad_allocD0Ev(struct _ZSt9bad_alloc *const); extern void _ZNSt9bad_allocD2Ev(struct _ZSt9bad_alloc *const);
#line 70
extern const char *_ZNKSt9bad_alloc4whatEv(const struct _ZSt9bad_alloc *const);
#line 86
extern void _ZNSt20bad_array_new_lengthC1Ev(struct _ZSt20bad_array_new_length *const); extern void _ZNSt20bad_array_new_lengthC2Ev(struct _ZSt20bad_array_new_length *const);
#line 94
extern void _ZNSt20bad_array_new_lengthD1Ev(struct _ZSt20bad_array_new_length *const); extern void _ZNSt20bad_array_new_lengthD0Ev(struct _ZSt20bad_array_new_length *const); extern void _ZNSt20bad_array_new_lengthD2Ev(struct _ZSt20bad_array_new_length *const); extern  /* COMDAT group:  */
#line 94
/* _ZTVSt9bad_alloc */ const long long _ZTVSt9bad_alloc[5]; extern unsigned short __eh_curr_region; extern struct __C7 *__curr_eh_stack_entry; extern  /* COMDAT group: _ZTVSt20bad_array_new_length */ const long long _ZTVSt20bad_array_new_length[5]; extern  /* COMDAT group: _ZTISt9bad_alloc */ const 
#line 94
struct __si_class_type_info _ZTISt9bad_alloc; extern  /* COMDAT group: _ZTISt20bad_array_new_length */ const struct __si_class_type_info _ZTISt20bad_array_new_length; extern const long long _ZTVN10__cxxabiv120__si_class_type_infoE[4]; extern const struct __class_type_info _ZTISt9exception; extern  /* */
#line 94
/*  COMDAT group: _ZTSSt9bad_alloc */ const char _ZTSSt9bad_alloc[13]; extern  /* COMDAT group: _ZTSSt20bad_array_new_length */ const char _ZTSSt20bad_array_new_length[25];  /* COMDAT group: _ZTVSt9bad_alloc */ const long long _ZTVSt9bad_alloc[5] = {0LL,((long long)(&_ZTISt9bad_alloc)),((long long)
#line 94
_ZNSt9bad_allocD1Ev),((long long)_ZNSt9bad_allocD0Ev),((long long)_ZNKSt9bad_alloc4whatEv)};  /* COMDAT group: _ZTVSt20bad_array_new_length */ const long long _ZTVSt20bad_array_new_length[5] = {0LL,((long long)(&_ZTISt20bad_array_new_length)),((long long)_ZNSt20bad_array_new_lengthD1Ev),((long long)
#line 94
_ZNSt20bad_array_new_lengthD0Ev),((long long)_ZNKSt9bad_alloc4whatEv)};  /* COMDAT group: _ZTISt9bad_alloc */ const struct __si_class_type_info _ZTISt9bad_alloc = {{{(_ZTVN10__cxxabiv120__si_class_type_infoE + 2),_ZTSSt9bad_alloc}},(&_ZTISt9exception)};  /* COMDAT group: _ZTISt20bad_array_new_length */ 
#line 94
const struct __si_class_type_info _ZTISt20bad_array_new_length = {{{(_ZTVN10__cxxabiv120__si_class_type_infoE + 2),_ZTSSt20bad_array_new_length}},((const struct __class_type_info *)(&_ZTISt9bad_alloc.base))};  /* COMDAT group: _ZTSSt9bad_alloc */ const char _ZTSSt9bad_alloc[13] = "St9bad_alloc";  /* */
#line 94
/*  COMDAT group: _ZTSSt20bad_array_new_length */ const char _ZTSSt20bad_array_new_length[25] = "St20bad_array_new_length";
#line 35
void _ZNSt9bad_allocC1Ev( struct _ZSt9bad_alloc *const this)



{ static struct __C8 __T621681976[1] = {{((void (*)())(&_ZNSt9exceptionD2Ev)),((unsigned short)0U),((unsigned short)65535U),((unsigned char)64U)}}; auto void *__T621820384[1]; auto struct __C7 __T621824264;  (__T621824264.next) = __curr_eh_stack_entry; __curr_eh_stack_entry = (&__T621824264); (
#line 39
__T621824264.kind) = ((unsigned char)1U); (((__T621824264.variant).function).regions) = (__T621681976); (((__T621824264.variant).function).obj_table) = (__T621820384); (((__T621824264.variant).function).saved_region_number) = __eh_curr_region; __eh_curr_region = ((unsigned short)65535U); 
#line 39
_ZNSt9exceptionC2Ev((&(this->__b_St9exception))); ((__T621820384)[0ULL]) = ((void *)(&(this->__b_St9exception))); __eh_curr_region = ((unsigned short)0U); ((this->__b_St9exception).__vptr) = (_ZTVSt9bad_alloc + 2); { __eh_curr_region = (((__T621824264.variant).function).saved_region_number); 
#line 39
__curr_eh_stack_entry = (__T621824264.next);  }
} void _ZNSt9bad_allocC2Ev( struct _ZSt9bad_alloc *const this) {  _ZNSt9bad_allocC1Ev(this);  }


void _ZNSt9bad_allocC1ERKS_( struct _ZSt9bad_alloc *const this,  const struct _ZSt9bad_alloc *__3041_39_rhs)



{ static struct __C8 __T621716080[1] = {{((void (*)())(&_ZNSt9exceptionD2Ev)),((unsigned short)0U),((unsigned short)65535U),((unsigned char)64U)}}; auto void *__T621834064[1]; auto struct __C7 __T621837944;  (__T621837944.next) = __curr_eh_stack_entry; __curr_eh_stack_entry = (&__T621837944); (
#line 47
__T621837944.kind) = ((unsigned char)1U); (((__T621837944.variant).function).regions) = (__T621716080); (((__T621837944.variant).function).obj_table) = (__T621834064); (((__T621837944.variant).function).saved_region_number) = __eh_curr_region; __eh_curr_region = ((unsigned short)65535U);
#line 43
_ZNSt9exceptionC2ERKS_((&(this->__b_St9exception)), (&(__3041_39_rhs->__b_St9exception))); ((__T621834064)[0ULL]) = ((void *)(&(this->__b_St9exception))); __eh_curr_region = ((unsigned short)0U); ((this->__b_St9exception).__vptr) = (_ZTVSt9bad_alloc + 2); { __eh_curr_region = (((__T621837944.variant
#line 43
).function).saved_region_number); __curr_eh_stack_entry = (__T621837944.next);  }




} void _ZNSt9bad_allocC2ERKS_( struct _ZSt9bad_alloc *const this,  const struct _ZSt9bad_alloc *__T621891008) {  _ZNSt9bad_allocC1ERKS_(this, __T621891008);  }


struct _ZSt9bad_alloc *_ZNSt9bad_allocaSERKS_( struct _ZSt9bad_alloc *const this,  const struct _ZSt9bad_alloc *__3049_50_rhs)



{

_ZNSt9exceptionaSERKS_((&(this->__b_St9exception)), (&(__3049_50_rhs->__b_St9exception)));
return this;
}


void _ZNSt9bad_allocD1Ev( struct _ZSt9bad_alloc *const this)



{ static struct __C8 __T621892680[1] = {{((void (*)())(&_ZNSt9exceptionD2Ev)),((unsigned short)0U),((unsigned short)65535U),((unsigned char)64U)}}; auto void *__T621850976[1]; auto struct __C7 __T621854064;  (__T621854064.next) = __curr_eh_stack_entry; __curr_eh_stack_entry = (&__T621854064); (
#line 66
__T621854064.kind) = ((unsigned char)1U); (((__T621854064.variant).function).regions) = (__T621892680); (((__T621854064.variant).function).obj_table) = (__T621850976); (((__T621854064.variant).function).saved_region_number) = __eh_curr_region; __eh_curr_region = ((unsigned short)65535U); ((this->
#line 66
__b_St9exception).__vptr) = (_ZTVSt9bad_alloc + 2); ((__T621850976)[0ULL]) = ((void *)(&(this->__b_St9exception))); __eh_curr_region = ((unsigned short)0U); { __eh_curr_region = ((unsigned short)65535U);
_ZNSt9exceptionD2Ev((&(this->__b_St9exception))); } { __eh_curr_region = (((__T621854064.variant).function).saved_region_number); __curr_eh_stack_entry = (__T621854064.next);  } } void _ZNSt9bad_allocD0Ev( struct _ZSt9bad_alloc *const this) {  _ZNSt9bad_allocD1Ev(this); _ZdlPvy(((void *)this), 8ULL)
#line 67
;  } void _ZNSt9bad_allocD2Ev( struct _ZSt9bad_alloc *const this) {  _ZNSt9bad_allocD1Ev(this);  }


const char *_ZNKSt9bad_alloc4whatEv( const struct _ZSt9bad_alloc *const this)




{ auto const char *__T621861888;  {
__T621861888 = ((const char *)("")); return __T621861888; }
}
#line 86
void _ZNSt20bad_array_new_lengthC1Ev( struct _ZSt20bad_array_new_length *const this)



{ static struct __C8 __T621897376[1] = {{((void (*)())(&_ZNSt9bad_allocD2Ev)),((unsigned short)0U),((unsigned short)65535U),((unsigned char)64U)}}; auto void *__T621864480[1]; auto struct __C7 __T621868536;  (__T621868536.next) = __curr_eh_stack_entry; __curr_eh_stack_entry = (&__T621868536); (
#line 90
__T621868536.kind) = ((unsigned char)1U); (((__T621868536.variant).function).regions) = (__T621897376); (((__T621868536.variant).function).obj_table) = (__T621864480); (((__T621868536.variant).function).saved_region_number) = __eh_curr_region; __eh_curr_region = ((unsigned short)65535U); 
#line 90
_ZNSt9bad_allocC2Ev((&(this->__b_St9bad_alloc))); ((__T621864480)[0ULL]) = ((void *)(&(this->__b_St9bad_alloc))); __eh_curr_region = ((unsigned short)0U); (((this->__b_St9bad_alloc).__b_St9exception).__vptr) = (_ZTVSt20bad_array_new_length + 2); { __eh_curr_region = (((__T621868536.variant).function
#line 90
).saved_region_number); __curr_eh_stack_entry = (__T621868536.next);  }
} void _ZNSt20bad_array_new_lengthC2Ev( struct _ZSt20bad_array_new_length *const this) {  _ZNSt20bad_array_new_lengthC1Ev(this);  }


void _ZNSt20bad_array_new_lengthD1Ev( struct _ZSt20bad_array_new_length *const this)



{ static struct __C8 __T621901888[1] = {{((void (*)())(&_ZNSt9bad_allocD2Ev)),((unsigned short)0U),((unsigned short)65535U),((unsigned char)64U)}}; auto void *__T621878296[1]; auto struct __C7 __T621881384;  (__T621881384.next) = __curr_eh_stack_entry; __curr_eh_stack_entry = (&__T621881384); (
#line 98
__T621881384.kind) = ((unsigned char)1U); (((__T621881384.variant).function).regions) = (__T621901888); (((__T621881384.variant).function).obj_table) = (__T621878296); (((__T621881384.variant).function).saved_region_number) = __eh_curr_region; __eh_curr_region = ((unsigned short)65535U); (((this->
#line 98
__b_St9bad_alloc).__b_St9exception).__vptr) = (_ZTVSt20bad_array_new_length + 2); ((__T621878296)[0ULL]) = ((void *)(&(this->__b_St9bad_alloc))); __eh_curr_region = ((unsigned short)0U); { __eh_curr_region = ((unsigned short)65535U);
_ZNSt9bad_allocD2Ev((&(this->__b_St9bad_alloc))); } { __eh_curr_region = (((__T621881384.variant).function).saved_region_number); __curr_eh_stack_entry = (__T621881384.next);  } } void _ZNSt20bad_array_new_lengthD0Ev( struct _ZSt20bad_array_new_length *const this) {  _ZNSt20bad_array_new_lengthD1Ev(
#line 99
this); _ZdlPvy(((void *)this), 8ULL);  } void _ZNSt20bad_array_new_lengthD2Ev( struct _ZSt20bad_array_new_length *const this) {  _ZNSt20bad_array_new_lengthD1Ev(this);  }
