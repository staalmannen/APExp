/*
 * gawkmisc.c --- miscellanious gawk routines that are OS specific.
 */

/*
 * Copyright (C) 1986, 1988, 1989, 1991-2004, 2010, 2011, 2017, 2022, 2023,
 * the Free Software Foundation, Inc.
 *
 * This file is part of GAWK, the GNU implementation of the
 * AWK Programming Language.
 *
 * GAWK is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * GAWK is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA
 */

#include "awk.h"

#if defined(HAVE_FCNTL_H)
#include <fcntl.h>
#endif

#if defined(__MINGW32__)
#include "pc/gawkmisc.pc"
#elif defined(VMS)
#include "vms/gawkmisc.vms"
#else /* posix */
#include "posix/gawkmisc.c"
#endif
