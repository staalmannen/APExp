/* Translated by the Edison Design Group C++/C front end (version 7.0) */
/* Wed Oct  7 03:19:07 2026 */
extern int __EDGCPFE__7_0;
void *memcpy(void *,const void *,unsigned long);
void *memset(void *,int,unsigned long);

# 1 "lib_src/throw.c"
struct __C1; struct __EDG_type_info; struct __class_type_info; struct __si_class_type_info; struct __fundamental_type_info;
# 6 "/usr/include/x86_64-linux-gnu/bits/types/__sigset_t.h" 3
struct __sigset_t;
# 49 "/usr/include/x86_64-linux-gnu/bits/types/struct_FILE.h" 3
struct _IO_FILE;
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
# 25 "lib_src/throw.c"
struct a_dummy_class;




struct a_throw_stack_entry;
# 157
struct a_mem_block_descr;
# 177
struct a_mem_allocation;
# 251
union _ZN28_INTERNAL_7_throw_c_721f9a2eUt_E;
# 32 "include_c++/typeinfo.stdh" 3
struct _ZSt9type_info; struct __C1 { void (*f)(); long d;}; struct __EDG_type_info { const long *__vptr; const char *__name;}; struct __class_type_info { struct __EDG_type_info base;}; struct __si_class_type_info { struct __class_type_info base; const struct __class_type_info *base_type;}; struct 
# 32
__fundamental_type_info { struct __EDG_type_info base;};
# 66 "lib_src/basics.h"
typedef unsigned char a_byte;


typedef int a_boolean;
typedef a_byte a_byte_boolean;
# 214 "/usr/lib/gcc/x86_64-linux-gnu/13/include/stddef.h" 3
typedef unsigned long size_t;
# 6 "/usr/include/x86_64-linux-gnu/bits/types/__sigset_t.h" 3
struct __sigset_t {
unsigned long __val[16];};
typedef struct __sigset_t __sigset_t;
# 7 "/usr/include/x86_64-linux-gnu/bits/types/FILE.h" 3
typedef struct _IO_FILE FILE;
# 101 "lib_src/runtime.h"
typedef size_t a_sizeof_t;
# 115
typedef void (*a_void_function_ptr)(void);
# 127
typedef void (*a_destructor_ptr)(void *);
# 136
typedef void (*a_destructor_with_vtable_param_ptr)(void *, void *);
# 155
typedef void (*a_delete_ptr)(void *);
# 164
typedef void (*a_two_operand_delete_ptr)(void *, a_sizeof_t);
# 228
typedef unsigned long long an_ia64_guard;


typedef an_ia64_guard *an_ia64_guard_ptr;
# 93 "lib_src/rtti.h"
typedef const struct _ZSt9type_info *a_type_info_impl_ptr;
# 178
typedef char *an_access_flag_string;
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
# 31 "lib_src/eh.h"
typedef long an_element_count;
# 37
typedef int a_conditional_flag;



typedef unsigned short an_object_handle;


typedef void *an_object_ptr;


typedef unsigned short a_region_number;


typedef unsigned an_ETS_flag_set;




typedef a_byte a_region_descr_flag_set;
# 163
typedef struct an_eh_array_supplement *an_eh_array_supplement_ptr;
struct an_eh_array_supplement {

an_object_handle handle;


a_sizeof_t element_size;

an_element_count array_size;};
# 177
typedef struct an_eh_array_supplement an_eh_array_supplement;



typedef struct an_eh_region_descr *an_eh_region_descr_ptr;
struct an_eh_region_descr {

a_void_function_ptr destructor_or_delete_routine;
# 190
an_object_handle handle;
# 200
a_region_number index_of_next_region;
# 206
a_region_descr_flag_set flags;char __dummy[3];};



typedef struct an_eh_region_descr an_eh_region_descr;
# 309
typedef struct an_exception_type_specification *an_exception_type_specification_ptr;
struct an_exception_type_specification {

a_type_info_impl_ptr type_info;
# 318
an_ETS_flag_set flags;
# 324
an_ETS_flag_set *ptr_flags;};
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
# 29 "lib_src/throw.c"
typedef struct a_throw_stack_entry *a_throw_stack_entry_ptr;
struct a_throw_stack_entry {

a_throw_stack_entry_ptr next;


a_type_info_impl_ptr type_info;


a_destructor_ptr destructor;


an_ETS_flag_set flags;



an_ETS_flag_set *ptr_flags;
# 52
an_access_flag_string access_flags;




void *object_address;


void *pointer_buffer;
# 71
long ptr_to_data_member_buffer;
# 78
struct __C1 ptr_to_member_function_buffer;
# 85
an_eh_stack_entry_ptr nearest_enclosing_try_block;
# 91
a_throw_stack_entry_ptr primary_entry;


unsigned long use_count;




a_byte_boolean is_rethrow;




a_byte_boolean is_internal;



a_byte_boolean discard_entry;
# 115
a_byte_boolean dtor_called;




a_byte_boolean in_handler;




a_byte_boolean object_evaluation_complete;
# 132
a_byte_boolean object_copy_complete;
# 138
a_byte_boolean use_access_flags;
# 147
an_eh_stack_entry throw_marker;};
# 156
typedef struct a_mem_block_descr *a_mem_block_descr_ptr;
struct a_mem_block_descr {

a_mem_block_descr_ptr next;

void *addr;

a_sizeof_t size;

a_sizeof_t used;


a_byte_boolean dynamically_allocated;char __dummy[7];};



typedef struct a_mem_block_descr a_mem_block_descr;



typedef struct a_mem_allocation *a_mem_allocation_ptr;
struct a_mem_allocation {

a_mem_allocation_ptr next;

a_sizeof_t alloc_size;



void *addr;


a_byte_boolean is_mem_block_descr_allocation;char __dummy[7];};
# 195
typedef void (*a_destroy_exception_object_ptr)(void);
# 251
union _ZN28_INTERNAL_7_throw_c_721f9a2eUt_E {
char memory[8192];




double dummy;};
# 35 "include_c++/exception.stdh" 3
typedef _Bool _ZSt6__bool;
# 32 "include_c++/typeinfo.stdh" 3
struct _ZSt9type_info { const long *__vptr;
# 50
const char *__type_name;};
# 128 "include_c++/cxxabi.h" 3
typedef void _ZN10__cxxabiv123__ctor_dtor_return_typeE;
# 136
typedef unsigned long long _ZN10__cxxabiv121__guard_variable_typeE;
# 672 "/usr/include/stdlib.h" 3
extern __attribute__((__alloc_size__(1))) __attribute__((__malloc__)) __attribute__((__nothrow__)) void *malloc(size_t __size);
# 687
extern __attribute__((__nothrow__)) void free(void *__ptr);
# 730
extern __attribute__((__nothrow__)) __attribute__((__noreturn__)) void abort(void);
# 357 "/usr/include/stdio.h" 3
extern int fprintf(FILE *__stream, const char *__format, ...);
# 143 "include_c++/cxxabi.h" 3
extern void __cxa_guard_abort(_ZN10__cxxabiv121__guard_variable_typeE *);
# 162
extern void __cxa_vec_dtor(void *, size_t, size_t, _ZN10__cxxabiv123__ctor_dtor_return_typeE (*)(void *));
# 188
extern void __cxa_bad_typeid(void);
# 196 "lib_src/rtti.h"
extern a_boolean __derived_to_base_conversion(void **p_ptr, void **p_new_ptr, a_type_info_impl_ptr class_info, a_type_info_impl_ptr base_info, an_access_flag_string *access_flags, a_boolean use_access_flags);
# 54 "/usr/include/setjmp.h" 3
extern __attribute__((__nothrow__)) __attribute__((__noreturn__)) void longjmp(struct __jmp_buf_tag *__env, int __val);
# 435 "lib_src/eh.h"
extern void __call_terminate(void);
# 443
extern void __call_unexpected(void);
# 450
extern void __cleanup_vec_new_or_delete(an_eh_stack_entry_ptr ehsep);
# 295 "lib_src/throw.c"
static void *_ZN28_INTERNAL_7_throw_c_721f9a2e13eh_get_memoryEm(a_sizeof_t size);
# 313
static void _ZN28_INTERNAL_7_throw_c_721f9a2e14eh_free_memoryEPv(void *ptr);
# 324
static void _ZN28_INTERNAL_7_throw_c_721f9a2e20mem_block_descr_initEP17a_mem_block_descr(a_mem_block_descr_ptr mbdp);
# 337
static void _ZN28_INTERNAL_7_throw_c_721f9a2e25init_eh_memory_managementEv(void);
# 360
static void *_ZN28_INTERNAL_7_throw_c_721f9a2e18alloc_in_mem_blockEmPP16a_mem_allocation(a_sizeof_t size, a_mem_allocation_ptr *map);
# 392
static void _ZN28_INTERNAL_7_throw_c_721f9a2e19alloc_new_mem_blockEm(a_sizeof_t size);
# 432
static void *_ZN28_INTERNAL_7_throw_c_721f9a2e17eh_alloc_on_stackEm(a_sizeof_t size);
# 471
static void _ZN28_INTERNAL_7_throw_c_721f9a2e17free_in_mem_blockEPv(void *ptr);
# 489
static void _ZN28_INTERNAL_7_throw_c_721f9a2e16eh_free_on_stackEPv(void *ptr);
# 665
static void _ZN28_INTERNAL_7_throw_c_721f9a2e7cleanupEP17an_eh_stack_entrytt(an_eh_stack_entry_ptr ehsep, a_region_number region, a_region_number stop_at_region);
# 901
static a_boolean _ZN28_INTERNAL_7_throw_c_721f9a2e35check_pointer_levels_and_qualifiersEP31an_exception_type_specificationPj(an_exception_type_specification_ptr etsp, an_ETS_flag_set *ptr_flags);
# 958
static int _ZN28_INTERNAL_7_throw_c_721f9a2e35check_exception_type_specificationsEP31an_exception_type_specificationPKSt9type_infojPjPciPPvPS1_Pi(an_exception_type_specification_ptr etsp, a_type_info_impl_ptr type_info, an_ETS_flag_set flags, an_ETS_flag_set *ptr_flags, an_access_flag_string 
# 958
access_flags, a_boolean use_access_flags, void **object_ptr, an_exception_type_specification_ptr *etsp_found, a_boolean *nullptr_conv_needed);
# 1143
static void _ZN28_INTERNAL_7_throw_c_721f9a2e21destroy_thrown_objectEP19a_throw_stack_entry(a_throw_stack_entry_ptr tsep);
# 1203
extern void __exception_started(void);
# 1221
extern void __exception_caught(void);
# 1238
extern void __throw(void);
# 1626
static void _ZN28_INTERNAL_7_throw_c_721f9a2e16push_throw_stackEPKSt9type_infoPFvPvEjPjPciS3_iiP19a_throw_stack_entry(a_type_info_impl_ptr type_info, a_destructor_ptr destructor, an_ETS_flag_set flags, an_ETS_flag_set *ptr_flags, an_access_flag_string access_flags, a_boolean use_access_flags, void *
# 1626
object_address, a_boolean is_rethrow, a_boolean is_internal, a_throw_stack_entry_ptr primary_entry);
# 1699
static void _ZN28_INTERNAL_7_throw_c_721f9a2e12rethrow_fullEi(a_boolean is_internal);
# 1729
extern void __rethrow(void);
# 1739
extern void __internal_rethrow(void);
# 1766
extern void *__throw_setup_ptr(a_type_info_impl_ptr type_info, a_sizeof_t size, an_ETS_flag_set *ptr_flags);
# 1790
extern void *__throw_setup(a_type_info_impl_ptr type_info, a_sizeof_t size, an_ETS_flag_set ets_flags);
# 1822
extern void *__throw_setup_dtor(a_type_info_impl_ptr type_info, a_sizeof_t size, int ets_flags, a_destructor_ptr destructor);
# 1875
extern void __free_thrown_object(void);
# 1925
extern void __destroy_exception_object(void);
# 1957
extern void __eh_exit_processing(void);
# 1970
extern void __suppress_optim_on_vars_in_try(void);
# 1983
extern an_eh_stack_entry_ptr __get_curr_eh_stack_entry(void);
# 1992
extern void __type_of_thrown_object(a_type_info_impl_ptr *type, an_ETS_flag_set *flags, an_ETS_flag_set **ptr_flags);
# 2007
extern a_boolean __can_throw_type(a_type_info_impl_ptr type, an_ETS_flag_set flags, an_ETS_flag_set *ptr_flags);
# 35 "include_c++/typeinfo.stdh" 3
extern _ZSt6__bool _ZNKSt9type_infoeqERKS_(const struct _ZSt9type_info *const, const struct _ZSt9type_info *);


extern const char *_ZNKSt9type_info4nameEv(const struct _ZSt9type_info *const);
# 151 "/usr/include/stdio.h" 3
extern FILE *stderr;
# 419 "lib_src/eh.h"
extern a_region_number __eh_curr_region;




extern an_eh_stack_entry_ptr __curr_eh_stack_entry;


extern int __catch_clause_number;



extern void *__caught_object_address;
# 204 "lib_src/throw.c"
char __TID_v = 0;




char __TID_n = 0;
# 231
static a_throw_stack_entry_ptr curr_throw_stack_entry;




static a_mem_block_descr_ptr curr_mem_block_descr;




static a_mem_allocation_ptr mem_allocation_stack;




static a_mem_block_descr initial_mem_block_descr;
# 261
static union _ZN28_INTERNAL_7_throw_c_721f9a2eUt_E initial_mem_block; extern  __attribute__((__weak__)) /* COMDAT group: _ZTIDn */ const struct __fundamental_type_info _ZTIDn; extern const long _ZTVN10__cxxabiv123__fundamental_type_infoE[4]; extern  __attribute__((__weak__)) /* COMDAT group: _ZTSDn */ 
# 261
const char _ZTSDn[3]; extern  __attribute__((__weak__)) /* COMDAT group: _ZTIv */ const struct __fundamental_type_info _ZTIv; extern  __attribute__((__weak__)) /* COMDAT group: _ZTSv */ const char _ZTSv[2]; extern const struct __si_class_type_info _ZTIN10__cxxabiv120__si_class_type_infoE; extern 
# 261
const struct __si_class_type_info _ZTIN10__cxxabiv121__vmi_class_type_infoE;
# 231
static a_throw_stack_entry_ptr curr_throw_stack_entry = ((a_throw_stack_entry_ptr)0);




static a_mem_block_descr_ptr curr_mem_block_descr = ((a_mem_block_descr_ptr)0);




static a_mem_allocation_ptr mem_allocation_stack = ((a_mem_allocation_ptr)0);  __attribute__((__weak__)) /* COMDAT group: _ZTIDn */ const struct __fundamental_type_info _ZTIDn = {{(_ZTVN10__cxxabiv123__fundamental_type_infoE + 2),_ZTSDn}};  __attribute__((__weak__)) /* COMDAT group: _ZTSDn */ const 
# 241
char _ZTSDn[3] = "Dn";  __attribute__((__weak__)) /* COMDAT group: _ZTIv */ const struct __fundamental_type_info _ZTIv = {{(_ZTVN10__cxxabiv123__fundamental_type_infoE + 2),_ZTSv}};  __attribute__((__weak__)) /* COMDAT group: _ZTSv */ const char _ZTSv[2] = "v";
# 295
static void *_ZN28_INTERNAL_7_throw_c_721f9a2e13eh_get_memoryEm( a_sizeof_t __12198_39_size)
# 301
{
auto void *__12205_10_mem_block;

__12205_10_mem_block = (malloc(__12198_39_size));

if (__12205_10_mem_block == ((void *)0)) {
__call_terminate();
}
return __12205_10_mem_block;
}


static void _ZN28_INTERNAL_7_throw_c_721f9a2e14eh_free_memoryEPv( void *__12216_34_ptr)
# 319
{
free(__12216_34_ptr); 
}


static void _ZN28_INTERNAL_7_throw_c_721f9a2e20mem_block_descr_initEP17a_mem_block_descr( a_mem_block_descr_ptr __12227_56_mbdp)



{
(__12227_56_mbdp->next) = ((a_mem_block_descr_ptr)0);
(__12227_56_mbdp->addr) = ((void *)0);
(__12227_56_mbdp->size) = 0UL;
(__12227_56_mbdp->used) = 0UL;
(__12227_56_mbdp->dynamically_allocated) = ((a_byte_boolean)0U); 
}


static void _ZN28_INTERNAL_7_throw_c_721f9a2e25init_eh_memory_managementEv(void)



{

_ZN28_INTERNAL_7_throw_c_721f9a2e20mem_block_descr_initEP17a_mem_block_descr((&initial_mem_block_descr));
(initial_mem_block_descr.addr) = ((void *)(&initial_mem_block));
(initial_mem_block_descr.size) = 8192UL;
(initial_mem_block_descr.used) = 0UL;
(initial_mem_block_descr.dynamically_allocated) = ((a_byte_boolean)0U);
curr_mem_block_descr = (&initial_mem_block_descr); 
}
# 360
static void *_ZN28_INTERNAL_7_throw_c_721f9a2e18alloc_in_mem_blockEmPP16a_mem_allocation( a_sizeof_t __12263_50_size, 
a_mem_allocation_ptr *__12264_34_map)
# 367
{
auto void *__12271_11_ptr;
auto int __12272_9_used;



__12272_9_used = ((int)(curr_mem_block_descr->used));
(*__12264_34_map) = ((a_mem_allocation_ptr)((void *)(((char *)(curr_mem_block_descr->addr)) + __12272_9_used)));
__12272_9_used += 32UL;
__12271_11_ptr = ((void *)((void *)(((char *)(curr_mem_block_descr->addr)) + __12272_9_used)));
__12272_9_used += __12263_50_size;
(curr_mem_block_descr->used) = ((a_sizeof_t)__12272_9_used);

((*__12264_34_map)->next) = mem_allocation_stack;
((*__12264_34_map)->addr) = __12271_11_ptr;
mem_allocation_stack = (*__12264_34_map);

((*__12264_34_map)->alloc_size) = __12263_50_size;
((*__12264_34_map)->is_mem_block_descr_allocation) = ((a_byte_boolean)0U);
if (!((curr_mem_block_descr->used) <= (curr_mem_block_descr->size))) { { fprintf(stderr, ((const char *)"Assertion failed in file \"%s\", line %d\n"), ((const char *)("lib_src/throw.c")), 386); abort(); } } ;
if (!((__12263_50_size % 8UL) == 0UL)) { { fprintf(stderr, ((const char *)"Assertion failed in file \"%s\", line %d\n"), ((const char *)("lib_src/throw.c")), 387); abort(); } } ;
return __12271_11_ptr;
}


static void _ZN28_INTERNAL_7_throw_c_721f9a2e19alloc_new_mem_blockEm( a_sizeof_t __12295_44_size)
# 399
{
auto void *__12303_11_mem_block;
auto a_mem_allocation_ptr __12304_24_map;
auto a_mem_block_descr_ptr __12305_25_mpdp;
auto a_sizeof_t __12306_15_new_size;
# 409
__12306_15_new_size = (((__12295_44_size / 8192UL) + 1UL) * 8192UL);

if ((__12306_15_new_size - __12295_44_size) < 4096UL) {
__12306_15_new_size += 8192UL;
}
__12295_44_size = __12306_15_new_size;


__12305_25_mpdp = ((a_mem_block_descr_ptr)(_ZN28_INTERNAL_7_throw_c_721f9a2e18alloc_in_mem_blockEmPP16a_mem_allocation(40UL, (&__12304_24_map))));

(__12304_24_map->is_mem_block_descr_allocation) = ((a_byte_boolean)1U);
__12303_11_mem_block = (_ZN28_INTERNAL_7_throw_c_721f9a2e13eh_get_memoryEm(__12295_44_size));

(__12305_25_mpdp->next) = curr_mem_block_descr;
curr_mem_block_descr = __12305_25_mpdp;

(__12305_25_mpdp->addr) = __12303_11_mem_block;
(__12305_25_mpdp->size) = __12295_44_size;
(__12305_25_mpdp->used) = 0UL;
(__12305_25_mpdp->dynamically_allocated) = ((a_byte_boolean)1U); 
}


static void *_ZN28_INTERNAL_7_throw_c_721f9a2e17eh_alloc_on_stackEm( a_sizeof_t __12335_43_size)



{
auto a_mem_allocation_ptr __12340_24_map;
auto int __12341_9_needed_for_alignment;
auto void *__12342_11_ptr;
auto a_sizeof_t __12343_15_alloc_size;



if (curr_mem_block_descr == ((a_mem_block_descr_ptr)0)) {
_ZN28_INTERNAL_7_throw_c_721f9a2e25init_eh_memory_managementEv();
}


__12341_9_needed_for_alignment = ((int)(((__12335_43_size % 8UL) == 0UL) ? 0UL : (8UL - (__12335_43_size % 8UL))));




__12343_15_alloc_size = (__12335_43_size + ((unsigned long)__12341_9_needed_for_alignment));
if ((((__12343_15_alloc_size + 32UL) + (curr_mem_block_descr->used)) + 72UL) > (curr_mem_block_descr->size))

{
_ZN28_INTERNAL_7_throw_c_721f9a2e19alloc_new_mem_blockEm(__12343_15_alloc_size);
}
__12342_11_ptr = (_ZN28_INTERNAL_7_throw_c_721f9a2e18alloc_in_mem_blockEmPP16a_mem_allocation(__12343_15_alloc_size, (&__12340_24_map)));
# 467
return __12342_11_ptr;
}


static void _ZN28_INTERNAL_7_throw_c_721f9a2e17free_in_mem_blockEPv( void *__12374_37_ptr)



{
auto a_mem_allocation_ptr __12379_24_map;
auto int __12380_9_used;

__12379_24_map = mem_allocation_stack;
mem_allocation_stack = (__12379_24_map->next);
if (!((__12379_24_map->addr) == __12374_37_ptr)) { { fprintf(stderr, ((const char *)"Assertion failed in file \"%s\", line %d\n"), ((const char *)("lib_src/throw.c")), 481); abort(); } } ;
__12380_9_used = ((int)(curr_mem_block_descr->used));
__12380_9_used -= (__12379_24_map->alloc_size);
__12380_9_used -= 32UL;
(curr_mem_block_descr->used) = ((a_sizeof_t)__12380_9_used); 
}


static void _ZN28_INTERNAL_7_throw_c_721f9a2e16eh_free_on_stackEPv( void *__12392_36_ptr)




{

_ZN28_INTERNAL_7_throw_c_721f9a2e17free_in_mem_blockEPv(__12392_36_ptr);

if ((curr_mem_block_descr->used) == 0UL) {
if ((curr_mem_block_descr->next) != ((a_mem_block_descr_ptr)0)) {

auto a_mem_block_descr_ptr __12404_29_mpdp_to_free;
__12404_29_mpdp_to_free = curr_mem_block_descr;
curr_mem_block_descr = (__12404_29_mpdp_to_free->next);


if (__12404_29_mpdp_to_free->dynamically_allocated) {

_ZN28_INTERNAL_7_throw_c_721f9a2e14eh_free_memoryEPv((__12404_29_mpdp_to_free->addr));
}

_ZN28_INTERNAL_7_throw_c_721f9a2e17free_in_mem_blockEPv(((void *)__12404_29_mpdp_to_free));
}
} 
}
# 665
static void _ZN28_INTERNAL_7_throw_c_721f9a2e7cleanupEP17an_eh_stack_entrytt( an_eh_stack_entry_ptr __12568_43_ehsep, 
a_region_number __12569_43_region, 
a_region_number __12570_25_stop_at_region)
# 676
{
auto an_object_ptr *__12580_34_obj_addr_array;
auto an_eh_region_descr_ptr __12581_26_ehrdp;
# 686
__12580_34_obj_addr_array = (((__12568_43_ehsep->variant).function).object_address_table);
for (; ((int)__12569_43_region) != ((int)__12570_25_stop_at_region); __12569_43_region = (__12581_26_ehrdp->index_of_next_region)) { {
auto an_object_ptr __12591_27_obj_addr = ((an_object_ptr)0);
auto a_conditional_flag *__12592_33_flag_addr = ((a_conditional_flag *)0);
auto char *__12593_13_temp_addr;
auto a_region_descr_flag_set __12594_33_flags;
auto an_eh_array_supplement_ptr __12595_32_ehasp = ((an_eh_array_supplement_ptr)0);
auto void *__12596_13_vtbl_ptr;
auto a_boolean __12597_17_has_vtbl_ptr = 0;

auto a_destroy_exception_object_ptr __12599_5_potential_destroy_exception_object_ptr;

__12581_26_ehrdp = ((((__12568_43_ehsep->variant).function).regions) + __12569_43_region);
# 710
__12599_5_potential_destroy_exception_object_ptr = ((a_destroy_exception_object_ptr)(__12581_26_ehrdp->destructor_or_delete_routine));

if (__12599_5_potential_destroy_exception_object_ptr == (&__destroy_exception_object))
{
__destroy_exception_object();
goto __T655882792;
}
__12594_33_flags = (__12581_26_ehrdp->flags);
if (((int)__12594_33_flags) & 0x2) {
# 727
__12592_33_flag_addr = ((a_conditional_flag *)(*(__12580_34_obj_addr_array + ((__12581_26_ehrdp + 1)->handle))));
# 734
if (!(*__12592_33_flag_addr)) { goto __T655882792; }
}
if (((((int)__12594_33_flags) & 0x20) != 0) && (((((int)__12594_33_flags) & 0x40) != 0) && ((((int)__12594_33_flags) & 0x8) == 0)))
{
# 745
auto an_eh_region_descr_ptr __12648_30_vtbl_ehrdp;
# 744
__12597_17_has_vtbl_ptr = 1;

__12648_30_vtbl_ehrdp = (__12581_26_ehrdp + 1);
if (__12592_33_flag_addr != ((a_conditional_flag *)0)) { __12648_30_vtbl_ehrdp++; }




__12596_13_vtbl_ptr = (*((void **)(__12580_34_obj_addr_array + (__12648_30_vtbl_ehrdp->handle))));
if (((int)(__12648_30_vtbl_ehrdp->flags)) & 0x1) {



__12593_13_temp_addr = ((char *)(*((void **)__12596_13_vtbl_ptr)));
__12596_13_vtbl_ptr = ((void *)__12593_13_temp_addr);
}
# 765
}
# 772
if (!(__12580_34_obj_addr_array != ((an_object_ptr *)0))) { { fprintf(stderr, ((const char *)"Assertion failed in file \"%s\", line %d\n"), ((const char *)("lib_src/throw.c")), 772); abort(); } } ;
if (((int)__12594_33_flags) & 0x8) {

__12595_32_ehasp = ((((__12568_43_ehsep->variant).function).array_table) + (__12581_26_ehrdp->handle));
__12591_27_obj_addr = (*(__12580_34_obj_addr_array + (__12595_32_ehasp->handle)));
} else  {

__12591_27_obj_addr = (*(__12580_34_obj_addr_array + (__12581_26_ehrdp->handle)));
}
if (((int)__12594_33_flags) & 0x1) {



__12593_13_temp_addr = ((char *)(*((void **)__12591_27_obj_addr)));
__12591_27_obj_addr = ((void *)__12593_13_temp_addr);
}
# 794
if ((((int)__12594_33_flags) & 0x80) != 0) {
# 803
__12592_33_flag_addr = ((a_conditional_flag *)__12591_27_obj_addr);
# 810
__cxa_guard_abort(((an_ia64_guard_ptr)__12592_33_flag_addr));



} else  { if (!(((int)__12594_33_flags) & 0x4)) {


auto a_destructor_ptr __12720_24_dtor_ptr;
__12720_24_dtor_ptr = ((a_destructor_ptr)(__12581_26_ehrdp->destructor_or_delete_routine));
if (((int)__12594_33_flags) & 0x8) {




auto a_boolean __12727_20_is_vla; __12727_20_is_vla = ((a_boolean)((((int)__12594_33_flags) & 0x40) != 0));
if (__12720_24_dtor_ptr != ((a_destructor_ptr)0)) { auto an_object_ptr __T655928936; auto size_t __T655929584; auto a_sizeof_t __T655930320; auto a_destructor_ptr __T655931056;
auto an_element_count __12729_28_elements; __12729_28_elements = (__12595_32_ehasp->array_size);
if (__12727_20_is_vla) {


auto a_sizeof_t *__12733_26_element_addr;
__12733_26_element_addr = ((a_sizeof_t *)(__12580_34_obj_addr_array[((__12581_26_ehrdp + 1)->handle)]));
__12729_28_elements = ((an_element_count)(*__12733_26_element_addr));
}
# 839
((((__T655928936 = __12591_27_obj_addr) , (__T655929584 = ((size_t)__12729_28_elements))) , (__T655930320 = (__12595_32_ehasp->element_size))) , (__T655931056 = __12720_24_dtor_ptr)) , (__cxa_vec_dtor(__T655928936, __T655929584, __T655930320, __T655931056));


}
} else  { if (__12597_17_has_vtbl_ptr) { auto an_object_ptr __T655931968; auto void *__T655932616;
# 852
auto a_destructor_with_vtable_param_ptr __12755_44_dtor_with_vtable;
__12755_44_dtor_with_vtable = ((a_destructor_with_vtable_param_ptr)__12720_24_dtor_ptr);
((__T655931968 = __12591_27_obj_addr) , (__T655932616 = __12596_13_vtbl_ptr)) , (__12755_44_dtor_with_vtable(__T655931968, __T655932616));
} else  {
# 867
__12720_24_dtor_ptr(__12591_27_obj_addr);

} }
} else  {


if (__12591_27_obj_addr != ((an_object_ptr)0)) {
if (((int)__12594_33_flags) & 0x8) { auto an_object_ptr __T655933528; auto a_sizeof_t __T655934176;


auto a_two_operand_delete_ptr __12780_36_delete_ptr;
__12780_36_delete_ptr = ((a_two_operand_delete_ptr)(__12581_26_ehrdp->destructor_or_delete_routine));

((__T655933528 = __12591_27_obj_addr) , (__T655934176 = (__12595_32_ehasp->element_size))) , (__12780_36_delete_ptr(__T655933528, __T655934176));
} else  {
auto a_delete_ptr __12785_24_delete_ptr;
__12785_24_delete_ptr = ((a_delete_ptr)(__12581_26_ehrdp->destructor_or_delete_routine));
__12785_24_delete_ptr(__12591_27_obj_addr);
}
}
} }
} __T655882792:; } 
}
# 901
static a_boolean _ZN28_INTERNAL_7_throw_c_721f9a2e35check_pointer_levels_and_qualifiersEP31an_exception_type_specificationPj(
an_exception_type_specification_ptr __12805_40_etsp, 
an_ETS_flag_set *__12806_24_ptr_flags)
# 914
{
auto a_boolean __12818_14_okay;
auto a_boolean __12819_14_previous_qualifiers_include_const = 1;
auto an_ETS_flag_set *__12820_20_source_ptr_flags;
auto an_ETS_flag_set *__12821_20_dest_ptr_flags;

__12821_20_dest_ptr_flags = (__12805_40_etsp->ptr_flags);
__12820_20_source_ptr_flags = __12806_24_ptr_flags;
for (__12818_14_okay = 1; __12818_14_okay == 1; ) {
auto an_ETS_flag_set __12826_21_dest_qualifiers;
auto an_ETS_flag_set __12827_21_source_qualifiers;

__12826_21_dest_qualifiers = ((*__12821_20_dest_ptr_flags) & 6U);
__12827_21_source_qualifiers = ((*__12820_20_source_ptr_flags) & 6U);
if (((int)(((*__12820_20_source_ptr_flags) & 32U) != 0U)) != ((int)(((*__12821_20_dest_ptr_flags) & 32U) != 0U))) {

__12818_14_okay = 0;
} else  { if (((~__12826_21_dest_qualifiers) & __12827_21_source_qualifiers) != 0U)
{

__12818_14_okay = 0;
} else  {


if (((~__12827_21_source_qualifiers) & __12826_21_dest_qualifiers) != 0U)
{
__12818_14_okay = __12819_14_previous_qualifiers_include_const;
if (!(__12818_14_okay)) { goto __T655955272; }
}

if (!((__12826_21_dest_qualifiers & 2U) != 0U)) {
__12819_14_previous_qualifiers_include_const = 0;
}
} }

if (((*__12820_20_source_ptr_flags) & 32U) != 0U) { goto __T655955272; }
__12821_20_dest_ptr_flags++;
__12820_20_source_ptr_flags++;
} __T655955272:;
return __12818_14_okay;
}



static int _ZN28_INTERNAL_7_throw_c_721f9a2e35check_exception_type_specificationsEP31an_exception_type_specificationPKSt9type_infojPjPciPPvPS1_Pi(
an_exception_type_specification_ptr __12862_39_etsp, 
a_type_info_impl_ptr __12863_26_type_info, 
an_ETS_flag_set __12864_22_flags, 
an_ETS_flag_set *__12865_23_ptr_flags, 
an_access_flag_string __12866_27_access_flags, 
a_boolean __12867_16_use_access_flags, 
void **__12868_14_object_ptr, 
an_exception_type_specification_ptr *__12869_40_etsp_found, 
a_boolean *__12870_17_nullptr_conv_needed)
# 978
{
auto int __12882_16_result = 0;
auto int __12883_16_index = 0;
auto a_boolean __12884_21_done = 0;
auto a_boolean __12885_14_is_ptr;

if (__12870_17_nullptr_conv_needed != ((a_boolean *)0)) { (*__12870_17_nullptr_conv_needed) = 0; }
(*__12869_40_etsp_found) = ((an_exception_type_specification_ptr)0);
__12885_14_is_ptr = ((a_boolean)(((__12864_22_flags & 1U) != 0U) || (__12865_23_ptr_flags != ((an_ETS_flag_set *)0))));
do { auto void **__T656126560; auto a_type_info_impl_ptr __T656127208; auto a_type_info_impl_ptr __T656127944; auto a_boolean __T656128680;
auto a_boolean __12891_23_match = 0;
auto void *__12892_25_new_ptr;
auto a_boolean __12893_16_ets_is_ptr;
auto a_boolean __12894_16_is_single_ptr;
auto a_boolean __12895_16_ets_is_single_ptr;
auto an_access_flag_string __12896_27_local_access_flags; __12896_27_local_access_flags = __12866_27_access_flags;



__12893_16_ets_is_ptr = ((a_boolean)((((__12862_39_etsp->flags) & 1U) != 0U) || ((__12862_39_etsp->ptr_flags) != ((an_ETS_flag_set *)0))));
__12895_16_ets_is_single_ptr = ((a_boolean)((((__12862_39_etsp->flags) & 1U) != 0U) || (0)));
__12894_16_is_single_ptr = ((a_boolean)(((__12864_22_flags & 1U) != 0U) || (0)));
__12883_16_index++;
if ((((__12862_39_etsp->flags) & 16U) != 0U) && (((__12862_39_etsp->flags) & 129U) == 0U)) {
__12891_23_match = 1;
} else  { if (__12893_16_ets_is_ptr != __12885_14_is_ptr) {

} else  { if (((__12862_39_etsp->type_info) == __12863_26_type_info) || ((_ZNKSt9type_info4nameEv((__12862_39_etsp->type_info))) == (_ZNKSt9type_info4nameEv(__12863_26_type_info)))) {


if (!(__12885_14_is_ptr)) {

if ((((((__12862_39_etsp->flags) & 128U) != 0U) && ((__12864_22_flags & 128U) != 0U)) && ((((__12862_39_etsp->flags) & 16U) != 0U) && (((__12862_39_etsp->flags) & 129U) != 0U))) && (!(((__12864_22_flags & 16U) != 0U) && ((__12864_22_flags & 129U) != 0U))))


{



} else  {
__12891_23_match = 1;
}
} else  { if (__12894_16_is_single_ptr != __12895_16_ets_is_single_ptr) {

} else  { auto an_exception_type_specification_ptr __T656119944; auto an_ETS_flag_set *__T656120592; if (__12894_16_is_single_ptr) {


auto an_ETS_flag_set __12928_25_source_qualifiers;
auto an_ETS_flag_set __12929_25_dest_qualifiers;
# 1025
__12928_25_source_qualifiers = (__12864_22_flags & 6U);
__12929_25_dest_qualifiers = ((__12862_39_etsp->flags) & 6U);
if (!(((~__12929_25_dest_qualifiers) & __12928_25_source_qualifiers) != 0U))
{

if ((!((((__12862_39_etsp->flags) & 16U) != 0U) && (((__12862_39_etsp->flags) & 129U) != 0U))) || (((__12864_22_flags & 16U) != 0U) && ((__12864_22_flags & 129U) != 0U))) {




__12891_23_match = 1;
}
}

} else  {


if (((__T656119944 = __12862_39_etsp) , (__T656120592 = __12865_23_ptr_flags)) , (_ZN28_INTERNAL_7_throw_c_721f9a2e35check_pointer_levels_and_qualifiersEP31an_exception_type_specificationPj(__T656119944, __T656120592))) {
__12891_23_match = 1;
}

} } }
} } }
if (__12891_23_match) {


} else  { if (((__12893_16_ets_is_ptr) || (((__12862_39_etsp->flags) & 192U) != 0U)) && (_ZNKSt9type_infoeqERKS_(__12863_26_type_info, (((const struct _ZSt9type_info *)&(_ZTIDn.base))))))
# 1063
{


__12891_23_match = 1;
if (__12870_17_nullptr_conv_needed != ((a_boolean *)0)) { (*__12870_17_nullptr_conv_needed) = 1; }

} else  { if (__12893_16_ets_is_ptr != __12885_14_is_ptr) {

} else  { if (!((!(((__12864_22_flags & 1U) != 0U) || (0))) || ((((__12862_39_etsp->flags) & __12864_22_flags) & 6U) == (__12864_22_flags & 6U)))) {
# 1077
} else  { if (((((__12862_39_etsp->type_info) == ((const struct _ZSt9type_info *)(&_ZTIv))) || ((_ZNKSt9type_info4nameEv((__12862_39_etsp->type_info))) == (_ZNKSt9type_info4nameEv((((const struct _ZSt9type_info *)&(_ZTIv.base))))))) && (__12893_16_ets_is_ptr == __12885_14_is_ptr)) && (
# 1077
__12895_16_ets_is_single_ptr))
# 1085
{


__12891_23_match = 1;
# 1096
} else  { if ((((!(__12885_14_is_ptr)) || ((__12894_16_is_single_ptr) && (__12895_16_ets_is_single_ptr))) && ((_ZNKSt9type_infoeqERKS_(((const struct _ZSt9type_info *)((__12863_26_type_info) ? ((struct __EDG_type_info *)((__12863_26_type_info->__vptr)[(-1)])) : ((__cxa_bad_typeid()) , ((struct 
# 1096
__EDG_type_info *)0)))), (((const struct _ZSt9type_info *)&((_ZTIN10__cxxabiv120__si_class_type_infoE.base).base))))) || (_ZNKSt9type_infoeqERKS_(((const struct _ZSt9type_info *)((__12863_26_type_info) ? ((struct __EDG_type_info *)((__12863_26_type_info->__vptr)[(-1)])) : ((__cxa_bad_typeid()) , ((
# 1096
struct __EDG_type_info *)0)))), (((const struct _ZSt9type_info *)&((_ZTIN10__cxxabiv121__vmi_class_type_infoE.base).base))))))) && (((((__T656126560 = __12868_14_object_ptr) , (__T656127208 = __12863_26_type_info)) , (__T656127944 = (__12862_39_etsp->type_info))) , (__T656128680 = 
# 1096
__12867_16_use_access_flags)) , (__derived_to_base_conversion(__T656126560, (&__12892_25_new_ptr), __T656127208, __T656127944, (&__12896_27_local_access_flags), __T656128680))))
# 1107
{
# 1116
__12891_23_match = 1;


if (__12868_14_object_ptr != ((void **)0)) { (*__12868_14_object_ptr) = __12892_25_new_ptr; }
# 1130
} } } } } }
if (__12891_23_match) {
__12882_16_result = __12883_16_index;
(*__12869_40_etsp_found) = __12862_39_etsp;
goto __T656117088;
}
__12884_21_done = ((a_boolean)((__12862_39_etsp->flags) & 32U));
__12862_39_etsp++;
} while (!(__12884_21_done)); __T656117088:;
return __12882_16_result;
}


static void _ZN28_INTERNAL_7_throw_c_721f9a2e21destroy_thrown_objectEP19a_throw_stack_entry( a_throw_stack_entry_ptr __13046_59_tsep)
# 1149
{
auto void *__13053_12_object_address;
auto a_throw_stack_entry_ptr __13054_27_primary_tsep;



__13054_27_primary_tsep = ((__13046_59_tsep->is_rethrow) ? (__13046_59_tsep->primary_entry) : __13046_59_tsep);
if (!(__13046_59_tsep->discard_entry)) {


(__13046_59_tsep->discard_entry) = ((a_byte_boolean)1U);



if (__13046_59_tsep->is_internal) { (__13054_27_primary_tsep->discard_entry) = ((a_byte_boolean)1U); }
if (!((__13054_27_primary_tsep->use_count) > 0UL)) { { fprintf(stderr, ((const char *)"Assertion failed in file \"%s\", line %d\n"), ((const char *)("lib_src/throw.c")), 1164); abort(); } } ;
(__13054_27_primary_tsep->use_count)--;
}
# 1178
if (((__13054_27_primary_tsep->use_count) == 0UL) && (!(__13054_27_primary_tsep->dtor_called))) {

(__13054_27_primary_tsep->dtor_called) = ((a_byte_boolean)1U);
__13053_12_object_address = (__13054_27_primary_tsep->object_address);
if ((__13054_27_primary_tsep->object_copy_complete) && (!((((__13054_27_primary_tsep->flags) & 1U) != 0U) || ((__13054_27_primary_tsep->ptr_flags) != ((an_ETS_flag_set *)0)))))
{
# 1189
auto a_destructor_ptr __13092_24_dtor_ptr;
__13092_24_dtor_ptr = ((a_destructor_ptr)(__13054_27_primary_tsep->destructor));
if (__13092_24_dtor_ptr != ((a_destructor_ptr)0)) {



__13092_24_dtor_ptr(__13053_12_object_address);

}
}
} 
}


void __exception_started(void)
# 1211
{
auto a_throw_stack_entry_ptr __13115_27_tsep; __13115_27_tsep = curr_throw_stack_entry;


((__13115_27_tsep->throw_marker).next) = __curr_eh_stack_entry;
__curr_eh_stack_entry = (&(__13115_27_tsep->throw_marker));
(__13115_27_tsep->object_evaluation_complete) = ((a_byte_boolean)1U); 
}


void __exception_caught(void)




{
if (!(((int)(__curr_eh_stack_entry->kind)) == 3)) { { fprintf(stderr, ((const char *)"Assertion failed in file \"%s\", line %d\n"), ((const char *)("lib_src/throw.c")), 1228); abort(); } }
;
# 1234
__curr_eh_stack_entry = (__curr_eh_stack_entry->next); 
}


void __throw(void)




{ static const struct __C1 __T656165448 = {((void (*)())0),0L};
auto an_eh_stack_entry_ptr __13147_26_ehsep;
auto an_eh_stack_entry_ptr __13148_26_destination_ehsep = ((an_eh_stack_entry_ptr)0);



auto int __13152_10_destination_catch_value;
auto void *__13153_12_object_ptr;
auto void *__13154_12_object_buffer_ptr;
auto a_type_info_impl_ptr __13155_25_thrown_type_info;
auto an_ETS_flag_set __13156_20_throw_flags;
auto an_ETS_flag_set *__13157_21_throw_ptr_flags;

auto an_exception_type_specification_ptr __13159_5_etsp_found = ((an_exception_type_specification_ptr)0);
auto a_boolean __13160_15_nullptr_conv_needed = 0;
auto an_access_flag_string __13161_33_access_flags;
auto a_boolean __13162_15_use_access_flags;

if (!(curr_throw_stack_entry->object_evaluation_complete)) {


__exception_started();
}


(curr_throw_stack_entry->object_copy_complete) = ((a_byte_boolean)1U);


__13155_25_thrown_type_info = (curr_throw_stack_entry->type_info);
__13156_20_throw_flags = (curr_throw_stack_entry->flags);
__13157_21_throw_ptr_flags = (curr_throw_stack_entry->ptr_flags);
__13161_33_access_flags = (curr_throw_stack_entry->access_flags);
__13162_15_use_access_flags = ((a_boolean)(curr_throw_stack_entry->use_access_flags));
# 1281
if (((__13156_20_throw_flags & 1U) != 0U) || (__13157_21_throw_ptr_flags != ((an_ETS_flag_set *)0))) {



__13154_12_object_buffer_ptr = (curr_throw_stack_entry->object_address);
__13153_12_object_ptr = (*((void **)__13154_12_object_buffer_ptr));
__13154_12_object_buffer_ptr = ((void *)(&(curr_throw_stack_entry->pointer_buffer)));
} else  {


__13154_12_object_buffer_ptr = (curr_throw_stack_entry->object_address);
__13153_12_object_ptr = __13154_12_object_buffer_ptr;
}
# 1301
__13147_26_ehsep = __curr_eh_stack_entry;
if (!(__13147_26_ehsep == (&(curr_throw_stack_entry->throw_marker)))) { { fprintf(stderr, ((const char *)"Assertion failed in file \"%s\", line %d\n"), ((const char *)("lib_src/throw.c")), 1302); abort(); } } ;

__13147_26_ehsep = (__13147_26_ehsep->next);
while (__13147_26_ehsep != ((an_eh_stack_entry_ptr)0)) { {
auto unsigned char __13209_28_kind; __13209_28_kind = (__13147_26_ehsep->kind);
# 1316
if (((int)__13209_28_kind) == 1) {

} else  { if (((int)__13209_28_kind) == 4) {

} else  { if ((((int)__13209_28_kind) == 0) || (((int)__13209_28_kind) == 5))
{
if ((((__13147_26_ehsep->variant).try_block).catch_info) == ((void *)0)) {

auto int __13227_13_result;
if ((((__13147_26_ehsep->variant).try_block).catch_entries) != ((an_exception_type_specification_ptr)0)) { auto an_exception_type_specification_ptr __T656361360; auto a_type_info_impl_ptr __T656362280; auto an_ETS_flag_set __T656363016; auto an_ETS_flag_set *__T656363752; auto an_access_flag_string 
# 1325
__T656364488; auto a_boolean __T656365224;


__13227_13_result = (((((((__T656361360 = (((__13147_26_ehsep->variant).try_block).catch_entries)) , (__T656362280 = __13155_25_thrown_type_info)) , (__T656363016 = __13156_20_throw_flags)) , (__T656363752 = __13157_21_throw_ptr_flags)) , (__T656364488 = __13161_33_access_flags)) , (__T656365224 = 
# 1328
__13162_15_use_access_flags)) , (_ZN28_INTERNAL_7_throw_c_721f9a2e35check_exception_type_specificationsEP31an_exception_type_specificationPKSt9type_infojPjPciPPvPS1_Pi(__T656361360, __T656362280, __T656363016, __T656363752, __T656364488, __T656365224, (&__13153_12_object_ptr), (&
# 1328
__13159_5_etsp_found), (&__13160_15_nullptr_conv_needed))));
# 1334
} else  {




__13227_13_result = 1;
}
if (__13227_13_result != 0) {
# 1350
if (__13148_26_destination_ehsep == ((an_eh_stack_entry_ptr)0)) {
__13148_26_destination_ehsep = __13147_26_ehsep;
__13152_10_destination_catch_value = __13227_13_result;
}
if ((((__13147_26_ehsep->variant).try_block).catch_entries) != ((an_exception_type_specification_ptr)0)) {




goto __T656267200;
}
}
}
} else  { if (__13148_26_destination_ehsep != ((an_eh_stack_entry_ptr)0)) {




__13147_26_ehsep = (__13147_26_ehsep->next);
goto __T656269176;
} else  { if (((int)__13209_28_kind) == 2) {
# 1376
auto int __13279_11_result = 0;
if (((__13147_26_ehsep->variant).throw_specification) != ((an_exception_type_specification_ptr)0)) { auto an_exception_type_specification_ptr __T656366136; auto a_type_info_impl_ptr __T656366784; auto an_ETS_flag_set __T656367520; auto an_ETS_flag_set *__T656368256; auto an_access_flag_string 
# 1377
__T656368992; auto a_boolean __T656369728;
auto an_exception_type_specification_ptr __13281_45_dummy_etsp;
__13279_11_result = (((((((__T656366136 = ((__13147_26_ehsep->variant).throw_specification)) , (__T656366784 = __13155_25_thrown_type_info)) , (__T656367520 = __13156_20_throw_flags)) , (__T656368256 = __13157_21_throw_ptr_flags)) , (__T656368992 = __13161_33_access_flags)) , (__T656369728 = 
# 1379
__13162_15_use_access_flags)) , (_ZN28_INTERNAL_7_throw_c_721f9a2e35check_exception_type_specificationsEP31an_exception_type_specificationPKSt9type_infojPjPciPPvPS1_Pi(__T656366136, __T656366784, __T656367520, __T656368256, __T656368992, __T656369728, ((void **)0), (&__13281_45_dummy_etsp), ((
# 1379
a_boolean *)0))));
# 1385
}
if (__13279_11_result == 0) {
__13148_26_destination_ehsep = __13147_26_ehsep;
goto __T656267200;
}
} else  { if (((int)__13209_28_kind) == 6) {
# 1396
__13148_26_destination_ehsep = __13147_26_ehsep;
goto __T656267200;
} else  { if (((int)__13209_28_kind) == 3) {
# 1404
__curr_eh_stack_entry = __13147_26_ehsep;


(curr_throw_stack_entry->in_handler) = ((a_byte_boolean)1U);
__exception_caught();
__call_terminate();
} else  {
{ fprintf(stderr, ((const char *)"Assertion failed in file \"%s\", line %d\n"), ((const char *)("lib_src/throw.c")), 1411); abort(); } ;
} } } } } } }
__13147_26_ehsep = (__13147_26_ehsep->next);
} __T656269176:; } __T656267200:;
# 1426
__13147_26_ehsep = __curr_eh_stack_entry;

__13147_26_ehsep = (__13147_26_ehsep->next);
while (__13147_26_ehsep != __13148_26_destination_ehsep) { auto an_eh_stack_entry_ptr __T656370816; auto a_region_number __T656371464;
auto unsigned char __13333_28_kind; __13333_28_kind = (__13147_26_ehsep->kind);
# 1440
if (((int)__13333_28_kind) == 1) {
((__T656370816 = __13147_26_ehsep) , (__T656371464 = __eh_curr_region)) , (_ZN28_INTERNAL_7_throw_c_721f9a2e7cleanupEP17an_eh_stack_entrytt(__T656370816, __T656371464, ((a_region_number)65535U)));
__eh_curr_region = (((__13147_26_ehsep->variant).function).saved_region_number);
} else  { if (((int)__13333_28_kind) == 4) {



__cleanup_vec_new_or_delete(__13147_26_ehsep);
} else  { if (((int)__13333_28_kind) == 0) {

if ((((__13147_26_ehsep->variant).try_block).catch_info) != ((void *)0)) {
# 1461
auto a_throw_stack_entry_ptr __13364_33_tsep;
__13364_33_tsep = ((a_throw_stack_entry_ptr)(((__13147_26_ehsep->variant).try_block).catch_info));
_ZN28_INTERNAL_7_throw_c_721f9a2e21destroy_thrown_objectEP19a_throw_stack_entry(__13364_33_tsep);
}
} else  { if (((int)__13333_28_kind) == 5) {


auto a_throw_stack_entry_ptr __13371_31_tsep;
for (__13371_31_tsep = curr_throw_stack_entry; __13371_31_tsep != ((a_throw_stack_entry_ptr)0); __13371_31_tsep = (__13371_31_tsep->next)) {
if ((__13371_31_tsep->nearest_enclosing_try_block) == __13147_26_ehsep) {
(__13371_31_tsep->nearest_enclosing_try_block) = ((an_eh_stack_entry_ptr)0);
}
}
} else  { if (((int)__13333_28_kind) == 2) {

} else  { if (((int)__13333_28_kind) == 3) {

} else  { if (((int)__13333_28_kind) == 6) {


{ fprintf(stderr, ((const char *)"Assertion failed in file \"%s\", line %d\n"), ((const char *)("lib_src/throw.c")), 1481); abort(); } ;
} else  {
{ fprintf(stderr, ((const char *)"Assertion failed in file \"%s\", line %d\n"), ((const char *)("lib_src/throw.c")), 1483); abort(); } ;
} } } } } } }
__13147_26_ehsep = (__13147_26_ehsep->next);
}
# 1494
if (__13148_26_destination_ehsep == ((an_eh_stack_entry_ptr)0)) {


(curr_throw_stack_entry->in_handler) = ((a_byte_boolean)1U);
__exception_caught();
__call_terminate();
}

if ((((int)(__13148_26_destination_ehsep->kind)) == 0) || (((int)(__13148_26_destination_ehsep->kind)) == 5))
{
# 1510
if (((int)(((__13148_26_destination_ehsep->variant).try_block).region_number)) != ((int)__eh_curr_region))
{ auto an_eh_stack_entry_ptr __T656372728; auto a_region_number __T656373376; auto a_region_number __T656374112;

auto an_eh_stack_entry_ptr __13416_29_function_ehsep; __13416_29_function_ehsep = (__13148_26_destination_ehsep->next);
while (((int)(__13416_29_function_ehsep->kind)) != 1) {
__13416_29_function_ehsep = (__13416_29_function_ehsep->next);
}
(((__T656372728 = __13416_29_function_ehsep) , (__T656373376 = __eh_curr_region)) , (__T656374112 = (((__13148_26_destination_ehsep->variant).try_block).region_number))) , (_ZN28_INTERNAL_7_throw_c_721f9a2e7cleanupEP17an_eh_stack_entrytt(__T656372728, __T656373376, __T656374112));



__eh_curr_region = (((__13148_26_destination_ehsep->variant).try_block).region_number);
}
}




if (!(__curr_eh_stack_entry == (&(curr_throw_stack_entry->throw_marker)))) { { fprintf(stderr, ((const char *)"Assertion failed in file \"%s\", line %d\n"), ((const char *)("lib_src/throw.c")), 1529); abort(); } }
;
(__curr_eh_stack_entry->next) = __13148_26_destination_ehsep;


(curr_throw_stack_entry->in_handler) = ((a_byte_boolean)1U);
if ((((int)(__13148_26_destination_ehsep->kind)) == 0) || (((int)(__13148_26_destination_ehsep->kind)) == 5))
{
auto a_boolean __13439_15_exception_caught = 0;
__catch_clause_number = __13152_10_destination_catch_value;
if (((__13156_20_throw_flags & 1U) != 0U) || (__13157_21_throw_ptr_flags != ((an_ETS_flag_set *)0))) {
# 1544
(*((void **)__13154_12_object_buffer_ptr)) = __13153_12_object_ptr;
__caught_object_address = __13154_12_object_buffer_ptr;
} else  { if (__13160_15_nullptr_conv_needed) {



if ((((__13159_5_etsp_found->flags) & 1U) != 0U) || ((__13159_5_etsp_found->ptr_flags) != ((an_ETS_flag_set *)0))) {

(curr_throw_stack_entry->pointer_buffer) = ((void *)0);
__caught_object_address = ((void *)(&(curr_throw_stack_entry->pointer_buffer)));
} else  { if (((__13159_5_etsp_found->flags) & 64U) != 0U) {

(curr_throw_stack_entry->ptr_to_data_member_buffer) = (-1L);
__caught_object_address = ((void *)(&(curr_throw_stack_entry->ptr_to_data_member_buffer)));

} else  {

(curr_throw_stack_entry->ptr_to_member_function_buffer) = __T656165448;
__caught_object_address = ((void *)(&(curr_throw_stack_entry->ptr_to_member_function_buffer)));

} }
} else  {




__caught_object_address = __13153_12_object_ptr;
} }


(((__13148_26_destination_ehsep->variant).try_block).catch_info) = ((void *)curr_throw_stack_entry);
# 1594
if (__13439_15_exception_caught) {

__exception_caught();
}
longjmp(((((__13148_26_destination_ehsep->variant).try_block).setjmp_buffer)), 1);
} else  { if (((int)(__13148_26_destination_ehsep->kind)) == 2)
{




__curr_eh_stack_entry = (__curr_eh_stack_entry->next);
# 1613
__call_unexpected();
} else  { if (((int)(__13148_26_destination_ehsep->kind)) == 6)
{




__curr_eh_stack_entry = (__curr_eh_stack_entry->next);
__call_terminate();
} } } 
}


static void _ZN28_INTERNAL_7_throw_c_721f9a2e16push_throw_stackEPKSt9type_infoPFvPvEjPjPciS3_iiP19a_throw_stack_entry( a_type_info_impl_ptr __13529_54_type_info, 
a_destructor_ptr __13530_31_destructor, 
an_ETS_flag_set __13531_30_flags, 
an_ETS_flag_set *__13532_31_ptr_flags, 
an_access_flag_string __13533_54_access_flags, 
a_boolean __13534_54_use_access_flags, 
void *__13535_21_object_address, 
a_boolean __13536_25_is_rethrow, 
a_boolean __13537_25_is_internal, 
a_throw_stack_entry_ptr __13538_54_primary_entry)



{
auto a_throw_stack_entry_ptr __13543_27_tsep;
auto an_eh_stack_entry_ptr __13544_26_ehsep;

__13543_27_tsep = ((a_throw_stack_entry_ptr)(_ZN28_INTERNAL_7_throw_c_721f9a2e17eh_alloc_on_stackEm(360UL)));
# 1650
__13544_26_ehsep = __curr_eh_stack_entry;
while (__13544_26_ehsep != ((an_eh_stack_entry_ptr)0)) {

if (((((int)(__13544_26_ehsep->kind)) == 0) || (((int)(__13544_26_ehsep->kind)) == 5)) && ((((__13544_26_ehsep->variant).try_block).catch_info) == ((void *)0))) {

goto __T656388440; }
__13544_26_ehsep = (__13544_26_ehsep->next);
} __T656388440:;
(__13543_27_tsep->nearest_enclosing_try_block) = __13544_26_ehsep;
if (curr_throw_stack_entry != ((a_throw_stack_entry_ptr)0)) {
if ((curr_throw_stack_entry->nearest_enclosing_try_block) == __13544_26_ehsep) {


_ZN28_INTERNAL_7_throw_c_721f9a2e21destroy_thrown_objectEP19a_throw_stack_entry(curr_throw_stack_entry);
}
}
(__13543_27_tsep->next) = curr_throw_stack_entry;
curr_throw_stack_entry = __13543_27_tsep;
(__13543_27_tsep->type_info) = __13529_54_type_info;
(__13543_27_tsep->destructor) = __13530_31_destructor;
(__13543_27_tsep->flags) = __13531_30_flags;
(__13543_27_tsep->ptr_flags) = __13532_31_ptr_flags;
(__13543_27_tsep->access_flags) = __13533_54_access_flags;
(__13543_27_tsep->use_access_flags) = ((a_byte_boolean)__13534_54_use_access_flags);
(__13543_27_tsep->object_address) = __13535_21_object_address;
(__13543_27_tsep->pointer_buffer) = ((void *)0);
(__13543_27_tsep->primary_entry) = __13538_54_primary_entry;
(__13543_27_tsep->use_count) = 0UL;


if (__13537_25_is_internal) {

} else  { if (__13536_25_is_rethrow) {
(__13538_54_primary_entry->use_count)++;
} else  {
(__13543_27_tsep->use_count)++;
} }
(__13543_27_tsep->is_rethrow) = ((a_byte_boolean)__13536_25_is_rethrow);
(__13543_27_tsep->is_internal) = ((a_byte_boolean)__13537_25_is_internal);
(__13543_27_tsep->dtor_called) = ((a_byte_boolean)0U);
(__13543_27_tsep->discard_entry) = ((a_byte_boolean)0U);
(__13543_27_tsep->in_handler) = ((a_byte_boolean)0U);
(__13543_27_tsep->object_copy_complete) = ((a_byte_boolean)0U);
(__13543_27_tsep->object_evaluation_complete) = ((a_byte_boolean)0U);
((__13543_27_tsep->throw_marker).next) = ((an_eh_stack_entry_ptr)0);
((__13543_27_tsep->throw_marker).kind) = ehsek_throw_processing_marker; 
}


static void _ZN28_INTERNAL_7_throw_c_721f9a2e12rethrow_fullEi( a_boolean __13602_36_is_internal)




{ auto a_type_info_impl_ptr __T656419704; auto a_destructor_ptr __T656420352; auto an_ETS_flag_set __T656421088; auto an_ETS_flag_set *__T656421824; auto an_access_flag_string __T656422560; auto a_boolean __T656423296; auto void *__T656424032; auto a_boolean __T656424768; auto 
# 1704
a_throw_stack_entry_ptr __T656425504;
auto a_throw_stack_entry_ptr __13608_27_tsep; __13608_27_tsep = curr_throw_stack_entry;


for (; __13608_27_tsep != ((a_throw_stack_entry_ptr)0); __13608_27_tsep = (__13608_27_tsep->next)) {
if ((__13608_27_tsep->in_handler) && (!(__13608_27_tsep->is_rethrow))) { goto __T656414864; }
} __T656414864:;
if (__13608_27_tsep == ((a_throw_stack_entry_ptr)0)) {

__call_terminate();
}
(((((((((__T656419704 = (__13608_27_tsep->type_info)) , (__T656420352 = (__13608_27_tsep->destructor))) , (__T656421088 = (__13608_27_tsep->flags))) , (__T656421824 = (__13608_27_tsep->ptr_flags))) , (__T656422560 = (__13608_27_tsep->access_flags))) , (__T656423296 = ((a_boolean)(__13608_27_tsep->
# 1715
use_access_flags)))) , (__T656424032 = (__13608_27_tsep->object_address))) , (__T656424768 = __13602_36_is_internal)) , (__T656425504 = __13608_27_tsep)) , (_ZN28_INTERNAL_7_throw_c_721f9a2e16push_throw_stackEPKSt9type_infoPFvPvEjPjPciS3_iiP19a_throw_stack_entry(__T656419704, __T656420352, 
# 1715
__T656421088, __T656421824, __T656422560, __T656423296, __T656424032, 1, __T656424768, __T656425504));
# 1725
__throw(); 
}


void __rethrow(void)



{
_ZN28_INTERNAL_7_throw_c_721f9a2e12rethrow_fullEi(0); 
}



void __internal_rethrow(void)
# 1745
{
__exception_caught();
_ZN28_INTERNAL_7_throw_c_721f9a2e12rethrow_fullEi(1); 
}
# 1766
void *__throw_setup_ptr( a_type_info_impl_ptr __13669_56_type_info, 
a_sizeof_t __13670_35_size, 
an_ETS_flag_set *__13671_31_ptr_flags)
# 1774
{ auto a_type_info_impl_ptr __T656436344; auto an_ETS_flag_set *__T656436992; auto void *__T656437728;
auto void *__13678_12_object_address;

__13678_12_object_address = ((void *)(_ZN28_INTERNAL_7_throw_c_721f9a2e17eh_alloc_on_stackEm(__13670_35_size)));
(((__T656436344 = __13669_56_type_info) , (__T656436992 = __13671_31_ptr_flags)) , (__T656437728 = __13678_12_object_address)) , (_ZN28_INTERNAL_7_throw_c_721f9a2e16push_throw_stackEPKSt9type_infoPFvPvEjPjPciS3_iiP19a_throw_stack_entry(__T656436344, ((a_destructor_ptr)0), 0U, __T656436992, ((
# 1778
an_access_flag_string)0), 0, __T656437728, 0, 0, ((a_throw_stack_entry_ptr)0)));
# 1784
return __13678_12_object_address;
}




void *__throw_setup( a_type_info_impl_ptr __13693_52_type_info, 
a_sizeof_t __13694_33_size, 
an_ETS_flag_set __13695_28_ets_flags)
# 1798
{ auto a_type_info_impl_ptr __T656446640; auto a_destructor_ptr __T656447288; auto an_ETS_flag_set __T656448024; auto void *__T656448760;
auto void *__13702_12_object_address;
auto a_destructor_ptr __13703_21_destructor;
# 1808
__13703_21_destructor = ((a_destructor_ptr)0);

__13702_12_object_address = ((void *)(_ZN28_INTERNAL_7_throw_c_721f9a2e17eh_alloc_on_stackEm(__13694_33_size)));
((((__T656446640 = __13693_52_type_info) , (__T656447288 = __13703_21_destructor)) , (__T656448024 = __13695_28_ets_flags)) , (__T656448760 = __13702_12_object_address)) , (_ZN28_INTERNAL_7_throw_c_721f9a2e16push_throw_stackEPKSt9type_infoPFvPvEjPjPciS3_iiP19a_throw_stack_entry(__T656446640, 
# 1811
__T656447288, __T656448024, ((an_ETS_flag_set *)0), ((an_access_flag_string)0), 0, __T656448760, 0, 0, ((a_throw_stack_entry_ptr)0)));
# 1817
return __13702_12_object_address;
}



void *__throw_setup_dtor( a_type_info_impl_ptr __13725_57_type_info, 
a_sizeof_t __13726_35_size, 
int __13727_20_ets_flags, 
a_destructor_ptr __13728_24_destructor)
# 1834
{ auto a_type_info_impl_ptr __T656456680; auto a_destructor_ptr __T656457328; auto an_ETS_flag_set __T656458064; auto void *__T656458800;
auto void *__13738_12_object_address;

__13738_12_object_address = ((void *)(_ZN28_INTERNAL_7_throw_c_721f9a2e17eh_alloc_on_stackEm(__13726_35_size)));
((((__T656456680 = __13725_57_type_info) , (__T656457328 = __13728_24_destructor)) , (__T656458064 = ((an_ETS_flag_set)__13727_20_ets_flags))) , (__T656458800 = __13738_12_object_address)) , (_ZN28_INTERNAL_7_throw_c_721f9a2e16push_throw_stackEPKSt9type_infoPFvPvEjPjPciS3_iiP19a_throw_stack_entry(
# 1838
__T656456680, __T656457328, __T656458064, ((an_ETS_flag_set *)0), ((an_access_flag_string)0), 0, __T656458800, 0, 0, ((a_throw_stack_entry_ptr)0)));
# 1844
return __13738_12_object_address;
}
# 1875
void __free_thrown_object(void)
# 1882
{
# 1888
if (!(curr_throw_stack_entry != ((a_throw_stack_entry_ptr)0))) { { fprintf(stderr, ((const char *)"Assertion failed in file \"%s\", line %d\n"), ((const char *)("lib_src/throw.c")), 1888); abort(); } } ;
_ZN28_INTERNAL_7_throw_c_721f9a2e21destroy_thrown_objectEP19a_throw_stack_entry(curr_throw_stack_entry);
# 1898
while ((curr_throw_stack_entry != ((a_throw_stack_entry_ptr)0)) && (curr_throw_stack_entry->discard_entry))
{
auto a_throw_stack_entry_ptr __13803_29_tsep;
auto a_boolean __13804_17_is_rethrow;
auto void *__13805_13_object_address;
# 1900
__13803_29_tsep = curr_throw_stack_entry;
__13804_17_is_rethrow = ((a_boolean)(__13803_29_tsep->is_rethrow));
__13805_13_object_address = (__13803_29_tsep->object_address);


if (!((__13804_17_is_rethrow) || (__13803_29_tsep->dtor_called))) { { fprintf(stderr, ((const char *)"Assertion failed in file \"%s\", line %d\n"), ((const char *)("lib_src/throw.c")), 1905); abort(); } } ;

curr_throw_stack_entry = (__13803_29_tsep->next);



_ZN28_INTERNAL_7_throw_c_721f9a2e16eh_free_on_stackEPv(((void *)__13803_29_tsep));
if (!(__13804_17_is_rethrow)) {

_ZN28_INTERNAL_7_throw_c_721f9a2e16eh_free_on_stackEPv(__13805_13_object_address);
}
} 
# 1922
}


void __destroy_exception_object(void)
# 1934
{
auto a_throw_stack_entry_ptr __13838_27_tsep;
# 1942
for (__13838_27_tsep = curr_throw_stack_entry; __13838_27_tsep != ((a_throw_stack_entry_ptr)0); __13838_27_tsep = (__13838_27_tsep->next)) {
if (((__13838_27_tsep->in_handler) && (!(__13838_27_tsep->dtor_called))) && (!(__13838_27_tsep->discard_entry))) { goto __T656478344; }
} __T656478344:;
if (!(__13838_27_tsep != ((a_throw_stack_entry_ptr)0))) { { fprintf(stderr, ((const char *)"Assertion failed in file \"%s\", line %d\n"), ((const char *)("lib_src/throw.c")), 1945); abort(); } } ;



if (__13838_27_tsep == curr_throw_stack_entry) {
__free_thrown_object();
} else  {
_ZN28_INTERNAL_7_throw_c_721f9a2e21destroy_thrown_objectEP19a_throw_stack_entry(__13838_27_tsep);
} 
}


void __eh_exit_processing(void)
# 1963
{


__curr_eh_stack_entry = ((an_eh_stack_entry_ptr)0); 
}


void __suppress_optim_on_vars_in_try(void)
# 1979
{
{ fprintf(stderr, ((const char *)"Assertion failed in file \"%s\", line %d\n"), ((const char *)("lib_src/throw.c")), 1980); abort(); } ; 
}

an_eh_stack_entry_ptr __get_curr_eh_stack_entry(void)



{
return __curr_eh_stack_entry;
}


void __type_of_thrown_object( a_type_info_impl_ptr *__13895_61_type, 
an_ETS_flag_set *__13896_29_flags, 
an_ETS_flag_set **__13897_30_ptr_flags)




{
if (!(curr_throw_stack_entry != ((a_throw_stack_entry_ptr)0))) { { fprintf(stderr, ((const char *)"Assertion failed in file \"%s\", line %d\n"), ((const char *)("lib_src/throw.c")), 2000); abort(); } } ;
(*__13895_61_type) = (curr_throw_stack_entry->type_info);
(*__13896_29_flags) = (curr_throw_stack_entry->flags);
(*__13897_30_ptr_flags) = (curr_throw_stack_entry->ptr_flags); 
}


a_boolean __can_throw_type( a_type_info_impl_ptr __13910_58_type, 
an_ETS_flag_set __13911_26_flags, 
an_ETS_flag_set *__13912_27_ptr_flags)
# 2016
{
auto a_boolean __13920_14_result = 0;
auto an_eh_stack_entry_ptr __13921_25_ehsep;

__13921_25_ehsep = __curr_eh_stack_entry;
for (__13921_25_ehsep = __curr_eh_stack_entry; __13921_25_ehsep != ((an_eh_stack_entry_ptr)0); __13921_25_ehsep = (__13921_25_ehsep->next)) {
if (((int)(__13921_25_ehsep->kind)) == 2) { goto __T656502576; }
} __T656502576:;
if (!(__13921_25_ehsep != ((an_eh_stack_entry_ptr)0))) { { fprintf(stderr, ((const char *)"Assertion failed in file \"%s\", line %d\n"), ((const char *)("lib_src/throw.c")), 2024); abort(); } } ;
if (((__13921_25_ehsep->variant).throw_specification) != ((an_exception_type_specification_ptr)0)) { auto an_exception_type_specification_ptr __T656513952; auto a_type_info_impl_ptr __T656514600; auto an_ETS_flag_set __T656515336; auto an_ETS_flag_set *__T656516072;
auto an_exception_type_specification_ptr __13929_41_dummy_etsp;
auto int __13930_13_catch_pos;
__13930_13_catch_pos = (((((__T656513952 = ((__13921_25_ehsep->variant).throw_specification)) , (__T656514600 = __13910_58_type)) , (__T656515336 = __13911_26_flags)) , (__T656516072 = __13912_27_ptr_flags)) , (
# 2028
_ZN28_INTERNAL_7_throw_c_721f9a2e35check_exception_type_specificationsEP31an_exception_type_specificationPKSt9type_infojPjPciPPvPS1_Pi(__T656513952, __T656514600, __T656515336, __T656516072, ((an_access_flag_string)0), 0, ((void **)0), (&__13929_41_dummy_etsp), ((a_boolean *)0))));
# 2034
if (__13930_13_catch_pos != 0) { __13920_14_result = 1; }
}
return __13920_14_result;
}
