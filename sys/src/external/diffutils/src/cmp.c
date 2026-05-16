/* GNU cmp - compare two files byte by byte

   Copyright (C) 1990-1996, 1998, 2001-2002, 2004, 2006-2007, 2009-2013,
   2015-2025 Free Software Foundation, Inc.

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
#include "paths.h"

#include <binary-io.h>
#include <c-ctype.h>
#include <c-stack.h>
#include <cmpbuf.h>
#include <diagnose.h>
#include <error.h>
#include <exitfail.h>
#include <file-type.h>
#include <getopt.h>
#include <hard-locale.h>
#include <progname.h>
#include <quote.h>
#include <unlocked-io.h>
#include <version-etc.h>
#include <xalloc.h>
#include <xstdopen.h>
#include <xstrtol.h>

#include <stdio.h>

/* The official name of this program (e.g., no 'g' prefix).  */
static char const PROGRAM_NAME[] = "cmp";

#define AUTHORS \
  proper_name_lite ("Torbjorn Granlund", "Torbj\303\266rn Granlund"), \
  _("David MacKenzie")

static bool
hard_locale_LC_MESSAGES (void)
{
#if defined LC_MESSAGES && ENABLE_NLS
  return hard_locale (LC_MESSAGES);
#else
  return false;
#endif
}

static int cmp (void);
static off_t file_position (int);
static idx_t block_compare (word const *, word const *) ATTRIBUTE_PURE;
static idx_t count_newlines (char *, idx_t);
static void sprintc (char *, unsigned char);

/* Filenames of the compared files.  */
static char const *file[2];

/* File descriptors of the files.  */
static int file_desc[2];

/* Status of the files.  If st_size is -1, stat_buf[i] is valid except
   that the file size is unspecified.  If st_size is -2, the rest of
   stat_buf[i] is unspecified except that st_blksize (if it exists) is
   a reasonable guess.  */
static struct stat stat_buf[2];

/* Read buffers for the files.  */
static word *buffer[2];

/* Optimal block size for the files.  */
static idx_t buf_size;

/* Initial prefix to ignore for each file, or negative if the user
   requested to ignore more than TYPE_MAXIMUM (intmax_t) bytes.  */
static intmax_t ignore_initial[2];

/* Number of bytes to compare.  INTMAX_MAX is effectively infinity,
   since there's no practical way on current computers to compare so
   many bytes.  Even if cmp added SEEK_HOLE and SEEK_DATA optimization,
   regular files can't have more than TYPE_MAXIMUM (off_t) bytes
   and special files are unlikely to support this optimization.  */
static intmax_t bytes = INTMAX_MAX;

/* Output format.  */
static enum comparison_type
  {
    type_first_diff,	/* Print the first difference.  */
    type_all_diffs,	/* Print all differences.  */
    type_no_stdout,	/* Do not output to stdout; only stderr.  */
    type_status		/* Exit status only.  */
  } comparison_type;

/* If nonzero, print values of bytes quoted like cat -t does. */
static bool opt_print_bytes;

/* Values for long options that do not have single-letter equivalents.  */
enum
{
  HELP_OPTION = CHAR_MAX + 1
};

static char const shortopts[] = "bci:ln:sv";
static struct option const longopts[] =
{
  {"print-bytes", 0, 0, 'b'},
  {"print-chars", 0, 0, 'c'}, /* obsolescent as of diffutils 2.7.3 */
  {"ignore-initial", 1, 0, 'i'},
  {"verbose", 0, 0, 'l'},
  {"bytes", 1, 0, 'n'},
  {"silent", 0, 0, 's'},
  {"quiet", 0, 0, 's'},
  {"version", 0, 0, 'v'},
  {"help", 0, 0, HELP_OPTION},
  {0, 0, 0, 0}
};

static char const valid_suffixes[] = "kKMGTPEZY0";

/* Update ignore_initial[F] according to the result of parsing an
   *operand ARGPTR of --ignore-initial, updating *ARGPTR to point
   *after the operand.  If DELIMITER is nonzero, the operand may be
   *followed by DELIMITER; otherwise it must be null-terminated.  */
static void
specify_ignore_initial (int f, char **argptr, char delimiter)
{
  intmax_t val;
  char const *arg = *argptr;
  strtol_error d = xstrtoimax (arg, argptr, 0, &val, valid_suffixes);
  strtol_error e = d & ~LONGINT_OVERFLOW;
  if (! ((e == LONGINT_OK
          || (e == LONGINT_INVALID_SUFFIX_CHAR && **argptr == delimiter))
         && 0 <= val))
    try_help ("invalid --ignore-initial value %s", quote (arg));
  if (0 <= ignore_initial[f] && ignore_initial[f] < val)
    ignore_initial[f] = d == e ? val : -1;
}

/* Specify the output format.  */
static void
specify_comparison_type (enum comparison_type t)
{
  if (comparison_type && comparison_type != t)
    try_help ("options -l and -s are incompatible", nullptr);
  comparison_type = t;
}

static void
check_stdout (void)
{
  if (ferror (stdout))
    error (EXIT_TROUBLE, 0, "%s", _("write failed"));
  else if (fclose (stdout) != 0)
    error (EXIT_TROUBLE, errno, "%s", _("standard output"));
}

static char const *const option_help_msgid[] = {
  N_("-b, --print-bytes          print differing bytes"),
  N_("-i, --ignore-initial=SKIP         skip first SKIP bytes of both inputs"),
  N_("-i, --ignore-initial=SKIP1:SKIP2  skip first SKIP1 bytes of FILE1 and\n"
     "                                      first SKIP2 bytes of FILE2"),
  N_("-l, --verbose              output byte numbers and differing byte values"),
  N_("-n, --bytes=LIMIT          compare at most LIMIT bytes"),
  N_("-s, --quiet, --silent      suppress all normal output"),
  N_("    --help                 display this help and exit"),
  N_("-v, --version              output version information and exit"),
  nullptr
};

static void
usage (void)
{
  printf (_("Usage: %s [OPTION]... FILE1 [FILE2 [SKIP1 [SKIP2]]]\n"),
	  squote (0, program_name));
  puts (_("Compare two files byte by byte."));
  printf ("\n%s\n\n",
_("The optional SKIP1 and SKIP2 specify the number of bytes to skip\n"
  "at the beginning of each file (zero by default)."));

  fputs (_("\
Mandatory arguments to long options are mandatory for short options too.\n\
"), stdout);
  for (char const *const *p = option_help_msgid;  *p;  p++)
    printf ("  %s\n", _(*p));
  printf ("\n%s\n\n%s\n%s\n",
          _("SKIP values may be followed by the following multiplicative suffixes:\n\
kB 1000, K 1024, MB 1,000,000, M 1,048,576,\n\
GB 1,000,000,000, G 1,073,741,824, and so on for T, P, E, Z, Y."),
          _("If a FILE is '-' or missing, read standard input."),
          _("Exit status is 0 if inputs are the same, 1 if different, 2 if trouble."));
  emit_bug_reporting_address ();
}

int
main (int argc, char **argv)
{
  exit_failure = EXIT_TROUBLE;
  initialize_main (&argc, &argv);
  set_program_name (argv[0]);
  setlocale (LC_ALL, "");
  bindtextdomain (PACKAGE, LOCALEDIR);
  bindtextdomain ("gnulib", GNULIB_LOCALEDIR);
  textdomain (PACKAGE);
  c_stack_action (nullptr);
  xstdopen ();

  /* Parse command line options.  */

  for (int c;
       0 <= (c = getopt_long (argc, argv, shortopts, longopts, nullptr)); )
    switch (c)
      {
      case 'b':
      case 'c': /* 'c' is obsolescent as of diffutils 2.7.3 */
        opt_print_bytes = true;
        break;

      case 'i':
        specify_ignore_initial (0, &optarg, ':');
        if (*optarg++ == ':')
          specify_ignore_initial (1, &optarg, 0);
	else if (ignore_initial[1] < ignore_initial[0] || ignore_initial[0] < 0)
          ignore_initial[1] = ignore_initial[0];
        break;

      case 'l':
        specify_comparison_type (type_all_diffs);
        break;

      case 'n':
        {
          intmax_t n;
	  strtol_error e = xstrtoimax (optarg, nullptr, 0, &n, valid_suffixes);
	  if ((e & ~LONGINT_OVERFLOW) != LONGINT_OK || n < 0)
	    try_help ("invalid --bytes value %s", quote (optarg));
	  bytes = MIN (bytes, n);
        }
        break;

      case 's':
        specify_comparison_type (type_status);
        break;

      case 'v':
        version_etc (stdout, PROGRAM_NAME, PACKAGE_NAME, Version,
                     AUTHORS, nullptr);
        check_stdout ();
        return EXIT_SUCCESS;

      case HELP_OPTION:
        usage ();
        check_stdout ();
        return EXIT_SUCCESS;

      default:
        try_help (nullptr, nullptr);
      }

  if (optind == argc)
    try_help ("missing operand after %s", quote (argv[argc - 1]));

  file[0] = argv[optind++];
  file[1] = optind < argc ? argv[optind++] : "-";

  for (int f = 0; f < 2 && optind < argc; f++)
    {
      char *arg = argv[optind++];
      specify_ignore_initial (f, &arg, 0);
    }

  if (optind < argc)
    try_help ("extra operand %s", quote (argv[optind]));

  for (int f = 0; f < 2; f++)
    {
      /* Two files with the same name and offset are identical.
         But wait until we open the file once, for proper diagnostics.  */
      if (f && 0 <= ignore_initial[0] && ignore_initial[0] == ignore_initial[1]
          && file_name_cmp (file[0], file[1]) == 0)
        return EXIT_SUCCESS;

      if (STREQ (file[f], "-"))
        {
          file_desc[f] = STDIN_FILENO;
          if (O_BINARY && ! isatty (STDIN_FILENO))
            set_binary_mode (STDIN_FILENO, O_BINARY);
        }
      else
        {
          file_desc[f] = open (file[f], O_RDONLY | O_BINARY | O_CLOEXEC);

          if (file_desc[f] < 0)
            {
              if (comparison_type != type_status)
		error (0, errno, "%s", squote (0, file[f]));
              exit (EXIT_TROUBLE);
            }
        }

      if (fstat (file_desc[f], stat_buf + f) < 0)
        {
	  stat_buf[f].st_size = -2;
#if HAVE_STRUCT_STAT_ST_BLKSIZE
          stat_buf[f].st_blksize = 8 * 1024;
#endif
        }
      else
	stat_buf[f].st_size = stat_size (&stat_buf[f]);
    }

  /* If the files are the same and have the same file position,
     the contents are identical.  */

  if (-1 <= stat_buf[0].st_size && -1 <= stat_buf[1].st_size
      && same_file (&stat_buf[0], &stat_buf[1])
      && file_position (0) == file_position (1))
    return EXIT_SUCCESS;

  /* If output is redirected to the null device, we can avoid some of
     the work.  */

  if (comparison_type != type_status)
    {
      struct stat outstat, nullstat;

      if (fstat (STDOUT_FILENO, &outstat) == 0
	  && S_ISCHR (outstat.st_mode)
          && stat (NULL_DEVICE, &nullstat) == 0
	  && same_file (&outstat, &nullstat))
        comparison_type = type_no_stdout;
    }

  /* If no output is needed,
     and both input descriptors are associated with plain files,
     and the file sizes are nonzero so they are not Linux /proc files,
     conclude that the files differ if they have different sizes
     and if more bytes will be compared than are in the smaller file.  */

  if (type_no_stdout <= comparison_type
      && 0 <= stat_buf[0].st_size && S_ISREG (stat_buf[0].st_mode)
      && 0 <= stat_buf[1].st_size && S_ISREG (stat_buf[1].st_mode))
    {
      off_t pos0 = file_position (0);
      if (0 <= pos0)
	{
	  off_t pos1 = file_position (1);
	  if (0 <= pos1)
	    {
	      off_t s0 = stat_buf[0].st_size - pos0;
	      off_t s1 = stat_buf[1].st_size - pos1;
	      if (s0 < 0)
		s0 = 0;
	      if (s1 < 0)
		s1 = 0;
	      if (s0 != s1 && MIN (s0, s1) < bytes)
		exit (EXIT_FAILURE);
	    }
	}
    }

  /* Guess a good block size for the files.  */

  idx_t blksize[2];
  for (int f = 0; f < 2; f++)
    if (ST_BLKSIZE (stat_buf[0]) < 0
	|| ckd_add (&blksize[f], ST_BLKSIZE (stat_buf[0]), 0))
      blksize[f] = 0;
  buf_size = buffer_lcm (blksize[0], blksize[1], IDX_MAX - sizeof (word));

  /* Allocate word-aligned buffers, with space for sentinels at the end.  */

  idx_t words_per_buffer = (buf_size + 2 * sizeof (word) - 1) / sizeof (word);
  buffer[0] = xinmalloc (words_per_buffer, 2 * sizeof (word));
  buffer[1] = buffer[0] + words_per_buffer;

  int exit_status = cmp ();

  for (int f = 0; f < 2; f++)
    if (close (file_desc[f]) != 0)
      error (EXIT_TROUBLE, errno, "%s", squote (0, file[f]));
  if (exit_status != EXIT_SUCCESS && comparison_type < type_no_stdout)
    check_stdout ();
  exit (exit_status);
}

/* Compare the two files already open on 'file_desc[0]' and 'file_desc[1]',
   using 'buffer[0]' and 'buffer[1]'.
   Return EXIT_SUCCESS if identical, EXIT_FAILURE if different,
   >1 if error.  */

static int
cmp (void)
{
  word *buffer0 = buffer[0];
  word *buffer1 = buffer[1];
  char *buf0 = (char *) buffer0;
  char *buf1 = (char *) buffer1;

  /* For -l, the print width of the offset, a positive number.
     Otherwise, the negative of the comparison type.
     This portmanteauization pacifies gcc -Wmaybe-uninitialized.  */
  int offset_width;

  if (comparison_type == type_all_diffs)
    {
      intmax_t byte_number_max = bytes;

      for (int f = 0; f < 2; f++)
	if (0 <= stat_buf[f].st_size && S_ISREG (stat_buf[f].st_mode))
	  {
	    off_t pos = file_position (f);
	    if (0 <= pos)
	      byte_number_max = MIN (byte_number_max,
				     MAX (0, stat_buf[f].st_size - pos));
	  }

      for (offset_width = 1; (byte_number_max /= 10) != 0; offset_width++)
        continue;
    }
  else
    offset_width = -comparison_type;

  bool eof[2] = { false, false };

  for (int f = 0; f < 2; f++)
    {
      intmax_t ig = ignore_initial[f];
      if (ig == 0)
	continue;

      if (0 <= file_position (f))
	continue;  /* lseek sufficed.  */

      if (! (0 <= ig && ig < TYPE_MAXIMUM (off_t))
	  && -1 <= stat_buf[f].st_size && S_ISREG (stat_buf[f].st_mode))
        {
	  /* When ignoring at least TYPE_MAXIMUM (off_t) bytes
	     of a regular file, pretend to be at end of file,
	     as lseeking to TYPE_MAXIMUM (off_t) might tickle a kernel bug,
	     and lseeking to file end would race with a growing file.  */
	  eof[f] = true;
	}
      else if (ig < 0)
	{
	  /* Report an error if asked to ignore more than
	     INTMAX_MAX bytes of a non-regular file,
	     as the actual number of bytes to ignore is not known.  */
	  error (EXIT_TROUBLE, EOVERFLOW, "%s", squote (0, file[f]));
	}
      else
	{
	  /* Read and discard the ignored initial prefix.  */
          do
            {
              idx_t bytes_to_read = MIN (ig, buf_size);
              ptrdiff_t r = block_read (file_desc[f], buf0, bytes_to_read);
              if (r != bytes_to_read)
                {
                  if (r < 0)
		    error (EXIT_TROUBLE, errno, "%s", squote (0, file[f]));
                  break;
                }
              ig -= r;
            }
	  while (0 < ig);
        }
    }

  bool at_line_start = true;
  intmax_t line_number = 1;	/* Line number (1...) of difference. */
  intmax_t byte_number = 1;	/* Byte number (1...) of difference. */
  intmax_t remaining = bytes;	/* Remaining bytes to compare, or -1.  */

  while (true)
    {
      idx_t bytes_to_read = MIN (buf_size, remaining);
      remaining -= bytes_to_read;

      ptrdiff_t read0 = (eof[0] ? 0
			 : block_read (file_desc[0], buf0, bytes_to_read));
      if (read0 < 0)
	error (EXIT_TROUBLE, errno, "%s", squote (0, file[0]));
      ptrdiff_t read1 = (eof[1] ? 0
			 : block_read (file_desc[1], buf1, bytes_to_read));
      if (read1 < 0)
	error (EXIT_TROUBLE, errno, "%s", squote (0, file[1]));

      idx_t smaller = MIN (read0, read1);

      idx_t first_diff;  /* Offset (0...) in buffers of 1st diff. */

      /* Optimize the common case where the buffers are the same.  */
      if (memcmp (buf0, buf1, smaller) == 0)
        first_diff = smaller;
      else
        {
          /* Insert sentinels for the block compare.  */
          if (read0 >= read1)
            buf1[read0] = 0x55; /* arbitrary */
          if (read1 >= read0)
            buf0[read1] = 0x79; /* arbitrary and distinct from the above */
          buf0[read0] = ~buf1[read0];
          buf1[read1] = ~buf0[read1];
          /* Ensure all bytes of a final word-read are initialized.  */
          memset (buf0 + read0 + 1, 0,
                  sizeof (word) - read0 % sizeof (word) - 1);
          memset (buf1 + read1 + 1, 0,
                  sizeof (word) - read1 % sizeof (word) - 1);

          first_diff = block_compare (buffer0, buffer1);
        }

      byte_number += first_diff;
      if (offset_width == -type_first_diff && first_diff != 0)
        {
          line_number += count_newlines (buf0, first_diff);
          at_line_start = buf0[first_diff - 1] == '\n';
        }

      int differing = 0;

      if (first_diff < smaller)
        {
	  switch (offset_width)
            {
	    case -type_first_diff:
              {
                if (!opt_print_bytes)
                  {
                    /* See POSIX for this format.  This message is
                       used only in the POSIX locale, so it need not
                       be translated.  */
                    static char const char_message[] =
		      "%s %s differ: char %"PRIdMAX", line %"PRIdMAX"\n";

                    /* The POSIX rationale recommends using the word
                       "byte" outside the POSIX locale.  Some gettext
                       implementations translate even in the POSIX
                       locale if certain other environment variables
                       are set, so use "byte" if a translation is
                       available, or if outside the POSIX locale.  */
                    static char const byte_msgid[] =
		      N_("%s %s differ: byte %"PRIdMAX", line %"PRIdMAX"\n");
                    char const *byte_message = _(byte_msgid);
                    bool use_byte_message = (byte_message != byte_msgid
                                             || hard_locale_LC_MESSAGES ());

                    printf (use_byte_message ? byte_message : char_message,
			    file[0], file[1], byte_number, line_number);
                  }
                else
                  {
                    unsigned char c0 = buf0[first_diff];
                    unsigned char c1 = buf1[first_diff];
                    char s0[5];
                    char s1[5];
                    sprintc (s0, c0);
                    sprintc (s1, c1);
		    printf (_("%s %s differ: byte %"PRIdMAX", line %"PRIdMAX
			      " is %3o %s %3o %s\n"),
			    file[0], file[1], byte_number, line_number,
                            c0, s0, c1, s1);
                  }
              }
              FALLTHROUGH;
	    case -type_status:
              return EXIT_FAILURE;

	    default:
	      dassert (comparison_type == type_all_diffs);

              do
                {
                  unsigned char c0 = buf0[first_diff];
                  unsigned char c1 = buf1[first_diff];
                  if (c0 != c1)
                    {
                      if (!opt_print_bytes)
                        {
                          /* See POSIX for this format.  */
			  printf ("%*"PRIdMAX" %3o %3o\n",
				  offset_width, byte_number, c0, c1);
                        }
                      else
                        {
                          char s0[5];
                          char s1[5];
                          sprintc (s0, c0);
                          sprintc (s1, c1);
			  printf ("%*"PRIdMAX" %3o %-4s %3o %s\n",
				  offset_width, byte_number, c0, s0, c1, s1);
                        }
                    }
                  byte_number++;
                  first_diff++;
                }
              while (first_diff < smaller);

              differing = -1;
              break;

	    case -type_no_stdout:
              differing = 1;
              break;
            }
        }

      if (read0 != read1)
        {
	  /* POSIX says that each of these format strings must be
	     "cmp: EOF on %s", optionally followed by a blank and
	     extra text sans newline, then terminated by "\n".  */
	  if (differing <= 0 && offset_width != -type_status)
	    fprintf (stderr,
		     _(byte_number == 1
		       ? N_("cmp: EOF on %s which is empty\n")
		       : offset_width != -type_first_diff
		       ? N_("cmp: EOF on %s after byte %"PRIdMAX"\n")
		       : at_line_start
		       ? N_("cmp: EOF on %s after byte %"PRIdMAX","
			    " line %"PRIdMAX"\n")
		       : N_("cmp: EOF on %s after byte %"PRIdMAX","
			    " in line %"PRIdMAX"\n")),
		     quote (file[read1 < read0]),
		     byte_number - 1, line_number - at_line_start);
          return EXIT_FAILURE;
        }

      if (0 < differing || read0 != buf_size)
	return differing == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
    }
}

/* Compare two blocks of memory P0 and P1 until they differ.
   If the blocks are not guaranteed to be different, put sentinels at the ends
   of the blocks before calling this function.

   Return the offset of the first byte that differs.  */

static idx_t
block_compare (word const *p0, word const *p1)
{
  word const *l0, *l1;
  char const *c0, *c1;

  /* Find the rough position of the first difference by reading words,
     not bytes.  */

  for (l0 = p0, l1 = p1;  *l0 == *l1;  l0++, l1++)
    continue;

  /* Find the exact differing position (endianness independent).  */

  for (c0 = (char const *) l0, c1 = (char const *) l1;
       *c0 == *c1;
       c0++, c1++)
    continue;

  return c0 - (char const *) p0;
}

/* Return the number of newlines in BUF, of size BUFSIZE,
   where BUF[NBYTES] is available for use as a sentinel.  */

static idx_t
count_newlines (char *buf, idx_t bufsize)
{
  idx_t count = 0;
  char *lim = buf + bufsize;
  char ch = *lim;
  *lim = '\n';
  for (char *p = buf; (p = rawmemchr (p, '\n')) != lim; p++)
    count++;
  *lim = ch;
  return count;
}

/* Put into BUF the unsigned char C, making unprintable bytes
   visible by quoting like cat -t does.  */

static void
sprintc (char *buf, unsigned char c)
{
  if (! c_isprint (c))
    {
      if (c >= 128)
        {
          *buf++ = 'M';
          *buf++ = '-';
          c -= 128;
        }
      if (c < 32)
        {
          *buf++ = '^';
          c += 64;
        }
      else if (c == 127)
        {
          *buf++ = '^';
          c = '?';
        }
    }

  *buf++ = c;
  *buf = 0;
}

/* Position file F to ignore_initial[F] bytes from its initial position,
   and yield its new position.  Return a negative number on failure.
   Do not report an error on failure, as lseek is generally a no-op
   on devices that cannot seek.  Don't try more than once.  */

static off_t
file_position (int f)
{
  /* The initial position of input file F, and whether that position has
     been determined.  The position is -1 if it could not be determined.  */
  static bool positioned[2];
  static off_t position[2];

  if (! positioned[f])
    {
      positioned[f] = true;
      off_t pos = ignore_initial[f];
      position[f] = (0 <= pos && pos <= TYPE_MAXIMUM (off_t)
		     ? lseek (file_desc[f], pos, SEEK_CUR)
		     : -1);
    }
  return position[f];
}
