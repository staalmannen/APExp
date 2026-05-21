#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

/*
 * Diagnostic: test direct write(2) and printf separately.
 * Output on stdout shows which path works.
 */
int
main(void)
{
	const char msg1[] = "write(1) direct: OK\n";
	const char msg2[] = "printf: OK\n";
	int r;

	r = write(1, msg1, sizeof msg1 - 1);
	if(r < 0) {
		const char err[] = "write(1) FAILED: errno=";
		char ebuf[32];
		int e = errno;
		write(2, err, sizeof err - 1);
		/* write errno as decimal without printf */
		if(e == 0) write(2, "0", 1);
		else {
			char tmp[12];
			int i = sizeof tmp;
			tmp[--i] = '\n';
			while(e > 0) { tmp[--i] = '0' + (e % 10); e /= 10; }
			write(2, tmp + i, sizeof tmp - i);
		}
	}

	printf("%s", msg2);
	fflush(stdout);

	return 0;
}
