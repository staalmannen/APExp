/*
 * cmplx.c
 *
 * C99 _Complex support for the Plan9/9front C compiler.
 *
 * _Complex float  (TCFLOAT)  and  _Complex double  (TCDOUBLE)  are lowered
 * entirely in the frontend.  In memory they are identical to:
 *   struct { float  re, im; }   (TCFLOAT,  width = 2*SZ_FLOAT)
 *   struct { double re, im; }   (TCDOUBLE, width = 2*SZ_DOUBLE)
 *
 * All arithmetic is expanded by cplxarith() before code generation.
 * The backends see only ordinary float/double loads, stores, and arithmetic,
 * plus struct copies (handled by the existing sugen() path).
 *
 * Return-value ABI: complex-returning functions use the same hidden-pointer
 * mechanism as TVLONG/TSTRUCT/TUNION because TCFLOAT and TCDOUBLE are
 * included in typesuvinit[] which is what typecmplx points to.
 */
#include "cc.h"

static int cplxtmpno;

/*
 * cplxtmp: allocate a fresh anonymous auto of complex type ct.
 * Each call produces a unique name to prevent aliasing.
 */
static Node*
cplxtmp(Type *ct)
{
	char buf[40];
	Sym *s;
	Node *n;

	snprint(buf, sizeof buf, ".cx%d", cplxtmpno++);
	s = slookup(buf);
	if(s->type == T) {
		s->class = CAUTO;
		s->type = ct;
		s->offset = 0;
	}
	n = new(ONAME, Z, Z);
	n->sym = s;
	n->type = ct;
	n->etype = ct->etype;
	n->class = CAUTO;
	n->addable = 1;
	return n;
}

/*
 * cplxre: lvalue for the real component of complex node n.
 *
 * Generates:  *(baseT *)&n
 */
Node*
cplxre(Node *n)
{
	Node *addr, *ind;
	Type *bt, *pt;

	bt = cplxbase(n->type->etype);
	pt = typ(TIND, bt);
	addr = new(OADDR, n, Z);
	addr->type = pt;
	ind = new(OIND, addr, Z);
	ind->type = bt;
	ind->addable = 1;
	return ind;
}

/*
 * cplxim: lvalue for the imaginary component of complex node n.
 *
 * Generates:  *((baseT *)&n + 1)
 */
Node*
cplxim(Node *n)
{
	Node *addr, *add, *off, *ind;
	Type *bt, *pt;

	bt = cplxbase(n->type->etype);
	pt = typ(TIND, bt);
	addr = new(OADDR, n, Z);
	addr->type = pt;
	off = new(OCONST, Z, Z);
	off->vconst = bt->width;
	off->type = types[TLONG];
	add = new(OADD, addr, off);
	add->type = pt;
	ind = new(OIND, add, Z);
	ind->type = bt;
	ind->addable = 1;
	return ind;
}

/*
 * cplxstore: build OLIST(OAS(dest.re, re), OAS(dest.im, im)).
 */
static Node*
cplxstore(Node *dest, Node *re, Node *im)
{
	Node *dre, *dim, *asre, *asim;
	Type *bt;

	bt = cplxbase(dest->type->etype);
	dre = cplxre(dest);
	dim = cplxim(dest);
	asre = new(OAS, dre, re);
	asre->type = bt;
	asim = new(OAS, dim, im);
	asim->type = bt;
	return new(OLIST, asre, asim);
}

/*
 * cplxcast: promote or reinterpret node n to complex type ct.
 *
 * real -> complex:  result is (ct){(baseT)n, 0.0}
 * complex -> complex: component-wise precision conversion.
 *
 * Returns a node of type ct (OCOMMA whose right child is the result temp).
 */
Node*
cplxcast(Node *n, Type *ct)
{
	Node *tmp, *asgn, *result;
	Type *bt, *sbt;

	bt = cplxbase(ct->etype);
	tmp = cplxtmp(ct);

	if(n->type != T && iscmplx(n->type->etype)) {
		/* complex -> complex (possibly different precision) */
		Node *srctmp, *stmpas, *src_re, *src_im, *cre, *cim;
		srctmp = cplxtmp(n->type);
		stmpas = new(OAS, srctmp, n);
		stmpas->type = n->type;
		sbt = cplxbase(n->type->etype);
		src_re = cplxre(srctmp);
		src_im = cplxim(srctmp);
		if(sbt != bt) {
			cre = new(OCAST, src_re, Z); cre->type = bt;
			cim = new(OCAST, src_im, Z); cim->type = bt;
			asgn = new(OLIST, stmpas, cplxstore(tmp, cre, cim));
		} else {
			asgn = new(OLIST, stmpas, cplxstore(tmp, src_re, src_im));
		}
	} else {
		/* real -> complex: imaginary = 0 */
		Node *re, *im;
		re = new(OCAST, n, Z);
		re->type = bt;
		im = new(OCONST, Z, Z);
		im->type = bt;
		im->fconst = 0.0;
		asgn = cplxstore(tmp, re, im);
	}
	result = new(OCOMMA, asgn, tmp);
	result->type = ct;
	return result;
}

/*
 * cplxarith: expand complex arithmetic or comparison node n in-place.
 *
 * On entry:
 *   n->op    the operation (OADD, OSUB, OMUL, ODIV, ONEG, OEQ, ONE,
 *            OASADD, OASSUB, OASMUL, OASDIV)
 *   n->type  result complex type (set by caller); int for OEQ/ONE
 *   n->left, n->right  operands (already through tcom())
 *
 * On exit: *n replaced with an OCOMMA tree that evaluates operands into
 * temporaries, computes result components, stores into a fresh auto,
 * and yields the auto as the expression value.
 *
 * For OEQ/ONE: *n is replaced with the boolean int expression directly.
 */
void
cplxarith(Node *n)
{
	Node *l, *r;
	Node *ltmp, *rtmp, *tmp;
	Node *ltmpas, *rtmpas;
	Node *lre, *lim, *rre, *rim;
	Node *resre, *resim, *asgn, *result;
	Type *ct, *bt;

	/*
	 * Determine the complex type to work in.
	 * For OEQ/ONE the caller sets n->type = int after calling us,
	 * so we derive ct from the operands.
	 */
	l = n->left;
	r = n->right;
	ct = n->type;
	if(ct == T || !iscmplx(ct->etype)) {
		if(l != Z && l->type != T && iscmplx(l->type->etype))
			ct = l->type;
		else if(r != Z && r->type != T && iscmplx(r->type->etype))
			ct = r->type;
		else {
			diag(n, "cplxarith: cannot determine complex type");
			return;
		}
	}
	bt = cplxbase(ct->etype);

	/* promote any real operands to complex */
	if(l != Z && l->type != T && !iscmplx(l->type->etype)) {
		l = cplxcast(l, ct);
		n->left = l;
	}
	if(r != Z && r->type != T && !iscmplx(r->type->etype)) {
		r = cplxcast(r, ct);
		n->right = r;
	}

	/* spill left operand to temp to avoid double-evaluation */
	ltmp = cplxtmp(ct);
	ltmpas = new(OAS, ltmp, l);
	ltmpas->type = ct;
	lre = cplxre(ltmp);
	lim = cplxim(ltmp);

	tmp = cplxtmp(ct);		/* result temporary */

	switch(n->op) {
	default:
		diag(n, "cplxarith: unsupported op %O", n->op);
		return;

	case OADD:
	case OASADD:
		/* (a+bi) + (c+di) = (a+c) + (b+d)i */
		rtmp = cplxtmp(ct);
		rtmpas = new(OAS, rtmp, r); rtmpas->type = ct;
		rre = cplxre(rtmp); rim = cplxim(rtmp);
		resre = new(OADD, lre, rre); resre->type = bt;
		resim = new(OADD, lim, rim); resim->type = bt;
		asgn = new(OLIST, ltmpas,
			new(OLIST, rtmpas, cplxstore(tmp, resre, resim)));
		break;

	case OSUB:
	case OASSUB:
		/* (a+bi) - (c+di) = (a-c) + (b-d)i */
		rtmp = cplxtmp(ct);
		rtmpas = new(OAS, rtmp, r); rtmpas->type = ct;
		rre = cplxre(rtmp); rim = cplxim(rtmp);
		resre = new(OSUB, lre, rre); resre->type = bt;
		resim = new(OSUB, lim, rim); resim->type = bt;
		asgn = new(OLIST, ltmpas,
			new(OLIST, rtmpas, cplxstore(tmp, resre, resim)));
		break;

	case OMUL:
	case OASMUL:
		/*
		 * (a+bi)(c+di) = (ac - bd) + (ad + bc)i
		 */
		rtmp = cplxtmp(ct);
		rtmpas = new(OAS, rtmp, r); rtmpas->type = ct;
		rre = cplxre(rtmp); rim = cplxim(rtmp);
		resre = new(OSUB,
			new(OMUL, lre, rre),
			new(OMUL, lim, rim));
		resre->type = bt;
		resre->left->type = bt;
		resre->right->type = bt;
		resim = new(OADD,
			new(OMUL, lre, rim),
			new(OMUL, lim, rre));
		resim->type = bt;
		resim->left->type = bt;
		resim->right->type = bt;
		asgn = new(OLIST, ltmpas,
			new(OLIST, rtmpas, cplxstore(tmp, resre, resim)));
		break;

	case ODIV:
	case OASDIV: {
		/*
		 * (a+bi)/(c+di) = ((ac+bd) + (bc-ad)i) / (c^2+d^2)
		 */
		Node *ac, *bd, *bc, *ad, *denom;
		rtmp = cplxtmp(ct);
		rtmpas = new(OAS, rtmp, r); rtmpas->type = ct;
		rre = cplxre(rtmp); rim = cplxim(rtmp);
		ac = new(OMUL, lre, rre); ac->type = bt;
		bd = new(OMUL, lim, rim); bd->type = bt;
		bc = new(OMUL, lim, rre); bc->type = bt;
		ad = new(OMUL, lre, rim); ad->type = bt;
		denom = new(OADD,
			new(OMUL, rre, rre),
			new(OMUL, rim, rim));
		denom->type = bt;
		denom->left->type = bt;
		denom->right->type = bt;
		resre = new(ODIV, new(OADD, ac, bd), denom);
		resre->type = bt;
		resre->left->type = bt;
		resim = new(ODIV, new(OSUB, bc, ad), denom);
		resim->type = bt;
		resim->left->type = bt;
		asgn = new(OLIST, ltmpas,
			new(OLIST, rtmpas, cplxstore(tmp, resre, resim)));
		break;
	}

	case ONEG:
		/* -(a+bi) = (-a) + (-b)i */
		resre = new(ONEG, lre, Z); resre->type = bt;
		resim = new(ONEG, lim, Z); resim->type = bt;
		asgn = new(OLIST, ltmpas, cplxstore(tmp, resre, resim));
		break;

	case OEQ:
	case ONE: {
		/*
		 * (a+bi)==(c+di)  iff  a==c && b==d
		 * Result is int.
		 */
		Node *cmpre, *cmpim, *both, *pre, *expr;
		rtmp = cplxtmp(ct);
		rtmpas = new(OAS, rtmp, r); rtmpas->type = ct;
		rre = cplxre(rtmp); rim = cplxim(rtmp);
		cmpre = new(OEQ, lre, rre); cmpre->type = types[TINT];
		cmpim = new(OEQ, lim, rim); cmpim->type = types[TINT];
		both = new(OANDAND, cmpre, cmpim); both->type = types[TINT];
		pre = new(OLIST, ltmpas, rtmpas);
		if(n->op == ONE) {
			expr = new(ONOT, both, Z);
			expr->type = types[TINT];
		} else {
			expr = both;
		}
		result = new(OCOMMA, pre, expr);
		result->type = types[TINT];
		*n = *result;
		return;
	}
	}

	result = new(OCOMMA, asgn, tmp);
	result->type = ct;
	*n = *result;
}
