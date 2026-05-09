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

int go_iconv(Fmt*);

/* Conflicting globals are commented out as they are provided by architecture-specific obj.c */
/*
char	symname[]	= SYMDEF;
char*	libdir[16];
int	nlibdir = 0;
int	cout = -1;
*/

//TODO: ifdef GOLANG
char	go_pkgname[]	= "__.PKGDEF";
char*	go_goroot;
char*	go_goarch;
char*	go_goos;

void
vlputl(vlong v)
{
	lputl(v);
	lputl(v>>32);
}

void
go_mywhatsys(void)
{
	go_goroot = getgoroot();
	go_goos = getgoos();
	go_goarch = thestring;	// ignore $GOARCH - we know who we are
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

// Copied from ../gc/subr.c:/^pathtoprefix; must stay in sync.
/*
 * Convert raw string to the prefix that will be used in the symbol table.
 * Invalid bytes turn into %xx.  Right now the only bytes that need
 * escaping are %, ., and ", but we escape all control characters too.
 */
char*
go_pathtoprefix(char *s)
{
	static char hex[] = "0123456789abcdef";
	char *p, *r, *w;
	int n;

	// check for chars that need escaping
	n = 0;
	for(r=s; *r; r++)
		if(*r <= ' ' || *r == '.' || *r == '%' || *r == '"')
			n++;

	// quick exit
	if(n == 0)
		return s;

	// escape
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

/* 
 * The following functions are mostly redundant or conflicting with 
 * architecture-specific linkers. They are kept here but might need
 * to be prefixed or removed if they cause linking errors.
 */

void
go_Lflag(char *arg)
{
	if(nlibdir >= 16-1) { // Assuming 16 from commented out libdir[16]
		print("too many -L's: %d\n", nlibdir);
		usage();
	}
	libdir[nlibdir++] = arg;
}

void
go_libinit(void)
{
	fmtinstall('i', go_iconv);
//TODO: ifdef GOLANG
	go_mywhatsys();	// get goroot, goarch, goos
	if(strcmp(go_goarch, thestring) != 0)
		print("goarch is not known: %s\n", go_goarch);

	// add goroot to the end of the libdir list.
	libdir[nlibdir++] = smprint("%s/pkg/%s_%s", go_goroot, go_goos, go_goarch);

	unlink(outfile);
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
		// try dot, -L "libdir", and then goroot.
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
	go_Library *l;
	char *p;

	for(i=0; i<go_libraryp; i++)
		if(strcmp(file, go_library[i].file) == 0)
			return;

	if(debug['v'])
		Bprint(&bso, "%5.2f addlibpath: srcref: %s objref: %s file: %s pkg: %s\n",
		cputime(), srcref, objref, file, pkg);

	if(go_libraryp == go_nlibrary){
		go_nlibrary = 50 + 2*go_libraryp;
		go_library = realloc(go_library, sizeof go_library[0] * go_nlibrary);
	}

	l = &go_library[go_libraryp++];

	p = go_mal(strlen(objref) + 1);
	strcpy(p, objref);
	l->objref = p;

	p = go_mal(strlen(srcref) + 1);
	strcpy(p, srcref);
	l->srcref = p;

	p = go_mal(strlen(file) + 1);
	strcpy(p, file);
	l->file = p;

	p = go_mal(strlen(pkg) + 1);
	strcpy(p, pkg);
	l->pkg = p;
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
	for(i=0; i<go_libraryp; i++) {
		if(debug['v'])
			Bprint(&bso, "%5.2f autolib: %s (from %s)\n", cputime(), go_library[i].file, go_library[i].objref);
		go_objfile(go_library[i].file, go_library[i].pkg);
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
	int32 off, esym, cnt, l;
	int work;
	Biobuf *f;
	Sym *s;
	char magbuf[SARMAG];
	char name[100], pname[150];
	struct ar_hdr arhdr;
	char *e, *start, *stop, *x;

	pkg = smprint("%i", pkg);

	if(file[0] == '-' && file[1] == 'l') {	// TODO: fix this
		if(debug['9'])
			sprint(name, "/%s/lib/lib", thestring);
		else
			sprint(name, "/usr/%clib/lib", thechar);
		strcat(name, file+2);
		strcat(name, ".a");
		file = name;
	}
	if(debug['v'])
		Bprint(&bso, "%5.2f ldobj: %s (%s)\n", cputime(), file, pkg);
	Bflush(&bso);
	f = Bopen(file, 0);
	if(f == nil) {
		diag("cannot open file: %s", file);
		go_errorexit();
	}
	l = Bread(f, magbuf, SARMAG);
	if(l != SARMAG || strncmp(magbuf, ARMAG, SARMAG)){
		/* load it as a regular file */
		l = Bseek(f, 0L, 2);
		Bseek(f, 0L, 0);
		go_ldobj(f, pkg, l, file, FileObj);
		Bterm(f);
		return;
	}

	l = Bread(f, &arhdr, SAR_HDR);
	if(l != SAR_HDR) {
		diag("%s: short read on archive file symbol header", file);
		goto out;
	}
	if(strncmp(arhdr.name, symname, strlen(symname))) {
		diag("%s: first entry not symbol header", file);
		goto out;
	}

	esym = SARMAG + SAR_HDR + atolwhex(arhdr.size);
	off = SARMAG + SAR_HDR;

	if(debug['u']) {
		struct ar_hdr pkghdr;
		int n;

		// Read next ar header to check for package safe bit.
		Bseek(f, esym+(esym&1), 0);
		l = Bread(f, &pkghdr, SAR_HDR);
		if(l != SAR_HDR) {
			diag("%s: short read on second archive header", file);
			goto out;
		}
		if(strncmp(pkghdr.name, go_pkgname, strlen(go_pkgname))) {
			diag("%s: second entry not package header", file);
			goto out;
		}
		n = atolwhex(pkghdr.size);
		ldpkg(f, pkg, n, file, Pkgdef);
	}

	/*
	 * just bang the whole symbol file into memory
	 */
	Bseek(f, off, 0);
	cnt = esym - off;
	start = go_mal(cnt + 10);
	cnt = Bread(f, start, cnt);
	if(cnt <= 0){
		Bterm(f);
		return;
	}
	stop = &start[cnt];
	memset(stop, 0, 10);

	work = 1;
	while(work) {
		if(debug['v'])
			Bprint(&bso, "%5.2f library pass: %s\n", cputime(), file);
		Bflush(&bso);
		work = 0;
		for(e = start; e < stop; e = strchr(e+5, 0) + 1) {
			x = expandpkg(e+5, pkg);
			s = go_lookup(x, 0);
			if(x != e+5)
				free(x);
			if(s->type != SXREF)
				continue;
			sprint(pname, "%s(%s)", file, s->name);
			if(debug['v'])
				Bprint(&bso, "%5.2f library: %s\n", cputime(), pname);
			Bflush(&bso);
			l = e[1] & 0xff;
			l |= (e[2] & 0xff) << 8;
			l |= (e[3] & 0xff) << 16;
			l |= (e[4] & 0xff) << 24;
			Bseek(f, l, 0);
			l = Bread(f, &arhdr, SAR_HDR);
			if(l != SAR_HDR)
				goto bad;
			if(strncmp(arhdr.fmag, ARFMAG, sizeof(arhdr.fmag)))
				goto bad;
			l = SARNAME;
			while(l > 0 && arhdr.name[l-1] == ' ')
				l--;
			sprint(pname, "%s(%.*s)", file, l, arhdr.name);
			l = atolwhex(arhdr.size);
			go_ldobj(f, pkg, l, pname, ArchiveObj);
			if(s->type == SXREF) {
				diag("%s: failed to load: %s", file, s->name);
				go_errorexit();
			}
			work = 1;
			xrefresolv = 1;
		}
	}
	return;

bad:
	diag("%s: bad or out of date archive", file);
out:
	Bterm(f);
}

void
go_ldobj(Biobuf *f, char *pkg, int64 len, char *pn, int whence)
{
	static int files;
	static char **filen;
	char **nfilen, *line;
	int i, n, c1, c2, c3;
	vlong import0, import1, eof;

	eof = Boffset(f) + len;

	// don't load individual object more than once.
	// happens with import of .6 files because of loop in xresolv.
	// doesn't happen with .a because SYMDEF is consulted
	// first to decide whether each individual object file is needed.
	for(i=0; i<files; i++)
		if(strcmp(filen[i], pn) == 0)
			return;

	if((files&15) == 0){
		nfilen = malloc((files+16)*sizeof(char*));
		memmove(nfilen, filen, files*sizeof(char*));
		free(filen);
		filen = nfilen;
	}
	pn = strdup(pn);
	filen[files++] = pn;

	/* check the header */
	line = Brdline(f, '\n');
	if(line == nil) {
		if(Blinelen(f) > 0) {
			diag("%s: malformed object file", pn);
			return;
		}
		goto eof;
	}
	n = Blinelen(f) - 1;
	if(n != strlen(thestring) || strncmp(line, thestring, n) != 0) {
		if(line)
			line[n] = '\0';
		if(strlen(pn) > 3 && strcmp(pn+strlen(pn)-3, ".go") == 0) {
			print("%cl: input %s is not .%c file (use %cg to compile .go files)\n", thechar, pn, thechar, thechar);
			go_errorexit();
		}
		diag("file not %s [%s]\n", thestring, line);
		return;
	}

	/* skip over exports and other info -- ends with \n!\n */
	import0 = Boffset(f);
	c1 = '\n';	// the last line ended in \n
	c2 = Bgetc(f);
	c3 = Bgetc(f);
	while(c1 != '\n' || c2 != '!' || c3 != '\n') {
		c1 = c2;
		c2 = c3;
		c3 = Bgetc(f);
		if(c3 == Beof)
			goto eof;
	}
	import1 = Boffset(f);

	Bseek(f, import0, 0);
	ldpkg(f, pkg, import1 - import0 - 2, pn, whence);	// -2 for !\n
	Bseek(f, import1, 0);

	ldobj1(f, pkg, eof - Boffset(f), pn);
	return;

eof:
	diag("truncated object file: %s", pn);
}

Sym*
go_lookup(char *symb, int v)
{
	Sym *s;
	char *p;
	long h;
	int l, c;

	h = v;
	for(p=symb; (c = *p) != 0; p++)
		h = h+h+h + c;
	l = (p - symb) + 1;
	if(h < 0)
		h = ~h;
	h %= NHASH;
	for(s = hash[h]; s != S; s = s->link)
		if(s->version == v)
		if(memcmp(s->name, symb, l) == 0)
			return s;

	s = go_mal(sizeof(Sym));
	s->name = go_mal(l);
	memmove(s->name, symb, l);

	s->link = hash[h];
	s->version = v;
	hash[h] = s;
	nsymbol++;
	return s;
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

	/*
	 * bad encoding of path components only allows
	 * MAXHIST components. if there is an overflow,
	 * first try to collapse xxx/..
	 */
	for(i=1; i<histfrogp; i++)
		if(strcmp(histfrog[i]->name+1, "..") == 0) {
			memmove(histfrog+i-1, histfrog+i+1,
				(histfrogp-i-1)*sizeof(histfrog[0]));
			histfrogp--;
			goto out;
		}

	/*
	 * next try to collapse .
	 */
	for(i=0; i<histfrogp; i++)
		if(strcmp(histfrog[i]->name+1, ".") == 0) {
			memmove(histfrog+i, histfrog+i+1,
				(histfrogp-i-1)*sizeof(histfrog[0]));
			goto out;
		}

	/*
	 * last chance, just truncate from front
	 */
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
