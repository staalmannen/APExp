#include "stdio_impl.h"
#include <fcntl.h>
#include <unistd.h>

/*
 * freopen reopens *the stream it is given*. C99 7.19.5.4p2: it "first
 * attempts to close any file that is associated with the specified
 * stream", then opens the new file and associates it with that same
 * stream, returning the stream itself.
 *
 * This used to fclose(f), open the file, and return a *new* FILE from
 * __fdopen:
 *
 *	if (f && f->fd >= 0) fclose(f);
 *	fd = open(name, flags, 0666);
 *	return __fdopen(fd, mode);
 *
 * which is not freopen at all. The caller's stream is the whole point:
 * every use of freopen is "make stdout (or stdin) be this file from now
 * on", and the return value is checked against NULL and otherwise
 * discarded.
 *
 * On a permanent stream it did nothing whatever. fclose() on a stream
 * with F_PERM -- stdin, stdout, stderr -- flushes and returns without
 * closing the descriptor, by design. So fd 1 stayed on the terminal,
 * open() got a fresh descriptor for the new file, __fdopen wrapped that
 * in a FILE nobody kept, and stdout still pointed at the terminal.
 *
 * flex is where it showed. main.c:333 does
 *
 *	prev_stdout = freopen (outfilename, "w+", stdout);
 *
 * and then writes the scanner to stdout, so the whole of lex.yy.c went
 * to the terminal and the file itself -- created by that open() and
 * never written to again -- was left at zero bytes.
 *
 * Now it is musl's: open the new file as a separate stream, dup2 its
 * descriptor onto the one the caller's stream already uses so that
 * fileno(f) does not change, adopt its flags and hooks, and close the
 * temporary. F_PERM is preserved, so stdout stays permanent.
 *
 * fileno(f) not changing is not a detail. flex's filter chain does
 * dup2(pipe, fileno(stdout)) afterwards, and forks children that
 * inherit descriptor 1 expecting it to be the output file.
 */
FILE *freopen(const char *name, const char *mode, FILE *f){
	int fl;
	FILE *f2;

	if(!f)
		return NULL;

	fflush(f);

	/*
	 * A null name means "change the mode of the stream that is
	 * already open" (POSIX). Only the access-mode bits can change;
	 * creation and truncation are meaningless here.
	 */
	if(!name){
		fl = __fmodeflags(mode) & ~(O_CREAT|O_EXCL|O_TRUNC|O_CLOEXEC);
		if(f->fd < 0 || fcntl(f->fd, F_SETFL, fl) < 0)
			goto fail;
		return f;
	}

	f2 = fopen(name, mode);
	if(!f2)
		goto fail;

	if(f2->fd == f->fd){
		f2->fd = -1;		/* so fclose(f2) leaves it open */
	}else if(f->fd < 0 || dup2(f2->fd, f->fd) < 0){
		fclose(f2);
		goto fail;
	}

	/*
	 * Take on the new file's nature, keeping this stream's identity:
	 * F_PERM says whether the FILE itself may be freed, and belongs
	 * to f, not to the file it happens to be open on. Copying the
	 * rest of the flags also clears any error and end-of-file left
	 * over from the old file, which 7.19.5.4 requires.
	 */
	f->flags = (f->flags & F_PERM) | f2->flags;
	f->read = f2->read;
	f->write = f2->write;
	f->seek = f2->seek;
	f->close = f2->close;

	/* Nothing buffered for the old file carries over. */
	f->rpos = f->rend = 0;
	f->wpos = f->wbase = f->wend = 0;

	fclose(f2);
	return f;

fail:
	fclose(f);
	return NULL;
}
