/*
 * special version for the task library
 * so we can get the proper stack base
 */
#include <stdlib.h>

extern "C" {
	extern void __dtors();
	extern void __main();
}
typedef void (*PFV)();
typedef struct Link Link;
struct Link{
	Link	*next;
	PFV	ctor;
	PFV	dtor;
};

static Link	*__head;
static long	__nuxi = 0xdeadbeef;
extern PFV _ctors[];
extern PFV _dtors[];

void __main()
{
	atexit(__dtors);

	if(__head){
		Link *last, *it, *next;
		last = 0;
		it = __head;
		while(it){
			if(it->ctor)
				(*it->ctor)();
			next = it->next;
			it->next = last;
			last = it;
			it = next;
		}
		__head = last;
		return;
	}
	for(PFV* pf=_ctors; *pf; pf++)
		(**pf)();
}

void
__dtors()
{
	static int done;
	if(done)
		return;
	done = 1;	// once only
	if(__head){
		Link *it;
		for(it = __head; it; it = it->next)
			if(it->dtor)
				(*it->dtor)();
		return;
	}
	PFV* pf = _dtors;
	while(*pf)
		pf++;
	while(_dtors < pf)
		(**--pf)();
}
