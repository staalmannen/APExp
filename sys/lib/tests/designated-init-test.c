/*
 * designated-init-test.c -- which object a designator designates.
 *
 * C99 6.7.8p17: a designator is interpreted relative to the object of
 * the *enclosing brace list*. So in
 *
 *	struct s x = { .inner.v = &n, .v = 1 };
 *
 * ".v" names the outer struct's v, whatever inner may contain -- the
 * fact that ".inner.v" just before it reached inside inner does not
 * leave us there. There are no braces around ".inner.v", so the current
 * object never changed.
 *
 * kencc used to stay inside. Having entered inner to satisfy the nested
 * designator, it restarted its member walk there for the next one, so a
 * member of the same name at the inner level won, silently, whenever
 * one existed. LibreSSL's apps/openssl/ciphers.c is the shape:
 *
 *	union { ...; int *value; ...; } opt;
 *	const int value;
 *
 *	{
 *	  .type = OPTION_VALUE,
 *	  .opt.value = &cfg.version,
 *	  .value = TLS1_2_VERSION,
 *	}
 *
 * where the second ".value" found the union's "int *value" rather than
 * the "const int value" beside the union:
 *
 *	ciphers.c:55 initialize pointer to an integer: ciphers_options
 *
 * That is the benign way for this to fail -- the types disagreed, so it
 * was refused. The union is incidental; a plain nested struct with a
 * repeated member name does the same thing, and if the two members have
 * the *same* type nothing is diagnosed at all: the value lands at the
 * wrong offset and the program is quietly wrong. That is what cases 3
 * and 4 below are for.
 *
 * Build and run:  pcc -o designated-init-test designated-init-test.c
 * Prints "PASS" per case; exit status is the number of failures.
 */

#include <stdio.h>

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

static int target = 42;

/* 1. ciphers.c's own shape: a named union with a member whose name is
      repeated in the enclosing struct, at a different type. */
struct opt {
	const char *name;
	int type;
	union {
		char **arg;
		int *flag;
		int *value;
	} opt;
	const int value;
	int tail;
};

static const struct opt options[] = {
	{
		.name = "tls1_2",
		.type = 7,
		.opt.value = &target,
		.value = 771,
		.tail = -1,
	},
	{
		.name = "v",
		.type = 7,
		.opt.value = &target,
		.value = 1,
		.tail = -2,
	},
};

/* 2. The same with a struct rather than a union, so nothing about this
      depends on union layout. */
struct inner2 { int a; int v; };
struct outer2 {
	struct inner2 in;
	int v;
	int tail;
};

static struct outer2 o2 = {
	.in.a = 5,
	.in.v = 6,
	.v = 7,
	.tail = 8,
};

/* 3. The silent case: both members are int, so a wrong match is not a
      type error and nothing is reported. Only the offsets tell. */
struct inner3 { int x; int same; };
struct outer3 {
	struct inner3 in;
	int same;
};

static struct outer3 o3 = {
	.in.same = 100,
	.same = 200,
};

/* 4. Designator after a nested one, naming a member that comes EARLIER
      in the outer struct -- the restart has to go back, not forward. */
struct inner4 { int p; int q; };
struct outer4 {
	int first;
	struct inner4 in;
	int last;
};

static struct outer4 o4 = {
	.in.q = 3,
	.first = 1,
	.last = 9,
};

/* 5. Nothing above should have disturbed the ordinary cases: a plain
      nested designator on its own, and positional initialisation. */
struct outer5 {
	struct inner4 in;
	int v;
};

static struct outer5 o5 = { .in.p = 11, .in.q = 12, .v = 13 };
static struct outer5 o5pos = { { 21, 22 }, 23 };

/* 6. With braces, a designator DOES restart at the braced level. This
      is the case the fix must not break. */
static struct outer2 o6 = {
	.in = { .v = 31, .a = 30 },
	.v = 32,
	.tail = 33,
};

int
main(void)
{
	char d[160];

	/* 1 */
	sprintf(d, "opt.value=%p (want %p), value=%d (want 771), tail=%d",
	        (void *)options[0].opt.value, (void *)&target,
	        options[0].value, options[0].tail);
	check("union member and struct member of the same name",
	      options[0].opt.value == &target && options[0].value == 771
	      && options[0].tail == -1, d);
	sprintf(d, "value=%d (want 1), tail=%d (want -2)",
	        options[1].value, options[1].tail);
	check("and again in the next array element",
	      options[1].opt.value == &target && options[1].value == 1
	      && options[1].tail == -2, d);

	/* 2 */
	sprintf(d, "in.a=%d in.v=%d v=%d tail=%d (want 5 6 7 8)",
	        o2.in.a, o2.in.v, o2.v, o2.tail);
	check("nested struct member and outer member of the same name",
	      o2.in.a == 5 && o2.in.v == 6 && o2.v == 7 && o2.tail == 8, d);

	/* 3 -- the one that would be silent */
	sprintf(d, "in.same=%d (want 100), same=%d (want 200)",
	        o3.in.same, o3.same);
	check("same name, same type: the value lands at the right offset",
	      o3.in.same == 100 && o3.same == 200, d);

	/* 4 */
	sprintf(d, "first=%d in.q=%d last=%d (want 1 3 9)",
	        o4.first, o4.in.q, o4.last);
	check("a designator after a nested one may name an earlier member",
	      o4.first == 1 && o4.in.q == 3 && o4.last == 9, d);

	/* 5 */
	sprintf(d, "in.p=%d in.q=%d v=%d (want 11 12 13)",
	        o5.in.p, o5.in.q, o5.v);
	check("consecutive designators into the same sub-object",
	      o5.in.p == 11 && o5.in.q == 12 && o5.v == 13, d);
	sprintf(d, "in.p=%d in.q=%d v=%d (want 21 22 23)",
	        o5pos.in.p, o5pos.in.q, o5pos.v);
	check("positional initialisation is unaffected",
	      o5pos.in.p == 21 && o5pos.in.q == 22 && o5pos.v == 23, d);

	/* 6 */
	sprintf(d, "in.a=%d in.v=%d v=%d tail=%d (want 30 31 32 33)",
	        o6.in.a, o6.in.v, o6.v, o6.tail);
	check("with braces, designators restart at the braced level",
	      o6.in.a == 30 && o6.in.v == 31 && o6.v == 32 && o6.tail == 33, d);

	if (failures)
		printf("\n%d failure(s)\n", failures);
	else
		printf("\nall ok\n");
	return failures;
}
