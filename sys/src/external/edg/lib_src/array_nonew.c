/* Translated by the Edison Design Group C++/C front end (version 7.0) */
/* Wed Oct  7 03:19:04 2026 */
extern int __EDGCPFE__7_0;
void *memcpy(void *,const void *,unsigned long);
void *memset(void *,int,unsigned long);

# 1 "lib_src/array_nonew.c"
# 61 "include_c++/new.stdh" 3
struct _ZSt9nothrow_t;
# 214 "/usr/lib/gcc/x86_64-linux-gnu/13/include/stddef.h" 3
typedef unsigned long size_t;
# 97 "include_c++/new.stdh" 3
extern __attribute__((__nothrow__)) void *_ZnwmRKSt9nothrow_t(size_t, const struct _ZSt9nothrow_t *);
# 20 "lib_src/array_nonew.c"
extern __attribute__((__nothrow__)) void *_ZnamRKSt9nothrow_t(size_t size, const struct _ZSt9nothrow_t *nothrow_arg); __attribute__((__nothrow__)) void *_ZnamRKSt9nothrow_t( size_t __11009_36_size, 
const struct _ZSt9nothrow_t *__11010_54_nothrow_arg)
# 27
{ auto size_t __T977130720; auto const struct _ZSt9nothrow_t *__T977131368; auto void *__T977132280;  {
__T977132280 = (((__T977130720 = __11009_36_size) , (__T977131368 = __11010_54_nothrow_arg)) , (_ZnwmRKSt9nothrow_t(__T977130720, __T977131368))); return __T977132280; }
}
