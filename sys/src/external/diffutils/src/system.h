/* System dependent declarations.

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

#include <config.h>

#include <verify.h>

#include <sys/types.h>

#include <sys/stat.h>
#include <stat-macros.h>
#include <stat-size.h>
#include <stat-time.h>
#include <timespec.h>

#include <unistd.h>

#include <fcntl.h>
#include <time.h>

#include <sys/wait.h>

#include <dirent.h>
#ifndef _D_EXACT_NAMLEN
# define _D_EXACT_NAMLEN(dp) strlen ((dp)->d_name)
#endif

#include <stdlib.h>

#include <inttypes.h>
#include <limits.h>
#include <locale.h>
#include <stdbit.h>
#include <stdckdint.h>
#include <stddef.h>
#include <string.h>

#include <gettext.h>
#if ! ENABLE_NLS
# undef textdomain
# define textdomain(Domainname) /* empty */
# undef bindtextdomain
# define bindtextdomain(Domainname, Dirname) /* empty */
#endif

#define _(msgid) gettext (msgid)
#define N_(msgid) msgid

#include <errno.h>

#include <signal.h>
#if !defined SIGCHLD && defined SIGCLD
# define SIGCHLD SIGCLD
#endif

#include <attribute.h>
#include <idx.h>
#include <intprops.h>
#include <minmax.h>
#include <propername.h>
#include <same-inode.h>

#include "version.h"

/* Evaluate an assertion E that is guaranteed to be true.
   E should not crash, loop forever, or have side effects.  */
#if defined DDEBUG && !defined NDEBUG
/* Abort the program if E is false.  */
# include <assert.h>
# define dassert(e) assert (e)
#else
/* The compiler can assume E, as behavior is undefined otherwise.  */
# define dassert(e) assume (e)
#endif

#ifndef SYSTEM_INLINE
# define SYSTEM_INLINE _GL_INLINE
#endif

_GL_INLINE_HEADER_BEGIN

/* Type used for fast comparison of several bytes at a time.
   The type is a pointer to an incomplete struct,
   so that its values are less likely to be misused.
   This used to be uintmax_t, but changing it to the size of a pointer
   made plain 'cmp' 90% faster (GCC 4.8.1, x86).  */

#ifndef word
typedef struct incomplete *word;
#endif

/* The signed integer type of a line number.  Since files are read
   into main memory, ptrdiff_t should be wide enough.  pI is for
   printing line numbers.  */

typedef ptrdiff_t lin;
#define LIN_MAX PTRDIFF_MAX
#define pI "t"
static_assert (LIN_MAX == IDX_MAX);

/* This section contains POSIX-compliant defaults for macros
   that are meant to be overridden by hand in config.h as needed.  */

#ifndef file_name_cmp
# define file_name_cmp strcmp
#endif

#ifndef initialize_main
# define initialize_main(argcp, argvp)
#endif

#ifndef NULL_DEVICE
# define NULL_DEVICE "/dev/null"
#endif

#define STREQ(a, b) (strcmp (a, b) == 0)

/* Return the floor of the log base 2 of N.  Return -1 if N is zero.  */
SYSTEM_INLINE int floor_log2 (idx_t n)
{
  static_assert (IDX_MAX <= SIZE_MAX);
  size_t s = n;
  int w = stdc_bit_width (s);
  return w - 1;
}

_GL_INLINE_HEADER_END

extern bool same_file (struct stat const *, struct stat const *)
  ATTRIBUTE_PURE;
extern off_t stat_size (struct stat const *)
  ATTRIBUTE_PURE;
