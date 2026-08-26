/*
 * apexp-mountlist.c -- read_file_system_list for Plan 9.
 *
 * gnulib's mountlist.c ends in
 *
 *   #error "Please port gnulib mountlist.c to your platform!"
 *
 * after a chain of arms for getmntent, getmntinfo, /etc/mnttab, the AIX
 * and OSF/1 mount() calls, and half a dozen others. None describes
 * Plan 9, which has no global mount table at all: what a process sees is
 * its own namespace, built from bind and mount operations and readable
 * as text from /proc/$pid/ns. Nothing there maps onto struct
 * mount_entry's device-node-and-fs-type shape without inventing values.
 *
 * So this reports "no list available" rather than a wrong one. That is a
 * documented outcome, not a failure: mountlist.h says read_file_system_list
 * returns "NULL on error", and the one caller in this build handles it.
 * coreutils' stat.c calls it from find_bind_mount, for the %m format,
 * behind a tried-once flag:
 *
 *   if (!tried_mount_list)
 *     if (!(mount_list = read_file_system_list (false)))
 *       ... warn once ...
 *
 * so stat keeps working and only %m goes quiet. df, the other caller,
 * is not among the programs built here.
 *
 * free_mount_entry is a copy of gnulib's, so that a caller which does
 * build a list by other means, or which frees a partially built one,
 * behaves identically. It is unreachable from read_file_system_list
 * here, which never returns a list to free.
 *
 * If a real implementation is wanted later, /proc/$pid/ns is the source,
 * and this file is the place for it.
 */

#include <config.h>

#include "mountlist.h"

#include <stdlib.h>
#include <errno.h>

struct mount_entry *
read_file_system_list (bool need_fs_type)
{
  (void) need_fs_type;
  errno = ENOSYS;
  return NULL;
}

void
free_mount_entry (struct mount_entry *me)
{
  free (me->me_devname);
  free (me->me_mountdir);
  free (me->me_mntroot);
  if (me->me_type_malloced)
    free (me->me_type);
  free (me);
}
