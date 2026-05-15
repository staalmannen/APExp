/* reading patches */

/* Copyright 1990-2025 Free Software Foundation, Inc.
   Copyright 1986-1988 Larry Wall

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

enum nametype { OLD, NEW, INDEX, NONE };

/* General purpose buffer.  */
extern char *patchbuf;

/* Allocated size of buf.  It is at least IO_BUFSIZE.  */
extern idx_t patchbufsize;

void grow_patchbuf (void);
idx_t pch_end (void) ATTRIBUTE_PURE;
idx_t pch_first (void) ATTRIBUTE_PURE;
idx_t pch_hunk_beg (void) ATTRIBUTE_PURE;
char const *pch_c_function (void) ATTRIBUTE_PURE;
bool pch_git_diff (void) ATTRIBUTE_PURE;
char const * pch_timestr (bool which) ATTRIBUTE_PURE;
mode_t pch_mode (bool which) ATTRIBUTE_PURE;
idx_t pch_newfirst (void) ATTRIBUTE_PURE;
idx_t pch_prefix_context (void) ATTRIBUTE_PURE;
idx_t pch_ptrn_lines (void) ATTRIBUTE_PURE;
idx_t pch_repl_lines (void) ATTRIBUTE_PURE;
idx_t pch_suffix_context (void) ATTRIBUTE_PURE;
void pch_swap (void);
bool pch_write_line (idx_t, FILE *);
bool there_is_another_patch (bool, mode_t *);
char *pfetch (idx_t) ATTRIBUTE_PURE;
char pch_char (idx_t) ATTRIBUTE_PURE;
bool another_hunk (enum diff, bool);
char pch_says_nonexistent (bool) ATTRIBUTE_PURE;
idx_t pch_line_len (idx_t) ATTRIBUTE_PURE;
char *pch_name (enum nametype) ATTRIBUTE_PURE;
bool pch_copy (void) ATTRIBUTE_PURE;
bool pch_rename (void) ATTRIBUTE_PURE;
void do_ed_script (char *, struct outfile *, FILE *);
void open_patch_file (char const *);
void re_patch (void);
void pch_normalize (enum diff);

extern struct timespec p_timestamp[2];  /* timestamps in patch headers */
