/* Translated by the Edison Design Group C++/C front end (version 7.0) */
/* Wed Oct  7 03:19:04 2026 */
extern int __EDGCPFE__7_0;
void *memcpy(void *,const void *,unsigned long);
void *memset(void *,int,unsigned long);

# 1 "lib_src/delete.c"
# 687 "/usr/include/stdlib.h" 3
extern __attribute__((__nothrow__)) void free(void *__ptr);
# 18 "lib_src/delete.c"
extern __attribute__((__nothrow__)) void _ZdlPv(void *ptr); __attribute__((__nothrow__)) void _ZdlPv( void *__11007_28_ptr)



{
if (__11007_28_ptr != ((void *)0)) {
free(__11007_28_ptr);
} 
}
