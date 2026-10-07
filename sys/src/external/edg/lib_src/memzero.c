/* Translated by the Edison Design Group C++/C front end (version 7.0) */
/* Wed Oct  7 07:14:42 2026 */
extern int __EDGCPFE__7_0;
void *memcpy(void *,const void *,unsigned long long);
void *memset(void *,int,unsigned long long);

#line 1 "lib_src/memzero.c"
#line 10 "ape-arch/stddef_arch.h"
typedef unsigned long long size_t;
#line 34 "ape-sys/string.h"
extern void *memset(void *, int, size_t);
#line 29 "lib_src/memzero.c"
extern void __memzero(void *buffer, size_t size); void __memzero( void *__3101_34_buffer, 
size_t __3102_32_size)



{ auto void *__T839104968; auto size_t __T839105616;



((__T839104968 = __3101_34_buffer) , (__T839105616 = __3102_32_size)) , (memset(__T839104968, 0, __T839105616)); 

}
