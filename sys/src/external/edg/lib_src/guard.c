/* Translated by the Edison Design Group C++/C front end (version 7.0) */
/* Wed Oct  7 03:19:05 2026 */
extern int __EDGCPFE__7_0;
void *memcpy(void *,const void *,unsigned long);
void *memset(void *,int,unsigned long);

# 1 "lib_src/guard.c"
# 228 "lib_src/runtime.h"
typedef unsigned long long an_ia64_guard;


typedef an_ia64_guard *an_ia64_guard_ptr;
# 83 "lib_src/guard.c"
extern int __cxa_guard_acquire(an_ia64_guard_ptr guard);
# 99
extern void __cxa_guard_release(an_ia64_guard_ptr guard);
# 111
extern void __cxa_guard_abort(an_ia64_guard_ptr guard);
# 83
int __cxa_guard_acquire( an_ia64_guard_ptr __11072_67_guard)




{
auto char *__11078_9_first_byte;
auto int __11079_8_initialize = 0;
# 89
__11078_9_first_byte = ((char *)__11072_67_guard);


if (((int)(*__11078_9_first_byte)) == 0) {
__11079_8_initialize = 1;
}
return __11079_8_initialize;
}


void __cxa_guard_release( an_ia64_guard_ptr __11088_68_guard)



{


auto char *__11095_9_first_byte; __11095_9_first_byte = ((char *)__11088_68_guard);
(*__11095_9_first_byte) = ((char)1); 
}


void __cxa_guard_abort( an_ia64_guard_ptr __11100_66_guard)
# 117
{
(*((char *)__11100_66_guard)) = ((char)0); 
}
