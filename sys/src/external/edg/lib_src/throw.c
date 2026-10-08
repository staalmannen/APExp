/* Translated by the Edison Design Group C++/C front end (version 7.0) */
/* Thu Oct  8 07:53:17 2026 */
extern int __EDGCPFE__7_0;
void *memcpy(void *,const void *,unsigned long long);
void *memset(void *,int,unsigned long long);

#line 1 "lib_src/throw.c"
struct __C1; struct __EDG_type_info; struct __class_type_info; struct __si_class_type_info; struct __fundamental_type_info;
#line 56 "ape-sys/_iofile.h"
struct _IO_FILE;
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
#line 25 "lib_src/throw.c"
struct a_dummy_class;




struct a_throw_stack_entry;
#line 157
struct a_mem_block_descr;
#line 177
struct a_mem_allocation;
#line 251
union _ZN28_INTERNAL_7_throw_c_721f9a2eUt_E;
#line 32 "include_c++/typeinfo.stdh"
struct _ZSt9type_info; struct __C1 { void (*f)(); long long d;}; struct __EDG_type_info { const long long *__vptr; const char *__name;}; struct __class_type_info { struct __EDG_type_info base;}; struct __si_class_type_info { struct __class_type_info base; const struct __class_type_info *base_type;}; 
#line 32
struct __fundamental_type_info { struct __EDG_type_info base;};
#line 66 "lib_src/basics.h"
typedef unsigned char a_byte;


typedef int a_boolean;
typedef a_byte a_byte_boolean;
#line 10 "ape-arch/stddef_arch.h"
typedef unsigned long long size_t;
#line 21 "ape-sys/stdio.h"
typedef struct _IO_FILE FILE;
#line 101 "lib_src/runtime.h"
typedef size_t a_sizeof_t;
#line 115
typedef void (*a_void_function_ptr)(void);
#line 127
typedef void (*a_destructor_ptr)(void *);
#line 136
typedef void (*a_destructor_with_vtable_param_ptr)(void *, void *);
#line 155
typedef void (*a_delete_ptr)(void *);
#line 164
typedef void (*a_two_operand_delete_ptr)(void *, a_sizeof_t);
#line 228
typedef unsigned long long an_ia64_guard;


typedef an_ia64_guard *an_ia64_guard_ptr;
#line 93 "lib_src/rtti.h"
typedef const struct _ZSt9type_info *a_type_info_impl_ptr;
#line 178
typedef char *an_access_flag_string;
#line 48 "lib_src/vec_newdel.h"
typedef struct an_array_alloc_eh_info *an_array_alloc_eh_info_ptr;
#line 10 "ape-sys/setjmp.h"
typedef int jmp_buf[20];
#line 31 "lib_src/eh.h"
typedef long an_element_count;
#line 37
typedef int a_conditional_flag;



typedef unsigned short an_object_handle;


typedef void *an_object_ptr;


typedef unsigned short a_region_number;


typedef unsigned an_ETS_flag_set;




typedef a_byte a_region_descr_flag_set;
#line 163
typedef struct an_eh_array_supplement *an_eh_array_supplement_ptr;
struct an_eh_array_supplement {

an_object_handle handle;


a_sizeof_t element_size;

an_element_count array_size;char __dummy[4];};
#line 177
typedef struct an_eh_array_supplement an_eh_array_supplement;



typedef struct an_eh_region_descr *an_eh_region_descr_ptr;
struct an_eh_region_descr {

a_void_function_ptr destructor_or_delete_routine;
#line 190
an_object_handle handle;
#line 200
a_region_number index_of_next_region;
#line 206
a_region_descr_flag_set flags;char __dummy[3];};



typedef struct an_eh_region_descr an_eh_region_descr;
#line 309
typedef struct an_exception_type_specification *an_exception_type_specification_ptr;
struct an_exception_type_specification {

a_type_info_impl_ptr type_info;
#line 318
an_ETS_flag_set flags;
#line 324
an_ETS_flag_set *ptr_flags;};
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
#line 29 "lib_src/throw.c"
typedef struct a_throw_stack_entry *a_throw_stack_entry_ptr;
struct a_throw_stack_entry {

a_throw_stack_entry_ptr next;


a_type_info_impl_ptr type_info;


a_destructor_ptr destructor;


an_ETS_flag_set flags;



an_ETS_flag_set *ptr_flags;
#line 52
an_access_flag_string access_flags;




void *object_address;


void *pointer_buffer;
#line 71
long long ptr_to_data_member_buffer;
#line 78
struct __C1 ptr_to_member_function_buffer;
#line 85
an_eh_stack_entry_ptr nearest_enclosing_try_block;
#line 91
a_throw_stack_entry_ptr primary_entry;


unsigned long use_count;




a_byte_boolean is_rethrow;




a_byte_boolean is_internal;



a_byte_boolean discard_entry;
#line 115
a_byte_boolean dtor_called;




a_byte_boolean in_handler;




a_byte_boolean object_evaluation_complete;
#line 132
a_byte_boolean object_copy_complete;
#line 138
a_byte_boolean use_access_flags;
#line 147
an_eh_stack_entry throw_marker;};
#line 156
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
#line 195
typedef void (*a_destroy_exception_object_ptr)(void);
#line 251
union _ZN28_INTERNAL_7_throw_c_721f9a2eUt_E {
char memory[8192];




double dummy;};
#line 35 "include_c++/exception.stdh"
typedef _Bool _ZSt6__bool;
#line 32 "include_c++/typeinfo.stdh"
struct _ZSt9type_info { const long long *__vptr;
#line 50
const char *__type_name;};
#line 128 "include_c++/cxxabi.h"
typedef void _ZN10__cxxabiv123__ctor_dtor_return_typeE;
#line 136
typedef unsigned long long _ZN10__cxxabiv121__guard_variable_typeE;
#line 66 "ape-sys/stdlib.h"
extern void free(void *);
extern void *malloc(size_t);

extern void abort(void);
#line 71 "ape-sys/stdio.h"
extern int fprintf(FILE *, const char *, ...);
#line 143 "include_c++/cxxabi.h"
extern void __cxa_guard_abort(_ZN10__cxxabiv121__guard_variable_typeE *);
#line 162
extern void __cxa_vec_dtor(void *, size_t, size_t, _ZN10__cxxabiv123__ctor_dtor_return_typeE (*)(void *));
#line 188
extern void __cxa_bad_typeid(void);
#line 196 "lib_src/rtti.h"
extern a_boolean __derived_to_base_conversion(void **p_ptr, void **p_new_ptr, a_type_info_impl_ptr class_info, a_type_info_impl_ptr base_info, an_access_flag_string *access_flags, a_boolean use_access_flags);
#line 18 "ape-sys/setjmp.h"
extern void longjmp(int *, int);
#line 435 "lib_src/eh.h"
extern void __call_terminate(void);
#line 443
extern void __call_unexpected(void);
#line 450
extern void __cleanup_vec_new_or_delete(an_eh_stack_entry_ptr ehsep);
#line 295 "lib_src/throw.c"
static void *_ZN28_INTERNAL_7_throw_c_721f9a2e13eh_get_memoryEy(a_sizeof_t size);
#line 313
static void _ZN28_INTERNAL_7_throw_c_721f9a2e14eh_free_memoryEPv(void *ptr);
#line 324
static void _ZN28_INTERNAL_7_throw_c_721f9a2e20mem_block_descr_initEP17a_mem_block_descr(a_mem_block_descr_ptr mbdp);
#line 337
static void _ZN28_INTERNAL_7_throw_c_721f9a2e25init_eh_memory_managementEv(void);
#line 360
static void *_ZN28_INTERNAL_7_throw_c_721f9a2e18alloc_in_mem_blockEyPP16a_mem_allocation(a_sizeof_t size, a_mem_allocation_ptr *map);
#line 392
static void _ZN28_INTERNAL_7_throw_c_721f9a2e19alloc_new_mem_blockEy(a_sizeof_t size);
#line 432
static void *_ZN28_INTERNAL_7_throw_c_721f9a2e17eh_alloc_on_stackEy(a_sizeof_t size);
#line 471
static void _ZN28_INTERNAL_7_throw_c_721f9a2e17free_in_mem_blockEPv(void *ptr);
#line 489
static void _ZN28_INTERNAL_7_throw_c_721f9a2e16eh_free_on_stackEPv(void *ptr);
#line 665
static void _ZN28_INTERNAL_7_throw_c_721f9a2e7cleanupEP17an_eh_stack_entrytt(an_eh_stack_entry_ptr ehsep, a_region_number region, a_region_number stop_at_region);
#line 901
static a_boolean _ZN28_INTERNAL_7_throw_c_721f9a2e35check_pointer_levels_and_qualifiersEP31an_exception_type_specificationPj(an_exception_type_specification_ptr etsp, an_ETS_flag_set *ptr_flags);
#line 958
static int _ZN28_INTERNAL_7_throw_c_721f9a2e35check_exception_type_specificationsEP31an_exception_type_specificationPKSt9type_infojPjPciPPvPS1_Pi(an_exception_type_specification_ptr etsp, a_type_info_impl_ptr type_info, an_ETS_flag_set flags, an_ETS_flag_set *ptr_flags, an_access_flag_string 
#line 958
access_flags, a_boolean use_access_flags, void **object_ptr, an_exception_type_specification_ptr *etsp_found, a_boolean *nullptr_conv_needed);
#line 1143
static void _ZN28_INTERNAL_7_throw_c_721f9a2e21destroy_thrown_objectEP19a_throw_stack_entry(a_throw_stack_entry_ptr tsep);
#line 1203
extern void __exception_started(void);
#line 1221
extern void __exception_caught(void);
#line 1238
extern void __throw(void);
#line 1626
static void _ZN28_INTERNAL_7_throw_c_721f9a2e16push_throw_stackEPKSt9type_infoPFvPvEjPjPciS3_iiP19a_throw_stack_entry(a_type_info_impl_ptr type_info, a_destructor_ptr destructor, an_ETS_flag_set flags, an_ETS_flag_set *ptr_flags, an_access_flag_string access_flags, a_boolean use_access_flags, void *
#line 1626
object_address, a_boolean is_rethrow, a_boolean is_internal, a_throw_stack_entry_ptr primary_entry);
#line 1699
static void _ZN28_INTERNAL_7_throw_c_721f9a2e12rethrow_fullEi(a_boolean is_internal);
#line 1729
extern void __rethrow(void);
#line 1739
extern void __internal_rethrow(void);
#line 1766
extern void *__throw_setup_ptr(a_type_info_impl_ptr type_info, a_sizeof_t size, an_ETS_flag_set *ptr_flags);
#line 1790
extern void *__throw_setup(a_type_info_impl_ptr type_info, a_sizeof_t size, an_ETS_flag_set ets_flags);
#line 1822
extern void *__throw_setup_dtor(a_type_info_impl_ptr type_info, a_sizeof_t size, int ets_flags, a_destructor_ptr destructor);
#line 1875
extern void __free_thrown_object(void);
#line 1925
extern void __destroy_exception_object(void);
#line 1957
extern void __eh_exit_processing(void);
#line 1970
extern void __suppress_optim_on_vars_in_try(void);
#line 1983
extern an_eh_stack_entry_ptr __get_curr_eh_stack_entry(void);
#line 1992
extern void __type_of_thrown_object(a_type_info_impl_ptr *type, an_ETS_flag_set *flags, an_ETS_flag_set **ptr_flags);
#line 2007
extern a_boolean __can_throw_type(a_type_info_impl_ptr type, an_ETS_flag_set flags, an_ETS_flag_set *ptr_flags);
#line 35 "include_c++/typeinfo.stdh"
extern _ZSt6__bool _ZNKSt9type_infoeqERKS_(const struct _ZSt9type_info *const, const struct _ZSt9type_info *);


extern const char *_ZNKSt9type_info4nameEv(const struct _ZSt9type_info *const);
#line 53 "ape-sys/stdio.h"
extern FILE *stderr;
#line 419 "lib_src/eh.h"
extern a_region_number __eh_curr_region;




extern an_eh_stack_entry_ptr __curr_eh_stack_entry;


extern int __catch_clause_number;



extern void *__caught_object_address;
#line 204 "lib_src/throw.c"
char __TID_v = 0;




char __TID_n = 0;
#line 231
static a_throw_stack_entry_ptr curr_throw_stack_entry;




static a_mem_block_descr_ptr curr_mem_block_descr;




static a_mem_allocation_ptr mem_allocation_stack;




static a_mem_block_descr initial_mem_block_descr;
#line 261
static union _ZN28_INTERNAL_7_throw_c_721f9a2eUt_E initial_mem_block; extern  /* COMDAT group: _ZTIDn */ const struct __fundamental_type_info _ZTIDn; extern const long long _ZTVN10__cxxabiv123__fundamental_type_infoE[4]; extern  /* COMDAT group: _ZTSDn */ const char _ZTSDn[3]; extern  /* */
#line 261
/*  COMDAT group: _ZTIv */ const struct __fundamental_type_info _ZTIv; extern  /* COMDAT group: _ZTSv */ const char _ZTSv[2]; extern const struct __si_class_type_info _ZTIN10__cxxabiv120__si_class_type_infoE; extern const struct __si_class_type_info _ZTIN10__cxxabiv121__vmi_class_type_infoE;
#line 231
static a_throw_stack_entry_ptr curr_throw_stack_entry = ((a_throw_stack_entry_ptr)0);




static a_mem_block_descr_ptr curr_mem_block_descr = ((a_mem_block_descr_ptr)0);




static a_mem_allocation_ptr mem_allocation_stack = ((a_mem_allocation_ptr)0);  /* COMDAT group: _ZTIDn */ const struct __fundamental_type_info _ZTIDn = {{(_ZTVN10__cxxabiv123__fundamental_type_infoE + 2),_ZTSDn}};  /* COMDAT group: _ZTSDn */ const char _ZTSDn[3] = "Dn";  /* COMDAT group: _ZTIv */ 
#line 241
const struct __fundamental_type_info _ZTIv = {{(_ZTVN10__cxxabiv123__fundamental_type_infoE + 2),_ZTSv}};  /* COMDAT group: _ZTSv */ const char _ZTSv[2] = "v";
#line 295
static void *_ZN28_INTERNAL_7_throw_c_721f9a2e13eh_get_memoryEy( a_sizeof_t __4048_39_size)
#line 301
{
auto void *__4055_10_mem_block;

__4055_10_mem_block = (malloc(__4048_39_size));

if (__4055_10_mem_block == ((void *)0)) {
__call_terminate();
}
return __4055_10_mem_block;
}


static void _ZN28_INTERNAL_7_throw_c_721f9a2e14eh_free_memoryEPv( void *__4066_34_ptr)
#line 319
{
free(__4066_34_ptr); 
}


static void _ZN28_INTERNAL_7_throw_c_721f9a2e20mem_block_descr_initEP17a_mem_block_descr( a_mem_block_descr_ptr __4077_56_mbdp)



{
(__4077_56_mbdp->next) = ((a_mem_block_descr_ptr)0);
(__4077_56_mbdp->addr) = ((void *)0);
(__4077_56_mbdp->size) = 0ULL;
(__4077_56_mbdp->used) = 0ULL;
(__4077_56_mbdp->dynamically_allocated) = ((a_byte_boolean)0U); 
}


static void _ZN28_INTERNAL_7_throw_c_721f9a2e25init_eh_memory_managementEv(void)



{

_ZN28_INTERNAL_7_throw_c_721f9a2e20mem_block_descr_initEP17a_mem_block_descr((&initial_mem_block_descr));
(initial_mem_block_descr.addr) = ((void *)(&initial_mem_block));
(initial_mem_block_descr.size) = 8192ULL;
(initial_mem_block_descr.used) = 0ULL;
(initial_mem_block_descr.dynamically_allocated) = ((a_byte_boolean)0U);
curr_mem_block_descr = (&initial_mem_block_descr); 
}
#line 360
static void *_ZN28_INTERNAL_7_throw_c_721f9a2e18alloc_in_mem_blockEyPP16a_mem_allocation( a_sizeof_t __4113_50_size, 
a_mem_allocation_ptr *__4114_34_map)
#line 367
{
auto void *__4121_11_ptr;
auto int __4122_9_used;



__4122_9_used = ((int)(curr_mem_block_descr->used));
(*__4114_34_map) = ((a_mem_allocation_ptr)((void *)(((char *)(curr_mem_block_descr->addr)) + __4122_9_used)));
__4122_9_used += 32ULL;
__4121_11_ptr = ((void *)((void *)(((char *)(curr_mem_block_descr->addr)) + __4122_9_used)));
__4122_9_used += __4113_50_size;
(curr_mem_block_descr->used) = ((a_sizeof_t)__4122_9_used);

((*__4114_34_map)->next) = mem_allocation_stack;
((*__4114_34_map)->addr) = __4121_11_ptr;
mem_allocation_stack = (*__4114_34_map);

((*__4114_34_map)->alloc_size) = __4113_50_size;
((*__4114_34_map)->is_mem_block_descr_allocation) = ((a_byte_boolean)0U);
if (!((curr_mem_block_descr->used) <= (curr_mem_block_descr->size))) { { fprintf(stderr, ((const char *)"Assertion failed in file \"%s\", line %d\n"), ((const char *)("lib_src/throw.c")), 386); abort(); } } ;
if (!((__4113_50_size % 8ULL) == 0ULL)) { { fprintf(stderr, ((const char *)"Assertion failed in file \"%s\", line %d\n"), ((const char *)("lib_src/throw.c")), 387); abort(); } } ;
return __4121_11_ptr;
}


static void _ZN28_INTERNAL_7_throw_c_721f9a2e19alloc_new_mem_blockEy( a_sizeof_t __4145_44_size)
#line 399
{
auto void *__4153_11_mem_block;
auto a_mem_allocation_ptr __4154_24_map;
auto a_mem_block_descr_ptr __4155_25_mpdp;
auto a_sizeof_t __4156_15_new_size;
#line 409
__4156_15_new_size = (((__4145_44_size / 8192ULL) + 1ULL) * 8192ULL);

if ((__4156_15_new_size - __4145_44_size) < 4096ULL) {
__4156_15_new_size += 8192ULL;
}
__4145_44_size = __4156_15_new_size;


__4155_25_mpdp = ((a_mem_block_descr_ptr)(_ZN28_INTERNAL_7_throw_c_721f9a2e18alloc_in_mem_blockEyPP16a_mem_allocation(40ULL, (&__4154_24_map))));

(__4154_24_map->is_mem_block_descr_allocation) = ((a_byte_boolean)1U);
__4153_11_mem_block = (_ZN28_INTERNAL_7_throw_c_721f9a2e13eh_get_memoryEy(__4145_44_size));

(__4155_25_mpdp->next) = curr_mem_block_descr;
curr_mem_block_descr = __4155_25_mpdp;

(__4155_25_mpdp->addr) = __4153_11_mem_block;
(__4155_25_mpdp->size) = __4145_44_size;
(__4155_25_mpdp->used) = 0ULL;
(__4155_25_mpdp->dynamically_allocated) = ((a_byte_boolean)1U); 
}


static void *_ZN28_INTERNAL_7_throw_c_721f9a2e17eh_alloc_on_stackEy( a_sizeof_t __4185_43_size)



{
auto a_mem_allocation_ptr __4190_24_map;
auto int __4191_9_needed_for_alignment;
auto void *__4192_11_ptr;
auto a_sizeof_t __4193_15_alloc_size;



if (curr_mem_block_descr == ((a_mem_block_descr_ptr)0)) {
_ZN28_INTERNAL_7_throw_c_721f9a2e25init_eh_memory_managementEv();
}


__4191_9_needed_for_alignment = ((int)(((__4185_43_size % 8ULL) == 0ULL) ? 0ULL : (8ULL - (__4185_43_size % 8ULL))));




__4193_15_alloc_size = (__4185_43_size + ((unsigned long long)__4191_9_needed_for_alignment));
if ((((__4193_15_alloc_size + 32ULL) + (curr_mem_block_descr->used)) + 72ULL) > (curr_mem_block_descr->size))

{
_ZN28_INTERNAL_7_throw_c_721f9a2e19alloc_new_mem_blockEy(__4193_15_alloc_size);
}
__4192_11_ptr = (_ZN28_INTERNAL_7_throw_c_721f9a2e18alloc_in_mem_blockEyPP16a_mem_allocation(__4193_15_alloc_size, (&__4190_24_map)));
#line 467
return __4192_11_ptr;
}


static void _ZN28_INTERNAL_7_throw_c_721f9a2e17free_in_mem_blockEPv( void *__4224_37_ptr)



{
auto a_mem_allocation_ptr __4229_24_map;
auto int __4230_9_used;

__4229_24_map = mem_allocation_stack;
mem_allocation_stack = (__4229_24_map->next);
if (!((__4229_24_map->addr) == __4224_37_ptr)) { { fprintf(stderr, ((const char *)"Assertion failed in file \"%s\", line %d\n"), ((const char *)("lib_src/throw.c")), 481); abort(); } } ;
__4230_9_used = ((int)(curr_mem_block_descr->used));
__4230_9_used -= (__4229_24_map->alloc_size);
__4230_9_used -= 32ULL;
(curr_mem_block_descr->used) = ((a_sizeof_t)__4230_9_used); 
}


static void _ZN28_INTERNAL_7_throw_c_721f9a2e16eh_free_on_stackEPv( void *__4242_36_ptr)




{

_ZN28_INTERNAL_7_throw_c_721f9a2e17free_in_mem_blockEPv(__4242_36_ptr);

if ((curr_mem_block_descr->used) == 0ULL) {
if ((curr_mem_block_descr->next) != ((a_mem_block_descr_ptr)0)) {

auto a_mem_block_descr_ptr __4254_29_mpdp_to_free;
__4254_29_mpdp_to_free = curr_mem_block_descr;
curr_mem_block_descr = (__4254_29_mpdp_to_free->next);


if (__4254_29_mpdp_to_free->dynamically_allocated) {

_ZN28_INTERNAL_7_throw_c_721f9a2e14eh_free_memoryEPv((__4254_29_mpdp_to_free->addr));
}

_ZN28_INTERNAL_7_throw_c_721f9a2e17free_in_mem_blockEPv(((void *)__4254_29_mpdp_to_free));
}
} 
}
#line 665
static void _ZN28_INTERNAL_7_throw_c_721f9a2e7cleanupEP17an_eh_stack_entrytt( an_eh_stack_entry_ptr __4418_43_ehsep, 
a_region_number __4419_43_region, 
a_region_number __4420_25_stop_at_region)
#line 676
{
auto an_object_ptr *__4430_34_obj_addr_array;
auto an_eh_region_descr_ptr __4431_26_ehrdp;
#line 686
__4430_34_obj_addr_array = (((__4418_43_ehsep->variant).function).object_address_table);
for (; ((int)__4419_43_region) != ((int)__4420_25_stop_at_region); __4419_43_region = (__4431_26_ehrdp->index_of_next_region)) { {
auto an_object_ptr __4441_27_obj_addr = ((an_object_ptr)0);
auto a_conditional_flag *__4442_33_flag_addr = ((a_conditional_flag *)0);
auto char *__4443_13_temp_addr;
auto a_region_descr_flag_set __4444_33_flags;
auto an_eh_array_supplement_ptr __4445_32_ehasp = ((an_eh_array_supplement_ptr)0);
auto void *__4446_13_vtbl_ptr;
auto a_boolean __4447_17_has_vtbl_ptr = 0;

auto a_destroy_exception_object_ptr __4449_5_potential_destroy_exception_object_ptr;

__4431_26_ehrdp = ((((__4418_43_ehsep->variant).function).regions) + __4419_43_region);
#line 710
__4449_5_potential_destroy_exception_object_ptr = ((a_destroy_exception_object_ptr)(__4431_26_ehrdp->destructor_or_delete_routine));

if (__4449_5_potential_destroy_exception_object_ptr == (&__destroy_exception_object))
{
__destroy_exception_object();
goto __T1021330024;
}
__4444_33_flags = (__4431_26_ehrdp->flags);
if (((int)__4444_33_flags) & 0x2) {
#line 727
__4442_33_flag_addr = ((a_conditional_flag *)(*(__4430_34_obj_addr_array + ((__4431_26_ehrdp + 1)->handle))));
#line 734
if (!(*__4442_33_flag_addr)) { goto __T1021330024; }
}
if (((((int)__4444_33_flags) & 0x20) != 0) && (((((int)__4444_33_flags) & 0x40) != 0) && ((((int)__4444_33_flags) & 0x8) == 0)))
{
#line 745
auto an_eh_region_descr_ptr __4498_30_vtbl_ehrdp;
#line 744
__4447_17_has_vtbl_ptr = 1;

__4498_30_vtbl_ehrdp = (__4431_26_ehrdp + 1);
if (__4442_33_flag_addr != ((a_conditional_flag *)0)) { __4498_30_vtbl_ehrdp++; }




__4446_13_vtbl_ptr = (*((void **)(__4430_34_obj_addr_array + (__4498_30_vtbl_ehrdp->handle))));
if (((int)(__4498_30_vtbl_ehrdp->flags)) & 0x1) {



__4443_13_temp_addr = ((char *)(*((void **)__4446_13_vtbl_ptr)));
__4446_13_vtbl_ptr = ((void *)__4443_13_temp_addr);
}
#line 765
}
#line 772
if (!(__4430_34_obj_addr_array != ((an_object_ptr *)0))) { { fprintf(stderr, ((const char *)"Assertion failed in file \"%s\", line %d\n"), ((const char *)("lib_src/throw.c")), 772); abort(); } } ;
if (((int)__4444_33_flags) & 0x8) {

__4445_32_ehasp = ((((__4418_43_ehsep->variant).function).array_table) + (__4431_26_ehrdp->handle));
__4441_27_obj_addr = (*(__4430_34_obj_addr_array + (__4445_32_ehasp->handle)));
} else  {

__4441_27_obj_addr = (*(__4430_34_obj_addr_array + (__4431_26_ehrdp->handle)));
}
if (((int)__4444_33_flags) & 0x1) {



__4443_13_temp_addr = ((char *)(*((void **)__4441_27_obj_addr)));
__4441_27_obj_addr = ((void *)__4443_13_temp_addr);
}
#line 794
if ((((int)__4444_33_flags) & 0x80) != 0) {
#line 803
__4442_33_flag_addr = ((a_conditional_flag *)__4441_27_obj_addr);
#line 810
__cxa_guard_abort(((an_ia64_guard_ptr)__4442_33_flag_addr));



} else  { if (!(((int)__4444_33_flags) & 0x4)) {


auto a_destructor_ptr __4570_24_dtor_ptr;
__4570_24_dtor_ptr = ((a_destructor_ptr)(__4431_26_ehrdp->destructor_or_delete_routine));
if (((int)__4444_33_flags) & 0x8) {




auto a_boolean __4577_20_is_vla; __4577_20_is_vla = ((a_boolean)((((int)__4444_33_flags) & 0x40) != 0));
if (__4570_24_dtor_ptr != ((a_destructor_ptr)0)) { auto an_object_ptr __T1021376168; auto size_t __T1021376816; auto a_sizeof_t __T1021377552; auto a_destructor_ptr __T1021378288;
auto an_element_count __4579_28_elements; __4579_28_elements = (__4445_32_ehasp->array_size);
if (__4577_20_is_vla) {


auto a_sizeof_t *__4583_26_element_addr;
__4583_26_element_addr = ((a_sizeof_t *)(__4430_34_obj_addr_array[((__4431_26_ehrdp + 1)->handle)]));
__4579_28_elements = ((an_element_count)(*__4583_26_element_addr));
}
#line 839
((((__T1021376168 = __4441_27_obj_addr) , (__T1021376816 = ((size_t)__4579_28_elements))) , (__T1021377552 = (__4445_32_ehasp->element_size))) , (__T1021378288 = __4570_24_dtor_ptr)) , (__cxa_vec_dtor(__T1021376168, __T1021376816, __T1021377552, __T1021378288));


}
} else  { if (__4447_17_has_vtbl_ptr) { auto an_object_ptr __T1021379200; auto void *__T1021379848;
#line 852
auto a_destructor_with_vtable_param_ptr __4605_44_dtor_with_vtable;
__4605_44_dtor_with_vtable = ((a_destructor_with_vtable_param_ptr)__4570_24_dtor_ptr);
((__T1021379200 = __4441_27_obj_addr) , (__T1021379848 = __4446_13_vtbl_ptr)) , (__4605_44_dtor_with_vtable(__T1021379200, __T1021379848));
} else  {
#line 867
__4570_24_dtor_ptr(__4441_27_obj_addr);

} }
} else  {


if (__4441_27_obj_addr != ((an_object_ptr)0)) {
if (((int)__4444_33_flags) & 0x8) { auto an_object_ptr __T1021380760; auto a_sizeof_t __T1021381408;


auto a_two_operand_delete_ptr __4630_36_delete_ptr;
__4630_36_delete_ptr = ((a_two_operand_delete_ptr)(__4431_26_ehrdp->destructor_or_delete_routine));

((__T1021380760 = __4441_27_obj_addr) , (__T1021381408 = (__4445_32_ehasp->element_size))) , (__4630_36_delete_ptr(__T1021380760, __T1021381408));
} else  {
auto a_delete_ptr __4635_24_delete_ptr;
__4635_24_delete_ptr = ((a_delete_ptr)(__4431_26_ehrdp->destructor_or_delete_routine));
__4635_24_delete_ptr(__4441_27_obj_addr);
}
}
} }
} __T1021330024:; } 
}
#line 901
static a_boolean _ZN28_INTERNAL_7_throw_c_721f9a2e35check_pointer_levels_and_qualifiersEP31an_exception_type_specificationPj(
an_exception_type_specification_ptr __4655_40_etsp, 
an_ETS_flag_set *__4656_24_ptr_flags)
#line 914
{
auto a_boolean __4668_14_okay;
auto a_boolean __4669_14_previous_qualifiers_include_const = 1;
auto an_ETS_flag_set *__4670_20_source_ptr_flags;
auto an_ETS_flag_set *__4671_20_dest_ptr_flags;

__4671_20_dest_ptr_flags = (__4655_40_etsp->ptr_flags);
__4670_20_source_ptr_flags = __4656_24_ptr_flags;
for (__4668_14_okay = 1; __4668_14_okay == 1; ) {
auto an_ETS_flag_set __4676_21_dest_qualifiers;
auto an_ETS_flag_set __4677_21_source_qualifiers;

__4676_21_dest_qualifiers = ((*__4671_20_dest_ptr_flags) & 6U);
__4677_21_source_qualifiers = ((*__4670_20_source_ptr_flags) & 6U);
if (((int)(((*__4670_20_source_ptr_flags) & 32U) != 0U)) != ((int)(((*__4671_20_dest_ptr_flags) & 32U) != 0U))) {

__4668_14_okay = 0;
} else  { if (((~__4676_21_dest_qualifiers) & __4677_21_source_qualifiers) != 0U)
{

__4668_14_okay = 0;
} else  {


if (((~__4677_21_source_qualifiers) & __4676_21_dest_qualifiers) != 0U)
{
__4668_14_okay = __4669_14_previous_qualifiers_include_const;
if (!(__4668_14_okay)) { goto __T1021402504; }
}

if (!((__4676_21_dest_qualifiers & 2U) != 0U)) {
__4669_14_previous_qualifiers_include_const = 0;
}
} }

if (((*__4670_20_source_ptr_flags) & 32U) != 0U) { goto __T1021402504; }
__4671_20_dest_ptr_flags++;
__4670_20_source_ptr_flags++;
} __T1021402504:;
return __4668_14_okay;
}



static int _ZN28_INTERNAL_7_throw_c_721f9a2e35check_exception_type_specificationsEP31an_exception_type_specificationPKSt9type_infojPjPciPPvPS1_Pi(
an_exception_type_specification_ptr __4712_39_etsp, 
a_type_info_impl_ptr __4713_26_type_info, 
an_ETS_flag_set __4714_22_flags, 
an_ETS_flag_set *__4715_23_ptr_flags, 
an_access_flag_string __4716_27_access_flags, 
a_boolean __4717_16_use_access_flags, 
void **__4718_14_object_ptr, 
an_exception_type_specification_ptr *__4719_40_etsp_found, 
a_boolean *__4720_17_nullptr_conv_needed)
#line 978
{
auto int __4732_16_result = 0;
auto int __4733_16_index = 0;
auto a_boolean __4734_21_done = 0;
auto a_boolean __4735_14_is_ptr;

if (__4720_17_nullptr_conv_needed != ((a_boolean *)0)) { (*__4720_17_nullptr_conv_needed) = 0; }
(*__4719_40_etsp_found) = ((an_exception_type_specification_ptr)0);
__4735_14_is_ptr = ((a_boolean)(((__4714_22_flags & 1U) != 0U) || (__4715_23_ptr_flags != ((an_ETS_flag_set *)0))));
do { auto void **__T1021511856; auto a_type_info_impl_ptr __T1021512504; auto a_type_info_impl_ptr __T1021513240; auto a_boolean __T1021513976;
auto a_boolean __4741_23_match = 0;
auto void *__4742_25_new_ptr;
auto a_boolean __4743_16_ets_is_ptr;
auto a_boolean __4744_16_is_single_ptr;
auto a_boolean __4745_16_ets_is_single_ptr;
auto an_access_flag_string __4746_27_local_access_flags; __4746_27_local_access_flags = __4716_27_access_flags;



__4743_16_ets_is_ptr = ((a_boolean)((((__4712_39_etsp->flags) & 1U) != 0U) || ((__4712_39_etsp->ptr_flags) != ((an_ETS_flag_set *)0))));
__4745_16_ets_is_single_ptr = ((a_boolean)((((__4712_39_etsp->flags) & 1U) != 0U) || (0)));
__4744_16_is_single_ptr = ((a_boolean)(((__4714_22_flags & 1U) != 0U) || (0)));
__4733_16_index++;
if ((((__4712_39_etsp->flags) & 16U) != 0U) && (((__4712_39_etsp->flags) & 129U) == 0U)) {
__4741_23_match = 1;
} else  { if (__4743_16_ets_is_ptr != __4735_14_is_ptr) {

} else  { if (((__4712_39_etsp->type_info) == __4713_26_type_info) || ((_ZNKSt9type_info4nameEv((__4712_39_etsp->type_info))) == (_ZNKSt9type_info4nameEv(__4713_26_type_info)))) {


if (!(__4735_14_is_ptr)) {

if ((((((__4712_39_etsp->flags) & 128U) != 0U) && ((__4714_22_flags & 128U) != 0U)) && ((((__4712_39_etsp->flags) & 16U) != 0U) && (((__4712_39_etsp->flags) & 129U) != 0U))) && (!(((__4714_22_flags & 16U) != 0U) && ((__4714_22_flags & 129U) != 0U))))


{



} else  {
__4741_23_match = 1;
}
} else  { if (__4744_16_is_single_ptr != __4745_16_ets_is_single_ptr) {

} else  { auto an_exception_type_specification_ptr __T1021505240; auto an_ETS_flag_set *__T1021505888; if (__4744_16_is_single_ptr) {


auto an_ETS_flag_set __4778_25_source_qualifiers;
auto an_ETS_flag_set __4779_25_dest_qualifiers;
#line 1025
__4778_25_source_qualifiers = (__4714_22_flags & 6U);
__4779_25_dest_qualifiers = ((__4712_39_etsp->flags) & 6U);
if (!(((~__4779_25_dest_qualifiers) & __4778_25_source_qualifiers) != 0U))
{

if ((!((((__4712_39_etsp->flags) & 16U) != 0U) && (((__4712_39_etsp->flags) & 129U) != 0U))) || (((__4714_22_flags & 16U) != 0U) && ((__4714_22_flags & 129U) != 0U))) {




__4741_23_match = 1;
}
}

} else  {


if (((__T1021505240 = __4712_39_etsp) , (__T1021505888 = __4715_23_ptr_flags)) , (_ZN28_INTERNAL_7_throw_c_721f9a2e35check_pointer_levels_and_qualifiersEP31an_exception_type_specificationPj(__T1021505240, __T1021505888))) {
__4741_23_match = 1;
}

} } }
} } }
if (__4741_23_match) {


} else  { if (((__4743_16_ets_is_ptr) || (((__4712_39_etsp->flags) & 192U) != 0U)) && (_ZNKSt9type_infoeqERKS_(__4713_26_type_info, (((const struct _ZSt9type_info *)&(_ZTIDn.base))))))
#line 1063
{


__4741_23_match = 1;
if (__4720_17_nullptr_conv_needed != ((a_boolean *)0)) { (*__4720_17_nullptr_conv_needed) = 1; }

} else  { if (__4743_16_ets_is_ptr != __4735_14_is_ptr) {

} else  { if (!((!(((__4714_22_flags & 1U) != 0U) || (0))) || ((((__4712_39_etsp->flags) & __4714_22_flags) & 6U) == (__4714_22_flags & 6U)))) {
#line 1077
} else  { if (((((__4712_39_etsp->type_info) == ((const struct _ZSt9type_info *)(&_ZTIv))) || ((_ZNKSt9type_info4nameEv((__4712_39_etsp->type_info))) == (_ZNKSt9type_info4nameEv((((const struct _ZSt9type_info *)&(_ZTIv.base))))))) && (__4743_16_ets_is_ptr == __4735_14_is_ptr)) && (
#line 1077
__4745_16_ets_is_single_ptr))
#line 1085
{


__4741_23_match = 1;
#line 1096
} else  { if ((((!(__4735_14_is_ptr)) || ((__4744_16_is_single_ptr) && (__4745_16_ets_is_single_ptr))) && ((_ZNKSt9type_infoeqERKS_(((const struct _ZSt9type_info *)((__4713_26_type_info) ? ((struct __EDG_type_info *)((__4713_26_type_info->__vptr)[(-1)])) : ((__cxa_bad_typeid()) , ((struct 
#line 1096
__EDG_type_info *)0)))), (((const struct _ZSt9type_info *)&((_ZTIN10__cxxabiv120__si_class_type_infoE.base).base))))) || (_ZNKSt9type_infoeqERKS_(((const struct _ZSt9type_info *)((__4713_26_type_info) ? ((struct __EDG_type_info *)((__4713_26_type_info->__vptr)[(-1)])) : ((__cxa_bad_typeid()) , ((
#line 1096
struct __EDG_type_info *)0)))), (((const struct _ZSt9type_info *)&((_ZTIN10__cxxabiv121__vmi_class_type_infoE.base).base))))))) && (((((__T1021511856 = __4718_14_object_ptr) , (__T1021512504 = __4713_26_type_info)) , (__T1021513240 = (__4712_39_etsp->type_info))) , (__T1021513976 = 
#line 1096
__4717_16_use_access_flags)) , (__derived_to_base_conversion(__T1021511856, (&__4742_25_new_ptr), __T1021512504, __T1021513240, (&__4746_27_local_access_flags), __T1021513976))))
#line 1107
{
#line 1116
__4741_23_match = 1;


if (__4718_14_object_ptr != ((void **)0)) { (*__4718_14_object_ptr) = __4742_25_new_ptr; }
#line 1130
} } } } } }
if (__4741_23_match) {
__4732_16_result = __4733_16_index;
(*__4719_40_etsp_found) = __4712_39_etsp;
goto __T1021502384;
}
__4734_21_done = ((a_boolean)((__4712_39_etsp->flags) & 32U));
__4712_39_etsp++;
} while (!(__4734_21_done)); __T1021502384:;
return __4732_16_result;
}


static void _ZN28_INTERNAL_7_throw_c_721f9a2e21destroy_thrown_objectEP19a_throw_stack_entry( a_throw_stack_entry_ptr __4896_59_tsep)
#line 1149
{
auto void *__4903_12_object_address;
auto a_throw_stack_entry_ptr __4904_27_primary_tsep;



__4904_27_primary_tsep = ((__4896_59_tsep->is_rethrow) ? (__4896_59_tsep->primary_entry) : __4896_59_tsep);
if (!(__4896_59_tsep->discard_entry)) {


(__4896_59_tsep->discard_entry) = ((a_byte_boolean)1U);



if (__4896_59_tsep->is_internal) { (__4904_27_primary_tsep->discard_entry) = ((a_byte_boolean)1U); }
if (!((__4904_27_primary_tsep->use_count) > 0UL)) { { fprintf(stderr, ((const char *)"Assertion failed in file \"%s\", line %d\n"), ((const char *)("lib_src/throw.c")), 1164); abort(); } } ;
(__4904_27_primary_tsep->use_count)--;
}
#line 1178
if (((__4904_27_primary_tsep->use_count) == 0UL) && (!(__4904_27_primary_tsep->dtor_called))) {

(__4904_27_primary_tsep->dtor_called) = ((a_byte_boolean)1U);
__4903_12_object_address = (__4904_27_primary_tsep->object_address);
if ((__4904_27_primary_tsep->object_copy_complete) && (!((((__4904_27_primary_tsep->flags) & 1U) != 0U) || ((__4904_27_primary_tsep->ptr_flags) != ((an_ETS_flag_set *)0)))))
{
#line 1189
auto a_destructor_ptr __4942_24_dtor_ptr;
__4942_24_dtor_ptr = ((a_destructor_ptr)(__4904_27_primary_tsep->destructor));
if (__4942_24_dtor_ptr != ((a_destructor_ptr)0)) {



__4942_24_dtor_ptr(__4903_12_object_address);

}
}
} 
}


void __exception_started(void)
#line 1211
{
auto a_throw_stack_entry_ptr __4965_27_tsep; __4965_27_tsep = curr_throw_stack_entry;


((__4965_27_tsep->throw_marker).next) = __curr_eh_stack_entry;
__curr_eh_stack_entry = (&(__4965_27_tsep->throw_marker));
(__4965_27_tsep->object_evaluation_complete) = ((a_byte_boolean)1U); 
}


void __exception_caught(void)




{
if (!(((int)(__curr_eh_stack_entry->kind)) == 3)) { { fprintf(stderr, ((const char *)"Assertion failed in file \"%s\", line %d\n"), ((const char *)("lib_src/throw.c")), 1228); abort(); } }
;
#line 1234
__curr_eh_stack_entry = (__curr_eh_stack_entry->next); 
}


void __throw(void)




{ static const struct __C1 __T1021736560 = {((void (*)())0),0LL};
auto an_eh_stack_entry_ptr __4997_26_ehsep;
auto an_eh_stack_entry_ptr __4998_26_destination_ehsep = ((an_eh_stack_entry_ptr)0);



auto int __5002_10_destination_catch_value;
auto void *__5003_12_object_ptr;
auto void *__5004_12_object_buffer_ptr;
auto a_type_info_impl_ptr __5005_25_thrown_type_info;
auto an_ETS_flag_set __5006_20_throw_flags;
auto an_ETS_flag_set *__5007_21_throw_ptr_flags;

auto an_exception_type_specification_ptr __5009_5_etsp_found = ((an_exception_type_specification_ptr)0);
auto a_boolean __5010_15_nullptr_conv_needed = 0;
auto an_access_flag_string __5011_33_access_flags;
auto a_boolean __5012_15_use_access_flags;

if (!(curr_throw_stack_entry->object_evaluation_complete)) {


__exception_started();
}


(curr_throw_stack_entry->object_copy_complete) = ((a_byte_boolean)1U);


__5005_25_thrown_type_info = (curr_throw_stack_entry->type_info);
__5006_20_throw_flags = (curr_throw_stack_entry->flags);
__5007_21_throw_ptr_flags = (curr_throw_stack_entry->ptr_flags);
__5011_33_access_flags = (curr_throw_stack_entry->access_flags);
__5012_15_use_access_flags = ((a_boolean)(curr_throw_stack_entry->use_access_flags));
#line 1281
if (((__5006_20_throw_flags & 1U) != 0U) || (__5007_21_throw_ptr_flags != ((an_ETS_flag_set *)0))) {



__5004_12_object_buffer_ptr = (curr_throw_stack_entry->object_address);
__5003_12_object_ptr = (*((void **)__5004_12_object_buffer_ptr));
__5004_12_object_buffer_ptr = ((void *)(&(curr_throw_stack_entry->pointer_buffer)));
} else  {


__5004_12_object_buffer_ptr = (curr_throw_stack_entry->object_address);
__5003_12_object_ptr = __5004_12_object_buffer_ptr;
}
#line 1301
__4997_26_ehsep = __curr_eh_stack_entry;
if (!(__4997_26_ehsep == (&(curr_throw_stack_entry->throw_marker)))) { { fprintf(stderr, ((const char *)"Assertion failed in file \"%s\", line %d\n"), ((const char *)("lib_src/throw.c")), 1302); abort(); } } ;

__4997_26_ehsep = (__4997_26_ehsep->next);
while (__4997_26_ehsep != ((an_eh_stack_entry_ptr)0)) { {
auto unsigned char __5059_28_kind; __5059_28_kind = (__4997_26_ehsep->kind);
#line 1316
if (((int)__5059_28_kind) == 1) {

} else  { if (((int)__5059_28_kind) == 4) {

} else  { if ((((int)__5059_28_kind) == 0) || (((int)__5059_28_kind) == 5))
{
if ((((__4997_26_ehsep->variant).try_block).catch_info) == ((void *)0)) {

auto int __5077_13_result;
if ((((__4997_26_ehsep->variant).try_block).catch_entries) != ((an_exception_type_specification_ptr)0)) { auto an_exception_type_specification_ptr __T1021681112; auto a_type_info_impl_ptr __T1021682032; auto an_ETS_flag_set __T1021682768; auto an_ETS_flag_set *__T1021683504; auto 
#line 1325
an_access_flag_string __T1021684240; auto a_boolean __T1021684976;


__5077_13_result = (((((((__T1021681112 = (((__4997_26_ehsep->variant).try_block).catch_entries)) , (__T1021682032 = __5005_25_thrown_type_info)) , (__T1021682768 = __5006_20_throw_flags)) , (__T1021683504 = __5007_21_throw_ptr_flags)) , (__T1021684240 = __5011_33_access_flags)) , (__T1021684976 = 
#line 1328
__5012_15_use_access_flags)) , (_ZN28_INTERNAL_7_throw_c_721f9a2e35check_exception_type_specificationsEP31an_exception_type_specificationPKSt9type_infojPjPciPPvPS1_Pi(__T1021681112, __T1021682032, __T1021682768, __T1021683504, __T1021684240, __T1021684976, (&__5003_12_object_ptr), (&
#line 1328
__5009_5_etsp_found), (&__5010_15_nullptr_conv_needed))));
#line 1334
} else  {




__5077_13_result = 1;
}
if (__5077_13_result != 0) {
#line 1350
if (__4998_26_destination_ehsep == ((an_eh_stack_entry_ptr)0)) {
__4998_26_destination_ehsep = __4997_26_ehsep;
__5002_10_destination_catch_value = __5077_13_result;
}
if ((((__4997_26_ehsep->variant).try_block).catch_entries) != ((an_exception_type_specification_ptr)0)) {




goto __T1021586888;
}
}
}
} else  { if (__4998_26_destination_ehsep != ((an_eh_stack_entry_ptr)0)) {




__4997_26_ehsep = (__4997_26_ehsep->next);
goto __T1021588864;
} else  { if (((int)__5059_28_kind) == 2) {
#line 1376
auto int __5129_11_result = 0;
if (((__4997_26_ehsep->variant).throw_specification) != ((an_exception_type_specification_ptr)0)) { auto an_exception_type_specification_ptr __T1021685888; auto a_type_info_impl_ptr __T1021686536; auto an_ETS_flag_set __T1021687272; auto an_ETS_flag_set *__T1021688008; auto an_access_flag_string 
#line 1377
__T1021688744; auto a_boolean __T1021689480;
auto an_exception_type_specification_ptr __5131_45_dummy_etsp;
__5129_11_result = (((((((__T1021685888 = ((__4997_26_ehsep->variant).throw_specification)) , (__T1021686536 = __5005_25_thrown_type_info)) , (__T1021687272 = __5006_20_throw_flags)) , (__T1021688008 = __5007_21_throw_ptr_flags)) , (__T1021688744 = __5011_33_access_flags)) , (__T1021689480 = 
#line 1379
__5012_15_use_access_flags)) , (_ZN28_INTERNAL_7_throw_c_721f9a2e35check_exception_type_specificationsEP31an_exception_type_specificationPKSt9type_infojPjPciPPvPS1_Pi(__T1021685888, __T1021686536, __T1021687272, __T1021688008, __T1021688744, __T1021689480, ((void **)0), (&__5131_45_dummy_etsp), ((
#line 1379
a_boolean *)0))));
#line 1385
}
if (__5129_11_result == 0) {
__4998_26_destination_ehsep = __4997_26_ehsep;
goto __T1021586888;
}
} else  { if (((int)__5059_28_kind) == 6) {
#line 1396
__4998_26_destination_ehsep = __4997_26_ehsep;
goto __T1021586888;
} else  { if (((int)__5059_28_kind) == 3) {
#line 1404
__curr_eh_stack_entry = __4997_26_ehsep;


(curr_throw_stack_entry->in_handler) = ((a_byte_boolean)1U);
__exception_caught();
__call_terminate();
} else  {
{ fprintf(stderr, ((const char *)"Assertion failed in file \"%s\", line %d\n"), ((const char *)("lib_src/throw.c")), 1411); abort(); } ;
} } } } } } }
__4997_26_ehsep = (__4997_26_ehsep->next);
} __T1021588864:; } __T1021586888:;
#line 1426
__4997_26_ehsep = __curr_eh_stack_entry;

__4997_26_ehsep = (__4997_26_ehsep->next);
while (__4997_26_ehsep != __4998_26_destination_ehsep) { auto an_eh_stack_entry_ptr __T1021690568; auto a_region_number __T1021691216;
auto unsigned char __5183_28_kind; __5183_28_kind = (__4997_26_ehsep->kind);
#line 1440
if (((int)__5183_28_kind) == 1) {
((__T1021690568 = __4997_26_ehsep) , (__T1021691216 = __eh_curr_region)) , (_ZN28_INTERNAL_7_throw_c_721f9a2e7cleanupEP17an_eh_stack_entrytt(__T1021690568, __T1021691216, ((a_region_number)65535U)));
__eh_curr_region = (((__4997_26_ehsep->variant).function).saved_region_number);
} else  { if (((int)__5183_28_kind) == 4) {



__cleanup_vec_new_or_delete(__4997_26_ehsep);
} else  { if (((int)__5183_28_kind) == 0) {

if ((((__4997_26_ehsep->variant).try_block).catch_info) != ((void *)0)) {
#line 1461
auto a_throw_stack_entry_ptr __5214_33_tsep;
__5214_33_tsep = ((a_throw_stack_entry_ptr)(((__4997_26_ehsep->variant).try_block).catch_info));
_ZN28_INTERNAL_7_throw_c_721f9a2e21destroy_thrown_objectEP19a_throw_stack_entry(__5214_33_tsep);
}
} else  { if (((int)__5183_28_kind) == 5) {


auto a_throw_stack_entry_ptr __5221_31_tsep;
for (__5221_31_tsep = curr_throw_stack_entry; __5221_31_tsep != ((a_throw_stack_entry_ptr)0); __5221_31_tsep = (__5221_31_tsep->next)) {
if ((__5221_31_tsep->nearest_enclosing_try_block) == __4997_26_ehsep) {
(__5221_31_tsep->nearest_enclosing_try_block) = ((an_eh_stack_entry_ptr)0);
}
}
} else  { if (((int)__5183_28_kind) == 2) {

} else  { if (((int)__5183_28_kind) == 3) {

} else  { if (((int)__5183_28_kind) == 6) {


{ fprintf(stderr, ((const char *)"Assertion failed in file \"%s\", line %d\n"), ((const char *)("lib_src/throw.c")), 1481); abort(); } ;
} else  {
{ fprintf(stderr, ((const char *)"Assertion failed in file \"%s\", line %d\n"), ((const char *)("lib_src/throw.c")), 1483); abort(); } ;
} } } } } } }
__4997_26_ehsep = (__4997_26_ehsep->next);
}
#line 1494
if (__4998_26_destination_ehsep == ((an_eh_stack_entry_ptr)0)) {


(curr_throw_stack_entry->in_handler) = ((a_byte_boolean)1U);
__exception_caught();
__call_terminate();
}

if ((((int)(__4998_26_destination_ehsep->kind)) == 0) || (((int)(__4998_26_destination_ehsep->kind)) == 5))
{
#line 1510
if (((int)(((__4998_26_destination_ehsep->variant).try_block).region_number)) != ((int)__eh_curr_region))
{ auto an_eh_stack_entry_ptr __T1021692480; auto a_region_number __T1021693128; auto a_region_number __T1021693864;

auto an_eh_stack_entry_ptr __5266_29_function_ehsep; __5266_29_function_ehsep = (__4998_26_destination_ehsep->next);
while (((int)(__5266_29_function_ehsep->kind)) != 1) {
__5266_29_function_ehsep = (__5266_29_function_ehsep->next);
}
(((__T1021692480 = __5266_29_function_ehsep) , (__T1021693128 = __eh_curr_region)) , (__T1021693864 = (((__4998_26_destination_ehsep->variant).try_block).region_number))) , (_ZN28_INTERNAL_7_throw_c_721f9a2e7cleanupEP17an_eh_stack_entrytt(__T1021692480, __T1021693128, __T1021693864));



__eh_curr_region = (((__4998_26_destination_ehsep->variant).try_block).region_number);
}
}




if (!(__curr_eh_stack_entry == (&(curr_throw_stack_entry->throw_marker)))) { { fprintf(stderr, ((const char *)"Assertion failed in file \"%s\", line %d\n"), ((const char *)("lib_src/throw.c")), 1529); abort(); 
#line 1528
} }
;
(__curr_eh_stack_entry->next) = __4998_26_destination_ehsep;


(curr_throw_stack_entry->in_handler) = ((a_byte_boolean)1U);
if ((((int)(__4998_26_destination_ehsep->kind)) == 0) || (((int)(__4998_26_destination_ehsep->kind)) == 5))
{
auto a_boolean __5289_15_exception_caught = 0;
__catch_clause_number = __5002_10_destination_catch_value;
if (((__5006_20_throw_flags & 1U) != 0U) || (__5007_21_throw_ptr_flags != ((an_ETS_flag_set *)0))) {
#line 1544
(*((void **)__5004_12_object_buffer_ptr)) = __5003_12_object_ptr;
__caught_object_address = __5004_12_object_buffer_ptr;
} else  { if (__5010_15_nullptr_conv_needed) {



if ((((__5009_5_etsp_found->flags) & 1U) != 0U) || ((__5009_5_etsp_found->ptr_flags) != ((an_ETS_flag_set *)0))) {

(curr_throw_stack_entry->pointer_buffer) = ((void *)0);
__caught_object_address = ((void *)(&(curr_throw_stack_entry->pointer_buffer)));
} else  { if (((__5009_5_etsp_found->flags) & 64U) != 0U) {

(curr_throw_stack_entry->ptr_to_data_member_buffer) = (-1LL);
__caught_object_address = ((void *)(&(curr_throw_stack_entry->ptr_to_data_member_buffer)));

} else  {

(curr_throw_stack_entry->ptr_to_member_function_buffer) = __T1021736560;
__caught_object_address = ((void *)(&(curr_throw_stack_entry->ptr_to_member_function_buffer)));

} }
} else  {




__caught_object_address = __5003_12_object_ptr;
} }


(((__4998_26_destination_ehsep->variant).try_block).catch_info) = ((void *)curr_throw_stack_entry);
#line 1594
if (__5289_15_exception_caught) {

__exception_caught();
}
longjmp(((((__4998_26_destination_ehsep->variant).try_block).setjmp_buffer)), 1);
} else  { if (((int)(__4998_26_destination_ehsep->kind)) == 2)
{




__curr_eh_stack_entry = (__curr_eh_stack_entry->next);
#line 1613
__call_unexpected();
} else  { if (((int)(__4998_26_destination_ehsep->kind)) == 6)
{




__curr_eh_stack_entry = (__curr_eh_stack_entry->next);
__call_terminate();
} } } 
}


static void _ZN28_INTERNAL_7_throw_c_721f9a2e16push_throw_stackEPKSt9type_infoPFvPvEjPjPciS3_iiP19a_throw_stack_entry( a_type_info_impl_ptr __5379_54_type_info, 
a_destructor_ptr __5380_31_destructor, 
an_ETS_flag_set __5381_30_flags, 
an_ETS_flag_set *__5382_31_ptr_flags, 
an_access_flag_string __5383_54_access_flags, 
a_boolean __5384_54_use_access_flags, 
void *__5385_21_object_address, 
a_boolean __5386_25_is_rethrow, 
a_boolean __5387_25_is_internal, 
a_throw_stack_entry_ptr __5388_54_primary_entry)



{
auto a_throw_stack_entry_ptr __5393_27_tsep;
auto an_eh_stack_entry_ptr __5394_26_ehsep;

__5393_27_tsep = ((a_throw_stack_entry_ptr)(_ZN28_INTERNAL_7_throw_c_721f9a2e17eh_alloc_on_stackEy(240ULL)));
#line 1650
__5394_26_ehsep = __curr_eh_stack_entry;
while (__5394_26_ehsep != ((an_eh_stack_entry_ptr)0)) {

if (((((int)(__5394_26_ehsep->kind)) == 0) || (((int)(__5394_26_ehsep->kind)) == 5)) && ((((__5394_26_ehsep->variant).try_block).catch_info) == ((void *)0))) {

goto __T1021801408; }
__5394_26_ehsep = (__5394_26_ehsep->next);
} __T1021801408:;
(__5393_27_tsep->nearest_enclosing_try_block) = __5394_26_ehsep;
if (curr_throw_stack_entry != ((a_throw_stack_entry_ptr)0)) {
if ((curr_throw_stack_entry->nearest_enclosing_try_block) == __5394_26_ehsep) {


_ZN28_INTERNAL_7_throw_c_721f9a2e21destroy_thrown_objectEP19a_throw_stack_entry(curr_throw_stack_entry);
}
}
(__5393_27_tsep->next) = curr_throw_stack_entry;
curr_throw_stack_entry = __5393_27_tsep;
(__5393_27_tsep->type_info) = __5379_54_type_info;
(__5393_27_tsep->destructor) = __5380_31_destructor;
(__5393_27_tsep->flags) = __5381_30_flags;
(__5393_27_tsep->ptr_flags) = __5382_31_ptr_flags;
(__5393_27_tsep->access_flags) = __5383_54_access_flags;
(__5393_27_tsep->use_access_flags) = ((a_byte_boolean)__5384_54_use_access_flags);
(__5393_27_tsep->object_address) = __5385_21_object_address;
(__5393_27_tsep->pointer_buffer) = ((void *)0);
(__5393_27_tsep->primary_entry) = __5388_54_primary_entry;
(__5393_27_tsep->use_count) = 0UL;


if (__5387_25_is_internal) {

} else  { if (__5386_25_is_rethrow) {
(__5388_54_primary_entry->use_count)++;
} else  {
(__5393_27_tsep->use_count)++;
} }
(__5393_27_tsep->is_rethrow) = ((a_byte_boolean)__5386_25_is_rethrow);
(__5393_27_tsep->is_internal) = ((a_byte_boolean)__5387_25_is_internal);
(__5393_27_tsep->dtor_called) = ((a_byte_boolean)0U);
(__5393_27_tsep->discard_entry) = ((a_byte_boolean)0U);
(__5393_27_tsep->in_handler) = ((a_byte_boolean)0U);
(__5393_27_tsep->object_copy_complete) = ((a_byte_boolean)0U);
(__5393_27_tsep->object_evaluation_complete) = ((a_byte_boolean)0U);
((__5393_27_tsep->throw_marker).next) = ((an_eh_stack_entry_ptr)0);
((__5393_27_tsep->throw_marker).kind) = ehsek_throw_processing_marker; 
}


static void _ZN28_INTERNAL_7_throw_c_721f9a2e12rethrow_fullEi( a_boolean __5452_36_is_internal)




{ auto a_type_info_impl_ptr __T1021832536; auto a_destructor_ptr __T1021833184; auto an_ETS_flag_set __T1021833920; auto an_ETS_flag_set *__T1021834656; auto an_access_flag_string __T1021835392; auto a_boolean __T1021836128; auto void *__T1021836864; auto a_boolean __T1021837600; auto 
#line 1704
a_throw_stack_entry_ptr __T1021838336;
auto a_throw_stack_entry_ptr __5458_27_tsep; __5458_27_tsep = curr_throw_stack_entry;


for (; __5458_27_tsep != ((a_throw_stack_entry_ptr)0); __5458_27_tsep = (__5458_27_tsep->next)) {
if ((__5458_27_tsep->in_handler) && (!(__5458_27_tsep->is_rethrow))) { goto __T1021827832; }
} __T1021827832:;
if (__5458_27_tsep == ((a_throw_stack_entry_ptr)0)) {

__call_terminate();
}
(((((((((__T1021832536 = (__5458_27_tsep->type_info)) , (__T1021833184 = (__5458_27_tsep->destructor))) , (__T1021833920 = (__5458_27_tsep->flags))) , (__T1021834656 = (__5458_27_tsep->ptr_flags))) , (__T1021835392 = (__5458_27_tsep->access_flags))) , (__T1021836128 = ((a_boolean)(__5458_27_tsep->
#line 1715
use_access_flags)))) , (__T1021836864 = (__5458_27_tsep->object_address))) , (__T1021837600 = __5452_36_is_internal)) , (__T1021838336 = __5458_27_tsep)) , (_ZN28_INTERNAL_7_throw_c_721f9a2e16push_throw_stackEPKSt9type_infoPFvPvEjPjPciS3_iiP19a_throw_stack_entry(__T1021832536, __T1021833184, 
#line 1715
__T1021833920, __T1021834656, __T1021835392, __T1021836128, __T1021836864, 1, __T1021837600, __T1021838336));
#line 1725
__throw(); 
}


void __rethrow(void)



{
_ZN28_INTERNAL_7_throw_c_721f9a2e12rethrow_fullEi(0); 
}



void __internal_rethrow(void)
#line 1745
{
__exception_caught();
_ZN28_INTERNAL_7_throw_c_721f9a2e12rethrow_fullEi(1); 
}
#line 1766
void *__throw_setup_ptr( a_type_info_impl_ptr __5519_56_type_info, 
a_sizeof_t __5520_35_size, 
an_ETS_flag_set *__5521_31_ptr_flags)
#line 1774
{ auto a_type_info_impl_ptr __T1021849176; auto an_ETS_flag_set *__T1021849824; auto void *__T1021850560;
auto void *__5528_12_object_address;

__5528_12_object_address = ((void *)(_ZN28_INTERNAL_7_throw_c_721f9a2e17eh_alloc_on_stackEy(__5520_35_size)));
(((__T1021849176 = __5519_56_type_info) , (__T1021849824 = __5521_31_ptr_flags)) , (__T1021850560 = __5528_12_object_address)) , (_ZN28_INTERNAL_7_throw_c_721f9a2e16push_throw_stackEPKSt9type_infoPFvPvEjPjPciS3_iiP19a_throw_stack_entry(__T1021849176, ((a_destructor_ptr)0), 0U, __T1021849824, ((
#line 1778
an_access_flag_string)0), 0, __T1021850560, 0, 0, ((a_throw_stack_entry_ptr)0)));
#line 1784
return __5528_12_object_address;
}




void *__throw_setup( a_type_info_impl_ptr __5543_52_type_info, 
a_sizeof_t __5544_33_size, 
an_ETS_flag_set __5545_28_ets_flags)
#line 1798
{ auto a_type_info_impl_ptr __T1021859472; auto a_destructor_ptr __T1021860120; auto an_ETS_flag_set __T1021860856; auto void *__T1021861592;
auto void *__5552_12_object_address;
auto a_destructor_ptr __5553_21_destructor;
#line 1808
__5553_21_destructor = ((a_destructor_ptr)0);

__5552_12_object_address = ((void *)(_ZN28_INTERNAL_7_throw_c_721f9a2e17eh_alloc_on_stackEy(__5544_33_size)));
((((__T1021859472 = __5543_52_type_info) , (__T1021860120 = __5553_21_destructor)) , (__T1021860856 = __5545_28_ets_flags)) , (__T1021861592 = __5552_12_object_address)) , (_ZN28_INTERNAL_7_throw_c_721f9a2e16push_throw_stackEPKSt9type_infoPFvPvEjPjPciS3_iiP19a_throw_stack_entry(__T1021859472, 
#line 1811
__T1021860120, __T1021860856, ((an_ETS_flag_set *)0), ((an_access_flag_string)0), 0, __T1021861592, 0, 0, ((a_throw_stack_entry_ptr)0)));
#line 1817
return __5552_12_object_address;
}



void *__throw_setup_dtor( a_type_info_impl_ptr __5575_57_type_info, 
a_sizeof_t __5576_35_size, 
int __5577_20_ets_flags, 
a_destructor_ptr __5578_24_destructor)
#line 1834
{ auto a_type_info_impl_ptr __T1021870600; auto a_destructor_ptr __T1021871248; auto an_ETS_flag_set __T1021871984; auto void *__T1021872720;
auto void *__5588_12_object_address;

__5588_12_object_address = ((void *)(_ZN28_INTERNAL_7_throw_c_721f9a2e17eh_alloc_on_stackEy(__5576_35_size)));
((((__T1021870600 = __5575_57_type_info) , (__T1021871248 = __5578_24_destructor)) , (__T1021871984 = ((an_ETS_flag_set)__5577_20_ets_flags))) , (__T1021872720 = __5588_12_object_address)) , (_ZN28_INTERNAL_7_throw_c_721f9a2e16push_throw_stackEPKSt9type_infoPFvPvEjPjPciS3_iiP19a_throw_stack_entry(
#line 1838
__T1021870600, __T1021871248, __T1021871984, ((an_ETS_flag_set *)0), ((an_access_flag_string)0), 0, __T1021872720, 0, 0, ((a_throw_stack_entry_ptr)0)));
#line 1844
return __5588_12_object_address;
}
#line 1875
void __free_thrown_object(void)
#line 1882
{
#line 1888
if (!(curr_throw_stack_entry != ((a_throw_stack_entry_ptr)0))) { { fprintf(stderr, ((const char *)"Assertion failed in file \"%s\", line %d\n"), ((const char *)("lib_src/throw.c")), 1888); abort(); } } ;
_ZN28_INTERNAL_7_throw_c_721f9a2e21destroy_thrown_objectEP19a_throw_stack_entry(curr_throw_stack_entry);
#line 1898
while ((curr_throw_stack_entry != ((a_throw_stack_entry_ptr)0)) && (curr_throw_stack_entry->discard_entry))
{
auto a_throw_stack_entry_ptr __5653_29_tsep;
auto a_boolean __5654_17_is_rethrow;
auto void *__5655_13_object_address;
#line 1900
__5653_29_tsep = curr_throw_stack_entry;
__5654_17_is_rethrow = ((a_boolean)(__5653_29_tsep->is_rethrow));
__5655_13_object_address = (__5653_29_tsep->object_address);


if (!((__5654_17_is_rethrow) || (__5653_29_tsep->dtor_called))) { { fprintf(stderr, ((const char *)"Assertion failed in file \"%s\", line %d\n"), ((const char *)("lib_src/throw.c")), 1905); abort(); } } ;

curr_throw_stack_entry = (__5653_29_tsep->next);



_ZN28_INTERNAL_7_throw_c_721f9a2e16eh_free_on_stackEPv(((void *)__5653_29_tsep));
if (!(__5654_17_is_rethrow)) {

_ZN28_INTERNAL_7_throw_c_721f9a2e16eh_free_on_stackEPv(__5655_13_object_address);
}
} 
#line 1922
}


void __destroy_exception_object(void)
#line 1934
{
auto a_throw_stack_entry_ptr __5688_27_tsep;
#line 1942
for (__5688_27_tsep = curr_throw_stack_entry; __5688_27_tsep != ((a_throw_stack_entry_ptr)0); __5688_27_tsep = (__5688_27_tsep->next)) {
if (((__5688_27_tsep->in_handler) && (!(__5688_27_tsep->dtor_called))) && (!(__5688_27_tsep->discard_entry))) { goto __T1021892264; }
} __T1021892264:;
if (!(__5688_27_tsep != ((a_throw_stack_entry_ptr)0))) { { fprintf(stderr, ((const char *)"Assertion failed in file \"%s\", line %d\n"), ((const char *)("lib_src/throw.c")), 1945); abort(); } } ;



if (__5688_27_tsep == curr_throw_stack_entry) {
__free_thrown_object();
} else  {
_ZN28_INTERNAL_7_throw_c_721f9a2e21destroy_thrown_objectEP19a_throw_stack_entry(__5688_27_tsep);
} 
}


void __eh_exit_processing(void)
#line 1963
{


__curr_eh_stack_entry = ((an_eh_stack_entry_ptr)0); 
}


void __suppress_optim_on_vars_in_try(void)
#line 1979
{
{ fprintf(stderr, ((const char *)"Assertion failed in file \"%s\", line %d\n"), ((const char *)("lib_src/throw.c")), 1980); abort(); } ; 
}

an_eh_stack_entry_ptr __get_curr_eh_stack_entry(void)



{
return __curr_eh_stack_entry;
}


void __type_of_thrown_object( a_type_info_impl_ptr *__5745_61_type, 
an_ETS_flag_set *__5746_29_flags, 
an_ETS_flag_set **__5747_30_ptr_flags)




{
if (!(curr_throw_stack_entry != ((a_throw_stack_entry_ptr)0))) { { fprintf(stderr, ((const char *)"Assertion failed in file \"%s\", line %d\n"), ((const char *)("lib_src/throw.c")), 2000); abort(); } } ;
(*__5745_61_type) = (curr_throw_stack_entry->type_info);
(*__5746_29_flags) = (curr_throw_stack_entry->flags);
(*__5747_30_ptr_flags) = (curr_throw_stack_entry->ptr_flags); 
}


a_boolean __can_throw_type( a_type_info_impl_ptr __5760_58_type, 
an_ETS_flag_set __5761_26_flags, 
an_ETS_flag_set *__5762_27_ptr_flags)
#line 2016
{
auto a_boolean __5770_14_result = 0;
auto an_eh_stack_entry_ptr __5771_25_ehsep;

__5771_25_ehsep = __curr_eh_stack_entry;
for (__5771_25_ehsep = __curr_eh_stack_entry; __5771_25_ehsep != ((an_eh_stack_entry_ptr)0); __5771_25_ehsep = (__5771_25_ehsep->next)) {
if (((int)(__5771_25_ehsep->kind)) == 2) { goto __T1021916344; }
} __T1021916344:;
if (!(__5771_25_ehsep != ((an_eh_stack_entry_ptr)0))) { { fprintf(stderr, ((const char *)"Assertion failed in file \"%s\", line %d\n"), ((const char *)("lib_src/throw.c")), 2024); abort(); } } ;
if (((__5771_25_ehsep->variant).throw_specification) != ((an_exception_type_specification_ptr)0)) { auto an_exception_type_specification_ptr __T1021927720; auto a_type_info_impl_ptr __T1021928368; auto an_ETS_flag_set __T1021994744; auto an_ETS_flag_set *__T1021995480;
auto an_exception_type_specification_ptr __5779_41_dummy_etsp;
auto int __5780_13_catch_pos;
__5780_13_catch_pos = (((((__T1021927720 = ((__5771_25_ehsep->variant).throw_specification)) , (__T1021928368 = __5760_58_type)) , (__T1021994744 = __5761_26_flags)) , (__T1021995480 = __5762_27_ptr_flags)) , (
#line 2028
_ZN28_INTERNAL_7_throw_c_721f9a2e35check_exception_type_specificationsEP31an_exception_type_specificationPKSt9type_infojPjPciPPvPS1_Pi(__T1021927720, __T1021928368, __T1021994744, __T1021995480, ((an_access_flag_string)0), 0, ((void **)0), (&__5779_41_dummy_etsp), ((a_boolean *)0))));
#line 2034
if (__5780_13_catch_pos != 0) { __5770_14_result = 1; }
}
return __5770_14_result;
}
