/* Translated by the Edison Design Group C++/C front end (version 7.0) */
/* Thu Oct  8 07:53:17 2026 */
extern int __EDGCPFE__7_0;
void *memcpy(void *,const void *,unsigned long long);
void *memset(void *,int,unsigned long long);

#line 1 "lib_src/newhandler.c"
struct __EDG_type_info; struct __class_type_info; struct __si_class_type_info;
#line 22 "include_c++/exception.stdh"
struct _ZSt9exception;
#line 41 "include_c++/new.stdh"
struct _ZSt9bad_alloc;
#line 50
struct _ZSt20bad_array_new_length; struct __EDG_type_info { const long long *__vptr; const char *__name;}; struct __class_type_info { struct __EDG_type_info base;}; struct __si_class_type_info { struct __class_type_info base; const struct __class_type_info *base_type;};
#line 22 "include_c++/exception.stdh"
struct _ZSt9exception { const long long *__vptr;};
#line 41 "include_c++/new.stdh"
struct _ZSt9bad_alloc { struct _ZSt9exception __b_St9exception;};
#line 50
struct _ZSt20bad_array_new_length { struct _ZSt9bad_alloc __b_St9bad_alloc;};
#line 17 "lib_src/newhandler.c"
extern void _Z21__default_new_handlerv(void); extern void *__throw_setup_dtor(const void *, unsigned long long, unsigned, void (*)(void *)); extern void __throw(void);
#line 35
extern void __throw_bad_array_new_length(void);
#line 43 "include_c++/new.stdh"
extern void _ZNSt9bad_allocC1Ev(struct _ZSt9bad_alloc *const);


extern void _ZNSt9bad_allocD1Ev(struct _ZSt9bad_alloc *const);
#line 52
extern void _ZNSt20bad_array_new_lengthC1Ev(struct _ZSt20bad_array_new_length *const);
extern void _ZNSt20bad_array_new_lengthD1Ev(struct _ZSt20bad_array_new_length *const); extern const struct __si_class_type_info _ZTISt9bad_alloc; extern const struct __si_class_type_info _ZTISt20bad_array_new_length;
#line 17 "lib_src/newhandler.c"
void _Z21__default_new_handlerv(void)
#line 25
{ auto struct _ZSt9bad_alloc *__T988067528;

(__T988067528 = ((struct _ZSt9bad_alloc *)(__throw_setup_dtor(((const void *)(&_ZTISt9bad_alloc)), 8ULL, 0U, ((void (*)(void *))_ZNSt9bad_allocD1Ev))))) , ((_ZNSt9bad_allocC1Ev(__T988067528)) , (__throw()));



}



void __throw_bad_array_new_length(void)
#line 41
{ auto struct _ZSt20bad_array_new_length *__T988070520;
(__T988070520 = ((struct _ZSt20bad_array_new_length *)(__throw_setup_dtor(((const void *)(&_ZTISt20bad_array_new_length)), 8ULL, 0U, ((void (*)(void *))_ZNSt20bad_array_new_lengthD1Ev))))) , ((_ZNSt20bad_array_new_lengthC1Ev(__T988070520)) , (__throw()));
}
