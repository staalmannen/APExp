#include "gc.h"

/*
 * gvlalloc - emit the runtime stack allocation for a VLA declaration.
 *
 * For 1c/2c the sgen.c gen() dispatch calls cgen(n, D_NONE, n), and
 * the OAS case in cgen evaluates the OALLOCA rhs into the lhs auto.
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
