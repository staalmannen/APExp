/* inputting files to be patched */

/* Copyright 1991-2025 Free Software Foundation, Inc.
   Copyright 1986, 1988 Larry Wall

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

#include <quotearg.h>
#include <util.h>
#include <xalloc.h>

#include <inp.h>
#include <safe.h>

/* Input-file-with-indexable-lines abstract type */

static char *i_buffer;			/* buffer of input file lines */
static char const **i_ptr;		/* pointers to lines in buffer */
idx_t input_lines;			/* how long is input file in lines */

static void report_revision (bool);

/* New patch--prepare to edit another file. */

void
re_input (void)
{
      if (i_buffer)
	{
	  free (i_buffer);
	  i_buffer = 0;
	  free (i_ptr);
	}
}

/* Report whether a desired revision was found.  */

static void
report_revision (bool found_revision)
{
  char const *rev = quotearg (revision);

  if (found_revision)
    {
      if (verbosity == VERBOSE)
	say ("Good.  This file appears to be the %s version.\n", rev);
    }
  else if (force)
    {
      if (verbosity != SILENT)
	say ("Warning: this file doesn't appear to be the %s version -- patching anyway.\n",
	     rev);
    }
  else if (batch)
    fatal ("This file doesn't appear to be the %s version -- aborting.",
	   rev);
  else
    {
      if (*ask (("This file doesn't appear to be the %s version"
		 " -- patch anyway? [n] "),
		rev)
	  != 'y')
	fatal ("aborted");
    }
}

bool
get_input_file (char *filename, char const *outname, mode_t file_type)
{
    bool elsewhere = strcmp (filename, outname) != 0;
    char const *cs;
    char *diffbuf;
    char *getbuf;

    if (inerrno == -1)
      inerrno = stat_file (filename, &instat);

    /* Perhaps look for RCS or SCCS versions.  */
    if (S_ISREG (file_type)
	&& patch_get
	&& invc != 0
	&& (inerrno
	    || (! elsewhere
		&& (/* No one can write to it.  */
		    (instat.st_mode & (S_IWUSR|S_IWGRP|S_IWOTH)) == 0
		    /* Only the owner (who's not me) can write to it.  */
		    || ((instat.st_mode & (S_IWGRP|S_IWOTH)) == 0
			&& instat.st_uid != geteuid ()))))
	&& (invc = !! (cs = (version_controller
			     (filename, elsewhere,
			      inerrno ? (struct stat *) 0 : &instat,
			      &getbuf, &diffbuf))))) {

	    if (!inerrno) {
		if (!elsewhere
		    && (instat.st_mode & (S_IWUSR|S_IWGRP|S_IWOTH)) != 0)
		    /* Somebody can write to it.  */
		  fatal ("File %s seems to be locked by somebody else under %s",
			 quotearg (filename), cs);
		if (diffbuf)
		  {
		    /* It might be checked out unlocked.  See if it's safe to
		       check out the default version locked.  */

		    if (verbosity == VERBOSE)
		      say ("Comparing file %s to default %s version...\n",
			   quotearg (filename), cs);

		    if (systemic (diffbuf) != 0)
		      {
			say ("warning: Patching file %s, which does not match default %s version\n",
			     quotearg (filename), cs);
			cs = 0;
		      }
		  }
		if (dry_run)
		  cs = 0;
	    }

	    if (cs && version_get (filename, cs, ! inerrno, elsewhere, getbuf,
				   &instat))
	      inerrno = 0;

	    free (getbuf);
	    free (diffbuf);
      }

    if (inerrno)
      {
	instat.st_mode = S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH;
	instat.st_size = 0;
      }
    else if (! ((S_ISREG (file_type) || S_ISLNK (file_type))
	        && (file_type & S_IFMT) == (instat.st_mode & S_IFMT)))
      {
	say ("File %s is not a %s -- refusing to patch\n",
	     quotearg (filename),
	     S_ISLNK (file_type) ? "symbolic link" : "regular file");
	return false;
      }
    return true;
}


/* Read input and build its line index.  */

void
scan_input (char *filename, mode_t file_type, int ifd)
{
  /* Fail if the file size doesn't fit,
     or if storage isn't available.  */
  idx_t size;
  if (ckd_add (&size, instat.st_size, 0))
    xalloc_die ();
  char *buffer = ximalloc (size);

  /* Read the input file, but don't bother reading it if it's empty.
     When creating files, the files do not actually exist.  */
  if (size)
    {
      if (S_ISREG (file_type))
        {
	  idx_t buffered = 0;

	  while (size - buffered != 0)
	    {
	      ssize_t n = Read (ifd, buffer + buffered, size - buffered);
	      if (n == 0)
		{
		  /* Some non-POSIX hosts exaggerate st_size in text mode;
		     or the file may have shrunk!  */
		  size = buffered;
		  break;
		}
	      buffered += n;
	    }
	}
      else
	{
	  ssize_t n = safe_readlink (filename, buffer, size);
	  if (n < 0)
	    pfatal ("can't read %s %s", "symbolic link", quotearg (filename));
	  size = n;
	}
  }

  /* Scan the buffer and build array of pointers to lines.  */
  char const *lim = buffer + size;
  idx_t iline = 3; /* 1 unused, 1 for SOF,
		      1 for EOF if last line is incomplete.  */
  for (char const *s = buffer;  (s = memchr (s, '\n', lim - s));  s++)
    iline++;
  char const **ptr = xireallocarray (nullptr, iline, sizeof *ptr);
  iline = 0;
  for (char const *s = buffer; ; s++)
    {
      ptr[++iline] = s;
      if (! (s = memchr (s, '\n', lim - s)))
	break;
    }
  if (size && lim[-1] != '\n')
    ptr[++iline] = lim;
  input_lines = iline - 1;

  if (revision)
    {
      char const *rev = revision;
      char rev0 = rev[0];
      bool found_revision = false;
      idx_t revlen = strlen (rev);

      if (revlen <= size)
	{
	  char const *limrev = lim - revlen;

	  for (char const *s = buffer; (s = memchr (s, rev0, limrev - s)); s++)
	    if (memcmp (s, rev, revlen) == 0
		&& (s == buffer || c_isspace (s[-1]))
		&& (s + 1 == limrev || c_isspace (s[revlen])))
	      {
		found_revision = true;
		break;
	      }
	}

      report_revision (found_revision);
    }

  i_buffer = buffer;
  i_ptr = ptr;
}

/* Fetch a line from the input file.  */

struct iline
ifetch (idx_t line)
{
  if (! (1 <= line && line <= input_lines))
    return (struct iline) { .ptr = "", .size = 0 };

  char const *ptr = i_ptr[line];
  return (struct iline) { .ptr = ptr, .size = i_ptr[line + 1] - ptr };
}
