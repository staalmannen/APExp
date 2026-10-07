/* Translated by the Edison Design Group C++/C front end (version 7.0) */
/* Wed Oct  7 07:14:43 2026 */
extern int __EDGCPFE__7_0;
void *memcpy(void *,const void *,unsigned long long);
void *memset(void *,int,unsigned long long);

#line 1 "lib_src/newnothrow.c"
struct __C1; struct __C2; struct __C3; struct __EDG_type_info; struct __class_type_info; struct __si_class_type_info; struct __C5; struct __C6; union __C7; struct __C8;
#line 22 "include_c++/exception.stdh"
struct _ZSt9exception;
#line 41 "include_c++/new.stdh"
struct _ZSt9bad_alloc;
#line 61
struct _ZSt9nothrow_t; struct __C2 { void (*dtor)(); unsigned short handle; unsigned short next; unsigned char flags;char __dummy[3];}; struct __C3 { struct __C2 *regions; void **obj_table; struct __C1 *array_table; unsigned short saved_region_number;char __dummy[6];}; struct __EDG_type_info { const
#line 61
 long long *__vptr; const char *__name;}; struct __class_type_info { struct __EDG_type_info base;}; struct __si_class_type_info { struct __class_type_info base; const struct __class_type_info *base_type;}; struct __C5 { const struct __EDG_type_info *tinfo; unsigned flags; unsigned *ptr_flags;}; 
#line 61
struct __C6 { long setjmp_buffer[25]; struct __C5 *catch_entries; void *rtinfo; unsigned short region_number;char __dummy[6];}; union __C7 { struct __C6 try_block; struct __C3 function; struct __C5 *throw_spec;}; struct __C8 { struct __C8 *next; unsigned char kind; union __C7 variant;};
#line 69 "lib_src/basics.h"
typedef int a_boolean;
#line 10 "ape-arch/stddef_arch.h"
typedef unsigned long long size_t;
#line 22 "include_c++/exception.stdh"
struct _ZSt9exception { const long long *__vptr;};
#line 41 "include_c++/new.stdh"
struct _ZSt9bad_alloc { struct _ZSt9exception __b_St9exception;};
#line 58
typedef void (*_ZSt11new_handler)(void);
#line 45 "ape-sys/stdlib.h"
extern void *malloc(size_t);
#line 207 "lib_src/runtime.h"
extern void _Z21__default_new_handlerv(void);
#line 21 "lib_src/newnothrow.c"
static a_boolean _ZN34_INTERNAL_12_newnothrow_c_969726bb16call_new_handlerEv(void); extern int _setjmp(long [25]); extern void __destroy_exception_object(void); extern void __exception_caught(void);
#line 57
extern void *_ZnwyRKSt9nothrow_t(size_t size, const struct _ZSt9nothrow_t *);
#line 44 "include_c++/new.stdh"
extern void _ZNSt9bad_allocC1ERKS_(struct _ZSt9bad_alloc *const, const struct _ZSt9bad_alloc *);

extern void _ZNSt9bad_allocD1Ev(struct _ZSt9bad_alloc *const);
#line 211 "lib_src/runtime.h"
extern _ZSt11new_handler _new_handler; extern struct __C8 *__curr_eh_stack_entry; extern const struct __si_class_type_info _ZTISt9bad_alloc; extern unsigned short __eh_curr_region; extern void *__caught_object_address; extern int __catch_clause_number;
#line 21 "lib_src/newnothrow.c"
static a_boolean _ZN34_INTERNAL_12_newnothrow_c_969726bb16call_new_handlerEv(void)
#line 27
{ static struct __C5 __T688909680[1] = {{((const struct __EDG_type_info *)(&_ZTISt9bad_alloc.base.base)),32U,((unsigned *)0)}}; static struct __C2 __T688913576[2] = {{((void (*)())(&__destroy_exception_object)),((unsigned short)0U),((unsigned short)65535U),((unsigned char)0U)},{((void (*)())(&
#line 27
_ZNSt9bad_allocD1Ev)),((unsigned short)0U),((unsigned short)0U),((unsigned char)0U)}}; auto struct __C8 __T689027288; auto void *__T689036928[1]; auto a_boolean __T689042000; auto struct __C8 __T689042776;
auto a_boolean __2998_13_done;



auto _ZSt11new_handler __3002_31_new_handler;
#line 27
(__T689042776.next) = __curr_eh_stack_entry; __curr_eh_stack_entry = (&__T689042776); (__T689042776.kind) = ((unsigned char)1U); (((__T689042776.variant).function).regions) = (__T688913576); (((__T689042776.variant).function).obj_table) = (__T689036928); (((__T689042776.variant).function).
#line 27
saved_region_number) = __eh_curr_region; __eh_curr_region = ((unsigned short)65535U);
__2998_13_done = 0;




__3002_31_new_handler = ((_new_handler != ((_ZSt11new_handler)0)) ? _new_handler : _Z21__default_new_handlerv); { (__T689027288.next) = __curr_eh_stack_entry; __curr_eh_stack_entry = (&__T689027288); (__T689027288.kind) = ((unsigned char)5U); (((__T689027288.variant).try_block).catch_entries) = (
#line 33
__T688909680); (((__T689027288.variant).try_block).rtinfo) = ((void *)0); (((__T689027288.variant).try_block).region_number) = __eh_curr_region;

if ((_setjmp(((((__T689027288.variant).try_block).setjmp_buffer)))) == 0) {;
(*__3002_31_new_handler)();
}
else  if (__catch_clause_number == 1) { auto struct _ZSt9bad_alloc __T689025744;  __eh_curr_region = ((unsigned short)0U); _ZNSt9bad_allocC1ERKS_((&__T689025744), ((const struct _ZSt9bad_alloc *)((struct _ZSt9bad_alloc *)__caught_object_address))); ((__T689036928)[0ULL]) = ((void *)(&__T689025744)); 
#line 38
__eh_curr_region = ((unsigned short)1U); __exception_caught();
__2998_13_done = 1; __eh_curr_region = ((unsigned short)0U);
_ZNSt9bad_allocD1Ev((&__T689025744)); __eh_curr_region = ((unsigned short)65535U); __destroy_exception_object(); } __curr_eh_stack_entry = (__T689027288.next); } {
#line 53
__T689042000 = __2998_13_done; { __eh_curr_region = (((__T689042776.variant).function).saved_region_number); __curr_eh_stack_entry = (__T689042776.next); return __T689042000; } }
}


void *_ZnwyRKSt9nothrow_t( size_t __3027_27_size,  const struct _ZSt9nothrow_t *__T689050024)
#line 72
{ auto void *__T689058296;
auto void *__3043_9_ptr;

if (__3027_27_size == 0ULL) { __3027_27_size = 1ULL; }
while ((__3043_9_ptr = ((void *)(malloc(__3027_27_size)))) == ((void *)0)) {
if (_new_handler != ((_ZSt11new_handler)0)) {


if (_ZN34_INTERNAL_12_newnothrow_c_969726bb16call_new_handlerEv()) { return ((void *)0); }
} else  {

return ((void *)0);
}
} {
__T689058296 = __3043_9_ptr; return __T689058296; }
}
