// Copyright 2010 The Go Authors. All rights reserved.
// Use of this source code is governed by a BSD-style
// license that can be found in the LICENSE file.


/*
 * Offsets and sizes of the DWARF debug sections, set by dwarfemitdebugsections().
 * Exposed so that elf.c (and any future format handler) can create section headers
 * without pulling in ELF-specific code into dwarf.c.
 */
extern vlong dwarfabbrevo;
extern vlong dwarfabbrevsize;
extern vlong dwarflineo;
extern vlong dwarflinesize;
extern vlong dwarfinfoo;
extern vlong dwarfinfosize;
extern vlong dwarfframeo;
extern vlong dwarfframesize;

/*
 * Register 'f' symbol file fragments.  Doing this while parsing the
 * .6 input saves a pass over the symbol table later.
 */
void dwarfaddfrag(int n, char* frag);

/*
 * Emit debug_abbrevs, debug_info and debug_line sections to current
 * offset in cout.
 */
void dwarfemitdebugsections(void);
