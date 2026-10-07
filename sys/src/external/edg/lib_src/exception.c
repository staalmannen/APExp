/* Translated by the Edison Design Group C++/C front end (version 7.0) */
/* Wed Oct  7 03:19:05 2026 */
extern int __EDGCPFE__7_0;
void *memcpy(void *,const void *,unsigned long);
void *memset(void *,int,unsigned long);

# 1 "lib_src/exception.c"
struct __C1; struct __C2; struct __EDG_type_info; struct __class_type_info; struct __si_class_type_info; struct __C4; struct __C5; union __C6; struct __C7; struct __C8;
# 22 "include_c++/exception.stdh" 3
struct _ZSt9exception;
# 40
struct _ZSt13bad_exception; struct __C2 { struct __C8 *regions; void **obj_table; struct __C1 *array_table; unsigned short saved_region_number;char __dummy[6];}; struct __EDG_type_info { const long *__vptr; const char *__name;}; struct __class_type_info { struct __EDG_type_info base;}; struct 
# 40
__si_class_type_info { struct __class_type_info base; const struct __class_type_info *base_type;}; struct __C5 { long setjmp_buffer[25]; struct __C4 *catch_entries; void *rtinfo; unsigned short region_number;char __dummy[6];}; union __C6 { struct __C5 try_block; struct __C2 function; struct __C4 *
# 40
throw_spec;}; struct __C7 { struct __C7 *next; unsigned char kind; union __C6 variant;}; struct __C8 { void (*dtor)(); unsigned short handle; unsigned short next; unsigned char flags;char __dummy[3];};
# 214 "/usr/lib/gcc/x86_64-linux-gnu/13/include/stddef.h" 3
typedef unsigned long size_t;
# 22 "include_c++/exception.stdh" 3
struct _ZSt9exception { const long *__vptr;};
# 40
struct _ZSt13bad_exception { struct _ZSt9exception __b_St9exception;};
# 125 "include_c++/new.stdh" 3
extern __attribute__((__nothrow__)) void _ZdlPvm(void *, size_t);
# 33 "lib_src/exception.c"
extern __attribute__((__nothrow__)) void _ZNSt9exceptionC1Ev(struct _ZSt9exception *const); extern void _ZNSt9exceptionC2Ev(struct _ZSt9exception *const);
# 41
extern __attribute__((__nothrow__)) void _ZNSt9exceptionC1ERKS_(struct _ZSt9exception *const, const struct _ZSt9exception *); extern void _ZNSt9exceptionC2ERKS_(struct _ZSt9exception *const, const struct _ZSt9exception *);
# 49
extern __attribute__((__nothrow__)) struct _ZSt9exception *_ZNSt9exceptionaSERKS_(struct _ZSt9exception *const, const struct _ZSt9exception *);
# 58
extern __attribute__((__nothrow__)) void _ZNSt9exceptionD1Ev(struct _ZSt9exception *const); extern void _ZNSt9exceptionD0Ev(struct _ZSt9exception *const); extern void _ZNSt9exceptionD2Ev(struct _ZSt9exception *const);
# 66
extern __attribute__((__nothrow__)) const char *_ZNKSt9exception4whatEv(const struct _ZSt9exception *const);
# 76
extern __attribute__((__nothrow__)) void _ZNSt13bad_exceptionC1Ev(struct _ZSt13bad_exception *const); extern void _ZNSt13bad_exceptionC2Ev(struct _ZSt13bad_exception *const);
# 84
extern __attribute__((__nothrow__)) void _ZNSt13bad_exceptionC1ERKS_(struct _ZSt13bad_exception *const, const struct _ZSt13bad_exception *rhs); extern void _ZNSt13bad_exceptionC2ERKS_(struct _ZSt13bad_exception *const, const struct _ZSt13bad_exception *);
# 93
extern __attribute__((__nothrow__)) struct _ZSt13bad_exception *_ZNSt13bad_exceptionaSERKS_(struct _ZSt13bad_exception *const, const struct _ZSt13bad_exception *rhs);
# 105
extern __attribute__((__nothrow__)) void _ZNSt13bad_exceptionD1Ev(struct _ZSt13bad_exception *const); extern void _ZNSt13bad_exceptionD0Ev(struct _ZSt13bad_exception *const); extern void _ZNSt13bad_exceptionD2Ev(struct _ZSt13bad_exception *const);
# 113
extern __attribute__((__nothrow__)) const char *_ZNKSt13bad_exception4whatEv(const struct _ZSt13bad_exception *const); extern  __attribute__((__weak__)) /* COMDAT group: _ZTVSt9exception */ const long _ZTVSt9exception[5]; extern  __attribute__((__weak__)) /* COMDAT group: _ZTVSt13bad_exception */ 
# 113
const long _ZTVSt13bad_exception[5]; extern unsigned short __eh_curr_region; extern struct __C7 *__curr_eh_stack_entry; extern  __attribute__((__weak__)) /* COMDAT group: _ZTISt9exception */ const struct __class_type_info _ZTISt9exception; extern  __attribute__((__weak__)) /* COMDAT group:  */
# 113
/* _ZTISt13bad_exception */ const struct __si_class_type_info _ZTISt13bad_exception; extern const long _ZTVN10__cxxabiv117__class_type_infoE[4]; extern const long _ZTVN10__cxxabiv120__si_class_type_infoE[4]; extern  __attribute__((__weak__)) /* COMDAT group: _ZTSSt9exception */ const char 
# 113
_ZTSSt9exception[13]; extern  __attribute__((__weak__)) /* COMDAT group: _ZTSSt13bad_exception */ const char _ZTSSt13bad_exception[18];  __attribute__((__weak__)) /* COMDAT group: _ZTVSt9exception */ const long _ZTVSt9exception[5] = {0L,((long)(&_ZTISt9exception)),((long)_ZNSt9exceptionD1Ev),((long)
# 113
_ZNSt9exceptionD0Ev),((long)_ZNKSt9exception4whatEv)};  __attribute__((__weak__)) /* COMDAT group: _ZTVSt13bad_exception */ const long _ZTVSt13bad_exception[5] = {0L,((long)(&_ZTISt13bad_exception)),((long)_ZNSt13bad_exceptionD1Ev),((long)_ZNSt13bad_exceptionD0Ev),((long)_ZNKSt13bad_exception4whatEv
# 113
)};  __attribute__((__weak__)) /* COMDAT group: _ZTISt9exception */ const struct __class_type_info _ZTISt9exception = {{(_ZTVN10__cxxabiv117__class_type_infoE + 2),_ZTSSt9exception}};  __attribute__((__weak__)) /* COMDAT group: _ZTISt13bad_exception */ const struct __si_class_type_info 
# 113
_ZTISt13bad_exception = {{{(_ZTVN10__cxxabiv120__si_class_type_infoE + 2),_ZTSSt13bad_exception}},(&_ZTISt9exception)};  __attribute__((__weak__)) /* COMDAT group: _ZTSSt9exception */ const char _ZTSSt9exception[13] = "St9exception";  __attribute__((__weak__)) /* COMDAT group: _ZTSSt13bad_exception */ 
# 113
const char _ZTSSt13bad_exception[18] = "St13bad_exception";__asm__(".align 2");
# 33
__attribute__((__nothrow__)) void _ZNSt9exceptionC1Ev( struct _ZSt9exception *const this)



{  (this->__vptr) = (_ZTVSt9exception + 2); 
}__asm__(".align 2");
void _ZNSt9exceptionC2Ev( struct _ZSt9exception *const this) {  _ZNSt9exceptionC1Ev(this);  }__asm__(".align 2");

__attribute__((__nothrow__)) void _ZNSt9exceptionC1ERKS_( struct _ZSt9exception *const this,  const struct _ZSt9exception *__T529610232)



{  (this->__vptr) = (_ZTVSt9exception + 2); 
}__asm__(".align 2");
void _ZNSt9exceptionC2ERKS_( struct _ZSt9exception *const this,  const struct _ZSt9exception *__T529675648) {  _ZNSt9exceptionC1ERKS_(this, __T529675648);  }__asm__(".align 2");

__attribute__((__nothrow__)) struct _ZSt9exception *_ZNSt9exceptionaSERKS_( struct _ZSt9exception *const this,  const struct _ZSt9exception *__T529612112)



{
return this;
}__asm__(".align 2");


__attribute__((__nothrow__)) void _ZNSt9exceptionD1Ev( struct _ZSt9exception *const this)



{  (this->__vptr) = (_ZTVSt9exception + 2); 
}__asm__(".align 2");
void _ZNSt9exceptionD0Ev( struct _ZSt9exception *const this) {  _ZNSt9exceptionD1Ev(this); _ZdlPvm(((void *)this), 8UL);  }__asm__(".align 2");
void _ZNSt9exceptionD2Ev( struct _ZSt9exception *const this) {  _ZNSt9exceptionD1Ev(this);  }__asm__(".align 2");
__attribute__((__nothrow__)) const char *_ZNKSt9exception4whatEv( const struct _ZSt9exception *const this)




{ auto const char *__T529615872;  {
__T529615872 = ((const char *)("")); return __T529615872; }
}__asm__(".align 2");


__attribute__((__nothrow__)) void _ZNSt13bad_exceptionC1Ev( struct _ZSt13bad_exception *const this)



{ static struct __C8 __T529565024[1] = {{((void (*)())(&_ZNSt9exceptionD2Ev)),((unsigned short)0U),((unsigned short)65535U),((unsigned char)64U)}}; auto void *__T529618464[1]; auto struct __C7 __T529622344;  (__T529622344.next) = __curr_eh_stack_entry; __curr_eh_stack_entry = (&__T529622344); (
# 80
__T529622344.kind) = ((unsigned char)1U); (((__T529622344.variant).function).regions) = (__T529565024); (((__T529622344.variant).function).obj_table) = (__T529618464); (((__T529622344.variant).function).saved_region_number) = __eh_curr_region; __eh_curr_region = ((unsigned short)65535U); 
# 80
_ZNSt9exceptionC2Ev((&(this->__b_St9exception))); ((__T529618464)[0UL]) = ((void *)(&(this->__b_St9exception))); __eh_curr_region = ((unsigned short)0U); ((this->__b_St9exception).__vptr) = (_ZTVSt13bad_exception + 2); { __eh_curr_region = (((__T529622344.variant).function).saved_region_number); 
# 80
__curr_eh_stack_entry = (__T529622344.next);  }
}__asm__(".align 2");
void _ZNSt13bad_exceptionC2Ev( struct _ZSt13bad_exception *const this) {  _ZNSt13bad_exceptionC1Ev(this);  }__asm__(".align 2");

__attribute__((__nothrow__)) void _ZNSt13bad_exceptionC1ERKS_( struct _ZSt13bad_exception *const this,  const struct _ZSt13bad_exception *__11073_51_rhs)




{ static struct __C8 __T529597720[1] = {{((void (*)())(&_ZNSt9exceptionD2Ev)),((unsigned short)0U),((unsigned short)65535U),((unsigned char)64U)}}; auto void *__T529632144[1]; auto struct __C7 __T529636024;  (__T529636024.next) = __curr_eh_stack_entry; __curr_eh_stack_entry = (&__T529636024); (
# 89
__T529636024.kind) = ((unsigned char)1U); (((__T529636024.variant).function).regions) = (__T529597720); (((__T529636024.variant).function).obj_table) = (__T529632144); (((__T529636024.variant).function).saved_region_number) = __eh_curr_region; __eh_curr_region = ((unsigned short)65535U);
# 85
_ZNSt9exceptionC2ERKS_((&(this->__b_St9exception)), (&(__11073_51_rhs->__b_St9exception))); ((__T529632144)[0UL]) = ((void *)(&(this->__b_St9exception))); __eh_curr_region = ((unsigned short)0U); ((this->__b_St9exception).__vptr) = (_ZTVSt13bad_exception + 2); { __eh_curr_region = (((__T529636024.
# 85
variant).function).saved_region_number); __curr_eh_stack_entry = (__T529636024.next);  }




}__asm__(".align 2");
void _ZNSt13bad_exceptionC2ERKS_( struct _ZSt13bad_exception *const this,  const struct _ZSt13bad_exception *__T529681584) {  _ZNSt13bad_exceptionC1ERKS_(this, __T529681584);  }__asm__(".align 2");

__attribute__((__nothrow__)) struct _ZSt13bad_exception *_ZNSt13bad_exceptionaSERKS_( struct _ZSt13bad_exception *const this,  const struct _ZSt13bad_exception *__11082_62_rhs)




{

_ZNSt9exceptionaSERKS_((&(this->__b_St9exception)), (&(__11082_62_rhs->__b_St9exception)));
return this;
}__asm__(".align 2");


__attribute__((__nothrow__)) void _ZNSt13bad_exceptionD1Ev( struct _ZSt13bad_exception *const this)



{ static struct __C8 __T529602640[1] = {{((void (*)())(&_ZNSt9exceptionD2Ev)),((unsigned short)0U),((unsigned short)65535U),((unsigned char)64U)}}; auto void *__T529649056[1]; auto struct __C7 __T529652144;  (__T529652144.next) = __curr_eh_stack_entry; __curr_eh_stack_entry = (&__T529652144); (
# 109
__T529652144.kind) = ((unsigned char)1U); (((__T529652144.variant).function).regions) = (__T529602640); (((__T529652144.variant).function).obj_table) = (__T529649056); (((__T529652144.variant).function).saved_region_number) = __eh_curr_region; __eh_curr_region = ((unsigned short)65535U); ((this->
# 109
__b_St9exception).__vptr) = (_ZTVSt13bad_exception + 2); ((__T529649056)[0UL]) = ((void *)(&(this->__b_St9exception))); __eh_curr_region = ((unsigned short)0U); { __eh_curr_region = ((unsigned short)65535U);
_ZNSt9exceptionD2Ev((&(this->__b_St9exception))); } { __eh_curr_region = (((__T529652144.variant).function).saved_region_number); __curr_eh_stack_entry = (__T529652144.next);  } }__asm__(".align 2");
void _ZNSt13bad_exceptionD0Ev( struct _ZSt13bad_exception *const this) {  _ZNSt13bad_exceptionD1Ev(this); _ZdlPvm(((void *)this), 8UL);  }__asm__(".align 2");
void _ZNSt13bad_exceptionD2Ev( struct _ZSt13bad_exception *const this) {  _ZNSt13bad_exceptionD1Ev(this);  }__asm__(".align 2");
__attribute__((__nothrow__)) const char *_ZNKSt13bad_exception4whatEv( const struct _ZSt13bad_exception *const this)




{ auto const char *__T529659968;  {
__T529659968 = ((const char *)("")); return __T529659968; }
}
