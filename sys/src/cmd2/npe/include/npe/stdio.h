#ifndef _npe_stdio_h_
#define _npe_stdio_h_

#include <npe.h>

FILE *popen(char *cmd, char *type);
int pclose(FILE *s);
int rename(char *old, char *new);

#endif
