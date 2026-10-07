/* Translated by the Edison Design Group C++/C front end (version 7.0) */
/* Wed Oct  7 03:19:03 2026 */
extern int __EDGCPFE__7_0;
void *memcpy(void *,const void *,unsigned long);
void *memset(void *,int,unsigned long);

# 1 "lib_src/array_new.c"
# 214 "/usr/lib/gcc/x86_64-linux-gnu/13/include/stddef.h" 3
typedef unsigned long size_t;
# 91 "include_c++/new.stdh" 3
extern void *_Znwm(size_t);
# 20 "lib_src/array_new.c"
extern void *_Znam(size_t size); void *_Znam( size_t __11009_29_size)



{
return _Znwm(__11009_29_size);
}
