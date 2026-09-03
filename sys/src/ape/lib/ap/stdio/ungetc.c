#include "stdio_impl.h"

/*
 * musl's ungetc, restored.
 *
 * This used to refuse a stream that had not been read from yet:
 *
 *	if(!f->buf || !f->rpos || f->rpos <= f->buf - UNGET)
 *		return EOF;
 *
 * with a comment saying __toread must not be called because it resets
 * rpos/rend and would destroy buffered data.  It only resets them when
 * there are none: musl guards the call with !f->rpos, which is true
 * exactly when no read window exists, and that is the case this test
 * was rejecting.  C99 7.19.7.11 guarantees one character of pushback on
 * any input stream, read from or not.
 *
 * flex is what found it.  Its filter chain re-points the stdin FILE at
 * a new descriptor, which C gives no way to do, so filter_apply_chain
 * dup2s onto fileno(stdin) and then resynchronises the stream with
 *
 *	fseek (stdin, 0, SEEK_CUR);
 *	ungetc (' ', stdin);
 *	(void) fgetc (stdin);
 *
 * -- push a character and take it straight back, which touches the
 * descriptor not at all.  flex's own comment calls it "a Hail Mary
 * situation".  With ungetc failing, the fgetc became a *real read* on a
 * pipe nothing had written to yet: each filter blocked there, and the
 * one that goes on to execvp("m4") swallowed a bufferful into a FILE
 * the exec was about to throw away.
 *
 * The chain is
 *
 *	flex -> filter_tee_header -> m4 -P -> filter_fix_linedirs -> lex.yy.c
 *
 * and it produced an empty lex.yy.c, or killed flex with "sys: write on
 * closed pipe" -- with nothing at all to say that ungetc was involved.
 * Covered by sys/lib/tests/unget-pipe-test.c.
 */
int ungetc(int c, FILE *f){
	if(c == EOF) return c;

	_FLOCK(f);

	/*
	 * Establish a read window if there is none. __toread leaves
	 * rpos == rend == f->buf + f->buf_size, so the UNGET area in
	 * front of f->buf is available and nothing has been read.
	 */
	if(!f->rpos) __toread(f);

	if(!f->rpos || f->rpos <= (unsigned char *)f->buf - UNGET){
		_FUNLOCK(f);
		return EOF;
	}

	*--f->rpos = (unsigned char)c;
	f->flags &= ~F_EOF;

	_FUNLOCK(f);
	return (unsigned char)c;
}
