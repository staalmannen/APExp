/* Translated by the Edison Design Group C++/C front end (version 7.0) */
/* Thu Oct  8 07:53:17 2026 */
extern int __EDGCPFE__7_0;
void *memcpy(void *,const void *,unsigned long long);
void *memset(void *,int,unsigned long long);

#line 1 "lib_src/delete.c"
#line 66 "ape-sys/stdlib.h"
extern void free(void *);
#line 18 "lib_src/delete.c"
extern void _ZdlPv(void *ptr); void _ZdlPv( void *__3016_28_ptr)



{
if (__3016_28_ptr != ((void *)0)) {
free(__3016_28_ptr);
} 
}
