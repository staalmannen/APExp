/* Translated by the Edison Design Group C++/C front end (version 7.0) */
/* Wed Oct  7 03:19:05 2026 */
extern int __EDGCPFE__7_0;
void *memcpy(void *,const void *,unsigned long);
void *memset(void *,int,unsigned long);

# 1 "lib_src/new.c"
# 214 "/usr/lib/gcc/x86_64-linux-gnu/13/include/stddef.h" 3
typedef unsigned long size_t;
# 58 "include_c++/new.stdh" 3
typedef void (*_ZSt11new_handler)(void);
# 672 "/usr/include/stdlib.h" 3
extern __attribute__((__alloc_size__(1))) __attribute__((__malloc__)) __attribute__((__nothrow__)) void *malloc(size_t __size);
# 207 "lib_src/runtime.h"
extern void _Z21__default_new_handlerv(void);
# 20 "lib_src/new.c"
extern void *_Znwm(size_t size);
# 211 "lib_src/runtime.h"
extern _ZSt11new_handler _new_handler;
# 20 "lib_src/new.c"
void *_Znwm( size_t __11009_34_size)
# 34
{
auto void *__11024_9_ptr;

if (__11009_34_size == 0UL) { __11009_34_size = 1UL; }
while ((__11024_9_ptr = ((void *)(malloc(__11009_34_size)))) == ((void *)0)) {



auto _ZSt11new_handler __11031_32_new_handler;
__11031_32_new_handler = ((_new_handler != ((_ZSt11new_handler)0)) ? _new_handler : _Z21__default_new_handlerv);
(*__11031_32_new_handler)();
# 56
}
return __11024_9_ptr;
}
