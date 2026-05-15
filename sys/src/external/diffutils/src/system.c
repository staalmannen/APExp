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

#define SYSTEM_INLINE _GL_EXTERN_INLINE
#include "system.h"

/* Do struct stat *S, *T describe the same file?  */
bool
same_file (struct stat const *s, struct stat const *t)
{
  if (! SAME_INODE (*s, *t))
    {
# if HAVE_STRUCT_STAT_ST_RDEV
      /* Two character special files describe the same device if st_rdev
	 is the same, and likewise for block special devices.
	 They have the same contents, so treat them as the same.  */
      if (((S_ISCHR (s->st_mode) && S_ISCHR (t->st_mode))
	   || (S_ISBLK (s->st_mode) && S_ISBLK (t->st_mode)))
	  && s->st_rdev == t->st_rdev)
	return true;
# endif
      return false;
    }

  /* Although POSIX says that two files are identical if st_ino and st_dev
     are the same, all too many file systems incorrectly assign the same
     (device, inode) pair to two distinct files, including:

     - GNU/Linux NFS servers that export all local file systems as a
       single NFS file system, if a local (device, inode) pair collides
       with another one after hashing.

     - GNU/Linux NFS servers that export Btrfs file systems with subvolumes,
       if the Btrfs (subvolume, inode) hashing function collides.
       See <https://lwn.net/Articles/866709/>.

     - Qemu virtio-fs before Qemu 5.2 (2020); see
       <https://bugzilla.redhat.com/show_bug.cgi?id=1795362>.

     - Network Appliance NFS servers in snapshot directories; see
       Network Appliance bug #195.

     - ClearCase MVFS; see bug id ATRia04618.

     Check whether two files that purport to be the same have the same
     attributes, to work around instances of this common bug.

     Birthtime is special as st_birthtime is not portable, but when
     either birthtime is available comparing them should be definitive.  */

#if (defined HAVE_STRUCT_STAT_ST_BIRTHTIMESPEC_TV_NSEC \
     || defined HAVE_STRUCT_STAT_ST_BIRTHTIM_TV_NSEC \
     || defined HAVE_STRUCT_STAT_ST_BIRTHTIMENSEC \
     || (defined _WIN32 && ! defined __CYGWIN__))
  /* If either file has a birth time, comparing them is definitive.  */
  struct timespec sbirth = get_stat_birthtime (s);
  struct timespec tbirth = get_stat_birthtime (t);
  if (0 <= sbirth.tv_nsec || 0 <= tbirth.tv_nsec)
    return timespec_cmp (sbirth, tbirth) == 0;
#endif

  /* Fall back on comparing other easily-obtainable attributes.
     Do not inspect all attributes, only attributes useful in checking
     for the bug.  Check attributes most likely to differ first.

     It's possible for two distinct files on a buggy file system to have
     the same attributes, but it's not worth slowing down all
     implementations (or complicating the configuration) to cater to
     these rare cases in buggy implementations.

     It's also possible for the same file to appear to be two different
     files, e.g., because its permissions were changed between the two
     stat calls.  In that case cmp and diff will do extra work
     to determine that the file contents are the same.  */

  return (get_stat_ctime_ns (s) == get_stat_ctime_ns (t)
	  && get_stat_mtime_ns (s) == get_stat_mtime_ns (t)
	  && s->st_ctime == t->st_ctime
	  && s->st_mtime == t->st_mtime
	  && s->st_size == t->st_size
	  && s->st_mode == t->st_mode
	  && s->st_uid == t->st_uid
	  && s->st_gid == t->st_gid
	  && s->st_nlink == t->st_nlink);
}

/* Use this for code that could be used if diff ever cares about
   st_size for symlinks, which it doesn't now.  */
#define care_about_symlink_size false

/* Return the number of bytes in the file described by *S,
   or -1 if this cannot be determined reliably.  */
off_t
stat_size (struct stat const *s)
{
  mode_t mode = s->st_mode;
  off_t size = s->st_size;
  if (size < 0)
    return -1;
  if (! (S_ISREG (mode) || (care_about_symlink_size && S_ISLNK (mode))
	 || S_TYPEISSHM (s) || S_TYPEISTMO (s)))
    return -1;

#if (defined __linux__ || defined __CYGWIN__ || defined __FreeBSD__ \
     || defined __NetBSD__ || defined _AIX)
  /* On some systems, /proc files with size zero are suspect.  */
  if (size == 0)
    {
      static dev_t proc_dev;
      if (!proc_dev)
	{
	  struct stat st;
	  st.st_dev = 0;
	  lstat ("/proc/self", &st);
	  proc_dev = st.st_dev;
	}
      if (proc_dev && s->st_dev == proc_dev)
	return -1;
    }
#endif
#if care_about_symlink_size && (defined __linux__ || defined __ANDROID__)
  /* Symlinks have suspect sizes on Linux kernels before 5.15,
     due to bugs in fscrypt.  */
  if (S_ISLNK (mode))
    {
      static signed char symlink_size_ok;
      if (! symlink_size_ok)
	{
	  struct utsname name;
	  uname (&name);
	  char *p = name.release;
	  symlink_size_ok = ((p[1] != '.' || '5' < p[0]
			      || (p[0] == '5'
				  && ('1' <= p[2] && p[2] <= '9')
				  && ('0' <= p[3] && p[3] <= '9')
				  && ('5' <= p[3]
				      || ('0' <= p[4] && p[4] <= '9'))))
			     ? 1 : -1);
	}
      if (symlink_size_ok < 0)
	return -1;
    }
#endif

  return size;
}
