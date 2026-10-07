/* Translated by the Edison Design Group C++/C front end (version 7.0) */
/* Wed Oct  7 07:14:44 2026 */
extern int __EDGCPFE__7_0;
void *memcpy(void *,const void *,unsigned long long);
void *memset(void *,int,unsigned long long);

#line 1 "lib_src/vec_newdel.c"
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
#line 62 "lib_src/vec_newdel.c"
struct an_array_alloc_eh_info;
#line 66 "lib_src/basics.h"
typedef unsigned char a_byte;


typedef int a_boolean;
#line 4 "ape-arch/stddef_arch.h"
typedef long long _ptrdiff_t;
#line 10
typedef unsigned long long size_t;
#line 20 "ape-sys/stddef.h"
typedef _ptrdiff_t ptrdiff_t;
#line 101 "lib_src/runtime.h"
typedef size_t a_sizeof_t;
#line 127
typedef void (*a_destructor_ptr)(void *);
#line 146
typedef void *(*a_new_ptr)(size_t);
#line 155
typedef void (*a_delete_ptr)(void *);
#line 164
typedef void (*a_two_operand_delete_ptr)(void *, a_sizeof_t);
#line 184
typedef void a_ctor_return_type;
#line 195
typedef a_ctor_return_type (*a_constructor_ptr)(void *);
#line 203
typedef a_ctor_return_type (*a_copy_constructor_ptr)(void *, void *);
#line 48 "lib_src/vec_newdel.h"
typedef struct an_array_alloc_eh_info *an_array_alloc_eh_info_ptr;
#line 10 "ape-sys/setjmp.h"
typedef int jmp_buf[20];
#line 44 "lib_src/eh.h"
typedef void *an_object_ptr;


typedef unsigned short a_region_number;
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
typedef struct an_eh_stack_entry an_eh_stack_entry;
#line 62 "lib_src/vec_newdel.c"
struct an_array_alloc_eh_info {
void *array_ptr;


ptrdiff_t number_of_elements;


size_t element_size;


size_t prefix_size;


size_t elements_processed;



a_boolean is_vec_new;



a_boolean free_memory_on_cleanup;



a_destructor_ptr destructor;



a_delete_ptr delete_routine;



a_boolean is_two_arg;



a_boolean terminate_immediately;};
#line 177
typedef size_t an_alloc_prefix;

typedef an_alloc_prefix *an_alloc_prefix_ptr;
#line 138 "include_c++/new.stdh"
extern void *_Znay(size_t);


extern void _ZdaPv(void *);
#line 435 "lib_src/eh.h"
extern void __call_terminate(void);
#line 466
extern void __throw_bad_array_new_length(void);
#line 19 "lib_src/memzero.h"
extern void __memzero(void *buffer, size_t size);
#line 112 "lib_src/vec_newdel.c"
static void _ZN34_INTERNAL_12_vec_newdel_c_8a08d4a536add_vec_new_or_delete_eh_stack_entryEP17an_eh_stack_entryP22an_array_alloc_eh_infoi(an_eh_stack_entry_ptr ehsep, an_array_alloc_eh_info_ptr aaehip, a_boolean is_vec_new);
#line 189
static void *_ZN34_INTERNAL_12_vec_newdel_c_8a08d4a511alloc_arrayEyyPFPvyE(size_t size, size_t prefix_size, a_new_ptr new_routine);
#line 222
static void _ZN34_INTERNAL_12_vec_newdel_c_8a08d4a510free_arrayEPvyyPFvS0_Ei(void *array_ptr, size_t size, size_t prefix_size, a_delete_ptr delete_routine, int is_two_arg);
#line 274
static a_boolean _ZN34_INTERNAL_12_vec_newdel_c_8a08d4a523record_array_alloc_infoEPvyxy(void *array_ptr, size_t size, ptrdiff_t number_of_elements, size_t element_size);
#line 334
static size_t _ZN34_INTERNAL_12_vec_newdel_c_8a08d4a514get_array_sizeEPvyPy(void *array_ptr, size_t element_size, size_t *number_of_elements);
#line 409
static void *_ZN34_INTERNAL_12_vec_newdel_c_8a08d4a517array_new_generalEPvxyyS0_PFvS0_ES2_PFS0_yES2_ii(void *array_ptr, ptrdiff_t number_of_elements, size_t element_size, size_t prefix_size, void *src_array_ptr, a_constructor_ptr ctor, a_destructor_ptr dtor, a_new_ptr new_routine, a_delete_ptr 
#line 409
delete_routine, int is_two_arg, a_boolean zero_init);
#line 756
extern void *__cxa_vec_new(size_t number_of_elements, size_t element_size, size_t prefix_size, a_constructor_ptr ctor, a_destructor_ptr dtor);
#line 773
extern void *__cxa_vec_new2(size_t number_of_elements, size_t element_size, size_t prefix_size, a_constructor_ptr ctor, a_destructor_ptr dtor, a_new_ptr new_routine, a_delete_ptr delete_routine);
#line 793
extern void *__cxa_vec_new3(size_t number_of_elements, size_t element_size, size_t prefix_size, a_constructor_ptr ctor, a_destructor_ptr dtor, a_new_ptr new_routine, a_two_operand_delete_ptr delete_routine);
#line 814
extern void __cxa_vec_ctor(void *array_ptr, size_t number_of_elements, size_t element_size, a_constructor_ptr ctor, a_destructor_ptr dtor);
#line 832
extern void __cxa_vec_cctor(void *array_ptr, void *src_array_ptr, size_t number_of_elements, size_t element_size, a_copy_constructor_ptr ctor, a_destructor_ptr dtor);
#line 853
extern void __cleanup_vec_new_or_delete(an_eh_stack_entry_ptr ehsep);
#line 917
static void _ZN34_INTERNAL_12_vec_newdel_c_8a08d4a520array_delete_generalEPvxyyPFvS0_EiS2_ii(void *array_ptr, ptrdiff_t number_of_elements_param, size_t element_size, size_t prefix_size, a_destructor_ptr dtor, int delete_flag, a_delete_ptr delete_routine, int is_two_arg, int terminate_immediately);
#line 1058
extern void __cxa_vec_dtor(void *array_ptr, size_t number_of_elements, size_t element_size, a_destructor_ptr dtor);
#line 1074
extern void __cxa_vec_delete(void *array_ptr, size_t element_size, size_t prefix_size, a_destructor_ptr dtor);
#line 1089
extern void __cxa_vec_delete2(void *array_ptr, size_t element_size, size_t prefix_size, a_destructor_ptr dtor, a_delete_ptr delete_routine);
#line 1105
extern void __cxa_vec_delete3(void *array_ptr, size_t element_size, size_t prefix_size, a_destructor_ptr dtor, a_two_operand_delete_ptr delete_routine);
#line 1123
extern void __cxa_vec_cleanup(void *array_ptr, size_t number_of_elements, size_t element_size, a_destructor_ptr dtor);
#line 1143
extern void __cxa_throw_bad_array_new_length(void);
#line 424 "lib_src/eh.h"
extern an_eh_stack_entry_ptr __curr_eh_stack_entry;
#line 112 "lib_src/vec_newdel.c"
static void _ZN34_INTERNAL_12_vec_newdel_c_8a08d4a536add_vec_new_or_delete_eh_stack_entryEP17an_eh_stack_entryP22an_array_alloc_eh_infoi(
an_eh_stack_entry_ptr __3917_32_ehsep, 
an_array_alloc_eh_info_ptr __3918_61_aaehip, 
a_boolean __3919_28_is_vec_new)




{
(__3917_32_ehsep->next) = __curr_eh_stack_entry;
__curr_eh_stack_entry = __3917_32_ehsep;
(__3917_32_ehsep->kind) = ehsek_vec_new_or_delete;
((__3917_32_ehsep->variant).array_alloc_eh_info) = __3918_61_aaehip;
(__3918_61_aaehip->array_ptr) = ((void *)0);
(__3918_61_aaehip->number_of_elements) = 0LL;
(__3918_61_aaehip->element_size) = 0ULL;
(__3918_61_aaehip->prefix_size) = 0ULL;
(__3918_61_aaehip->elements_processed) = 0ULL;
(__3918_61_aaehip->is_vec_new) = __3919_28_is_vec_new;
(__3918_61_aaehip->free_memory_on_cleanup) = 0;
(__3918_61_aaehip->destructor) = ((a_destructor_ptr)0);
(__3918_61_aaehip->delete_routine) = ((a_delete_ptr)0);
(__3918_61_aaehip->is_two_arg) = 0; 
}
#line 189
static void *_ZN34_INTERNAL_12_vec_newdel_c_8a08d4a511alloc_arrayEyyPFPvyE( size_t __3993_41_size, 
size_t __3994_49_prefix_size, 
a_new_ptr __3995_22_new_routine)
#line 198
{
auto void *__4003_10_array_ptr;

__3993_41_size += __3994_49_prefix_size;



if (__3995_22_new_routine == ((a_new_ptr)0)) {

__4003_10_array_ptr = (_Znay(__3993_41_size));



} else  {
__4003_10_array_ptr = ((*__3995_22_new_routine)(__3993_41_size));
}
if (__4003_10_array_ptr != ((void *)0)) {

__4003_10_array_ptr = ((void *)(((char *)__4003_10_array_ptr) + __3994_49_prefix_size));
}
return __4003_10_array_ptr;
}


static void _ZN34_INTERNAL_12_vec_newdel_c_8a08d4a510free_arrayEPvyyPFvS0_Ei( void *__4026_31_array_ptr, 
size_t __4027_18_size, 
size_t __4028_41_prefix_size, 
a_delete_ptr __4029_23_delete_routine, 
int __4030_15_is_two_arg)
#line 233
{

__4027_18_size += __4028_41_prefix_size;

__4026_31_array_ptr = ((void *)(((char *)__4026_31_array_ptr) - __4028_41_prefix_size));



if (__4029_23_delete_routine == ((a_delete_ptr)0)) {

_ZdaPv(__4026_31_array_ptr);



} else  {
if (__4030_15_is_two_arg) { auto void *__T962933384; auto size_t __T962934032;
auto a_two_operand_delete_ptr __4053_32_two_op_delete_routine;
__4053_32_two_op_delete_routine = ((a_two_operand_delete_ptr)__4029_23_delete_routine);
((__T962933384 = __4026_31_array_ptr) , (__T962934032 = __4027_18_size)) , ((*__4053_32_two_op_delete_routine)(__T962933384, __T962934032));
} else  {
(*__4029_23_delete_routine)(__4026_31_array_ptr);
}
} 
}
#line 274
static a_boolean _ZN34_INTERNAL_12_vec_newdel_c_8a08d4a523record_array_alloc_infoEPvyxy( void *__4078_57_array_ptr, 
size_t __4079_26_size, 
ptrdiff_t __4080_24_number_of_elements, 
size_t __4081_16_element_size)
#line 283
{

auto an_alloc_prefix_ptr __4089_23_app;
#line 295
__4089_23_app = (((an_alloc_prefix_ptr)__4078_57_array_ptr) - 1);

(*__4089_23_app) = ((an_alloc_prefix)__4080_24_number_of_elements);
#line 303
return 0;
#line 327
}
#line 334
static size_t _ZN34_INTERNAL_12_vec_newdel_c_8a08d4a514get_array_sizeEPvyPy( void *__4138_43_array_ptr, 
size_t __4139_17_element_size, 
size_t *__4140_17_number_of_elements)
#line 344
{

auto an_alloc_prefix_ptr __4150_23_app;
auto size_t __4151_11_size;
#line 365
__4150_23_app = (((an_alloc_prefix_ptr)__4138_43_array_ptr) - 1);



(*__4140_17_number_of_elements) = (*__4150_23_app);

__4151_11_size = ((*__4140_17_number_of_elements) * __4139_17_element_size);

return __4151_11_size;
#line 403
}
#line 409
static void *_ZN34_INTERNAL_12_vec_newdel_c_8a08d4a517array_new_generalEPvxyyS0_PFvS0_ES2_PFS0_yES2_ii( void *__4213_55_array_ptr, 
ptrdiff_t __4214_47_number_of_elements, 
size_t __4215_54_element_size, 
size_t __4216_54_prefix_size, 
void *__4217_55_src_array_ptr, 
a_constructor_ptr __4218_54_ctor, 
a_destructor_ptr __4219_54_dtor, 
a_new_ptr __4220_33_new_routine, 
a_delete_ptr __4221_54_delete_routine, 
int __4222_21_is_two_arg, 
a_boolean __4223_54_zero_init)
#line 461
{ auto void *__T962995784; auto size_t __T962996432;
auto size_t __4266_13_array_size;
auto ptrdiff_t __4267_13_i;
auto void *__4268_14_arr_ptr;


auto an_eh_stack_entry __4271_22_ehse;
auto struct an_array_alloc_eh_info __4272_26_aaehi;
auto a_boolean __4273_15_create_eh_stack_entry;
auto a_boolean __4274_15_free_memory_on_cleanup; __4274_15_free_memory_on_cleanup = ((a_boolean)(__4213_55_array_ptr == ((void *)0)));




__4273_15_create_eh_stack_entry = ((a_boolean)((__4219_54_dtor != ((a_destructor_ptr)0)) || (__4213_55_array_ptr == ((void *)0))));

if ((__4213_55_array_ptr == ((void *)0)) || (__4216_54_prefix_size != 0ULL)) { auto void *__T962992752; auto size_t __T962993400; auto ptrdiff_t __T962994136; auto size_t __T962994872;
auto a_boolean __4282_15_err;
#line 486
if ((__4215_54_element_size != 0ULL) && (((unsigned long long)__4214_47_number_of_elements) > ((18446744073709551615ULL - __4216_54_prefix_size) / __4215_54_element_size)))
{
__cxa_throw_bad_array_new_length();
}


__4266_13_array_size = (((unsigned long long)__4214_47_number_of_elements) * __4215_54_element_size);



if (__4266_13_array_size == 0ULL) { __4266_13_array_size = 1ULL; }
if (__4213_55_array_ptr == ((void *)0)) { auto size_t __T962990184; auto size_t __T962991104; auto a_new_ptr __T962991840;


__4213_55_array_ptr = ((((__T962990184 = __4266_13_array_size) , (__T962991104 = __4216_54_prefix_size)) , (__T962991840 = __4220_33_new_routine)) , (_ZN34_INTERNAL_12_vec_newdel_c_8a08d4a511alloc_arrayEyyPFPvyE(__T962990184, __T962991104, __T962991840)));
if (__4213_55_array_ptr == ((void *)0)) {
goto __4387_1_error_exit;
}
}


if (__4216_54_prefix_size != 0ULL) {
__4282_15_err = (((((__T962992752 = __4213_55_array_ptr) , (__T962993400 = __4266_13_array_size)) , (__T962994136 = __4214_47_number_of_elements)) , (__T962994872 = __4215_54_element_size)) , (_ZN34_INTERNAL_12_vec_newdel_c_8a08d4a523record_array_alloc_infoEPvyxy(__T962992752, __T962993400, 
#line 508
__T962994136, __T962994872)));

if (__4282_15_err) { goto __4387_1_error_exit; }
}

} else  { if (__4223_54_zero_init) {
__4266_13_array_size = (((unsigned long long)__4214_47_number_of_elements) * __4215_54_element_size);

} }

if (__4223_54_zero_init) {
((__T962995784 = __4213_55_array_ptr) , (__T962996432 = __4266_13_array_size)) , (__memzero(__T962995784, __T962996432));
}


if (__4273_15_create_eh_stack_entry) {
_ZN34_INTERNAL_12_vec_newdel_c_8a08d4a536add_vec_new_or_delete_eh_stack_entryEP17an_eh_stack_entryP22an_array_alloc_eh_infoi((&__4271_22_ehse), (&__4272_26_aaehi), 1);
(__4272_26_aaehi.free_memory_on_cleanup) = __4274_15_free_memory_on_cleanup;
(__4272_26_aaehi.number_of_elements) = __4214_47_number_of_elements;
(__4272_26_aaehi.element_size) = __4215_54_element_size;
(__4272_26_aaehi.prefix_size) = __4216_54_prefix_size;
(__4272_26_aaehi.destructor) = __4219_54_dtor;
(__4272_26_aaehi.delete_routine) = __4221_54_delete_routine;
(__4272_26_aaehi.is_two_arg) = __4222_21_is_two_arg;
(__4272_26_aaehi.array_ptr) = __4213_55_array_ptr;

(__4272_26_aaehi.terminate_immediately) = 0;

}
#line 545
if (__4218_54_ctor != ((a_constructor_ptr)0)) {
for ((__4267_13_i = 0LL) , (__4268_14_arr_ptr = __4213_55_array_ptr); __4267_13_i < __4214_47_number_of_elements; (__4267_13_i++) , (__4268_14_arr_ptr = ((void *)(((char *)__4268_14_arr_ptr) + __4215_54_element_size))))

{
if (__4217_55_src_array_ptr == ((void *)0)) {
#line 557
(*__4218_54_ctor)(__4268_14_arr_ptr);

} else  { auto void *__T962997344; auto void *__T962997992;

auto a_copy_constructor_ptr __4365_32_cctor;
__4365_32_cctor = ((a_copy_constructor_ptr)__4218_54_ctor);
((__T962997344 = __4268_14_arr_ptr) , (__T962997992 = __4217_55_src_array_ptr)) , ((*__4365_32_cctor)(__T962997344, __T962997992));
}

if (__4219_54_dtor != ((a_destructor_ptr)0)) {


(__4272_26_aaehi.elements_processed)++;
}



if (__4217_55_src_array_ptr != ((void *)0)) { __4217_55_src_array_ptr = ((void *)(((char *)__4217_55_src_array_ptr) + __4215_54_element_size)); }
}
}

if (__4273_15_create_eh_stack_entry) {

__curr_eh_stack_entry = (__curr_eh_stack_entry->next);
}

__4387_1_error_exit:;

return __4213_55_array_ptr;
}
#line 756
void *__cxa_vec_new(
size_t __4561_60_number_of_elements, 
size_t __4562_60_element_size, 
size_t __4563_60_prefix_size, 
a_constructor_ptr __4564_60_ctor, 
a_destructor_ptr __4565_60_dtor)



{ auto ptrdiff_t __T963005480; auto size_t __T963006128; auto size_t __T963006864; auto a_constructor_ptr __T963007600; auto a_destructor_ptr __T963008336;
return (((((__T963005480 = ((ptrdiff_t)__4561_60_number_of_elements)) , (__T963006128 = __4562_60_element_size)) , (__T963006864 = __4563_60_prefix_size)) , (__T963007600 = __4564_60_ctor)) , (__T963008336 = __4565_60_dtor)) , (
#line 766
_ZN34_INTERNAL_12_vec_newdel_c_8a08d4a517array_new_generalEPvxyyS0_PFvS0_ES2_PFS0_yES2_ii(((void *)0), __T963005480, __T963006128, __T963006864, ((void *)0), __T963007600, __T963008336, ((a_new_ptr)0), ((a_delete_ptr)0), 0, 0));



}


void *__cxa_vec_new2(
size_t __4578_60_number_of_elements, 
size_t __4579_60_element_size, 
size_t __4580_60_prefix_size, 
a_constructor_ptr __4581_60_ctor, 
a_destructor_ptr __4582_60_dtor, 
a_new_ptr __4583_60_new_routine, 
a_delete_ptr __4584_60_delete_routine)




{ auto ptrdiff_t __T963015328; auto size_t __T963015976; auto size_t __T963016712; auto a_constructor_ptr __T963017448; auto a_destructor_ptr __T963018184; auto a_new_ptr __T963018920; auto a_delete_ptr __T963019656;
return (((((((__T963015328 = ((ptrdiff_t)__4578_60_number_of_elements)) , (__T963015976 = __4579_60_element_size)) , (__T963016712 = __4580_60_prefix_size)) , (__T963017448 = __4581_60_ctor)) , (__T963018184 = __4582_60_dtor)) , (__T963018920 = __4583_60_new_routine)) , (__T963019656 = 
#line 786
__4584_60_delete_routine)) , (_ZN34_INTERNAL_12_vec_newdel_c_8a08d4a517array_new_generalEPvxyyS0_PFvS0_ES2_PFS0_yES2_ii(((void *)0), __T963015328, __T963015976, __T963016712, ((void *)0), __T963017448, __T963018184, __T963018920, __T963019656, 0, 0));



}


void *__cxa_vec_new3(
size_t __4598_60_number_of_elements, 
size_t __4599_60_element_size, 
size_t __4600_60_prefix_size, 
a_constructor_ptr __4601_60_ctor, 
a_destructor_ptr __4602_60_dtor, 
a_new_ptr __4603_60_new_routine, 
a_two_operand_delete_ptr __4604_60_delete_routine)




{ auto ptrdiff_t __T963026736; auto size_t __T963027384; auto size_t __T963028120; auto a_constructor_ptr __T963028856; auto a_destructor_ptr __T963029592; auto a_new_ptr __T963030328; auto a_delete_ptr __T963031064;
return (((((((__T963026736 = ((ptrdiff_t)__4598_60_number_of_elements)) , (__T963027384 = __4599_60_element_size)) , (__T963028120 = __4600_60_prefix_size)) , (__T963028856 = __4601_60_ctor)) , (__T963029592 = __4602_60_dtor)) , (__T963030328 = __4603_60_new_routine)) , (__T963031064 = ((
#line 806
a_delete_ptr)__4604_60_delete_routine))) , (_ZN34_INTERNAL_12_vec_newdel_c_8a08d4a517array_new_generalEPvxyyS0_PFvS0_ES2_PFS0_yES2_ii(((void *)0), __T963026736, __T963027384, __T963028120, ((void *)0), __T963028856, __T963029592, __T963030328, __T963031064, 1, 0));




}


void __cxa_vec_ctor(
void *__4619_61_array_ptr, 
size_t __4620_60_number_of_elements, 
size_t __4621_60_element_size, 
a_constructor_ptr __4622_60_ctor, 
a_destructor_ptr __4623_60_dtor)




{ auto void *__T963104408; auto ptrdiff_t __T963105056; auto size_t __T963105792; auto a_constructor_ptr __T963106528; auto a_destructor_ptr __T963107264;
(((((__T963104408 = __4619_61_array_ptr) , (__T963105056 = ((ptrdiff_t)__4620_60_number_of_elements))) , (__T963105792 = __4621_60_element_size)) , (__T963106528 = __4622_60_ctor)) , (__T963107264 = __4623_60_dtor)) , (
#line 825
_ZN34_INTERNAL_12_vec_newdel_c_8a08d4a517array_new_generalEPvxyyS0_PFvS0_ES2_PFS0_yES2_ii(__T963104408, __T963105056, __T963105792, 0ULL, ((void *)0), __T963106528, __T963107264, ((a_new_ptr)0), ((a_delete_ptr)0), 0, 0)); 



}


void __cxa_vec_cctor(
void *__4637_61_array_ptr, 
void *__4638_61_src_array_ptr, 
size_t __4639_60_number_of_elements, 
size_t __4640_60_element_size, 
a_copy_constructor_ptr __4641_60_ctor, 
a_destructor_ptr __4642_60_dtor)



{ auto void *__T963114768; auto ptrdiff_t __T963115416; auto size_t __T963116152; auto void *__T963116888; auto a_constructor_ptr __T963117624; auto a_destructor_ptr __T963118360;
((((((__T963114768 = __4637_61_array_ptr) , (__T963115416 = ((ptrdiff_t)__4639_60_number_of_elements))) , (__T963116152 = __4640_60_element_size)) , (__T963116888 = __4638_61_src_array_ptr)) , (__T963117624 = ((a_constructor_ptr)__4641_60_ctor))) , (__T963118360 = __4642_60_dtor)) , (
#line 843
_ZN34_INTERNAL_12_vec_newdel_c_8a08d4a517array_new_generalEPvxyyS0_PFvS0_ES2_PFS0_yES2_ii(__T963114768, __T963115416, __T963116152, 0ULL, __T963116888, __T963117624, __T963118360, ((a_new_ptr)0), ((a_delete_ptr)0), 0, 0)); 




}




void __cleanup_vec_new_or_delete( an_eh_stack_entry_ptr __4657_65_ehsep)
#line 859
{


auto an_array_alloc_eh_info_ptr __4666_30_aaehip;
auto a_destructor_ptr __4667_21_dtor;
auto size_t __4668_14_number_of_elements;
auto size_t __4669_14_element_size;
auto void *__4670_25_arr_ptr;
auto void *__4671_12_array_ptr;
auto size_t __4672_14_i;
auto size_t __4673_21_first_element;
#line 862
__4666_30_aaehip = ((__4657_65_ehsep->variant).array_alloc_eh_info);
__4667_21_dtor = (__4666_30_aaehip->destructor);
#line 872
if (__4666_30_aaehip->terminate_immediately) {
__call_terminate();
}

__4671_12_array_ptr = ((void *)(__4666_30_aaehip->array_ptr));
__4669_14_element_size = (__4666_30_aaehip->element_size);
if (__4666_30_aaehip->is_vec_new) {


__4668_14_number_of_elements = (__4666_30_aaehip->elements_processed);
__4673_21_first_element = (__4668_14_number_of_elements - 1ULL);
} else  {
__4673_21_first_element = ((((unsigned long long)(__4666_30_aaehip->number_of_elements)) - (__4666_30_aaehip->elements_processed)) - 1ULL);

__4668_14_number_of_elements = (__4673_21_first_element + 1ULL);
}
if (__4667_21_dtor != ((a_destructor_ptr)0)) {

for ((__4672_14_i = 0ULL) , (__4670_25_arr_ptr = ((void *)(((char *)__4671_12_array_ptr) + (__4673_21_first_element * __4669_14_element_size)))); __4672_14_i < __4668_14_number_of_elements; (__4672_14_i++) , (__4670_25_arr_ptr = ((void *)(((char *)__4670_25_arr_ptr) + (-((int)
#line 890
__4669_14_element_size))))))



{
#line 900
(*__4667_21_dtor)(__4670_25_arr_ptr);

}
}
if (__4666_30_aaehip->free_memory_on_cleanup) { auto void *__T963140920; auto size_t __T963141568; auto size_t __T963142304; auto a_delete_ptr __T963143040; auto a_boolean __T963143776;

auto size_t __4710_12_size; __4710_12_size = (__4669_14_element_size * ((unsigned long long)(__4666_30_aaehip->number_of_elements)));
(((((__T963140920 = __4671_12_array_ptr) , (__T963141568 = __4710_12_size)) , (__T963142304 = (__4666_30_aaehip->prefix_size))) , (__T963143040 = (__4666_30_aaehip->delete_routine))) , (__T963143776 = (__4666_30_aaehip->is_two_arg))) , (
#line 907
_ZN34_INTERNAL_12_vec_newdel_c_8a08d4a510free_arrayEPvyyPFvS0_Ei(__T963140920, __T963141568, __T963142304, __T963143040, __T963143776));

} 
}
#line 917
static void _ZN34_INTERNAL_12_vec_newdel_c_8a08d4a520array_delete_generalEPvxyyPFvS0_EiS2_ii( void *__4721_55_array_ptr, 
ptrdiff_t __4722_54_number_of_elements_param, 
size_t __4723_54_element_size, 
size_t __4724_54_prefix_size, 
a_destructor_ptr __4725_54_dtor, 
int __4726_16_delete_flag, 
a_delete_ptr __4727_52_delete_routine, 
int __4728_16_is_two_arg, 
int __4729_54_terminate_immediately)
#line 941
{
auto size_t __4746_25_i;
auto void *__4747_26_arr_ptr;
auto size_t __4748_11_array_size = 0ULL;
auto size_t __4749_11_number_of_elements; __4749_11_number_of_elements = ((size_t)__4722_54_number_of_elements_param);


if (__4721_55_array_ptr != ((void *)0)) { auto void *__T963173648; auto size_t __T963174296; auto size_t __T963175032; auto a_delete_ptr __T963175768; auto int __T963176504;

auto an_eh_stack_entry __4754_24_ehse;
auto struct an_array_alloc_eh_info __4755_28_aaehi;
_ZN34_INTERNAL_12_vec_newdel_c_8a08d4a536add_vec_new_or_delete_eh_stack_entryEP17an_eh_stack_entryP22an_array_alloc_eh_infoi((&__4754_24_ehse), (&__4755_28_aaehi), 0);

(__4755_28_aaehi.free_memory_on_cleanup) = __4726_16_delete_flag;
(__4755_28_aaehi.array_ptr) = __4721_55_array_ptr;
(__4755_28_aaehi.number_of_elements) = ((ptrdiff_t)__4749_11_number_of_elements);
(__4755_28_aaehi.element_size) = __4723_54_element_size;
(__4755_28_aaehi.prefix_size) = __4724_54_prefix_size;
(__4755_28_aaehi.destructor) = __4725_54_dtor;
(__4755_28_aaehi.delete_routine) = __4727_52_delete_routine;
(__4755_28_aaehi.is_two_arg) = __4728_16_is_two_arg;

(__4755_28_aaehi.terminate_immediately) = __4729_54_terminate_immediately;




if ((__4722_54_number_of_elements_param == (-1LL)) && (__4724_54_prefix_size != 0ULL)) { auto void *__T963171816; auto size_t __T963172736;

__4748_11_array_size = (((__T963171816 = __4721_55_array_ptr) , (__T963172736 = __4723_54_element_size)) , (_ZN34_INTERNAL_12_vec_newdel_c_8a08d4a514get_array_sizeEPvyPy(__T963171816, __T963172736, (&__4749_11_number_of_elements))));

}

(__4755_28_aaehi.number_of_elements) = ((ptrdiff_t)__4749_11_number_of_elements);




if (__4725_54_dtor != ((a_destructor_ptr)0)) {
for ((__4746_25_i = 0ULL) , (__4747_26_arr_ptr = ((void *)(((char *)__4721_55_array_ptr) + ((__4749_11_number_of_elements - 1ULL) * __4723_54_element_size)))); __4746_25_i < __4749_11_number_of_elements; (__4746_25_i++) , (__4747_26_arr_ptr = ((void *)(((char *)__4747_26_arr_ptr) + (-((int)
#line 980
__4723_54_element_size))))))



{
#line 990
(__4755_28_aaehi.elements_processed)++;
#line 997
(*__4725_54_dtor)(__4747_26_arr_ptr);

}
}




__curr_eh_stack_entry = (__curr_eh_stack_entry->next);


if (__4726_16_delete_flag) {
(((((__T963173648 = __4721_55_array_ptr) , (__T963174296 = __4748_11_array_size)) , (__T963175032 = __4724_54_prefix_size)) , (__T963175768 = __4727_52_delete_routine)) , (__T963176504 = __4728_16_is_two_arg)) , (_ZN34_INTERNAL_12_vec_newdel_c_8a08d4a510free_arrayEPvyyPFvS0_Ei(__T963173648, 
#line 1009
__T963174296, __T963175032, __T963175768, __T963176504));

}
} 
}
#line 1058
void __cxa_vec_dtor(
void *__4863_61_array_ptr, 
size_t __4864_60_number_of_elements, 
size_t __4865_60_element_size, 
a_destructor_ptr __4866_60_dtor)



{ auto void *__T963182544; auto ptrdiff_t __T963183192; auto size_t __T963183928; auto a_destructor_ptr __T963184664;
((((__T963182544 = __4863_61_array_ptr) , (__T963183192 = ((ptrdiff_t)__4864_60_number_of_elements))) , (__T963183928 = __4865_60_element_size)) , (__T963184664 = __4866_60_dtor)) , (_ZN34_INTERNAL_12_vec_newdel_c_8a08d4a520array_delete_generalEPvxyyPFvS0_EiS2_ii(__T963182544, __T963183192, 
#line 1067
__T963183928, 0ULL, __T963184664, 0, ((a_delete_ptr)0), 0, 0)); 



}


void __cxa_vec_delete( void *__4878_65_array_ptr, 
size_t __4879_64_element_size, 
size_t __4880_64_prefix_size, 
a_destructor_ptr __4881_64_dtor)



{ auto void *__T963191008; auto size_t __T963191656; auto size_t __T963192392; auto a_destructor_ptr __T963193128;
((((__T963191008 = __4878_65_array_ptr) , (__T963191656 = __4879_64_element_size)) , (__T963192392 = __4880_64_prefix_size)) , (__T963193128 = __4881_64_dtor)) , (_ZN34_INTERNAL_12_vec_newdel_c_8a08d4a520array_delete_generalEPvxyyPFvS0_EiS2_ii(__T963191008, (-1LL), __T963191656, __T963192392, 
#line 1082
__T963193128, 1, ((a_delete_ptr)0), 0, 0)); 



}


void __cxa_vec_delete2( void *__4893_66_array_ptr, 
size_t __4894_65_element_size, 
size_t __4895_65_prefix_size, 
a_destructor_ptr __4896_65_dtor, 
a_delete_ptr __4897_65_delete_routine)



{ auto void *__T963199224; auto size_t __T963199872; auto size_t __T963200608; auto a_destructor_ptr __T963201344; auto a_delete_ptr __T963202080;
(((((__T963199224 = __4893_66_array_ptr) , (__T963199872 = __4894_65_element_size)) , (__T963200608 = __4895_65_prefix_size)) , (__T963201344 = __4896_65_dtor)) , (__T963202080 = __4897_65_delete_routine)) , (_ZN34_INTERNAL_12_vec_newdel_c_8a08d4a520array_delete_generalEPvxyyPFvS0_EiS2_ii(
#line 1098
__T963199224, (-1LL), __T963199872, __T963200608, __T963201344, 1, __T963202080, 0, 0)); 



}


void __cxa_vec_delete3(
void *__4910_64_array_ptr, 
size_t __4911_63_element_size, 
size_t __4912_63_prefix_size, 
a_destructor_ptr __4913_63_dtor, 
a_two_operand_delete_ptr __4914_63_delete_routine)




{ auto void *__T963208264; auto size_t __T963208912; auto size_t __T963209648; auto a_destructor_ptr __T963210384; auto a_delete_ptr __T963211120;
(((((__T963208264 = __4910_64_array_ptr) , (__T963208912 = __4911_63_element_size)) , (__T963209648 = __4912_63_prefix_size)) , (__T963210384 = __4913_63_dtor)) , (__T963211120 = ((a_delete_ptr)__4914_63_delete_routine))) , (
#line 1116
_ZN34_INTERNAL_12_vec_newdel_c_8a08d4a520array_delete_generalEPvxyyPFvS0_EiS2_ii(__T963208264, (-1LL), __T963208912, __T963209648, __T963210384, 1, __T963211120, 1, 0)); 



}


void __cxa_vec_cleanup(
void *__4928_24_array_ptr, 
size_t __4929_23_number_of_elements, 
size_t __4930_23_element_size, 
a_destructor_ptr __4931_23_dtor)




{
if (__4931_23_dtor != ((a_destructor_ptr)0)) { auto void *__T963218320; auto ptrdiff_t __T963219240; auto size_t __T963219976; auto a_destructor_ptr __T963220712;
((((__T963218320 = __4928_24_array_ptr) , (__T963219240 = ((ptrdiff_t)__4929_23_number_of_elements))) , (__T963219976 = __4930_23_element_size)) , (__T963220712 = __4931_23_dtor)) , (_ZN34_INTERNAL_12_vec_newdel_c_8a08d4a520array_delete_generalEPvxyyPFvS0_EiS2_ii(__T963218320, __T963219240, 
#line 1134
__T963219976, 0ULL, __T963220712, 0, ((a_delete_ptr)0), 0, 1));



} 
}



void __cxa_throw_bad_array_new_length(void)
#line 1149
{

__throw_bad_array_new_length(); 

}
