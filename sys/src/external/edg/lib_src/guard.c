/* Translated by the Edison Design Group C++/C front end (version 7.0) */
/* Thu Oct  8 07:53:17 2026 */
extern int __EDGCPFE__7_0;
void *memcpy(void *,const void *,unsigned long long);
void *memset(void *,int,unsigned long long);

#line 1 "lib_src/guard.c"
#line 228 "lib_src/runtime.h"
typedef unsigned long long an_ia64_guard;


typedef an_ia64_guard *an_ia64_guard_ptr;
#line 83 "lib_src/guard.c"
extern int __cxa_guard_acquire(an_ia64_guard_ptr guard);
#line 99
extern void __cxa_guard_release(an_ia64_guard_ptr guard);
#line 111
extern void __cxa_guard_abort(an_ia64_guard_ptr guard);
#line 83
int __cxa_guard_acquire( an_ia64_guard_ptr __3081_67_guard)




{
auto char *__3087_9_first_byte;
auto int __3088_8_initialize = 0;
#line 89
__3087_9_first_byte = ((char *)__3081_67_guard);


if (((int)(*__3087_9_first_byte)) == 0) {
__3088_8_initialize = 1;
}
return __3088_8_initialize;
}


void __cxa_guard_release( an_ia64_guard_ptr __3097_68_guard)



{


auto char *__3104_9_first_byte; __3104_9_first_byte = ((char *)__3097_68_guard);
(*__3104_9_first_byte) = ((char)1); 
}


void __cxa_guard_abort( an_ia64_guard_ptr __3109_66_guard)
#line 117
{
(*((char *)__3109_66_guard)) = ((char)0); 
}
