/* Translated by the Edison Design Group C++/C front end (version 7.0) */
/* Wed Oct  7 03:19:07 2026 */
extern int __EDGCPFE__7_0;
void *memcpy(void *,const void *,unsigned long);
void *memset(void *,int,unsigned long);

# 1 "lib_src/vec_newdel.c"
# 6 "/usr/include/x86_64-linux-gnu/bits/types/__sigset_t.h" 3
struct __sigset_t;
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
# 62 "lib_src/vec_newdel.c"
struct an_array_alloc_eh_info;
# 66 "lib_src/basics.h"
typedef unsigned char a_byte;


typedef int a_boolean;
# 214 "/usr/lib/gcc/x86_64-linux-gnu/13/include/stddef.h" 3
typedef unsigned long size_t;
# 6 "/usr/include/x86_64-linux-gnu/bits/types/__sigset_t.h" 3
struct __sigset_t {
unsigned long __val[16];};
typedef struct __sigset_t __sigset_t;
# 145 "/usr/lib/gcc/x86_64-linux-gnu/13/include/stddef.h" 3
typedef long ptrdiff_t;
# 101 "lib_src/runtime.h"
typedef size_t a_sizeof_t;
# 127
typedef void (*a_destructor_ptr)(void *);
# 146
typedef void *(*a_new_ptr)(size_t);
# 155
typedef void (*a_delete_ptr)(void *);
# 164
typedef void (*a_two_operand_delete_ptr)(void *, a_sizeof_t);
# 184
typedef void a_ctor_return_type;
# 195
typedef a_ctor_return_type (*a_constructor_ptr)(void *);
# 203
typedef a_ctor_return_type (*a_copy_constructor_ptr)(void *, void *);
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
typedef struct an_eh_stack_entry an_eh_stack_entry;
# 62 "lib_src/vec_newdel.c"
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
# 177
typedef size_t an_alloc_prefix;

typedef an_alloc_prefix *an_alloc_prefix_ptr;
# 138 "include_c++/new.stdh" 3
extern void *_Znam(size_t);


extern __attribute__((__nothrow__)) void _ZdaPv(void *);
# 435 "lib_src/eh.h"
extern void __call_terminate(void);
# 466
extern void __throw_bad_array_new_length(void);
# 19 "lib_src/memzero.h"
extern void __memzero(void *buffer, size_t size);
# 112 "lib_src/vec_newdel.c"
static void _ZN34_INTERNAL_12_vec_newdel_c_8a08d4a536add_vec_new_or_delete_eh_stack_entryEP17an_eh_stack_entryP22an_array_alloc_eh_infoi(an_eh_stack_entry_ptr ehsep, an_array_alloc_eh_info_ptr aaehip, a_boolean is_vec_new);
# 189
static __inline__ void *_ZN34_INTERNAL_12_vec_newdel_c_8a08d4a511alloc_arrayEmmPFPvmE(size_t size, size_t prefix_size, a_new_ptr new_routine);
# 222
static void _ZN34_INTERNAL_12_vec_newdel_c_8a08d4a510free_arrayEPvmmPFvS0_Ei(void *array_ptr, size_t size, size_t prefix_size, a_delete_ptr delete_routine, int is_two_arg);
# 274
static __inline__ a_boolean _ZN34_INTERNAL_12_vec_newdel_c_8a08d4a523record_array_alloc_infoEPvmlm(void *array_ptr, size_t size, ptrdiff_t number_of_elements, size_t element_size);
# 334
static __inline__ size_t _ZN34_INTERNAL_12_vec_newdel_c_8a08d4a514get_array_sizeEPvmPm(void *array_ptr, size_t element_size, size_t *number_of_elements);
# 409
static void *_ZN34_INTERNAL_12_vec_newdel_c_8a08d4a517array_new_generalEPvlmmS0_PFvS0_ES2_PFS0_mES2_ii(void *array_ptr, ptrdiff_t number_of_elements, size_t element_size, size_t prefix_size, void *src_array_ptr, a_constructor_ptr ctor, a_destructor_ptr dtor, a_new_ptr new_routine, a_delete_ptr 
# 409
delete_routine, int is_two_arg, a_boolean zero_init);
# 756
extern void *__cxa_vec_new(size_t number_of_elements, size_t element_size, size_t prefix_size, a_constructor_ptr ctor, a_destructor_ptr dtor);
# 773
extern void *__cxa_vec_new2(size_t number_of_elements, size_t element_size, size_t prefix_size, a_constructor_ptr ctor, a_destructor_ptr dtor, a_new_ptr new_routine, a_delete_ptr delete_routine);
# 793
extern void *__cxa_vec_new3(size_t number_of_elements, size_t element_size, size_t prefix_size, a_constructor_ptr ctor, a_destructor_ptr dtor, a_new_ptr new_routine, a_two_operand_delete_ptr delete_routine);
# 814
extern void __cxa_vec_ctor(void *array_ptr, size_t number_of_elements, size_t element_size, a_constructor_ptr ctor, a_destructor_ptr dtor);
# 832
extern void __cxa_vec_cctor(void *array_ptr, void *src_array_ptr, size_t number_of_elements, size_t element_size, a_copy_constructor_ptr ctor, a_destructor_ptr dtor);
# 853
extern void __cleanup_vec_new_or_delete(an_eh_stack_entry_ptr ehsep);
# 917
static void _ZN34_INTERNAL_12_vec_newdel_c_8a08d4a520array_delete_generalEPvlmmPFvS0_EiS2_ii(void *array_ptr, ptrdiff_t number_of_elements_param, size_t element_size, size_t prefix_size, a_destructor_ptr dtor, int delete_flag, a_delete_ptr delete_routine, int is_two_arg, int terminate_immediately);
# 1058
extern void __cxa_vec_dtor(void *array_ptr, size_t number_of_elements, size_t element_size, a_destructor_ptr dtor);
# 1074
extern void __cxa_vec_delete(void *array_ptr, size_t element_size, size_t prefix_size, a_destructor_ptr dtor);
# 1089
extern void __cxa_vec_delete2(void *array_ptr, size_t element_size, size_t prefix_size, a_destructor_ptr dtor, a_delete_ptr delete_routine);
# 1105
extern void __cxa_vec_delete3(void *array_ptr, size_t element_size, size_t prefix_size, a_destructor_ptr dtor, a_two_operand_delete_ptr delete_routine);
# 1123
extern void __cxa_vec_cleanup(void *array_ptr, size_t number_of_elements, size_t element_size, a_destructor_ptr dtor);
# 1143
extern void __cxa_throw_bad_array_new_length(void);
# 424 "lib_src/eh.h"
extern an_eh_stack_entry_ptr __curr_eh_stack_entry;
# 112 "lib_src/vec_newdel.c"
static void _ZN34_INTERNAL_12_vec_newdel_c_8a08d4a536add_vec_new_or_delete_eh_stack_entryEP17an_eh_stack_entryP22an_array_alloc_eh_infoi(
an_eh_stack_entry_ptr __12095_32_ehsep, 
an_array_alloc_eh_info_ptr __12096_61_aaehip, 
a_boolean __12097_28_is_vec_new)




{
(__12095_32_ehsep->next) = __curr_eh_stack_entry;
__curr_eh_stack_entry = __12095_32_ehsep;
(__12095_32_ehsep->kind) = ehsek_vec_new_or_delete;
((__12095_32_ehsep->variant).array_alloc_eh_info) = __12096_61_aaehip;
(__12096_61_aaehip->array_ptr) = ((void *)0);
(__12096_61_aaehip->number_of_elements) = 0L;
(__12096_61_aaehip->element_size) = 0UL;
(__12096_61_aaehip->prefix_size) = 0UL;
(__12096_61_aaehip->elements_processed) = 0UL;
(__12096_61_aaehip->is_vec_new) = __12097_28_is_vec_new;
(__12096_61_aaehip->free_memory_on_cleanup) = 0;
(__12096_61_aaehip->destructor) = ((a_destructor_ptr)0);
(__12096_61_aaehip->delete_routine) = ((a_delete_ptr)0);
(__12096_61_aaehip->is_two_arg) = 0; 
}
# 189
static __inline__ void *_ZN34_INTERNAL_12_vec_newdel_c_8a08d4a511alloc_arrayEmmPFPvmE( size_t __12171_41_size, 
size_t __12172_49_prefix_size, 
a_new_ptr __12173_22_new_routine)
# 198
{
auto void *__12181_10_array_ptr;

__12171_41_size += __12172_49_prefix_size;



if (__12173_22_new_routine == ((a_new_ptr)0)) {

__12181_10_array_ptr = (_Znam(__12171_41_size));



} else  {
__12181_10_array_ptr = ((*__12173_22_new_routine)(__12171_41_size));
}
if (__12181_10_array_ptr != ((void *)0)) {

__12181_10_array_ptr = ((void *)(((char *)__12181_10_array_ptr) + __12172_49_prefix_size));
}
return __12181_10_array_ptr;
}


static void _ZN34_INTERNAL_12_vec_newdel_c_8a08d4a510free_arrayEPvmmPFvS0_Ei( void *__12204_31_array_ptr, 
size_t __12205_18_size, 
size_t __12206_41_prefix_size, 
a_delete_ptr __12207_23_delete_routine, 
int __12208_15_is_two_arg)
# 233
{

__12205_18_size += __12206_41_prefix_size;

__12204_31_array_ptr = ((void *)(((char *)__12204_31_array_ptr) - __12206_41_prefix_size));



if (__12207_23_delete_routine == ((a_delete_ptr)0)) {

_ZdaPv(__12204_31_array_ptr);



} else  {
if (__12208_15_is_two_arg) { auto void *__T255217288; auto size_t __T255217936;
auto a_two_operand_delete_ptr __12231_32_two_op_delete_routine;
__12231_32_two_op_delete_routine = ((a_two_operand_delete_ptr)__12207_23_delete_routine);
((__T255217288 = __12204_31_array_ptr) , (__T255217936 = __12205_18_size)) , ((*__12231_32_two_op_delete_routine)(__T255217288, __T255217936));
} else  {
(*__12207_23_delete_routine)(__12204_31_array_ptr);
}
} 
}
# 274
static __inline__ a_boolean _ZN34_INTERNAL_12_vec_newdel_c_8a08d4a523record_array_alloc_infoEPvmlm( void *__12256_57_array_ptr, 
size_t __12257_26_size, 
ptrdiff_t __12258_24_number_of_elements, 
size_t __12259_16_element_size)
# 283
{

auto an_alloc_prefix_ptr __12267_23_app;
# 295
__12267_23_app = (((an_alloc_prefix_ptr)__12256_57_array_ptr) - 1);

(*__12267_23_app) = ((an_alloc_prefix)__12258_24_number_of_elements);
# 303
return 0;
# 327
}
# 334
static __inline__ size_t _ZN34_INTERNAL_12_vec_newdel_c_8a08d4a514get_array_sizeEPvmPm( void *__12316_43_array_ptr, 
size_t __12317_17_element_size, 
size_t *__12318_17_number_of_elements)
# 344
{

auto an_alloc_prefix_ptr __12328_23_app;
auto size_t __12329_11_size;
# 365
__12328_23_app = (((an_alloc_prefix_ptr)__12316_43_array_ptr) - 1);



(*__12318_17_number_of_elements) = (*__12328_23_app);

__12329_11_size = ((*__12318_17_number_of_elements) * __12317_17_element_size);

return __12329_11_size;
# 403
}
# 409
static void *_ZN34_INTERNAL_12_vec_newdel_c_8a08d4a517array_new_generalEPvlmmS0_PFvS0_ES2_PFS0_mES2_ii( void *__12391_55_array_ptr, 
ptrdiff_t __12392_47_number_of_elements, 
size_t __12393_54_element_size, 
size_t __12394_54_prefix_size, 
void *__12395_55_src_array_ptr, 
a_constructor_ptr __12396_54_ctor, 
a_destructor_ptr __12397_54_dtor, 
a_new_ptr __12398_33_new_routine, 
a_delete_ptr __12399_54_delete_routine, 
int __12400_21_is_two_arg, 
a_boolean __12401_54_zero_init)
# 461
{ auto void *__T255345240; auto size_t __T255345888;
auto size_t __12444_13_array_size;
auto ptrdiff_t __12445_13_i;
auto void *__12446_14_arr_ptr;


auto an_eh_stack_entry __12449_22_ehse;
auto struct an_array_alloc_eh_info __12450_26_aaehi;
auto a_boolean __12451_15_create_eh_stack_entry;
auto a_boolean __12452_15_free_memory_on_cleanup; __12452_15_free_memory_on_cleanup = ((a_boolean)(__12391_55_array_ptr == ((void *)0)));




__12451_15_create_eh_stack_entry = ((a_boolean)((__12397_54_dtor != ((a_destructor_ptr)0)) || (__12391_55_array_ptr == ((void *)0))));

if ((__12391_55_array_ptr == ((void *)0)) || (__12394_54_prefix_size != 0UL)) { auto void *__T255342208; auto size_t __T255342856; auto ptrdiff_t __T255343592; auto size_t __T255344328;
auto a_boolean __12460_15_err;
# 486
if ((__12393_54_element_size != 0UL) && (((unsigned long)__12392_47_number_of_elements) > ((18446744073709551615UL - __12394_54_prefix_size) / __12393_54_element_size)))
{
__cxa_throw_bad_array_new_length();
}


__12444_13_array_size = (((unsigned long)__12392_47_number_of_elements) * __12393_54_element_size);



if (__12444_13_array_size == 0UL) { __12444_13_array_size = 1UL; }
if (__12391_55_array_ptr == ((void *)0)) { auto size_t __T255339640; auto size_t __T255340560; auto a_new_ptr __T255341296;


__12391_55_array_ptr = ((((__T255339640 = __12444_13_array_size) , (__T255340560 = __12394_54_prefix_size)) , (__T255341296 = __12398_33_new_routine)) , (_ZN34_INTERNAL_12_vec_newdel_c_8a08d4a511alloc_arrayEmmPFPvmE(__T255339640, __T255340560, __T255341296)));
if (__12391_55_array_ptr == ((void *)0)) {
goto __12565_1_error_exit;
}
}


if (__12394_54_prefix_size != 0UL) {
__12460_15_err = (((((__T255342208 = __12391_55_array_ptr) , (__T255342856 = __12444_13_array_size)) , (__T255343592 = __12392_47_number_of_elements)) , (__T255344328 = __12393_54_element_size)) , (_ZN34_INTERNAL_12_vec_newdel_c_8a08d4a523record_array_alloc_infoEPvmlm(__T255342208, __T255342856, 
# 508
__T255343592, __T255344328)));

if (__12460_15_err) { goto __12565_1_error_exit; }
}

} else  { if (__12401_54_zero_init) {
__12444_13_array_size = (((unsigned long)__12392_47_number_of_elements) * __12393_54_element_size);

} }

if (__12401_54_zero_init) {
((__T255345240 = __12391_55_array_ptr) , (__T255345888 = __12444_13_array_size)) , (__memzero(__T255345240, __T255345888));
}


if (__12451_15_create_eh_stack_entry) {
_ZN34_INTERNAL_12_vec_newdel_c_8a08d4a536add_vec_new_or_delete_eh_stack_entryEP17an_eh_stack_entryP22an_array_alloc_eh_infoi((&__12449_22_ehse), (&__12450_26_aaehi), 1);
(__12450_26_aaehi.free_memory_on_cleanup) = __12452_15_free_memory_on_cleanup;
(__12450_26_aaehi.number_of_elements) = __12392_47_number_of_elements;
(__12450_26_aaehi.element_size) = __12393_54_element_size;
(__12450_26_aaehi.prefix_size) = __12394_54_prefix_size;
(__12450_26_aaehi.destructor) = __12397_54_dtor;
(__12450_26_aaehi.delete_routine) = __12399_54_delete_routine;
(__12450_26_aaehi.is_two_arg) = __12400_21_is_two_arg;
(__12450_26_aaehi.array_ptr) = __12391_55_array_ptr;

(__12450_26_aaehi.terminate_immediately) = 0;

}
# 545
if (__12396_54_ctor != ((a_constructor_ptr)0)) {
for ((__12445_13_i = 0L) , (__12446_14_arr_ptr = __12391_55_array_ptr); __12445_13_i < __12392_47_number_of_elements; (__12445_13_i++) , (__12446_14_arr_ptr = ((void *)(((char *)__12446_14_arr_ptr) + __12393_54_element_size))))

{
if (__12395_55_src_array_ptr == ((void *)0)) {
# 557
(*__12396_54_ctor)(__12446_14_arr_ptr);

} else  { auto void *__T255346800; auto void *__T255347448;

auto a_copy_constructor_ptr __12543_32_cctor;
__12543_32_cctor = ((a_copy_constructor_ptr)__12396_54_ctor);
((__T255346800 = __12446_14_arr_ptr) , (__T255347448 = __12395_55_src_array_ptr)) , ((*__12543_32_cctor)(__T255346800, __T255347448));
}

if (__12397_54_dtor != ((a_destructor_ptr)0)) {


(__12450_26_aaehi.elements_processed)++;
}



if (__12395_55_src_array_ptr != ((void *)0)) { __12395_55_src_array_ptr = ((void *)(((char *)__12395_55_src_array_ptr) + __12393_54_element_size)); }
}
}

if (__12451_15_create_eh_stack_entry) {

__curr_eh_stack_entry = (__curr_eh_stack_entry->next);
}

__12565_1_error_exit:;

return __12391_55_array_ptr;
}
# 756
void *__cxa_vec_new(
size_t __12739_60_number_of_elements, 
size_t __12740_60_element_size, 
size_t __12741_60_prefix_size, 
a_constructor_ptr __12742_60_ctor, 
a_destructor_ptr __12743_60_dtor)



{ auto ptrdiff_t __T255354936; auto size_t __T255355584; auto size_t __T255356320; auto a_constructor_ptr __T255357056; auto a_destructor_ptr __T255357792;
return (((((__T255354936 = ((ptrdiff_t)__12739_60_number_of_elements)) , (__T255355584 = __12740_60_element_size)) , (__T255356320 = __12741_60_prefix_size)) , (__T255357056 = __12742_60_ctor)) , (__T255357792 = __12743_60_dtor)) , (
# 766
_ZN34_INTERNAL_12_vec_newdel_c_8a08d4a517array_new_generalEPvlmmS0_PFvS0_ES2_PFS0_mES2_ii(((void *)0), __T255354936, __T255355584, __T255356320, ((void *)0), __T255357056, __T255357792, ((a_new_ptr)0), ((a_delete_ptr)0), 0, 0));



}


void *__cxa_vec_new2(
size_t __12756_60_number_of_elements, 
size_t __12757_60_element_size, 
size_t __12758_60_prefix_size, 
a_constructor_ptr __12759_60_ctor, 
a_destructor_ptr __12760_60_dtor, 
a_new_ptr __12761_60_new_routine, 
a_delete_ptr __12762_60_delete_routine)




{ auto ptrdiff_t __T255364784; auto size_t __T255365432; auto size_t __T255366168; auto a_constructor_ptr __T255366904; auto a_destructor_ptr __T255367640; auto a_new_ptr __T255368376; auto a_delete_ptr __T255369112;
return (((((((__T255364784 = ((ptrdiff_t)__12756_60_number_of_elements)) , (__T255365432 = __12757_60_element_size)) , (__T255366168 = __12758_60_prefix_size)) , (__T255366904 = __12759_60_ctor)) , (__T255367640 = __12760_60_dtor)) , (__T255368376 = __12761_60_new_routine)) , (__T255369112 = 
# 786
__12762_60_delete_routine)) , (_ZN34_INTERNAL_12_vec_newdel_c_8a08d4a517array_new_generalEPvlmmS0_PFvS0_ES2_PFS0_mES2_ii(((void *)0), __T255364784, __T255365432, __T255366168, ((void *)0), __T255366904, __T255367640, __T255368376, __T255369112, 0, 0));



}


void *__cxa_vec_new3(
size_t __12776_60_number_of_elements, 
size_t __12777_60_element_size, 
size_t __12778_60_prefix_size, 
a_constructor_ptr __12779_60_ctor, 
a_destructor_ptr __12780_60_dtor, 
a_new_ptr __12781_60_new_routine, 
a_two_operand_delete_ptr __12782_60_delete_routine)




{ auto ptrdiff_t __T255376192; auto size_t __T255376840; auto size_t __T255377576; auto a_constructor_ptr __T255378312; auto a_destructor_ptr __T255379048; auto a_new_ptr __T255379784; auto a_delete_ptr __T255380520;
return (((((((__T255376192 = ((ptrdiff_t)__12776_60_number_of_elements)) , (__T255376840 = __12777_60_element_size)) , (__T255377576 = __12778_60_prefix_size)) , (__T255378312 = __12779_60_ctor)) , (__T255379048 = __12780_60_dtor)) , (__T255379784 = __12781_60_new_routine)) , (__T255380520 = ((
# 806
a_delete_ptr)__12782_60_delete_routine))) , (_ZN34_INTERNAL_12_vec_newdel_c_8a08d4a517array_new_generalEPvlmmS0_PFvS0_ES2_PFS0_mES2_ii(((void *)0), __T255376192, __T255376840, __T255377576, ((void *)0), __T255378312, __T255379048, __T255379784, __T255380520, 1, 0));




}


void __cxa_vec_ctor(
void *__12797_61_array_ptr, 
size_t __12798_60_number_of_elements, 
size_t __12799_60_element_size, 
a_constructor_ptr __12800_60_ctor, 
a_destructor_ptr __12801_60_dtor)




{ auto void *__T255388312; auto ptrdiff_t __T255388960; auto size_t __T255389696; auto a_constructor_ptr __T255390432; auto a_destructor_ptr __T255391168;
(((((__T255388312 = __12797_61_array_ptr) , (__T255388960 = ((ptrdiff_t)__12798_60_number_of_elements))) , (__T255389696 = __12799_60_element_size)) , (__T255390432 = __12800_60_ctor)) , (__T255391168 = __12801_60_dtor)) , (
# 825
_ZN34_INTERNAL_12_vec_newdel_c_8a08d4a517array_new_generalEPvlmmS0_PFvS0_ES2_PFS0_mES2_ii(__T255388312, __T255388960, __T255389696, 0UL, ((void *)0), __T255390432, __T255391168, ((a_new_ptr)0), ((a_delete_ptr)0), 0, 0)); 



}


void __cxa_vec_cctor(
void *__12815_61_array_ptr, 
void *__12816_61_src_array_ptr, 
size_t __12817_60_number_of_elements, 
size_t __12818_60_element_size, 
a_copy_constructor_ptr __12819_60_ctor, 
a_destructor_ptr __12820_60_dtor)



{ auto void *__T255398672; auto ptrdiff_t __T255399320; auto size_t __T255400056; auto void *__T255400792; auto a_constructor_ptr __T255401528; auto a_destructor_ptr __T255402264;
((((((__T255398672 = __12815_61_array_ptr) , (__T255399320 = ((ptrdiff_t)__12817_60_number_of_elements))) , (__T255400056 = __12818_60_element_size)) , (__T255400792 = __12816_61_src_array_ptr)) , (__T255401528 = ((a_constructor_ptr)__12819_60_ctor))) , (__T255402264 = __12820_60_dtor)) , (
# 843
_ZN34_INTERNAL_12_vec_newdel_c_8a08d4a517array_new_generalEPvlmmS0_PFvS0_ES2_PFS0_mES2_ii(__T255398672, __T255399320, __T255400056, 0UL, __T255400792, __T255401528, __T255402264, ((a_new_ptr)0), ((a_delete_ptr)0), 0, 0)); 




}




void __cleanup_vec_new_or_delete( an_eh_stack_entry_ptr __12835_65_ehsep)
# 859
{


auto an_array_alloc_eh_info_ptr __12844_30_aaehip;
auto a_destructor_ptr __12845_21_dtor;
auto size_t __12846_14_number_of_elements;
auto size_t __12847_14_element_size;
auto void *__12848_25_arr_ptr;
auto void *__12849_12_array_ptr;
auto size_t __12850_14_i;
auto size_t __12851_21_first_element;
# 862
__12844_30_aaehip = ((__12835_65_ehsep->variant).array_alloc_eh_info);
__12845_21_dtor = (__12844_30_aaehip->destructor);
# 872
if (__12844_30_aaehip->terminate_immediately) {
__call_terminate();
}

__12849_12_array_ptr = ((void *)(__12844_30_aaehip->array_ptr));
__12847_14_element_size = (__12844_30_aaehip->element_size);
if (__12844_30_aaehip->is_vec_new) {


__12846_14_number_of_elements = (__12844_30_aaehip->elements_processed);
__12851_21_first_element = (__12846_14_number_of_elements - 1UL);
} else  {
__12851_21_first_element = ((((unsigned long)(__12844_30_aaehip->number_of_elements)) - (__12844_30_aaehip->elements_processed)) - 1UL);

__12846_14_number_of_elements = (__12851_21_first_element + 1UL);
}
if (__12845_21_dtor != ((a_destructor_ptr)0)) {

for ((__12850_14_i = 0UL) , (__12848_25_arr_ptr = ((void *)(((char *)__12849_12_array_ptr) + (__12851_21_first_element * __12847_14_element_size)))); __12850_14_i < __12846_14_number_of_elements; (__12850_14_i++) , (__12848_25_arr_ptr = ((void *)(((char *)__12848_25_arr_ptr) + (-((int)
# 890
__12847_14_element_size))))))



{
# 900
(*__12845_21_dtor)(__12848_25_arr_ptr);

}
}
if (__12844_30_aaehip->free_memory_on_cleanup) { auto void *__T255424824; auto size_t __T255425472; auto size_t __T255426208; auto a_delete_ptr __T255426944; auto a_boolean __T255427680;

auto size_t __12888_12_size; __12888_12_size = (__12847_14_element_size * ((unsigned long)(__12844_30_aaehip->number_of_elements)));
(((((__T255424824 = __12849_12_array_ptr) , (__T255425472 = __12888_12_size)) , (__T255426208 = (__12844_30_aaehip->prefix_size))) , (__T255426944 = (__12844_30_aaehip->delete_routine))) , (__T255427680 = (__12844_30_aaehip->is_two_arg))) , (
# 907
_ZN34_INTERNAL_12_vec_newdel_c_8a08d4a510free_arrayEPvmmPFvS0_Ei(__T255424824, __T255425472, __T255426208, __T255426944, __T255427680));

} 
}
# 917
static void _ZN34_INTERNAL_12_vec_newdel_c_8a08d4a520array_delete_generalEPvlmmPFvS0_EiS2_ii( void *__12899_55_array_ptr, 
ptrdiff_t __12900_54_number_of_elements_param, 
size_t __12901_54_element_size, 
size_t __12902_54_prefix_size, 
a_destructor_ptr __12903_54_dtor, 
int __12904_16_delete_flag, 
a_delete_ptr __12905_52_delete_routine, 
int __12906_16_is_two_arg, 
int __12907_54_terminate_immediately)
# 941
{
auto size_t __12924_25_i;
auto void *__12925_26_arr_ptr;
auto size_t __12926_11_array_size = 0UL;
auto size_t __12927_11_number_of_elements; __12927_11_number_of_elements = ((size_t)__12900_54_number_of_elements_param);


if (__12899_55_array_ptr != ((void *)0)) { auto void *__T255457552; auto size_t __T255458200; auto size_t __T255458936; auto a_delete_ptr __T255459672; auto int __T255460408;

auto an_eh_stack_entry __12932_24_ehse;
auto struct an_array_alloc_eh_info __12933_28_aaehi;
_ZN34_INTERNAL_12_vec_newdel_c_8a08d4a536add_vec_new_or_delete_eh_stack_entryEP17an_eh_stack_entryP22an_array_alloc_eh_infoi((&__12932_24_ehse), (&__12933_28_aaehi), 0);

(__12933_28_aaehi.free_memory_on_cleanup) = __12904_16_delete_flag;
(__12933_28_aaehi.array_ptr) = __12899_55_array_ptr;
(__12933_28_aaehi.number_of_elements) = ((ptrdiff_t)__12927_11_number_of_elements);
(__12933_28_aaehi.element_size) = __12901_54_element_size;
(__12933_28_aaehi.prefix_size) = __12902_54_prefix_size;
(__12933_28_aaehi.destructor) = __12903_54_dtor;
(__12933_28_aaehi.delete_routine) = __12905_52_delete_routine;
(__12933_28_aaehi.is_two_arg) = __12906_16_is_two_arg;

(__12933_28_aaehi.terminate_immediately) = __12907_54_terminate_immediately;




if ((__12900_54_number_of_elements_param == (-1L)) && (__12902_54_prefix_size != 0UL)) { auto void *__T255455720; auto size_t __T255456640;

__12926_11_array_size = (((__T255455720 = __12899_55_array_ptr) , (__T255456640 = __12901_54_element_size)) , (_ZN34_INTERNAL_12_vec_newdel_c_8a08d4a514get_array_sizeEPvmPm(__T255455720, __T255456640, (&__12927_11_number_of_elements))));

}

(__12933_28_aaehi.number_of_elements) = ((ptrdiff_t)__12927_11_number_of_elements);




if (__12903_54_dtor != ((a_destructor_ptr)0)) {
for ((__12924_25_i = 0UL) , (__12925_26_arr_ptr = ((void *)(((char *)__12899_55_array_ptr) + ((__12927_11_number_of_elements - 1UL) * __12901_54_element_size)))); __12924_25_i < __12927_11_number_of_elements; (__12924_25_i++) , (__12925_26_arr_ptr = ((void *)(((char *)__12925_26_arr_ptr) + (-((int)
# 980
__12901_54_element_size))))))



{
# 990
(__12933_28_aaehi.elements_processed)++;
# 997
(*__12903_54_dtor)(__12925_26_arr_ptr);

}
}




__curr_eh_stack_entry = (__curr_eh_stack_entry->next);


if (__12904_16_delete_flag) {
(((((__T255457552 = __12899_55_array_ptr) , (__T255458200 = __12926_11_array_size)) , (__T255458936 = __12902_54_prefix_size)) , (__T255459672 = __12905_52_delete_routine)) , (__T255460408 = __12906_16_is_two_arg)) , (_ZN34_INTERNAL_12_vec_newdel_c_8a08d4a510free_arrayEPvmmPFvS0_Ei(__T255457552, 
# 1009
__T255458200, __T255458936, __T255459672, __T255460408));

}
} 
}
# 1058
void __cxa_vec_dtor(
void *__13041_61_array_ptr, 
size_t __13042_60_number_of_elements, 
size_t __13043_60_element_size, 
a_destructor_ptr __13044_60_dtor)



{ auto void *__T255466448; auto ptrdiff_t __T255467096; auto size_t __T255467832; auto a_destructor_ptr __T255468568;
((((__T255466448 = __13041_61_array_ptr) , (__T255467096 = ((ptrdiff_t)__13042_60_number_of_elements))) , (__T255467832 = __13043_60_element_size)) , (__T255468568 = __13044_60_dtor)) , (_ZN34_INTERNAL_12_vec_newdel_c_8a08d4a520array_delete_generalEPvlmmPFvS0_EiS2_ii(__T255466448, __T255467096, 
# 1067
__T255467832, 0UL, __T255468568, 0, ((a_delete_ptr)0), 0, 0)); 



}


void __cxa_vec_delete( void *__13056_65_array_ptr, 
size_t __13057_64_element_size, 
size_t __13058_64_prefix_size, 
a_destructor_ptr __13059_64_dtor)



{ auto void *__T255474912; auto size_t __T255475560; auto size_t __T255476296; auto a_destructor_ptr __T255477032;
((((__T255474912 = __13056_65_array_ptr) , (__T255475560 = __13057_64_element_size)) , (__T255476296 = __13058_64_prefix_size)) , (__T255477032 = __13059_64_dtor)) , (_ZN34_INTERNAL_12_vec_newdel_c_8a08d4a520array_delete_generalEPvlmmPFvS0_EiS2_ii(__T255474912, (-1L), __T255475560, __T255476296, 
# 1082
__T255477032, 1, ((a_delete_ptr)0), 0, 0)); 



}


void __cxa_vec_delete2( void *__13071_66_array_ptr, 
size_t __13072_65_element_size, 
size_t __13073_65_prefix_size, 
a_destructor_ptr __13074_65_dtor, 
a_delete_ptr __13075_65_delete_routine)



{ auto void *__T255483128; auto size_t __T255483776; auto size_t __T255484512; auto a_destructor_ptr __T255485248; auto a_delete_ptr __T255485984;
(((((__T255483128 = __13071_66_array_ptr) , (__T255483776 = __13072_65_element_size)) , (__T255484512 = __13073_65_prefix_size)) , (__T255485248 = __13074_65_dtor)) , (__T255485984 = __13075_65_delete_routine)) , (_ZN34_INTERNAL_12_vec_newdel_c_8a08d4a520array_delete_generalEPvlmmPFvS0_EiS2_ii(
# 1098
__T255483128, (-1L), __T255483776, __T255484512, __T255485248, 1, __T255485984, 0, 0)); 



}


void __cxa_vec_delete3(
void *__13088_64_array_ptr, 
size_t __13089_63_element_size, 
size_t __13090_63_prefix_size, 
a_destructor_ptr __13091_63_dtor, 
a_two_operand_delete_ptr __13092_63_delete_routine)




{ auto void *__T255492168; auto size_t __T255492816; auto size_t __T255493552; auto a_destructor_ptr __T255494288; auto a_delete_ptr __T255495024;
(((((__T255492168 = __13088_64_array_ptr) , (__T255492816 = __13089_63_element_size)) , (__T255493552 = __13090_63_prefix_size)) , (__T255494288 = __13091_63_dtor)) , (__T255495024 = ((a_delete_ptr)__13092_63_delete_routine))) , (
# 1116
_ZN34_INTERNAL_12_vec_newdel_c_8a08d4a520array_delete_generalEPvlmmPFvS0_EiS2_ii(__T255492168, (-1L), __T255492816, __T255493552, __T255494288, 1, __T255495024, 1, 0)); 



}


void __cxa_vec_cleanup(
void *__13106_24_array_ptr, 
size_t __13107_23_number_of_elements, 
size_t __13108_23_element_size, 
a_destructor_ptr __13109_23_dtor)




{
if (__13109_23_dtor != ((a_destructor_ptr)0)) { auto void *__T255522392; auto ptrdiff_t __T255523312; auto size_t __T255524048; auto a_destructor_ptr __T255524784;
((((__T255522392 = __13106_24_array_ptr) , (__T255523312 = ((ptrdiff_t)__13107_23_number_of_elements))) , (__T255524048 = __13108_23_element_size)) , (__T255524784 = __13109_23_dtor)) , (_ZN34_INTERNAL_12_vec_newdel_c_8a08d4a520array_delete_generalEPvlmmPFvS0_EiS2_ii(__T255522392, __T255523312, 
# 1134
__T255524048, 0UL, __T255524784, 0, ((a_delete_ptr)0), 0, 1));



} 
}



void __cxa_throw_bad_array_new_length(void)
# 1149
{

__throw_bad_array_new_length(); 

}
