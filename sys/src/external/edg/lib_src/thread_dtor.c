/* Translated by the Edison Design Group C++/C front end (version 7.0) */
/* Wed Oct  7 07:14:44 2026 */
extern int __EDGCPFE__7_0;
void *memcpy(void *,const void *,unsigned long long);
void *memset(void *,int,unsigned long long);

#line 1 "lib_src/thread_dtor.c"
#line 28 "lib_src/dtor_list.h"
struct a_needed_destruction;
#line 8 "ape-sys/lock.h"
struct Lock;
#line 59 "ape-sys/pthread.h"
struct _ZN11pthread_keyUt_E;
#line 56
struct pthread_key;
#line 132 "lib_src/runtime.h"
typedef void (*a_cxa_dtor_ptr)(void *);
#line 217
typedef void *a_dso_handle;
#line 27 "lib_src/dtor_list.h"
typedef struct a_needed_destruction *a_needed_destruction_ptr;
#line 14 "ape-sys/pthread.h"
typedef struct pthread_key pthread_key_t;
#line 8 "ape-sys/lock.h"
struct Lock {
int val;};
typedef struct Lock Lock;
#line 56 "ape-sys/pthread.h"
struct pthread_key {
Lock l;
void (*destroy)(void *);



struct _ZN11pthread_keyUt_E *arenas;
int n;char __dummy[4];};
#line 182 "include_c++/cxxabi.h"
extern int __cxa_atexit(void (*)(void *), void *, void *);
#line 74 "lib_src/dtor_list.h"
extern void _Z23__finalize_destructionsPP20a_needed_destructionPv(a_needed_destruction_ptr *destruction_list, a_dso_handle dso_handle);


extern int _Z25__add_destruction_to_listPP20a_needed_destructionPFvPvES2_S2_(a_needed_destruction_ptr *destruction_list, a_cxa_dtor_ptr destruction_routine, void *object, a_dso_handle dso_handle);
#line 117 "ape-sys/pthread.h"
extern int pthread_key_create(pthread_key_t *, void (*)(void *));


extern int pthread_setspecific(pthread_key_t, const void *);
#line 28 "lib_src/thread_dtor.c"
static void _ZN35_INTERNAL_13_thread_dtor_c_d6dc8ad719__thread_terminatedEPv(void *unused); extern a_needed_destruction_ptr *_ZTW32__thread_needed_destruction_head(void); extern void _ZTH32__thread_needed_destruction_head(void);
#line 46
static int _ZN35_INTERNAL_13_thread_dtor_c_d6dc8ad738__thread_register_finalization_routineEv(void);
#line 100
static void _ZN35_INTERNAL_13_thread_dtor_c_d6dc8ad736finalize_current_thread_destructionsEPv(void *unused);
#line 117
extern int __cxa_thread_atexit(a_cxa_dtor_ptr destruction_routine, void *object, a_dso_handle dso_handle);
#line 87 "lib_src/dtor_list.h"
extern __thread a_needed_destruction_ptr __thread_needed_destruction_head;
#line 137 "lib_src/thread_dtor.c"
static int _ZZ19__cxa_thread_atexitE4once;
#line 59
static __thread pthread_key_t _ZZN35_INTERNAL_13_thread_dtor_c_d6dc8ad738__thread_register_finalization_routineEvE11pthread_key;
#line 137
static int _ZZ19__cxa_thread_atexitE4once = 0;
#line 28
static void _ZN35_INTERNAL_13_thread_dtor_c_d6dc8ad719__thread_terminatedEPv( void *__4375_39_unused)
#line 34
{



_Z23__finalize_destructionsPP20a_needed_destructionPv((_ZTW32__thread_needed_destruction_head()), ((a_dso_handle)0)); 

} a_needed_destruction_ptr *_ZTW32__thread_needed_destruction_head(void) {  if (_ZTH32__thread_needed_destruction_head) {
#line 38
_ZTH32__thread_needed_destruction_head(); } return &__thread_needed_destruction_head; }
#line 46
static int _ZN35_INTERNAL_13_thread_dtor_c_d6dc8ad738__thread_register_finalization_routineEv(void)
#line 57
{


auto int __4407_7_result; __4407_7_result = (pthread_key_create((&_ZZN35_INTERNAL_13_thread_dtor_c_d6dc8ad738__thread_register_finalization_routineEvE11pthread_key), (&_ZN35_INTERNAL_13_thread_dtor_c_d6dc8ad719__thread_terminatedEPv)));
if (__4407_7_result == 0) { auto pthread_key_t __T779357280; auto const void *__T779358488;


__4407_7_result = (((__T779357280 = _ZZN35_INTERNAL_13_thread_dtor_c_d6dc8ad738__thread_register_finalization_routineEvE11pthread_key) , (__T779358488 = ((const void *)(&_ZZN35_INTERNAL_13_thread_dtor_c_d6dc8ad738__thread_register_finalization_routineEvE11pthread_key)))) , (pthread_setspecific(
#line 64
__T779357280, __T779358488)));
}
return __4407_7_result;



}
#line 100
static void _ZN35_INTERNAL_13_thread_dtor_c_d6dc8ad736finalize_current_thread_destructionsEPv( void *__4447_56_unused)
#line 111
{
_Z23__finalize_destructionsPP20a_needed_destructionPv((_ZTW32__thread_needed_destruction_head()), ((a_dso_handle)0)); 
}



int __cxa_thread_atexit( a_cxa_dtor_ptr __4464_57_destruction_routine, 
void *__4465_58_object, 
a_dso_handle __4466_57_dso_handle)
#line 133
{
auto int __4481_7_result = 0;



if (!(_ZZ19__cxa_thread_atexitE4once)) {




_ZZ19__cxa_thread_atexitE4once = 1;
__cxa_atexit((&_ZN35_INTERNAL_13_thread_dtor_c_d6dc8ad736finalize_current_thread_destructionsEPv), ((void *)0), ((void *)0));

}

if ((*(_ZTW32__thread_needed_destruction_head())) == ((a_needed_destruction_ptr)0)) {

if ((_ZN35_INTERNAL_13_thread_dtor_c_d6dc8ad738__thread_register_finalization_routineEv()) != 0) {
__4481_7_result = 1;
}
}
if (__4481_7_result == 0) { auto a_needed_destruction_ptr *__T779353928; auto a_cxa_dtor_ptr __T779354848; auto void *__T779355584; auto a_dso_handle __T779356320;
__4481_7_result = (((((__T779353928 = (_ZTW32__thread_needed_destruction_head())) , (__T779354848 = __4464_57_destruction_routine)) , (__T779355584 = __4465_58_object)) , (__T779356320 = __4466_57_dso_handle)) , (_Z25__add_destruction_to_listPP20a_needed_destructionPFvPvES2_S2_(__T779353928, 
#line 155
__T779354848, __T779355584, __T779356320)));


}
return __4481_7_result;
}
