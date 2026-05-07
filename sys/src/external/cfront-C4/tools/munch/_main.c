/* @(#) _main.c 1.2 1/27/86 17:47:56 */
/*ident	"@(#)cfront:lib/static/_main.c	1.2"*/

typedef void (*PFV)();

extern int atexit(void*);
extern PFV _ctors[];
extern void __dtors();

void __cfront_pre_main()
{
    atexit((PFV)__dtors);

    PFV* pf=_ctors;
    for (; *pf; pf++) (**pf)();
}
