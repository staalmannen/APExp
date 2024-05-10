#include <u.h>
#include <libc.h>
#include <ar.h>
#include <bio.h>
#include <mach.h>
#include "mkmk.h"

#define Nhash	101
static List *Functab[Nhash];

static void
addfunc(Sym *s, void* p)
{
	int h;
	List *l;

	USED(p);
	if(s->type != 'T')
		return;
	if (((s->name[0] == '.' || s->name[0] == '$')))
		return;
	if(s->name[0] == '_')
		return;

	h = hash(s->name, Nhash);
	for(l = Functab[h]; l; l = l->next)
		if(strcmp(l->name, s->name) == 0)
			return;
	l = emallocz(sizeof(List) +strlen(s->name) +1, 0);
	l->name = (char *)&l[1];
	strcpy(l->name, s->name);

	l->next = Functab[h];
	Functab[h] = l;
}


static void
doar(Biobuf *bp, char *file)
{
	int offset, size, obj;
	char membername[SARNAME];
	char symname[]="__.SYMDEF";	/* table of contents file name */

	for (offset = Boffset(bp);;offset += size) {
		size = nextar(bp, offset, membername);
		if (size < 0) {
			fprint(2, "%s: phase error on ar header %ld",
				file, offset);
			return;
		}
		if (size == 0)
			return;
		if (strcmp(membername, symname) == 0)
			continue;
		obj = objtype(bp, 0);
		if (obj < 0) {
			fprint(2, "%s: %s inconsistent file",
				file, membername);
			return;
		}
		if (!readar(bp, obj, offset+size, 1)) {
			fprint(2, "%s: %s invalid symbol reference in file",
					file, membername);
			return;
		}
		objtraverse(addfunc, 0);
	}
}

void
parse_ar(char *file)
{
	Biobuf *bp;

	if((bp = Bopen(file, OREAD)) == nil)
		return;
	if (isar(bp))
		doar(bp, file);
	Bterm(bp);
}

int
inlibrary(char *name)
{
	int h;
	List *l;
	h = hash(name, Nhash);
	for(l = Functab[h]; l; l = l->next)
		if(strcmp(l->name, name) == 0)
			return 1;
	return 0;
}

