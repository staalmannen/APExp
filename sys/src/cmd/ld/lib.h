// Derived from Inferno utils/6l/l.h
// http://code.google.com/p/inferno-os/source/browse/utils/6l/l.h
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

#ifndef _LD_LIB_H_
#define _LD_LIB_H_

// Where symbol table data gets mapped into memory.
#define SYMDATVA 0x99LL<<24

/* Go-style types for compatibility */
typedef unsigned char uint8;
typedef unsigned short uint16;
typedef long uint32;
typedef uvlong uint64;
typedef char int8;
typedef short int16;
typedef long int32;
typedef vlong int64;

/* Rename conflicting symbols from standard linkers */
#define library go_library
#define libraryp go_libraryp
#define nlibrary go_nlibrary
#define Library go_Library

/* I/O macros used by DWARF (little-endian) */
#define LPUT(v) lputl(v)
#define WPUT(v) wputl(v)
#define VPUT(v) vlputl(v)

/* Map names to the renamed versions in lib.c */
#define mal go_mal
#define unmal go_unmal
#define addsection go_addsection
#define ewrite go_ewrite
#define mangle go_mangle
#define mywhatsys go_mywhatsys
#define pathchar go_pathchar
#define pathtoprefix go_pathtoprefix

typedef struct Reloc Reloc;
struct Reloc
{
	int n;
	int t;
	uchar *m;
	ulong *a;
};

typedef struct go_Library go_Library;
...
// Terrible but standard terminology.
// A segment describes a block of file to load into memory.
// A section further describes the pieces of that block for
// use in debuggers and such.

typedef struct Segment Segment;
typedef struct Section Section;

struct Segment
{
	uchar	rwx;		// permission as usual unix bits (5 = r-x etc)
	uvlong	vaddr;	// virtual address
	uvlong	len;		// length in memory
	uvlong	fileoff;	// file offset
	uvlong	filelen;	// length on disk
	Section*	sect;
};

struct Section
{
	uchar	rwx;
	char	*name;
	uvlong	vaddr;
	uvlong	len;
	Section	*next;	// in segment list
	Segment	*seg;
};

extern	char	symname[];
extern	char	*libdir[];
extern	int	nlibdir;
extern	int	cout;

EXTERN	char*	INITENTRY;
EXTERN	char	thechar;
EXTERN	char*	thestring;
EXTERN	go_Library*	go_library;
EXTERN	int	go_libraryp;
EXTERN	int	go_nlibrary;
EXTERN	Sym*	hash[NHASH];
EXTERN	Sym*	histfrog[MAXHIST];
EXTERN	uchar	fnuxi8[8];
EXTERN	uchar	fnuxi4[4];
EXTERN	int	histfrogp;
EXTERN	int	histgen;
EXTERN	uchar	inuxi1[1];
EXTERN	uchar	inuxi2[2];
EXTERN	uchar	inuxi4[4];
EXTERN	uchar	inuxi8[8];
EXTERN	char*	outfile;
EXTERN	int32	nsymbol;
EXTERN	char*	thestring;

EXTERN	Segment	segtext;
EXTERN	Segment	segdata;
EXTERN	Segment	segrodata;	// NaCl only
EXTERN	Segment	segsym;

void	go_addlib(char *src, char *obj);
void	go_addlibpath(char *srcref, char *objref, char *file, char *pkg);
Section*	go_addsection(Segment*, char*, int);
void	go_copyhistfrog(char *buf, int nbuf);
void	go_addhist(int32 line, int type);
void	go_asmlc(void);
void	go_histtoauto(void);
void	go_collapsefrog(Sym *s);
Sym*	go_lookup(char *symb, int v);
void	go_nuxiinit(void);
int	go_find1(int32 l, int c);
int	go_find2(int32 l, int c);
int32	go_ieeedtof(Ieee *e);
double	go_ieeedtod(Ieee *e);
void	undefsym(Sym *s);
void	go_zerosig(char *sp);
void	readundefs(char *f, int t);
int32	go_Bget4(Biobuf *f);
void	go_loadlib(void);
void	go_errorexit(void);
void	go_mangle(char*);
void	go_objfile(char *file, char *pkg);
void	go_libinit(void);
void	go_Lflag(char *arg);
void	usage(void);
void	ldobj1(Biobuf *f, char*, int64 len, char *pn);
void	go_ldobj(Biobuf*, char*, int64, char*, int);
void	ldpkg(Biobuf*, char*, int64, char*, int);
void	mark(Sym *s);
void	go_mkfwd(void);
char*	expandpkg(char*, char*);
void	deadcode(void);
void	go_ewrite(int, void*, int);
Reloc*	addrel(Sym*);
void	codeblk(int32, int32);
void	datblk(int32, int32);
Sym*	datsort(Sym*);
void	reloc(void);
void	savedata(Sym*, Prog*);
void	symgrow(Sym*, int32);
vlong	addstring(Sym*, char*);
vlong	adduint32(Sym*, uint32);
vlong	adduint64(Sym*, uint64);
vlong	addaddr(Sym*, Sym*);
vlong	addsize(Sym*, Sym*);
vlong	adduint8(Sym*, uint8);
vlong	adduint16(Sym*, uint16);
void	strnput(char*, int);

int	go_pathchar(void);
void*	go_mal(uint32);
void	go_unmal(void*, uint32);
void	go_mywhatsys(void);
void	vlputl(vlong);

/* set by call to mywhatsys() */
extern	char*	go_goroot;
extern	char*	go_goarch;
extern	char*	go_goos;

/* whence for ldpkg */
enum {
	FileObj = 0,
	ArchiveObj,
	Pkgdef
};

#endif
