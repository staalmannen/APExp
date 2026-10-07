/* Translated by the Edison Design Group C++/C front end (version 7.0) */
/* Wed Oct  7 03:19:05 2026 */
extern int __EDGCPFE__7_0;
void *memcpy(void *,const void *,unsigned long);
void *memset(void *,int,unsigned long);

# 1 "lib_src/edg_exit.c"
# 23 "lib_src/static_init.h"
extern void _Z12__call_dtorsv(void);
# 20 "lib_src/edg_exit.c"
extern void exit(int);




extern void __eh_exit_processing(void);


extern void _Z10__edg_exiti(int val); void _Z10__edg_exiti( int __175_21_val)
# 34
{
__eh_exit_processing();
# 41
_Z12__call_dtorsv();
exit(__175_21_val); 
}
