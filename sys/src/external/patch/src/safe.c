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

#include <config.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/resource.h>
#include <sys/time.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <safe.h>

#include <basename-lgpl.h>
#include <hash.h>
#include <filename.h>
#include <xalloc.h>

#include "common.h"

#include "util.h"

#define LIST_INLINE _GL_EXTERN_INLINE
#include "list.h"

#ifndef EFTYPE
# define EFTYPE 0
#endif

#ifdef O_PATH
enum { O_PATHSEARCH = O_PATH };
#else
enum { O_PATHSEARCH = O_SEARCH };
#endif

enum { MAX_PATH_COMPONENTS = 1024 };

/* Flag to turn the safe_* functions into their unsafe variants; files may then
   lie outside the current working directory. */
bool unsafe;

/* Path lookup results are cached in a hash table + LRU list. When the
   cache is full, the oldest entries are removed.  */

static intmax_t dirfd_cache_misses;

struct cached_dirfd {
  struct list_head lru_link;
  struct list_head children_link, children;
  struct cached_dirfd *parent;

  char *name;
  int fd;
};

static Hash_table *cached_dirfds;
static rlim_t min_cached_fds = 8;
static rlim_t max_cached_fds;
static LIST_HEAD (lru_list);

static size_t hash_cached_dirfd (const void *entry, size_t table_size)
{
  const struct cached_dirfd *d = entry;
  size_t strhash = hash_string (d->name, table_size);
  return (strhash * 31 + d->parent->fd) % table_size;
}

static bool compare_cached_dirfds (const void *_a,
				   const void *_b)
{
  const struct cached_dirfd *a = _a;
  const struct cached_dirfd *b = _b;

  return (a->parent->fd == b->parent->fd &&
	  !strcmp (a->name, b->name));
}

static void free_cached_dirfd (struct cached_dirfd *entry)
{
  list_del (&entry->children_link);
  free (entry->name);
  free (entry);
}

static void init_dirfd_cache (void)
{
  struct rlimit nofile;

  if (getrlimit (RLIMIT_NOFILE, &nofile) == 0)
    {
      if (nofile.rlim_cur == RLIM_INFINITY)
        max_cached_fds = RLIM_INFINITY;
      else
	max_cached_fds = MAX (nofile.rlim_cur / 4, min_cached_fds);
    }
  else
    max_cached_fds = min_cached_fds;

  cached_dirfds = hash_initialize (min_cached_fds, nullptr,
				   hash_cached_dirfd,
				   compare_cached_dirfds, nullptr);

  if (!cached_dirfds)
    xalloc_die ();
}

static struct cached_dirfd *lookup_cached_dirfd (struct cached_dirfd *dir, const char *name)
{
  struct cached_dirfd *entry = nullptr;

  if (cached_dirfds)
    {
      struct cached_dirfd key;
      key.parent = dir;
      key.name = (char *) name;
      entry = hash_lookup (cached_dirfds, &key);
    }

  return entry;
}

static void remove_cached_dirfd (struct cached_dirfd *entry)
{
  while (! list_empty (&entry->children))
    {
      struct cached_dirfd *child =
	list_entry (entry->children.next,
		    offsetof (struct cached_dirfd, children_link));
      list_del_init (&child->children_link);
      /* assert (list_empty (&child->children_link)); */
      hash_remove (cached_dirfds, child);  /* noop when not hashed */
    }
  list_del (&entry->lru_link);
  hash_remove (cached_dirfds, entry);  /* noop when not hashed */
  close (entry->fd);
  free_cached_dirfd (entry);
}

static void insert_cached_dirfd (struct cached_dirfd *entry, int keepfd)
{
  if (!cached_dirfds)
    init_dirfd_cache ();

  if (max_cached_fds != RLIM_INFINITY)
    {
      /* Trim off the least recently used entries */
      while (hash_get_n_entries (cached_dirfds) >= max_cached_fds)
	{
	  struct cached_dirfd *last =
	    list_entry (lru_list.prev,
			offsetof (struct cached_dirfd, lru_link));
	  if (&last->lru_link == &lru_list)
	    break;
	  if (last->fd == keepfd)
	    {
	      last = list_entry (last->lru_link.prev,
				 offsetof (struct cached_dirfd, lru_link));
	      if (&last->lru_link == &lru_list)
		break;
	    }
	  remove_cached_dirfd (last);
	}
    }

  /* Only insert if the parent still exists. */
  if (! list_empty (&entry->children_link))
    if (hash_insert (cached_dirfds, entry) != entry)
      xalloc_die ();
}

static void invalidate_cached_dirfd (int dirfd, const char *name)
{
  struct cached_dirfd dir, key, *entry;
  if (!cached_dirfds)
    return;

  dir.fd = dirfd;
  key.parent = &dir;
  key.name = (char *) name;
  entry = hash_lookup (cached_dirfds, &key);
  if (entry)
    remove_cached_dirfd (entry);
}

/* Put the looked up path back onto the lru list.  Return the file descriptor
   of the top entry.  */
static int put_path (struct cached_dirfd *entry)
{
  int fd = entry->fd;

  while (entry)
    {
      struct cached_dirfd *parent = entry->parent;
      if (! parent)
	break;
      list_add (&entry->lru_link, &lru_list);
      entry = parent;
    }

  return fd;
}

static struct cached_dirfd *
new_cached_dirfd (struct cached_dirfd *dir, char *name, int fd)
{
  struct cached_dirfd *entry = xmalloc (sizeof (struct cached_dirfd));

  INIT_LIST_HEAD (&entry->lru_link);
  list_add (&entry->children_link, &dir->children);
  INIT_LIST_HEAD (&entry->children);
  entry->parent = dir;
  entry->name = name;
  entry->fd = fd;
  return entry;
}

/* In DIR, look up NAME as a subdirectory.
   Return the corresponding cache entry if found, a null pointer otherwise.
   If KEEPFD is nonnegative, make sure that any cache entry for it is not
   removed from the cache (and KEEPFD remains open).  */
static struct cached_dirfd *
openat_cached (struct cached_dirfd *dir, char const *name, int keepfd)
{
  int fd;
  struct cached_dirfd *entry = lookup_cached_dirfd (dir, name);

  if (entry)
    {
      list_del_init (&entry->lru_link);
      /* assert (list_empty (&entry->lru_link)); */
      return entry;
    }
  dirfd_cache_misses++;

  /* Actually get the new directory file descriptor. Don't follow
     symbolic links. */
  fd = openat (dir->fd, name, O_PATHSEARCH | O_DIRECTORY | O_NOFOLLOW);

  /* Don't cache errors. */
  if (fd < 0)
    return nullptr;

  /* Store new cache entry */
  entry = new_cached_dirfd (dir, xstrdup (name), fd);
  insert_cached_dirfd (entry, keepfd);
  return entry;
}

static idx_t ATTRIBUTE_PURE
count_path_components (const char *path)
{
  while (ISSLASH (*path))
    path++;
  if (! *path)
    return 1;
  for (idx_t components = 0; ; components++)
    {
      if (!*path)
	return components;
      while (*path && ! ISSLASH (*path))
	path++;
      while (ISSLASH (*path))
	path++;
    }
}

/* A symlink to resolve. */
struct symlink {
  struct symlink *prev;
  char *path;
};

static void push_symlink (struct symlink **stack, struct symlink *symlink)
{
  symlink->prev = *stack;
  *stack = symlink;
}

static void pop_symlink (struct symlink **stack)
{
  struct symlink *top = *stack;
  *stack = top->prev;
  free (top);
}

static int cwd_stat_errno = -1;
static struct stat cwd_stat;

static struct symlink *read_symlink(int dirfd, const char *name)
{
  int saved_errno = errno;
  struct stat st;
  struct symlink *symlink;
  char *buffer;
  ssize_t ret;

  if (fstatat (dirfd, name, &st, AT_SYMLINK_NOFOLLOW)
      || ! S_ISLNK (st.st_mode))
    {
      errno = saved_errno;
      return nullptr;
    }
  idx_t symlinksize;
  if (ckd_add (&symlinksize, st.st_size, 1 + sizeof *symlink))
    xalloc_die ();
  symlink = ximalloc (symlinksize);
  buffer = (char *)(symlink + 1);
  ret = readlinkat (dirfd, name, buffer, st.st_size);
  if (ret <= 0)
    goto fail;
  buffer[ret] = 0;
  symlink->path = buffer;
  if (ISSLASH (*buffer))
    {
      char *end;

      if (cwd_stat_errno == -1)
	{
	  cwd_stat_errno = stat (".", &cwd_stat) == 0 ? 0 : errno;
	  if (cwd_stat_errno)
	    goto fail_exdev;
	}
      end = buffer + ret;
      for (;;)
	{
	  char slash;
	  int rv;

	  slash = *end; *end = 0;
	  rv = stat (symlink->path, &st);
	  *end = slash;

	  if (rv == 0
	      && st.st_dev == cwd_stat.st_dev
	      && st.st_ino == cwd_stat.st_ino)
	    {
	      while (ISSLASH (*end))
		end++;
	      symlink->path = end;
	      return symlink;
	    }
	  end--;
	  if (end == symlink->path)
	    break;
	  while (end != symlink->path + 1 && ! ISSLASH (*end))
	    end--;
	  while (end != symlink->path + 1 && ISSLASH (*(end - 1)))
	    end--;
	}
      goto fail_exdev;
    }
  return symlink;

fail_exdev:
  errno = EXDEV;
fail:
  free (symlink);
  return nullptr;
}

/* Resolve the next path component in PATH inside DIR.  If it is a symlink,
   read it and returned it in TOP. */
static struct cached_dirfd *
traverse_next (struct cached_dirfd *dir, char **path, int keepfd,
	       struct symlink **symlink)
{
  char *p = *path;
  struct cached_dirfd *entry = dir;

  while (*p && ! ISSLASH (*p))
    p++;
  if (**path == '.' && *path + 1 == p)
    ;
  else if (**path == '.' && *(*path + 1) == '.' && *path + 2 == p)
    {
      entry = dir->parent;
      if (! entry)
	{
	  /* Must not leave the working tree. */
	  errno = EXDEV;
	}
      else
	{
	  assert (list_empty (&dir->lru_link));
	  list_add (&dir->lru_link, &lru_list);
	}
    }
  else
    {
      char slash_or_nul = *p;
      *p = '\0';
      entry = openat_cached (dir, *path, keepfd);
      if (! entry)
	{
	  if (errno == ELOOP
	      || errno == EMLINK  /* FreeBSD 10.1: Too many links */
	      || (errno == EFTYPE
		  /* NetBSD 6.1: Inappropriate file type or format.  */)
	      || errno == ENOTDIR)
	    {
	      *symlink = read_symlink (dir->fd, *path);
	      if (*symlink)
		entry = dir;
	      errno = ELOOP;
	    }
	}
      *p = slash_or_nul;
    }
  if (entry)
    while (ISSLASH (*p))
      p++;
  *path = p;
  return entry;
}

/* Traverse PATHNAME.

   If REJECT_NL, fail if the PATHNAME's last component contains a newline.
   Otherwise, if unsafe or PATHNAME is absolute, just return AT_FDCWD.
   Otherwise, update PATHNAME to point to the last path component and
   return a file descriptor to its parent directory (which can be AT_FDCWD).
   If KEEPFD is nonnegative, make sure that any cache entry for it is not
   removed from the cache (and KEEPFD remains open).

   When this function is not running, all cache entries are on the lru list,
   and all cache entries which still have a parent are also in the hash table.
   While this function is running, all cache entries on the path being looked
   up are off the lru list but in the hash table.
    */
static int
traverse_another_path (char **pathname, bool reject_nl, int keepfd)
{
  char *path = *pathname;
  char *last = last_component (path);
  if (reject_nl && strchr (last, '\n'))
    {
      errno = EILSEQ;
      return DIRFD_INVALID;
    }
  if (unsafe || last == path || IS_ABSOLUTE_FILE_NAME (path))
    return AT_FDCWD;

  static struct cached_dirfd cwd = {
    .fd = AT_FDCWD,
  };

  intmax_t misses = dirfd_cache_misses;
  struct cached_dirfd *dir = &cwd;
  struct symlink *stack = nullptr;
  idx_t steps = count_path_components (path);
  struct cached_dirfd *traversed_symlink = nullptr;

  INIT_LIST_HEAD (&cwd.children);

  if (steps > MAX_PATH_COMPONENTS)
    {
      errno = ELOOP;
      return DIRFD_INVALID;
    }

  if (debug & 32)
    {
      idx_t full_pathlen = last - path;
      int pathlen = ckd_sub (&pathlen, full_pathlen, 0) ? -1 : pathlen;
      Fprintf (stdout, "Resolving path \"%.*s\"", pathlen, path);
    }

  while (stack || path != last)
    {
      struct cached_dirfd *entry;
      struct symlink *symlink = nullptr;
      char *prev = path;

      entry = traverse_next (dir, stack ? &stack->path : &path, keepfd, &symlink);
      if (! entry)
	{
	  if (debug & 32)
	    {
	      Fputs (" (failed)\n", stdout);
	      Fflush (stdout);
	    }
	  goto fail;
	}
      dir = entry;
      if (! stack && symlink)
	{
	  const char *p = prev;
	  while (*p && ! ISSLASH (*p))
	    p++;
	  char *name = ximemdup0 (prev, p - prev);
	  traversed_symlink = new_cached_dirfd (dir, name, DIRFD_INVALID);
	}
      if (stack && ! *stack->path)
	pop_symlink (&stack);
      if (symlink && *symlink->path)
	{
	  push_symlink (&stack, symlink);
	  steps += count_path_components (symlink->path);
	  if (steps > MAX_PATH_COMPONENTS)
	    {
	      errno = ELOOP;
	      goto fail;
	    }
	}
      else if (symlink)
	pop_symlink (&symlink);
      if (traversed_symlink && ! stack)
	{
	  traversed_symlink->fd =
	    entry->fd == AT_FDCWD ? AT_FDCWD : dup (entry->fd);
	  if (traversed_symlink->fd < 0)
	    free_cached_dirfd (traversed_symlink);
	  else
	    {
	      insert_cached_dirfd (traversed_symlink, keepfd);
	      list_add (&traversed_symlink->lru_link, &lru_list);
	    }
	  traversed_symlink = nullptr;
	}
    }
  *pathname = last;
  if (debug & 32)
    {
      misses = dirfd_cache_misses - misses;
      if (! misses)
	Fprintf (stdout, " (cached)\n");
      else
	Fprintf (stdout, " (%jd miss%s)\n", misses, misses == 1 ? "" : "es");
      Fflush (stdout);
    }
  return put_path (dir);

fail:
  if (traversed_symlink)
    free_cached_dirfd (traversed_symlink);
  put_path (dir);
  while (stack)
    pop_symlink (&stack);
  return DIRFD_INVALID;
}

/* Just traverse PATHNAME; see traverse_another_path(). */
static int
traverse_path (char **pathname, bool reject_nl)
{
  return traverse_another_path (pathname, reject_nl, DIRFD_INVALID);
}

static int
safe_xstat (char *pathname, struct stat *buf, int flags)
{
  int dirfd = traverse_path (&pathname, false);
  if (dirfd == DIRFD_INVALID)
    return -1;
  return fstatat (dirfd, pathname, buf, flags);
}

/* Replacement for stat() */
int
safe_stat (char *pathname, struct stat *buf)
{
  return safe_xstat (pathname, buf, 0);
}

/* Replacement for lstat() */
int
safe_lstat (char *pathname, struct stat *buf)
{
  return safe_xstat (pathname, buf, AT_SYMLINK_NOFOLLOW);
}

/* Replacement for open() */
int
safe_open (char *pathname, int flags, mode_t mode)
{
  int creat_excl = flags & (O_CREAT | O_EXCL);
  int dirfd = traverse_path (&pathname, creat_excl == (O_CREAT | O_EXCL));
  if (dirfd == DIRFD_INVALID)
    return -1;

  /* If O_CREAT is set but O_EXCL is not, traverse_path does not
     suffice for checking file names with '\n', so check by hand.  */
  if (creat_excl == O_CREAT
      && strchr (last_component (pathname), '\n')
      && faccessat (dirfd, pathname, F_OK, AT_EACCESS) < 0
      && errno == ENOENT)
    {
      errno = EILSEQ;
      return -1;
    }

  return openat (dirfd, pathname, flags, mode);
}

/* Replacement for rename() */
int
safe_rename (char *oldpath, char *newpath)
{
  int olddirfd = traverse_path (&oldpath, false);
  if (olddirfd == DIRFD_INVALID)
    return -1;

  int newdirfd = traverse_another_path (&newpath, true, olddirfd);
  if (newdirfd == DIRFD_INVALID)
    return -1;

  int ret = renameat (olddirfd, oldpath, newdirfd, newpath);
  if (! ret)
    {
      invalidate_cached_dirfd (olddirfd, oldpath);
      invalidate_cached_dirfd (newdirfd, newpath);
    }
  return ret;
}

/* Replacement for mkdir() */
int
safe_mkdir (char *pathname, mode_t mode)
{
  int dirfd = traverse_path (&pathname, true);
  if (dirfd == DIRFD_INVALID)
    return -1;
  return mkdirat (dirfd, pathname, mode);
}

/* Replacement for rmdir() */
int
safe_rmdir (char *pathname)
{
  int dirfd = traverse_path (&pathname, false);
  if (dirfd == DIRFD_INVALID)
    return -1;

  int ret = unlinkat (dirfd, pathname, AT_REMOVEDIR);
  if (! ret)
    invalidate_cached_dirfd (dirfd, pathname);
  return ret;
}

/* Replacement for unlink() */
int
safe_unlink (char *pathname)
{
  int dirfd = traverse_path (&pathname, false);
  if (dirfd == DIRFD_INVALID)
    return -1;
  return unlinkat (dirfd, pathname, 0);
}

/* Replacement for symlink() */
int
safe_symlink (char const *target, char *linkpath)
{
  int dirfd = traverse_path (&linkpath, true);
  if (dirfd == DIRFD_INVALID)
    return -1;
  return symlinkat (target, dirfd, linkpath);
}

/* Replacement for chmod() */
int
safe_chmod (char *pathname, mode_t mode)
{
  int dirfd = traverse_path (&pathname, false);
  if (dirfd == DIRFD_INVALID)
    return -1;
  return fchmodat (dirfd, pathname, mode, 0);
}

/* Replacement for lchown() */
int
safe_lchown (char *pathname, uid_t owner, gid_t group)
{
  int dirfd = traverse_path (&pathname, false);
  if (dirfd == DIRFD_INVALID)
    return -1;
  return fchownat (dirfd, pathname, owner, group, AT_SYMLINK_NOFOLLOW);
}

/* Replacement for lutimens() */
int
safe_lutimens (char *pathname, struct timespec const times[2])
{
  int dirfd = traverse_path (&pathname, false);
  if (dirfd == DIRFD_INVALID)
    return -1;
  return utimensat (dirfd, pathname, times, AT_SYMLINK_NOFOLLOW);
}

/* Replacement for readlink() */
ssize_t
safe_readlink (char *pathname, char *buf, size_t bufsiz)
{
  int dirfd = traverse_path (&pathname, false);
  if (dirfd == DIRFD_INVALID)
    return -1;
  return readlinkat (dirfd, pathname, buf, bufsiz);
}

/* Replacement for access() */
int
safe_access (char *pathname, int mode)
{
  int dirfd = traverse_path (&pathname, false);
  if (dirfd == DIRFD_INVALID)
    return -1;
  return faccessat (dirfd, pathname, mode, AT_EACCESS);
}
