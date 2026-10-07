/* Translated by the Edison Design Group C++/C front end (version 7.0) */
/* Wed Oct  7 07:14:43 2026 */
extern int __EDGCPFE__7_0;
void *memcpy(void *,const void *,unsigned long long);
void *memset(void *,int,unsigned long long);

#line 1 "lib_src/static_init.c"
#line 21 "lib_src/main.h"
struct __linkl;
#line 69 "lib_src/basics.h"
typedef int a_boolean;
#line 115 "lib_src/runtime.h"
typedef void (*a_void_function_ptr)(void);
#line 21 "lib_src/main.h"
struct __linkl {

struct __linkl *next;

void (*ctor)(void);

void (*dtor)(void);};
#line 48 "ape-sys/stdlib.h"
extern int atexit(void (*func)(void));
#line 184 "include_c++/cxxabi.h"
extern void __cxa_finalize(void *);
#line 31 "lib_src/static_init.c"
extern void _Z12__call_dtorsv(void);
#line 122
extern void _Z31__register_finalization_routinev(void);
#line 141
extern void _Z12__call_ctorsv(void);
#line 36 "lib_src/main.h"
extern struct __linkl *__head;
#line 51
extern a_void_function_ptr _ctors[];
#line 28 "lib_src/static_init.c"
static int use_patch_info;
#line 129
static a_boolean _ZZ31__register_finalization_routinevE18already_registered;
#line 28
static int use_patch_info = 1;
#line 129
static a_boolean _ZZ31__register_finalization_routinevE18already_registered = 0;
#line 31
void _Z12__call_dtorsv(void)
#line 46
{
#line 78
__cxa_finalize(((void *)0)); 

}
#line 122
void _Z31__register_finalization_routinev(void)
#line 128
{

if (!(_ZZ31__register_finalization_routinevE18already_registered)) {
_ZZ31__register_finalization_routinevE18already_registered = 1;

atexit((&_Z12__call_dtorsv));



} 
}


void _Z12__call_ctorsv(void)
#line 148
{
auto struct __linkl *__3298_19_link_ptr;
auto struct __linkl *__3299_19_reverse_ptr;
auto struct __linkl *__3300_19_next_ptr;
#line 158
use_patch_info = ((int)(__head != ((struct __linkl *)0)));
if (use_patch_info) {




for ((__3298_19_link_ptr = __head) , (__3299_19_reverse_ptr = ((struct __linkl *)0)); __3298_19_link_ptr != ((struct __linkl *)0); __3298_19_link_ptr = __3300_19_next_ptr)

{


__3300_19_next_ptr = (__3298_19_link_ptr->next);



if ((__3298_19_link_ptr->ctor) != ((void (*)(void))0)) {
(*(__3298_19_link_ptr->ctor))();
}



(__3298_19_link_ptr->next) = __3299_19_reverse_ptr;
__3299_19_reverse_ptr = __3298_19_link_ptr;
}


__head = __3299_19_reverse_ptr;
} else  {


auto int __3337_11_pos = 0;
while ((_ctors)[__3337_11_pos]) { (*((_ctors)[(__3337_11_pos++)]))(); }
} 
}
