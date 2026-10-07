/*
 * structalign-test -- does `pcc -J' lay structs out the way every
 * other C compiler does, and does plain `pcc' still lay them out the
 * 9front way?
 *
 * THREE RUNS, and the middle one is the control:
 *
 *   gcc           -o /tmp/sa structalign-test.c && /tmp/sa   0 failures
 *   pcc -9 -DPLAN9 -o sa structalign-test.c && ./sa          FAILURES
 *   pcc    -DPLAN9 -o sa structalign-test.c && ./sa          0 failures
 *
 * **Conforming layout is now the DEFAULT, so the flags have swapped
 * round**: a plain `pcc' conforms and `-9' is the way back to the
 * 9front rule. `-J' is still accepted and now does nothing.
 *
 * `-DPLAN9' is not decoration: section 5's `#pragma pack' is behind
 * it, exactly as `cmd/tar/mkfile' guards tar.h's, so without the
 * define that section compiles as ordinary structs and measures
 * nothing. gcc is run without it for the same reason.
 *
 * **The plain-pcc run is not a formality.** A test that passes under
 * -J tells you nothing on its own: it looks identical whether the
 * flag works or the compiler was always conforming. Only the run
 * WITHOUT the flag says the test can see the difference at all --
 *
 * **AND THAT MIDDLE RUN REPORTED 0 FAILURES ONCE, FOR A REASON THAT
 * WAS NOT THE COMPILER.** `pcc' appended `-J' to the compiler on
 * every invocation that passed neither -A nor -B (an ancient no-op
 * in stock cc, since nothing reads debug['J']), so the command
 * written above as the control was silently the same compile as the
 * one below it. `cfrontsz-probe' ran with cfront's own `-B', kept
 * the old rule, and disagreed on fourteen types in the same minute
 * -- which is the whole of the "two instruments disagree about one
 * compiler" puzzle section 7 below was added for. *If this control
 * passes again, suspect the driver before the compiler.*
 *
 * `-9' exists for this run and essentially only for this run. Without
 * a way back from a default, the control cannot be taken at all --
 * *an irreversible default takes the measurement with it.*
 *
 * *a check that cannot fail is not a check*, which this tree has
 * now paid for in `strftime-xcheck', `ctype-xcheck' and twice in
 * `random-xcheck'. Expect section 1 and section 2 to fail without
 * -J; if they pass, something is wrong with the test, not with the
 * compiler.
 *
 * ------------------------------------------------------------------
 * WHAT -J CHANGES, AND IT IS EXACTLY TWO LINES OF `align()'.
 *
 *   Asu2  tail padding: was always SZ_VLONG, now the struct's own
 *         alignment. `struct{char a[3];}' is 3 rather than 8.
 *   Ael1  a nested struct/union MEMBER: was always SZ_VLONG because
 *         `ewidth[TSTRUCT]' is negative and the ceiling test caught
 *         it, now that member type's own alignment.
 *
 * Scalars were never wrong: `Ael1' already answers `ewidth[etype]'
 * for them, which is their natural alignment on these targets. *The
 * defect was narrower than "kencc aligns everything to 8" and this
 * test is built around the two cases rather than around the slogan.*
 *
 * ------------------------------------------------------------------
 * WHY IT MATTERS, MEASURED RATHER THAN ASSERTED.
 *
 * GNU tar's `union block' came out 520 here where every other system
 * says 512, and since tar walks its archive with `union block *'
 * arithmetic, every block after the first landed eight bytes late --
 * both when tar WROTE an archive and when it READ one. The tree
 * carries `#pragma pack on' around tar.h's on-disk structs for that,
 * and section 5 checks the pragma still behaves with -J, since the
 * two mechanisms now touch the same code.
 *
 * ------------------------------------------------------------------
 * OFFSETS, NOT ONLY SIZES, and section 3 is the reason.
 *
 * A wrong `sizeof' breaks a stride. A wrong OFFSET puts one member's
 * bytes where another member is read, which is how a `const char *'
 * comes to hold the text `precisio' -- the cfront crash this round
 * started from. Sizes alone would pass a compiler that padded the
 * tail correctly and still misplaced an interior member.
 *
 * The expected numbers are gcc's, and gcc is the oracle because the
 * question IS "what does everyone else do". They are not transcribed
 * from a standard: the file was compiled with gcc and the numbers
 * taken from the run.
 */
#include <stdio.h>
#include <stddef.h>
#include <string.h>

static int failures;

static void
eq(const char *what, long got, long want)
{
	if(got == want)
		printf("PASS %-34s %ld\n", what, got);
	else {
		printf("FAIL %-34s got %ld, want %ld\n", what, got, want);
		failures++;
	}
}

/* ---- section 1: tail padding (Asu2) ---- */
struct c3  { char a[3]; };
struct c5  { char a[5]; };
struct c500{ char a[500]; };
struct sc  { short s; char c; };
struct ic  { int i; char c; };
struct dc  { double d; char c; };	/* alignment 8 already: must NOT move */

/* ---- section 2: a nested struct member (Ael1) ---- */
struct inner3 { char a[3]; };
struct outer3 { char c; struct inner3 i; char d; };
struct arr3   { char c; struct inner3 i[4]; };

/* ---- section 3: interior offsets ---- */
struct mixed {
	char		tag;
	struct inner3	n;
	short		s;
	char		trail;
};

/* ---- section 4: unions and bitfields ---- */
union  u3  { char a[3]; short s; };
struct bits { unsigned x : 3; unsigned y : 5; char c; };

/*
 * ---- section 8: a BIT-FIELD GROUP after a member ----
 *
 * GNU make's `struct command_switch', trimmed to the shape that
 * matters. It is here because this exact struct found a bug the rest
 * of this file could not: `sualign()' carried the current bit-field
 * UNIT's offset in `o', and the max-member-alignment loop added for
 * -J overwrote `o' with its own result -- so the SECOND and later
 * fields of every bit-field group were placed at the previous
 * member's ALIGNMENT instead of at the unit's offset. Here that put
 * `toenv', `no_makefile' and `specified' at offset 4, on top of
 * `type', and `6l' refused the link with `multiple initialization'
 * for every array entry whose two writes to those four bytes were
 * both non-zero.
 *
 * **Section 4's `struct bits' could never have caught it**: its two
 * bit fields are the FIRST members, so the clobbered `o' happened to
 * be the alignment of nothing and the offsets came out right anyway.
 * *A bit-field group needs a member in front of it before a wrong
 * unit offset is visible at all*, which is why this section is a
 * separate shape rather than a line added to that one.
 *
 * It asserts OFFSETS, not just the size: the size was right in both
 * builds -- 56 either way, since it is already a multiple of 8 -- so
 * a size-only check passes against the bug.
 */
struct cs {
	int		c;
	int		type;
	void		*value_ptr;
	unsigned int	env : 1;
	unsigned int	toenv : 1;
	unsigned int	no_makefile : 1;
	unsigned int	specified : 1;
	const void	*noarg_value;
};

/* ---- section 5: #pragma pack must still win ---- */
#ifdef PLAN9
#pragma pack on
#endif
struct packed3 { char a[3]; };
struct packedn { char c; struct inner3 i; char d; };
#ifdef PLAN9
#pragma pack off
#endif

/* ---- section 6: the shape that broke tar ---- */
struct sparse_t { char offs[12]; char numbytes[12]; };
struct oldgnu   {
	char	atime[12];
	char	ctime[12];
	char	offset[12];
	char	longnames[4];
	char	pad;
	struct sparse_t sp[4];
	char	isextended;
	char	realsize[12];
};

/*
 * ---- section 7: the two instruments disagreed, so ask both here ----
 *
 * `cfrontsz-probe' reported `node' as 8 here against the translator's
 * 3, and `struct name' as 152 against 144 -- i.e. kencc PADS. The same
 * `pcc', minutes later, built section 1 of this file and answered 3 for
 * `struct{char a[3];}' -- i.e. kencc does NOT pad. Both cannot be true
 * of one compiler, so one of the two runs is not measuring what its
 * output says.
 *
 * cfront's `node' is three TYPEDEF'd unsigned chars where section 1 has
 * one char ARRAY, and `align()' should not care -- `Ael1' walks through
 * TARRAY to the element type and a typedef is transparent. Asking both
 * IN ONE PROGRAM is what turns that "should" into a reading.
 *
 * A PROBE: it prints and asserts nothing, because its job is to tell
 * two instruments apart rather than to judge the compiler.
 */
typedef unsigned char TOK;
typedef unsigned char bit;
struct cf_node { TOK base; bit permanent; bit baseclass; };

int
main(void)
{
	printf("structalign-test: struct layout, with and without -J\n");
	/*
	 * WHICH COMPILER BUILT THIS. `-J' predefines this macro (see
	 * cc/lex.c), so its absence means the flag was not understood --
	 * `pcc' silently drops a flag its ARGBEGIN does not name, and
	 * `6c' turns an unknown letter into a debug counter, so without
	 * this line a stale compiler and a working one print the same
	 * thing. *That is the ambiguity the first VM run had.*
	 */
#ifdef __APEXP_CONFORMALIGN__
	printf("build: -J was understood (__APEXP_CONFORMALIGN__ defined)\n");
#else
	printf("build: -J NOT in effect (expected for the gcc run, which\n"
	       "       is the oracle). Under pcc this means either -J was\n"
	       "       not passed, or this pcc/6c predates the flag -- so\n"
	       "       if you passed -J and see this line, the compilers\n"
	       "       were NOT rebuilt and every number below is the old\n"
	       "       rule.\n");
#endif

	printf("\nSection 1: tail padding -- the struct's own alignment\n");
	eq("sizeof struct{char a[3];}", (long)sizeof(struct c3), 3);
	eq("sizeof struct{char a[5];}", (long)sizeof(struct c5), 5);
	eq("sizeof struct{char a[500];}", (long)sizeof(struct c500), 500);
	eq("sizeof struct{short;char;}", (long)sizeof(struct sc), 4);
	eq("sizeof struct{int;char;}", (long)sizeof(struct ic), 8);
	/*
	 * The CONTROL of this section: its alignment is already 8, so a
	 * conforming compiler and this one agree. It must pass in all
	 * three runs -- if it moves under -J the flag is over-reaching.
	 */
	eq("sizeof struct{double;char;} (control)", (long)sizeof(struct dc), 16);

	printf("\nSection 2: a nested struct member takes ITS alignment\n");
	eq("sizeof struct inner3", (long)sizeof(struct inner3), 3);
	eq("sizeof struct outer3", (long)sizeof(struct outer3), 5);
	eq("sizeof struct arr3", (long)sizeof(struct arr3), 13);

	printf("\nSection 3: interior OFFSETS, not just sizes\n");
	/*
	 * A compiler that padded tails correctly and still aligned the
	 * nested member to 8 passes every size above and fails here.
	 */
	eq("offsetof(mixed, tag)", (long)offsetof(struct mixed, tag), 0);
	eq("offsetof(mixed, n)", (long)offsetof(struct mixed, n), 1);
	eq("offsetof(mixed, s)", (long)offsetof(struct mixed, s), 4);
	eq("offsetof(mixed, trail)", (long)offsetof(struct mixed, trail), 6);
	eq("sizeof struct mixed", (long)sizeof(struct mixed), 8);

	printf("\nSection 4: unions, and a bit-field PROBE\n");
	eq("sizeof union{char a[3];short;}", (long)sizeof(union u3), 4);
	/*
	 * A PROBE, not a check, and the distinction is the point: -J
	 * does not claim to fix this and asserting it would make the
	 * test report a failure for something the flag never promised.
	 *
	 * gcc answers 4 -- it puts the two bit fields in one byte of the
	 * storage unit and places `c' in the next. kencc allocates bit
	 * fields in whole `tfield' units (dcl.c: `w += tfield->width'),
	 * so `c' lands at offset 4 and the struct is 8. That is a
	 * SEPARATE non-conformance, in different code, and it is
	 * recorded here rather than silently folded into this flag's
	 * result.
	 */
	printf("     %-34s %ld   (gcc says 4; kencc allocates bit fields\n"
	       "     %-34s      in whole int units, so 8 is expected here\n"
	       "     %-34s      and -J does not change it)\n",
	    "sizeof struct{u:3;u:5;char;}", (long)sizeof(struct bits), "", "");

	printf("\nSection 5: #pragma pack still wins over -J\n");
	/*
	 * Both mechanisms now read the same two lines of align(), so a
	 * -J that ignored packflg -- or a packflg the new code stepped
	 * on -- would show here and nowhere else. Under gcc the pragma
	 * is absent and these are the ordinary conforming answers, which
	 * happen to be the same; that is why the Plan 9 run is the one
	 * that carries this section.
	 */
	eq("sizeof packed struct{char a[3];}", (long)sizeof(struct packed3), 3);
	eq("sizeof packed nested", (long)sizeof(struct packedn), 5);

	printf("\nSection 6: the shape that made every tar archive wrong\n");
	eq("sizeof struct sparse_t", (long)sizeof(struct sparse_t), 24);
	/*
	 * 150, and that number came from RUNNING this under gcc rather
	 * than from adding the fields up: my own arithmetic said 149.
	 * *An expected value computed by hand is a guess written as
	 * though measured* -- the same slip as `40.3' being recorded as
	 * 0664 before the log was read.
	 */
	eq("sizeof struct oldgnu", (long)sizeof(struct oldgnu), 150);

	printf("\nSection 7: PROBE -- the shape cfrontsz-probe measured\n");
	/*
	 * If these two numbers DIFFER, a typedef'd-char struct and a
	 * char-array struct are laid out differently and that is a new
	 * finding. If they AGREE and both are 3, then cfrontsz-probe's
	 * `node == 8' came from a DIFFERENT compiler than this run --
	 * cfront's own build, which carries `-B' and its own flags. If
	 * they agree and both are 8, section 1 above has already failed
	 * and this run is the old rule throughout.
	 */
	printf("     %-34s %ld   (cfront's `node'; its translator says 3,\n",
	    "sizeof struct{TOK;bit;bit;}", (long)sizeof(struct cf_node));
	printf("     %-34s %ld    cfrontsz-probe measured 8 on the VM)\n",
	    "sizeof struct{char a[3];}", (long)sizeof(struct c3));

	printf("\nSection 8: a bit-field GROUP after a member\n");
	/*
	 * The numbers came from RUNNING this under gcc, not from adding
	 * the fields up -- the rule section 6 records after my own
	 * arithmetic said 149 where gcc said 150.
	 *
	 * `env' is the one that would still pass against the bug: it is
	 * the FIRST field of the group, the one that sets the unit
	 * offset rather than reading it back. The three after it are
	 * the check.
	 */
	/*
	 * `offsetof' CANNOT NAME A BIT FIELD -- C forbids taking its
	 * address, and gcc says so -- so the check is the COLLISION
	 * itself rather than the offsets: set each field of the group
	 * in turn and ask whether an earlier member survived it. That
	 * is the same question the linker asked, and it is the one the
	 * failure actually consists of.
	 */
	{
		struct cs s;
		long bad;

		memset(&s, 0, sizeof s);
		s.c = 0x11111111;
		s.type = 0x22222222;
		s.value_ptr = (void *)0;

		s.env = 1;
		eq("env=1 leaves type intact", (long)s.type, 0x22222222);
		s.toenv = 1;
		eq("toenv=1 leaves type intact", (long)s.type, 0x22222222);
		s.no_makefile = 1;
		eq("no_makefile=1 leaves type intact", (long)s.type, 0x22222222);
		s.specified = 1;
		eq("specified=1 leaves type intact", (long)s.type, 0x22222222);
		eq("...and c intact", (long)s.c, 0x11111111);

		/* all four are distinct bits of ONE unit */
		bad = (s.env != 1) + (s.toenv != 1) +
		      (s.no_makefile != 1) + (s.specified != 1);
		eq("all four bits read back as 1", bad, 0);

		eq("offsetof(cs, type)", (long)offsetof(struct cs, type), 4);
		eq("offsetof(cs, noarg_value)",
		    (long)offsetof(struct cs, noarg_value), 24);
		eq("sizeof struct cs", (long)sizeof(struct cs), 32);
	}

	printf("\n%d failures\n", failures);
	return failures;
}
