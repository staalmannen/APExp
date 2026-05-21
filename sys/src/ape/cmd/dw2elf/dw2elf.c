/*
 * dw2elf — convert Plan9 a.out + .dwtypes sidecars to ELF64 with DWARF.
 *
 * Usage: dw2elf [-o output] input.aout [file.dwtypes ...]
 *
 * Reads the Plan9 amd64 a.out fat-header binary and optional .dwtypes
 * type-info sidecars produced by the modified Plan9 C compilers, then
 * emits an ELF64 executable with the same code/data layout plus DWARF
 * debug sections.  The output runs on 9front via its native ELF exec
 * handler and is inspectable with dwarfdump.
 *
 * Plan9 a.out fat header (amd64, HEADTYPE=2, big-endian fields):
 *   [0]  u32  magic      (0x00008a97)
 *   [4]  u32  textsize
 *   [8]  u32  datsize
 *  [12]  u32  bsssize
 *  [16]  u32  symsize
 *  [20]  u32  entry_lo   (PADDR, low 32 bits)
 *  [24]  u32  spsize
 *  [28]  u32  lcsize
 *  [32]  u64  entry      (64-bit virtual entry point)
 * Total header: 40 bytes (HEADR).  INITTEXT = 0x200028, INITRND = 0x200000.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

#include <libdwarf.h>
#include <dwarf.h>
#include <libdwarfp.h>

/* ── Plan9 a.out constants (amd64 fat header) ─────────────────────────── */
#define AOUT_HEADR       40
#define AOUT_INITTEXT    ((uint64_t)0x200028)
#define AOUT_INITRND     ((uint64_t)0x200000)
#define AOUT_FAT_MAGIC   0x00008a97u

/* ── ELF64 constants ───────────────────────────────────────────────────── */
#define ELFCLASS64    2
#define ELFDATA2LSB   1
#define EV_CURRENT    1
#define ET_EXEC       2
#define EM_X86_64     62
#define PT_LOAD       1
#define PF_X          1
#define PF_W          2
#define PF_R          4
#define SHT_NULL      0
#define SHT_PROGBITS  1
#define SHT_NOBITS    8
#define SHT_STRTAB    3
#define SHF_WRITE     1
#define SHF_ALLOC     2
#define SHF_EXECINSTR 4
#define EHDR_SIZE     64
#define PHDR_SIZE     56
#define SHDR_SIZE     64

/* ── Plan9 etype values (APExp cc.h with TBOOL=3 inserted) ────────────── */
#define P9_TVOID    0
#define P9_TCHAR    1
#define P9_TUCHAR   2
#define P9_TBOOL    3
#define P9_TSHORT   4
#define P9_TUSHORT  5
#define P9_TINT     6
#define P9_TUINT    7
#define P9_TLONG    8   /* 32-bit on Plan9 */
#define P9_TULONG   9
#define P9_TVLONG   10  /* 64-bit */
#define P9_TUVLONG  11
#define P9_TFLOAT   12
#define P9_TDOUBLE  13
#define P9_TIND     14  /* pointer — 8 bytes on amd64 */
#define P9_TARRAY   15
#define P9_TSTRUCT  16
#define P9_TUNION   17
#define P9_TFUNC    18

/* ── byte-order helpers ────────────────────────────────────────────────── */

static uint32_t be32r(const uint8_t *p)
{
	return ((uint32_t)p[0]<<24)|((uint32_t)p[1]<<16)|
	       ((uint32_t)p[2]<<8)|p[3];
}
static uint64_t be64r(const uint8_t *p)
{
	return ((uint64_t)be32r(p)<<32)|be32r(p+4);
}
static void le16w(uint8_t *p, uint16_t v)
{ p[0]=(uint8_t)v; p[1]=(uint8_t)(v>>8); }
static void le32w(uint8_t *p, uint32_t v)
{ p[0]=(uint8_t)v; p[1]=(uint8_t)(v>>8); p[2]=(uint8_t)(v>>16); p[3]=(uint8_t)(v>>24); }
static void le64w(uint8_t *p, uint64_t v)
{ le32w(p,(uint32_t)v); le32w(p+4,(uint32_t)(v>>32)); }

/* ── I/O helpers ───────────────────────────────────────────────────────── */

static void xwrite(int fd, const void *buf, size_t n)
{
	if(write(fd, buf, n) != (ssize_t)n) { perror("dw2elf: write"); exit(1); }
}

static uint8_t *loadfile(const char *path, size_t *outlen)
{
	FILE *f;
	uint8_t *buf;
	f = fopen(path, "rb");
	if(!f) { perror(path); exit(1); }
	fseek(f, 0, SEEK_END);
	*outlen = (size_t)ftell(f);
	rewind(f);
	buf = malloc(*outlen ? *outlen : 1);
	if(!buf) { fprintf(stderr, "dw2elf: out of memory\n"); exit(1); }
	fread(buf, 1, *outlen, f);
	fclose(f);
	return buf;
}

/* ── ELF structure writers ─────────────────────────────────────────────── */

static void write_ehdr(int fd, uint64_t entry, uint64_t phoff, uint64_t shoff,
                       uint16_t phnum, uint16_t shnum, uint16_t shstrndx)
{
	uint8_t e[EHDR_SIZE];
	memset(e, 0, EHDR_SIZE);
	e[0]=0x7f; e[1]='E'; e[2]='L'; e[3]='F';
	e[4]=ELFCLASS64; e[5]=ELFDATA2LSB; e[6]=EV_CURRENT;
	le16w(e+16, ET_EXEC);    le16w(e+18, EM_X86_64);
	le32w(e+20, EV_CURRENT); le64w(e+24, entry);
	le64w(e+32, phoff);      le64w(e+40, shoff);
	le16w(e+52, EHDR_SIZE);  le16w(e+54, PHDR_SIZE);
	le16w(e+56, phnum);      le16w(e+58, SHDR_SIZE);
	le16w(e+60, shnum);      le16w(e+62, shstrndx);
	xwrite(fd, e, EHDR_SIZE);
}

static void write_phdr(int fd, uint32_t type, uint32_t flags,
                       uint64_t offset, uint64_t vaddr,
                       uint64_t filesz, uint64_t memsz, uint64_t align)
{
	uint8_t p[PHDR_SIZE];
	memset(p, 0, PHDR_SIZE);
	le32w(p+0, type);  le32w(p+4, flags);
	le64w(p+8, offset); le64w(p+16, vaddr); le64w(p+24, vaddr);
	le64w(p+32, filesz); le64w(p+40, memsz); le64w(p+48, align);
	xwrite(fd, p, PHDR_SIZE);
}

static void write_shdr(int fd, uint32_t name, uint32_t type, uint64_t flags,
                       uint64_t addr, uint64_t offset, uint64_t size,
                       uint32_t link, uint32_t info, uint64_t align,
                       uint64_t entsize)
{
	uint8_t s[SHDR_SIZE];
	memset(s, 0, SHDR_SIZE);
	le32w(s+0, name);  le32w(s+4, type);  le64w(s+8, flags);
	le64w(s+16, addr); le64w(s+24, offset); le64w(s+32, size);
	le32w(s+40, link); le32w(s+44, info);
	le64w(s+48, align); le64w(s+56, entsize);
	xwrite(fd, s, SHDR_SIZE);
}

/* ── .shstrtab builder ─────────────────────────────────────────────────── */
#define STRTAB_MAX 8192
static char  shstrtab_buf[STRTAB_MAX];
static int   shstrtab_len = 1;   /* byte 0 = '\0' for SHN_UNDEF */

static int shstrtab_add(const char *s)
{
	int off = shstrtab_len;
	int n = (int)strlen(s) + 1;
	if(shstrtab_len + n > STRTAB_MAX) {
		fprintf(stderr, "dw2elf: .shstrtab overflow\n"); exit(1);
	}
	memcpy(shstrtab_buf + shstrtab_len, s, n);
	shstrtab_len += n;
	return off;
}

/* ── DWARF producer section table ──────────────────────────────────────── */
#define MAX_DW_SECTS 16
static struct {
	const char *name;
	uint8_t    *data;
	size_t      len;
	uint32_t    elf_idx;   /* assigned by callback */
	int         shname;    /* offset in .shstrtab */
	long        foffset;   /* byte offset in output file */
} dw_sects[MAX_DW_SECTS];
static int n_dw_sects = 0;
static int dw_base_elf_idx;   /* ELF index of first DWARF section */

static int dw_section_callback(
	const char *name, int size,
	Dwarf_Unsigned type, Dwarf_Unsigned flags,
	Dwarf_Unsigned link, Dwarf_Unsigned info,
	Dwarf_Unsigned *sect_name_index,
	void *user_data, int *error)
{
	(void)size; (void)type; (void)flags;
	(void)link; (void)info; (void)user_data;
	if(n_dw_sects >= MAX_DW_SECTS) { *error = 1; return DW_DLV_ERROR; }
	dw_sects[n_dw_sects].name = name;
	dw_sects[n_dw_sects].elf_idx = (uint32_t)(dw_base_elf_idx + n_dw_sects);
	*sect_name_index = dw_sects[n_dw_sects].elf_idx;
	n_dw_sects++;
	return DW_DLV_OK;
}

/* ── .dwtypes sidecar reader ───────────────────────────────────────────── */

static const uint8_t *sc_buf;
static size_t         sc_len;
static size_t         sc_pos;

static uint32_t sc_u32(void)
{
	uint32_t v;
	if(sc_pos + 4 > sc_len) return 0;
	memcpy(&v, sc_buf + sc_pos, 4);
	sc_pos += 4;
	return v;   /* sidecar is written in Plan9 native LE */
}

static uint8_t sc_u8(void)
{
	if(sc_pos >= sc_len) return 0;
	return sc_buf[sc_pos++];
}

/* returns malloc'd string; caller must free */
static char *sc_str(void)
{
	uint32_t n = sc_u32();
	char *s;
	if(n == 0 || sc_pos + n > sc_len) return strdup("?");
	s = malloc(n + 1);
	memcpy(s, sc_buf + sc_pos, n);
	s[n] = 0;
	sc_pos += n;
	return s;
}

static void sc_skip_type(int depth)
{
	uint8_t tag;
	if(depth > 8) return;
	tag = sc_u8();
	switch(tag) {
	case P9_TIND:
		sc_skip_type(depth+1);
		break;
	case P9_TARRAY:
		sc_skip_type(depth+1);
		(void)sc_u32();
		break;
	case P9_TSTRUCT:
	case P9_TUNION:
		{ char *s = sc_str(); free(s); }
		break;
	}
}

/* ── DWARF emission ────────────────────────────────────────────────────── */

static void emit_sidecar(Dwarf_P_Debug dbg, const char *srcname,
                         const uint8_t *buf, size_t len)
{
	Dwarf_P_Die cu_die, func_die, param_die;
	Dwarf_P_Attribute attr_out;
	Dwarf_Error err;
	uint32_t nparams, nlocals, i, j;
	char *fname, *pname;

	sc_buf = buf;
	sc_len = len;
	sc_pos = 8;   /* skip "DWTYPES1" magic */

	if(dwarf_new_die_a(dbg, DW_TAG_compile_unit,
	                   NULL, NULL, NULL, NULL, &cu_die, &err) != DW_DLV_OK)
		return;
	dwarf_add_AT_name_a(cu_die, (char *)srcname, &attr_out, &err);
	if(dwarf_add_die_to_debug_a(dbg, cu_die, &err) != DW_DLV_OK)
		return;

	while(sc_pos < sc_len) {
		fname   = sc_str();
		sc_skip_type(0);    /* return type */
		nparams = sc_u32();

		func_die = NULL;
		if(dwarf_new_die_a(dbg, DW_TAG_subprogram,
		                   cu_die, NULL, NULL, NULL,
		                   &func_die, &err) == DW_DLV_OK)
			dwarf_add_AT_name_a(func_die, fname, &attr_out, &err);

		for(i = 0; i < nparams; i++) {
			pname = sc_str();
			sc_skip_type(0);
			if(func_die) {
				if(dwarf_new_die_a(dbg, DW_TAG_formal_parameter,
				                   func_die, NULL, NULL, NULL,
				                   &param_die, &err) == DW_DLV_OK)
					dwarf_add_AT_name_a(param_die, pname, &attr_out, &err);
			}
			free(pname);
		}

		/* locals (v1: always 0) */
		nlocals = sc_u32();
		for(j = 0; j < nlocals; j++) {
			{ char *s = sc_str(); free(s); }
			(void)sc_u32();   /* stack offset */
			sc_skip_type(0);
		}

		free(fname);
	}
}

/* ── main ──────────────────────────────────────────────────────────────── */

int main(int argc, char *argv[])
{
	const char  *outpath = NULL;
	const char  *inpath  = NULL;
	char       **sidecars;
	int          nsidecars = 0;
	int          i;
	uint8_t     *aout_buf;
	size_t       aout_len;
	uint32_t     magic, textsize, datsize, bsssize;
	uint64_t     entry;
	uint64_t     text_vaddr, data_vaddr;
	long         text_foff, data_foff;
	long         dw_start_foff, shstrtab_foff, shdr_foff;
	long         cur;
	int          ofd;
	uint16_t     shnum, shstrndx;
	int          shn_text, shn_data, shn_bss, shn_shstr;
	uint8_t      zero = 0;

	sidecars = malloc(argc * sizeof(char *));

	for(i = 1; i < argc; i++) {
		if(strcmp(argv[i], "-o") == 0 && i+1 < argc)
			outpath = argv[++i];
		else if(inpath == NULL)
			inpath = argv[i];
		else
			sidecars[nsidecars++] = argv[i];
	}

	if(inpath == NULL) {
		fprintf(stderr,
		  "usage: dw2elf [-o output] input.aout [sidecar.dwtypes ...]\n");
		return 1;
	}

	if(outpath == NULL) {
		/* strip known extension and add .elf */
		char *tmp = malloc(strlen(inpath) + 5);
		char *p;
		strcpy(tmp, inpath);
		p = strrchr(tmp, '.');
		if(p) *p = 0;
		strcat(tmp, ".elf");
		outpath = tmp;
	}

	/* ── read Plan9 a.out ── */
	aout_buf = loadfile(inpath, &aout_len);
	if(aout_len < AOUT_HEADR) {
		fprintf(stderr, "dw2elf: %s: too small\n", inpath); return 1;
	}

	magic    = be32r(aout_buf +  0);
	textsize = be32r(aout_buf +  4);
	datsize  = be32r(aout_buf +  8);
	bsssize  = be32r(aout_buf + 12);
	/* symsize at +16 — not needed */
	entry    = be64r(aout_buf + 32);

	if((magic & 0xffffu) != (AOUT_FAT_MAGIC & 0xffffu)) {
		fprintf(stderr, "dw2elf: %s: bad a.out magic 0x%08x\n",
		        inpath, magic);
		return 1;
	}
	if(aout_len < (size_t)(AOUT_HEADR + textsize + datsize)) {
		fprintf(stderr, "dw2elf: %s: truncated\n", inpath); return 1;
	}

	/* ── virtual address layout (mirrors Plan9 a.out loader) ── */
	text_vaddr = AOUT_INITTEXT;
	data_vaddr = (text_vaddr + textsize + AOUT_INITRND - 1)
	             & ~(AOUT_INITRND - 1);

	/* ── ELF file offset layout ── */
	text_foff = EHDR_SIZE + 2 * PHDR_SIZE;       /* 176 */
	data_foff = text_foff + (long)textsize;

	/* ── DWARF generation ── */
	/* sections 0=NULL 1=.text 2=.data 3=.bss → DWARF starts at 4 */
	dw_base_elf_idx = 4;

	if(nsidecars > 0) {
		Dwarf_P_Debug  dbg;
		Dwarf_Error    derr;
		Dwarf_Unsigned nbufs;
		int res;

		res = dwarf_producer_init(
		    DW_DLC_POINTER64 | DW_DLC_TARGET_LITTLEENDIAN,
		    dw_section_callback, NULL, NULL, NULL,
		    "x86_64", "V4", "",
		    &dbg, &derr);

		if(res == DW_DLV_OK) {
			for(i = 0; i < nsidecars; i++) {
				size_t sclen;
				uint8_t *scbuf = loadfile(sidecars[i], &sclen);
				if(sclen >= 8 &&
				   memcmp(scbuf, "DWTYPES1", 8) == 0)
					emit_sidecar(dbg, sidecars[i], scbuf, sclen);
				else
					fprintf(stderr,
					  "dw2elf: %s: bad magic, skipping\n",
					  sidecars[i]);
				free(scbuf);
			}

			if(dwarf_transform_to_disk_form_a(dbg, &nbufs, &derr)
			   == DW_DLV_OK) {
				Dwarf_Unsigned j2;
				for(j2 = 0; j2 < nbufs; j2++) {
					Dwarf_Unsigned eidx, blen;
					Dwarf_Ptr      bptr;
					int k;
					if(dwarf_get_section_bytes_a(dbg, j2,
					    &eidx, &blen, &bptr, &derr)
					    != DW_DLV_OK)
						continue;
					for(k = 0; k < n_dw_sects; k++) {
						if(dw_sects[k].elf_idx
						   == (uint32_t)eidx) {
							dw_sects[k].data =
							  malloc(blen ? blen : 1);
							dw_sects[k].len  = blen;
							memcpy(dw_sects[k].data,
							       bptr, blen);
							break;
						}
					}
				}
			}
			dwarf_producer_finish_a(dbg, &derr);
		}
	}

	/* ── build .shstrtab ── */
	/* byte 0 is '\0' (pre-initialised) */
	shn_text  = shstrtab_add(".text");
	shn_data  = shstrtab_add(".data");
	shn_bss   = shstrtab_add(".bss");
	for(i = 0; i < n_dw_sects; i++)
		dw_sects[i].shname = shstrtab_add(dw_sects[i].name);
	shn_shstr = shstrtab_add(".shstrtab");

	/* ── compute section file offsets ── */
	dw_start_foff = data_foff + (long)datsize;
	cur = dw_start_foff;
	for(i = 0; i < n_dw_sects; i++) {
		dw_sects[i].foffset = cur;
		cur += (long)dw_sects[i].len;
	}
	/* 8-byte align .shstrtab and section headers */
	shstrtab_foff = (cur + 7) & ~7L;
	shdr_foff     = (shstrtab_foff + shstrtab_len + 7) & ~7L;

	/* shnum: NULL + .text + .data + .bss + DWARF sects + .shstrtab */
	shnum    = (uint16_t)(4 + n_dw_sects + 1);
	shstrndx = (uint16_t)(shnum - 1);

	/* ── open output file ── */
	ofd = open(outpath, O_WRONLY|O_CREAT|O_TRUNC, 0755);
	if(ofd < 0) { perror(outpath); return 1; }

	/* ── ELF header ── */
	write_ehdr(ofd, entry,
	           EHDR_SIZE,                /* phoff */
	           (uint64_t)shdr_foff,
	           2, shnum, shstrndx);

	/* ── program headers ── */
	write_phdr(ofd, PT_LOAD, PF_R|PF_X,
	           (uint64_t)text_foff, text_vaddr,
	           textsize, textsize, AOUT_INITRND);
	write_phdr(ofd, PT_LOAD, PF_R|PF_W,
	           (uint64_t)data_foff, data_vaddr,
	           datsize, (uint64_t)datsize + bsssize, AOUT_INITRND);

	/* ── text and data ── */
	xwrite(ofd, aout_buf + AOUT_HEADR, textsize);
	xwrite(ofd, aout_buf + AOUT_HEADR + textsize, datsize);

	/* ── DWARF sections ── */
	for(i = 0; i < n_dw_sects; i++) {
		if(dw_sects[i].data && dw_sects[i].len)
			xwrite(ofd, dw_sects[i].data, dw_sects[i].len);
	}

	/* ── pad to .shstrtab ── */
	cur = (long)lseek(ofd, 0, SEEK_CUR);
	while(cur < shstrtab_foff) { xwrite(ofd, &zero, 1); cur++; }
	xwrite(ofd, shstrtab_buf, shstrtab_len);

	/* ── pad to section headers ── */
	cur = (long)lseek(ofd, 0, SEEK_CUR);
	while(cur < shdr_foff) { xwrite(ofd, &zero, 1); cur++; }

	/* ── section headers ── */
	write_shdr(ofd, 0, SHT_NULL, 0, 0, 0, 0, 0, 0, 0, 0);
	write_shdr(ofd, shn_text, SHT_PROGBITS, SHF_ALLOC|SHF_EXECINSTR,
	           text_vaddr, (uint64_t)text_foff, textsize, 0, 0, 16, 0);
	write_shdr(ofd, shn_data, SHT_PROGBITS, SHF_ALLOC|SHF_WRITE,
	           data_vaddr, (uint64_t)data_foff, datsize, 0, 0, 8, 0);
	write_shdr(ofd, shn_bss, SHT_NOBITS, SHF_ALLOC|SHF_WRITE,
	           data_vaddr + datsize, 0, bsssize, 0, 0, 8, 0);
	for(i = 0; i < n_dw_sects; i++) {
		write_shdr(ofd, dw_sects[i].shname, SHT_PROGBITS, 0,
		           0, (uint64_t)dw_sects[i].foffset,
		           (uint64_t)dw_sects[i].len, 0, 0, 1, 0);
	}
	write_shdr(ofd, shn_shstr, SHT_STRTAB, 0,
	           0, (uint64_t)shstrtab_foff, (uint64_t)shstrtab_len,
	           0, 0, 1, 0);

	close(ofd);
	free(aout_buf);
	printf("dw2elf: %s (%u text + %u data + %u bss",
	       outpath, textsize, datsize, bsssize);
	if(n_dw_sects > 0)
		printf(" + %d DWARF sections", n_dw_sects);
	printf(")\n");
	return 0;
}
