/*
 * vla_test.c – regression tests for C99 variable-length arrays.
 *
 * Build:
 *   6c vla_test.c
 *   6l -o vla_test vla_test.6
 *   ./vla_test
 */
#include <u.h>
#include <libc.h>

/* ---- test 1: basic VLA, read/write -------------------------------- */
static int
sum(int n)
{
	int a[n];
	int i, s;

	for(i = 0; i < n; i++)
		a[i] = i + 1;
	s = 0;
	for(i = 0; i < n; i++)
		s += a[i];
	return s;
}

/* ---- test 2: sizeof(vla) must return runtime byte count ----------- */
static long
vlasize(int n)
{
	short buf[n];
	return sizeof buf;	/* must equal n * sizeof(short) == n*2 */
}

/* ---- test 3: VLA parameter list (C99 item 14) --------------------- */
static int
dot(int n, int a[n], int b[n])
{
	int i, s;
	s = 0;
	for(i = 0; i < n; i++)
		s += a[i] * b[i];
	return s;
}

/* ---- test 4: VLA in a nested scope -------------------------------- */
static void
nested(int r, int c)
{
	int i, j;
	{
		int m[r * c];
		for(i = 0; i < r*c; i++)
			m[i] = i;
		assert(m[r*c - 1] == r*c - 1);
	}
	/* stack should be restored here; allocate another VLA */
	{
		char tmp[c];
		for(j = 0; j < c; j++)
			tmp[j] = (char)j;
		assert(tmp[c-1] == (char)(c-1));
	}
}

/* ---- test 5: VLA pointer arithmetic ------------------------------ */
static void
ptrarith(int n)
{
	int a[n];
	int *p = a;
	int i;
	for(i = 0; i < n; i++)
		p[i] = i * i;
	for(i = 0; i < n; i++)
		assert(*(a + i) == i * i);
}

/* ---- test 6: zero-size edge case ---------------------------------- */
static void
zerovla(void)
{
	int n = 0;
	int a[n];	/* legal, no storage needed */
	USED(a);
}

void
main(void)
{
	int u[3] = {1, 2, 3};
	int v[3] = {4, 5, 6};

	assert(sum(5)  == 15);
	assert(sum(10) == 55);
	assert(vlasize(7)  == 7  * 2);
	assert(vlasize(13) == 13 * 2);
