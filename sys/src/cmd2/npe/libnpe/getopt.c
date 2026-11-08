#include <unistd.h>
#include "_parg.h"

char *optarg;
int optind, opterr, optopt;

static struct parg_state npe_ps;
static int npe_ps_init;

int
getopt(int argc, char *argv[], char *optstring)
{
	int r;

	if(npe_ps_init == 0){
		npe_parg_init(&npe_ps);
		npe_ps_init = 1;
	}
	r = npe_parg_getopt(&npe_ps, argc, argv, optstring);
	optarg = (char*)npe_ps.optarg;
	optind = npe_ps.optind;
	optopt = npe_ps.optopt;

	return r;
}
