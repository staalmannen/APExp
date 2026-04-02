/* vms_printf.c - augmentation for the fwrite() function.

   Original author John E. Malmberg

   Copyright (C) 2026, the Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software Foundation,
   Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.  */

/* This module provides wrapper to printf related routines that rewrites the
   format string to replace conversion codes not supported by
   OpenVMS yet.

   This may be adjusted when the calling program changes to use new
   unsupported conversion codes, or if a Version of OpenVMS starts
   supporting new conversion codes.

   Note that using this wrapper utility disables the OpenVMS C compilers
   many optimizations for printf related routines, and will change
   a compile time error to a runtime error.
*/

/* OpenVMS C COMPILERS only use the directory of header file path if a
   header file is actually found at that path.
   For non-existent paths compiler junks the path and looks up the header
   definitions in a system library file.

   Using the non-existant "vms_fake_path" will force the compiler to
   use the OpenVMS system provided header.

   usage in header file, which must be included before any of the include
   stdio.h file below:

   #define printf decc_printf
   #define fprintf decc_fprintf
   #include <vms_fake_path/stdio.h>
   #static vms_printf


*/
# include <vms_fake_path/ctype.h>
# include <vms_fake_path/errno.h>
# include <vms_fake_path/stdlib.h>
# include <vms_fake_path/stdarg.h>
# include <vms_fake_path/stdio.h>
# include <vms_fake_path/string.h>

static char * vms_reformat(const char *format)
{
    char * new_format;
    int format_len;
    const char *old_f;
    char * new_f;
    int in_format = 0;

    format_len = strlen(format);
    /* Currently all known conversions for this routine will result in the same
       length of format string as the original.
       Some versions of VMS have a bug in handling format_len = 0
    */
    if (format_len == 0)
      {
        errno = EINVAL;
        return NULL;
      }
    new_format = malloc(format_len);
    if (new_format == NULL)
        return NULL;
    old_f = format;
    new_f = new_format;
    strcpy(new_format, format);
    while (*new_f != 0)
    {
      if (in_format != 0)
        {
          if (isalpha(*new_f))
            {
              /* Start of format character found leaving format */
              in_format = 0;
              /* only format currently replaced is %z with %l */
              if (*new_f == 'z')
                  *new_f = 'l';
            }
          new_f++;
          continue;
        }
      /* Not in a format specifier */
      if (new_f[0] == '%')
        {
          if (new_f[1] == '%')
            {
              /* Not a real format character, skip both */
              new_f++;
            }
          else
            {
              /* Now in a format specifier */
              in_format = 1;
              new_f++;
              continue;
            }
        }
      new_f++;
    }
    return new_format;
}


/* wrap the printf functions. */
int vms_printf(const char * format, ...) {
    char * new_format;
    int result;
    va_list args;
    va_start(args, format);

    new_format = vms_reformat(format);
    if (new_format == NULL)
        return -1;

    result = vprintf(new_format, args);
    va_end(args);
    free(new_format);
    return result;
}

int vms_sprintf(char *str, const char *format, ...) {
    char * new_format;
    int result;
    va_list args;
    va_start(args, format);

    new_format = vms_reformat(format);
    if (new_format == NULL)
        return -1;

    result = vsprintf(str, new_format, args);
    va_end(args);
    free(new_format);
    return result;
}

int vms_fprintf(FILE* stream, const char *format, ...) {
    char * new_format;
    int result;
    va_list args;
    va_start(args, format);

    new_format = vms_reformat(format);
    if (new_format == NULL)
        return -1;

    result = vfprintf(stream, new_format, args);
    va_end(args);
    free(new_format);
    return result;
}
