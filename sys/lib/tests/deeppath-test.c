/*
 * deeppath-test.c -- how deep a directory tree this system can make,
 * walk and remove.
 *
 * WHERE THIS CAME FROM. Tcl's fCmd.test builds a tree about fifty
 * levels deep and its cleanup could not delete it:
 *
 *	error deleting "./tfad/dir/tfad/dir/... x55": invalid operation
 *
 * `invalid operation` is hjfs's message for removing a directory that
 * still has something in it -- measured in rmdir-test, not guessed --
 * so the recursive delete had failed to empty it, and the whole of
 * unixFCmd.test and winFCmd.test aborted behind that one line. They
 * were the last two files in the suite still exiting with an error.
 *
 * THE LIMIT WAS OURS AND IT WAS A DEFINITION. `<limits.h>` had
 *
 *	#define PATH_MAX _POSIX_PATH_MAX	(255)
 *	#define NAME_MAX _POSIX_NAME_MAX	(14)
 *
 * -- the numbers POSIX guarantees every implementation supports *at
 * least*, used as though they were what this system supports at most.
 * `realpath()` is musl's and declares `char stack[PATH_MAX+1]`, so it
 * refused a 550-character path outright; Tcl's TclpObjNormalizePath and
 * its directory walker each declare `char buf[MAXPATHLEN]`. Plan 9 has
 * no inherent path limit at all -- 9P walks one element at a time and
 * never carries a whole path -- so the wall was entirely of APE's own
 * making. 14 was already contradicted next door: <dirent.h> sets
 * MAXNAMLEN to 255 and struct dirent is char d_name[MAXNAMLEN+1].
 *
 * THIS FILE'S OWN BUFFER IS NOT PATH_MAX, deliberately: the constant is
 * the thing under test, and a probe that sizes itself by the value it
 * is measuring cannot report that the value is wrong.
 *
 * It prints PATH_MAX and NAME_MAX first, so the output says which build
 * ran -- the rule that a green run has to be readable as one.
 *
 * Correct on glibc, which is where it was checked.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <limits.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>

#ifndef __GNUC__
#define HAVE_ERRSTR 1
#endif

#ifdef HAVE_ERRSTR
extern int errstr(char*, unsigned int);
static const char *
p9err(void)
{
	static char buf[256];

	buf[0] = 0;
	errstr(buf, sizeof buf);
	return buf;
}
#else
static const char *
p9err(void)
{
	return "";
}
#endif

static int failures;

static void
ok(const char *what, int good)
{
	printf("  %s %s\n", good ? "PASS" : "FAIL", what);
	if(!good)
		failures++;
}

static void
why(const char *what)
{
	const char *pe;

	pe = p9err();
	printf("  no   %s -> errno %d (%s)%s%s\n", what, errno,
		strerror(errno), pe[0] ? "; plan 9 says: " : "", pe);
}

#define ROOT	"dptest"
#define COMP	"deep"		/* 4 chars, so 5 per level with the slash */
#define WANT	140		/* about 700 characters, Tcl reaches ~550 */

static char path[16384];	/* NOT PATH_MAX: see the note at the top */

int
main(void)
{
	int i, depth, best;
	size_t len;
	struct stat st;
	DIR *d;
	char *slash, *rp;
	static char resolved[16384];

	printf("--- 0. what this build believes ---\n");
#ifdef MAXPATHLEN
	printf("  note PATH_MAX %d, MAXPATHLEN %d, NAME_MAX %d\n",
		(int)PATH_MAX, (int)MAXPATHLEN, (int)NAME_MAX);
#else
	/* glibc keeps MAXPATHLEN in <sys/param.h>; APE has it in limits.h */
	printf("  note PATH_MAX %d, NAME_MAX %d (no MAXPATHLEN here)\n",
		(int)PATH_MAX, (int)NAME_MAX);
#endif
	/*
	 * WHICH limits.h A COMPILE ACTUALLY READ, asked rather than
	 * inferred. `/$objtype/include/ape` is searched before
	 * `/sys/include/ape`, so stock APE's copy shadows this tree's
	 * unless a real file in every architecture directory shadows it
	 * back. This line is what found that: the numbers above were
	 * stock's, not the ones sitting in the tree.
	 */
#ifdef _APEXP_LIMITS_H
	printf("  note <limits.h> came from THIS TREE\n");
#else
	printf("  note <limits.h> did NOT come from this tree\n");
#endif
	printf("  note _POSIX_PATH_MAX %d, _POSIX_NAME_MAX %d"
		" (the standard's MINIMA)\n",
		(int)_POSIX_PATH_MAX, (int)_POSIX_NAME_MAX);

	printf("--- 1. how deep can a tree be made ---\n");
	strcpy(path, ROOT);
	if(mkdir(path, 0777) < 0 && errno != EEXIST){
		why("mkdir " ROOT);
		return 1;
	}
	depth = 1;
	for(i = 0; i < WANT; i++){
		len = strlen(path);
		strcpy(path+len, "/" COMP);
		if(mkdir(path, 0777) < 0){
			why("mkdir at that depth");
			path[len] = 0;		/* it does not exist */
			break;
		}
		depth++;
	}
	best = depth;
	printf("  note deepest tree made: %d levels, %d characters\n",
		best, (int)strlen(path));
	ok("a path longer than _POSIX_PATH_MAX can be created",
		strlen(path) > (size_t)_POSIX_PATH_MAX);

	printf("--- 2. can the deepest directory be reached ---\n");
	if(stat(path, &st) < 0)
		why("stat the deepest directory");
	else
		ok("stat of the deepest directory", 1);

	if((d = opendir(path)) == NULL)
		why("opendir the deepest directory");
	else {
		closedir(d);
		ok("opendir of the deepest directory", 1);
	}

	/*
	 * realpath is the one Tcl's normalizer uses, and musl's puts two
	 * PATH_MAX arrays on the stack -- so it refuses anything longer,
	 * whatever the file system can do.
	 */
	errno = 0;
	rp = realpath(path, resolved);
	if(rp == NULL)
		why("realpath of the deepest directory");
	else
		ok("realpath of the deepest directory", 1);

	printf("--- 3. can it be removed again ---\n");
	for(i = best; i > 0; i--){
		if(rmdir(path) < 0){
			why("rmdir at that depth");
			printf("  note failed with %d levels left,"
				" %d characters\n", i, (int)strlen(path));
			break;
		}
		if((slash = strrchr(path, '/')) == NULL)
			break;
		*slash = 0;
	}
	ok("the whole tree could be removed", i == 0 || strcmp(path, ROOT) == 0);

	/* leave nothing behind even if the walk above stopped early */
	while((slash = strrchr(path, '/')) != NULL){
		rmdir(path);
		*slash = 0;
	}
	rmdir(ROOT);

	printf("%d failure(s)\n", failures);
	return failures;
}
