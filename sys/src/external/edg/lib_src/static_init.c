/* Translated by the Edison Design Group C++/C front end (version 7.0) */
/* Wed Oct  7 03:19:07 2026 */
extern int __EDGCPFE__7_0;
void *memcpy(void *,const void *,unsigned long);
void *memset(void *,int,unsigned long);

# 1 "lib_src/static_init.c"
# 21 "lib_src/main.h"
struct __linkl;
# 69 "lib_src/basics.h"
typedef int a_boolean;
# 115 "lib_src/runtime.h"
typedef void (*a_void_function_ptr)(void);
# 21 "lib_src/main.h"
struct __linkl {

struct __linkl *next;

void (*ctor)(void);

void (*dtor)(void);};
# 734 "/usr/include/stdlib.h" 3
extern __attribute__((__nothrow__)) int atexit(void (*__func)(void));
# 184 "include_c++/cxxabi.h" 3
extern void __cxa_finalize(void *);
# 31 "lib_src/static_init.c"
extern void _Z12__call_dtorsv(void);
# 122
extern void _Z31__register_finalization_routinev(void);
# 141
extern void _Z12__call_ctorsv(void);
# 36 "lib_src/main.h"
extern struct __linkl *__head;
# 51
extern a_void_function_ptr _ctors[];
# 28 "lib_src/static_init.c"
static int use_patch_info;
# 129
static a_boolean _ZZ31__register_finalization_routinevE18already_registered;
# 28
static int use_patch_info = 1;
# 129
static a_boolean _ZZ31__register_finalization_routinevE18already_registered = 0;
# 31
void _Z12__call_dtorsv(void)
# 46
{
# 78
__cxa_finalize(((void *)0)); 

}
# 122
void _Z31__register_finalization_routinev(void)
# 128
{

if (!(_ZZ31__register_finalization_routinevE18already_registered)) {
_ZZ31__register_finalization_routinevE18already_registered = 1;

atexit((&_Z12__call_dtorsv));



} 
}


void _Z12__call_ctorsv(void)
# 148
{
auto struct __linkl *__11317_19_link_ptr;
auto struct __linkl *__11318_19_reverse_ptr;
auto struct __linkl *__11319_19_next_ptr;
# 158
use_patch_info = ((int)(__head != ((struct __linkl *)0)));
if (use_patch_info) {




for ((__11317_19_link_ptr = __head) , (__11318_19_reverse_ptr = ((struct __linkl *)0)); __11317_19_link_ptr != ((struct __linkl *)0); __11317_19_link_ptr = __11319_19_next_ptr)

{


__11319_19_next_ptr = (__11317_19_link_ptr->next);



if ((__11317_19_link_ptr->ctor) != ((void (*)(void))0)) {
(*(__11317_19_link_ptr->ctor))();
}



(__11317_19_link_ptr->next) = __11318_19_reverse_ptr;
__11318_19_reverse_ptr = __11317_19_link_ptr;
}


__head = __11318_19_reverse_ptr;
} else  {


auto int __11356_11_pos = 0;
while ((_ctors)[__11356_11_pos]) { (*((_ctors)[(__11356_11_pos++)]))(); }
} 
}
