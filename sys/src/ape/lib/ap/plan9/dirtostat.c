#include "lib.h"
#include <sys/stat.h>
#include <errno.h>
#include "sys9.h"
#include "dir.h"

/* fi is non-null if there is an fd associated with s */
void
_dirtostat(struct stat *s, Dir *d, Fdinfo *fi)
{
	int num;
	char *nam;

	s->st_dev = (d->type<<8)|(d->dev&0xFF);
	s->st_ino = d->qid.path;
	s->st_mode = d->mode&0777;
	s->st_blksize = 8192;       /* reasonable default for Plan9 */
	s->st_blocks = (d->length + 511) / 512;
	if(fi && (fi->flags&FD_ISTTY))
		s->st_mode |= S_IFCHR;
	else if(d->mode & 0x80000000)
		s->st_mode |= S_IFDIR;
	else if(d->type == '|' || d->type == 's')
		s->st_mode |= S_IFIFO;
	else if(d->type != 'M')
		s->st_mode |= S_IFCHR;
	else
		s->st_mode |= S_IFREG;
	s->st_nlink = 1;
	s->st_uid = 1;
	s->st_gid = 1;

	/*
	 * st_rdev IDENTIFIES A SPECIAL FILE, and POSIX leaves it
	 * unspecified for anything else -- so it is set here only for
	 * the character and block cases, and stays 0 for the rest.
	 *
	 * IT USED TO BE 0 ALWAYS, AND THAT MADE EVERY CHARACTER DEVICE
	 * LOOK LIKE EVERY OTHER ONE.  gnulib's `same_file' is
	 * dev+ino, and then a SECOND arm: two char specials, or two
	 * block specials, with equal st_rdev are "the same device, so
	 * the same contents" (`diffutils/src/system.c:30').  With
	 * st_rdev a constant that arm says yes to every pair.
	 *
	 * What it cost was SILENCE, which is the worst available
	 * failure.  `cmp a b' asks whether its own stdout is
	 * /dev/null, so that it can skip the work of describing a
	 * difference nobody will read (`cmp.c:336').  Under a terminal
	 * stdout is /dev/cons -- a char special -- /dev/null is a char
	 * special, both answered rdev 0, so cmp concluded it was
	 * writing to the bit bucket and compared the files in total
	 * silence.  **Two plainly different files, no output, and an
	 * exit status nobody reads.**  Plan 9's own `cmp' has no such
	 * optimisation, which is why it answered and APE's did not.
	 * `diff' has a second victim at `diff.c:1300': inside a
	 * recursive diff, two non-regular files with equal st_rdev
	 * are reported identical without being read.
	 *
	 * THE VALUE IS NOT INVENTED.  Plan 9 has no device numbers,
	 * but st_rdev's actual contract -- shared by every name that
	 * reaches one device, different for any two distinct ones --
	 * is exactly what a qid is.  A bind gives two paths one qid;
	 * /dev/cons and /dev/null have different ones.  That is the
	 * same identity st_ino already carries, which is the point:
	 * on this system two char specials are the same device if and
	 * only if they are the same file.
	 */
	if(S_ISCHR(s->st_mode) || S_ISBLK(s->st_mode))
		s->st_rdev = d->qid.path;
	else
		s->st_rdev = 0;
	if(fi && (fi->flags&FD_BUFFERED))
		s->st_size = fi->buf->n;
	else
		s->st_size = d->length;
		s->st_atim.tv_sec  = d->atime;
		s->st_atim.tv_nsec = 0;
		s->st_mtim.tv_sec  = d->mtime;
		s->st_mtim.tv_nsec = 0;
		s->st_ctim.tv_sec  = d->mtime;
		s->st_ctim.tv_nsec = 0;
	if(fi && fi->uid != -2){
		s->st_uid = fi->uid;
		s->st_gid = fi->gid;
	} else {
		nam = d->uid;
		if(_getpw(&num, &nam, 0))
			s->st_uid = num;
		nam = d->gid;
		if(_getpw(&num, &nam, 0))
			s->st_gid = num;
		if(fi){
			fi->uid = s->st_uid;
			fi->gid = s->st_gid;
		}
	}
}

/*
 * Version marker for `rdev-test.c'. `pcc -o x x.c' relinks against
 * the INSTALLED libap, so a test built from a fresh pull can run
 * days-old library code and report a pass on it; a test that calls
 * this will not LINK against a libap predating the st_rdev change
 * above. Eighth use of the idiom, after _sock_listenmark, _execmark,
 * _ttymark, _getcwdmark, _printfmark, _dupmark and _dotdirmark --
 * and the one it matters most for, since the bug it guards against
 * is one whose whole symptom is that nothing is printed.
 */
int
_rdevmark(void)
{
	return 1;
}
