#include "label.h"
#include <assert.h>
#include <stdio.h>

typedef unsigned long ulong;

/* argbase -- return stack location guaranteed to have args for m in it */
ulong *argbase(Label f) {
	ulong *fp = (ulong *)f.fp;
	return (ulong *)fp[3];	/* parent's fp */
}

/* movelabel -- adjust label to reflect new stack location */
Label movelabel(Label f, ulong sp) {
	long d = (long)(sp - f.sp);

	f.sp = f.sp + d;
	f.fp = f.fp + d;
	f.ap = f.ap + d;
	return f;
}

/* stackbase -- return the location of the base of the stack */
ulong *stackbase(Label m) {
	ulong *p = (ulong *)m.fp;

	p = (ulong *)p[3];	/* _main's fp */
	p = (ulong *)p[2];	/* main's ap */
	return p + *p;		/* base of main's args */
}

/* upframe -- find the label for the frame calling f */
Label upframe(Label f) {
	ulong *fp = (ulong *)f.fp;
	short mask = ((short *)fp)[3];
	int i;

	fp += 2;
	f.ap = *fp++;
	f.fp = *fp++;
	f.pc = *fp++;
	for (i = 6; i <= 11; i++)
		if (mask & 1 << i)
			f.r[i - 6] = *fp++;
	f.sp = (ulong)(fp + *fp);
	return f;
}
