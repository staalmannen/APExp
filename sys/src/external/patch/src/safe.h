/* safe path traversal functions for 'patch' */

/* Copyright 2015-2025 Free Software Foundation, Inc.

   Written by Tim Waugh <twaugh@redhat.com> and
   Andreas Gruenbacher <agruenba@redhat.com>.

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

/* A constant that cannot be successfully passed as a directory file
   descriptor to openat etc.  Its value is negative but does not equal
   AT_FDCWD.  Normally the value is -1, but it is -2 on perverse
   platforms where AT_FDCWD == -1.  */

enum { DIRFD_INVALID = -1 - (AT_FDCWD == -1) };

extern bool unsafe;

int safe_stat (char *pathname, struct stat *buf);
int safe_lstat (char *pathname, struct stat *buf);
int safe_open (char *pathname, int flags, mode_t mode);
int safe_rename (char *oldpath, char *newpath);
int safe_mkdir (char *pathname, mode_t mode);
int safe_rmdir (char *pathname);
int safe_unlink (char *pathname);
int safe_symlink (const char *target, char *linkpath);
int safe_chmod (char *pathname, mode_t mode);
int safe_lchown (char *pathname, uid_t owner, gid_t group);
int safe_lutimens (char *pathname, struct timespec const times[2]);
ssize_t safe_readlink(char *pathname, char *buf, size_t bufsiz);
int safe_access(char *pathname, int mode);
