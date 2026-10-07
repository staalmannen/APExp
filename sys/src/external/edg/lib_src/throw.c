/* Translated by the Edison Design Group C++/C front end (version 7.0) */
/* Wed Oct  7 07:14:44 2026 */
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
#line 44 "ape-sys/stdlib.h"
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
static void *_ZN28_INTERNAL_7_throw_c_721f9a2e13eh_get_memoryEy( a_sizeof_t __4020_39_size)
#line 301
{
auto void *__4027_10_mem_block;

__4027_10_mem_block = (malloc(__4020_39_size));

if (__4027_10_mem_block == ((void *)0)) {
__call_terminate();
}
return __4027_10_mem_block;
}


static void _ZN28_INTERNAL_7_throw_c_721f9a2e14eh_free_memoryEPv( void *__4038_34_ptr)
#line 319
{
free(__4038_34_ptr); 
}


static void _ZN28_INTERNAL_7_throw_c_721f9a2e20mem_block_descr_initEP17a_mem_block_descr( a_mem_block_descr_ptr __4049_56_mbdp)



{
(__4049_56_mbdp->next) = ((a_mem_block_descr_ptr)0);
(__4049_56_mbdp->addr) = ((void *)0);
(__4049_56_mbdp->size) = 0ULL;
(__4049_56_mbdp->used) = 0ULL;
(__4049_56_mbdp->dynamically_allocated) = ((a_byte_boolean)0U); 
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
static void *_ZN28_INTERNAL_7_throw_c_721f9a2e18alloc_in_mem_blockEyPP16a_mem_allocation( a_sizeof_t __4085_50_size, 
a_mem_allocation_ptr *__4086_34_map)
#line 367
{
auto void *__4093_11_ptr;
auto int __4094_9_used;



__4094_9_used = ((int)(curr_mem_block_descr->used));
(*__4086_34_map) = ((a_mem_allocation_ptr)((void *)(((char *)(curr_mem_block_descr->addr)) + __4094_9_used)));
__4094_9_used += 32ULL;
__4093_11_ptr = ((void *)((void *)(((char *)(curr_mem_block_descr->addr)) + __4094_9_used)));
__4094_9_used += __4085_50_size;
(curr_mem_block_descr->used) = ((a_sizeof_t)__4094_9_used);

((*__4086_34_map)->next) = mem_allocation_stack;
((*__4086_34_map)->addr) = __4093_11_ptr;
mem_allocation_stack = (*__4086_34_map);

((*__4086_34_map)->alloc_size) = __4085_50_size;
((*__4086_34_map)->is_mem_block_descr_allocation) = ((a_byte_boolean)0U);
if (!((curr_mem_block_descr->used) <= (curr_mem_block_descr->size))) { { fprintf(stderr, ((const char *)"Assertion failed in file \"%s\", line %d\n"), ((const char *)("lib_src/throw.c")), 386); abort(); } } ;
if (!((__4085_50_size % 8ULL) == 0ULL)) { { fprintf(stderr, ((const char *)"Assertion failed in file \"%s\", line %d\n"), ((const char *)("lib_src/throw.c")), 387); abort(); } } ;
return __4093_11_ptr;
}


static void _ZN28_INTERNAL_7_throw_c_721f9a2e19alloc_new_mem_blockEy( a_sizeof_t __4117_44_size)
#line 399
{
auto void *__4125_11_mem_block;
auto a_mem_allocation_ptr __4126_24_map;
auto a_mem_block_descr_ptr __4127_25_mpdp;
auto a_sizeof_t __4128_15_new_size;
#line 409
__4128_15_new_size = (((__4117_44_size / 8192ULL) + 1ULL) * 8192ULL);

if ((__4128_15_new_size - __4117_44_size) < 4096ULL) {
__4128_15_new_size += 8192ULL;
}
__4117_44_size = __4128_15_new_size;


__4127_25_mpdp = ((a_mem_block_descr_ptr)(_ZN28_INTERNAL_7_throw_c_721f9a2e18alloc_in_mem_blockEyPP16a_mem_allocation(40ULL, (&__4126_24_map))));

(__4126_24_map->is_mem_block_descr_allocation) = ((a_byte_boolean)1U);
__4125_11_mem_block = (_ZN28_INTERNAL_7_throw_c_721f9a2e13eh_get_memoryEy(__4117_44_size));

(__4127_25_mpdp->next) = curr_mem_block_descr;
curr_mem_block_descr = __4127_25_mpdp;

(__4127_25_mpdp->addr) = __4125_11_mem_block;
(__4127_25_mpdp->size) = __4117_44_size;
(__4127_25_mpdp->used) = 0ULL;
(__4127_25_mpdp->dynamically_allocated) = ((a_byte_boolean)1U); 
}


static void *_ZN28_INTERNAL_7_throw_c_721f9a2e17eh_alloc_on_stackEy( a_sizeof_t __4157_43_size)



{
auto a_mem_allocation_ptr __4162_24_map;
auto int __4163_9_needed_for_alignment;
auto void *__4164_11_ptr;
auto a_sizeof_t __4165_15_alloc_size;



if (curr_mem_block_descr == ((a_mem_block_descr_ptr)0)) {
_ZN28_INTERNAL_7_throw_c_721f9a2e25init_eh_memory_managementEv();
}


__4163_9_needed_for_alignment = ((int)(((__4157_43_size % 8ULL) == 0ULL) ? 0ULL : (8ULL - (__4157_43_size % 8ULL))));




__4165_15_alloc_size = (__4157_43_size + ((unsigned long long)__4163_9_needed_for_alignment));
if ((((__4165_15_alloc_size + 32ULL) + (curr_mem_block_descr->used)) + 72ULL) > (curr_mem_block_descr->size))

{
_ZN28_INTERNAL_7_throw_c_721f9a2e19alloc_new_mem_blockEy(__4165_15_alloc_size);
}
__4164_11_ptr = (_ZN28_INTERNAL_7_throw_c_721f9a2e18alloc_in_mem_blockEyPP16a_mem_allocation(__4165_15_alloc_size, (&__4162_24_map)));
#line 467
return __4164_11_ptr;
}


static void _ZN28_INTERNAL_7_throw_c_721f9a2e17free_in_mem_blockEPv( void *__4196_37_ptr)



{
auto a_mem_allocation_ptr __4201_24_map;
auto int __4202_9_used;

__4201_24_map = mem_allocation_stack;
mem_allocation_stack = (__4201_24_map->next);
if (!((__4201_24_map->addr) == __4196_37_ptr)) { { fprintf(stderr, ((const char *)"Assertion failed in file \"%s\", line %d\n"), ((const char *)("lib_src/throw.c")), 481); abort(); } } ;
__4202_9_used = ((int)(curr_mem_block_descr->used));
__4202_9_used -= (__4201_24_map->alloc_size);
__4202_9_used -= 32ULL;
(curr_mem_block_descr->used) = ((a_sizeof_t)__4202_9_used); 
}


static void _ZN28_INTERNAL_7_throw_c_721f9a2e16eh_free_on_stackEPv( void *__4214_36_ptr)




{

_ZN28_INTERNAL_7_throw_c_721f9a2e17free_in_mem_blockEPv(__4214_36_ptr);

if ((curr_mem_block_descr->used) == 0ULL) {
if ((curr_mem_block_descr->next) != ((a_mem_block_descr_ptr)0)) {

auto a_mem_block_descr_ptr __4226_29_mpdp_to_free;
__4226_29_mpdp_to_free = curr_mem_block_descr;
curr_mem_block_descr = (__4226_29_mpdp_to_free->next);


if (__4226_29_mpdp_to_free->dynamically_allocated) {

_ZN28_INTERNAL_7_throw_c_721f9a2e14eh_free_memoryEPv((__4226_29_mpdp_to_free->addr));
}

_ZN28_INTERNAL_7_throw_c_721f9a2e17free_in_mem_blockEPv(((void *)__4226_29_mpdp_to_free));
}
} 
}
#line 665
static void _ZN28_INTERNAL_7_throw_c_721f9a2e7cleanupEP17an_eh_stack_entrytt( an_eh_stack_entry_ptr __4390_43_ehsep, 
a_region_number __4391_43_region, 
a_region_number __4392_25_stop_at_region)
#line 676
{
auto an_object_ptr *__4402_34_obj_addr_array;
auto an_eh_region_descr_ptr __4403_26_ehrdp;
#line 686
__4402_34_obj_addr_array = (((__4390_43_ehsep->variant).function).object_address_table);
for (; ((int)__4391_43_region) != ((int)__4392_25_stop_at_region); __4391_43_region = (__4403_26_ehrdp->index_of_next_region)) { {
auto an_object_ptr __4413_27_obj_addr = ((an_object_ptr)0);
auto a_conditional_flag *__4414_33_flag_addr = ((a_conditional_flag *)0);
auto char *__4415_13_temp_addr;
auto a_region_descr_flag_set __4416_33_flags;
auto an_eh_array_supplement_ptr __4417_32_ehasp = ((an_eh_array_supplement_ptr)0);
auto void *__4418_13_vtbl_ptr;
auto a_boolean __4419_17_has_vtbl_ptr = 0;

auto a_destroy_exception_object_ptr __4421_5_potential_destroy_exception_object_ptr;

__4403_26_ehrdp = ((((__4390_43_ehsep->variant).function).regions) + __4391_43_region);
#line 710
__4421_5_potential_destroy_exception_object_ptr = ((a_destroy_exception_object_ptr)(__4403_26_ehrdp->destructor_or_delete_routine));

if (__4421_5_potential_destroy_exception_object_ptr == (&__destroy_exception_object))
{
__destroy_exception_object();
goto __T405564968;
}
__4416_33_flags = (__4403_26_ehrdp->flags);
if (((int)__4416_33_flags) & 0x2) {
#line 727
__4414_33_flag_addr = ((a_conditional_flag *)(*(__4402_34_obj_addr_array + ((__4403_26_ehrdp + 1)->handle))));
#line 734
if (!(*__4414_33_flag_addr)) { goto __T405564968; }
}
if (((((int)__4416_33_flags) & 0x20) != 0) && (((((int)__4416_33_flags) & 0x40) != 0) && ((((int)__4416_33_flags) & 0x8) == 0)))
{
#line 745
auto an_eh_region_descr_ptr __4470_30_vtbl_ehrdp;
#line 744
__4419_17_has_vtbl_ptr = 1;

__4470_30_vtbl_ehrdp = (__4403_26_ehrdp + 1);
if (__4414_33_flag_addr != ((a_conditional_flag *)0)) { __4470_30_vtbl_ehrdp++; }




__4418_13_vtbl_ptr = (*((void **)(__4402_34_obj_addr_array + (__4470_30_vtbl_ehrdp->handle))));
if (((int)(__4470_30_vtbl_ehrdp->flags)) & 0x1) {



__4415_13_temp_addr = ((char *)(*((void **)__4418_13_vtbl_ptr)));
__4418_13_vtbl_ptr = ((void *)__4415_13_temp_addr);
}
#line 765
}
#line 772
if (!(__4402_34_obj_addr_array != ((an_object_ptr *)0))) { { fprintf(stderr, ((const char *)"Assertion failed in file \"%s\", line %d\n"), ((const char *)("lib_src/throw.c")), 772); abort(); } } ;
if (((int)__4416_33_flags) & 0x8) {

__4417_32_ehasp = ((((__4390_43_ehsep->variant).function).array_table) + (__4403_26_ehrdp->handle));
__4413_27_obj_addr = (*(__4402_34_obj_addr_array + (__4417_32_ehasp->handle)));
} else  {

__4413_27_obj_addr = (*(__4402_34_obj_addr_array + (__4403_26_ehrdp->handle)));
}
if (((int)__4416_33_flags) & 0x1) {



__4415_13_temp_addr = ((char *)(*((void **)__4413_27_obj_addr)));
__4413_27_obj_addr = ((void *)__4415_13_temp_addr);
}
#line 794
if ((((int)__4416_33_flags) & 0x80) != 0) {
#line 803
__4414_33_flag_addr = ((a_conditional_flag *)__4413_27_obj_addr);
#line 810
__cxa_guard_abort(((an_ia64_guard_ptr)__4414_33_flag_addr));



} else  { if (!(((int)__4416_33_flags) & 0x4)) {


auto a_destructor_ptr __4542_24_dtor_ptr;
__4542_24_dtor_ptr = ((a_destructor_ptr)(__4403_26_ehrdp->destructor_or_delete_routine));
if (((int)__4416_33_flags) & 0x8) {




auto a_boolean __4549_20_is_vla; __4549_20_is_vla = ((a_boolean)((((int)__4416_33_flags) & 0x40) != 0));
if (__4542_24_dtor_ptr != ((a_destructor_ptr)0)) { auto an_object_ptr __T405611112; auto size_t __T405611760; auto a_sizeof_t __T405612496; auto a_destructor_ptr __T405613232;
auto an_element_count __4551_28_elements; __4551_28_elements = (__4417_32_ehasp->array_size);
if (__4549_20_is_vla) {


auto a_sizeof_t *__4555_26_element_addr;
__4555_26_element_addr = ((a_sizeof_t *)(__4402_34_obj_addr_array[((__4403_26_ehrdp + 1)->handle)]));
__4551_28_elements = ((an_element_count)(*__4555_26_element_addr));
}
#line 839
((((__T405611112 = __4413_27_obj_addr) , (__T405611760 = ((size_t)__4551_28_elements))) , (__T405612496 = (__4417_32_ehasp->element_size))) , (__T405613232 = __4542_24_dtor_ptr)) , (__cxa_vec_dtor(__T405611112, __T405611760, __T405612496, __T405613232));


}
} else  { if (__4419_17_has_vtbl_ptr) { auto an_object_ptr __T405614144; auto void *__T405614792;
#line 852
auto a_destructor_with_vtable_param_ptr __4577_44_dtor_with_vtable;
__4577_44_dtor_with_vtable = ((a_destructor_with_vtable_param_ptr)__4542_24_dtor_ptr);
((__T405614144 = __4413_27_obj_addr) , (__T405614792 = __4418_13_vtbl_ptr)) , (__4577_44_dtor_with_vtable(__T405614144, __T405614792));
} else  {
#line 867
__4542_24_dtor_ptr(__4413_27_obj_addr);

} }
} else  {


if (__4413_27_obj_addr != ((an_object_ptr)0)) {
if (((int)__4416_33_flags) & 0x8) { auto an_object_ptr __T405615704; auto a_sizeof_t __T405616352;


auto a_two_operand_delete_ptr __4602_36_delete_ptr;
__4602_36_delete_ptr = ((a_two_operand_delete_ptr)(__4403_26_ehrdp->destructor_or_delete_routine));

((__T405615704 = __4413_27_obj_addr) , (__T405616352 = (__4417_32_ehasp->element_size))) , (__4602_36_delete_ptr(__T405615704, __T405616352));
} else  {
auto a_delete_ptr __4607_24_delete_ptr;
__4607_24_delete_ptr = ((a_delete_ptr)(__4403_26_ehrdp->destructor_or_delete_routine));
__4607_24_delete_ptr(__4413_27_obj_addr);
}
}
} }
} __T405564968:; } 
}
#line 901
static a_boolean _ZN28_INTERNAL_7_throw_c_721f9a2e35check_pointer_levels_and_qualifiersEP31an_exception_type_specificationPj(
an_exception_type_specification_ptr __4627_40_etsp, 
an_ETS_flag_set *__4628_24_ptr_flags)
#line 914
{
auto a_boolean __4640_14_okay;
auto a_boolean __4641_14_previous_qualifiers_include_const = 1;
auto an_ETS_flag_set *__4642_20_source_ptr_flags;
auto an_ETS_flag_set *__4643_20_dest_ptr_flags;

__4643_20_dest_ptr_flags = (__4627_40_etsp->ptr_flags);
__4642_20_source_ptr_flags = __4628_24_ptr_flags;
for (__4640_14_okay = 1; __4640_14_okay == 1; ) {
auto an_ETS_flag_set __4648_21_dest_qualifiers;
auto an_ETS_flag_set __4649_21_source_qualifiers;

__4648_21_dest_qualifiers = ((*__4643_20_dest_ptr_flags) & 6U);
__4649_21_source_qualifiers = ((*__4642_20_source_ptr_flags) & 6U);
if (((int)(((*__4642_20_source_ptr_flags) & 32U) != 0U)) != ((int)(((*__4643_20_dest_ptr_flags) & 32U) != 0U))) {

__4640_14_okay = 0;
} else  { if (((~__4648_21_dest_qualifiers) & __4649_21_source_qualifiers) != 0U)
{

__4640_14_okay = 0;
} else  {


if (((~__4649_21_source_qualifiers) & __4648_21_dest_qualifiers) != 0U)
{
__4640_14_okay = __4641_14_previous_qualifiers_include_const;
if (!(__4640_14_okay)) { goto __T405637448; }
}

if (!((__4648_21_dest_qualifiers & 2U) != 0U)) {
__4641_14_previous_qualifiers_include_const = 0;
}
} }

if (((*__4642_20_source_ptr_flags) & 32U) != 0U) { goto __T405637448; }
__4643_20_dest_ptr_flags++;
__4642_20_source_ptr_flags++;
} __T405637448:;
return __4640_14_okay;
}



static int _ZN28_INTERNAL_7_throw_c_721f9a2e35check_exception_type_specificationsEP31an_exception_type_specificationPKSt9type_infojPjPciPPvPS1_Pi(
an_exception_type_specification_ptr __4684_39_etsp, 
a_type_info_impl_ptr __4685_26_type_info, 
an_ETS_flag_set __4686_22_flags, 
an_ETS_flag_set *__4687_23_ptr_flags, 
an_access_flag_string __4688_27_access_flags, 
a_boolean __4689_16_use_access_flags, 
void **__4690_14_object_ptr, 
an_exception_type_specification_ptr *__4691_40_etsp_found, 
a_boolean *__4692_17_nullptr_conv_needed)
#line 978
{
auto int __4704_16_result = 0;
auto int __4705_16_index = 0;
auto a_boolean __4706_21_done = 0;
auto a_boolean __4707_14_is_ptr;

if (__4692_17_nullptr_conv_needed != ((a_boolean *)0)) { (*__4692_17_nullptr_conv_needed) = 0; }
(*__4691_40_etsp_found) = ((an_exception_type_specification_ptr)0);
__4707_14_is_ptr = ((a_boolean)(((__4686_22_flags & 1U) != 0U) || (__4687_23_ptr_flags != ((an_ETS_flag_set *)0))));
do { auto void **__T405746800; auto a_type_info_impl_ptr __T405747448; auto a_type_info_impl_ptr __T405748184; auto a_boolean __T405748920;
auto a_boolean __4713_23_match = 0;
auto void *__4714_25_new_ptr;
auto a_boolean __4715_16_ets_is_ptr;
auto a_boolean __4716_16_is_single_ptr;
auto a_boolean __4717_16_ets_is_single_ptr;
auto an_access_flag_string __4718_27_local_access_flags; __4718_27_local_access_flags = __4688_27_access_flags;



__4715_16_ets_is_ptr = ((a_boolean)((((__4684_39_etsp->flags) & 1U) != 0U) || ((__4684_39_etsp->ptr_flags) != ((an_ETS_flag_set *)0))));
__4717_16_ets_is_single_ptr = ((a_boolean)((((__4684_39_etsp->flags) & 1U) != 0U) || (0)));
__4716_16_is_single_ptr = ((a_boolean)(((__4686_22_flags & 1U) != 0U) || (0)));
__4705_16_index++;
if ((((__4684_39_etsp->flags) & 16U) != 0U) && (((__4684_39_etsp->flags) & 129U) == 0U)) {
__4713_23_match = 1;
} else  { if (__4715_16_ets_is_ptr != __4707_14_is_ptr) {

} else  { if (((__4684_39_etsp->type_info) == __4685_26_type_info) || ((_ZNKSt9type_info4nameEv((__4684_39_etsp->type_info))) == (_ZNKSt9type_info4nameEv(__4685_26_type_info)))) {


if (!(__4707_14_is_ptr)) {

if ((((((__4684_39_etsp->flags) & 128U) != 0U) && ((__4686_22_flags & 128U) != 0U)) && ((((__4684_39_etsp->flags) & 16U) != 0U) && (((__4684_39_etsp->flags) & 129U) != 0U))) && (!(((__4686_22_flags & 16U) != 0U) && ((__4686_22_flags & 129U) != 0U))))


{



} else  {
__4713_23_match = 1;
}
} else  { if (__4716_16_is_single_ptr != __4717_16_ets_is_single_ptr) {

} else  { auto an_exception_type_specification_ptr __T405740184; auto an_ETS_flag_set *__T405740832; if (__4716_16_is_single_ptr) {


auto an_ETS_flag_set __4750_25_source_qualifiers;
auto an_ETS_flag_set __4751_25_dest_qualifiers;
#line 1025
__4750_25_source_qualifiers = (__4686_22_flags & 6U);
__4751_25_dest_qualifiers = ((__4684_39_etsp->flags) & 6U);
if (!(((~__4751_25_dest_qualifiers) & __4750_25_source_qualifiers) != 0U))
{

if ((!((((__4684_39_etsp->flags) & 16U) != 0U) && (((__4684_39_etsp->flags) & 129U) != 0U))) || (((__4686_22_flags & 16U) != 0U) && ((__4686_22_flags & 129U) != 0U))) {




__4713_23_match = 1;
}
}

} else  {


if (((__T405740184 = __4684_39_etsp) , (__T405740832 = __4687_23_ptr_flags)) , (_ZN28_INTERNAL_7_throw_c_721f9a2e35check_pointer_levels_and_qualifiersEP31an_exception_type_specificationPj(__T405740184, __T405740832))) {
__4713_23_match = 1;
}

} } }
} } }
if (__4713_23_match) {


} else  { if (((__4715_16_ets_is_ptr) || (((__4684_39_etsp->flags) & 192U) != 0U)) && (_ZNKSt9type_infoeqERKS_(__4685_26_type_info, (((const struct _ZSt9type_info *)&(_ZTIDn.base))))))
#line 1063
{


__4713_23_match = 1;
if (__4692_17_nullptr_conv_needed != ((a_boolean *)0)) { (*__4692_17_nullptr_conv_needed) = 1; }

} else  { if (__4715_16_ets_is_ptr != __4707_14_is_ptr) {

} else  { if (!((!(((__4686_22_flags & 1U) != 0U) || (0))) || ((((__4684_39_etsp->flags) & __4686_22_flags) & 6U) == (__4686_22_flags & 6U)))) {
#line 1077
} else  { if (((((__4684_39_etsp->type_info) == ((const struct _ZSt9type_info *)(&_ZTIv))) || ((_ZNKSt9type_info4nameEv((__4684_39_etsp->type_info))) == (_ZNKSt9type_info4nameEv((((const struct _ZSt9type_info *)&(_ZTIv.base))))))) && (__4715_16_ets_is_ptr == __4707_14_is_ptr)) && (
#line 1077
__4717_16_ets_is_single_ptr))
#line 1085
{


__4713_23_match = 1;
#line 1096
} else  { if ((((!(__4707_14_is_ptr)) || ((__4716_16_is_single_ptr) && (__4717_16_ets_is_single_ptr))) && ((_ZNKSt9type_infoeqERKS_(((const struct _ZSt9type_info *)((__4685_26_type_info) ? ((struct __EDG_type_info *)((__4685_26_type_info->__vptr)[(-1)])) : ((__cxa_bad_typeid()) , ((struct 
#line 1096
__EDG_type_info *)0)))), (((const struct _ZSt9type_info *)&((_ZTIN10__cxxabiv120__si_class_type_infoE.base).base))))) || (_ZNKSt9type_infoeqERKS_(((const struct _ZSt9type_info *)((__4685_26_type_info) ? ((struct __EDG_type_info *)((__4685_26_type_info->__vptr)[(-1)])) : ((__cxa_bad_typeid()) , ((
#line 1096
struct __EDG_type_info *)0)))), (((const struct _ZSt9type_info *)&((_ZTIN10__cxxabiv121__vmi_class_type_infoE.base).base))))))) && (((((__T405746800 = __4690_14_object_ptr) , (__T405747448 = __4685_26_type_info)) , (__T405748184 = (__4684_39_etsp->type_info))) , (__T405748920 = 
#line 1096
__4689_16_use_access_flags)) , (__derived_to_base_conversion(__T405746800, (&__4714_25_new_ptr), __T405747448, __T405748184, (&__4718_27_local_access_flags), __T405748920))))
#line 1107
{
#line 1116
__4713_23_match = 1;


if (__4690_14_object_ptr != ((void **)0)) { (*__4690_14_object_ptr) = __4714_25_new_ptr; }
#line 1130
} } } } } }
if (__4713_23_match) {
__4704_16_result = __4705_16_index;
(*__4691_40_etsp_found) = __4684_39_etsp;
goto __T405737328;
}
__4706_21_done = ((a_boolean)((__4684_39_etsp->flags) & 32U));
__4684_39_etsp++;
} while (!(__4706_21_done)); __T405737328:;
return __4704_16_result;
}


static void _ZN28_INTERNAL_7_throw_c_721f9a2e21destroy_thrown_objectEP19a_throw_stack_entry( a_throw_stack_entry_ptr __4868_59_tsep)
#line 1149
{
auto void *__4875_12_object_address;
auto a_throw_stack_entry_ptr __4876_27_primary_tsep;



__4876_27_primary_tsep = ((__4868_59_tsep->is_rethrow) ? (__4868_59_tsep->primary_entry) : __4868_59_tsep);
if (!(__4868_59_tsep->discard_entry)) {


(__4868_59_tsep->discard_entry) = ((a_byte_boolean)1U);



if (__4868_59_tsep->is_internal) { (__4876_27_primary_tsep->discard_entry) = ((a_byte_boolean)1U); }
if (!((__4876_27_primary_tsep->use_count) > 0UL)) { { fprintf(stderr, ((const char *)"Assertion failed in file \"%s\", line %d\n"), ((const char *)("lib_src/throw.c")), 1164); abort(); } } ;
(__4876_27_primary_tsep->use_count)--;
}
#line 1178
if (((__4876_27_primary_tsep->use_count) == 0UL) && (!(__4876_27_primary_tsep->dtor_called))) {

(__4876_27_primary_tsep->dtor_called) = ((a_byte_boolean)1U);
__4875_12_object_address = (__4876_27_primary_tsep->object_address);
if ((__4876_27_primary_tsep->object_copy_complete) && (!((((__4876_27_primary_tsep->flags) & 1U) != 0U) || ((__4876_27_primary_tsep->ptr_flags) != ((an_ETS_flag_set *)0)))))
{
#line 1189
auto a_destructor_ptr __4914_24_dtor_ptr;
__4914_24_dtor_ptr = ((a_destructor_ptr)(__4876_27_primary_tsep->destructor));
if (__4914_24_dtor_ptr != ((a_destructor_ptr)0)) {



__4914_24_dtor_ptr(__4875_12_object_address);

}
}
} 
}


void __exception_started(void)
#line 1211
{
auto a_throw_stack_entry_ptr __4937_27_tsep; __4937_27_tsep = curr_throw_stack_entry;


((__4937_27_tsep->throw_marker).next) = __curr_eh_stack_entry;
__curr_eh_stack_entry = (&(__4937_27_tsep->throw_marker));
(__4937_27_tsep->object_evaluation_complete) = ((a_byte_boolean)1U); 
}


void __exception_caught(void)




{
if (!(((int)(__curr_eh_stack_entry->kind)) == 3)) { { fprintf(stderr, ((const char *)"Assertion failed in file \"%s\", line %d\n"), ((const char *)("lib_src/throw.c")), 1228); abort(); } }
;
#line 1234
__curr_eh_stack_entry = (__curr_eh_stack_entry->next); 
}


void __throw(void)




{ static const struct __C1 __T405970808 = {((void (*)())0),0LL};
auto an_eh_stack_entry_ptr __4969_26_ehsep;
auto an_eh_stack_entry_ptr __4970_26_destination_ehsep = ((an_eh_stack_entry_ptr)0);



auto int __4974_10_destination_catch_value;
auto void *__4975_12_object_ptr;
auto void *__4976_12_object_buffer_ptr;
auto a_type_info_impl_ptr __4977_25_thrown_type_info;
auto an_ETS_flag_set __4978_20_throw_flags;
auto an_ETS_flag_set *__4979_21_throw_ptr_flags;

auto an_exception_type_specification_ptr __4981_5_etsp_found = ((an_exception_type_specification_ptr)0);
auto a_boolean __4982_15_nullptr_conv_needed = 0;
auto an_access_flag_string __4983_33_access_flags;
auto a_boolean __4984_15_use_access_flags;

if (!(curr_throw_stack_entry->object_evaluation_complete)) {


__exception_started();
}


(curr_throw_stack_entry->object_copy_complete) = ((a_byte_boolean)1U);


__4977_25_thrown_type_info = (curr_throw_stack_entry->type_info);
__4978_20_throw_flags = (curr_throw_stack_entry->flags);
__4979_21_throw_ptr_flags = (curr_throw_stack_entry->ptr_flags);
__4983_33_access_flags = (curr_throw_stack_entry->access_flags);
__4984_15_use_access_flags = ((a_boolean)(curr_throw_stack_entry->use_access_flags));
#line 1281
if (((__4978_20_throw_flags & 1U) != 0U) || (__4979_21_throw_ptr_flags != ((an_ETS_flag_set *)0))) {



__4976_12_object_buffer_ptr = (curr_throw_stack_entry->object_address);
__4975_12_object_ptr = (*((void **)__4976_12_object_buffer_ptr));
__4976_12_object_buffer_ptr = ((void *)(&(curr_throw_stack_entry->pointer_buffer)));
} else  {


__4976_12_object_buffer_ptr = (curr_throw_stack_entry->object_address);
__4975_12_object_ptr = __4976_12_object_buffer_ptr;
}
#line 1301
__4969_26_ehsep = __curr_eh_stack_entry;
if (!(__4969_26_ehsep == (&(curr_throw_stack_entry->throw_marker)))) { { fprintf(stderr, ((const char *)"Assertion failed in file \"%s\", line %d\n"), ((const char *)("lib_src/throw.c")), 1302); abort(); } } ;

__4969_26_ehsep = (__4969_26_ehsep->next);
while (__4969_26_ehsep != ((an_eh_stack_entry_ptr)0)) { {
auto unsigned char __5031_28_kind; __5031_28_kind = (__4969_26_ehsep->kind);
#line 1316
if (((int)__5031_28_kind) == 1) {

} else  { if (((int)__5031_28_kind) == 4) {

} else  { if ((((int)__5031_28_kind) == 0) || (((int)__5031_28_kind) == 5))
{
if ((((__4969_26_ehsep->variant).try_block).catch_info) == ((void *)0)) {

auto int __5049_13_result;
if ((((__4969_26_ehsep->variant).try_block).catch_entries) != ((an_exception_type_specification_ptr)0)) { auto an_exception_type_specification_ptr __T405916056; auto a_type_info_impl_ptr __T405916976; auto an_ETS_flag_set __T405917712; auto an_ETS_flag_set *__T405918448; auto an_access_flag_string 
#line 1325
__T405919184; auto a_boolean __T405919920;


__5049_13_result = (((((((__T405916056 = (((__4969_26_ehsep->variant).try_block).catch_entries)) , (__T405916976 = __4977_25_thrown_type_info)) , (__T405917712 = __4978_20_throw_flags)) , (__T405918448 = __4979_21_throw_ptr_flags)) , (__T405919184 = __4983_33_access_flags)) , (__T405919920 = 
#line 1328
__4984_15_use_access_flags)) , (_ZN28_INTERNAL_7_throw_c_721f9a2e35check_exception_type_specificationsEP31an_exception_type_specificationPKSt9type_infojPjPciPPvPS1_Pi(__T405916056, __T405916976, __T405917712, __T405918448, __T405919184, __T405919920, (&__4975_12_object_ptr), (&
#line 1328
__4981_5_etsp_found), (&__4982_15_nullptr_conv_needed))));
#line 1334
} else  {




__5049_13_result = 1;
}
if (__5049_13_result != 0) {
#line 1350
if (__4970_26_destination_ehsep == ((an_eh_stack_entry_ptr)0)) {
__4970_26_destination_ehsep = __4969_26_ehsep;
__4974_10_destination_catch_value = __5049_13_result;
}
if ((((__4969_26_ehsep->variant).try_block).catch_entries) != ((an_exception_type_specification_ptr)0)) {




goto __T405821832;
}
}
}
} else  { if (__4970_26_destination_ehsep != ((an_eh_stack_entry_ptr)0)) {




__4969_26_ehsep = (__4969_26_ehsep->next);
goto __T405823808;
} else  { if (((int)__5031_28_kind) == 2) {
#line 1376
auto int __5101_11_result = 0;
if (((__4969_26_ehsep->variant).throw_specification) != ((an_exception_type_specification_ptr)0)) { auto an_exception_type_specification_ptr __T405920832; auto a_type_info_impl_ptr __T405921480; auto an_ETS_flag_set __T405922216; auto an_ETS_flag_set *__T405922952; auto an_access_flag_string 
#line 1377
__T405923688; auto a_boolean __T405924424;
auto an_exception_type_specification_ptr __5103_45_dummy_etsp;
__5101_11_result = (((((((__T405920832 = ((__4969_26_ehsep->variant).throw_specification)) , (__T405921480 = __4977_25_thrown_type_info)) , (__T405922216 = __4978_20_throw_flags)) , (__T405922952 = __4979_21_throw_ptr_flags)) , (__T405923688 = __4983_33_access_flags)) , (__T405924424 = 
#line 1379
__4984_15_use_access_flags)) , (_ZN28_INTERNAL_7_throw_c_721f9a2e35check_exception_type_specificationsEP31an_exception_type_specificationPKSt9type_infojPjPciPPvPS1_Pi(__T405920832, __T405921480, __T405922216, __T405922952, __T405923688, __T405924424, ((void **)0), (&__5103_45_dummy_etsp), ((
#line 1379
a_boolean *)0))));
#line 1385
}
if (__5101_11_result == 0) {
__4970_26_destination_ehsep = __4969_26_ehsep;
goto __T405821832;
}
} else  { if (((int)__5031_28_kind) == 6) {
#line 1396
__4970_26_destination_ehsep = __4969_26_ehsep;
goto __T405821832;
} else  { if (((int)__5031_28_kind) == 3) {
#line 1404
__curr_eh_stack_entry = __4969_26_ehsep;


(curr_throw_stack_entry->in_handler) = ((a_byte_boolean)1U);
__exception_caught();
__call_terminate();
} else  {
{ fprintf(stderr, ((const char *)"Assertion failed in file \"%s\", line %d\n"), ((const char *)("lib_src/throw.c")), 1411); abort(); } ;
} } } } } } }
__4969_26_ehsep = (__4969_26_ehsep->next);
} __T405823808:; } __T405821832:;
#line 1426
__4969_26_ehsep = __curr_eh_stack_entry;

__4969_26_ehsep = (__4969_26_ehsep->next);
while (__4969_26_ehsep != __4970_26_destination_ehsep) { auto an_eh_stack_entry_ptr __T405925512; auto a_region_number __T405926160;
auto unsigned char __5155_28_kind; __5155_28_kind = (__4969_26_ehsep->kind);
#line 1440
if (((int)__5155_28_kind) == 1) {
((__T405925512 = __4969_26_ehsep) , (__T405926160 = __eh_curr_region)) , (_ZN28_INTERNAL_7_throw_c_721f9a2e7cleanupEP17an_eh_stack_entrytt(__T405925512, __T405926160, ((a_region_number)65535U)));
__eh_curr_region = (((__4969_26_ehsep->variant).function).saved_region_number);
} else  { if (((int)__5155_28_kind) == 4) {



__cleanup_vec_new_or_delete(__4969_26_ehsep);
} else  { if (((int)__5155_28_kind) == 0) {

if ((((__4969_26_ehsep->variant).try_block).catch_info) != ((void *)0)) {
#line 1461
auto a_throw_stack_entry_ptr __5186_33_tsep;
__5186_33_tsep = ((a_throw_stack_entry_ptr)(((__4969_26_ehsep->variant).try_block).catch_info));
_ZN28_INTERNAL_7_throw_c_721f9a2e21destroy_thrown_objectEP19a_throw_stack_entry(__5186_33_tsep);
}
} else  { if (((int)__5155_28_kind) == 5) {


auto a_throw_stack_entry_ptr __5193_31_tsep;
for (__5193_31_tsep = curr_throw_stack_entry; __5193_31_tsep != ((a_throw_stack_entry_ptr)0); __5193_31_tsep = (__5193_31_tsep->next)) {
if ((__5193_31_tsep->nearest_enclosing_try_block) == __4969_26_ehsep) {
(__5193_31_tsep->nearest_enclosing_try_block) = ((an_eh_stack_entry_ptr)0);
}
}
} else  { if (((int)__5155_28_kind) == 2) {

} else  { if (((int)__5155_28_kind) == 3) {

} else  { if (((int)__5155_28_kind) == 6) {


{ fprintf(stderr, ((const char *)"Assertion failed in file \"%s\", line %d\n"), ((const char *)("lib_src/throw.c")), 1481); abort(); } ;
} else  {
{ fprintf(stderr, ((const char *)"Assertion failed in file \"%s\", line %d\n"), ((const char *)("lib_src/throw.c")), 1483); abort(); } ;
} } } } } } }
__4969_26_ehsep = (__4969_26_ehsep->next);
}
#line 1494
if (__4970_26_destination_ehsep == ((an_eh_stack_entry_ptr)0)) {


(curr_throw_stack_entry->in_handler) = ((a_byte_boolean)1U);
__exception_caught();
__call_terminate();
}

if ((((int)(__4970_26_destination_ehsep->kind)) == 0) || (((int)(__4970_26_destination_ehsep->kind)) == 5))
{
#line 1510
if (((int)(((__4970_26_destination_ehsep->variant).try_block).region_number)) != ((int)__eh_curr_region))
{ auto an_eh_stack_entry_ptr __T405927424; auto a_region_number __T405928072; auto a_region_number __T405928808;

auto an_eh_stack_entry_ptr __5238_29_function_ehsep; __5238_29_function_ehsep = (__4970_26_destination_ehsep->next);
while (((int)(__5238_29_function_ehsep->kind)) != 1) {
__5238_29_function_ehsep = (__5238_29_function_ehsep->next);
}
(((__T405927424 = __5238_29_function_ehsep) , (__T405928072 = __eh_curr_region)) , (__T405928808 = (((__4970_26_destination_ehsep->variant).try_block).region_number))) , (_ZN28_INTERNAL_7_throw_c_721f9a2e7cleanupEP17an_eh_stack_entrytt(__T405927424, __T405928072, __T405928808));



__eh_curr_region = (((__4970_26_destination_ehsep->variant).try_block).region_number);
}
}




if (!(__curr_eh_stack_entry == (&(curr_throw_stack_entry->throw_marker)))) { { fprintf(stderr, ((const char *)"Assertion failed in file \"%s\", line %d\n"), ((const char *)("lib_src/throw.c")), 1529); abort(); } }
;
(__curr_eh_stack_entry->next) = __4970_26_destination_ehsep;


(curr_throw_stack_entry->in_handler) = ((a_byte_boolean)1U);
if ((((int)(__4970_26_destination_ehsep->kind)) == 0) || (((int)(__4970_26_destination_ehsep->kind)) == 5))
{
auto a_boolean __5261_15_exception_caught = 0;
__catch_clause_number = __4974_10_destination_catch_value;
if (((__4978_20_throw_flags & 1U) != 0U) || (__4979_21_throw_ptr_flags != ((an_ETS_flag_set *)0))) {
#line 1544
(*((void **)__4976_12_object_buffer_ptr)) = __4975_12_object_ptr;
__caught_object_address = __4976_12_object_buffer_ptr;
} else  { if (__4982_15_nullptr_conv_needed) {



if ((((__4981_5_etsp_found->flags) & 1U) != 0U) || ((__4981_5_etsp_found->ptr_flags) != ((an_ETS_flag_set *)0))) {

(curr_throw_stack_entry->pointer_buffer) = ((void *)0);
__caught_object_address = ((void *)(&(curr_throw_stack_entry->pointer_buffer)));
} else  { if (((__4981_5_etsp_found->flags) & 64U) != 0U) {

(curr_throw_stack_entry->ptr_to_data_member_buffer) = (-1LL);
__caught_object_address = ((void *)(&(curr_throw_stack_entry->ptr_to_data_member_buffer)));

} else  {

(curr_throw_stack_entry->ptr_to_member_function_buffer) = __T405970808;
__caught_object_address = ((void *)(&(curr_throw_stack_entry->ptr_to_member_function_buffer)));

} }
} else  {




__caught_object_address = __4975_12_object_ptr;
} }


(((__4970_26_destination_ehsep->variant).try_block).catch_info) = ((void *)curr_throw_stack_entry);
#line 1594
if (__5261_15_exception_caught) {

__exception_caught();
}
longjmp(((((__4970_26_destination_ehsep->variant).try_block).setjmp_buffer)), 1);
} else  { if (((int)(__4970_26_destination_ehsep->kind)) == 2)
{




__curr_eh_stack_entry = (__curr_eh_stack_entry->next);
#line 1613
__call_unexpected();
} else  { if (((int)(__4970_26_destination_ehsep->kind)) == 6)
{




__curr_eh_stack_entry = (__curr_eh_stack_entry->next);
__call_terminate();
} } } 
}


static void _ZN28_INTERNAL_7_throw_c_721f9a2e16push_throw_stackEPKSt9type_infoPFvPvEjPjPciS3_iiP19a_throw_stack_entry( a_type_info_impl_ptr __5351_54_type_info, 
a_destructor_ptr __5352_31_destructor, 
an_ETS_flag_set __5353_30_flags, 
an_ETS_flag_set *__5354_31_ptr_flags, 
an_access_flag_string __5355_54_access_flags, 
a_boolean __5356_54_use_access_flags, 
void *__5357_21_object_address, 
a_boolean __5358_25_is_rethrow, 
a_boolean __5359_25_is_internal, 
a_throw_stack_entry_ptr __5360_54_primary_entry)



{
auto a_throw_stack_entry_ptr __5365_27_tsep;
auto an_eh_stack_entry_ptr __5366_26_ehsep;

__5365_27_tsep = ((a_throw_stack_entry_ptr)(_ZN28_INTERNAL_7_throw_c_721f9a2e17eh_alloc_on_stackEy(240ULL)));
#line 1650
__5366_26_ehsep = __curr_eh_stack_entry;
while (__5366_26_ehsep != ((an_eh_stack_entry_ptr)0)) {

if (((((int)(__5366_26_ehsep->kind)) == 0) || (((int)(__5366_26_ehsep->kind)) == 5)) && ((((__5366_26_ehsep->variant).try_block).catch_info) == ((void *)0))) {

goto __T405943136; }
__5366_26_ehsep = (__5366_26_ehsep->next);
} __T405943136:;
(__5365_27_tsep->nearest_enclosing_try_block) = __5366_26_ehsep;
if (curr_throw_stack_entry != ((a_throw_stack_entry_ptr)0)) {
if ((curr_throw_stack_entry->nearest_enclosing_try_block) == __5366_26_ehsep) {


_ZN28_INTERNAL_7_throw_c_721f9a2e21destroy_thrown_objectEP19a_throw_stack_entry(curr_throw_stack_entry);
}
}
(__5365_27_tsep->next) = curr_throw_stack_entry;
curr_throw_stack_entry = __5365_27_tsep;
(__5365_27_tsep->type_info) = __5351_54_type_info;
(__5365_27_tsep->destructor) = __5352_31_destructor;
(__5365_27_tsep->flags) = __5353_30_flags;
(__5365_27_tsep->ptr_flags) = __5354_31_ptr_flags;
(__5365_27_tsep->access_flags) = __5355_54_access_flags;
(__5365_27_tsep->use_access_flags) = ((a_byte_boolean)__5356_54_use_access_flags);
(__5365_27_tsep->object_address) = __5357_21_object_address;
(__5365_27_tsep->pointer_buffer) = ((void *)0);
(__5365_27_tsep->primary_entry) = __5360_54_primary_entry;
(__5365_27_tsep->use_count) = 0UL;


if (__5359_25_is_internal) {

} else  { if (__5358_25_is_rethrow) {
(__5360_54_primary_entry->use_count)++;
} else  {
(__5365_27_tsep->use_count)++;
} }
(__5365_27_tsep->is_rethrow) = ((a_byte_boolean)__5358_25_is_rethrow);
(__5365_27_tsep->is_internal) = ((a_byte_boolean)__5359_25_is_internal);
(__5365_27_tsep->dtor_called) = ((a_byte_boolean)0U);
(__5365_27_tsep->discard_entry) = ((a_byte_boolean)0U);
(__5365_27_tsep->in_handler) = ((a_byte_boolean)0U);
(__5365_27_tsep->object_copy_complete) = ((a_byte_boolean)0U);
(__5365_27_tsep->object_evaluation_complete) = ((a_byte_boolean)0U);
((__5365_27_tsep->throw_marker).next) = ((an_eh_stack_entry_ptr)0);
((__5365_27_tsep->throw_marker).kind) = ehsek_throw_processing_marker; 
}


static void _ZN28_INTERNAL_7_throw_c_721f9a2e12rethrow_fullEi( a_boolean __5424_36_is_internal)




{ auto a_type_info_impl_ptr __T406070592; auto a_destructor_ptr __T406071240; auto an_ETS_flag_set __T406071976; auto an_ETS_flag_set *__T406072712; auto an_access_flag_string __T406073448; auto a_boolean __T406074184; auto void *__T406074920; auto a_boolean __T406075656; auto 
#line 1704
a_throw_stack_entry_ptr __T406076392;
auto a_throw_stack_entry_ptr __5430_27_tsep; __5430_27_tsep = curr_throw_stack_entry;


for (; __5430_27_tsep != ((a_throw_stack_entry_ptr)0); __5430_27_tsep = (__5430_27_tsep->next)) {
if ((__5430_27_tsep->in_handler) && (!(__5430_27_tsep->is_rethrow))) { goto __T406065888; }
} __T406065888:;
if (__5430_27_tsep == ((a_throw_stack_entry_ptr)0)) {

__call_terminate();
}
(((((((((__T406070592 = (__5430_27_tsep->type_info)) , (__T406071240 = (__5430_27_tsep->destructor))) , (__T406071976 = (__5430_27_tsep->flags))) , (__T406072712 = (__5430_27_tsep->ptr_flags))) , (__T406073448 = (__5430_27_tsep->access_flags))) , (__T406074184 = ((a_boolean)(__5430_27_tsep->
#line 1715
use_access_flags)))) , (__T406074920 = (__5430_27_tsep->object_address))) , (__T406075656 = __5424_36_is_internal)) , (__T406076392 = __5430_27_tsep)) , (_ZN28_INTERNAL_7_throw_c_721f9a2e16push_throw_stackEPKSt9type_infoPFvPvEjPjPciS3_iiP19a_throw_stack_entry(__T406070592, __T406071240, __T406071976
#line 1715
, __T406072712, __T406073448, __T406074184, __T406074920, 1, __T406075656, __T406076392));
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
void *__throw_setup_ptr( a_type_info_impl_ptr __5491_56_type_info, 
a_sizeof_t __5492_35_size, 
an_ETS_flag_set *__5493_31_ptr_flags)
#line 1774
{ auto a_type_info_impl_ptr __T406087232; auto an_ETS_flag_set *__T406087880; auto void *__T406088616;
auto void *__5500_12_object_address;

__5500_12_object_address = ((void *)(_ZN28_INTERNAL_7_throw_c_721f9a2e17eh_alloc_on_stackEy(__5492_35_size)));
(((__T406087232 = __5491_56_type_info) , (__T406087880 = __5493_31_ptr_flags)) , (__T406088616 = __5500_12_object_address)) , (_ZN28_INTERNAL_7_throw_c_721f9a2e16push_throw_stackEPKSt9type_infoPFvPvEjPjPciS3_iiP19a_throw_stack_entry(__T406087232, ((a_destructor_ptr)0), 0U, __T406087880, ((
#line 1778
an_access_flag_string)0), 0, __T406088616, 0, 0, ((a_throw_stack_entry_ptr)0)));
#line 1784
return __5500_12_object_address;
}




void *__throw_setup( a_type_info_impl_ptr __5515_52_type_info, 
a_sizeof_t __5516_33_size, 
an_ETS_flag_set __5517_28_ets_flags)
#line 1798
{ auto a_type_info_impl_ptr __T406097528; auto a_destructor_ptr __T406098176; auto an_ETS_flag_set __T406098912; auto void *__T406099648;
auto void *__5524_12_object_address;
auto a_destructor_ptr __5525_21_destructor;
#line 1808
__5525_21_destructor = ((a_destructor_ptr)0);

__5524_12_object_address = ((void *)(_ZN28_INTERNAL_7_throw_c_721f9a2e17eh_alloc_on_stackEy(__5516_33_size)));
((((__T406097528 = __5515_52_type_info) , (__T406098176 = __5525_21_destructor)) , (__T406098912 = __5517_28_ets_flags)) , (__T406099648 = __5524_12_object_address)) , (_ZN28_INTERNAL_7_throw_c_721f9a2e16push_throw_stackEPKSt9type_infoPFvPvEjPjPciS3_iiP19a_throw_stack_entry(__T406097528, 
#line 1811
__T406098176, __T406098912, ((an_ETS_flag_set *)0), ((an_access_flag_string)0), 0, __T406099648, 0, 0, ((a_throw_stack_entry_ptr)0)));
#line 1817
return __5524_12_object_address;
}



void *__throw_setup_dtor( a_type_info_impl_ptr __5547_57_type_info, 
a_sizeof_t __5548_35_size, 
int __5549_20_ets_flags, 
a_destructor_ptr __5550_24_destructor)
#line 1834
{ auto a_type_info_impl_ptr __T406107568; auto a_destructor_ptr __T406108216; auto an_ETS_flag_set __T406108952; auto void *__T406109688;
auto void *__5560_12_object_address;

__5560_12_object_address = ((void *)(_ZN28_INTERNAL_7_throw_c_721f9a2e17eh_alloc_on_stackEy(__5548_35_size)));
((((__T406107568 = __5547_57_type_info) , (__T406108216 = __5550_24_destructor)) , (__T406108952 = ((an_ETS_flag_set)__5549_20_ets_flags))) , (__T406109688 = __5560_12_object_address)) , (_ZN28_INTERNAL_7_throw_c_721f9a2e16push_throw_stackEPKSt9type_infoPFvPvEjPjPciS3_iiP19a_throw_stack_entry(
#line 1838
__T406107568, __T406108216, __T406108952, ((an_ETS_flag_set *)0), ((an_access_flag_string)0), 0, __T406109688, 0, 0, ((a_throw_stack_entry_ptr)0)));
#line 1844
return __5560_12_object_address;
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
auto a_throw_stack_entry_ptr __5625_29_tsep;
auto a_boolean __5626_17_is_rethrow;
auto void *__5627_13_object_address;
#line 1900
__5625_29_tsep = curr_throw_stack_entry;
__5626_17_is_rethrow = ((a_boolean)(__5625_29_tsep->is_rethrow));
__5627_13_object_address = (__5625_29_tsep->object_address);


if (!((__5626_17_is_rethrow) || (__5625_29_tsep->dtor_called))) { { fprintf(stderr, ((const char *)"Assertion failed in file \"%s\", line %d\n"), ((const char *)("lib_src/throw.c")), 1905); abort(); } } ;

curr_throw_stack_entry = (__5625_29_tsep->next);



_ZN28_INTERNAL_7_throw_c_721f9a2e16eh_free_on_stackEPv(((void *)__5625_29_tsep));
if (!(__5626_17_is_rethrow)) {

_ZN28_INTERNAL_7_throw_c_721f9a2e16eh_free_on_stackEPv(__5627_13_object_address);
}
} 
#line 1922
}


void __destroy_exception_object(void)
#line 1934
{
auto a_throw_stack_entry_ptr __5660_27_tsep;
#line 1942
for (__5660_27_tsep = curr_throw_stack_entry; __5660_27_tsep != ((a_throw_stack_entry_ptr)0); __5660_27_tsep = (__5660_27_tsep->next)) {
if (((__5660_27_tsep->in_handler) && (!(__5660_27_tsep->dtor_called))) && (!(__5660_27_tsep->discard_entry))) { goto __T406133936; }
} __T406133936:;
if (!(__5660_27_tsep != ((a_throw_stack_entry_ptr)0))) { { fprintf(stderr, ((const char *)"Assertion failed in file \"%s\", line %d\n"), ((const char *)("lib_src/throw.c")), 1945); abort(); } } ;



if (__5660_27_tsep == curr_throw_stack_entry) {
__free_thrown_object();
} else  {
_ZN28_INTERNAL_7_throw_c_721f9a2e21destroy_thrown_objectEP19a_throw_stack_entry(__5660_27_tsep);
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


void __type_of_thrown_object( a_type_info_impl_ptr *__5717_61_type, 
an_ETS_flag_set *__5718_29_flags, 
an_ETS_flag_set **__5719_30_ptr_flags)




{
if (!(curr_throw_stack_entry != ((a_throw_stack_entry_ptr)0))) { { fprintf(stderr, ((const char *)"Assertion failed in file \"%s\", line %d\n"), ((const char *)("lib_src/throw.c")), 2000); abort(); } } ;
(*__5717_61_type) = (curr_throw_stack_entry->type_info);
(*__5718_29_flags) = (curr_throw_stack_entry->flags);
(*__5719_30_ptr_flags) = (curr_throw_stack_entry->ptr_flags); 
}


a_boolean __can_throw_type( a_type_info_impl_ptr __5732_58_type, 
an_ETS_flag_set __5733_26_flags, 
an_ETS_flag_set *__5734_27_ptr_flags)
#line 2016
{
auto a_boolean __5742_14_result = 0;
auto an_eh_stack_entry_ptr __5743_25_ehsep;

__5743_25_ehsep = __curr_eh_stack_entry;
for (__5743_25_ehsep = __curr_eh_stack_entry; __5743_25_ehsep != ((an_eh_stack_entry_ptr)0); __5743_25_ehsep = (__5743_25_ehsep->next)) {
if (((int)(__5743_25_ehsep->kind)) == 2) { goto __T406158016; }
} __T406158016:;
if (!(__5743_25_ehsep != ((an_eh_stack_entry_ptr)0))) { { fprintf(stderr, ((const char *)"Assertion failed in file \"%s\", line %d\n"), ((const char *)("lib_src/throw.c")), 2024); abort(); } } ;
if (((__5743_25_ehsep->variant).throw_specification) != ((an_exception_type_specification_ptr)0)) { auto an_exception_type_specification_ptr __T406169392; auto a_type_info_impl_ptr __T406170040; auto an_ETS_flag_set __T406170776; auto an_ETS_flag_set *__T406171512;
auto an_exception_type_specification_ptr __5751_41_dummy_etsp;
auto int __5752_13_catch_pos;
__5752_13_catch_pos = (((((__T406169392 = ((__5743_25_ehsep->variant).throw_specification)) , (__T406170040 = __5732_58_type)) , (__T406170776 = __5733_26_flags)) , (__T406171512 = __5734_27_ptr_flags)) , (
#line 2028
_ZN28_INTERNAL_7_throw_c_721f9a2e35check_exception_type_specificationsEP31an_exception_type_specificationPKSt9type_infojPjPciPPvPS1_Pi(__T406169392, __T406170040, __T406170776, __T406171512, ((an_access_flag_string)0), 0, ((void **)0), (&__5751_41_dummy_etsp), ((a_boolean *)0))));
#line 2034
if (__5752_13_catch_pos != 0) { __5742_14_result = 1; }
}
return __5742_14_result;
}
