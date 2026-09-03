#include "stdio_impl.h"
#include <errno.h>

/*
 * fseeko, and by way of fseek.c every seek in the library.
 *
 * Three things were wrong here, and the first is the one that mattered:
 *
 * 1. A failed seek set the error indicator.
 *
 *    C99 7.19.9.2p5: fseek "returns nonzero only for a request that
 *    cannot be satisfied". It says nothing about ferror, and neither
 *    glibc nor musl touches it -- a stream you cannot seek is not a
 *    stream that has failed.
 *
 *    A pipe is not seekable, so this poisoned every stream that was
 *    ever asked its position. flex is what found it: its filter chain
 *    re-points the stdin FILE at a pipe and resynchronises the stream
 *    with (filter.c:164)
 *
 *	fseek (stdin, 0, SEEK_CUR);
 *	ungetc (' ', stdin);
 *	(void) fgetc (stdin);
 *
 *    The fseek fails, as it must on a pipe, and flex ignores the
 *    result -- correctly. But the stream was left in error, and this
 *    stdio's fgets tests it explicitly:
 *
 *	if(c==EOF && s==as || ferror(f)) return NULL;
 *
 *    so the first fgets in every filter returned NULL without reading
 *    a byte. Each filter exited immediately, m4 saw end of file on its
 *    input, and flex died writing into a pipe with no reader. The whole
 *    chain is
 *
 *	flex -> filter_tee_header -> m4 -P -> filter_fix_linedirs -> lex.yy.c
 *
 *    and it produced a lex.yy.c of zero bytes -- which looks like
 *    success, because freopen creates that file before any filter runs.
 *
 * 2. A relative seek ignored data already in the read buffer.
 *
 *    C99 7.19.9.2p2: SEEK_CUR is relative to the current position,
 *    which is where the *caller* has read to, not where the buffer was
 *    filled to. fseek(f, 0, SEEK_CUR) is meant to be a no-op; without
 *    the adjustment it silently moved the file position forward by
 *    whatever was still buffered. ftell.c already accounted for it, so
 *    the two disagreed.
 *
 * 3. It went straight to lseek(f->fd) and refused f->fd < 0, so a
 *    stream from fmemopen or open_memstream -- which has no descriptor
 *    and does its seeking through f->seek -- could never be sought at
 *    all. POSIX requires those to be seekable.
 *
 * Covered by sys/lib/tests/unget-pipe-test.c.
 */
int fseeko(FILE *f, off_t offs, int type){
	_FLOCK(f);

	/* Adjust a relative seek for unread data in the buffer. */
	if(type == SEEK_CUR && f->rend)
		offs -= f->rend - f->rpos;

	/* Flush the write buffer, and report an error if that fails. */
	if(f->wpos != f->wbase){
		f->write(f, 0, 0);
		if(f->flags & F_ERR){
			_FUNLOCK(f);
			return -1;
		}
	}

	/* Leave writing mode. */
	f->wpos = f->wbase = f->wend = 0;

	if(!f->seek || f->seek(f, offs, type) < 0){
		_FUNLOCK(f);
		return -1;	/* not an error indicator -- see above */
	}

	/*
	 * The seek succeeded, so the stream is seekable and the read
	 * buffer is stale. C99 7.19.9.2p5 also makes this undo any
	 * ungetc pushback and clear end-of-file; the error indicator is
	 * left alone, as glibc and musl leave it.
	 */
	f->rpos = f->rend = 0;
	f->flags &= ~F_EOF;

	_FUNLOCK(f);
	return 0;
}
