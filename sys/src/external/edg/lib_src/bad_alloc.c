/* Translated by the Edison Design Group C++/C front end (version 7.0) */
/* Wed Oct  7 03:19:04 2026 */
extern int __EDGCPFE__7_0;
void *memcpy(void *,const void *,unsigned long);
void *memset(void *,int,unsigned long);

# 1 "lib_src/bad_alloc.c"
struct __C1; struct __C2; struct __EDG_type_info; struct __class_type_info; struct __si_class_type_info; struct __C4; struct __C5; union __C6; struct __C7; struct __C8;
# 22 "include_c++/exception.stdh" 3
struct _ZSt9exception;
# 41 "include_c++/new.stdh" 3
struct _ZSt9bad_alloc;
# 50
struct _ZSt20bad_array_new_length; struct __C2 { struct __C8 *regions; void **obj_table; struct __C1 *array_table; unsigned short saved_region_number;char __dummy[6];}; struct __EDG_type_info { const long *__vptr; const char *__name;}; struct __class_type_info { struct __EDG_type_info base;}; struct 
# 50
__si_class_type_info { struct __class_type_info base; const struct __class_type_info *base_type;}; struct __C5 { long setjmp_buffer[25]; struct __C4 *catch_entries; void *rtinfo; unsigned short region_number;char __dummy[6];}; union __C6 { struct __C5 try_block; struct __C2 function; struct __C4 *
# 50
throw_spec;}; struct __C7 { struct __C7 *next; unsigned char kind; union __C6 variant;}; struct __C8 { void (*dtor)(); unsigned short handle; unsigned short next; unsigned char flags;char __dummy[3];};
# 214 "/usr/lib/gcc/x86_64-linux-gnu/13/include/stddef.h" 3
typedef unsigned long size_t;
# 22 "include_c++/exception.stdh" 3
struct _ZSt9exception { const long *__vptr;};
# 41 "include_c++/new.stdh" 3
struct _ZSt9bad_alloc { struct _ZSt9exception __b_St9exception;};
# 50
struct _ZSt20bad_array_new_length { struct _ZSt9bad_alloc __b_St9bad_alloc;};
# 125
extern __attribute__((__nothrow__)) void _ZdlPvm(void *, size_t);
# 24 "include_c++/exception.stdh" 3
extern __attribute__((__nothrow__)) void _ZNSt9exceptionC1Ev(struct _ZSt9exception *const); extern void _ZNSt9exceptionC2Ev(struct _ZSt9exception *const);
extern __attribute__((__nothrow__)) void _ZNSt9exceptionC1ERKS_(struct _ZSt9exception *const, const struct _ZSt9exception *); extern void _ZNSt9exceptionC2ERKS_(struct _ZSt9exception *const, const struct _ZSt9exception *);
extern __attribute__((__nothrow__)) struct _ZSt9exception *_ZNSt9exceptionaSERKS_(struct _ZSt9exception *const, const struct _ZSt9exception *);
extern __attribute__((__nothrow__)) void _ZNSt9exceptionD1Ev(struct _ZSt9exception *const); extern void _ZNSt9exceptionD2Ev(struct _ZSt9exception *const);
# 35 "lib_src/bad_alloc.c"
extern __attribute__((__nothrow__)) void _ZNSt9bad_allocC1Ev(struct _ZSt9bad_alloc *const); extern void _ZNSt9bad_allocC2Ev(struct _ZSt9bad_alloc *const);
# 43
extern __attribute__((__nothrow__)) void _ZNSt9bad_allocC1ERKS_(struct _ZSt9bad_alloc *const, const struct _ZSt9bad_alloc *rhs); extern void _ZNSt9bad_allocC2ERKS_(struct _ZSt9bad_alloc *const, const struct _ZSt9bad_alloc *);
# 51
extern __attribute__((__nothrow__)) struct _ZSt9bad_alloc *_ZNSt9bad_allocaSERKS_(struct _ZSt9bad_alloc *const, const struct _ZSt9bad_alloc *rhs);
# 62
extern __attribute__((__nothrow__)) void _ZNSt9bad_allocD1Ev(struct _ZSt9bad_alloc *const); extern void _ZNSt9bad_allocD0Ev(struct _ZSt9bad_alloc *const); extern void _ZNSt9bad_allocD2Ev(struct _ZSt9bad_alloc *const);
# 70
extern __attribute__((__nothrow__)) const char *_ZNKSt9bad_alloc4whatEv(const struct _ZSt9bad_alloc *const);
# 86
extern __attribute__((__nothrow__)) void _ZNSt20bad_array_new_lengthC1Ev(struct _ZSt20bad_array_new_length *const); extern void _ZNSt20bad_array_new_lengthC2Ev(struct _ZSt20bad_array_new_length *const);
# 94
extern __attribute__((__nothrow__)) void _ZNSt20bad_array_new_lengthD1Ev(struct _ZSt20bad_array_new_length *const); extern void _ZNSt20bad_array_new_lengthD0Ev(struct _ZSt20bad_array_new_length *const); extern void _ZNSt20bad_array_new_lengthD2Ev(struct _ZSt20bad_array_new_length *const); extern 
# 94
 __attribute__((__weak__)) /* COMDAT group: _ZTVSt9bad_alloc */ const long _ZTVSt9bad_alloc[5]; extern unsigned short __eh_curr_region; extern struct __C7 *__curr_eh_stack_entry; extern  __attribute__((__weak__)) /* COMDAT group: _ZTVSt20bad_array_new_length */ const long 
# 94
_ZTVSt20bad_array_new_length[5]; extern  __attribute__((__weak__)) /* COMDAT group: _ZTISt9bad_alloc */ const struct __si_class_type_info _ZTISt9bad_alloc; extern  __attribute__((__weak__)) /* COMDAT group: _ZTISt20bad_array_new_length */ const struct __si_class_type_info 
# 94
_ZTISt20bad_array_new_length; extern const long _ZTVN10__cxxabiv120__si_class_type_infoE[4]; extern const struct __class_type_info _ZTISt9exception; extern  __attribute__((__weak__)) /* COMDAT group: _ZTSSt9bad_alloc */ const char _ZTSSt9bad_alloc[13]; extern  __attribute__((__weak__)) /* */
# 94
/*  COMDAT group: _ZTSSt20bad_array_new_length */ const char _ZTSSt20bad_array_new_length[25];  __attribute__((__weak__)) /* COMDAT group: _ZTVSt9bad_alloc */ const long _ZTVSt9bad_alloc[5] = {0L,((long)(&_ZTISt9bad_alloc)),((long)_ZNSt9bad_allocD1Ev),((long)_ZNSt9bad_allocD0Ev),((long)
# 94
_ZNKSt9bad_alloc4whatEv)};  __attribute__((__weak__)) /* COMDAT group: _ZTVSt20bad_array_new_length */ const long _ZTVSt20bad_array_new_length[5] = {0L,((long)(&_ZTISt20bad_array_new_length)),((long)_ZNSt20bad_array_new_lengthD1Ev),((long)_ZNSt20bad_array_new_lengthD0Ev),((long)
# 94
_ZNKSt9bad_alloc4whatEv)};  __attribute__((__weak__)) /* COMDAT group: _ZTISt9bad_alloc */ const struct __si_class_type_info _ZTISt9bad_alloc = {{{(_ZTVN10__cxxabiv120__si_class_type_infoE + 2),_ZTSSt9bad_alloc}},(&_ZTISt9exception)};  __attribute__((__weak__)) /* COMDAT group:  */
# 94
/* _ZTISt20bad_array_new_length */ const struct __si_class_type_info _ZTISt20bad_array_new_length = {{{(_ZTVN10__cxxabiv120__si_class_type_infoE + 2),_ZTSSt20bad_array_new_length}},((const struct __class_type_info *)(&_ZTISt9bad_alloc.base))};  __attribute__((__weak__)) /* COMDAT group:  */
# 94
/* _ZTSSt9bad_alloc */ const char _ZTSSt9bad_alloc[13] = "St9bad_alloc";  __attribute__((__weak__)) /* COMDAT group: _ZTSSt20bad_array_new_length */ const char _ZTSSt20bad_array_new_length[25] = "St20bad_array_new_length";__asm__(".align 2");
# 35
__attribute__((__nothrow__)) void _ZNSt9bad_allocC1Ev( struct _ZSt9bad_alloc *const this)



{ static struct __C8 __T740661792[1] = {{((void (*)())(&_ZNSt9exceptionD2Ev)),((unsigned short)0U),((unsigned short)65535U),((unsigned char)64U)}}; auto void *__T740713584[1]; auto struct __C7 __T740717464;  (__T740717464.next) = __curr_eh_stack_entry; __curr_eh_stack_entry = (&__T740717464); (
# 39
__T740717464.kind) = ((unsigned char)1U); (((__T740717464.variant).function).regions) = (__T740661792); (((__T740717464.variant).function).obj_table) = (__T740713584); (((__T740717464.variant).function).saved_region_number) = __eh_curr_region; __eh_curr_region = ((unsigned short)65535U); 
# 39
_ZNSt9exceptionC2Ev((&(this->__b_St9exception))); ((__T740713584)[0UL]) = ((void *)(&(this->__b_St9exception))); __eh_curr_region = ((unsigned short)0U); ((this->__b_St9exception).__vptr) = (_ZTVSt9bad_alloc + 2); { __eh_curr_region = (((__T740717464.variant).function).saved_region_number); 
# 39
__curr_eh_stack_entry = (__T740717464.next);  }
}__asm__(".align 2");
void _ZNSt9bad_allocC2Ev( struct _ZSt9bad_alloc *const this) {  _ZNSt9bad_allocC1Ev(this);  }__asm__(".align 2");

__attribute__((__nothrow__)) void _ZNSt9bad_allocC1ERKS_( struct _ZSt9bad_alloc *const this,  const struct _ZSt9bad_alloc *__11032_39_rhs)



{ static struct __C8 __T740695664[1] = {{((void (*)())(&_ZNSt9exceptionD2Ev)),((unsigned short)0U),((unsigned short)65535U),((unsigned char)64U)}}; auto void *__T740727264[1]; auto struct __C7 __T740731144;  (__T740731144.next) = __curr_eh_stack_entry; __curr_eh_stack_entry = (&__T740731144); (
# 47
__T740731144.kind) = ((unsigned char)1U); (((__T740731144.variant).function).regions) = (__T740695664); (((__T740731144.variant).function).obj_table) = (__T740727264); (((__T740731144.variant).function).saved_region_number) = __eh_curr_region; __eh_curr_region = ((unsigned short)65535U);
# 43
_ZNSt9exceptionC2ERKS_((&(this->__b_St9exception)), (&(__11032_39_rhs->__b_St9exception))); ((__T740727264)[0UL]) = ((void *)(&(this->__b_St9exception))); __eh_curr_region = ((unsigned short)0U); ((this->__b_St9exception).__vptr) = (_ZTVSt9bad_alloc + 2); { __eh_curr_region = (((__T740731144.variant
# 43
).function).saved_region_number); __curr_eh_stack_entry = (__T740731144.next);  }




}__asm__(".align 2");
void _ZNSt9bad_allocC2ERKS_( struct _ZSt9bad_alloc *const this,  const struct _ZSt9bad_alloc *__T740779392) {  _ZNSt9bad_allocC1ERKS_(this, __T740779392);  }__asm__(".align 2");

__attribute__((__nothrow__)) struct _ZSt9bad_alloc *_ZNSt9bad_allocaSERKS_( struct _ZSt9bad_alloc *const this,  const struct _ZSt9bad_alloc *__11040_50_rhs)



{

_ZNSt9exceptionaSERKS_((&(this->__b_St9exception)), (&(__11040_50_rhs->__b_St9exception)));
return this;
}__asm__(".align 2");


__attribute__((__nothrow__)) void _ZNSt9bad_allocD1Ev( struct _ZSt9bad_alloc *const this)



{ static struct __C8 __T740700544[1] = {{((void (*)())(&_ZNSt9exceptionD2Ev)),((unsigned short)0U),((unsigned short)65535U),((unsigned char)64U)}}; auto void *__T740744176[1]; auto struct __C7 __T740747264;  (__T740747264.next) = __curr_eh_stack_entry; __curr_eh_stack_entry = (&__T740747264); (
# 66
__T740747264.kind) = ((unsigned char)1U); (((__T740747264.variant).function).regions) = (__T740700544); (((__T740747264.variant).function).obj_table) = (__T740744176); (((__T740747264.variant).function).saved_region_number) = __eh_curr_region; __eh_curr_region = ((unsigned short)65535U); ((this->
# 66
__b_St9exception).__vptr) = (_ZTVSt9bad_alloc + 2); ((__T740744176)[0UL]) = ((void *)(&(this->__b_St9exception))); __eh_curr_region = ((unsigned short)0U); { __eh_curr_region = ((unsigned short)65535U);
_ZNSt9exceptionD2Ev((&(this->__b_St9exception))); } { __eh_curr_region = (((__T740747264.variant).function).saved_region_number); __curr_eh_stack_entry = (__T740747264.next);  } }__asm__(".align 2");
void _ZNSt9bad_allocD0Ev( struct _ZSt9bad_alloc *const this) {  _ZNSt9bad_allocD1Ev(this); _ZdlPvm(((void *)this), 8UL);  }__asm__(".align 2");
void _ZNSt9bad_allocD2Ev( struct _ZSt9bad_alloc *const this) {  _ZNSt9bad_allocD1Ev(this);  }__asm__(".align 2");
__attribute__((__nothrow__)) const char *_ZNKSt9bad_alloc4whatEv( const struct _ZSt9bad_alloc *const this)




{ auto const char *__T740755088;  {
__T740755088 = ((const char *)("")); return __T740755088; }
}__asm__(".align 2");
# 86
__attribute__((__nothrow__)) void _ZNSt20bad_array_new_lengthC1Ev( struct _ZSt20bad_array_new_length *const this)



{ static struct __C8 __T740705048[1] = {{((void (*)())(&_ZNSt9bad_allocD2Ev)),((unsigned short)0U),((unsigned short)65535U),((unsigned char)64U)}}; auto void *__T740757680[1]; auto struct __C7 __T740761736;  (__T740761736.next) = __curr_eh_stack_entry; __curr_eh_stack_entry = (&__T740761736); (
# 90
__T740761736.kind) = ((unsigned char)1U); (((__T740761736.variant).function).regions) = (__T740705048); (((__T740761736.variant).function).obj_table) = (__T740757680); (((__T740761736.variant).function).saved_region_number) = __eh_curr_region; __eh_curr_region = ((unsigned short)65535U); 
# 90
_ZNSt9bad_allocC2Ev((&(this->__b_St9bad_alloc))); ((__T740757680)[0UL]) = ((void *)(&(this->__b_St9bad_alloc))); __eh_curr_region = ((unsigned short)0U); (((this->__b_St9bad_alloc).__b_St9exception).__vptr) = (_ZTVSt20bad_array_new_length + 2); { __eh_curr_region = (((__T740761736.variant).function)
# 90
.saved_region_number); __curr_eh_stack_entry = (__T740761736.next);  }
}__asm__(".align 2");
void _ZNSt20bad_array_new_lengthC2Ev( struct _ZSt20bad_array_new_length *const this) {  _ZNSt20bad_array_new_lengthC1Ev(this);  }__asm__(".align 2");

__attribute__((__nothrow__)) void _ZNSt20bad_array_new_lengthD1Ev( struct _ZSt20bad_array_new_length *const this)



{ static struct __C8 __T740709560[1] = {{((void (*)())(&_ZNSt9bad_allocD2Ev)),((unsigned short)0U),((unsigned short)65535U),((unsigned char)64U)}}; auto void *__T740771496[1]; auto struct __C7 __T740774584;  (__T740774584.next) = __curr_eh_stack_entry; __curr_eh_stack_entry = (&__T740774584); (
# 98
__T740774584.kind) = ((unsigned char)1U); (((__T740774584.variant).function).regions) = (__T740709560); (((__T740774584.variant).function).obj_table) = (__T740771496); (((__T740774584.variant).function).saved_region_number) = __eh_curr_region; __eh_curr_region = ((unsigned short)65535U); (((this->
# 98
__b_St9bad_alloc).__b_St9exception).__vptr) = (_ZTVSt20bad_array_new_length + 2); ((__T740771496)[0UL]) = ((void *)(&(this->__b_St9bad_alloc))); __eh_curr_region = ((unsigned short)0U); { __eh_curr_region = ((unsigned short)65535U);
_ZNSt9bad_allocD2Ev((&(this->__b_St9bad_alloc))); } { __eh_curr_region = (((__T740774584.variant).function).saved_region_number); __curr_eh_stack_entry = (__T740774584.next);  } }__asm__(".align 2");
void _ZNSt20bad_array_new_lengthD0Ev( struct _ZSt20bad_array_new_length *const this) {  _ZNSt20bad_array_new_lengthD1Ev(this); _ZdlPvm(((void *)this), 8UL);  }__asm__(".align 2");
void _ZNSt20bad_array_new_lengthD2Ev( struct _ZSt20bad_array_new_length *const this) {  _ZNSt20bad_array_new_lengthD1Ev(this);  }
