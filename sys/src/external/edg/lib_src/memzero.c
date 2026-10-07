/* Translated by the Edison Design Group C++/C front end (version 7.0) */
/* Wed Oct  7 03:19:05 2026 */
extern int __EDGCPFE__7_0;
void *memcpy(void *,const void *,unsigned long);
void *memset(void *,int,unsigned long);

# 1 "lib_src/memzero.c"
# 214 "/usr/lib/gcc/x86_64-linux-gnu/13/include/stddef.h" 3
typedef unsigned long size_t;
# 61 "/usr/include/string.h" 3
extern __attribute__((__nothrow__)) void *memset(void *__s, int __c, size_t __n);
# 29 "lib_src/memzero.c"
extern void __memzero(void *buffer, size_t size); void __memzero( void *__12756_34_buffer, 
size_t __12757_32_size)



{ auto void *__T554141176; auto size_t __T554141824;



((__T554141176 = __12756_34_buffer) , (__T554141824 = __12757_32_size)) , (memset(__T554141176, 0, __T554141824)); 

}
