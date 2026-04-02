/* vms/inttypes.h - Definitions for assisting GNULIB on OpenVMS

   Copyright (C) 2017-2026 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify it
   under the terms of the GNU Lesser General Public License as published
   by the Free Software Foundation; either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* Written by John Malmberg */

#ifndef VMS_INTTYPES_H
#define VMS_INTTYPES_H

#if (__DECC_VER > 70390010)
#include <vms_fake_path/stdint.h>
#endif
#ifndef __VAX
# if __CRTL_VER < 80500000
#   ifndef PRIuMAX
#       define PRIuMAX "llu"
#   endif
#   ifndef PRIdMAX
#       define PRIdMAX "lld"
#   endif
#   ifndef PRIoMAX
#      define PRIoMAX "llo"
#   endif
#   ifndef PRIxMAX
#      define PRIxMAX "llx"
#   endif
# endif
#else /* _VAX */
# ifndef PRIuMAX
#   define PRIuMAX "u"
# endif
# ifndef PRIdMAX
#   define PRIdMAX "d"
# endif
# ifndef PRIoMAX
#   define PRIoMAX "o"
# endif
# ifndef PRIxMAX
#   define PRIxMAX "x"
# endif

  typedef signed char int8_t;
  typedef unsigned char uint8_t;
  typedef short int int16_t;
  typedef unsigned short int unit16_t;
  typedef int int32_t;
  typedef unsigned int uint32_t;
#endif /* _VAX */

#endif /* VMS_INTTYPES_H */
