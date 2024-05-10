#include <u.h>
#include <libc.h>
#include <ctype.h>
#include <bio.h>
#include "mkmk.h"

List *Pragmalib = nil;

#define Name1(x)	(isalpha((x)) || (x) == '_')
#define NameN(x)	(isalnum((x)) || (x) == '_')

enum {				/* cpp parser states */
	Tlost = 0,
	Tenable = 1,
	Tdisable = 2,
	Tinherit = 4,

	Memchunk = 1024,	/* chunk size for command line allocation */
};

static void
cpperr(State *s, char *fmt, ...)
{
	va_list arg;

	fprint(2, "%s %s:%d ", argv0, s->file, s->line);
	va_start(arg, fmt);
	vfprint(2, fmt, arg);
	va_end(arg);
}

static int
peek(State *s)
{
	if(s->sp < 1)
		return Tlost;
	return s->stk[s->sp -1];
}

static int
pop(State *s)
{
	if(s->sp < 1)
		return Tlost;
	return s->stk[--s->sp];
}

static void
push(State *s, int state)
{
	if(s->sp >= Ifstack){
		cpperr(s, "#ifdef stack overflow\n");
		return;
	}
	if(state == Tdisable)
		state = Tdisable|Tinherit;
	s->stk[s->sp++] = state | (peek(s) & Tinherit);
}

static void
doinclude(State *s, char *p)
{
	File *f;
	int sysinc;
	char term, *q, *path;

	if(peek(s) & (Tdisable|Tinherit))
		return;

	switch(*p){
	case '"': p++; term = '"'; break;
	case '<': p++; term = '>'; break;
	default:
		cpperr(s, "%c - bad filename quote character\n", *p);
		return;
	}
	if((q = strchr(p, term)) == nil){
		cpperr(s, "%s - unterminated filename\n", p);
		return;
	}
	*q = 0;

	if((path = findinc(p, term, s->langincdirs, &sysinc)) == nil){
		if(Autoconf && strcmp(p, "config.h") != 0)
			cpperr(s, "%q - include file not found\n", p);
	}

	if(path == nil)
		path = estrdup(p);
	f = addfile(path, sysinc);
	f->ref++;
	free(path);
	scanfile(s->dep, f, s->file, s->line);
}

static void
dodefine(State *s, char *p)
{
	int brace;
	Symb *sym;
	char *name, *val;

	if(peek(s) & (Tdisable|Tinherit))
		return;

	if(! Name1(*p))
		cpperr(s, "%q - bad character in macro name\n", p);
	name = p;
	while(NameN(*p))
		p++;

	val = nil;
	if(*p == '('){
		*p++ = 0;
		brace = 1;
		while(*p){
			switch(*p++){
			case '(': brace++; break;
			case ')': brace--; break;
			default: break;
			}
			if(brace == 0)
				break;
		}
		val = p;
		
	}
	if(isspace(*p)){
		*p++ = 0;
		while(isspace(*p))
			p++;
		val = p;
	}

	if(val == nil || ! *val)
		val = "1";
	setsym(name, val);
}

static void
doundef(State *s, char *p)
{
	char *name;

	if(peek(s) & (Tdisable|Tinherit))
		return;

	if(! Name1(*p))
		cpperr(s, "%q - bad character in macro name\n", p);
	name = p;
	while(NameN(*p))
		p++;
	*p = 0;

	/*
	 * Ignore any error, it appears to be legal to #undef
	 * a name which has never been #define'ed
	 */
	rmsym(name);
}

static void
doifdef(State *s, char *p)
{
	char *name;

	if(peek(s) & (Tdisable|Tinherit)){
		push(s, Tdisable);
		return;
	}

	if(! Name1(*p))
		cpperr(s, "%q - bad character in macro name\n", p);
	name = p;
	while(NameN(*p))
		p++;
	*p = 0;

	if(looksym(name, s->langincdirs) == nil)
		push(s, Tdisable);
	else
		push(s, Tenable);
}

static void
doifndef(State *s, char *p)
{
	char *name;

	if(peek(s) & (Tdisable|Tinherit)){
		push(s, Tdisable);
		return;
	}

	if(! Name1(*p))
		cpperr(s, "%q - bad character in macro name\n", p);
	name = p;
	while(NameN(*p))
		p++;
	*p = 0;
	if(looksym(name, s->langincdirs) == nil)
		push(s, Tenable);
	else
		push(s, Tdisable);
}

static void
doif(State *s, char *p)
{
	if(peek(s) & (Tdisable|Tinherit)){
		push(s, Tdisable);
		return;
	}

	if(expr(s, p))
		push(s, Tenable);
	else
		push(s, Tdisable);
}

static void
doelif(State *s, char *p)
{
	if(peek(s) & (Tdisable|Tinherit))
		return;

	switch(pop(s)){
	case Tenable:
	case Tenable|Tinherit:
		push(s, Tdisable);
		return;
	case Tlost:
		cpperr(s, "#elif - not in a conditional clause\n");
		return;
	}

	if(expr(s, p))
		push(s, Tenable);
	else
		push(s, Tdisable);
}

static void
doelse(State *s, char *)
{
	switch(pop(s)){
	case Tenable:
	case Tenable|Tinherit:
		push(s, Tdisable);
		break;
	case Tdisable:
	case Tdisable|Tinherit:
		push(s, Tenable);
		break;
	case Tlost:
		cpperr(s, "#else - not in a conditional clause\n");
		break;
	}
}

static void
doendif(State *s, char *)
{
	switch(pop(s)){
	case Tlost:
	case Tlost|Tinherit:
		cpperr(s, "#endif - not in a conditional clause\n");
		break;
	}
}

static char *
expand(char *str)
{
	int l;
	char *p, *path;

	l = strlen(str)+1;
	path = estrdup(str);

	for(;;){
		if((p = strstr(path, "$O")) == nil)
			break;
		memmove(p+1, p+2, strlen(p+2)+1);
		p[0] = Objletter;
	}
	for(;;){
		if((p = strstr(path, "$M")) == nil)
			break;
		if(strlen(path)+strlen(Objname)-2+1 >= l) {
			l = strlen(path)+strlen(Objname)-2+2;
			path = erealloc(path, l);
			continue;
		}
		memmove(p+strlen(Objname), p+2, strlen(p+2)+1);
		memmove(p, Objname, strlen(Objname));
	}
	return path;
}

static void
dopragma(State *s, char *p)
{
	int l;
	char *q, *t, *path, *m;
	static char *lib = "lib";

	l = strlen(lib);
	if(strncmp(p, "lib", l) != 0)
		return;
	p += l;

	while(isspace(*p))
		p++;
	if(*p++ != '"')
		cpperr(s, "#pragma lib - \" not found\n");
	if((q = strrchr(p, '"')) == nil)
		cpperr(s, "#pragma lib - \" unmatched\n");
	*q = 0;

	path = expand(p);
	if(addlist(&Pragmalib, path) == 1)
		parse_ar(path);
	free(path);
}


static char *
pass1(State *s, char *buf, int *alloc)
{
	int c, t, used, state;
	enum { Lost, String, Cplusplus, Comment };

	used = 0;
	state = Lost;

	while((c = Bgetc(s->bp)) != -1){
		if(c == '\n'){
			s->line++;
			if(state == Cplusplus)
				state = Lost;
		}
		if(c == '/'){
			t = Bgetc(s->bp);
			if(t == '*' && state == Lost)
				state = Comment;
			else
			if(t == '/' && state == Lost)
				state = Cplusplus;
			else
				Bungetc(s->bp);
		}

		if(c == '*'){
			t = Bgetc(s->bp);
			if(t == '/' && state == Comment){
				state = Lost;
				c = ' ';
			}
			else
				Bungetc(s->bp);
		}
		if(c == '\\'){
			t = Bgetc(s->bp);
			if(t == '\n')
				c = ' ';
			else
				Bungetc(s->bp);
		}

		if(c == '\n' && state == Lost)
			break;

		if(state != Comment && state != Cplusplus){
			if(used >= *alloc-1){
				*alloc += Memchunk;
				buf = erealloc(buf, *alloc);
			}
			buf[used++] = c;
		}
	}
	if(c == -1)
		return nil;
	buf[used] = 0;
	return buf;
}

void
parse_cpp(State *s)
{
	int l, alloc;
	char *p, *buf;
	struct {
		char *name;
		void (*func)(State *, char *);
	} *d, dir[] = {
		{ "include",	doinclude },
		{ "define",	dodefine },
		{ "ifndef",	doifndef },
		{ "undef",	doundef },
		{ "ifdef",	doifdef },
		{ "endif",	doendif },
		{ "elif",	doelif },
		{ "else",	doelse },
		{ "if",		doif },
		{ "pragma",	dopragma },
	};
	
	alloc = Memchunk;
	buf = emallocz(alloc, 0);
	while((buf = pass1(s, buf, &alloc)) != nil){
		p = buf;
		while(isspace(*p))
			p++;
		if(*p++ != '#')
			continue;

		while(isspace(*p))
			p++;
		for(d = dir; d < &dir[nelem(dir)]; d++){
			l = strlen(d->name);
			if(strncmp(p, d->name, l) == 0){
				p += l;
				break;
			}
		}
		if(d >= &dir[nelem(dir)])
			continue;

		while(isspace(*p))
			p++;
//print("%s:%d %s %s [%d -> ", s->file, s->line, d->name, p, peek(s));
		d->func(s, p);
//print("%d]\n", peek(s));
	}
	free(buf);
}

