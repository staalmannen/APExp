#include "lib.h"
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include "sys9.h"
#include "dir.h"

/*
 * IS `from' THE SAME DIRECTORY AS, OR AN ANCESTOR OF, THE PLACE `to'
 * WOULD GO? POSIX requires EINVAL when "the old pathname names an
 * ancestor directory of the new pathname", and Tcl's fCmd-9.14.3 and
 * unixFCmd-1.3 ask for exactly that -- `file rename td1 td1' becomes
 * rename("td1", "td1/td1"), which would otherwise report Plan 9's
 * "invalid operation".
 *
 * BY QID RATHER THAN BY STRING. A textual prefix test passes both of
 * those tests and is wrong for `../td1/foo', for `a/./b' and for
 * anything reached through a bind -- and this name space has binds
 * everywhere. So walk up from the parent of `to', appending "/.." and
 * asking the file server each time, and compare identities. The walk
 * stops when a stat fails or the qid stops changing, which is the root.
 *
 * qid.vers is deliberately NOT compared: it changes when a file is
 * written, and this is a question about identity rather than contents.
 */
static int
intoself(Dir *s, const char *to, const char *last)
{
	char p[1024];
	Dir *d;
	Qid prev;
	long n;
	int i, same;

	n = last - to;
	if(n <= 0){
		strcpy(p, ".");
		n = 1;
	} else {
		if(n >= sizeof p - 8)
			return 0;
		memcpy(p, to, n);
		p[n] = 0;
		if(n > 1 && p[n-1] == '/')
			p[--n] = 0;
	}
	memset(&prev, 0, sizeof prev);
	for(i = 0; i < 128; i++){
		if((d = _dirstat(p)) == nil)
			return 0;
		same = d->qid.path == s->qid.path
			&& d->qid.type == s->qid.type
			&& d->type == s->type
			&& d->dev == s->dev;
		if(same){
			free(d);
			return 1;
		}
		if(i > 0 && d->qid.path == prev.path && d->qid.type == prev.type){
			free(d);
			return 0;	/* the root: going up changes nothing */
		}
		prev = d->qid;
		free(d);
		if(n + 4 >= sizeof p)
			return 0;
		memcpy(p+n, "/..", 4);
		n += 3;
	}
	return 0;
}

int
rename(const char *from, const char *to)
{
	char buf[8192], *f, *t;
	Dir *s, *d, nd;
	int n, ffd, tfd;

	f = strrchr(from, '/');
	t = strrchr(to, '/');
	f = f != nil ? f+1 : (char*)from;
	t = t != nil ? t+1 : (char*)to;

	if(*f == '\0' || strcmp(f, ".") == 0 || strcmp(f, "..") == 0
	|| *t == '\0' || strcmp(t, ".") == 0 || strcmp(t, "..") == 0){
		errno = EINVAL;
		return -1;
	}

	if((s = _dirstat(from)) == nil){
		_syserrno();
		return -1;
	}
	if((d = _dirstat(to)) != nil){
		if(d->qid.type == s->qid.type
		&& d->qid.path == s->qid.path
		&& d->qid.vers == s->qid.vers
		&& d->type == s->type
		&& d->dev == s->dev)
			goto out;	/* same file */

		if((d->mode ^ s->mode) & DMDIR){
			errno = (d->mode & DMDIR) ? EISDIR : ENOTDIR;
			goto err;
		}
	}

	if((s->mode & DMDIR) != 0 && intoself(s, to, t)){
		errno = EINVAL;
		goto err;
	}

	/* from and to are in same directory (we miss some cases) */
	if(f-from==t-to && strncmp(from, to, f-from)==0){
		if(d != nil && _REMOVE(to) < 0){
			_syserrno();
			goto err;
		}
		_nulldir(&nd);
		nd.name = t;
		if(_dirwstat(from, &nd) < 0){
			_syserrno();
			goto err;
		}
		goto out;
	}

	/*
	 * Different directories, so the file has to be copied: a wstat can
	 * change a name but cannot move a file to another directory.
	 *
	 * A DIRECTORY IS ITS OWN CASE, and not having one here is what made
	 * every directory rename across directories fail. The code below
	 * used to run for directories too, and `_CREATE(to, OWRITE, ...)'
	 * cannot work on one -- a directory cannot be opened for writing --
	 * so it came back as Plan 9's "invalid operation", i.e. EPLAN9, i.e.
	 * Tcl's `POSIX {unknown error}'. That is fCmd-9.11, which expects
	 * the rename to simply SUCCEED, and it is also why fCmd-9.1 and
	 * unixFCmd-1.7 reported "invalid operation" where they wanted
	 * "permission denied": the create failed for the wrong reason before
	 * the permission on the real target was ever tested.
	 *
	 * An EMPTY directory can be made at the destination and the original
	 * removed. A NON-EMPTY one needs its whole tree copied, which is the
	 * caller's business rather than rename()'s, and EXDEV is how POSIX
	 * says so -- Tcl's CopyRenameOneFile branches on exactly that errno
	 * and does the recursive copy itself.
	 */
	if((s->mode & DMDIR) != 0){
		if((ffd = _OPEN(from, OREAD)) < 0){
			_syserrno();
			goto err;
		}
		n = _READ(ffd, buf, sizeof(buf));
		_CLOSE(ffd);
		if(n > 0){
			errno = EXDEV;
			goto err;
		}
		if(n < 0){
			_syserrno();
			goto err;
		}
		if(d != nil && _REMOVE(to) < 0){
			_syserrno();
			goto err;
		}
		/* OREAD and DMDIR: the two things the old path had wrong */
		if((tfd = _CREATE(to, OREAD, DMDIR | (s->mode & 0777))) < 0){
			_syserrno();
			goto err;
		}
		_CLOSE(tfd);
		if(_REMOVE(from) < 0){
			_syserrno();
			_REMOVE(to);
			goto err;
		}
		goto out;
	}

	if((ffd = _OPEN(from, OREAD)) < 0){
		_syserrno();
		goto err;
	}
	if(d != nil && _REMOVE(to) < 0){
		_syserrno();
		_CLOSE(ffd);
		goto err;
	}
	if((tfd = _CREATE(to, OWRITE, s->mode)) < 0){
		_syserrno();
		_CLOSE(ffd);
		goto err;
	}
	while((n = _READ(ffd, buf, sizeof(buf))) > 0){
		if(_WRITE(tfd, buf, n) != n)
			break;
	}
	_CLOSE(ffd);
	_CLOSE(tfd);
	if(n != 0 || _REMOVE(from) < 0){
		_syserrno();
		_REMOVE(to);	/* cleanup */
		goto err;
	}
out:
	free(s);
	free(d);
	return 0;
err:
	free(s);
	free(d);
	return -1;
}
