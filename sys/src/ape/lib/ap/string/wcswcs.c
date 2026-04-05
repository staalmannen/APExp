#include <wchar.h>

#undef wcswcs

wchar_t *wcswcs(const wchar_t *haystack, const wchar_t *needle)
{
	return wcsstr(haystack, needle);
}
