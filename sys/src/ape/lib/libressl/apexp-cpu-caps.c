/*
 * apexp-cpu-caps.c -- crypto_cpu_caps_init for APExp.
 *
 * Stands in for crypto/arch/$objtype/crypto_cpu_caps.c, which cannot be
 * compiled here. On amd64 that file reads the CPU's feature bits with
 * GCC extended inline assembly:
 *
 *	__asm__ ("cpuid": "+a"(eax), "+b"(ebx), "+c"(ecx), "+d"(edx));
 *	__asm__ ("xgetbv": "+a"(eax), "+c"(ecx), "+d"(edx));
 *
 * kencc has no extended asm -- no output operands, no constraints -- so
 * there is nothing to translate it into short of an assembly file per
 * architecture.
 *
 * Reporting no capabilities is the correct answer rather than a
 * degradation, because this archive is built with OPENSSL_NO_ASM. The
 * capability bits exist to choose between a generic C routine and a
 * hand-written assembly one; with no assembly compiled in, there is
 * nothing to choose. crypto_arch.h gates every HAVE_*_ASM on
 * !OPENSSL_NO_ASM, so the generic paths are the only ones present, and
 * they do not consult these variables.
 *
 * OPENSSL_ia32cap_P is the historical name the perlasm-generated code
 * uses. Nothing here reads it, but it is part of the ABI that file
 * defines, so it is defined here too rather than left to become an
 * undefined symbol if some object is added later that expects it.
 *
 * If assembly is ever wanted, this is the file to replace: write the
 * cpuid sequence in Plan 9 amd64 assembly and set the same three
 * variables.
 */

#include <stdint.h>

#include "crypto_arch.h"

uint64_t OPENSSL_ia32cap_P;
uint64_t crypto_cpu_caps_amd64;

void
crypto_cpu_caps_init(void)
{
	OPENSSL_ia32cap_P = 0;
	crypto_cpu_caps_amd64 = 0;
}
