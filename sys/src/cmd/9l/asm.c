#include	"l.h"

#define	PADDR(a)	((ulong)(a) & ~0xF0000000UL)

#define	LPUT(c)\
	{\
		cbp[0] = (c)>>24;\
		cbp[1] = (c)>>16;\
		cbp[2] = (c)>>8;\
		cbp[3] = (c);\
		cbp += 4;\
		cbc -= 4;\
		if(cbc <= 0)\
			cflush();\
	}

#define	CPUT(c)\
	{\
		cbp[0] = (c);\
		cbp++;\
		cbc--;\
		if(cbc <= 0)\
			cflush();\
	}

void	strnput(char*, int);

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
	if(dlm && s->type == SDATA)
		return s->value+INITDAT;
	if(s->type != STEXT && s->type != SLEAF)
		diag("entry not text: %s", s->name);
	return s->value;
}

void
asmb(void)
{
	Prog *p;
	long t, magic;
	Optab *o;
	vlong vl;

	if(debug['v'])
		Bprint(&bso, "%5.2f asm\n", cputime());
	Bflush(&bso);
	seek(cout, HEADR, 0);
	pc = INITTEXT;
//fprint(2, "pc=%llux INITTEXT=%llux\n",pc, INITTEXT);
	for(p = firstp; p != P; p = p->link) {
		if(p->as == ATEXT) {
			curtext = p;
			autosize = p->to.offset + 8;
			if(p->from3.type == D_CONST) {
				for(; pc < p->pc; pc++)
					CPUT(0);
			}
		}
		if(p->pc != pc) {
			diag("phase error %llux sb %llux",
				p->pc, pc);
			if(!debug['a'])
				prasm(curp);
			pc = p->pc;
		}
		curp = p;
		o = oplook(p);	/* could probably avoid this call */
		if(asmout(p, o, 0)) {
			p = p->link;
			pc += 4;
		}
		pc += o->size;
	}
	if(debug['a'])
		Bprint(&bso, "\n");
	Bflush(&bso);
	cflush();

	curtext = P;
	switch(HEADTYPE) {
	case 0:
	case 1:
	case 2:
	case 5:
	case 6:
		seek(cout, HEADR+textsize, 0);
		break;
	case 3:
		seek(cout, rnd(HEADR+textsize, 4), 0);
		break;
	}

	if(dlm){
		char buf[8];

		write(cout, buf, INITDAT-textsize);
		textsize = INITDAT;
	}

	for(t = 0; t < datsize; t += sizeof(buf)-100) {
		if(datsize-t > sizeof(buf)-100)
			datblk(t, sizeof(buf)-100);
		else
			datblk(t, datsize-t);
	}

	symsize = 0;
	lcsize = 0;
	if(!debug['s']) {
		if(debug['v'])
			Bprint(&bso, "%5.2f sym\n", cputime());
		Bflush(&bso);
		switch(HEADTYPE) {
		case 0:
		case 1:
		case 2:
		case 5:
		case 6:
			seek(cout, HEADR+textsize+datsize, 0);
			break;
		case 3:
			seek(cout, rnd(HEADR+textsize, 4)+datsize, 0);
			break;
		}
		if(!debug['s'])
			asmsym();
		if(debug['v'])
			Bprint(&bso, "%5.2f sp\n", cputime());
		Bflush(&bso);
		if(!debug['s'])
			asmlc();
		if(dlm)
			asmdyn();
		if(HEADTYPE == 0 || HEADTYPE == 1)	/* round up file length for boot image */
			if((symsize+lcsize) & 1)
				CPUT(0);
		cflush();
	}
	else if(dlm){
		asmdyn();
		cflush();
	}

	seek(cout, 0L, 0);
	switch(HEADTYPE) {
	case 0:
		lput(0x1030107);		/* magic and sections */
		lput(textsize);			/* sizes */
		lput(datsize);
		lput(bsssize);
		lput(symsize);			/* nsyms */
		lput(entryvalue());		/* va of entry */
		lput(0L);
		lput(lcsize);
		break;
	case 1:
		if(dlm)
			lput(0x80000000 | (4*21*21+7));		/* q.out magic */
		else
			lput(4*21*21+7);	/* q.out magic */
		lput(textsize);			/* sizes */
		lput(datsize);
		lput(bsssize);
		lput(symsize);			/* nsyms */
		lput(entryvalue());		/* va of entry */
		lput(0L);
		lput(lcsize);
		break;
	case 2:	/* plan9 */
		magic = 4*27*27+7;
		magic |= 0x00008000;		/* fat header */
		if(dlm)
			magic |= 0x80000000;	/* dlm */
		lput(magic);
		lput(textsize);			/* sizes */
		lput(datsize);
		lput(bsssize);
		lput(symsize);			/* nsyms */
		vl = entryvalue();
		lput(PADDR(vl));		/* va of entry (real mode on boot) */
		lput(0L);
		lput(lcsize);
		llput(vl);		/* va of entry */
		break;
	case 3:
		break;
	case 5:
	case 6:
		strnput("\177ELF", 4);		/* e_ident */
		CPUT(2);			/* class = 64 bit */
		CPUT(2);			/* data = MSB */
		CPUT(1);			/* version = CURRENT */
		strnput("", 9);
		lput((2L<<16)|21L);		/* type = EXEC; machine = PowerPC64 */
		lput(1L);			/* version = CURRENT */
		llput(entryvalue());	/* entry vaddr */
		llput(0x40L);			/* offset to first phdr */

		if(debug['S']){
			llput(HEADR+textsize+datsize+symsize);	/* offset to first shdr */
			lput(0L);		/* flags = PPC */
			lput((0x40L<<16)|0x38L);	/* Ehdr & Phdr sizes*/
			lput((3L<<16)|0x40L);	/* # Phdrs & Shdr size */
			lput((3L<<16)|2L);	/* # Shdrs & shdr string size */
		} else {
			llput(0L);			/* offset to first shdr */
			lput(0L);			/* flags = PPC */
			lput((0x40L<<16)|0x38L);	/* Ehdr & Phdr sizes*/
			if(HEADTYPE == 5)
				lput((3L<<16)|0L);	/* # Phdrs & Shdr size */
			else
				lput((2L<<16)|0L);	/* # Phdrs & Shdr size */
			lput((0L<<16)|0L);		/* # Shdrs & shdr string size */
		}

		if(HEADTYPE == 5){
			lput(1L);			/* text - type = PT_LOAD */
			lput(0x05L);			/* protections = RX */
			llput(HEADR);			/* file offset */
			llput(INITTEXT);	/* vaddr */
			llput(INITTEXT);			/* paddr */
			llput(textsize);			/* file size */
			llput(textsize);			/* memory size */
			llput(0x10000L);			/* alignment */
	
			lput(1L);			/* data - type = PT_LOAD */
			lput(0x07L);			/* protections = RWX */
			llput(HEADR+textsize);		/* file offset */
			llput(INITDAT);		/* vaddr */
			llput(INITDAT);			/* paddr */
			llput(datsize);			/* file size */
			llput(datsize);			/* memory size */
			llput(0x10000L);			/* alignment */
		} else {
			lput(1L);			/* text + data - type = PT_LOAD */
			lput(0x07L);			/* protections = RWX */
			llput(HEADR);			/* file offset */
			/*
			 * linux kexec shits the bed with high physical segments.
			 * These are not actually used, so we just grumble and comply.
			 * /
			llput(INITTEXT&0xFFFFFFFF);	/* vaddr */
			llput(INITTEXT&0xFFFFFFFF);	/* paddr */
			llput(textsize+datsize);	/* file size */
			llput(textsize+datsize);	/* memory size */
			llput(0x100000L);		/* alignment */
		}

		lput(0L);			/* data - type = PT_NULL */
		lput(0x04L);			/* protections = R */
		llput(HEADR+textsize+datsize);	/* file offset */
		llput(0L);
		llput(0L);
		llput(symsize);			/* symbol table size */
		llput(lcsize);			/* line number size */
		llput(0x04L);			/* alignment code?? */
		cflush();

		if(!debug['S'])
			break;

		seek(cout, HEADR+textsize+datsize+symsize, 0);
		lput(1);			/* Section name (string tbl index) */
		lput(1);			/* Section type */
		llput(2|4);			/* Section flags */
		llput(INITTEXT);	/* Section virtual addr at execution */
		llput(HEADR);			/* Section file offset */
		llput(textsize);			/* Section size in bytes */
		lput(0);			/* Link to another section */
		lput(0);			/* Additional section information */
		llput(0x10000L);			/* Section alignment */
		llput(0);			/* Entry size if section holds table */

		lput(7);			/* Section name (string tbl index) */
		lput(1);			/* Section type */
		llput(2|1);			/* Section flags */
		llput(INITDAT);		/* Section virtual addr at execution */
		llput(HEADR+textsize);		/* Section file offset */
		llput(datsize);			/* Section size in bytes */
		lput(0);			/* Link to another section */
		lput(0);			/* Additional section information */
		llput(0x10000L);			/* Section alignment */
		llput(0);			/* Entry size if section holds table */

		/* string section header */
		lput(12);			/* Section name (string tbl index) */
		lput(3);			/* Section type */
		llput(1 << 5);			/* Section flags */
		llput(0);			/* Section virtual addr at execution */
		llput(HEADR+textsize+datsize+symsize+3*40);	/* Section file offset */
		llput(14);			/* Section size in bytes */
		lput(0);			/* Link to another section */
		lput(0);			/* Additional section information */
		llput(1);			/* Section alignment */
		llput(0);			/* Entry size if section holds table */

		/* string table */
		cput(0);
		strnput(".text", 5);
		cput(0);
		strnput(".data", 5);
		cput(0);
		strnput(".strtab", 7);
		cput(0);
		cput(0);

		break;
	}
	cflush();
}

void
strnput(char *s, int n)
{
	for(; *s; s++){
		CPUT(*s);
		n--;
	}
	for(; n > 0; n--)
		CPUT(0);
}

void
cput(long l)
{
	CPUT(l);
}

void
wput(long l)
{
	cbp[0] = l>>8;
	cbp[1] = l;
	cbp += 2;
	cbc -= 2;
	if(cbc <= 0)
		cflush();
}

void
llput(vlong v)
{
	lput(v>>32);
	lput(v);
}

void
lput(long l)
{

	LPUT(l);
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
asmsym(void)
{
	Prog *p;
	Auto *a;
	Sym *s;
	int h;

	s = lookup("etext", 0);
	if(s->type == STEXT)
		putsymb(s->name, 'T', s->value, s->version);

	for(h=0; h<NHASH; h++)
		for(s=hash[h]; s!=S; s=s->link)
			switch(s->type) {
			case SCONST:
				putsymb(s->name, 'D', s->value, s->version);
				continue;

			case SDATA:
				putsymb(s->name, 'D', s->value+INITDAT, s->version);
				continue;

			case SBSS:
				putsymb(s->name, 'B', s->value+INITDAT, s->version);
				continue;

			case SFILE:
				putsymb(s->name, 'f', s->value, s->version);
				continue;
			}

	for(p=textp; p!=P; p=p->cond) {
		s = p->from.sym;
		if(s->type != STEXT && s->type != SLEAF)
			continue;

		/* filenames first */
		for(a=p->to.autom; a; a=a->link)
			if(a->type == D_FILE)
				putsymb(a->sym->name, 'z', a->aoffset, 0);
			else
			if(a->type == D_FILE1)
				putsymb(a->sym->name, 'Z', a->aoffset, 0);

		if(s->type == STEXT)
			putsymb(s->name, 'T', s->value, s->version);
		else
			putsymb(s->name, 'L', s->value, s->version);

		/* frame, auto and param after */
		putsymb(".frame", 'm', p->to.offset+8, 0);
		for(a=p->to.autom; a; a=a->link)
			if(a->type == D_AUTO)
				putsymb(a->sym->name, 'a', -a->aoffset, 0);
			else
			if(a->type == D_PARAM)
				putsymb(a->sym->name, 'p', a->aoffset, 0);
	}
	if(debug['v'] || debug['n'])
		Bprint(&bso, "symsize = %lud\n", symsize);
	Bflush(&bso);
}

void
putsymb(char *s, int t, vlong v, int ver)
{
	int i, f;
	long l;

	if(t == 'f')
		s++;
	if(HEADTYPE == 2){
		l = v>>32;
		LPUT(l);
	}
	l = v;
	LPUT(l);
	if(ver)
		t += 'a' - 'A';
	CPUT(t+0x80);			/* 0x80 is variable length */

	if(t == 'Z' || t == 'z') {
		CPUT(s[0]);
		for(i=1; s[i] != 0 || s[i+1] != 0; i += 2) {
			CPUT(s[i]);
			CPUT(s[i+1]);
		}
		CPUT(0);
		CPUT(0);
		i++;
	}
	else {
		for(i=0; s[i]; i++)
			CPUT(s[i]);
		CPUT(0);
	}
	symsize += 4 + 1 + i + 1;
	if(HEADTYPE == 2)
		symsize += 4;

	if(debug['n']) {
		if(t == 'z' || t == 'Z') {
			Bprint(&bso, "%c %.8llux ", t, v);
			for(i=1; s[i] != 0 || s[i+1] != 0; i+=2) {
				f = ((s[i]&0xff) << 8) | (s[i+1]&0xff);
				Bprint(&bso, "/%x", f);
			}
			Bprint(&bso, "\n");
			return;
		}
		if(ver)
			Bprint(&bso, "%c %.8llux %s<%d>\n", t, v, s, ver);
		else
			Bprint(&bso, "%c %.8llux %s\n", t, v, s);
	}
}

#define	MINLC	4
void
asmlc(void)
{
	vlong oldpc, oldlc;
	Prog *p;
	long v, s;

	oldpc = INITTEXT;
	oldlc = 0;
	for(p = firstp; p != P; p = p->link) {
		if(p->line == oldlc || p->as == ATEXT || p->as == ANOP) {
			if(p->as == ATEXT)
				curtext = p;
			if(debug['L'])
				Bprint(&bso, "%6llux %P\n",
					p->pc, p);
			continue;
		}
		if(debug['L'])
			Bprint(&bso, "\t\t%6ld", lcsize);
		v = (p->pc - oldpc) / MINLC;
		while(v) {
			s = 127;
			if(v < 127)
				s = v;
			CPUT(s+128);	/* 129-255 +pc */
			if(debug['L'])
				Bprint(&bso, " pc+%ld*%d(%ld)", s, MINLC, s+128);
			v -= s;
			lcsize++;
		}
		s = p->line - oldlc;
		oldlc = p->line;
		oldpc = p->pc + MINLC;
		if(s > 64 || s < -64) {
			CPUT(0);	/* 0 vv +lc */
			CPUT(s>>24);
			CPUT(s>>16);
			CPUT(s>>8);
			CPUT(s);
			if(debug['L']) {
				if(s > 0)
					Bprint(&bso, " lc+%ld(%d,%ld)\n",
						s, 0, s);
				else
					Bprint(&bso, " lc%ld(%d,%ld)\n",
						s, 0, s);
				Bprint(&bso, "%6llux %P\n",
					p->pc, p);
			}
			lcsize += 5;
			continue;
		}
		if(s > 0) {
			CPUT(0+s);	/* 1-64 +lc */
			if(debug['L']) {
				Bprint(&bso, " lc+%ld(%ld)\n", s, 0+s);
				Bprint(&bso, "%6llux %P\n",
					p->pc, p);
			}
		} else {
			CPUT(64-s);	/* 65-128 -lc */
			if(debug['L']) {
				Bprint(&bso, " lc%ld(%ld)\n", s, 64-s);
				Bprint(&bso, "%6llux %P\n",
					p->pc, p);
			}
		}
		lcsize++;
	}
	while(lcsize & 1) {
		s = 129;
		CPUT(s);
		lcsize++;
	}
	if(debug['v'] || debug['L'])
		Bprint(&bso, "lcsize = %ld\n", lcsize);
	Bflush(&bso);
}

void
datblk(long s, long n)
{
	Prog *p;
	uchar *cast;
	long l, fl, j;
	vlong d;
	int i, c;

	memset(buf.dbuf, 0, n+100);
	for(p = datap; p != P; p = p->link) {
		curp = p;
		l = p->from.sym->value + p->from.offset - s;
		c = p->reg;
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
		if(p->as != AINIT && p->as != ADYNT) {
			for(j=l+(c-i)-1; j>=l; j--)
				if(buf.dbuf[j]) {
					print("%P\n", p);
					diag("multiple initialization");
					break;
				}
		}
		switch(p->to.type) {
		default:
			diag("unknown mode in initialization\n%P", p);
			break;

		case D_FCONST:
			switch(c) {
			default:
			case 4:
				fl = ieeedtof(&p->to.ieee);
				cast = (uchar*)&fl;
				for(; i<c; i++) {
					buf.dbuf[l] = cast[fnuxi8[i+4]];
					l++;
				}
				break;
			case 8:
				cast = (uchar*)&p->to.ieee;
				for(; i<c; i++) {
					buf.dbuf[l] = cast[fnuxi8[i]];
					l++;
				}
				break;
			}
			break;

		case D_SCONST:
			for(; i<c; i++) {
				buf.dbuf[l] = p->to.sval[i];
				l++;
			}
			break;

		case D_CONST:
			d = p->to.offset;
			if(p->to.sym) {
				if(p->to.sym->type == SUNDEF){	/* TO DO: simplify */
					ckoff(p->to.sym, d);
					d += p->to.sym->value;
				}
				if(p->to.sym->type == STEXT ||
				   p->to.sym->type == SLEAF)
					d += p->to.sym->value;
				if(p->to.sym->type == SDATA)
					d += p->to.sym->value + INITDAT;
				if(p->to.sym->type == SBSS)
					d += p->to.sym->value + INITDAT;
				if(dlm)
					dynreloc(p->to.sym, l+s+INITDAT, 1, 0, 0);
			}
			fl = d;
			cast = (uchar*)&fl;
			switch(c) {
			default:
				diag("bad nuxi %d %d\n%P", c, i, curp);
				break;
			case 1:
				for(; i<c; i++) {
					buf.dbuf[l] = cast[inuxi1[i]];
					l++;
				}
				break;
			case 2:
				for(; i<c; i++) {
					buf.dbuf[l] = cast[inuxi2[i]];
					l++;
				}
				break;
			case 4:
				for(; i<c; i++) {
					buf.dbuf[l] = cast[inuxi4[i]];
					l++;
				}
				break;
			case 8:
				cast = (uchar*)&d;
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
