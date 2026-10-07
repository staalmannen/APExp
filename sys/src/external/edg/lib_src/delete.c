/* Translated by the Edison Design Group C++/C front end (version 7.0) */
/* Wed Oct  7 07:14:41 2026 */
extern int __EDGCPFE__7_0;
void *memcpy(void *,const void *,unsigned long long);
void *memset(void *,int,unsigned long long);

#line 1 "lib_src/delete.c"
#line 44 "ape-sys/stdlib.h"
extern void free(void *);
#line 18 "lib_src/delete.c"
extern void _ZdlPv(void *ptr); void _ZdlPv( void *__2988_28_ptr)



{
if (__2988_28_ptr != ((void *)0)) {
free(__2988_28_ptr);
} 
}
