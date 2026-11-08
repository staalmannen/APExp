#include <u.h>
#include <libc.h>
#include <thread.h>

int npe_main_renamed(int argc, char *argv[]);
int mainstacksize = 256*1024;
extern void (*exit)(int);

static void
npe_threadexit(int x)
{
	threadexitsall(x == 0 ? nil : "error");
}

void
threadmain(int argc, char *argv[])
{
	exit = npe_threadexit;

	argv0 = *argv; /* for sdl to set at least some kind of label */
	tmfmtinstall();

	threadexitsall(npe_main_renamed(argc, argv) == 0 ? nil : "error");
}
