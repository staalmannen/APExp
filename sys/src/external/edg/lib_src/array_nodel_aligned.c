/* Translated by the Edison Design Group C++/C front end (version 7.0) */
/* Wed Oct  7 03:19:03 2026 */
extern int __EDGCPFE__7_0;
void *memcpy(void *,const void *,unsigned long);
void *memset(void *,int,unsigned long);

# 1 "lib_src/array_nodel_aligned.c"
# 61 "include_c++/new.stdh" 3
struct _ZSt9nothrow_t;
# 214 "/usr/lib/gcc/x86_64-linux-gnu/13/include/stddef.h" 3
typedef unsigned long size_t;
# 113 "include_c++/new.stdh" 3
extern __attribute__((__nothrow__)) void _ZdlPvSt11align_val_tRKSt9nothrow_t(void *, unsigned long, const struct _ZSt9nothrow_t *);
# 21 "lib_src/array_nodel_aligned.c"
extern __attribute__((__nothrow__)) void _ZdaPvSt11align_val_tRKSt9nothrow_t(void *ptr, unsigned long align, const struct _ZSt9nothrow_t *nothrow_arg); __attribute__((__nothrow__)) void _ZdaPvSt11align_val_tRKSt9nothrow_t( void *__11010_33_ptr, 
unsigned long __11011_57_align, 
const struct _ZSt9nothrow_t *__11012_56_nothrow_arg)
# 29
{ auto void *__T875828984; auto unsigned long __T875829632; auto const struct _ZSt9nothrow_t *__T875830368;
(((__T875828984 = __11010_33_ptr) , (__T875829632 = __11011_57_align)) , (__T875830368 = __11012_56_nothrow_arg)) , (_ZdlPvSt11align_val_tRKSt9nothrow_t(__T875828984, __T875829632, __T875830368)); 
}
