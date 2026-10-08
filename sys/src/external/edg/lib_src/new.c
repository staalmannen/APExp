/* Translated by the Edison Design Group C++/C front end (version 7.0) */
/* Thu Oct  8 07:53:17 2026 */
extern int __EDGCPFE__7_0;
void *memcpy(void *,const void *,unsigned long long);
void *memset(void *,int,unsigned long long);

#line 1 "lib_src/new.c"
#line 10 "ape-arch/stddef_arch.h"
typedef unsigned long long size_t;
#line 58 "include_c++/new.stdh"
typedef void (*_ZSt11new_handler)(void);
#line 67 "ape-sys/stdlib.h"
extern void *malloc(size_t);
#line 207 "lib_src/runtime.h"
extern void _Z21__default_new_handlerv(void);
#line 20 "lib_src/new.c"
extern void *_Znwy(size_t size);
#line 211 "lib_src/runtime.h"
extern _ZSt11new_handler _new_handler;
#line 20 "lib_src/new.c"
void *_Znwy( size_t __3018_34_size)
#line 34
{
auto void *__3033_9_ptr;

if (__3018_34_size == 0ULL) { __3018_34_size = 1ULL; }
while ((__3033_9_ptr = ((void *)(malloc(__3018_34_size)))) == ((void *)0)) {



auto _ZSt11new_handler __3040_32_new_handler;
__3040_32_new_handler = ((_new_handler != ((_ZSt11new_handler)0)) ? _new_handler : _Z21__default_new_handlerv);
(*__3040_32_new_handler)();
#line 56
}
return __3033_9_ptr;
}
