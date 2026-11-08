#include <iconv.h>
#include "_iconv.h"

static int
cp2tcs(char *cp, char *tcs, int sz)
{
	int opt, n, i;
	char *s;

	opt = 0;
	n = 0;
	for(s = cp; (s = strstr(s, "//")) != nil;){
		if(n == 0)
			n = (int)(s - cp);
		s += 2;
		if(strncmp(s, "TRANSLIT", 8) == 0 && (s[8] == 0 || s[8] == '/'))
			opt |= Itranslit;
		else if(strncmp(s, "IGNORE", 6) == 0 && (s[6] == 0 || s[6] == '/'))
			opt |= Iignore;
	}
	if(n < 1)
		n = strlen(cp);

	if(cp[0] >= '0' && cp[0] <= '9'){ /* ibm */
		n = snprint(tcs, sz, "ibm%.*s", n, cp);
	}else if(strncmp(cp, "ISO", 3) == 0){
		if(cp[3] == '-' || cp[3] == '_'){
			n--;
			cp++;
		}
		n = snprint(tcs, sz, "%.*s", n-3, cp+3);
	}else if(strncmp(cp, "CP12", 4) == 0){
		n = snprint(tcs, sz, "windows-12%.*s", n-4, cp+4);
	}else{ /* last chance, convert to lowercase. FIXME not all are supported, no checks are made */
		n = snprint(tcs, sz, "%.*s", n, cp);
		for(i = 0; i < n; i++)
			tcs[i] = tolower(tcs[i]);
	}

	return n >= sz ? -1 : opt;
}

iconv_t
iconv_open(char *to, char *from)
{
	int opt, pid, p[2];
	iconv_t ic;

	p[0] = p[1] = -1;
	if((ic = calloc(1, sizeof(*ic))) == nil)
		goto err;
	if(cp2tcs(from, ic->from, sizeof(ic->from)) < 0)
		goto err;
	if((opt = cp2tcs(to, ic->to, sizeof(ic->to))) < 0)
		goto err;
	if(pipe(p) < 0)
		goto err;
	if((pid = rfork(RFPROC|RFFDG|RFNOTEG|RFCENVG|RFNOWAIT)) == 0){
		dup(p[Tcs], 0);
		dup(p[Tcs], 1);
		close(p[0]);
		close(p[1]);
		close(2); /* comment it out if you need debugging */
		execl("/bin/tcs", "tcs", "-f", ic->from, "-t", ic->to, (opt == Iignore) ? "-c" : nil, nil);
		sysfatal("execl: %r");
	}else if(pid < 0){
		goto err;
	}
	close(p[Tcs]);
	ic->fd = p[Us];

	setmalloctag(ic, getcallerpc(&to));

	return ic;
err:
	close(p[0]);
	close(p[1]);
	if(ic != nil)
		free(ic);
	return (iconv_t)-1;
}
