#include <sys/types.h>
#include <grp.h>
#include <errno.h>

/*
 * Plan 9 has no supplementary group list, so there is nothing to
 * initialise. Fails with EPERM, as setgroups() in this directory does:
 * callers that drop privileges test for exactly that and carry on.
 * GNU tar's lib/rtapelib.c is one --
 *
 *   if (initgroups (pw->pw_name, gid) != 0 && errno != EPERM)
 *     return "initgroups";
 *
 * -- so reporting the truth is better here than pretending success.
 */
int
initgroups(const char *user, gid_t group)
{
	(void)user; (void)group;
	errno = EPERM;
	return -1;
}
