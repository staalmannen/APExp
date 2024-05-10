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

static struct{
	Link	*link;
	long	nuxi;
} __head = { 0, 0xdeadbeef };
extern PFV _ctors[];
extern PFV _dtors[];
void __task__init();

void __main()
{
	__task__init();
	atexit(__dtors);

	if(__head.link){
		Link *last, *it, *next;
		last = 0;
		it = __head.link;
		while(it){
			if(it->ctor)
				(*it->ctor)();
			next = it->next;
			it->next = last;
			last = it;
			it = next;
		}
		__head.link = last;
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
	if(__head.link){
		Link *it;
		for(it = __head.link; it; it = it->next)
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
