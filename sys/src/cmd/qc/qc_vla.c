#include "gc.h"

/*
 * gvlalloc - emit the runtime stack allocation for a VLA declaration.
 */
void
gvlalloc(Type *vt, Node *ptr)
{
	Node *ap, *asn;

	if(vt == T || !vt->vla || vt->vlasizevar == Z || ptr == Z)
		return;

	ap = new(OALLOCA, vt->vlasizevar, Z);
	ap->type = typ(TIND, vt->link);

	asn = new(OAS, ptr, ap);
	gen(asn);
}
