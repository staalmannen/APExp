
/*
 * Portable Object Compiler - Postlink Auxiliary File
 * (c) 1997-2019 David Stes. All rights reserved.
 *
 * UNIX configuration file for postlink.
 * objc -dl initializer for ld.so (or similar) runtime linkers.
 */

extern void loadobjc(void *);
extern void unloadobjc(void *);

/* _msgControl is emitted by postlink (prepended to this file) */

void _init(void) { loadobjc(_msgControl); }
void _fini(void) { unloadobjc(_msgControl); }

