/*
 * ungetc must work on a stream that has not been read from yet, and
 * the stdin-repointing idiom built on it must not touch the fd.
 *
 * C99 7.19.7.11: "One character of pushback is guaranteed." It says
 * nothing about having read first, and glibc and musl both allow it --
 * musl's ungetc calls __toread() when f->rpos is null, which
 * establishes an empty read window so the UNGET area in front of the
 * buffer becomes usable.
 *
 * libap's ungetc used to return EOF in that case, on the reasoning that
 * __toread would discard buffered data. It only resets rpos/rend when
 * there are none.
 *
 * flex is what found it, and the failure was three steps removed.
 * flex's output goes through a chain of filter processes,
 *
 *	flex -> filter_tee_header -> m4 -P -> filter_fix_linedirs -> lex.yy.c
 *
 * and each child has to make the stdin FILE refer to a new descriptor,
 * which C gives no way to do. filter_apply_chain dup2s onto
 * fileno(stdin) and then resynchronises the stream (filter.c:164):
 *
 *	fseek (stdin, 0, SEEK_CUR);
 *	ungetc (' ', stdin);
 *	(void) fgetc (stdin);
 *
 * push a character and take it straight back. It reads nothing -- as
 * long as ungetc works. When it does not, the fgetc becomes a real read
 * on a pipe nothing has written to yet, so every filter blocked there,
 * and the one that goes on to execvp("m4") swallowed a bufferful into a
 * FILE the exec was about to discard.
 *
 * What it cost: flex produced an empty lex.yy.c, or died with
 *
 *	flex: sys: write on closed pipe
 *
 * neither of which mentions stdio. flex is the only thing in the tree
 * that runs a filter chain, so it had never worked here.
 *
 * Correct on gcc, which is where the expected values come from.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

#define NLINES	2000
#define RESULT	"/tmp/unget-pipe-test.out"

static int failures;

static void
check(const char *what, int ok, const char *detail)
{
	if(ok){
		printf("PASS %s\n", what);
	}else{
		printf("FAIL %s: %s\n", what, detail);
		failures++;
	}
}

/*
 * 1. ungetc before any read, on a regular file. The stream is freshly
 * opened, so f->rpos is null and this is exactly the rejected case.
 */
static void
unread_file(void)
{
	FILE *f;
	char detail[128];
	int r, c;

	f = fopen(RESULT, "w");
	if(!f){
		check("ungetc on unread file", 0, "cannot create temp file");
		return;
	}
	fputs("abc\n", f);
	fclose(f);

	f = fopen(RESULT, "r");
	if(!f){
		check("ungetc on unread file", 0, "cannot reopen temp file");
		return;
	}
	r = ungetc('X', f);
	if(r != 'X'){
		snprintf(detail, sizeof detail, "ungetc returned %d, want %d",
			r, 'X');
		check("ungetc on unread file", 0, detail);
		fclose(f);
		return;
	}
	c = getc(f);
	snprintf(detail, sizeof detail, "getc returned %d, want %d", c, 'X');
	check("ungetc on unread file", c == 'X', detail);

	/* and the file's own first character must still be there */
	c = getc(f);
	snprintf(detail, sizeof detail, "getc returned %d, want %d", c, 'a');
	check("file content intact after pushback", c == 'a', detail);
	fclose(f);
}

/*
 * 2. The same on a pipe, which is what flex actually does -- and where
 * a real read would block rather than merely losing data.
 */
static void
unread_pipe(void)
{
	int p[2];
	FILE *f;
	char detail[128];
	int r, c;

	if(pipe(p) < 0){
		check("ungetc on unread pipe", 0, "pipe failed");
		return;
	}
	f = fdopen(p[0], "r");
	if(!f){
		check("ungetc on unread pipe", 0, "fdopen failed");
		close(p[0]);
		close(p[1]);
		return;
	}

	/*
	 * Close the write end first. Nothing is ever written, so a
	 * correct ungetc still answers ' ' without touching the fd,
	 * while a broken one that falls through to a real read gets EOF
	 * and reports a failure -- rather than blocking forever, which
	 * is what it would do with the write end still open, and which
	 * is exactly how flex hung.
	 */
	close(p[1]);

	r = ungetc(' ', f);
	if(r != ' '){
		snprintf(detail, sizeof detail, "ungetc returned %d, want %d",
			r, ' ');
		check("ungetc on unread pipe", 0, detail);
		fclose(f);
		return;
	}
	c = getc(f);
	snprintf(detail, sizeof detail, "getc returned %d, want %d", c, ' ');
	check("ungetc on unread pipe", c == ' ', detail);

	fclose(f);
}

/*
 * 3. freopen reopens the stream it is given (C99 7.19.5.4p2), keeping
 * its identity and its descriptor number. flex does
 *
 *	freopen (outfilename, "w+", stdout);
 *
 * at main.c:333 and then writes the scanner to stdout, and its filter
 * chain later does dup2(pipe, fileno(stdout)) and forks children that
 * inherit descriptor 1 expecting it to be the output file. A freopen
 * that returns some other stream leaves stdout on the terminal.
 *
 * Done in a child so the test's own stdout is not disturbed. stdout is
 * a permanent stream (F_PERM), which is the case that was broken:
 * fclose() on such a stream flushes without closing the descriptor.
 */
static void
freopen_stdout(void)
{
	int pid, status, fd;
	FILE *res;
	char detail[128];
	char got[64];

	/*
	 * Flush before forking. When stdout is not a terminal it is
	 * fully buffered, and the child would inherit everything printed
	 * so far and write it out a second time.
	 */
	fflush(stdout);

	if((pid = fork()) < 0){
		check("freopen keeps the stream", 0, "fork failed");
		return;
	}
	if(pid == 0){
		if(freopen(RESULT, "w", stdout) == NULL)
			_exit(2);
		/* fileno must not change: flex's dup2 relies on it. */
		printf("fd=%d hello\n", fileno(stdout));
		fflush(stdout);
		_exit(0);
	}
	if(waitpid(pid, &status, 0) < 0 || status != 0){
		snprintf(detail, sizeof detail, "child status %#x", status);
		check("freopen keeps the stream", 0, detail);
		return;
	}

	res = fopen(RESULT, "r");
	if(!res || !fgets(got, sizeof got, res)){
		check("freopen keeps the stream", 0,
			"nothing was written to the file");
		if(res)
			fclose(res);
		return;
	}
	fclose(res);
	got[strcspn(got, "\n")] = '\0';

	if(sscanf(got, "fd=%d", &fd) != 1){
		snprintf(detail, sizeof detail, "file holds \"%s\"", got);
		check("freopen keeps the stream", 0, detail);
		return;
	}
	snprintf(detail, sizeof detail, "file holds \"%s\"", got);
	check("freopen writes reach the file", strstr(got, "hello") != NULL,
		detail);
	snprintf(detail, sizeof detail, "fileno(stdout) became %d, want 1", fd);
	check("freopen keeps the descriptor", fd == 1, detail);
}

/*
 * 4. fclose closes the file, even on a permanent stream.
 *
 * C99 7.19.5.1 has no exemption for stdin/stdout/stderr: fclose
 * "causes the stream to be flushed and the associated file to be
 * closed". F_PERM only means the FILE itself is static and must not be
 * freed.
 *
 * This is how a program at the head of a pipeline says it is done.
 * flex's cleanup is fclose(stdout) followed by wait() for its filter
 * children, so a descriptor left open means the first filter never sees
 * end of file and nothing downstream can exit.
 *
 * Tested by writing to the descriptor afterwards, which is exact and
 * needs no timing: if fclose closed it, the write fails. Done in a
 * child, since it closes stdout for good.
 */
static void
fclose_perm(void)
{
	int pid, status, fd, r;
	FILE *res;
	char detail[128];
	long wrote = 0;

	fflush(stdout);

	if((pid = fork()) < 0){
		check("fclose closes a permanent stream", 0, "fork failed");
		return;
	}
	if(pid == 0){
		fd = fileno(stdout);
		fclose(stdout);

		/* Must happen before anything reopens a low descriptor. */
		r = write(fd, "x", 1);

		res = fopen(RESULT, "w");
		if(!res)
			_exit(3);
		fprintf(res, "%d\n", r);
		fclose(res);
		_exit(0);
	}
	if(waitpid(pid, &status, 0) < 0 || status != 0){
		snprintf(detail, sizeof detail, "child status %#x", status);
		check("fclose closes a permanent stream", 0, detail);
		return;
	}

	res = fopen(RESULT, "r");
	if(!res || fscanf(res, "%ld", &wrote) != 1){
		check("fclose closes a permanent stream", 0,
			"child wrote no result");
		if(res)
			fclose(res);
		return;
	}
	fclose(res);

	snprintf(detail, sizeof detail,
		"write to the descriptor after fclose returned %ld,"
		" want -1", wrote);
	check("fclose closes a permanent stream", wrote == -1, detail);
}

/*
 * 5. flex's filter idiom end to end: the child re-points stdin at a
 * pipe and reads every line the parent writes. A lost or duplicated
 * character shows up as a wrong count or a wrong byte total.
 */
static void
filter_child(void)
{
	int p[2];
	int pid, status;
	FILE *out, *res;
	char detail[128];
	long lines, bytes, want = 0;
	char line[64];
	int i;

	if(pipe(p) < 0){
		check("flex filter idiom", 0, "pipe failed");
		return;
	}

	fflush(stdout);

	if((pid = fork()) < 0){
		check("flex filter idiom", 0, "fork failed");
		close(p[0]);
		close(p[1]);
		return;
	}

	if(pid == 0){
		char buf[512];
		long nl = 0, nb = 0;
		int sk, ug, gc;

		/*
		 * Everything here reports to stderr, which nothing in this
		 * test redirects. A child that exits quietly takes the
		 * parent with it -- the parent is left writing into a pipe
		 * with no reader -- and then there is nothing on screen to
		 * say which step went wrong.
		 */
		close(p[1]);
		clearerr(stdin);
		if(dup2(p[0], fileno(stdin)) == -1){
			fprintf(stderr, "  child: dup2 onto fileno(stdin) failed\n");
			_exit(2);
		}
		close(p[0]);

		/* filter.c:164-171, verbatim in shape */
		sk = fseek(stdin, 0, SEEK_CUR);
		ug = ungetc(' ', stdin);
		gc = fgetc(stdin);

		fprintf(stderr, "  child: fseek=%d ungetc=%d fgetc=%d\n",
			sk, ug, gc);
		if(ug != ' ')
			fprintf(stderr, "  child: ungetc failed;"
				" the fgetc above was a real read\n");

		while(fgets(buf, sizeof buf, stdin)){
			nl++;
			nb += strlen(buf);
		}

		res = fopen(RESULT, "w");
		if(!res){
			fprintf(stderr, "  child: cannot write %s\n", RESULT);
			_exit(3);
		}
		fprintf(res, "%ld %ld\n", nl, nb);
		fclose(res);
		_exit(0);
	}

	close(p[0]);
	out = fdopen(p[1], "w");
	if(!out){
		check("flex filter idiom", 0, "fdopen failed");
		close(p[1]);
		return;
	}
	for(i = 0; i < NLINES; i++){
		snprintf(line, sizeof line, "line %d padding padding padding\n", i);
		want += strlen(line);
		fputs(line, out);
	}
	if(ferror(out))
		printf("  parent: write failed --"
			" the child stopped reading early\n");
	fclose(out);

	if(waitpid(pid, &status, 0) < 0){
		check("flex filter idiom", 0, "waitpid failed");
		return;
	}
	if(status != 0){
		snprintf(detail, sizeof detail, "child exited with status %#x",
			status);
		check("flex filter idiom, child ran", 0, detail);
		return;
	}

	res = fopen(RESULT, "r");
	if(!res || fscanf(res, "%ld %ld", &lines, &bytes) != 2){
		check("flex filter idiom", 0, "child wrote no result");
		if(res)
			fclose(res);
		return;
	}
	fclose(res);

	snprintf(detail, sizeof detail, "child saw %ld lines, want %d",
		lines, NLINES);
	check("flex filter idiom, line count", lines == NLINES, detail);

	/*
	 * The byte total is the case that matters: a failed ungetc
	 * still leaves the line count right, because the fgetc that
	 * follows it eats one character out of the first line rather
	 * than a whole line.
	 */
	snprintf(detail, sizeof detail, "child saw %ld bytes, want %ld",
		bytes, want);
	check("flex filter idiom, byte count", bytes == want, detail);
}

int
main(void)
{
	/*
	 * The parent must survive a child that stops reading, so that it
	 * can say so. Without this it dies of SIGPIPE mid-loop and the
	 * test prints neither a failure nor a total.
	 */
	signal(SIGPIPE, SIG_IGN);

	unread_file();
	unread_pipe();
	freopen_stdout();
	fclose_perm();
	filter_child();
	remove(RESULT);

	printf("%d failure(s)\n", failures);
	return failures;
}
