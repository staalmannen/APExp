/* Translated by the Edison Design Group C++/C front end (version 7.0) */
/* Wed Oct  7 03:19:06 2026 */
extern int __EDGCPFE__7_0;
void *memcpy(void *,const void *,unsigned long);
void *memset(void *,int,unsigned long);

# 1 "lib_src/newnothrow.c"
struct __C1; struct __C2; struct __C3; struct __EDG_type_info; struct __class_type_info; struct __si_class_type_info; struct __C5; struct __C6; union __C7; struct __C8;
# 22 "include_c++/exception.stdh" 3
struct _ZSt9exception;
# 41 "include_c++/new.stdh" 3
struct _ZSt9bad_alloc;
# 61
struct _ZSt9nothrow_t; struct __C2 { void (*dtor)(); unsigned short handle; unsigned short next; unsigned char flags;char __dummy[3];}; struct __C3 { struct __C2 *regions; void **obj_table; struct __C1 *array_table; unsigned short saved_region_number;char __dummy[6];}; struct __EDG_type_info { const
# 61
 long *__vptr; const char *__name;}; struct __class_type_info { struct __EDG_type_info base;}; struct __si_class_type_info { struct __class_type_info base; const struct __class_type_info *base_type;}; struct __C5 { const struct __EDG_type_info *tinfo; unsigned flags; unsigned *ptr_flags;}; struct 
# 61
__C6 { long setjmp_buffer[25]; struct __C5 *catch_entries; void *rtinfo; unsigned short region_number;char __dummy[6];}; union __C7 { struct __C6 try_block; struct __C3 function; struct __C5 *throw_spec;}; struct __C8 { struct __C8 *next; unsigned char kind; union __C7 variant;};
# 69 "lib_src/basics.h"
typedef int a_boolean;
# 214 "/usr/lib/gcc/x86_64-linux-gnu/13/include/stddef.h" 3
typedef unsigned long size_t;
# 22 "include_c++/exception.stdh" 3
struct _ZSt9exception { const long *__vptr;};
# 41 "include_c++/new.stdh" 3
struct _ZSt9bad_alloc { struct _ZSt9exception __b_St9exception;};
# 58
typedef void (*_ZSt11new_handler)(void);
# 672 "/usr/include/stdlib.h" 3
extern __attribute__((__alloc_size__(1))) __attribute__((__malloc__)) __attribute__((__nothrow__)) void *malloc(size_t __size);
# 207 "lib_src/runtime.h"
extern void _Z21__default_new_handlerv(void);
# 21 "lib_src/newnothrow.c"
static a_boolean _ZN34_INTERNAL_12_newnothrow_c_5889dc9716call_new_handlerEv(void); extern int _setjmp(long [25]); extern void __destroy_exception_object(void); extern void __exception_caught(void);
# 57
extern __attribute__((__nothrow__)) void *_ZnwmRKSt9nothrow_t(size_t size, const struct _ZSt9nothrow_t *);
# 44 "include_c++/new.stdh" 3
extern __attribute__((__nothrow__)) void _ZNSt9bad_allocC1ERKS_(struct _ZSt9bad_alloc *const, const struct _ZSt9bad_alloc *);

extern __attribute__((__nothrow__)) void _ZNSt9bad_allocD1Ev(struct _ZSt9bad_alloc *const);
# 211 "lib_src/runtime.h"
extern _ZSt11new_handler _new_handler; extern struct __C8 *__curr_eh_stack_entry; extern const struct __si_class_type_info _ZTISt9bad_alloc; extern unsigned short __eh_curr_region; extern void *__caught_object_address; extern int __catch_clause_number;
# 21 "lib_src/newnothrow.c"
static a_boolean _ZN34_INTERNAL_12_newnothrow_c_5889dc9716call_new_handlerEv(void)
# 27
{ static struct __C5 __T309275816[1] = {{((const struct __EDG_type_info *)(&_ZTISt9bad_alloc.base.base)),32U,((unsigned *)0)}}; static struct __C2 __T309279480[2] = {{((void (*)())(&__destroy_exception_object)),((unsigned short)0U),((unsigned short)65535U),((unsigned char)0U)},{((void (*)())(&
# 27
_ZNSt9bad_allocD1Ev)),((unsigned short)0U),((unsigned short)0U),((unsigned char)0U)}}; auto struct __C8 __T309306584; auto void *__T309316224[1]; auto a_boolean __T309321296; auto struct __C8 __T309322072;
auto a_boolean __11017_13_done;



auto _ZSt11new_handler __11021_31_new_handler;
# 27
(__T309322072.next) = __curr_eh_stack_entry; __curr_eh_stack_entry = (&__T309322072); (__T309322072.kind) = ((unsigned char)1U); (((__T309322072.variant).function).regions) = (__T309279480); (((__T309322072.variant).function).obj_table) = (__T309316224); (((__T309322072.variant).function).
# 27
saved_region_number) = __eh_curr_region; __eh_curr_region = ((unsigned short)65535U);
__11017_13_done = 0;




__11021_31_new_handler = ((_new_handler != ((_ZSt11new_handler)0)) ? _new_handler : _Z21__default_new_handlerv); { (__T309306584.next) = __curr_eh_stack_entry; __curr_eh_stack_entry = (&__T309306584); (__T309306584.kind) = ((unsigned char)5U); (((__T309306584.variant).try_block).catch_entries) = (
# 33
__T309275816); (((__T309306584.variant).try_block).rtinfo) = ((void *)0); (((__T309306584.variant).try_block).region_number) = __eh_curr_region;

if ((_setjmp(((((__T309306584.variant).try_block).setjmp_buffer)))) == 0) {;
(*__11021_31_new_handler)();
}
else  if (__catch_clause_number == 1) { auto struct _ZSt9bad_alloc __T309305040;  __eh_curr_region = ((unsigned short)0U); _ZNSt9bad_allocC1ERKS_((&__T309305040), ((const struct _ZSt9bad_alloc *)((struct _ZSt9bad_alloc *)__caught_object_address))); ((__T309316224)[0UL]) = ((void *)(&__T309305040)); 
# 38
__eh_curr_region = ((unsigned short)1U); __exception_caught();
__11017_13_done = 1; __eh_curr_region = ((unsigned short)0U);
_ZNSt9bad_allocD1Ev((&__T309305040)); __eh_curr_region = ((unsigned short)65535U); __destroy_exception_object(); } __curr_eh_stack_entry = (__T309306584.next); } {
# 53
__T309321296 = __11017_13_done; { __eh_curr_region = (((__T309322072.variant).function).saved_region_number); __curr_eh_stack_entry = (__T309322072.next); return __T309321296; } }
}


__attribute__((__nothrow__)) void *_ZnwmRKSt9nothrow_t( size_t __11046_27_size,  const struct _ZSt9nothrow_t *__T309329320)
# 72
{ auto void *__T309337592;
auto void *__11062_9_ptr;

if (__11046_27_size == 0UL) { __11046_27_size = 1UL; }
while ((__11062_9_ptr = ((void *)(malloc(__11046_27_size)))) == ((void *)0)) {
if (_new_handler != ((_ZSt11new_handler)0)) {


if (_ZN34_INTERNAL_12_newnothrow_c_5889dc9716call_new_handlerEv()) { return ((void *)0); }
} else  {

return ((void *)0);
}
} {
__T309337592 = __11062_9_ptr; return __T309337592; }
}
