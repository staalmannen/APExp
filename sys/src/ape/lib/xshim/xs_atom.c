#include <u.h>
#include <libc.h>
#include <draw.h>
#include <xshim_types.h>
#include "xshim_p.h"
#include "xs_atomnames.h"

/*
 * Atoms, interned by name, as X interns them: the same name always gives the
 * same atom, and the predefined atoms (1..XA_LAST_PREDEFINED) have the names
 * X gives them.  An atom id is the index into the name table, plus one; the
 * names are never removed, so an id stays valid for the life of the program.
 */

static char	**names;
static ulong	nnames, ncap;

static void
loadpredefined(void)
{
	ulong i;

	if(names != nil)
		return;
	ncap = XS_NPREDEF + 64;
	names = malloc(ncap * sizeof *names);
	if(names == nil)
		return;
	for(i = 0; i < XS_NPREDEF; i++)
		names[i] = xs_predefined[i];
	nnames = XS_NPREDEF;
}

static Atom
lookup(char *name)
{
	ulong i;

	for(i = 0; i < nnames; i++)
		if(strcmp(names[i], name) == 0)
			return i + 1;
	return None;
}

Atom
XInternAtom(Display *dpy, char *name, Bool only_if_exists)
{
	char *copy;
	char **t;
	Atom a;

	USED(dpy);
	loadpredefined();
	if(names == nil || name == nil)
		return None;
	a = lookup(name);
	if(a != None || only_if_exists)
		return a;
	if(nnames == ncap){
		t = realloc(names, (ncap * 2) * sizeof *t);
		if(t == nil)
			return None;
		names = t;
		ncap *= 2;
	}
	copy = strdup(name);
	if(copy == nil)
		return None;
	names[nnames++] = copy;
	return nnames;
}

/* the name of an atom, as a copy the caller frees with XFree; nil if unknown */
char*
XGetAtomName(Display *dpy, Atom atom)
{
	USED(dpy);
	loadpredefined();
	if(atom == None || atom > nnames)
		return nil;
	return strdup(names[atom - 1]);
}

int
XFree(void *data)
{
	free(data);
	return 1;
}
