/* Translated by the Edison Design Group C++/C front end (version 7.0) */
/* Thu Oct  8 07:53:16 2026 */
extern int __EDGCPFE__7_0;
void *memcpy(void *,const void *,unsigned long long);
void *memset(void *,int,unsigned long long);

#line 1 "lib_src/array_nonew_aligned.c"
#line 61 "include_c++/new.stdh"
struct _ZSt9nothrow_t;
#line 10 "ape-arch/stddef_arch.h"
typedef unsigned long long size_t;
#line 110 "include_c++/new.stdh"
extern void *_ZnwySt11align_val_tRKSt9nothrow_t(size_t, unsigned long long, const struct _ZSt9nothrow_t *);
#line 21 "lib_src/array_nonew_aligned.c"
extern void *_ZnaySt11align_val_tRKSt9nothrow_t(size_t size, unsigned long long align, const struct _ZSt9nothrow_t *nothrow_arg); void *_ZnaySt11align_val_tRKSt9nothrow_t( size_t __3019_36_size, 
unsigned long long __3020_54_align, 
const struct _ZSt9nothrow_t *__3021_54_nothrow_arg)
#line 29
{ auto size_t __T44252176; auto unsigned long long __T44252824; auto const struct _ZSt9nothrow_t *__T44253560; auto void *__T44254472;  {
__T44254472 = ((((__T44252176 = __3019_36_size) , (__T44252824 = __3020_54_align)) , (__T44253560 = __3021_54_nothrow_arg)) , (_ZnwySt11align_val_tRKSt9nothrow_t(__T44252176, __T44252824, __T44253560))); return __T44254472; }
}
