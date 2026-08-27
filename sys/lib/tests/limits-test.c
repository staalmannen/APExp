/*
 * limits-test.c -- do the *_MAX macros match the types they describe?
 *
 * The one that matters most is
 *
 *      (size_t) -1 == SIZE_MAX
 *
 * because portable code uses SIZE_MAX as a sentinel meaning "length not
 * given, go and find the NUL". gnulib's quotearg.c is the case that
 * prompted this:
 *
 *      for (size_t i = 0;
 *           ! (argsize == SIZE_MAX ? arg[i] == '\0' : i == argsize);
 *           i++)
 *
 * with argsize passed as (size_t) -1. If SIZE_MAX is narrower than
 * size_t, that comparison is false, the NUL test is never reached, and
 * the loop counts towards 2**64 instead -- walking off the end of the
 * heap. That is how GNU ls died:
 *
 *      page fault  quotearg_buffer_restyled+0x162
 *      sys: trap: fault read addr=0x44b000
 *
 * with i at 0xa8d0, exactly the distance from the string to the first
 * unmapped page.
 *
 * APE has form here. From CLAUDE.md: size_t and ssize_t were "unsigned
 * long" and "long", which is 32-bit on Plan 9 amd64, until 2026-04 --
 * sprintf passed vsnprintf an n of 0x7fff7ffffffe and memset ran into
 * the guard page. The types were fixed then. Whether every macro that
 * describes them was fixed with them is what this checks.
 *
 * Nothing here is Plan 9-specific: it is all identities the C standard
 * requires, so it passes anywhere and only fails where something is
 * genuinely inconsistent.
 *
 * Build and run:  pcc -o limits-test limits-test.c
 * Prints "PASS" per case; exit status is the number of failures.
 */

#include <stdio.h>
#include <stddef.h>
#include <stdint.h>
#include <limits.h>
#include <sys/types.h>	/* ssize_t */

static int failures;

static void
check(const char *what, int ok, const char *detail)
{
	if (ok)
		printf("PASS  %s\n", what);
	else {
		printf("FAIL  %s%s%s\n", what, detail ? ": " : "",
		       detail ? detail : "");
		failures++;
	}
}

int
main(void)
{
	char d[160];

	printf("sizeof: void* %d, size_t %d, ptrdiff_t %d, long %d,"
	       " long long %d, intmax_t %d\n",
	       (int)sizeof(void *), (int)sizeof(size_t), (int)sizeof(ptrdiff_t),
	       (int)sizeof(long), (int)sizeof(long long), (int)sizeof(intmax_t));
	printf("SIZE_MAX    %llx\n", (unsigned long long)SIZE_MAX);
	printf("UINTPTR_MAX %llx\n", (unsigned long long)UINTPTR_MAX);
	printf("PTRDIFF_MAX %llx\n", (unsigned long long)PTRDIFF_MAX);
	printf("UINTMAX_MAX %llx\n", (unsigned long long)UINTMAX_MAX);
	printf("ULONG_MAX   %llx\n", (unsigned long long)ULONG_MAX);
	printf("SSIZE_MAX   %llx\n", (unsigned long long)SSIZE_MAX);

	/* Which headers actually got read, and what they decided. When
	   SIZE_MAX is wrong these say why: SIZE_MAX comes from
	   "#if INTPTR_WIDTH == 64" in <stdint.h>, INTPTR_WIDTH comes from
	   <stdint_arch.h>, and _BITS64 comes from <_apetypes.h>. Any of
	   the three can be missing if a header is shadowed -- pcc searches
	   -I/$objtype/include/ape before -I/sys/include/ape, so the host's
	   stock APE wins there unless this tree has a file of that name. */
#ifdef _STDINT_GENERIC_H_
	printf("stdint.h:       APExp's (_STDINT_GENERIC_H_ set)\n");
#else
	printf("stdint.h:       NOT APExp's -- _STDINT_GENERIC_H_ unset\n");
#endif
#ifdef _STDINT_ARCH_H_
	printf("stdint_arch.h:  read\n");
#else
	printf("stdint_arch.h:  NOT read\n");
#endif
#ifdef INTPTR_WIDTH
	printf("INTPTR_WIDTH:   %d\n", (int)INTPTR_WIDTH);
#else
	printf("INTPTR_WIDTH:   undefined\n");
#endif
#ifdef _BITS64
	printf("_BITS64:        set\n");
#else
	printf("_BITS64:        unset\n");
#endif
	printf("\n");

	/* The one quotearg depends on. Written exactly as it uses it. */
	{
		size_t argsize = (size_t) -1;

		sprintf(d, "(size_t)-1 is %llx, SIZE_MAX is %llx",
		        (unsigned long long)argsize,
		        (unsigned long long)SIZE_MAX);
		check("(size_t)-1 == SIZE_MAX", argsize == SIZE_MAX, d);
	}

	/* SIZE_MAX must be able to hold any object size, so it cannot be
	   narrower than the type. */
	sprintf(d, "sizeof(size_t) is %d but SIZE_MAX needs %d bytes",
	        (int)sizeof(size_t),
	        SIZE_MAX > 0xffffffffULL ? 8 : 4);
	check("SIZE_MAX is as wide as size_t",
	      (sizeof(size_t) == 8) == (SIZE_MAX > 0xffffffffULL), d);

	/* C23, and APE defines it; older hosts may not. */
#ifdef SIZE_WIDTH
	sprintf(d, "SIZE_WIDTH is %d, sizeof(size_t)*8 is %d",
	        (int)SIZE_WIDTH, (int)(sizeof(size_t) * 8));
	check("SIZE_WIDTH matches sizeof(size_t)",
	      SIZE_WIDTH == sizeof(size_t) * 8, d);
#else
	printf("note  SIZE_WIDTH is not defined here\n");
#endif

	/* A pointer has to fit in uintptr_t, and on a flat address space
	   size_t and uintptr_t are the same width. */
	check("sizeof(uintptr_t) == sizeof(void *)",
	      sizeof(uintptr_t) == sizeof(void *), "they differ");
	sprintf(d, "UINTPTR_MAX %llx, SIZE_MAX %llx",
	        (unsigned long long)UINTPTR_MAX, (unsigned long long)SIZE_MAX);
	check("UINTPTR_MAX == SIZE_MAX", UINTPTR_MAX == SIZE_MAX, d);
	{
		uintptr_t u = (uintptr_t) -1;
		check("(uintptr_t)-1 == UINTPTR_MAX", u == UINTPTR_MAX, NULL);
	}

	/* ptrdiff_t is signed and the same width. */
	check("sizeof(ptrdiff_t) == sizeof(size_t)",
	      sizeof(ptrdiff_t) == sizeof(size_t), "they differ");
	sprintf(d, "PTRDIFF_MAX %llx, SIZE_MAX/2 %llx",
	        (unsigned long long)PTRDIFF_MAX,
	        (unsigned long long)(SIZE_MAX / 2));
	check("PTRDIFF_MAX == SIZE_MAX/2",
	      (unsigned long long)PTRDIFF_MAX == SIZE_MAX / 2, d);

	/* ssize_t, which had the same history as size_t and the same bug:
	   SSIZE_MAX was LONG_MAX, and kencc's long is 32-bit on amd64
	   while ssize_t has been long long since the 2026-04 width fix. */
	{
		size_t big = (size_t) -1;
		ssize_t smax = (ssize_t) (((size_t) -1) >> 1);

		sprintf(d, "sizeof(size_t) is %d", (int)sizeof(size_t));
		check("size_t can hold more than 4G on a 64-bit host",
		      sizeof(void *) != 8 || big > 0xffffffffULL, d);

		sprintf(d, "sizeof(ssize_t) is %d, SSIZE_MAX is %llx",
		        (int)sizeof(ssize_t), (unsigned long long)SSIZE_MAX);
		check("SSIZE_MAX is as wide as ssize_t", SSIZE_MAX == smax, d);
		check("sizeof(ssize_t) == sizeof(size_t)",
		      sizeof(ssize_t) == sizeof(size_t), "they differ");
	}

	/* The same identity for every other unsigned type: a macro that
	   does not match its type is the bug, whichever type it is. */
	{
		unsigned int ui = (unsigned int) -1;
		unsigned long ul = (unsigned long) -1;
		unsigned long long ull = (unsigned long long) -1;
		uintmax_t um = (uintmax_t) -1;

		check("(unsigned int)-1 == UINT_MAX", ui == UINT_MAX, NULL);
		check("(unsigned long)-1 == ULONG_MAX", ul == ULONG_MAX, NULL);
		check("(unsigned long long)-1 == ULLONG_MAX",
		      ull == ULLONG_MAX, NULL);
		check("(uintmax_t)-1 == UINTMAX_MAX", um == UINTMAX_MAX, NULL);
	}

	/* And the signed ones, via the standard identity. */
	check("INT_MAX is 2**(N-1)-1 for int",
	      INT_MAX == (int)((1ULL << (sizeof(int) * 8 - 1)) - 1), NULL);
	check("LONG_MAX is 2**(N-1)-1 for long",
	      LONG_MAX == (long)((1ULL << (sizeof(long) * 8 - 1)) - 1), NULL);
	check("INTMAX_MAX is 2**(N-1)-1 for intmax_t",
	      INTMAX_MAX == (intmax_t)((1ULL << (sizeof(intmax_t) * 8 - 1)) - 1),
	      NULL);
	sprintf(d, "INT64_MAX %llx", (unsigned long long)INT64_MAX);
	check("INT64_MAX is 0x7fffffffffffffff",
	      INT64_MAX == 0x7fffffffffffffffLL, d);
	sprintf(d, "UINT64_MAX %llx", (unsigned long long)UINT64_MAX);
	check("UINT64_MAX is 0xffffffffffffffff",
	      UINT64_MAX == 0xffffffffffffffffULL, d);

	/* The fixed-width types have to be exactly that wide. */
	check("sizeof(int32_t) == 4", sizeof(int32_t) == 4, NULL);
	check("sizeof(int64_t) == 8", sizeof(int64_t) == 8, NULL);
	check("sizeof(intmax_t) >= 8", sizeof(intmax_t) >= 8, NULL);

	if (failures)
		printf("\n%d failure(s)\n", failures);
	else
		printf("\nall ok\n");
	return failures;
}
