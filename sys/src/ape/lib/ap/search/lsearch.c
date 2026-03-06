#include <search.h>
#include <string.h>

void *lsearch(const void *key, void *base, size_t *nelp, size_t width,
	int (*compar)(const void *, const void *))
{
// plan9 compiler cannot do VLA, so I set width = 255 ...
	char (*p)[255] = base;
	size_t n = *nelp;
	size_t i;

	for (i = 0; i < n; i++)
		if (compar(key, p[i]) == 0)
			return p[i];
	*nelp = n+1;
	return memcpy(p[n], key, width);
}

void *lfind(const void *key, const void *base, size_t *nelp,
	size_t width, int (*compar)(const void *, const void *))
{
	char (*p)[255] = (void *)base;
	size_t n = *nelp;
	size_t i;

	for (i = 0; i < n; i++)
		if (compar(key, p[i]) == 0)
			return p[i];
	return 0;
}


