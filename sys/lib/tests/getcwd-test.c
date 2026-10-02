/*
 * getcwd-test -- does getcwd() ALLOCATE when asked to?
 *
 *	pcc -o getcwd-test getcwd-test.c && ./getcwd-test
 *
 * On the host, where there is no libap to mark:
 *
 *	gcc -Wall -o /tmp/getcwd-test getcwd-test.c \
 *	    -xc <(echo 'int _getcwdmark(void){return 1;}')
 *	/tmp/getcwd-test
 *
 * (0 failures on glibc.)
 *
 * ------------------------------------------------------------------
 * THE BUG IT CAME FROM: bash would not start, and the message was
 * about an address rather than about a directory.
 *
 *	bash 7263782: suicide: invalid address 0x0/4096 in sys call
 *
 * `acid' on it:
 *
 *	_FD2PATH(a0=0x5)                  syscall/_FD2PATH.s:6
 *	getcwd(buf=0x0, len=0x1000)       ap/unistd/getcwd.c:21
 *	get_working_directory(...)        bash/builtins/common.c:603
 *	set_pwd() / initialize_shell_variables() / shell_initialize()
 *
 * **`buf=0x0' is the whole bug.** libap's getcwd passed its argument
 * straight to `_FD2PATH' with no null check, so `getcwd(NULL, n)' --
 * the glibc/musl/POSIX.1-2008 "allocate it for me" form, which a great
 * deal of GNU code uses -- handed the kernel address zero.
 *
 * ------------------------------------------------------------------
 * WHY IT HID FOR SO LONG, which is worth more than the fix.
 *
 * **bash had already detected it and shipped a replacement, and the
 * link order discarded that.** bash's `config.h' says
 * `#define GETCWD_BROKEN 1'; `config-bot.h:66' therefore does
 * `#undef HAVE_GETCWD'; so `lib/sh/getcwd.c' compiles a getcwd that
 * DOES allocate, and `getcwd.$O' is in the mkfile's OBJSH. But that
 * object lands inside `libsh.a', and the mkfile links on purpose:
 *
 *	#link libap first to already occupy symbols supported by libap
 *	LIB= .../libap.a $BASHLIBS ...
 *
 * so `getcwd' resolved out of libap and bash's own copy was never
 * pulled. *A program's workaround for a library bug is only as good as
 * the link order.* It is the gnulib `strerror' finding pointing the
 * other way: there libap's correct version lost to gnulib's broken
 * one, here bash's correct version lost to libap's broken one.
 *
 * **And libap held the right idiom NEXT DOOR the whole time.**
 * `misc/get_current_dir.c' implements `get_current_dir_name()` with
 * the comment "like getcwd(NULL, 0) on Linux -- allocates", by
 * malloc'ing PATH_MAX and calling getcwd into it. Same shape as
 * `mktemp' ignoring `__randname' in its own directory: *the library
 * contained a working version of the thing it could not do.*
 *
 * ------------------------------------------------------------------
 * SECTION 3 IS THE ONE THAT CARRIES THE RESULT, and before the fix it
 * did not FAIL, it KILLED THE PROCESS. So a run that reaches section 4
 * at all has already proved the main point; the count is about the
 * corners. Section 5 is the control that separates "handles NULL" from
 * "ignores its arguments" -- a getcwd that allocated unconditionally
 * would pass 2, 3 and 4 and get 5 wrong.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <limits.h>
#include <unistd.h>

extern int _getcwdmark(void);

static int failures;

static void
ok(int cond, const char *what)
{
	printf("%s: %s\n", cond ? "PASS" : "FAIL", what);
	if(!cond)
		failures++;
}

int
main(void)
{
	char buf[PATH_MAX];
	char *a, *b, *c;

	printf("getcwd-test\n");
	printf("_getcwdmark = %d  (libap with the NULL-buffer fix)\n\n",
		_getcwdmark());

	/* 1. the classic form, which always worked */
	printf("1. getcwd(buf, sizeof buf)\n");
	a = getcwd(buf, sizeof buf);
	ok(a == buf, "returns the caller's buffer");
	ok(a != 0 && a[0] == '/', "answer is an absolute path");
	printf("   cwd = %s\n\n", a ? a : "(null)");
	if(a == 0){
		printf("cannot continue without a cwd\n");
		return 1;
	}

	/*
	 * 2. getcwd(NULL, PATH_MAX) -- EXACTLY what bash does at
	 *    builtins/common.c:603. This is the call that killed the
	 *    process outright.
	 */
	printf("2. getcwd(NULL, PATH_MAX)   <- bash's call; used to KILL\n");
	b = getcwd(0, PATH_MAX);
	ok(b != 0, "returns non-NULL");
	if(b != 0){
		ok(b != buf, "returns a buffer of its own");
		ok(strcmp(b, buf) == 0, "same answer as section 1");
		free(b);			/* must be a real malloc'd pointer */
		printf("   free() accepted it\n");
	}
	printf("\n");

	/* 3. the "you choose the size" form */
	printf("3. getcwd(NULL, 0)\n");
	c = getcwd(0, 0);
	ok(c != 0, "returns non-NULL");
	if(c != 0){
		ok(strcmp(c, buf) == 0, "same answer as section 1");
		free(c);
	}
	printf("\n");

	/*
	 * 4. THE CONTROL. POSIX: a non-null buffer with size 0 is
	 *    EINVAL. An implementation that just allocated whatever it
	 *    was asked would pass everything above and get this wrong,
	 *    so this is what separates "handles NULL" from "ignores its
	 *    arguments".
	 */
	printf("4. getcwd(buf, 0)  -- must be EINVAL, not a cwd\n");
	errno = 0;
	a = getcwd(buf, 0);
	ok(a == 0, "returns NULL");
	ok(errno == EINVAL, "errno is EINVAL");
	printf("   errno = %d (%s)\n\n", errno, strerror(errno));

	printf("%d failures\n", failures);
	return failures;
}
