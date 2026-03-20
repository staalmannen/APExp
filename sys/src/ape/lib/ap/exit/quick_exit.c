#include <stdlib.h>
#include <unistd.h>

/*
 * at_quick_exit / quick_exit - C11 quick exit facility
 *
 * quick_exit() is like exit() but only calls handlers registered
 * with at_quick_exit(), not those registered with atexit(), and
 * does not flush stdio buffers. Useful for async-signal-safe exit.
 *
 * Since APE is single-threaded, we implement this simply with a
 * fixed-size handler table matching the atexit() approach.
 */

#define NQUICKEXIT 32

static void (*_quick_fns[NQUICKEXIT])(void);
static int _nquick = 0;

int
at_quick_exit(void (*f)(void))
{
	if(_nquick >= NQUICKEXIT)
		return -1;
	_quick_fns[_nquick++] = f;
	return 0;
}

_Noreturn void
quick_exit(int status)
{
	int i;

	/* call handlers in reverse registration order, per C11 */
	for(i = _nquick - 1; i >= 0; i--)
		if(_quick_fns[i])
			_quick_fns[i]();

	_exit(status);
}
