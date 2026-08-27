#include <u.h>
#include <sys/types.h>
#include <errno.h>
#include <libsec.h>

void
arc4random_buf(void *buf, size_t nbytes)
{
	genrandom(buf, nbytes);
}

unsigned int
arc4random(void)
{
	uint v;

	arc4random_buf(&v, sizeof v);
	return v;
}

/*
 * arc4random_uniform - a uniform value in [0, upper_bound).
 *
 * From OpenBSD. Taking arc4random() % upper_bound is the obvious
 * spelling and is biased whenever upper_bound does not divide 2**32:
 * the low residues occur once more often than the high ones. Instead
 * reject the first 2**32 % upper_bound values, so that what remains is
 * an exact multiple of upper_bound.
 *
 * 2**32 % upper_bound == -upper_bound % 2**32, which is what the
 * unsigned negation below computes without needing 64-bit arithmetic.
 * The loop is expected to run once; the worst case, upper_bound just
 * over 2**31, rejects half the draws each time.
 */
unsigned int
arc4random_uniform(unsigned int upper_bound)
{
	unsigned int r, min;

	if (upper_bound < 2)
		return 0;

	min = -upper_bound % upper_bound;

	for (;;) {
		r = arc4random();
		if (r >= min)
			break;
	}
	return r % upper_bound;
}

int
getentropy(void *buf, size_t len)
{
	if (len > 256) {
		errno = EIO;
		return -1;
	}
	genrandom(buf, len);
	return 0;
}
