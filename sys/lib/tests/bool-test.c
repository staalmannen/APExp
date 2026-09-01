/*
 * bool-test.c -- converting to bool is a comparison, not a truncation.
 *
 * C99 6.3.1.2: "When any scalar value is converted to _Bool, the result
 * is 0 if the value compares equal to 0; otherwise, the result is 1."
 * Every conversion to bool means that -- casts, assignments,
 * initialisers, arguments, returns -- and it is what makes bool usable
 * as a flag at all.
 *
 * kencc had no separate bool type: lex.c mapped _Bool and bool onto
 * LCHAR, which the grammar turns into BCHAR, so bool was a plain signed
 * char and converting to it kept the low byte. So (bool)256 was 0, and
 * (bool)p for an 8-byte-aligned pointer was whatever its low byte held
 * -- always even, so storing it in a one-bit bit field, which keeps
 * bit 0, always gave 0.
 *
 * Found through perl. handy.h has
 *
 *	#define cBOOL(cbool) ((bool) (cbool))
 *
 * and op.h uses it to record whether an op has a next sibling:
 *
 *	#define OpMAYBESIB_set(o, sib, parent) \
 *	    ((o)->op_moresib = cBOOL(sib), ...)
 *
 * Every op in every compiled program came out with op_moresib = 0
 * beside a correct op_sibparent, so Perl_op_linklist found no siblings,
 * every statement list collapsed to its first element, and miniperl
 * compiled programs it then declined to execute -- no output, no
 * diagnostic, exit status 0. Case 6 below is that macro.
 *
 * Build and run:  pcc -o bool-test bool-test.c
 * Prints "PASS" per case; exit status is the number of failures.
 */

#include <stdbool.h>
#include <stdio.h>
#include <string.h>

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

/* not static: nothing may fold these away */
int zero = 0;
int low_byte_zero = 256;
int low_bit_zero = 2;
/* long long, not long: kencc's long is 32 bits even on amd64, so a
   long here would be truncated to 0 before the cast ever saw it and the
   case would test nothing. */
long long big = 0x100000000LL;
double half = 0.5;
char buf[64];
char *aligned = buf;
char *nullp = 0;

static bool
returns_bool(int v)
{
	return v;		/* a return is a conversion too */
}

static int
takes_bool(bool b)
{
	return b;		/* as is an argument */
}

int
main(void)
{
	bool b;
	char detail[128];

	printf("sizeof(bool) = %d\n", (int)sizeof(bool));

	/*
	 * 1. The cast, on values whose low byte or low bit is zero --
	 *    the ones a truncating conversion gets wrong.
	 */
	sprintf(detail, "(bool)256 = %d", (int)(bool)low_byte_zero);
	check("cast of a value with a zero low byte",
	    (bool)low_byte_zero == 1, detail);

	sprintf(detail, "(bool)2 = %d", (int)(bool)low_bit_zero);
	check("cast of a value with a zero low bit",
	    (bool)low_bit_zero == 1, detail);

	sprintf(detail, "(bool)0x100000000 = %d (big = %lld)",
	    (int)(bool)big, big);
	check("cast of a value with a zero low word", (bool)big == 1,
	    detail);

	sprintf(detail, "(bool)0 = %d", (int)(bool)zero);
	check("cast of zero", (bool)zero == 0, detail);

	/*
	 * 2. Pointers. An object pointer is aligned, so its low bits are
	 *    zero; this is the case perl hit.
	 */
	sprintf(detail, "(bool)%p = %d", (void *)aligned, (int)(bool)aligned);
	check("cast of a non-null pointer", (bool)aligned == 1, detail);
	check("cast of a null pointer", (bool)nullp == 0, NULL);

	/* 3. Floating point: a value below 1 must not round to false. */
	sprintf(detail, "(bool)0.5 = %d", (int)(bool)half);
	check("cast of a fraction", (bool)half == 1, detail);

	/* 4. Assignment and initialisation convert as well. */
	b = low_byte_zero;
	sprintf(detail, "b = 256 gave %d", (int)b);
	check("assignment of a value with a zero low byte", b == 1, detail);

	{
		bool init = low_bit_zero;

		sprintf(detail, "bool b = 2 gave %d", (int)init);
		check("initialisation", init == 1, detail);
	}

	/* 5. Arguments and returns. */
	sprintf(detail, "takes_bool(256) = %d", takes_bool(low_byte_zero));
	check("argument conversion", takes_bool(low_byte_zero) == 1, detail);
	sprintf(detail, "returns_bool(256) = %d",
	    (int)returns_bool(low_byte_zero));
	check("return conversion", returns_bool(low_byte_zero) == 1, detail);

	/*
	 * 6. perl's OpMAYBESIB_set: a cast to bool stored in a one-bit
	 *    bit field, which keeps bit 0 of whatever it is given. This
	 *    is correct C for the field -- the conversion in front of it
	 *    is what has to produce 1.
	 */
	{
		struct {
			unsigned moresib:1;
			unsigned spare:15;
		} op;
		char *sib = aligned;

		memset(&op, 0, sizeof op);
		op.moresib = (bool)(sib);
		sprintf(detail, "moresib = (bool)%p gave %d", (void *)sib,
		    (int)op.moresib);
		check("cast to bool stored in a one-bit field",
		    op.moresib == 1, detail);

		op.moresib = (bool)(nullp);
		check("and a null pointer still gives 0", op.moresib == 0,
		    NULL);
	}

	/* 7. bool keeps unsigned char's representation. */
	check("sizeof(bool) is 1", sizeof(bool) == 1, NULL);

	/* 8. true and false. */
	check("true and false", (int)true == 1 && (int)false == 0, NULL);

	if (failures == 0)
		printf("\nall bool cases passed\n");
	else
		printf("\n%d bool case%s failed\n", failures,
		    failures == 1 ? "" : "s");
	return failures;
}
