#include "gc.h"

int
machcap(Node *n)
{

	if(n == Z)
		return 1;	/* test */

	switch(n->op) {
	case OMUL:
	case OLMUL:
	case OASMUL:
	case OASLMUL:
		if(typechl[n->type->etype])
			return 1;
		if(typev[n->type->etype]) {
				return 1;
		}
		break;

	case ONEG:
		/*
		 * Floating-point negation is a sign-bit flip, generated in
		 * cgen.c.  Answering 0 here made com.c rewrite -x as 0 - x,
		 * which is right for integers and wrong for floating point:
		 * 0.0 - 0.0 is +0.0, so -(+0.0) came out positive.
		 */
		if(typefd[n->left->type->etype])
			return 1;
		/* fall through */
	case OCOM:
	case OADD:
	case OAND:
	case OOR:
	case OSUB:
	case OXOR:
	case OASHL:
	case OLSHR:
	case OASHR:
		if(typechlv[n->left->type->etype])
			return 1;
		break;

	case OCAST:
		return 1;

	case OCOND:
	case OCOMMA:
	case OLIST:
	case OANDAND:
	case OOROR:
	case ONOT:
		return 1;

	case OASADD:
	case OASSUB:
	case OASAND:
	case OASOR:
	case OASXOR:
		return 1;

	case OASASHL:
	case OASASHR:
	case OASLSHR:
		return 1;

	case OPOSTINC:
	case OPOSTDEC:
	case OPREINC:
	case OPREDEC:
		return 1;

	case OEQ:
	case ONE:
	case OLE:
	case OGT:
	case OLT:
	case OGE:
	case OHI:
	case OHS:
	case OLO:
	case OLS:
		return 1;
	}
	return 0;
}
