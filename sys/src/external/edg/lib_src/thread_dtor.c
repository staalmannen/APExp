/* Translated by the Edison Design Group C++/C front end (version 7.0) */
/* Wed Oct  7 03:19:07 2026 */
extern int __EDGCPFE__7_0;
void *memcpy(void *,const void *,unsigned long);
void *memset(void *,int,unsigned long);

# 1 "lib_src/thread_dtor.c"
# 28 "lib_src/dtor_list.h"
struct a_needed_destruction;
# 49 "/usr/include/x86_64-linux-gnu/bits/pthreadtypes.h" 3
typedef unsigned pthread_key_t;
# 132 "lib_src/runtime.h"
typedef void (*a_cxa_dtor_ptr)(void *);
# 217
typedef void *a_dso_handle;
# 27 "lib_src/dtor_list.h"
typedef struct a_needed_destruction *a_needed_destruction_ptr;
# 182 "include_c++/cxxabi.h" 3
extern int __cxa_atexit(void (*)(void *), void *, void *);
# 74 "lib_src/dtor_list.h"
extern void _Z23__finalize_destructionsPP20a_needed_destructionPv(a_needed_destruction_ptr *destruction_list, a_dso_handle dso_handle);


extern int _Z25__add_destruction_to_listPP20a_needed_destructionPFvPvES2_S2_(a_needed_destruction_ptr *destruction_list, a_cxa_dtor_ptr destruction_routine, void *object, a_dso_handle dso_handle);
# 1297 "/usr/include/pthread.h" 3
extern __attribute__((__nothrow__)) int pthread_key_create(pthread_key_t *__key, void (*__destr_function)(void *));
# 1308
extern __attribute__((__nothrow__)) int pthread_setspecific(pthread_key_t __key, const void *__pointer);
# 28 "lib_src/thread_dtor.c"
static void _ZN35_INTERNAL_13_thread_dtor_c_d6dc8ad719__thread_terminatedEPv(void *unused); extern __attribute__((__weak__)) a_needed_destruction_ptr *_ZTW32__thread_needed_destruction_head(void); extern __attribute__((__weak__)) void _ZTH32__thread_needed_destruction_head(void);
# 46
static int _ZN35_INTERNAL_13_thread_dtor_c_d6dc8ad738__thread_register_finalization_routineEv(void);
# 100
static void _ZN35_INTERNAL_13_thread_dtor_c_d6dc8ad736finalize_current_thread_destructionsEPv(void *unused);
# 117
extern int __cxa_thread_atexit(a_cxa_dtor_ptr destruction_routine, void *object, a_dso_handle dso_handle);
# 87 "lib_src/dtor_list.h"
extern __thread a_needed_destruction_ptr __thread_needed_destruction_head;
# 137 "lib_src/thread_dtor.c"
static int _ZZ19__cxa_thread_atexitE4once;
# 59
static __thread pthread_key_t _ZZN35_INTERNAL_13_thread_dtor_c_d6dc8ad738__thread_register_finalization_routineEvE11pthread_key;
# 137
static int _ZZ19__cxa_thread_atexitE4once = 0;
# 28
static void _ZN35_INTERNAL_13_thread_dtor_c_d6dc8ad719__thread_terminatedEPv( void *__14739_39_unused)
# 34
{



_Z23__finalize_destructionsPP20a_needed_destructionPv((_ZTW32__thread_needed_destruction_head()), ((a_dso_handle)0)); 

} __attribute__((__weak__)) a_needed_destruction_ptr *_ZTW32__thread_needed_destruction_head(void) {  if (_ZTH32__thread_needed_destruction_head) {
# 38
_ZTH32__thread_needed_destruction_head(); } return &__thread_needed_destruction_head; }
# 46
static int _ZN35_INTERNAL_13_thread_dtor_c_d6dc8ad738__thread_register_finalization_routineEv(void)
# 57
{


auto int __14771_7_result; __14771_7_result = (pthread_key_create((&_ZZN35_INTERNAL_13_thread_dtor_c_d6dc8ad738__thread_register_finalization_routineEvE11pthread_key), (&_ZN35_INTERNAL_13_thread_dtor_c_d6dc8ad719__thread_terminatedEPv)));
if (__14771_7_result == 0) { auto pthread_key_t __T283854568; auto const void *__T283855776;


__14771_7_result = (((__T283854568 = _ZZN35_INTERNAL_13_thread_dtor_c_d6dc8ad738__thread_register_finalization_routineEvE11pthread_key) , (__T283855776 = ((const void *)(&_ZZN35_INTERNAL_13_thread_dtor_c_d6dc8ad738__thread_register_finalization_routineEvE11pthread_key)))) , (pthread_setspecific(
# 64
__T283854568, __T283855776)));
}
return __14771_7_result;



}
# 100
static void _ZN35_INTERNAL_13_thread_dtor_c_d6dc8ad736finalize_current_thread_destructionsEPv( void *__14811_56_unused)
# 111
{
_Z23__finalize_destructionsPP20a_needed_destructionPv((_ZTW32__thread_needed_destruction_head()), ((a_dso_handle)0)); 
}



int __cxa_thread_atexit( a_cxa_dtor_ptr __14828_57_destruction_routine, 
void *__14829_58_object, 
a_dso_handle __14830_57_dso_handle)
# 133
{
auto int __14845_7_result = 0;



if (!(_ZZ19__cxa_thread_atexitE4once)) {




_ZZ19__cxa_thread_atexitE4once = 1;
__cxa_atexit((&_ZN35_INTERNAL_13_thread_dtor_c_d6dc8ad736finalize_current_thread_destructionsEPv), ((void *)0), ((void *)0));

}

if ((*(_ZTW32__thread_needed_destruction_head())) == ((a_needed_destruction_ptr)0)) {

if ((_ZN35_INTERNAL_13_thread_dtor_c_d6dc8ad738__thread_register_finalization_routineEv()) != 0) {
__14845_7_result = 1;
}
}
if (__14845_7_result == 0) { auto a_needed_destruction_ptr *__T283851216; auto a_cxa_dtor_ptr __T283852136; auto void *__T283852872; auto a_dso_handle __T283853608;
__14845_7_result = (((((__T283851216 = (_ZTW32__thread_needed_destruction_head())) , (__T283852136 = __14828_57_destruction_routine)) , (__T283852872 = __14829_58_object)) , (__T283853608 = __14830_57_dso_handle)) , (_Z25__add_destruction_to_listPP20a_needed_destructionPFvPvES2_S2_(__T283851216, 
# 155
__T283852136, __T283852872, __T283853608)));


}
return __14845_7_result;
}
