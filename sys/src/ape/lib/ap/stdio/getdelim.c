#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>

/*
 * getdelim / getline for APExp
 *
 * Written against APE's FILE interface (getc/feof/ferror) rather than
 * ported from musl, because musl's implementation directly accesses
 * FILE struct internals (rpos, rend, mode, wbase) that do not exist
 * in APE's FILE struct.
 *
 * Behaviour is identical to POSIX getdelim/getline.
 */

ssize_t getdelim(char **restrict s, size_t *restrict n, int delim, FILE *restrict f)
{
	size_t i = 0;
	int c;

	if (!s || !n) {
		errno = EINVAL;
		return -1;
	}

	/* allocate an initial buffer if the caller has none */
	if (!*s || !*n) {
		*n = 128;
		*s = malloc(*n);
		if (!*s) {
			errno = ENOMEM;
			return -1;
		}
	}

	for (;;) {
		c = getc(f);
		if (c == EOF) {
			if (feof(f) && i > 0)
				break;
			return -1;
		}

		/* grow the buffer if needed: need room for char + NUL */
		if (i + 2 > *n) {
			size_t m = *n * 2;
			char *tmp = realloc(*s, m);
			if (!tmp) {
				/* undo the getc so the stream is consistent */
				ungetc(c, f);
				errno = ENOMEM;
				return -1;
			}
			*s = tmp;
			*n = m;
		}

		(*s)[i++] = (char)c;
		if (c == delim)
			break;
	}

	(*s)[i] = '\0';
	return (ssize_t)i;
}

ssize_t getline(char **restrict s, size_t *restrict n, FILE *restrict f)
{
	return getdelim(s, n, '\n', f);
}
