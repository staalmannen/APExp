// Copyright 2010 The Go Authors. All rights reserved.
// Use of this source code is governed by a BSD-style
// license that can be found in the LICENSE file.

#ifndef _LD_DWARF_H_
#define _LD_DWARF_H_

/*
 * Register 'f' symbol file fragments.  Doing this while parsing the
 * .6 input saves a pass over the symbol table later.
 */
void dwarfaddfrag(int n, char* frag);

/*
 * Offsets and sizes of the four debug sections as emitted by
 * dwarfemitdebugsections().  Filled in by the function; used by the
 * arch linker to build an ELF section header table.
 */
typedef struct DwarfSects DwarfSects;
struct DwarfSects {
	vlong abbrev_off, abbrev_sz;
	vlong line_off,   line_sz;
	vlong frame_off,  frame_sz;
	vlong info_off,   info_sz;
};

/*
 * Emit .debug_abbrev, .debug_line, .debug_frame, .debug_info sections
 * to the current position in cout.  If out != nil, fills *out with
 * each section's file offset and byte size.
 */
void dwarfemitdebugsections(DwarfSects *out);

#endif /* _LD_DWARF_H_ */
