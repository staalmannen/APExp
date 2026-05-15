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

#include <common.h>
#include <basename-lgpl.h>
#include <filename.h>
#include <inp.h>
#include <quotearg.h>
#include <util.h>
#include <xalloc.h>
#include <pch.h>
#if HAVE_SETMODE_DOS
# include <io.h>
#endif
#include <safe.h>

#define INITHUNKMAX 125			/* initial dynamic allocation size */

/* Patch (diff listing) abstract type. */

static FILE *pfp;			/* patch file pointer */
static char p_says_nonexistent[2];	/* [0] for old file, [1] for new:
		0 for existent and nonempty,
		1 for existent and probably (but not necessarily) empty,
		2 for nonexistent */
static idx_t p_rfc934_nesting;		/* RFC 934 nesting level */
static char *p_name[3];			/* filenames in patch headers */
static char const *invalid_names[2];
static bool p_copy[2];			/* Does this patch create a copy? */
static bool p_rename[2];		/* Does this patch rename a file? */
struct timespec p_timestamp[2];		/* timestamps in patch headers */
static char *p_timestr[2];		/* timestamps as strings */
static char *p_sha1[2];			/* SHA1 checksums */
static mode_t p_mode[2];		/* file modes */
static off_t p_filesize;		/* size of the patch file */
static idx_t p_first;			/* 1st line number */
static idx_t p_newfirst;		/* 1st line number of replacement */
static idx_t p_ptrn_lines;		/* # lines in pattern */
static idx_t p_repl_lines;		/* # lines in replacement text */
static ptrdiff_t p_end = -1;		/* last line in hunk */
static idx_t p_max;			/* max allowed value of p_end */
static idx_t p_prefix_context;		/* # of prefix context lines */
static idx_t p_suffix_context;		/* # of suffix context lines */
static idx_t p_input_line;		/* current line # from patch file */
static char **p_line;			/* the text of the hunk */
static idx_t *p_len;			/* line length including \n if any */
static char *p_Char;			/* +, -, and ! */
static idx_t hunkmax = INITHUNKMAX;	/* size of above arrays */
static idx_t p_indent;			/* indent to patch */
static bool p_strip_trailing_cr;	/* true if stripping trailing \r */
static bool p_pass_comments_through;	/* true if not ignoring # lines */
static off_t p_base;			/* where to intuit this time */
static idx_t p_bline;			/* line # of p_base */
static off_t p_start;			/* where intuit found a patch */
static idx_t p_sline;			/* and the line number for it */
static idx_t p_hunk_beg;		/* line number of current hunk */
static ptrdiff_t p_efake = -1;		/* end of faked up lines--don't free */
static ptrdiff_t p_bfake = -1;		/* beg of faked up lines */
static char *p_c_function;		/* the C function a hunk is in */
static bool p_git_diff;			/* true if this is a git style diff */

static enum diff intuit_diff_type (bool, mode_t *);
static enum nametype best_name (char * const *, int const *);
static idx_t prefix_components (char *, bool);
static idx_t pget_line (idx_t, idx_t, bool, bool, bool);
static idx_t get_line (bool);
static bool incomplete_line (void);
static void grow_hunkmax (void);
static void malformed (void);
static void next_intuit_at (off_t, idx_t);
static void skip_to (off_t, idx_t);
static char get_ed_command_letter (char const *);

static char initial_patchbuf[IO_BUFSIZE];
char *patchbuf = initial_patchbuf;
idx_t patchbufsize = IO_BUFSIZE;

void
grow_patchbuf (void)
{
  bool onheap = patchbufsize != IO_BUFSIZE;
  patchbuf = xpalloc (onheap ? patchbuf : nullptr, &patchbufsize, 1, -1, 1);
  if (!onheap)
    memcpy (patchbuf, initial_patchbuf, IO_BUFSIZE);
}

/* Prepare to look for the next patch in the patch file. */

void
re_patch (void)
{
    p_first = 0;
    p_newfirst = 0;
    p_ptrn_lines = 0;
    p_repl_lines = 0;
    p_end = -1;
    p_max = 0;
    p_indent = 0;
    p_strip_trailing_cr = false;
}

/* Open the patch file at the beginning of time. */

void
open_patch_file (char const *filename)
{
    off_t file_pos = 0;
    off_t pos;
    struct stat st;

    if (!filename || !*filename || strEQ (filename, "-"))
      pfp = stdin;
    else
      {
	pfp = fopen (filename, binary_transput ? "rb" : "r");
	if (!pfp)
	  pfatal ("Can't open patch file %s", quotearg (filename));
      }
    int pfd = fileno (pfp);
#if HAVE_SETMODE_DOS
    if (binary_transput)
      {
	if (isatty (pfd))
	  fatal ("cannot read binary data from tty on this platform");
	setmode (pfd, O_BINARY);
      }
#endif
    if (fstat (pfd, &st) < 0)
      pfatal ("fstat");
    if (S_ISREG (st.st_mode) && 0 <= (pos = ftello (pfp)))
      file_pos = pos;
    else
      {
	idx_t charsread;
	int fd;
	FILE *read_pfp = pfp;
	fd = make_tempfile (&tmppat, 'p', nullptr, O_RDWR | O_BINARY, 0);
	if (fd < 0)
	  pfatal ("Can't create temporary file %s", tmppat.name);
	pfp = fdopen (fd, "w+b");
	if (! pfp)
	  pfatal ("Can't open stream for file %s", quotearg (tmppat.name));
	for (st.st_size = 0;
	     (charsread = Read (pfd, patchbuf, patchbufsize)) != 0;
	     st.st_size += charsread)
	  Fwrite (patchbuf, 1, charsread, pfp);
	if (fclose (read_pfp) < 0)
	  read_fatal ();
	Fflush (pfp);
	Fseeko (pfp, 0, SEEK_SET);
      }
    p_filesize = st.st_size;
    next_intuit_at (file_pos, 1);
}

/* Make sure our dynamically realloced tables are malloced to begin with. */

static void
set_hunkmax (void)
{
  p_line = xireallocarray (p_line, hunkmax, sizeof *p_line);
  p_len = xireallocarray (p_len, hunkmax, sizeof *p_len);
  p_Char = xireallocarray (p_Char, hunkmax, sizeof *p_Char);
}

/* Enlarge the arrays containing the current hunk of patch. */

static void
grow_hunkmax (void)
{
  assert (p_line && p_len && p_Char);
  p_line = xpalloc (p_line, &hunkmax, 1, -1, sizeof *p_line);
  p_len = xireallocarray (p_len, hunkmax, sizeof *p_len);
  p_Char = xireallocarray (p_Char, hunkmax, sizeof *p_Char);
}

static bool
maybe_reverse (char const *name, bool nonexistent, bool is_empty)
{
  bool looks_reversed = ((! is_empty)
			 < p_says_nonexistent[reverse_flag ^ is_empty]);

  /* Allow to create and delete empty files when we know that they are empty:
     in the "diff --git" format, we know that from the index header.  */
  if (is_empty
      && p_says_nonexistent[reverse_flag ^ nonexistent] == 1
      && p_says_nonexistent[! reverse_flag ^ nonexistent] == 2)
    return false;

  if (looks_reversed)
    reverse_flag ^=
      ok_to_reverse ("The next patch%s would %s the file %s,\nwhich %s!",
		     reverse_flag ? ", when reversed," : "",
		     (nonexistent ? "delete"
		      : is_empty ? "empty out"
		      : "create"),
		     quotearg (name),
		     (nonexistent ? "does not exist"
		      : is_empty ? "is already empty"
		      : "already exists"));
  return looks_reversed;
}

/* True if the remainder of the patch file contains a diff of some sort. */

bool
there_is_another_patch (bool need_header, mode_t *file_type)
{
    if (p_base != 0 && p_base >= p_filesize) {
	if (verbosity == VERBOSE)
	    say ("done\n");
	return false;
    }
    if (verbosity == VERBOSE)
	say ("Hmm...");
    diff_type = intuit_diff_type (need_header, file_type);
    if (diff_type == NO_DIFF) {
	if (verbosity == VERBOSE)
	  say (p_base
	       ? "  Ignoring the trailing garbage.\ndone\n"
	       : "  I can't seem to find a patch in there anywhere.\n");
	if (! p_base && p_filesize)
	  fatal ("Only garbage was found in the patch input.");
	return false;
    }
    if (skip_rest_of_patch)
      {
	Fseeko (pfp, p_start, SEEK_SET);
	p_input_line = p_sline - 1;
	return true;
      }
    if (verbosity == VERBOSE)
	say ("  %sooks like %s to me...\n",
	    (p_base == 0 ? "L" : "The next patch l"),
	    diff_type == UNI_DIFF ? "a unified diff" :
	    diff_type == CONTEXT_DIFF ? "a context diff" :
	    diff_type == NEW_CONTEXT_DIFF ? "a new-style context diff" :
	    diff_type == NORMAL_DIFF ? "a normal diff" :
	    diff_type == GIT_BINARY_DIFF ? "a git binary diff" :
	    "an ed script" );

    if (no_strip_trailing_cr)
      p_strip_trailing_cr = false;

    if (verbosity != SILENT)
      {
	if (p_indent)
	  say ("(Patch is indented %td space%s.)\n",
	       p_indent, &"s"[p_indent == 1]);
	if (p_strip_trailing_cr)
	  say ("(Stripping trailing CRs from patch; use --binary to disable.)\n");
	if (! inname)
	  {
	    say ("can't find file to patch at input line %td\n", p_sline);
	    if (diff_type != ED_DIFF && diff_type != NORMAL_DIFF)
	      say (strippath < 0
		   ? "Perhaps you should have used the -p or --strip option?\n"
		   : "Perhaps you used the wrong -p or --strip option?\n");
	  }
      }

    skip_to(p_start,p_sline);
    while (!inname) {
	if (force | batch) {
	    say ("No file to patch.  Skipping patch.\n");
	    skip_rest_of_patch = true;
	    return true;
	}
	char *answer = ask ("File to patch: ");
	idx_t answerlen = strlen (answer);
	if (1 < answerlen && answer[answerlen - 1] == '\n')
	  {
	    inname = ximemdup0 (answer, answerlen - 1);
	    inerrno = stat_file (inname, &instat);
	    if (inerrno)
	      {
		Fputs (inname, stderr);
		putline (stderr, ": ", strerror (inerrno), nullptr);
		Fflush (stderr);
		free (inname);
		inname = nullptr;
	      }
	    else
	      invc = -1;
	  }
	if (!inname) {
	    if (*ask ("Skip this patch? [y] ") != 'n') {
		if (verbosity != SILENT)
		    say ("Skipping patch.\n");
		skip_rest_of_patch = true;
		return true;
	    }
	}
    }
    return true;
}

/* Scan a Git-style mode from STR, and return the corresponding mode_t
   suitable for use on this platform.  Return 0 if the scan fails.  */

static mode_t ATTRIBUTE_PURE
fetchmode (char const *str)
{
   const char *s;
   int mode;

   while (c_isspace (*str))
     str++;

   for (s = str, mode = 0; s - str < 6; s++)
     {
       if (! ('0' <= *s && *s <= '7'))
	 return 0;
       mode = (mode << 3) + (*s - '0');
     }
   if (*s == '\r')
     s++;
   if (*s != '\n')
     return 0;

   /* Check the file type.  Also, convert Git numbering for file types
      to this platform's numbering; ordinarily they are the same, but
      POSIX does not require this.  */
   mode_t file_type;
   switch (mode >> 9)
     {
     case 0100: file_type = S_IFREG; break;
#ifdef S_IFLNK
     case 0120: file_type = S_IFLNK; break;
#endif
     /* 'patch' can handle only files and symlinks, so fail with
	other Git file types such as submodules.  */
     default: return 0;
     }

   /* 'patch' can deal only with regular files and symlinks.  Because it
      uses zero to indicate unknown or missing file types, S_IFLNK and
      S_IFREG must be nonzero.  This is true on all known platforms
      although POSIX does not require it; check here to be sure.  */
   static_assert (S_IFLNK);
   static_assert (S_IFREG);

   mode_t m = file_type | (mode & S_IRWXUGO);
   if (!m)
     {
       /* This can happen only on perverse platforms where, e.g.,
	  S_IFREG == 0.  */
       fatal ("mode %.6s treated as missing at line %td: %s",
	      str, p_input_line, patchbuf);
     }

    /* NOTE: The "diff --git" format always sets the file mode permission
       bits of symlinks to 0.  (On Linux, symlinks actually always have
       0777 permissions, so this is not even consistent.)  */

   return m;
}

static char *
get_sha1 (char const *start, char const *end)
{
  return ximemdup0 (start, end - start);
}

static char ATTRIBUTE_PURE
sha1_says_nonexistent (char const *sha1)
{
  char const *empty_sha1 = "e69de29bb2d1d6434b8b29ae775ad8c2e48c5391";
  char const *s;

  /* Nonexistent files have an all-zero checksum.  */
  for (s = sha1; *s; s++)
    if (*s != '0')
      break;
  if (! *s)
    return 2;

  /* Empty files have empty_sha1 as their checksum.  */
  for (s = sha1; *s; s++, empty_sha1++)
    if (*s != *empty_sha1)
      break;
  return ! *s;
}

static char const * ATTRIBUTE_PURE
skip_hex_digits (char const *str)
{
  char const *s;

  for (s = str; (*s >= '0' && *s <= '9') || (*s >= 'a' && *s <= 'f'); s++)
    /* do nothing */ ;
  return s == str ? nullptr : s;
}

static char const * ATTRIBUTE_PURE
skip_spaces (char const *str)
{
  while (c_isspace (*str))
    str++;
  return str;
}

static bool
name_is_valid (char const *name)
{
  int i;
  bool is_valid = true;

  for (i = 0; i < ARRAY_SIZE (invalid_names); i++)
    {
      if (! invalid_names[i])
	break;
      if (! strcmp (invalid_names[i], name))
	return false;
    }

  is_valid = filename_is_safe (name);

  /* Allow any filename if we are in the filesystem root.  */
  if (! is_valid && cwd_is_root (name))
    is_valid = true;

  if (! is_valid)
    {
      say ("Ignoring potentially dangerous file name %s\n", quotearg (name));
      if (i < ARRAY_SIZE (invalid_names))
	invalid_names[i] = name;
    }
  return is_valid;
}

/* Determine what kind of diff is in the remaining part of the patch file. */

static enum diff
intuit_diff_type (bool need_header, mode_t *p_file_type)
{
    off_t this_line = 0;
    off_t first_command_line = -1;
    char first_ed_command_letter = 0;
    idx_t fcl_line = 0; /* Pacify 'gcc -W'.  */
    bool this_is_a_command = false;
    bool stars_this_line = false;
    bool extended_headers = false;
    enum nametype i;
    struct stat st[3];
    int stat_errno[3];
    signed char version_controlled[3];
    enum diff retval;
    mode_t file_type;
    idx_t indent = 0;

    for (i = OLD;  i <= INDEX;  i++)
      if (p_name[i]) {
	  free (p_name[i]);
	  p_name[i] = 0;
        }
    for (i = 0; i < ARRAY_SIZE (invalid_names); i++)
      invalid_names[i] = nullptr;
    for (i = OLD; i <= NEW; i++)
      if (p_timestr[i])
	{
	  free(p_timestr[i]);
	  p_timestr[i] = 0;
	}
    for (i = OLD; i <= NEW; i++)
      if (p_sha1[i])
	{
	  free (p_sha1[i]);
	  p_sha1[i] = 0;
	}
    p_git_diff = false;
    for (i = OLD; i <= NEW; i++)
      {
	p_mode[i] = 0;
	p_copy[i] = false;
	p_rename[i] = false;
      }

    /* Ed and normal format patches don't have filename headers.  */
    if (diff_type == ED_DIFF || diff_type == NORMAL_DIFF)
      need_header = false;

    version_controlled[OLD] = -1;
    version_controlled[NEW] = -1;
    version_controlled[INDEX] = -1;
    p_rfc934_nesting = 0;
    p_timestamp[OLD].tv_sec = p_timestamp[NEW].tv_sec = -1;
    p_timestamp[OLD].tv_nsec = p_timestamp[NEW].tv_nsec = -1;
    p_says_nonexistent[OLD] = p_says_nonexistent[NEW] = 0;
    Fseeko (pfp, p_base, SEEK_SET);
    p_input_line = p_bline - 1;
    for (;;) {
	char *s;
	char *t;
	off_t previous_line = this_line;
	bool last_line_was_command = this_is_a_command;
	bool stars_last_line = stars_this_line;
	idx_t indent_last_line = indent;
	char ed_command_letter;
	bool strip_trailing_cr;

	indent = 0;
	this_line = Ftello (pfp);
	idx_t chars_read = pget_line (0, 0, false, false, false);
	if (! chars_read) {
	    if (first_ed_command_letter) {
					/* nothing but deletes!? */
		p_start = first_command_line;
		p_sline = fcl_line;
		retval = ED_DIFF;
		goto scan_exit;
	    }
	    else {
		p_start = this_line;
		p_sline = p_input_line;
		if (extended_headers)
		  {
		    /* Patch contains no hunks; any diff type will do. */
		    retval = UNI_DIFF;
		    goto scan_exit;
		  }
		return NO_DIFF;
	    }
	}
	strip_trailing_cr
	  = 2 <= chars_read && patchbuf[chars_read - 2] == '\r';
	for (s = patchbuf; c_isblank (*s) || *s == 'X'; s++) {
	    if (*s == '\t')
		indent = (indent + 8) & ~7;
	    else
		indent++;
	}
	if (c_isdigit (*s))
	  {
	    for (t = s + 1; c_isdigit (*t) || *t == ',';  t++)
	      /* do nothing */ ;
	    if (*t == 'd' || *t == 'c' || *t == 'a')
	      {
		for (t++; c_isdigit (*t) || *t == ','; t++)
		  /* do nothing */ ;
		for (; c_isblank (*t); t++)
		  /* do nothing */ ;
		if (*t == '\r')
		  t++;
		this_is_a_command = (*t == '\n');
	      }
	  }
	if (! need_header
	    && first_command_line < 0
	    && ((ed_command_letter = get_ed_command_letter (s))
		|| this_is_a_command)) {
	    first_command_line = this_line;
	    first_ed_command_letter = ed_command_letter;
	    fcl_line = p_input_line;
	    p_indent = indent;		/* assume this for now */
	    p_strip_trailing_cr = strip_trailing_cr;
	}
	if (!stars_last_line && strnEQ (s, "***", 3) && c_isblank (s[3]))
	  {
	    fetchname (s+4, strippath, &p_name[OLD], &p_timestr[OLD],
		       &p_timestamp[OLD]);
	    need_header = false;
	  }
	else if (strnEQ (s, "+++", 3) && c_isblank (s[3]))
	  {
	    /* Swap with NEW below.  */
	    fetchname (s+4, strippath, &p_name[OLD], &p_timestr[OLD],
		       &p_timestamp[OLD]);
	    need_header = false;
	    p_strip_trailing_cr = strip_trailing_cr;
	  }
	else if (strnEQ(s, "Index:", 6))
	  {
	    fetchname (s + 6, strippath, &p_name[INDEX], nullptr, nullptr);
	    need_header = false;
	    p_strip_trailing_cr = strip_trailing_cr;
	  }
	else if (strnEQ(s, "Prereq:", 7))
	  {
	    for (t = s + 7; c_isspace (*t); t++)
	      /* do nothing */ ;
	    revision = t;
	    for (t = revision;  *t;  t++)
	      if (c_isspace (*t))
		{
		  char const *u;
		  for (u = t + 1; c_isspace (*u); u++)
		    /* do nothing */ ;
		  if (*u)
		    say ("Prereq: with multiple words at line %td of patch\n",
			 p_sline);
		  break;
		}
	    if (t == revision)
		revision = 0;
	    else {
		char oldc = *t;
		*t = '\0';
		revision = xstrdup (revision);
		*t = oldc;
	    }
	  }
	else if (strnEQ (s, "diff --git ", 11))
	  {
	    char const *u;

	    if (extended_headers)
	      {
		p_start = this_line;
		p_sline = p_input_line;
		/* Patch contains no hunks; any diff type will do. */
		retval = UNI_DIFF;
		goto scan_exit;
	      }

	    for (i = OLD; i <= NEW; i++)
	      {
		free (p_name[i]);
		p_name[i] = 0;
	      }
	    if (! ((p_name[OLD] = parse_name (s + 11, strippath, &u))
		   && c_isspace (*u)
		   && (p_name[NEW] = parse_name (u, strippath, &u))
		   && (u = skip_spaces (u), ! *u)))
	      for (i = OLD; i <= NEW; i++)
		{
		  free (p_name[i]);
		  p_name[i] = 0;
		}
	    p_git_diff = true;
	    need_header = false;
	  }
	else if (p_git_diff && strnEQ (s, "index ", 6))
	  {
	    char const *u, *v;
	    if ((u = skip_hex_digits (s + 6))
		&& u[0] == '.' && u[1] == '.'
		&& (v = skip_hex_digits (u + 2))
		&& (! *v || c_isspace (*v)))
	      {
		p_sha1[OLD] = get_sha1 (s + 6, u);
		p_sha1[NEW] = get_sha1 (u + 2, v);
		p_says_nonexistent[OLD] = sha1_says_nonexistent (p_sha1[OLD]);
		p_says_nonexistent[NEW] = sha1_says_nonexistent (p_sha1[NEW]);
		if (*(v = skip_spaces (v)))
		  p_mode[OLD] = p_mode[NEW] = fetchmode (v);
		extended_headers = true;
	      }
	  }
	else if (p_git_diff && strnEQ (s, "old mode ", 9))
	  {
	    p_mode[OLD] = fetchmode (s + 9);
	    extended_headers = true;
	  }
	else if (p_git_diff && strnEQ (s, "new mode ", 9))
	  {
	    p_mode[NEW] = fetchmode (s + 9);
	    extended_headers = true;
	  }
	else if (p_git_diff && strnEQ (s, "deleted file mode ", 18))
	  {
	    p_mode[OLD] = fetchmode (s + 18);
	    p_says_nonexistent[NEW] = 2;
	    extended_headers = true;
	  }
	else if (p_git_diff && strnEQ (s, "new file mode ", 14))
	  {
	    p_mode[NEW] = fetchmode (s + 14);
	    p_says_nonexistent[OLD] = 2;
	    extended_headers = true;
	  }
	else if (p_git_diff && strnEQ (s, "rename from ", 12))
	  {
	    /* Git leaves out the prefix in the file name in this header,
	       so we can only ignore the file name.  */
	    p_rename[OLD] = true;
	    extended_headers = true;
	  }
	else if (p_git_diff && strnEQ (s, "rename to ", 10))
	  {
	    /* Git leaves out the prefix in the file name in this header,
	       so we can only ignore the file name.  */
	    p_rename[NEW] = true;
	    extended_headers = true;
	  }
	else if (p_git_diff && strnEQ (s, "copy from ", 10))
	  {
	    /* Git leaves out the prefix in the file name in this header,
	       so we can only ignore the file name.  */
	    p_copy[OLD] = true;
	    extended_headers = true;
	  }
	else if (p_git_diff && strnEQ (s, "copy to ", 8))
	  {
	    /* Git leaves out the prefix in the file name in this header,
	       so we can only ignore the file name.  */
	    p_copy[NEW] = true;
	    extended_headers = true;
	  }
	else if (p_git_diff && strnEQ (s, "GIT binary patch", 16))
	  {
	    p_start = this_line;
	    p_sline = p_input_line;
	    retval = GIT_BINARY_DIFF;
	    goto scan_exit;
	  }
	else
	  {
	    for (t = s;  t[0] == '-' && t[1] == ' ';  t += 2)
	      /* do nothing */ ;
	    if (strnEQ (t, "---", 3) && c_isblank (t[3]))
	      {
		struct timespec timestamp = { .tv_sec = -1, .tv_nsec = -1 };
		fetchname (t+4, strippath, &p_name[NEW], &p_timestr[NEW],
			   &timestamp);
		need_header = false;
		if (0 <= timestamp.tv_nsec)
		  {
		    p_timestamp[NEW] = timestamp;
		    p_rfc934_nesting = (t - s) >> 1;
		  }
		p_strip_trailing_cr = strip_trailing_cr;
	      }
	  }
	if (need_header)
	  continue;
	if ((diff_type == NO_DIFF || diff_type == ED_DIFF) &&
	  first_command_line >= 0 &&
	  strEQ(s, ".\n") ) {
	    p_start = first_command_line;
	    p_sline = fcl_line;
	    retval = ED_DIFF;
	    goto scan_exit;
	}
	if ((diff_type == NO_DIFF || diff_type == UNI_DIFF)
	    && strnEQ(s, "@@ -", 4)) {

	    /* 'p_name', 'p_timestr', and 'p_timestamp' are backwards;
	       swap them.  */
	    struct timespec ti = p_timestamp[OLD];
	    p_timestamp[OLD] = p_timestamp[NEW];
	    p_timestamp[NEW] = ti;
	    t = p_name[OLD];
	    p_name[OLD] = p_name[NEW];
	    p_name[NEW] = t;
	    t = p_timestr[OLD];
	    p_timestr[OLD] = p_timestr[NEW];
	    p_timestr[NEW] = t;

	    s += 4;
	    if (s[0] == '0' && !c_isdigit (s[1]))
	      p_says_nonexistent[OLD] = 1 + ! p_timestamp[OLD].tv_sec;
	    while (*s != ' ' && *s != '\n')
	      s++;
	    while (*s == ' ')
	      s++;
	    if (s[0] == '+' && s[1] == '0' && !c_isdigit (s[2]))
	      p_says_nonexistent[NEW] = 1 + ! p_timestamp[NEW].tv_sec;
	    p_indent = indent;
	    p_start = this_line;
	    p_sline = p_input_line;
	    retval = UNI_DIFF;
	    if (! ((p_name[OLD] || ! p_timestamp[OLD].tv_sec)
		   && (p_name[NEW] || ! p_timestamp[NEW].tv_sec))
		&& ! p_name[INDEX] && need_header)
	      say ("missing header for unified diff at line %td of patch\n",
		   p_sline);
	    goto scan_exit;
	}
	stars_this_line = strnEQ(s, "********", 8);
	if ((diff_type == NO_DIFF
	     || diff_type == CONTEXT_DIFF
	     || diff_type == NEW_CONTEXT_DIFF)
	    && stars_last_line && indent_last_line == indent
	    && strnEQ (s, "***", 3) && c_isblank (s[3])) {
	    s += 4;
	    while (c_isblank (*s))
	      s++;
	    if (s[0] == '0' && !c_isdigit (s[1]))
	      p_says_nonexistent[OLD] = 1 + ! p_timestamp[OLD].tv_sec;
	    /* if this is a new context diff the character just before */
	    /* the newline is a '*'. */
	    while (*s != '\n')
		s++;
	    p_indent = indent;
	    p_strip_trailing_cr = strip_trailing_cr;
	    p_start = previous_line;
	    p_sline = p_input_line - 1;
	    retval = (*(s-1) == '*' ? NEW_CONTEXT_DIFF : CONTEXT_DIFF);

	    {
	      /* Scan the first hunk to see whether the file contents
		 appear to have been deleted.  */
	      off_t saved_p_base = p_base;
	      idx_t saved_p_bline = p_bline;
	      Fseeko (pfp, previous_line, SEEK_SET);
	      p_input_line -= 2;
	      if (another_hunk (retval, false)
		  && ! p_repl_lines && p_newfirst == 1)
		p_says_nonexistent[NEW] = 1 + ! p_timestamp[NEW].tv_sec;
	      next_intuit_at (saved_p_base, saved_p_bline);
	    }

	    if (! ((p_name[OLD] || ! p_timestamp[OLD].tv_sec)
		   && (p_name[NEW] || ! p_timestamp[NEW].tv_sec))
		&& ! p_name[INDEX] && need_header)
	      say ("missing header for context diff at line %td of patch\n",
		   p_sline);
	    goto scan_exit;
	}
	if ((diff_type == NO_DIFF || diff_type == NORMAL_DIFF) &&
	  last_line_was_command &&
	  (strnEQ(s, "< ", 2) || strnEQ(s, "> ", 2)) ) {
	    p_start = previous_line;
	    p_sline = p_input_line - 1;
	    p_indent = indent;
	    retval = NORMAL_DIFF;
	    goto scan_exit;
	}
    }

  scan_exit:

    /* The old, new, or old and new file types may be defined.  When both
       file types are defined, make sure they are the same, or else assume
       we do not know the file type.  */
    file_type = p_mode[OLD] & S_IFMT;
    if (file_type)
      {
	mode_t new_file_type = p_mode[NEW] & S_IFMT;
	if (new_file_type && file_type != new_file_type)
	  file_type = 0;
      }
    else
      {
	file_type = p_mode[NEW] & S_IFMT;
	if (! file_type)
	  file_type = S_IFREG;
      }
    *p_file_type = file_type;

    /* To intuit 'inname', the name of the file to patch,
       use the algorithm specified by POSIX 1003.1-2024 lines 109651-109671
       (with some modifications if posixly_correct is zero):

       - Take the old and new names from the context header if present,
	 and take the index name from the 'Index:' line if present and
	 if either the old and new names are both absent
	 or posixly_correct is nonzero.
	 Consider the file names to be in the order (old, new, index).
       - If some named files exist, use the first one if posixly_correct
	 is nonzero, the best one otherwise.
       - If patch_get is nonzero, and no named files exist,
	 but an RCS or SCCS master file exists,
	 use the first named file with an RCS or SCCS master.
       - If no named files exist, no RCS or SCCS master was found,
	 some names are given, posixly_correct is zero,
	 and the patch appears to create a file, then use the best name
	 requiring the creation of the fewest directories.
       - Otherwise, report failure by setting 'inname' to 0;
	 this causes our invoker to ask the user for a file name.  */

    i = NONE;

    if (!inname)
      {
	enum nametype i0 = NONE;

	if (! posixly_correct && (p_name[OLD] || p_name[NEW]) && p_name[INDEX])
	  {
	    free (p_name[INDEX]);
	    p_name[INDEX] = 0;
	  }

	for (i = OLD;  i <= INDEX;  i++)
	  if (p_name[i])
	    {
	      if (i0 != NONE && strcmp (p_name[i0], p_name[i]) == 0)
		{
		  /* It's the same name as before; reuse stat results.  */
		  stat_errno[i] = stat_errno[i0];
		  if (! stat_errno[i])
		    st[i] = st[i0];
		}
	      else
		{
		  stat_errno[i] = stat_file (p_name[i], &st[i]);
		  if (! stat_errno[i])
		    {
		      if (lookup_file_id (&st[i]) == DELETE_LATER)
			stat_errno[i] = ENOENT;
		      else if (posixly_correct && name_is_valid (p_name[i]))
			break;
		    }
		}
	      i0 = i;
	    }

	if (! posixly_correct)
	  {
	    /* The best of all existing files. */
	    i = best_name (p_name, stat_errno);

	    if (i == NONE && patch_get)
	      {
		enum nametype nope = NONE;

		for (i = OLD;  i <= INDEX;  i++)
		  if (p_name[i])
		    {
		      char const *cs;
		      char *getbuf;
		      char *diffbuf;
		      bool readonly = (outfile
				       && strcmp (outfile, p_name[i]) != 0);

		      if (nope == NONE || strcmp (p_name[nope], p_name[i]) != 0)
			{
			  cs = (version_controller
			        (p_name[i], readonly, (struct stat *) 0,
				 &getbuf, &diffbuf));
			  version_controlled[i] = !! cs;
			  if (cs)
			    {
			      if (version_get (p_name[i], cs, false, readonly,
					       getbuf, &st[i]))
				stat_errno[i] = 0;
			      else
				version_controlled[i] = 0;

			      free (getbuf);
			      free (diffbuf);

			      if (! stat_errno[i])
				break;
			    }
			}

		      nope = i;
		    }
	      }

	    if (i0 != NONE
		&& (i == NONE || (st[i].st_mode & S_IFMT) == file_type)
		&& maybe_reverse (p_name[i == NONE ? i0 : i], i == NONE,
				  i == NONE || st[i].st_size == 0)
		&& i == NONE)
	      i = i0;

	    if (i == NONE && p_says_nonexistent[reverse_flag])
	      {
		ptrdiff_t newdirs[3];
		ptrdiff_t newdirs_min = PTRDIFF_MAX;
		int above_minimum[3];

		for (i = OLD;  i <= INDEX;  i++)
		  if (p_name[i])
		    {
		      newdirs[i] = (prefix_components (p_name[i], false)
				    - prefix_components (p_name[i], true));
		      if (newdirs[i] < newdirs_min)
			newdirs_min = newdirs[i];
		    }

		for (i = OLD;  i <= INDEX;  i++)
		  if (p_name[i])
		    above_minimum[i] = newdirs_min < newdirs[i];

		/* The best of the filenames that create the fewest
		   directories. */
		i = best_name (p_name, above_minimum);
	      }
	  }
      }

    if ((pch_rename () || pch_copy ())
	&& ! inname
	&& ! ((i == OLD || i == NEW) &&
	      p_name[reverse_flag] && p_name[! reverse_flag] &&
	      name_is_valid (p_name[reverse_flag]) &&
	      name_is_valid (p_name[! reverse_flag])))
      {
	say ("Cannot %s file without two valid file names\n", pch_rename () ? "rename" : "copy");
	skip_rest_of_patch = true;
      }

    if (i == NONE)
      {
	if (inname)
	  {
	    inerrno = stat_file (inname, &instat);
	    if (inerrno || (instat.st_mode & S_IFMT) == file_type)
	      maybe_reverse (inname, inerrno, inerrno || instat.st_size == 0);
	  }
	else
          inerrno = -1;
      }
    else
      {
	inname = xstrdup (p_name[i]);
	inerrno = stat_errno[i];
	invc = version_controlled[i];
	instat = st[i];
      }

    return retval;
}

/* Count the path name components in FILENAME's prefix.
   If CHECKDIRS is true, count only existing directories.  */
static idx_t
prefix_components (char *filename, bool checkdirs)
{
  idx_t count = 0;
  struct stat stat_buf;
  int stat_result;
  char *f = filename + FILE_SYSTEM_PREFIX_LEN (filename);

  if (*f)
    while (*++f)
      if (ISSLASH (f[0]) && ! ISSLASH (f[-1]))
	{
	  if (checkdirs)
	    {
	      *f = '\0';
	      stat_result = safe_stat (filename, &stat_buf);
	      *f = '/';
	      if (! (stat_result == 0 && S_ISDIR (stat_buf.st_mode)))
		break;
	    }

	  count++;
	}

  return count;
}

/* Return the index of the best of NAME[OLD], NAME[NEW], and NAME[INDEX].
   Ignore null names, and ignore NAME[i] if IGNORE[i] is nonzero.
   Return NONE if all names are ignored.  */
static enum nametype
best_name (char *const *name, int const *ignore)
{
  enum nametype i;
  idx_t components[3];
  idx_t components_min = IDX_MAX;
  idx_t basename_len[3];
  idx_t basename_len_min = IDX_MAX;
  idx_t len[3];
  idx_t len_min = IDX_MAX;

  for (i = OLD;  i <= INDEX;  i++)
    if (name[i] && !ignore[i])
      {
	/* Take the names with the fewest prefix components.  */
	components[i] = prefix_components (name[i], false);
	if (components_min < components[i])
	  continue;
	components_min = components[i];

	/* Of those, take the names with the shortest basename.  */
	basename_len[i] = strlen (last_component (name[i]));
	if (basename_len_min < basename_len[i])
	  continue;
	basename_len_min = basename_len[i];

	/* Of those, take the shortest names.  */
	len[i] = strlen (name[i]);
	if (len_min < len[i])
	  continue;
	len_min = len[i];
      }

  /* Of those, take the first name.  */
  for (i = OLD;  i <= INDEX;  i++)
    if (name[i] && !ignore[i]
	&& name_is_valid (name[i])
	&& components[i] == components_min
	&& basename_len[i] == basename_len_min
	&& len[i] == len_min)
      break;

  return i;
}

/* Remember where this patch ends so we know where to start up again. */

static void
next_intuit_at (off_t file_pos, idx_t file_line)
{
    p_base = file_pos;
    p_bline = file_line;
}

/* Basically a verbose fseek() to the actual diff listing. */

static void
skip_to (off_t file_pos, idx_t file_line)
{
    FILE *i = pfp;
    FILE *o = stdout;
    int c;

    assert(p_base <= file_pos);
    if ((verbosity == VERBOSE || !inname) && p_base < file_pos) {
	Fseeko (i, p_base, SEEK_SET);
	say ("The text leading up to this was:\n--------------------------\n");

	while (Ftello (i) < file_pos)
	  {
	    Fputc ('|', o);
	    do
	      {
		c = getc (i);
		if (c < 0)
		  read_fatal ();
		Fputc (c, o);
	      }
	    while (c != '\n');
	  }

	say ("--------------------------\n");
    }
    else
	Fseeko (i, file_pos, SEEK_SET);
    p_input_line = file_line - 1;
}

/* Make this a function for better debugging.  */
static void
malformed (void)
{
  fatal ("malformed patch at line %td: %s", p_input_line, patchbuf);
		/* about as informative as "Syntax error" in C */
}

/* Parse a line number from a string.
   The number is optionally preceded and followed by blank characters.
   Return the address of the first char after the scan.  */
static char *
scan_linenum (char *string, idx_t *linenum)
{
  char *s0, *s;
  idx_t n = 0;
  bool overflow = false;

  for (s0 = string; c_isblank (*s0); s0++)
    continue;

  for (s = s0; c_isdigit (*s); s++)
    {
      overflow |= ckd_mul (&n, n, 10);
      overflow |= ckd_add (&n, n, *s - '0');
    }

  if (s == s0)
    fatal ("missing line number at line %td: %s", p_input_line, patchbuf);

  if (overflow)
    {
      int s0len = ckd_add (&s0len, s - s0, 0) ? -1 : s0len;
      fatal ("line number %.*s is too large at line %td: %s",
	     s0len, s0, p_input_line, patchbuf);
    }

  *linenum = n;

  while (c_isblank (*s))
    s++;

  return s;
}

/* True if there is more of the current diff listing to process,
   false otherwise.  */

bool
another_hunk (enum diff difftype, bool rev)
{
    char *s;
    idx_t context = 0;

    set_hunkmax();

    while (p_end >= 0) {
	if (p_end == p_efake)
	    p_end = p_bfake;		/* don't free twice */
	else
	    free(p_line[p_end]);
	p_end--;
    }
    assert (p_end < 0);
    p_efake = -1;

    if (p_c_function)
      {
	free (p_c_function);
	p_c_function = nullptr;
      }

    p_max = hunkmax;			/* gets reduced when --- found */
    if (difftype == CONTEXT_DIFF || difftype == NEW_CONTEXT_DIFF) {
	off_t line_beginning = Ftello (pfp);
					/* file pos of the current line */
	idx_t repl_beginning = 0;	/* index of --- line */
	idx_t fillcnt = 0;	/* #lines of missing ptrn or repl */
	idx_t fillsrc;		/* index of first line to copy */
	idx_t filldst;		/* index of first missing line */
	bool ptrn_spaces_eaten = false;	/* ptrn was slightly malformed */
	bool some_context = false;	/* (perhaps internal) context seen */
	bool repl_could_be_missing = true;
	bool ptrn_missing = false;	/* The pattern was missing.  */
	bool repl_missing = false;	/* Likewise for replacement.  */
	off_t repl_backtrack_position = 0;
					/* file pos of first repl line */
	idx_t repl_patch_line;		/* input line number for same */
	idx_t repl_context;		/* context for same */
	ptrdiff_t
	  ptrn_prefix_context = -1,	/* lines in pattern prefix context */
	  ptrn_suffix_context = -1,	/* lines in pattern suffix context */
	  repl_prefix_context = -1;	/* lines in replac. prefix context */
	idx_t ptrn_copiable = 0;	/* # of copiable lines in ptrn */
	idx_t repl_copiable = 0;	/* Likewise for replacement.  */

	/* Pacify 'gcc -Wall'.  */
	fillsrc = filldst = repl_patch_line = repl_context = 0;

	idx_t chars_read = get_line (false);
	if (chars_read <= 8
	    || strncmp (patchbuf, "********", 8) != 0) {
	    next_intuit_at(line_beginning,p_input_line);
	    return false;
	}
	s = patchbuf;
	while (*s == '*')
	    s++;
	if (c_isblank (*s))
	  {
	    p_c_function = s;
	    while (*s != '\n')
		s++;
	    p_c_function = ximemdup0 (p_c_function, s - p_c_function);
	  }
	p_hunk_beg = p_input_line + 1;
	while (p_end < p_max) {
	    chars_read = get_line (true);
	    if (!chars_read) {
		if (repl_beginning && repl_could_be_missing) {
		    repl_missing = true;
		    goto hunk_done;
		}
		if (p_max - p_end < 4) {
		    /* Assume blank lines got chopped.  */
		    strcpy (patchbuf, "  \n");
		    chars_read = 3;
		} else {
		    fatal ("unexpected end of file in patch");
		}
	    }
	    p_end++;
	    if (p_end == hunkmax)
	      fatal (("unterminated hunk starting at line %td;"
		      " giving up at line %td: %s"),
		     pch_hunk_beg (), p_input_line, patchbuf);
	    assert(p_end < hunkmax);
	    p_Char[p_end] = *patchbuf;
	    p_len[p_end] = 0;
	    p_line[p_end] = 0;
	    switch (*patchbuf) {
	    case '*':
		if (strnEQ(patchbuf, "********", 8)) {
		    if (repl_beginning && repl_could_be_missing) {
			repl_missing = true;
			goto hunk_done;
		    }
		    else
		      fatal ("unexpected end of hunk at line %td",
			     p_input_line);
		}
		if (p_end != 0) {
		    if (repl_beginning && repl_could_be_missing) {
			repl_missing = true;
			goto hunk_done;
		    }
		    fatal ("unexpected '***' at line %td: %s",
			   p_input_line, patchbuf);
		}
		context = 0;
		p_len[p_end] = strlen (patchbuf);
		p_line[p_end] = xmemdup (patchbuf, p_len[p_end] + 1);
		for (s = patchbuf; *s && !c_isdigit (*s); s++)
		  /* do nothing */ ;
		s = scan_linenum (s, &p_first);
		if (*s == ',') {
		    idx_t last;
		    scan_linenum (s + 1, &last);
		    if (p_first == 0 && last == 0)
		      p_first = 1;
		    p_ptrn_lines = last - p_first + 1;
		    if (p_ptrn_lines < 0)
		      malformed ();
		}
		else if (p_first)
		    p_ptrn_lines = 1;
		else {
		    p_ptrn_lines = 0;
		    p_first = 1;
		}
		if (p_first >= IDX_MAX - p_ptrn_lines
		    || p_ptrn_lines >= IDX_MAX - 6)
		  malformed ();
		p_max = p_ptrn_lines + 6;	/* we need this much at least */
		while (p_max + 1 >= hunkmax)
		  grow_hunkmax ();
		p_max = hunkmax;
		break;
	    case '-':
		if (patchbuf[1] != '-')
		  goto change_line;
		if (ptrn_prefix_context < 0)
		  ptrn_prefix_context = context;
		ptrn_suffix_context = context;
		if (repl_beginning
		    || p_end <= 0
		    || (p_end
			!= p_ptrn_lines + 1 + (p_Char[p_end - 1] == '\n')))
		  {
		    if (p_end == 1)
		      {
			/* 'Old' lines were omitted.  Set up to fill
			   them in from 'new' context lines.  */
			ptrn_missing = true;
			p_end = p_ptrn_lines + 1;
			ptrn_prefix_context = ptrn_suffix_context = -1;
			fillsrc = p_end + 1;
			filldst = 1;
			fillcnt = p_ptrn_lines;
		      }
		    else if (! repl_beginning)
		      fatal (("%s '---' at line %td;"
			      " check line numbers at line %td"),
			     (p_end <= p_ptrn_lines
			      ? "Premature"
			      : "Overdue"),
			     p_input_line, p_hunk_beg);
		    else if (! repl_could_be_missing)
		      fatal (("duplicate '---' at line %td;"
			      " check line numbers at line %td"),
			     p_input_line, p_hunk_beg + repl_beginning);
		    else
		      {
			repl_missing = true;
			goto hunk_done;
		      }
		  }
		repl_beginning = p_end;
		repl_backtrack_position = Ftello (pfp);
		repl_patch_line = p_input_line;
		repl_context = context;
		p_len[p_end] = strlen (patchbuf);
		p_line[p_end] = xmemdup (patchbuf, p_len[p_end] + 1);
		p_Char[p_end] = '=';
		for (s = patchbuf; *s && !c_isdigit (*s); s++)
		  /* do nothing */ ;
		s = scan_linenum (s, &p_newfirst);
		if (*s == ',')
		  {
		    idx_t last;
		    scan_linenum (s + 1, &last);
		    p_repl_lines = last - p_newfirst + 1;
		    if (p_repl_lines < 0)
		      malformed ();
		  }
		else if (p_newfirst)
		  p_repl_lines = 1;
		else
		  {
		    p_repl_lines = 0;
		    p_newfirst = 1;
		  }
		if (p_newfirst >= IDX_MAX - p_repl_lines
		    || p_repl_lines >= IDX_MAX - p_end)
		  malformed ();
		p_max = p_repl_lines + p_end;
		while (p_max + 1 >= hunkmax)
		  grow_hunkmax ();
		if (p_repl_lines != ptrn_copiable
		    && (p_prefix_context != 0
			|| context != 0
			|| p_repl_lines != 1))
		  repl_could_be_missing = false;
		context = 0;
		break;
	    case '+':  case '!':
		repl_could_be_missing = false;
	      change_line:
		s = patchbuf + 1;
		chars_read--;
		if (*s == '\n' && canonicalize_ws) {
		    strcpy (s, " \n");
		    chars_read = 2;
		}
		if (c_isblank (*s)) {
		    s++;
		    chars_read--;
		} else if (repl_beginning && repl_could_be_missing) {
		    repl_missing = true;
		    goto hunk_done;
		}
		if (! repl_beginning)
		  {
		    if (ptrn_prefix_context < 0)
		      ptrn_prefix_context = context;
		  }
		else
		  {
		    if (repl_prefix_context < 0)
		      repl_prefix_context = context;
		  }
		chars_read -=
		  (1 < chars_read
		   && p_end == (repl_beginning ? p_max : p_ptrn_lines)
		   && incomplete_line ());
		p_len[p_end] = chars_read;
		p_line[p_end] = savebuf (s, chars_read);
		context = 0;
		break;
	    case '\t': case '\n':	/* assume spaces got eaten */
		s = patchbuf;
		if (*patchbuf == '\t') {
		    s++;
		    chars_read--;
		}
		if (repl_beginning && repl_could_be_missing &&
		    (!ptrn_spaces_eaten || difftype == NEW_CONTEXT_DIFF) ) {
		    repl_missing = true;
		    goto hunk_done;
		}
		chars_read -=
		  (1 < chars_read
		   && p_end == (repl_beginning ? p_max : p_ptrn_lines)
		   && incomplete_line ());
		p_len[p_end] = chars_read;
		p_line[p_end] = savebuf (patchbuf, chars_read);
		if (p_end != p_ptrn_lines + 1) {
		    ptrn_spaces_eaten |= (repl_beginning != 0);
		    some_context = true;
		    context++;
		    if (repl_beginning)
			repl_copiable++;
		    else
			ptrn_copiable++;
		    p_Char[p_end] = ' ';
		}
		break;
	    case ' ':
		s = patchbuf + 1;
		chars_read--;
		if (*s == '\n' && canonicalize_ws) {
		    strcpy (s, "\n");
		    chars_read = 2;
		}
		if (c_isblank (*s)) {
		    s++;
		    chars_read--;
		} else if (repl_beginning && repl_could_be_missing) {
		    repl_missing = true;
		    goto hunk_done;
		}
		some_context = true;
		context++;
		if (repl_beginning)
		    repl_copiable++;
		else
		    ptrn_copiable++;
		chars_read -=
		  (1 < chars_read
		   && p_end == (repl_beginning ? p_max : p_ptrn_lines)
		   && incomplete_line ());
		p_len[p_end] = chars_read;
		p_line[p_end] = savebuf (s, chars_read);
		break;
	    default:
		if (repl_beginning && repl_could_be_missing) {
		    repl_missing = true;
		    goto hunk_done;
		}
		malformed ();
	    }
	}

    hunk_done:
	if (p_end >=0 && !repl_beginning)
	  fatal ("no '---' found in patch at line %td", pch_hunk_beg ());

	if (repl_missing) {

	    /* reset state back to just after --- */
	    p_input_line = repl_patch_line;
	    context = repl_context;
	    for (p_end--; p_end > repl_beginning; p_end--)
		free(p_line[p_end]);
	    Fseeko (pfp, repl_backtrack_position, SEEK_SET);

	    /* redundant 'new' context lines were omitted - set */
	    /* up to fill them in from the old file context */
	    fillsrc = 1;
	    filldst = repl_beginning+1;
	    fillcnt = p_repl_lines;
	    p_end = p_max;
	}
	else if (! ptrn_missing && ptrn_copiable != repl_copiable)
	  fatal ("context mangled in hunk at line %td", p_hunk_beg);
	else if (!some_context && fillcnt == 1) {
	    /* the first hunk was a null hunk with no context */
	    /* and we were expecting one line -- fix it up. */
	    while (filldst < p_end) {
		p_line[filldst] = p_line[filldst+1];
		p_Char[filldst] = p_Char[filldst+1];
		p_len[filldst] = p_len[filldst+1];
		filldst++;
	    }
#if 0
	    repl_beginning--;		/* this doesn't need to be fixed */
#endif
	    p_end--;
	    p_first++;			/* do append rather than insert */
	    fillcnt = 0;
	    p_ptrn_lines = 0;
	}

	p_prefix_context = ((repl_prefix_context < 0
			     || (0 <= ptrn_prefix_context
				 && ptrn_prefix_context < repl_prefix_context))
			    ? ptrn_prefix_context : repl_prefix_context);
	p_suffix_context = ((0 <= ptrn_suffix_context
			     && ptrn_suffix_context < context)
			    ? ptrn_suffix_context : context);
	if (p_prefix_context < 0 || p_suffix_context < 0)
	  fatal ("replacement text or line numbers mangled in hunk at line %td",
		 p_hunk_beg);

	if (difftype == CONTEXT_DIFF
	    && (fillcnt
		|| (p_first > 1
		    && p_prefix_context + p_suffix_context < ptrn_copiable))) {
	    if (verbosity == VERBOSE)
		say ("%s\n%s\n%s\n",
"(Fascinating -- this is really a new-style context diff but without",
"the telltale extra asterisks on the *** line that usually indicate",
"the new style...)");
	    diff_type = difftype = NEW_CONTEXT_DIFF;
	}

	/* if there were omitted context lines, fill them in now */
	if (fillcnt) {
	    p_bfake = filldst;		/* remember where not to free() */
	    p_efake = filldst + fillcnt - 1;
	    while (fillcnt-- > 0) {
		while (fillsrc <= p_end && fillsrc != repl_beginning
		       && p_Char[fillsrc] != ' ')
		    fillsrc++;
		if (p_end < fillsrc || fillsrc == repl_beginning)
		  fatal (("replacement text or line numbers mangled"
			  " in hunk at line %td"),
			 p_hunk_beg);
		p_line[filldst] = p_line[fillsrc];
		p_Char[filldst] = p_Char[fillsrc];
		p_len[filldst] = p_len[fillsrc];
		fillsrc++; filldst++;
	    }
	    while (fillsrc <= p_end && fillsrc != repl_beginning)
	      {
		if (p_Char[fillsrc] == ' ')
		  fatal (("replacement text or line numbers mangled"
			  " in hunk at line %td"),
			 p_hunk_beg);
		fillsrc++;
	      }
	    if (debug & 64)
	      Fprintf (stdout, "fillsrc %td, filldst %td, rb %td, e+1 %td\n",
		       fillsrc, filldst, repl_beginning, p_end + 1);
	    assert(fillsrc==p_end+1 || fillsrc==repl_beginning);
	    assert(filldst==p_end+1 || filldst==repl_beginning);
	}
    }
    else if (difftype == UNI_DIFF) {
	off_t line_beginning = Ftello (pfp); /* file pos of the current line */

	idx_t fillsrc;	/* index of old lines */
	idx_t filldst;	/* index of new lines */
	char ch = '\0';

	if (get_line (false) <= 4
	    || strncmp (patchbuf, "@@ -", 4) != 0) {
	    next_intuit_at(line_beginning,p_input_line);
	    return false;
	}
	s = scan_linenum (patchbuf + 4, &p_first);
	if (*s == ',')
	  {
	    idx_t nlines;
	    s = scan_linenum (s + 1, &nlines);
	    if (p_first >= IDX_MAX - nlines)
	      malformed ();
	    p_ptrn_lines = nlines;
	  }
	else
	    p_ptrn_lines = 1;
	if (*s == ' ') s++;
	if (*s != '+')
	    malformed ();
	s = scan_linenum (s + 1, &p_newfirst);
	if (*s == ',')
	  {
	    idx_t nlines;
	    s = scan_linenum (s + 1, &nlines);
	    if (p_newfirst >= IDX_MAX - nlines)
	      malformed ();
	    p_repl_lines = nlines;
	  }
	else
	    p_repl_lines = 1;
	if (*s == ' ') s++;
	if (*s++ != '@')
	    malformed ();
	if (*s++ == '@' && *s == ' ')
	  {
	    p_c_function = s;
	    while (*s != '\n')
		s++;
	    p_c_function = ximemdup0 (p_c_function, s - p_c_function);
	  }
	if (!p_ptrn_lines)
	    p_first++;			/* do append rather than insert */
	if (!p_repl_lines)
	    p_newfirst++;
	if (p_ptrn_lines >= IDX_MAX - (p_repl_lines + 1))
	  malformed ();
	p_max = p_ptrn_lines + p_repl_lines + 1;
	while (p_max + 1 >= hunkmax)
	  grow_hunkmax ();
	fillsrc = 1;
	filldst = fillsrc + p_ptrn_lines;
	p_end = filldst + p_repl_lines;
	p_len[0] = sprintf (patchbuf, "*** %td,%td ****\n",
			    p_first, p_first + p_ptrn_lines - 1);
	p_line[0] = xmemdup (patchbuf, p_len[0] + 1);
	p_Char[0] = '*';
	p_len[filldst] = sprintf (patchbuf, "--- %td,%td ----\n",
				  p_newfirst, p_newfirst + p_repl_lines - 1);
	p_line[filldst] = xmemdup (patchbuf, p_len[filldst] + 1);
	p_Char[filldst++] = '=';
	p_prefix_context = -1;
	p_hunk_beg = p_input_line + 1;
	while (fillsrc <= p_ptrn_lines || filldst <= p_end) {
	    idx_t chars_read = get_line (true);
	    if (!chars_read) {
		if (p_max - filldst < 3) {
		    /* Assume blank lines got chopped.  */
		    strcpy (patchbuf, " \n");
		    chars_read = 2;
		} else {
		    fatal ("unexpected end of file in patch");
		}
	    }
	    if (*patchbuf == '\t' || *patchbuf == '\n') {
		ch = ' ';		/* assume the space got eaten */
		s = savebuf (patchbuf, chars_read);
	    }
	    else {
		ch = *patchbuf;
		s = savebuf (patchbuf+1, --chars_read);
	    }
	    switch (ch) {
	    case '-':
		if (fillsrc > p_ptrn_lines) {
		    free(s);
		    p_end = filldst-1;
		    malformed ();
		}
		chars_read -= fillsrc == p_ptrn_lines && incomplete_line ();
		p_Char[fillsrc] = ch;
		p_line[fillsrc] = s;
		p_len[fillsrc++] = chars_read;
		break;
	    case '=':
		ch = ' ';
		FALLTHROUGH;
	    case ' ':
		if (fillsrc > p_ptrn_lines) {
		    free(s);
		    while (--filldst > p_ptrn_lines)
			free(p_line[filldst]);
		    p_end = fillsrc-1;
		    malformed ();
		}
		context++;
		chars_read -= fillsrc == p_ptrn_lines && incomplete_line ();
		p_Char[fillsrc] = ch;
		p_line[fillsrc] = s;
		p_len[fillsrc++] = chars_read;
		s = savebuf (s, chars_read);
		FALLTHROUGH;
	    case '+':
		if (filldst > p_end) {
		    free(s);
		    while (--filldst > p_ptrn_lines)
			free(p_line[filldst]);
		    p_end = fillsrc-1;
		    malformed ();
		}
		chars_read -= filldst == p_end && incomplete_line ();
		p_Char[filldst] = ch;
		p_line[filldst] = s;
		p_len[filldst++] = chars_read;
		break;
	    default:
		p_end = filldst;
		free (s);
		malformed ();
	    }
	    if (ch != ' ') {
		if (p_prefix_context < 0)
		    p_prefix_context = context;
		context = 0;
	    }
	}/* while */
	if (p_prefix_context < 0)
	  malformed ();
	p_suffix_context = context;
    }
    else {				/* normal diff--fake it up */
	char hunk_type;
	idx_t min, max;
	off_t line_beginning = Ftello (pfp);

	p_prefix_context = p_suffix_context = 0;
	idx_t chars_read = get_line (false);
	bool invalid_line = chars_read <= 0;
	if (!invalid_line)
	  for (s = patchbuf; c_isblank (*s); s++)
	    continue;
	if (invalid_line || !c_isdigit (*s))
	  {
	    next_intuit_at(line_beginning,p_input_line);
	    return false;
	  }
	s = scan_linenum (s, &p_first);
	if (*s == ',') {
	    idx_t last;
	    s = scan_linenum (s + 1, &last);
	    ptrdiff_t diff = last - p_first;
	    if (! (-1 <= diff && diff < IDX_MAX))
	      malformed ();
	    p_ptrn_lines = diff + 1;
	}
	else
	    p_ptrn_lines = (*s != 'a');
	hunk_type = *s;
	if (hunk_type == 'a')
	    p_first++;			/* do append rather than insert */
	s = scan_linenum (s + 1, &min);
	if (*s == ',')
	    scan_linenum (s + 1, &max);
	else
	    max = min;
	if (min > max || max - min == IDX_MAX)
	  malformed ();
	if (hunk_type == 'd')
	    min++;
	p_newfirst = min;
	p_repl_lines = max - min + 1;
	if (p_newfirst >= IDX_MAX - p_repl_lines)
	  malformed ();
	if (p_ptrn_lines >= IDX_MAX - (p_repl_lines + 1))
	  malformed ();
	p_end = p_ptrn_lines + p_repl_lines + 1;
	while (p_end + 1 >= hunkmax)
	  grow_hunkmax ();
	p_len[0] = sprintf (patchbuf, "*** %td,%td\n",
			    p_first, p_first + p_ptrn_lines - 1);
	p_line[0] = xmemdup (patchbuf, p_len[0] + 1);
	p_Char[0] = '*';

	idx_t i;
	for (i=1; i<=p_ptrn_lines; i++) {
	    chars_read = get_line (true);
	    if (!chars_read)
	      fatal ("unexpected end of file in patch at line %td",
		     p_input_line);
	    if (! (patchbuf[0] == '<' && c_isblank (patchbuf[1])))
	      fatal (("'<' followed by space or tab expected"
		      " at line %td of patch"),
		     p_input_line);
	    chars_read -= 2 + (i == p_ptrn_lines && incomplete_line ());
	    p_len[i] = chars_read;
	    p_line[i] = savebuf (patchbuf + 2, chars_read);
	    p_Char[i] = '-';
	}
	if (hunk_type == 'c') {
	    chars_read = get_line (true);
	    if (! chars_read)
	      fatal ("unexpected end of file in patch at line %td",
		     p_input_line);
	    if (*patchbuf != '-')
	      fatal ("'---' expected at line %td of patch", p_input_line);
	}
	p_len[i] = sprintf (patchbuf, "--- %td,%td\n", min, max);
	p_line[i] = xmemdup (patchbuf, p_len[i] + 1);
	p_Char[i] = '=';
	for (i++; i<=p_end; i++) {
	    chars_read = get_line (true);
	    if (!chars_read)
	      fatal ("unexpected end of file in patch at line %td",
		     p_input_line);
	    if (! (patchbuf[0] == '>' && c_isblank (patchbuf[1])))
	      fatal (("'>' followed by space or tab expected"
		      " at line %td of patch"),
		     p_input_line);
	    chars_read -= 2 + (i == p_end && incomplete_line ());
	    p_len[i] = chars_read;
	    p_line[i] = savebuf (patchbuf + 2, chars_read);
	    p_Char[i] = '+';
	}
    }
    if (rev)				/* backwards patch? */
      pch_swap ();
    assert (p_end + 1 < hunkmax);
    p_Char[p_end + 1] = '^';  /* add a stopper for apply_hunk */
    if (debug & 2) {
	for (idx_t i = 0; i <= p_end + 1; i++) {
	    if (p_Char[i] == '\n')
	      {
		Fprintf (stderr, "%td\n", i);
		continue;
	      }
	    Fprintf (stderr, "%td %c", i, p_Char[i]);
	    if (p_Char[i] == '*')
	      Fprintf (stderr, " %td,%td\n", p_first, p_ptrn_lines);
	    else if (p_Char[i] == '=')
	      Fprintf (stderr, " %td,%td\n", p_newfirst, p_repl_lines);
	    else if (p_Char[i] != '^')
	      {
		Fputs (" |", stderr);
		if (! pch_write_line (i, stderr))
		  Fputc ('\n', stderr);
	      }
	    else
	      Fputc ('\n', stderr);
	}
	Fflush (stderr);
    }
    return true;
}

static idx_t
get_line (bool allow_nul)
{
   return pget_line (p_indent, p_rfc934_nesting, p_strip_trailing_cr,
		     p_pass_comments_through, allow_nul);
}

/* Input a line from the patch file, worrying about indentation.
   Strip up to INDENT characters' worth of leading indentation.
   Then remove up to RFC934_NESTING instances of leading "- ".
   If STRIP_TRAILING_CR is true, remove any trailing carriage-return.
   Unless PASS_COMMENTS_THROUGH is true, ignore any resulting lines
   that begin with '#'; they're comments.
   If ALLOW_NUL, allow null bytes in the line; otherwise diagnose and fail.
   Ignore any partial lines at end of input, but warn about them.
   Succeed if a line was read; it is terminated by "\n\0" for convenience.
   Return the number of characters read, including '\n' but not '\0'.  */

static idx_t
pget_line (idx_t indent, ptrdiff_t rfc934_nesting, bool strip_trailing_cr,
	   bool pass_comments_through, bool allow_nul)
{
  FILE *fp = pfp;
  int c;
  idx_t i;
  char *b;
  int invalid_byte = allow_nul ? -1 : 0;
  bool got_invalid_byte = false;

  do
    {
      i = 0;
      for (;;)
	{
	  c = getc (fp);
	  if (c < 0)
	    {
	      if (ferror (fp))
		read_fatal ();
	      return 0;
	    }
	  if (indent <= i)
	    break;
	  if (c == ' ' || c == 'X')
	    i++;
	  else if (c == '\t')
	    i = (i + 8) & ~7;
	  else
	    got_invalid_byte |= c == invalid_byte;
	}

      i = 0;
      b = patchbuf;

      while (c == '-' && 0 <= --rfc934_nesting)
	{
	  c = getc (fp);
	  if (c < 0)
	    goto patch_ends_in_middle_of_line;
	  if (c != ' ')
	    {
	      i = 1;
	      b[0] = '-';
	      got_invalid_byte |= c == invalid_byte;
	      break;
	    }
	  c = getc (fp);
	  if (c < 0)
	    goto patch_ends_in_middle_of_line;
	}

      idx_t s = patchbufsize;

      for (;;)
	{
	  if (i == s - 1)
	    {
	      grow_patchbuf ();
	      b = patchbuf;
	      s = patchbufsize;
	    }
	  b[i++] = c;
	  if (c == '\n')
	    break;
	  got_invalid_byte |= c == invalid_byte;
	  c = getc (fp);
	  if (c < 0)
	    goto patch_ends_in_middle_of_line;
	}

      p_input_line++;
    }
  while (*b == '#' && !pass_comments_through);

  if (got_invalid_byte)
    fatal ("patch line %td contains NUL byte", p_input_line);

  if (strip_trailing_cr && 2 <= i && b[i - 2] == '\r')
    b[i-- - 2] = '\n';
  b[i] = '\0';
  return i;

 patch_ends_in_middle_of_line:
  if (ferror (fp))
    read_fatal ();
  say ("patch unexpectedly ends in middle of line\n");
  return 0;
}

static bool
incomplete_line (void)
{
  FILE *fp = pfp;
  int c;
  off_t line_beginning = Ftello (fp);

  if (getc (fp) == '\\')
    {
      while ((c = getc (fp)) != '\n')
	if (c < 0)
	  {
	    if (ferror (fp))
	      read_fatal ();
	    break;
	  }
      return true;
    }
  else
    {
      /* We don't trust ungetc.  */
      Fseeko (pfp, line_beginning, SEEK_SET);
      return false;
    }
}

/* Reverse the old and new portions of the current hunk. */

void
pch_swap (void)
{
    char **tp_line;		/* the text of the hunk */
    idx_t *tp_len;		/* length of each line */
    char *tp_char;		/* +, -, and ! */
    bool blankline = false;
    char *s;

    idx_t oldfirst = p_first;
    p_first = p_newfirst;
    p_newfirst = oldfirst;

    /* make a scratch copy */

    tp_line = p_line;
    tp_len = p_len;
    tp_char = p_Char;
    p_line = 0;	/* force set_hunkmax to allocate again */
    p_len = 0;
    p_Char = 0;
    set_hunkmax();

    /* now turn the new into the old */

    idx_t i = p_ptrn_lines + 1;
    if (tp_char[i] == '\n') {		/* account for possible blank line */
	blankline = true;
	i++;
    }
    if (p_efake >= 0) {			/* fix non-freeable ptr range */
	ptrdiff_t n = p_efake <= i ? p_end - p_ptrn_lines : -i;
	p_efake += n;
	p_bfake += n;
    }
    idx_t n;
    for (n=0; i <= p_end; i++,n++) {
	p_line[n] = tp_line[i];
	p_Char[n] = tp_char[i];
	if (p_Char[n] == '+')
	    p_Char[n] = '-';
	p_len[n] = tp_len[i];
    }
    if (blankline) {
	i = p_ptrn_lines + 1;
	p_line[n] = tp_line[i];
	p_Char[n] = tp_char[i];
	p_len[n] = tp_len[i];
	n++;
    }
    assert(p_Char[0] == '=');
    p_Char[0] = '*';
    for (s=p_line[0]; *s; s++)
	if (*s == '-')
	    *s = '*';

    /* now turn the old into the new */

    assert(tp_char[0] == '*');
    tp_char[0] = '=';
    for (s=tp_line[0]; *s; s++)
	if (*s == '*')
	    *s = '-';
    for (i=0; n <= p_end; i++,n++) {
	p_line[n] = tp_line[i];
	p_Char[n] = tp_char[i];
	if (p_Char[n] == '-')
	    p_Char[n] = '+';
	p_len[n] = tp_len[i];
    }
    assert(i == p_ptrn_lines + 1);
    i = p_ptrn_lines;
    p_ptrn_lines = p_repl_lines;
    p_repl_lines = i;
    p_Char[p_end + 1] = '^';
    free (tp_line);
    free (tp_len);
    free (tp_char);
}

/* Return whether file WHICH (false = old, true = new) appears to nonexistent.
   Return 1 for empty, 2 for nonexistent.  */

char
pch_says_nonexistent (bool which)
{
  return p_says_nonexistent[which];
}

char *
pch_name (enum nametype type)
{
  return type == NONE ? nullptr : p_name[type];
}

bool pch_copy (void)
{
  return p_copy[OLD] && p_copy[NEW];
}

bool pch_rename (void)
{
  return p_rename[OLD] && p_rename[NEW];
}

/* Return the specified line position in the old file of the old context. */

idx_t
pch_first (void)
{
    return p_first;
}

/* Return the number of lines of old context. */

idx_t
pch_ptrn_lines (void)
{
    return p_ptrn_lines;
}

/* Return the probable line position in the new file of the first line. */

idx_t
pch_newfirst (void)
{
    return p_newfirst;
}

/* Return the number of lines in the replacement text including context. */

idx_t
pch_repl_lines (void)
{
    return p_repl_lines;
}

/* Return the number of lines in the whole hunk. */

idx_t
pch_end (void)
{
    return p_end;
}

/* Return the number of context lines before the first changed line. */

idx_t
pch_prefix_context (void)
{
    return p_prefix_context;
}

/* Return the number of context lines after the last changed line. */

idx_t
pch_suffix_context (void)
{
    return p_suffix_context;
}

/* Return the length of a particular patch line. */

idx_t
pch_line_len (idx_t line)
{
    return p_len[line];
}

/* Return the control character (+, -, *, !, etc) for a patch line.  A '\n'
   indicates an empty line in a hunk.  (The empty line is not part of the
   old or new context.  For some reason, the context format allows that.)  */

char
pch_char (idx_t line)
{
    return p_Char[line];
}

/* Return a pointer to a particular patch line. */

char *
pfetch (idx_t line)
{
    return p_line[line];
}

/* Output a patch line.  */

bool
pch_write_line (idx_t line, FILE *file)
{
  bool after_newline =
    (p_len[line] > 0) && (p_line[line][p_len[line] - 1] == '\n');

  Fwrite (p_line[line], sizeof (*p_line[line]), p_len[line], file);
  return after_newline;
}

/* Return where in the patch file this hunk began, for error messages. */

idx_t
pch_hunk_beg (void)
{
    return p_hunk_beg;
}

char const *
pch_c_function (void)
{
    return p_c_function;
}

/* Return true if in a git-style patch. */

bool
pch_git_diff (void)
{
  return p_git_diff;
}

char const *
pch_timestr (bool which)
{
  return p_timestr[which];
}

mode_t
pch_mode (bool which)
{
  return p_mode[which];
}

/* Is the newline-terminated line a valid 'ed' command for patch
   input?  If so, return the command character; if not, return 0.
   This accepts just a subset of the valid commands, but it's
   good enough in practice.  */

static char ATTRIBUTE_PURE
get_ed_command_letter (char const *line)
{
  char const *p = line;
  char letter;
  bool pair = false;

  if (c_isdigit (*p))
    {
      while (c_isdigit (*++p))
	/* do nothing */ ;
      if (*p == ',')
	{
	  if (! c_isdigit (*++p))
	    return 0;
	  while (c_isdigit (*++p))
	    /* do nothing */ ;
	  pair = true;
	}
    }

  letter = *p++;

  switch (letter)
    {
    case 'a':
    case 'i':
      if (pair)
	return 0;
      break;

    case 'c':
    case 'd':
      break;

    case 's':
      if (strncmp (p, "/.//", 4) != 0)
	return 0;
      p += 4;
      break;

    default:
      return 0;
    }

  while (c_isblank (*p))
    p++;
  if (*p == '\n')
    return letter;
  return 0;
}

/* GCC misunderstands dup2; see
   <https://gcc.gnu.org/bugzilla/show_bug.cgi?id=109839>.  */
#if 13 <= __GNUC__
# pragma GCC diagnostic ignored "-Wanalyzer-fd-leak"
#endif

/* Apply an ed script by feeding ed itself. */

void
do_ed_script (char *input_name, struct outfile *output, FILE *ofp)
{
    char const *output_name = output->name;
    off_t beginning_of_this_line;
    FILE *tmpfp = 0;
    int tmpfd = -1; /* placate gcc's -Wmaybe-uninitialized */

    if (! dry_run && ! skip_rest_of_patch)
      {
	/* Write ed script to a temporary file.  This causes ed to abort on
	   invalid commands such as when line numbers or ranges exceed the
	   number of available lines.  When ed reads from a pipe, it rejects
	   invalid commands and treats the next line as a new command, which
	   can lead to arbitrary command execution.  */

	tmpfd = make_tempfile (&tmped, 'e', nullptr, O_RDWR | O_BINARY, 0);
	if (tmpfd < 0)
	  pfatal ("Can't create temporary file %s", quotearg (tmped.name));
	tmpfp = fdopen (tmpfd, "w+b");
	if (! tmpfp)
	  pfatal ("Can't open stream for file %s", quotearg (tmped.name));
      }

    for (;;) {
	char ed_command_letter;
	beginning_of_this_line = Ftello (pfp);
	idx_t chars_read = get_line (false);
	if (! chars_read) {
	    next_intuit_at(beginning_of_this_line,p_input_line);
	    break;
	}
	ed_command_letter = get_ed_command_letter (patchbuf);
	if (ed_command_letter) {
	    if (tmpfp)
	      Fwrite (patchbuf, 1, chars_read, tmpfp);
	    if (ed_command_letter != 'd' && ed_command_letter != 's') {
	        p_pass_comments_through = true;
		while ((chars_read = get_line (true)) != 0) {
		    if (tmpfp)
		      Fwrite (patchbuf, 1, chars_read, tmpfp);
		    if (chars_read == 2  &&  strEQ (patchbuf, ".\n"))
			break;
		}
		p_pass_comments_through = false;
	    }
	}
	else {
	    next_intuit_at(beginning_of_this_line,p_input_line);
	    break;
	}
    }
    if (!tmpfp)
      return;
    static char const w_q[] = { 'w', '\n', 'q', '\n' };
    Fwrite (w_q, 1, sizeof w_q, tmpfp);
    Fflush (tmpfp);

    if (lseek (tmpfd, 0, SEEK_SET) < 0)
      pfatal ("Can't rewind to the beginning of file %s",
	      quotearg (tmped.name));

    if (inerrno != ENOENT)
      copy_file (input_name, &instat, output, nullptr,
		 output->exists ? 0 : O_EXCL, instat.st_mode, 0, true);
    Fflush (stdout);

    int stdin_dup = dup (STDIN_FILENO);
    if (stdin_dup < 0 || dup2 (tmpfd, STDIN_FILENO) < 0)
      pfatal ("Failed to duplicate standard input");
    assert (output_name[0] != '!' && output_name[0] != '-');
    idx_t output_namelen = quote_system_arg (nullptr, output_name);
    char *command = ximalloc (sizeof (EDITOR_PROGRAM " - ") + output_namelen);
    char *p = command;
    p = stpcpy (p, EDITOR_PROGRAM " - ");
    p += quote_system_arg (p, output_name);
    *p = '\0';
    int status = systemic (command);
    free (command);
    if (status != EXIT_SUCCESS)
      fatal ("%s FAILED", EDITOR_PROGRAM);
    if (dup2 (stdin_dup, STDIN_FILENO) < 0 || close (stdin_dup) < 0)
      pfatal ("Failed to duplicate standard input");

    Fclose (tmpfp);

    if (ofp)
      {
	FILE *ifp = fopen (output_name, binary_transput ? "rb" : "r");
	int c;
	if (!ifp)
	  pfatal ("can't open '%s'", output_name);
	while (0 <= (c = getc (ifp)))
	  Fputc (c, ofp);
	if (ferror (ifp) || fclose (ifp) < 0)
	  read_fatal ();
      }
}

void
pch_normalize (enum diff format)
{
  idx_t old = 1;
  idx_t new = p_ptrn_lines + 1;

  while (p_Char[new] == '=' || p_Char[new] == '\n')
    new++;

  if (format == UNI_DIFF)
    {
      /* Convert '!' markers into '-' and '+' as defined by the Unified
         Format.  */

      for (; old <= p_ptrn_lines; old++)
	if (p_Char[old] == '!')
	  p_Char[old] = '-';
      for (; new <= p_end; new++)
	if (p_Char[new] == '!')
	  p_Char[new] = '+';
    }
  else
    {
      /* Convert '-' and '+' markers which are part of a group into '!' as
	 defined by the Context Format.  */

      while (old <= p_ptrn_lines)
	{
	  if (p_Char[old] == '-')
	    {
	      if (new <= p_end && p_Char[new] == '+')
		{
		  do
		    {
		      p_Char[old] = '!';
		      old++;
		    }
		  while (old <= p_ptrn_lines && p_Char[old] == '-');
		  do
		    {
		      p_Char[new] = '!';
		      new++;
		    }
		  while (new <= p_end && p_Char[new] == '+');
		}
	      else
		{
		  do
		    old++;
		  while (old <= p_ptrn_lines && p_Char[old] == '-');
		}
	    }
	  else if (new <= p_end && p_Char[new] == '+')
	    {
	      do
		new++;
	      while (new <= p_end && p_Char[new] == '+');
	    }
	  else
	    {
	      old++;
	      new++;
	    }
	}
    }
}
