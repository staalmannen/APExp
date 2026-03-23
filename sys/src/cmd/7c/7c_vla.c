#include "gc.h"

/*
 * gvlalloc - emit the runtime stack allocation for a VLA declaration.
 *
 * Called from gen() in pgen.c when it encounters an OAS node whose
 * right-hand side is OALLOCA (planted by dcl.c for each VLA).  Emits:
 *
 *   ptr = OALLOCA(sizevar)
 *
 * The OALLOCA node is lowered by cgen() in 7c/cgen.c to an inline
 * SP adjustment.
 *
 * `vt`  - the VLA array Type (carries vlasizevar)
 * `ptr` - Node for the pointer auto that receives the base address
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
