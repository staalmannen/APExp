#include <u.h>
#include <libc.h>
#include <ctype.h>
#include <bio.h>
#include "mkmk.h"


void *
emallocz(long len, int clear)
{
	void *p;

	if((p = mallocz(len, clear)) == nil)
		sysfatal("mallocz: no memory %r\n");
	setmalloctag(p, getcallerpc(&len));
	return p;
}

void *
erealloc(void *p, long len)
{
	void *q;

	if((q = realloc(p, len)) == nil)
		sysfatal("realloc: no memory %r\n");
	setmalloctag(q, getcallerpc(&p));
	return q;
}

char *
estrdup(char *s)
{
	void *p;
	int l;

	l = strlen(s);
	if((p = strdup(s)) == nil)
		sysfatal("strdup: no memory %r\n");
	setmalloctag(p, getcallerpc(&s));
	return p;
}

void
wrap(int *colp, char *fmt, ...)
{
	va_list args;
	/*
	 * I don't care what you say, tab stops are 
	 * and always will be every eight characters.
	 */
	enum { Tabstops = 8 };

	if(*colp > Wrap){
		Bprint(op, "\\\n\t");
		*colp = Tabstops;
	}

	va_start(args, fmt);
	*colp += Bvprint(op, fmt, args);
	va_end(args);
}
	
int
trimfmt(Fmt *f)
{
	int n;
	char *s, *p, *q;

	s = va_arg(f->args, char *);
	p = estrdup(s);
	if((q = strrchr(p, '.')) == nil)
		sysfatal("trimfmt: %q string contains no dot", p);
	*q = 0;

	n = fmtprint(f, "%s", p);
	free(p);
	return n;
}


int
addlist(List **root, char *name)
{
	List *l, **prev;

	for(prev = root, l = *root; l; prev = &l->next, l = l->next)
		if(strcmp(l->name, name) == 0)
			return 0;

	l = emallocz(sizeof(List)+strlen(name)+1, 1);
	l->name = (char *)&l[1];
	strcpy(l->name, name);
	*prev = l;
	return 1;
}

uint
hash(char *s, int sz)
{
	uint n;

	for(n = 0; *s; s++)
		n = *s + 31 * n;
	return n % sz;
}

char *
findinc(char *file, char type, List *langincdir, int *sysinc)
{
	List *l;
	char *s;

	*sysinc = 0;
	if(type == '"' || *file == '/'){
		s = estrdup(file);
		if(access(s, 4) != -1)
			return s;
		free(s);
	}
	for (l = Incdir; l; l = l->next){
		s = emallocz(strlen(l->name)+strlen(file)+2, 0);
		strcpy(s, l->name);
		strcat(s, "/");
		strcat(s, file);
		if(access(s, 4) != -1)
			return s;
		free(s);
	}
	for (l = langincdir; l; l = l->next){
		s = emallocz(strlen(l->name)+strlen(file)+2, 0);
		strcpy(s, l->name);
		strcat(s, "/");
		strcat(s, file);
		if(access(s, 4) != -1){
			includehint(file);
			*sysinc = 1;
			return s;
		}
		free(s);
	}
	return nil;
}

