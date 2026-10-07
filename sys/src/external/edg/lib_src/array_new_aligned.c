/* Translated by the Edison Design Group C++/C front end (version 7.0) */
/* Wed Oct  7 03:19:03 2026 */
extern int __EDGCPFE__7_0;
void *memcpy(void *,const void *,unsigned long);
void *memset(void *,int,unsigned long);

# 1 "lib_src/array_new_aligned.c"
# 214 "/usr/lib/gcc/x86_64-linux-gnu/13/include/stddef.h" 3
typedef unsigned long size_t;
# 109 "include_c++/new.stdh" 3
extern void *_ZnwmSt11align_val_t(size_t, unsigned long);
# 21 "lib_src/array_new_aligned.c"
extern void *_ZnamSt11align_val_t(size_t size, unsigned long align); void *_ZnamSt11align_val_t( size_t __11010_29_size,  unsigned long __11010_62_align)



{ auto size_t __T581403696; auto unsigned long __T581404344;
return ((__T581403696 = __11010_29_size) , (__T581404344 = __11010_62_align)) , (_ZnwmSt11align_val_t(__T581403696, __T581404344));
}
