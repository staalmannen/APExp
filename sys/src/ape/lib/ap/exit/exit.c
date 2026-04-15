#include <unistd.h>
#define	NONEXIT	34
int (*_atexitfns[NONEXIT])(void);
/* POSIX requires all open streams be flushed on exit */
extern void __stdio_exit(void);
void _doatexits(void){
	int i, (*f)(void);
	for(i = NONEXIT-1; i >= 0; i--)
		if(_atexitfns[i]){
			f = _atexitfns[i];
			_atexitfns[i] = 0;	/* self defense against bozos */
			(*f)();
		}
}
void exit(int status)
{
	__stdio_exit();
	_doatexits();
	_exit(status);
}
