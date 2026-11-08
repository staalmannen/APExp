#include <unistd.h>

int
unlink(char *path)
{
	return remove(path);
}
