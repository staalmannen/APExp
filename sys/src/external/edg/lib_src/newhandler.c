/* Translated by the Edison Design Group C++/C front end (version 7.0) */
/* Wed Oct  7 03:19:06 2026 */
extern int __EDGCPFE__7_0;
void *memcpy(void *,const void *,unsigned long);
void *memset(void *,int,unsigned long);

# 1 "lib_src/newhandler.c"
struct __EDG_type_info; struct __class_type_info; struct __si_class_type_info;
# 22 "include_c++/exception.stdh" 3
struct _ZSt9exception;
# 41 "include_c++/new.stdh" 3
struct _ZSt9bad_alloc;
# 50
struct _ZSt20bad_array_new_length; struct __EDG_type_info { const long *__vptr; const char *__name;}; struct __class_type_info { struct __EDG_type_info base;}; struct __si_class_type_info { struct __class_type_info base; const struct __class_type_info *base_type;};
# 22 "include_c++/exception.stdh" 3
struct _ZSt9exception { const long *__vptr;};
# 41 "include_c++/new.stdh" 3
struct _ZSt9bad_alloc { struct _ZSt9exception __b_St9exception;};
# 50
struct _ZSt20bad_array_new_length { struct _ZSt9bad_alloc __b_St9bad_alloc;};
# 17 "lib_src/newhandler.c"
extern void _Z21__default_new_handlerv(void); extern void *__throw_setup_dtor(const void *, unsigned long, unsigned, void (*)(void *)); extern __attribute__((__noreturn__)) void __throw(void);
# 35
extern void __throw_bad_array_new_length(void);
# 43 "include_c++/new.stdh" 3
extern __attribute__((__nothrow__)) void _ZNSt9bad_allocC1Ev(struct _ZSt9bad_alloc *const);


extern __attribute__((__nothrow__)) void _ZNSt9bad_allocD1Ev(struct _ZSt9bad_alloc *const);
# 52
extern __attribute__((__nothrow__)) void _ZNSt20bad_array_new_lengthC1Ev(struct _ZSt20bad_array_new_length *const);
extern __attribute__((__nothrow__)) void _ZNSt20bad_array_new_lengthD1Ev(struct _ZSt20bad_array_new_length *const); extern const struct __si_class_type_info _ZTISt9bad_alloc; extern const struct __si_class_type_info _ZTISt20bad_array_new_length;
# 17 "lib_src/newhandler.c"
void _Z21__default_new_handlerv(void)
# 25
{ auto struct _ZSt9bad_alloc *__T1046090072;

(__T1046090072 = ((struct _ZSt9bad_alloc *)(__throw_setup_dtor(((const void *)(&_ZTISt9bad_alloc)), 8UL, 0U, ((void (*)(void *))_ZNSt9bad_allocD1Ev))))) , ((_ZNSt9bad_allocC1Ev(__T1046090072)) , (__throw()));



}



void __throw_bad_array_new_length(void)
# 41
{ auto struct _ZSt20bad_array_new_length *__T1046093064;
(__T1046093064 = ((struct _ZSt20bad_array_new_length *)(__throw_setup_dtor(((const void *)(&_ZTISt20bad_array_new_length)), 8UL, 0U, ((void (*)(void *))_ZNSt20bad_array_new_lengthD1Ev))))) , ((_ZNSt20bad_array_new_lengthC1Ev(__T1046093064)) , (__throw()));
}
