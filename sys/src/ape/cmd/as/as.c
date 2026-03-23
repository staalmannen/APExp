/*
 * as - GNU assembler syntax front-end for Plan 9 (9front)
 *
 * Translates AT&T (GAS) or Intel syntax assembly to Plan 9 assembly,
 * then invokes the appropriate native Plan 9 assembler.
 *
 * Supported target architectures and their Plan 9 assemblers:
 *   amd64    6a   (default)
 *   386      8a
 *   arm      5a
 *   arm64    7a
 *   ppc64    9a
 *   power    qa   (32-bit PowerPC)
 *   mips     va
 *   sparc    ka
 *   68000    1a
 *   68020    2a
 *
 * Usage:
 *   as [options] file.s ...
 *
 * Architecture selection (default: amd64):
 *   -march=ARCH or -m ARCH   where ARCH is one of the names above
 *   -m32 / --32              alias for -march=386
 *   -m64 / --64              alias for -march=amd64
 *   -marm / -marm64          alias for arm / arm64
 *   -mppc64 / -mpower        alias for ppc64 / power
 *   -mmips / -msparc         alias for mips / sparc
 *   -m68k / -m68020          alias for 68000 / 68020
 *
 * Syntax selection (default: auto-detect):
 *   -att             force AT&T syntax
 *   -intel           force Intel syntax
 *   -plan9           force Plan 9 pass-through
 *
 * Other options (GNU as compatible):
 *   -o outfile       output file
 *   -I dir           add include directory (passed to native assembler)
 *   -D sym[=val]     define symbol (passed to native assembler)
 *   -v               verbose
 *   --               end of options
 *
 * Syntax detection (when not forced):
 *   - ".intel_syntax" in file  → Intel mode
 *   - "%" signs in file        → AT&T mode
 *   - TEXT/DATA/GLOBL/$(SB)    → Plan 9 pass-through
 *   - Default                  → AT&T
 */

#define _GNU_SOURCE
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

typedef enum {
	ARCH_AMD64,   /* 6a */
	ARCH_386,     /* 8a */
	ARCH_ARM,     /* 5a */
	ARCH_ARM64,   /* 7a */
	ARCH_PPC64,   /* 9a */
	ARCH_POWER,   /* qa  (32-bit PowerPC) */
	ARCH_MIPS,    /* va */
	ARCH_SPARC,   /* ka */
	ARCH_68000,   /* 1a */
	ARCH_68020    /* 2a */
} Arch;

typedef enum { SYN_AUTO, SYN_ATT, SYN_INTEL, SYN_PLAN9 } Syntax;

/* Return the Plan 9 assembler name for the current arch */
static const char *
assembler_name(Arch a)
{
	switch(a) {
	case ARCH_AMD64:  return "6a";
	case ARCH_386:    return "8a";
	case ARCH_ARM:    return "5a";
	case ARCH_ARM64:  return "7a";
	case ARCH_PPC64:  return "9a";
	case ARCH_POWER:  return "qa";
	case ARCH_MIPS:   return "va";
	case ARCH_SPARC:  return "ka";
	case ARCH_68000:  return "1a";
	case ARCH_68020:  return "2a";
	}
	return "6a";
}

/* Return 1 if arch uses x86-style register naming (%), 0 for Rn/Fn style */
static int arch_is_x86(Arch a) { return a == ARCH_AMD64 || a == ARCH_386; }
/* Return 1 if arch uses 68k-style Dn/An register naming */
static int arch_is_68k(Arch a) { return a == ARCH_68000 || a == ARCH_68020; }

static Arch   arch         = ARCH_AMD64;
static Syntax syntax       = SYN_AUTO;
static int    verbose      = 0;
static int    convert_only = 0;   /* -S: translate to Plan 9 .s, don't assemble */
static char  *outfile      = NULL;
static char  *incdirs[MAXINC];
static int    ninc         = 0;
static char  *defines[MAXDEF];
static int    ndef         = 0;
static char  *infiles[MAXFILES];
static int    nfiles       = 0;

/* ------------------------------------------------------------------ */
/* Numeric local label resolution                                      */
/* ------------------------------------------------------------------ */

/*
 * GNU GAS allows numeric labels like "1:" to be defined multiple times
 * in a single file.  Jumps use "1f" (next forward definition of "1:")
 * or "1b" (nearest backward definition of "1:").
 *
 * Plan 9 assemblers require every label to be unique.
 *
 * Strategy: two-pass translation.
 *
 * Pass 1 (collect): read the file line by line; every time we see a
 *   numeric label "N:" record its line number and a unique serial
 *   index.  Build a flat array of (linenum, digit, serial).
 *
 * Pass 2 (translate): when emitting a line that contains a numeric
 *   label "N:", replace it with ".Lnum_N_<serial>:".  When we see a
 *   reference "Nf" in an operand, find the first collected label with
 *   digit==N whose line number is > current line.  When we see "Nb",
 *   find the last one with line number < current line.
 */

#define MAX_NUMLABELS 1024

typedef struct {
	int linenum;   /* 1-based line number where "N:" appears */
	int digit;     /* the N in "N:" */
	int serial;    /* unique serial for this occurrence */
} NumLabel;

static NumLabel numlabels[MAX_NUMLABELS];
static int      nnumlabels = 0;

/* serial counter per digit (0..9), used to assign unique serials */
static int numlabel_serial[10];

/*
 * Collect all numeric labels from a file.
 * Called before translation begins.
 */
static void
collect_numlabels(const char *filename)
{
	FILE *f;
	char line[MAXLINE];
	int  lineno = 0;

	nnumlabels = 0;
	memset(numlabel_serial, 0, sizeof(numlabel_serial));

	f = fopen(filename, "r");
	if (!f) return;

	while (fgets(line, sizeof(line), f)) {
		char *p = line;
		lineno++;

		/* skip leading whitespace */
		while (isspace((unsigned char)*p)) p++;

		/* Look for a numeric label: a single digit followed by ':' */
		/* It can appear at start of line or after a previous label+colon */
		while (*p) {
			if (isdigit((unsigned char)*p) && p[1] == ':') {
				int d = *p - '0';
				if (nnumlabels < MAX_NUMLABELS) {
					numlabels[nnumlabels].linenum = lineno;
					numlabels[nnumlabels].digit   = d;
					numlabels[nnumlabels].serial  = numlabel_serial[d]++;
					nnumlabels++;
				}
				/* don't break — there could be more on this line */
				p += 2;
				continue;
			}
			p++;
		}
	}
	fclose(f);
}

/*
 * Given a reference like "1f" or "1b" at the current translation line,
 * return the Plan 9 label name it should resolve to.
 * Returns pointer to a static buffer.
 */
static const char *
resolve_numlabel(int digit, int forward, int cur_lineno)
{
	static char buf[64];
	int i;

	if (forward) {
		/* first label with this digit at a line > cur_lineno */
		for (i = 0; i < nnumlabels; i++) {
			if (numlabels[i].digit == digit &&
			    numlabels[i].linenum > cur_lineno) {
				snprintf(buf, sizeof(buf), ".Lnum%d_%d",
				         digit, numlabels[i].serial);
				return buf;
			}
		}
	} else {
		/* last label with this digit at a line <= cur_lineno */
		for (i = nnumlabels - 1; i >= 0; i--) {
			if (numlabels[i].digit == digit &&
			    numlabels[i].linenum <= cur_lineno) {
				snprintf(buf, sizeof(buf), ".Lnum%d_%d",
				         digit, numlabels[i].serial);
				return buf;
			}
		}
	}

	/* not found — return something that will cause an obvious error */
	snprintf(buf, sizeof(buf), ".Lnum%d_MISSING", digit);
	return buf;
}

/*
 * Translate a numeric label reference in an operand token in-place.
 * e.g. "1f" → ".Lnum1_3"   "2b" → ".Lnum2_1"
 * Modifies out[outsz] to hold the translated operand.
 * cur_lineno: 1-based current line being translated.
 */
static void
translate_numlabel_ref(const char *in, char *out, int outsz, int cur_lineno)
{
	const char *p = in;
	/* skip whitespace */
	while (isspace((unsigned char)*p)) p++;

	/* Pattern: optional sign/hash, then a digit followed by 'f' or 'b' */
	if (isdigit((unsigned char)*p) &&
	    (p[1] == 'f' || p[1] == 'b') &&
	    (p[2] == '\0' || isspace((unsigned char)p[2]))) {
		int d = *p - '0';
		int fwd = (p[1] == 'f');
		const char *resolved = resolve_numlabel(d, fwd, cur_lineno);
		snprintf(out, outsz, "%s", resolved);
		return;
	}
	snprintf(out, outsz, "%s", in);
}

/*
 * Current line number during translation (set by translate_file).
 */
static int cur_lineno = 0;

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

/* Forward declarations (RISC translators reference common utilities) */
static char *trim(char *s);
static void strlower(const char *src, char *buf, int sz);
static const char *lookup_in_table(const RegMap *tab, const char *name);
static int split_operands(const char *s, char ops[][MAXLINE], int maxops);
static void translate_line_att(const char *line, FILE *out);
static const char *resolve_numlabel(int digit, int forward, int cur_lineno);
static const char *translate_opcode(const char *mnem);

/* ================================================================
 * RISC / non-x86 register alias tables
 * ================================================================ */

/*
 * ARM (5a) — r0-r15, ABI aliases, VFP regs
 * Plan 9 5a names: R0-R15, F0-F15, C0-C15 (coprocessor)
 */
static RegMap arm_aliases[] = {
	/* integer registers */
	{ "r0",  "R0"  }, { "r1",  "R1"  }, { "r2",  "R2"  }, { "r3",  "R3"  },
	{ "r4",  "R4"  }, { "r5",  "R5"  }, { "r6",  "R6"  }, { "r7",  "R7"  },
	{ "r8",  "R8"  }, { "r9",  "R9"  }, { "r10", "R10" }, { "r11", "R11" },
	{ "r12", "R12" }, { "r13", "R13" }, { "r14", "R14" }, { "r15", "R15" },
	/* ABI name aliases */
	{ "sp",  "R13" }, /* stack pointer */
	{ "lr",  "R14" }, /* link register */
	{ "pc",  "R15" }, /* program counter */
	{ "ip",  "R12" }, /* intra-procedure scratch */
	{ "fp",  "R11" }, /* frame pointer (Linux EABI) */
	{ "sl",  "R10" }, /* stack limit */
	/* VFP single-precision: GNU s0-s31 pair into Plan 9 F0-F15 */
	{ "s0",  "F0"  }, { "s1",  "F0"  }, { "s2",  "F1"  }, { "s3",  "F1"  },
	{ "s4",  "F2"  }, { "s5",  "F2"  }, { "s6",  "F3"  }, { "s7",  "F3"  },
	{ "s8",  "F4"  }, { "s9",  "F4"  }, { "s10", "F5"  }, { "s11", "F5"  },
	{ "s12", "F6"  }, { "s13", "F6"  }, { "s14", "F7"  }, { "s15", "F7"  },
	{ "s16", "F8"  }, { "s17", "F8"  }, { "s18", "F9"  }, { "s19", "F9"  },
	{ "s20", "F10" }, { "s21", "F10" }, { "s22", "F11" }, { "s23", "F11" },
	{ "s24", "F12" }, { "s25", "F12" }, { "s26", "F13" }, { "s27", "F13" },
	{ "s28", "F14" }, { "s29", "F14" }, { "s30", "F15" }, { "s31", "F15" },
	/* VFP double-precision: GNU d0-d15 → Plan 9 F0-F15 */
	{ "d0",  "F0"  }, { "d1",  "F1"  }, { "d2",  "F2"  }, { "d3",  "F3"  },
	{ "d4",  "F4"  }, { "d5",  "F5"  }, { "d6",  "F6"  }, { "d7",  "F7"  },
	{ "d8",  "F8"  }, { "d9",  "F9"  }, { "d10", "F10" }, { "d11", "F11" },
	{ "d12", "F12" }, { "d13", "F13" }, { "d14", "F14" }, { "d15", "F15" },
	/* status registers */
	{ "cpsr", "CPSR" }, { "spsr", "SPSR" },
	{ "fpsr", "FPSR" }, { "fpcr", "FPCR" },
	{ NULL, NULL }
};

/*
 * ARM64 (7a) — x0-x30/w0-w30, xzr/wzr, sp, v0-v31, d0-d31, s0-s31
 * Plan 9 7a names: R0-R30, ZR(R31), RSP, F0-F31, V0-V31
 */
static RegMap arm64_aliases[] = {
	/* 64-bit x-registers → R0-R30 */
	{ "x0",  "R0"  }, { "x1",  "R1"  }, { "x2",  "R2"  }, { "x3",  "R3"  },
	{ "x4",  "R4"  }, { "x5",  "R5"  }, { "x6",  "R6"  }, { "x7",  "R7"  },
	{ "x8",  "R8"  }, { "x9",  "R9"  }, { "x10", "R10" }, { "x11", "R11" },
	{ "x12", "R12" }, { "x13", "R13" }, { "x14", "R14" }, { "x15", "R15" },
	{ "x16", "R16" }, { "x17", "R17" }, { "x18", "R18" }, { "x19", "R19" },
	{ "x20", "R20" }, { "x21", "R21" }, { "x22", "R22" }, { "x23", "R23" },
	{ "x24", "R24" }, { "x25", "R25" }, { "x26", "R26" }, { "x27", "R27" },
	{ "x28", "R28" }, { "x29", "R29" }, { "x30", "R30" },
	/* 32-bit w-registers → same Rn (assembler infers width from opcode) */
	{ "w0",  "R0"  }, { "w1",  "R1"  }, { "w2",  "R2"  }, { "w3",  "R3"  },
	{ "w4",  "R4"  }, { "w5",  "R5"  }, { "w6",  "R6"  }, { "w7",  "R7"  },
	{ "w8",  "R8"  }, { "w9",  "R9"  }, { "w10", "R10" }, { "w11", "R11" },
	{ "w12", "R12" }, { "w13", "R13" }, { "w14", "R14" }, { "w15", "R15" },
	{ "w16", "R16" }, { "w17", "R17" }, { "w18", "R18" }, { "w19", "R19" },
	{ "w20", "R20" }, { "w21", "R21" }, { "w22", "R22" }, { "w23", "R23" },
	{ "w24", "R24" }, { "w25", "R25" }, { "w26", "R26" }, { "w27", "R27" },
	{ "w28", "R28" }, { "w29", "R29" }, { "w30", "R30" },
	/* zero register, stack pointer, ABI aliases */
	{ "xzr", "ZR"  }, { "wzr", "ZR"  },
	{ "sp",  "RSP" },
	{ "lr",  "R30" }, { "fp",  "R29" },
	/* SIMD/FP: v-regs → V, d/s/h/b-regs → F */
	{ "v0",  "V0"  }, { "v1",  "V1"  }, { "v2",  "V2"  }, { "v3",  "V3"  },
	{ "v4",  "V4"  }, { "v5",  "V5"  }, { "v6",  "V6"  }, { "v7",  "V7"  },
	{ "v8",  "V8"  }, { "v9",  "V9"  }, { "v10", "V10" }, { "v11", "V11" },
	{ "v12", "V12" }, { "v13", "V13" }, { "v14", "V14" }, { "v15", "V15" },
	{ "v16", "V16" }, { "v17", "V17" }, { "v18", "V18" }, { "v19", "V19" },
	{ "v20", "V20" }, { "v21", "V21" }, { "v22", "V22" }, { "v23", "V23" },
	{ "v24", "V24" }, { "v25", "V25" }, { "v26", "V26" }, { "v27", "V27" },
	{ "v28", "V28" }, { "v29", "V29" }, { "v30", "V30" }, { "v31", "V31" },
	{ "d0",  "F0"  }, { "d1",  "F1"  }, { "d2",  "F2"  }, { "d3",  "F3"  },
	{ "d4",  "F4"  }, { "d5",  "F5"  }, { "d6",  "F6"  }, { "d7",  "F7"  },
	{ "d8",  "F8"  }, { "d9",  "F9"  }, { "d10", "F10" }, { "d11", "F11" },
	{ "d12", "F12" }, { "d13", "F13" }, { "d14", "F14" }, { "d15", "F15" },
	{ "d16", "F16" }, { "d17", "F17" }, { "d18", "F18" }, { "d19", "F19" },
	{ "d20", "F20" }, { "d21", "F21" }, { "d22", "F22" }, { "d23", "F23" },
	{ "d24", "F24" }, { "d25", "F25" }, { "d26", "F26" }, { "d27", "F27" },
	{ "d28", "F28" }, { "d29", "F29" }, { "d30", "F30" }, { "d31", "F31" },
	{ "s0",  "F0"  }, { "s1",  "F1"  }, { "s2",  "F2"  }, { "s3",  "F3"  },
	{ "s4",  "F4"  }, { "s5",  "F5"  }, { "s6",  "F6"  }, { "s7",  "F7"  },
	{ "s8",  "F8"  }, { "s9",  "F9"  }, { "s10", "F10" }, { "s11", "F11" },
	{ "s12", "F12" }, { "s13", "F13" }, { "s14", "F14" }, { "s15", "F15" },
	{ "s16", "F16" }, { "s17", "F17" }, { "s18", "F18" }, { "s19", "F19" },
	{ "s20", "F20" }, { "s21", "F21" }, { "s22", "F22" }, { "s23", "F23" },
	{ "s24", "F24" }, { "s25", "F25" }, { "s26", "F26" }, { "s27", "F27" },
	{ "s28", "F28" }, { "s29", "F29" }, { "s30", "F30" }, { "s31", "F31" },
	/* system registers */
	{ "nzcv", "NZCV" }, { "fpcr", "FPCR" }, { "fpsr", "FPSR" },
	{ NULL, NULL }
};

/*
 * MIPS (va) — r0-r31, f0-f31, ABI names
 * Plan 9 va names: R0-R31, F0-F31, M0-M31 (CP0), HI, LO
 * GNU MIPS ABI: $zero/$0, $at, $v0-$v1, $a0-$a3, $t0-$t9,
 *               $s0-$s7, $k0-$k1, $gp, $sp, $fp/$s8, $ra
 */
static RegMap mips_aliases[] = {
	/* numeric names */
	{ "r0",  "R0"  }, { "r1",  "R1"  }, { "r2",  "R2"  }, { "r3",  "R3"  },
	{ "r4",  "R4"  }, { "r5",  "R5"  }, { "r6",  "R6"  }, { "r7",  "R7"  },
	{ "r8",  "R8"  }, { "r9",  "R9"  }, { "r10", "R10" }, { "r11", "R11" },
	{ "r12", "R12" }, { "r13", "R13" }, { "r14", "R14" }, { "r15", "R15" },
	{ "r16", "R16" }, { "r17", "R17" }, { "r18", "R18" }, { "r19", "R19" },
	{ "r20", "R20" }, { "r21", "R21" }, { "r22", "R22" }, { "r23", "R23" },
	{ "r24", "R24" }, { "r25", "R25" }, { "r26", "R26" }, { "r27", "R27" },
	{ "r28", "R28" }, { "r29", "R29" }, { "r30", "R30" }, { "r31", "R31" },
	/* ABI symbolic names (also written with $ prefix in GNU: $zero etc) */
	{ "zero", "R0"  }, { "at",  "R1"  },
	{ "v0",   "R2"  }, { "v1",  "R3"  },
	{ "a0",   "R4"  }, { "a1",  "R5"  }, { "a2",  "R6"  }, { "a3",  "R7"  },
	{ "t0",   "R8"  }, { "t1",  "R9"  }, { "t2",  "R10" }, { "t3",  "R11" },
	{ "t4",   "R12" }, { "t5",  "R13" }, { "t6",  "R14" }, { "t7",  "R15" },
	{ "s0",   "R16" }, { "s1",  "R17" }, { "s2",  "R18" }, { "s3",  "R19" },
	{ "s4",   "R20" }, { "s5",  "R21" }, { "s6",  "R22" }, { "s7",  "R23" },
	{ "t8",   "R24" }, { "t9",  "R25" },
	{ "k0",   "R26" }, { "k1",  "R27" },
	{ "gp",   "R28" }, { "sp",  "R29" }, { "fp",  "R30" }, { "ra",  "R31" },
	/* FP registers */
	{ "f0",  "F0"  }, { "f1",  "F1"  }, { "f2",  "F2"  }, { "f3",  "F3"  },
	{ "f4",  "F4"  }, { "f5",  "F5"  }, { "f6",  "F6"  }, { "f7",  "F7"  },
	{ "f8",  "F8"  }, { "f9",  "F9"  }, { "f10", "F10" }, { "f11", "F11" },
	{ "f12", "F12" }, { "f13", "F13" }, { "f14", "F14" }, { "f15", "F15" },
	{ "f16", "F16" }, { "f17", "F17" }, { "f18", "F18" }, { "f19", "F19" },
	{ "f20", "F20" }, { "f21", "F21" }, { "f22", "F22" }, { "f23", "F23" },
	{ "f24", "F24" }, { "f25", "F25" }, { "f26", "F26" }, { "f27", "F27" },
	{ "f28", "F28" }, { "f29", "F29" }, { "f30", "F30" }, { "f31", "F31" },
	{ NULL, NULL }
};

/*
 * SPARC (ka) — GNU window-based names map to flat R0-R31
 *   %g0-%g7  global   → R0-R7
 *   %o0-%o7  out      → R8-R15   (%o6 = %sp)
 *   %l0-%l7  local    → R16-R23
 *   %i0-%i7  in       → R24-R31  (%i6 = %fp)
 * FP: %f0-%f31 → F0-F31 (ka only defines even-numbered for doubles,
 *     but we map all 32; the assembler enforces alignment)
 */
static RegMap sparc_aliases[] = {
	{ "g0", "R0"  }, { "g1", "R1"  }, { "g2", "R2"  }, { "g3", "R3"  },
	{ "g4", "R4"  }, { "g5", "R5"  }, { "g6", "R6"  }, { "g7", "R7"  },
	{ "o0", "R8"  }, { "o1", "R9"  }, { "o2", "R10" }, { "o3", "R11" },
	{ "o4", "R12" }, { "o5", "R13" }, { "o6", "R14" }, { "o7", "R15" },
	{ "l0", "R16" }, { "l1", "R17" }, { "l2", "R18" }, { "l3", "R19" },
	{ "l4", "R20" }, { "l5", "R21" }, { "l6", "R22" }, { "l7", "R23" },
	{ "i0", "R24" }, { "i1", "R25" }, { "i2", "R26" }, { "i3", "R27" },
	{ "i4", "R28" }, { "i5", "R29" }, { "i6", "R30" }, { "i7", "R31" },
	{ "sp", "R14" }, /* %o6 */
	{ "fp", "R30" }, /* %i6 */
	{ "f0",  "F0"  }, { "f1",  "F1"  }, { "f2",  "F2"  }, { "f3",  "F3"  },
	{ "f4",  "F4"  }, { "f5",  "F5"  }, { "f6",  "F6"  }, { "f7",  "F7"  },
	{ "f8",  "F8"  }, { "f9",  "F9"  }, { "f10", "F10" }, { "f11", "F11" },
	{ "f12", "F12" }, { "f13", "F13" }, { "f14", "F14" }, { "f15", "F15" },
	{ "f16", "F16" }, { "f17", "F17" }, { "f18", "F18" }, { "f19", "F19" },
	{ "f20", "F20" }, { "f21", "F21" }, { "f22", "F22" }, { "f23", "F23" },
	{ "f24", "F24" }, { "f25", "F25" }, { "f26", "F26" }, { "f27", "F27" },
	{ "f28", "F28" }, { "f29", "F29" }, { "f30", "F30" }, { "f31", "F31" },
	/* special registers */
	{ "y",   "Y"   }, { "psr", "PSR" }, { "wim", "WIM" }, { "tbr", "TBR" },
	{ "fsr", "FSR" }, { "csr", "CSR" },
	{ NULL, NULL }
};

/*
 * PowerPC 32-bit (qa) and PPC64 (9a) — identical register namespaces.
 * Plan 9 names: R0-R31, F0-F31, CR0-CR7, LR, CTR, XER, MSR, FPSCR
 * GNU names: r0-r31, f0-f31, cr0-cr7, lr, ctr, xer, msr, fpscr
 */
static RegMap ppc_aliases[] = {
	{ "r0",  "R0"  }, { "r1",  "R1"  }, { "r2",  "R2"  }, { "r3",  "R3"  },
	{ "r4",  "R4"  }, { "r5",  "R5"  }, { "r6",  "R6"  }, { "r7",  "R7"  },
	{ "r8",  "R8"  }, { "r9",  "R9"  }, { "r10", "R10" }, { "r11", "R11" },
	{ "r12", "R12" }, { "r13", "R13" }, { "r14", "R14" }, { "r15", "R15" },
	{ "r16", "R16" }, { "r17", "R17" }, { "r18", "R18" }, { "r19", "R19" },
	{ "r20", "R20" }, { "r21", "R21" }, { "r22", "R22" }, { "r23", "R23" },
	{ "r24", "R24" }, { "r25", "R25" }, { "r26", "R26" }, { "r27", "R27" },
	{ "r28", "R28" }, { "r29", "R29" }, { "r30", "R30" }, { "r31", "R31" },
	/* ABI aliases */
	{ "sp",  "R1"  }, /* stack pointer */
	{ "toc", "R2"  }, /* table of contents (64-bit ABI) */
	{ "f0",  "F0"  }, { "f1",  "F1"  }, { "f2",  "F2"  }, { "f3",  "F3"  },
	{ "f4",  "F4"  }, { "f5",  "F5"  }, { "f6",  "F6"  }, { "f7",  "F7"  },
	{ "f8",  "F8"  }, { "f9",  "F9"  }, { "f10", "F10" }, { "f11", "F11" },
	{ "f12", "F12" }, { "f13", "F13" }, { "f14", "F14" }, { "f15", "F15" },
	{ "f16", "F16" }, { "f17", "F17" }, { "f18", "F18" }, { "f19", "F19" },
	{ "f20", "F20" }, { "f21", "F21" }, { "f22", "F22" }, { "f23", "F23" },
	{ "f24", "F24" }, { "f25", "F25" }, { "f26", "F26" }, { "f27", "F27" },
	{ "f28", "F28" }, { "f29", "F29" }, { "f30", "F30" }, { "f31", "F31" },
	{ "cr0", "CR0" }, { "cr1", "CR1" }, { "cr2", "CR2" }, { "cr3", "CR3" },
	{ "cr4", "CR4" }, { "cr5", "CR5" }, { "cr6", "CR6" }, { "cr7", "CR7" },
	{ "lr",    "LR"    }, { "ctr",   "CTR"   },
	{ "xer",   "XER"   }, { "msr",   "MSR"   },
	{ "fpscr", "FPSCR" },
	{ NULL, NULL }
};

/*
 * MC68000 / MC68020 (1a / 2a)
 * GNU AT&T: %d0-%d7 (data), %a0-%a7 (address), %fp0-%fp7 (float)
 * Plan 9:   R0-R7          A0-A7               F0-F7
 * %a7 = %sp (stack pointer), %a6 = %fp (frame pointer by convention)
 * %pc = PC, %ccr = CCR, %sr = SR
 */
static RegMap m68k_aliases[] = {
	{ "d0", "R0" }, { "d1", "R1" }, { "d2", "R2" }, { "d3", "R3" },
	{ "d4", "R4" }, { "d5", "R5" }, { "d6", "R6" }, { "d7", "R7" },
	{ "a0", "A0" }, { "a1", "A1" }, { "a2", "A2" }, { "a3", "A3" },
	{ "a4", "A4" }, { "a5", "A5" }, { "a6", "A6" }, { "a7", "A7" },
	{ "sp", "A7" }, /* stack pointer = a7 */
	{ "fp", "A6" }, /* frame pointer = a6 by convention */
	{ "fp0", "F0" }, { "fp1", "F1" }, { "fp2", "F2" }, { "fp3", "F3" },
	{ "fp4", "F4" }, { "fp5", "F5" }, { "fp6", "F6" }, { "fp7", "F7" },
	{ "pc",  "PC"  }, { "ccr", "CCR" }, { "sr",  "SR"  },
	{ "usp", "USP" }, { "vbr", "VBR" }, { "sfc", "SFC" }, { "dfc", "DFC" },
	{ "cacr","CACR"}, { "caar","CAAR"}, { "msp", "MSP" }, { "isp", "ISP" },
	{ "fpcr","FPCR"}, { "fpsr","FPSR"}, { "fpiar","FPIAR" },
	{ NULL, NULL }
};
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
	/*
	 * Instructions that NEVER take a size suffix in Plan 9.
	 * These must be listed explicitly so the Intel suffix-adding logic
	 * (which sees "ret"/"nop"/etc. as bare names) does not append Q/L.
	 */
	{ "ret",    "RET"     }, { "retl",   "RET"     }, { "retq",  "RET"  },
	{ "retw",   "RET"     }, { "retf",   "RETF"    }, { "retfq", "RETF" },
	{ "nop",    "NOP"     }, { "nopl",   "NOP"     }, { "nopw",  "NOP"  },
	{ "hlt",    "HLT"     }, { "pause",  "PAUSE"   },
	{ "leave",  "LEAVE"   }, { "leaveq", "LEAVE"   }, { "leavel","LEAVE"},
	{ "cpuid",  "CPUID"   },
	{ "syscall","SYSCALL" }, { "sysret", "SYSRET"  },
	{ "int3",   "INT"     }, { "int",    "INT"      },
	{ "cli",    "CLI"     }, { "sti",    "STI"      },
	{ "cld",    "CLD"     }, { "std",    "STD"      },
	{ "clc",    "CLC"     }, { "stc",    "STC"      }, { "cmc",  "CMC"  },
	{ "pushf",  "PUSHFL"  }, { "pushfq", "PUSHFQ"  }, { "popf", "POPFL"},
	{ "popfq",  "POPFQ"   },
	{ "lahf",   "LAHF"    }, { "sahf",   "SAHF"     },
	{ "cbw",    "CBW"     }, { "cwde",   "CWDE"     }, { "cdqe", "CDQE" },
	{ "cwd",    "CWD"     }, { "cdq",    "CDQ"      }, { "cqo",  "CQO"  },
	/*
	 * x87 FPU: Plan 9 6a has no "FN" (no-wait) prefix variants.
	 * All FPU instructions use the same name regardless of wait/no-wait.
	 * GNU "FNSTSW" → Plan 9 "FSTSW", "FNCLEX" → "FCLEX", etc.
	 * Also note Plan 9 uses FSTSW/FSTCW/FSTENV (no leading F dropped).
	 */
	{ "fnstsw",  "FSTSW"  }, { "fnstsw", "FSTSW"   },
	{ "fnclex",  "FCLEX"  },
	{ "fnstcw",  "FSTCW"  },
	{ "fnstenv", "FSTENV" },
	{ "fnsave",  "FSAVE"  },
	{ "fninit",  "FINIT"  },
	{ "fnop",    "FNOP"   },
	/* GNU "fwait" is an explicit wait — Plan 9 spells it FWAIT */
	{ "fwait",   "FWAIT"  },
	{ NULL, NULL }
};

/* ------------------------------------------------------------------ */
/* ARM64 (7a) opcode special-case table                               */
/* ------------------------------------------------------------------ */

/*
 * ARM64 instructions whose Plan 9 name differs from the GNU uppercase,
 * or whose operand handling needs special treatment.
 *
 * The "special" field is a hint to translate_line_arm64():
 *   0  = just rename, standard operand order (src → dst)
 *   'R' = reverse all operands (GNU dst,s1,s2 → Plan9 s2,s1,dst)
 *   'M' = MRS/MSR: sysreg operand stays first in Plan9
 *   'S' = STP/LDP: register-pair syntax
 *   'B' = B.cond: strip the dot, map condition suffix
 *   'I' = MOV with immediate: add size suffix from register width
 */
typedef struct { const char *gas; const char *p9; int special; } Arm64OpcMap;

static Arm64OpcMap arm64_opcode_map[] = {
	/* system register access — operand order is reversed in Plan9 */
	{ "mrs",   "MRS",   'M' },
	{ "msr",   "MSR",   'M' },
	/* three-operand data processing — GNU: dst,s1,s2 → Plan9: s2,s1,dst */
	{ "bic",   "BIC",   'R' },
	{ "orn",   "ORN",   'R' },
	{ "eon",   "EON",   'R' },
	{ "orr",   "ORR",   'R' },
	{ "and",   "AND",   'R' },
	{ "eor",   "EOR",   'R' },
	{ "add",   "ADD",   'R' },
	{ "adds",  "ADDS",  'R' },
	{ "sub",   "SUB",   'R' },
	{ "subs",  "SUBS",  'R' },
	{ "mul",   "MUL",   'R' },
	{ "udiv",  "UDIV",  'R' },
	{ "sdiv",  "SDIV",  'R' },
	{ "lsl",   "LSL",   'R' },
	{ "lsr",   "LSR",   'R' },
	{ "asr",   "ASR",   'R' },
	{ "ror",   "ROR",   'R' },
	/* two-operand (dst, src) → Plan9 (src, dst) */
	{ "mov",   "MOVD",  'I' },  /* size resolved from register */
	{ "mvn",   "MVN",   0   },
	{ "neg",   "NEG",   0   },
	{ "negs",  "NEGS",  0   },
	/* compare — GNU: reg,imm → Plan9: $imm,reg */
	{ "cmp",   "CMP",   0   },
	{ "cmn",   "CMN",   0   },
	{ "tst",   "TST",   0   },
	/* load/store pairs */
	{ "stp",   "STP",   'S' },
	{ "ldp",   "LDP",   'S' },
	/* conditional branch b.cond */
	{ "b.eq",  "BEQ",   'B' },
	{ "b.ne",  "BNE",   'B' },
	{ "b.cs",  "BCS",   'B' },
	{ "b.cc",  "BCC",   'B' },
	{ "b.hs",  "BCS",   'B' },  /* hs = unsigned >= = cs */
	{ "b.lo",  "BCC",   'B' },  /* lo = unsigned <  = cc */
	{ "b.mi",  "BMI",   'B' },
	{ "b.pl",  "BPL",   'B' },
	{ "b.vs",  "BVS",   'B' },
	{ "b.vc",  "BVC",   'B' },
	{ "b.hi",  "BHI",   'B' },
	{ "b.ls",  "BLS",   'B' },
	{ "b.ge",  "BGE",   'B' },
	{ "b.lt",  "BLT",   'B' },
	{ "b.gt",  "BGT",   'B' },
	{ "b.le",  "BLE",   'B' },
	{ "b.al",  "B",     'B' },
	{ "b.nv",  "B",     'B' },
	/* ret/bl/b — no suffix needed */
	{ "ret",   "RET",   0   },
	{ "bl",    "BL",    0   },
	{ "blr",   "BLR",   0   },
	{ "b",     "B",     0   },
	{ "br",    "B",     0   },
	/* load/store */
	{ "ldr",   "MOVD",  'I' },
	{ "ldrw",  "MOVW",  0   },
	{ "ldrh",  "MOVH",  0   },
	{ "ldrb",  "MOVB",  0   },
	{ "str",   "MOVD",  'I' },
	{ "strw",  "MOVW",  0   },
	{ "strh",  "MOVH",  0   },
	{ "strb",  "MOVB",  0   },
	/* NOP */
	{ "nop",   "NOP",   0   },
	{ NULL, NULL, 0 }
};

/*
 * Determine Plan 9 size suffix for an ARM64 register name.
 * w-registers → 'W' (32-bit), x-registers → 'D' (64-bit), others → 'D'.
 */
static char
arm64_reg_suffix(const char *regname)
{
	char low[32];
	strlower(regname, low, sizeof(low));
	if (low[0] == 'w') return 'W';
	return 'D';
}

/*
 * Translate a single ARM64 register token (no % prefix in GNU ARM64).
 * Input: "x0", "w1", "xzr", "sp", "fpcr", "fpsr", etc.
 * Output: Plan9 form in buf.
 */
static void
translate_arm64_reg(const char *in, char *out, int outsz)
{
	char low[32];
	const char *r;

	while (isspace((unsigned char)*in)) in++;
	strlower(in, low, sizeof(low));
	/* strip trailing non-alnum (e.g. comma remnants) */
	char *e = low;
	while (*e && (isalnum((unsigned char)*e) || *e == '_')) e++;
	*e = '\0';

	r = lookup_in_table(arm64_aliases, low);
	if (r) { snprintf(out, outsz, "%s", r); return; }
	/* system registers: fpcr, fpsr — pass uppercase */
	if (strcmp(low, "fpcr") == 0) { snprintf(out, outsz, "FPCR"); return; }
	if (strcmp(low, "fpsr") == 0) { snprintf(out, outsz, "FPSR"); return; }
	if (strcmp(low, "nzcv") == 0) { snprintf(out, outsz, "NZCV"); return; }
	/* fallback: uppercase */
	char tmp[32];
	int i;
	for (i = 0; low[i] && i < (int)sizeof(tmp)-1; i++)
		tmp[i] = toupper((unsigned char)low[i]);
	tmp[i] = '\0';
	snprintf(out, outsz, "%s", tmp);
}

/*
 * Translate an ARM64 memory operand "[xN]" or "[xN, #off]" → "off(RN)".
 */
static void
translate_arm64_mem(const char *in, char *out, int outsz)
{
	char inner[256];
	const char *p = in;
	char *q = inner;

	while (*p == '[' || isspace((unsigned char)*p)) p++;
	while (*p && *p != ']') *q++ = *p++;
	*q = '\0';
	trim(inner);

	/* split on comma */
	char *comma = strchr(inner, ',');
	char base_s[64] = "", off_s[64] = "0";
	if (comma) {
		*comma = '\0';
		strncpy(base_s, trim(inner),  sizeof(base_s)-1);
		strncpy(off_s,  trim(comma+1), sizeof(off_s)-1);
		/* strip leading # from immediate offset */
		char *os = off_s;
		while (isspace((unsigned char)*os)) os++;
		if (*os == '#') memmove(off_s, os+1, strlen(os));
	} else {
		strncpy(base_s, trim(inner), sizeof(base_s)-1);
	}

	char base_p9[32];
	translate_arm64_reg(base_s, base_p9, sizeof(base_p9));
	snprintf(out, outsz, "%s(%s)", off_s, base_p9);
}

/*
 * Translate a single ARM64 operand token.
 * Could be: register, #immediate, [mem], or label.
 */
static void
translate_arm64_operand(const char *in, char *out, int outsz)
{
	const char *p = in;
	while (isspace((unsigned char)*p)) p++;

	/* immediate: #N */
	if (*p == '#') {
		snprintf(out, outsz, "$%s", p+1);
		return;
	}
	/* memory: [base, ...] */
	if (*p == '[') {
		translate_arm64_mem(p, out, outsz);
		return;
	}
	/* numeric label ref */
	if (isdigit((unsigned char)*p) &&
	    (p[1] == 'f' || p[1] == 'b') &&
	    (p[2] == '\0' || isspace((unsigned char)p[2]))) {
		int d = *p - '0';
		int fwd = (p[1] == 'f');
		snprintf(out, outsz, "%s", resolve_numlabel(d, fwd, cur_lineno));
		return;
	}
	/* register */
	translate_arm64_reg(p, out, outsz);
}

/*
 * Translate a full ARM64 assembly line to Plan 9.
 */
static void
translate_line_arm64(const char *line, FILE *out)
{
	char buf[MAXLINE];
	strncpy(buf, line, sizeof(buf)-1);
	char *p = buf;
	static int in_block_comment = 0;

	/* block comment continuation */
	if (in_block_comment) {
		char *end = strstr(p, "*/");
		if (end) { in_block_comment = 0; p = end + 2; }
		else { fprintf(out, "\n"); return; }
	}

	/* strip line and block comments */
	{
		char *lc = strstr(p, "//");
		if (lc) *lc = '\0';
		char *bc = strstr(p, "/*");
		if (bc) {
			char *ec = strstr(bc+2, "*/");
			if (ec) { memmove(bc, ec+2, strlen(ec+2)+1); }
			else { in_block_comment = 1; *bc = '\0'; }
		}
	}

	p = trim(p);
	if (!*p) { fprintf(out, "\n"); return; }

	/* preprocessor */
	if (*p == '#') { fprintf(out, "%s\n", p); return; }

	/* label */
	char *colon = strchr(p, ':');
	if (colon) {
		int llen = colon - p;
		char lbl[256] = "";
		if (llen < (int)sizeof(lbl)-1 && llen > 0) {
			memcpy(lbl, p, llen);
			lbl[llen] = '\0';
			int ok = 1;
			for (int i = 0; lbl[i]; i++)
				if (!isalnum((unsigned char)lbl[i]) && lbl[i] != '_' && lbl[i] != '.')
					{ ok = 0; break; }
			if (ok) {
				/* numeric label? */
				if (llen == 1 && isdigit((unsigned char)lbl[0])) {
					int d = lbl[0] - '0';
					int serial = -1;
					for (int j = 0; j < nnumlabels; j++) {
						if (numlabels[j].digit == d &&
						    numlabels[j].linenum == cur_lineno) {
							serial = numlabels[j].serial;
							break;
						}
					}
					if (serial >= 0)
						snprintf(lbl, sizeof(lbl), ".Lnum%d_%d", d, serial);
				}
				fprintf(out, "%s:\n", lbl);
				p = colon + 1;
				while (isspace((unsigned char)*p)) p++;
			}
		}
	}
	if (!*p) return;

	/* directives */
	if (*p == '.') {
		/* reuse AT&T directive handler */
		translate_line_att(p, out);
		return;
	}

	/* extract mnemonic (may contain dot: b.eq) */
	char mnem[32] = "";
	int  mi = 0;
	while (*p && !isspace((unsigned char)*p) && mi < (int)sizeof(mnem)-1)
		mnem[mi++] = *p++;
	mnem[mi] = '\0';
	while (isspace((unsigned char)*p)) p++;

	/* split operands */
	char ops[8][MAXLINE];
	int  nops = split_operands(p, ops, 8);

	/* look up in arm64 opcode table */
	char mlow[32];
	strlower(mnem, mlow, sizeof(mlow));
	int found = 0;
	int special = 0;
	const char *p9op = NULL;
	for (int i = 0; arm64_opcode_map[i].gas; i++) {
		if (strcmp(arm64_opcode_map[i].gas, mlow) == 0) {
			p9op   = arm64_opcode_map[i].p9;
			special = arm64_opcode_map[i].special;
			found  = 1;
			break;
		}
	}
	if (!found) {
		/* default: uppercase */
		static char ubuf[32];
		int i;
		for (i = 0; mlow[i] && i < (int)sizeof(ubuf)-1; i++)
			ubuf[i] = toupper((unsigned char)mlow[i]);
		ubuf[i] = '\0';
		p9op = ubuf;
	}

	char tops[8][MAXLINE];

	switch (special) {
	case 'M':
		/*
		 * MRS/MSR: in GNU, "mrs xN, sysreg" / "msr sysreg, xN"
		 * Plan9 7a wants: "MRS SYSREG, RN" / "MSR RN, SYSREG"
		 * i.e. sysreg is always first in Plan9.
		 * GNU MRS: ops[0]=dst-reg, ops[1]=sysreg → swap
		 * GNU MSR: ops[0]=sysreg, ops[1]=src-reg → keep order
		 */
		if (nops == 2) {
			char t0[MAXLINE], t1[MAXLINE];
			translate_arm64_operand(ops[0], t0, MAXLINE);
			translate_arm64_operand(ops[1], t1, MAXLINE);
			if (strcmp(mlow, "mrs") == 0)
				/* GNU: dst, sysreg → Plan9: sysreg, dst */
				fprintf(out, "\t%s\t%s, %s\n", p9op, t1, t0);
			else
				/* GNU: sysreg, src → Plan9: src, sysreg — keep */
				fprintf(out, "\t%s\t%s, %s\n", p9op, t0, t1);
		} else {
			fprintf(out, "\t%s\n", p9op);
		}
		return;

	case 'R':
		/*
		 * Three-operand data-processing: GNU: dst, s1, s2 → Plan9: s2, s1, dst
		 * Two-operand: dst, src → Plan9: src, dst
		 */
		for (int i = 0; i < nops; i++)
			translate_arm64_operand(ops[i], tops[i], MAXLINE);
		if (nops == 3)
			fprintf(out, "\t%s\t%s, %s, %s\n", p9op, tops[2], tops[1], tops[0]);
		else if (nops == 2)
			fprintf(out, "\t%s\t%s, %s\n", p9op, tops[1], tops[0]);
		else
			fprintf(out, "\t%s\n", p9op);
		return;

	case 'I': {
		/*
		 * MOV/LDR/STR with size from register width.
		 * GNU MOV: dst, src — Plan9: src, dst (reversed)
		 * Size: w-reg → MOVW, x-reg → MOVD
		 */
		static char ibuf[32];
		/* determine size from first operand (dst in GNU) */
		char low0[32];
		strlower(ops[0], low0, sizeof(low0));
		char sfx = arm64_reg_suffix(low0);
		snprintf(ibuf, sizeof(ibuf), "MOV%c", sfx);
		p9op = ibuf;
		for (int i = 0; i < nops; i++)
			translate_arm64_operand(ops[i], tops[i], MAXLINE);
		if (nops == 2)
			fprintf(out, "\t%s\t%s, %s\n", p9op, tops[1], tops[0]);
		else {
			fprintf(out, "\t%s", p9op);
			for (int i = 0; i < nops; i++)
				fprintf(out, "%s%s", i==0?"\t":", ", tops[i]);
			fprintf(out, "\n");
		}
		return;
	}

	case 'S':
		/*
		 * STP/LDP register-pair syntax.
		 * GNU STP: "stp w1, w2, [x0]"   → Plan9: "STP (R1, R2), 0(R0)"
		 * GNU LDP: "ldp w1, w2, [x0]"   → Plan9: "LDP 0(R0), (R1, R2)"
		 */
		if (nops == 3) {
			char r1[32], r2[32], mem[64];
			translate_arm64_operand(ops[0], r1,  sizeof(r1));
			translate_arm64_operand(ops[1], r2,  sizeof(r2));
			translate_arm64_mem(ops[2], mem, sizeof(mem));
			if (strcmp(mlow, "stp") == 0)
				fprintf(out, "\tSTP\t(%s, %s), %s\n", r1, r2, mem);
			else
				fprintf(out, "\tLDP\t%s, (%s, %s)\n", mem, r1, r2);
		} else {
			fprintf(out, "\t%s", p9op);
			for (int i = 0; i < nops; i++) {
				translate_arm64_operand(ops[i], tops[i], MAXLINE);
				fprintf(out, "%s%s", i==0?"\t":", ", tops[i]);
			}
			fprintf(out, "\n");
		}
		return;

	case 'B':
		/* B.cond label — already looked up the Plan9 mnemonic (BEQ etc.) */
		if (nops == 1) {
			char ltmp[MAXLINE];
			translate_arm64_operand(ops[0], ltmp, MAXLINE);
			fprintf(out, "\t%s\t%s\n", p9op, ltmp);
		} else {
			fprintf(out, "\t%s\n", p9op);
		}
		return;

	default:
		/*
		 * Standard: CMP, CMN, TST — GNU: reg, #imm → Plan9: $imm, reg
		 * Other two-operand: GNU src,dst order (RISC is opposite of x86 Intel)
		 * For ARM64 GNU AT&T-like: most two-operand: dst, src → Plan9: src, dst
		 */
		for (int i = 0; i < nops; i++)
			translate_arm64_operand(ops[i], tops[i], MAXLINE);
		/* CMP/CMN/TST: keep as-is (reg first is already right for Plan9 after swap) */
		if (nops == 2) {
			/* GNU: dst, src → Plan9: src, dst */
			fprintf(out, "\t%s\t%s, %s\n", p9op, tops[1], tops[0]);
		} else if (nops == 1) {
			fprintf(out, "\t%s\t%s\n", p9op, tops[0]);
		} else if (nops == 0) {
			fprintf(out, "\t%s\n", p9op);
		} else {
			fprintf(out, "\t%s", p9op);
			for (int i = 0; i < nops; i++)
				fprintf(out, "%s%s", i==0?"\t":", ", tops[i]);
			fprintf(out, "\n");
		}
		return;
	}
}

/* ------------------------------------------------------------------ */
/* MIPS (va) special translation                                      */
/* ------------------------------------------------------------------ */

/*
 * MIPS GNU uses $N (numeric) or $name for registers.
 * The translate_operand_att path handles %-prefixed regs; for MIPS
 * we need to handle $-prefixed operands separately.
 *
 * Also handles: li, jr, lw, sw, cfc1, ctc1, andi, ori, xori, addiu, beq.
 */

/* Map a MIPS $reg token (without $) to a Plan9 name */
static const char *
lookup_mips_dollar_reg(const char *name)
{
	char low[32];
	strlower(name, low, sizeof(low));
	/* numeric: $0..$31 */
	if (isdigit((unsigned char)low[0])) {
		char *end;
		long n = strtol(low, &end, 10);
		if (end != low && *end == '\0' && n >= 0 && n <= 31) {
			static char buf[8];
			snprintf(buf, sizeof(buf), "R%ld", n);
			return buf;
		}
	}
	/* named */
	return lookup_in_table(mips_aliases, low);
}

/*
 * Translate a MIPS operand token.
 * Could be: $reg, $name, number (bare immediate), N($reg) (memory).
 */
static void
translate_mips_operand(const char *in, char *out, int outsz)
{
	const char *p = in;
	while (isspace((unsigned char)*p)) p++;

	/* $register */
	if (*p == '$') {
		char rname[32];
		const char *rp = p+1;
		int i = 0;
		while (*rp && (isalnum((unsigned char)*rp) || *rp=='_') && i < (int)sizeof(rname)-1)
			rname[i++] = *rp++;
		rname[i] = '\0';
		const char *r = lookup_mips_dollar_reg(rname);
		if (r) { snprintf(out, outsz, "%s", r); return; }
		snprintf(out, outsz, "%s", p); /* unknown, pass through */
		return;
	}

	/* memory: N($reg) */
	if (strchr(p, '(')) {
		char disp[64] = "0", base[32] = "";
		const char *q = p;
		char *dp = disp;
		while (*q && *q != '(') *dp++ = *q++;
		*dp = '\0';
		if (*q == '(') {
			q++;
			char rname[32]; int i = 0;
			/* strip $ */
			if (*q == '$') q++;
			while (*q && *q != ')' && i < (int)sizeof(rname)-1)
				rname[i++] = *q++;
			rname[i] = '\0';
			const char *r = lookup_mips_dollar_reg(rname);
			snprintf(base, sizeof(base), "%s", r ? r : rname);
		}
		trim(disp);
		if (!*disp || strcmp(disp,"0")==0)
			snprintf(out, outsz, "0(%s)", base);
		else
			snprintf(out, outsz, "%s(%s)", disp, base);
		return;
	}

	/* numeric label ref */
	if (isdigit((unsigned char)*p) &&
	    (p[1] == 'f' || p[1] == 'b') &&
	    (p[2] == '\0' || isspace((unsigned char)p[2]))) {
		int d = *p - '0';
		int fwd = (p[1] == 'f');
		snprintf(out, outsz, "%s", resolve_numlabel(d, fwd, cur_lineno));
		return;
	}

	/* bare immediate (hex or decimal) — add $ */
	{
		char *end;
		strtol(p, &end, 0);
		if (end != p && (*end == '\0' || isspace((unsigned char)*end))) {
			snprintf(out, outsz, "$%s", p);
			return;
		}
	}

	/* label or symbol */
	snprintf(out, outsz, "%s", p);
}

/*
 * Translate a MIPS/va instruction line to Plan 9.
 */
static void
translate_line_mips(const char *line, FILE *out)
{
	char buf[MAXLINE];
	strncpy(buf, line, sizeof(buf)-1);
	char *p = buf;
	static int in_block_comment = 0;

	if (in_block_comment) {
		char *end = strstr(p, "*/");
		if (end) { in_block_comment = 0; p = end+2; }
		else { fprintf(out, "\n"); return; }
	}

	/* strip comments */
	{
		char *hsh = strchr(p, '#');
		/* Don't strip # that starts a preprocessor line */
		char *tp = p;
		while (isspace((unsigned char)*tp)) tp++;
		if (hsh && hsh != tp) *hsh = '\0';
		char *lc = strstr(p, "//");
		if (lc) *lc = '\0';
		char *bc = strstr(p, "/*");
		if (bc) {
			char *ec = strstr(bc+2, "*/");
			if (ec) memmove(bc, ec+2, strlen(ec+2)+1);
			else { in_block_comment = 1; *bc = '\0'; }
		}
	}

	p = trim(p);
	if (!*p) { fprintf(out, "\n"); return; }

	/* preprocessor */
	if (*p == '#') { fprintf(out, "%s\n", p); return; }

	/* label */
	char *colon = strchr(p, ':');
	if (colon) {
		int llen = colon - p;
		char lbl[256] = "";
		if (llen < (int)sizeof(lbl)-1 && llen > 0) {
			memcpy(lbl, p, llen); lbl[llen] = '\0';
			int ok = 1;
			for (int i = 0; lbl[i]; i++)
				if (!isalnum((unsigned char)lbl[i]) && lbl[i]!='_' && lbl[i]!='.')
					{ ok = 0; break; }
			if (ok) {
				if (llen == 1 && isdigit((unsigned char)lbl[0])) {
					int d = lbl[0] - '0', serial = -1;
					for (int j = 0; j < nnumlabels; j++)
						if (numlabels[j].digit==d && numlabels[j].linenum==cur_lineno)
							{ serial=numlabels[j].serial; break; }
					if (serial >= 0) snprintf(lbl, sizeof(lbl), ".Lnum%d_%d", d, serial);
				}
				fprintf(out, "%s:\n", lbl);
				p = colon+1;
				while (isspace((unsigned char)*p)) p++;
			}
		}
	}
	if (!*p) return;

	/* directives */
	if (*p == '.') { translate_line_att(p, out); return; }

	/* extract mnemonic */
	char mnem[32] = "";
	int mi = 0;
	while (*p && !isspace((unsigned char)*p) && mi < (int)sizeof(mnem)-1)
		mnem[mi++] = *p++;
	mnem[mi] = '\0';
	while (isspace((unsigned char)*p)) p++;

	char mlow[32];
	strlower(mnem, mlow, sizeof(mlow));

	/* split operands */
	char ops[8][MAXLINE];
	int nops = split_operands(p, ops, 8);

	char tops[8][MAXLINE];
	for (int i = 0; i < nops; i++)
		translate_mips_operand(ops[i], tops[i], MAXLINE);

	/*
	 * MIPS special instruction translations:
	 */

	/* jr $ra → RET */
	if (strcmp(mlow, "jr") == 0 && nops == 1 &&
	    (strcmp(tops[0], "R31") == 0 || strcmp(tops[0], "RA") == 0)) {
		fprintf(out, "\tRET\n");
		return;
	}
	/* jr $reg → JMP (reg) */
	if (strcmp(mlow, "jr") == 0 && nops == 1) {
		fprintf(out, "\tJMP\t(%s)\n", tops[0]);
		return;
	}

	/* li $dst, imm → MOVW $imm, Rdst */
	if (strcmp(mlow, "li") == 0 && nops == 2) {
		fprintf(out, "\tMOVW\t%s, %s\n", tops[1], tops[0]);
		return;
	}

	/* lw $dst, off($base) → MOVW off(Rbase), Rdst */
	if (strcmp(mlow, "lw") == 0 && nops == 2) {
		fprintf(out, "\tMOVW\t%s, %s\n", tops[1], tops[0]);
		return;
	}
	/* sw $src, off($base) → MOVW Rsrc, off(Rbase) */
	if (strcmp(mlow, "sw") == 0 && nops == 2) {
		fprintf(out, "\tMOVW\t%s, %s\n", tops[0], tops[1]);
		return;
	}

	/* cfc1 $dst, $31 → MOVW FCR31, Rdst */
	if (strcmp(mlow, "cfc1") == 0 && nops == 2) {
		/* ops[1] is the FP control reg number (usually $31) */
		char fcrname[16];
		snprintf(fcrname, sizeof(fcrname), "FCR%s",
		         ops[1][0]=='$' ? ops[1]+1 : ops[1]);
		/* uppercase fcrname */
		for (int i = 0; fcrname[i]; i++)
			fcrname[i] = toupper((unsigned char)fcrname[i]);
		fprintf(out, "\tMOVW\t%s, %s\n", fcrname, tops[0]);
		return;
	}
	/* ctc1 $src, $31 → MOVW Rsrc, FCR31 */
	if (strcmp(mlow, "ctc1") == 0 && nops == 2) {
		char fcrname[16];
		snprintf(fcrname, sizeof(fcrname), "FCR%s",
		         ops[1][0]=='$' ? ops[1]+1 : ops[1]);
		for (int i = 0; fcrname[i]; i++)
			fcrname[i] = toupper((unsigned char)fcrname[i]);
		fprintf(out, "\tMOVW\t%s, %s\n", tops[0], fcrname);
		return;
	}

	/* andi/ori/xori $dst,$src,imm → AND/OR/XOR $imm, Rsrc, Rdst */
	if ((strcmp(mlow,"andi")==0 || strcmp(mlow,"ori")==0 || strcmp(mlow,"xori")==0)
	    && nops == 3) {
		const char *p9 = (mlow[0]=='a') ? "AND" : (mlow[0]=='o') ? "OR" : "XOR";
		fprintf(out, "\t%s\t%s, %s, %s\n", p9, tops[2], tops[1], tops[0]);
		return;
	}

	/* addiu $dst, $src, imm → ADD $imm, Rsrc, Rdst */
	if ((strcmp(mlow,"addiu")==0 || strcmp(mlow,"addi")==0) && nops == 3) {
		fprintf(out, "\tADD\t%s, %s, %s\n", tops[2], tops[1], tops[0]);
		return;
	}

	/* beq $r1, $r2, label → BEQ R1, R2, label  (Plan9 va: BEQ Rsrc, label) */
	if (strcmp(mlow,"beq")==0 && nops == 3) {
		/* Plan9 va: BEQ doesn't take two-register form cleanly;
		 * if $r2 == $0 emit "BEQ Rsrc, label", else emit a comment warning */
		if (strcmp(tops[1],"R0")==0)
			fprintf(out, "\tBEQ\t%s, %s\n", tops[0], tops[2]);
		else
			fprintf(out, "\tBEQ\t%s, %s\t// was: beq %s, %s, %s\n",
			        tops[0], tops[2], ops[0], ops[1], ops[2]);
		return;
	}

	/* nop (in delay slot) */
	if (strcmp(mlow, "nop") == 0) { fprintf(out, "\tNOP\n"); return; }

	/* three-operand: and/or/xor/add/sub $dst, $s1, $s2 → OP Rs2, Rs1, Rdst
	 * MIPS GNU: dst, s1, s2 (like ARM)
	 * Plan9 va: s2, s1, dst (reversed) for three-operand, or s, dst for two */
	if (nops == 3) {
		const char *p9op = translate_opcode(mnem); /* uppercase */
		fprintf(out, "\t%s\t%s, %s, %s\n", p9op, tops[2], tops[1], tops[0]);
		return;
	}

	/* default: uppercase, keep operand order */
	{
		const char *p9op = translate_opcode(mnem);
		fprintf(out, "\t%s", p9op);
		for (int i = 0; i < nops; i++)
			fprintf(out, "%s%s", i==0?"\t":", ", tops[i]);
		fprintf(out, "\n");
	}
}

/* ------------------------------------------------------------------ */
/* PowerPC (9a/qa) special translation                                */
/* ------------------------------------------------------------------ */

/*
 * PPC GNU uses bare integer register numbers with no prefix: "3", "9", "1".
 * Context distinguishes registers from immediates: in "addi 1,1,16",
 * the first two "1"s are R1 (register), the third is 16 (immediate).
 * This is instruction-specific.  We use a per-opcode operand-type table.
 *
 * Strategy: for each opcode, define which operand positions are registers
 * vs immediates.  Positions not listed are treated as immediates (get $).
 * 'r' = register, 'i' = immediate, 'm' = memory disp(reg), 'f' = FP reg.
 */

typedef struct {
	const char *gas;
	const char *p9;
	const char *optypes; /* string of 'r','i','f','m' per operand; NULL=all-regs */
	int reverse;         /* 1 = reverse operand order for Plan9 */
} PPCOpcMap;

static PPCOpcMap ppc_opcode_map[] = {
	/* data movement */
	{ "li",    "MOVW",  "ri",  1 },  /* li Rdst, imm → MOVW $imm, Rdst */
	{ "lis",   "MOVW",  "ri",  1 },  /* lis Rdst, imm (high) */
	{ "mr",    "MOVW",  "rr",  1 },  /* mr Rdst, Rsrc → MOVW Rsrc, Rdst */
	{ "mflr",  "MOVW",  "r",   0 },  /* mflr Rdst — special, emits MOVW LR, Rdst */
	{ "mtlr",  "MOVW",  "r",   0 },  /* mtlr Rsrc — special, emits MOVW Rsrc, LR */
	{ "mfctr", "MOVW",  "r",   0 },
	{ "mtctr", "MOVW",  "r",   0 },
	{ "mffs",  "FMOVD", "f",   0 },  /* mffs Fdst — FMOVD FPSCR, Fdst */
	{ "mtfsf", "MTFSF", "if",  0 },  /* mtfsf mask, Fsrc */
	/* load/store */
	{ "lwz",   "MOVWZ", "rm",  1 },  /* lwz Rdst, off(Rbase) → MOVWZ off(Rbase),Rdst */
	{ "lfd",   "FMOVD", "fm",  1 },  /* lfd Fdst, off(Rbase) → FMOVD off(Rbase),Fdst */
	{ "stw",   "MOVW",  "rm",  0 },  /* stw Rsrc, off(Rbase) → MOVW Rsrc, off(Rbase) */
	{ "stfd",  "FMOVD", "fm",  0 },  /* stfd Fsrc, off(Rbase) → FMOVD Fsrc, off(Rbase) */
	{ "stwu",  "MOVWU", "rm",  0 },  /* stwu Rsrc, off(Rbase) */
	/* arithmetic */
	{ "addi",  "ADD",   "rri", 0 },  /* addi Rdst, Rs1, imm → ADD $imm, Rs1, Rdst */
	{ "addis", "ADDIS", "rri", 0 },
	{ "add",   "ADD",   "rrr", 0 },  /* add Rdst, Rs1, Rs2 → ADD Rs2, Rs1, Rdst */
	{ "subf",  "SUB",   "rrr", 0 },
	/* logical */
	{ "and",   "AND",   "rrr", 0 },
	{ "andc",  "ANDN",  "rrr", 0 },
	{ "or",    "OR",    "rrr", 0 },
	{ "xor",   "XOR",   "rrr", 0 },
	{ "ori",   "OR",    "rri", 0 },
	{ "oris",  "ORIS",  "rri", 0 },
	{ "andi",  "AND",   "rri", 0 },  /* andi. handled via dot stripping */
	{ "andis", "ANDIS", "rri", 0 },
	{ "nor",   "NOR",   "rrr", 0 },
	/* shift/rotate */
	{ "slwi",  "SLW",   "rri", 0 },
	{ "srwi",  "SRW",   "rri", 0 },
	{ "srawi", "SRAW",  "rri", 0 },
	{ "clrlwi","RLWNM", "rri", 0 }, /* simplified — emit RLWNM comment */
	{ "clrrwi","RLWNM", "rri", 0 },
	/* compare */
	{ "cmpwi", "CMPW",  "ri",  1 },  /* cmpwi Rsrc, imm → CMPW $imm, Rsrc */
	{ "cmpw",  "CMPW",  "rr",  1 },
	{ "cmplwi","CMPU",  "ri",  1 },
	{ "cmplw", "CMPU",  "rr",  1 },
	/* branch */
	{ "b",     "BR",    NULL,  0 },
	{ "bl",    "BL",    NULL,  0 },
	{ "blr",   "RET",   NULL,  0 },
	{ "bctr",  "BL",    NULL,  0 },  /* branch to CTR */
	{ "bctrl", "BL",    NULL,  0 },
	{ "beq",   "BEQ",   NULL,  0 },
	{ "bne",   "BNE",   NULL,  0 },
	{ "blt",   "BLT",   NULL,  0 },
	{ "bgt",   "BGT",   NULL,  0 },
	{ "ble",   "BLE",   NULL,  0 },
	{ "bge",   "BGE",   NULL,  0 },
	{ "bso",   "BVS",   NULL,  0 },
	/* NOP */
	{ "nop",   "NOP",   NULL,  0 },
	{ NULL, NULL, NULL, 0 }
};

/*
 * Translate a PPC operand.
 * type: 'r' = register (bare number → R#), 'f' = FP reg (bare → F#),
 *       'i' = immediate (bare number gets $), 'm' = disp(reg).
 */
static void
translate_ppc_operand(const char *in, char type, char *out, int outsz)
{
	const char *p = in;
	while (isspace((unsigned char)*p)) p++;

	/* already has $ or R prefix from prior processing? pass through */
	if (*p == '$' || *p == 'R' || *p == 'F') {
		snprintf(out, outsz, "%s", p);
		return;
	}

	/* memory: N(M) */
	if (strchr(p, '(') && type == 'm') {
		char disp[64]="0", base[32]="";
		const char *q = p;
		char *dp = disp;
		while (*q && *q != '(') *dp++ = *q++;
		*dp = '\0';
		if (*q == '(') {
			q++;
			char rn[16]; int i=0;
			while (*q && *q != ')' && i < (int)sizeof(rn)-1)
				rn[i++] = *q++;
			rn[i] = '\0';
			/* bare number → R# */
			char *end; long rv = strtol(rn, &end, 10);
			if (end != rn && *end == '\0')
				snprintf(base, sizeof(base), "R%ld", rv);
			else {
				/* named reg */
				const char *r2 = lookup_in_table(ppc_aliases, rn);
				snprintf(base, sizeof(base), "%s", r2 ? r2 : rn);
			}
		}
		trim(disp);
		snprintf(out, outsz, "%s(%s)", *disp ? disp : "0", base);
		return;
	}

	/* numeric label ref */
	if (isdigit((unsigned char)*p) &&
	    (p[1] == 'f' || p[1] == 'b') &&
	    (p[2] == '\0' || isspace((unsigned char)p[2]))) {
		int d = *p - '0';
		int fwd = (p[1] == 'f');
		snprintf(out, outsz, "%s", resolve_numlabel(d, fwd, cur_lineno));
		return;
	}

	/* bare number */
	{
		char *end;
		long v = strtol(p, &end, 0);
		if (end != p && (*end == '\0' || isspace((unsigned char)*end))) {
			if (type == 'r')
				snprintf(out, outsz, "R%ld", v);
			else if (type == 'f')
				snprintf(out, outsz, "F%ld", v);
			else
				snprintf(out, outsz, "$%ld", v);
			return;
		}
	}

	/* named register or label */
	{
		char low[32];
		strlower(p, low, sizeof(low));
		const char *r2 = lookup_in_table(ppc_aliases, low);
		if (r2) { snprintf(out, outsz, "%s", r2); return; }
	}

	snprintf(out, outsz, "%s", p);
}

/*
 * Translate a PPC/9a instruction line to Plan 9.
 */
static void
translate_line_ppc(const char *line, FILE *out)
{
	char buf[MAXLINE];
	strncpy(buf, line, sizeof(buf)-1);
	char *p = buf;
	static int in_block_comment = 0;

	if (in_block_comment) {
		char *end = strstr(p, "*/");
		if (end) { in_block_comment = 0; p = end+2; }
		else { fprintf(out, "\n"); return; }
	}

	/* strip comments */
	{
		char *lc = strstr(p, "//");
		if (lc) *lc = '\0';
		char *bc = strstr(p, "/*");
		if (bc) {
			char *ec = strstr(bc+2, "*/");
			if (ec) memmove(bc, ec+2, strlen(ec+2)+1);
			else { in_block_comment = 1; *bc = '\0'; }
		}
	}

	p = trim(p);
	if (!*p) { fprintf(out, "\n"); return; }

	/* preprocessor */
	if (*p == '#') { fprintf(out, "%s\n", p); return; }

	/* label: could be "1:" or "sym:" */
	char *colon = strchr(p, ':');
	if (colon) {
		int llen = colon - p;
		char lbl[256] = "";
		if (llen < (int)sizeof(lbl)-1 && llen > 0) {
			memcpy(lbl, p, llen); lbl[llen] = '\0';
			int ok = 1;
			for (int i = 0; lbl[i]; i++)
				if (!isalnum((unsigned char)lbl[i]) && lbl[i]!='_' && lbl[i]!='.')
					{ ok = 0; break; }
			if (ok) {
				if (llen == 1 && isdigit((unsigned char)lbl[0])) {
					int d = lbl[0]-'0', serial = -1;
					for (int j = 0; j < nnumlabels; j++)
						if (numlabels[j].digit==d && numlabels[j].linenum==cur_lineno)
							{ serial=numlabels[j].serial; break; }
					if (serial >= 0) snprintf(lbl, sizeof(lbl), ".Lnum%d_%d", d, serial);
				}
				fprintf(out, "%s:\n", lbl);
				p = colon+1;
				while (isspace((unsigned char)*p)) p++;
			}
		}
	}
	if (!*p) return;

	/* directives */
	if (*p == '.') {
		/* .zero N — emit N zero bytes */
		if (strncmp(p, ".zero", 5) == 0) {
			char *arg = p+5;
			while (isspace((unsigned char)*arg)) arg++;
			long n = strtol(arg, NULL, 0);
			for (long i = 0; i < n; i++)
				fprintf(out, "\tBYTE\t$0\n");
			return;
		}
		translate_line_att(p, out);
		return;
	}

	/* extract mnemonic; strip dot-suffix (sets CR) and branch hints (+/-) */
	char mnem[32] = "";
	int mi = 0;
	while (*p && !isspace((unsigned char)*p) && mi < (int)sizeof(mnem)-1)
		mnem[mi++] = *p++;
	mnem[mi] = '\0';
	while (isspace((unsigned char)*p)) p++;

	/* strip branch prediction hints: beq+, beq- */
	{
		int n = strlen(mnem);
		if (n > 1 && (mnem[n-1]=='+' || mnem[n-1]=='-'))
			mnem[n-1] = '\0';
	}

	/* dot-suffix: andis. → ANDISCC, beq. → BEQCC, etc. */
	char p9suffix[8] = "";
	{
		int n = strlen(mnem);
		if (n > 1 && mnem[n-1] == '.') {
			mnem[n-1] = '\0';
			strncpy(p9suffix, "CC", sizeof(p9suffix));
		}
	}

	char mlow[32];
	strlower(mnem, mlow, sizeof(mlow));

	/* split operands */
	char ops[8][MAXLINE];
	int nops = split_operands(p, ops, 8);

	/* look up in PPC table */
	PPCOpcMap *mp = NULL;
	for (int i = 0; ppc_opcode_map[i].gas; i++) {
		if (strcmp(ppc_opcode_map[i].gas, mlow) == 0) {
			mp = &ppc_opcode_map[i];
			break;
		}
	}

	/* special cases first */

	/* blr → RET */
	if (strcmp(mlow, "blr") == 0) {
		fprintf(out, "\tRET\n");
		return;
	}

	/* mflr Rdst → MOVW LR, Rdst */
	if (strcmp(mlow, "mflr") == 0 && nops == 1) {
		char t[MAXLINE];
		translate_ppc_operand(ops[0], 'r', t, MAXLINE);
		fprintf(out, "\tMOVW\tLR, %s\n", t);
		return;
	}
	/* mtlr Rsrc → MOVW Rsrc, LR */
	if (strcmp(mlow, "mtlr") == 0 && nops == 1) {
		char t[MAXLINE];
		translate_ppc_operand(ops[0], 'r', t, MAXLINE);
		fprintf(out, "\tMOVW\t%s, LR\n", t);
		return;
	}

	/* mffs Fdst → FMOVD FPSCR, Fdst */
	if (strcmp(mlow, "mffs") == 0 && nops == 1) {
		char t[MAXLINE];
		translate_ppc_operand(ops[0], 'f', t, MAXLINE);
		fprintf(out, "\tFMOVD\tFPSCR, %s\n", t);
		return;
	}

	/* addi Rdst, Rs1, imm → ADD $imm, Rs1, Rdst */
	if ((strcmp(mlow,"addi")==0 || strcmp(mlow,"addis")==0) && nops == 3) {
		char t0[32], t1[32], t2[32];
		translate_ppc_operand(ops[0], 'r', t0, sizeof(t0));
		translate_ppc_operand(ops[1], 'r', t1, sizeof(t1));
		translate_ppc_operand(ops[2], 'i', t2, sizeof(t2));
		const char *p9 = strcmp(mlow,"addis")==0 ? "ADDIS" : "ADD";
		fprintf(out, "\t%s\t%s, %s, %s\n", p9, t2, t1, t0);
		return;
	}

	/* cmpwi Rsrc, imm → CMPW $imm, Rsrc */
	if ((strcmp(mlow,"cmpwi")==0 || strcmp(mlow,"cmplwi")==0) && nops == 2) {
		char t0[32], t1[32];
		translate_ppc_operand(ops[0], 'r', t0, sizeof(t0));
		translate_ppc_operand(ops[1], 'i', t1, sizeof(t1));
		const char *p9 = strcmp(mlow,"cmplwi")==0 ? "CMPU" : "CMPW";
		fprintf(out, "\t%s\t%s, %s\n", p9, t1, t0);
		return;
	}

	/* clrlwi / clrrwi — complex rotate; emit as RLWNM comment */
	if (strcmp(mlow,"clrlwi")==0 || strcmp(mlow,"clrrwi")==0) {
		fprintf(out, "\t// %s %s (complex rotate — translate manually)\n", mnem, p);
		return;
	}

	if (mp) {
		const char *optypes = mp->optypes ? mp->optypes : "rrrrr";
		char tops[8][MAXLINE];
		for (int i = 0; i < nops; i++) {
			char ot = (i < (int)strlen(optypes)) ? optypes[i] : 'r';
			translate_ppc_operand(ops[i], ot, tops[i], MAXLINE);
		}

		/* Build Plan9 op name */
		char p9name[32];
		snprintf(p9name, sizeof(p9name), "%s%s", mp->p9, p9suffix);

		/* Emit based on nops and operand semantic */
		if (nops == 0) {
			fprintf(out, "\t%s\n", p9name);
		} else if (nops == 1) {
			fprintf(out, "\t%s\t%s\n", p9name, tops[0]);
		} else if (nops == 2) {
			if (mp->reverse)
				fprintf(out, "\t%s\t%s, %s\n", p9name, tops[1], tops[0]);
			else
				fprintf(out, "\t%s\t%s, %s\n", p9name, tops[0], tops[1]);
		} else if (nops == 3) {
			/* three-operand: GNU dst,s1,s2 or dst,s1,imm */
			/* Plan9 PPC: src2/imm, src1, dst */
			fprintf(out, "\t%s\t%s, %s, %s\n", p9name, tops[2], tops[1], tops[0]);
		} else {
			fprintf(out, "\t%s", p9name);
			for (int i = 0; i < nops; i++)
				fprintf(out, "%s%s", i==0?"\t":", ", tops[i]);
			fprintf(out, "\n");
		}
		return;
	}

	/* default: uppercase, treat all operands as registers */
	{
		char p9name[32];
		char upmnem[32];
		int i;
		for (i = 0; mnem[i] && i < (int)sizeof(upmnem)-1; i++)
			upmnem[i] = toupper((unsigned char)mnem[i]);
		upmnem[i] = '\0';
		snprintf(p9name, sizeof(p9name), "%s%s", upmnem, p9suffix);

		char tops[8][MAXLINE];
		for (i = 0; i < nops; i++)
			translate_ppc_operand(ops[i], 'r', tops[i], MAXLINE);

		fprintf(out, "\t%s", p9name);
		for (i = 0; i < nops; i++)
			fprintf(out, "%s%s", i==0?"\t":", ", tops[i]);
		fprintf(out, "\n");
	}
}

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
 * Look up in a RegMap table. Returns Plan 9 name or NULL.
 */
static const char *
lookup_in_table(const RegMap *tab, const char *name)
{
	int i;
	for (i = 0; tab[i].gas; i++) {
		if (strcmp(tab[i].gas, name) == 0)
			return tab[i].p9;
	}
	return NULL;
}

/*
 * For RISC arches whose GNU names are just lowercase Rn/Fn/etc,
 * try a generic uppercase conversion as a fallback.
 * e.g. "r5" → "R5", "f12" → "F12", "cr3" → "CR3"
 */
static const char *
generic_risc_reg(const char *name)
{
	static char buf[16];
	int i;
	/* must start with a letter, rest digits */
	if (!isalpha((unsigned char)name[0])) return NULL;
	for (i = 1; name[i]; i++)
		if (!isdigit((unsigned char)name[i])) return NULL;
	/* uppercase prefix + digits */
	buf[0] = toupper((unsigned char)name[0]);
	strncpy(buf+1, name+1, sizeof(buf)-2);
	buf[sizeof(buf)-1] = '\0';
	return buf;
}

/*
 * Look up a register name (without % prefix, already lowercased).
 * Returns Plan 9 name or NULL if unknown.
 * Dispatches based on current arch.
 */
static const char *
lookup_reg(const char *name)
{
	const char *r;
	static char buf[8];
	int n;

	switch (arch) {
	case ARCH_AMD64:
	case ARCH_386:
		/* x86: handle st(n) variants, then look up in att_regs */
		if (strncmp(name, "st(", 3) == 0) {
			n = atoi(name+3);
			snprintf(buf, sizeof(buf), "F%d", n);
			return buf;
		}
		return lookup_in_table(att_regs, name);

	case ARCH_ARM:
		r = lookup_in_table(arm_aliases, name);
		return r ? r : generic_risc_reg(name);

	case ARCH_ARM64:
		r = lookup_in_table(arm64_aliases, name);
		return r ? r : generic_risc_reg(name);

	case ARCH_MIPS:
		/* MIPS GNU uses $rN or $name; we receive name without $ */
		r = lookup_in_table(mips_aliases, name);
		return r ? r : generic_risc_reg(name);

	case ARCH_SPARC:
		/* sparc register names come in after stripping %, e.g. "g0", "o1" */
		r = lookup_in_table(sparc_aliases, name);
		return r ? r : generic_risc_reg(name);

	case ARCH_PPC64:
	case ARCH_POWER:
		r = lookup_in_table(ppc_aliases, name);
		return r ? r : generic_risc_reg(name);

	case ARCH_68000:
	case ARCH_68020:
		return lookup_in_table(m68k_aliases, name);
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

/* ------------------------------------------------------------------ */
/* AT&T size-suffix inference                                          */
/* ------------------------------------------------------------------ */

/*
 * In GNU AT&T syntax, size suffixes (b/w/l/q) on the mnemonic are
 * mandatory for most instructions.  However, some GAS source files
 * omit the suffix when the operand size is unambiguous from the
 * register name (e.g. "inc %rdi" — clearly 64-bit).
 *
 * Plan 9 assemblers are strict: "INC DI" is ambiguous; the correct
 * form is "INCQ DI" for the 64-bit case.
 *
 * This function examines up to two operands (the register operands in
 * an AT&T instruction) and returns the appropriate Plan 9 size suffix
 * character ('B', 'W', 'L', 'Q') or '\0' if it cannot determine one.
 *
 * We only call this for x86/amd64; RISC arches don't need it.
 */
static char
infer_suffix_from_regs(const char *op1, const char *op2)
{
	/* We look at register operands only — skip $imm, mem, etc. */
	const char *ops[2];
	ops[0] = op1;
	ops[1] = op2;

	/*
	 * Map of lowercase AT&T register name → suffix character.
	 * Only the first match found is used.
	 */
	static const struct { const char *name; char sfx; } rmap[] = {
		/* 64-bit → Q */
		{ "rax",'Q' }, { "rcx",'Q' }, { "rdx",'Q' }, { "rbx",'Q' },
		{ "rsp",'Q' }, { "rbp",'Q' }, { "rsi",'Q' }, { "rdi",'Q' },
		{ "r8", 'Q' }, { "r9", 'Q' }, { "r10",'Q' }, { "r11",'Q' },
		{ "r12",'Q' }, { "r13",'Q' }, { "r14",'Q' }, { "r15",'Q' },
		/* 32-bit → L */
		{ "eax",'L' }, { "ecx",'L' }, { "edx",'L' }, { "ebx",'L' },
		{ "esp",'L' }, { "ebp",'L' }, { "esi",'L' }, { "edi",'L' },
		{ "r8d",'L'  }, { "r9d",'L'  }, { "r10d",'L' }, { "r11d",'L' },
		{ "r12d",'L' }, { "r13d",'L' }, { "r14d",'L' }, { "r15d",'L' },
		/* 16-bit → W */
		{ "ax", 'W' }, { "cx", 'W' }, { "dx", 'W' }, { "bx", 'W' },
		{ "sp", 'W' }, { "bp", 'W' }, { "si", 'W' }, { "di", 'W' },
		{ "r8w",'W' }, { "r9w",'W' }, { "r10w",'W'}, { "r11w",'W'},
		{ "r12w",'W'}, { "r13w",'W'}, { "r14w",'W'}, { "r15w",'W'},
		/* 8-bit → B */
		{ "al", 'B' }, { "cl", 'B' }, { "dl", 'B' }, { "bl", 'B' },
		{ "ah", 'B' }, { "ch", 'B' }, { "dh", 'B' }, { "bh", 'B' },
		{ "spl",'B' }, { "bpl",'B' }, { "sil",'B' }, { "dil",'B' },
		{ "r8b",'B' }, { "r9b",'B' }, { "r10b",'B'}, { "r11b",'B'},
		{ "r12b",'B'}, { "r13b",'B'}, { "r14b",'B'}, { "r15b",'B'},
		{ NULL, '\0' }
	};
	int oi, ri;

	for (oi = 0; oi < 2; oi++) {
		const char *o = ops[oi];
		if (!o || !*o) continue;
		while (isspace((unsigned char)*o)) o++;
		if (*o == '%') {
			char tmp[32];
			strlower(o+1, tmp, sizeof(tmp));
			/* strip trailing non-alnum (e.g. from "ch," remnants) */
			char *e = tmp;
			while (*e && (isalnum((unsigned char)*e))) e++;
			*e = '\0';
			for (ri = 0; rmap[ri].name; ri++) {
				if (strcmp(rmap[ri].name, tmp) == 0)
					return rmap[ri].sfx;
			}
		}
	}
	/* default for arch */
	return (arch == ARCH_AMD64) ? 'Q' : 'L';
}

/*
 * Opcodes that never take a size suffix in Plan 9 even when the
 * AT&T source omits one — these are already handled in opcode_map,
 * but we need to skip suffix-inference for them.
 */
static int
opcode_needs_no_suffix(const char *mlow)
{
	static const char *nosuf[] = {
		"ret","retl","retq","retf","retfq",
		"nop","nopl","nopw",
		"hlt","pause","leave","leaveq","leavel",
		"cpuid","syscall","sysret",
		"int3","int","cli","sti","cld","std","clc","stc","cmc",
		"pushf","pushfq","popf","popfq",
		"lahf","sahf",
		"cbw","cwde","cdqe","cwd","cdq","cqo",
		"fnclex","fwait","fnop",
		"fnstsw","fnsave","fnstenv","fnstcw",
		"fstsw","fclex","fstcw","fstenv","fsave","finit","fninit",
		"frstor","fldenv","fldcw",
		"stmxcsr","ldmxcsr","fxsave","fxrstor",
		"mfence","lfence","sfence",
		"rdtsc","rdtscp","rdmsr","wrmsr","rdpmc",
		"iret","iretq","iretl",
		"lock","rep","repe","repz","repne","repnz",
		NULL
	};
	int i;
	for (i = 0; nosuf[i]; i++)
		if (strcmp(nosuf[i], mlow) == 0) return 1;
	return 0;
}

/*
 * Given an AT&T mnemonic with no size suffix (e.g. "inc", "add", "or"),
 * and the raw operand strings, return the Plan 9 mnemonic with the
 * appropriate suffix appended.
 * Returns pointer to a static buffer.
 */
static const char *
infer_att_opcode(const char *mnem, const char *op1, const char *op2)
{
	static char buf[80];
	char mlow[64];
	char sfx;
	const char *p9base;

	strlower(mnem, mlow, sizeof(mlow));

	/*
	 * If the mnemonic already ends with a known AT&T size suffix and the
	 * stem (mnemonic minus last char) is NOT a bare instruction name,
	 * treat it as already suffixed and just uppercase it.
	 * Example: "movq" → last='q', stem="mov" which IS a bare name
	 *          → still needs inference? No — "movq" IS explicitly suffixed.
	 * So the rule is: if last char is b/w/l/q AND the stem+suffix form
	 * is a genuine GAS suffixed mnemonic (i.e. stem is a known base),
	 * return it uppercased directly.
	 * We identify this by checking: does the caller's needs_inference[]
	 * list contain the stem? If stem is in the list AND last char is a
	 * suffix → it's a genuinely suffixed mnemonic like "movq","addl".
	 * If stem is NOT in the list → last char is part of the opcode name.
	 *
	 * Simpler heuristic that works for all cases in practice:
	 * If the mnemonic was passed here, the caller already decided it needs
	 * inference OR it's a genuinely unsuffixed name. Just infer from regs.
	 */
	if (opcode_needs_no_suffix(mlow))
		return translate_opcode(mnem);

	sfx = infer_suffix_from_regs(op1, op2);
	p9base = translate_opcode(mnem); /* uppercased base */

	snprintf(buf, sizeof(buf), "%s%c", p9base, sfx);
	return buf;
}

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
	static int in_block_comment = 0;
	static int in_data_section  = 0;
	static char data_label[256] = "";
	static int  data_offset     = 0;
	static int  data_is_globl   = 0;

#define FLUSH_DATA_GLOBL() do { \
	if (data_label[0] && data_offset > 0) { \
		fprintf(out, "GLOBL %s(SB),%d,$%d\n", \
		        data_label, data_is_globl ? 0 : 4 /*NOPTR*/, data_offset); \
		data_label[0] = '\0'; \
		data_offset   = 0; \
		data_is_globl = 0; \
	} \
} while(0)

	/* NULL line = EOF signal: flush any pending data GLOBL */
	if (!line) {
		FLUSH_DATA_GLOBL();
		return;
	}

	strncpy(buf, line, sizeof(buf)-1);
	buf[sizeof(buf)-1] = '\0';
	char *p = buf;

	/* Handle multi-line C block comments across lines */
	if (in_block_comment) {
		char *end = strstr(p, "*/");
		if (end) {
			in_block_comment = 0;
			p = end + 2;
		} else {
			fprintf(out, "\n");
			return;
		}
	}

	/* Strip comments: #, //, and C-style block comments (may start mid-line) */
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
					/* inline block comment — replace with space */
					memmove(c, end+2, strlen(end+2)+1);
					/* don't advance c, re-scan from same position */
					continue;
				} else {
					/* opens a block comment that continues on next lines */
					in_block_comment = 1;
					*c = '\0';
					break;
				}
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
			/*
			 * Numeric local label: a single decimal digit.
			 * Look up its serial number from our pre-collected table
			 * and emit ".Lnum{d}_{serial}:" instead.
			 */
			if (llen == 1 && isdigit((unsigned char)label[0])) {
				int d = label[0] - '0';
				int serial = -1;
				int j;
				/* find the entry matching this line number */
				for (j = 0; j < nnumlabels; j++) {
					if (numlabels[j].digit == d &&
					    numlabels[j].linenum == cur_lineno) {
						serial = numlabels[j].serial;
						break;
					}
				}
				if (serial >= 0) {
					snprintf(label, sizeof(label), ".Lnum%d_%d", d, serial);
				} else {
					snprintf(label, sizeof(label), ".Lnum%d_?", d);
				}
				p = colon+1;
				while (isspace((unsigned char)*p)) p++;
				fprintf(out, "%s:\n", label);
				label[0] = '\0'; /* already emitted */
			} else {
				/* a label should be alphanumeric+underscore+dot */
				int ok = 1;
				for (int i = 0; label[i]; i++)
					if (!isalnum((unsigned char)label[i]) && label[i] != '_' && label[i] != '.' && label[i] != '$')
						{ ok = 0; break; }
				if (ok) {
					p = colon+1;
					while (isspace((unsigned char)*p)) p++;
					if (in_data_section) {
						/* flush GLOBL for previous data symbol if any */
						FLUSH_DATA_GLOBL();
						/* record this label for the upcoming data directives */
						strncpy(data_label, label, sizeof(data_label)-1);
						data_label[sizeof(data_label)-1] = '\0';
						data_offset = 0;
					} else {
						fprintf(out, "%s:\n", label);
					}
					label[0] = '\0'; /* already emitted or consumed */
				}
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

		/* Track which section we're in */
		if (strcasecmp(dir, ".text") == 0) {
			FLUSH_DATA_GLOBL();
			in_data_section = 0;
		} else if (strcasecmp(dir, ".data") == 0 ||
		           strcasecmp(dir, ".bss")  == 0 ||
		           strcasecmp(dir, ".rodata") == 0) {
			in_data_section = 1;
		} else if (strcasecmp(dir, ".section") == 0) {
			int going_text = (strstr(args, ".text") != NULL ||
			                  strcmp(trim(args), "text") == 0);
			if (going_text) { FLUSH_DATA_GLOBL(); in_data_section = 0; }
			else              in_data_section = 1;
		}

		/* Look up directive */
		int found = 0;
		for (i = 0; dir_map[i].gas_dir; i++) {
			if (strcasecmp(dir_map[i].gas_dir, dir) == 0) {
				found = 1;
				if (dir_map[i].p9_dir == NULL) {
					fprintf(out, "// %s %s\n", dir, args);
				} else if (strcmp(dir_map[i].p9_dir, "GLOBL") == 0) {
					/*
					 * .globl sym — mark the named symbol as globally visible.
					 * If we're in the data section and this matches the current
					 * data label, set the flag so GLOBL gets flags=0 (exported).
					 * Otherwise comment it out — we can't generate a full GLOBL
					 * without knowing the size yet.
					 */
					char gsym[256];
					strncpy(gsym, args, sizeof(gsym)-1);
					gsym[sizeof(gsym)-1] = '\0';
					trim(gsym);
					if (in_data_section && strcmp(gsym, data_label) == 0) {
						data_is_globl = 1;
					} else if (in_data_section) {
						/* .globl before the label — remember it */
						if (strcmp(gsym, data_label) == 0 || !data_label[0]) {
							strncpy(data_label, gsym, sizeof(data_label)-1);
							data_is_globl = 1;
						} else {
							fprintf(out, "// GLOBL %s\n", args);
						}
					} else {
						fprintf(out, "// GLOBL %s\n", args);
					}
				} else if (strcmp(dir_map[i].p9_dir, "BYTE") == 0 ||
				           strcmp(dir_map[i].p9_dir, "WORD") == 0 ||
				           strcmp(dir_map[i].p9_dir, "LONG") == 0 ||
				           strcmp(dir_map[i].p9_dir, "QUAD") == 0) {
					/*
					 * Data directives in .data context:
					 * If we just swallowed a label, emit as DATA label+0(SB)/N,$val
					 * Otherwise emit as bare BYTE/WORD/LONG/QUAD $val (in .text context).
					 */
					int elemsz = (strcmp(dir_map[i].p9_dir,"BYTE")==0) ? 1 :
					             (strcmp(dir_map[i].p9_dir,"WORD")==0) ? 2 :
					             (strcmp(dir_map[i].p9_dir,"LONG")==0) ? 4 : 8;
					char ops[8][MAXLINE];
					int nops = split_operands(args, ops, 8);
					if (in_data_section && data_label[0]) {
						for (int j = 0; j < nops; j++) {
							char *v = trim(ops[j]);
							if (*v == '$') v++;   /* strip leading $ if present */
							fprintf(out, "DATA %s+%d(SB)/%d,$%s\n",
							        data_label, data_offset, elemsz, v);
							data_offset += elemsz;
						}
					} else {
						for (int j = 0; j < nops; j++)
							fprintf(out, "\t%s $%s\n", dir_map[i].p9_dir, trim(ops[j]));
					}
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

	/*
	 * AT&T suffix inference:
	 * When the mnemonic has no explicit size suffix but Plan 9 requires one,
	 * infer the suffix from the register operands.
	 * Only for x86/amd64 and only when the mnemonic is in the explicit
	 * opcode_map (which means it already has the right Plan 9 form) OR
	 * when the uppercased mnemonic will be ambiguous to the assembler.
	 *
	 * We use infer_att_opcode() which checks whether a suffix is already
	 * present and only adds one when needed.
	 */
	if (arch_is_x86(arch)) {
		char mlow_tmp[64];
		strlower(mnem, mlow_tmp, sizeof(mlow_tmp));
		/*
		 * Explicit whitelist of bare (unsuffixed) AT&T mnemonics that
		 * need a size suffix added.  The old character-based check
		 * ("ends in b/w/l/q?") caused false positives: "shl" ends in
		 * 'l' and would be skipped, emitting bare SHL which 6a rejects.
		 * Strategy: if in the whitelist → always infer.  Otherwise if
		 * the mnemonic ends in a real suffix char → trust it as-is.
		 */
		static const char *needs_inference[] = {
			"add","sub","and","or","xor","not","neg",
			"cmp","test","mov","lea","xchg",
			"inc","dec","mul","imul","div","idiv",
			/* shifts: shl/shr/sal/sar/rol/ror end in 'l'/'r'
			 * which looks like a suffix letter but isn't */
			"shl","shr","sal","sar","rol","ror","rcl","rcr",
			"push","pop","call",
			NULL
		};
		int needs_infer = 0, ni;
		for (ni = 0; needs_inference[ni]; ni++) {
			if (strcmp(needs_inference[ni], mlow_tmp) == 0) {
				needs_infer = 1;
				break;
			}
		}
		/* Also run inference for mnemonics not ending in b/w/l/q
		 * (their last char can't be a suffix, so they're bare) */
		if (!needs_infer) {
			int n = strlen(mlow_tmp);
			char last = n > 0 ? mlow_tmp[n-1] : 0;
			if (!((last=='b'||last=='w'||last=='l'||last=='q') && n>=2))
				needs_infer = 1;
		}
		if (needs_infer && !opcode_needs_no_suffix(mlow_tmp)) {
			int in_map = 0, mi;
			for (mi = 0; opcode_map[mi].gas; mi++) {
				if (strcmp(opcode_map[mi].gas, mlow_tmp) == 0) {
					in_map = 1;
					break;
				}
			}
			if (!in_map) {
				const char *op1 = nops > 0 ? ops[0] : "";
				const char *op2 = nops > 1 ? ops[1] : "";
				p9op = infer_att_opcode(mnem, op1, op2);
			}
		}
	}

	/* AT&T operand order: src, dst — Plan 9 is also src, dst — same!
	 * Exception: CMP and TEST. Plan 9 grammar requires the register first
	 * even when the immediate is the "source" in AT&T.
	 * AT&T: cmpl $0, %eax  → Plan 9: CMPL AX, $0
	 * AT&T: testl $1, %eax → Plan 9: TESTL AX, $1
	 */
	{
		char mlow[64];
		strlower(mnem, mlow, sizeof(mlow));
		if (nops == 2 && ops[0][0] == '$') {
			/* check if it's a CMP or TEST variant */
			int is_cmp_test = (strncmp(mlow, "cmp",  3) == 0 ||
			                   strncmp(mlow, "test", 4) == 0);
			if (is_cmp_test) {
				/* swap: Plan 9 wants reg, $imm not $imm, reg */
				char tmp[MAXLINE];
				strncpy(tmp,    ops[0], MAXLINE);
				strncpy(ops[0], ops[1], MAXLINE);
				strncpy(ops[1], tmp,    MAXLINE);
			}
		}
	}

	/* Translate each operand, resolving numeric label refs (Nf/Nb) */
	char tops[8][MAXLINE];
	for (i = 0; i < nops; i++) {
		char tmp_op[MAXLINE];
		/* First resolve any numeric label reference */
		translate_numlabel_ref(ops[i], tmp_op, sizeof(tmp_op), cur_lineno);
		/* Then translate the operand (register, memory, immediate) */
		translate_operand_att(tmp_op, tops[i], MAXLINE);
	}

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
	static int in_block_comment = 0;

	/* Handle multi-line block comments */
	if (in_block_comment) {
		char *end = strstr(p, "*/");
		if (end) {
			in_block_comment = 0;
			p = end + 2;
		} else {
			fprintf(out, "\n");
			return;
		}
	}

	/* Strip C-style block comments (inline) and open-ended ones */
	{
		char *c = p;
		while (*c) {
			if (*c == '/' && c[1] == '*') {
				char *end = strstr(c+2, "*/");
				if (end) {
					memmove(c, end+2, strlen(end+2)+1);
					continue;
				} else {
					in_block_comment = 1;
					*c = '\0';
					break;
				}
			}
			c++;
		}
	}

	/* Strip Intel comment (;) and C++ comment (//) */
	{
		char *sc = strchr(p, ';');
		if (sc) *sc = '\0';
		char *lc = strstr(p, "//");
		if (lc) *lc = '\0';
	}

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

	char ops[8][MAXLINE];
	int nops = split_operands(p, ops, 8);

	/* Reverse operand order for Intel → Plan 9 */
	char tops[8][MAXLINE];
	for (i = 0; i < nops; i++)
		translate_operand_intel(ops[i], tops[i], MAXLINE, mnem);

	const char *p9op = translate_opcode(mnem);

	/*
	 * Intel instructions without size suffixes:
	 * push/pop/call/jmp/ret in 64-bit mode need Q suffix in Plan 9.
	 * mov/add/sub etc. without suffix: Plan 9 can often infer from operands,
	 * but for safety we add Q for 64-bit, L for 32-bit arch.
	 */
	{
		char mlow[64];
		strlower(mnem, mlow, sizeof(mlow));
		int n = strlen(mlow);

		/*
		 * has_suffix: true if the mnemonic already ends with a valid
		 * Plan 9 size suffix letter that is NOT just part of the opcode name.
		 * We use an explicit whitelist of unsuffixed ops to avoid false positives
		 * (e.g. "sub" ends in 'b', "add" ends in 'd', "or" ends in 'r').
		 */
		static const char *need_suffix[] = {
			"push", "pop",
			"mov",  "add", "sub",  "and", "or",  "xor",
			"cmp",  "test","lea",  "not", "neg",
			"inc",  "dec", "mul",  "imul","div", "idiv",
			"shl",  "shr", "sal",  "sar", "rol", "ror",
			"xchg", "bswap",
			NULL
		};
		const char *sfx = (arch == ARCH_AMD64) ? "Q" : "L";
		int matched = 0;
		for (int j = 0; need_suffix[j]; j++) {
			if (strcmp(mlow, need_suffix[j]) == 0) {
				static char sfxbuf[80];
				snprintf(sfxbuf, sizeof(sfxbuf), "%s%s",
				         translate_opcode(mnem), sfx);
				p9op = sfxbuf;
				matched = 1;
				break;
			}
		}
		(void)n; (void)matched;

		/*
		 * Intel CMP/TEST operand adjustment:
		 * Intel: cmp eax, 0  (dst=eax src=0) → after swap tops[1],tops[0] = $0,AX
		 * But Plan 9 needs: CMPQ AX, $0
		 * The 2-operand swap below already swaps Intel dst,src → src,dst.
		 * For CMP, Intel "dst" is the register being compared, which becomes
		 * tops[0] and after swap is output second — WRONG.
		 * We need to UN-swap for CMP/TEST: output tops[0], tops[1] (Intel order =
		 * register, immediate = Plan 9 order for CMP).
		 */
		if (nops == 2 && (strncmp(mlow, "cmp", 3) == 0 ||
		                  strncmp(mlow, "test", 4) == 0)) {
			/* output without swap */
			fprintf(out, "\t%s\t%s, %s\n", p9op, tops[0], tops[1]);
			return;
		}
	}
	if (nops == 2) {
		/* Intel: dst, src → Plan 9: src, dst — swap */
		fprintf(out, "\t%s\t%s, %s\n", p9op, tops[1], tops[0]);
	} else if (nops == 1) {
		fprintf(out, "\t%s\t%s\n", p9op, tops[0]);
	} else if (nops == 0) {
		fprintf(out, "\t%s\n", p9op);
	} else {
		/* 3-operand: usually imm, src, dst → keep as-is for now */
		fprintf(out, "\t%s", p9op);
		for (i = 0; i < nops; i++) {
			if (i == 0) fprintf(out, "\t%s", tops[i]);
			else        fprintf(out, ", %s", tops[i]);
		}
		fprintf(out, "\n");
	}
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
	 * Plan 9 pass-through: copy verbatim so the rest of the pipeline
	 * (invoke_assembler, cleanup) stays uniform.
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

	/*
	 * Pass 1: collect all numeric local labels (1:, 2:, etc.) so we
	 * can resolve forward (1f) and backward (1b) references in pass 2.
	 * Done for all arches since numeric labels are universal GAS syntax.
	 */
	collect_numlabels(infile);

	in  = fopen(infile,       "r");
	out = fopen(outfile_path, "w");
	if (!in)  die("cannot open input: %s: %s",  infile,      strerror(errno));
	if (!out) die("cannot open output: %s: %s", outfile_path, strerror(errno));

	cur_lineno = 0;
	while (fgets(line, sizeof(line), in)) {
		cur_lineno++;
		switch (arch) {
		case ARCH_ARM64:
			translate_line_arm64(line, out);
			break;
		case ARCH_MIPS:
			translate_line_mips(line, out);
			break;
		case ARCH_PPC64:
		case ARCH_POWER:
			translate_line_ppc(line, out);
			break;
		default:
			if (syn == SYN_INTEL)
				translate_line_intel(line, out);
			else
				translate_line_att(line, out);
			break;
		}
	}

	/* Flush any pending data section GLOBL at end of file */
	if (syn != SYN_INTEL &&
	    arch != ARCH_ARM64 && arch != ARCH_MIPS &&
	    arch != ARCH_PPC64 && arch != ARCH_POWER)
		translate_line_att(NULL, out);

	fclose(in);
	fclose(out);

	/* Verbose: dump translated output to stderr */
	if (verbose) {
		FILE *f = fopen(outfile_path, "r");
		if (f) {
			char vline[MAXLINE];
			while (fgets(vline, sizeof(vline), f))
				fputs(vline, stderr);
			fclose(f);
		}
	}
}

static int
invoke_assembler(const char *translated, const char *output)
{
	char cmd[4096];
	const char *native = assembler_name(arch);
	int pos = 0;
	int n;
	int i;

	n = snprintf(cmd+pos, sizeof(cmd)-pos, "%s", native);
	pos += n;

	if (output) {
		n = snprintf(cmd+pos, sizeof(cmd)-pos, " -o %s", output);
		pos += n;
	}

	/*
	 * Add Plan 9 standard include directories so that
	 * #include "textflag.h" and similar headers resolve correctly.
	 *
	 * Priority order (mirrors what Plan 9 mk does):
	 *   1. /$objtype/include  (arch-specific, from $objtype env var)
	 *   2. /sys/include       (system-wide)
	 *
	 * We read $objtype from the environment; if unset, fall back to
	 * the arch string for the selected target.
	 */
	{
		static const char *arch_thestring[] = {
			"amd64", "386", "arm", "arm64",
			"power64", "power", "mips", "sparc",
			"68000", "68020"
		};
		const char *objtype = getenv("objtype");
		if (!objtype || !*objtype)
			objtype = arch_thestring[arch];
		n = snprintf(cmd+pos, sizeof(cmd)-pos,
		             " -I /%s/include -I /sys/include", objtype);
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
		"  -o outfile         output file\n"
		"  -S                 convert to Plan 9 syntax only, do not assemble\n"
		"                     output goes to outfile (or stdout if no -o)\n"
		"  -att               force AT&T syntax input\n"
		"  -intel             force Intel syntax input\n"
		"  -plan9             force Plan 9 syntax (pass through)\n"
		"architecture (default: amd64 / 6a):\n"
		"  -march=ARCH        amd64 386 arm arm64 ppc64 power mips sparc 68000 68020\n"
		"  -m32 / --32        alias for -march=386\n"
		"  -m64 / --64        alias for -march=amd64\n"
		"  -marm              alias for -march=arm\n"
		"  -marm64            alias for -march=arm64\n"
		"  -mppc64 / -mpowerpc64  alias for -march=ppc64\n"
		"  -mpower / -mpowerpc    alias for -march=power\n"
		"  -mmips             alias for -march=mips\n"
		"  -msparc            alias for -march=sparc\n"
		"  -m68k              alias for -march=68000\n"
		"  -m68020            alias for -march=68020\n"
		"other:\n"
		"  -I dir             add include directory\n"
		"  -D sym[=val]       define symbol\n"
		"  -v                 verbose (dump translated Plan 9 output to stderr)\n"
	);
	exit(1);
}

/*
 * Parse an architecture name string into an Arch enum.
 * Returns -1 if unrecognized.
 */
static int
parse_arch(const char *s)
{
	if (strcmp(s, "amd64") == 0 || strcmp(s, "x86_64") == 0) return ARCH_AMD64;
	if (strcmp(s, "386")   == 0 || strcmp(s, "i386")   == 0 ||
	    strcmp(s, "i486")  == 0 || strcmp(s, "i586")   == 0 ||
	    strcmp(s, "i686")  == 0)                              return ARCH_386;
	if (strcmp(s, "arm")   == 0 || strcmp(s, "armv7")  == 0) return ARCH_ARM;
	if (strcmp(s, "arm64") == 0 || strcmp(s, "aarch64") == 0) return ARCH_ARM64;
	if (strcmp(s, "ppc64") == 0 || strcmp(s, "powerpc64") == 0 ||
	    strcmp(s, "powerpc64le") == 0)                        return ARCH_PPC64;
	if (strcmp(s, "power") == 0 || strcmp(s, "powerpc") == 0 ||
	    strcmp(s, "ppc")   == 0)                              return ARCH_POWER;
	if (strcmp(s, "mips")  == 0 || strcmp(s, "mips64") == 0 ||
	    strcmp(s, "mipsel") == 0)                             return ARCH_MIPS;
	if (strcmp(s, "sparc") == 0 || strcmp(s, "sparc64") == 0) return ARCH_SPARC;
	if (strcmp(s, "68000") == 0 || strcmp(s, "m68000") == 0 ||
	    strcmp(s, "m68k")  == 0)                              return ARCH_68000;
	if (strcmp(s, "68020") == 0 || strcmp(s, "m68020") == 0) return ARCH_68020;
	return -1;
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
		} else if (strcmp(a, "-S") == 0) {
			convert_only = 1;
		} else if (strcmp(a, "-att") == 0 || strcmp(a, "--att") == 0) {
			syntax = SYN_ATT;
		} else if (strcmp(a, "-intel") == 0 || strcmp(a, "--intel") == 0) {
			syntax = SYN_INTEL;
		} else if (strcmp(a, "-plan9") == 0 || strcmp(a, "--plan9") == 0) {
			syntax = SYN_PLAN9;
		/* Architecture flags */
		} else if (strcmp(a, "-m32") == 0 || strcmp(a, "--32") == 0) {
			arch = ARCH_386;
		} else if (strcmp(a, "-m64") == 0 || strcmp(a, "--64") == 0) {
			arch = ARCH_AMD64;
		} else if (strcmp(a, "-marm") == 0) {
			arch = ARCH_ARM;
		} else if (strcmp(a, "-marm64") == 0 || strcmp(a, "-maarch64") == 0) {
			arch = ARCH_ARM64;
		} else if (strcmp(a, "-mppc64") == 0 || strcmp(a, "-mpowerpc64") == 0 ||
		           strcmp(a, "-mpowerpc64le") == 0) {
			arch = ARCH_PPC64;
		} else if (strcmp(a, "-mpower") == 0 || strcmp(a, "-mpowerpc") == 0 ||
		           strcmp(a, "-mppc") == 0) {
			arch = ARCH_POWER;
		} else if (strcmp(a, "-mmips") == 0 || strcmp(a, "-mmips64") == 0) {
			arch = ARCH_MIPS;
		} else if (strcmp(a, "-msparc") == 0 || strcmp(a, "-msparc64") == 0) {
			arch = ARCH_SPARC;
		} else if (strcmp(a, "-m68k") == 0 || strcmp(a, "-m68000") == 0) {
			arch = ARCH_68000;
		} else if (strcmp(a, "-m68020") == 0) {
			arch = ARCH_68020;
		} else if (strncmp(a, "-march=", 7) == 0) {
			int r = parse_arch(a+7);
			if (r < 0) die("unknown architecture: %s", a+7);
			arch = (Arch)r;
		} else if (strcmp(a, "-march") == 0) {
			if (++i >= argc) die("-march requires argument");
			int r = parse_arch(argv[i]);
			if (r < 0) die("unknown architecture: %s", argv[i]);
			arch = (Arch)r;
		/* Other options */
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
			   --noexecstack, -g, --gdwarf*, --fatal-warnings, -EL/-EB etc. */
			if (strcmp(a, "--noexecstack") != 0 &&
			    strcmp(a, "--fatal-warnings") != 0 &&
			    strncmp(a, "--gdwarf", 8) != 0 &&
			    strncmp(a, "-g", 2) != 0 &&
			    strcmp(a, "-EL") != 0 &&
			    strcmp(a, "-EB") != 0 &&
			    strcmp(a, "-mfpu=vfp") != 0 &&
			    strncmp(a, "-mfpu=", 6) != 0 &&
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

		if (convert_only) {
			/*
			 * -S: translate to Plan 9 syntax only; write to outfile
			 * or stdout.  No temp file, no assembler invocation.
			 */
			const char *dst = outfile ? outfile : "-";
			FILE *out_f;
			if (strcmp(dst, "-") == 0) {
				out_f = stdout;
			} else {
				out_f = fopen(dst, "w");
				if (!out_f) die("cannot open output: %s: %s", dst, strerror(errno));
			}

			/* collect numeric labels */
			collect_numlabels(infile);
			FILE *in_f = fopen(infile, "r");
			if (!in_f) die("cannot open input: %s: %s", infile, strerror(errno));
			char cvline[MAXLINE];
			cur_lineno = 0;
			while (fgets(cvline, sizeof(cvline), in_f)) {
				cur_lineno++;
				switch (arch) {
				case ARCH_ARM64: translate_line_arm64(cvline, out_f); break;
				case ARCH_MIPS:  translate_line_mips(cvline, out_f);  break;
				case ARCH_PPC64:
				case ARCH_POWER: translate_line_ppc(cvline, out_f);   break;
				default:
					if (syn == SYN_INTEL)
						translate_line_intel(cvline, out_f);
					else
						translate_line_att(cvline, out_f);
					break;
				}
			}
			if (syn != SYN_INTEL &&
			    arch != ARCH_ARM64 && arch != ARCH_MIPS &&
			    arch != ARCH_PPC64 && arch != ARCH_POWER)
				translate_line_att(NULL, out_f);
			fclose(in_f);
			if (out_f != stdout) fclose(out_f);
			continue;
		}

		const char *tmpname = make_tmpname(infile);
		translate_file(infile, tmpname, syn);

		/* Determine output file for this input */
		char *thisout = outfile;
		if (!thisout && nfiles > 1) {
			/* multiple files, no -o: let the native assembler derive it */
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
