/* common definitions for 'patch' */

/* Copyright 1990-2025 Free Software Foundation, Inc.
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

#ifndef DEBUGGING
#define DEBUGGING 1
#endif

#include <config.h>

#include <attribute.h>
#include <c-ctype.h>
#include <idx.h>
#include <intprops.h>
#include <progname.h>
#include <minmax.h>

#include <assert.h>
#include <errno.h>
#include <fcntl.h>
#include <inttypes.h>
#include <limits.h>
#include <stdckdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>

/* handy definitions */

#define strEQ(s1,s2) (!strcmp(s1, s2))
#define strnEQ(s1,s2,l) (!strncmp(s1, s2, l))
#define ARRAY_SIZE(a) (sizeof (a) / sizeof ((a)[0]))

/* typedefs */

/* A description of an output file.  It may be temporary.  */
struct outfile
{
  /* Name of the file.  */
  char *name;

  /* Equal to NAME if the file exists; otherwise a null pointer.
     When non-null, the storage it points to is safe to access in
     a signal handler.  */
  char volatile *volatile exists;

  /* Equal to NAME if NAME should be freed when this structure is
     freed or reused; otherwise, a null pointer.  */
  char *alloc;

  /* Whether the file is intended to be temporary, and therefore
     should be cleaned up before exit, if it exists.  */
  bool temporary;
};

/* globals */

extern char *inname;
extern char *outfile;
extern int inerrno;
extern signed char invc;
extern struct stat instat;
extern bool dry_run;
extern bool posixly_correct;

extern char const *origprae;
extern char const *origbase;
extern char const *origsuff;

extern struct outfile tmped;
extern struct outfile tmppat;

#if DEBUGGING
extern unsigned short int debug;
#else
# define debug 0
#endif
extern bool force;
extern bool batch;
extern bool noreverse_flag;
extern bool reverse_flag;
extern enum verbosity { DEFAULT_VERBOSITY, SILENT, VERBOSE } verbosity;
extern bool skip_rest_of_patch;
extern intmax_t strippath;
extern bool canonicalize_ws;
extern intmax_t patch_get;
extern bool set_time;
extern bool set_utc;
extern bool follow_symlinks;

enum diff
  {
    NO_DIFF,
    CONTEXT_DIFF,
    NORMAL_DIFF,
    ED_DIFF,
    NEW_CONTEXT_DIFF,
    UNI_DIFF,
    GIT_BINARY_DIFF
  };

extern enum diff diff_type;

extern char *revision;			/* prerequisite revision, if any */

void fatal_cleanup (void);
_Noreturn void fatal_exit (void);

#if ! (HAVE_GETEUID || defined geteuid)
# if ! (HAVE_GETUID || defined getuid)
#  define geteuid() (-1)
# else
#  define geteuid() getuid ()
# endif
#endif

#ifdef HAVE_SETMODE_DOS
  extern int binary_transput;	/* O_BINARY if binary i/o is desired */
#else
# define binary_transput 0
#endif

/* Disable the CR stripping heuristic?  */
extern bool no_strip_trailing_cr;

#ifndef NULL_DEVICE
#define NULL_DEVICE "/dev/null"
#endif

#ifndef TTY_DEVICE
#define TTY_DEVICE "/dev/tty"
#endif

/* Output stream state.  */
struct outstate
{
  FILE *ofp;
  bool after_newline;
  bool zero_output;
};

/* offset in the input and output at which the previous hunk matched */
extern ptrdiff_t in_offset;
extern ptrdiff_t out_offset;

/* how many input lines have been irretractably output */
extern idx_t last_frozen_line;

bool copy_till (struct outstate *, idx_t);
bool similar (char const *, idx_t, char const *, idx_t) ATTRIBUTE_PURE;

#ifdef ENABLE_MERGE
enum conflict_style { MERGE_MERGE, MERGE_DIFF3 };
extern enum conflict_style conflict_style;

bool merge_hunk (intmax_t hunk, struct outstate *, idx_t where, bool *);
#else
# define merge_hunk(hunk, outstate, where, somefailed) false
#endif
