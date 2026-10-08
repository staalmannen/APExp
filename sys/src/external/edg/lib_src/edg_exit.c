/* Translated by the Edison Design Group C++/C front end (version 7.0) */
/* Thu Oct  8 07:53:17 2026 */
extern int __EDGCPFE__7_0;
void *memcpy(void *,const void *,unsigned long long);
void *memset(void *,int,unsigned long long);

#line 1 "lib_src/edg_exit.c"
#line 23 "lib_src/static_init.h"
extern void _Z12__call_dtorsv(void);
#line 20 "lib_src/edg_exit.c"
extern void exit(int);




extern void __eh_exit_processing(void);


extern void _Z10__edg_exiti(int val); void _Z10__edg_exiti( int __175_21_val)
#line 34
{
__eh_exit_processing();
#line 41
_Z12__call_dtorsv();
exit(__175_21_val); 
}
