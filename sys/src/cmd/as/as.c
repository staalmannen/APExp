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
		"  -v                 verbose\n"
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
