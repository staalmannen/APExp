/*
 * dwtypes.h — function type-info sidecar writer hook.
 * Included by pgen.c; Sym must be visible (via gc.h → cc.h) before this.
 */
void dwtypes_emit_func(Sym *func);
