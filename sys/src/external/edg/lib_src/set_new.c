/* Translated by the Edison Design Group C++/C front end (version 7.0) */
/* Wed Oct  7 03:19:06 2026 */
extern int __EDGCPFE__7_0;
void *memcpy(void *,const void *,unsigned long);
void *memset(void *,int,unsigned long);

# 1 "lib_src/set_new.c"
# 58 "include_c++/new.stdh" 3
typedef void (*_ZSt11new_handler)(void);
# 31 "lib_src/set_new.c"
extern __attribute__((__nothrow__)) _ZSt11new_handler _ZSt15set_new_handlerPFvvE(_ZSt11new_handler handler);
# 43
extern __attribute__((__nothrow__)) _ZSt11new_handler _ZSt15get_new_handlerv(void);
# 211 "lib_src/runtime.h"
extern _ZSt11new_handler _new_handler;
# 31 "lib_src/set_new.c"
__attribute__((__nothrow__)) _ZSt11new_handler _ZSt15set_new_handlerPFvvE( _ZSt11new_handler __11020_41_handler)




{ auto _ZSt11new_handler __T185222784;
auto _ZSt11new_handler __11026_15_rr; __11026_15_rr = _new_handler;
_new_handler = __11020_41_handler; {
__T185222784 = __11026_15_rr; return __T185222784; }
}


__attribute__((__nothrow__)) _ZSt11new_handler _ZSt15get_new_handlerv(void)



{ auto _ZSt11new_handler __T185224328;  {
__T185224328 = _new_handler; return __T185224328; }
}
