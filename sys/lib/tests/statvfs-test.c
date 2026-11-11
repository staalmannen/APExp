/*
 * statvfs-test.c -- statvfs/fstatvfs under APExp.
 *
 * ***TWO RUNS, AND BOTH ARE REQUIRED***, because the two modes are the
 * whole point of the implementation:
 *
 *	pcc -o statvfs-test statvfs-test.c && ./statvfs-test
 *	APEXP_STATVFS=strict ./statvfs-test
 *
 * The first must report free space; the second must fail with ENOSYS.
 * *A run of only the first cannot tell a working switch from a switch
 * that is never read*, which is the `structalign-test' arrangement for
 * the same reason.
 *
 * WHERE IT CAME FROM.  Plan 9 cannot answer this question -- 9P2000
 * has no `Tstatfs', and the file servers that do know (hjfs's `df')
 * print to the system console rather than to the caller.  libap used
 * to return ENOSYS always, which is the truthful answer and which
 * turns into ZERO in any caller that does not check: php's
 * `disk_free_space()' gives `false', the Phoronix Test Suite evaluates
 * `false < 1024' and reports `Lock creation failed due to lack of disk
 * space' on a disk with plenty.  `lib/ap/stat/statvfs.c' has the whole
 * argument and the reason the default is now the optimistic answer.
 *
 * THE gcc CONTROL IS `-DHOSTCHECK', AND IT IS NOT OPTIONAL:
 *
 *	gcc -DHOSTCHECK -o statvfs-host statvfs-test.c && ./statvfs-host
 *
 * That drops the APExp-specific sections and the version marker, and
 * leaves the POSIX invariants -- which glibc's real statvfs must also
 * satisfy.  *If section 1 fails on the host it is this file's bug, not
 * the library's*, which is what the convention is for.  The APExp
 * sections cannot run there because the host's statvfs reports a real
 * disk, and asserting 8 TiB against it would be asserting the answer
 * rather than the rule.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/statvfs.h>

#ifndef HOSTCHECK
/*
 * Version marker.  `pcc -o x x.c' relinks against the INSTALLED libap,
 * so without this a test from a fresh pull can run days-old library
 * code and report on it.  This one matters more than most: the whole
 * change is a behaviour switch, and the OLD library's answer (ENOSYS)
 * is a legitimate output of the NEW one under `strict' -- so a stale
 * libap would look exactly like a working `strict' run.
 */
extern int _statvfsmark(void);
#endif

static int fails;

static void
ok(const char *what, int cond)
{
	if(cond)
		printf("  PASS %s\n", what);
	else {
		printf("  FAIL %s\n", what);
		fails++;
	}
}

int
main(void)
{
	struct statvfs b;
	int fd, r, strict;
	unsigned long long bytes;

	/*
	 * Line-buffered, and a marker before any work.  A fault, a kill
	 * and a clean finish all give the prompt back, so silence is not
	 * a pass -- `fsync-test' had to learn that the expensive way.
	 */
	setvbuf(stdout, NULL, _IOLBF, 0);
	printf("statvfs-test: starting\n");

#ifndef HOSTCHECK
	printf("_statvfsmark = %d\n", _statvfsmark());
#endif

	/*
	 * The test reads the switch itself and asserts accordingly.
	 * That is not circular: the environment is this program's own
	 * INPUT, and what is being asserted is the library's response to
	 * it.  (Deriving the expectation from the library's own output
	 * would be the `munmaptrim-xcheck' mistake -- both sides of the
	 * comparison from the thing under test.)
	 */
	{
		char *s = getenv("APEXP_STATVFS");
		strict = s != NULL && strcmp(s, "strict") == 0;
	}
	printf("mode: %s\n\n", strict ? "strict (expect ENOSYS)"
				      : "default (expect success)");

	/* ---- 1: POSIX invariants, true of any implementation ------ */
	printf("Section 1: invariants every statvfs must satisfy\n");

	errno = 0;
	r = statvfs("/does/not/exist/anywhere", &b);
	ok("a missing path fails", r < 0);
	ok("...with ENOENT rather than ENOSYS", errno == ENOENT);

	errno = 0;
	r = fstatvfs(-1, &b);
	ok("fstatvfs(-1) fails", r < 0);
	ok("...with EBADF", errno == EBADF);

	/* ---- 2: the default mode reports space ---------------------- */
	printf("\nSection 2: statvfs(\"/\")\n");
	errno = 0;
	memset(&b, 0, sizeof b);
	r = statvfs("/", &b);

	if(strict){
		ok("strict: statvfs fails", r < 0);
		ok("strict: errno is ENOSYS", errno == ENOSYS);
	} else {
		ok("statvfs succeeds", r == 0);
		if(r == 0){
			ok("f_bsize is non-zero", b.f_bsize > 0);
			ok("f_frsize is non-zero", b.f_frsize > 0);
			ok("f_namemax is sane", b.f_namemax >= 14);
			/*
			 * The ordering invariant, which holds for a real
			 * filesystem and must hold for a synthetic one:
			 * you cannot have more available than free, nor
			 * more free than exist.
			 */
			ok("f_bavail <= f_bfree", b.f_bavail <= b.f_bfree);
			ok("f_bfree <= f_blocks", b.f_bfree <= b.f_blocks);

			/*
			 * **The multiplication is the point**, not the
			 * size: this is what every caller does, and on a
			 * 32-bit-`long' target it is where a too-large
			 * sentinel would wrap.  `f_frsize' is `unsigned
			 * long' (32 bits here) and `f_bavail' is
			 * `unsigned long long', so the product must be
			 * computed in 64 bits and must not be zero.
			 */
			bytes = (unsigned long long)b.f_bavail * b.f_frsize;
			printf("  INFO f_bavail=%llu f_frsize=%lu -> %llu bytes\n",
			    (unsigned long long)b.f_bavail,
			    (unsigned long)b.f_frsize, bytes);
			ok("available bytes do not overflow to zero", bytes > 0);
			ok("available bytes exceed 1MB (what callers gate on)",
			    bytes > 1024ULL * 1024ULL);
		}
	}

	/* ---- 3: fstatvfs agrees with statvfs ----------------------- */
	printf("\nSection 3: fstatvfs on an open descriptor\n");
	fd = open("/", O_RDONLY);
	if(fd < 0){
		printf("  INFO cannot open \"/\" (%s); section skipped\n",
		    strerror(errno));
	} else {
		struct statvfs f;

		errno = 0;
		memset(&f, 0, sizeof f);
		r = fstatvfs(fd, &f);
		if(strict){
			ok("strict: fstatvfs fails", r < 0);
			ok("strict: errno is ENOSYS", errno == ENOSYS);
		} else {
			ok("fstatvfs succeeds", r == 0);
			if(r == 0)
				ok("fstatvfs agrees with statvfs on f_frsize",
				    f.f_frsize == b.f_frsize);
		}
		close(fd);
	}

#ifndef HOSTCHECK
	/* ---- 4: APExp's own answer, which the host cannot have ----- */
	printf("\nSection 4: the synthetic values are recognisable\n");
	if(strict){
		printf("  INFO strict mode; section 4 is about the default\n");
	} else {
		memset(&b, 0, sizeof b);
		if(statvfs("/", &b) == 0){
			/*
			 * Not "is it 8 TiB" for its own sake -- the value
			 * may be retuned.  What is asserted is that it is
			 * a ROUND POWER OF TWO repeated across the block
			 * fields, which is what makes it legible as
			 * synthetic to anyone reading `stat -f' or a
			 * debugger.  A measured filesystem would not be.
			 */
			ok("f_blocks is a power of two",
			    b.f_blocks != 0 && (b.f_blocks & (b.f_blocks-1)) == 0);
			ok("free == total (nothing is measured)",
			    b.f_bfree == b.f_blocks && b.f_bavail == b.f_blocks);
			ok("f_type is 0, meaning unknown", b.f_type == 0);
			ok("f_fsid is 0", b.f_fsid == 0);
		}
	}
#endif

	printf("\nstatvfs-test: %d failures\n", fails);
	return fails;
}
