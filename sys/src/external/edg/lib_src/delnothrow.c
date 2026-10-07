/* Translated by the Edison Design Group C++/C front end (version 7.0) */
/* Wed Oct  7 03:19:04 2026 */
extern int __EDGCPFE__7_0;
void *memcpy(void *,const void *,unsigned long);
void *memset(void *,int,unsigned long);

# 1 "lib_src/delnothrow.c"
# 61 "include_c++/new.stdh" 3
struct _ZSt9nothrow_t;
# 94
extern __attribute__((__nothrow__)) void _ZdlPv(void *);
# 18 "lib_src/delnothrow.c"
extern __attribute__((__nothrow__)) void _ZdlPvRKSt9nothrow_t(void *ptr, const struct _ZSt9nothrow_t *); __attribute__((__nothrow__)) void _ZdlPvRKSt9nothrow_t( void *__11007_31_ptr,  const struct _ZSt9nothrow_t *__T666906696)
# 24
{
_ZdlPv(__11007_31_ptr); 
}
