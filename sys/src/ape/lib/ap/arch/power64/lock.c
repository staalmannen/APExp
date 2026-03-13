#define _LOCK_EXTENSION
#include "../plan9/sys9.h"
#include <lock.h>

int tas(int*);	/* tas.s */

void
lock(Lock *lk)
{
	int i;

	/* once fast */
	if(!tas(&lk->val))
		return;
	/* a thousand times pretty fast */
	for(i=0; i<1000; i++){
		if(!tas(&lk->val))
			return;
		sleep(0);
	}
	/* now nice and slow */
	for(i=0; i<1000; i++){
		if(!tas(&lk->val))
			return;
		sleep(100);
	}
	/* take your time */
	while(tas(&lk->val))
		sleep(1000);
}

int
canlock(Lock *lk)
{
	if(tas(&lk->val))
		return 0;
	return 1;
}

void
unlock(Lock *lk)
{
	lk->val = 0;
}
