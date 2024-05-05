/* Report an dynamic array index out of bounds condition.
   Copyright (C) 2017-2021 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU General Public
   License as published by the Free Software Foundation; either
   version 3 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   General Public License for more details.

   You should have received a copy of the GNU General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */

#ifndef _LIBC
# include <libc-config.h>
#endif

#include <dynarray.h>
#include <stdio.h>
#include <stdlib.h>

void
__libc_dynarray_at_failure (size_t size, size_t index)
{
#ifdef _LIBC
  char buf[200];
  __snprintf (buf, sizeof (buf), "Fatal glibc error: "
              "array index %zu not less than array length %zu\n",
              index, size);
#else
 abort ();
#endif
}
libc_hidden_def (__libc_dynarray_at_failure)
