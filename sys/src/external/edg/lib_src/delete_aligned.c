/* Translated by the Edison Design Group C++/C front end (version 7.0) */
/* Thu Oct  8 07:53:17 2026 */
extern int __EDGCPFE__7_0;
void *memcpy(void *,const void *,unsigned long long);
void *memset(void *,int,unsigned long long);

#line 1 "lib_src/delete_aligned.c"
#line 10 "ape-arch/stddef_arch.h"
typedef unsigned long long size_t;
#line 66 "ape-sys/stdlib.h"
extern void free(void *);
#line 19 "lib_src/delete_aligned.c"
extern void _ZdlPvSt11align_val_t(void *ptr, unsigned long long); void _ZdlPvSt11align_val_t( void *__3017_28_ptr,  unsigned long long __T284063160)



{
if (__3017_28_ptr != ((void *)0)) {
free(__3017_28_ptr);
} 
}
