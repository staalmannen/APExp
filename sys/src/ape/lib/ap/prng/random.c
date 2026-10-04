/*
 * random, srandom, initstate, setstate -- the BSD/XSI additive-feedback
 * generator. ABSENT from libap entirely until bacon's link failed on
 * `Handle_Tree: undefined: random' and `main: undefined: srandom'.
 *
 * NOT the same thing as the `rand'/`srand'/`lrand' in `rand.c' beside
 * this file, and the difference is why that generator could not simply
 * be renamed. `rand.c' is Mitchell & Reeds, whose state is 607 longs
 * -- 2428 bytes. `initstate()' is handed a buffer of 8 to 256 bytes
 * and must keep the generator's whole state INSIDE it, so there is no
 * arrangement under which a 2428-byte state fits. *The library did
 * hold a working generator, and this is the one case in this tree
 * where reaching for it would have been wrong.*
 *
 * BIT-COMPATIBLE WITH glibc AND 4.4BSD, deliberately: a seeded
 * sequence is something programs and test suites compare across
 * machines, so "a generator with the right distribution" is not the
 * requirement -- the right NUMBERS are. `random-xcheck.c' is what says
 * it holds rather than this paragraph.
 *
 * THE DEFAULT STREAM COSTS NO TABLE. glibc ships 31 magic words for
 * the unseeded state; 4.3BSD's own comment says that table is the
 * state left by `initstate(1, randtbl, 128)', and the rear pointer
 * returns to 0 because srandom discards exactly 10*deg values. So
 * `srandom(1)' on first use reproduces it. *Deriving it is worth more
 * than transcribing it*: this tree has spent three rounds on constants
 * that existed twice and disagreed, and a 31-word table typed by hand
 * would be a fourth -- with the failure arriving as a wrong number
 * rather than a diagnostic. The cross-check measures the claim.
 *
 * `uint32_t' and not `long' throughout: the feedback step relies on
 * addition WRAPPING at 32 bits, which is true of kencc's `long' and
 * false of the host's. That is this tree's oldest invariant, and Gay's
 * strtod kit was broken by exactly it in four places.
 */
#include <stdlib.h>
#include <stdint.h>
#include <errno.h>

/*
 * Five state sizes. The degree is how many words of history the
 * feedback runs over; the separation is the distance between the two
 * pointers. Both tables are indexed by type, so they are written as
 * tables rather than as a switch.
 */
#define	TYPE_0		0		/* 8 bytes: a plain LCG, no array */
#define	TYPE_1		1		/* 32 bytes */
#define	TYPE_2		2		/* 64 bytes */
#define	TYPE_3		3		/* 128 bytes, the default */
#define	TYPE_4		4		/* 256 bytes */
#define	MAX_TYPES	5

#define	BREAK_0		8
#define	BREAK_1		32
#define	BREAK_2		64
#define	BREAK_3		128
#define	BREAK_4		256

#define	DEG_3		31

static const int degrees[MAX_TYPES] = { 0, 7, 15, DEG_3, 63 };
static const int seps[MAX_TYPES]    = { 0, 3,  1,     3,  1 };

/*
 * The default state. Word 0 is not state: it holds the type and the
 * rear pointer's offset, so that a buffer handed back by initstate()
 * describes itself and setstate() can restore it. That is the format
 * BSD defined and callers may round-trip, so it is not ours to change.
 */
static uint32_t deftbl[DEG_3 + 1];
static uint32_t *state = deftbl + 1;
static uint32_t *fptr;
static uint32_t *rptr;
static uint32_t *end_ptr;
static int rand_type = TYPE_3;
static int rand_deg = DEG_3;
static int rand_sep = 3;
static int started;

void
srandom(unsigned int seed)
{
	int32_t word, hi, lo;
	int i, kc;

	started = 1;
	/* seed 0 would leave the Lehmer recurrence at a fixed point */
	if(seed == 0)
		seed = 1;
	state[0] = seed;
	if(rand_type == TYPE_0)
		return;
	/*
	 * x = 16807*x mod (2^31 - 1), by Schrage's factorisation, so no
	 * intermediate leaves 32 bits. Writing it as a 64-bit multiply
	 * would be clearer and would stop being this generator.
	 */
	word = (int32_t)seed;
	for(i = 1; i < rand_deg; i++){
		hi = word / 127773;
		lo = word % 127773;
		word = 16807*lo - 2836*hi;
		if(word < 0)
			word += 2147483647;
		state[i] = (uint32_t)word;
	}
	fptr = &state[rand_sep];
	rptr = &state[0];
	end_ptr = &state[rand_deg];
	kc = rand_deg*10;
	while(--kc >= 0)
		random();
}

long
random(void)
{
	uint32_t val;

	if(!started)
		srandom(1);
	if(rand_type == TYPE_0){
		state[0] = (state[0]*1103515245u + 12345u) & 0x7fffffffu;
		return (long)state[0];
	}
	/*
	 * The low bit of the sum is discarded rather than masked off:
	 * in an additive generator it has period 2, so `random() & 1'
	 * would alternate. Hence the shift before the mask.
	 */
	*fptr += *rptr;
	val = (*fptr >> 1) & 0x7fffffffu;
	if(++fptr >= end_ptr){
		fptr = state;
		++rptr;
	}else if(++rptr >= end_ptr)
		rptr = state;
	return (long)val;
}

/* write the type and rear-pointer offset into the state's word 0 */
static void
stamp(void)
{
	if(rand_type == TYPE_0)
		state[-1] = TYPE_0;
	else
		state[-1] = (uint32_t)(MAX_TYPES*(rptr - state) + rand_type);
}

char *
initstate(unsigned int seed, char *arg_state, size_t n)
{
	char *ostate;
	int type;

	if(arg_state == 0){
		errno = EINVAL;
		return 0;
	}
	if(n < BREAK_0){
		errno = EINVAL;
		return 0;
	}
	if(!started)
		srandom(1);
	ostate = (char *)&state[-1];
	stamp();

	if(n < BREAK_1)
		type = TYPE_0;
	else if(n < BREAK_2)
		type = TYPE_1;
	else if(n < BREAK_3)
		type = TYPE_2;
	else if(n < BREAK_4)
		type = TYPE_3;
	else
		type = TYPE_4;

	rand_type = type;
	rand_deg = degrees[type];
	rand_sep = seps[type];
	state = (uint32_t *)arg_state + 1;
	end_ptr = &state[rand_deg];
	srandom(seed);
	stamp();
	return ostate;
}

char *
setstate(char *arg_state)
{
	uint32_t *new_state;
	char *ostate;
	int type, rear;

	if(arg_state == 0){
		errno = EINVAL;
		return 0;
	}
	new_state = (uint32_t *)arg_state;
	if(!started)
		srandom(1);
	/*
	 * SAVE BEFORE READING, and the order is load-bearing rather than
	 * tidy. Handing setstate() the state ALREADY in use is a thing
	 * callers do, and then `new_state[0]' is the very word stamp()
	 * just wrote -- so stamping first makes that call a no-op that
	 * continues the sequence, while reading first rewinds it to
	 * wherever the last srandom() left off. glibc stamps first, the
	 * two answers are both defensible, and only one of them is the
	 * one programs have been written against. `random-xcheck'
	 * section 4 is what found this: every other section passed.
	 */
	ostate = (char *)&state[-1];
	stamp();

	type = (int)(new_state[0] % MAX_TYPES);
	rear = (int)(new_state[0] / MAX_TYPES);
	/*
	 * Refuse a word that cannot have come from initstate() rather
	 * than running with it: a bad rear offset indexes outside the
	 * caller's buffer on the first call, where the fault would be
	 * reported against random() and not against this one.
	 */
	if(type == TYPE_0){
		if(rear != 0){
			errno = EINVAL;
			return 0;
		}
	}else if(type < TYPE_0 || type > TYPE_4 || rear >= degrees[type]){
		errno = EINVAL;
		return 0;
	}
	rand_type = type;
	rand_deg = degrees[type];
	rand_sep = seps[type];
	state = new_state + 1;
	if(type != TYPE_0){
		rptr = &state[rear];
		fptr = &state[(rear + rand_sep) % rand_deg];
	}
	end_ptr = &state[rand_deg];
	return ostate;
}
