/* Translated by the Edison Design Group C++/C front end (version 7.0) */
/* Wed Oct  7 07:14:42 2026 */
extern int __EDGCPFE__7_0;
void *memcpy(void *,const void *,unsigned long long);
void *memset(void *,int,unsigned long long);

#line 1 "lib_src/main.c"
#line 69 "lib_src/basics.h"
typedef int a_boolean;
#line 22 "lib_src/static_init.h"
extern void _Z12__call_ctorsv(void);
#line 22 "lib_src/main.c"
extern void _main(void);
#line 32
static a_boolean _ZZ5_mainE11main_called; static a_boolean _ZZ5_mainE11main_called = 0;
#line 22
void _main(void)
#line 31
{
#line 37
if (!(_ZZ5_mainE11main_called)) {
_ZZ5_mainE11main_called = 1;
_Z12__call_ctorsv();
} 
}
