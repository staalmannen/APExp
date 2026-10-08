/* Translated by the Edison Design Group C++/C front end (version 7.0) */
/* Thu Oct  8 07:53:17 2026 */
extern int __EDGCPFE__7_0;
void *memcpy(void *,const void *,unsigned long long);
void *memset(void *,int,unsigned long long);

#line 1 "lib_src/exception.c"
struct __C1; struct __C2; struct __EDG_type_info; struct __class_type_info; struct __si_class_type_info; struct __C4; struct __C5; union __C6; struct __C7; struct __C8;
#line 22 "include_c++/exception.stdh"
struct _ZSt9exception;
#line 40
struct _ZSt13bad_exception; struct __C2 { struct __C8 *regions; void **obj_table; struct __C1 *array_table; unsigned short saved_region_number;char __dummy[6];}; struct __EDG_type_info { const long long *__vptr; const char *__name;}; struct __class_type_info { struct __EDG_type_info base;}; struct 
#line 40
__si_class_type_info { struct __class_type_info base; const struct __class_type_info *base_type;}; struct __C5 { long setjmp_buffer[25]; struct __C4 *catch_entries; void *rtinfo; unsigned short region_number;char __dummy[6];}; union __C6 { struct __C5 try_block; struct __C2 function; struct __C4 *
#line 40
throw_spec;}; struct __C7 { struct __C7 *next; unsigned char kind; union __C6 variant;}; struct __C8 { void (*dtor)(); unsigned short handle; unsigned short next; unsigned char flags;char __dummy[3];};
#line 10 "ape-arch/stddef_arch.h"
typedef unsigned long long size_t;
#line 22 "include_c++/exception.stdh"
struct _ZSt9exception { const long long *__vptr;};
#line 40
struct _ZSt13bad_exception { struct _ZSt9exception __b_St9exception;};
#line 125 "include_c++/new.stdh"
extern void _ZdlPvy(void *, size_t);
#line 33 "lib_src/exception.c"
extern void _ZNSt9exceptionC1Ev(struct _ZSt9exception *const); extern void _ZNSt9exceptionC2Ev(struct _ZSt9exception *const);
#line 41
extern void _ZNSt9exceptionC1ERKS_(struct _ZSt9exception *const, const struct _ZSt9exception *); extern void _ZNSt9exceptionC2ERKS_(struct _ZSt9exception *const, const struct _ZSt9exception *);
#line 49
extern struct _ZSt9exception *_ZNSt9exceptionaSERKS_(struct _ZSt9exception *const, const struct _ZSt9exception *);
#line 58
extern void _ZNSt9exceptionD1Ev(struct _ZSt9exception *const); extern void _ZNSt9exceptionD0Ev(struct _ZSt9exception *const); extern void _ZNSt9exceptionD2Ev(struct _ZSt9exception *const);
#line 66
extern const char *_ZNKSt9exception4whatEv(const struct _ZSt9exception *const);
#line 76
extern void _ZNSt13bad_exceptionC1Ev(struct _ZSt13bad_exception *const); extern void _ZNSt13bad_exceptionC2Ev(struct _ZSt13bad_exception *const);
#line 84
extern void _ZNSt13bad_exceptionC1ERKS_(struct _ZSt13bad_exception *const, const struct _ZSt13bad_exception *rhs); extern void _ZNSt13bad_exceptionC2ERKS_(struct _ZSt13bad_exception *const, const struct _ZSt13bad_exception *);
#line 93
extern struct _ZSt13bad_exception *_ZNSt13bad_exceptionaSERKS_(struct _ZSt13bad_exception *const, const struct _ZSt13bad_exception *rhs);
#line 105
extern void _ZNSt13bad_exceptionD1Ev(struct _ZSt13bad_exception *const); extern void _ZNSt13bad_exceptionD0Ev(struct _ZSt13bad_exception *const); extern void _ZNSt13bad_exceptionD2Ev(struct _ZSt13bad_exception *const);
#line 113
extern const char *_ZNKSt13bad_exception4whatEv(const struct _ZSt13bad_exception *const); extern  /* COMDAT group: _ZTVSt9exception */ const long long _ZTVSt9exception[5]; extern  /* COMDAT group: _ZTVSt13bad_exception */ const long long _ZTVSt13bad_exception[5]; extern unsigned short 
#line 113
__eh_curr_region; extern struct __C7 *__curr_eh_stack_entry; extern  /* COMDAT group: _ZTISt9exception */ const struct __class_type_info _ZTISt9exception; extern  /* COMDAT group: _ZTISt13bad_exception */ const struct __si_class_type_info _ZTISt13bad_exception; extern const long long 
#line 113
_ZTVN10__cxxabiv117__class_type_infoE[4]; extern const long long _ZTVN10__cxxabiv120__si_class_type_infoE[4]; extern  /* COMDAT group: _ZTSSt9exception */ const char _ZTSSt9exception[13]; extern  /* COMDAT group: _ZTSSt13bad_exception */ const char _ZTSSt13bad_exception[18];  /* COMDAT group:  */
#line 113
/* _ZTVSt9exception */ const long long _ZTVSt9exception[5] = {0LL,((long long)(&_ZTISt9exception)),((long long)_ZNSt9exceptionD1Ev),((long long)_ZNSt9exceptionD0Ev),((long long)_ZNKSt9exception4whatEv)};  /* COMDAT group: _ZTVSt13bad_exception */ const long long _ZTVSt13bad_exception[5] = {0LL,((
#line 113
long long)(&_ZTISt13bad_exception)),((long long)_ZNSt13bad_exceptionD1Ev),((long long)_ZNSt13bad_exceptionD0Ev),((long long)_ZNKSt13bad_exception4whatEv)};  /* COMDAT group: _ZTISt9exception */ const struct __class_type_info _ZTISt9exception = {{(_ZTVN10__cxxabiv117__class_type_infoE + 2),
#line 113
_ZTSSt9exception}};  /* COMDAT group: _ZTISt13bad_exception */ const struct __si_class_type_info _ZTISt13bad_exception = {{{(_ZTVN10__cxxabiv120__si_class_type_infoE + 2),_ZTSSt13bad_exception}},(&_ZTISt9exception)};  /* COMDAT group: _ZTSSt9exception */ const char _ZTSSt9exception[13] = "St9exception"
#line 113
;  /* COMDAT group: _ZTSSt13bad_exception */ const char _ZTSSt13bad_exception[18] = "St13bad_exception";
#line 33
void _ZNSt9exceptionC1Ev( struct _ZSt9exception *const this)



{  (this->__vptr) = (_ZTVSt9exception + 2); 
} void _ZNSt9exceptionC2Ev( struct _ZSt9exception *const this) {  _ZNSt9exceptionC1Ev(this);  }


void _ZNSt9exceptionC1ERKS_( struct _ZSt9exception *const this,  const struct _ZSt9exception *__T656501608)



{  (this->__vptr) = (_ZTVSt9exception + 2); 
} void _ZNSt9exceptionC2ERKS_( struct _ZSt9exception *const this,  const struct _ZSt9exception *__T656571840) {  _ZNSt9exceptionC1ERKS_(this, __T656571840);  }


struct _ZSt9exception *_ZNSt9exceptionaSERKS_( struct _ZSt9exception *const this,  const struct _ZSt9exception *__T656503488)



{
return this;
}


void _ZNSt9exceptionD1Ev( struct _ZSt9exception *const this)



{  (this->__vptr) = (_ZTVSt9exception + 2); 
} void _ZNSt9exceptionD0Ev( struct _ZSt9exception *const this) {  _ZNSt9exceptionD1Ev(this); _ZdlPvy(((void *)this), 8ULL);  } void _ZNSt9exceptionD2Ev( struct _ZSt9exception *const this) {  _ZNSt9exceptionD1Ev(this);  }


const char *_ZNKSt9exception4whatEv( const struct _ZSt9exception *const this)




{ auto const char *__T656507248;  {
__T656507248 = ((const char *)("")); return __T656507248; }
}


void _ZNSt13bad_exceptionC1Ev( struct _ZSt13bad_exception *const this)



{ static struct __C8 __T656369984[1] = {{((void (*)())(&_ZNSt9exceptionD2Ev)),((unsigned short)0U),((unsigned short)65535U),((unsigned char)64U)}}; auto void *__T656509840[1]; auto struct __C7 __T656513720;  (__T656513720.next) = __curr_eh_stack_entry; __curr_eh_stack_entry = (&__T656513720); (
#line 80
__T656513720.kind) = ((unsigned char)1U); (((__T656513720.variant).function).regions) = (__T656369984); (((__T656513720.variant).function).obj_table) = (__T656509840); (((__T656513720.variant).function).saved_region_number) = __eh_curr_region; __eh_curr_region = ((unsigned short)65535U); 
#line 80
_ZNSt9exceptionC2Ev((&(this->__b_St9exception))); ((__T656509840)[0ULL]) = ((void *)(&(this->__b_St9exception))); __eh_curr_region = ((unsigned short)0U); ((this->__b_St9exception).__vptr) = (_ZTVSt13bad_exception + 2); { __eh_curr_region = (((__T656513720.variant).function).saved_region_number); 
#line 80
__curr_eh_stack_entry = (__T656513720.next);  }
} void _ZNSt13bad_exceptionC2Ev( struct _ZSt13bad_exception *const this) {  _ZNSt13bad_exceptionC1Ev(this);  }


void _ZNSt13bad_exceptionC1ERKS_( struct _ZSt13bad_exception *const this,  const struct _ZSt13bad_exception *__3082_51_rhs)




{ static struct __C8 __T656637328[1] = {{((void (*)())(&_ZNSt9exceptionD2Ev)),((unsigned short)0U),((unsigned short)65535U),((unsigned char)64U)}}; auto void *__T656523520[1]; auto struct __C7 __T656527400;  (__T656527400.next) = __curr_eh_stack_entry; __curr_eh_stack_entry = (&__T656527400); (
#line 89
__T656527400.kind) = ((unsigned char)1U); (((__T656527400.variant).function).regions) = (__T656637328); (((__T656527400.variant).function).obj_table) = (__T656523520); (((__T656527400.variant).function).saved_region_number) = __eh_curr_region; __eh_curr_region = ((unsigned short)65535U);
#line 85
_ZNSt9exceptionC2ERKS_((&(this->__b_St9exception)), (&(__3082_51_rhs->__b_St9exception))); ((__T656523520)[0ULL]) = ((void *)(&(this->__b_St9exception))); __eh_curr_region = ((unsigned short)0U); ((this->__b_St9exception).__vptr) = (_ZTVSt13bad_exception + 2); { __eh_curr_region = (((__T656527400.
#line 85
variant).function).saved_region_number); __curr_eh_stack_entry = (__T656527400.next);  }




} void _ZNSt13bad_exceptionC2ERKS_( struct _ZSt13bad_exception *const this,  const struct _ZSt13bad_exception *__T656577776) {  _ZNSt13bad_exceptionC1ERKS_(this, __T656577776);  }


struct _ZSt13bad_exception *_ZNSt13bad_exceptionaSERKS_( struct _ZSt13bad_exception *const this,  const struct _ZSt13bad_exception *__3091_62_rhs)




{

_ZNSt9exceptionaSERKS_((&(this->__b_St9exception)), (&(__3091_62_rhs->__b_St9exception)));
return this;
}


void _ZNSt13bad_exceptionD1Ev( struct _ZSt13bad_exception *const this)



{ static struct __C8 __T656642248[1] = {{((void (*)())(&_ZNSt9exceptionD2Ev)),((unsigned short)0U),((unsigned short)65535U),((unsigned char)64U)}}; auto void *__T656540432[1]; auto struct __C7 __T656543520;  (__T656543520.next) = __curr_eh_stack_entry; __curr_eh_stack_entry = (&__T656543520); (
#line 109
__T656543520.kind) = ((unsigned char)1U); (((__T656543520.variant).function).regions) = (__T656642248); (((__T656543520.variant).function).obj_table) = (__T656540432); (((__T656543520.variant).function).saved_region_number) = __eh_curr_region; __eh_curr_region = ((unsigned short)65535U); ((this->
#line 109
__b_St9exception).__vptr) = (_ZTVSt13bad_exception + 2); ((__T656540432)[0ULL]) = ((void *)(&(this->__b_St9exception))); __eh_curr_region = ((unsigned short)0U); { __eh_curr_region = ((unsigned short)65535U);
_ZNSt9exceptionD2Ev((&(this->__b_St9exception))); } { __eh_curr_region = (((__T656543520.variant).function).saved_region_number); __curr_eh_stack_entry = (__T656543520.next);  } } void _ZNSt13bad_exceptionD0Ev( struct _ZSt13bad_exception *const this) {  _ZNSt13bad_exceptionD1Ev(this); _ZdlPvy(((void
#line 110
 *)this), 8ULL);  } void _ZNSt13bad_exceptionD2Ev( struct _ZSt13bad_exception *const this) {  _ZNSt13bad_exceptionD1Ev(this);  }


const char *_ZNKSt13bad_exception4whatEv( const struct _ZSt13bad_exception *const this)




{ auto const char *__T656551344;  {
__T656551344 = ((const char *)("")); return __T656551344; }
}
