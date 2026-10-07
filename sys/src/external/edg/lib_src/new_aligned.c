/* Translated by the Edison Design Group C++/C front end (version 7.0) */
/* Wed Oct  7 03:19:06 2026 */
extern int __EDGCPFE__7_0;
void *memcpy(void *,const void *,unsigned long);
void *memset(void *,int,unsigned long);

# 1 "lib_src/new_aligned.c"
# 214 "/usr/lib/gcc/x86_64-linux-gnu/13/include/stddef.h" 3
typedef unsigned long size_t;
# 58 "include_c++/new.stdh" 3
typedef void (*_ZSt11new_handler)(void);
# 718 "/usr/include/stdlib.h" 3
extern __attribute__((__nothrow__)) int posix_memalign(void **__memptr, size_t __alignment, size_t __size);
# 207 "lib_src/runtime.h"
extern void _Z21__default_new_handlerv(void);
# 22 "lib_src/new_aligned.c"
extern void *_ZnwmSt11align_val_t(size_t size, unsigned long align);
# 211 "lib_src/runtime.h"
extern _ZSt11new_handler _new_handler;
# 22 "lib_src/new_aligned.c"
void *_ZnwmSt11align_val_t( size_t __11011_34_size, 
unsigned long __11012_54_align)
# 36
{ auto size_t __T157684272; auto size_t __T157684920;
auto void *__11026_9_ptr;

if (__11011_34_size == 0UL) { __11011_34_size = 1UL; }
while ((__11026_9_ptr = ((void *)((((__T157684272 = ((size_t)__11012_54_align)) , (__T157684920 = __11011_34_size)) , (posix_memalign((&__11026_9_ptr), __T157684272, __T157684920))) ? ((void *)0) : __11026_9_ptr))) == ((void *)0))
{



auto _ZSt11new_handler __11034_32_new_handler;
__11034_32_new_handler = ((_new_handler != ((_ZSt11new_handler)0)) ? _new_handler : _Z21__default_new_handlerv);
(*__11034_32_new_handler)();
# 59
}
return __11026_9_ptr;
}
