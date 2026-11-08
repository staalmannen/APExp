#include <unistd.h>
#include <getopt.h>
#include "_parg.h"

static struct parg_state npe_ps;
static int npe_ps_init;

int
getopt_long(int argc, char *argv[], char *optstring, struct option *longopts, int *longindex)
{
	int r;

	if(npe_ps_init == 0){
		npe_parg_init(&npe_ps);
		npe_ps_init = 1;
	}
	r = npe_parg_getopt_long(&npe_ps, argc, argv, optstring, (void*)longopts, longindex);
	optarg = (char*)npe_ps.optarg;
	optind = npe_ps.optind;
	optopt = npe_ps.optopt;

	return r;
}
