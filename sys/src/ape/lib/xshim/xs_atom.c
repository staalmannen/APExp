#include <u.h>
#include <libc.h>
#include <draw.h>
#include "xshim_p.h"

/*
 * XInternAtom, with the semantics Tk's xlib/xutil.c had: each call returns a
 * new id above the predefined atoms.  Atoms are not interned by name, so the
 * same name gets a different id each time.  That is what Tk relies on today,
 * and changing it is a separate, gated step.
 *
 * The request counter Tk bumped here (LastKnownRequestProcessed) is a field of
 * Tk's own Display structure, which the library must not know about, so it is
 * not kept.
 */
static Atom	lastatom = XA_LAST_PREDEFINED;

Atom
XInternAtom(Display *dpy, char *name, Bool only_if_exists)
{
	USED(dpy);
	USED(name);
	USED(only_if_exists);
	return ++lastatom;
}
