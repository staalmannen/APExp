/*
 * isatty must follow the descriptor, including across dup2 and exec.
 *
 * APE caches the answer in _fdinfo[fd].flags as FD_ISTTY, and the flag
 * is inherited across an exec through the $_fdinfo environment
 * variable. sfdinit() in plan9/_fdinfo.c restored that inherited value
 * and then only ever OR'd FD_ISTTY back in from the real descriptor --
 * it never cleared it. So a descriptor that was the console in the
 * parent and a pipe in the child kept FD_ISTTY, and isatty() lied.
 *
 * Tcl decides whether it is interactive with isatty(0)
 * (tclMain.c:365). Tk's test suite drives a child wish over a pipe, so
 * the child believed it had a terminal and wrote its "% " prompt into
 * the pipe, where the parent was reading results:
 *
 *	Error in startup script: unexpected output from background
 *	process: "% foo"
 *
 * Nothing about that names isatty, or stdio, or even Tk.
 *
 * The three cases below are the three places the answer can go wrong,
 * and they fail independently: a plain pipe, a pipe moved onto
 * descriptor 0 by dup2, and the same across an exec -- which is the one
 * that was broken, and the only one $_fdinfo is involved in.
 *
 * Correct on gcc, which is where the expected values come from.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define RESULT	"/tmp/isatty-test.out"

static int failures;

static void
check(const char *what, int got, int want)
{
	if(got == want){
		printf("PASS %s: isatty = %d\n", what, got);
	}else{
		printf("FAIL %s: isatty = %d, want %d\n", what, got, want);
		failures++;
	}
}

/*
 * The child half: re-executed with one argument, it reports isatty(0)
 * for whatever descriptor 0 it was given. Writing to a file rather than
 * stdout because stdout is where the harness prints, and because the
 * point of the exercise is that descriptor 0 is a pipe.
 */
static int
child_main(void)
{
	FILE *f;

	f = fopen(RESULT, "w");
	if(f == NULL)
		return 2;
	fprintf(f, "%d\n", isatty(0));
	fclose(f);
	return 0;
}

int
main(int argc, char **argv)
{
	int p[2], pid, status, fd0, r;
	FILE *f;

	if(argc > 1 && strcmp(argv[1], "--child") == 0)
		return child_main();

	/* 1. A pipe is not a terminal. */
	if(pipe(p) < 0){
		printf("FAIL pipe failed\n");
		return 1;
	}
	check("pipe read end", isatty(p[0]), 0);
	check("pipe write end", isatty(p[1]), 0);

	/*
	 * 2. Still not a terminal after being moved onto descriptor 0.
	 * Save the real descriptor 0 first so the rest of the test, and
	 * anything after it, still has one.
	 */
	fd0 = dup(0);
	if(fd0 < 0){
		printf("FAIL dup(0) failed\n");
		return 1;
	}
	if(dup2(p[0], 0) < 0){
		printf("FAIL dup2 onto 0 failed\n");
		return 1;
	}
	check("pipe dup2'd onto stdin", isatty(0), 0);

	/*
	 * 3. And still not a terminal on the far side of an exec. This
	 * is the case $_fdinfo carries the stale flag through.
	 */
	fflush(stdout);
	if((pid = fork()) < 0){
		printf("FAIL fork failed\n");
		return 1;
	}
	if(pid == 0){
		execl(argv[0], argv[0], "--child", (char *)NULL);
		_exit(3);
	}
	if(waitpid(pid, &status, 0) < 0 || status != 0){
		printf("FAIL exec'd child: status %#x\n", status);
		failures++;
	}else{
		f = fopen(RESULT, "r");
		if(f == NULL || fscanf(f, "%d", &r) != 1){
			printf("FAIL exec'd child wrote no result\n");
			failures++;
			if(f != NULL)
				fclose(f);
		}else{
			fclose(f);
			check("pipe on stdin across exec", r, 0);
		}
	}

	/* Put descriptor 0 back. */
	dup2(fd0, 0);
	close(fd0);
	close(p[0]);
	close(p[1]);
	remove(RESULT);

	printf("%d failure(s)\n", failures);
	return failures;
}
