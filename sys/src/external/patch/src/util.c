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

#define UTIL_INLINE _GL_EXTERN_INLINE

#include <common.h>
#include <basename-lgpl.h>
#include <filename.h>
#include <hash.h>
#include <quotearg.h>
#include <util.h>
#include <utimens.h>
#include <xalloc.h>

#include <parse-datetime.h>
#include <ignore-value.h>
#include <error.h>

#include <signal.h>
#include <stdarg.h>

#include <tempname.h>

#if USE_XATTR
# include <attr/error_context.h>
# include <attr/libattr.h>
#endif

#include <pch.h>
#include <safe.h>

enum backup_type backup_type;

static void makedirs (char const *);
static void Write (int, void const *, idx_t);

typedef struct
{
  dev_t dev;
  ino_t ino;
  enum file_id_type type;
  bool queued_output;
} file_id;

/* Convert STR to a pointer to volatile, after making the contents
   safe to use in a signal handler.  */
char volatile *
volatilize (char *str)
{
  /* Access the string contents as volatile, to force contents into
     memory.  This loop is redundant on typical platforms, although
     the C standard requires it.  */
  for (char volatile *p = str; *p; p++)
    continue;

  return str;
}

/* Return an index for ENTRY into a hash table of size TABLE_SIZE.  */

static size_t
file_id_hasher (void const *entry, size_t table_size)
{
  file_id const *e = entry;
  uintmax_t ino = e->ino, dev = e->dev;
  return (ino ^ dev) % table_size;
}

/* Do ENTRY1 and ENTRY2 refer to the same files?  */

static bool
file_id_comparator (void const *entry1, void const *entry2)
{
  file_id const *e1 = entry1;
  file_id const *e2 = entry2;
  return (e1->ino == e2->ino && e1->dev == e2->dev);
}

static Hash_table *file_id_table;

/* Initialize the hash table.  */

void
init_backup_hash_table (void)
{
  file_id_table = hash_initialize (0, nullptr, file_id_hasher,
				   file_id_comparator, free);
  if (!file_id_table)
    xalloc_die ();
}

static file_id *
__insert_file_id (struct stat const *st, enum file_id_type type)
{
   file_id *p;
   static file_id *next_slot;

   if (!next_slot)
     next_slot = xmalloc (sizeof *next_slot);
   next_slot->dev = st->st_dev;
   next_slot->ino = st->st_ino;
   next_slot->queued_output = false;
   p = hash_insert (file_id_table, next_slot);
   if (!p)
     xalloc_die ();
   if (p == next_slot)
     next_slot = nullptr;
   p->type = type;
   return p;
}

static file_id *
__lookup_file_id (struct stat const *st)
{
  file_id f;

  f.dev = st->st_dev;
  f.ino = st->st_ino;
  return hash_lookup (file_id_table, &f);
}

/* Insert a file with status ST and type TYPE into the hash table.
   The type of an existing entry can be changed by re-inserting it.  */

void
insert_file_id (struct stat const *st, enum file_id_type type)
{
  __insert_file_id (st, type);
}

/* Has the file identified by ST already been inserted into the hash
   table, and what type does it have?  */

enum file_id_type
lookup_file_id (struct stat const *st)
{
  file_id *p = __lookup_file_id (st);

  return p ? p->type : UNKNOWN;
}

void
set_queued_output (struct stat const *st, bool queued_output)
{
  file_id *p = __lookup_file_id (st);

  if (! p)
    p = __insert_file_id (st, UNKNOWN);
  p->queued_output = queued_output;
}

bool
has_queued_output (struct stat const *st)
{
  file_id *p = __lookup_file_id (st);

  return p && p->queued_output;
}

static bool ATTRIBUTE_PURE
contains_slash (const char *s)
{
  for (; *s; s++)
    if (ISSLASH(*s))
      return true;
  return false;
}

/* Assuming that a chown-like syscall using file descriptor FD (or a
   filename-oriented syscall if FD < 0) failed with errno = ERR,
   return true if the current process lacks appropriate privileges.  */

static bool
lacks_appropriate_privileges (int fd, int err)
{
  if (err == EPERM)
    return true;
#ifdef __linux__
  /* Work around <https://bugs.gnu.org/65599>  */
  if (0 <= fd && errno == EACCES)
    return true;
#endif
  return false;
}

#if USE_XATTR

static void ATTRIBUTE_FORMAT ((_GL_ATTRIBUTE_SPEC_PRINTF_STANDARD, 2, 3))
copy_attr_error (MAYBE_UNUSED struct error_context *ctx, char const *fmt, ...)
{
  int err = errno;
  va_list ap;

  if (err != ENOSYS && err != ENOTSUP && err != EPERM)
    {
      va_start (ap, fmt);
      verror (0, err, fmt, ap);
      va_end (ap);
    }
}

static void ATTRIBUTE_FORMAT ((_GL_ATTRIBUTE_SPEC_PRINTF_STANDARD, 2, 3))
copy_fdattr_error (MAYBE_UNUSED struct error_context *ctx, char const *fmt, ...)
{
  int err = errno;
  va_list ap;

  if (err != ENOSYS && err != ENOTSUP
      && !lacks_appropriate_privileges (err, 0))
    {
      va_start (ap, fmt);
      verror (0, err, fmt, ap);
      va_end (ap);
    }
}

static char const *
copy_attr_quote (MAYBE_UNUSED struct error_context *ctx, char const *str)
{
  return quotearg (str);
}

static void
copy_attr_free (MAYBE_UNUSED struct error_context *ctx,
		MAYBE_UNUSED char const *str)
{
}

static int
copy_attr_check (const char *name, struct error_context *ctx)
{
	int action = attr_copy_action (name, ctx);
	return action == 0 || action == ATTR_ACTION_PERMISSIONS;
}


static int
copy_attr (char const *src_path, int src_fd,
	   char const *dst_path, int dst_fd)
{
  /* Pacify GCC through at least GCC 14, which otherwise complains about
     the ".error = ...".  */
  #if 4 < __GNUC__ + (8 <= __GNUC_MINOR__)
  # pragma GCC diagnostic push
  # pragma GCC diagnostic ignored "-Wsuggest-attribute=format"
  #endif

  bool copy_with_names = (src_fd < 0) | (dst_fd < 0);
  struct error_context ctx =
  {
    .error = copy_with_names ? copy_attr_error : copy_fdattr_error,
    .quote = copy_attr_quote,
    .quote_free = copy_attr_free
  };

  #if 4 < __GNUC__ + (8 <= __GNUC_MINOR__)
  # pragma GCC diagnostic pop
  #endif

  if (0 <= src_fd && 0 <= dst_fd)
    return attr_copy_fd (src_path, src_fd, dst_path, dst_fd,
			 copy_attr_check, &ctx);

  /* FIXME: We are copying between files we know we can safely access by
   * pathname. A safe_ version of attr_copy_file() might still be slightly
   * more efficient for deep paths. */
  return attr_copy_file (src_path, dst_path, copy_attr_check, &ctx);
}

#else  /* USE_XATTR */

static int
copy_attr (MAYBE_UNUSED char const *src_path, MAYBE_UNUSED int src_fd,
	   MAYBE_UNUSED char const *dst_path, MAYBE_UNUSED int dst_fd)
{
  return 0;
}

#endif

void
set_file_attributes (char *to, int tofd, enum file_attributes attr,
		     char const *from, int fromfd, const struct stat *st,
		     mode_t mode, struct timespec *new_time)
{
  if (attr & FA_TIMES)
    {
      struct timespec times[2];
      if (new_time)
	times[0] = times[1] = *new_time;
      else
        {
	  times[0] = get_stat_atime (st);
	  times[1] = get_stat_mtime (st);
	}
      int ok = (tofd < 0 ? -1
		: 0 <= futimens (tofd, times) ? 1
		: errno == ENOSYS ? -1 : 0);
      if (!ok || (ok < 0 && safe_lutimens (to, times) < 0))
	pfatal ("Failed to set the timestamps of %s %s",
		S_ISLNK (mode) ? "symbolic link" : "file",
		quotearg (to));
    }
  if (attr & FA_IDS)
    {
      uid_t uid_1 = -1;
      gid_t gid_1 = -1;
      static uid_t euid = -1;
      static gid_t egid = -1;
      uid_t uid;
      uid_t gid;

      if (euid == uid_1)
        {
	  euid = geteuid ();
	  egid = getegid ();
	}
      uid = euid == st->st_uid ? uid_1 : st->st_uid;
      gid = egid == st->st_gid ? gid_1 : st->st_gid;

      /* May fail if we are not privileged to set the file owner, or we are
         not in group instat.st_gid.  Ignore those errors.  */
      if ((uid != uid_1 || gid != gid_1)
	  && ((tofd < 0 ? safe_lchown (to, uid, gid) : fchown (tofd, uid, gid))
	      < 0)
	  && (!lacks_appropriate_privileges (tofd, errno)
	      || (uid != uid_1
		  && (uid = -1,
		      ((tofd < 0
			? safe_lchown (to, uid, gid)
			: fchown (tofd, uid, gid))
		       < 0))
		  && !lacks_appropriate_privileges (tofd, errno))))
	pfatal ("Failed to set the %s of %s %s",
		uid == uid_1 ? "owner" : "owning group",
		S_ISLNK (mode) ? "symbolic link" : "file",
		quotearg (to));
    }
  if (attr & FA_XATTRS)
    if (copy_attr (from, fromfd, to, tofd) < 0
	&& errno != ENOSYS && errno != ENOTSUP
	&& lacks_appropriate_privileges (errno, tofd))
      fatal_exit ();
  if (attr & FA_MODE)
    {
      /* The "diff --git" format does not store the file permissions of
	 symlinks, so don't try to set symlink file permissions even on
	 systems where we could.  */
      if (! S_ISLNK (mode)
	  && (tofd < 0 ? safe_chmod (to, mode) : fchmod (tofd, mode)) < 0)
	pfatal ("Failed to set the permissions of %s %s",
		S_ISLNK (mode) ? "symbolic link" : "file",
		quotearg (to));
    }
}

static void
create_backup_copy (char *from, char *to, const struct stat *st,
		    bool to_dir_known_to_exist)
{
  copy_file (from, st, &(struct outfile) { .name = to },
	     nullptr, 0, st->st_mode, FA_TIMES | FA_IDS | FA_MODE,
	     to_dir_known_to_exist);
}

void
create_backup (char *to, const struct stat *to_st, bool leave_original)
{
  /* When the input to patch modifies the same file more than once, patch only
     backs up the initial version of each file.

     To figure out which files have already been backed up, patch remembers the
     files that replace the original files.  Files not known already are backed
     up; files already known have already been backed up before, and are
     skipped.

     When a patch tries to delete a file, in order to not break the above
     logic, we merely remember which file to delete.  After the entire patch
     file has been read, we delete all files marked for deletion which have not
     been recreated in the meantime.  */

  if (to_st && ! (S_ISREG (to_st->st_mode) || S_ISLNK (to_st->st_mode)))
    fatal ("File %s is not a %s -- refusing to create backup",
	   to, S_ISLNK (to_st->st_mode) ? "symbolic link" : "regular file");

  if (to_st && lookup_file_id (to_st) == CREATED)
    {
      if (debug & 4)
	say ("File %s already seen\n", quotearg (to));
    }
  else
    {
      int try_makedirs_errno = 0;
      char *bakname;

      if (origprae || origbase || origsuff)
	{
	  char const *p = origprae ? origprae : "";
	  char const *b = origbase ? origbase : "";
	  char const *s = origsuff ? origsuff : "";
	  char const *t = to;
	  idx_t plen = strlen (p);
	  idx_t blen = strlen (b);
	  idx_t slen = strlen (s);
	  idx_t tlen = strlen (t);
	  char const *o;
	  idx_t olen;

	  for (o = t + tlen, olen = 0;
	       o > t && ! ISSLASH (*(o - 1));
	       o--)
	    /* do nothing */ ;
	  olen = t + tlen - o;
	  tlen -= olen;
	  bakname = xmalloc (plen + tlen + blen + olen + slen + 1);
	  memcpy (bakname, p, plen);
	  memcpy (bakname + plen, t, tlen);
	  memcpy (bakname + plen + tlen, b, blen);
	  memcpy (bakname + plen + tlen + blen, o, olen);
	  memcpy (bakname + plen + tlen + blen + olen, s, slen + 1);

	  if ((origprae
	       && (contains_slash (origprae + FILE_SYSTEM_PREFIX_LEN (origprae))
		   || contains_slash (to)))
	      || (origbase && contains_slash (origbase)))
	    try_makedirs_errno = ENOENT;
	}
      else
	{
	  bakname = find_backup_file_name (AT_FDCWD, to, backup_type);
	  if (!bakname)
	    xalloc_die ();
	}

      if (! to_st)
	{
	  int fd;

	  if (debug & 4)
	    say ("Creating empty file %s\n", quotearg (bakname));

	  try_makedirs_errno = ENOENT;
	  safe_unlink (bakname);
	  while ((fd = safe_open (bakname, O_CREAT | O_EXCL | O_WRONLY | O_TRUNC, 0666)) < 0)
	    {
	      if (errno != try_makedirs_errno)
		pfatal ("Can't create file %s", quotearg (bakname));
	      makedirs (bakname);
	      try_makedirs_errno = 0;
	    }
	  if (close (fd) != 0)
	    pfatal ("Can't close file %s", quotearg (bakname));
	}
      else if (leave_original)
	create_backup_copy (to, bakname, to_st, try_makedirs_errno == 0);
      else
	{
	  if (debug & 4)
	    say ("Renaming file %s to %s\n",
		 quotearg_n (0, to), quotearg_n (1, bakname));
	  while (safe_rename (to, bakname) != 0)
	    {
	      if (errno == try_makedirs_errno)
		{
		  makedirs (bakname);
		  try_makedirs_errno = 0;
		}
	      else if (errno == EXDEV)
		{
		  create_backup_copy (to, bakname, to_st,
				      try_makedirs_errno == 0);
		  safe_unlink (to);
		  break;
		}
	      else
		pfatal ("Can't rename file %s to %s",
			quotearg_n (0, to), quotearg_n (1, bakname));
	    }
	}
      free (bakname);
    }
}

/* Move a file OUTFROM (where *FROMST is OUTFROM's status if known),
   to TO, renaming it if possible and copying it if necessary.
   If we must create TO, use MODE to create it.
   If OUTFROM is null, remove TO.
   and FROMST must be nonnull if both FROM and BACKUP are nonnull.
   Back up TO if BACKUP is true.  */

void
move_file (struct outfile *outfrom, struct stat const *fromst,
	   char *to, mode_t mode, bool backup)
{
  struct stat to_st;
  int to_errno;

  to_errno = stat_file (to, &to_st);
  if (backup)
    create_backup (to, to_errno ? nullptr : &to_st, false);
  if (! to_errno)
    insert_file_id (&to_st, OVERWRITTEN);

  if (outfrom)
    {
      char *from = outfrom->name;
      if (S_ISLNK (mode))
	{
	  bool to_dir_known_to_exist = false;

	  /* FROM contains the contents of the symlink we have patched; need
	     to convert that back into a symlink. */
	  idx_t alloc;
	  if (ckd_add (&alloc, fromst->st_size, 1))
	    xalloc_die ();
	  char *buffer = ximalloc (alloc);

	  int fd = safe_open (from, O_RDONLY | O_BINARY, 0);
	  if (fd < 0)
	    pfatal ("Can't reopen file %s", quotearg (from));

	  idx_t size = 0;
	  for (idx_t i; 0 < (i = Read (fd, buffer + size, alloc - size)); )
	    size += i;
	  if (close (fd) < 0)
	    read_fatal ();
	  if (size == alloc)
	    fatal ("file %s grew", quotearg (from));
	  buffer[size] = 0;

	  if (! backup)
	    {
	      if (safe_unlink (to) == 0)
		to_dir_known_to_exist = true;
	    }
	  if (safe_symlink (buffer, to) != 0)
	    {
	      if (errno == ENOENT && ! to_dir_known_to_exist)
		makedirs (to);
	      if (safe_symlink (buffer, to) != 0)
		pfatal ("Can't create %s %s", "symbolic link", to);
	    }
	  free (buffer);
	  if (safe_lstat (to, &to_st) != 0)
	    pfatal ("Can't get file attributes of %s %s", "symbolic link", to);
	  insert_file_id (&to_st, CREATED);
	}
      else
	{
	  if (debug & 4)
	    say ("Renaming file %s to %s\n",
		 quotearg_n (0, from), quotearg_n (1, to));

	  defer_signals ();
	  if (safe_rename (from, to) != 0)
	    {
	      undefer_signals ();
	      bool to_dir_known_to_exist = false;

	      if (errno == ENOENT
		  && (to_errno == -1 || to_errno == ENOENT))
		{
		  makedirs (to);
		  to_dir_known_to_exist = true;
		  defer_signals ();
		  if (safe_rename (from, to) == 0)
		    goto rename_succeeded;
		  undefer_signals ();
		}

	      if (errno == EXDEV)
		{
		  struct stat tost;
		  if (! backup)
		    {
		      if (safe_unlink (to) == 0)
			to_dir_known_to_exist = true;
		      else if (errno != ENOENT)
			pfatal ("Can't remove file %s", quotearg (to));
		    }
		  copy_file (from, fromst, &(struct outfile) { .name = to },
			     &tost, 0, mode, 0, to_dir_known_to_exist);
		  insert_file_id (&tost, CREATED);
		  return;
		}

	      pfatal ("Can't rename file %s to %s",
		      quotearg_n (0, from), quotearg_n (1, to));
	    }

	rename_succeeded:
	  /* Do not clear outfrom->exists if it's possible that the
	     rename returned zero because FROM and TO are hard links to
	     the same file.  This possibility can't occur if the
	     source is a temporary file that we just created,
	     or if the destination doesn't exist, or if the
	     destination's link count is 1 (or zero!).  */
	  if (outfrom->temporary || 0 < to_errno
	      || (to_errno == 0 && to_st.st_nlink <= 1))
	    outfrom->exists = nullptr;
	  undefer_signals ();

	  insert_file_id (fromst, CREATED);
	}
    }
  else if (! backup)
    {
      if (debug & 4)
	say ("Removing file %s\n", quotearg (to));
      if (safe_unlink (to) != 0 && errno != ENOENT)
	pfatal ("Can't remove file %s", quotearg (to));
    }
}

/* Create OUT with OPEN_FLAGS, and with MODE adjusted so that
   we can read and write the file and that the file is not executable.
   Return the file descriptor.  */
int
create_file (struct outfile *out, int open_flags, mode_t mode,
	     bool to_dir_known_to_exist)
{
  char *file = out->name;
  mode |= S_IRUSR | S_IWUSR;
  mode &= ~ (S_IXUSR | S_IXGRP | S_IXOTH);
  defer_signals ();
  int fd = safe_open (file, O_CREAT | O_TRUNC | open_flags, mode);
  out->exists = fd < 0 ? nullptr : volatilize (file);
  undefer_signals ();
  if (fd < 0 && !to_dir_known_to_exist && errno == ENOENT)
    {
      char *f = xstrdup (file);
      makedirs (f);
      free (f);
      defer_signals ();
      fd = safe_open (file, O_CREAT | O_TRUNC | open_flags, mode);
      out->exists = fd < 0 ? nullptr : file;
      undefer_signals ();
    }
  if (fd < 0)
    pfatal ("Can't create file %s", quotearg (file));
  return fd;
}

static int
copy_to_fd (char *from, int tofd)
{
  int from_flags = O_RDONLY | O_BINARY | (follow_symlinks ? 0 : O_NOFOLLOW);
  int fromfd = safe_open (from, from_flags, 0);
  if (fromfd < 0)
    pfatal ("Can't reopen file %s", quotearg (from));
  for (idx_t i; 0 < (i = Read (fromfd, patchbuf, patchbufsize)); )
    Write (tofd, patchbuf, i);
  return fromfd;
}

/* Copy a file. */

void
copy_file (char *from, struct stat const *fromst,
	   struct outfile *outto, struct stat *tost,
	   int to_flags, mode_t mode, enum file_attributes attr,
	   bool to_dir_known_to_exist)
{
  int fromfd, tofd;
  char *to = outto->name;

  if (debug & 4)
    say ("Copying %s %s to %s\n",
	 S_ISLNK (mode) ? "symbolic link" : "file",
	 quotearg_n (0, from), quotearg_n (1, to));

  if (S_ISLNK (mode))
    {
      idx_t alloc;
      if (ckd_add (&alloc, fromst->st_size, 1))
	xalloc_die ();
      char *buffer = ximalloc (alloc);
      ssize_t r = safe_readlink (from, buffer, alloc);

      if (r < 0)
	pfatal ("Can't read symbolic link %s", from);
      if (r == alloc)
	fatal ("symbolic link %s grew", quotearg (from));
      buffer[r] = '\0';
      defer_signals ();
      outto->exists = safe_symlink (buffer, to) < 0 ? nullptr : volatilize (to);
      undefer_signals ();
      if (!outto->exists)
	pfatal ("Can't create %s %s", "symbolic link", to);
      if (tost && safe_lstat (to, tost) != 0)
	pfatal ("Can't get file attributes of %s %s", "symbolic link", to);
      free (buffer);
      fromfd = tofd = -1;
    }
  else
    {
      assert (S_ISREG (mode));
      if (! follow_symlinks)
	to_flags |= O_NOFOLLOW;
      tofd = create_file (outto, O_WRONLY | O_BINARY | to_flags, mode,
			  to_dir_known_to_exist);
      fromfd = copy_to_fd (from, tofd);
      if (tost && fstat (tofd, tost) != 0)
	pfatal ("Can't get file attributes of %s %s", "file", to);
    }

  set_file_attributes (to, tofd, attr, from, fromfd, fromst, mode, nullptr);
  if (0 <= fromfd && close (fromfd) < 0)
    read_fatal ();
  if (0 <= tofd && close (tofd) < 0)
    write_fatal ();
}

/* Append to file. */

void
append_to_file (char *from, char *to)
{
  int to_flags = (O_WRONLY | O_APPEND | O_BINARY
		  | (follow_symlinks ? 0 : O_NOFOLLOW));
  int tofd = safe_open (to, to_flags, 0);
  if (tofd < 0)
    pfatal ("Can't reopen file %s", quotearg (to));
  int fromfd = copy_to_fd (from, tofd);
  if (close (fromfd) < 0)
    read_fatal ();
  if (close (tofd) < 0)
    write_fatal ();
}

static char const DEV_NULL[] = NULL_DEVICE;

static char const RCSSUFFIX[] = ",v";
static char const CHECKOUT[] = "co %s";
static char const CHECKOUT_LOCKED[] = "co -l %s";
static char const RCSDIFF1[] = "rcsdiff %s";

#define SCCSPREFIX "s."
static char const GET[] = "get ";
static char const GET_LOCKED[] = "get -e ";
static char const SCCSDIFF1[] = "get -p ";
static char const SCCSDIFF2[] = "|diff - %s";

static char const CLEARTOOL_CO[] = "cleartool co -unr -nc ";

static char const PERFORCE_CO[] = "p4 edit ";

idx_t
quote_system_arg (char *quoted, char const *arg)
{
  char *q = quotearg_style (shell_quoting_style, arg);
  idx_t len = strlen (q);

  if (quoted)
    memcpy (quoted, q, len + 1);
  return len;
}

/* Get the status of the file named by TRYBUF into ST.
   Return true if successful, false (setting errno) otherwise.
   Before getting the status, copy to DIREND the concatenation of A,
   B, and (if nonnull) C; this can modify TRYBUF.  */
static bool
trystat (char *trybuf, struct stat *st, char *dirend,
	 char const *a, char const *b, char const *c)
{
  char *p = stpcpy (dirend, a);
  if (b)
    p = stpcpy (p, b);
  if (c)
    strcpy (p, c);
  return safe_stat (trybuf, st) == 0;
}

/* Return "RCS" if FILENAME is controlled by RCS,
   "SCCS" if it is controlled by SCCS,
   "ClearCase" if it is controlled by Clearcase,
   "Perforce" if it is controlled by Perforce,
   and 0 otherwise.
   READONLY is true if we desire only readonly access to FILENAME.
   FILESTAT describes FILENAME's status or is 0 if FILENAME does not exist.
   If successful and if GETBUF is nonzero, set *GETBUF to a command
   that gets the file; similarly for DIFFBUF and a command to diff the file
   (but set *DIFFBUF to a null pointer if the diff operation is meaningless).
   *GETBUF and *DIFFBUF must be freed by the caller.  */
char const *
version_controller (char const *filename, bool readonly,
		    struct stat const *filestat, char **getbuf, char **diffbuf)
{
  struct stat cstat;
  char const *filebase = last_component (filename);
  char const *dotslash = *filename == '-' ? "./" : "";
  idx_t dirlen = filebase - filename;
  idx_t filebaselen = strlen (filebase);
  idx_t maxfixlen = sizeof "SCCS/" - 1 + sizeof SCCSPREFIX - 1;
  idx_t maxtrysize = dirlen + filebaselen + maxfixlen + 1;
  idx_t quotelen = quote_system_arg (0, filename);
  idx_t maxgetsize = sizeof CLEARTOOL_CO + quotelen + maxfixlen;
  idx_t maxdiffsize =
    (sizeof SCCSDIFF1 + sizeof SCCSDIFF2 + sizeof DEV_NULL - 1
     + 2 * quotelen + maxfixlen);
  char *trybuf = ximalloc (maxtrysize);
  char const *r = 0;

  char *dirend = mempcpy (trybuf, filename, dirlen);

  /* Check that RCS file is not working file.
     Some hosts don't report file name length errors.  */

  if ((trystat (trybuf, &cstat, dirend, "RCS/", filebase, RCSSUFFIX)
       || trystat (trybuf, &cstat, dirend, "RCS/", filebase, 0)
       || trystat (trybuf, &cstat, dirend, filebase, RCSSUFFIX, nullptr))
      && ! (filestat
	    && filestat->st_dev == cstat.st_dev
	    && filestat->st_ino == cstat.st_ino))
    {
      if (getbuf)
	{
	  char *p = *getbuf = xmalloc (maxgetsize);
	  p += sprintf (p, readonly ? CHECKOUT : CHECKOUT_LOCKED, dotslash);
	  p += quote_system_arg (p, filename);
	  *p = '\0';
	}

      if (diffbuf)
	{
	  char *p = *diffbuf = xmalloc (maxdiffsize);
	  p += sprintf (p, RCSDIFF1, dotslash);
	  p += quote_system_arg (p, filename);
	  *p++ = '>';
	  strcpy (p, DEV_NULL);
	}

      r = "RCS";
    }
  else if (trystat (trybuf, &cstat, dirend, "SCCS/" SCCSPREFIX, filebase,
		    nullptr)
	   || trystat (trybuf, &cstat, dirend, SCCSPREFIX, filebase, nullptr))
    {
      if (getbuf)
	{
	  char *p = *getbuf = xmalloc (maxgetsize);
	  p += sprintf (p, readonly ? GET : GET_LOCKED);
	  p += quote_system_arg (p, trybuf);
	  *p = '\0';
	}

      if (diffbuf)
	{
	  char *p = *diffbuf = xmalloc (maxdiffsize);
	  strcpy (p, SCCSDIFF1);
	  p += sizeof SCCSDIFF1 - 1;
	  p += quote_system_arg (p, trybuf);
	  p += sprintf (p, SCCSDIFF2, dotslash);
	  p += quote_system_arg (p, filename);
	  *p++ = '>';
	  strcpy (p, DEV_NULL);
	}

      r = "SCCS";
    }
  else if (!readonly && filestat
	   && trystat (trybuf, &cstat, dirend, filebase, "@@", nullptr)
	   && S_ISDIR (cstat.st_mode))
    {
      if (getbuf)
	{
	  char *p = *getbuf = xmalloc (maxgetsize);
	  strcpy (p, CLEARTOOL_CO);
	  p += sizeof CLEARTOOL_CO - 1;
	  p += quote_system_arg (p, filename);
	  *p = '\0';
	}

      if (diffbuf)
	*diffbuf = 0;

      r = "ClearCase";
     }
  else if (!readonly && filestat &&
           (getenv("P4PORT") || getenv("P4USER") || getenv("P4CONFIG")))
    {
      if (getbuf)
	{
	  char *p = *getbuf = xmalloc (maxgetsize);
	  strcpy (p, PERFORCE_CO);
	  p += sizeof PERFORCE_CO - 1;
	  p += quote_system_arg (p, filename);
	  *p = '\0';
	}

      if (diffbuf)
	*diffbuf = 0;

      r = "Perforce";
    }

  free (trybuf);
  return r;
}

/* Get FILENAME from version control system CS.  The file already exists if
   EXISTS.  Only readonly access is needed if READONLY.
   Use the command GETBUF to actually get the named file.
   Store the resulting file status into *FILESTAT.
   Return true if successful.  */
bool
version_get (char *filename, char const *cs, bool exists, bool readonly,
	     char const *getbuf, struct stat *filestat)
{
  if (patch_get < 0)
    {
      if (*ask ("Get file %s from %s%s? [y] ",
		quotearg (filename), cs, readonly ? "" : " with lock")
	  == 'n')
	return 0;
    }

  if (dry_run)
    {
      if (! exists)
	fatal ("can't do dry run on nonexistent version-controlled file %s; invoke '%s' and try again",
	       quotearg (filename), getbuf);
    }
  else
    {
      if (verbosity == VERBOSE)
	say ("Getting file %s from %s%s...\n", quotearg (filename),
	     cs, readonly ? "" : " with lock");
      if (systemic (getbuf) != 0)
	fatal ("Can't get file %s from %s", quotearg (filename), cs);
      if (safe_stat (filename, filestat) != 0)
	pfatal ("%s", quotearg (filename));
    }

  return 1;
}

/* Allocate a unique area for a string. */

char *
savebuf (char const *s, idx_t size)
{
  return size ? xmemdup (s, size) : nullptr;
}

/* Terminal output, pun intended. */

void
fatal (char const *format, ...)
{
  fputs (program_name, stderr);
  fputs (": **** ", stderr);
  va_list args;
  va_start (args, format);
  vfprintf (stderr, format, args);
  va_end (args);
  fputc ('\n', stderr);
  fflush (stderr);
  fatal_exit ();
}

void
xalloc_die (void)
{
  fatal ("out of memory");
}

void
read_fatal (void)
{
  pfatal ("read error");
}

void
write_fatal (void)
{
  pfatal ("write error");
}

/* Output to FP a line containing the concatenation of the remaining
   string arguments.  A null pointer terminates the string args.  */
void
putline (FILE *fp, ...)
{
  va_list ap;
  va_start (ap, fp);
  for (char *arg; (arg = va_arg (ap, char *)); )
    Fputs (arg, fp);
  va_end (ap);
  Fputc ('\n', fp);
}

/* Say something from patch, something from the system, then silence . . . */

void
pfatal (char const *format, ...)
{
  int errnum = errno;
  fputs (program_name, stderr);
  fputs (": **** ", stderr);
  va_list args;
  va_start (args, format);
  vfprintf (stderr, format, args);
  va_end (args);
  fprintf (stderr, " : %s\n",
	   errnum == EILSEQ ? "Invalid byte sequence" : strerror (errnum));
  fflush (stderr);
  fatal_exit ();
}

/* Tell the user something.  */

static void
ATTRIBUTE_FORMAT ((_GL_ATTRIBUTE_SPEC_PRINTF_STANDARD, 1, 0))
vsay (char const *format, va_list args)
{
  if (vfprintf (stdout, format, args) < 0)
    write_fatal ();
  Fflush (stdout);
}

void
say (char const *format, ...)
{
  va_list args;
  va_start (args, format);
  vsay (format, args);
  va_end (args);
}

/* Get a response from the user, somehow or other. */

char *
ask (char const *format, ...)
{
  static int ttyfd = -2;
  va_list args;

  va_start (args, format);
  int nout = vfprintf (stdout, format, args);
  va_end (args);
  if (nout < 0)
    write_fatal ();
  Fflush (stdout);

  if (ttyfd == -2)
    {
      /* If standard output is not a tty, don't bother opening /dev/tty,
	 since it's unlikely that stdout will be seen by the tty user.
	 The isatty test also works around a bug in GNU Emacs 19.34 under Linux
	 which makes a call-process 'patch' hang when it reads from /dev/tty.
	 POSIX.1-2024 line 109671 requires that we read /dev/tty,
	 though.  */
      ttyfd = (posixly_correct || isatty (STDOUT_FILENO)
	       ? open (TTY_DEVICE, O_RDONLY)
	       : -1);
    }

  if (ttyfd < 0)
    {
      /* No terminal at all -- default it.  */
      Fputc ('\n', stdout);
      patchbuf[0] = '\n';
      patchbuf[1] = '\0';
    }
  else
    {
      idx_t s = 0;
      while (true)
	{
	  idx_t readsize = MIN (patchbufsize - 1 - s, IO_BUFSIZE);
	  ssize_t r = read (ttyfd, patchbuf + s, readsize);
	  if (r <= 0)
	    {
	      if (r == 0)
		Fputs ("EOF\n", stdout);
	      else
		{
		  error (0, errno, "tty read failed");
		  ignore_value (close (ttyfd));
		  ttyfd = -1;
		}
	      break;
	    }
	  s += r;
	  if (r < readsize || patchbuf[s - 1] == '\n')
	    break;
	  if (s == patchbufsize - 1)
	    grow_patchbuf ();
	}
      patchbuf[s] = '\0';
    }

  return patchbuf;
}

/* Return nonzero if it OK to reverse a patch.  */

bool
ok_to_reverse (char const *format, ...)
{
  bool r = false;

  if (noreverse_flag || ! (force && verbosity == SILENT))
    {
      va_list args;
      va_start (args, format);
      vsay (format, args);
      va_end (args);
    }

  if (noreverse_flag)
    {
      say ("  Skipping patch.\n");
      skip_rest_of_patch = true;
    }
  else if (force)
    {
      if (verbosity != SILENT)
	say ("  Applying it anyway.\n");
    }
  else if (batch)
    {
      say (reverse_flag ? "  Ignoring -R.\n" : "  Assuming -R.\n");
      r = true;
    }
  else
    {
      r = (*ask (reverse_flag ? "  Ignore -R? [n] " : "  Assume -R? [n] ")
	   == 'y');
      if (! r)
	{
	  if (*ask ("Apply anyway? [n] ") != 'y')
	    {
	      if (verbosity != SILENT)
		say ("Skipping patch.\n");
	      skip_rest_of_patch = true;
	    }
	}
    }

  return r;
}

/* Critical sections and signals.  */

/* If nonzero, the corresponding signal was the first one received.
   Otherwise, no signal has been received.  */
static sig_atomic_t volatile signal_received;

/* Whether we are in a critical section, so that signals are deferred
   until the next call to undefer_signal.  */
static sig_atomic_t signals_are_deferred;

/* Signal SIG has arrived and can be acted on now.
   Clean up and arrange to terminate.
   This function is async-signal-safe.  */
static void
fatal_cleanup_and_terminate (int sig)
{
  fatal_cleanup ();

  /* Cause the program to terminate with signal SIG.  Termination occurs now
     if not in a signal handler, otherwise when the signal handler returns.  */
  signal (sig, SIG_DFL);
  raise (sig);
}

/* Handle a delivered signal.  While this function is running,
   all signals that 'patch' cares about are blocked.
   This function is async-signal-safe.  */
static void
handle_signal (int sig)
{
#if ! (HAVE_SIGACTION && HAVE_SIGFILLSET)
  /* Cater to non-POSIX systems that lack sigaction and reset to SIG_DFL.  */
  signal (sig, SIG_IGN);
#endif

  /* If multiple signals arrive, handle just the first one.
     That's good enough, as 'patch' is about to exit.  */
  if (signal_received)
    return;
  signal_received = sig;

  if (!signals_are_deferred)
    {
      signals_are_deferred = 1;	/* Avoid infinite recursion.  */
      fatal_cleanup_and_terminate (sig);
    }
}

/* Defer incoming signals until later.  */
void
defer_signals (void)
{
  signals_are_deferred = 1;
}

/* Handle any signals that have arrived, and stop deferring them.  */
void
undefer_signals (void)
{
  signals_are_deferred = 0;
  int sig = signal_received;
  if (sig)
    fatal_cleanup_and_terminate (sig);
}

void
init_signals (void)
{
  static int const sigs[] =
    {
      SIGHUP,
      SIGINT,
#ifdef SIGPIPE
      SIGPIPE,
#endif
#ifdef SIGTERM
      SIGTERM,
#endif
#ifdef SIGXCPU
      SIGXCPU,
#endif
#ifdef SIGXFSZ
      SIGXFSZ,
#endif
    };
  enum { NUM_SIGS = sizeof sigs / sizeof *sigs };

  /* System V fork+wait does not work if SIGCHLD is ignored.  */
  signal (SIGCHLD, SIG_DFL);

#if HAVE_SIGACTION && HAVE_SIGFILLSET
  struct sigaction fatal_act = { .sa_handler = handle_signal };
  sigfillset (&fatal_act.sa_mask);
  for (int i = 0; i < NUM_SIGS; i++)
    {
      struct sigaction initial_act;
      if (sigaction (sigs[i], nullptr, &initial_act) == 0
	  && initial_act.sa_handler != SIG_IGN)
	sigaction (sigs[i], &fatal_act, nullptr);
    }
#else
  for (int i = 0; i < NUM_SIGS; i++)
    if (signal (sigs[i], SIG_IGN) != SIG_IGN)
      signal (sigs[i], handle_signal);
#endif
}

int
systemic (char const *command)
{
  if (debug & 8)
    say ("+ %s\n", command);
  Fflush (stdout);
  return system (command);
}

/* Replace '/' with '\0' in FILENAME if it marks a place that
   needs testing for the existence of directory.  Return the address
   of the last location replaced, or 0 if none were replaced.  */
static char *
replace_slashes (char *filename)
{
  char *f;
  char *last_location_replaced = 0;
  char const *component_start;

  for (f = filename + FILE_SYSTEM_PREFIX_LEN (filename);  ISSLASH (*f);  f++)
    /* do nothing */ ;

  component_start = f;

  for (; *f; f++)
    if (ISSLASH (*f))
      {
	char *slash = f;

	/* Treat multiple slashes as if they were one slash.  */
	while (ISSLASH (f[1]))
	  f++;

	/* Ignore slashes at the end of the path.  */
	if (! f[1])
	  break;

	/* "." and ".." need not be tested.  */
	if (! (slash - component_start <= 2
	       && component_start[0] == '.' && slash[-1] == '.'))
	  {
	    *slash = '\0';
	    last_location_replaced = slash;
	  }

	component_start = f + 1;
      }

  return last_location_replaced;
}

/* Make sure we'll have the directories to create a file.
   Ignore the last element of 'filename'.  */

static void
makedirs (char const *name)
{
  char *filename = xstrdup (name);
  char *f;
  char *flim = replace_slashes (filename);

  /* FIXME: Now with the pathname lookup cache, there is no reason for
     deferring the creation of directories. Callers should be updated. */

  if (flim)
    {
      /* Create any missing directories, replacing NULs by '/'s.
	 Ignore errors.  We may have to keep going even after an EEXIST,
	 since the path may contain ".."s; and when there is an EEXIST
	 failure the system may return some other error number.
	 Any problems will eventually be reported when we create the file.  */
      for (f = filename;  f <= flim;  f++)
	if (!*f)
	  {
	    safe_mkdir (filename,
		   S_IRUSR|S_IWUSR|S_IXUSR
		   |S_IRGRP|S_IWGRP|S_IXGRP
		   |S_IROTH|S_IWOTH|S_IXOTH);
	    *f = '/';
	  }
    }
  free (filename);
}

/* Remove empty ancestor directories of FILENAME.
   Ignore errors, since the path may contain ".."s, and when there
   is an EEXIST failure the system may return some other error number.  */
void
removedirs (char const *name)
{
  char *filename = xstrdup (name);

  for (idx_t i = strlen (filename);  i != 0;  i--)
    if (ISSLASH (filename[i])
	&& ! (ISSLASH (filename[i - 1])
	      || (filename[i - 1] == '.'
		  && (i == 1
		      || ISSLASH (filename[i - 2])
		      || (filename[i - 2] == '.'
			  && (i == 2
			      || ISSLASH (filename[i - 3])))))))
      {
	filename[i] = '\0';
	if (safe_rmdir (filename) == 0 && verbosity == VERBOSE)
	  say ("Removed empty directory %s\n", quotearg (filename));
	filename[i] = '/';
      }
  free (filename);
}

static struct timespec initial_time;

void
init_time (void)
{
  gettime (&initial_time);
}

static char *
parse_c_string (char const *s, char const **endp)
{
  char *u, *v;

  assert (*s == '"');
  s++;
  u = v = xmalloc (strlen (s));
  for (;;)
    {
      char c = *s++;

      switch (c)
	{
	  case 0:
	    goto fail;

	  case '"':
	    *v = '\0';
	    /* 'u = xrealloc (u, v + 1 - u);' would save a bit of space here,
	       but would likely be more trouble than it's worth.  */
	    if (endp)
	      *endp = s;
	    return u;

	  case '\\':
	    break;

	  default:
	    *v++ = c;
	    continue;
	}

      c = *s++;
      switch (c)
	{
	  case 'a': c = '\a'; break;
	  case 'b': c = '\b'; break;
	  case 'f': c = '\f'; break;
	  case 'n': c = '\n'; break;
	  case 'r': c = '\r'; break;
	  case 't': c = '\t'; break;
	  case 'v': c = '\v'; break;
	  case '\\': case '"':
	    break;  /* verbatim */
	  case '0': case '1': case '2': case '3':
	    {
	      int acc = (c - '0') << 6;

	      c = *s++;
	      if (c < '0' || c > '7')
	        goto fail;
	      acc |= (c - '0') << 3;
	      c = *s++;
	      if (c < '0' || c > '7')
	        goto fail;
	      acc |= (c - '0');
	      if (!acc)
		goto fail;
	      c = acc;
	      break;
	    }
	  default:
	    goto fail;
	}
      *v++ = c;
    }

fail:
  free (u);
  if (endp)
    *endp = s;
  return nullptr;
}

/* Strip up to STRIP_LEADING leading slashes.
   If STRIP_LEADING is negative, strip all leading slashes.
   Returns a pointer into NAME on success, and a null pointer otherwise.
  */
static bool
strip_leading_slashes (char *name, intmax_t strip_leading)
{
  intmax_t s = strip_leading;
  char *p, *n;

  for (p = n = name;  *p;  p++)
    {
      if (ISSLASH (*p))
	{
	  while (ISSLASH (p[1]))
	    p++;
	  if (strip_leading < 0 || --s >= 0)
	      n = p+1;
	}
    }
  if ((strip_leading < 0 || s <= 0) && *n)
    {
      memmove (name, n, strlen (n) + 1);
      return true;
    }
  else
    return false;
}


/* Make filenames more reasonable. */

void
fetchname (char const *at, intmax_t strip_leading, char **pname,
	   char **ptimestr, struct timespec *pstamp)
{
    char *name;
    const char *t;
    char *timestr = nullptr;
    struct timespec stamp = { .tv_sec = -1, .tv_nsec = -1 };

    while (c_isspace (*at))
	at++;
    if (debug & 128)
	say ("fetchname %s %jd\n", at, strip_leading);

    if (*at == '"')
      {
	name = parse_c_string (at, &t);
	if (! name)
	  {
	    if (debug & 128)
	      say ("ignoring malformed filename %s\n", quotearg (at));
	    return;
	  }
      }
    else
      {
	for (t = at;  *t;  t++)
	  {
	    if (c_isspace (*t))
	      {
		/* Allow file names with internal spaces,
		   but only if a tab separates the file name from the date.  */
		char const *u = t;
		while (*u != '\t' && c_isspace (u[1]))
		  u++;
		if (*u != '\t' && (strchr (u + 1, pstamp ? '\t' : '\n')))
		  continue;
		break;
	      }
	  }
	name = ximemdup0 (at, t - at);
      }

    /* If the name is "/dev/null", ignore the name and mark the file
       as being nonexistent.  The name "/dev/null" appears in patches
       regardless of how NULL_DEVICE is spelled.  */
    if (strcmp (name, "/dev/null") == 0)
      {
	free (name);
	if (pstamp)
	  {
	    pstamp->tv_sec = 0;
	    pstamp->tv_nsec = 0;
	  }
	return;
      }

    /* Ignore the name if it doesn't have enough slashes to strip off.  */
    if (! strip_leading_slashes (name, strip_leading))
      {
	free (name);
	return;
      }

    if (ptimestr)
      {
	char const *u = t + strlen (t);

	if (u != t && *(u-1) == '\n')
	  u--;
	if (u != t && *(u-1) == '\r')
	  u--;
	timestr = ximemdup0 (t, u - t);
      }

      if (*t != '\n')
	{
	  if (! pstamp)
	    {
	      free (name);
	      free (timestr);
	      return;
	    }

	  /* The head says a file is nonexistent if its timestamp is the epoch;
	     but when the listed time is local time not UTC, POSIX.1
	     allows local time offset anywhere in the range
	     -25:00 < offset < +26:00, so match any time in that range.
	     The algorithm below can match a time when it is close to
	     but not at the epoch if the time string has a timezone
	     indication, but this bug would be a pain to fix and the
	     situation is so rare that it is perhaps not worth fixing.  */

	  if ((parse_datetime (&stamp, t, &initial_time)
	       & ! (set_time | set_utc))
	      && (!TYPE_SIGNED (time_t)
		  || (timespec_cmp (((struct timespec)
				     { .tv_sec = -25 * 60 * 60 }),
				    stamp)
		      < 0))
	      && (timespec_cmp (stamp,
				((struct timespec)
				 { .tv_sec = 26 * 60 * 60 }))
		  < 0))
	    stamp = (struct timespec) {0};
	}

    free (*pname);
    *pname = name;
    if (ptimestr)
      {
	free (*ptimestr);
	*ptimestr = timestr;
      }
    if (pstamp)
      *pstamp = stamp;
}

char *
parse_name (char const *s, intmax_t strip_leading, char const **endp)
{
  char *ret;

  while (c_isspace (*s))
    s++;
  if (*s == '"')
    {
      ret = parse_c_string (s, endp);
      if (!ret)
        return nullptr;
    }
  else
    {
      char const *t;

      for (t = s; *t && !c_isspace (*t); t++)
	/* do nothing*/ ;
      ret = ximemdup0 (s, t - s);
      if (endp)
	*endp = t;
    }
  if (! strip_leading_slashes (ret, strip_leading))
    {
      free (ret);
      ret = nullptr;
    }
  return ret;
}

void
Fclose (FILE *stream)
{
  Fflush (stream);
  if (fclose (stream) < 0)
    write_fatal ();
}

void
Fflush (FILE *stream)
{
  if (fflush (stream) < 0)
    write_fatal ();
}

void
Fprintf (FILE *stream, char const *format, ...)
{
  va_list args;
  va_start (args, format);
  int nout = vfprintf (stream, format, args);
  va_end (args);
  if (nout < 0)
    write_fatal ();
}

void
Fputc (int c, FILE *stream)
{
  if (fputc (c, stream) < 0)
    write_fatal ();
}

void
Fputs (char const *s, FILE *stream)
{
  if (fputs (s, stream) < 0)
    write_fatal ();
}

void
Fseeko (FILE *stream, off_t offset, int ptrname)
{
  if (fseeko (stream, offset, ptrname) < 0)
    pfatal ("fseeko");
}

off_t
Ftello (FILE *stream)
{
  off_t off = ftello (stream);
  if (off < 0)
    pfatal ("ftello");
  return off;
}

void
Fwrite (void const *ptr, size_t size, size_t nitems, FILE *stream)
{
  if (fwrite (ptr, size, nitems, stream) < nitems)
    write_fatal ();
}

idx_t
Read (int filedes, void *buf, idx_t nbyte)
{
  ssize_t r = read (filedes, buf, MIN (nbyte, IO_BUFSIZE));
  if (r < 0)
    read_fatal ();
  return r;
}

static void
Write (int filedes, void const *buf, idx_t nbyte)
{
  char const *b = buf, *blim = b + nbyte;
  while (b < blim)
    {
      ssize_t w = write (filedes, b, MIN (blim - b, IO_BUFSIZE));
      if (w < 0)
	write_fatal ();
      b += w;
    }
}

/* Name of default temporary directory; must not contain \n.  */
#ifndef TMPDIR
#define TMPDIR "/tmp"
#endif

struct try_safe_open_args
  {
    struct outfile *out;
    int flags;
    mode_t mode;
  };

static int
try_safe_open (char *template, void *vargs)
{
  struct try_safe_open_args *args = vargs;
  struct outfile *out = args->out;
  int flags = O_CREAT | O_EXCL | args->flags;
  mode_t mode = args->mode;
  defer_signals ();
  int fd = safe_open (template, flags, mode);
  out->exists = fd < 0 ? nullptr : volatilize (template);
  undefer_signals ();
  if (0 <= fd || errno != ENOENT)
    return fd;
  makedirs (template);
  defer_signals ();
  fd = safe_open (template, flags, mode);
  out->exists = fd < 0 ? nullptr : volatilize (template);
  int err = errno;
  undefer_signals ();
  errno = err;
  return fd;
}

int
make_tempfile (struct outfile *out, char letter, char const *real_name,
	       int flags, mode_t mode)
{
  char *template;
  struct try_safe_open_args args = {
    .out = out,
    .flags = flags,
    .mode = mode,
  };
  int fd;

  if (real_name && ! dry_run)
    {
      /* Use the real name sans any newlines in the last component,
	 followed by ".", LETTER, and 6 random chars.  */
      char const *last = last_component (real_name);
      idx_t realdirlen = last - real_name;
      template = ximalloc (realdirlen + strlen (last) + sizeof ".cXXXXXX");
      char *t = mempcpy (template, real_name, realdirlen);
      for (char const *p = last; *p; p++)
	t += (*t = *p) != '\n';
      sprintf (t, ".%cXXXXXX", letter);
    }
  else
    {
      /* In the temp dir, use the name "p", LETTER, and 6 random chars.  */

      static char const *tmpdir;
      static idx_t tmpdirlen;

      if (!tmpdir)
	{
	  tmpdir = TMPDIR;

	  /* TMPDIR is the Unix tradition; TMP and TEMP are DOS traditions.  */
	  static char const envnames[][sizeof "TMPDIR"]
	    = { "TMPDIR", "TMP", "TEMP" };
	  for (int i = 0; i < ARRAY_SIZE (envnames); i++)
	    {
	      char const *val = getenv (envnames[i]);
	      if (val)
		{
		  tmpdir = val;
		  break;
		}
	    }
	  tmpdirlen = strlen (tmpdir);
	}

      template = ximalloc (tmpdirlen + 10);
      sprintf (mempcpy (template, tmpdir, tmpdirlen), "/p%cXXXXXX", letter);
    }
  fd = try_tempname (template, 0, &args, try_safe_open);
  out->name = out->alloc = template;
  return fd;
}

int
stat_file (char *filename, struct stat *st)
{
  int (*xstat) (char *, struct stat *) =
    follow_symlinks ? safe_stat : safe_lstat;

  return xstat (filename, st) == 0 ? 0 : errno;
}

/* Check if a filename is relative and free of ".." components.
   Such a path cannot lead to files outside the working tree
   as long as the working tree only contains symlinks that are
   "filename_is_safe" when followed.  */
bool
filename_is_safe (char const *name)
{
  if (IS_ABSOLUTE_FILE_NAME (name))
    return false;
  while (*name)
    {
      if (*name == '.' && *++name == '.'
	  && ( ! *++name || ISSLASH (*name)))
	return false;
      while (*name && ! ISSLASH (*name))
	name++;
      while (ISSLASH (*name))
	name++;
    }
  return true;
}

/* Check if we are in the root of a particular filesystem namespace ("/" on
   UNIX or a particular drive's root on DOS-like systems).  */
bool
cwd_is_root (char const *name)
{
  int prefix_len = FILE_SYSTEM_PREFIX_LEN (name);
  struct stat st;
  dev_t root_dev;
  ino_t root_ino;

  if (prefix_len == 0)
    {
      static dev_t main_root_dev;
      static ino_t main_root_ino;
      if (!main_root_ino)
	{
	  if (stat ("/", &st) < 0)
	    return false;
	  main_root_dev = st.st_dev;
	  main_root_ino = st.st_ino;
	}
      root_dev = main_root_dev;
      root_ino = main_root_ino;
    }
  else
    {
      char root[4];
      memcpy (root, name, prefix_len);
      root[prefix_len] = '/';
      root[prefix_len + 1] = 0;
      if (stat (root, &st) < 0)
	return false;
      root_dev = st.st_dev;
      root_ino = st.st_ino;
    }
  static dev_t cwd_dev;
  static ino_t cwd_ino;
  if (!cwd_ino)
    {
      if (stat (".", &st) < 0)
	return false;
      cwd_dev = st.st_dev;
      cwd_ino = st.st_ino;
    }
  return (root_dev == cwd_dev) & (root_ino == cwd_ino);
}
