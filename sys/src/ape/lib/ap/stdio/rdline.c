/*
 * pANS stdio -- rdline
 * This is not a pANS routine.
 * Adapted for musl stdio
 */
#include "stdio_impl.h"
#include <string.h>

char *rdline(FILE *f, char **ep){
	int cnt;
	char *nlp, *vp;

	/* Ensure we're in read mode */
	if (__toread(f)) {
		return NULL;
	}

	/* Initialize buffer if needed */
	if (!f->buf || f->buf_size == 0) {
		if (setvbuf(f, NULL, _IOFBF, BUFSIZ) != 0) {
			return NULL;
		}
	}

	vp = f->rpos;
	for(;;){
		/*
		 * Look for a newline.
		 * If none found, slide the partial line to the beginning
		 * of the buffer, read some more and keep looking.
		 */
		nlp = memchr(f->rpos, '\n', f->rend - f->rpos);
		if(nlp != 0) break;

		if(f->rpos != f->buf){
			memmove(f->buf, f->rpos, f->rend - f->rpos);
			f->rend -= f->rpos - f->buf;
			f->rpos = f->buf;
			vp = f->rpos;
		}

		cnt = f->buf_size - (f->rend - f->buf);
		if(cnt == 0){	/* no room left */
			nlp = f->rend - 1;
			break;
		}

		cnt = read(f->fd, f->rend, cnt);
		if(cnt == -1){
			f->flags |= F_ERR;
			return NULL;
		}
		if(cnt == 0){
			f->flags |= F_EOF;
			return NULL;
		}

		f->rpos = f->rend;
		f->rend += cnt;
	}

	*nlp = '\0';
	f->rpos = nlp + 1;
	if(ep) *ep = nlp;
	return vp;
}

