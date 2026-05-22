/*
 * Minimal ELF64 output support for Plan9 linkers.
 * Adapted from Go 1.4 src/cmd/ld/elf.c.
 * Dynamic linking support removed.
 */

#include	"l.h"
#include	"lib.h"
#include	"elf.h"

#define NSECT 48

int iself;
int numelfphdr;
int numelfshdr;

static int elf64;
static ElfEhdr hdr;
static ElfPhdr *phdr[NSECT];
static ElfShdr *shdr[NSECT];

/*
 * Simple string table for section names (.shstrtab).
 * Byte 0 is always '\0' (the empty string / NULL section name).
 */
static char elfstrtab[4096];
static int elfstrtabsz = 1;

static int
addelfstring(char *s)
{
	int off, n;

	off = elfstrtabsz;
	n = strlen(s) + 1;
	if(elfstrtabsz + n > (int)sizeof(elfstrtab)) {
		diag("elf string table overflow");
		errorexit();
	}
	memmove(elfstrtab + elfstrtabsz, s, n);
	elfstrtabsz += n;
	return off;
}

void
elfinit(void)
{
	iself = 1;

	switch(thechar) {
	case '6':
	case '7':
		elf64 = 1;
		hdr.phoff = ELF64HDRSIZE;
		hdr.shoff = ELF64HDRSIZE;
		hdr.ehsize = ELF64HDRSIZE;
		hdr.phentsize = ELF64PHDRSIZE;
		hdr.shentsize = ELF64SHDRSIZE;
		break;
	default:
		elf64 = 0;
		hdr.phoff = ELF32HDRSIZE;
		hdr.shoff = ELF32HDRSIZE;
		hdr.ehsize = ELF32HDRSIZE;
		hdr.phentsize = ELF32PHDRSIZE;
		hdr.shentsize = ELF32SHDRSIZE;
		break;
	}
}

ElfEhdr*
getElfEhdr(void)
{
	return &hdr;
}

ElfPhdr*
newElfPhdr(void)
{
	ElfPhdr *e;

	e = mal(sizeof *e);
	if(hdr.phnum >= NSECT) {
		diag("too many phdrs");
		errorexit();
	}
	phdr[hdr.phnum++] = e;
	numelfphdr = hdr.phnum;
	if(elf64)
		hdr.shoff += ELF64PHDRSIZE;
	else
		hdr.shoff += ELF32PHDRSIZE;
	return e;
}

ElfShdr*
newElfShdr(vlong nameoff)
{
	ElfShdr *e;

	e = mal(sizeof *e);
	e->name = (uint32)nameoff;
	e->shnum = hdr.shnum;
	if(hdr.shnum >= NSECT) {
		diag("too many shdrs");
		errorexit();
	}
	shdr[hdr.shnum++] = e;
	numelfshdr = hdr.shnum;
	return e;
}

/*
 * elfshname: find or create a section header for the named section.
 * The name is added to the in-memory string table if not already present.
 */
ElfShdr*
elfshname(char *name)
{
	int i, off;
	ElfShdr *sh;

	/* Search existing shdrs for a matching name offset */
	for(i = 1; i < elfstrtabsz; ) {
		if(strcmp(elfstrtab + i, name) == 0) {
			off = i;
			goto found;
		}
		i += strlen(elfstrtab + i) + 1;
	}
	/* Not in strtab yet: add it */
	off = addelfstring(name);

found:
	/* Look for existing shdr with this name offset */
	for(i = 0; i < hdr.shnum; i++) {
		sh = shdr[i];
		if((int)sh->name == off)
			return sh;
	}
	/* Create a new shdr */
	sh = newElfShdr(off);
	return sh;
}

static void
elf64phdr(ElfPhdr *e)
{
	LPUT(e->type);
	LPUT(e->flags);
	VPUT(e->off);
	VPUT(e->vaddr);
	VPUT(e->paddr);
	VPUT(e->filesz);
	VPUT(e->memsz);
	VPUT(e->align);
}

static void
elf32phdr(ElfPhdr *e)
{
	LPUT(e->type);
	LPUT((uint32)e->off);
	LPUT((uint32)e->vaddr);
	LPUT((uint32)e->paddr);
	LPUT((uint32)e->filesz);
	LPUT((uint32)e->memsz);
	LPUT(e->flags);
	LPUT((uint32)e->align);
}

static void
elf64shdr(ElfShdr *e)
{
	LPUT(e->name);
	LPUT(e->type);
	VPUT(e->flags);
	VPUT(e->addr);
	VPUT(e->off);
	VPUT(e->size);
	LPUT(e->link);
	LPUT(e->info);
	VPUT(e->addralign);
	VPUT(e->entsize);
}

static void
elf32shdr(ElfShdr *e)
{
	LPUT(e->name);
	LPUT(e->type);
	LPUT((uint32)e->flags);
	LPUT((uint32)e->addr);
	LPUT((uint32)e->off);
	LPUT((uint32)e->size);
	LPUT(e->link);
	LPUT(e->info);
	LPUT((uint32)e->addralign);
	LPUT((uint32)e->entsize);
}

static uint32
elf64writehdr(void)
{
	int i;

	for(i = 0; i < EI_NIDENT; i++)
		cput(hdr.ident[i]);
	WPUT(hdr.type);
	WPUT(hdr.machine);
	LPUT(hdr.version);
	VPUT(hdr.entry);
	VPUT(hdr.phoff);
	VPUT(hdr.shoff);
	LPUT(hdr.flags);
	WPUT(hdr.ehsize);
	WPUT(hdr.phentsize);
	WPUT(hdr.phnum);
	WPUT(hdr.shentsize);
	WPUT(hdr.shnum);
	WPUT(hdr.shstrndx);
	return ELF64HDRSIZE;
}

static uint32
elf32writehdr(void)
{
	int i;

	for(i = 0; i < EI_NIDENT; i++)
		cput(hdr.ident[i]);
	WPUT(hdr.type);
	WPUT(hdr.machine);
	LPUT(hdr.version);
	LPUT((uint32)hdr.entry);
	LPUT((uint32)hdr.phoff);
	LPUT((uint32)hdr.shoff);
	LPUT(hdr.flags);
	WPUT(hdr.ehsize);
	WPUT(hdr.phentsize);
	WPUT(hdr.phnum);
	WPUT(hdr.shentsize);
	WPUT(hdr.shnum);
	WPUT(hdr.shstrndx);
	return ELF32HDRSIZE;
}

uint32
elfwritehdr(void)
{
	if(elf64)
		return elf64writehdr();
	return elf32writehdr();
}

uint32
elfwritephdrs(void)
{
	int i;

	if(elf64) {
		for(i = 0; i < hdr.phnum; i++)
			elf64phdr(phdr[i]);
		return hdr.phnum * ELF64PHDRSIZE;
	}
	for(i = 0; i < hdr.phnum; i++)
		elf32phdr(phdr[i]);
	return hdr.phnum * ELF32PHDRSIZE;
}

uint32
elfwriteshdrs(void)
{
	int i;

	if(elf64) {
		for(i = 0; i < hdr.shnum; i++)
			elf64shdr(shdr[i]);
		return hdr.shnum * ELF64SHDRSIZE;
	}
	for(i = 0; i < hdr.shnum; i++)
		elf32shdr(shdr[i]);
	return hdr.shnum * ELF32SHDRSIZE;
}

uint32
elfwritestrtab(void)
{
	strnput(elfstrtab, elfstrtabsz);
	cflush();
	return elfstrtabsz;
}
