/* utility functions for 'patch' */

/* Copyright 1992-2025 Free Software Foundation, Inc.
   Copyright 1986 Larry Wall

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

#include <timespec.h>
#include <stat-time.h>
#include <backupfile.h>

enum file_id_type { UNKNOWN, CREATED, DELETE_LATER, OVERWRITTEN };

enum file_attributes {
  FA_TIMES = 1,
  FA_IDS = 2,
  FA_MODE = 4,
  FA_XATTRS = 8
};

/* Exit status for trouble, such as write failure.  */
enum { EXIT_TROUBLE = 2 };

/* Read or write at most IO_BUFSIZE bytes at a time.
   In 2024 256 KiB was determined to be the best blocksize
   to minimize system call overhead across most systems
   when copying files.  See coreutils/src/ioblksize.h.  */
enum { IO_BUFSIZE = 256 * 1024 };

/* POSIX says behavior is implementation-defined for I/O requests
   larger than SSIZE_MAX.  IO_BUFSIZE is OK on all known platforms.
   Check it to be sure.  */
static_assert (IO_BUFSIZE <= SSIZE_MAX);

extern enum backup_type backup_type;

_GL_INLINE_HEADER_BEGIN
#ifndef UTIL_INLINE
# define UTIL_INLINE _GL_INLINE
#endif

char volatile *volatilize (char *);

/* Convert S to a pointer to non-volatile.  This is the inverse of volatilize.
   S’s contents must not be updated by a signal handler.  */
UTIL_INLINE char *
devolatilize (char volatile *s)
{
  return (char *) s;
}

bool ok_to_reverse (char const *, ...) ATTRIBUTE_FORMAT ((printf, 1, 2));
char *ask (char const *, ...) ATTRIBUTE_FORMAT ((printf, 1, 2));
void say (char const *, ...) ATTRIBUTE_FORMAT ((printf, 1, 2));

_Noreturn void fatal (char const *, ...) ATTRIBUTE_FORMAT ((printf, 1, 2));
_Noreturn void pfatal (char const *, ...) ATTRIBUTE_FORMAT ((printf, 1, 2));

void fetchname (char const *, intmax_t, char **, char **, struct timespec *);
char *parse_name (char const *, intmax_t, char const **);
char *savebuf (char const *, idx_t)
  ATTRIBUTE_MALLOC ATTRIBUTE_DEALLOC_FREE ATTRIBUTE_ALLOC_SIZE ((2));
char const *version_controller (char const *, bool, struct stat const *, char **, char **);
bool version_get (char *, char const *, bool, bool, char const *, struct stat *);
int create_file (struct outfile *, int, mode_t, bool);
int systemic (char const *);
void Fclose (FILE *);
void Fflush (FILE *);
void Fprintf (FILE *, char const *, ...) ATTRIBUTE_FORMAT ((printf, 2, 3));
void Fputc (int, FILE *);
void Fputs (char const *restrict, FILE *restrict);
void Fseeko (FILE *, off_t, int);
off_t Ftello (FILE *);
void Fwrite (void const *restrict, size_t, size_t, FILE *restrict);
idx_t Read (int, void *, idx_t);
void copy_file (char *, struct stat const *, struct outfile *, struct stat *,
		int, mode_t, enum file_attributes, bool);
void append_to_file (char *, char *);
idx_t quote_system_arg (char *, char const *);
void init_signals (void);
void defer_signals (void);
void undefer_signals (void);
void init_backup_hash_table (void);
void init_time (void);
_Noreturn void xalloc_die (void);
void create_backup (char *, const struct stat *, bool);
void move_file (struct outfile *, struct stat const *,
		char *, mode_t, bool);
_Noreturn void read_fatal (void);
void removedirs (char const *);
_Noreturn void write_fatal (void);
void putline (FILE *, ...);
void insert_file_id (struct stat const *, enum file_id_type);
enum file_id_type lookup_file_id (struct stat const *);
void set_queued_output (struct stat const *, bool);
bool has_queued_output (struct stat const *);
int stat_file (char *, struct stat *);
bool filename_is_safe (char const *) ATTRIBUTE_PURE;
bool cwd_is_root (char const *);

void set_file_attributes (char *, int, enum file_attributes, char const *, int,
			  const struct stat *, mode_t, struct timespec *);

int make_tempfile (struct outfile *, char, char const *, int, mode_t);

_GL_INLINE_HEADER_END
