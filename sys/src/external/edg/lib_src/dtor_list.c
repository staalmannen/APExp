/* Translated by the Edison Design Group C++/C front end (version 7.0) */
/* Wed Oct  7 03:19:05 2026 */
extern int __EDGCPFE__7_0;
void *memcpy(void *,const void *,unsigned long);
void *memset(void *,int,unsigned long);

# 1 "lib_src/dtor_list.c"
# 28 "lib_src/dtor_list.h"
struct a_needed_destruction;
# 214 "/usr/lib/gcc/x86_64-linux-gnu/13/include/stddef.h" 3
typedef unsigned long size_t;
# 127 "lib_src/runtime.h"
typedef void (*a_destructor_ptr)(void *);




typedef void (*a_cxa_dtor_ptr)(void *);
# 217
typedef void *a_dso_handle;
# 27 "lib_src/dtor_list.h"
typedef struct a_needed_destruction *a_needed_destruction_ptr;
struct a_needed_destruction {

a_needed_destruction_ptr next;

void *object;
# 44
a_destructor_ptr destruction_routine;
# 50
a_dso_handle dso_handle;};
# 672 "/usr/include/stdlib.h" 3
extern __attribute__((__alloc_size__(1))) __attribute__((__malloc__)) __attribute__((__nothrow__)) void *malloc(size_t __size);
# 687
extern __attribute__((__nothrow__)) void free(void *__ptr);
# 196 "lib_src/dtor_list.c"
extern void _Z23__finalize_destructionsPP20a_needed_destructionPv(a_needed_destruction_ptr *destruction_list, a_dso_handle dso_handle);
# 233
extern int _Z25__add_destruction_to_listPP20a_needed_destructionPFvPvES2_S2_(a_needed_destruction_ptr *destruction_list, a_cxa_dtor_ptr destruction_routine, void *object, a_dso_handle dso_handle);
# 42
__thread a_needed_destruction_ptr __thread_needed_destruction_head = 0;
# 196
void _Z23__finalize_destructionsPP20a_needed_destructionPv( a_needed_destruction_ptr *__11364_56_destruction_list, 
a_dso_handle __11365_55_dso_handle)
# 203
{
auto a_needed_destruction_ptr *__11372_29_ndpp; auto a_needed_destruction_ptr __11372_35_ndp; auto a_needed_destruction_ptr __11372_40_old_head;

__11372_29_ndpp = __11364_56_destruction_list;
while ((*__11372_29_ndpp) != ((a_needed_destruction_ptr)0)) {
__11372_35_ndp = (*__11372_29_ndpp);

if ((__11365_55_dso_handle != ((a_dso_handle)0)) && ((__11372_35_ndp->dso_handle) != __11365_55_dso_handle)) {
__11372_29_ndpp = (&(__11372_35_ndp->next));
goto __T73398368;
}




(*__11372_29_ndpp) = (__11372_35_ndp->next);
__11372_40_old_head = (*__11364_56_destruction_list);

(*(__11372_35_ndp->destruction_routine))((__11372_35_ndp->object));

free(((void *)__11372_35_ndp));


if ((*__11364_56_destruction_list) != __11372_40_old_head) {
__11372_29_ndpp = __11364_56_destruction_list;
} __T73398368:;
} 
}


int _Z25__add_destruction_to_listPP20a_needed_destructionPFvPvES2_S2_( a_needed_destruction_ptr *__11401_57_destruction_list, 
a_cxa_dtor_ptr __11402_56_destruction_routine, 
void *__11403_57_object, 
a_dso_handle __11404_56_dso_handle)
# 244
{
auto int __11413_28_success = 1;
auto a_needed_destruction_ptr __11414_28_ndp;

__11414_28_ndp = ((a_needed_destruction_ptr)(malloc(32UL)));
if (__11414_28_ndp == ((a_needed_destruction_ptr)0)) {
__11413_28_success = 0;
} else  {
(__11414_28_ndp->object) = __11403_57_object;
(__11414_28_ndp->destruction_routine) = ((a_destructor_ptr)__11402_56_destruction_routine);
(__11414_28_ndp->dso_handle) = __11404_56_dso_handle;
(__11414_28_ndp->next) = (*__11401_57_destruction_list);
(*__11401_57_destruction_list) = __11414_28_ndp;
}
return (int)(!(__11413_28_success));
}
