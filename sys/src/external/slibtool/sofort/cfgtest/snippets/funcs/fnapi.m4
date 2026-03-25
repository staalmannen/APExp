m4_define(_
_include_headers,_
[m4_ifelse(_
m4_len($1),0,,_
[#include <$1>]
[_include_headers(m4_shift($@))]_
)])_
_
_
_include_headers(_FUNCINCS)_

_FUNCTYPE (*func)(_FUNCARGS) = _FUNCNAME;

int main(void)
{
	return !!func;
}
