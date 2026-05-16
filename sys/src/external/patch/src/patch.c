/* patch - a program to apply diffs to original files */

/* Copyright 1989-2025 Free Software Foundation, Inc.
   Copyright 1984-1988 Larry Wall

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
#include <argmatch.h>
#include <closeout.h>
#include <exitfail.h>
#include <getopt.h>
#include <inp.h>
#include <pch.h>
#include <quotearg.h>
#include <util.h>
#include <version.h>
#include <xalloc.h>
#include <xstdopen.h>
#include <safe.h>

#ifndef __has_feature
# define __has_feature(a) false
#endif

#if defined __SANITIZE_ADDRESS__ || __has_feature (address_sanitizer)
# define SANITIZE_ADDRESS true
#else
# define SANITIZE_ADDRESS false
#endif

/* See common.h for the declarations of these variables.  */

bool batch;
bool canonicalize_ws;
bool dry_run;
bool follow_symlinks;
bool force;
bool no_strip_trailing_cr;
bool noreverse_flag;
bool posixly_correct;
bool reverse_flag;
bool set_time;
bool set_utc;
bool skip_rest_of_patch;
char *inname;
char *outfile;
char *revision;
char const *origbase;
char const *origprae;
char const *origsuff;
enum conflict_style conflict_style;
enum diff diff_type;
enum verbosity verbosity;
idx_t last_frozen_line;
#ifndef binary_transput
int binary_transput;
#endif
int inerrno;
intmax_t patch_get;
intmax_t strippath;
ptrdiff_t in_offset;
ptrdiff_t out_offset;
signed char invc;
struct stat instat;
struct outfile tmped = { .temporary = true };
struct outfile tmppat = { .temporary = true };
#ifndef debug
unsigned short int debug;
#endif

/* procedures */

static FILE *create_output_file (struct outfile *, int);
static idx_t locate_hunk (idx_t);
static bool check_line_endings (idx_t);
static bool apply_hunk (struct outstate *, idx_t);
static bool patch_match (idx_t, idx_t, idx_t, idx_t);
static bool spew_output (struct outstate *, struct stat *);
static intmax_t numeric_string (char const *, bool, char const *);
static void perfile_cleanup_remove (void);
static void cleanup_remove (void);
static void perfile_cleanup_free (void);
static void get_some_switches (int, char **);
static void init_output (struct outstate *);
static FILE *open_outfile (char *);
static void init_reject (char const *);
static void reinitialize_almost_everything (void);
_Noreturn static void usage (FILE *, int);

static void abort_hunk (char const *, bool, bool);
static void abort_hunk_context (bool, bool);
static void abort_hunk_unified (bool, bool);

static void output_file (struct outfile *, const struct stat *, char *,
			 const struct stat *, mode_t, bool);

static void delete_files (void);
static void output_files (struct stat const *, int);

#ifdef ENABLE_MERGE
static bool merge;
#else
# define merge false
#endif

static enum diff reject_format = NO_DIFF;  /* automatic */
static bool make_backups;
static bool backup_if_mismatch;
static bool backup_if_mismatch_specified;
static char const *version_control;
static char const *version_control_context;
static bool remove_empty_files;
static bool explicit_inname;
static enum { RO_IGNORE, RO_WARN, RO_FAIL } read_only_behavior = RO_WARN;

/* true if -R was specified on command line.  */
static bool reverse_flag_specified;

static char const *do_defines; /* symbol to patch using ifdef, ifndef, etc. */
static char const if_defined[] = "\n#ifdef ";
static char const not_defined[] = "\n#ifndef ";
static char const else_defined[] = "\n#else\n";
static char const end_defined[] = "\n#endif\n";

static FILE *rejfp;  /* reject file pointer */

static char const *patchname;
static struct outfile outrej;
static struct outfile tmpout = { .temporary = true };
static struct outfile tmprej = { .temporary = true };

static intmax_t maxfuzz = 2;

static char serrbuf[BUFSIZ];

/* Apply a set of diffs as appropriate. */

int
main (int argc, char **argv)
{
    char const *val;
    bool somefailed = false;
    struct outstate outstate;
    struct stat tmpoutst;
    bool skip_reject_file = false;
    bool apply_empty_patch = false;
    mode_t file_type;
    bool have_git_diff = false;

    exit_failure = EXIT_TROUBLE;
    set_program_name (argv[0]);
    init_time ();

    xstdopen ();
    setbuf(stderr, serrbuf);
    atexit (close_stdout);

    strippath = -1;

    val = getenv ("QUOTING_STYLE");
    {
      int i = val ? argmatch (val, quoting_style_args, 0, 0) : -1;
      set_quoting_style (nullptr, i < 0 ? shell_quoting_style : i);
    }

    posixly_correct = getenv ("POSIXLY_CORRECT") != 0;
    patch_get = ((val = getenv ("PATCH_GET"))
		 ? numeric_string (val, true, "PATCH_GET value")
		 : 0);

    val = getenv ("SIMPLE_BACKUP_SUFFIX");
    simple_backup_suffix = val && *val ? val : ".orig";

    if ((version_control = getenv ("PATCH_VERSION_CONTROL")))
      version_control_context = "$PATCH_VERSION_CONTROL";
    else if ((version_control = getenv ("VERSION_CONTROL")))
      version_control_context = "$VERSION_CONTROL";

    init_backup_hash_table ();

    /* parse switches */
    get_some_switches (argc, argv);

    /* Make get_date() assume that context diff headers use UTC. */
    if (set_utc && setenv ("TZ", "UTC0", 1) < 0)
      pfatal ("setenv");

    if (!backup_if_mismatch_specified)
      backup_if_mismatch = !posixly_correct;
    if (make_backups | backup_if_mismatch)
      backup_type = get_version (version_control_context, version_control);

    init_output (&outstate);
    if (outfile)
      outstate.ofp = open_outfile (outfile);

    /* Make sure we clean up in case of disaster.  */
    init_signals ();

    /* When the file to patch is specified on the command line, allow that file
       to lie outside the current working tree.  Still doesn't allow to follow
       symlinks.  */
    if (inname)
      unsafe = true;

    if (inname && outfile)
      {
	/* When an input and an output filename is given and the patch is
	   empty, copy the input file to the output file.  In this case, the
	   input file must be a regular file (i.e., symlinks cannot be copied
	   this way).  */
	apply_empty_patch = true;
	file_type = S_IFREG;
	inerrno = -1;
      }
    for (
	open_patch_file (patchname);
	there_is_another_patch (! (inname || posixly_correct), &file_type)
	  || apply_empty_patch;
	reinitialize_almost_everything(),
	  skip_reject_file = false,
	  apply_empty_patch = false
    ) {					/* for each patch in patch file */
      intmax_t hunk = 0;
      intmax_t failed = 0;
      bool mismatch = false;
      char *outname = nullptr;

      if (skip_rest_of_patch)
	somefailed = true;

      if (have_git_diff != pch_git_diff ())
	{
	  if (have_git_diff)
	    {
	      output_files (nullptr, 0);
	      inerrno = -1;
	    }
	  have_git_diff = ! have_git_diff;
	}

      if (rejfp)
	{
	  Fclose (rejfp);
	  rejfp = nullptr;
	}

      defer_signals ();
      perfile_cleanup_remove ();
      undefer_signals ();
      perfile_cleanup_free ();

      if (! skip_rest_of_patch && ! file_type)
	{
	  unsigned int old_mode = pch_mode (  reverse_flag) & S_IFMT;
	  unsigned int new_mode = pch_mode (! reverse_flag) & S_IFMT;
	  say ("File %s: can't change file type from %#o to %#o.\n",
	       quotearg (inname), old_mode, new_mode);
	  skip_rest_of_patch = true;
	  somefailed = true;
	}

      if (! skip_rest_of_patch)
	{
	  if (outfile)
	    outname = outfile;
	  else if (pch_copy () || pch_rename ())
	    outname = pch_name (! reverse_flag);
	  else
	    outname = inname;
	}

      if (pch_git_diff () && ! skip_rest_of_patch)
	{
	  struct stat outstat;
	  int outerrno = 0;

	  /* Try to recognize concatenated git diffs based on the SHA1 hashes
	     in the headers.  Will not always succeed for patches that rename
	     or copy files.  */

	  if (! strcmp (inname, outname))
	    {
	      if (inerrno == -1)
		inerrno = stat_file (inname, &instat);
	      outstat = instat;
	      outerrno = inerrno;
	    }
	  else
	    outerrno = stat_file (outname, &outstat);

	  if (! outerrno)
	    {
	      if (has_queued_output (&outstat))
		{
		  output_files (&outstat, 0);
		  outerrno = stat_file (outname, &outstat);
		  inerrno = -1;
		}
	      if (! outerrno)
		set_queued_output (&outstat, true);
	    }
	}

      if (! skip_rest_of_patch)
	{
	  if (! get_input_file (inname, outname, file_type))
	    {
	      skip_rest_of_patch = true;
	      somefailed = true;
	    }
	}

      if (read_only_behavior != RO_IGNORE
	  && ! inerrno && ! S_ISLNK (instat.st_mode)
	  && safe_access (inname, W_OK) != 0)
	{
	  say ("File %s is read-only; ", quotearg (inname));
	  if (read_only_behavior == RO_WARN)
	    say ("trying to patch anyway\n");
	  else
	    {
	      say ("refusing to patch\n");
	      skip_rest_of_patch = true;
	      somefailed = true;
	    }
	}

      tmpoutst.st_size = -1;
      int outfd = make_tempfile (&tmpout, 'o', outname,
				 O_WRONLY | binary_transput,
				 instat.st_mode & S_IRWXUGO);
      if (outfd < 0)
	{
	  /* FIXME: Explain why ELOOP and EXDEV are special here.  */
	  if (diff_type == ED_DIFF
	      || ! (errno == ELOOP || errno == EXDEV))
	    pfatal ("Can't create temporary file %s", tmpout.name);

	  say ("Invalid file name %s -- skipping patch\n", quotearg (outname));
	  skip_rest_of_patch = true;
	  skip_reject_file = true;
	  somefailed = true;
	}
      if (!outfile)
	init_output (&outstate);
      int ifd = -1;

      if (diff_type == ED_DIFF) {
	outstate.zero_output = false;
	somefailed |= skip_rest_of_patch;
	do_ed_script (inname, &tmpout, outstate.ofp);
	if (! dry_run && ! outfile && ! skip_rest_of_patch)
	  {
	    if (fstat (outfd, &tmpoutst) != 0)
	      pfatal ("%s", tmpout.name);
	    outstate.zero_output = tmpoutst.st_size == 0;
	  }
      } else {
	bool apply_anyway = merge;  /* don't try to reverse when merging */

	if (! skip_rest_of_patch && diff_type == GIT_BINARY_DIFF) {
	  say ("File %s: git binary diffs are not supported.\n",
	       quotearg (outname));
	  skip_rest_of_patch = true;
	  somefailed = true;
	}
	/* initialize the patched file */
	if (! skip_rest_of_patch && ! outfile)
	  {
	    outstate.ofp = fdopen (outfd, binary_transput ? "wb" : "w");
	    if (! outstate.ofp)
	      pfatal ("%s", tmpout.name);
	    /* outstate.ofp now owns the file descriptor */
	  }
	else
	  {
	    /* When writing to a single output file (-o FILE), always pretend
	       that the output file ends in a newline.  Otherwise, when another
	       file is written to the same output file, apply_hunk will fail.  */
	    outstate.after_newline = true;
	  }

	/* find out where all the lines are */
	if (!skip_rest_of_patch) {
	    if (S_ISREG (file_type) && instat.st_size != 0)
	      {
		int oflags = (O_RDONLY | binary_transput
			      | (follow_symlinks ? 0 : O_NOFOLLOW));
		ifd = safe_open (inname, oflags, 0);
		if (ifd < 0)
		  pfatal ("Can't open file %s", quotearg (inname));
	      }

	    scan_input (inname, file_type, ifd);

	    if (verbosity != SILENT)
	      {
		bool renamed = strcmp (inname, outname);
		bool skip_rename = ! renamed && pch_rename ();

		say ("%s %s %s%c",
		     dry_run ? "checking" : "patching",
		     S_ISLNK (file_type) ? "symbolic link" : "file",
		     quotearg (outname), renamed || skip_rename ? ' ' : '\n');
		if (renamed || skip_rename)
		  say ("(%s%s from %s)\n",
		       skip_rename ? "already " : "",
		       pch_copy () ? "copied" :
		       (pch_rename () ? "renamed" : "read"),
		       ! skip_rename ? inname : pch_name (! strcmp (inname, pch_name (OLD))));
	      }
	}

	/* apply each hunk of patch */
	while (another_hunk (diff_type, reverse_flag))
	  {
	    idx_t where = 0; /* Pacify 'gcc -Wall'.  */
	    idx_t newwhere;
	    idx_t fuzz = 0;
	    idx_t mymaxfuzz;

	    if (merge)
	      {
		/* When in merge mode, don't apply with fuzz.  */
		mymaxfuzz = 0;
	      }
	    else
	      {
		idx_t prefix_context = pch_prefix_context ();
		idx_t suffix_context = pch_suffix_context ();
		idx_t context = MAX (prefix_context, suffix_context);
		mymaxfuzz = MIN (maxfuzz, context);
	      }

	    hunk++;
	    if (!skip_rest_of_patch) {
		bool incr_fuzz;
		do {
		    incr_fuzz = true;
		    where = locate_hunk(fuzz);
		    if (! where || fuzz || in_offset)
		      mismatch = true;
		    if (hunk == 1 && ! where && ! (force | apply_anyway)
			&& reverse_flag == reverse_flag_specified) {
						/* dwim for reversed patch? */
			pch_swap ();
			/* Try again.  */
			where = locate_hunk (fuzz);
			if (where
			    && (ok_to_reverse
				("%s patch detected!",
				 (reverse_flag
				  ? "Unreversed"
				  : "Reversed (or previously applied)"))))
			  reverse_flag = ! reverse_flag;
			else
			  {
			    /* Put it back to normal.  */
			    pch_swap ();
			    if (where)
			      {
				apply_anyway = true;
				incr_fuzz = false;
				where = 0;
			      }
			  }
		    }
		} while (!skip_rest_of_patch && !where
			 && (fuzz += incr_fuzz) <= mymaxfuzz);
	    }

	    newwhere = (where ? where : pch_first()) + out_offset;
	    if (skip_rest_of_patch
		|| (merge && ! merge_hunk (hunk, &outstate, where,
					   &somefailed))
		|| (! merge
		    && ((where == 1 && pch_says_nonexistent (reverse_flag) == 2
			 && instat.st_size)
			|| ! where
			|| ! apply_hunk (&outstate, where))))
	      {
		if (! skip_reject_file)
		  abort_hunk (outname, ! failed, reverse_flag);
		failed++;
		if (verbosity == VERBOSE ||
		    (! skip_rest_of_patch && verbosity != SILENT))
		  say ("Hunk #%jd %s at %td%s.\n", hunk,
		       skip_rest_of_patch ? "ignored" : "FAILED",
		       newwhere,
		       ! skip_rest_of_patch && check_line_endings (newwhere)
			 ?  " (different line endings)" : "");
	      }
	    else if (! merge &&
		     (verbosity == VERBOSE
		      || (verbosity != SILENT && (fuzz || in_offset))))
	      {
		say ("Hunk #%jd succeeded at %td", hunk, newwhere);
		if (fuzz)
		  say (" with fuzz %td", fuzz);
		if (in_offset)
		  say (" (offset %td line%s)", in_offset,
		       &"s"[in_offset == 1]);
		say (".\n");
	      }
	  }

	if (!skip_rest_of_patch)
	  {
	    /* Finish spewing out the new file.  */
	    if (! spew_output (&outstate, &tmpoutst))
	      {
		say ("Skipping patch.\n");
		skip_rest_of_patch = true;
	      }
	  }
      }

      /* and put the output where desired */
      bool replace_file = false, backup;
      mode_t mode;
      if (! skip_rest_of_patch && ! outfile) {
	  backup = make_backups || (backup_if_mismatch && (mismatch | failed));
	  if (outstate.zero_output
	      && (remove_empty_files
		  || (pch_says_nonexistent (! reverse_flag) == 2
		      && ! posixly_correct)
		  || S_ISLNK (file_type)))
	    {
	      if (! dry_run)
		output_file (nullptr, nullptr, outname,
			     (inname == outname) ? &instat : nullptr,
			     file_type | 0, backup);
	    }
	  else
	    {
	      if (! outstate.zero_output
		  && pch_says_nonexistent (! reverse_flag) == 2
		  && (remove_empty_files || ! posixly_correct)
		  && ! (merge && somefailed))
		{
		  mismatch = true;
		  somefailed = true;
		  if (verbosity != SILENT)
		    say ("Not deleting file %s as content differs from patch\n",
			 quotearg (outname));
		}

	      if (! dry_run)
		{
		  mode_t old_mode = pch_mode (reverse_flag);
		  mode_t new_mode = pch_mode (! reverse_flag);
		  bool set_mode = new_mode && old_mode != new_mode;

		  /* Avoid replacing files when nothing has changed.  */
		  if (failed < hunk || diff_type == ED_DIFF || set_mode
		      || pch_copy () || pch_rename ())
		    {
		      enum file_attributes attr = 0;
		      struct timespec new_time = p_timestamp[! reverse_flag];
		      mode = file_type |
			  ((set_mode ? new_mode : instat.st_mode) & S_IRWXUGO);

		      if ((set_time | set_utc) && 0 <= new_time.tv_nsec)
			{
			  struct timespec old_time = p_timestamp[reverse_flag];

			  if (! force && ! inerrno
			      && pch_says_nonexistent (reverse_flag) != 2
			      && 0 <= old_time.tv_nsec
			      && timespec_cmp (old_time,
					       get_stat_mtime (&instat)))
			    say ("Not setting time of file %s "
				 "(time mismatch)\n",
				 quotearg (outname));
			  else if (! force && (mismatch | failed))
			    say ("Not setting time of file %s "
				 "(contents mismatch)\n",
				 quotearg (outname));
			  else
			    attr |= FA_TIMES;
			}

		      if (inerrno)
		        {
			  if (set_mode)
			    attr |= FA_MODE;
			  set_file_attributes (tmpout.name, outfd, attr,
					       nullptr, -1, nullptr,
					       mode, &new_time);
			}
		      else
			{
			  attr |= FA_IDS | FA_MODE | FA_XATTRS;
			  set_file_attributes (tmpout.name, outfd, attr,
					       inname, ifd,
					       &instat, mode, &new_time);
			}

		      replace_file = true;
		    }
		  else if (backup)
		    {
		      struct stat outstat;

		      if (stat_file (outname, &outstat) != 0)
			say ("Cannot stat file %s, skipping backup\n", outname);
		      else
			output_file (&(struct outfile) { .name = outname },
				     &outstat, nullptr, nullptr,
				     file_type | 0, true);
		    }
		}
	    }
      }

      if (0 <= ifd && close (ifd) < 0)
	read_fatal ();

      if (!outfile)
	{
	  if (outstate.ofp)
	    {
	      Fclose (outstate.ofp);
	      outstate.ofp = nullptr;
	    }
	  else if (0 <= outfd && close (outfd) < 0)
	    write_fatal ();
	}

      if (replace_file)
	{
	  output_file (&tmpout, &tmpoutst, outname, nullptr, mode, backup);
	  if (pch_rename ())
	    output_file (nullptr, nullptr, inname, &instat, mode, backup);
	}

      if (diff_type != ED_DIFF) {
	struct stat rejst;

	if (failed && ! skip_reject_file) {
	    Fflush (rejfp);
	    if (fstat (fileno (rejfp), &rejst) < 0)
	      write_fatal ();
	    Fclose (rejfp);
	    rejfp = nullptr;
	    somefailed = true;
	    say ("%jd out of %jd hunk%s %s", failed, hunk, &"s"[hunk == 1],
		 skip_rest_of_patch ? "ignored" : "FAILED");
	    char *rejname = outrej.name;
	    if (outname && (! rejname || strcmp (rejname, "-") != 0)) {
		char *rej = rejname;
		if (!rejname) {
		    /* FIXME: This should really be done differently!  */
		    const char *s = simple_backup_suffix;
		    simple_backup_suffix = ".rej";
		    rej = find_backup_file_name (AT_FDCWD, outname, simple_backups);
		    idx_t len = strlen (rej);
		    if (rej[len - 1] == '~')
		      rej[len - 1] = '#';
		    simple_backup_suffix = s;
		}
		if (! dry_run)
		  {
		    say (" -- saving rejects to file %s\n", quotearg (rej));
		    if (rejname)
		      {
			if (!outrej.exists)
			  copy_file (tmprej.name, nullptr, &outrej, nullptr, 0,
				     S_IFREG | 0666, 0, true);
			else
			  append_to_file (tmprej.name, rejname);
		      }
		    else
		      {
			struct stat oldst;
			int olderrno;

			olderrno = stat_file (rej, &oldst);
			if (olderrno && olderrno != ENOENT)
			  write_fatal ();
		        if (! olderrno && lookup_file_id (&oldst) == CREATED)
			  append_to_file (tmprej.name, rej);
			else
			  move_file (&tmprej,
				     &rejst, rej, S_IFREG | 0666, false);
		      }
		  }
		else
		  say ("\n");
		if (!rejname)
		    free (rej);
	    } else
	      say ("\n");
	}
      }
    }
    if (outstate.ofp)
      Fclose (outstate.ofp);

    defer_signals ();
    cleanup_remove ();
    undefer_signals ();

    output_files (nullptr, 1);
    delete_files ();
    return somefailed ? EXIT_FAILURE : EXIT_SUCCESS;
}

/* Prepare to find the next patch to do in the patch file. */

static void
reinitialize_almost_everything (void)
{
    re_patch();
    re_input();

    input_lines = 0;
    last_frozen_line = 0;

    if (inname && ! explicit_inname) {
	free (inname);
	inname = 0;
    }

    in_offset = 0;
    out_offset = 0;

    diff_type = NO_DIFF;

    if (revision) {
	free(revision);
	revision = 0;
    }

    reverse_flag = reverse_flag_specified;
    skip_rest_of_patch = false;
}

static char const shortopts[] = "bB:cd:D:eEfF:g:i:l"
#if 0 && defined ENABLE_MERGE
				"m"
#endif
				"nNo:p:r:RstTuvV:x:Y:z:Z";

static struct option const longopts[] =
{
  {"backup", no_argument, nullptr, 'b'},
  {"prefix", required_argument, nullptr, 'B'},
  {"context", no_argument, nullptr, 'c'},
  {"directory", required_argument, nullptr, 'd'},
  {"ifdef", required_argument, nullptr, 'D'},
  {"ed", no_argument, nullptr, 'e'},
  {"remove-empty-files", no_argument, nullptr, 'E'},
  {"force", no_argument, nullptr, 'f'},
  {"fuzz", required_argument, nullptr, 'F'},
  {"get", required_argument, nullptr, 'g'},
  {"input", required_argument, nullptr, 'i'},
  {"ignore-whitespace", no_argument, nullptr, 'l'},
#ifdef ENABLE_MERGE
  {"merge", optional_argument, nullptr, 'm'},
#endif
  {"normal", no_argument, nullptr, 'n'},
  {"forward", no_argument, nullptr, 'N'},
  {"output", required_argument, nullptr, 'o'},
  {"strip", required_argument, nullptr, 'p'},
  {"reject-file", required_argument, nullptr, 'r'},
  {"reverse", no_argument, nullptr, 'R'},
  {"quiet", no_argument, nullptr, 's'},
  {"silent", no_argument, nullptr, 's'},
  {"batch", no_argument, nullptr, 't'},
  {"set-time", no_argument, nullptr, 'T'},
  {"unified", no_argument, nullptr, 'u'},
  {"version", no_argument, nullptr, 'v'},
  {"version-control", required_argument, nullptr, 'V'},
  {"debug", required_argument, nullptr, 'x'},
  {"basename-prefix", required_argument, nullptr, 'Y'},
  {"suffix", required_argument, nullptr, 'z'},
  {"set-utc", no_argument, nullptr, 'Z'},
  {"dry-run", no_argument, nullptr, CHAR_MAX + 1},
  {"verbose", no_argument, nullptr, CHAR_MAX + 2},
  {"binary", no_argument, nullptr, CHAR_MAX + 3},
  {"help", no_argument, nullptr, CHAR_MAX + 4},
  {"backup-if-mismatch", no_argument, nullptr, CHAR_MAX + 5},
  {"no-backup-if-mismatch", no_argument, nullptr, CHAR_MAX + 6},
  {"posix", no_argument, nullptr, CHAR_MAX + 7},
  {"quoting-style", required_argument, nullptr, CHAR_MAX + 8},
  {"reject-format", required_argument, nullptr, CHAR_MAX + 9},
  {"read-only", required_argument, nullptr, CHAR_MAX + 10},
  {"follow-symlinks", no_argument, nullptr, CHAR_MAX + 11},
  {nullptr, no_argument, nullptr, 0}
};

static char const *const option_help[] =
{
"Input options:",
"",
"  -p NUM  --strip=NUM  Strip NUM leading components from file names.",
"  -F LINES  --fuzz LINES  Set the fuzz factor to LINES for inexact matching.",
"  -l  --ignore-whitespace  Ignore white space changes between patch and input.",
"",
"  -c  --context  Interpret the patch as a context difference.",
"  -e  --ed  Interpret the patch as an ed script.",
"  -n  --normal  Interpret the patch as a normal difference.",
"  -u  --unified  Interpret the patch as a unified difference.",
"",
"  -N  --forward  Ignore patches that appear to be reversed or already applied.",
"  -R  --reverse  Assume patches were created with old and new files swapped.",
"",
"  -i PATCHFILE  --input=PATCHFILE  Read patch from PATCHFILE instead of stdin.",
"",
"Output options:",
"",
"  -o FILE  --output=FILE  Output patched files to FILE.",
"  -r FILE  --reject-file=FILE  Output rejects to FILE.",
"",
"  -D NAME  --ifdef=NAME  Make merged if-then-else output using NAME.",
#ifdef ENABLE_MERGE
"  --merge  Merge using conflict markers instead of creating reject files.",
#endif
"  -E  --remove-empty-files  Remove output files that are empty after patching.",
"",
"  -Z  --set-utc  Set times of patched files, assuming diff uses UTC (GMT).",
"  -T  --set-time  Likewise, assuming local time.",
"",
"  --quoting-style=WORD   output file names using quoting style WORD.",
"    Valid WORDs are: literal, shell, shell-always, c, escape.",
"    Default is taken from QUOTING_STYLE env variable, or 'shell' if unset.",
"",
"Backup and version control options:",
"",
"  -b  --backup  Back up the original contents of each file.",
"  --backup-if-mismatch  Back up if the patch does not match exactly.",
"  --no-backup-if-mismatch  Back up mismatches only if otherwise requested.",
"",
"  -V STYLE  --version-control=STYLE  Use STYLE version control.",
"	STYLE is either 'simple', 'numbered', or 'existing'.",
"  -B PREFIX  --prefix=PREFIX  Prepend PREFIX to backup file names.",
"  -Y PREFIX  --basename-prefix=PREFIX  Prepend PREFIX to backup file basenames.",
"  -z SUFFIX  --suffix=SUFFIX  Append SUFFIX to backup file names.",
"",
"  -g NUM  --get=NUM  Get files from RCS etc. if positive; ask if negative.",
"",
"Miscellaneous options:",
"",
"  -t  --batch  Ask no questions; skip bad-Prereq patches; assume reversed.",
"  -f  --force  Like -t, but ignore bad-Prereq patches, and assume unreversed.",
"  -s  --quiet  --silent  Work silently unless an error occurs.",
"  --verbose  Output extra information about the work being done.",
"  --dry-run  Do not actually change any files; just print what would happen.",
"  --posix  Conform to the POSIX standard.",
"",
"  -d DIR  --directory=DIR  Change the working directory to DIR first.",
"  --reject-format=FORMAT  Create 'context' or 'unified' rejects.",
"  --binary  Read and write data in binary mode.",
"  --read-only=BEHAVIOR  How to handle read-only input files: 'ignore' that they",
"                        are read-only, 'warn' (default), or 'fail'.",
"",
"  -v  --version  Output version info.",
"  --help  Output this help.",
"",
"Report bugs to <" PACKAGE_BUGREPORT ">.",
0
};

static void
usage (FILE *stream, int status)
{
  char const * const *p;

  if (status != EXIT_SUCCESS)
    {
      Fprintf (stream, "%s: Try '%s --help' for more information.\n",
	       program_name, program_name);
    }
  else
    {
      Fprintf (stream, "Usage: %s [OPTION]... [ORIGFILE [PATCHFILE]]\n\n",
	       program_name);
      for (p = option_help;  *p;  p++)
	Fprintf (stream, "%s\n", *p);
    }

  exit (status);
}

/* Process a backup file name option argument of type OPTION_TYPE.  */
static char const *
backup_file_name_option (char const *option_type)
{
  if (!*optarg)
    fatal ("backup %s is empty", option_type);
  return xstrdup (optarg);
}

/* Process switches and filenames.  */

static void
get_some_switches (int argc, char **argv)
{
    int optc;
    while (0 <= (optc = getopt_long (argc, argv, shortopts, longopts, nullptr)))
	switch (optc) {
	    case 'b':
		make_backups = true;
		 /* Special hack for backward compatibility with CVS 1.9.
		    If the last 4 args are '-b SUFFIX ORIGFILE PATCHFILE',
		    treat '-b' as if it were '-b -z'.  */
		if (argc - optind == 3
		    && strcmp (argv[optind - 1], "-b") == 0
		    && ! (argv[optind + 0][0] == '-' && argv[optind + 0][1])
		    && ! (argv[optind + 1][0] == '-' && argv[optind + 1][1])
		    && ! (argv[optind + 2][0] == '-' && argv[optind + 2][1]))
		  {
		    optarg = argv[optind++];
		    if (verbosity != SILENT)
		      say ("warning: the '-b %s' option is obsolete; use '-b -z %s' instead\n",
			   optarg, optarg);
		    goto case_z;
		  }
		break;
	    case 'B':
		origprae = backup_file_name_option ("prefix");
		break;
	    case 'c':
		diff_type = CONTEXT_DIFF;
		break;
	    case 'd':
		if (chdir(optarg) < 0)
		  pfatal ("Can't change to directory %s", quotearg (optarg));
		break;
	    case 'D':
		do_defines = xstrdup (optarg);
		break;
	    case 'e':
		diff_type = ED_DIFF;
		break;
	    case 'E':
		remove_empty_files = true;
		break;
	    case 'f':
		force = true;
		break;
	    case 'F':
		maxfuzz = numeric_string (optarg, false, "fuzz factor");
		break;
	    case 'g':
		patch_get = numeric_string (optarg, true, "get option value");
		break;
	    case 'i':
		patchname = xstrdup (optarg);
		break;
	    case 'l':
		canonicalize_ws = true;
		break;
#ifdef ENABLE_MERGE
	    case 'm':
		merge = true;
		if (optarg)
		  {
		    if (! strcmp (optarg, "merge"))
		      conflict_style = MERGE_MERGE;
		    else if (! strcmp (optarg, "diff3"))
		      conflict_style = MERGE_DIFF3;
		    else
		      usage (stderr, EXIT_TROUBLE);
		  }
		else
		  conflict_style = MERGE_MERGE;
		break;
#endif
	    case 'n':
		diff_type = NORMAL_DIFF;
		break;
	    case 'N':
		noreverse_flag = true;
		break;
	    case 'o':
		outfile = xstrdup (optarg);
		break;
	    case 'p':
		strippath = numeric_string (optarg, false, "strip count");
		break;
	    case 'r':
		outrej.name = xstrdup (optarg);
		/* No need to set outrej.alloc, as outrej is never freed.  */
		break;
	    case 'R':
		reverse_flag = true;
		reverse_flag_specified = true;
		break;
	    case 's':
		verbosity = SILENT;
		break;
	    case 't':
		batch = true;
		break;
	    case 'T':
		set_time = true;
		break;
	    case 'u':
		diff_type = UNI_DIFF;
		break;
	    case 'v':
		version();
		exit (EXIT_SUCCESS);
		break;
	    case 'V':
		version_control = optarg;
		version_control_context = "--version-control or -V option";
		break;
#if DEBUGGING
	    case 'x':
		debug = numeric_string (optarg, true, "debugging option");
		break;
#endif
	    case 'Y':
		origbase = backup_file_name_option ("basename prefix");
		break;
	    case 'z':
	    case_z:
		origsuff = backup_file_name_option ("suffix");
		break;
	    case 'Z':
		set_utc = true;
		break;
	    case CHAR_MAX + 1:
		dry_run = true;
		break;
	    case CHAR_MAX + 2:
		verbosity = VERBOSE;
		break;
	    case CHAR_MAX + 3:
		no_strip_trailing_cr = true;
#if HAVE_SETMODE_DOS
		binary_transput = O_BINARY;
#endif
		break;
	    case CHAR_MAX + 4:
		usage (stdout, EXIT_SUCCESS);
	    case CHAR_MAX + 5:
		backup_if_mismatch = true;
		backup_if_mismatch_specified = true;
		break;
	    case CHAR_MAX + 6:
		backup_if_mismatch = false;
		backup_if_mismatch_specified = true;
		break;
	    case CHAR_MAX + 7:
		posixly_correct = true;
		break;
	    case CHAR_MAX + 8:
		{
		  int i = argmatch (optarg, quoting_style_args, 0, 0);
		  if (i < 0)
		    {
		      invalid_arg ("quoting style", optarg, i);
		      usage (stderr, EXIT_TROUBLE);
		    }
		  set_quoting_style (nullptr, i);
		}
		break;
	    case CHAR_MAX + 9:
		if (strcmp (optarg, "context") == 0)
		  reject_format = NEW_CONTEXT_DIFF;
		else if (strcmp (optarg, "unified") == 0)
		  reject_format = UNI_DIFF;
		else
		  usage (stderr, EXIT_TROUBLE);
		break;
	    case CHAR_MAX + 10:
		if (strcmp (optarg, "ignore") == 0)
		  read_only_behavior = RO_IGNORE;
		else if (strcmp (optarg, "warn") == 0)
		  read_only_behavior = RO_WARN;
		else if (strcmp (optarg, "fail") == 0)
		  read_only_behavior = RO_FAIL;
		else
		  usage (stderr, EXIT_TROUBLE);
		break;
	    case CHAR_MAX + 11:
		follow_symlinks = true;
		break;
	    default:
		usage (stderr, EXIT_TROUBLE);
	}

    /* Process any filename args.  */
    if (optind < argc)
      {
	inname = xstrdup (argv[optind++]);
	explicit_inname = true;
	invc = -1;
	if (optind < argc)
	  {
	    patchname = xstrdup (argv[optind++]);
	    if (optind < argc)
	      {
		Fprintf (stderr, "%s: %s: extra operand\n",
			 program_name, quotearg (argv[optind]));
		usage (stderr, EXIT_TROUBLE);
	      }
	  }
      }
}

/* Handle STRING (possibly negative if NEGATIVE_ALLOWED is nonzero)
   of type ARGTYPE_MSGID by converting it to an integer,
   returning the result.  If the integer does not fit,
   return an extreme value.  */
static intmax_t
numeric_string (char const *string,
		bool negative_allowed,
		char const *argtype_msgid)
{
  intmax_t value = 0;
  char const *p = string;
  bool negative = *p == '-';
  bool overflow = false;

  p += negative || *p == '+';

  do
    {
      if (!c_isdigit (*p))
	fatal ("%s %s is not a number", argtype_msgid, quotearg (string));
      overflow |= ckd_mul (&value, value, 10);
      overflow |= ckd_add (&value, value, negative ? '0' - *p : *p - '0');
    }
  while (*++p);

  if (value < 0 && ! negative_allowed)
    fatal ("%s %s is negative", argtype_msgid, quotearg (string));

  return !overflow ? value : negative ? INTMAX_MIN : INTMAX_MAX;
}

/* Attempt to find the right place to apply this hunk of patch. */

static idx_t
locate_hunk (idx_t fuzz)
{
    idx_t first_guess = pch_first () + in_offset;
    idx_t pat_lines = pch_ptrn_lines ();
    idx_t prefix_context = pch_prefix_context ();
    idx_t suffix_context = pch_suffix_context ();
    idx_t context = MAX (prefix_context, suffix_context);
    ptrdiff_t prefix_fuzz = fuzz + prefix_context - context;
    ptrdiff_t suffix_fuzz = fuzz + suffix_context - context;
    idx_t max_where = input_lines - (pat_lines - suffix_fuzz) + 1;
    idx_t min_where = last_frozen_line + 1;
    ptrdiff_t max_pos_offset = max_where - first_guess;
    ptrdiff_t max_neg_offset = first_guess - min_where;
    ptrdiff_t max_offset = MAX (max_pos_offset, max_neg_offset);
    ptrdiff_t min_offset;

    if (!pat_lines)			/* null range matches always */
	return first_guess;

    /* Do not try lines <= 0.  */
    if (first_guess <= max_neg_offset)
	max_neg_offset = first_guess - 1;

    if (prefix_fuzz < 0 && pch_first () <= 1)
      {
	/* Can only match start of file.  */

	if (suffix_fuzz < 0)
	  /* Can only match entire file.  */
	  if (pat_lines != input_lines || prefix_context < last_frozen_line)
	    return 0;

	ptrdiff_t offset = 1 - first_guess;
	if (last_frozen_line <= prefix_context
	    && offset <= max_pos_offset
	    && patch_match (first_guess, offset, 0, suffix_fuzz))
	  {
	    in_offset += offset;
	    return first_guess + offset;
	  }
	else
	  return 0;
      }
    else if (prefix_fuzz < 0)
      prefix_fuzz = 0;

    if (suffix_fuzz < 0)
      {
	/* Can only match end of file.  */
	ptrdiff_t offset = first_guess - (input_lines - pat_lines + 1);
	if (offset <= max_neg_offset
	    && patch_match (first_guess, -offset, prefix_fuzz, 0))
	  {
	    in_offset -= offset;
	    return first_guess - offset;
	  }
	else
	  return 0;
      }

    min_offset = max_pos_offset < 0 ? first_guess - max_where
	       : max_neg_offset < 0 ? first_guess - min_where
	       : 0;
    for (ptrdiff_t offset = min_offset; offset <= max_offset; offset++) {
	if (offset <= max_pos_offset
	    && patch_match (first_guess, offset, prefix_fuzz, suffix_fuzz)) {
	    if (debug & 1)
	      say ("Offset changing from %td to %td\n",
		   in_offset, in_offset + offset);
	    in_offset += offset;
	    return first_guess+offset;
	}
	if (offset <= max_neg_offset
	    && patch_match (first_guess, -offset, prefix_fuzz, suffix_fuzz)) {
	    if (debug & 1)
	      say ("Offset changing from %td to %td\n",
		   in_offset, in_offset - offset);
	    in_offset -= offset;
	    return first_guess-offset;
	}
    }
    return 0;
}

static void
mangled_patch (idx_t old, idx_t new)
{
  if (debug & 1)
    say ("oldchar = '%c', newchar = '%c'\n",
        pch_char (old), pch_char (new));
  fatal (("Out-of-sync patch, lines %td,%td"
	  " -- mangled text or line numbers, maybe?"),
	 pch_hunk_beg () + old, pch_hunk_beg () + new);
}

/* Output a line number range in unified format.  */

static void
print_unidiff_range (FILE *fp, idx_t start, idx_t count)
{
  switch (count)
    {
    case 0:
      Fprintf (fp, "%td,0", start - 1);
      break;

    case 1:
      Fprintf (fp, "%td", start);
      break;

    default:
      Fprintf (fp, "%td,%td", start, count);
      break;
    }
}

static void
print_header_line (FILE *fp, const char *tag, bool reverse)
{
  const char *name = pch_name (reverse);
  const char *timestr = pch_timestr (reverse);
  putline (fp, tag, name ? name : "/dev/null", timestr, nullptr);
}

/* Produce unified reject files */

static void
abort_hunk_unified (bool header, bool reverse)
{
  idx_t old = 1;
  idx_t lastline = pch_ptrn_lines ();
  idx_t new = lastline + 1;
  char const *c_function = pch_c_function();

  if (header)
    {
      if (pch_name (INDEX))
	putline (rejfp, "Index: ", pch_name (INDEX), nullptr);
      print_header_line (rejfp, "--- ", reverse);
      print_header_line (rejfp, "+++ ", ! reverse);
    }

  /* Add out_offset to guess the same as the previous successful hunk.  */
  Fputs ("@@ -", rejfp);
  print_unidiff_range (rejfp, pch_first () + out_offset, lastline);
  Fputs (" +", rejfp);
  print_unidiff_range (rejfp, pch_newfirst () + out_offset, pch_repl_lines ());
  putline (rejfp, " @@", c_function, nullptr);

  while (pch_char (new) == '=' || pch_char (new) == '\n')
    new++;

  if (diff_type != UNI_DIFF)
    pch_normalize (UNI_DIFF);

  for (; ; old++, new++)
    {
      for (;  pch_char (old) == '-';  old++)
	{
	  Fputc ('-', rejfp);
	  pch_write_line (old, rejfp);
	}
      for (;  pch_char (new) == '+';  new++)
	{
	  Fputc ('+', rejfp);
	  pch_write_line (new, rejfp);
	}

      if (old > lastline)
	  break;

      if (pch_char (new) != pch_char (old))
	mangled_patch (old, new);

      Fputc (' ', rejfp);
      pch_write_line (old, rejfp);
    }
  if (pch_char (new) != '^')
    mangled_patch (old, new);
}

/* Output the rejected patch in context format.  */

static void
abort_hunk_context (bool header, bool reverse)
{
    idx_t pat_end = pch_end ();
    /* add in out_offset to guess the same as the previous successful hunk */
    idx_t oldfirst = pch_first () + out_offset;
    idx_t newfirst = pch_newfirst () + out_offset;
    idx_t oldlast = oldfirst + pch_ptrn_lines () - 1;
    idx_t newlast = newfirst + pch_repl_lines () - 1;
    char const *stars   = diff_type < NEW_CONTEXT_DIFF ? ""       : " ****";
    char const *minuses = diff_type < NEW_CONTEXT_DIFF ? " -----" : " ----";
    char const *c_function = pch_c_function();

    if (diff_type == UNI_DIFF)
      pch_normalize (NEW_CONTEXT_DIFF);

    if (header)
      {
	if (pch_name (INDEX))
	  putline (rejfp, "Index: ", pch_name (INDEX), nullptr);
	print_header_line (rejfp, "*** ", reverse);
	print_header_line (rejfp, "--- ", ! reverse);
      }
    putline (rejfp, "***************", c_function, nullptr);

    for (idx_t i = 0; i <= pat_end; i++) {
	switch (pch_char(i)) {
	case '*':
	    if (oldlast < oldfirst)
		Fprintf (rejfp, "*** 0%s\n", stars);
	    else if (oldlast == oldfirst)
		Fprintf (rejfp, "*** %td%s\n", oldfirst, stars);
	    else
		Fprintf (rejfp, "*** %td,%td%s\n", oldfirst, oldlast, stars);
	    break;
	case '=':
	    if (newlast < newfirst)
		Fprintf (rejfp, "--- 0%s\n", minuses);
	    else if (newlast == newfirst)
		Fprintf (rejfp, "--- %td%s\n", newfirst, minuses);
	    else
		Fprintf (rejfp, "--- %td,%td%s\n", newfirst, newlast, minuses);
	    break;
	case ' ': case '-': case '+': case '!':
	    Fprintf (rejfp, "%c ", pch_char (i));
	    FALLTHROUGH;
	case '\n':
	    pch_write_line (i, rejfp);
	    break;
	default:
	    fatal ("fatal internal error in abort_hunk_context");
	}
	if (ferror (rejfp))
	  write_fatal ();
    }
}

/* Output the rejected hunk.  */

static void
abort_hunk (char const *outname, bool header, bool reverse)
{
  if (!tmprej.exists)
    init_reject (outname);
  if (reject_format == UNI_DIFF
      || (reject_format == NO_DIFF && diff_type == UNI_DIFF))
    abort_hunk_unified (header, reverse);
  else
    abort_hunk_context (header, reverse);
}

/* We found where to apply it (we hope), so do it. */

static bool
apply_hunk (struct outstate *outstate, idx_t where)
{
    idx_t old = 1;
    idx_t lastline = pch_ptrn_lines ();
    idx_t new = lastline + 1;
    enum {OUTSIDE, IN_IFNDEF, IN_IFDEF, IN_ELSE} def_state = OUTSIDE;
    char const *R_do_defines = do_defines;
    idx_t pat_end = pch_end ();
    FILE *fp = outstate->ofp;

    where--;
    while (pch_char(new) == '=' || pch_char(new) == '\n')
	new++;

    while (old <= lastline) {
	if (pch_char(old) == '-') {
	    assert (outstate->after_newline);
	    if (! copy_till (outstate, where + old - 1))
		return false;
	    if (R_do_defines) {
		if (def_state == OUTSIDE) {
		    putline (fp, outstate->after_newline + not_defined,
			     R_do_defines, nullptr);
		    def_state = IN_IFNDEF;
		}
		else if (def_state == IN_IFDEF) {
		    Fputs (outstate->after_newline + else_defined, fp);
		    def_state = IN_ELSE;
		}
		if (ferror (fp))
		  write_fatal ();
		outstate->after_newline = pch_write_line (old, fp);
		outstate->zero_output = false;
	    }
	    last_frozen_line++;
	    old++;
	}
	else if (new > pat_end) {
	    break;
	}
	else if (pch_char(new) == '+') {
	    if (! copy_till (outstate, where + old - 1))
		return false;
	    if (R_do_defines) {
		if (def_state == IN_IFNDEF) {
		    Fputs (outstate->after_newline + else_defined, fp);
		    def_state = IN_ELSE;
		}
		else if (def_state == OUTSIDE) {
		    putline (fp, outstate->after_newline + if_defined,
			     R_do_defines, nullptr);
		    def_state = IN_IFDEF;
		}
		if (ferror (fp))
		  write_fatal ();
	    }
	    outstate->after_newline = pch_write_line (new, fp);
	    outstate->zero_output = false;
	    new++;
	}
	else if (pch_char(new) != pch_char(old))
	  mangled_patch (old, new);
	else if (pch_char(new) == '!') {
	    assert (outstate->after_newline);
	    if (! copy_till (outstate, where + old - 1))
		return false;
	    assert (outstate->after_newline);
	    if (R_do_defines) {
	       putline (fp, 1 + not_defined, R_do_defines, nullptr);
	       if (ferror (fp))
		write_fatal ();
	       def_state = IN_IFNDEF;
	    }

	    do
	      {
		if (R_do_defines) {
		    outstate->after_newline = pch_write_line (old, fp);
		}
		last_frozen_line++;
		old++;
	      }
	    while (pch_char (old) == '!');

	    if (R_do_defines) {
		Fputs (outstate->after_newline + else_defined, fp);
		if (ferror (fp))
		  write_fatal ();
		def_state = IN_ELSE;
	    }

	    do
	      {
		outstate->after_newline = pch_write_line (new, fp);
		new++;
	      }
	    while (pch_char (new) == '!');
	    outstate->zero_output = false;
	}
	else {
	    assert(pch_char(new) == ' ');
	    old++;
	    new++;
	    if (R_do_defines && def_state != OUTSIDE) {
		Fputs (outstate->after_newline + end_defined, fp);
		if (ferror (fp))
		  write_fatal ();
		outstate->after_newline = true;
		def_state = OUTSIDE;
	    }
	}
    }
    if (new <= pat_end && pch_char(new) == '+') {
	if (! copy_till (outstate, where + old - 1))
	    return false;
	if (R_do_defines) {
	    if (def_state == OUTSIDE) {
		putline (fp, outstate->after_newline + if_defined,
			 R_do_defines, nullptr);
		def_state = IN_IFDEF;
	    }
	    else if (def_state == IN_IFNDEF) {
		Fputs (outstate->after_newline + else_defined, fp);
		def_state = IN_ELSE;
	    }
	    if (ferror (fp))
	      write_fatal ();
	    outstate->zero_output = false;
	}

	do
	  {
	    if (!outstate->after_newline)
	      Fputc ('\n', fp);
	    outstate->after_newline = pch_write_line (new, fp);
	    outstate->zero_output = false;
	    new++;
	  }
	while (new <= pat_end && pch_char (new) == '+');
    }
    if (R_do_defines && def_state != OUTSIDE) {
	Fputs (outstate->after_newline + end_defined, fp);
	if (ferror (fp))
	  write_fatal ();
	outstate->after_newline = true;
    }
    out_offset += pch_repl_lines() - pch_ptrn_lines ();
    return true;
}

/* Create an output file.  */

static FILE *
create_output_file (struct outfile *out, int open_flags)
{
  int fd = create_file (out, O_WRONLY | binary_transput | open_flags,
			instat.st_mode, true);
  FILE *f = fdopen (fd, binary_transput ? "wb" : "w");
  if (! f)
    pfatal ("Can't create file %s", quotearg (out->name));
  return f;
}

/* Open the new file. */

static void
init_output (struct outstate *outstate)
{
  outstate->ofp = nullptr;
  outstate->after_newline = true;
  outstate->zero_output = true;
}

/* GCC misunderstands dup2; see
   <https://gcc.gnu.org/bugzilla/show_bug.cgi?id=109839>.  */
#if 13 <= __GNUC__
# pragma GCC diagnostic ignored "-Wanalyzer-fd-leak"
#endif

static FILE *
open_outfile (char *name)
{
  if (strcmp (name, "-") != 0)
    return create_output_file (&(struct outfile) { .name = name }, 0);
  else
    {
      int stdout_dup = dup (STDOUT_FILENO);
      if (stdout_dup < 0)
	pfatal ("Failed to duplicate standard output");
      FILE *ofp = fdopen (stdout_dup, "a");
      if (! ofp)
	pfatal ("Failed to duplicate standard output");
      if (dup2 (STDERR_FILENO, STDOUT_FILENO) < 0)
	pfatal ("Failed to redirect messages to standard error");
      /* FIXME: Do we need to switch stdout_dup into O_BINARY mode here? */
      return ofp;
    }
}

/* Open a file to put hunks we can't locate. */

static void
init_reject (char const *outname)
{
  int fd;
  fd = make_tempfile (&tmprej, 'r', outname, O_WRONLY | binary_transput, 0666);
  if (fd < 0)
    pfatal ("Can't create temporary file %s", tmprej.name);
  rejfp = fdopen (fd, binary_transput ? "wb" : "w");
  if (! rejfp)
    pfatal ("Can't open stream for file %s", quotearg (tmprej.name));
}

/* Copy input file to output, up to wherever hunk is to be applied. */

bool
copy_till (struct outstate *outstate, idx_t lastline)
{
    idx_t R_last_frozen_line = last_frozen_line;
    FILE *fp = outstate->ofp;

    if (R_last_frozen_line > lastline)
      {
	say ("misordered hunks! output would be garbled\n");
	return false;
      }
    while (R_last_frozen_line < lastline)
      {
	R_last_frozen_line++;
	struct iline line = ifetch (R_last_frozen_line);
	if (line.size)
	  {
	    if (!outstate->after_newline)
	      Fputc ('\n', fp);
	    Fwrite (line.ptr, 1, line.size, fp);
	    outstate->after_newline = line.ptr[line.size - 1] == '\n';
	    outstate->zero_output = false;
	  }
      }
    last_frozen_line = R_last_frozen_line;
    return true;
}

/* Finish copying the input file to the output file. */

static bool
spew_output (struct outstate *outstate, struct stat *st)
{
    if (debug & 256)
      say ("il=%td lfl=%td\n", input_lines, last_frozen_line);

    if (last_frozen_line < input_lines)
      if (! copy_till (outstate, input_lines))
	return false;

    if (outstate->ofp && ! outfile)
      {
	Fflush (outstate->ofp);
	if (fstat (fileno (outstate->ofp), st) < 0)
	  write_fatal ();
      }

    return true;
}

/* Does the patch pattern match at line base+offset? */

static bool
patch_match (idx_t base, ptrdiff_t offset, idx_t prefix_fuzz, idx_t suffix_fuzz)
{
    idx_t pat_lines = pch_ptrn_lines () - suffix_fuzz;

    for (idx_t pline = 1 + prefix_fuzz; pline <= pat_lines; pline++) {
	struct iline line = ifetch (pline - 1 + base + offset);
	if (canonicalize_ws) {
	    if (!similar(line.ptr, line.size,
			 pfetch(pline),
			 pch_line_len(pline) ))
		return false;
	}
	else if (line.size != pch_line_len (pline)
		 || memcmp (line.ptr, pfetch (pline), line.size) != 0)
	    return false;
    }
    return true;
}

/* Check if the line endings in the input file and in the patch differ. */

static bool
check_line_endings (idx_t where)
{
  char const *p = pfetch (1);
  idx_t size = pch_line_len (1);
  if (! size)
    return false;
  bool patch_crlf = 2 <= size && p[size - 2] == '\r' && p[size - 1] == '\n';

  if (! input_lines)
    return false;
  if (where > input_lines)
    where = input_lines;
  struct iline line = ifetch (where);
  if (! line.size)
    return false;
  bool input_crlf = (2 <= line.size
		     && line.ptr[line.size - 2] == '\r'
		     && line.ptr[line.size - 1] == '\n');
  return patch_crlf != input_crlf;
}

/* Do two lines match with canonicalized white space? */

bool
similar (char const *a, idx_t alen, char const *b, idx_t blen)
{
  /* Ignore presence or absence of trailing newlines.  */
  alen  -=  alen && a[alen - 1] == '\n';
  blen  -=  blen && b[blen - 1] == '\n';

  for (;;)
    {
      if (!blen || c_isblank (*b))
	{
	  while (blen && c_isblank (*b))
	    b++, blen--;
	  if (alen)
	    {
	      if (!c_isblank (*a))
		return false;
	      do a++, alen--;
	      while (alen && c_isblank (*a));
	    }
	  if (!alen || !blen)
	    return alen == blen;
	}
      else if (!alen || *a++ != *b++)
	return false;
      else
	alen--, blen--;
    }
}

/* Deferred deletion of files. */

struct file_to_delete {
  char *name;
  struct stat st;
  bool backup;
  struct file_to_delete *next;
};

static struct file_to_delete *files_to_delete;
static struct file_to_delete **files_to_delete_tail = &files_to_delete;

static void
delete_file_later (char *name, const struct stat *st, bool backup)
{
  struct file_to_delete *file_to_delete;
  struct stat st_tmp;

  if (! st)
    {
      if (stat_file (name, &st_tmp) != 0)
	pfatal ("Can't get file attributes of %s %s", "file", name);
      st = &st_tmp;
    }
  file_to_delete = xmalloc (sizeof *file_to_delete);
  file_to_delete->name = xstrdup (name);
  file_to_delete->st = *st;
  file_to_delete->backup = backup;
  file_to_delete->next = nullptr;
  *files_to_delete_tail = file_to_delete;
  files_to_delete_tail = &file_to_delete->next;
  insert_file_id (st, DELETE_LATER);
}

static void
delete_files (void)
{
  struct file_to_delete *next;
  for (struct file_to_delete *f = files_to_delete; f; f = next)
    {
      if (lookup_file_id (&f->st) == DELETE_LATER)
	{
	  mode_t mode = f->st.st_mode;

	  if (verbosity == VERBOSE)
	    say ("Removing %s %s\n",
		 S_ISLNK (mode) ? "symbolic link" : "file",
		 quotearg (f->name));
	  move_file (nullptr, nullptr, f->name, mode, f->backup);
	  removedirs (f->name);
	}
      next = f->next;
    }
}

/* Putting output files into place and removing them. */

struct file_to_output {
  struct outfile from;
  struct stat from_st;
  char *volatile to;
  mode_t mode;
  bool backup;
  struct file_to_output *volatile next;
};

static struct file_to_output *volatile files_to_output;
static struct file_to_output *volatile *files_to_output_tail =
  &files_to_output;

static void
output_file_later (struct outfile *from, const struct stat *from_st,
		   char const *to, mode_t mode, bool backup)
{
  idx_t tosize = to ? strlen (to) + 1 : 0;
  struct file_to_output *f = ximalloc (sizeof *f + tosize);
  char *alloc = from->alloc;
  f->from.name = f->from.alloc = alloc ? alloc : xstrdup (from->name);
  if (alloc)
    from->alloc = nullptr;
  f->from.exists = alloc ? from->exists : volatilize (f->from.alloc);
  f->from.temporary = from->temporary;
  f->from_st = *from_st;
  f->to = to ? memcpy (f + 1, to, tosize) : nullptr;
  f->mode = mode;
  f->backup = backup;
  f->next = nullptr;

  /* In a critical section, transfer ownership from FROM to F->from.  */
  defer_signals ();
  *files_to_output_tail = f;
  from->exists = nullptr;
  undefer_signals ();

  files_to_output_tail = &f->next;
}

static void
output_file_now (struct outfile *from,
		 const struct stat *from_st, char *to,
		 mode_t mode, bool backup)
{
  if (!to)
    {
      if (backup)
	create_backup (from->name, from_st, true);
    }
  else
    {
      assert (0 <= from_st->st_size);
      move_file (from, from_st, to, mode, backup);
    }
}

static void
output_file (struct outfile *from,
	     const struct stat *from_st, char *to,
	     const struct stat *to_st, mode_t mode, bool backup)
{
  if (!from)
    {
      /* Remember which files should be deleted and only delete them when the
	 entire input to patch has been processed.  This allows to correctly
	 determine for which files backup files have already been created.  */

      delete_file_later (to, to_st, backup);
    }
  else if (pch_git_diff () && pch_says_nonexistent (reverse_flag) != 2)
    {
      /* In git-style diffs, the "before" state of each patch refers to the initial
	 state before modifying any files, input files can be referenced more than
	 once (when creating copies), and output files are modified at most once.
	 However, the input to GNU patch may consist of multiple concatenated
	 git-style diffs, which must be processed separately.  (The same output
	 file may go through multiple revisions.)

	 To implement this, we remember which files to /modify/ instead of
	 modifying the files immediately, but we create /new/ output files
	 immediately.  The new output files serve as markers to detect when a
	 file is modified more than once; this allows to recognize most
	 concatenated git-style diffs.
      */

      output_file_later (from, from_st, to, mode, backup);
    }
  else
    output_file_now (from, from_st, to, mode, backup);
}

/* A root to pacify -fsanitize=address if it is being used.  */
#if SANITIZE_ADDRESS
extern struct file_to_output *volatile files_to_output_root;
struct file_to_output *volatile files_to_output_root
  ATTRIBUTE_EXTERNALLY_VISIBLE;
#endif

/* Output files that were delayed until now.
   If ST, output only files up to and including ST.

   EXITING == 0 is the typical case.
   If EXITING != 0, we are about to exit so freeing memory is optional.
   If EXITING < 0, we are in a signal handler (and in a critical section);
   so ignore ST, remove temporaries in an async-signal-safe way,
   and of course do not attempt to free memory.  */

static void
output_files (struct stat const *st, int exiting)
{
  struct file_to_output *next;
  struct file_to_output *f = files_to_output;
#if SANITIZE_ADDRESS
  files_to_output_root = f;
#endif
  for (; f; f = next)
    {
      char *to = f->to;
      next = f->next;
      bool early_return;

      if (exiting < 0)
	{
	  /* Do not call 'safe_unlink' as it is not async-signal-safe.
	     'unlink' should be good enough here, as we already
	     checked the file's parent directory.  */
	  if (to)
	    {
	      char volatile *exists = f->from.exists;
	      if (exists)
		unlink (devolatilize (exists));
	    }
	  early_return = false;
	}
      else
	{
	  struct stat const *from_st = &f->from_st;

	  output_file_now (&f->from, from_st, to, f->mode, f->backup);

	  defer_signals ();
	  if (to)
	    {
	      char volatile *exists = f->from.exists;
	      if (exists)
		safe_unlink (devolatilize (exists));
	    }
	  files_to_output = next;
	  undefer_signals ();

	  early_return = (st
			  && st->st_dev == from_st->st_dev
			  && st->st_ino == from_st->st_ino);
	}

      if (!exiting)
	{
	  free (f->from.alloc);
	  free (f);
	}

      if (!next)
	files_to_output_tail = &files_to_output;

      if (early_return)
	return;
    }
}

/* Clean up temp files after a signal.  This function is async-signal-safe.  */

void
fatal_cleanup (void)
{
  cleanup_remove ();
  output_files (nullptr, -1);
}

/* Clean up temp files and exit after a fatal error.  */

void
fatal_exit (void)
{
  defer_signals ();
  cleanup_remove ();
  undefer_signals ();
  output_files (nullptr, 1);
  exit (EXIT_TROUBLE);
}

/* Remove TMP's file if it exists.
   This function is async-signal-safe.  */
static void
remove_if_needed (struct outfile *tmp)
{
  char volatile *exists = tmp->exists;
  if (exists)
    {
      safe_unlink (devolatilize (exists));
      tmp->exists = nullptr;
    }
}

/* Remove per-file temporary files.
   This function is async-signal-safe.  */
static void
perfile_cleanup_remove (void)
{
  remove_if_needed (&tmped);
  remove_if_needed (&tmpout);
  remove_if_needed (&tmprej);
}

/* Remove all temporary files.
   This function is async-signal-safe.  */
static void
cleanup_remove (void)
{
  remove_if_needed (&tmppat);
  perfile_cleanup_remove ();
}

/* Free any storage associated with an output file.  */
static void
free_outfile_name (struct outfile *f)
{
  free (f->alloc);
  f->name = f->alloc = nullptr;
}

/* Free storage associated with per-file temporaries.  */
static void
perfile_cleanup_free (void)
{
  free_outfile_name (&tmped);
  free_outfile_name (&tmpout);
  free_outfile_name (&tmprej);
}
