/* GNU diff - compare files line by line

   Copyright (C) 1988-1989, 1992-1994, 1996, 1998, 2001-2002, 2004, 2006-2007,
   2009-2013, 2015-2025 Free Software Foundation, Inc.

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

#define DIFF_INLINE _GL_EXTERN_INLINE
#include "diff.h"
#include "paths.h"

#include <binary-io.h>
#include <c-ctype.h>
#include <c-stack.h>
#include <careadlinkat.h>
#include <diagnose.h>
#include <dirname.h>
#include <error.h>
#include <exclude.h>
#include <exitfail.h>
#include <file-type.h>
#include <filenamecat.h>
#include <fnmatch.h>
#include <getopt.h>
#include <hard-locale.h>
#include <progname.h>
#include <quote.h>
#include <sh-quote.h>
#include <stat-time.h>
#include <version-etc.h>
#include <xalloc.h>
#include <xstdopen.h>

#ifdef MAJOR_IN_MKDEV
# include <sys/mkdev.h>
#elif defined MAJOR_IN_SYSMACROS
# include <sys/sysmacros.h>
#elif !defined major /* Might be defined in sys/types.h.  */
# define major(dev)  (((dev) >> 8) & 0xff)
# define minor(dev)  ((dev) & 0xff)
#endif

/* The official name of this program (e.g., no 'g' prefix).  */
static char const PROGRAM_NAME[] = "diff";

#define AUTHORS \
  _("Paul Eggert"), \
  _("Mike Haertel"), \
  _("David Hayes"), \
  _("Richard Stallman"), \
  _("Len Tower")

#ifndef GUTTER_WIDTH_MINIMUM
# define GUTTER_WIDTH_MINIMUM 3
#endif

struct regexp_list
{
  char *regexps;	/* chars representing disjunction of the regexps */
  idx_t len;		/* chars used in 'regexps' */
  idx_t size;		/* size malloc'ed for 'regexps'; 0 if not malloc'ed */
  bool multiple_regexps;/* Does 'regexps' represent a disjunction?  */
  struct re_pattern_buffer *buf;
};

static void add_regexp (struct regexp_list *, char const *);
static void summarize_regexp_list (struct regexp_list *);
static void specify_style (enum output_style);
static void specify_value (char const **, char const *, char const *);
static void specify_colors_style (char const *);
static void check_stdout (void);
static void usage (void);

/* If comparing directories, compare their common subdirectories
   recursively.  */
static bool recursive;

/* In context diffs, show previous lines that match these regexps.  */
static struct regexp_list function_regexp_list;

/* Ignore changes affecting only lines that match these regexps.  */
static struct regexp_list ignore_regexp_list;

#if O_BINARY
/* Use binary I/O when reading and writing data (--binary).
   On POSIX hosts, this has no effect.  */
static bool binary;
#else
enum { binary = true };
#endif

/* Use Linux-style O_PATH if available and supported by fstat(),
   POSIX-style O_SEARCH otherwise.  */
#if O_PATH_SUPPORTS_FSTAT
enum { O_PATH_DEFINED = true };
enum { O_PATHSEARCH = O_PATH };
#else
enum { O_PATH_DEFINED = false };
enum { O_PATHSEARCH = O_SEARCH };
#endif

/* If one file is missing, treat it as present but empty (-N).  */
static bool new_file;

/* If the first file is missing, treat it as present but empty
   (--unidirectional-new-file).  */
static bool unidirectional_new_file;

/* Report files compared that are the same (-s).
   Normally nothing is output when that happens.  */
static bool report_identical_files;

/* Do not treat directories specially.  */
static bool no_directory;

/* Values for long options that do not have single-letter equivalents.  */
enum
{
  BINARY_OPTION = CHAR_MAX + 1,
  FROM_FILE_OPTION,
  HELP_OPTION,
  HORIZON_LINES_OPTION,
  IGNORE_FILE_NAME_CASE_OPTION,
  INHIBIT_HUNK_MERGE_OPTION,
  LEFT_COLUMN_OPTION,
  LINE_FORMAT_OPTION,
  NO_DEREFERENCE_OPTION,
  NO_IGNORE_FILE_NAME_CASE_OPTION,
  NORMAL_OPTION,
  SDIFF_MERGE_ASSIST_OPTION,
  STRIP_TRAILING_CR_OPTION,
  SUPPRESS_BLANK_EMPTY_OPTION,
  SUPPRESS_COMMON_LINES_OPTION,
  TABSIZE_OPTION,
  TO_FILE_OPTION,

  /* These options must be in sequence.  */
  UNCHANGED_LINE_FORMAT_OPTION,
  OLD_LINE_FORMAT_OPTION,
  NEW_LINE_FORMAT_OPTION,

  /* These options must be in sequence.  */
  UNCHANGED_GROUP_FORMAT_OPTION,
  OLD_GROUP_FORMAT_OPTION,
  NEW_GROUP_FORMAT_OPTION,
  CHANGED_GROUP_FORMAT_OPTION,

  COLOR_OPTION,
  COLOR_PALETTE_OPTION,

  NO_DIRECTORY_OPTION,
  PRESUME_OUTPUT_TTY_OPTION,
};

static char const group_format_option[][sizeof "--unchanged-group-format"] =
  {
    "--unchanged-group-format",
    "--old-group-format",
    "--new-group-format",
    "--changed-group-format"
  };

static char const line_format_option[][sizeof "--unchanged-line-format"] =
  {
    "--unchanged-line-format",
    "--old-line-format",
    "--new-line-format"
  };

static char const shortopts[] =
  "0123456789abBcC:dD:eEfF:hHiI:lL:nNpPqrsS:tTuU:vwW:x:X:yZ";
static struct option const longopts[] =
{
  {"binary", 0, 0, BINARY_OPTION},
  {"brief", 0, 0, 'q'},
  {"changed-group-format", 1, 0, CHANGED_GROUP_FORMAT_OPTION},
  {"color", 2, 0, COLOR_OPTION},
  {"context", 2, 0, 'C'},
  {"ed", 0, 0, 'e'},
  {"exclude", 1, 0, 'x'},
  {"exclude-from", 1, 0, 'X'},
  {"expand-tabs", 0, 0, 't'},
  {"forward-ed", 0, 0, 'f'},
  {"from-file", 1, 0, FROM_FILE_OPTION},
  {"help", 0, 0, HELP_OPTION},
  {"horizon-lines", 1, 0, HORIZON_LINES_OPTION},
  {"ifdef", 1, 0, 'D'},
  {"ignore-all-space", 0, 0, 'w'},
  {"ignore-blank-lines", 0, 0, 'B'},
  {"ignore-case", 0, 0, 'i'},
  {"ignore-file-name-case", 0, 0, IGNORE_FILE_NAME_CASE_OPTION},
  {"ignore-matching-lines", 1, 0, 'I'},
  {"ignore-space-change", 0, 0, 'b'},
  {"ignore-tab-expansion", 0, 0, 'E'},
  {"ignore-trailing-space", 0, 0, 'Z'},
  {"inhibit-hunk-merge", 0, 0, INHIBIT_HUNK_MERGE_OPTION},
  {"initial-tab", 0, 0, 'T'},
  {"label", 1, 0, 'L'},
  {"left-column", 0, 0, LEFT_COLUMN_OPTION},
  {"line-format", 1, 0, LINE_FORMAT_OPTION},
  {"minimal", 0, 0, 'd'},
  {"new-file", 0, 0, 'N'},
  {"new-group-format", 1, 0, NEW_GROUP_FORMAT_OPTION},
  {"new-line-format", 1, 0, NEW_LINE_FORMAT_OPTION},
  {"no-dereference", 0, 0, NO_DEREFERENCE_OPTION},
  {"no-ignore-file-name-case", 0, 0, NO_IGNORE_FILE_NAME_CASE_OPTION},
  {"normal", 0, 0, NORMAL_OPTION},
  {"old-group-format", 1, 0, OLD_GROUP_FORMAT_OPTION},
  {"old-line-format", 1, 0, OLD_LINE_FORMAT_OPTION},
  {"paginate", 0, 0, 'l'},
  {"palette", 1, 0, COLOR_PALETTE_OPTION},
  {"rcs", 0, 0, 'n'},
  {"recursive", 0, 0, 'r'},
  {"report-identical-files", 0, 0, 's'},
  {"sdiff-merge-assist", 0, 0, SDIFF_MERGE_ASSIST_OPTION},
  {"show-c-function", 0, 0, 'p'},
  {"show-function-line", 1, 0, 'F'},
  {"side-by-side", 0, 0, 'y'},
  {"speed-large-files", 0, 0, 'H'},
  {"starting-file", 1, 0, 'S'},
  {"strip-trailing-cr", 0, 0, STRIP_TRAILING_CR_OPTION},
  {"suppress-blank-empty", 0, 0, SUPPRESS_BLANK_EMPTY_OPTION},
  {"suppress-common-lines", 0, 0, SUPPRESS_COMMON_LINES_OPTION},
  {"tabsize", 1, 0, TABSIZE_OPTION},
  {"text", 0, 0, 'a'},
  {"to-file", 1, 0, TO_FILE_OPTION},
  {"unchanged-group-format", 1, 0, UNCHANGED_GROUP_FORMAT_OPTION},
  {"unchanged-line-format", 1, 0, UNCHANGED_LINE_FORMAT_OPTION},
  {"unidirectional-new-file", 0, 0, 'P'},
  {"unified", 2, 0, 'U'},
  {"version", 0, 0, 'v'},
  {"width", 1, 0, 'W'},

  /* This is solely for diff3.  Do not document.  */
  {"-no-directory", no_argument, nullptr, NO_DIRECTORY_OPTION},

  /* This is solely for testing.  Do not document.  */
  {"-presume-output-tty", no_argument, nullptr, PRESUME_OUTPUT_TTY_OPTION},
  {0, 0, 0, 0}
};

/* Return a string containing the command options with which diff was invoked.
   Spaces appear between what were separate ARGV-elements.
   There is a space at the beginning but none at the end.
   If there were no options, the result is an empty string.

   Arguments: OPTIONVEC, a vector containing separate ARGV-elements, and COUNT,
   the length of that vector.  */

static char *
option_list (char **optionvec, int count)
{
  idx_t size = 1;

  for (int i = 0; i < count; i++)
    {
      size_t optsize = 1 + shell_quote_length (optionvec[i]);
      if (ckd_add (&size, size, optsize))
	xalloc_die ();
    }

  char *result = ximalloc (size);
  char *p = result;

  for (int i = 0; i < count; i++)
    {
      *p++ = ' ';
      p = shell_quote_copy (p, optionvec[i]);
    }

  *p = '\0';
  return result;
}


/* Return an option value suitable for add_exclude.  */

static int
exclude_options (void)
{
  return EXCLUDE_WILDCARDS | (ignore_file_name_case ? FNM_CASEFOLD : 0);
}

int
main (int argc, char **argv)
{
  /* Do our initializations.  */
  exit_failure = EXIT_TROUBLE;
  initialize_main (&argc, &argv);
  set_program_name (argv[0]);
  setlocale (LC_ALL, "");
  bindtextdomain (PACKAGE, LOCALEDIR);
  bindtextdomain ("gnulib", GNULIB_LOCALEDIR);
  textdomain (PACKAGE);
  c_stack_action (nullptr);
  function_regexp_list.buf = &function_regexp;
  ignore_regexp_list.buf = &ignore_regexp;
  re_set_syntax (RE_SYNTAX_GREP | RE_NO_POSIX_BACKTRACKING);
  excluded = new_exclude ();
  presume_output_tty = false;
  xstdopen ();

  /* Parse command line options.  */

  lin ocontext = -1;
  bool explicit_context = false;
  intmax_t width = 0;
  bool show_c_function = false;
  char const *from_file = nullptr;
  char const *to_file = nullptr;

  for (int prev = -1, c;
       0 <= (c = getopt_long (argc, argv, shortopts, longopts, nullptr));
       prev = c)
    switch (c)
      {
      case 0:
	break;

      case '0':
      case '1':
      case '2':
      case '3':
      case '4':
      case '5':
      case '6':
      case '7':
      case '8':
      case '9':
	if (! c_isdigit (prev))
	  ocontext = 0;
	if (ckd_mul (&ocontext, ocontext, 10)
	    || ckd_add (&ocontext, ocontext, c - '0'))
	  ocontext = LIN_MAX;
	break;

      case 'a':
	text = true;
	break;

      case 'b':
	if (ignore_white_space < IGNORE_SPACE_CHANGE)
	  ignore_white_space = IGNORE_SPACE_CHANGE;
	break;

      case 'Z':
	if (ignore_white_space < IGNORE_SPACE_CHANGE)
	  ignore_white_space |= IGNORE_TRAILING_SPACE;
	break;

      case 'B':
	ignore_blank_lines = true;
	break;

      case 'C':
      case 'U':
	{
	  intmax_t numval;

	  if (optarg)
	    {
	      char *numend;
	      numval = strtoimax (optarg, &numend, 10);
	      if (*numend || numval < 0)
		try_help ("invalid context length %s", quote (optarg));
	    }
	  else
	    numval = 3;

	  specify_style (c == 'U' ? OUTPUT_UNIFIED : OUTPUT_CONTEXT);
	  if (context < numval)
	    context = MIN (numval, LIN_MAX);
	  explicit_context = true;
	}
	break;

      case 'c':
	specify_style (OUTPUT_CONTEXT);
	if (context < 3)
	  context = 3;
	break;

      case 'd':
	minimal = true;
	break;

      case 'D':
	specify_style (OUTPUT_IFDEF);
	{
	  static char const C_ifdef_group_formats[]
	    = (/* UNCHANGED */
	       "%="
	       "\0"

	       /* OLD */
	       "#ifndef @\n"
	       "%<"
	       "#endif /* ! @ */\n"
	       "\0"

	       /* NEW */
	       "#ifdef @\n"
	       "%>"
	       "#endif /* @ */\n"
	       "\0"

	       /* CHANGED */
	       "#ifndef @\n"
	       "%<"
	       "#else /* @ */\n"
	       "%>"
	       "#endif /* @ */\n");
	  int nats = 7; /* 7 "@"s are in C_ifdef_group_formats.  */

	  char *b = xinmalloc (((sizeof C_ifdef_group_formats + 1) / nats
				+ strlen (optarg)),
			       nats);
	  char *base = b;
	  int changes = 0;

	  for (int i = 0; i < sizeof C_ifdef_group_formats; i++)
	    {
	      char ch = C_ifdef_group_formats[i];
	      switch (ch)
		{
		default:
		  *b++ = ch;
		  break;

		case '@':
		  b = stpcpy (b, optarg);
		  break;

		case '\0':
		  *b++ = ch;
		  specify_value (&group_format[changes++], base, "-D");
		  base = b;
		  break;
		}
	    }
	}
	break;

      case 'e':
	specify_style (OUTPUT_ED);
	break;

      case 'E':
	if (ignore_white_space < IGNORE_SPACE_CHANGE)
	  ignore_white_space |= IGNORE_TAB_EXPANSION;
	break;

      case 'f':
	specify_style (OUTPUT_FORWARD_ED);
	break;

      case 'F':
	add_regexp (&function_regexp_list, optarg);
	break;

      case 'h':
	/* Split the files into chunks for faster processing.
	   Usually does not change the result.

	   This currently has no effect.  */
	break;

      case 'H':
	speed_large_files = true;
	break;

      case 'i':
	ignore_case = true;
	break;

      case 'I':
	add_regexp (&ignore_regexp_list, optarg);
	break;

      case 'l':
	if (!pr_program[0])
	  try_help ("pagination not supported on this host", nullptr);
	paginate = true;
#ifdef SIGCHLD
	/* Pagination requires forking and waiting, and
	   System V fork+wait does not work if SIGCHLD is ignored.  */
	signal (SIGCHLD, SIG_DFL);
#endif
	break;

      case 'L':
	if (!file_label[0])
	  file_label[0] = optarg;
	else if (!file_label[1])
	  file_label[1] = optarg;
	else
	  fatal ("too many file label options");
	break;

      case 'n':
	specify_style (OUTPUT_RCS);
	break;

      case 'N':
	new_file = true;
	break;

      case 'p':
	show_c_function = true;
	add_regexp (&function_regexp_list, "^[[:alpha:]$_]");
	break;

      case 'P':
	unidirectional_new_file = true;
	break;

      case 'q':
	brief = true;
	break;

      case 'r':
	recursive = true;
	break;

      case 's':
	report_identical_files = true;
	break;

      case 'S':
	specify_value (&starting_file, optarg, "-S");
	break;

      case 't':
	expand_tabs = true;
	break;

      case 'T':
	initial_tab = true;
	break;

      case 'u':
	specify_style (OUTPUT_UNIFIED);
	if (context < 3)
	  context = 3;
	break;

      case 'v':
	version_etc (stdout, PROGRAM_NAME, PACKAGE_NAME, Version,
		     AUTHORS, nullptr);
	check_stdout ();
	return EXIT_SUCCESS;

      case 'w':
	ignore_white_space = IGNORE_ALL_SPACE;
	break;

      case 'x':
	add_exclude (excluded, optarg, exclude_options ());
	break;

      case 'X':
	if (add_exclude_file (add_exclude, excluded, optarg,
			      exclude_options (), '\n'))
	  pfatal_with_name (optarg);
	break;

      case 'y':
	specify_style (OUTPUT_SDIFF);
	break;

      case 'W':
	{
	  char *numend;
	  intmax_t numval = strtoimax (optarg, &numend, 10);
	  if (numval <= 0 || *numend)
	    try_help ("invalid width %s", quote (optarg));
	  if (width != numval)
	    {
	      if (width)
		fatal ("conflicting width options");
	      width = numval;
	    }
	}
	break;

      case BINARY_OPTION:
#if O_BINARY
	binary = true;
	if (! isatty (STDOUT_FILENO))
	  set_binary_mode (STDOUT_FILENO, O_BINARY);
#endif
	break;

      case FROM_FILE_OPTION:
	specify_value (&from_file, optarg, "--from-file");
	break;

      case HELP_OPTION:
	usage ();
	check_stdout ();
	return EXIT_SUCCESS;

      case HORIZON_LINES_OPTION:
	{
	  char *numend;
	  intmax_t numval = strtoimax (optarg, &numend, 10);
	  if (*numend || numval < 0)
	    try_help ("invalid horizon length %s", quote (optarg));
	  horizon_lines = MAX (horizon_lines, MIN (numval, LIN_MAX));
	}
	break;

      case IGNORE_FILE_NAME_CASE_OPTION:
	ignore_file_name_case = true;
	break;

      case INHIBIT_HUNK_MERGE_OPTION:
	/* This option is obsolete, but accept it for backward
	   compatibility.  */
	break;

      case LEFT_COLUMN_OPTION:
	left_column = true;
	break;

      case LINE_FORMAT_OPTION:
	specify_style (OUTPUT_IFDEF);
	for (int i = 0; i < sizeof line_format / sizeof line_format[0]; i++)
	  specify_value (&line_format[i], optarg, "--line-format");
	break;

      case NO_DEREFERENCE_OPTION:
	no_dereference_symlinks = true;
	break;

      case NO_IGNORE_FILE_NAME_CASE_OPTION:
	ignore_file_name_case = false;
	break;

      case NORMAL_OPTION:
	specify_style (OUTPUT_NORMAL);
	break;

      case SDIFF_MERGE_ASSIST_OPTION:
	specify_style (OUTPUT_SDIFF);
	sdiff_merge_assist = true;
	break;

      case STRIP_TRAILING_CR_OPTION:
	strip_trailing_cr = true;
	break;

      case SUPPRESS_BLANK_EMPTY_OPTION:
	suppress_blank_empty = true;
	break;

      case SUPPRESS_COMMON_LINES_OPTION:
	suppress_common_lines = true;
	break;

      case TABSIZE_OPTION:
	{
	  char *numend;
	  intmax_t numval = strtoimax (optarg, &numend, 10);
	  if (! (0 < numval && numval <= INTMAX_MAX - GUTTER_WIDTH_MINIMUM)
	      || *numend)
	    try_help ("invalid tabsize %s", quote (optarg));
	  if (tabsize != numval)
	    {
	      if (tabsize)
		fatal ("conflicting tabsize options");
	      tabsize = numval;
	    }
	}
	break;

      case TO_FILE_OPTION:
	specify_value (&to_file, optarg, "--to-file");
	break;

      case UNCHANGED_LINE_FORMAT_OPTION:
      case OLD_LINE_FORMAT_OPTION:
      case NEW_LINE_FORMAT_OPTION:
	specify_style (OUTPUT_IFDEF);
	c -= UNCHANGED_LINE_FORMAT_OPTION;
	specify_value (&line_format[c], optarg, line_format_option[c]);
	break;

      case UNCHANGED_GROUP_FORMAT_OPTION:
      case OLD_GROUP_FORMAT_OPTION:
      case NEW_GROUP_FORMAT_OPTION:
      case CHANGED_GROUP_FORMAT_OPTION:
	specify_style (OUTPUT_IFDEF);
	c -= UNCHANGED_GROUP_FORMAT_OPTION;
	specify_value (&group_format[c], optarg, group_format_option[c]);
	break;

      case COLOR_OPTION:
	specify_colors_style (optarg);
	break;

      case COLOR_PALETTE_OPTION:
	set_color_palette (optarg);
	break;

      case NO_DIRECTORY_OPTION:
	no_directory = true;
	break;

      case PRESUME_OUTPUT_TTY_OPTION:
	presume_output_tty = true;
	break;

      default:
	try_help (nullptr, nullptr);
      }

  if (colors_style == AUTO)
    {
      char const *t = getenv ("TERM");
      if (t && STREQ (t, "dumb"))
        colors_style = NEVER;
    }

  if (output_style == OUTPUT_UNSPECIFIED)
    {
      if (show_c_function)
        {
          specify_style (OUTPUT_CONTEXT);
          if (ocontext < 0)
            context = 3;
        }
      else
        specify_style (OUTPUT_NORMAL);
    }

  if (output_style != OUTPUT_CONTEXT || hard_locale (LC_TIME))
    {
#if defined STAT_TIMESPEC || defined STAT_TIMESPEC_NS
      time_format = "%Y-%m-%d %H:%M:%S.%N %z";
#else
      time_format = "%Y-%m-%d %H:%M:%S %z";
#endif
#if !HAVE_TM_GMTOFF
      localtz = tzalloc (getenv ("TZ"));
#endif
    }
  else
    {
      /* See POSIX 1003.1-2017 for this format.  */
      time_format = "%a %b %e %T %Y";
    }

  if (0 <= ocontext
      && (output_style == OUTPUT_CONTEXT
          || output_style == OUTPUT_UNIFIED)
      && (context < ocontext
          || (ocontext < context && ! explicit_context)))
    context = ocontext;

  if (! tabsize)
    tabsize = 8;
  if (! width)
    width = 130;

  {
    /* Maximize first the half line width, and then the gutter width,
       according to the following constraints:

        1.  Two half lines plus a gutter must fit in a line.
        2.  If the half line width is nonzero:
            a.  The gutter width is at least GUTTER_WIDTH_MINIMUM.
            b.  If tabs are not expanded to spaces,
                a half line plus a gutter is an integral number of tabs,
                so that tabs in the right column line up.  */

    intmax_t t = expand_tabs ? 1 : tabsize;
    intmax_t w = width;
    intmax_t t_plus_g = t + GUTTER_WIDTH_MINIMUM;
    intmax_t unaligned_off = (w >> 1) + (t_plus_g >> 1) + (w & t_plus_g & 1);
    intmax_t off = unaligned_off - unaligned_off % t;
    sdiff_half_width = MAX (0, MIN (off - GUTTER_WIDTH_MINIMUM, w - off));
    sdiff_column2_offset = sdiff_half_width ? off : w;
  }

  /* Make the horizon at least as large as the context, so that
     shift_boundaries has more freedom to shift the first and last hunks.  */
  if (horizon_lines < context)
    horizon_lines = context;

  summarize_regexp_list (&function_regexp_list);
  summarize_regexp_list (&ignore_regexp_list);

  if (output_style == OUTPUT_IFDEF)
    {
      for (int i = 0; i < sizeof line_format / sizeof line_format[0]; i++)
        if (!line_format[i])
          line_format[i] = "%l\n";
      if (!group_format[OLD])
        group_format[OLD]
          = group_format[CHANGED] ? group_format[CHANGED] : "%<";
      if (!group_format[NEW])
        group_format[NEW]
          = group_format[CHANGED] ? group_format[CHANGED] : "%>";
      if (!group_format[UNCHANGED])
        group_format[UNCHANGED] = "%=";
      if (!group_format[CHANGED])
	{
	  char *p = xmalloc (strlen (group_format[OLD])
			     + strlen (group_format[NEW]) + 1);
	  group_format[CHANGED] = p;
	  strcpy (stpcpy (p, group_format[OLD]), group_format[NEW]);
	}
    }

  no_diff_means_no_output =
    (output_style == OUTPUT_IFDEF ?
      (!*group_format[UNCHANGED]
       || (STREQ (group_format[UNCHANGED], "%=")
           && !*line_format[UNCHANGED]))
     : (output_style != OUTPUT_SDIFF) | suppress_common_lines);

  files_can_be_treated_as_binary =
    (brief & binary
     & ~ (ignore_blank_lines | ignore_case | strip_trailing_cr
          | (ignore_regexp_list.regexps || ignore_white_space)));

  switch_string = option_list (argv + 1, optind - 1);

  int exit_status = EXIT_SUCCESS;

  noparent.file[0].desc = AT_FDCWD;
  noparent.file[1].desc = AT_FDCWD;
  static enum detype const de_unknowns[] = {DE_UNKNOWN, DE_UNKNOWN};

  if (from_file)
    {
      if (to_file)
        fatal ("--from-file and --to-file both specified");
      else
        for (; optind < argc; optind++)
          {
	    int status = compare_files (&noparent, de_unknowns,
					from_file, argv[optind]);
            if (exit_status < status)
              exit_status = status;
          }
    }
  else
    {
      if (to_file)
        for (; optind < argc; optind++)
          {
	    int status = compare_files (&noparent, de_unknowns,
					argv[optind], to_file);
            if (exit_status < status)
              exit_status = status;
          }
      else
        {
          if (argc - optind != 2)
            {
              if (argc - optind < 2)
		try_help ("missing operand after %s", quote (argv[argc - 1]));
              else
		try_help ("extra operand %s", quote (argv[optind + 2]));
            }

	  exit_status = compare_files (&noparent, de_unknowns,
				       argv[optind], argv[optind + 1]);
        }
    }

  /* Print any messages that were saved up for last.  */
  print_message_queue ();

  check_stdout ();
  cleanup_signal_handlers ();
  return exit_status;
}

/* Append to REGLIST the regexp PATTERN.  */

static void
add_regexp (struct regexp_list *reglist, char const *pattern)
{
  idx_t patlen = strlen (pattern);
  char const *m = re_compile_pattern (pattern, patlen, reglist->buf);

  if (m != 0)
    error (EXIT_TROUBLE, 0, "%s: %s", squote (0, pattern), m);
  else
    {
      char *regexps = reglist->regexps;
      idx_t len = reglist->len;
      bool multiple_regexps = reglist->multiple_regexps = regexps != 0;
      idx_t newlen = reglist->len = len + 2 * multiple_regexps + patlen;
      idx_t size = reglist->size;

      if (size <= newlen)
	regexps = reglist->regexps = xpalloc (regexps, &reglist->size,
					      newlen - size + 1, -1, 1);
      if (multiple_regexps)
        {
          regexps[len++] = '\\';
          regexps[len++] = '|';
        }
      memcpy (regexps + len, pattern, patlen + 1);
    }
}

/* Ensure that REGLIST represents the disjunction of its regexps.
   This is done here, rather than earlier, to avoid O(N^2) behavior.  */

static void
summarize_regexp_list (struct regexp_list *reglist)
{
  if (reglist->regexps)
    {
      /* At least one regexp was specified.  Allocate a fastmap for it.  */
      reglist->buf->fastmap = xmalloc (1 << CHAR_BIT);
      if (reglist->multiple_regexps)
        {
          /* Compile the disjunction of the regexps.
             (If just one regexp was specified, it is already compiled.)  */
          char const *m = re_compile_pattern (reglist->regexps, reglist->len,
                                              reglist->buf);
          if (m)
	    error (EXIT_TROUBLE, 0, "%s: %s",
		   squote (0, reglist->regexps), m);
        }
    }
}

/* Get the value of errno after a system call fails,
   and help the compiler by telling it that errno is positive.  */
static int
get_errno (void)
{
  int err = errno;
  dassert (0 < err);
  return err;
}

static void
check_stdout (void)
{
  if (ferror (stdout))
    fatal ("write failed");
  else if (fclose (stdout) != 0)
    pfatal_with_name (_("standard output"));
}

static char const *const option_help_msgid[] = {
  N_("    --normal                  output a normal diff (the default)"),
  N_("-q, --brief                   report only when files differ"),
  N_("-s, --report-identical-files  report when two files are the same"),
  N_("-c, -C NUM, --context[=NUM]   output NUM (default 3) lines of copied context"),
  N_("-u, -U NUM, --unified[=NUM]   output NUM (default 3) lines of unified context"),
  N_("-e, --ed                      output an ed script"),
  N_("-n, --rcs                     output an RCS format diff"),
  N_("-y, --side-by-side            output in two columns"),
  N_("-W, --width=NUM               output at most NUM (default 130) print columns"),
  N_("    --left-column             output only the left column of common lines"),
  N_("    --suppress-common-lines   do not output common lines"),
  "",
  N_("-p, --show-c-function         show which C function each change is in"),
  N_("-F, --show-function-line=RE   show the most recent line matching RE"),
  N_("    --label LABEL             use LABEL instead of file name and timestamp\n"
     "                                (can be repeated)"),
  "",
  N_("-t, --expand-tabs             expand tabs to spaces in output"),
  N_("-T, --initial-tab             make tabs line up by prepending a tab"),
  N_("    --tabsize=NUM             tab stops every NUM (default 8) print columns"),
  N_("    --suppress-blank-empty    suppress space or tab before empty output lines"),
  N_("-l, --paginate                pass output through 'pr' to paginate it"),
  "",
  N_("-r, --recursive                 recursively compare any subdirectories found"),
  N_("    --no-dereference            don't follow symbolic links"),
  N_("-N, --new-file                  treat absent files as empty"),
  N_("    --unidirectional-new-file   treat absent first files as empty"),
  N_("    --ignore-file-name-case     ignore case when comparing file names"),
  N_("    --no-ignore-file-name-case  consider case when comparing file names"),
  N_("-x, --exclude=PAT               exclude files that match PAT"),
  N_("-X, --exclude-from=FILE         exclude files that match any pattern in FILE"),
  N_("-S, --starting-file=FILE        start with FILE when comparing directories"),
  N_("    --from-file=FILE1           compare FILE1 to all operands;\n"
     "                                  FILE1 can be a directory"),
  N_("    --to-file=FILE2             compare all operands to FILE2;\n"
     "                                  FILE2 can be a directory"),
  "",
  N_("-i, --ignore-case               ignore case differences in file contents"),
  N_("-E, --ignore-tab-expansion      ignore changes due to tab expansion"),
  N_("-Z, --ignore-trailing-space     ignore white space at line end"),
  N_("-b, --ignore-space-change       ignore changes in the amount of white space"),
  N_("-w, --ignore-all-space          ignore all white space"),
  N_("-B, --ignore-blank-lines        ignore changes where lines are all blank"),
  N_("-I, --ignore-matching-lines=RE  ignore changes where all lines match RE"),
  "",
  N_("-a, --text                      treat all files as text"),
  N_("    --strip-trailing-cr         strip trailing carriage return on input"),
#if O_BINARY
  N_("    --binary                    read and write data in binary mode"),
#endif
  "",
  N_("-D, --ifdef=NAME                output merged file with '#ifdef NAME' diffs"),
  N_("    --GTYPE-group-format=GFMT   format GTYPE input groups with GFMT"),
  N_("    --line-format=LFMT          format all input lines with LFMT"),
  N_("    --LTYPE-line-format=LFMT    format LTYPE input lines with LFMT"),
  N_("  These format options provide fine-grained control over the output\n"
     "    of diff, generalizing -D/--ifdef."),
  N_("  LTYPE is 'old', 'new', or 'unchanged'.  GTYPE is LTYPE or 'changed'."),
  N_("  GFMT (only) may contain:\n\
    %<  lines from FILE1\n\
    %>  lines from FILE2\n\
    %=  lines common to FILE1 and FILE2\n\
    %[-][WIDTH][.[PREC]]{doxX}LETTER  printf-style spec for LETTER\n\
      LETTERs are as follows for new group, lower case for old group:\n\
        F  first line number\n\
        L  last line number\n\
        N  number of lines = L-F+1\n\
        E  F-1\n\
        M  L+1\n\
    %(A=B?T:E)  if A equals B then T else E"),
  N_("  LFMT (only) may contain:\n\
    %L  contents of line\n\
    %l  contents of line, excluding any trailing newline\n\
    %[-][WIDTH][.[PREC]]{doxX}n  printf-style spec for input line number"),
  N_("  Both GFMT and LFMT may contain:\n\
    %%  %\n\
    %c'C'  the single character C\n\
    %c'\\OOO'  the character with octal code OOO\n\
    C    the character C (other characters represent themselves)"),
  "",
  N_("-d, --minimal            try hard to find a smaller set of changes"),
  N_("    --horizon-lines=NUM  keep NUM lines of the common prefix and suffix"),
  N_("    --speed-large-files  assume large files and many scattered small changes"),
  N_("    --color[=WHEN]       color output; WHEN is 'never', 'always', or 'auto';\n"
     "                           plain --color means --color='auto'"),
  N_("    --palette=PALETTE    the colors to use when --color is active; PALETTE is\n"
     "                           a colon-separated list of terminfo capabilities"),
  "",
  N_("    --help               display this help and exit"),
  N_("-v, --version            output version information and exit"),
  "",
  N_("FILES are 'FILE1 FILE2' or 'DIR1 DIR2' or 'DIR FILE' or 'FILE DIR'."),
  N_("If --from-file or --to-file is given, there are no restrictions on FILE(s)."),
  N_("If a FILE is '-', read standard input."),
  N_("Exit status is 0 if inputs are the same, 1 if different, 2 if trouble."),
  nullptr
};

static void
usage (void)
{
  printf (_("Usage: %s [OPTION]... FILES\n"), squote (0, program_name));
  printf ("%s\n\n", _("Compare FILES line by line."));

  fputs (_("\
Mandatory arguments to long options are mandatory for short options too.\n\
"), stdout);

  for (char const *const *p = option_help_msgid;  *p;  p++)
    {
      if (!**p)
        putchar ('\n');
      else
        {
          char const *msg = _(*p);
	  for (char const *nl; (nl = strchr (msg, '\n')); msg = nl + 1)
            {
	      fputs ("  ", stdout);
	      fwrite (msg, 1, nl + 1 - msg, stdout);
            }

	  if (*msg == ' ' || *msg == '-')
	    fputs ("  ", stdout);
	  puts (msg);
        }
    }
  emit_bug_reporting_address ();
}

/* Set VAR to VALUE, reporting an OPTION error if this is a
   conflict.  */
static void
specify_value (char const **var, char const *value, char const *option)
{
  if (*var && ! STREQ (*var, value))
    {
      error (0, 0, _("conflicting %s option value %s"), option, quote (value));
      try_help (nullptr, nullptr);
    }
  *var = value;
}

/* Set the output style to STYLE, diagnosing conflicts.  */
static void
specify_style (enum output_style style)
{
  if (output_style != style)
    {
      if (output_style != OUTPUT_UNSPECIFIED)
        try_help ("conflicting output style options", nullptr);
      output_style = style;
    }
}

/* Set the color mode.  */
static void
specify_colors_style (char const *value)
{
  if (value == nullptr || STREQ (value, "auto"))
    colors_style = AUTO;
  else if (STREQ (value, "always"))
    colors_style = ALWAYS;
  else if (STREQ (value, "never"))
    colors_style = NEVER;
  else
    try_help ("invalid color %s", quote (value));
}


/* True if PCMP's file F is a directory.  */
static bool
dir_p (struct comparison const *pcmp, int f)
{
  return S_ISDIR (pcmp->file[f].stat.st_mode) != 0;
}

/* If openat with O_NOFOLLOW fails because the file is a symlink,
   this platform sets errno to NOFOLLOW_SYMLINK_ERRNO.
   Although POSIX says errno must be ELOOP in that situation,
   FreeBSD and NetBSD behave more usefully.  */
enum { NOFOLLOW_SYMLINK_ERRNO =
#ifdef __FreeBSD__
	 EMLINK
#elif defined __NetBSD__
	 EFTYPE
#else
	 ELOOP
#endif
};

/* Compare two files with parent comparison PARENT.
   The two files are described by CMP, which has been prepped to contain
   the files' stat results, file types, and possibly descriptors.
   If the files need to be opened, use OPEN_FLAGS.  */
static int
compare_prepped_files (struct comparison const *parent,
		       struct comparison *cmp, int open_flags)
{
  /* If neither file "exists", there's nothing to compare.  */
  if (cmp->file[0].desc == NONEXISTENT && cmp->file[1].desc == NONEXISTENT)
    return EXIT_SUCCESS;

  bool same_files = (cmp->file[0].desc != NONEXISTENT
		     && cmp->file[1].desc != NONEXISTENT
		     && cmp->file[0].filetype == cmp->file[1].filetype
		     && same_file (&cmp->file[0].stat, &cmp->file[1].stat));

  /* If the two named files are actually the same physical file.
     we know they are identical without actually reading them.  */
  if (same_files & no_diff_means_no_output)
    return EXIT_SUCCESS;

  bool toplevel = parent == &noparent;

  /* Compare the two hierarchies if both files are directories, or if
     diff is recursive and one file is a directory and the other
     pretends to be a directory full of empty files.  But don't
     compare dir contents one level down unless -r was specified.  */
  if (dir_p (cmp, 0) & dir_p (cmp, 1)
      || (recursive
	  && ((new_file & dir_p (cmp, 1)
	       && cmp->file[0].desc == NONEXISTENT)
	      || (((new_file | unidirectional_new_file) & dir_p (cmp, 0))
		  && cmp->file[1].desc == NONEXISTENT))))
    {
      if (output_style == OUTPUT_IFDEF)
	fatal ("-D option not supported with directories");

      if (recursive | toplevel)
	return diff_dirs (cmp);
      else
	{
	  /* See POSIX 1003.1-2017 for this format.  */
	  message ("Common subdirectories: %s and %s\n",
		   squote (0, cmp->file[0].name),
		   squote (1, cmp->file[1].name));
	  return EXIT_SUCCESS;
	}
    }

  /* Fail if only one file exists.  */
  if ((cmp->file[0].desc == NONEXISTENT
       && ! (new_file | unidirectional_new_file))
      || (cmp->file[1].desc == NONEXISTENT && !new_file))
    {
      bool existing = cmp->file[0].desc == NONEXISTENT;
      char const *dname = parent->file[existing].name;
      char const *bname = last_component (cmp->file[existing].name);

      /* See POSIX 1003.1-2017 for this format.  */
      message ("Only in %s: %s\n", squote (0, dname), squote (1, bname));
      return EXIT_FAILURE;
    }

  /* If the two files have different types, or have the same type but
     the type is unusual, then simply report their type.
     However, at the top level do this only if one file is a symlink
     and the other is not.  */
  mode_t mode0 = cmp->file[0].stat.st_mode;
  mode_t mode1 = cmp->file[1].stat.st_mode;
  if (toplevel ? !S_ISLNK (mode0) != !S_ISLNK (mode1)
      : S_ISREG (mode0) ? !S_ISREG (mode1)
      : S_ISLNK (mode0) ? !S_ISLNK (mode1)
      : S_ISCHR (mode0) ? !S_ISCHR (mode1)
      : S_ISBLK (mode0) ? !S_ISBLK (mode1)
      : true)
    {
      /* POSIX 1003.1-2017 says any message will do, so long as it
	 contains the file names.  */
      message ("File %s is a %s while file %s is a %s\n",
	       file_label[0] ? file_label[0] : squote (0, cmp->file[0].name),
	       gettext (cmp->file[0].filetype),
	       file_label[1] ? file_label[1] : squote (1, cmp->file[1].name),
	       gettext (cmp->file[1].filetype));

      return EXIT_FAILURE;
    }

  /* If both files are symlinks, compare symlink contents.  */
  if (S_ISLNK (mode0))
    {
      /* We get here only if we are not dereferencing symlinks.  */
      dassert (no_dereference_symlinks);

      int status = EXIT_SUCCESS;
      char *link_value[2]; link_value[1] = nullptr;
      char linkbuf[2][128];

      for (bool f = false; ; f = true)
	{
	  int linkfd = cmp->file[f].desc;
	  int dirfd = parent->file[f].desc;
	  char const *name = cmp->file[f].name;
	  int dirarg = linkfd < 0 ? dirfd : linkfd;
	  char const *namearg = (linkfd < 0
				 ? (dirfd < 0 ? name : last_component (name))
				 : "");
	  link_value[f] = careadlinkat (dirarg, namearg,
					linkbuf[f], sizeof linkbuf[f],
					nullptr, readlinkat);
	  if (!link_value[f])
	    {
	      perror_with_name (cmp->file[f].name);
	      status = EXIT_TROUBLE;
	      break;
	    }
	  if (f)
	    {
	      status = (STREQ (link_value[0], link_value[f])
			? EXIT_SUCCESS : EXIT_FAILURE);
	      break;
	    }
	}

      if (status == EXIT_FAILURE)
	message ("Symbolic links %s -> %s and %s -> %s differ\n",
		 quote_n (0, cmp->file[0].name), quote_n (1, link_value[0]),
		 quote_n (2, cmp->file[1].name), quote_n (3, link_value[1]));

      for (int f = 0; f < 2; f++)
	if (link_value[f] != linkbuf[f])
	  free (link_value[f]);

      return status;
    }

  /* When not at the top level, compare device numbers of special files,
     and report file types of all other non-regular files.
     POSIX 1003.1-2017 says any message will do,
     so long as it contains the file names.  */
  if (!toplevel && !S_ISREG (mode0))
    {
      if (cmp->file[0].stat.st_rdev == cmp->file[1].stat.st_rdev)
	return EXIT_SUCCESS;

      intmax_t num[] = {
	major (cmp->file[0].stat.st_rdev),
	minor (cmp->file[0].stat.st_rdev),
	major (cmp->file[1].stat.st_rdev),
	minor (cmp->file[1].stat.st_rdev)
      };
      enum { n_num = sizeof num / sizeof *num };
      char numbuf[n_num][INT_BUFSIZE_BOUND (intmax_t)];
      for (int i = 0; i < n_num; i++)
	sprintf (numbuf[i], "%"PRIdMAX, num[i]);

      message ((S_ISCHR (mode0)
		? ("Character special files %s (%s, %s)"
		   " and %s (%s, %s) differ\n")
		: ("Block special files %s (%s, %s)"
		   " and %s (%s, %s) differ\n")),
	       quote_n (0, cmp->file[0].name), numbuf[0], numbuf[1],
	       quote_n (2, cmp->file[1].name), numbuf[2], numbuf[3]);

      return EXIT_FAILURE;
    }

  if (files_can_be_treated_as_binary
      && S_ISREG (mode0)
      && S_ISREG (mode1)
      && cmp->file[0].stat.st_size != cmp->file[1].stat.st_size
      && 0 <= cmp->file[0].stat.st_size
      && 0 <= cmp->file[1].stat.st_size)
    {
      message ("Files %s and %s differ\n",
	       file_label[0] ? file_label[0] : squote (0, cmp->file[0].name),
	       file_label[1] ? file_label[1] : squote (1, cmp->file[1].name));
      return EXIT_FAILURE;
    }

  /* Both files exist and neither is a directory or a symbolic link.
     Open the files and record their descriptors,
     if they are not already open.  */

  int status = EXIT_SUCCESS;

  for (int f = 0; f < 2; f++)
    if (cmp->file[f].desc == UNOPENED)
      {
	if (f && same_files)
	  cmp->file[f].desc = cmp->file[0].desc;
	else
	  {
	    int dirfd = parent->file[f].desc;
	    char const *name = cmp->file[f].name;
	    char const *nm = dirfd < 0 ? name : last_component (name);
	    cmp->file[f].desc = openat (dirfd, nm, open_flags);
	    if (cmp->file[f].desc < 0)
	      {
		perror_with_name (name);
		status = EXIT_TROUBLE;
	      }
	  }
      }
    else if (cmp->file[f].desc == OPEN_FAILED)
      {
	error (0, cmp->file[f].openerr, "%s", squote (0, cmp->file[f].name));
	status = EXIT_TROUBLE;
      }

  /* Compare the files' contents, if no error was found.  */

  if (status != EXIT_SUCCESS)
    return status;
  return diff_2_files (cmp);
}


/* Compare two files (or dirs) with parent comparison PARENT,
   directory entries of type DETYPE, and names NAME0 and NAME1.
   (If PARENT == &NOPARENT, then the first name is just NAME0, etc.)
   This is self-contained; it opens the files and closes them.

   Names are relative to the original working directory.  If a file
   appears in only one dir, the other name is a null pointer.

   Value is EXIT_SUCCESS if files are the same, EXIT_FAILURE if
   different, EXIT_TROUBLE if there is a problem opening them.  */

int
compare_files (struct comparison const *parent, enum detype const detype[2],
               char const *name0,
               char const *name1)
{
  /* If this is directory comparison, perhaps we have a file
     that exists only in one of the directories.
     If so, just print a message to that effect.  */

  if (! ((name0 && name1)
         || (unidirectional_new_file && name1)
         || new_file))
    {
      char const *name = name0 ? name0 : name1;
      char const *dir = parent->file[!name0].name;

      /* See POSIX 1003.1-2017 for this format.  */
      message ("Only in %s: %s\n", squote (0, dir), squote (1, name));

      /* Return EXIT_FAILURE so that diff_dirs will return
         EXIT_FAILURE ("some files differ").  */
      return EXIT_FAILURE;
    }

  struct comparison cmp = { .file[0].desc = name0 ? UNOPENED : NONEXISTENT,
			    .file[1].desc = name1 ? UNOPENED : NONEXISTENT,
			    .file[0].stat.st_size = name0 ? -1 : 0,
			    .file[1].stat.st_size = name1 ? -1 : 0,
			    .parent = parent };

  /* Now record the full name of each file, including nonexistent ones.  */

  if (!name0)
    name0 = name1;
  if (!name1)
    name1 = name0;

  char *free0;
  char *free1;
  bool toplevel = parent == &noparent;

  if (toplevel)
    {
      free0 = nullptr;
      free1 = nullptr;
      cmp.file[0].name = name0;
      cmp.file[1].name = name1;
    }
  else
    {
      cmp.file[0].name = free0
        = file_name_concat (parent->file[0].name, name0, nullptr);
      cmp.file[1].name = free1
        = file_name_concat (parent->file[1].name, name1, nullptr);
    }

  int oflags = ((binary ? O_BINARY : 0) | O_CLOEXEC
		| (no_dereference_symlinks ? O_NOFOLLOW : 0));

  /* Stat the files if needed, possibly opening them first if that is
     safe or will be done anyway.  */

  for (int f = 0; f < 2; f++)
    {
      int fd = cmp.file[f].desc;
      if (fd != UNOPENED)
	continue;

      if (f && file_name_cmp (cmp.file[f].name, cmp.file[0].name) == 0)
	{
	  cmp.file[f].desc = cmp.file[0].desc;
	  cmp.file[f].filetype = cmp.file[0].filetype;
	  cmp.file[f].stat = cmp.file[0].stat;
	  continue;
	}

      int parentdesc = parent->file[f].desc;
      char const *name = cmp.file[f].name;
      char const *nm = parentdesc < 0 ? name : last_component (name);
      int err = 0;

      if (STREQ (cmp.file[f].name, "-"))
	{
	  fd = STDIN_FILENO;
	  if (binary && ! isatty (fd))
	    set_binary_mode (fd, O_BINARY);
	}
      else if (toplevel || detype[f] == DE_REG || detype[f] == DE_DIR
	       || (O_PATH_DEFINED && detype[f] == DE_LNK
		   && no_dereference_symlinks))
	{
	  /* Either we would open the file anyway because it's the top level,
	     or the file is known to be a type that is
	     safe to open and is likely to be opened anyway.
	     Open the file now, as openat+fstat avoids an fstatat+openat race
	     and might be a bit faster.  */
	  int accmode = ((O_PATH_DEFINED && !toplevel && detype[f] == DE_LNK
			  && no_dereference_symlinks)
			 ? O_PATHSEARCH : O_RDONLY);
	  fd = openat (parentdesc, nm, accmode | oflags);
	  if (fd < 0)
	    {
	      err = get_errno ();

	      /* 'diff DIR FILE' needs read access to DIR if
		 --ignore-file-name-case; otherwise O_PATHSEARCH suffices.
		 But do not check for this if ---no-directory.  */
	      if (err == EACCES && toplevel
		  && !ignore_file_name_case && !no_directory
		  && (f == 0 || !dir_p (&cmp, 0)))
		{
		  fd = openat (parentdesc, nm,
			       O_PATHSEARCH | O_DIRECTORY | oflags);
		  if (0 <= fd)
		    err = 0;
		}

	      /* If it is a symlink, fstatat later.  If it might be a
		 symlink, play it safe and fstatat later.  */
	      if (err == NOFOLLOW_SYMLINK_ERRNO
		  && (NOFOLLOW_SYMLINK_ERRNO != ELOOP
		      || (no_dereference_symlinks
			  && (detype[f] == DE_UNKNOWN
			      || (detype[f] == DE_LNK
				  && accmode == O_RDONLY)))))
		{
		  fd = UNOPENED;
		  err = 0;
		}

	      cmp.file[f].openerr = err;
	    }
	}

      /* Get the file's status unless an earlier error makes it unnecessary.  */
      if (! (cmp.file[1 - f].err
	     /* If openat failed as follows, fstatat would fail too.  */
	     || err == ENOENT || err == ENOTDIR || err == ELOOP
	     || err == EOVERFLOW || err == ENAMETOOLONG))
	{
	  if ((fd < 0
	       ? fstatat (parentdesc, nm, &cmp.file[f].stat,
			  no_dereference_symlinks ? AT_SYMLINK_NOFOLLOW : 0)
	       : fstat (fd, &cmp.file[f].stat))
	      < 0)
	    err = get_errno ();
	  else
	    {
	      err = 0;
	      off_t size = stat_size (&cmp.file[f].stat);

	      if (0 <= size && fd == STDIN_FILENO)
		{
		  off_t pos = lseek (fd, 0, SEEK_CUR);
		  if (0 <= pos)
		    size = MAX (0, size - pos);
		}

	      cmp.file[f].stat.st_size = size;
	      cmp.file[f].filetype = c_file_type (&cmp.file[f].stat);
	    }
	}

      cmp.file[f].desc = fd;
      cmp.file[f].err = err;
    }

  if (toplevel)
    {
      if (!no_directory && toplevel
	  && !cmp.file[0].err && !cmp.file[1].err
	  && dir_p (&cmp, 0) != dir_p (&cmp, 1))
	{
	  /* If one is a directory, use the file in that dir with the
	     other file's basename.  */

	  int fnm_arg = dir_p (&cmp, 0);
	  int dir_arg = 1 - fnm_arg;
	  if (cmp.file[fnm_arg].desc == STDIN_FILENO)
	    fatal ("cannot compare '-' to a directory");
	  char const *fnm = cmp.file[fnm_arg].name;
	  enum detype dir_detype;
	  char const *filename = cmp.file[dir_arg].name = free0
	    = find_dir_file_pathname (&cmp.file[dir_arg], last_component (fnm),
				      &dir_detype);
	  int dirfd = cmp.file[dir_arg].desc;
	  if (dirfd < 0)
	    dirfd = AT_FDCWD;
	  char const *atname = dirfd < 0 ? filename : last_component (filename);
	  cmp.file[dir_arg].desc = UNOPENED;
	  noparent.file[dir_arg].desc = dirfd;
	  cmp.file[dir_arg].desc
	    = (dir_detype == DE_LNK && no_dereference_symlinks
	       ? (errno = ELOOP, -1)
	       : openat (dirfd, atname, O_RDONLY | oflags));
	  if (O_PATH_DEFINED && cmp.file[dir_arg].desc < 0
	      && (dir_detype == DE_LNK || dir_detype == DE_UNKNOWN)
	      && no_dereference_symlinks && errno == NOFOLLOW_SYMLINK_ERRNO)
	    cmp.file[dir_arg].desc = openat (dirfd, atname,
					     O_PATHSEARCH | oflags);
	  if (cmp.file[dir_arg].desc < 0
	      ? (O_PATH_DEFINED || !no_dereference_symlinks
		 || errno != NOFOLLOW_SYMLINK_ERRNO
		 || (fstatat (dirfd, atname, &cmp.file[dir_arg].stat,
			      AT_SYMLINK_NOFOLLOW)
		     < 0))
	      : fstat (cmp.file[dir_arg].desc, &cmp.file[dir_arg].stat) < 0)
	    cmp.file[dir_arg].err = get_errno ();
	  else
	    {
	      cmp.file[dir_arg].stat.st_size
		= stat_size (&cmp.file[dir_arg].stat);
	      cmp.file[dir_arg].filetype
		= c_file_type (&cmp.file[dir_arg].stat);
	    }
	}

      /* Mark files as nonexistent as needed for -N and -P,
	 if they do not exist but their counterparts do exist.  */
      for (int f = 0; f < 2; f++)
	if ((new_file || (f == 0 && unidirectional_new_file))
	    && (cmp.file[f].err == ENOENT || cmp.file[f].err == ENOTDIR)
	    && ! (cmp.file[1 - f].err == ENOENT
		  || cmp.file[1 - f].err == ENOTDIR))
	  {
	    cmp.file[f].desc = NONEXISTENT;
	    cmp.file[f].err = 0;
	  }
    }

  for (int f = 0; f < 2; f++)
    if (cmp.file[f].desc == NONEXISTENT)
      {
	cmp.file[f].filetype = cmp.file[1 - f].filetype;
	cmp.file[f].stat.st_mode = cmp.file[1 - f].stat.st_mode;
      }

  int status = EXIT_SUCCESS;

  for (int f = 0; f < 2; f++)
    if (cmp.file[f].err)
      {
	error (0, cmp.file[f].err, "%s", squote (0, cmp.file[f].name));
	status = EXIT_TROUBLE;
      }

  if (status == EXIT_SUCCESS)
    status = compare_prepped_files (parent, &cmp, O_RDONLY | oflags);

  /* Close any input files.  */
  for (int f = 0; f < 2; f++)
    if ((f == 0 || cmp.file[f].desc != cmp.file[0].desc)
	&& (cmp.file[f].dirstream ? closedir (cmp.file[f].dirstream) < 0
	    : 0 <= cmp.file[f].desc && close (cmp.file[f].desc) < 0))
      {
	perror_with_name (cmp.file[f].name);
	status = EXIT_TROUBLE;
      }

  /* Now the comparison has been done, if no error prevented it,
     and STATUS is the value this function will return.  */

  if (status == EXIT_SUCCESS)
    {
      if (report_identical_files && !dir_p (&cmp, 0))
	message
	  ("Files %s and %s are identical\n",
	   file_label[0] ? file_label[0] : squote (0, cmp.file[0].name),
	   file_label[1] ? file_label[1] : squote (1, cmp.file[1].name));
    }
  else
    {
      /* Flush stdout so that the user sees differences immediately.
         This can hurt performance, unfortunately.  */
      if (fflush (stdout) != 0)
        pfatal_with_name (_("standard output"));
    }

  free (free0);
  free (free1);

  return status;
}

/* Define variables declared in diff.h (which see).  */
FILE *outfile;
bool brief;
bool expand_tabs;
bool files_can_be_treated_as_binary;
bool ignore_blank_lines;
bool ignore_case;
bool ignore_file_name_case;
bool initial_tab;
bool left_column;
bool minimal;
bool no_dereference_symlinks;
bool no_diff_means_no_output;
bool paginate;
bool presume_output_tty;
bool sdiff_merge_assist;
bool speed_large_files;
bool strip_trailing_cr;
bool suppress_blank_empty;
bool suppress_common_lines;
bool text;
char *file_label[2];
char *switch_string;
char const *group_format[CHANGED + 1];
char const *line_format[NEW + 1];
char const *starting_file;
char const *time_format;
enum DIFF_white_space ignore_white_space;
enum colors_style colors_style;
enum output_style output_style;
intmax_t sdiff_column2_offset;
intmax_t sdiff_half_width;
intmax_t tabsize;
lin context;
lin horizon_lines;
struct comparison curr;
struct comparison noparent;
struct exclude *excluded;
struct re_pattern_buffer function_regexp;
struct re_pattern_buffer ignore_regexp;
#ifndef localtz
timezone_t localtz;
#endif
