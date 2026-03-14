#include "cc.h"

/*
 * Weak-symbol default stubs for VLA frame management.
 *
 * These are compiled into cc.a (the common frontend library).
 * Each backend (6c, 8c, 5c) overrides gvla_prologue and gvla_epilogue
 * with strong definitions in its own vla.c, which includes gc.h and
 * has access to the backend instruction emitters.
 *
 * gret() is also overridden per-backend because it must call
 * gvla_epilogue() before emitting the return instruction.
 * The stub here is never actually reached when a backend is linked;
 * it exists only to satisfy the linker for tools that include cc.a
 * but do not provide their own definitions.
 */
#pragma	weak	gvla_prologue
void gvla_prologue(void) {}

#pragma	weak	gvla_epilogue
void gvla_epilogue(void) {}

#pragma	weak	gret
void gret(void) {}
