/*
 * as - GNU assembler syntax front-end for Plan 9 (9front)
 *
 * Translates AT&T (GAS) or Intel syntax assembly to Plan 9 assembly,
 * then invokes the native assembler (6a or 8a).
 *
 * Usage:
 *   as [options] file.s ...
 *   as -att [options] file.s ...     (force AT&T syntax)
 *   as -intel [options] file.s ...   (force Intel syntax)
 *
 * Options (GNU as compatible):
 *   -o outfile     output file
 *   -m32           target i386 (use 8a)
 *   -m64           target amd64 (use 6a)  [default]
 *   --32           same as -m32
 *   --64           same as -m64
 *   -I dir         add include directory (passed to native assembler)
 *   -D sym=val     define symbol (passed to native assembler)
 *   -v             verbose: print translated output to stderr
 *   --             end of options
 *
 * Syntax detection (when not forced):
 *   - If file contains ".intel_syntax", use Intel mode
 *   - If file contains ".att_syntax" or "%"-prefixed registers, use AT&T
 *   - If file looks like Plan 9 assembly (uppercase opcodes, no % or []),
 *     pass it through unmodified directly to the native assembler
 *   - Default: AT&T
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdarg.h>
#include <errno.h>
#include <unistd.h>

/* ------------------------------------------------------------------ */
/* Configuration */
/* ------------------------------------------------------------------ */

#define MAXLINE    4096
#define MAXARGS    256
#define MAXINC     32
#define MAXDEF     64
#define MAXFILES   256

typedef enum { ARCH_AMD64, ARCH_386 } Arch;
typedef enum { SYN_AUTO, SYN_ATT, SYN_INTEL, SYN_PLAN9 } Syntax;

static Arch   arch    = ARCH_AMD64;
static Syntax syntax  = SYN_AUTO;
static int    verbose = 0;
static char  *outfile = NULL;
static char  *incdirs[MAXINC];
static int    ninc    = 0;
static char  *defines[MAXDEF];
static int    ndef    = 0;
static char  *infiles[MAXFILES];
static int    nfiles  = 0;

/* ------------------------------------------------------------------ */
/* Register name tables */
/* ------------------------------------------------------------------ */

/*
 * AT&T register name → Plan 9 register name
 * AT&T uses %rax, %eax, %ax, %al, %ah etc.
 * Plan 9 uses AX (for both 32 and 64 bit — the assembler knows from opcode)
 */
typedef struct { const char *gas; const char *p9; } RegMap;

static RegMap att_regs[] = {
	/* 64-bit */
	{ "rax", "AX" },  { "rcx", "CX" },  { "rdx", "DX" },  { "rbx", "BX" },
	{ "rsp", "SP" },  { "rbp", "BP" },  { "rsi", "SI" },  { "rdi", "DI" },
	{ "r8",  "R8" },  { "r9",  "R9" },  { "r10", "R10" }, { "r11", "R11" },
	{ "r12", "R12" }, { "r13", "R13" }, { "r14", "R14" }, { "r15", "R15" },
	/* 32-bit */
	{ "eax", "AX" },  { "ecx", "CX" },  { "edx", "DX" },  { "ebx", "BX" },
	{ "esp", "SP" },  { "ebp", "BP" },  { "esi", "SI" },  { "edi", "DI" },
	{ "r8d", "R8" },  { "r9d", "R9" },  { "r10d","R10" }, { "r11d","R11" },
	{ "r12d","R12" }, { "r13d","R13" }, { "r14d","R14" }, { "r15d","R15" },
	/* 16-bit */
	{ "ax",  "AX" },  { "cx",  "CX" },  { "dx",  "DX" },  { "bx",  "BX" },
	{ "sp",  "SP" },  { "bp",  "BP" },  { "si",  "SI" },  { "di",  "DI" },
	{ "r8w", "R8" },  { "r9w", "R9" },  { "r10w","R10" }, { "r11w","R11" },
	{ "r12w","R12" }, { "r13w","R13" }, { "r14w","R14" }, { "r15w","R15" },
	/* 8-bit */
	{ "al",  "AL" },  { "cl",  "CL" },  { "dl",  "DL" },  { "bl",  "BL" },
	{ "ah",  "AH" },  { "ch",  "CH" },  { "dh",  "DH" },  { "bh",  "BH" },
	{ "spl", "SP" },  { "bpl", "BP" },  { "sil", "SI" },  { "dil", "DI" },
	{ "r8b", "R8" },  { "r9b", "R9" },  { "r10b","R10" }, { "r11b","R11" },
	{ "r12b","R12" }, { "r13b","R13" }, { "r14b","R14" }, { "r15b","R15" },
	/* FP / MMX / SSE */
	{ "st",   "F0" }, { "st(0)","F0" }, { "st(1)","F1" }, { "st(2)","F2" },
	{ "st(3)","F3" }, { "st(4)","F4" }, { "st(5)","F5" }, { "st(6)","F6" },
	{ "st(7)","F7" },
	{ "mm0","M0" }, { "mm1","M1" }, { "mm2","M2" }, { "mm3","M3" },
	{ "mm4","M4" }, { "mm5","M5" }, { "mm6","M6" }, { "mm7","M7" },
	{ "xmm0","X0" },{ "xmm1","X1" },{ "xmm2","X2" },{ "xmm3","X3" },
	{ "xmm4","X4" },{ "xmm5","X5" },{ "xmm6","X6" },{ "xmm7","X7" },
	/* segment registers */
	{ "cs", "CS" }, { "ss", "SS" }, { "ds", "DS" },
	{ "es", "ES" }, { "fs", "FS" }, { "gs", "GS" },
	{ NULL, NULL }
};

/*
 * Intel syntax register names (no % prefix, same names but uppercase/lowercase)
 * We normalise to lowercase before lookup in the same table.
 */

/* ------------------------------------------------------------------ */
/* Opcode translation tables */
/* ------------------------------------------------------------------ */

/*
 * Most Plan 9 opcodes are just the GNU mnemonic uppercased.
 * But there are differences:
 *  - AT&T size suffixes (b/w/l/q) → Plan 9 suffixes (B/W/L/Q)  [same, just uppercase]
 *  - some AT&T names differ from Plan 9
 *  - GNU uses "mov" with suffix; Plan 9 uses MOVB/MOVW/MOVL/MOVQ
 *  - sign/zero extend moves: movsx/movzx → MOVBLSx etc.
 *  - AT&T cdq → Plan 9 CDQ; cltq → CDQE; etc.
 *  - syscall → SYSCALL (same)
 *  - GNU "rep;" prefix → Plan 9 "REP;" (handled as prefix)
 */

typedef struct { const char *gas; const char *p9; } OpcMap;

static OpcMap opcode_map[] = {
	/* sign/zero extending moves — AT&T encodes size in mnemonic */
	{ "movsbw",  "MOVBWSX" }, { "movsbw",  "MOVBWSX" },
	{ "movsbl",  "MOVBLSX" }, { "movswl",  "MOVWLSX" },
	{ "movsbq",  "MOVBQSX" }, { "movswq",  "MOVWQSX" }, { "movslq", "MOVLQSX" },
	{ "movzbw",  "MOVBWZX" }, { "movzbl",  "MOVBLZX" }, { "movzwl", "MOVWLZX" },
	{ "movzbq",  "MOVBQZX" }, { "movzwq",  "MOVWQZX" },
	/* AT&T cltd/cqto etc. */
	{ "cwtl",  "CWDE" },   /* sign-extend AX→EAX */
	{ "cltd",  "CDQ"  },   /* sign-extend EAX→EDX:EAX */
	{ "cqto",  "CQO"  },   /* sign-extend RAX→RDX:RAX */
	{ "cwtd",  "CWD"  },
	{ "cbtw",  "CBW"  },
	{ "cltq",  "CDQE" },
	/* Plan 9 uses CDQE not CLTQ, CQO not CQTO */
	{ "cdqe",  "CDQE" },
	{ "cqo",   "CQO"  },
	/* AT&T conditional jumps — Plan 9 names differ slightly */
	{ "jnae",  "JCS"  }, { "jnb",  "JCC" }, { "jnbe","JHI" },
	{ "jng",   "JLE"  }, { "jnge", "JLT" }, { "jnl", "JGE" },
	{ "jnle",  "JGT"  }, { "jno",  "JOC" }, { "jnp", "JPC" },
	{ "jpe",   "JPS"  }, { "jpo",  "JPC" }, { "jnz", "JNE" },
	{ "jz",    "JEQ"  }, { "je",   "JEQ" }, { "jne", "JNE" },
	{ "jb",    "JCS"  }, { "jc",   "JCS" }, { "jae", "JCC" },
	{ "jbe",   "JLS"  }, { "ja",   "JHI" }, { "jl",  "JLT" },
	{ "jge",   "JGE"  }, { "jle",  "JLE" }, { "jg",  "JGT" },
	{ "js",    "JMI"  }, { "jns",  "JPL" }, { "jo",  "JOS" },
	{ "jp",    "JPS"  },
	/* AT&T set* — same but uppercase */
	{ "setnae","SETCS"},{ "setnb","SETCC"},{ "setnbe","SETHI"},
	{ "setng", "SETLE"},{ "setnge","SETLT"},{ "setnl","SETGE"},
	{ "setnle","SETGT"},{ "setno","SETOC"},{ "setnp","SETPC"},
	{ "setpe", "SETPS"},{ "setpo","SETPC"},{ "setnz","SETNE"},
	{ "setz",  "SETEQ"},{ "sete", "SETEQ"},{ "setne","SETNE"},
	{ "setb",  "SETCS"},{ "setc", "SETCS"},{ "setae","SETCC"},
	{ "setbe", "SETLS"},{ "seta", "SETHI"},{ "setl", "SETLT"},
	{ "setge", "SETGE"},{ "setle","SETLE"},{ "setg", "SETGT"},
	{ "sets",  "SETMI"},{ "setns","SETPL"},{ "seto", "SETOS"},
	{ "setp",  "SETPS"},
	/* cmov variants */
	{ "cmovnae","CMOVLCS"},{ "cmovnb","CMOVLCC"},{ "cmovnbe","CMOVLHI"},
	/* misc aliases */
	{ "sal",   "SHL"  },  /* sal is an alias for shl */
	{ "salb",  "SHLB" }, { "salw", "SHLW" }, { "sall", "SHLL" }, { "salq", "SHLQ" },
	{ "repe",  "REP"  }, { "repz", "REP"  }, { "repne","REPN" }, { "repnz","REPN" },
	/* fpu AT&T names */
	{ "fldl",  "FMOVD"  }, { "flds",  "FMOVF"  }, { "fldt",  "FMOVX"  },
	{ "fildl", "FMOVL"  }, { "fildll","FMOVV"  }, { "fildw", "FMOVW"  },
	{ "fstpl", "FMOVDP" }, { "fstps", "FMOVFP" }, { "fstpt", "FMOVXP" },
	{ "fistpl","FMOVLP" }, { "fistpll","FMOVVP"},{ "fistpw","FMOVWP" },
	{ "fstl",  "FMOVD"  }, { "fsts",  "FMOVF"  },
	{ "fistl", "FMOVL"  }, { "fistw", "FMOVW"  },
	{ "faddp", "FADDDP" }, { "fsubrp","FSUBRDP"}, { "fsubp", "FSUBDP" },
	{ "fmulp", "FMULDP" }, { "fdivrp","FDIVRDP"}, { "fdivp", "FDIVDP" },
	{ "fucompp","FUCOMPP"},{ "fucomp","FUCOMP" }, { "fucom", "FUCOM"  },
	{ "fcompp","FCOMDPP"},
	/* string ops — Plan 9 spells these the same */
	{ "lodsb","LODSB"},{ "lodsl","LODSL"},{ "lodsw","LODSW"},{ "lodsq","LODSQ"},
	{ "stosb","STOSB"},{ "stosl","STOSL"},{ "stosw","STOSW"},{ "stosq","STOSQ"},
	{ "movsb","MOVSB"},{ "movsl","MOVSL"},{ "movsw","MOVSW"},{ "movsq","MOVSQ"},
	{ "scasb","SCASB"},{ "scasl","SCASL"},{ "scasw","SCASW"},{ "scasq","SCASQ"},
	{ "cmpsb","CMPSB"},{ "cmpsl","CMPSL"},{ "cmpsw","CMPSW"},{ "cmpsq","CMPSQ"},
	{ NULL, NULL }
};

/* ------------------------------------------------------------------ */
/* Directive translation */
/* ------------------------------------------------------------------ */

typedef struct {
	const char *gas_dir;   /* GNU directive */
	const char *p9_dir;    /* Plan 9 directive, or NULL if to be dropped */
} DirMap;

static DirMap dir_map[] = {
	/* section directives — Plan 9 doesn't have these; we map to comments */
	{ ".text",       NULL },   /* start of text — no-op, Plan 9 doesn't need it */
	{ ".data",       NULL },
	{ ".bss",        NULL },
	{ ".section",    NULL },
	{ ".subsection", NULL },
	/* alignment */
	{ ".align",      "ALIGN" }, /* not a real Plan 9 directive but passable via NOP padding; handled specially */
	{ ".p2align",    "ALIGN" },
	{ ".balign",     "ALIGN" },
	/* data */
	{ ".byte",    "BYTE" },
	{ ".word",    "WORD" },
	{ ".short",   "WORD" },
	{ ".long",    "LONG" },
	{ ".int",     "LONG" },
	{ ".quad",    "QUAD" },
	{ ".float",   "LONG" },   /* single-precision float literal */
	{ ".double",  "QUAD" },   /* will be emitted as $float */
	{ ".string",  "SCONST" }, /* handled specially */
	{ ".asciz",   "SCONST" },
	{ ".ascii",   "SCONST" },
	/* symbol */
	{ ".globl",   "GLOBL" },
	{ ".global",  "GLOBL" },
	{ ".local",   NULL },     /* Plan 9 symbols are local by default */
	{ ".type",    NULL },     /* no type annotations needed */
	{ ".size",    NULL },
	{ ".file",    NULL },
	{ ".ident",   NULL },
	/* debug / dwarf — drop all */
	{ ".loc",     NULL },
	{ ".cfi_startproc", NULL },
	{ ".cfi_endproc",   NULL },
	{ ".cfi_def_cfa",   NULL },
	{ ".cfi_def_cfa_offset", NULL },
	{ ".cfi_def_cfa_register", NULL },
	{ ".cfi_offset", NULL },
	{ ".cfi_remember_state", NULL },
	{ ".cfi_restore_state", NULL },
	{ ".cfi_restore", NULL },
	{ ".cfi_same_value", NULL },
	{ ".cfi_escape", NULL },
	{ ".cfi_signal_frame", NULL },
	{ ".cfi_undefined", NULL },
	{ ".cfi_personality", NULL },
	{ ".cfi_lsda",  NULL },
	{ ".cfi_sections", NULL },
	/* misc */
	{ ".intel_syntax", NULL },
	{ ".att_syntax",   NULL },
	{ ".noprefix",     NULL },
	{ ".set",    NULL },  /* handled as symbol assignment */
	{ ".equ",    NULL },  /* same */
	{ ".comm",   NULL },  /* handled specially */
	{ ".lcomm",  NULL },
	{ NULL, NULL }
};

/* ------------------------------------------------------------------ */
/* Utility */
/* ------------------------------------------------------------------ */

static void
die(const char *fmt, ...)
{
	va_list ap;
	fprintf(stderr, "as: ");
	va_start(ap, fmt);
	vfprintf(stderr, fmt, ap);
	va_end(ap);
	fprintf(stderr, "\n");
	exit(1);
}

static void
warn(const char *fmt, ...)
{
	va_list ap;
	fprintf(stderr, "as: warning: ");
	va_start(ap, fmt);
	vfprintf(stderr, fmt, ap);
	va_end(ap);
	fprintf(stderr, "\n");
}

/* Trim leading/trailing whitespace in-place, return pointer to start */
static char *
trim(char *s)
{
	char *e;
	while (isspace((unsigned char)*s)) s++;
	e = s + strlen(s);
	while (e > s && isspace((unsigned char)e[-1])) e--;
	*e = '\0';
	return s;
}

/* Copy string to lowercase into buf */
static void
strlower(const char *src, char *buf, int sz)
{
	int i;
	for (i = 0; i < sz-1 && src[i]; i++)
		buf[i] = tolower((unsigned char)src[i]);
	buf[i] = '\0';
}

/* ------------------------------------------------------------------ */
/* Register translation */
/* ------------------------------------------------------------------ */

/*
 * Look up a register name (without % prefix, already lowercased).
 * Returns Plan 9 name or NULL if unknown.
 */
static const char *
lookup_reg(const char *name)
{
	int i;
	/* handle st(n) variants */
	if (strncmp(name, "st(", 3) == 0) {
		static char buf[8];
		int n = atoi(name+3);
		snprintf(buf, sizeof(buf), "F%d", n);
		return buf;
	}
	for (i = 0; att_regs[i].gas; i++) {
		if (strcmp(att_regs[i].gas, name) == 0)
			return att_regs[i].p9;
	}
	return NULL;
}

/* ------------------------------------------------------------------ */
/* Opcode translation */
/* ------------------------------------------------------------------ */

/*
 * Translate an AT&T/Intel mnemonic to a Plan 9 mnemonic.
 * Returned string is static or points into a static buffer.
 */
static const char *
translate_opcode(const char *mnem)
{
	static char buf[64];
	char low[64];
	int i;

	strlower(mnem, low, sizeof(low));

	/* check explicit mapping table first */
	for (i = 0; opcode_map[i].gas; i++) {
		if (strcmp(opcode_map[i].gas, low) == 0)
			return opcode_map[i].p9;
	}

	/*
	 * Default: uppercase the mnemonic.
	 * Plan 9 opcode names are exactly the AT&T names uppercased in most cases.
	 * e.g. movq→MOVQ, addl→ADDL, pushq→PUSHQ, syscall→SYSCALL
	 */
	for (i = 0; low[i] && i < (int)sizeof(buf)-1; i++)
		buf[i] = toupper((unsigned char)low[i]);
	buf[i] = '\0';
	return buf;
}

/* ------------------------------------------------------------------ */
/* Operand translation */
/* ------------------------------------------------------------------ */

/*
 * State for parsing a single operand.
 */
typedef struct {
	char   buf[MAXLINE];
	int    is_mem;    /* 1 if memory reference */
	int    is_imm;    /* 1 if immediate */
	int    is_reg;    /* 1 if register */
} Operand;

/*
 * Translate an AT&T immediate: $expr → $expr (mostly the same)
 * The $ prefix is kept. We just need to handle register-based address
 * immediates like $symbol which become $symbol(SB).
 */

/*
 * Translate an AT&T memory operand to Plan 9 syntax.
 *
 * AT&T: disp(base, index, scale)
 *   → Plan 9: disp(BASE)(INDEX*scale)
 *
 * AT&T: (%rsp)     → Plan 9: 0(SP)
 * AT&T: 8(%rsp)    → Plan 9: 8(SP)
 * AT&T: (%rip)     → Plan 9: used for globals: symbol+offset(SB)
 * AT&T: symbol(%rip) → symbol(SB)
 *
 * We parse the AT&T memory operand and reconstruct in Plan 9 form.
 */
static void
translate_mem_att(const char *in, char *out, int outsz)
{
	/*
	 * AT&T memory syntax: disp(base,index,scale)
	 * Each part is optional.
	 * disp can be a number, symbol, or symbol+offset.
	 */
	char disp[256] = "";
	char base[64]  = "";
	char idx[64]   = "";
	char scl[16]   = "";
	const char *p = in;
	char *q;
	int depth;

	/* collect displacement (everything before first '(') */
	q = disp;
	while (*p && *p != '(') {
		*q++ = *p++;
	}
	*q = '\0';

	if (*p == '(') {
		/* parse (base, index, scale) */
		char inner[256];
		char *parts[3] = { NULL, NULL, NULL };
		char *tok;
		int np = 0;

		p++; /* skip ( */
		q = inner;
		depth = 1;
		while (*p && depth > 0) {
			if (*p == '(') depth++;
			else if (*p == ')') { depth--; if (depth == 0) { p++; break; } }
			*q++ = *p++;
		}
		*q = '\0';

		/* split by comma */
		tok = strtok(inner, ",");
		while (tok && np < 3) {
			while (isspace((unsigned char)*tok)) tok++;
			parts[np++] = tok;
			tok = strtok(NULL, ",");
		}

		if (np >= 1) strncpy(base, parts[0], sizeof(base)-1);
		if (np >= 2) strncpy(idx,  parts[1], sizeof(idx)-1);
		if (np >= 3) strncpy(scl,  parts[2], sizeof(scl)-1);
	}

	/* trim all parts */
	char *db = trim(disp);
	char *bb = trim(base);
	char *ib = trim(idx);
	char *sb = trim(scl);

	/* translate base register: %reg → REG */
	char base_p9[32] = "";
	char idx_p9[32]  = "";

	if (*bb == '%') {
		char tmp[32];
		strlower(bb+1, tmp, sizeof(tmp));
		const char *r = lookup_reg(tmp);
		if (r) snprintf(base_p9, sizeof(base_p9), "%s", r);
		else   snprintf(base_p9, sizeof(base_p9), "%s", bb+1); /* unknown, pass through */
	} else if (*bb) {
		/* could be a segment register reference or something */
		snprintf(base_p9, sizeof(base_p9), "%s", bb);
	}

	if (*ib == '%') {
		char tmp[32];
		strlower(ib+1, tmp, sizeof(tmp));
		const char *r = lookup_reg(tmp);
		if (r) snprintf(idx_p9, sizeof(idx_p9), "%s", r);
		else   snprintf(idx_p9, sizeof(idx_p9), "%s", ib+1);
	} else if (*ib) {
		snprintf(idx_p9, sizeof(idx_p9), "%s", ib);
	}

	/*
	 * Handle RIP-relative addressing: disp(%rip)
	 * In Plan 9 this becomes symbol(SB) or symbol+offset(SB)
	 */
	if (strcmp(base_p9, "IP") == 0 /* rip translates to IP conceptually */ ||
	    (strlen(bb) >= 3 && strncasecmp(bb+(*bb=='%'), "rip", 3) == 0)) {
		/* RIP-relative: the disp is a symbol or symbol±offset */
		if (*db) {
			/* check if disp already contains a symbol */
			/* just append (SB) */
			snprintf(out, outsz, "%s(SB)", db);
		} else {
			snprintf(out, outsz, "0(SB)");
		}
		return;
	}

	/*
	 * Reconstruct Plan 9 memory address:
	 *   disp(BASE)(IDX*scale)
	 */
	char result[512] = "";
	char *rp = result;
	int  rem = sizeof(result);
	int  n;

	/* displacement */
	if (*db) {
		n = snprintf(rp, rem, "%s", db);
		rp += n; rem -= n;
	} else if (!*base_p9 && !*idx_p9) {
		/* bare number — just pass through */
		snprintf(out, outsz, "0");
		return;
	}

	/* base */
	if (*base_p9) {
		n = snprintf(rp, rem, "(%s)", base_p9);
		rp += n; rem -= n;
	} else if (!*db) {
		/* no disp, no base — degenerate */
	}

	/* index * scale */
	if (*idx_p9) {
		if (*sb && strcmp(sb, "1") != 0)
			n = snprintf(rp, rem, "(%s*%s)", idx_p9, sb);
		else
			n = snprintf(rp, rem, "(%s*1)", idx_p9);
		rp += n; rem -= n;
	}

	if (*result == '\0') snprintf(result, sizeof(result), "0");
	snprintf(out, outsz, "%s", result);
}

/*
 * Translate an Intel-syntax memory operand to Plan 9.
 * Intel: [base + index*scale + disp]
 * We parse what's inside [] and reconstruct.
 */
static void
translate_mem_intel(const char *in, char *out, int outsz)
{
	/* Strip [] brackets */
	char inner[256];
	const char *p = in;
	char *q = inner;

	while (*p == '[' || isspace((unsigned char)*p)) p++;
	while (*p && *p != ']') *q++ = *p++;
	*q = '\0';
	trim(inner);

	/*
	 * Parse: [base + idx*scale + disp] in any order
	 * We find tokens separated by + and -
	 */
	char base_p9[32] = "";
	char idx_p9[32]  = "";
	char scl[16] = "1";
	long disp_val = 0;
	char disp_sym[256] = "";
	int  have_disp = 0;

	/* Tokenise by + and - while tracking signs */
	char tmp[256];
	strncpy(tmp, inner, sizeof(tmp)-1);

	/* Replace '-' with '+-' so strtok can split on '+' */
	char expanded[512];
	q = expanded;
	for (p = tmp; *p; p++) {
		if (*p == '-' && p != tmp) { *q++ = '+'; }
		*q++ = *p;
	}
	*q = '\0';

	char *tok = strtok(expanded, "+");
	while (tok) {
		char t[128];
		int neg = 0;
		while (isspace((unsigned char)*tok)) tok++;
		if (*tok == '-') { neg = 1; tok++; }
		while (isspace((unsigned char)*tok)) tok++;
		strncpy(t, tok, sizeof(t)-1);
		trim(t);

		/* Check for index*scale */
		char *star = strchr(t, '*');
		if (star) {
			*star = '\0';
			char reg[64], sc[16];
			strncpy(reg, t, sizeof(reg)-1);
			strncpy(sc, star+1, sizeof(sc)-1);
			trim(reg); trim(sc);
			strlower(reg, reg, sizeof(reg));
			const char *r = lookup_reg(reg);
			if (r) snprintf(idx_p9, sizeof(idx_p9), "%s", r);
			snprintf(scl, sizeof(scl), "%s", sc);
		} else {
			/* register, symbol, or number? */
			char low[128];
			strlower(t, low, sizeof(low));
			const char *r = lookup_reg(low);
			if (r) {
				/* is it rip? */
				if (strcmp(low, "rip") == 0 || strcmp(low, "eip") == 0) {
					/* RIP-relative — will be handled after loop */
					strncpy(base_p9, "RIP", sizeof(base_p9)-1);
				} else if (!*base_p9) {
					strncpy(base_p9, r, sizeof(base_p9)-1);
				} else {
					/* second register without scale — treat as idx*1 */
					strncpy(idx_p9, r, sizeof(idx_p9)-1);
					strncpy(scl, "1", sizeof(scl)-1);
				}
			} else {
				/* number or symbol */
				char *end;
				long v = strtol(t, &end, 0);
				if (end != t && *end == '\0') {
					disp_val += neg ? -v : v;
					have_disp = 1;
				} else {
					/* symbol */
					if (*disp_sym) strncat(disp_sym, "+", sizeof(disp_sym)-strlen(disp_sym)-1);
					if (neg) strncat(disp_sym, "-", sizeof(disp_sym)-strlen(disp_sym)-1);
					strncat(disp_sym, t, sizeof(disp_sym)-strlen(disp_sym)-1);
				}
			}
		}
		tok = strtok(NULL, "+");
	}

	/* RIP-relative */
	if (strcmp(base_p9, "RIP") == 0) {
		if (*disp_sym) {
			if (have_disp && disp_val != 0)
				snprintf(out, outsz, "%s+%ld(SB)", disp_sym, disp_val);
			else
				snprintf(out, outsz, "%s(SB)", disp_sym);
		} else {
			snprintf(out, outsz, "%ld(SB)", disp_val);
		}
		return;
	}

	/* Build Plan 9 address */
	char result[512] = "";
	q = result;
	int remr = sizeof(result);
	int n;

	/* disp part */
	if (*disp_sym) {
		n = snprintf(q, remr, "%s", disp_sym);
		q += n; remr -= n;
		if (have_disp && disp_val > 0)  { n = snprintf(q, remr, "+%ld", disp_val);  q += n; remr -= n; }
		if (have_disp && disp_val < 0)  { n = snprintf(q, remr, "%ld",  disp_val);  q += n; remr -= n; }
	} else if (have_disp) {
		n = snprintf(q, remr, "%ld", disp_val);
		q += n; remr -= n;
	}

	if (*base_p9) {
		n = snprintf(q, remr, "(%s)", base_p9);
		q += n; remr -= n;
	}
	if (*idx_p9) {
		n = snprintf(q, remr, "(%s*%s)", idx_p9, scl);
		q += n; remr -= n;
	}

	if (*result == '\0') snprintf(result, sizeof(result), "0");
	snprintf(out, outsz, "%s", result);
}

/* ------------------------------------------------------------------ */
/* AT&T operand → Plan 9 */
/* ------------------------------------------------------------------ */

static void
translate_operand_att(const char *in, char *out, int outsz)
{
	char tmp[MAXLINE];
	const char *p = in;

	while (isspace((unsigned char)*p)) p++;

	if (*p == '$') {
		/* immediate */
		/* $symbol → $symbol(SB) if it's a name, else $value */
		const char *val = p+1;
		/* check if it's a pure number */
		char *end;
		strtol(val, &end, 0);
		if (end != val && (*end == '\0' || isspace((unsigned char)*end))) {
			snprintf(out, outsz, "$%s", val);
		} else {
			/* symbol address — becomes $symbol(SB) */
			/* but if it has arithmetic like $sym+4, keep as-is with (SB) appended */
			snprintf(out, outsz, "$%s", val);
		}
		return;
	}

	if (*p == '%') {
		/* register */
		char regname[32];
		strlower(p+1, regname, sizeof(regname));
		const char *r = lookup_reg(regname);
		if (r) snprintf(out, outsz, "%s", r);
		else   snprintf(out, outsz, "%s", p+1); /* unknown register, uppercase it */
		return;
	}

	if (*p == '*') {
		/* indirect branch target: *%reg or *mem */
		const char *q2 = p+1;
		while (isspace((unsigned char)*q2)) q2++;
		if (*q2 == '%') {
			char regname[32];
			strlower(q2+1, regname, sizeof(regname));
			const char *r = lookup_reg(regname);
			snprintf(out, outsz, "*%s", r ? r : q2+1);
		} else {
			translate_mem_att(q2, tmp, sizeof(tmp));
			snprintf(out, outsz, "*%s", tmp);
		}
		return;
	}

	/* Check if it's a memory reference (contains '(' or is a bare symbol) */
	if (strchr(p, '(')) {
		translate_mem_att(p, out, outsz);
		return;
	}

	/* Bare symbol or label — might be a branch target or data reference */
	/* In Plan 9: bare label reference stays bare; symbol+offset(SB) for data */
	snprintf(out, outsz, "%s", p);
}

/* ------------------------------------------------------------------ */
/* Intel operand → Plan 9 */
/* ------------------------------------------------------------------ */

static void
translate_operand_intel(const char *in, char *out, int outsz, const char *size_hint)
{
	const char *p = in;
	char tmp[MAXLINE];

	while (isspace((unsigned char)*p)) p++;

	/* Strip size overrides: BYTE PTR, WORD PTR, DWORD PTR, QWORD PTR, etc. */
	if (strncasecmp(p, "BYTE",  4) == 0 ||
	    strncasecmp(p, "WORD",  4) == 0 ||
	    strncasecmp(p, "DWORD", 5) == 0 ||
	    strncasecmp(p, "QWORD", 5) == 0 ||
	    strncasecmp(p, "TBYTE", 5) == 0 ||
	    strncasecmp(p, "XMMWORD", 7) == 0 ||
	    strncasecmp(p, "YMMWORD", 7) == 0) {
		/* skip over "XXX PTR" */
		while (*p && !isspace((unsigned char)*p)) p++;
		while (isspace((unsigned char)*p)) p++;
		if (strncasecmp(p, "PTR", 3) == 0) p += 3;
		while (isspace((unsigned char)*p)) p++;
	}

	if (*p == '[') {
		translate_mem_intel(p, out, outsz);
		return;
	}

	/* Immediate: just a number or symbol */
	char *end;
	strtol(p, &end, 0);
	if (end != p && (*end == '\0' || isspace((unsigned char)*end))) {
		snprintf(out, outsz, "$%s", p); /* add $ for Plan 9 immediate */
		return;
	}

	/* Register? */
	char low[64];
	strlower(p, low, sizeof(low));
	const char *r = lookup_reg(low);
	if (r) {
		snprintf(out, outsz, "%s", r);
		return;
	}

	/* Symbol or label */
	snprintf(out, outsz, "%s", p);
	(void)size_hint;
	(void)tmp;
}

/* ------------------------------------------------------------------ */
/* Line-by-line translator */
/* ------------------------------------------------------------------ */

/*
 * Split a line into: label, opcode, operands[]
 */
typedef struct {
	char label[256];
	char opcode[64];
	char operands[8][MAXLINE];
	int  noperands;
	int  is_directive;
	int  is_label_only;
} AsmLine;

/* Split operands respecting parentheses/brackets */
static int
split_operands(const char *s, char ops[][MAXLINE], int maxops)
{
	int n = 0;
	int depth = 0;
	const char *start = s;
	char *dst;

	if (!*s) return 0;

	dst = ops[0];
	while (*s) {
		if (*s == '(' || *s == '[') depth++;
		else if (*s == ')' || *s == ']') depth--;
		else if (*s == ',' && depth == 0) {
			*dst = '\0';
			trim(ops[n]);
			n++;
			if (n >= maxops) break;
			dst = ops[n];
			s++;
			while (isspace((unsigned char)*s)) s++;
			start = s;
			continue;
		}
		*dst++ = *s++;
	}
	*dst = '\0';
	if (*trim(ops[n])) n++;
	(void)start;
	return n;
}

/*
 * Detect the syntax of an assembly file by scanning its content.
 *
 * Plan 9 markers (any one is conclusive):
 *   - A line that is exactly "TEXT" or starts with "TEXT " or "TEXT\t"
 *   - A line starting with "DATA " or "GLOBL "
 *   - Use of Plan 9 pseudo-registers in their canonical form:
 *     a word boundary followed by "(SB)", "(SP)", "(FP)", "(PC)"
 *   - An #include directive (Plan 9 .s files use the C preprocessor)
 *     combined with absence of % signs
 *
 * GNU AT&T markers:
 *   - Any % sign (register prefix)
 *   - ".att_syntax"
 *
 * GNU Intel markers:
 *   - ".intel_syntax"
 *
 * The scan reads up to DETECT_LINES lines, collecting evidence, and
 * decides at the end.  A single conclusive Plan 9 or AT&T/Intel marker
 * short-circuits the scan immediately.
 */
#define DETECT_LINES 200

static Syntax
detect_syntax(const char *filename)
{
	FILE *f = fopen(filename, "r");
	char line[MAXLINE];
	int  nlines = 0;
	int  has_percent    = 0;  /* saw a % — strong AT&T evidence */
	int  has_brackets   = 0;  /* saw [ — strong Intel evidence */
	int  has_plan9_pseudo = 0; /* saw (SB)/(FP)/(PC) — strong Plan 9 evidence */
	int  has_plan9_directive = 0; /* TEXT/DATA/GLOBL at start of line */
	int  has_uppercase_op = 0;   /* opcode-like uppercase word at line start */

	if (!f) return SYN_ATT;

	while (nlines++ < DETECT_LINES && fgets(line, sizeof(line), f)) {
		char *p = line;
		/* skip leading whitespace */
		while (isspace((unsigned char)*p)) p++;
		/* skip empty lines and // comments */
		if (!*p || (p[0]=='/' && p[1]=='/')) continue;
		/* skip C preprocessor lines — present in both Plan 9 and GNU */
		if (*p == '#') continue;

		/* --- conclusive GNU markers --- */
		if (strncasecmp(p, ".intel_syntax", 13) == 0)
			{ fclose(f); return SYN_INTEL; }
		if (strncasecmp(p, ".att_syntax", 11) == 0)
			{ fclose(f); return SYN_ATT; }
		if (strchr(p, '%'))
			{ fclose(f); return SYN_ATT; }

		/* --- conclusive Plan 9 markers --- */
		/*
		 * TEXT, DATA, GLOBL are Plan 9 directives that never appear
		 * in GNU .s files (GNU uses .text, .data, .globl).
		 * Match at the very start of the line (possibly after a label).
		 */
		if (strncmp(p, "TEXT\t",  5) == 0 || strncmp(p, "TEXT ",  5) == 0 ||
		    strncmp(p, "DATA\t",  5) == 0 || strncmp(p, "DATA ",  5) == 0 ||
		    strncmp(p, "GLOBL\t", 6) == 0 || strncmp(p, "GLOBL ", 6) == 0)
			{ fclose(f); return SYN_PLAN9; }

		/*
		 * Plan 9 pseudo-registers: (SB), (FP), (PC) following an operand.
		 * These never appear in GNU syntax.
		 */
		if (strstr(p, "(SB)") || strstr(p, "(FP)") || strstr(p, "(PC)"))
			{ fclose(f); return SYN_PLAN9; }

		/* --- accumulate weaker evidence --- */
		if (strchr(p, '['))
			has_brackets = 1;

		/*
		 * Plan 9 opcodes are UPPERCASE with a size suffix letter.
		 * Heuristic: a line that starts with 1-8 uppercase letters
		 * followed by a tab or space, where the word is all-caps,
		 * is likely a Plan 9 instruction.
		 * We exclude single-letter words (labels like "A:") and
		 * known GNU uppercase tokens.
		 */
		if (isupper((unsigned char)*p)) {
			const char *q = p;
			int len = 0;
			int all_upper = 1;
			while (isalpha((unsigned char)*q)) {
				if (islower((unsigned char)*q)) all_upper = 0;
				q++; len++;
			}
			if (all_upper && len >= 2 && len <= 8 &&
			    (*q == '\t' || *q == ' ') &&
			    /* exclude GNU .s tokens that happen to be uppercase */
			    strncmp(p, "SECTION", 7) != 0) {
				has_uppercase_op++;
			}
		}
	}

	fclose(f);

	/*
	 * Decide from accumulated evidence.
	 * We already returned early for conclusive cases.
	 * Remaining ambiguity: file with no % signs and no Plan 9 markers.
	 */
	if (has_plan9_directive || has_plan9_pseudo)
		return SYN_PLAN9;

	if (has_brackets && !has_percent)
		return SYN_INTEL;

	/*
	 * If we saw several uppercase-opcode lines and no % signs at all,
	 * this is likely Plan 9.  Threshold of 3 avoids false positives
	 * from files with just a few constants defined in uppercase.
	 */
	if (has_uppercase_op >= 3 && !has_percent && !has_brackets)
		return SYN_PLAN9;

	return SYN_ATT; /* default */
}


/*
 * Translate a single line of AT&T assembly to Plan 9 assembly.
 * Writes result to out (a FILE*).
 */
static void
translate_line_att(const char *line, FILE *out)
{
	char buf[MAXLINE];
	strncpy(buf, line, sizeof(buf)-1);
	char *p = buf;

	/* Strip comments: #, //, and C-style block comments */
	{
		int in_str2 = 0;
		char *c = p;
		while (*c) {
			if (*c == '"') { in_str2 = !in_str2; c++; continue; }
			if (in_str2) { c++; continue; }
			if (*c == '#') { *c = '\0'; break; }
			if (*c == '/' && c[1] == '/') { *c = '\0'; break; }
			if (*c == '/' && c[1] == '*') {
				char *end = strstr(c+2, "*/");
				if (end) {
					*c = ' ';
					memmove(c+1, end+2, strlen(end+2)+1);
				} else {
					*c = '\0';
				}
				continue;
			}
			c++;
		}
	}

	p = trim(p);
	if (!*p) {
		fprintf(out, "\n");
		return;
	}

	/* Preserve C preprocessor directives */
	if (*p == '#') {
		fprintf(out, "%s\n", p);
		return;
	}

	/* Check for label */
	char label[256] = "";
	char *colon = strchr(p, ':');
	if (colon) {
		/* make sure it's really a label (not e.g. inside an operand) */
		char tmp2[256];
		int llen = colon - p;
		if (llen < (int)sizeof(label)-1) {
			memcpy(label, p, llen);
			label[llen] = '\0';
			/* a label should be alphanumeric+underscore+dot */
			int ok = 1;
			for (int i = 0; label[i]; i++)
				if (!isalnum((unsigned char)label[i]) && label[i] != '_' && label[i] != '.' && label[i] != '$')
					{ ok = 0; break; }
			if (ok) {
				p = colon+1;
				while (isspace((unsigned char)*p)) p++;
				/* output label */
				fprintf(out, "%s:\n", label);
			}
			(void)tmp2;
		}
	}

	if (!*p) return;

	/* Directive? */
	if (*p == '.') {
		char dir[64];
		char *sp = p;
		int i = 0;
		while (*sp && !isspace((unsigned char)*sp) && i < (int)sizeof(dir)-1)
			dir[i++] = *sp++;
		dir[i] = '\0';
		while (isspace((unsigned char)*sp)) sp++;
		char *args = sp;

		/* Look up directive */
		int found = 0;
		for (i = 0; dir_map[i].gas_dir; i++) {
			if (strcasecmp(dir_map[i].gas_dir, dir) == 0) {
				found = 1;
				if (dir_map[i].p9_dir == NULL) {
					fprintf(out, "// %s %s\n", dir, args);
				} else if (strcmp(dir_map[i].p9_dir, "GLOBL") == 0) {
					/* .globl symbol → we'll emit GLOBL at TEXT time; for now just note it */
					fprintf(out, "// GLOBL %s\n", args);
				} else if (strcmp(dir_map[i].p9_dir, "BYTE") == 0 ||
				           strcmp(dir_map[i].p9_dir, "WORD") == 0 ||
				           strcmp(dir_map[i].p9_dir, "LONG") == 0 ||
				           strcmp(dir_map[i].p9_dir, "QUAD") == 0) {
					/* Data directives — emit for each comma-separated value */
					char ops[8][MAXLINE];
					int nops = split_operands(args, ops, 8);
					for (int j = 0; j < nops; j++)
						fprintf(out, "\t%s $%s\n", dir_map[i].p9_dir, trim(ops[j]));
				} else if (strcmp(dir_map[i].p9_dir, "SCONST") == 0) {
					/* .string "..." — emit as BYTE sequence */
					fprintf(out, "\t// string: %s\n", args);
				} else if (strcmp(dir_map[i].p9_dir, "ALIGN") == 0) {
					/* .align n — Plan 9 doesn't have standalone ALIGN,
					   but we can emit a comment; the linker handles alignment */
					fprintf(out, "\t// ALIGN %s\n", args);
				} else {
					fprintf(out, "\t%s %s\n", dir_map[i].p9_dir, args);
				}
				break;
			}
		}
		if (!found) {
			/* Unknown directive — comment it out */
			fprintf(out, "// %s %s\n", dir, args);
		}
		return;
	}

	/* Instruction */
	/* Extract mnemonic */
	char mnem[64];
	int i = 0;
	while (*p && !isspace((unsigned char)*p) && i < (int)sizeof(mnem)-1)
		mnem[i++] = *p++;
	mnem[i] = '\0';
	while (isspace((unsigned char)*p)) p++;

	/* Handle lock/rep/repne prefixes */
	char prefix[64] = "";
	char mlow[64];
	strlower(mnem, mlow, sizeof(mlow));
	if (strcmp(mlow, "lock") == 0 || strcmp(mlow, "rep") == 0 ||
	    strcmp(mlow, "repe") == 0 || strcmp(mlow, "repz") == 0 ||
	    strcmp(mlow, "repne") == 0|| strcmp(mlow, "repnz") == 0) {
		snprintf(prefix, sizeof(prefix), "%s; ", translate_opcode(mnem));
		/* next token is the real instruction */
		i = 0;
		while (*p && !isspace((unsigned char)*p) && i < (int)sizeof(mnem)-1)
			mnem[i++] = *p++;
		mnem[i] = '\0';
		while (isspace((unsigned char)*p)) p++;
	}

	const char *p9op = translate_opcode(mnem);

	/* Split operands */
	char ops[8][MAXLINE];
	int nops = split_operands(p, ops, 8);

	/* AT&T operand order: src, dst — Plan 9 is also src, dst — same! */
	/* But we still need to translate each operand */
	char tops[8][MAXLINE];
	for (i = 0; i < nops; i++)
		translate_operand_att(ops[i], tops[i], MAXLINE);

	/* Emit */
	fprintf(out, "\t%s%s", prefix, p9op);
	for (i = 0; i < nops; i++) {
		if (i == 0) fprintf(out, "\t%s", tops[i]);
		else        fprintf(out, ", %s", tops[i]);
	}
	fprintf(out, "\n");
}

/*
 * Translate a single line of Intel syntax assembly to Plan 9.
 */
static void
translate_line_intel(const char *line, FILE *out)
{
	char buf[MAXLINE];
	strncpy(buf, line, sizeof(buf)-1);
	char *p = buf;

	/* Strip comment: ; is Intel comment */
	char *sc = strchr(p, ';');
	if (sc) *sc = '\0';

	p = trim(p);
	if (!*p) { fprintf(out, "\n"); return; }

	if (*p == '#') { fprintf(out, "%s\n", p); return; }

	/* Label */
	char label[256] = "";
	char *colon = strchr(p, ':');
	if (colon) {
		int llen = colon - p;
		if (llen < (int)sizeof(label)-1) {
			memcpy(label, p, llen);
			label[llen] = '\0';
			int ok = 1;
			for (int i = 0; label[i]; i++)
				if (!isalnum((unsigned char)label[i]) && label[i] != '_' && label[i] != '.')
					{ ok = 0; break; }
			if (ok) {
				p = colon+1;
				while (isspace((unsigned char)*p)) p++;
				fprintf(out, "%s:\n", label);
			}
		}
	}

	if (!*p) return;

	/* Directive */
	if (*p == '.') {
		/* Same handling as AT&T */
		translate_line_att(p, out);
		return;
	}

	/* Instruction: Intel order is  opcode dst, src — Plan 9 is src, dst */
	char mnem[64];
	int i = 0;
	while (*p && !isspace((unsigned char)*p) && i < (int)sizeof(mnem)-1)
		mnem[i++] = *p++;
	mnem[i] = '\0';
	while (isspace((unsigned char)*p)) p++;

	const char *p9op = translate_opcode(mnem);

	char ops[8][MAXLINE];
	int nops = split_operands(p, ops, 8);

	/* Reverse operand order for Intel → Plan 9 */
	char tops[8][MAXLINE];
	for (i = 0; i < nops; i++)
		translate_operand_intel(ops[i], tops[i], MAXLINE, mnem);

	fprintf(out, "\t%s", p9op);
	if (nops == 2) {
		/* Intel: dst, src → Plan 9: src, dst — swap */
		fprintf(out, "\t%s, %s", tops[1], tops[0]);
	} else if (nops == 1) {
		fprintf(out, "\t%s", tops[0]);
	} else if (nops > 2) {
		/* 3-operand: usually imm, src, dst → keep as-is for now */
		for (i = 0; i < nops; i++) {
			if (i == 0) fprintf(out, "\t%s", tops[i]);
			else        fprintf(out, ", %s", tops[i]);
		}
	}
	fprintf(out, "\n");
}

/* ------------------------------------------------------------------ */
/* File translation */
/* ------------------------------------------------------------------ */

static void
translate_file(const char *infile, const char *outfile_path, Syntax syn)
{
	FILE *in, *out;
	char line[MAXLINE];

	/*
	 * Plan 9 pass-through: copy verbatim into the temp file so the
	 * rest of the pipeline (invoke_assembler, cleanup) stays uniform.
	 */
	if (syn == SYN_PLAN9) {
		in  = fopen(infile,       "rb");
		out = fopen(outfile_path, "wb");
		if (!in)  die("cannot open input: %s: %s",  infile,       strerror(errno));
		if (!out) die("cannot open output: %s: %s", outfile_path,  strerror(errno));
		while (fgets(line, sizeof(line), in))
			fputs(line, out);
		fclose(in);
		fclose(out);
		if (verbose)
			fprintf(stderr, "as: %s: Plan 9 syntax, passing through unmodified\n", infile);
		return;
	}

	in  = fopen(infile,       "r");
	out = fopen(outfile_path, "w");
	if (!in)  die("cannot open input: %s: %s",  infile,      strerror(errno));
	if (!out) die("cannot open output: %s: %s", outfile_path, strerror(errno));

	while (fgets(line, sizeof(line), in)) {
		if (syn == SYN_INTEL)
			translate_line_intel(line, out);
		else
			translate_line_att(line, out);

		if (verbose) {
			if (syn == SYN_INTEL)
				translate_line_intel(line, stderr);
			else
				translate_line_att(line, stderr);
		}
	}

	fclose(in);
	fclose(out);
}

static int
invoke_assembler(const char *translated, const char *output)
{
	char cmd[4096];
	const char *native = (arch == ARCH_AMD64) ? "6a" : "8a";
	int pos = 0;
	int n;
	int i;

	n = snprintf(cmd+pos, sizeof(cmd)-pos, "%s", native);
	pos += n;

	if (output) {
		n = snprintf(cmd+pos, sizeof(cmd)-pos, " -o %s", output);
		pos += n;
	}

	for (i = 0; i < ninc; i++) {
		n = snprintf(cmd+pos, sizeof(cmd)-pos, " -I %s", incdirs[i]);
		pos += n;
	}

	for (i = 0; i < ndef; i++) {
		n = snprintf(cmd+pos, sizeof(cmd)-pos, " -D %s", defines[i]);
		pos += n;
	}

	n = snprintf(cmd+pos, sizeof(cmd)-pos, " %s", translated);
	pos += n;

	if (verbose) fprintf(stderr, "as: exec: %s\n", cmd);

	return system(cmd);
}

/* ------------------------------------------------------------------ */
/* Temp file helpers */
/* ------------------------------------------------------------------ */

static char tmpfiles[MAXFILES][256];
static int  ntmpfiles = 0;

static void
cleanup_temps(void)
{
	int i;
	for (i = 0; i < ntmpfiles; i++)
		remove(tmpfiles[i]);
}

static const char *
make_tmpname(const char *origname)
{
	static char buf[256];
	const char *base = strrchr(origname, '/');
	base = base ? base+1 : origname;
	snprintf(buf, sizeof(buf), "/tmp/as_%s_XXXXXX", base);
	/* Plan 9 mktemp — just use a fixed name with pid for simplicity */
	snprintf(buf, sizeof(buf), "/tmp/as_%d_%d.s", (int)getpid(), ntmpfiles);
	strncpy(tmpfiles[ntmpfiles++], buf, 255);
	return buf;
}

/* ------------------------------------------------------------------ */
/* Usage */
/* ------------------------------------------------------------------ */

static void
usage(void)
{
	fprintf(stderr,
		"usage: as [options] file.s ...\n"
		"options:\n"
		"  -o outfile     output file\n"
		"  -att           force AT&T syntax input\n"
		"  -intel         force Intel syntax input\n"
		"  -plan9         force Plan 9 syntax (pass through unmodified)\n"
		"  -m32 / --32    target i386 (use 8a)\n"
		"  -m64 / --64    target amd64 (use 6a) [default]\n"
		"  -I dir         add include directory\n"
		"  -D sym[=val]   define symbol\n"
		"  -v             verbose\n"
	);
	exit(1);
}

/* ------------------------------------------------------------------ */
/* main */
/* ------------------------------------------------------------------ */

int
main(int argc, char *argv[])
{
	int i;
	int status = 0;

	atexit(cleanup_temps);

	/* Parse arguments */
	for (i = 1; i < argc; i++) {
		char *a = argv[i];

		if (strcmp(a, "--") == 0) { i++; break; }

		if (strcmp(a, "-o") == 0) {
			if (++i >= argc) die("-o requires argument");
			outfile = argv[i];
		} else if (strncmp(a, "-o", 2) == 0) {
			outfile = a+2;
		} else if (strcmp(a, "-att") == 0 || strcmp(a, "--att") == 0) {
			syntax = SYN_ATT;
		} else if (strcmp(a, "-intel") == 0 || strcmp(a, "--intel") == 0) {
			syntax = SYN_INTEL;
		} else if (strcmp(a, "-plan9") == 0 || strcmp(a, "--plan9") == 0) {
			syntax = SYN_PLAN9;
		} else if (strcmp(a, "-m32") == 0 || strcmp(a, "--32") == 0) {
			arch = ARCH_386;
		} else if (strcmp(a, "-m64") == 0 || strcmp(a, "--64") == 0) {
			arch = ARCH_AMD64;
		} else if (strcmp(a, "-v") == 0 || strcmp(a, "--verbose") == 0) {
			verbose = 1;
		} else if (strcmp(a, "-I") == 0) {
			if (++i >= argc) die("-I requires argument");
			if (ninc < MAXINC) incdirs[ninc++] = argv[i];
		} else if (strncmp(a, "-I", 2) == 0) {
			if (ninc < MAXINC) incdirs[ninc++] = a+2;
		} else if (strcmp(a, "-D") == 0) {
			if (++i >= argc) die("-D requires argument");
			if (ndef < MAXDEF) defines[ndef++] = argv[i];
		} else if (strncmp(a, "-D", 2) == 0) {
			if (ndef < MAXDEF) defines[ndef++] = a+2;
		} else if (*a == '-') {
			/* Silently ignore other GNU as options we don't care about:
			   --noexecstack, -g, --gdwarf*, --fatal-warnings, etc. */
			if (strcmp(a, "--noexecstack") != 0 &&
			    strcmp(a, "--fatal-warnings") != 0 &&
			    strncmp(a, "--gdwarf", 8) != 0 &&
			    strncmp(a, "-g", 2) != 0 &&
			    strcmp(a, "-W") != 0 &&
			    strcmp(a, "-w") != 0) {
				warn("ignoring unknown option: %s", a);
			}
		} else {
			if (nfiles < MAXFILES) infiles[nfiles++] = a;
		}
	}

	/* Remaining args after -- */
	for (; i < argc; i++)
		if (nfiles < MAXFILES) infiles[nfiles++] = argv[i];

	if (nfiles == 0) usage();

	/* Translate and assemble each file */
	for (i = 0; i < nfiles; i++) {
		Syntax syn = syntax;
		const char *infile = infiles[i];

		if (syn == SYN_AUTO)
			syn = detect_syntax(infile);

		const char *tmpname = make_tmpname(infile);
		translate_file(infile, tmpname, syn);

		/* Determine output file for this input */
		char *thisout = outfile;
		char autout[256];
		if (!thisout && nfiles == 1) {
			thisout = NULL; /* let 6a/8a derive it */
		} else if (!thisout) {
			/* multiple files, no -o: derive from input name */
			strncpy(autout, infile, sizeof(autout)-4);
			char *dot = strrchr(autout, '.');
			if (dot) *dot = '\0';
			/* 6a will produce .6, 8a will produce .8 */
			thisout = NULL;
		}

		int ret = invoke_assembler(tmpname, thisout);
		if (ret != 0) {
			warn("assembler failed for %s (exit %d)", infile, ret);
			status = 1;
		}
	}

	return status;
}
