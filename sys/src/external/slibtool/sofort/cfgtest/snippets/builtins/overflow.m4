m4_define(_
_builtin_args,_
[m4_ifelse(_
$1,add_overflow,[int a, int b, int * c],_
$1,sadd_overflow,[int a, int b, int * c],_
$1,saddl_overflow,[long int a, long int b, long int * c],_
$1,saddll_overflow,[long long int a, long long int b, long long int * c],_
$1,uadd_overflow,[unsigned int a, unsigned int b, unsigned int * c],_
$1,uaddl_overflow,[unsigned long int a, unsigned long int b, unsigned long int * c],_
$1,uaddll_overflow,[unsigned long long int a, unsigned long long int b, unsigned long long int * c],_
_
$1,mul_overflow,[int a, int b, int * c],_
$1,smul_overflow,[int a, int b, int * c],_
$1,smull_overflow,[long int a, long int b, long int * c],_
$1,smulll_overflow,[long long int a, long long int b, long long int * c],_
$1,umul_overflow,[unsigned int a, unsigned int b, unsigned int * c],_
$1,umull_overflow,[unsigned long int a, unsigned long int b, unsigned long int * c],_
$1,umulll_overflow,[unsigned long long int a, unsigned long long int b, unsigned long long int * c],_
_
$1,sub_overflow,[int a, int b, int * c],_
$1,ssub_overflow,[int a, int b, int * c],_
$1,ssubl_overflow,[long int a, long int b, long int * c],_
$1,ssubll_overflow,[long long int a, long long int b, long long int * c],_
$1,usub_overflow,[unsigned int a, unsigned int b, unsigned int * c],_
$1,usubl_overflow,[unsigned long int a, unsigned long int b, unsigned long int * c],_
$1,usubll_overflow,[unsigned long long int a, unsigned long long int b, unsigned long long int * c],_
_
$1,add_overflow_p,[int a, int b, int c],_
$1,mul_overflow_p,[int a, int b, int c],_
$1,sub_overflow_p,[int a, int b, int c],_
__ERROR__)])_
_
_
m4_define(_
_builtin_atoi,_
[m4_ifelse(_
$1,add_overflow,[atoi],_
$1,sadd_overflow,[atoi],_
$1,saddl_overflow,[atol],_
$1,saddll_overflow,[atoll],_
$1,uadd_overflow,[atoi],_
$1,uaddl_overflow,[atol],_
$1,uaddll_overflow,[atoll],_
_
$1,mul_overflow,[atoi],_
$1,smul_overflow,[atoi],_
$1,smull_overflow,[atol],_
$1,smulll_overflow,[atoll],_
$1,umul_overflow,[atoi],_
$1,umull_overflow,[atol],_
$1,umulll_overflow,[atoll],_
_
$1,sub_overflow,[atoi],_
$1,ssub_overflow,[atoi],_
$1,ssubl_overflow,[atol],_
$1,ssubll_overflow,[atoll],_
$1,usub_overflow,[atoi],_
$1,usubl_overflow,[atol],_
$1,usubll_overflow,[atoll],_
_
$1,add_overflow_p,[atoi],_
$1,mul_overflow_p,[atoi],_
$1,sub_overflow_p,[atoi],_
__ERROR__)])_
_
m4_define(_
_builtin_chkptr,_
[m4_ifelse(_
$1,add_overflow,[int],_
$1,sadd_overflow,[int],_
$1,saddl_overflow,[long int],_
$1,saddll_overflow,[long long int],_
$1,uadd_overflow,[unsigned int],_
$1,uaddl_overflow,[unsigned long int],_
$1,uaddll_overflow,[unsigned long long int],_
_
$1,mul_overflow,[int],_
$1,smul_overflow,[int],_
$1,smull_overflow,[long int],_
$1,smulll_overflow,[long long int],_
$1,umul_overflow,[unsigned int],_
$1,umull_overflow,[unsigned long int],_
$1,umulll_overflow,[unsigned long long int],_
_
$1,sub_overflow,[int],_
$1,ssub_overflow,[int],_
$1,ssubl_overflow,[long int],_
$1,ssubll_overflow,[long long int],_
$1,usub_overflow,[unsigned int],_
$1,usubl_overflow,[unsigned long int],_
$1,usubll_overflow,[unsigned long long int],_
__ERROR__)])_
_
m4_define(_
_builtin_chkarg,_
[m4_ifelse(_
$1,add_overflow_p,[(int)],_
$1,mul_overflow_p,[(int)],_
$1,sub_overflow_p,[(int)],_
[&](_builtin_chkptr($1))_
)])_
_
_
#include <stdlib.h>

int [f__]_BUILTIN[](_builtin_args(_BUILTIN))
{
	return [__builtin_]_BUILTIN[(a,b,c)];
}

int main(int argc, char ** argv)
{
	return (argc >= 2)
		? [f__]_BUILTIN[](argc,_builtin_atoi(_BUILTIN)(*++argv),_builtin_chkarg(_BUILTIN){0})
		: 2;
}
