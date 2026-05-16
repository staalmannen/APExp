/* File I/O for GNU DIFF.

   Copyright (C) 1988-1989, 1992-1995, 1998, 2001-2002, 2004, 2006, 2009-2013,
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
#include <binary-io.h>
#include <cmpbuf.h>
#include <file-type.h>
#include <ialloc.h>
#include <mcel.h>
#include <xalloc.h>

#include <ctype.h>
#include <uchar.h>

/* The type of a hash value.  */
typedef size_t hash_value;
enum { HASH_VALUE_WIDTH = SIZE_WIDTH };
static_assert (! TYPE_SIGNED (hash_value));

/* Rotate a hash value to the left.  */
static hash_value
rol (hash_value v, int n)
{
  return v << n | v >> (HASH_VALUE_WIDTH - n);
}

/* Given a hash value and a new character, return a new hash value.  */
static hash_value
hash (hash_value h, hash_value c)
{
  return rol (h, 7) + c;
}

/* Lines are put into equivalence classes of lines that match in lines_differ.
   Each equivalence class is represented by one of these structures,
   but only while the classes are being computed.
   Afterward, each class is represented by a number.  */
struct equivclass
{
  lin next;		/* Next item in this bucket.  */
  hash_value hash;	/* Hash of lines in this class.  */
  char const *line;	/* A line that fits this class.  */
  idx_t length;		/* That line's length, counting its newline.  */
};

/* Hash-table: array of buckets, each being a chain of equivalence classes.
   buckets[-1] is reserved for incomplete lines.  */
static lin *buckets;

/* Number of buckets in the hash table array, not counting buckets[-1].  */
static idx_t nbuckets;

/* Array in which the equivalence classes are allocated.
   The bucket-chains go through the elements in this array.
   The number of an equivalence class is its index in this array.  */
static struct equivclass *equivs;

/* Index of first free element in the array 'equivs'.  */
static lin equivs_index;

/* Number of elements allocated in the array 'equivs'.  */
static idx_t equivs_alloc;

/* The file buffer, considered as an array of bytes rather than
   as an array of words.  */

static char *
file_buffer (struct file_data const *f)
{
  return (char *) f->buffer;
}

/* Read a block of data into a file buffer, checking for EOF and error.  */

void
file_block_read (struct file_data *current, idx_t size)
{
  if (size && ! current->eof)
    {
      ptrdiff_t s = block_read (current->desc,
				file_buffer (current) + current->buffered,
				size);
      if (s < 0)
        pfatal_with_name (current->name);
      current->buffered += s;
      current->eof = s < size;
    }
}

/* Check for binary files and compare them for exact identity.  */

/* Return true if BUF contains a non text character.
   SIZE is the number of characters in BUF.  */

#define binary_file_p(buf, size) (!! memchr (buf, 0, size))

/* Get ready to read the current file.
   Return nonzero if SKIP_TEST is zero,
   and if it appears to be a binary file.  */

static bool
sip (struct file_data *current, bool skip_test)
{
  /* If we have a nonexistent file at this stage, treat it as empty.  */
  if (current->desc < 0)
    {
      /* Leave room for a sentinel.  */
      current->bufsize = sizeof (word);
      current->buffer = ximalloc (current->bufsize);
    }
  else
    {
      idx_t blksize;
      if (ST_BLKSIZE (current->stat) < 0
	  || ckd_add (&blksize, ST_BLKSIZE (current->stat), 0))
	blksize = 0;
      current->bufsize = buffer_lcm (sizeof (word), blksize, IDX_MAX);
      current->buffer = ximalloc (current->bufsize);

#ifdef __KLIBC__
      /* Skip test if seek is not possible */
      skip_test = skip_test
                  || (lseek (current->desc, 0, SEEK_CUR) < 0
                      && errno == ESPIPE);
#endif

      if (! skip_test)
        {
          /* Check first part of file to see if it's a binary file.  */

          int prev_mode = set_binary_mode (current->desc, O_BINARY);
          file_block_read (current, current->bufsize);
          off_t buffered = current->buffered;

          if (prev_mode != O_BINARY)
            {
              /* Revert to text mode and seek back to the start to reread
                 the file.  Use relative seek, since file descriptors
                 like stdin might not start at offset zero.  */
              if (lseek (current->desc, - buffered, SEEK_CUR) < 0)
                pfatal_with_name (current->name);
              set_binary_mode (current->desc, prev_mode);
              current->buffered = 0;
              current->eof = false;
            }

          return binary_file_p (current->buffer, buffered);
        }
    }

  current->buffered = 0;
  current->eof = false;
  return false;
}

/* Slurp the rest of the current file completely into memory.  */

static void
slurp (struct file_data *current)
{
  if (current->desc < 0)
    {
      /* The file is nonexistent.  */
      return;
    }

  /* Upper bound on the room needed for an appended newline, word
     sentinel, and worst-case word alignment.  */
  enum { extra_room = 2 * sizeof (word) };

  if (S_ISREG (current->stat.st_mode))
    {
      /* It's a regular file; try to allocate a big enough buffer so
	 that it can be slurped in all at once, along with appended
	 newline plus word sentinel plus word-alignment.  */
      off_t file_size = current->stat.st_size;
      idx_t cc;
      if (0 <= file_size
	  && !ckd_add (&cc, file_size - file_size % sizeof (word), extra_room)
	  && current->bufsize < cc)
	{
	  #if __GNUC__ == 13 && __GNUC_MINOR__ < 3
	    /* Work around GCC bug 110014.  */
	    #pragma GCC diagnostic push
	    #pragma GCC diagnostic ignored "-Wanalyzer-allocation-size"
	  #endif

	  word *buffer = irealloc (current->buffer, cc);

	  if (buffer)
	    {
	      current->buffer = buffer;
	      current->bufsize = cc;
	    }

	  #if __GNUC__ == 13
	    #pragma GCC diagnostic pop
	  #endif
	}
    }

  /* Read the file, growing the buffer as needed.  */

  while (file_block_read (current, current->bufsize - current->buffered),
	 !current->eof)
    current->buffer = xpalloc (current->buffer, &current->bufsize,
			       extra_room, -1, 1);

  if (current->bufsize - current->buffered < extra_room)
    {
      if (ckd_add (&current->bufsize, current->buffered, extra_room))
	xalloc_die ();
      current->buffer = xirealloc (current->buffer, current->bufsize);
    }
}

/* Return true if CH1 and ERR1 stand for the same character or
   encoding error as CH2 and ERR2.  */
static bool
same_ch_err (char32_t ch1, unsigned char err1, char32_t ch2, unsigned char err2)
{
  return ! ((ch1 ^ ch2) | (err1 ^ err2));
}

/* Compare lines S1 of length S1LEN and S2 of length S2LEN (typically
   one line from each input file) according to the command line options.
   Line lengths include the trailing newline.
   For efficiency, this is invoked only when the lines do not match exactly
   but an option like -i might cause us to ignore the difference.
   Return nonzero if the lines differ.
   Line lengths do not include the trailing newline.  */

static bool
lines_differ (char const *s1, idx_t s1len, char const *s2, idx_t s2len)
{
  char const *t1 = s1;
  char const *t2 = s2;
  intmax_t tab = 0, column = 0;

  if (MB_CUR_MAX == 1)
    while (true)
      {
	unsigned char c1 = *t1++;
	unsigned char c2 = *t2++;

	/* Test for exact char equality first, since it's a common case.  */
	if (c1 != c2)
	  {
	    switch (ignore_white_space)
	      {
	      case IGNORE_ALL_SPACE:
		/* For -w, just skip past any white space.  */
		while (isspace (c1) && c1 != '\n') c1 = *t1++;
		while (isspace (c2) && c2 != '\n') c2 = *t2++;
		break;

	      case IGNORE_SPACE_CHANGE:
		/* For -b, advance past any sequence of white space in
		   line 1 and consider it just one space, or nothing at
		   all if it is at the end of the line.  */
		if (isspace (c1))
		  while (c1 != '\n')
		    {
		      c1 = *t1++;
		      if (! isspace (c1))
			{
			  --t1;
			  c1 = ' ';
			  break;
			}
		    }

		/* Likewise for line 2.  */
		if (isspace (c2))
		  while (c2 != '\n')
		    {
		      c2 = *t2++;
		      if (! isspace (c2))
			{
			  --t2;
			  c2 = ' ';
			  break;
			}
		    }

		if (c1 != c2)
		  {
		    /* If we went too far when doing the simple test
		       for equality, go back to the first non-white-space
		       character in both sides and try again.  */
		    if (c2 == ' ' && c1 != '\n'
			&& s1 + 1 < t1
			&& isspace ((unsigned char) t1[-2]))
		      {
			--t1;
			continue;
		      }
		    if (c1 == ' ' && c2 != '\n'
			&& s2 + 1 < t2
			&& isspace ((unsigned char) t2[-2]))
		      {
			--t2;
			continue;
		      }
		  }

		break;

	      case IGNORE_TRAILING_SPACE:
	      case IGNORE_TAB_EXPANSION_AND_TRAILING_SPACE:
		if (isspace (c1) && isspace (c2))
		  {
		    if (c1 != '\n')
		      {
			char const *p = t1;
			unsigned char c;
			while ((c = *p) != '\n' && isspace (c))
			  ++p;
			if (c != '\n')
			  break;
		      }
		    if (c2 != '\n')
		      {
			char const *p = t2;
			unsigned char c;
			while ((c = *p) != '\n' && isspace (c))
			  ++p;
			if (c != '\n')
			  break;
		      }
		    /* Both lines have nothing but whitespace left.  */
		    return false;
		  }
		if (ignore_white_space == IGNORE_TRAILING_SPACE)
		  break;
		FALLTHROUGH;
	      case IGNORE_TAB_EXPANSION:
		if ((c1 == ' ' && c2 == '\t')
		    || (c1 == '\t' && c2 == ' '))
		  {
		    intmax_t tab2 = tab, column2 = column;
		    for (;; c1 = *t1++)
		      {
			if (c1 == '\t' || (c1 == ' ' && column == tabsize - 1))
			  {
			    tab++;
			    column = 0;
			  }
			else if (c1 == ' ')
			  column++;
			else
			  break;
		      }
		    for (;; c2 = *t2++)
		      {
			if (c2 == '\t' || (c2 == ' ' && column2 == tabsize - 1))
			  {
			    tab2++;
			    column2 = 0;
			  }
			else if (c2 == ' ')
			  column2++;
			else
			  break;
		      }
		    if (tab != tab2 || column != column2)
		      return true;
		  }
		break;

	      case IGNORE_NO_WHITE_SPACE:
		break;
	      }

	    if (ignore_case)
	      {
		c1 = tolower (c1);
		c2 = tolower (c2);
	      }

	    if (c1 != c2)
	      break;
	  }

	switch (c1)
	  {
	  case '\n':
	    return false;

	  case '\r':
	    tab = column = 0;
	    break;

	  case '\b':
	    if (0 < column)
	      column--;
	    else if (0 < tab)
	      {
		tab--;
		column = tabsize - 1;
	      }
	    break;

	  case '\0': case '\a': case '\f': case '\v':
	    break;

	  default:
	    column += !! isprint (c1);
	    if (column < tabsize)
	      break;
	    FALLTHROUGH;
	  case '\t':
	    tab++;
	    column = 0;
	    break;
	  }
      }
  else
    {
      char const *lim1 = s1 + s1len;
      char const *lim2 = s2 + s2len;
      char32_t ch1prev = 0;

      while (true)
	{
	  mcel_t g1 = mcel_scan (t1, lim1);
	  mcel_t g2 = mcel_scan (t2, lim2);
	  t1 += g1.len;
	  t2 += g2.len;
	  char32_t ch1 = g1.ch;
	  char32_t ch2 = g2.ch;

	  /* Test for exact equality first, since it's a common case.  */
	  if (! same_ch_err (ch1, g1.err, ch2, g2.err))
	    {
	      switch (ignore_white_space)
		{
		case IGNORE_ALL_SPACE:
		  /* For -w, just skip past any white space.  */
		  while (ch1 != '\n' && c32isspace (ch1))
		    {
		      g1 = mcel_scan (t1, lim1);
		      t1 += g1.len;
		      ch1 = g1.ch;
		    }
		  while (ch2 != '\n' && c32isspace (ch2))
		    {
		      g2 = mcel_scan (t2, lim2);
		      t2 += g2.len;
		      ch2 = g2.ch;
		    }
		  break;

		case IGNORE_SPACE_CHANGE:
		  /* For -b, advance past any sequence of white space in
		     line 1 and consider it just one space, or nothing at
		     all if it is at the end of the line.  */
		  if (c32isspace (ch1))
		    while (ch1 != '\n')
		      {
			g1 = mcel_scan (t1, lim1);
			t1 += g1.len;
			ch1 = g1.ch;
			if (! c32isspace (ch1))
			  {
			    t1 -= g1.len;
			    ch1 = ' ';
			    break;
			  }
		      }

		  /* Likewise for line 2.  */
		  if (c32isspace (ch2))
		    while (ch2 != '\n')
		      {
			g2 = mcel_scan (t2, lim2);
			t2 += g2.len;
			ch2 = g2.ch;
			if (! c32isspace (ch2))
			  {
			    t2 -= g2.len;
			    ch2 = ' ';
			    break;
			  }
		      }

		  if (ch1 != ch2)
		    {
		      /* If we went too far when doing the simple test
			 for equality, go back to the first non-white-space
			 character in both sides and try again.  */
		      if (ch2 == ' ' && ch1 != '\n' && c32isspace (ch1prev))
			{
			  t1 -= g1.len;
			  continue;
			}
		      if (ch1 == ' ' && ch2 != '\n' && c32isspace (ch1prev))
			{
			  t2 -= g2.len;
			  continue;
			}
		    }

		  break;

		case IGNORE_TRAILING_SPACE:
		case IGNORE_TAB_EXPANSION_AND_TRAILING_SPACE:
		  if (c32isspace (ch1) && c32isspace (ch2))
		    {
		      if (ch1 != '\n')
			{
			  char const *p = t1;
			  while (*p != '\n')
			    {
			      mcel_t g = mcel_scan (p, lim1);
			      if (c32isspace (g.ch))
				break;
			      p += g.len;
			    }
			  if (*p != '\n')
			    break;
			}
		      if (ch2 != '\n')
			{
			  char const *p = t2;
			  while (*p != '\n')
			    {
			      mcel_t g = mcel_scan (p, lim2);
			      if (! c32isspace (g.ch))
				break;
			      p += g.len;
			    }
			  if (*p != '\n')
			    break;
			}
		      /* Both lines have nothing but whitespace left.  */
		      return false;
		    }
		  if (ignore_white_space == IGNORE_TRAILING_SPACE)
		    break;
		  FALLTHROUGH;
		case IGNORE_TAB_EXPANSION:
		  if ((ch1 == ' ' && ch2 == '\t')
		      || (ch1 == '\t' && ch2 == ' '))
		    {
		      intmax_t tab2 = tab, column2 = column;

		      while (true)
			{
			  if (ch1 == '\t'
			      || (ch1 == ' ' && column == tabsize - 1))
			    {
			      tab++;
			      column = 0;
			    }
			  else if (ch1 == ' ')
			    column++;
			  else
			    break;

			  g1 = mcel_scan (t1, lim1);
			  t1 += g1.len;
			  ch1 = g1.ch;
			}

		      while (true)
			{
			  if (ch2 == '\t'
			      || (ch2 == ' ' && column2 == tabsize - 1))
			    {
			      tab2++;
			      column2 = 0;
			    }
			  else if (ch2 == ' ')
			    column2++;
			  else
			    break;

			  g2 = mcel_scan (t2, lim2);
			  t2 += g2.len;
			  ch2 = g2.ch;
			}

		      if (tab != tab2 || column != column2)
			return true;
		    }
		  break;

		case IGNORE_NO_WHITE_SPACE:
		  break;
		}

	      if (ignore_case)
		{
		  ch1 = c32tolower (ch1);
		  ch2 = c32tolower (ch2);
		}

	      if (! same_ch_err (ch1, g1.err, ch2, g2.err))
		break;
	    }

	  switch (ch1)
	    {
	    case '\n':
	      return false;

	    case '\r':
	      tab = column = 0;
	      break;

	    case '\b':
	      if (0 < column)
		column--;
	      else if (0 < tab)
		{
		  tab--;
		  column = tabsize - 1;
		}
	      break;

	    case '\a': case '\f': case '\v':
	      break;

	    default:
	      /* Assume that downcasing does not change print width.  */
	      column += g1.err ? 1 : c32width (ch1);
	      if (column < tabsize)
		break;
	      FALLTHROUGH;
	    case '\t':
	      tab++;
	      column = 0;
	      break;
	    }

	  ch1prev = ch1;
	}
    }

  return true;
}

/* Split the file into lines, simultaneously computing the equivalence
   class for each line.  If two lines hash differently, lines_differ
   must return false.  */

static void
find_and_hash_each_line (struct file_data *current)
{
  char const *p = current->prefix_end;

  /* Cache often-used quantities in local variables to help the compiler.  */
  char const **linbuf = current->linbuf;
  lin alloc_lines = current->alloc_lines;
  lin line = 0;
  lin linbuf_base = current->linbuf_base;
  lin *cureqs = xinmalloc (alloc_lines, sizeof *cureqs);
  struct equivclass *eqs = equivs;
  lin eqs_index = equivs_index;
  idx_t eqs_alloc = equivs_alloc;
  char const *suffix_begin = current->suffix_begin;
  char const *bufend = file_buffer (current) + current->buffered;
  bool ig_case = ignore_case;
  enum DIFF_white_space ig_white_space = ignore_white_space;
  bool unibyte = MB_CUR_MAX == 1;
  bool diff_length_compare_anyway =
    (ig_white_space != IGNORE_NO_WHITE_SPACE) | (!unibyte & ig_case);
  bool same_length_diff_contents_compare_anyway =
    diff_length_compare_anyway | ig_case;

  while (p < suffix_begin)
    {
      char const *ip = p;
      hash_value h = 0;

      /* Hash this line until we find a newline.  */
      switch (ig_white_space)
        {
        case IGNORE_ALL_SPACE:
	  if (unibyte)
	    for (unsigned char c; (c = *p) != '\n'; p++)
	      {
		if (! isspace (c))
		  h = hash (h, ig_case ? tolower (c) : c);
	      }
	  else
	    for (mcel_t g; *p != '\n'; p += g.len)
	      {
		g = mcel_scan (p, suffix_begin);
		if (! c32isspace (g.ch))
		  h = hash (h, (ig_case ? c32tolower (g.ch) : g.ch) - g.err);
	      }
          break;

        case IGNORE_SPACE_CHANGE:
	  if (unibyte)
	    for (unsigned char c; (c = *p) != '\n'; p++)
	      {
		if (isspace (c))
		  {
		    do
		      {
			c = *++p;
			if (c == '\n')
			  goto hashing_done;
		      }
		    while (isspace (c));

		    h = hash (h, ' ');
		  }

		/* C is now the first non-space.  */
		h = hash (h, ig_case ? tolower (c) : c);
	      }
	  else
	    for (mcel_t g; *p != '\n'; p += g.len)
	      {
		g = mcel_scan (p, suffix_begin);
		if (c32isspace (g.ch))
		  {
		    do
		      {
			p += g.len;
			if (*p == '\n')
			  goto hashing_done;
			g = mcel_scan (p, suffix_begin);
		      }
		    while (c32isspace (g.ch));

		    h = hash (h, ' ');
		  }

		/* G is now the first non-space.  */
		h = hash (h, (ig_case ? c32tolower (g.ch) : g.ch) - g.err);
	      }
          break;

        case IGNORE_TAB_EXPANSION:
        case IGNORE_TAB_EXPANSION_AND_TRAILING_SPACE:
        case IGNORE_TRAILING_SPACE:
          {
	    intmax_t tab = 0, column = 0;
	    if (unibyte)
	      for (unsigned char c; (c = *p) != '\n'; p++)
		{
		  intmax_t repetitions = 1;

		  if (ig_white_space & IGNORE_TRAILING_SPACE
		      && isspace (c))
		    {
		      char const *p1 = p;
		      unsigned char c1;
		      do
			{
			  c1 = *++p1;
			  if (c1 == '\n')
			    {
			      p = p1;
			      goto hashing_done;
			    }
			}
		      while (isspace (c1));
		    }

		  if (ig_white_space & IGNORE_TAB_EXPANSION)
		    switch (c)
		      {
		      case '\b':
			if (0 < column)
			  column--;
			else if (0 < tab)
			  {
			    tab--;
			    column = tabsize - 1;
			  }
			break;

		      case '\t':
			c = ' ';
			repetitions = tabsize - column % tabsize;
			tab += column / tabsize + 1;
			column = 0;
			break;

		      case '\r':
			tab = column = 0;
			break;

		      case '\0': case '\a': case '\f': case '\v':
			break;

		      default:
			column++;
			break;
		      }

		  if (ig_case)
		    c = tolower (c);

		  do
		    h = hash (h, c);
		  while (--repetitions != 0);
		}
	    else
	      for (mcel_t g; *p != '\n'; p += g.len)
		{
		  intmax_t repetitions = 1;

		  g = mcel_scan (p, suffix_begin);
		  char32_t ch;
		  if (g.err)
		    {
		      ch = -g.err;
		      column++;
		    }
		  else
		    {
		      ch = g.ch;
		      if (ig_white_space & IGNORE_TRAILING_SPACE
			  && c32isspace (ch))
			{
			  char const *p1 = p + g.len;
			  for (mcel_t g1; ; p1 += g1.len)
			    {
			      if (*p1 == '\n')
				{
				  p = p1;
				  goto hashing_done;
				}
			      g1 = mcel_scan (p1, suffix_begin);
			      if (! c32isspace (g1.ch))
				break;
			    }
			}

		      if (ig_white_space & IGNORE_TAB_EXPANSION)
			switch (ch)
			  {
			  case '\b':
			    if (0 < column)
			      column--;
			    else if (0 < tab)
			      {
				tab--;
				column = tabsize - 1;
			      }
			    break;

			  case '\t':
			    ch = ' ';
			    repetitions = tabsize - column % tabsize;
			    tab += column / tabsize + 1;
			    column = 0;
			    break;

			  case '\r':
			    tab = column = 0;
			    break;

			  case '\0': case '\a': case '\f': case '\v':
			    break;

			  default:
			    column += c32width (ch);
			    break;
			  }

		      if (ig_case)
			ch = c32tolower (ch);
		    }

		  do
		    h = hash (h, ch);
		  while (--repetitions != 0);
		}
          }
          break;

        default:
	  if (unibyte)
	    {
	      if (ig_case)
		for (unsigned char c; (c = *p) != '\n'; p++)
		  h = hash (h, tolower (c));
	      else
		for (unsigned char c; (c = *p) != '\n'; p++)
		  h = hash (h, c);
	    }
	  else
	    {
	      if (ig_case)
		for (mcel_t g; *p != '\n'; p += g.len)
		  {
		    g = mcel_scan (p, suffix_begin);
		    h = hash (h, c32tolower (g.ch) - g.err);
		  }
	      else
		for (mcel_t g; *p != '\n'; p += g.len)
		  {
		    g = mcel_scan (p, suffix_begin);
		    h = hash (h, g.ch - g.err);
		  }
	    }
          break;
        }

   hashing_done:;

      lin *bucket = &buckets[h % nbuckets];

      /* Advance past the line's trailing newline.  */
      p++;
      idx_t length = p - ip;

      if (p == bufend
          && current->missing_newline
          && robust_output_style (output_style))
        {
          /* The last line is incomplete and we do not silently
             complete lines.  If the line cannot compare equal to any
             complete line, put it into buckets[-1] so that it can
             compare equal only to the other file's incomplete line
             (if one exists).  */
          if (ig_white_space < IGNORE_TRAILING_SPACE)
            bucket = &buckets[-1];
        }

      lin i;
      for (i = *bucket;  ;  i = eqs[i].next)
        if (!i)
          {
            /* Create a new equivalence class in this bucket.  */
            i = eqs_index++;
            if (i == eqs_alloc)
	      eqs = xpalloc (eqs, &eqs_alloc, 1, -1, sizeof *eqs);
            eqs[i].next = *bucket;
            eqs[i].hash = h;
            eqs[i].line = ip;
            eqs[i].length = length;
            *bucket = i;
            break;
          }
        else if (eqs[i].hash == h)
          {
            char const *eqline = eqs[i].line;
	    idx_t eqlinelen = eqs[i].length;

            /* Reuse existing class if lines_differ reports the lines
               equal.  */
	    if (eqlinelen == length)
              {
                /* Reuse existing equivalence class if the lines are identical.
                   This detects the common case of exact identity
                   faster than lines_differ would.  */
		if (memcmp (eqline, ip, length - 1) == 0)
                  break;
                if (!same_length_diff_contents_compare_anyway)
                  continue;
              }
            else if (!diff_length_compare_anyway)
              continue;

	    if (! lines_differ (eqline, eqlinelen, ip, length))
              break;
          }

      /* Maybe increase the size of the line table.  */
      if (line == alloc_lines)
        {
	  /* Grow (alloc_lines - linbuf_base) by adding to alloc_lines.  */
	  idx_t n = alloc_lines - linbuf_base;
          linbuf += linbuf_base;
	  linbuf = xpalloc (linbuf, &n, 1, -1, sizeof *linbuf);
          linbuf -= linbuf_base;
	  alloc_lines = linbuf_base + n;
          cureqs = xirealloc (cureqs, alloc_lines * sizeof *cureqs);
        }
      linbuf[line] = ip;
      cureqs[line] = i;
      ++line;
    }

  current->buffered_lines = line;

  for (lin i = 0;  ;  i++)
    {
      /* Record the line start for lines in the suffix that we care about.
         Record one more line start than lines,
         so that we can compute the length of any buffered line.  */
      if (line == alloc_lines)
        {
	  /* Grow (alloc_lines - linbuf_base) by adding to alloc_lines.  */
	  idx_t n = alloc_lines - linbuf_base;
	  linbuf += linbuf_base;
	  linbuf = xpalloc (linbuf, &n, 1, -1, sizeof *linbuf);
	  linbuf -= linbuf_base;
	  alloc_lines = linbuf_base + n;
        }
      linbuf[line] = p;

      if (p == bufend)
        {
          /* If the last line is incomplete and we do not silently
             complete lines, don't count its appended newline.  */
          if (current->missing_newline && robust_output_style (output_style))
            linbuf[line]--;
          break;
        }

      if (context <= i && no_diff_means_no_output)
        break;

      line++;

      while (*p++ != '\n')
        continue;
    }

  /* Done with cache in local variables.  */
  current->linbuf = linbuf;
  current->valid_lines = line;
  current->alloc_lines = alloc_lines;
  current->equivs = cureqs;
  equivs = eqs;
  equivs_alloc = eqs_alloc;
  equivs_index = eqs_index;
}

/* Prepare the text.  Make sure the text end is initialized.
   Make sure text ends in a newline,
   but remember that we had to add one.
   Strip trailing CRs, if that was requested.  */

static void
prepare_text (struct file_data *current)
{
  idx_t buffered = current->buffered;
  char *p = file_buffer (current);
  if (!p)
    return;

  if (strip_trailing_cr)
    {
      char *srclim = p + buffered;
      *srclim = '\r';
      char *dst = rawmemchr (p, '\r');

      for (char const *src = dst; src != srclim; src++)
        {
          src += *src == '\r' && src[1] == '\n';
          *dst++ = *src;
        }

      buffered -= srclim - dst;
    }

  if (buffered != 0 && p[buffered - 1] != '\n')
    {
      p[buffered++] = '\n';
      current->missing_newline = true;
    }

  /* Don't use uninitialized storage when planting or using sentinels.  */
  memset (p + buffered, 0, sizeof (word));

  current->buffered = buffered;
}

/* We have found N lines in a buffer of size S; guess the
   proportionate number of lines that will be found in a buffer of
   size T.  However, do not guess a number of lines so large that the
   resulting line table might cause overflow in size calculations.  */
static lin
guess_lines (lin n, idx_t s, idx_t t)
{
  idx_t guessed_bytes_per_line = n < 10 ? 32 : s / (n - 1);
  lin guessed_lines = MAX (1, t / guessed_bytes_per_line);
  return MIN (guessed_lines, LIN_MAX / (2 * sizeof (char *) + 1) - 5) + 5;
}

/* Given a vector of two file_data objects, find the identical
   prefixes and suffixes of each object.  */

static void
find_identical_ends (struct file_data filevec[])
{
  slurp (&filevec[0]);
  prepare_text (&filevec[0]);
  if (filevec[0].desc != filevec[1].desc)
    {
      slurp (&filevec[1]);
      prepare_text (&filevec[1]);
    }
  else
    {
      filevec[1].buffer = filevec[0].buffer;
      filevec[1].bufsize = filevec[0].bufsize;
      filevec[1].buffered = filevec[0].buffered;
      filevec[1].missing_newline = filevec[0].missing_newline;
    }

  /* Find identical prefix.  */

  word *w0 = filevec[0].buffer;
  word *w1 = filevec[1].buffer;
  char *buffer0 = (char *) w0;
  char *buffer1 = (char *) w1;
  char *p0 = buffer0;
  char *p1 = buffer1;
  idx_t n0 = filevec[0].buffered;
  idx_t n1 = filevec[1].buffered;

  if (p0 == p1)
    /* The buffers are the same; sentinels won't work.  */
    p0 = p1 += n1;
  else
    {
      /* Insert end sentinels, in this case characters that are guaranteed
         to make the equality test false, and thus terminate the loop.  */

      if (n0 < n1)
        p0[n0] = ~p1[n0];
      else
        p1[n1] = ~p0[n1];

      /* Loop until first mismatch, or to the sentinel characters.  */

      /* Compare a word at a time for speed.  */
      while (*w0 == *w1)
        w0++, w1++;

      /* Do the last few bytes of comparison a byte at a time.  */
      p0 = (char *) w0;
      p1 = (char *) w1;
      while (*p0 == *p1)
        p0++, p1++;

      /* Don't mistakenly count missing newline as part of prefix.  */
      if (robust_output_style (output_style)
          && ((buffer0 + n0 - filevec[0].missing_newline < p0)
              !=
              (buffer1 + n1 - filevec[1].missing_newline < p1)))
        p0--, p1--;
    }

  /* Now P0 and P1 point at the first nonmatching characters.  */

  /* Skip back to last line-beginning in the prefix,
     and then discard up to HORIZON_LINES lines from the prefix.  */
  lin hor = horizon_lines;
  while (p0 != buffer0 && (p0[-1] != '\n' || hor--))
    p0--, p1--;

  /* Record the prefix.  */
  filevec[0].prefix_end = p0;
  filevec[1].prefix_end = p1;

  /* Find identical suffix.  */

  /* P0 and P1 point beyond the last chars not yet compared.  */
  p0 = buffer0 + n0;
  p1 = buffer1 + n1;

  if (! robust_output_style (output_style)
      || filevec[0].missing_newline == filevec[1].missing_newline)
    {
      char const *end0 = p0;	/* Addr of last char in file 0.  */

      /* Get value of P0 at which we should stop scanning backward:
         this is when either P0 or P1 points just past the last char
         of the identical prefix.  */
      char const *beg0 = filevec[0].prefix_end + (n0 < n1 ? 0 : n0 - n1);

      /* Scan back until chars don't match or we reach that point.  */
      while (p0 != beg0)
        if (*--p0 != *--p1)
          {
            /* Point at the first char of the matching suffix.  */
            ++p0, ++p1;
            beg0 = p0;
            break;
          }

      /* Are we at a line-beginning in both files?  If not, add the rest of
         this line to the main body.  Discard up to HORIZON_LINES lines from
         the identical suffix.  Also, discard one extra line,
         because shift_boundaries may need it.  */
      lin i = horizon_lines + !((buffer0 == p0 || p0[-1] == '\n')
				&&
				(buffer1 == p1 || p1[-1] == '\n'));
      while (i-- && p0 != end0)
        while (*p0++ != '\n')
          continue;

      p1 += p0 - beg0;
    }

  /* Record the suffix.  */
  filevec[0].suffix_begin = p0;
  filevec[1].suffix_begin = p1;

  /* Calculate number of lines of prefix to save.

     prefix_count == 0 means save the whole prefix;
     we need this for options like -D that output the whole file,
     or for enormous contexts (to avoid worrying about arithmetic overflow).
     We also need it for options like -F that output some preceding line;
     at least we will need to find the last few lines,
     but since we don't know how many, it's easiest to find them all.

     Otherwise, prefix_count != 0.  Save just prefix_count lines at start
     of the line buffer; they'll be moved to the proper location later.
     Handle 1 more line than the context says (because we count 1 too many),
     rounded up to the next power of 2 to speed index computation.  */

  lin alloc_lines0, prefix_count, middle_guess;
  if (no_diff_means_no_output && ! function_regexp.fastmap
      && context < LIN_MAX / 4 && context < n0)
    {
      middle_guess = guess_lines (0, 0, p0 - filevec[0].prefix_end);
      lin suffix_guess = guess_lines (0, 0, buffer0 + n0 - p0);
      prefix_count = (lin) 1 << (floor_log2 (context) + 1);
      alloc_lines0 = (prefix_count + middle_guess
                      + MIN (context, suffix_guess));
    }
  else
    {
      prefix_count = 0;
      alloc_lines0 = guess_lines (0, 0, n0);
    }

  lin prefix_mask = prefix_count - 1;
  lin lines = 0;
  char const **linbuf0 = xinmalloc (alloc_lines0, sizeof *linbuf0);
  bool prefix_needed = ! (no_diff_means_no_output
			  && filevec[0].prefix_end == p0
			  && filevec[1].prefix_end == p1);
  p0 = buffer0;

  /* If the prefix is needed, find the prefix lines.  */
  if (prefix_needed)
    {
      char const *end0 = filevec[0].prefix_end;
      while (p0 != end0)
        {
          lin l = lines++ & prefix_mask;
          if (l == alloc_lines0)
	    linbuf0 = xpalloc (linbuf0, &alloc_lines0, 1, -1, sizeof *linbuf0);
          linbuf0[l] = p0;
          while (*p0++ != '\n')
            continue;
        }
    }
  lin buffered_prefix = prefix_count && context < lines ? context : lines;

  /* Allocate line buffer 1.  */

  middle_guess = guess_lines (lines, p0 - buffer0, p1 - filevec[1].prefix_end);
  lin suffix_guess = guess_lines (lines, p0 - buffer0, buffer1 + n1 - p1);
  lin alloc_lines1;
  if (ckd_add (&alloc_lines1, buffered_prefix,
               middle_guess + MIN (context, suffix_guess)))
    xalloc_die ();
  char const **linbuf1 = xnmalloc (alloc_lines1, sizeof *linbuf1);

  if (buffered_prefix != lines)
    {
      /* Rotate prefix lines to proper location.  */
      for (lin i = 0;  i < buffered_prefix;  i++)
        linbuf1[i] = linbuf0[(lines - context + i) & prefix_mask];
      for (lin i = 0;  i < buffered_prefix;  i++)
        linbuf0[i] = linbuf1[i];
    }

  /* Initialize line buffer 1 from line buffer 0.  */
  for (lin i = 0; i < buffered_prefix; i++)
    linbuf1[i] = linbuf0[i] - buffer0 + buffer1;

  /* Record the line buffer, adjusted so that
     linbuf[0] points at the first differing line.  */
  filevec[0].linbuf = linbuf0 + buffered_prefix;
  filevec[1].linbuf = linbuf1 + buffered_prefix;
  filevec[0].linbuf_base = filevec[1].linbuf_base = - buffered_prefix;
  filevec[0].alloc_lines = alloc_lines0 - buffered_prefix;
  filevec[1].alloc_lines = alloc_lines1 - buffered_prefix;
  filevec[0].prefix_lines = filevec[1].prefix_lines = lines;
}

/* If 1 < k, then (2**k - prime_offset[k]) is the largest prime less
   than 2**k.  This table is derived from Chris K. Caldwell's list
   <http://www.utm.edu/research/primes/lists/2small/>.  */

static unsigned char const prime_offset[] =
{
  0, 0, 1, 1, 3, 1, 3, 1, 5, 3, 3, 9, 3, 1, 3, 19, 15, 1, 5, 1, 3, 9, 3,
  15, 3, 39, 5, 39, 57, 3, 35, 1, 5, 9, 41, 31, 5, 25, 45, 7, 87, 21,
  11, 57, 17, 55, 21, 115, 59, 81, 27, 129, 47, 111, 33, 55, 5, 13, 27,
  55, 93, 1, 57, 25
};

/* Verify that this host's idx_t is not too wide for the above table.  */

static_assert (PTRDIFF_WIDTH - 1 <= sizeof prime_offset);

/* Given a vector of two file_data objects, read the file associated
   with each one, and build the table of equivalence classes.
   Return nonzero if either file appears to be a binary file.
   If PRETEND_BINARY is nonzero, pretend they are binary regardless.  */

bool
read_files (struct file_data filevec[], bool pretend_binary)
{
  bool skip_test = text | pretend_binary;
  bool appears_binary = pretend_binary | sip (&filevec[0], skip_test);

  if (filevec[0].desc != filevec[1].desc)
    appears_binary |= sip (&filevec[1], skip_test | appears_binary);
  else
    {
      filevec[1].buffer = filevec[0].buffer;
      filevec[1].bufsize = filevec[0].bufsize;
      filevec[1].buffered = filevec[0].buffered;
    }
  if (appears_binary)
    {
      set_binary_mode (filevec[0].desc, O_BINARY);
      set_binary_mode (filevec[1].desc, O_BINARY);
      return true;
    }

  find_identical_ends (filevec);

  equivs_alloc = filevec[0].alloc_lines + filevec[1].alloc_lines + 1;
  equivs = xnmalloc (equivs_alloc, sizeof *equivs);
  /* Equivalence class 0 is permanently safe for lines that were not
     hashed.  Real equivalence classes start at 1.  */
  equivs_index = 1;

  /* Allocate (one plus) a prime number of hash buckets.  Use a prime
     number between 1/3 and 2/3 of the value of equiv_allocs,
     approximately.  */
  int p = equivs_alloc <= 256 * 3 ? 9 : floor_log2 (equivs_alloc / 3) + 1;
  nbuckets = ((idx_t) 1 << p) - prime_offset[p];
  buckets = xicalloc (nbuckets + 1, sizeof *buckets);
  buckets++;

  for (int i = 0; i < 2; i++)
    find_and_hash_each_line (&filevec[i]);

  filevec[0].equiv_max = filevec[1].equiv_max = equivs_index;

  free (equivs);
  free (buckets - 1);

  return false;
}
