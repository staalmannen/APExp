#ifndef _npe_stdlib_h_
#define _npe_stdlib_h_

#include <npe.h>

typedef struct div_t div_t;

struct div_t
{
	int quot;
	int rem;
};

#define RAND_MAX 32767
#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

int setenv(char *name, char *value, int overwrite);
char *realpath(char *path, char *buffer);
int mkstemp(char *t);
div_t div(int n, int d);

#endif
