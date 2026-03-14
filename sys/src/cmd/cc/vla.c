#include "cc.h"

/*
 * gvla_prologue / gvla_epilogue / gret
 *
 * No-op defaults compiled into cc.a.  Each back-end that needs to
 * bracket VLA functions with a frame-pointer save/restore provides
 * strong definitions of these three functions in its own txt.c.
 * The Plan 9 linker resolves to the strong definition when present.
 *
 * Note: gvlalloc() is NOT defined here.  It must call gen(), which is
 * a back-end function declared in gc.h and defined per-arch.  Each
 * back-end therefore defines gvlalloc() in its own pgen.c or a new
 * vla.c compiled as part of that back-end, where gc.h is in scope.
 * See 6c/vla.c, 8c/vla.c, 5c/vla.c.
 */
#pragma	weak	gvla_prologue
void gvla_prologue(void) {}

#pragma	weak	gvla_epilogue
void gvla_epilogue(void) {}

#pragma	weak	gret
void gret(void) { gbranch(ORETURN); }
