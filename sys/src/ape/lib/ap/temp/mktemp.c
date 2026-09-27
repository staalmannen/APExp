/*
 * mktemp -- replace the trailing XXXXXX of a template with a name
 * that does not exist yet.
 *
 * THE VERSION THIS REPLACES COULD PRODUCE 26 NAMES PER PROCESS.
 *
 * It wrote the pid modulo 100000 into five of the six X's and then
 * tried a single trailing letter, 'a' through 'z':
 *
 *	x = getpid() % 100000;
 *	sprintf(p, "%05d", x);
 *	p += 5;
 *	for(c = 'a'; c <= 'z'; c++) {
 *		*p = c;
 *		if (stat(template, &stbuf) < 0)
 *			return template;
 *	}
 *	*template = 0;
 *
 * -- so the twenty-seventh temporary file a process ever asked for
 * could not be named, and mktemp answered by emptying the template.
 * mkstemp then looped twenty times over EXACTLY THE SAME twenty-six
 * candidates, because nothing in them varied but the pid, and
 * finished by calling open("") -- which on Plan 9 is the error
 * `empty file name'.
 *
 * WHAT IT COST, AND HOW IT SURFACED. coreutils `sort' on a 272 MB
 * file:
 *
 *	sort: cannot create temporary file in '/tmp': empty file name
 *
 * A merge sort of that size wants far more than 26 spill files. The
 * message names `/tmp' and reads like a permission problem or a full
 * disc -- and the text after the colon is a **Plan 9 errstr**, come
 * through libap's EPLAN9 arm rather than a POSIX strerror, so *it
 * describes the last system call rather than the directory it
 * names.* Read as a /tmp problem it sends you nowhere.
 *
 * It is not sort's bug. Any program wanting many temporaries hits
 * it, and only at the 27th -- so a program that makes a handful is
 * fine for ever and one that makes dozens dies. That is why it
 * survived this long.
 *
 * USES musl's __randname, WHICH WAS ALREADY IN THIS DIRECTORY and
 * already in OFILES: `mkdtemp.c' beside this file has always used
 * it, so the tree held a working generator and a broken one at the
 * same time, and mktemp had the broken one. *When the library
 * already does the thing you are adding, copy the whole idiom rather
 * than write a second one.* 32 characters per position, six
 * positions, about 1.07e9 names, reseeded per call from
 * clock_gettime and lrand.
 *
 * ON THE RACE. `stat' saying "not there" does not promise the name
 * is still free when the caller opens it, and this function cannot
 * fix that -- POSIX marks mktemp obsolescent for exactly that
 * reason. **mkstemp is the safe entry point**: it opens O_EXCL and
 * retries, and the larger name space is what gives the retry
 * somewhere to go.
 */
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

extern char *__randname(char *);

enum {
	NTRY = 100,	/* as mkdtemp uses */
};

char*
mktemp(char *template)
{
	size_t l;
	int i;
	struct stat stbuf;

	l = strlen(template);
	if(l < 6 || memcmp(template + l - 6, "XXXXXX", 6) != 0){
		/*
		 * POSIX: empty the string and say why. The old version
		 * emptied it without setting errno, so the caller
		 * reported whatever errno happened to hold -- which is
		 * how a naming failure came out as a message about
		 * /tmp.
		 */
		*template = 0;
		errno = EINVAL;
		return template;
	}

	for(i = 0; i < NTRY; i++){
		__randname(template + l - 6);
		if(stat(template, &stbuf) < 0)
			return template;
	}

	*template = 0;
	errno = EEXIST;
	return template;
}
