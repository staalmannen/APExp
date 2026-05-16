/*  Merge a patch

    Copyright 2009-2025 Free Software Foundation, Inc.
    Written by Andreas Gruenbacher <agruen@gnu.org>, 2009.

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

#include <common.h>
#include <xalloc.h>
#include <inp.h>
#include <pch.h>
#include <util.h>

static idx_t count_context_lines (void);
static bool context_matches_file (idx_t, idx_t);
static void compute_changes (idx_t, idx_t, idx_t, idx_t, char *, char *);

#define OFFSET ptrdiff_t
#define EQUAL_IDX(x, y) (context_matches_file (x, y))
#include "bestmatch.h"

#define XVECREF_YVECREF_EQUAL(ctxt, x, y) (context_matches_file (x, y))
#define OFFSET ptrdiff_t
#define EXTRA_CONTEXT_FIELDS \
	char *xchar; \
	char *ychar;
#define NOTE_DELETE(ctxt, xoff) ctxt->xchar[xoff] = '-';
#define NOTE_INSERT(ctxt, yoff) ctxt->ychar[yoff] = '+';
#define USE_HEURISTIC 1
#include "diffseq.h"

static idx_t
locate_merge (idx_t *matched)
{
    idx_t first_guess = pch_first () + in_offset;
    idx_t pat_lines = pch_ptrn_lines ();
    idx_t context_lines = count_context_lines ();
    idx_t max_where = input_lines - pat_lines + context_lines + 1;
    idx_t min_where = last_frozen_line + 1;
    ptrdiff_t max_pos_offset = max_where - first_guess;
    ptrdiff_t max_neg_offset = first_guess - min_where;
    ptrdiff_t max_offset = MAX (max_pos_offset, max_neg_offset);
    idx_t where = first_guess;
    idx_t max_matched = 0;
    bool match_until_eof;

    /* Note: we need to preserve patch's property that it applies hunks at the
       best match closest to their original position in the file.  It is
       common for hunks to apply equally well in several places in a file.
       Applying at the first best match would be a lot easier.
     */

    if (context_lines == 0)
      goto out;  /* locate_hunk() already tried that */

    /* Allow at most CONTEXT_LINES lines to be replaced (replacing counts
       as insert + delete), and require the remaining MIN lines to match.  */
    idx_t max = 2 * context_lines;
    idx_t min = pat_lines - context_lines;

    if (debug & 1)
      say ("locating merge: min=%td max=%td ", min, max);

    /* Hunks from the start or end of the file have less context. Anchor them
       to the start or end, trying to make up for this disadvantage.  */
    ptrdiff_t offset = pch_suffix_context () - pch_prefix_context ();
    if (offset > 0 && pch_first () <= 1)
      max_pos_offset = 0;
    match_until_eof = offset < 0;

    /* Do not try lines <= 0.  */
    if (first_guess <= max_neg_offset)
      max_neg_offset = first_guess - 1;

    for (offset = 0; offset <= max_offset; offset++)
      {
	if (offset <= max_pos_offset)
	  {
	    idx_t guess = first_guess + offset, last, changes;

	    changes = bestmatch (1, pat_lines + 1, guess, input_lines + 1,
				 match_until_eof ? input_lines - guess + 1 : min,
				 max, &last);
	    if (changes <= max && max_matched < last - guess)
	      {
		max_matched = last - guess;
		where = guess;
		if (changes == 0)
		  break;
		min = last - guess;
		max = changes - 1;
	      }
	  }
	if (0 < offset && offset <= max_neg_offset)
	  {
	    idx_t guess = first_guess - offset, last, changes;

	    changes = bestmatch (1, pat_lines + 1, guess, input_lines + 1,
				 match_until_eof ? input_lines - guess + 1 : min,
				 max, &last);
	    if (changes <= max && max_matched < last - guess)
	      {
		max_matched = last - guess;
		where = guess;
		if (changes == 0)
		  break;
		min = last - guess;
		max = changes - 1;
	      }
	  }
      }
    if (debug & 1)
      say ("where=%td matched=%td changes=%td\n", where, max_matched, max + 1);

  out:
    *matched = max_matched;
    if (where < min_where)
      where = min_where;
    return where;
}

static void
print_linerange (idx_t from, idx_t to)
{
  if (to <= from)
    Fprintf (stdout, "%td", from);
  else
    Fprintf (stdout, "%td-%td", from, to);
}

static void
merge_result (bool *first_result, intmax_t hunk, char const *what,
	      idx_t from, idx_t to)
{
  static char const *last_what;

  if (*first_result && what)
    {
      Fprintf (stdout, "Hunk #%jd %s at ", hunk, what);
      last_what = what;
    }
  else if (! what)
    {
      if (! *first_result)
	{
	  Fputs (".\n", stdout);
	  Fflush (stdout);
	  last_what = 0;
	}
      return;
    }
  else if (last_what == what)
    Fputc (',', stdout);
  else
    Fprintf (stdout, ", %s at ", what);

  print_linerange (from + out_offset, to + out_offset);
  *first_result = false;
}

bool
merge_hunk (intmax_t hunk, struct outstate *outstate,
	    idx_t where, bool *somefailed)
{
  bool applies_cleanly;
  bool first_result = true;
  bool already_applied;
  FILE *fp = outstate->ofp;
  idx_t old = 1;
  idx_t firstold = pch_ptrn_lines ();
  idx_t new = firstold + 1;
  char *oldin;
  idx_t lastwhere;

  /* Convert '!' markers into '-' and '+' to simplify things here.  */
  pch_normalize (UNI_DIFF);

  assert (pch_char (pch_end () + 1) == '^');
  while (pch_char (new) == '=' || pch_char (new) == '\n')
    new++;

  idx_t matched;
  if (where)
    {
      applies_cleanly = true;
      matched = pch_ptrn_lines ();
    }
  else
    {
      where = locate_merge (&matched);
      applies_cleanly = false;
    }

  idx_t in = firstold + 2;
  oldin = xmalloc (in + matched + 1);
  memset (oldin, ' ', in + matched);
  oldin[0] = '*';
  oldin[in - 1] = '=';
  oldin[in + matched] = '^';
  compute_changes (old, in - 1, where, where + matched,
		   oldin + old, oldin + in);

  if (debug & 2)
    {
      Fputc ('\n', stderr);
      for (idx_t n = 0; n <= in + matched; n++)
	{
	  Fprintf (stderr, "%td %c", n, oldin[n]);
	  if (n == 0)
	    Fprintf (stderr, " %td,%td\n", pch_first (), pch_ptrn_lines ());
	  else if (n <= firstold)
	    {
	      Fputs (" |", stderr);
	      Fwrite (pfetch (n), 1, pch_line_len (n), stderr);
	    }
	  else if (n == in - 1)
	    Fprintf (stderr, " %td,%td\n", where, matched);
	  else if (n >= in && n < in + matched)
	    {
	      struct iline line = ifetch (where + n - in);
	      Fputs (" |", stderr);
	      Fwrite (line.ptr, 1, line.size, stderr);
	    }
	  else
	    Fputc ('\n', stderr);
	}
      Fflush (stderr);
    }

  if (last_frozen_line < where - 1)
    if (! copy_till (outstate, where - 1))
      return false;

  for (;;)
    {
      firstold = old;
      idx_t firstnew = new;
      idx_t firstin = in;

      if (pch_char (old) == '-' || pch_char (new) == '+')
	{
	  while (pch_char (old) == '-')
	    {
	      if (oldin[old] == '-' || oldin[in] == '+')
		goto conflict;
	      else if (oldin[old] == ' ')
		{
		  assert (oldin[in] == ' ');
		  in++;
		}
	      old++;
	    }
	  if (oldin[old] == '-' || oldin[in] == '+')
	    goto conflict;
	  while (pch_char (new) == '+')
	    new++;

	  idx_t lines = new - firstnew;
	  if (verbosity == VERBOSE
	      || ((verbosity != SILENT) && ! applies_cleanly))
	    merge_result (&first_result, hunk, "merged",
			  where, where + lines - 1);
	  last_frozen_line += (old - firstold);
	  where += (old - firstold);
	  out_offset += new - firstnew;

	  if (firstnew < new)
	    {
	      while (firstnew < new)
		{
		  outstate->after_newline = pch_write_line (firstnew, fp);
		  firstnew++;
		}
	      outstate->zero_output = false;
	    }
	}
      else if (pch_char (old) == ' ')
	{
	  if (oldin[old] == '-')
	    {
	      while (pch_char (old) == ' ')
		{
		  if (oldin[old] != '-')
		    break;
		  if (pch_char (new) == '+')
		    goto conflict;
		  else
		    assert (pch_char (new) == ' ');
		  old++;
		  new++;
		}
	      if (pch_char (old) == '-' || pch_char (new) == '+')
		goto conflict;
	    }
	  else if (oldin[in] == '+')
	    {
	      while (oldin[in] == '+')
		in++;

	      /* Take these lines from the input file.  */
	      where += in - firstin;
	      if (! copy_till (outstate, where - 1))
		return false;
	    }
	  else if (oldin[old] == ' ')
	    {
	      while (pch_char (old) == ' '
		     && oldin[old] == ' '
		     && pch_char (new) == ' '
		     && oldin[in] == ' ')
		{
		  old++;
		  new++;
		  in++;
		}

	      /* Take these lines from the input file.  */
	      where += (in - firstin);
	      if (! copy_till (outstate, where - 1))
		return false;
	    }
	}
      else
	{
	  assert (pch_char (old) == '=' && pch_char (new) == '^');
	  /* Nothing more left to merge.  */
	  break;
	}
      continue;

    conflict:
      /* Find the end of the conflict.  */
      for (;;)
	{
	  if (pch_char (old) == '-')
	    {
	      while (oldin[in] == '+')
		in++;
	      if (oldin[old] == ' ')
		{
		  assert (oldin[in] == ' ');
		  in++;
		}
	      old++;
	    }
	  else if (oldin[old] == '-')
	    {
	      while (pch_char (new) == '+')
		new++;
	      if (pch_char (old) == ' ')
		{
		  assert (pch_char (new) == ' ');
		  new++;
		}
	      old++;
	    }
	  else if (pch_char (new) == '+')
	    while (pch_char (new) == '+')
	      new++;
	  else if (oldin[in] == '+')
	    while (oldin[in] == '+')
	      in++;
	  else
	    break;
	}
      assert (((pch_char (old) == ' ' && pch_char (new) == ' ')
	       || (pch_char (old) == '=' && pch_char (new) == '^'))
	      && ((oldin[old] == ' ' && oldin[in] == ' ')
		  || (oldin[old] == '=' && oldin[in] == '^')));

      /* Output common prefix lines.  */
      for (lastwhere = where;
	   firstin < in && firstnew < new
	     && context_matches_file (firstnew, lastwhere);
	   firstin++, firstnew++, lastwhere++)
	/* do nothing */ ;
      already_applied = (firstin == in && firstnew == new);
      if (already_applied)
	merge_result (&first_result, hunk, "already applied",
		      where, lastwhere - 1);
      if (conflict_style == MERGE_DIFF3)
	{
	  idx_t common_prefix = lastwhere - where;

	  /* Forget about common prefix lines.  */
	  firstin -= common_prefix;
	  firstnew -= common_prefix;
	  lastwhere -= common_prefix;
	}
      if (where != lastwhere)
	{
	  where = lastwhere;
	  if (! copy_till (outstate, where - 1))
	    return false;
	}

      if (! already_applied)
	{
	  idx_t common_suffix = 0;

	  if (conflict_style == MERGE_MERGE)
	    {
	      /* Remember common suffix lines.  */
	      for (lastwhere = where + (in - firstin);
		   firstin < in && firstnew < new
		   && context_matches_file (new - 1, lastwhere - 1);
		   in--, new--, lastwhere--, common_suffix++)
		/* do nothing */ ;
	    }

	  idx_t lines = 3 + (in - firstin) + (new - firstnew);
	  if (conflict_style == MERGE_DIFF3)
	    lines += 1 + (old - firstold);
	  merge_result (&first_result, hunk, "NOT MERGED",
			where, where + lines - 1);
	  out_offset += lines - (in - firstin);

	  Fputs (&"\n<<<<<<<\n"[outstate->after_newline], fp);
	  outstate->after_newline = true;
	  if (firstin < in)
	    {
	      where += (in - firstin);
	      if (! copy_till (outstate, where - 1))
		return false;
	    }

	  if (conflict_style == MERGE_DIFF3)
	    {
	      Fputs (&"\n|||||||\n"[outstate->after_newline], fp);
	      outstate->after_newline = true;
	      while (firstold < old)
		{
		  outstate->after_newline = pch_write_line (firstold, fp);
		  firstold++;
		}
	    }

	  Fputs (&"\n=======\n"[outstate->after_newline], fp);
	  outstate->after_newline = true;
	  while (firstnew < new)
	    {
	      outstate->after_newline = pch_write_line (firstnew, fp);
	      firstnew++;
	    }
	  Fputs (&"\n>>>>>>>\n"[outstate->after_newline], fp);
	  outstate->after_newline = true;
	  outstate->zero_output = false;
	  if (ferror (fp))
	    write_fatal ();

	  /* Output common suffix lines.  */
	  if (common_suffix)
	    {
	      where += common_suffix;
	      if (! copy_till (outstate, where - 1))
		return false;
	      in += common_suffix;
	      new += common_suffix;
	    }
	  *somefailed = true;
	}
    }
  merge_result (&first_result, 0, 0, 0, 0);

  assert (last_frozen_line == where - 1);
  free (oldin);
  return true;
}

static idx_t
count_context_lines (void)
{
  idx_t lastold = pch_ptrn_lines ();
  idx_t context = 0;

  for (idx_t old = 1; old <= lastold; old++)
    if (pch_char (old) == ' ')
      context++;
  return context;
}

static bool
context_matches_file (idx_t old, idx_t where)
{
  struct iline line = ifetch (where);
  return line.size &&
	 (canonicalize_ws ?
	  similar (pfetch (old), pch_line_len (old), line.ptr, line.size) :
	  (line.size == pch_line_len (old) &&
	   memcmp (line.ptr, pfetch (old), line.size) == 0));
}

static void
compute_changes (idx_t xmin, idx_t xmax, idx_t ymin, idx_t ymax,
		 char *xchar, char *ychar)
{
  struct context ctxt;
  ctxt.xchar = xchar - xmin;
  ctxt.ychar = ychar - ymin;

  idx_t diags;
  if (ckd_add (&diags, xmax, ymax) || ckd_add (&diags, diags, 3))
    xalloc_die ();
  ctxt.fdiag = xinmalloc (diags, 2 * sizeof *ctxt.fdiag);
  ctxt.bdiag = ctxt.fdiag + diags;
  ctxt.fdiag += ymax + 1;
  ctxt.bdiag += ymax + 1;

  ctxt.heuristic = true;

  compareseq (xmin, xmax, ymin, ymax, false, &ctxt);

  ctxt.fdiag -= ymax + 1;
  free (ctxt.fdiag);
}
