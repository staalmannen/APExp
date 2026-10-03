#include "lib.h"
#include <stdlib.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>
#include <errno.h>
/* <sys/limits.h> for PATH_MAX, as unistd/getcwd.c takes it: the two
   limits headers redefine each other and only this order is proven */
#include <sys/limits.h>
#include <string.h>
#include "sys9.h"
#include "dir.h"

#define DBLOCKSIZE 20

/*
 * st_mode to the d_type value readdir() reports. POSIX gives these as
 * DT_* constants, which are small integers unrelated to the S_IF* bits,
 * so the two have to be mapped rather than aliased.
 *
 * There is no DT_SOCK arm. S_IFSOCK has its own value in APE's
 * <sys/stat.h> now, but Plan 9 has no Unix-domain sockets in the file
 * system, so nothing here ever has that mode and the arm would be dead.
 * A FIFO, which mkfifo() can create, does reach DT_FIFO.
 */
static unsigned char
_dtype(mode_t m)
{
	if(S_ISREG(m))
		return DT_REG;
	if(S_ISDIR(m))
		return DT_DIR;
	if(S_ISCHR(m))
		return DT_CHR;
	if(S_ISBLK(m))
		return DT_BLK;
	if(S_ISLNK(m))
		return DT_LNK;
	if(S_ISFIFO(m))
		return DT_FIFO;
	return DT_UNKNOWN;
}

/*
 * PLAN 9 DIRECTORIES CONTAIN NEITHER `.' NOR `..', AND EVERY OTHER
 * SYSTEM'S DO. readdir() synthesises them as entries 0 and 1.
 *
 * Measured in two independent suites before being touched: Tcl's
 * `filename-14.9' wants `glob globTest/.*' to yield them, and bash's
 * `run-extglob' wants `. .. .a .foo' where this tree answered
 * `.a .foo'. *One measurement made it a curiosity; the second made it
 * worth a round.*
 *
 * THE SWEEP THAT HAD TO COME FIRST. This changes what every directory
 * read in every program sees, so the question is not whether POSIX
 * wants the entries -- it does -- but whether anything here walks a
 * directory without skipping them, because such a caller recurses for
 * ever. All six readdir() callers in libap were read:
 *
 *	unistd/rmdir.c  skips both by strcmp        -- safe
 *	misc/fts.c      ISDOT(), unless FTS_SEEDOT  -- safe
 *	misc/nftw.c     open-coded ISDOT            -- safe
 *	regex/glob.c    FNM_PERIOD, see below       -- safe, and WANTS them
 *	dirent/scandir.c  does not skip             -- correct: scandir
 *	                                               reports everything
 *	                                               and the caller's
 *	                                               filter decides
 *	dirent/seekdir.c  replays readdir()         -- stays consistent
 *
 * **Two of them were written expecting these entries to exist**, which
 * is the strongest evidence available that their absence is the
 * anomaly rather than this change: `rmdir.c' spends a strcmp per entry
 * skipping names Plan 9 never produced, and musl's `glob' does not
 * skip them at all -- it relies on `fnmatch' with FNM_PERIOD, so an
 * ordinary `*' excludes them while an explicit `.*' matches them. That
 * is exactly what the two failing tests ask for, so **glob needs no
 * change and starts answering correctly on its own.**
 *
 * WHY THE STATS ARE REAL. `d_ino' is what `find' uses for loop
 * detection, what the classic getcwd walks `..' comparing, and what
 * `du' uses for hard links. Reporting 0 would be the trap already
 * recorded for zipfs's `st_rdev' -- *a field that is always zero reads
 * as information and is not*. So `.' is fstat'ed from the stream's own
 * descriptor and `..' is stat'ed through `fd2path' + "/..", at a cost
 * of two stats per directory TRAVERSAL rather than per entry.
 *
 * At the root `/..' is `/' on Plan 9 as on a unix, so the parent entry
 * is self-referential there and no special case is needed. If the
 * parent cannot be stat'ed at all the directory's own identity is used
 * rather than a zero, which is the same choice for the same reason.
 *
 * NO NEW FIELD, AND THAT IS NOT A TRICK. `dd_seek' is already the
 * stream's entry counter, maintained here and zeroed by rewinddir();
 * the synthetic entries genuinely ARE entries 0 and 1, so the counter
 * that describes them is the same fact rather than a second one. It
 * also makes `telldir'/`seekdir' right for nothing: seekdir rewinds
 * and replays readdir(), so it replays these too. *`sizeof(DIR)' is
 * unchanged, so this is not an ABI change* -- but a libap fix still
 * has to reach existing binaries, so a full rebuild is needed anyway,
 * for the other reason.
 */
static struct dirent *
_dotent(DIR *d)
{
	struct dirent *dr;
	char buf[PATH_MAX];
	int n;

	dr = (struct dirent *)d->dd_buf;
	memset(dr, 0, sizeof *dr);

	if(d->dd_seek == 0)
		strcpy(dr->d_name, ".");
	else
		strcpy(dr->d_name, "..");

	/*
	 * The stream's own descriptor identifies `.' exactly, and is the
	 * fallback for `..' when the parent cannot be reached.
	 */
	if(fstat(d->dd_fd, &dr->d_stat) < 0){
		/*
		 * Report the entry rather than the stream: a directory
		 * being read plainly exists, and failing here would end
		 * the traversal over a stat rather than over the data.
		 */
		memset(&dr->d_stat, 0, sizeof dr->d_stat);
		dr->d_stat.st_mode = S_IFDIR | 0555;
	}
	if(d->dd_seek == 1
	&& _FD2PATH(d->dd_fd, buf, (int)(sizeof buf - 4)) >= 0){
		n = strlen(buf);
		/* "/" would otherwise become "//.." */
		if(n > 0 && buf[n-1] == '/')
			n--;
		strcpy(buf+n, "/..");
		/* on failure `..' keeps the fstat above, i.e. itself */
		stat(buf, &dr->d_stat);
	}

	dr->d_ino = dr->d_stat.st_ino;
	dr->d_type = DT_DIR;
	d->dd_seek++;
	return dr;
}

struct dirent *
readdir(DIR *d)
{
	int i;
	struct dirent *dr;
	Dir *dirs, *dir;

	if(d == NULL){
		errno = EBADF;
		return NULL;
	}
	/*
	 * Before any real entry, and before the read that would fill
	 * dd_buf -- which is the buffer _dotent writes into, free to use
	 * here because dd_loc and dd_size are still 0 and the caller's
	 * previous entry is already invalidated by this call.
	 */
	if(d->dd_seek < 2)
		return _dotent(d);
	if(d->dd_loc >= d->dd_size){
		if(d->dirloc >= d->dirsize){
			free(d->dirs);
			d->dirs = NULL;
			d->dirsize = _dirread(d->dd_fd, &d->dirs);
			d->dirloc = 0;
		}
		if(d->dirsize < 0) {	/* malloc or read failed in _dirread? */
			free(d->dirs);
			d->dirs = NULL;
		}
		if(d->dirs == NULL)
			return NULL;

		dr = (struct dirent *)d->dd_buf;
		dirs = d->dirs;
		for(i=0; i<DBLOCKSIZE && d->dirloc < d->dirsize; i++){
			dir = &dirs[d->dirloc++];
			strncpy(dr[i].d_name, dir->name, MAXNAMLEN);
			dr[i].d_name[MAXNAMLEN] = 0;
			_dirtostat(&dr[i].d_stat, dir, NULL);
			dr[i].d_ino = dr[i].d_stat.st_ino;
			dr[i].d_type = _dtype(dr[i].d_stat.st_mode);
		}
		d->dd_loc = 0;
		d->dd_size = i*sizeof(struct dirent);
	}
	dr = (struct dirent*)(d->dd_buf+d->dd_loc);
	d->dd_loc += sizeof(struct dirent);
	d->dd_seek++;
	return dr;
}

/*
 * Version marker for `dotdir-test.c'. `pcc -o x x.c' relinks against
 * the INSTALLED libap, so a test built from a fresh pull can run
 * days-old library code and report a pass on it; a test that calls
 * this will not LINK against a libap predating the entries above.
 * Seventh use of the idiom, after _sock_listenmark, _execmark,
 * _ttymark, _getcwdmark, _printfmark and _dupmark.
 */
int
_dotdirmark(void)
{
	return 1;
}

