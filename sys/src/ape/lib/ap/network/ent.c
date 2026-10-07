#include <netdb.h>

void sethostent(int x)
{
}

struct hostent *gethostent()
{
	return 0;
}

struct netent *getnetent()
{
	return 0;
}

void endhostent(void)
{
}

/* kencc has no weak symbols, so this is a no-op -- but it used to
 * arrive from the PUBLIC <features.h>, where its parameter names
 * had to be kept matching an external package's to avoid a cpp
 * redefinition error. Supplied privately instead. */
#ifndef weak_alias
#define weak_alias(name, aliasname) /* no weak alias on Plan9 */
#endif

weak_alias(sethostent, setnetent);
weak_alias(endhostent, endnetent);
