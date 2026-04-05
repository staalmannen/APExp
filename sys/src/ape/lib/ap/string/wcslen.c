#include <wchar.h>

#undef wcslen

size_t wcslen(const wchar_t *s)
{
	const wchar_t *a;
	for (a=s; *s; s++);
	return s-a;
}
