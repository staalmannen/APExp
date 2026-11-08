#include <libgen.h>

char*
dirname(char *path)
{
	char *p;

	if(path == nil || path[0] == 0)
		return ".";
	if(path[0] != 0 && path[0] == '/' && path[1] == 0)
		return path;
	p = path + strlen(path);
	for(p--; p > path+1 && *p == '/'; p--)
		*p = 0;
	for(p--; p > path && *p != '/'; p--)
		;
	if(*p == '/' && p == path)
		return "/";
	if(p == path)
		return ".";
	if(*p == '/')
		*p = 0;
	return path;
}
