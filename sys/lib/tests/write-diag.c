#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

/*
 * Diagnostic test for the no-output bug.
 * Compile: pcc write-diag.c
 *
 * Tests three write paths separately:
 *   1. Plan9 _PWRITE() — bypasses all APE layers
 *   2. APE write(2)    — goes through pwrite()/FD_ISOPEN check
 *   3. printf+fflush   — goes through musl stdio
 */

/* Plan9 raw write syscall (bypasses APE pwrite wrapper entirely) */
extern long _PWRITE(int, void *, long, long long);

/* APE fd-info flags (FD_ISOPEN = 0x2) */
typedef struct { unsigned long flags; unsigned long oflags; } Fdinfo_min;
extern Fdinfo_min _fdinfo[];

static void
rawwrite(int fd, const char *s)
{
	_PWRITE(fd, (void *)s, strlen(s), -1LL);
}

static void
rawdec(int fd, unsigned long n)
{
	char buf[20];
	int i = sizeof buf;
	if(n == 0){ _PWRITE(fd, "0", 1, -1LL); return; }
	while(n > 0){ buf[--i] = '0' + (int)(n % 10); n /= 10; }
	_PWRITE(fd, buf+i, (long)(sizeof buf - i), -1LL);
}

int
main(void)
{
	int r;

	/* Step 1: raw Plan9 syscall — no APE wrapper at all */
	rawwrite(1, "1. _PWRITE direct: OK\n");

	/* Step 2: show _fdinfo state for fd 1 */
	rawwrite(1, "2. _fdinfo[1].flags=0x");
	rawdec(1, _fdinfo[1].flags);
	rawwrite(1, " (FD_ISOPEN=");
	rawdec(1, (_fdinfo[1].flags & 0x2) != 0);
	rawwrite(1, ")\n");

	/* Step 3: APE write(2) */
	r = write(1, "3. write(1): OK\n", 16);
	if(r < 0){
		rawwrite(1, "3. write(1) FAILED errno=");
		rawdec(1, (unsigned long)errno);
		rawwrite(1, "\n");
	}

	/* Step 4: printf + fflush */
	printf("4. printf: OK\n");
	fflush(stdout);

	return 0;
}
