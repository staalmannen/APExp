/*
 * punoffset-test.c -- does a store survive when the object is later
 * read at a DIFFERENT OFFSET through a cast pointer?
 *
 *	pcc -o punoffset-test punoffset-test.c && ./punoffset-test
 *	gcc -fno-strict-aliasing -O2 -o /tmp/p punoffset-test.c && /tmp/p
 *
 * ***A COMPILER TEST, AND ITS SUBJECT IS A SILENT MISCOMPILE THAT WAS
 * LIVE IN EVERY BACKEND.*** `6c/reg.c's `mkvar' keys a variable on
 * (sym, name, OFFSET), so `x+0(SP)' and `x+6(SP)' are two UNRELATED
 * variables.  An ordinary type pun writes one and reads the other, the
 * store then has no readers, and `regopt' excises it:
 *
 *	int f(void){ u64 x = g(); return *((u16*)&x + 3); }
 *	  CALL g; MOVWLZX x+-2(SP),AX	-- g()'s result never stored
 *
 *	u64 f(u64 x){ *((u16*)&x+3) = 0xbeef; return x; }
 *	  MOVW $48879,x+6(FP); MOVQ BP,AX	-- the write is lost
 *
 * *** IT IS NOT A `REGARG' BUG, WHICH IS WHAT THE FIRST DRAFT OF THIS
 * FILE WAS CALLED.*** The parameter cases are the ones that led here --
 * amd64 passes argument one in BP, so the frame copy exists only
 * because `cc/pgen.c' spills it, and that spill is what got excised --
 * but sections 1 and 2 show a PLAIN LOCAL losing its store with no
 * parameter involved at all. *Naming it after the first example found
 * would have hidden half of it.*
 *
 * WHERE IT CAME FROM. clisp's `mtypecode(obj)' is `(*((tint*)&(obj)+3))',
 * the type tag read out of an object's top two bytes, and `mconsp',
 * `matomp' and `SstringCase' are all built on it.  `lisp.run' printed
 * its banner and then died reading `namestring_asciz[bytelen-1]' with
 * `bytelen' 0: `directory_namestring_parts' had answered "not a cons"
 * for a pathname slot that provably held one, because
 * `var object directory = ...' wrote `directory+-16(SP)' and
 * `mconsp(directory)' read `directory+-10(SP)'.
 *
 * ***THE INSTRUMENT THAT FOUND IT ALMOST MISSED IT.*** Reading the
 * generated code for that function, `MOVWQZX directory+-10(SP),SI' was
 * taken as proof that the local "is in memory and written" -- the READ
 * was checked and nothing was checked to have written it. The same
 * shape as trusting a disassembly's mnemonic over its bytes.
 *
 * SECTIONS 3, 6, 7 AND 8 ARE CONTROLS AND PASSED EVEN UNFIXED. Keeping
 * the address in a pointer variable makes the compiler emit a `LEAQ',
 * which is a `D_ADDR', and `mkvar' marks those in `addrs' explicitly --
 * so the bug was never "the address was taken", it was "the address was
 * taken and FOLDED INTO the memory reference".  A test with only the
 * pointer-variable form reports a clean run against a broken compiler.
 *
 * ***IT CANNOT BE WRITTEN WITH A UNION.*** A union is the portable way
 * to pun and it also makes the compiler keep the object in memory for
 * its own reasons -- which is the path that already worked. The test
 * has to replicate the cast real code writes. For the same reason the
 * gcc check wants `-fno-strict-aliasing': the question is what kencc
 * does with this shape, not whether the shape is strictly conforming.
 */

#include <stdio.h>
#include <stdlib.h>

typedef unsigned long long u64;
typedef unsigned short u16;

static int failed = 0;

/* volatile so that gcc -O2 cannot fold the pun away and test nothing */
static volatile u64 seed = 0x1234000000000000ULL;

static u64
opaque(void)
{
	return seed;
}

static void
ck(const char *what, u64 got, u64 want)
{
	if (got == want) {
		printf("PASS %s: 0x%llx\n", what, (unsigned long long)got);
	} else {
		printf("FAIL %s: got 0x%llx want 0x%llx\n", what,
		       (unsigned long long)got, (unsigned long long)want);
		failed++;
	}
}

/* 1. a LOCAL written as a whole, read at an offset */
static u16
localread(void)
{
	u64 x = opaque();
	return *((u16*)&x + 3);
}

/* 2. a LOCAL written at an offset, read as a whole */
static u64
localwrite(void)
{
	u64 x = opaque();
	*((u16*)&x + 3) = 0xbeef;
	return x >> 48;
}

/* 3. control: the same local, reached through a pointer variable */
static u16
localptr(void)
{
	u64 x = opaque();
	u64 *p = &x;
	return (u16)(*p >> 48);
}

/* 4. a PARAMETER read at an offset.  On amd64 this one is in REGARG. */
static u16
paramread(u64 x)
{
	return *((u16*)&x + 3);
}

/* 5. a PARAMETER written at an offset, then read as a whole */
static u64
paramwrite(u64 x)
{
	*((u16*)&x + 3) = 0xbeef;
	return x >> 48;
}

/* 6. control: parameter through a pointer variable */
static u16
paramptr(u64 x)
{
	u64 *p = &x;
	return (u16)(*p >> 48);
}

/* 7. control: by value, which never needed a frame copy */
static u16
parambyvalue(u64 x)
{
	return (u16)(x >> 48);
}

/* 8. control: the SECOND parameter really is on the stack */
static u16
param2read(u64 a, u64 x)
{
	(void)a;
	return *((u16*)&x + 3);
}

int
main(void)
{
	u64 v;

	setvbuf(stdout, (char*)0, _IOLBF, 0);
	printf("punoffset-test: starting\n");

	v = 0x1234000000000000ULL;

	/* the four that were broken */
	ck("1 local read at offset", localread(), 0x1234);
	ck("2 local written at offset", localwrite(), 0xbeef);
	ck("4 parameter read at offset", paramread(v), 0x1234);
	ck("5 parameter written at offset", paramwrite(v), 0xbeef);

	/* the four controls, which passed even against a broken compiler */
	ck("3 local via pointer variable", localptr(), 0x1234);
	ck("6 parameter via pointer variable", paramptr(v), 0x1234);
	ck("7 parameter by value", parambyvalue(v), 0x1234);
	ck("8 second parameter at offset", param2read(0, v), 0x1234);

	printf("punoffset-test: %d failure%s\n", failed,
	       failed == 1 ? "" : "s");
	return failed;
}
