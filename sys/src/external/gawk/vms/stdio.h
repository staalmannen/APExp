/* vms/stdio.h - Definitions for assisting GNULIB on OpenVMS

   Copyright (C) 2017-2019,2026 Free Software Foundation, Inc.

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

#ifndef VMS_STDIO_H
#define VMS_STDIO_H

#include <vms_fake_path/stdio.h>

/* These are broken in some versions of the CRTL */
#define vms_feof_unlocked(fp) ((*fp) ? \
  (((unsigned int)((*(fp))->_flag) & _IOEOF) != 0): 0 )
#define vms_clearerr_unlocked(stream)((*stream)? \
  ((void)((*(fp))->_flag &= ~(_IOERR | _IOEOF))) : (void)0 )

/* Gnulib expects ferror on a closed file to return 1 */
#define vms_ferror_unlocked(fp) \
  ((*fp)? (((unsigned int)((*(fp))->_flag) & _IOERR) != 0) : 1 )

/* These macros do not exist on VAX */
#ifndef __FP_OPTIMIZATIONS
# define __FP_OPTIMIZATIONS 0
#endif
#ifndef __FP_LOCKING
# define __FP_LOCKING 0
#endif

#if  __FP_OPTIMIZATIONS
# ifdef feof
#  undef feof
# endif
# define feof vms_feof_unlocked
# ifdef ferror
#   undef ferror
# endif
# define ferror vms_ferror_unlocked
# ifdef clearerr
#  undef clearerr
# endif
# define clearerr vms_clearerr_unlocked
#endif

#if __FP_LOCKING
# ifdef feof_unlocked
#  undef feof_unlocked
# endif
# define feof_unlocked vms_feof_unlocked
# ifdef ferror_unlocked
#   undef ferror_unlocked
# endif
# define ferror_unlocked vms_ferror_unlocked
# ifdef clearerr_unlocked
#  undef clearerr_unlocked
# endif
# define clearerr_unlocked vms_clearerr_unlocked
#endif


#ifndef __VAX
# undef FILENAME_MAX
# define FILENAME_MAX 4096
#endif

#ifdef P_tmpdir
# undef P_tmpdir
# define P_tmpdir "/tmp"
#endif

#if 0 /* future wrappers to enable better compatibilty */
__FILE_ptr32
vms_fopen (const char * file_spec, const char * a_mode);
#define fopen(__file_spec, __a_mode) vms_fopen (__file_spec, __a_mode)

int
vms_fclose (FILE * fd);

#define fclose(__fd) vms_fclose (__fd)

/* Routines potentially needing wrappers to allow reading directories */
/*
int vms_decc_record_read (FILE *fp, void * buffer, int nbytes);
__FILE_ptr32 vms_fdopen (int file_desc, const char * a_mode);
int vms_fgetname (FILE * file_ptr, char * buffer); (OpenVMS doc has too small
of buffer)
__FILE_ptr32 vms_freopen (const char * file_spec, const char * a_mode, FILE *
                          file_ptr);
*/

/* popen related */
/*
int vms_pclose (FILE * stream);
__FILE_ptr32 vms_popen (const char *command, const char *type);
*/

int
vms_remove (const char *file_spec);
#define remove(path) vms_remove (path)

int
vms_rename (const char *old, const char *new);
#define rename(old, new) vms_rename (old, new)

#endif /* future */

#endif /* VMS_STDIO_H */

