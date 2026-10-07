/* Translated by the Edison Design Group C++/C front end (version 7.0) */
/* Wed Oct  7 03:19:05 2026 */
extern int __EDGCPFE__7_0;
void *memcpy(void *,const void *,unsigned long);
void *memset(void *,int,unsigned long);

# 1 "lib_src/eh_util.c"
struct __C1; struct __C2; struct __C3; struct __EDG_type_info; struct __class_type_info; struct __si_class_type_info; struct __C5; struct __C6; union __C7; struct __C8;
# 6 "/usr/include/x86_64-linux-gnu/bits/types/__sigset_t.h" 3
struct __sigset_t;
# 17 "lib_src/error.h"
enum an_error_code {
ec_none,
ec_abort_header,
ec_terminate_called,
ec_terminate_returned,
ec_already_marked_for_destruction,
ec_main_called_more_than_once,
ec_pure_virtual_called,
ec_bad_cast,
ec_bad_typeid,
ec_array_not_from_vec_new,
ec_terminate_called_more_than_once,
ec_negative_vla_size,
ec_vla_allocation_failed,
ec_deleted_virtual_called,
ec_thread_registration_failed,
ec_last};
# 48 "lib_src/vec_newdel.h"
struct an_array_alloc_eh_info;
# 26 "/usr/include/x86_64-linux-gnu/bits/types/struct___jmp_buf_tag.h" 3
struct __jmp_buf_tag;
# 164 "lib_src/eh.h"
struct an_eh_array_supplement;
# 182
struct an_eh_region_descr;
# 310
struct an_exception_type_specification;
# 335
enum an_eh_stack_entry_kind {
ehsek_old_try_block,
ehsek_function,
ehsek_throw_spec,
ehsek_throw_processing_marker,
ehsek_vec_new_or_delete,
ehsek_try_block,
ehsek_noexcept};
# 356
struct _ZN17an_eh_stack_entryUt_Ut_E;
# 385
struct _ZN17an_eh_stack_entryUt_Ut0_E;
# 354
union _ZN17an_eh_stack_entryUt_E;
# 347
struct an_eh_stack_entry;
# 22 "include_c++/exception.stdh" 3
struct _ZSt9exception;
# 40
struct _ZSt13bad_exception;
# 32 "include_c++/typeinfo.stdh" 3
struct _ZSt9type_info; struct __C2 { void (*dtor)(); unsigned short handle; unsigned short next; unsigned char flags;char __dummy[3];}; struct __C3 { struct __C2 *regions; void **obj_table; struct __C1 *array_table; unsigned short saved_region_number;char __dummy[6];}; struct __EDG_type_info { const
# 32
 long *__vptr; const char *__name;}; struct __class_type_info { struct __EDG_type_info base;}; struct __si_class_type_info { struct __class_type_info base; const struct __class_type_info *base_type;}; struct __C5 { const struct __EDG_type_info *tinfo; unsigned flags; unsigned *ptr_flags;}; struct 
# 32
__C6 { long setjmp_buffer[25]; struct __C5 *catch_entries; void *rtinfo; unsigned short region_number;char __dummy[6];}; union __C7 { struct __C6 try_block; struct __C3 function; struct __C5 *throw_spec;}; struct __C8 { struct __C8 *next; unsigned char kind; union __C7 variant;};
# 66 "lib_src/basics.h"
typedef unsigned char a_byte;


typedef int a_boolean;
# 6 "/usr/include/x86_64-linux-gnu/bits/types/__sigset_t.h" 3
struct __sigset_t {
unsigned long __val[16];};
typedef struct __sigset_t __sigset_t;
# 115 "lib_src/runtime.h"
typedef void (*a_void_function_ptr)(void);
# 93 "lib_src/rtti.h"
typedef const struct _ZSt9type_info *a_type_info_impl_ptr;
# 48 "lib_src/vec_newdel.h"
typedef struct an_array_alloc_eh_info *an_array_alloc_eh_info_ptr;
# 31 "/usr/include/x86_64-linux-gnu/bits/setjmp.h" 3
typedef long __jmp_buf[8];
# 26 "/usr/include/x86_64-linux-gnu/bits/types/struct___jmp_buf_tag.h" 3
struct __jmp_buf_tag {
# 32
__jmp_buf __jmpbuf;
int __mask_was_saved;
__sigset_t __saved_mask;};
# 32 "/usr/include/setjmp.h" 3
typedef struct __jmp_buf_tag jmp_buf[1];
# 44 "lib_src/eh.h"
typedef void *an_object_ptr;


typedef unsigned short a_region_number;


typedef unsigned an_ETS_flag_set;
# 177
typedef struct an_eh_array_supplement an_eh_array_supplement;
# 210
typedef struct an_eh_region_descr an_eh_region_descr;
# 309
typedef struct an_exception_type_specification *an_exception_type_specification_ptr;
# 346
typedef struct an_eh_stack_entry *an_eh_stack_entry_ptr;
# 356
struct _ZN17an_eh_stack_entryUt_Ut_E {

jmp_buf setjmp_buffer;
# 370
an_exception_type_specification_ptr catch_entries;


void *catch_info;




a_region_number region_number;char __dummy[6];};
# 385
struct _ZN17an_eh_stack_entryUt_Ut0_E {

an_eh_region_descr *regions;



an_object_ptr *object_address_table;


an_eh_array_supplement *array_table;



a_region_number saved_region_number;char __dummy[6];};
# 354
union _ZN17an_eh_stack_entryUt_E {
# 382
struct _ZN17an_eh_stack_entryUt_Ut_E try_block;
# 401
struct _ZN17an_eh_stack_entryUt_Ut0_E function;


an_exception_type_specification_ptr throw_specification;




an_array_alloc_eh_info_ptr array_alloc_eh_info;};
# 347
struct an_eh_stack_entry {

an_eh_stack_entry_ptr next;


unsigned char kind;
# 414
union _ZN17an_eh_stack_entryUt_E variant;};
# 22 "include_c++/exception.stdh" 3
struct _ZSt9exception { const long *__vptr;};
# 35
typedef _Bool _ZSt6__bool;




struct _ZSt13bad_exception { struct _ZSt9exception __b_St9exception;};
# 49
typedef void (*_ZSt17terminate_handler)(void);
# 730 "/usr/include/stdlib.h" 3
extern __attribute__((__nothrow__)) __attribute__((__noreturn__)) void abort(void);
# 36 "lib_src/error.h"
extern __attribute__((__noreturn__)) void __abort_execution(enum an_error_code err_code);
# 454 "lib_src/eh.h"
extern void __type_of_thrown_object(a_type_info_impl_ptr *type, an_ETS_flag_set *flags, an_ETS_flag_set **ptr_flags);



extern a_boolean __can_throw_type(a_type_info_impl_ptr type, an_ETS_flag_set flags, an_ETS_flag_set *ptr_flags);




extern an_eh_stack_entry_ptr __get_curr_eh_stack_entry(void);
# 53 "lib_src/eh_util.c"
extern void __default_terminate(void);
# 152
extern void __call_unexpected(void); extern int _setjmp(long [25]); extern void __destroy_exception_object(void); extern void __exception_caught(void); extern __attribute__((__noreturn__)) void __rethrow(void); extern void *__throw_setup_dtor(const void *, unsigned long, unsigned, void (*)(void *)); 
# 152
extern __attribute__((__noreturn__)) void __throw(void);
# 205
extern void __call_terminate(void);
# 42 "include_c++/exception.stdh" 3
extern __attribute__((__nothrow__)) void _ZNSt13bad_exceptionC1Ev(struct _ZSt13bad_exception *const);


extern __attribute__((__nothrow__)) void _ZNSt13bad_exceptionD1Ev(struct _ZSt13bad_exception *const);
# 40 "lib_src/eh_util.c"
extern __attribute__((__nothrow__)) __attribute__((__noreturn__)) void _ZSt9terminatev(void);
# 62
extern __attribute__((__nothrow__)) _ZSt17terminate_handler _ZSt13set_terminatePFvvE(_ZSt17terminate_handler new_func);
# 75
extern __attribute__((__nothrow__)) _ZSt17terminate_handler _ZSt13get_terminatev(void);
# 84
extern __attribute__((__nothrow__)) __attribute__((__noreturn__)) void _ZSt10unexpectedv(void);
# 94
extern __attribute__((__nothrow__)) a_void_function_ptr _ZSt14set_unexpectedPFvvE(a_void_function_ptr new_func);
# 107
extern __attribute__((__nothrow__)) int _ZSt19uncaught_exceptionsv(void);
# 135
extern __attribute__((__nothrow__)) _ZSt6__bool _ZSt18uncaught_exceptionv(void);
# 439 "lib_src/eh.h"
extern a_void_function_ptr __default_terminate_routine;
# 446
extern a_void_function_ptr __default_unexpected_routine;
# 20 "lib_src/eh_util.c"
static a_boolean terminate_called_by_runtime;
# 26
static a_boolean terminate_called; extern struct __C8 *__curr_eh_stack_entry; extern unsigned short __eh_curr_region; extern const struct __si_class_type_info _ZTISt13bad_exception;
# 20
static a_boolean terminate_called_by_runtime = 0;
# 26
static a_boolean terminate_called = 0;
# 53
void __default_terminate(void)



{
__abort_execution(ec_terminate_called); 
}
# 152
void __call_unexpected(void)
# 163
{ static struct __C5 __T231679240[1] = {{((const struct __EDG_type_info *)0),48U,((unsigned *)0)}}; static struct __C2 __T231682880[1] = {{((void (*)())(&__destroy_exception_object)),((unsigned short)0U),((unsigned short)65535U),((unsigned char)0U)}}; auto struct __C8 __T231634016; auto struct __C8 
# 163
__T231648712;  (__T231648712.next) = __curr_eh_stack_entry; __curr_eh_stack_entry = (&__T231648712); (__T231648712.kind) = ((unsigned char)1U); (((__T231648712.variant).function).regions) = (__T231682880); (((__T231648712.variant).function).saved_region_number) = __eh_curr_region; __eh_curr_region = 
# 163
((unsigned short)65535U); { (__T231634016.next) = __curr_eh_stack_entry; __curr_eh_stack_entry = (&__T231634016); (__T231634016.kind) = ((unsigned char)5U); (((__T231634016.variant).try_block).catch_entries) = (__T231679240); (((__T231634016.variant).try_block).rtinfo) = ((void *)0); (((__T231634016
# 163
.variant).try_block).region_number) = __eh_curr_region;

if ((_setjmp(((((__T231634016.variant).try_block).setjmp_buffer)))) == 0) {;
_ZSt10unexpectedv();
}
else  { auto a_type_info_impl_ptr __T231643128; auto an_ETS_flag_set __T231643776; auto an_ETS_flag_set *__T231644512;
auto a_type_info_impl_ptr __12072_26_thrown_type;
auto an_ETS_flag_set __12073_22_thrown_flags;
auto an_ETS_flag_set *__12074_23_thrown_ptr_flags;
# 168
__eh_curr_region = ((unsigned short)0U); __exception_caught();



__type_of_thrown_object((&__12072_26_thrown_type), (&__12073_22_thrown_flags), (&__12074_23_thrown_ptr_flags));
if ((((__T231643128 = __12072_26_thrown_type) , (__T231643776 = __12073_22_thrown_flags)) , (__T231644512 = __12074_23_thrown_ptr_flags)) , (__can_throw_type(__T231643128, __T231643776, __T231644512))) {


__rethrow();
} else  {
auto a_type_info_impl_ptr __12081_28_bad_exception_type;
__12081_28_bad_exception_type = ((const struct _ZSt9type_info *)(&_ZTISt13bad_exception));

if (__can_throw_type(__12081_28_bad_exception_type, 0U, ((an_ETS_flag_set *)0)))

{ auto struct _ZSt13bad_exception *__T231645600;


(__T231645600 = ((struct _ZSt13bad_exception *)(__throw_setup_dtor(((const void *)(&_ZTISt13bad_exception)), 8UL, 0U, ((void (*)(void *))_ZNSt13bad_exceptionD1Ev))))) , ((_ZNSt13bad_exceptionC1Ev(__T231645600)) , (__throw()));
} else  {


__call_terminate();
}
} __eh_curr_region = ((unsigned short)65535U);
__destroy_exception_object(); } __curr_eh_stack_entry = (__T231634016.next); }
# 201
abort(); { __eh_curr_region = (((__T231648712.variant).function).saved_region_number); __curr_eh_stack_entry = (__T231648712.next);  }
}


void __call_terminate(void)




{
terminate_called_by_runtime = 1;
_ZSt9terminatev();

abort(); 
}
# 40
__attribute__((__nothrow__)) __attribute__((__noreturn__)) void _ZSt9terminatev(void)



{

if (terminate_called) { __abort_execution(ec_terminate_called_more_than_once); }
terminate_called = 1;
if (__default_terminate_routine != ((a_void_function_ptr)0)) { __default_terminate_routine(); }
__abort_execution(ec_terminate_returned); 
}
# 62
__attribute__((__nothrow__)) _ZSt17terminate_handler _ZSt13set_terminatePFvvE(
_ZSt17terminate_handler __11966_55_new_func)




{ auto _ZSt17terminate_handler __T231606624;
auto _ZSt17terminate_handler __11972_36_old_func; __11972_36_old_func = __default_terminate_routine;
__default_terminate_routine = __11966_55_new_func; {
__T231606624 = __11972_36_old_func; return __T231606624; }
}


__attribute__((__nothrow__)) _ZSt17terminate_handler _ZSt13get_terminatev(void)



{ auto a_void_function_ptr __T231608168;  {
__T231608168 = __default_terminate_routine; return __T231608168; }
}


__attribute__((__nothrow__)) __attribute__((__noreturn__)) void _ZSt10unexpectedv(void)



{
if (__default_unexpected_routine != ((a_void_function_ptr)0)) { __default_unexpected_routine(); }
_ZSt9terminatev(); 
}


__attribute__((__nothrow__)) a_void_function_ptr _ZSt14set_unexpectedPFvvE( a_void_function_ptr __11997_56_new_func)
# 100
{ auto a_void_function_ptr __T231613656;
auto a_void_function_ptr __12004_23_old_func; __12004_23_old_func = __default_unexpected_routine;
__default_unexpected_routine = __11997_56_new_func; {
__T231613656 = __12004_23_old_func; return __T231613656; }
}


__attribute__((__nothrow__)) int _ZSt19uncaught_exceptionsv(void)



{ auto int __T231620704;
auto an_eh_stack_entry_ptr __12015_25_ehsep;
auto int __12016_9_result = 0;


if (!(terminate_called_by_runtime)) {



__12015_25_ehsep = (__get_curr_eh_stack_entry());
for (; __12015_25_ehsep != ((an_eh_stack_entry_ptr)0); __12015_25_ehsep = (__12015_25_ehsep->next)) {
if (((int)(__12015_25_ehsep->kind)) == 3) {




__12016_9_result++;
}
}
} {
__T231620704 = __12016_9_result; return __T231620704; }
}


__attribute__((__nothrow__)) _ZSt6__bool _ZSt18uncaught_exceptionv(void)



{ auto _Bool __T231622816;  {
__T231622816 = ((_Bool)((_ZSt19uncaught_exceptionsv()) > 0)); return __T231622816; }
}
