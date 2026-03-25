m4_define(_
_builtin_arg,_
[m4_ifelse(_
$1,ffs,[int x],_
$1,clz,[unsigned int x],_
$1,ctz,[unsigned int x],_
$1,clrsb,[int x],_
$1,popcount,[unsigned int x],_
$1,parity,[unsigned int x],_
_
$1,ffsl,[long x],_
$1,clzl,[unsigned long x],_
$1,ctzl,[unsigned long x],_
$1,clrsbl,[long x],_
$1,popcountl,[unsigned long x],_
$1,parityl,[unsigned long x],_
_
$1,ffsll,[long x],_
$1,clzll,[unsigned long x],_
$1,ctzll,[unsigned long x],_
$1,clrsbll,[long x],_
$1,popcountll,[unsigned long x],_
$1,parityll,[unsigned long x],_
__ERROR__)])_
_
_
m4_define(_
_builtin_atoi,_
[m4_ifelse(_
$1,ffs,[atoi],_
$1,clz,[atoi],_
$1,ctz,[atoi],_
$1,clrsb,[atoi],_
$1,popcount,[atoi],_
$1,parity,[atoi],_
_
$1,ffsl,[atol],_
$1,clzl,[atol],_
$1,ctzl,[atol],_
$1,clrsbl,[atol],_
$1,popcountl,[atol],_
$1,parityl,[atol],_
_
$1,ffsll,[atol],_
$1,clzll,[atol],_
$1,ctzll,[atol],_
$1,clrsbll,[atol],_
$1,popcountll,[atol],_
$1,parityll,[atol],_
__ERROR__)])_
_
_
#include <stdlib.h>

int [f__]_BUILTIN[](_builtin_arg(_BUILTIN))
{
	return [__builtin_]_BUILTIN[(x)];
}

int main(int argc, char ** argv)
{
	return (argc >= 2)
		? [f__]_BUILTIN[](_builtin_atoi(_BUILTIN)(*++argv))
		: 2;
}
