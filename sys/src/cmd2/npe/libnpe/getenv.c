#include <unistd.h>

#undef getenv

static char *
home(char *subpath)
{
	char *s, *e;

	if((s = getenv("home")) != nil){
		e = cleanname(smprint("%s/%s", s, subpath));
		free(s);
	}else
		e = strdup("/tmp");

	return e;
}

char *
npe_getenv(char *s)
{
	static char *e;

	free(e);
	e = nil;

	if((e = getenv(s)) != nil)
		return e;

	if(strcmp(s, "XDG_RUNTIME_DIR") == 0 || strcmp(s, "XDG_CACHE_HOME") == 0)
		return "/tmp";
	if(strcmp(s, "XDG_CONFIG_HOME") == 0 || strcmp(s, "XDG_DATA_HOME") == 0)
		return home("lib");

	if(strcmp(s, "HOME") == 0)
		s = "home";
	else if(strcmp(s, "USER") == 0)
		s = "user";

	e = getenv(s);

	return e;
}
