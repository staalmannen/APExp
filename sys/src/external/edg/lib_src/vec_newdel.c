/* Translated by the Edison Design Group C++/C front end (version 7.0) */
/* Thu Oct  8 07:53:17 2026 */
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
an_eh_stack_entry_ptr __3945_32_ehsep, 
an_array_alloc_eh_info_ptr __3946_61_aaehip, 
a_boolean __3947_28_is_vec_new)




{
(__3945_32_ehsep->next) = __curr_eh_stack_entry;
__curr_eh_stack_entry = __3945_32_ehsep;
(__3945_32_ehsep->kind) = ehsek_vec_new_or_delete;
((__3945_32_ehsep->variant).array_alloc_eh_info) = __3946_61_aaehip;
(__3946_61_aaehip->array_ptr) = ((void *)0);
(__3946_61_aaehip->number_of_elements) = 0LL;
(__3946_61_aaehip->element_size) = 0ULL;
(__3946_61_aaehip->prefix_size) = 0ULL;
(__3946_61_aaehip->elements_processed) = 0ULL;
(__3946_61_aaehip->is_vec_new) = __3947_28_is_vec_new;
(__3946_61_aaehip->free_memory_on_cleanup) = 0;
(__3946_61_aaehip->destructor) = ((a_destructor_ptr)0);
(__3946_61_aaehip->delete_routine) = ((a_delete_ptr)0);
(__3946_61_aaehip->is_two_arg) = 0; 
}
#line 189
static void *_ZN34_INTERNAL_12_vec_newdel_c_8a08d4a511alloc_arrayEyyPFPvyE( size_t __4021_41_size, 
size_t __4022_49_prefix_size, 
a_new_ptr __4023_22_new_routine)
#line 198
{
auto void *__4031_10_array_ptr;

__4021_41_size += __4022_49_prefix_size;



if (__4023_22_new_routine == ((a_new_ptr)0)) {

__4031_10_array_ptr = (_Znay(__4021_41_size));



} else  {
__4031_10_array_ptr = ((*__4023_22_new_routine)(__4021_41_size));
}
if (__4031_10_array_ptr != ((void *)0)) {

__4031_10_array_ptr = ((void *)(((char *)__4031_10_array_ptr) + __4022_49_prefix_size));
}
return __4031_10_array_ptr;
}


static void _ZN34_INTERNAL_12_vec_newdel_c_8a08d4a510free_arrayEPvyyPFvS0_Ei( void *__4054_31_array_ptr, 
size_t __4055_18_size, 
size_t __4056_41_prefix_size, 
a_delete_ptr __4057_23_delete_routine, 
int __4058_15_is_two_arg)
#line 233
{

__4055_18_size += __4056_41_prefix_size;

__4054_31_array_ptr = ((void *)(((char *)__4054_31_array_ptr) - __4056_41_prefix_size));



if (__4057_23_delete_routine == ((a_delete_ptr)0)) {

_ZdaPv(__4054_31_array_ptr);



} else  {
if (__4058_15_is_two_arg) { auto void *__T869499896; auto size_t __T869500544;
auto a_two_operand_delete_ptr __4081_32_two_op_delete_routine;
__4081_32_two_op_delete_routine = ((a_two_operand_delete_ptr)__4057_23_delete_routine);
((__T869499896 = __4054_31_array_ptr) , (__T869500544 = __4055_18_size)) , ((*__4081_32_two_op_delete_routine)(__T869499896, __T869500544));
} else  {
(*__4057_23_delete_routine)(__4054_31_array_ptr);
}
} 
}
#line 274
static a_boolean _ZN34_INTERNAL_12_vec_newdel_c_8a08d4a523record_array_alloc_infoEPvyxy( void *__4106_57_array_ptr, 
size_t __4107_26_size, 
ptrdiff_t __4108_24_number_of_elements, 
size_t __4109_16_element_size)
#line 283
{

auto an_alloc_prefix_ptr __4117_23_app;
#line 295
__4117_23_app = (((an_alloc_prefix_ptr)__4106_57_array_ptr) - 1);

(*__4117_23_app) = ((an_alloc_prefix)__4108_24_number_of_elements);
#line 303
return 0;
#line 327
}
#line 334
static size_t _ZN34_INTERNAL_12_vec_newdel_c_8a08d4a514get_array_sizeEPvyPy( void *__4166_43_array_ptr, 
size_t __4167_17_element_size, 
size_t *__4168_17_number_of_elements)
#line 344
{

auto an_alloc_prefix_ptr __4178_23_app;
auto size_t __4179_11_size;
#line 365
__4178_23_app = (((an_alloc_prefix_ptr)__4166_43_array_ptr) - 1);



(*__4168_17_number_of_elements) = (*__4178_23_app);

__4179_11_size = ((*__4168_17_number_of_elements) * __4167_17_element_size);

return __4179_11_size;
#line 403
}
#line 409
static void *_ZN34_INTERNAL_12_vec_newdel_c_8a08d4a517array_new_generalEPvxyyS0_PFvS0_ES2_PFS0_yES2_ii( void *__4241_55_array_ptr, 
ptrdiff_t __4242_47_number_of_elements, 
size_t __4243_54_element_size, 
size_t __4244_54_prefix_size, 
void *__4245_55_src_array_ptr, 
a_constructor_ptr __4246_54_ctor, 
a_destructor_ptr __4247_54_dtor, 
a_new_ptr __4248_33_new_routine, 
a_delete_ptr __4249_54_delete_routine, 
int __4250_21_is_two_arg, 
a_boolean __4251_54_zero_init)
#line 461
{ auto void *__T869567112; auto size_t __T869567760;
auto size_t __4294_13_array_size;
auto ptrdiff_t __4295_13_i;
auto void *__4296_14_arr_ptr;


auto an_eh_stack_entry __4299_22_ehse;
auto struct an_array_alloc_eh_info __4300_26_aaehi;
auto a_boolean __4301_15_create_eh_stack_entry;
auto a_boolean __4302_15_free_memory_on_cleanup; __4302_15_free_memory_on_cleanup = ((a_boolean)(__4241_55_array_ptr == ((void *)0)));




__4301_15_create_eh_stack_entry = ((a_boolean)((__4247_54_dtor != ((a_destructor_ptr)0)) || (__4241_55_array_ptr == ((void *)0))));

if ((__4241_55_array_ptr == ((void *)0)) || (__4244_54_prefix_size != 0ULL)) { auto void *__T869564080; auto size_t __T869564728; auto ptrdiff_t __T869565464; auto size_t __T869566200;
auto a_boolean __4310_15_err;
#line 486
if ((__4243_54_element_size != 0ULL) && (((unsigned long long)__4242_47_number_of_elements) > ((18446744073709551615ULL - __4244_54_prefix_size) / __4243_54_element_size)))
{
__cxa_throw_bad_array_new_length();
}


__4294_13_array_size = (((unsigned long long)__4242_47_number_of_elements) * __4243_54_element_size);



if (__4294_13_array_size == 0ULL) { __4294_13_array_size = 1ULL; }
if (__4241_55_array_ptr == ((void *)0)) { auto size_t __T869561512; auto size_t __T869562432; auto a_new_ptr __T869563168;


__4241_55_array_ptr = ((((__T869561512 = __4294_13_array_size) , (__T869562432 = __4244_54_prefix_size)) , (__T869563168 = __4248_33_new_routine)) , (_ZN34_INTERNAL_12_vec_newdel_c_8a08d4a511alloc_arrayEyyPFPvyE(__T869561512, __T869562432, __T869563168)));
if (__4241_55_array_ptr == ((void *)0)) {
goto __4415_1_error_exit;
}
}


if (__4244_54_prefix_size != 0ULL) {
__4310_15_err = (((((__T869564080 = __4241_55_array_ptr) , (__T869564728 = __4294_13_array_size)) , (__T869565464 = __4242_47_number_of_elements)) , (__T869566200 = __4243_54_element_size)) , (_ZN34_INTERNAL_12_vec_newdel_c_8a08d4a523record_array_alloc_infoEPvyxy(__T869564080, __T869564728, 
#line 508
__T869565464, __T869566200)));

if (__4310_15_err) { goto __4415_1_error_exit; }
}

} else  { if (__4251_54_zero_init) {
__4294_13_array_size = (((unsigned long long)__4242_47_number_of_elements) * __4243_54_element_size);

} }

if (__4251_54_zero_init) {
((__T869567112 = __4241_55_array_ptr) , (__T869567760 = __4294_13_array_size)) , (__memzero(__T869567112, __T869567760));
}


if (__4301_15_create_eh_stack_entry) {
_ZN34_INTERNAL_12_vec_newdel_c_8a08d4a536add_vec_new_or_delete_eh_stack_entryEP17an_eh_stack_entryP22an_array_alloc_eh_infoi((&__4299_22_ehse), (&__4300_26_aaehi), 1);
(__4300_26_aaehi.free_memory_on_cleanup) = __4302_15_free_memory_on_cleanup;
(__4300_26_aaehi.number_of_elements) = __4242_47_number_of_elements;
(__4300_26_aaehi.element_size) = __4243_54_element_size;
(__4300_26_aaehi.prefix_size) = __4244_54_prefix_size;
(__4300_26_aaehi.destructor) = __4247_54_dtor;
(__4300_26_aaehi.delete_routine) = __4249_54_delete_routine;
(__4300_26_aaehi.is_two_arg) = __4250_21_is_two_arg;
(__4300_26_aaehi.array_ptr) = __4241_55_array_ptr;

(__4300_26_aaehi.terminate_immediately) = 0;

}
#line 545
if (__4246_54_ctor != ((a_constructor_ptr)0)) {
for ((__4295_13_i = 0LL) , (__4296_14_arr_ptr = __4241_55_array_ptr); __4295_13_i < __4242_47_number_of_elements; (__4295_13_i++) , (__4296_14_arr_ptr = ((void *)(((char *)__4296_14_arr_ptr) + __4243_54_element_size))))

{
if (__4245_55_src_array_ptr == ((void *)0)) {
#line 557
(*__4246_54_ctor)(__4296_14_arr_ptr);

} else  { auto void *__T869568672; auto void *__T869569320;

auto a_copy_constructor_ptr __4393_32_cctor;
__4393_32_cctor = ((a_copy_constructor_ptr)__4246_54_ctor);
((__T869568672 = __4296_14_arr_ptr) , (__T869569320 = __4245_55_src_array_ptr)) , ((*__4393_32_cctor)(__T869568672, __T869569320));
}

if (__4247_54_dtor != ((a_destructor_ptr)0)) {


(__4300_26_aaehi.elements_processed)++;
}



if (__4245_55_src_array_ptr != ((void *)0)) { __4245_55_src_array_ptr = ((void *)(((char *)__4245_55_src_array_ptr) + __4243_54_element_size)); }
}
}

if (__4301_15_create_eh_stack_entry) {

__curr_eh_stack_entry = (__curr_eh_stack_entry->next);
}

__4415_1_error_exit:;

return __4241_55_array_ptr;
}
#line 756
void *__cxa_vec_new(
size_t __4589_60_number_of_elements, 
size_t __4590_60_element_size, 
size_t __4591_60_prefix_size, 
a_constructor_ptr __4592_60_ctor, 
a_destructor_ptr __4593_60_dtor)



{ auto ptrdiff_t __T869576808; auto size_t __T869577456; auto size_t __T869578192; auto a_constructor_ptr __T869578928; auto a_destructor_ptr __T869579664;
return (((((__T869576808 = ((ptrdiff_t)__4589_60_number_of_elements)) , (__T869577456 = __4590_60_element_size)) , (__T869578192 = __4591_60_prefix_size)) , (__T869578928 = __4592_60_ctor)) , (__T869579664 = __4593_60_dtor)) , (
#line 766
_ZN34_INTERNAL_12_vec_newdel_c_8a08d4a517array_new_generalEPvxyyS0_PFvS0_ES2_PFS0_yES2_ii(((void *)0), __T869576808, __T869577456, __T869578192, ((void *)0), __T869578928, __T869579664, ((a_new_ptr)0), ((a_delete_ptr)0), 0, 0));



}


void *__cxa_vec_new2(
size_t __4606_60_number_of_elements, 
size_t __4607_60_element_size, 
size_t __4608_60_prefix_size, 
a_constructor_ptr __4609_60_ctor, 
a_destructor_ptr __4610_60_dtor, 
a_new_ptr __4611_60_new_routine, 
a_delete_ptr __4612_60_delete_routine)




{ auto ptrdiff_t __T869586656; auto size_t __T869587304; auto size_t __T869588040; auto a_constructor_ptr __T869588776; auto a_destructor_ptr __T869589512; auto a_new_ptr __T869590248; auto a_delete_ptr __T869590984;
return (((((((__T869586656 = ((ptrdiff_t)__4606_60_number_of_elements)) , (__T869587304 = __4607_60_element_size)) , (__T869588040 = __4608_60_prefix_size)) , (__T869588776 = __4609_60_ctor)) , (__T869589512 = __4610_60_dtor)) , (__T869590248 = __4611_60_new_routine)) , (__T869590984 = 
#line 786
__4612_60_delete_routine)) , (_ZN34_INTERNAL_12_vec_newdel_c_8a08d4a517array_new_generalEPvxyyS0_PFvS0_ES2_PFS0_yES2_ii(((void *)0), __T869586656, __T869587304, __T869588040, ((void *)0), __T869588776, __T869589512, __T869590248, __T869590984, 0, 0));



}


void *__cxa_vec_new3(
size_t __4626_60_number_of_elements, 
size_t __4627_60_element_size, 
size_t __4628_60_prefix_size, 
a_constructor_ptr __4629_60_ctor, 
a_destructor_ptr __4630_60_dtor, 
a_new_ptr __4631_60_new_routine, 
a_two_operand_delete_ptr __4632_60_delete_routine)




{ auto ptrdiff_t __T869598064; auto size_t __T869598712; auto size_t __T869599448; auto a_constructor_ptr __T869600184; auto a_destructor_ptr __T869600920; auto a_new_ptr __T869601656; auto a_delete_ptr __T869602392;
return (((((((__T869598064 = ((ptrdiff_t)__4626_60_number_of_elements)) , (__T869598712 = __4627_60_element_size)) , (__T869599448 = __4628_60_prefix_size)) , (__T869600184 = __4629_60_ctor)) , (__T869600920 = __4630_60_dtor)) , (__T869601656 = __4631_60_new_routine)) , (__T869602392 = ((
#line 806
a_delete_ptr)__4632_60_delete_routine))) , (_ZN34_INTERNAL_12_vec_newdel_c_8a08d4a517array_new_generalEPvxyyS0_PFvS0_ES2_PFS0_yES2_ii(((void *)0), __T869598064, __T869598712, __T869599448, ((void *)0), __T869600184, __T869600920, __T869601656, __T869602392, 1, 0));




}


void __cxa_vec_ctor(
void *__4647_61_array_ptr, 
size_t __4648_60_number_of_elements, 
size_t __4649_60_element_size, 
a_constructor_ptr __4650_60_ctor, 
a_destructor_ptr __4651_60_dtor)




{ auto void *__T869675736; auto ptrdiff_t __T869676384; auto size_t __T869677120; auto a_constructor_ptr __T869677856; auto a_destructor_ptr __T869678592;
(((((__T869675736 = __4647_61_array_ptr) , (__T869676384 = ((ptrdiff_t)__4648_60_number_of_elements))) , (__T869677120 = __4649_60_element_size)) , (__T869677856 = __4650_60_ctor)) , (__T869678592 = __4651_60_dtor)) , (
#line 825
_ZN34_INTERNAL_12_vec_newdel_c_8a08d4a517array_new_generalEPvxyyS0_PFvS0_ES2_PFS0_yES2_ii(__T869675736, __T869676384, __T869677120, 0ULL, ((void *)0), __T869677856, __T869678592, ((a_new_ptr)0), ((a_delete_ptr)0), 0, 0)); 



}


void __cxa_vec_cctor(
void *__4665_61_array_ptr, 
void *__4666_61_src_array_ptr, 
size_t __4667_60_number_of_elements, 
size_t __4668_60_element_size, 
a_copy_constructor_ptr __4669_60_ctor, 
a_destructor_ptr __4670_60_dtor)



{ auto void *__T869686096; auto ptrdiff_t __T869686744; auto size_t __T869687480; auto void *__T869688216; auto a_constructor_ptr __T869688952; auto a_destructor_ptr __T869689688;
((((((__T869686096 = __4665_61_array_ptr) , (__T869686744 = ((ptrdiff_t)__4667_60_number_of_elements))) , (__T869687480 = __4668_60_element_size)) , (__T869688216 = __4666_61_src_array_ptr)) , (__T869688952 = ((a_constructor_ptr)__4669_60_ctor))) , (__T869689688 = __4670_60_dtor)) , (
#line 843
_ZN34_INTERNAL_12_vec_newdel_c_8a08d4a517array_new_generalEPvxyyS0_PFvS0_ES2_PFS0_yES2_ii(__T869686096, __T869686744, __T869687480, 0ULL, __T869688216, __T869688952, __T869689688, ((a_new_ptr)0), ((a_delete_ptr)0), 0, 0)); 




}




void __cleanup_vec_new_or_delete( an_eh_stack_entry_ptr __4685_65_ehsep)
#line 859
{


auto an_array_alloc_eh_info_ptr __4694_30_aaehip;
auto a_destructor_ptr __4695_21_dtor;
auto size_t __4696_14_number_of_elements;
auto size_t __4697_14_element_size;
auto void *__4698_25_arr_ptr;
auto void *__4699_12_array_ptr;
auto size_t __4700_14_i;
auto size_t __4701_21_first_element;
#line 862
__4694_30_aaehip = ((__4685_65_ehsep->variant).array_alloc_eh_info);
__4695_21_dtor = (__4694_30_aaehip->destructor);
#line 872
if (__4694_30_aaehip->terminate_immediately) {
__call_terminate();
}

__4699_12_array_ptr = ((void *)(__4694_30_aaehip->array_ptr));
__4697_14_element_size = (__4694_30_aaehip->element_size);
if (__4694_30_aaehip->is_vec_new) {


__4696_14_number_of_elements = (__4694_30_aaehip->elements_processed);
__4701_21_first_element = (__4696_14_number_of_elements - 1ULL);
} else  {
__4701_21_first_element = ((((unsigned long long)(__4694_30_aaehip->number_of_elements)) - (__4694_30_aaehip->elements_processed)) - 1ULL);

__4696_14_number_of_elements = (__4701_21_first_element + 1ULL);
}
if (__4695_21_dtor != ((a_destructor_ptr)0)) {

for ((__4700_14_i = 0ULL) , (__4698_25_arr_ptr = ((void *)(((char *)__4699_12_array_ptr) + (__4701_21_first_element * __4697_14_element_size)))); __4700_14_i < __4696_14_number_of_elements; (__4700_14_i++) , (__4698_25_arr_ptr = ((void *)(((char *)__4698_25_arr_ptr) + (-((int)
#line 890
__4697_14_element_size))))))



{
#line 900
(*__4695_21_dtor)(__4698_25_arr_ptr);

}
}
if (__4694_30_aaehip->free_memory_on_cleanup) { auto void *__T869712248; auto size_t __T869712896; auto size_t __T869713632; auto a_delete_ptr __T869714368; auto a_boolean __T869715104;

auto size_t __4738_12_size; __4738_12_size = (__4697_14_element_size * ((unsigned long long)(__4694_30_aaehip->number_of_elements)));
(((((__T869712248 = __4699_12_array_ptr) , (__T869712896 = __4738_12_size)) , (__T869713632 = (__4694_30_aaehip->prefix_size))) , (__T869714368 = (__4694_30_aaehip->delete_routine))) , (__T869715104 = (__4694_30_aaehip->is_two_arg))) , (
#line 907
_ZN34_INTERNAL_12_vec_newdel_c_8a08d4a510free_arrayEPvyyPFvS0_Ei(__T869712248, __T869712896, __T869713632, __T869714368, __T869715104));

} 
}
#line 917
static void _ZN34_INTERNAL_12_vec_newdel_c_8a08d4a520array_delete_generalEPvxyyPFvS0_EiS2_ii( void *__4749_55_array_ptr, 
ptrdiff_t __4750_54_number_of_elements_param, 
size_t __4751_54_element_size, 
size_t __4752_54_prefix_size, 
a_destructor_ptr __4753_54_dtor, 
int __4754_16_delete_flag, 
a_delete_ptr __4755_52_delete_routine, 
int __4756_16_is_two_arg, 
int __4757_54_terminate_immediately)
#line 941
{
auto size_t __4774_25_i;
auto void *__4775_26_arr_ptr;
auto size_t __4776_11_array_size = 0ULL;
auto size_t __4777_11_number_of_elements; __4777_11_number_of_elements = ((size_t)__4750_54_number_of_elements_param);


if (__4749_55_array_ptr != ((void *)0)) { auto void *__T869744976; auto size_t __T869745624; auto size_t __T869746360; auto a_delete_ptr __T869747096; auto int __T869747832;

auto an_eh_stack_entry __4782_24_ehse;
auto struct an_array_alloc_eh_info __4783_28_aaehi;
_ZN34_INTERNAL_12_vec_newdel_c_8a08d4a536add_vec_new_or_delete_eh_stack_entryEP17an_eh_stack_entryP22an_array_alloc_eh_infoi((&__4782_24_ehse), (&__4783_28_aaehi), 0);

(__4783_28_aaehi.free_memory_on_cleanup) = __4754_16_delete_flag;
(__4783_28_aaehi.array_ptr) = __4749_55_array_ptr;
(__4783_28_aaehi.number_of_elements) = ((ptrdiff_t)__4777_11_number_of_elements);
(__4783_28_aaehi.element_size) = __4751_54_element_size;
(__4783_28_aaehi.prefix_size) = __4752_54_prefix_size;
(__4783_28_aaehi.destructor) = __4753_54_dtor;
(__4783_28_aaehi.delete_routine) = __4755_52_delete_routine;
(__4783_28_aaehi.is_two_arg) = __4756_16_is_two_arg;

(__4783_28_aaehi.terminate_immediately) = __4757_54_terminate_immediately;




if ((__4750_54_number_of_elements_param == (-1LL)) && (__4752_54_prefix_size != 0ULL)) { auto void *__T869743144; auto size_t __T869744064;

__4776_11_array_size = (((__T869743144 = __4749_55_array_ptr) , (__T869744064 = __4751_54_element_size)) , (_ZN34_INTERNAL_12_vec_newdel_c_8a08d4a514get_array_sizeEPvyPy(__T869743144, __T869744064, (&__4777_11_number_of_elements))));

}

(__4783_28_aaehi.number_of_elements) = ((ptrdiff_t)__4777_11_number_of_elements);




if (__4753_54_dtor != ((a_destructor_ptr)0)) {
for ((__4774_25_i = 0ULL) , (__4775_26_arr_ptr = ((void *)(((char *)__4749_55_array_ptr) + ((__4777_11_number_of_elements - 1ULL) * __4751_54_element_size)))); __4774_25_i < __4777_11_number_of_elements; (__4774_25_i++) , (__4775_26_arr_ptr = ((void *)(((char *)__4775_26_arr_ptr) + (-((int)
#line 980
__4751_54_element_size))))))



{
#line 990
(__4783_28_aaehi.elements_processed)++;
#line 997
(*__4753_54_dtor)(__4775_26_arr_ptr);

}
}




__curr_eh_stack_entry = (__curr_eh_stack_entry->next);


if (__4754_16_delete_flag) {
(((((__T869744976 = __4749_55_array_ptr) , (__T869745624 = __4776_11_array_size)) , (__T869746360 = __4752_54_prefix_size)) , (__T869747096 = __4755_52_delete_routine)) , (__T869747832 = __4756_16_is_two_arg)) , (_ZN34_INTERNAL_12_vec_newdel_c_8a08d4a510free_arrayEPvyyPFvS0_Ei(__T869744976, 
#line 1009
__T869745624, __T869746360, __T869747096, __T869747832));

}
} 
}
#line 1058
void __cxa_vec_dtor(
void *__4891_61_array_ptr, 
size_t __4892_60_number_of_elements, 
size_t __4893_60_element_size, 
a_destructor_ptr __4894_60_dtor)



{ auto void *__T869753872; auto ptrdiff_t __T869754520; auto size_t __T869755256; auto a_destructor_ptr __T869755992;
((((__T869753872 = __4891_61_array_ptr) , (__T869754520 = ((ptrdiff_t)__4892_60_number_of_elements))) , (__T869755256 = __4893_60_element_size)) , (__T869755992 = __4894_60_dtor)) , (_ZN34_INTERNAL_12_vec_newdel_c_8a08d4a520array_delete_generalEPvxyyPFvS0_EiS2_ii(__T869753872, __T869754520, 
#line 1067
__T869755256, 0ULL, __T869755992, 0, ((a_delete_ptr)0), 0, 0)); 



}


void __cxa_vec_delete( void *__4906_65_array_ptr, 
size_t __4907_64_element_size, 
size_t __4908_64_prefix_size, 
a_destructor_ptr __4909_64_dtor)



{ auto void *__T869762336; auto size_t __T869762984; auto size_t __T869763720; auto a_destructor_ptr __T869764456;
((((__T869762336 = __4906_65_array_ptr) , (__T869762984 = __4907_64_element_size)) , (__T869763720 = __4908_64_prefix_size)) , (__T869764456 = __4909_64_dtor)) , (_ZN34_INTERNAL_12_vec_newdel_c_8a08d4a520array_delete_generalEPvxyyPFvS0_EiS2_ii(__T869762336, (-1LL), __T869762984, __T869763720, 
#line 1082
__T869764456, 1, ((a_delete_ptr)0), 0, 0)); 



}


void __cxa_vec_delete2( void *__4921_66_array_ptr, 
size_t __4922_65_element_size, 
size_t __4923_65_prefix_size, 
a_destructor_ptr __4924_65_dtor, 
a_delete_ptr __4925_65_delete_routine)



{ auto void *__T869770552; auto size_t __T869771200; auto size_t __T869771936; auto a_destructor_ptr __T869772672; auto a_delete_ptr __T869773408;
(((((__T869770552 = __4921_66_array_ptr) , (__T869771200 = __4922_65_element_size)) , (__T869771936 = __4923_65_prefix_size)) , (__T869772672 = __4924_65_dtor)) , (__T869773408 = __4925_65_delete_routine)) , (_ZN34_INTERNAL_12_vec_newdel_c_8a08d4a520array_delete_generalEPvxyyPFvS0_EiS2_ii(
#line 1098
__T869770552, (-1LL), __T869771200, __T869771936, __T869772672, 1, __T869773408, 0, 0)); 



}


void __cxa_vec_delete3(
void *__4938_64_array_ptr, 
size_t __4939_63_element_size, 
size_t __4940_63_prefix_size, 
a_destructor_ptr __4941_63_dtor, 
a_two_operand_delete_ptr __4942_63_delete_routine)




{ auto void *__T869779592; auto size_t __T869780240; auto size_t __T869780976; auto a_destructor_ptr __T869781712; auto a_delete_ptr __T869782448;
(((((__T869779592 = __4938_64_array_ptr) , (__T869780240 = __4939_63_element_size)) , (__T869780976 = __4940_63_prefix_size)) , (__T869781712 = __4941_63_dtor)) , (__T869782448 = ((a_delete_ptr)__4942_63_delete_routine))) , (
#line 1116
_ZN34_INTERNAL_12_vec_newdel_c_8a08d4a520array_delete_generalEPvxyyPFvS0_EiS2_ii(__T869779592, (-1LL), __T869780240, __T869780976, __T869781712, 1, __T869782448, 1, 0)); 



}


void __cxa_vec_cleanup(
void *__4956_24_array_ptr, 
size_t __4957_23_number_of_elements, 
size_t __4958_23_element_size, 
a_destructor_ptr __4959_23_dtor)




{
if (__4959_23_dtor != ((a_destructor_ptr)0)) { auto void *__T869789648; auto ptrdiff_t __T869790568; auto size_t __T869791304; auto a_destructor_ptr __T869792040;
((((__T869789648 = __4956_24_array_ptr) , (__T869790568 = ((ptrdiff_t)__4957_23_number_of_elements))) , (__T869791304 = __4958_23_element_size)) , (__T869792040 = __4959_23_dtor)) , (_ZN34_INTERNAL_12_vec_newdel_c_8a08d4a520array_delete_generalEPvxyyPFvS0_EiS2_ii(__T869789648, __T869790568, 
#line 1134
__T869791304, 0ULL, __T869792040, 0, ((a_delete_ptr)0), 0, 1));



} 
}



void __cxa_throw_bad_array_new_length(void)
#line 1149
{

__throw_bad_array_new_length(); 

}
