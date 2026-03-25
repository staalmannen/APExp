#include <stdlib.h>
#include <string.h>

#define MEM_READ         0
#define MEM_WRITE        1
#define MEM_SHARED_READ  2

#define TEMPORAL_LOCALITY_NONE   0
#define TEMPORAL_LOCALITY_LOW    1
#define TEMPORAL_LOCALITY_MEDIUM 2
#define TEMPORAL_LOCALITY_HIGH   3

m4_define(_
_builtin_prefetch,_
[[
int main(int argc, char ** argv)
{
	__builtin_prefetch(&argv[0],MEM_WRITE,TEMPORAL_LOCALITY_HIGH);
	return 0;
}
]])_
_
m4_define(_
_builtin_expect,_
[[
int main(int argc, char ** argv)
{
	return __builtin_expect(atol(argv[--argc]),strlen(argv[0])) & 0x7fffffff;
}
]])_
_
m4_define(_
_builtin_choose_expr,_
[[
int main(int argc, char ** argv)
{
	return __builtin_choose_expr(MEM_WRITE,strlen(argv[0]),argv[0][0]);
}
]])_
_
_
_
m4_define(_builtin_test,[_builtin_$1]())_
_builtin_test(_BUILTIN)_
