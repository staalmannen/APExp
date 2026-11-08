#ifndef _npe_getopt_h_
#define _npe_getopt_h_

#include <npe.h>
#include <unistd.h>

/* make sure this is exactly what parg_option struct is in _parg.h */
struct option {
	char *name;
	int has_arg;
	int *flag;
	int val;
};

int getopt_long(int argc, char *argv[], char *optstring, struct option *longopts, int *longindex);

#endif
