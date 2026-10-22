/*
 * rdev-test.c -- can two different files be told apart?
 *
 * WHERE THIS CAME FROM.  `cmp bacon.bac.c src/bacon.bac.c' on 9front
 * printed NOTHING for two files of different sizes that differ at byte
 * 17, while Plan 9's own `cmp' answered
 *
 *	bacon.bac.c src/bacon.bac.c differ: char 17
 *
 * **A comparison program that cannot report a difference is the purest
 * form of a check that cannot fail**, and this tree runs `cmp' in its
 * own instructions -- so every such check had been silently passing.
 *
 * THE CAUSE IS ONE CONSTANT.  `_dirtostat' set `st_rdev = 0' for every
 * file.  gnulib's `same_file' is dev+ino and then a SECOND arm
 * (`diffutils/src/system.c:30'): two char specials, or two block
 * specials, with equal `st_rdev' are "the same device, so the same
 * contents".  With st_rdev a constant that arm says YES TO EVERY PAIR.
 * `cmp' asks whether its own stdout is /dev/null so it can skip
 * describing a difference nobody will read (`cmp.c:336'); under a
 * terminal stdout is /dev/cons, a char special, and /dev/null is a char
 * special, so cmp concluded it was writing to the bit bucket and
 * compared in silence.  `diff.c:1300' is a second victim: inside a
 * recursive diff, two non-regular files with equal st_rdev are reported
 * identical without being read.
 *
 * SECTION 0 IS THE CONTROL, AND IT IS ALSO A SECOND MEASUREMENT.
 * Two ordinary files must have different `st_ino' -- POSIX requires it,
 * and if that fails nothing else in this file means anything, since
 * `same_file' would be answering on the dev+ino arm before it ever
 * reaches the one under test.  **It is also where APE's 16-bit `ino_t'
 * would show.**  `sys/include/ape/sys/types.h' makes `ino_t' and
 * `dev_t' `unsigned short', while a Plan 9 qid path is 64 bits, so
 * st_ino is that path truncated to 16 bits and two files collide once a
 * file server holds more than 65536 of them.  *The APExp tree alone is
 * 64799 files.*  Section 0 prints both widths and both inodes, so a run
 * says which world it is in rather than leaving it to be assumed.
 *
 * Build:
 *   gcc -o rdev-test rdev-test.c && ./rdev-test      # host, 0
 *   pcc -o rdev-test rdev-test.c && ./rdev-test      # 9front
 *
 * Exit status is the failure count.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

#ifndef __APEXP__
extern int _rdevmark(void);
#endif

static int fails;

static void
eq(const char *what, long got, long want)
{
	if (got == want)
		printf("PASS %-44s %ld\n", what, got);
	else {
		printf("FAIL %-44s %ld   want %ld\n", what, got, want);
		fails++;
	}
}

/*
 * diffutils/src/system.c's same_file(), transcribed rather than
 * described -- the whole question is what THAT function answers, and a
 * paraphrase of it would be a different test.
 */
static int
same_file(const struct stat *s, const struct stat *t)
{
	if (!(s->st_ino == t->st_ino && s->st_dev == t->st_dev)) {
		if (((S_ISCHR(s->st_mode) && S_ISCHR(t->st_mode))
		     || (S_ISBLK(s->st_mode) && S_ISBLK(t->st_mode)))
		    && s->st_rdev == t->st_rdev)
			return 1;
		return 0;
	}
	return 1;
}

/* The char-special files to try, commonest first.  Two that exist and
 * are character devices are enough; the names differ between systems,
 * so the file finds them rather than naming a pair. */
static const char *devs[] = {
	"/dev/null", "/dev/zero", "/dev/cons", "/dev/tty",
	"/dev/random", "/dev/urandom", "/dev/full", 0
};

int
main(void)
{
	struct stat a, b, out, nul;
	char fa[] = "/tmp/rdevtestaXXXXXX";
	char fb[] = "/tmp/rdevtestbXXXXXX";
	int da, db, i, n, inow;
	const char *na, *nb;
	struct stat ds[8];
	const char *dn[8];

	printf("rdev-test: can two different files be told apart?\n");
	printf("The rule under test is diffutils' own same_file(),\n");
	printf("transcribed verbatim: dev+ino, then st_rdev for the\n");
	printf("character and block specials.\n\n");

#ifndef __APEXP__
	printf("_rdevmark = %d\n\n", _rdevmark());
#endif

	/* ---- section 0: CONTROL, and the ino_t measurement ---- */
	printf("Section 0: CONTROL -- two ordinary files, and the widths\n");
	printf("     sizeof(ino_t) = %d   sizeof(dev_t) = %d\n",
	    (int)sizeof(((struct stat *)0)->st_ino),
	    (int)sizeof(((struct stat *)0)->st_dev));
	inow = (int)sizeof(((struct stat *)0)->st_ino);
	if (inow < 4)
		printf("     NOTE: st_ino is %d bits, so two files collide\n"
		       "     once a server holds more than %lu of them --\n"
		       "     the APExp tree alone is about 64800 files.\n",
		    inow * 8, (unsigned long)1 << (inow * 8));

	da = mkstemp(fa);
	db = mkstemp(fb);
	if (da < 0 || db < 0) {
		printf("FAIL could not make two temporary files\n");
		return ++fails;
	}
	write(da, "aaaa", 4);
	write(db, "bbbb", 4);
	if (fstat(da, &a) < 0 || fstat(db, &b) < 0) {
		printf("FAIL could not fstat them\n");
		return ++fails;
	}
	printf("     a: dev %ld ino %ld    b: dev %ld ino %ld\n",
	    (long)a.st_dev, (long)a.st_ino, (long)b.st_dev, (long)b.st_ino);
	eq("two ordinary files are not the same file",
	    same_file(&a, &b), 0);
	close(da);
	close(db);
	unlink(fa);
	unlink(fb);

	/* ---- section 1: two distinct character devices ---- */
	printf("\nSection 1: two distinct character devices\n");
	n = 0;
	for (i = 0; devs[i] && n < 8; i++)
		if (stat(devs[i], &ds[n]) == 0 && S_ISCHR(ds[n].st_mode)) {
			dn[n] = devs[i];
			n++;
		}
	if (n < 2) {
		printf("     only %d character device(s) found -- SKIPPED\n", n);
		printf("     (this section needs two; it is not a failure)\n");
	} else {
		na = dn[0];
		nb = dn[1];
		printf("     %s: rdev %ld    %s: rdev %ld\n",
		    na, (long)ds[0].st_rdev, nb, (long)ds[1].st_rdev);
		eq("two different char devices are not one file",
		    same_file(&ds[0], &ds[1]), 0);
	}

	/* ---- section 2: PROBE -- the exact question cmp asks ---- */
	printf("\nSection 2: PROBE -- what `cmp' asks about its own stdout\n");
	printf("     (asserts nothing: the answer depends on where stdout\n");
	printf("      goes.  With stdout on a TERMINAL the right answer is\n");
	printf("      `no'; redirect it to a file and the question is moot,\n");
	printf("      since cmp's test requires stdout to be a char device.)\n");
	if (fstat(1, &out) < 0 || stat("/dev/null", &nul) < 0)
		printf("     could not stat stdout or /dev/null\n");
	else {
		printf("     stdout: chr %d rdev %ld   /dev/null: chr %d rdev %ld\n",
		    S_ISCHR(out.st_mode) != 0, (long)out.st_rdev,
		    S_ISCHR(nul.st_mode) != 0, (long)nul.st_rdev);
		if (S_ISCHR(out.st_mode) && same_file(&out, &nul))
			printf("     -> cmp would believe stdout IS /dev/null\n"
			       "        and compare in SILENCE.  If stdout is a\n"
			       "        terminal, that is the bug.\n");
		else
			printf("     -> cmp would print its result normally.\n");
	}

	printf("\n%d failures\n", fails);
	return fails;
}
