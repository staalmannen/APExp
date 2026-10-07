/* Translated by the Edison Design Group C++/C front end (version 7.0) */
/* Wed Oct  7 03:19:04 2026 */
extern int __EDGCPFE__7_0;
void *memcpy(void *,const void *,unsigned long);
void *memset(void *,int,unsigned long);

# 1 "lib_src/delnothrow_aligned.c"
# 61 "include_c++/new.stdh" 3
struct _ZSt9nothrow_t;
# 214 "/usr/lib/gcc/x86_64-linux-gnu/13/include/stddef.h" 3
typedef unsigned long size_t;
# 112 "include_c++/new.stdh" 3
extern __attribute__((__nothrow__)) void _ZdlPvSt11align_val_t(void *, unsigned long);
# 19 "lib_src/delnothrow_aligned.c"
extern __attribute__((__nothrow__)) void _ZdlPvSt11align_val_tRKSt9nothrow_t(void *ptr, unsigned long align, const struct _ZSt9nothrow_t *); __attribute__((__nothrow__)) void _ZdlPvSt11align_val_tRKSt9nothrow_t( void *__11008_31_ptr, 
unsigned long __11009_57_align,  const struct _ZSt9nothrow_t *__T199709104)
# 26
{ auto void *__T199710192; auto unsigned long __T199710840;
((__T199710192 = __11008_31_ptr) , (__T199710840 = __11009_57_align)) , (_ZdlPvSt11align_val_t(__T199710192, __T199710840)); 
}
