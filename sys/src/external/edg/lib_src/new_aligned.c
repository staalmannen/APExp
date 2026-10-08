/* Translated by the Edison Design Group C++/C front end (version 7.0) */
/* Thu Oct  8 07:53:17 2026 */
extern int __EDGCPFE__7_0;
void *memcpy(void *,const void *,unsigned long long);
void *memset(void *,int,unsigned long long);

#line 1 "lib_src/new_aligned.c"
#line 10 "ape-arch/stddef_arch.h"
typedef unsigned long long size_t;
#line 58 "include_c++/new.stdh"
typedef void (*_ZSt11new_handler)(void);
#line 113 "ape-sys/stdlib.h"
extern int posix_memalign(void **, size_t, size_t);
#line 207 "lib_src/runtime.h"
extern void _Z21__default_new_handlerv(void);
#line 22 "lib_src/new_aligned.c"
extern void *_ZnwySt11align_val_t(size_t size, unsigned long long align);
#line 211 "lib_src/runtime.h"
extern _ZSt11new_handler _new_handler;
#line 22 "lib_src/new_aligned.c"
void *_ZnwySt11align_val_t( size_t __3020_34_size, 
unsigned long long __3021_54_align)
#line 36
{ auto size_t __T225486752; auto size_t __T225487400;
auto void *__3035_9_ptr;

if (__3020_34_size == 0ULL) { __3020_34_size = 1ULL; }
while ((__3035_9_ptr = ((void *)((((__T225486752 = ((size_t)__3021_54_align)) , (__T225487400 = __3020_34_size)) , (posix_memalign((&__3035_9_ptr), __T225486752, __T225487400))) ? ((void *)0) : __3035_9_ptr))) == ((void *)0))
{



auto _ZSt11new_handler __3043_32_new_handler;
__3043_32_new_handler = ((_new_handler != ((_ZSt11new_handler)0)) ? _new_handler : _Z21__default_new_handlerv);
(*__3043_32_new_handler)();
#line 59
}
return __3035_9_ptr;
}
