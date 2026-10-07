/* Translated by the Edison Design Group C++/C front end (version 7.0) */
/* Wed Oct  7 03:19:04 2026 */
extern int __EDGCPFE__7_0;
void *memcpy(void *,const void *,unsigned long);
void *memset(void *,int,unsigned long);

# 1 "lib_src/array_nonew_aligned.c"
# 61 "include_c++/new.stdh" 3
struct _ZSt9nothrow_t;
# 214 "/usr/lib/gcc/x86_64-linux-gnu/13/include/stddef.h" 3
typedef unsigned long size_t;
# 110 "include_c++/new.stdh" 3
extern __attribute__((__nothrow__)) void *_ZnwmSt11align_val_tRKSt9nothrow_t(size_t, unsigned long, const struct _ZSt9nothrow_t *);
# 21 "lib_src/array_nonew_aligned.c"
extern __attribute__((__nothrow__)) void *_ZnamSt11align_val_tRKSt9nothrow_t(size_t size, unsigned long align, const struct _ZSt9nothrow_t *nothrow_arg); __attribute__((__nothrow__)) void *_ZnamSt11align_val_tRKSt9nothrow_t( size_t __11010_36_size, 
unsigned long __11011_54_align, 
const struct _ZSt9nothrow_t *__11012_54_nothrow_arg)
# 29
{ auto size_t __T543770272; auto unsigned long __T543770920; auto const struct _ZSt9nothrow_t *__T543771656; auto void *__T543772568;  {
__T543772568 = ((((__T543770272 = __11010_36_size) , (__T543770920 = __11011_54_align)) , (__T543771656 = __11012_54_nothrow_arg)) , (_ZnwmSt11align_val_tRKSt9nothrow_t(__T543770272, __T543770920, __T543771656))); return __T543772568; }
}
