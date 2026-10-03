/*
 * dotdir-test -- does readdir() report "." and ".."?
 *
 *	pcc -o dotdir-test dotdir-test.c && ./dotdir-test
 *
 * On the host, where there is no libap to mark:
 *
 *	gcc -Wall -o /tmp/dotdir-test dotdir-test.c \
 *	    -xc <(echo 'int _dotdirmark(void){return 1;}')
 *	/tmp/dotdir-test
 *
 * (0 failures on glibc, which is the point: every assertion here is a
 * rule every other system already obeys, so the host run says whether
 * the TEST is right before the VM says whether the TREE is.)
 *
 * ------------------------------------------------------------------
 * THE BUG.
 *
 * **Plan 9 directories contain neither entry**, so libap's readdir()
 * reported neither, and a program that walks `.*' or counts entries
 * saw something no other system produces. Measured in two independent
 * suites: Tcl's `filename-14.9' wants `glob globTest/.*' to yield them,
 * and bash's `run-extglob' wants `. .. .a .foo' where this tree
 * answered `.a .foo'.
 *
 * ------------------------------------------------------------------
 * WHAT EACH SECTION IS FOR, since several could pass for the wrong
 * reason:
 *
 *  3  The names are there. An implementation that stopped at this
 *     would pass and still be wrong, which is what 4 is for.
 *  4  **THE HALF-FIX CONTROL.** `d_ino' must be the real inode: `.'
 *     the directory's own and `..' the parent's, both checked against
 *     `stat()'. Synthesising the names with `d_ino = 0' passes 3 and
 *     fails only here -- and it is the trap this tree already has a
 *     rule for, from zipfs's `st_rdev': *a field that is always zero
 *     reads as information and is not.* `find' uses these for loop
 *     detection and the classic `getcwd' walks `..' comparing them.
 *  5  Nothing was LOST. A fix that prepended two entries and dropped
 *     the first real one would pass 3 and 4.
 *  6  rewinddir() replays them, and telldir()/seekdir() agree across
 *     the boundary between synthetic and real entries -- the position
 *     of a real entry must still name that entry.
 *  7  **THE END-TO-END ASSERTION, and the one the two suites
 *     measure**: `glob("*")' must NOT return them and `glob(".*")'
 *     must. Both go through the same readdir, and musl's glob tells
 *     them apart with FNM_PERIOD rather than by skipping -- so this
 *     asks whether the thing the failing tests want actually happens,
 *     rather than whether readdir changed.
 *
 * Section 7 is why 3 is not enough on its own: *a library answering
 * correctly is not the same as the program on top of it answering
 * correctly*, and only one of those two is what the suites compare.
 *
 * ------------------------------------------------------------------
 * WHAT THE HOST CONTROL COVERED, AND TWO THINGS IT DID NOT.
 *
 * The old behaviour was replicated on the host with an LD_PRELOAD
 * readdir that drops both entries: **5 failures against 0**, naming
 * sections 3, 4a, 4b, 4c and 6a. Section 5 stayed PASS, correctly --
 * it asks about the real entries, which that control does not touch.
 *
 * **Section 7 did NOT fail under it**, and the reason matters: glibc's
 * `glob' does not route through an interposed `readdir', so on the
 * host section 7 measures glibc's glob and nothing of ours. *Its host
 * PASS is therefore not evidence that the readdir-to-glob chain
 * works.* On Plan 9 it is, because libap's glob calls libap's readdir
 * directly with no symbol versioning in between -- so section 7 is the
 * one section whose value is entirely on the VM.
 *
 * **Section 6b did not exercise what it is for on the host either.**
 * glibc returned `.hidden' first, so `pos_first_real' was 0 and the
 * seek never crossed the synthetic/real boundary. On Plan 9 the first
 * real entry is at position 2 and it will. The assertion is right
 * either way; the host run just does not reach the interesting case.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <errno.h>
#include <fcntl.h>	/* open() -- without it the call is implicit int */
#include <glob.h>
#include <sys/stat.h>
#include <sys/types.h>

extern int _dotdirmark(void);

static int failures;

static void
ck(int ok, const char *what)
{
	printf("%s: %s\n", ok ? "PASS" : "FAIL", what);
	if(!ok)
		failures++;
}

#define DIRNAME "dotdirtest.d"
#define NFILE 5

static void
cleanup(void)
{
	char p[256];
	int i;

	for(i = 0; i < NFILE; i++){
		sprintf(p, "%s/f%d", DIRNAME, i);
		unlink(p);
	}
	sprintf(p, "%s/.hidden", DIRNAME);
	unlink(p);
	rmdir(DIRNAME);
}

int
main(void)
{
	DIR *d;
	struct dirent *e;
	struct stat sdot, sdotdot;
	ino_t ino_dot, ino_dotdot;
	int sawdot, sawdotdot, nreal, i, tdot, tdotdot;
	long pos_first_real;
	char first_real[256], p[256];
	glob_t g;

	setvbuf(stdout, 0, _IONBF, 0);

	printf("1. _dotdirmark = %d  (libap whose readdir has . and ..)\n\n",
		_dotdirmark());

	/* 2. a directory with known contents */
	cleanup();
	if(mkdir(DIRNAME, 0777) < 0){
		perror("mkdir");
		return 1;
	}
	for(i = 0; i < NFILE; i++){
		sprintf(p, "%s/f%d", DIRNAME, i);
		close(open(p, O_WRONLY|O_CREAT|O_TRUNC, 0666));
	}
	sprintf(p, "%s/.hidden", DIRNAME);
	close(open(p, O_WRONLY|O_CREAT|O_TRUNC, 0666));
	ck(1, "2. built " DIRNAME " with 5 files and one dotfile");

	/* the truth to compare d_ino against */
	if(stat(DIRNAME, &sdot) < 0 || stat(".", &sdotdot) < 0){
		perror("stat");
		cleanup();
		return 1;
	}

	/* 3. the names are reported at all */
	sawdot = sawdotdot = nreal = 0;
	tdot = tdotdot = -1;
	ino_dot = ino_dotdot = 0;
	pos_first_real = -1;
	first_real[0] = 0;
	if((d = opendir(DIRNAME)) == NULL){
		perror("opendir");
		cleanup();
		return 1;
	}
	for(;;){
		long here = telldir(d);
		if((e = readdir(d)) == NULL)
			break;
		if(strcmp(e->d_name, ".") == 0){
			sawdot++;
			ino_dot = e->d_ino;
			tdot = e->d_type;
		} else if(strcmp(e->d_name, "..") == 0){
			sawdotdot++;
			ino_dotdot = e->d_ino;
			tdotdot = e->d_type;
		} else {
			if(pos_first_real < 0){
				pos_first_real = here;
				strcpy(first_real, e->d_name);
			}
			nreal++;
		}
	}
	closedir(d);
	ck(sawdot == 1 && sawdotdot == 1,
		"3. readdir reports exactly one '.' and one '..'");

	/*
	 * 4. THE HALF-FIX CONTROL -- see the header. Names without real
	 *    inodes would pass section 3 and fail only here.
	 */
	printf("   .  d_ino %llu  vs stat(%s)  %llu   d_type %d\n",
		(unsigned long long)ino_dot, DIRNAME,
		(unsigned long long)sdot.st_ino, tdot);
	printf("   .. d_ino %llu  vs stat(.)   %llu   d_type %d\n",
		(unsigned long long)ino_dotdot,
		(unsigned long long)sdotdot.st_ino, tdotdot);
	ck(ino_dot == sdot.st_ino, "4a. '.' d_ino is the directory's own");
	ck(ino_dotdot == sdotdot.st_ino, "4b. '..' d_ino is the parent's");
	ck(tdot == DT_DIR && tdotdot == DT_DIR, "4c. both are DT_DIR");

	/* 5. nothing lost: the six real entries are all still there */
	printf("   real entries seen: %d (want 6)\n", nreal);
	ck(nreal == 6, "5. all six real entries still reported");

	/* 6. rewinddir replays them; telldir/seekdir cross the boundary */
	if((d = opendir(DIRNAME)) != NULL){
		int again = 0;
		while((e = readdir(d)) != NULL)
			if(strcmp(e->d_name, ".") == 0
			|| strcmp(e->d_name, "..") == 0)
				again++;
		rewinddir(d);
		i = 0;
		while((e = readdir(d)) != NULL)
			if(strcmp(e->d_name, ".") == 0
			|| strcmp(e->d_name, "..") == 0)
				i++;
		ck(again == 2 && i == 2, "6a. rewinddir replays both");
		closedir(d);
	} else
		ck(0, "6a. rewinddir replays both (opendir failed)");

	if(pos_first_real >= 0 && (d = opendir(DIRNAME)) != NULL){
		seekdir(d, pos_first_real);
		e = readdir(d);
		printf("   seekdir(%ld) -> %s (want %s)\n",
			pos_first_real, e ? e->d_name : "(null)", first_real);
		ck(e != NULL && strcmp(e->d_name, first_real) == 0,
			"6b. seekdir to a real entry's telldir position");
		closedir(d);
	} else
		ck(0, "6b. seekdir to a real entry's telldir position");

	/*
	 * 7. END TO END, and the thing the two suites actually compare.
	 *    `*' must not match them, `.*' must -- both through the same
	 *    readdir, told apart by fnmatch's FNM_PERIOD rather than by
	 *    glob skipping anything.
	 */
	sprintf(p, "%s/*", DIRNAME);
	memset(&g, 0, sizeof g);
	sawdot = 0;
	if(glob(p, 0, NULL, &g) == 0){
		for(i = 0; i < (int)g.gl_pathc; i++){
			const char *b = strrchr(g.gl_pathv[i], '/');
			b = b ? b+1 : g.gl_pathv[i];
			if(strcmp(b, ".") == 0 || strcmp(b, "..") == 0)
				sawdot++;
		}
	}
	printf("   glob(\"%s\") matched %d, of which dot entries: %d\n",
		p, (int)g.gl_pathc, sawdot);
	ck(sawdot == 0, "7a. glob '*' does NOT match . or ..");
	globfree(&g);

	sprintf(p, "%s/.*", DIRNAME);
	memset(&g, 0, sizeof g);
	sawdot = 0;
	if(glob(p, 0, NULL, &g) == 0){
		for(i = 0; i < (int)g.gl_pathc; i++){
			const char *b = strrchr(g.gl_pathv[i], '/');
			b = b ? b+1 : g.gl_pathv[i];
			if(strcmp(b, ".") == 0 || strcmp(b, "..") == 0)
				sawdot++;
		}
	}
	printf("   glob(\"%s\") matched %d, of which dot entries: %d\n",
		p, (int)g.gl_pathc, sawdot);
	ck(sawdot == 2, "7b. glob '.*' DOES match both . and ..");
	globfree(&g);

	cleanup();
	printf("\n%d failures\n", failures);
	return failures;
}
