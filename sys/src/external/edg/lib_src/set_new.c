/* Translated by the Edison Design Group C++/C front end (version 7.0) */
/* Wed Oct  7 07:14:43 2026 */
extern int __EDGCPFE__7_0;
void *memcpy(void *,const void *,unsigned long long);
void *memset(void *,int,unsigned long long);

#line 1 "lib_src/set_new.c"
#line 58 "include_c++/new.stdh"
typedef void (*_ZSt11new_handler)(void);
#line 31 "lib_src/set_new.c"
extern _ZSt11new_handler _ZSt15set_new_handlerPFvvE(_ZSt11new_handler handler);
#line 43
extern _ZSt11new_handler _ZSt15get_new_handlerv(void);
#line 211 "lib_src/runtime.h"
extern _ZSt11new_handler _new_handler;
#line 31 "lib_src/set_new.c"
_ZSt11new_handler _ZSt15set_new_handlerPFvvE( _ZSt11new_handler __3001_41_handler)




{ auto _ZSt11new_handler __T419367552;
auto _ZSt11new_handler __3007_15_rr; __3007_15_rr = _new_handler;
_new_handler = __3001_41_handler; {
__T419367552 = __3007_15_rr; return __T419367552; }
}


_ZSt11new_handler _ZSt15get_new_handlerv(void)



{ auto _ZSt11new_handler __T419369096;  {
__T419369096 = _new_handler; return __T419369096; }
}
