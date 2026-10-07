/* Translated by the Edison Design Group C++/C front end (version 7.0) */
/* Wed Oct  7 03:19:04 2026 */
extern int __EDGCPFE__7_0;
void *memcpy(void *,const void *,unsigned long);
void *memset(void *,int,unsigned long);

# 1 "lib_src/delete_aligned.c"
# 214 "/usr/lib/gcc/x86_64-linux-gnu/13/include/stddef.h" 3
typedef unsigned long size_t;
# 687 "/usr/include/stdlib.h" 3
extern __attribute__((__nothrow__)) void free(void *__ptr);
# 19 "lib_src/delete_aligned.c"
extern __attribute__((__nothrow__)) void _ZdlPvSt11align_val_t(void *ptr, unsigned long); __attribute__((__nothrow__)) void _ZdlPvSt11align_val_t( void *__11008_28_ptr,  unsigned long __T331673672)



{
if (__11008_28_ptr != ((void *)0)) {
free(__11008_28_ptr);
} 
}
