/*
 * malloc_align.h — shared definitions for aligned allocation
 *
 * APE's free() computes bp = (Bucket*)(ptr - datoff) and checks
 * bp->magic == MAGIC.  datoff is always 16 (the Bucket header
 * is padded to 16 bytes on all APE targets).
 *
 * For over-allocated aligned blocks, we place an AlignHdr at
 * (aligned_ptr - DATOFF) — exactly where free() looks.  free()
 * detects ALIGN_MAGIC there and recurses with the original
 * malloc return value instead of aborting.
 *
 * AlignHdr layout (16 bytes = DATOFF, offsets are byte-level):
 *   [0..3]  int  magic   — ALIGN_MAGIC
 *   [4..7]  int  _pad
 *   [8..15] void *orig   — original malloc() return value
 *
 * The .orig field starts at byte 8 on all targets:
 *   - 64-bit: int(4)+int(4)+void*(8) = 16 bytes ✓
 *   - 32-bit: int(4)+int(4)+void*(4) = 12 bytes, but we only use
 *             bytes 8..11 so 16-byte extent is still safe ✓
 */

#ifndef _MALLOC_ALIGN_H
#define _MALLOC_ALIGN_H

#include <stdint.h>

#define DATOFF       16                 /* must match datoff in malloc.c/free.c */
#define ALIGN_MAGIC  0xA11900CC        /* sentinel for aligned-fallback blocks  */

static inline void
malign_place(void *aligned, void *orig)
{
	char *hdr = (char*)aligned - DATOFF;
	*(int*)(hdr + 0) = (int)ALIGN_MAGIC;
	*(int*)(hdr + 4) = 0;
	*(void**)(hdr + 8) = orig;
}

static inline int
malign_check(void *bp_ptr)
{
	return *(int*)bp_ptr == (int)ALIGN_MAGIC;
}

static inline void*
malign_orig(void *bp_ptr)
{
	return *(void**)((char*)bp_ptr + 8);
}

#endif /* _MALLOC_ALIGN_H */
