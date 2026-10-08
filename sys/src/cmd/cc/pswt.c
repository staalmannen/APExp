#include "gc.h"

int
swcmp(const void *a1, const void *a2)
{
	C1 *p1, *p2;

	p1 = (C1*)a1;
	p2 = (C1*)a2;
	if(p1->val < p2->val)
		return -1;
	return p1->val > p2->val;
}

void
doswit(Node *n)
{
	Case *c;
	C1 *q, *iq, *iqh, *iql;
	long def, nc, i, j, isv, nh;
	Prog *hsb;
	Node *vr[2];
	int dup;

	def = 0;
	nc = 0;
	isv = 0;
	for(c = cases; c->link != C; c = c->link) {
		if(c->def) {
			if(def)
				diag(n, "more than one default in switch");
			def = c->label;
			continue;
		}
		nc++;
	}
	/*
	 * `isv' is a property of the SWITCH EXPRESSION and of nothing
	 * else.  It used to be OR'd with every case's own `isv' first
	 * and then overridden here, which read as though a wide label
	 * could widen the comparison; it cannot, since C converts
	 * each label to the expression's promoted type (see below).
	 */
	isv = typev[n->type->etype];

	iq = alloc(nc*sizeof(C1));
	q = iq;
	for(c = cases; c->link != C; c = c->link) {
		if(c->def)
			continue;
		q->label = c->label;
		if(isv)
			q->val = c->val;
		else
			q->val = (long)c->val;	/* cast ensures correct value for 32-bit switch on 64-bit architecture */
		/*
		 * A 64-bit case TYPE IS NOT A 64-BIT CASE VALUE, and
		 * this used to `continue' here -- dropping the label
		 * -- for any case whose TYPE was wide, under the
		 * comment "can never match".  `pgen.c:342' sets a
		 * case's `isv' from `typev[type]' alone, so
		 * `case (int64_t)14:' in a switch on an `int' was
		 * discarded, and the switch fell to `default' for a
		 * value it plainly contains.  SILENT: the file
		 * compiled.
		 *
		 * C 6.8.4.2p5 settles it and gcc agrees when asked:
		 * the constant expression "is converted to the
		 * promoted type of the controlling expression", so a
		 * wide label is TRUNCATED and then compared like any
		 * other -- `case 0x100000001LL:' in a switch on an
		 * int is reached by 1, and a label that truncates
		 * onto another one is a genuine duplicate rather than
		 * something to throw away.  The `(long)' cast above
		 * already performs exactly that conversion, so the
		 * rule costs nothing but the deletion.
		 *
		 * The warning stays, and is now about the VALUE: it
		 * fires only where a WIDE label's conversion actually
		 * changed the constant, which is gcc's `-Woverflow'
		 * case.  `c->isv' is still in the test and has to be:
		 * without it an ordinary `case 0xffffffffU:' in a
		 * switch on an `unsigned' warns, because `(long)'
		 * sign-extends it to -1 -- correct bits, different
		 * `vlong', and a warning on code that is right.
		 *
		 * CHICKEN's `runtime.c' is where this was found, and
		 * the spelling is not exotic: `chicken.h' writes
		 * every immediate as `((C_word)(C_SPECIAL_BITS |
		 * 0x10))' and `C_word' is 64 bits here, so four of
		 * `decode_literal2''s eight labels are small numbers
		 * wearing a wide type.
		 */
		if(c->isv && !isv && q->val != c->val)
			warn(n, "case constant truncated to the switch expression's type");
		q++;
	}
	/*
	 * AND `nc' IS RECOUNTED, which is the half that was loud.  It
	 * was the number of non-default cases, counted BEFORE the
	 * loop above could drop any -- while `alloc()' is a hunk bump
	 * allocator and does not zero.  So `qsort' and the duplicate
	 * scan below ran over `nc' entries of which the last few had
	 * never been written, and reported those against each other:
	 * **`duplicate cases in switch 0', once per unwritten pair,
	 * naming a case the program does not contain.**  Five dropped
	 * labels gave exactly the four reports chicken showed.
	 * Nothing drops any more, so the two counts agree -- this is
	 * insurance against the next `continue' added to that loop,
	 * and it is one line.
	 */
	nc = q - iq;
	qsort(iq, nc, sizeof(C1), swcmp);
	if(debug['W'])
	for(i=0; i<nc; i++)
		print("case %2ld: = %.8llux\n", i, (vlong)iq[i].val);
	dup = 0;
	for(i=0; i<nc-1; i++)
		if(iq[i].val == iq[i+1].val) {
			diag(n, "duplicate cases in switch %lld", (vlong)iq[i].val);
			dup = 1;
		}
	if(dup)
		return;
	if(def == 0) {
		def = breakpc;
		nbreak++;
	}
	if(!isv || ewidth[TIND] > ewidth[TLONG] || n->op == OREGISTER) {
		swit1(iq, nc, def, n);
		return;
	}

	/*
	 * 64-bit case on 32-bit machine:
	 * switch on high-order words, and
	 * in each of those, switch on low-order words
	 */
	if(n->op != OREGPAIR)
		fatal(n, "internal: expected register pair");
	if(thechar == '8'){	/* TO DO: need an enquiry function */
		vr[0] = n->left;	/* low */
		vr[1] = n->right;	/* high */
	}else{
		vr[0] = n->right;
		vr[1] = n->left;
	}
	vr[0]->type = types[TLONG];
	vr[1]->type = types[TLONG];
	gbranch(OGOTO);
	hsb = p;
	iqh = alloc(nc*sizeof(C1));
	iql = alloc(nc*sizeof(C1));
	nh = 0;
	for(i=0; i<nc;){
		iqh[nh].val = iq[i].val >> 32;
		q = iql;
		/* iq is sorted, so equal top halves are adjacent */
		for(j = i; j < nc; j++){
			if((iq[j].val>>32) != iqh[nh].val)
				break;
			q->val = (long)iq[j].val;
			q->label = iq[j].label;
			q++;
		}
		qsort(iql,  q-iql, sizeof(C1), swcmp);
if(0){for(int k=0; k<(q-iql); k++)print("nh=%ld k=%d h=%#llux l=%#llux lab=%ld\n", nh, k, (vlong)iqh[nh].val,  (vlong)iql[k].val, iql[k].label);}
		iqh[nh].label = pc;
		nh++;
		swit1(iql, q-iql, def, vr[0]);
		i = j;
	}
	patch(hsb, pc);
if(0){for(int k=0; k<nh; k++)print("k*=%d h=%#llux lab=%ld\n", k, (vlong)iqh[k].val,  iqh[k].label);}
	swit1(iqh, nh, def, vr[1]);
}

void
casf(void)
{
	Case *c;

	c = alloc(sizeof(*c));
	c->link = cases;
	cases = c;
}

long
outlstring(Rune *s, long n)
{
	char buf[sizeof(Rune)];
	int c, i;
	long r;

	if(suppress)
		return nstring;
	while(nstring % sizeof buf)
		outstring("", 1);
	r = nstring;
	while(n > 0) {
		c = *s++;
		if(align(0, types[TCHAR], Aarg1)) {
			for(i = sizeof buf; i > 0; c >>= 8)
				buf[--i] = c;
		} else {
			for(i = 0; i < sizeof buf; c >>= 8)
				buf[i++] = c;
		}
		outstring(buf, sizeof buf);
		n -= sizeof buf;
	}
	return r;
}

void
nullwarn(Node *l, Node *r)
{
	warn(Z, "result of operation not used");
	if(l != Z)
		cgen(l, Z);
	if(r != Z)
		cgen(r, Z);
}

void
ieeedtod(Ieee *ieee, double native)
{
	double fr, ho, f;
	int exp;

	/*
	 * Zero must be tested before the sign, not after: -0.0 is not
	 * < 0, so it used to fall into the "native == 0" arm below and
	 * come out as +0.0.  A constant -0.0 in the source was
	 * therefore emitted with its sign lost.
	 */
	if(native == 0) {
		ieee->l = 0;
		ieee->h = fpnegzero(native)? 0x80000000L: 0;
		return;
	}
	if(native < 0) {
		ieeedtod(ieee, -native);
		ieee->h |= 0x80000000L;
		return;
	}
	fr = frexp(native, &exp);
	f = 2097152L;		/* shouldnt use fp constants here */
	fr = modf(fr*f, &ho);
	ieee->h = ho;
	ieee->h &= 0xfffffL;
	ieee->h |= (exp+1022L) << 20;
	f = 65536L;
	fr = modf(fr*f, &ho);
	ieee->l = ho;
	ieee->l <<= 16;
	ieee->l |= (long)(fr*f);
}
