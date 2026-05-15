/* Context-format output routines for GNU DIFF.

   Copyright (C) 1988-1989, 1991-1995, 1998, 2001-2002, 2004, 2006, 2009-2013,
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

#include "diff.h"
#include <c-ctype.h>
#include <stat-time.h>
#include <strftime.h>

static char const *find_function (char const *const *, lin);
static struct change *find_hunk (struct change *);
static void mark_ignorable (struct change *);
static void pr_context_hunk (struct change *);
static void pr_unidiff_hunk (struct change *);

/* Last place find_function started searching from.  */
static lin find_function_last_search;

/* The value find_function returned when it started searching there.  */
static lin find_function_last_match;

/* Print a label for a context diff, with a file name and date or a label.  */

static void
print_context_label (char const *mark,
                     struct file_data *inf,
                     char const *name,
                     char const *label)
{
  set_color_context (HEADER_CONTEXT);
  if (label)
    fprintf (outfile, "%s %s", mark, label);
  else
    {
      /* POSIX requires current time for stdin.  */
      struct timespec ts;
      if (inf->desc == STDIN_FILENO)
	{
	  static struct timespec now;
	  if (!now.tv_sec)
	    timespec_get (&now, TIME_UTC);
	  ts = now;
	}
      else
	ts = get_stat_mtime (&inf->stat);

      /* Buffer for nstftime output, big enough to handle any
	 timestamp formatted according to time_format.
	 Its size is an upper bound for the format "%Y-%m-%d %H:%M:%S.%N %z",
	 with an int for year and a time_t for time zone hour.
	 The format "%Y-%m-%d %H:%M:%S %z" generates fewer bytes,
	 and although the format "%a %b %e %T %Y" could in theory
	 generate more bytes in practice it never does.  */
      char buf[INT_STRLEN_BOUND (int) + INT_STRLEN_BOUND (time_t)
	       + sizeof "-%m-%d %H:%M:%S.000000000 +00"];

      struct tm const *tm = localtime (&ts.tv_sec);
      int nsec = ts.tv_nsec;
      if (tm && nstrftime (buf, sizeof buf, time_format, tm, localtz, nsec))
	fprintf (outfile, "%s %s\t%s", mark, name, buf);
      else if (TYPE_SIGNED (time_t))
        {
	  intmax_t sec = inf->stat.st_mtime;
	  fprintf (outfile, "%s %s\t%"PRIdMAX".%.9d", mark, name, sec, nsec);
	}
      else
	{
	  uintmax_t sec = inf->stat.st_mtime;
	  fprintf (outfile, "%s %s\t%"PRIuMAX".%.9d", mark, name, sec, nsec);
	}
    }
  set_color_context (RESET_CONTEXT);
  putc ('\n', outfile);
}

/* Print a header for a context diff, with the file names and dates.  */

void
print_context_header (struct file_data inf[], char const *const *names, bool unidiff)
{
  if (unidiff)
    {
      print_context_label ("---", &inf[0], names[0], file_label[0]);
      print_context_label ("+++", &inf[1], names[1], file_label[1]);
    }
  else
    {
      print_context_label ("***", &inf[0], names[0], file_label[0]);
      print_context_label ("---", &inf[1], names[1], file_label[1]);
    }
}

/* Print an edit script in context format.  */

void
print_context_script (struct change *script, bool unidiff)
{
  if (ignore_blank_lines || ignore_regexp.fastmap)
    mark_ignorable (script);
  else
    for (struct change *e = script; e; e = e->link)
      e->ignore = false;

  find_function_last_search = - curr.file[0].prefix_lines;
  find_function_last_match = LIN_MAX;

  if (unidiff)
    print_script (script, find_hunk, pr_unidiff_hunk);
  else
    print_script (script, find_hunk, pr_context_hunk);
}

/* Print a pair of line numbers with a comma, translated for file FILE.
   If the second number is not greater, use the first in place of it.

   Args A and B are internal line numbers.
   We print the translated (real) line numbers.  */

static void
print_context_number_range (struct file_data const *file, lin a, lin b)
{
  lin trans_a, trans_b;
  translate_range (file, a, b, &trans_a, &trans_b);

  /* We can have B <= A in the case of a range of no lines.
     In this case, we should print the line number before the range,
     which is B.

     POSIX 1003.1-2001 requires two line numbers separated by a comma
     even if the line numbers are the same.  However, this does not
     match existing practice and is surely an error in the
     specification.  */

  if (trans_b <= trans_a)
    fprintf (outfile, "%"pI"d", trans_b);
  else
    fprintf (outfile, "%"pI"d,%"pI"d", trans_a, trans_b);
}

/* Print FUNCTION in a context header.  */
static void
print_context_function (FILE *out, char const *function)
{
  int i, j;
  putc (' ', out);
  for (i = 0; c_isspace ((unsigned char) function[i]) && function[i] != '\n'; i++)
    continue;
  for (j = i; j < i + 40 && function[j] != '\n'; j++)
    continue;
  while (i < j && c_isspace ((unsigned char) function[j - 1]))
    j--;
  fwrite (function + i, sizeof (char), j - i, out);
}

/* Print a portion of an edit script in context format.
   HUNK is the beginning of the portion to be printed.
   The end is marked by a 'link' that has been nulled out.

   Prints out lines from both files, and precedes each
   line with the appropriate flag-character.  */

static void
pr_context_hunk (struct change *hunk)
{
  /* Determine range of line numbers involved in each file.  */
  lin first0, last0, first1, last1;
  enum changes changes = analyze_hunk (hunk, &first0, &last0, &first1, &last1);
  if (! changes)
    return;

  /* Include a context's width before and after.  */

  lin minus_prefix_lines = - curr.file[0].prefix_lines;
  first0 = MAX (first0 - context, minus_prefix_lines);
  first1 = MAX (first1 - context, minus_prefix_lines);
  if (last0 < curr.file[0].valid_lines - context)
    last0 += context;
  else
    last0 = curr.file[0].valid_lines - 1;
  if (last1 < curr.file[1].valid_lines - context)
    last1 += context;
  else
    last1 = curr.file[1].valid_lines - 1;

  /* If desired, find the preceding function definition line in file 0.  */
  char const *function = nullptr;
  if (function_regexp.fastmap)
    function = find_function (curr.file[0].linbuf, first0);

  begin_output ();
  FILE *out = outfile;

  fputs ("***************", out);

  if (function)
    print_context_function (out, function);

  putc ('\n', out);
  set_color_context (LINE_NUMBER_CONTEXT);
  fputs ("*** ", out);
  print_context_number_range (&curr.file[0], first0, last0);
  fputs (" ****", out);
  set_color_context (RESET_CONTEXT);
  putc ('\n', out);

  if (changes & OLD)
    {
      struct change *next = hunk;

      for (lin i = first0; i <= last0; i++)
        {
          set_color_context (DELETE_CONTEXT);

          /* Skip past changes that apply (in file 0)
             only to lines before line I.  */

          while (next && next->line0 + next->deleted <= i)
            next = next->link;

          /* Compute the marking for line I.  */

          char const *prefix = " ";
          if (next && next->line0 <= i)
            {
              /* The change NEXT covers this line.
                 If lines were inserted here in file 1, this is "changed".
                 Otherwise it is "deleted".  */
              prefix = (next->inserted > 0 ? "!" : "-");
            }
	  print_1_line_nl (prefix, &curr.file[0].linbuf[i], true);
          set_color_context (RESET_CONTEXT);
	  if (curr.file[0].linbuf[i + 1][-1] == '\n')
            putc ('\n', out);
        }
    }

  set_color_context (LINE_NUMBER_CONTEXT);
  fputs ("--- ", out);
  print_context_number_range (&curr.file[1], first1, last1);
  fputs (" ----", out);
  set_color_context (RESET_CONTEXT);
  putc ('\n', out);

  if (changes & NEW)
    {
      struct change *next = hunk;

      for (lin i = first1; i <= last1; i++)
        {
          set_color_context (ADD_CONTEXT);

          /* Skip past changes that apply (in file 1)
             only to lines before line I.  */

          while (next && next->line1 + next->inserted <= i)
            next = next->link;

          /* Compute the marking for line I.  */

          char const *prefix = " ";
          if (next && next->line1 <= i)
            {
              /* The change NEXT covers this line.
                 If lines were deleted here in file 0, this is "changed".
                 Otherwise it is "inserted".  */
              prefix = (next->deleted > 0 ? "!" : "+");
            }
	  print_1_line_nl (prefix, &curr.file[1].linbuf[i], true);
          set_color_context (RESET_CONTEXT);
	  if (curr.file[1].linbuf[i + 1][-1] == '\n')
            putc ('\n', out);
        }
    }
}

/* Print a pair of line numbers with a comma, translated for file FILE.
   If the second number is smaller, use the first in place of it.
   If the numbers are equal, print just one number.

   Args A and B are internal line numbers.
   We print the translated (real) line numbers.  */

static void
print_unidiff_number_range (struct file_data const *file, lin a, lin b)
{
  lin trans_a, trans_b;
  translate_range (file, a, b, &trans_a, &trans_b);

  /* We can have B < A in the case of a range of no lines.
     In this case, we print the line number before the range,
     which is B.  It would be more logical to print A, but
     'patch' expects B in order to detect diffs against empty files.  */
  if (trans_b <= trans_a)
    fprintf (outfile, trans_b < trans_a ? "%"pI"d,0" : "%"pI"d", trans_b);
  else
    fprintf (outfile, "%"pI"d,%"pI"d", trans_a, trans_b - trans_a + 1);
}

/* Print a portion of an edit script in unidiff format.
   HUNK is the beginning of the portion to be printed.
   The end is marked by a 'link' that has been nulled out.

   Prints out lines from both files, and precedes each
   line with the appropriate flag-character.  */

static void
pr_unidiff_hunk (struct change *hunk)
{
  /* Determine range of line numbers involved in each file.  */
  lin first0, last0, first1, last1;
  if (! analyze_hunk (hunk, &first0, &last0, &first1, &last1))
    return;

  /* Include a context's width before and after.  */

  lin minus_prefix_lines = - curr.file[0].prefix_lines;
  first0 = MAX (first0 - context, minus_prefix_lines);
  first1 = MAX (first1 - context, minus_prefix_lines);
  if (last0 < curr.file[0].valid_lines - context)
    last0 += context;
  else
    last0 = curr.file[0].valid_lines - 1;
  if (last1 < curr.file[1].valid_lines - context)
    last1 += context;
  else
    last1 = curr.file[1].valid_lines - 1;

  /* If desired, find the preceding function definition line in file 0.  */
  char const *function = nullptr;
  if (function_regexp.fastmap)
    function = find_function (curr.file[0].linbuf, first0);

  begin_output ();
  FILE *out = outfile;

  set_color_context (LINE_NUMBER_CONTEXT);
  fputs ("@@ -", out);
  print_unidiff_number_range (&curr.file[0], first0, last0);
  fputs (" +", out);
  print_unidiff_number_range (&curr.file[1], first1, last1);
  fputs (" @@", out);
  set_color_context (RESET_CONTEXT);

  if (function)
    print_context_function (out, function);

  putc ('\n', out);

  struct change *next = hunk;
  lin i = first0;
  lin j = first1;

  while (i <= last0 || j <= last1)
    {

      /* If the line isn't a difference, output the context from file 0. */

      if (!next || i < next->line0)
        {
	  char const *const *line = &curr.file[0].linbuf[i++];
          if (! (suppress_blank_empty && **line == '\n'))
            putc (initial_tab ? '\t' : ' ', out);
          print_1_line (nullptr, line);
          j++;
        }
      else
        {
          /* For each difference, first output the deleted part. */

          lin k = next->deleted;

          while (k--)
            {
	      char const *const *line = &curr.file[0].linbuf[i++];
              set_color_context (DELETE_CONTEXT);
              putc ('-', out);
              if (initial_tab && ! (suppress_blank_empty && **line == '\n'))
                putc ('\t', out);
              print_1_line_nl (nullptr, line, true);

              set_color_context (RESET_CONTEXT);

              if (line[1][-1] == '\n')
                putc ('\n', out);
            }

          /* Then output the inserted part. */

          k = next->inserted;

          while (k--)
            {
	      char const *const *line = &curr.file[1].linbuf[j++];
              set_color_context (ADD_CONTEXT);
              putc ('+', out);
              if (initial_tab && ! (suppress_blank_empty && **line == '\n'))
                putc ('\t', out);
              print_1_line_nl (nullptr, line, true);

              set_color_context (RESET_CONTEXT);

              if (line[1][-1] == '\n')
                putc ('\n', out);
            }

          /* We're done with this hunk, so on to the next! */

          next = next->link;
        }
    }
}

/* Scan a (forward-ordered) edit script for the first place that more than
   2*CONTEXT unchanged lines appear, and return a pointer
   to the 'struct change' for the last change before those lines.  */

static struct change * ATTRIBUTE_PURE
find_hunk (struct change *script)
{
  /* Threshold distance is CONTEXT if the second change is ignorable,
     min (2 * CONTEXT + 1, LIN_MAX) otherwise.  */
  lin ignorable_threshold = context;
  lin non_ignorable_threshold = (ckd_mul (&non_ignorable_threshold, context, 2)
				 ? LIN_MAX
				 : non_ignorable_threshold + 1);

  for (struct change *next; ; script = next)
    {
      next = script->link;
      /* Compute number of first line in each file beyond this changed.  */
      lin top0 = script->line0 + script->deleted;
      lin top1 = script->line1 + script->inserted;
      lin thresh = (next && next->ignore
		    ? ignorable_threshold
		    : non_ignorable_threshold);
      /* It is not supposed to matter which file we check in the end-test.  */
      dassert (!next || next->line0 - top0 == next->line1 - top1);

      /* Keep going if less than THRESH lines elapse
	 before the affected line.  */
      if (!next || thresh <= next->line0 - top0)
	return script;
    }
}

/* Set the 'ignore' flag properly in each change in SCRIPT.
   It should be 1 if all the lines inserted or deleted in that change
   are ignorable lines.  */

static void
mark_ignorable (struct change *script)
{
  while (script)
    {
      struct change *next = script->link;

      /* Turn this change into a hunk: detach it from the others.  */
      script->link = nullptr;

      /* Determine whether this change is ignorable.  */
      lin first0, last0, first1, last1;
      script->ignore = ! analyze_hunk (script,
                                       &first0, &last0, &first1, &last1);

      /* Reconnect the chain as before.  */
      script->link = next;

      /* Advance to the following change.  */
      script = next;
    }
}

/* Find the last function-header line in LINBUF prior to line number LINENUM.
   This is a line containing a match for the regexp in 'function_regexp'.
   Return the address of the text, or null if no function-header is found.  */

static char const *
find_function (char const *const *linbuf, lin linenum)
{
  lin i = linenum;
  lin last = find_function_last_search;
  find_function_last_search = i;

  while (last <= --i)
    {
      /* See if this line is what we want.  */
      char const *line = linbuf[i];
      idx_t linelen = linbuf[i + 1] - line - 1;

      /* This line is for documentation; in practice it's equivalent
	 to LEN = LINELEN and no machine code is generated.  */
      regoff_t len = MIN (linelen, TYPE_MAXIMUM (regoff_t));

      if (0 <= re_search (&function_regexp, line, len, 0, len, nullptr))
        {
          find_function_last_match = i;
          return line;
        }
    }
  /* If we search back to where we started searching the previous time,
     find the line we found last time.  */
  if (find_function_last_match != LIN_MAX)
    return linbuf[find_function_last_match];

  return nullptr;
}
