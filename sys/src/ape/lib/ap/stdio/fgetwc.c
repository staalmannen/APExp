/*
 * pANS stdio -- fgetwc, getwc, getwchar
 *
 * Pull bytes one at a time and offer them to mbrtowc until it either
 * completes a character or rejects the sequence. This is the same shape
 * as fgetrune() in multibyte/, and it works whatever MB_CUR_MAX is
 * because mbrtowc reports an incomplete prefix as (size_t)-2.
 *
 * No _FLOCK here: fgetc does its own locking and __lockfile is a plain
 * pthread mutex, so locking at this level would deadlock.
 *
 * C99 7.24.3.1: on an encoding error set the stream's error indicator
 * and errno to EILSEQ. The bytes already consumed are not pushed back --
 * the standard leaves the file position unspecified in that case, and
 * ungetc only guarantees room for UNGET bytes.
 */
#include "stdio_impl.h"
#include <wchar.h>
#include <limits.h>
#include <errno.h>
#include <string.h>

wint_t fgetwc(FILE *f)
{
	mbstate_t st;
	char b[MB_LEN_MAX];
	wchar_t wc;
	size_t r;
	int c, i;

	for (i = 0; i < MB_LEN_MAX; ) {
		if ((c = fgetc(f)) == EOF) {
			if (i) {		/* truncated sequence at EOF */
				f->flags |= F_ERR;
				errno = EILSEQ;
			}
			return WEOF;
		}
		b[i++] = (char)c;
		/*
		 * Re-parse the whole prefix from a cleared state each time.
		 * Carrying the state across calls while also re-passing the
		 * earlier bytes would count them twice: a -2 return means
		 * mbrtowc has already absorbed what it was given.
		 */
		memset(&st, 0, sizeof st);
		r = mbrtowc(&wc, b, (size_t)i, &st);
		if (r == (size_t)-2)	/* incomplete, needs another byte */
			continue;
		if (r == (size_t)-1)	/* invalid sequence */
			break;
		return (wint_t)wc;	/* r == 0 means L'\0', a real character */
	}
	f->flags |= F_ERR;
	errno = EILSEQ;
	return WEOF;
}

wint_t getwc(FILE *f)
{
	return fgetwc(f);
}

wint_t getwchar(void)
{
	return fgetwc(stdin);
}
