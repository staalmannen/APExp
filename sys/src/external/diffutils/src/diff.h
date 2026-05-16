/* Shared definitions for GNU DIFF

   Copyright (C) 1988-1989, 1991-1995, 1998, 2001-2002, 2004, 2009-2013,
   2015-2025 Free Software Foundation, Inc.

   This file is part of GNU DIFF.

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

#include "system.h"
#include <regex.h>
#include <stdio.h>
#include <unlocked-io.h>

_GL_INLINE_HEADER_BEGIN

#ifndef DIFF_INLINE
# define DIFF_INLINE _GL_INLINE
#endif

/* What kind of changes a hunk contains.  */
enum changes
{
  /* No changes: lines common to both files.  */
  UNCHANGED,

  /* Deletes only: lines taken from just the first file.  */
  OLD,

  /* Inserts only: lines taken from just the second file.  */
  NEW,

  /* Both deletes and inserts: a hunk containing both old and new lines.  */
  CHANGED
};

/* When colors should be used in the output.  */
enum colors_style
{
  /* Never output colors.  */
  NEVER,

  /* Output colors if the output is a terminal.  */
  AUTO,

  /* Always output colors.  */
  ALWAYS,
};

/* Variables for command line options */

enum output_style
{
  /* No output style specified.  */
  OUTPUT_UNSPECIFIED,

  /* Default output style.  */
  OUTPUT_NORMAL,

  /* Output the differences with lines of context before and after (-c).  */
  OUTPUT_CONTEXT,

  /* Output the differences in a unified context diff format (-u).  */
  OUTPUT_UNIFIED,

  /* Output the differences as commands suitable for 'ed' (-e).  */
  OUTPUT_ED,

  /* Output the diff as a forward ed script (-f).  */
  OUTPUT_FORWARD_ED,

  /* Like -f, but output a count of changed lines in each "command" (-n).  */
  OUTPUT_RCS,

  /* Output merged #ifdef'd file (-D).  */
  OUTPUT_IFDEF,

  /* Output sdiff style (-y).  */
  OUTPUT_SDIFF
};

/* True for output styles that are robust,
   i.e. can handle a file that ends in a non-newline.
   This is indented unusually to pacify 'make syntax-check'.  */
DIFF_INLINE bool robust_output_style (enum output_style s)
{
  return s != OUTPUT_ED && s != OUTPUT_FORWARD_ED;
}

extern enum output_style output_style;

/* Define the current color context used to print a line.  */
extern enum colors_style colors_style;

/* Nonzero if output cannot be generated for identical files.  */
extern bool no_diff_means_no_output;

/* Number of lines of context to show in each set of diffs.
   This is zero when context is not to be shown.  */
extern lin context;

/* Consider all files as text files (-a).
   Don't interpret codes over 0177 as implying a "binary file".  */
extern bool text;

/* Number of lines to keep in identical prefix and suffix.  */
extern lin horizon_lines;

/* The significance of white space during comparisons.  */
enum DIFF_white_space
{
  /* All white space is significant (the default).  */
  IGNORE_NO_WHITE_SPACE,

  /* Ignore changes due to tab expansion (-E).  */
  IGNORE_TAB_EXPANSION,

  /* Ignore changes in trailing horizontal white space (-Z).  */
  IGNORE_TRAILING_SPACE,

  /* IGNORE_TAB_EXPANSION and IGNORE_TRAILING_SPACE are a special case
     because they are independent and can be ORed together, yielding
     IGNORE_TAB_EXPANSION_AND_TRAILING_SPACE.  */
  IGNORE_TAB_EXPANSION_AND_TRAILING_SPACE,

  /* Ignore changes in horizontal white space (-b).  */
  IGNORE_SPACE_CHANGE,

  /* Ignore all horizontal white space (-w).  */
  IGNORE_ALL_SPACE
};
extern enum DIFF_white_space ignore_white_space;

/* Ignore changes that affect only blank lines (-B).  */
extern bool ignore_blank_lines;

/* Files can be compared byte-by-byte, as if they were binary.
   This depends on various options.  */
extern bool files_can_be_treated_as_binary;

/* Ignore differences in case of letters (-i).  */
extern bool ignore_case;

/* Ignore differences in case of letters in file names.  */
extern bool ignore_file_name_case;

/* Act on symbolic links themselves rather than on their target
   (--no-dereference).  */
extern bool no_dereference_symlinks;

/* Local timezone for 'c' output headers, if needed.  */
#if HAVE_TM_GMTOFF
# define localtz 0 /* Placeholder since localtz is never needed.  */
#else
extern timezone_t localtz;
#endif

/* File labels for '-c' output headers (--label).  */
extern char *file_label[2];

/* Regexp to identify function-header lines (-F).  */
extern struct re_pattern_buffer function_regexp;

/* Ignore changes that affect only lines matching this regexp (-I).  */
extern struct re_pattern_buffer ignore_regexp;

/* Say only whether files differ, not how (-q).  */
extern bool brief;

/* Expand tabs in the output so the text lines up properly
   despite the characters added to the front of each line (-t).  */
extern bool expand_tabs;

/* Number of columns between tab stops.  */
extern intmax_t tabsize;

/* Use a tab in the output, rather than a space, before the text of an
   input line, so as to keep the proper alignment in the input line
   without changing the characters in it (-T).  */
extern bool initial_tab;

/* Do not output an initial space or tab before the text of an empty line.  */
extern bool suppress_blank_empty;

/* Remove trailing carriage returns from input.  */
extern bool strip_trailing_cr;

/* In directory comparison, specify file to start with (-S).
   This is used for resuming an aborted comparison.
   All file names less than this name are ignored.  */
extern char const *starting_file;

/* Pipe each file's output through pr (-l).  */
extern bool paginate;

/* Line group formats for unchanged, old, new, and changed groups.  */
extern char const *group_format[CHANGED + 1];

/* Line formats for unchanged, old, and new lines.  */
extern char const *line_format[NEW + 1];

/* If using OUTPUT_SDIFF print extra information to help the sdiff filter.  */
extern bool sdiff_merge_assist;

/* Tell OUTPUT_SDIFF to show only the left version of common lines.  */
extern bool left_column;

/* Tell OUTPUT_SDIFF to not show common lines.  */
extern bool suppress_common_lines;

/* The half line width and column 2 offset for OUTPUT_SDIFF.  */
extern intmax_t sdiff_half_width;
extern intmax_t sdiff_column2_offset;

/* String containing all the command options diff received,
   with spaces between and at the beginning but none at the end.
   If there were no options given, this string is empty.  */
extern char *switch_string;

/* Use heuristics for better speed with large files with a small
   density of changes.  */
extern bool speed_large_files;

/* Patterns that match file names to be excluded.  */
extern struct exclude *excluded;

/* Don't discard lines.  This makes things slower (sometimes much
   slower) but will find a guaranteed minimal set of changes.  */
extern bool minimal;

/* The strftime format to use for time strings.  */
extern char const *time_format;

/* The result of comparison is an "edit script": a chain of 'struct change'.
   Each 'struct change' represents one place where some lines are deleted
   and some are inserted.

   LINE0 and LINE1 are the first affected lines in the two files (origin 0).
   DELETED is the number of lines deleted here from file 0.
   INSERTED is the number of lines inserted here in file 1.

   If DELETED is 0 then LINE0 is the number of the line before
   which the insertion was done; vice versa for INSERTED and LINE1.  */

struct change
{
  struct change *link;		/* Previous or next edit command  */
  lin inserted;			/* # lines of file 1 changed here.  */
  lin deleted;			/* # lines of file 0 changed here.  */
  lin line0;			/* Line number of 1st deleted line.  */
  lin line1;			/* Line number of 1st inserted line.  */
  bool ignore;			/* Flag used in context.c.  */
};

/* Structures that describe the input files.  */

/* Directory entry types.  Like dirent DT_* macros, but portable and
   safe to use as 'char'.  Use the same values as GNU/Linux, as this
   may help compilers on that platform.  */
enum detype
  {
    DE_UNKNOWN,
    DE_FIFO,
    DE_CHR,
    DE_DIR = 4,
    DE_BLK = 6,
    DE_REG = 8,
    DE_LNK = 10,
    DE_SOCK = 12,
    DE_WHT = 14,

    /* This one is not in GNU/Linux; it means the directory entry
       type has been determined but is none of the above.  */
    DE_OTHER
  };

/* Data on one input file being compared.  */

struct file_data {
    int             desc;	/* File descriptor  */
    int             openerr;	/* openat errno, or 0  */
    int             err;	/* openat or fstatat or fstat errno, or 0  */
    char const      *name;	/* File name  */
    char const      *filetype;	/* file type as untranslated string  */
    struct stat     stat;	/* File status */

    /* Directory stream corresponding to DESC, if it has been fdopendir'ed.
       Null otherwise.  */
    DIR *dirstream;

    /* Buffer in which text of file is read.  */
    word *buffer;

    /* Allocated size of buffer, in bytes.  Always a multiple of
       sizeof *buffer.  */
    idx_t bufsize;

    /* Number of valid bytes now in the buffer.  */
    idx_t buffered;

    /* Array of pointers to lines in the file.  */
    char const **linbuf;

    /* linbuf_base <= 0 <= buffered_lines <= valid_lines <= alloc_lines.
       linbuf[0 ... buffered_lines - 1] are possibly differing.
       linbuf[linbuf_base ... valid_lines - 1] contain valid data.
       linbuf[linbuf_base ... alloc_lines - 1] are allocated.  */
    lin linbuf_base, buffered_lines, valid_lines, alloc_lines;

    /* Pointer to end of prefix of this file to ignore when hashing.  */
    char const *prefix_end;

    /* Count of lines in the prefix.
       There are this many lines in the file before linbuf[0].  */
    lin prefix_lines;

    /* Pointer to start of suffix of this file to ignore when hashing.  */
    char const *suffix_begin;

    /* Vector, indexed by line number, containing an equivalence code for
       each line.  It is this vector that is actually compared with that
       of another file to generate differences.  */
    lin *equivs;

    /* Vector, like the previous one except that
       the elements for discarded lines have been squeezed out.  */
    lin *undiscarded;

    /* Vector mapping virtual line numbers (not counting discarded lines)
       to real ones (counting those lines).  Both are origin-0.  */
    lin *realindexes;

    /* Total number of nondiscarded lines.  */
    lin nondiscarded_lines;

    /* Vector, indexed by real origin-0 line number,
       containing true for a line that is an insertion or a deletion.
       The results of comparison are stored here.  */
    bool *changed;

    /* 1 if file ends in a line with no final newline.  */
    bool missing_newline;

    /* 1 if at end of file.  */
    bool eof;

    /* 1 more than the maximum equivalence value used for this or its
       sibling file.  */
    lin equiv_max;
};

/* struct file_data.desc markers.
   A top level parent directory desc can be AT_FDCWD;
   it is OK if AT_FDCWD is one of these other values.  */
enum { OPEN_FAILED = -1 }; /* open was attempted but failed */
enum { NONEXISTENT = -2 }; /* nonexistent file */
enum { UNOPENED = -3 }; /* unopened file (e.g., file type mismatch) */

/* Data on two input files being compared.  */

struct comparison
  {
    /* The two files.  */
    struct file_data file[2];

    /* The parent comparison, or &noparent if at the top level.  */
    struct comparison const *parent;
  };

/* Describe the two files currently being compared.  */

extern struct comparison curr;

/* A placeholder for the parent of the top level comparison.
   Only the desc slots are used; although they are typically AT_FDCWD,
   one might be nonnegative for a directory at the top level
   for 'diff DIR FILE' or 'diff FILE DIR'.  */

extern struct comparison noparent;

/* Stdio stream to output diffs to.  */

extern FILE *outfile;

/* Declare various functions.  */

/* analyze.c */
extern int diff_2_files (struct comparison *);

/* context.c */
extern void print_context_header (struct file_data[],
				  char const *const *, bool);
extern void print_context_script (struct change *, bool);

/* diff.c */
extern int compare_files (struct comparison const *, enum detype const[2],
			  char const *, char const *);

/* dir.c */
extern int diff_dirs (struct comparison *);
extern char *find_dir_file_pathname (struct file_data *, char const *,
				     enum detype *)
  ATTRIBUTE_MALLOC ATTRIBUTE_DEALLOC_FREE
  ATTRIBUTE_RETURNS_NONNULL;

/* ed.c */
extern void print_ed_script (struct change *);
extern void pr_forward_ed_script (struct change *);

/* ifdef.c */
extern void print_ifdef_script (struct change *);

/* io.c */
extern void file_block_read (struct file_data *, idx_t);
extern bool read_files (struct file_data[], bool);

/* normal.c */
extern void print_normal_script (struct change *);

/* rcs.c */
extern void print_rcs_script (struct change *);

/* side.c */
extern void print_sdiff_script (struct change *);

/* util.c */
extern char const change_letter[4];
extern char const pr_program[];
extern lin translate_line_number (struct file_data const *, lin)
  ATTRIBUTE_PURE;
extern struct change *find_change (struct change *) ATTRIBUTE_CONST;
extern enum changes analyze_hunk (struct change *, lin *, lin *, lin *, lin *);
extern void begin_output (void);
extern void cleanup_signal_handlers (void);
extern void debug_script (struct change *);
extern _Noreturn void fatal (char const *);
extern void finish_output (void);
extern void message (char const *, ...) ATTRIBUTE_FORMAT ((printf, 1, 2));
extern void output_1_line (char const *, char const *, char const *,
                           char const *);
extern void perror_with_name (char const *);
extern _Noreturn void pfatal_with_name (char const *);
extern void print_1_line (char const *, char const *const *);
extern void print_1_line_nl (char const *, char const *const *, bool);
extern void print_message_queue (void);
extern void print_number_range (char, struct file_data *, lin, lin);
extern void print_script (struct change *, struct change * (*) (struct change *),
                          void (*) (struct change *));
extern void setup_output (char const *, char const *, bool);
extern void translate_range (struct file_data const *, lin, lin, lin *, lin *);

enum color_context
{
  HEADER_CONTEXT,
  ADD_CONTEXT,
  DELETE_CONTEXT,
  RESET_CONTEXT,
  LINE_NUMBER_CONTEXT,
};

extern bool presume_output_tty;

extern void set_color_context (enum color_context color_context);
extern void set_color_palette (char *palette);

_GL_INLINE_HEADER_END
