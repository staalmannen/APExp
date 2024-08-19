#include <u.h>
#include <libc.h>
#include <ctype.h>
#include <bio.h>
#include "mkmk.h"
/*
 * This code is left over from an old Unix version of mkmk,
 * it has not been tested since the move to plan9 but is left
 * here in case it is useful in the future
 */

/*
 * HPUX Fortran has two include statement syntaxes:
 *
 * 1/ Starting in the 7th column
 *	the word 'include',
 *	whitespace,
 *	filename with no delimiters.
 *
 * 2/ A dollar '$' in 1st column, 
 *	whitespace,
 *	the word 'include',
 * 	whitespace,
 *	the file delimited by single _or_ double quotes.
 *
 * The word 'include' is not case significant.
 */ 


void
doinclude(State *s, char *buf)
{
	File *f;
	int sysinc;
	char match, *p, *q, *path;

	switch(*p++){
	case '\'': match = '\''; break;
	case '"': match = '"'; break;
	default:
		fprint(2, "%s: %s:%d bad include syntax\n", argv0, s->file, s->line);
		return;
	}

	for(q = strchr(p, 0)-1; p > buf && *q != match; q--)
		*q = 0;
	if(*q == match)
		*q = 0;

	if((path = findinc(p, '"', s->langincdirs, &sysinc)) == 0)
		fprint(2, "%s: %s:%d %q - include file not found\n", argv0, s->file, s->line, p);
	f = addfile(path, sysinc);
	f->ref++;
	free(path);
	scanfile(s->dep, f, s->file, s->line);
}

void
parse_f77(State *s)
{
	char *p;

	while((p = Brdline(s->bp, '\n')) != nil){
		p[Blinelen(s->bp)-1] = 0;

		if(*p != '$' && tolower(p[7]) != 'i')
			continue;

		if(*p == '$')
			p++;

		while(isspace(*p))
			p++;
		if(cistrncmp(p, "include", 7) != 0)
			continue;
		p += 7;

		while(isspace(*p))
			p++;
		doinclude(s, p);
	}
}
