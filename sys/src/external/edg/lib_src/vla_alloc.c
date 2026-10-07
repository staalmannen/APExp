/* Translated by the Edison Design Group C++/C front end (version 7.0) */
/* Wed Oct  7 07:14:44 2026 */
extern int __EDGCPFE__7_0;
void *memcpy(void *,const void *,unsigned long long);
void *memset(void *,int,unsigned long long);

#line 1 "lib_src/vla_alloc.c"
#line 56 "ape-sys/_iofile.h"
struct _IO_FILE;
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
#line 45 "lib_src/vla_alloc.c"
struct a_vla_allocation;
#line 64
struct a_vla_pool;
#line 66 "lib_src/basics.h"
typedef unsigned char a_byte;
#line 4 "ape-arch/stddef_arch.h"
typedef long long _ptrdiff_t;
#line 10
typedef unsigned long long size_t;
#line 20 "ape-sys/stddef.h"
typedef _ptrdiff_t ptrdiff_t;
#line 21 "ape-sys/stdio.h"
typedef struct _IO_FILE FILE;
#line 44 "lib_src/vla_alloc.c"
typedef struct a_vla_allocation *a_vla_allocation_ptr;
struct a_vla_allocation {


a_byte *block;


a_byte *storage;


void *frame_marker;};
#line 63
typedef struct a_vla_pool *a_vla_pool_ptr;
struct a_vla_pool {


a_vla_allocation_ptr allocations;



ptrdiff_t last_allocation;


ptrdiff_t capacity;


a_byte *normal_block;

ptrdiff_t normal_offset;


a_byte *spare_block;};


typedef struct a_vla_pool a_vla_pool;
#line 44 "ape-sys/stdlib.h"
extern void free(void *);
extern void *malloc(size_t);
extern void *realloc(void *, size_t);
extern void abort(void);
#line 71 "ape-sys/stdio.h"
extern int fprintf(FILE *, const char *, ...);
#line 36 "lib_src/error.h"
extern void __abort_execution(enum an_error_code err_code);
#line 97 "lib_src/vla_alloc.c"
static void _ZN33_INTERNAL_11_vla_alloc_c_be8bd49b18init_curr_vla_poolEv(void);
#line 118
static void _ZN33_INTERNAL_11_vla_alloc_c_be8bd49b31increase_curr_vla_pool_capacityEv(void);
#line 133
static void _ZN33_INTERNAL_11_vla_alloc_c_be8bd49b21free_dead_allocationsEPv(void *ptr);
#line 187
extern void __vla_alloc(void *ptr, ptrdiff_t n_bytes);
#line 278
extern void __vla_dealloc(void *ptr);
#line 325
extern void __vla_dealloc_eh(void *ptr);
#line 53 "ape-sys/stdio.h"
extern FILE *stderr;
#line 94 "lib_src/vla_alloc.c"
static a_vla_pool_ptr curr_vla_pool;
#line 103
static a_vla_pool _ZZN33_INTERNAL_11_vla_alloc_c_be8bd49b18init_curr_vla_poolEvE4pool;
#line 97
static void _ZN33_INTERNAL_11_vla_alloc_c_be8bd49b18init_curr_vla_poolEv(void)




{

(_ZZN33_INTERNAL_11_vla_alloc_c_be8bd49b18init_curr_vla_poolEvE4pool.last_allocation) = (-1LL);
(_ZZN33_INTERNAL_11_vla_alloc_c_be8bd49b18init_curr_vla_poolEvE4pool.capacity) = 250LL;
(_ZZN33_INTERNAL_11_vla_alloc_c_be8bd49b18init_curr_vla_poolEvE4pool.allocations) = ((a_vla_allocation_ptr)(malloc((((unsigned long long)(_ZZN33_INTERNAL_11_vla_alloc_c_be8bd49b18init_curr_vla_poolEvE4pool.capacity)) * 24ULL))));

if ((_ZZN33_INTERNAL_11_vla_alloc_c_be8bd49b18init_curr_vla_poolEvE4pool.allocations) == ((a_vla_allocation_ptr)0)) {
__abort_execution(ec_vla_allocation_failed);
}
(_ZZN33_INTERNAL_11_vla_alloc_c_be8bd49b18init_curr_vla_poolEvE4pool.normal_block) = ((a_byte *)0);
(_ZZN33_INTERNAL_11_vla_alloc_c_be8bd49b18init_curr_vla_poolEvE4pool.normal_offset) = 32700LL;
(_ZZN33_INTERNAL_11_vla_alloc_c_be8bd49b18init_curr_vla_poolEvE4pool.spare_block) = ((a_byte *)0);
curr_vla_pool = (&_ZZN33_INTERNAL_11_vla_alloc_c_be8bd49b18init_curr_vla_poolEvE4pool); 
}


static void _ZN33_INTERNAL_11_vla_alloc_c_be8bd49b31increase_curr_vla_pool_capacityEv(void)



{ auto void *__T1032708392; auto unsigned long long __T1032709040;
(curr_vla_pool->capacity) *= 2LL;
(curr_vla_pool->allocations) = ((a_vla_allocation_ptr)(((__T1032708392 = ((void *)(curr_vla_pool->allocations))) , (__T1032709040 = (((unsigned long long)(curr_vla_pool->capacity)) * 24ULL))) , (realloc(__T1032708392, __T1032709040))));


if ((curr_vla_pool->allocations) == ((a_vla_allocation_ptr)0)) {
__abort_execution(ec_vla_allocation_failed);
} 
}


static void _ZN33_INTERNAL_11_vla_alloc_c_be8bd49b21free_dead_allocationsEPv( void *__3128_42_ptr)
#line 141
{
auto ptrdiff_t __3137_14_alloc_idx; __3137_14_alloc_idx = (curr_vla_pool->last_allocation);


for (; __3137_14_alloc_idx >= 0LL; --__3137_14_alloc_idx) {
auto a_vla_allocation_ptr __3141_27_allocation; __3141_27_allocation = ((curr_vla_pool->allocations) + __3137_14_alloc_idx);
if (((char *)(&__3137_14_alloc_idx)) > ((char *)__3128_42_ptr)) {

if (((char *)(__3141_27_allocation->frame_marker)) < ((char *)__3128_42_ptr)) {
goto __T1032716472;
}
} else  {

if (((char *)(__3141_27_allocation->frame_marker)) > ((char *)__3128_42_ptr)) {
goto __T1032716472;
}
}
if ((__3141_27_allocation->block) == ((a_byte *)0)) {

free(((void *)(__3141_27_allocation->storage)));
} else  {


auto ptrdiff_t __3159_18_offset; __3159_18_offset = ((__3141_27_allocation->storage) - (__3141_27_allocation->block));
if (__3159_18_offset == 0LL) {




if ((curr_vla_pool->spare_block) == ((a_byte *)0)) {
(curr_vla_pool->spare_block) = (__3141_27_allocation->block);
} else  {
free(((void *)(__3141_27_allocation->block)));
}
(curr_vla_pool->normal_block) = ((a_byte *)0);
(curr_vla_pool->normal_offset) = 32700LL;
} else  {
(curr_vla_pool->normal_offset) = __3159_18_offset;
}
(curr_vla_pool->normal_offset) = __3159_18_offset;
}
} __T1032716472:;
(curr_vla_pool->last_allocation) = __3137_14_alloc_idx; 
}


void __vla_alloc( void *__3182_39_ptr, 
ptrdiff_t __3183_38_n_bytes)




{
auto ptrdiff_t __3189_25_alloc_idx; auto ptrdiff_t __3189_36_padding;
auto a_vla_allocation_ptr __3190_25_allocation;

if (__3183_38_n_bytes == 0LL) {


__3183_38_n_bytes = 1LL;
} else  { if (__3183_38_n_bytes < 0LL) {
__abort_execution(ec_negative_vla_size);
} }
__3189_36_padding = (8LL - (__3183_38_n_bytes % 8LL));
if (__3189_36_padding != 8LL) {


__3183_38_n_bytes += __3189_36_padding;
}
if (curr_vla_pool == ((a_vla_pool_ptr)0)) {

_ZN33_INTERNAL_11_vla_alloc_c_be8bd49b18init_curr_vla_poolEv();
} else  {



auto ptrdiff_t __3212_16_last_idx; __3212_16_last_idx = (curr_vla_pool->last_allocation);
if (__3212_16_last_idx >= 0LL) {
if (((char *)(&__3212_16_last_idx)) > ((char *)__3182_39_ptr)) {

if (((char *)(((curr_vla_pool->allocations)[__3212_16_last_idx]).frame_marker)) > ((char *)(&__3189_25_alloc_idx)))
{
_ZN33_INTERNAL_11_vla_alloc_c_be8bd49b21free_dead_allocationsEPv(((void *)(&__3189_25_alloc_idx)));
}
} else  {

if (((char *)(((curr_vla_pool->allocations)[__3212_16_last_idx]).frame_marker)) < ((char *)(&__3189_25_alloc_idx)))
{
_ZN33_INTERNAL_11_vla_alloc_c_be8bd49b21free_dead_allocationsEPv(((void *)(&__3189_25_alloc_idx)));
}
}
}
}
__3189_25_alloc_idx = (++(curr_vla_pool->last_allocation));
if (__3189_25_alloc_idx == (curr_vla_pool->capacity)) {

_ZN33_INTERNAL_11_vla_alloc_c_be8bd49b31increase_curr_vla_pool_capacityEv();
}
__3190_25_allocation = ((curr_vla_pool->allocations) + __3189_25_alloc_idx);
(__3190_25_allocation->frame_marker) = ((void *)(&__3189_25_alloc_idx));
if (__3183_38_n_bytes >= 4096LL) {

auto a_byte *__3238_14_special_block; __3238_14_special_block = ((a_byte *)(malloc(((size_t)__3183_38_n_bytes))));
if (__3238_14_special_block == ((a_byte *)0)) {
__abort_execution(ec_vla_allocation_failed);
}
(__3190_25_allocation->storage) = ((*((a_byte **)__3182_39_ptr)) = __3238_14_special_block);


(__3190_25_allocation->block) = ((a_byte *)0);
} else  {

if (((curr_vla_pool->normal_block) == ((a_byte *)0)) || ((32700LL - (curr_vla_pool->normal_offset)) < (__3183_38_n_bytes - 1LL)))
{



if ((curr_vla_pool->spare_block) != ((a_byte *)0)) {
(curr_vla_pool->normal_block) = (curr_vla_pool->spare_block);
(curr_vla_pool->spare_block) = ((a_byte *)0);
} else  {
(curr_vla_pool->normal_block) = ((a_byte *)(malloc(32700ULL)));
if ((curr_vla_pool->normal_block) == ((a_byte *)0)) {
__abort_execution(ec_vla_allocation_failed);
}
}
(curr_vla_pool->normal_offset) = 0LL;
}
(__3190_25_allocation->storage) = ((*((a_byte **)__3182_39_ptr)) = ((a_byte *)((curr_vla_pool->normal_block) + (curr_vla_pool->normal_offset))));


(__3190_25_allocation->block) = (curr_vla_pool->normal_block);
(curr_vla_pool->normal_offset) += __3183_38_n_bytes;
} 
}


void __vla_dealloc( void *__3273_36_ptr)



{
auto ptrdiff_t __3278_14_alloc_idx; __3278_14_alloc_idx = (curr_vla_pool->last_allocation);



for (; ; --__3278_14_alloc_idx) {
auto a_vla_allocation_ptr __3283_27_allocation; __3283_27_allocation = ((curr_vla_pool->allocations) + __3278_14_alloc_idx);

if (!(__3278_14_alloc_idx >= 0LL)) { { fprintf(stderr, ((const char *)"Assertion failed in file \"%s\", line %d\n"), ((const char *)("lib_src/vla_alloc.c")), 290); abort(); } } ;
if ((__3283_27_allocation->block) == ((a_byte *)0)) {

free(((void *)(__3283_27_allocation->storage)));
if ((__3283_27_allocation->storage) == (*((a_byte **)__3273_36_ptr))) {
goto __T1032780224;
}
} else  {


auto ptrdiff_t __3295_18_offset; __3295_18_offset = ((__3283_27_allocation->storage) - (__3283_27_allocation->block));
if (__3295_18_offset == 0LL) {




if ((curr_vla_pool->spare_block) == ((a_byte *)0)) {
(curr_vla_pool->spare_block) = (__3283_27_allocation->block);
} else  {
free(((void *)(__3283_27_allocation->block)));
}
(curr_vla_pool->normal_block) = ((a_byte *)0);
(curr_vla_pool->normal_offset) = 32700LL;
} else  {
(curr_vla_pool->normal_offset) = __3295_18_offset;
}
if ((__3283_27_allocation->storage) == (*((a_byte **)__3273_36_ptr))) {
goto __T1032780224;
}
}
} __T1032780224:;
(curr_vla_pool->last_allocation) = (__3278_14_alloc_idx - 1LL); 
}


void __vla_dealloc_eh( void *__3320_39_ptr)




{
__vla_dealloc(((void *)(&__3320_39_ptr))); 
}
