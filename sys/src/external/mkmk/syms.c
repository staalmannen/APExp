#include <u.h>
#include <libc.h>
#include <ctype.h>
#include <bio.h>
#include "mkmk.h"

/*
 * ANSI requires at least 4095 simultanious macro definitions.
 */

#define Nhash	101
static Symb *Symtab[Nhash];

void
setsym(char *name, char *val)
{
	int h;
	Symb *s;

	h = hash(name, Nhash);
	for(s = Symtab[h]; s; s = s->next)
		if(strcmp(s->name, name) == 0)
			break;
	if(s){
		free(s->val);
		s->val = estrdup(val);
		return;
	}
	s = emallocz(sizeof(Symb) +strlen(name) +1, 0);
	s->name = (char *)&s[1];
	strcpy(s->name, name);
	s->val = estrdup(val);
	s->next = Symtab[h];
	Symtab[h] = s;
}

char *
looksym(char *name, List *incdirs)
{
	int h;
	Symb *s;
	char *val;

	h = hash(name, Nhash);
	for(s = Symtab[h]; s; s = s->next)
		if(strcmp(s->name, name) == 0)
			return s->val;

	if(incdirs == nil)
		return nil;
	return macrohint(name, incdirs);
}

int
rmsym(char *name)
{
	int h;
	Symb *s, **p;

	h = hash(name, Nhash);
	for(p = &Symtab[h], s = Symtab[h]; s; p = &s->next, s = s->next)
		if(strcmp(s->name, name) == 0)
			break;
	if(! s)
		return -1;

	*p = s->next;
	free(s->val);
	free(s);
	return 0;
}

void
dumpvars(Biobuf *bp)
{
	Symb *s;
	int h, n, len;

	len = 0;
	for(h = 0; h < Nhash; h++)
		for(s = Symtab[h]; s; s = s->next){
			n = strlen(s->name);
			if(n > len)
				len = n;
		}

	Bprint(bp, "%*s  %s\n", -len, "variable", "value");

	for(h = 0; h < Nhash; h++)
		for(s = Symtab[h]; s; s = s->next)
			Bprint(bp, "%*s  %s\n", -len, s->name, s->val);
}

