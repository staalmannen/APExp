#include	"l.h"
#include	"../ld/dwarf.h"

#define	Dbufslop	100

/* Write one 40-byte ELF32 section header (little-endian).
 * Parameter named 'foff' (file offset) to avoid collision with
 * l.h's #define offset u0.u0offset. */
static void
elf32shdr(long sh_name, long sh_type, long sh_flags, long sh_addr,
          long foff, long sh_size, long sh_link, long sh_info,
          long sh_align, long sh_entsize)
{
	lputl(sh_name);
	lputl(sh_type);
	lputl(sh_flags);
	lputl(sh_addr);
	lputl(foff);
	lputl(sh_size);
	lputl(sh_link);
	lputl(sh_info);
	lputl(sh_align);
	lputl(sh_entsize);
}

#define PADDR(a)	((a) & ~0xfffffffff0000000ull)

vlong
entryvalue(void)
{
	char *a;
	Sym *s;

	a = INITENTRY;
	if(*a >= '0' && *a <= '9')
		return atolwhex(a);
	s = lookup(a, 0);
	if(s->type == 0)
		return INITTEXT;
	switch(s->type) {
	case STEXT:
		break;
	case SDATA:
		if(dlm)
			return s->value+INITDAT;
	default:
		diag("entry not text: %s", s->name);
	}
	return s->value;
}

void
wputl(ushort w)
{
	cput(w);
	cput(w>>8);
}

void
wput(ushort w)
{
	cput(w>>8);
	cput(w);
}

void
lput(long l)
{
	cput(l>>24);
	cput(l>>16);
	cput(l>>8);
	cput(l);
}

void
llput(vlong v)
{
	lput(v>>32);
	lput(v);
}

void
lputl(long l)
{
	cput(l);
	cput(l>>8);
	cput(l>>16);
	cput(l>>24);
}

void
strnput(char *s, int n)
{
	for(; *s && n > 0; s++){
		cput(*s);
		n--;
	}
	while(n > 0){
		cput(0);
		n--;
	}
}

void
asmb(void)
{
	Prog *p;
	long v, magic;
	int a;
	uchar *op1;
	vlong vl;
	/* ELF section header table info, filled in when emitting DWARF. */
	long elf_shoff = 0, elf_shnum = 0, elf_shstrndx = 0;

	if(debug['v'])
		Bprint(&bso, "%5.2f asmb\n", cputime());
	Bflush(&bso);

	seek(cout, HEADR, 0);
	pc = INITTEXT;
	curp = firstp;
	for(p = firstp; p != P; p = p->link) {
		if(p->as == ATEXT)
			curtext = p;
		if(p->pc != pc) {
			if(!debug['a'])
				print("%P\n", curp);
			diag("phase error %llux sb %llux in %s", p->pc, pc, TNAME);
			pc = p->pc;
		}
		curp = p;
		asmins(p);
		a = (andptr - and);
		if(cbc < a)
			cflush();
		if(debug['a']) {
			Bprint(&bso, pcstr, pc);
			for(op1 = and; op1 < andptr; op1++)
				Bprint(&bso, "%.2ux", *op1 & 0xff);
			Bprint(&bso, "\t%P\n", curp);
		}
		if(dlm) {
			if(p->as == ATEXT)
				reloca = nil;
			else if(reloca != nil)
				diag("reloc failure: %P", curp);
		}
		memmove(cbp, and, a);
		cbp += a;
		pc += a;
		cbc -= a;
	}
	cflush();
	switch(HEADTYPE) {
	default:
		diag("unknown header type %ld", HEADTYPE);
	case 2:
	case 3:
	case 5:
		seek(cout, HEADR+textsize, 0);
		break;
	}

	if(debug['v'])
		Bprint(&bso, "%5.2f datblk\n", cputime());
	Bflush(&bso);

	if(dlm){
		char buf[8];

		write(cout, buf, INITDAT-textsize);
		textsize = INITDAT;
	}

	for(v = 0; v < datsize; v += sizeof(buf)-Dbufslop) {
		if(datsize-v > sizeof(buf)-Dbufslop)
			datblk(v, sizeof(buf)-Dbufslop);
		else
			datblk(v, datsize-v);
	}

	symsize = 0;
	spsize = 0;
	lcsize = 0;
	if(!debug['s']) {
		if(debug['v'])
			Bprint(&bso, "%5.2f sym\n", cputime());
		Bflush(&bso);
		switch(HEADTYPE) {
		default:
		case 2:
		case 3:
		case 5:
			seek(cout, HEADR+textsize+datsize, 0);
			break;
		}
		if(!debug['s'])
			asmsym();
		if(debug['v'])
			Bprint(&bso, "%5.2f sp\n", cputime());
		Bflush(&bso);
		if(debug['v'])
			Bprint(&bso, "%5.2f pc\n", cputime());
		Bflush(&bso);
		if(!debug['s'])
			asmlc();
		if(dlm)
			asmdyn();
		cflush();
	}
	else if(dlm){
		seek(cout, HEADR+textsize+datsize, 0);
		asmdyn();
		cflush();
	}

	/* For ELF output, append DWARF debug sections and build section header table. */
	if(HEADTYPE == 5) {
		/*
		 * .shstrtab — section name strings with embedded NULs.
		 * Written piecewise because strnput stops at the first NUL.
		 * Byte offsets (for sh_name fields):
		 *   0  ""              (SHT_NULL entry has empty name)
		 *   1  ".text"
		 *   7  ".data"
		 *  13  ".debug_abbrev"
		 *  27  ".debug_line"
		 *  39  ".debug_frame"
		 *  52  ".debug_info"
		 *  64  ".shstrtab"
		 * Total: 74 bytes
		 */
		enum { SHSTRTABSZ = 74 };
		DwarfSects ds;
		vlong shstroff, shoff;

		dwarfemitdebugsections(&ds);
		cflush();

		/* .shstrtab */
		shstroff = cpos();
		cput(0);                        /*  0: empty name for SHT_NULL */
		strnput(".text",         6);    /*  1 */
		strnput(".data",         6);    /*  7 */
		strnput(".debug_abbrev", 14);   /* 13 */
		strnput(".debug_line",   12);   /* 27 */
		strnput(".debug_frame",  13);   /* 39 */
		strnput(".debug_info",   12);   /* 52 */
		strnput(".shstrtab",     10);   /* 64 */
		cflush();

		/* section header table (8 × 40-byte ELF32 Shdr entries) */
		shoff = cpos();
		elf32shdr(0,   0, 0, 0,                  0,                    0,               0, 0, 0,  0);
		elf32shdr(1,   1, 6, PADDR(INITTEXT),    HEADR,                (long)textsize,  0, 0, 16, 0); /* .text */
		elf32shdr(7,   1, 3, PADDR(INITDAT),     HEADR+(long)textsize, (long)datsize,   0, 0, 8,  0); /* .data */
		elf32shdr(13,  1, 0, 0, (long)ds.abbrev_off, (long)ds.abbrev_sz, 0, 0, 1, 0); /* .debug_abbrev */
		elf32shdr(27,  1, 0, 0, (long)ds.line_off,   (long)ds.line_sz,   0, 0, 1, 0); /* .debug_line */
		elf32shdr(39,  1, 0, 0, (long)ds.frame_off,  (long)ds.frame_sz,  0, 0, 8, 0); /* .debug_frame */
		elf32shdr(52,  1, 0, 0, (long)ds.info_off,   (long)ds.info_sz,   0, 0, 1, 0); /* .debug_info */
		elf32shdr(64,  3, 0, 0, (long)shstroff,       SHSTRTABSZ,         0, 0, 1, 0); /* .shstrtab */
		cflush();

		elf_shoff    = (long)shoff;
		elf_shnum    = 8;
		elf_shstrndx = 7;
	}

	if(debug['v'])
		Bprint(&bso, "%5.2f headr\n", cputime());
	Bflush(&bso);
	seek(cout, 0L, 0);
	switch(HEADTYPE) {
	default:
	case 2:	/* plan9 */
		magic = 4*26*26+7;
		magic |= 0x00008000;		/* fat header */
		if(dlm)
			magic |= 0x80000000;	/* dlm */
		lput(magic);			/* magic */
		lput(textsize);			/* sizes */
		lput(datsize);
		lput(bsssize);
		lput(symsize);			/* nsyms */
		vl = entryvalue();
		lput(PADDR(vl));		/* va of entry */
		lput(spsize);			/* sp offsets */
		lput(lcsize);			/* line offsets */
		llput(vl);			/* va of entry */
		break;
	case 3:	/* plan9 */
		magic = 4*26*26+7;
		if(dlm)
			magic |= 0x80000000;
		lput(magic);			/* magic */
		lput(textsize);			/* sizes */
		lput(datsize);
		lput(bsssize);
		lput(symsize);			/* nsyms */
		lput(entryvalue());		/* va of entry */
		lput(spsize);			/* sp offsets */
		lput(lcsize);			/* line offsets */
		break;
	case 5:
		strnput("\177ELF", 4);		/* e_ident */
		cput(1);			/* class = 32 bit */
		cput(1);			/* data = LSB */
		cput(1);			/* version = CURRENT */
		strnput("", 9);
		wputl(2);			/* type = EXEC */
		if(debug['8'])
			wputl(3);		/* machine = 386 */
		else
			wputl(62);		/* machine = AMD64 */
		lputl(1L);			/* version = CURRENT */
		lputl(PADDR(entryvalue()));	/* entry vaddr */
		lputl(52L);			/* offset to first phdr */
		lputl(elf_shoff);		/* offset to first shdr */
		lputl(0L);			/* processor specific flags */
		wputl(52);			/* Ehdr size */
		wputl(32);			/* Phdr size */
		wputl(3);			/* # of Phdrs */
		wputl(elf_shnum ? 40 : 0);	/* Shdr entry size */
		wputl(elf_shnum);		/* # of Shdrs */
		wputl(elf_shstrndx);		/* .shstrtab section index */

		lputl(1L);			/* text - type = PT_LOAD */
		lputl(HEADR);			/* file offset */
		lputl(INITTEXT);		/* vaddr */
		lputl(PADDR(INITTEXT));		/* paddr */
		lputl(textsize);		/* file size */
		lputl(textsize);		/* memory size */
		lputl(0x05L);			/* protections = RX */
		lputl(INITRND);			/* alignment */

		lputl(1L);			/* data - type = PT_LOAD */
		lputl(HEADR+textsize);		/* file offset */
		lputl(INITDAT);			/* vaddr */
		lputl(PADDR(INITDAT));		/* paddr */
		lputl(datsize);			/* file size */
		lputl(datsize+bsssize);		/* memory size */
		lputl(0x06L);			/* protections = RW */
		lputl(INITRND);			/* alignment */

		lputl(0L);			/* symbols - type = PT_NULL */
		lputl(HEADR+textsize+datsize);	/* file offset */
		lputl(0L);
		lputl(0L);
		lputl(symsize);			/* symbol table size */
		lputl(lcsize);			/* line number size */
		lputl(0x04L);			/* protections = R */
		lputl(0x04L);			/* alignment */
		break;
	}
	cflush();
}

void
cflush(void)
{
	int n;

	n = sizeof(buf.cbuf) - cbc;
	if(n)
		write(cout, buf.cbuf, n);
	cbp = buf.cbuf;
	cbc = sizeof(buf.cbuf);
}

void
datblk(long s, long n)
{
	Prog *p;
	uchar *cast;
	long l, fl, j;
	vlong o;
	int i, c;

	memset(buf.dbuf, 0, n+Dbufslop);
	for(p = datap; p != P; p = p->link) {
		curp = p;
		l = p->from.sym->value + p->from.offset - s;
		c = p->from.scale;
		i = 0;
		if(l < 0) {
			if(l+c <= 0)
				continue;
			while(l < 0) {
				l++;
				i++;
			}
		}
		if(l >= n)
			continue;
		if(p->as != AINIT && p->as != ADYNT && !p->from.sym->dupok) {
			for(j=l+(c-i)-1; j>=l; j--)
				if(buf.dbuf[j]) {
					print("%P\n", p);
					diag("multiple initialization");
					break;
				}
		}
		switch(p->to.type) {
		case D_FCONST:
			switch(c) {
			default:
			case 4:
				fl = ieeedtof(&p->to.ieee);
				cast = (uchar*)&fl;
				if(debug['a'] && i == 0) {
					Bprint(&bso, pcstr, l+s+INITDAT);
					for(j=0; j<c; j++)
						Bprint(&bso, "%.2ux", cast[fnuxi4[j]]);
					Bprint(&bso, "\t%P\n", curp);
				}
				for(; i<c; i++) {
					buf.dbuf[l] = cast[fnuxi4[i]];
					l++;
				}
				break;
			case 8:
				cast = (uchar*)&p->to.ieee;
				if(debug['a'] && i == 0) {
					Bprint(&bso, pcstr, l+s+INITDAT);
					for(j=0; j<c; j++)
						Bprint(&bso, "%.2ux", cast[fnuxi8[j]]);
					Bprint(&bso, "\t%P\n", curp);
				}
				for(; i<c; i++) {
					buf.dbuf[l] = cast[fnuxi8[i]];
					l++;
				}
				break;
			}
			break;

		case D_SCONST:
			if(debug['a'] && i == 0) {
				Bprint(&bso, pcstr, l+s+INITDAT);
				for(j=0; j<c; j++)
					Bprint(&bso, "%.2ux", p->to.scon[j] & 0xff);
				Bprint(&bso, "\t%P\n", curp);
			}
			for(; i<c; i++) {
				buf.dbuf[l] = p->to.scon[i];
				l++;
			}
			break;
		default:
			o = p->to.offset;
			if(p->to.type == D_ADDR) {
				if(p->to.index != D_STATIC && p->to.index != D_EXTERN)
					diag("DADDR type%P", p);
				if(p->to.sym) {
					if(p->to.sym->type == SUNDEF)
						ckoff(p->to.sym, o);
					o += p->to.sym->value;
					if(p->to.sym->type != STEXT && p->to.sym->type != SUNDEF)
						o += INITDAT;
					if(dlm)
						dynreloc(p->to.sym, l+s+INITDAT, 1);
				}
			}
			fl = o;
			cast = (uchar*)&fl;
			switch(c) {
			default:
				diag("bad nuxi %d %d\n%P", c, i, curp);
				break;
			case 1:
				if(debug['a'] && i == 0) {
					Bprint(&bso, pcstr, l+s+INITDAT);
					for(j=0; j<c; j++)
						Bprint(&bso, "%.2ux", cast[inuxi1[j]]);
					Bprint(&bso, "\t%P\n", curp);
				}
				for(; i<c; i++) {
					buf.dbuf[l] = cast[inuxi1[i]];
					l++;
				}
				break;
			case 2:
				if(debug['a'] && i == 0) {
					Bprint(&bso, pcstr, l+s+INITDAT);
					for(j=0; j<c; j++)
						Bprint(&bso, "%.2ux", cast[inuxi2[j]]);
					Bprint(&bso, "\t%P\n", curp);
				}
				for(; i<c; i++) {
					buf.dbuf[l] = cast[inuxi2[i]];
					l++;
				}
				break;
			case 4:
				if(debug['a'] && i == 0) {
					Bprint(&bso, pcstr, l+s+INITDAT);
					for(j=0; j<c; j++)
						Bprint(&bso, "%.2ux", cast[inuxi4[j]]);
					Bprint(&bso, "\t%P\n", curp);
				}
				for(; i<c; i++) {
					buf.dbuf[l] = cast[inuxi4[i]];
					l++;
				}
				break;
			case 8:
				cast = (uchar*)&o;
				if(debug['a'] && i == 0) {
					Bprint(&bso, pcstr, l+s+INITDAT);
					for(j=0; j<c; j++)
						Bprint(&bso, "%.2ux", cast[inuxi8[j]]);
					Bprint(&bso, "\t%P\n", curp);
				}
				for(; i<c; i++) {
					buf.dbuf[l] = cast[inuxi8[i]];
					l++;
				}
				break;
			}
			break;
		}
	}
	write(cout, buf.dbuf, n);
}

vlong
rnd(vlong v, vlong r)
{
	vlong c;

	if(r <= 0)
		return v;
	v += r - 1;
	c = v % r;
	if(c < 0)
		c += r;
	v -= c;
	return v;
}
