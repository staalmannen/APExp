#include <unistd.h>

int
mkdir(char *path, int perm)
{
	int f;

	if(access(path, AEXIST) == 0){
		werrstr("%s: already exists", path);
		return -1;
	}
	if((f = create(path, OREAD, DMDIR|perm)) < 0){
		werrstr("%s: can't create: %r", path);
		return -1;
	}
	close(f);

	return 0;
}
