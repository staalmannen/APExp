/* Translated by the Edison Design Group C++/C front end (version 7.0) */
/* Wed Oct  7 03:19:07 2026 */
extern int __EDGCPFE__7_0;
void *memcpy(void *,const void *,unsigned long);
void *memset(void *,int,unsigned long);

# 1 "lib_src/vla_alloc.c"
# 49 "/usr/include/x86_64-linux-gnu/bits/types/struct_FILE.h" 3
struct _IO_FILE;
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
# 45 "lib_src/vla_alloc.c"
struct a_vla_allocation;
# 64
struct a_vla_pool;
# 66 "lib_src/basics.h"
typedef unsigned char a_byte;
# 214 "/usr/lib/gcc/x86_64-linux-gnu/13/include/stddef.h" 3
typedef unsigned long size_t;
# 7 "/usr/include/x86_64-linux-gnu/bits/types/FILE.h" 3
typedef struct _IO_FILE FILE;
# 145 "/usr/lib/gcc/x86_64-linux-gnu/13/include/stddef.h" 3
typedef long ptrdiff_t;
# 44 "lib_src/vla_alloc.c"
typedef struct a_vla_allocation *a_vla_allocation_ptr;
struct a_vla_allocation {


a_byte *block;


a_byte *storage;


void *frame_marker;};
# 63
typedef struct a_vla_pool *a_vla_pool_ptr;
struct a_vla_pool {


a_vla_allocation_ptr allocations;



ptrdiff_t last_allocation;


ptrdiff_t capacity;


a_byte *normal_block;

ptrdiff_t normal_offset;


a_byte *spare_block;};


typedef struct a_vla_pool a_vla_pool;
# 672 "/usr/include/stdlib.h" 3
extern __attribute__((__alloc_size__(1))) __attribute__((__malloc__)) __attribute__((__nothrow__)) void *malloc(size_t __size);
# 683
extern __attribute__((__alloc_size__(2))) __attribute__((__nothrow__)) void *realloc(void *__ptr, size_t __size);



extern __attribute__((__nothrow__)) void free(void *__ptr);
# 730
extern __attribute__((__nothrow__)) __attribute__((__noreturn__)) void abort(void);
# 357 "/usr/include/stdio.h" 3
extern int fprintf(FILE *__stream, const char *__format, ...);
# 36 "lib_src/error.h"
extern __attribute__((__noreturn__)) void __abort_execution(enum an_error_code err_code);
# 97 "lib_src/vla_alloc.c"
static void _ZN33_INTERNAL_11_vla_alloc_c_be8bd49b18init_curr_vla_poolEv(void);
# 118
static void _ZN33_INTERNAL_11_vla_alloc_c_be8bd49b31increase_curr_vla_pool_capacityEv(void);
# 133
static void _ZN33_INTERNAL_11_vla_alloc_c_be8bd49b21free_dead_allocationsEPv(void *ptr);
# 187
extern void __vla_alloc(void *ptr, ptrdiff_t n_bytes);
# 278
extern void __vla_dealloc(void *ptr);
# 325
extern void __vla_dealloc_eh(void *ptr);
# 151 "/usr/include/stdio.h" 3
extern FILE *stderr;
# 94 "lib_src/vla_alloc.c"
static a_vla_pool_ptr curr_vla_pool;
# 103
static a_vla_pool _ZZN33_INTERNAL_11_vla_alloc_c_be8bd49b18init_curr_vla_poolEvE4pool;
# 97
static void _ZN33_INTERNAL_11_vla_alloc_c_be8bd49b18init_curr_vla_poolEv(void)




{

(_ZZN33_INTERNAL_11_vla_alloc_c_be8bd49b18init_curr_vla_poolEvE4pool.last_allocation) = (-1L);
(_ZZN33_INTERNAL_11_vla_alloc_c_be8bd49b18init_curr_vla_poolEvE4pool.capacity) = 250L;
(_ZZN33_INTERNAL_11_vla_alloc_c_be8bd49b18init_curr_vla_poolEvE4pool.allocations) = ((a_vla_allocation_ptr)(malloc((((unsigned long)(_ZZN33_INTERNAL_11_vla_alloc_c_be8bd49b18init_curr_vla_poolEvE4pool.capacity)) * 24UL))));

if ((_ZZN33_INTERNAL_11_vla_alloc_c_be8bd49b18init_curr_vla_poolEvE4pool.allocations) == ((a_vla_allocation_ptr)0)) {
__abort_execution(ec_vla_allocation_failed);
}
(_ZZN33_INTERNAL_11_vla_alloc_c_be8bd49b18init_curr_vla_poolEvE4pool.normal_block) = ((a_byte *)0);
(_ZZN33_INTERNAL_11_vla_alloc_c_be8bd49b18init_curr_vla_poolEvE4pool.normal_offset) = 32700L;
(_ZZN33_INTERNAL_11_vla_alloc_c_be8bd49b18init_curr_vla_poolEvE4pool.spare_block) = ((a_byte *)0);
curr_vla_pool = (&_ZZN33_INTERNAL_11_vla_alloc_c_be8bd49b18init_curr_vla_poolEvE4pool); 
}


static void _ZN33_INTERNAL_11_vla_alloc_c_be8bd49b31increase_curr_vla_pool_capacityEv(void)



{ auto void *__T711314728; auto unsigned long __T711315376;
(curr_vla_pool->capacity) *= 2L;
(curr_vla_pool->allocations) = ((a_vla_allocation_ptr)(((__T711314728 = ((void *)(curr_vla_pool->allocations))) , (__T711315376 = (((unsigned long)(curr_vla_pool->capacity)) * 24UL))) , (realloc(__T711314728, __T711315376))));


if ((curr_vla_pool->allocations) == ((a_vla_allocation_ptr)0)) {
__abort_execution(ec_vla_allocation_failed);
} 
}


static void _ZN33_INTERNAL_11_vla_alloc_c_be8bd49b21free_dead_allocationsEPv( void *__11147_42_ptr)
# 141
{
auto ptrdiff_t __11156_14_alloc_idx; __11156_14_alloc_idx = (curr_vla_pool->last_allocation);


for (; __11156_14_alloc_idx >= 0L; --__11156_14_alloc_idx) {
auto a_vla_allocation_ptr __11160_27_allocation; __11160_27_allocation = ((curr_vla_pool->allocations) + __11156_14_alloc_idx);
if (((char *)(&__11156_14_alloc_idx)) > ((char *)__11147_42_ptr)) {

if (((char *)(__11160_27_allocation->frame_marker)) < ((char *)__11147_42_ptr)) {
goto __T711322808;
}
} else  {

if (((char *)(__11160_27_allocation->frame_marker)) > ((char *)__11147_42_ptr)) {
goto __T711322808;
}
}
if ((__11160_27_allocation->block) == ((a_byte *)0)) {

free(((void *)(__11160_27_allocation->storage)));
} else  {


auto ptrdiff_t __11178_18_offset; __11178_18_offset = ((__11160_27_allocation->storage) - (__11160_27_allocation->block));
if (__11178_18_offset == 0L) {




if ((curr_vla_pool->spare_block) == ((a_byte *)0)) {
(curr_vla_pool->spare_block) = (__11160_27_allocation->block);
} else  {
free(((void *)(__11160_27_allocation->block)));
}
(curr_vla_pool->normal_block) = ((a_byte *)0);
(curr_vla_pool->normal_offset) = 32700L;
} else  {
(curr_vla_pool->normal_offset) = __11178_18_offset;
}
(curr_vla_pool->normal_offset) = __11178_18_offset;
}
} __T711322808:;
(curr_vla_pool->last_allocation) = __11156_14_alloc_idx; 
}


void __vla_alloc( void *__11201_39_ptr, 
ptrdiff_t __11202_38_n_bytes)




{
auto ptrdiff_t __11208_25_alloc_idx; auto ptrdiff_t __11208_36_padding;
auto a_vla_allocation_ptr __11209_25_allocation;

if (__11202_38_n_bytes == 0L) {


__11202_38_n_bytes = 1L;
} else  { if (__11202_38_n_bytes < 0L) {
__abort_execution(ec_negative_vla_size);
} }
__11208_36_padding = (8L - (__11202_38_n_bytes % 8L));
if (__11208_36_padding != 8L) {


__11202_38_n_bytes += __11208_36_padding;
}
if (curr_vla_pool == ((a_vla_pool_ptr)0)) {

_ZN33_INTERNAL_11_vla_alloc_c_be8bd49b18init_curr_vla_poolEv();
} else  {



auto ptrdiff_t __11231_16_last_idx; __11231_16_last_idx = (curr_vla_pool->last_allocation);
if (__11231_16_last_idx >= 0L) {
if (((char *)(&__11231_16_last_idx)) > ((char *)__11201_39_ptr)) {

if (((char *)(((curr_vla_pool->allocations)[__11231_16_last_idx]).frame_marker)) > ((char *)(&__11208_25_alloc_idx)))
{
_ZN33_INTERNAL_11_vla_alloc_c_be8bd49b21free_dead_allocationsEPv(((void *)(&__11208_25_alloc_idx)));
}
} else  {

if (((char *)(((curr_vla_pool->allocations)[__11231_16_last_idx]).frame_marker)) < ((char *)(&__11208_25_alloc_idx)))
{
_ZN33_INTERNAL_11_vla_alloc_c_be8bd49b21free_dead_allocationsEPv(((void *)(&__11208_25_alloc_idx)));
}
}
}
}
__11208_25_alloc_idx = (++(curr_vla_pool->last_allocation));
if (__11208_25_alloc_idx == (curr_vla_pool->capacity)) {

_ZN33_INTERNAL_11_vla_alloc_c_be8bd49b31increase_curr_vla_pool_capacityEv();
}
__11209_25_allocation = ((curr_vla_pool->allocations) + __11208_25_alloc_idx);
(__11209_25_allocation->frame_marker) = ((void *)(&__11208_25_alloc_idx));
if (__11202_38_n_bytes >= 4096L) {

auto a_byte *__11257_14_special_block; __11257_14_special_block = ((a_byte *)(malloc(((size_t)__11202_38_n_bytes))));
if (__11257_14_special_block == ((a_byte *)0)) {
__abort_execution(ec_vla_allocation_failed);
}
(__11209_25_allocation->storage) = ((*((a_byte **)__11201_39_ptr)) = __11257_14_special_block);


(__11209_25_allocation->block) = ((a_byte *)0);
} else  {

if (((curr_vla_pool->normal_block) == ((a_byte *)0)) || ((32700L - (curr_vla_pool->normal_offset)) < (__11202_38_n_bytes - 1L)))
{



if ((curr_vla_pool->spare_block) != ((a_byte *)0)) {
(curr_vla_pool->normal_block) = (curr_vla_pool->spare_block);
(curr_vla_pool->spare_block) = ((a_byte *)0);
} else  {
(curr_vla_pool->normal_block) = ((a_byte *)(malloc(32700UL)));
if ((curr_vla_pool->normal_block) == ((a_byte *)0)) {
__abort_execution(ec_vla_allocation_failed);
}
}
(curr_vla_pool->normal_offset) = 0L;
}
(__11209_25_allocation->storage) = ((*((a_byte **)__11201_39_ptr)) = ((a_byte *)((curr_vla_pool->normal_block) + (curr_vla_pool->normal_offset))));


(__11209_25_allocation->block) = (curr_vla_pool->normal_block);
(curr_vla_pool->normal_offset) += __11202_38_n_bytes;
} 
}


void __vla_dealloc( void *__11292_36_ptr)



{
auto ptrdiff_t __11297_14_alloc_idx; __11297_14_alloc_idx = (curr_vla_pool->last_allocation);



for (; ; --__11297_14_alloc_idx) {
auto a_vla_allocation_ptr __11302_27_allocation; __11302_27_allocation = ((curr_vla_pool->allocations) + __11297_14_alloc_idx);

if (!(__11297_14_alloc_idx >= 0L)) { { fprintf(stderr, ((const char *)"Assertion failed in file \"%s\", line %d\n"), ((const char *)("lib_src/vla_alloc.c")), 290); abort(); } } ;
if ((__11302_27_allocation->block) == ((a_byte *)0)) {

free(((void *)(__11302_27_allocation->storage)));
if ((__11302_27_allocation->storage) == (*((a_byte **)__11292_36_ptr))) {
goto __T711386560;
}
} else  {


auto ptrdiff_t __11314_18_offset; __11314_18_offset = ((__11302_27_allocation->storage) - (__11302_27_allocation->block));
if (__11314_18_offset == 0L) {




if ((curr_vla_pool->spare_block) == ((a_byte *)0)) {
(curr_vla_pool->spare_block) = (__11302_27_allocation->block);
} else  {
free(((void *)(__11302_27_allocation->block)));
}
(curr_vla_pool->normal_block) = ((a_byte *)0);
(curr_vla_pool->normal_offset) = 32700L;
} else  {
(curr_vla_pool->normal_offset) = __11314_18_offset;
}
if ((__11302_27_allocation->storage) == (*((a_byte **)__11292_36_ptr))) {
goto __T711386560;
}
}
} __T711386560:;
(curr_vla_pool->last_allocation) = (__11297_14_alloc_idx - 1L); 
}


void __vla_dealloc_eh( void *__11339_39_ptr)




{
__vla_dealloc(((void *)(&__11339_39_ptr))); 
}
