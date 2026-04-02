/* vms/math.h - Definitions for assisting GNULIB on OpenVMS

   Copyright (C) 2026 Free Software Foundation, Inc.

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

#ifndef VMS_MATH_H
#define VMS_MATH_H

#include <vms_fake_path/math.h>

#ifdef __VAX

static double vms_copysign(double num1, double num2) {
    if (num2 < 0.0)
        return (num1 < 0.0) ? num1 : - num1;
    else
        return (num1 < 0.0) ? -num1 : num1;
}
#ifdef copysign
#undef copysign
#endif
#define copysign vms_copysign

#endif /* __VAX */


#endif /* VMS_MATH_H */
