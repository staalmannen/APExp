// Derived from Inferno utils/6l/obj.c and utils/6l/span.c
// http://code.google.com/p/inferno-os/source/browse/utils/6l/obj.c
// http://code.google.com/p/inferno-os/source/browse/utils/6l/span.c
//
//	Copyright © 1994-1999 Lucent Technologies Inc.  All rights reserved.
//	Portions Copyright © 1995-1997 C H Forsyth (forsyth@terzarima.net)
//	Portions Copyright © 1997-1999 Vita Nuova Limited
//	Portions Copyright © 2000-2007 Vita Nuova Holdings Limited (www.vitanuova.com)
//	Portions Copyright © 2004,2006 Bruce Ellis
//	Portions Copyright © 2005-2007 C H Forsyth (forsyth@terzarima.net)
//	Revisions Copyright © 2000-2007 Lucent Technologies Inc. and others
//	Portions Copyright © 2009 The Go Authors.  All rights reserved.
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#include	"l.h"
#include	"lib.h"
#include	<ar.h>
#include	<ctype.h>

char* getgoroot(void);
char* getgoos(void);

#ifndef isalpha
#define isalpha(c) (((c)>='a' && (c)<='z') || ((c)>='A' && (c)<='Z'))
#endif

/* Global linker symbols */
char*	libdir[16];
int	nlibdir = 0;
int	go_libraryp;
go_Library*	go_library;
int	go_nlibrary;

/* set by go_mywhatsys() */
char*	go_goroot;
char*	go_goarch;
char*	go_goos;

/*
 * These functions bridge the DWARF code to the native linker's output.
 * We use the native cput() and cflush() macros defined in l.h.
 */

void
vlputl(vlong v)
{
	lputl(v);
	lputl(v>>32);
}

vlong
cpos(void)
{
	return seek(cout, 0, 1);
}

void
ldobj1(Biobuf *f, char *pkg, int64 len, char *pn)
{
	ldobj(f->fid, len, pn);
}

void
go_ldobj(Biobuf *f, char *pkg, int64 len, char *pn, int whence)
{
	ldobj(f->fid, len, pn);
}

void
ldpkg(Biobuf *f, char *pkg, int64 len, char *filename, int whence)
{
	go_ldpkg(f, pkg, len, filename, whence);
}

char*
expandpkg(char *name, char *pkg)
{
	return go_expandpkg(name, pkg);
}
char*
getgoroot(void)
{
	char *p;
	p = getenv("GOROOT");
	if(p == nil)
		p = "/usr/local/go";
	return p;
}

char*
getgoos(void)
{
	char *p;
	p = getenv("GOOS");
	if(p == nil)
		p = "plan9";
	return p;
}

int
go_pathchar(void)
{
	return '/';
}

static	uchar*	hunk;
static	uint32	nhunk;
#define	NHUNK	(10UL<<20)

void*
go_mal(uint32 n)
{
	void *v;

	n = (n+7)&~7;
	if(n > NHUNK) {
		v = malloc(n);
		memset(v, 0, n);
		return v;
	}
	if(n > nhunk) {
		hunk = malloc(NHUNK);
		nhunk = NHUNK;
	}

	v = hunk;
	nhunk -= n;
	hunk += n;

	memset(v, 0, n);
	return v;
}

void
go_unmal(void *v, uint32 n)
{
	n = (n+7)&~7;
	if(hunk - n == v) {
		hunk -= n;
		nhunk += n;
	}
}

char*
go_pathtoprefix(char *s)
{
	static char hex[] = "0123456789abcdef";
	char *p, *r, *w;
	int n;

	n = 0;
	for(r=s; *r; r++)
		if(*r <= ' ' || *r == '.' || *r == '%' || *r == '"')
			n++;

	if(n == 0)
		return s;

	p = go_mal((r-s)+1+2*n);
	for(r=s, w=p; *r; r++) {
		if(*r <= ' ' || *r == '.' || *r == '%' || *r == '"') {
			*w++ = '%';
			*w++ = hex[(*r>>4)&0xF];
			*w++ = hex[*r&0xF];
		} else
			*w++ = *r;
	}
	*w = '\0';
	return p;
}

int
go_iconv(Fmt *fp)
{
	char *p;

	p = va_arg(fp->args, char*);
	if(p == nil) {
		fmtstrcpy(fp, "<nil>");
		return 0;
	}
	p = go_pathtoprefix(p);
	fmtstrcpy(fp, p);
	return 0;
}

void
go_mywhatsys(void)
{
	go_goroot = getgoroot();
	go_goos = getgoos();
	go_goarch = thestring;	// ignore $GOARCH - we know who we are
}

void
go_mangle(char *file)
{
	fprint(2, "%s: mangled input file\n", file);
	go_errorexit();
}

Section*
go_addsection(Segment *seg, char *name, int rwx)
{
	Section **l;
	Section *sect;
	
	for(l=&seg->sect; *l; l=&(*l)->next)
		;
	sect = go_mal(sizeof *sect);
	sect->rwx = rwx;
	sect->name = name;
	sect->seg = seg;
	*l = sect;
	return sect;
}

void
go_ewrite(int fd, void *buf, int n)
{
	if(write(fd, buf, n) < 0) {
		diag("write error: %r");
		go_errorexit();
	}
}

void
go_Lflag(char *arg)
{
	if(nlibdir >= 16-1) {
		print("too many -L's: %d\n", nlibdir);
		usage();
	}
	libdir[nlibdir++] = arg;
}

void
go_libinit(void)
{
	fmtinstall('i', go_iconv);
	go_mywhatsys();
	if(strcmp(go_goarch, thestring) != 0)
		print("goarch is not known: %s\n", go_goarch);

	libdir[nlibdir++] = smprint("%s/pkg/%s_%s", go_goroot, go_goos, go_goarch);


	remove(outfile);
	cout = create(outfile, 1, 0775);
	if(cout < 0) {
		diag("cannot create %s", outfile);
		go_errorexit();
	}

	if(INITENTRY == nil) {
		INITENTRY = go_mal(strlen(go_goarch)+strlen(go_goos)+10);
		sprint(INITENTRY, "_rt0_%s_%s", go_goarch, go_goos);
	}
	go_lookup(INITENTRY, 0)->type = SXREF;
}

void
go_errorexit(void)
{
	if(nerrors) {
		if(cout >= 0)
			remove(outfile);
		exits("error");
	}
	exits(0);
}

void
go_addlib(char *src, char *obj)
{
	char name[1024], pname[1024], comp[256], *p;
	int i, search;

	if(histfrogp <= 0)
		return;

	search = 0;
	if(histfrog[0]->name[1] == '/') {
		sprint(name, "");
		i = 1;
	} else
	if(isalpha(histfrog[0]->name[1]) && histfrog[0]->name[2] == ':') {
		strcpy(name, histfrog[0]->name+1);
		i = 1;
	} else
	if(histfrog[0]->name[1] == '.') {
		sprint(name, ".");
		i = 0;
	} else {
		sprint(name, "");
		i = 0;
		search = 1;
	}

	for(; i<histfrogp; i++) {
		snprint(comp, sizeof comp, "%s", histfrog[i]->name+1);
		for(;;) {
			p = strstr(comp, "$O");
			if(p == 0)
				break;
			memmove(p+1, p+2, strlen(p+2)+1);
			p[0] = thechar;
		}
		for(;;) {
			p = strstr(comp, "$M");
			if(p == 0)
				break;
			if(strlen(comp)+strlen(thestring)-2+1 >= sizeof comp) {
				diag("library component too long");
				return;
			}
			memmove(p+strlen(thestring), p+2, strlen(p+2)+1);
			memmove(p, thestring, strlen(thestring));
		}
		if(strlen(name) + strlen(comp) + 3 >= sizeof(name)) {
			diag("library component too long");
			return;
		}
		if(i > 0 || !search)
			strcat(name, "/");
		strcat(name, comp);
	}
	cleanname(name);

	if(search) {
		for(i=0; i<nlibdir; i++) {
			snprint(pname, sizeof pname, "%s/%s", libdir[i], name);
			if(access(pname, AEXIST) >= 0)
				break;
		}
	}else
		strcpy(pname, name);
	cleanname(pname);

	/* runtime.a -> runtime */
	if(strlen(name) > 2 && name[strlen(name)-2] == '.')
		name[strlen(name)-2] = '\0';

	if(debug['v'])
		Bprint(&bso, "%5.2f addlib: %s %s pulls in %s\n", cputime(), obj, src, pname);

	go_addlibpath(src, obj, pname, name);
}

void
go_addlibpath(char *srcref, char *objref, char *file, char *pkg)
{
	int i;
	int nlib = 0; // Temporary to satisfy linker
	char *p;

	if(debug['v'])
		Bprint(&bso, "%5.2f addlibpath: srcref: %s objref: %s file: %s pkg: %s\n",
		cputime(), srcref, objref, file, pkg);
}

void
go_loadlib(void)
{
	char pname[1024];
	int i;
	int32 h;
	Sym *s;

#ifdef GOLANG    
    int found = 0;
	for(i=0; i<nlibdir; i++) {
		snprint(pname, sizeof pname, "%s/runtime.a", libdir[i]);
		if(debug['v'])
			Bprint(&bso, "searching for runtime.a in %s\n", pname);
		if(access(pname, AEXIST) >= 0) {
			go_addlibpath("internal", "internal", pname, "runtime");
			found = 1;
			break;
		}
	}
	if(!found) Bprint(&bso, "warning: unable to find runtime.a\n");
#endif

loop:
	xrefresolv = 0;
	// Use architecture-specific library list
	for(i=0; i<libraryp; i++) {
		if(debug['v'])
			Bprint(&bso, "%5.2f autolib: %s (from %s)\n", cputime(), library[i], libraryobj[i]);
		objfile(library[i]);
	}

	if(xrefresolv)
	for(h=0; h<NHASH; h++)
	for(s = hash[h]; s != S; s = s->link)
		if(s->type == SXREF)
			goto loop;
}

void
go_objfile(char *file, char *pkg)
{
	// Wrapper to call native objfile
	objfile(file);
}

Sym*
go_lookup(char *symb, int v)
{
	return (Sym *) lookup(symb, v);
}

void
go_copyhistfrog(char *buf, int nbuf)
{
	char *p, *ep;
	int i;

	p = buf;
	ep = buf + nbuf;
	i = 0;
	for(i=0; i<histfrogp; i++) {
		p = seprint(p, ep, "%s", histfrog[i]->name+1);
		if(i+1<histfrogp && (p == buf || p[-1] != '/'))
			p = seprint(p, ep, "/");
	}
}

void
go_addhist(int32 line, int type)
{
	Auto *u;
	Sym *s;
	int i, j, k;

	u = go_mal(sizeof(Auto));
	s = go_mal(sizeof(Sym));
	s->name = go_mal(2*(histfrogp+1) + 1);

	u->asym = s;
	u->type = type;
	u->aoffset = line;
	u->link = curhist;
	curhist = u;

	s->name[0] = 0;
	j = 1;
	for(i=0; i<histfrogp; i++) {
		k = histfrog[i]->value;
		s->name[j+0] = k>>8;
		s->name[j+1] = k;
		j += 2;
	}
	s->name[j] = 0;
	s->name[j+1] = 0;
}

void
go_histtoauto(void)
{
	Auto *l;

	while((l = curhist) != nil) {
		curhist = l->link;
		l->link = curauto;
		curauto = l;
	}
}

void
go_collapsefrog(Sym *s)
{
	int i;

	for(i=1; i<histfrogp; i++)
		if(strcmp(histfrog[i]->name+1, "..") == 0) {
			memmove(histfrog+i-1, histfrog+i+1,
				(histfrogp-i-1)*sizeof(histfrog[0]));
			histfrogp--;
			goto out;
		}

	for(i=0; i<histfrogp; i++) {
		if(strcmp(histfrog[i]->name+1, ".") == 0) {
			memmove(histfrog+i, histfrog+i+1,
				(histfrogp-i-1)*sizeof(histfrog[0]));
			goto out;
		}
	}

	memmove(histfrog+0, histfrog+1,
		(histfrogp-1)*sizeof(histfrog[0]));

out:
	histfrog[histfrogp-1] = s;
}

vlong
addstring(Sym *s, char *str)
{
	USED(s);
	diag("addstring %s not implemented", str);
	return 0;
}
