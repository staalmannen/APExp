/* Translated by the Edison Design Group C++/C front end (version 7.0) */
/* Wed Oct  7 07:14:41 2026 */
extern int __EDGCPFE__7_0;
void *memcpy(void *,const void *,unsigned long long);
void *memset(void *,int,unsigned long long);

#line 1 "lib_src/delete_aligned.c"
#line 10 "ape-arch/stddef_arch.h"
typedef unsigned long long size_t;
#line 44 "ape-sys/stdlib.h"
extern void free(void *);
#line 19 "lib_src/delete_aligned.c"
extern void _ZdlPvSt11align_val_t(void *ptr, unsigned long long); void _ZdlPvSt11align_val_t( void *__2989_28_ptr,  unsigned long long __T998949960)



{
if (__2989_28_ptr != ((void *)0)) {
free(__2989_28_ptr);
} 
}
