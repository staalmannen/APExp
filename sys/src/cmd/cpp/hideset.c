#include <u.h>
#include <libc.h>
#include <stdio.h>
#include "cpp.h"

/*
 * A hideset is a null-terminated array of Nlist pointers.
 * They are referred to by indices in the hidesets array.
 * Hideset 0 is empty.
 */

#define	HSSIZ	128
typedef	Nlist	**Hideset;
Hideset	*hidesets;
int	nhidesets = 0;
int	maxhidesets = 3;
int	inserths(Hideset, Hideset, Nlist *);

/*
 * Interning index for newhideset().
 *
 * **newhideset() used to compare its candidate against EVERY existing
 * hideset**, so the cost of one macro expansion grew with the number of
 * distinct hidesets seen so far and the cost of a file was quadratic in
 * it.  That is not a regression, it is how this file has always been;
 * it only became worth fixing when `expand()' started painting RP as
 * well as NAME (see the comment there) and clisp's `spvw.c' went from
 * sixteen seconds to minutes.  *The intersection made an existing cost
 * visible rather than creating one* -- the unpatched cpp already spent
 * most of those sixteen seconds in this function.
 *
 * `hsbucket' holds 1+index so that 0 can mean empty, and `hsnext'
 * chains the collisions; both are rebuilt by nothing, since a hideset
 * is never removed.  A set is canonical -- `inserths' keeps it sorted
 * and deduplicated -- so at most one existing entry can equal the
 * candidate and the first match is the answer, exactly as the linear
 * scan's first match was.
 */
#define	HSBUCKETS	4096		/* must be a power of two */
static int	hsbucket[HSBUCKETS];
static int	*hsnext;

static unsigned
hashhs(Hideset hs)
{
	unsigned h;
	Hideset p;

	h = 2166136261U;
	for (p = hs; *p; p++) {
		/*
		 * The key is the pointer, and it must be the WHOLE pointer:
		 * kencc is LLP64, so a cast to ulong would drop the top half
		 * of every Nlist* on amd64 and bucket unrelated sets together.
		 * `uvlong' rather than `uintptr' on purpose -- `uintptr' is a
		 * recent addition to 9front's `<u.h>' and this file is built by
		 * whatever host cpp the bootstrap starts from.
		 */
		h ^= (unsigned)((uvlong)*p >> 4);
		h *= 16777619;
	}
	return h & (HSBUCKETS-1);
}

static int
sameset(Hideset a, Hideset b)
{
	while (*a == *b) {
		if (*a == NULL)
			return 1;
		a++;
		b++;
	}
	return 0;
}

/*
 * Test for membership in a hideset
 */
int
checkhideset(int hs, Nlist *np)
{
	Hideset hsp;

	if (hs>=nhidesets)
		abort();
	for (hsp = hidesets[hs]; *hsp; hsp++) {
		if (*hsp == np)
			return 1;
	}
	return 0;
}

/*
 * Return the (possibly new) hideset obtained by adding np to hs.
 */
int
newhideset(int hs, Nlist *np)
{
	int i, len;
	unsigned h;
	Nlist *nhs[HSSIZ+3];
	Hideset hs1;

	len = inserths(nhs, hidesets[hs], np);
	h = hashhs(nhs);
	for (i = hsbucket[h]; i != 0; i = hsnext[i-1])
		if (sameset(nhs, hidesets[i-1]))
			return i-1;
	if (len>=HSSIZ)
		return hs;
	if (nhidesets >= maxhidesets) {
		maxhidesets = 3*maxhidesets/2+1;
		hidesets = (Hideset *)dorealloc(hidesets, (sizeof (Hideset *))*maxhidesets);
		hsnext = (int *)dorealloc(hsnext, sizeof(int)*maxhidesets);
	}
	hs1 = (Hideset)domalloc(len*sizeof(Hideset));
	memmove(hs1, nhs, len*sizeof(Hideset));
	hidesets[nhidesets] = hs1;
	hsnext[nhidesets] = hsbucket[h];
	hsbucket[h] = nhidesets+1;
	return nhidesets++;
}

int
inserths(Hideset dhs, Hideset shs, Nlist *np)
{
	Hideset odhs = dhs;

	while (*shs && *shs < np)
		*dhs++ = *shs++;
	if (*shs != np)
		*dhs++ = np;
	do {
		*dhs++ = *shs;
	} while (*shs++);
	return dhs - odhs;
}

/*
 * Hideset intersection.
 *
 * A function-like macro's expansion is hidden by (HS(name) & HS(')')) | {name},
 * not by HS(name) | {name}: see the comment in expand().  The arrays are
 * sorted but newhideset() interns, so walk one and test membership in the
 * other rather than merging by hand.  `hp' walks the inner array, which
 * newhideset() never reallocs -- it only grows `hidesets' itself.
 */
int
intersecthideset(int hs1, int hs2)
{
	Hideset hp;
	int hs;

	if (hs1==hs2)
		return hs1;
	if (hs1==0 || hs2==0)
		return 0;
	hs = 0;
	for (hp = hidesets[hs1]; *hp; hp++)
		if (checkhideset(hs2, *hp))
			hs = newhideset(hs, *hp);
	return hs;
}

/*
 * Hideset union
 */
int
unionhideset(int hs1, int hs2)
{
	Hideset hp;

	for (hp = hidesets[hs2]; *hp; hp++)
		hs1 = newhideset(hs1, *hp);
	return hs1;
}

void
iniths(void)
{
	hidesets = (Hideset *)domalloc(maxhidesets*sizeof(Hideset *));
	hsnext = (int *)domalloc(maxhidesets*sizeof(int));
	hidesets[0] = (Hideset)domalloc(sizeof(Hideset));
	*hidesets[0] = NULL;
	/*
	 * Hideset 0 is the empty set and is deliberately NOT indexed: every
	 * newhideset() call adds a name, so no candidate can ever be empty
	 * and hashing it would only add a bucket nothing matches.
	 */
	hsnext[0] = 0;
	nhidesets++;
}

void
prhideset(int hs)
{
	Hideset np;

	for (np = hidesets[hs]; *np; np++) {
		fprintf(stderr, (char*)(*np)->name, (*np)->len);
		fprintf(stderr, " ", 1);
	}
}
