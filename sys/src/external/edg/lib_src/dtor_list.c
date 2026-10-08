/* Translated by the Edison Design Group C++/C front end (version 7.0) */
/* Thu Oct  8 07:53:17 2026 */
extern int __EDGCPFE__7_0;
void *memcpy(void *,const void *,unsigned long long);
void *memset(void *,int,unsigned long long);

#line 1 "lib_src/dtor_list.c"
#line 28 "lib_src/dtor_list.h"
struct a_needed_destruction;
#line 10 "ape-arch/stddef_arch.h"
typedef unsigned long long size_t;
#line 127 "lib_src/runtime.h"
typedef void (*a_destructor_ptr)(void *);




typedef void (*a_cxa_dtor_ptr)(void *);
#line 217
typedef void *a_dso_handle;
#line 27 "lib_src/dtor_list.h"
typedef struct a_needed_destruction *a_needed_destruction_ptr;
struct a_needed_destruction {

a_needed_destruction_ptr next;

void *object;
#line 44
a_destructor_ptr destruction_routine;
#line 50
a_dso_handle dso_handle;};
#line 66 "ape-sys/stdlib.h"
extern void free(void *);
extern void *malloc(size_t);
#line 196 "lib_src/dtor_list.c"
extern void _Z23__finalize_destructionsPP20a_needed_destructionPv(a_needed_destruction_ptr *destruction_list, a_dso_handle dso_handle);
#line 233
extern int _Z25__add_destruction_to_listPP20a_needed_destructionPFvPvES2_S2_(a_needed_destruction_ptr *destruction_list, a_cxa_dtor_ptr destruction_routine, void *object, a_dso_handle dso_handle);
#line 42
__thread a_needed_destruction_ptr __thread_needed_destruction_head = 0;
#line 196
void _Z23__finalize_destructionsPP20a_needed_destructionPv( a_needed_destruction_ptr *__3373_56_destruction_list, 
a_dso_handle __3374_55_dso_handle)
#line 203
{
auto a_needed_destruction_ptr *__3381_29_ndpp; auto a_needed_destruction_ptr __3381_35_ndp; auto a_needed_destruction_ptr __3381_40_old_head;

__3381_29_ndpp = __3373_56_destruction_list;
while ((*__3381_29_ndpp) != ((a_needed_destruction_ptr)0)) {
__3381_35_ndp = (*__3381_29_ndpp);

if ((__3374_55_dso_handle != ((a_dso_handle)0)) && ((__3381_35_ndp->dso_handle) != __3374_55_dso_handle)) {
__3381_29_ndpp = (&(__3381_35_ndp->next));
goto __T1004178896;
}




(*__3381_29_ndpp) = (__3381_35_ndp->next);
__3381_40_old_head = (*__3373_56_destruction_list);

(*(__3381_35_ndp->destruction_routine))((__3381_35_ndp->object));

free(((void *)__3381_35_ndp));


if ((*__3373_56_destruction_list) != __3381_40_old_head) {
__3381_29_ndpp = __3373_56_destruction_list;
} __T1004178896:;
} 
}


int _Z25__add_destruction_to_listPP20a_needed_destructionPFvPvES2_S2_( a_needed_destruction_ptr *__3410_57_destruction_list, 
a_cxa_dtor_ptr __3411_56_destruction_routine, 
void *__3412_57_object, 
a_dso_handle __3413_56_dso_handle)
#line 244
{
auto int __3422_28_success = 1;
auto a_needed_destruction_ptr __3423_28_ndp;

__3423_28_ndp = ((a_needed_destruction_ptr)(malloc(32ULL)));
if (__3423_28_ndp == ((a_needed_destruction_ptr)0)) {
__3422_28_success = 0;
} else  {
(__3423_28_ndp->object) = __3412_57_object;
(__3423_28_ndp->destruction_routine) = ((a_destructor_ptr)__3411_56_destruction_routine);
(__3423_28_ndp->dso_handle) = __3413_56_dso_handle;
(__3423_28_ndp->next) = (*__3410_57_destruction_list);
(*__3410_57_destruction_list) = __3423_28_ndp;
}
return (int)(!(__3422_28_success));
}
