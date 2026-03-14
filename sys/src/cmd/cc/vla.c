#include "cc.h"

/*
 * gvlalloc – emit the runtime stack allocation for a VLA declaration.
 *
 * Called from the statement code-generator (in each back-end's gen.c or
 * pgen.c) immediately after the hidden _vlaN size variables have been
 * initialised.  Emits:
 *
 *   ptr = OALLOCA(sizevar)
 *
 * The OALLOCA node is lowered by the back-end's cgen() to an inline SP
 * adjustment (see 6c/cgen.c, 8c/cgen.c, 5c/cgen.c).
 *
 * `vt`  – the VLA array Type (carries vlasizevar)
 * `ptr` – Node for the pointer auto that receives the base address
 */
void
gvlalloc(Type *vt, Node *ptr)
{
	Node *ap, *asn;

	if(vt == T || !vt->vla || vt->vlasizevar == Z || ptr == Z)
		return;

	ap = new(OALLOCA, vt->vlasizevar, Z);
	ap->type = typ(TIND, vt->link);	/* pointer to element type */

	asn = new(OAS, ptr, ap);
	gen(asn);
}

/*
 * gvla_prologue / gvla_epilogue / gret
 *
 * No-op defaults.  Each back-end that needs to bracket VLA functions
 * with a frame-pointer save/restore provides strong definitions of
 * these three functions in its own cgen.c (see 6c/cgen.c etc.).
 * The linker resolves to the strong definition when one is present.
 */
#pragma	weak	gvla_prologue
void gvla_prologue(void) {}

#pragma	weak	gvla_epilogue
void gvla_epilogue(void) {}

#pragma	weak	gret
