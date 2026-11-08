#include <unistd.h>

int
rename(char *old, char *new)
{
	Dir d;

	nulldir(&d);
	d.name = new;

	return dirwstat(old, &d) > 0 ? 0 : -1;
}
