/* Buffer primitives for comparison operations.

   Copyright (C) 1993, 1995, 1998, 2001-2002, 2006, 2009-2013, 2015-2025 Free
   Software Foundation, Inc.

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

#include "cmpbuf.h"

#include <errno.h>
#include <limits.h>
#include <signal.h>
#include <stdckdint.h>
#include <unistd.h>
#include <stdint.h>
#include <inttypes.h>
#include <sys/types.h>

#include "intprops.h"
#include "minmax.h"

/* Read NBYTES bytes from descriptor FD into BUF.
   Return the number of characters successfully read.
   On error, return -1, setting errno.
   The number returned is always NBYTES unless end-of-file or error.  */

ptrdiff_t
block_read (int fd, char *buf, idx_t nbytes)
{
  char *bp = buf;
  char const *buflim = buf + nbytes;
  idx_t readlim = MIN (IDX_MAX, MIN (SSIZE_MAX, SIZE_MAX));

  do
    {
      idx_t bytes_remaining = buflim - bp;
      idx_t bytes_to_read = MIN (bytes_remaining, readlim);
      ssize_t nread = read (fd, bp, bytes_to_read);
      if (nread <= 0)
        {
          if (nread == 0)
            break;

          /* Accommodate FreeBSD 13, which can't read more than INT_MAX bytes
	     when debug.iosize_max_clamp is nonzero.  Prefer a power
	     of two for the read limit in this case.

	     Also, work around a bug in Linux kernel 6.3.8 tmpfs,
	     which fails if the current offset + bytes_to_read exceeds
	     TYPE_MAXIMUM (off_t), even if EOF occurs before then.  */
	  if (errno == EINVAL)
	    {
	      if (bytes_to_read <= 1)
		{
		  if (lseek (fd, 0, SEEK_CUR) == TYPE_MAXIMUM (off_t))
		    {
		      nread = 0;
		      break;
		    }
		  errno = EINVAL;
		}
	      else
		{
		  readlim = MIN (bytes_to_read >> 1, INT_MAX / 2 + 1);
		  continue;
		}
	    }

          /* This is needed for programs that have signal handlers on
             older hosts without SA_RESTART.  It also accommodates
             ancient AIX hosts that set errno to EINTR after uncaught
             SIGCONT.  See <news:1r77ojINN85n@ftp.UU.NET>
             (1993-04-22).  */
          if (! SA_RESTART && errno == EINTR)
            continue;

          return -1;
        }
      bp += nread;
    }
  while (bp < buflim);

  return bp - buf;
}

/* Least common multiple of two buffer sizes A and B.  However, if
   either A or B is zero, or if the multiple is greater than LCM_MAX,
   return a reasonable buffer size.  */

idx_t
buffer_lcm (idx_t a, idx_t b, idx_t lcm_max)
{
  /* Yield reasonable values if buffer sizes are zero.  Although A and
     B must be nonnegative, GCC generates better code from (A <= 0)
     than from (A != 0).  */
  if (a <= 0)
    return b <= 0 ? 8 * 1024 : b;
  if (b <= 0)
    return a;

  /* n = gcd (a, b) */
  idx_t m, n, r;
  for (m = a, n = b;  (r = m % n) != 0;  m = n, n = r)
    continue;

  /* Yield a if there is an overflow.  */
  idx_t q = a / n, lcm;
  return !ckd_mul (&lcm, b, q) && lcm <= lcm_max ? lcm : a;
}
