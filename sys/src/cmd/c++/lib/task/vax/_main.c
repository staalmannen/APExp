/*
 * special version for the task library
 * so we can get the proper stack base
 */

#include <stdlib.h>

extern "C" {
	extern void __dtors();
	extern void _main();
}

typedef void (*PFV)();
extern PFV _ctors[];

void __task__init();

void _main() {
	__task__init();

	for (PFV* pf=_ctors; *pf; pf++)
		(**pf)();

	atexit (__dtors);
}
