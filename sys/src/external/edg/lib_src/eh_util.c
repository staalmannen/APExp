/* Translated by the Edison Design Group C++/C front end (version 7.0) */
/* Thu Oct  8 07:53:17 2026 */
extern int __EDGCPFE__7_0;
void *memcpy(void *,const void *,unsigned long long);
void *memset(void *,int,unsigned long long);

#line 1 "lib_src/eh_util.c"
struct __C1; struct __C2; struct __C3; struct __EDG_type_info; struct __class_type_info; struct __si_class_type_info; struct __C5; struct __C6; union __C7; struct __C8;
#line 17 "lib_src/error.h"
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
#line 48 "lib_src/vec_newdel.h"
struct an_array_alloc_eh_info;
#line 164 "lib_src/eh.h"
struct an_eh_array_supplement;
#line 182
struct an_eh_region_descr;
#line 310
struct an_exception_type_specification;
#line 335
enum an_eh_stack_entry_kind {
ehsek_old_try_block,
ehsek_function,
ehsek_throw_spec,
ehsek_throw_processing_marker,
ehsek_vec_new_or_delete,
ehsek_try_block,
ehsek_noexcept};
#line 356
struct _ZN17an_eh_stack_entryUt_Ut_E;
#line 385
struct _ZN17an_eh_stack_entryUt_Ut0_E;
#line 354
union _ZN17an_eh_stack_entryUt_E;
#line 347
struct an_eh_stack_entry;
#line 22 "include_c++/exception.stdh"
struct _ZSt9exception;
#line 40
struct _ZSt13bad_exception;
#line 32 "include_c++/typeinfo.stdh"
struct _ZSt9type_info; struct __C2 { void (*dtor)(); unsigned short handle; unsigned short next; unsigned char flags;char __dummy[3];}; struct __C3 { struct __C2 *regions; void **obj_table; struct __C1 *array_table; unsigned short saved_region_number;char __dummy[6];}; struct __EDG_type_info { const
#line 32
 long long *__vptr; const char *__name;}; struct __class_type_info { struct __EDG_type_info base;}; struct __si_class_type_info { struct __class_type_info base; const struct __class_type_info *base_type;}; struct __C5 { const struct __EDG_type_info *tinfo; unsigned flags; unsigned *ptr_flags;}; 
#line 32
struct __C6 { long setjmp_buffer[25]; struct __C5 *catch_entries; void *rtinfo; unsigned short region_number;char __dummy[6];}; union __C7 { struct __C6 try_block; struct __C3 function; struct __C5 *throw_spec;}; struct __C8 { struct __C8 *next; unsigned char kind; union __C7 variant;};
#line 66 "lib_src/basics.h"
typedef unsigned char a_byte;


typedef int a_boolean;
#line 115 "lib_src/runtime.h"
typedef void (*a_void_function_ptr)(void);
#line 93 "lib_src/rtti.h"
typedef const struct _ZSt9type_info *a_type_info_impl_ptr;
#line 48 "lib_src/vec_newdel.h"
typedef struct an_array_alloc_eh_info *an_array_alloc_eh_info_ptr;
#line 10 "ape-sys/setjmp.h"
typedef int jmp_buf[20];
#line 44 "lib_src/eh.h"
typedef void *an_object_ptr;


typedef unsigned short a_region_number;


typedef unsigned an_ETS_flag_set;
#line 177
typedef struct an_eh_array_supplement an_eh_array_supplement;
#line 210
typedef struct an_eh_region_descr an_eh_region_descr;
#line 309
typedef struct an_exception_type_specification *an_exception_type_specification_ptr;
#line 346
typedef struct an_eh_stack_entry *an_eh_stack_entry_ptr;
#line 356
struct _ZN17an_eh_stack_entryUt_Ut_E {

jmp_buf setjmp_buffer;
#line 370
an_exception_type_specification_ptr catch_entries;


void *catch_info;




a_region_number region_number;char __dummy[6];};
#line 385
struct _ZN17an_eh_stack_entryUt_Ut0_E {

an_eh_region_descr *regions;



an_object_ptr *object_address_table;


an_eh_array_supplement *array_table;



a_region_number saved_region_number;char __dummy[6];};
#line 354
union _ZN17an_eh_stack_entryUt_E {
#line 382
struct _ZN17an_eh_stack_entryUt_Ut_E try_block;
#line 401
struct _ZN17an_eh_stack_entryUt_Ut0_E function;


an_exception_type_specification_ptr throw_specification;




an_array_alloc_eh_info_ptr array_alloc_eh_info;};
#line 347
struct an_eh_stack_entry {

an_eh_stack_entry_ptr next;


unsigned char kind;
#line 414
union _ZN17an_eh_stack_entryUt_E variant;};
#line 22 "include_c++/exception.stdh"
struct _ZSt9exception { const long long *__vptr;};
#line 35
typedef _Bool _ZSt6__bool;




struct _ZSt13bad_exception { struct _ZSt9exception __b_St9exception;};
#line 49
typedef void (*_ZSt17terminate_handler)(void);
#line 69 "ape-sys/stdlib.h"
extern void abort(void);
#line 36 "lib_src/error.h"
extern void __abort_execution(enum an_error_code err_code);
#line 454 "lib_src/eh.h"
extern void __type_of_thrown_object(a_type_info_impl_ptr *type, an_ETS_flag_set *flags, an_ETS_flag_set **ptr_flags);



extern a_boolean __can_throw_type(a_type_info_impl_ptr type, an_ETS_flag_set flags, an_ETS_flag_set *ptr_flags);




extern an_eh_stack_entry_ptr __get_curr_eh_stack_entry(void);
#line 53 "lib_src/eh_util.c"
extern void __default_terminate(void);
#line 152
extern void __call_unexpected(void); extern int setjmp(long [25]); extern void __destroy_exception_object(void); extern void __exception_caught(void); extern void __rethrow(void); extern void *__throw_setup_dtor(const void *, unsigned long long, unsigned, void (*)(void *)); extern void __throw(void)
#line 152
;
#line 205
extern void __call_terminate(void);
#line 42 "include_c++/exception.stdh"
extern void _ZNSt13bad_exceptionC1Ev(struct _ZSt13bad_exception *const);


extern void _ZNSt13bad_exceptionD1Ev(struct _ZSt13bad_exception *const);
#line 40 "lib_src/eh_util.c"
extern void _ZSt9terminatev(void);
#line 62
extern _ZSt17terminate_handler _ZSt13set_terminatePFvvE(_ZSt17terminate_handler new_func);
#line 75
extern _ZSt17terminate_handler _ZSt13get_terminatev(void);
#line 84
extern void _ZSt10unexpectedv(void);
#line 94
extern a_void_function_ptr _ZSt14set_unexpectedPFvvE(a_void_function_ptr new_func);
#line 107
extern int _ZSt19uncaught_exceptionsv(void);
#line 135
extern _ZSt6__bool _ZSt18uncaught_exceptionv(void);
#line 439 "lib_src/eh.h"
extern a_void_function_ptr __default_terminate_routine;
#line 446
extern a_void_function_ptr __default_unexpected_routine;
#line 20 "lib_src/eh_util.c"
static a_boolean terminate_called_by_runtime;
#line 26
static a_boolean terminate_called; extern struct __C8 *__curr_eh_stack_entry; extern unsigned short __eh_curr_region; extern const struct __si_class_type_info _ZTISt13bad_exception;
#line 20
static a_boolean terminate_called_by_runtime = 0;
#line 26
static a_boolean terminate_called = 0;
#line 53
void __default_terminate(void)



{
__abort_execution(ec_terminate_called); 
}
#line 152
void __call_unexpected(void)
#line 163
{ static struct __C5 __T217645056[1] = {{((const struct __EDG_type_info *)0),48U,((unsigned *)0)}}; static struct __C2 __T217648928[1] = {{((void (*)())(&__destroy_exception_object)),((unsigned short)0U),((unsigned short)65535U),((unsigned char)0U)}}; auto struct __C8 __T217602512; auto struct __C8 
#line 163
__T217617208;  (__T217617208.next) = __curr_eh_stack_entry; __curr_eh_stack_entry = (&__T217617208); (__T217617208.kind) = ((unsigned char)1U); (((__T217617208.variant).function).regions) = (__T217648928); (((__T217617208.variant).function).saved_region_number) = __eh_curr_region; __eh_curr_region = 
#line 163
((unsigned short)65535U); { (__T217602512.next) = __curr_eh_stack_entry; __curr_eh_stack_entry = (&__T217602512); (__T217602512.kind) = ((unsigned char)5U); (((__T217602512.variant).try_block).catch_entries) = (__T217645056); (((__T217602512.variant).try_block).rtinfo) = ((void *)0); (((__T217602512
#line 163
.variant).try_block).region_number) = __eh_curr_region;

if ((setjmp(((((__T217602512.variant).try_block).setjmp_buffer)))) == 0) {;
_ZSt10unexpectedv();
}
else  { auto a_type_info_impl_ptr __T217611624; auto an_ETS_flag_set __T217612272; auto an_ETS_flag_set *__T217613008;
auto a_type_info_impl_ptr __3922_26_thrown_type;
auto an_ETS_flag_set __3923_22_thrown_flags;
auto an_ETS_flag_set *__3924_23_thrown_ptr_flags;
#line 168
__eh_curr_region = ((unsigned short)0U); __exception_caught();



__type_of_thrown_object((&__3922_26_thrown_type), (&__3923_22_thrown_flags), (&__3924_23_thrown_ptr_flags));
if ((((__T217611624 = __3922_26_thrown_type) , (__T217612272 = __3923_22_thrown_flags)) , (__T217613008 = __3924_23_thrown_ptr_flags)) , (__can_throw_type(__T217611624, __T217612272, __T217613008))) {


__rethrow();
} else  {
auto a_type_info_impl_ptr __3931_28_bad_exception_type;
__3931_28_bad_exception_type = ((const struct _ZSt9type_info *)(&_ZTISt13bad_exception));

if (__can_throw_type(__3931_28_bad_exception_type, 0U, ((an_ETS_flag_set *)0)))

{ auto struct _ZSt13bad_exception *__T217614096;


(__T217614096 = ((struct _ZSt13bad_exception *)(__throw_setup_dtor(((const void *)(&_ZTISt13bad_exception)), 8ULL, 0U, ((void (*)(void *))_ZNSt13bad_exceptionD1Ev))))) , ((_ZNSt13bad_exceptionC1Ev(__T217614096)) , (__throw()));
} else  {


__call_terminate();
}
} __eh_curr_region = ((unsigned short)65535U);
__destroy_exception_object(); } __curr_eh_stack_entry = (__T217602512.next); }
#line 201
abort(); { __eh_curr_region = (((__T217617208.variant).function).saved_region_number); __curr_eh_stack_entry = (__T217617208.next);  }
}


void __call_terminate(void)




{
terminate_called_by_runtime = 1;
_ZSt9terminatev();

abort(); 
}
#line 40
void _ZSt9terminatev(void)



{

if (terminate_called) { __abort_execution(ec_terminate_called_more_than_once); }
terminate_called = 1;
if (__default_terminate_routine != ((a_void_function_ptr)0)) { __default_terminate_routine(); }
__abort_execution(ec_terminate_returned); 
}
#line 62
_ZSt17terminate_handler _ZSt13set_terminatePFvvE(
_ZSt17terminate_handler __3816_55_new_func)




{ auto _ZSt17terminate_handler __T217575120;
auto _ZSt17terminate_handler __3822_36_old_func; __3822_36_old_func = __default_terminate_routine;
__default_terminate_routine = __3816_55_new_func; {
__T217575120 = __3822_36_old_func; return __T217575120; }
}


_ZSt17terminate_handler _ZSt13get_terminatev(void)



{ auto a_void_function_ptr __T217576664;  {
__T217576664 = __default_terminate_routine; return __T217576664; }
}


void _ZSt10unexpectedv(void)



{
if (__default_unexpected_routine != ((a_void_function_ptr)0)) { __default_unexpected_routine(); }
_ZSt9terminatev(); 
}


a_void_function_ptr _ZSt14set_unexpectedPFvvE( a_void_function_ptr __3847_56_new_func)
#line 100
{ auto a_void_function_ptr __T217582152;
auto a_void_function_ptr __3854_23_old_func; __3854_23_old_func = __default_unexpected_routine;
__default_unexpected_routine = __3847_56_new_func; {
__T217582152 = __3854_23_old_func; return __T217582152; }
}


int _ZSt19uncaught_exceptionsv(void)



{ auto int __T217589200;
auto an_eh_stack_entry_ptr __3865_25_ehsep;
auto int __3866_9_result = 0;


if (!(terminate_called_by_runtime)) {



__3865_25_ehsep = (__get_curr_eh_stack_entry());
for (; __3865_25_ehsep != ((an_eh_stack_entry_ptr)0); __3865_25_ehsep = (__3865_25_ehsep->next)) {
if (((int)(__3865_25_ehsep->kind)) == 3) {




__3866_9_result++;
}
}
} {
__T217589200 = __3866_9_result; return __T217589200; }
}


_ZSt6__bool _ZSt18uncaught_exceptionv(void)



{ auto _Bool __T217591312;  {
__T217591312 = ((_Bool)((_ZSt19uncaught_exceptionsv()) > 0)); return __T217591312; }
}
