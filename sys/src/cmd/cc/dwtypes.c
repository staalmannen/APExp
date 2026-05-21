/*
 * dwtypes.c — per-function type-info sidecar writer for Plan9 C compilers.
 *
 * Called from codgen() in pgen.c after each function's register-opt pass.
 * Writes a binary record for every function when the environment variable
 * _DWTYPES is present (set by "pcc -g" before invoking the compiler).
 *
 * Sidecar format (.dwtypes) — all integers little-endian (Plan9 native):
 *
 *   Header:  8 bytes  "DWTYPES1"
 *   Per function (one record per codgen() call, repeat until EOF):
 *     funcname:   u32 len (includes NUL) + bytes
 *     rettype:    type_record
 *     nparams:    u32
 *     params[]:   { name: u32+bytes,  type: type_record } × nparams
 *     nlocals:    u32  (always 0 in this version)
 *
 *   type_record:
 *     etype:      u8  (Plan9 etype value from cc.h)
 *     TIND   →    + sub type_record
 *     TARRAY →    + element type_record  +  u32 count
 *     TSTRUCT/TUNION → + tag_name (u32 len + bytes)
 *     (all other etypes: just the one byte)
 *
 * No flush or close is needed: write(2) is unbuffered and the kernel closes
 * open file descriptors on process exit.
 */
#include "cc.h"

static int dwfd = -1;   /* -1 = not yet opened; -2 = disabled/error */

static void
dw_write(void *buf, int n)
{
	if(write(dwfd, buf, n) != n)
		dwfd = -2;
}

static void
dw_u32(ulong v)
{
	dw_write(&v, 4);
}

static void
dw_str(char *s)
{
	ulong n;
	if(s == nil || s[0] == 0)
		s = "?";
	n = strlen(s) + 1;
	dw_u32(n);
	dw_write(s, n);
}

static void
dw_type(Type *t, int depth)
{
	uchar tag;
	ulong count;

	if(t == T || depth > 8) {
		tag = 0;	/* TVOID — treat as unknown */
		dw_write(&tag, 1);
		return;
	}
	tag = (uchar)t->etype;
	dw_write(&tag, 1);
	switch(t->etype) {
	case TIND:
		dw_type(t->link, depth+1);
		break;
	case TARRAY:
		dw_type(t->link, depth+1);
		count = (t->link && t->link->width > 0) ?
		        (ulong)(t->width / t->link->width) : 0;
		dw_u32(count);
		break;
	case TSTRUCT:
	case TUNION:
		dw_str(t->tag && t->tag->name ? t->tag->name : "?");
		break;
	}
}

static void
dwtypes_open(void)
{
	char buf[4096];
	char *p;
	int fd;

	if(outfile == nil || outfile[0] == 0) {
		dwfd = -2;
		return;
	}
	/* foo.6 → foo.dwtypes (same directory as object file) */
	snprint(buf, sizeof buf, "%s", outfile);
	p = utfrrune(buf, '.');
	if(p != nil)
		*p = 0;
	strncat(buf, ".dwtypes", sizeof(buf) - strlen(buf) - 1);

	fd = create(buf, OWRITE, 0666);
	if(fd < 0) {
		dwfd = -2;
		return;
	}
	dwfd = fd;
	dw_write("DWTYPES1", 8);
}

void
dwtypes_emit_func(Sym *func)
{
	Type *t;
	ulong nparams;
	int efd;

	if(dwfd == -2)
		return;

	if(dwfd < 0) {
		/* Check for _DWTYPES env var (Plan9: /env/_DWTYPES) */
		efd = open("/env/_DWTYPES", OREAD);
		if(efd < 0) {
			dwfd = -2;
			return;
		}
		close(efd);
		dwtypes_open();
		if(dwfd < 0)
			return;
	}

	/* function name */
	dw_str(func->name ? func->name : "?");

	/* return type */
	dw_type(thisfn ? thisfn->link : T, 0);

	/* parameter count, then records */
	nparams = 0;
	if(thisfn)
		for(t = thisfn->down; t != T && t->etype != TVOID; t = t->down)
			nparams++;
	dw_u32(nparams);

	if(thisfn)
		for(t = thisfn->down; t != T && t->etype != TVOID; t = t->down) {
			dw_str(t->sym && t->sym->name ? t->sym->name : "?");
			dw_type(t, 0);
		}

	/* locals: not yet collected */
	dw_u32(0);
}
