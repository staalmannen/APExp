#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include "lib.h"

/*
 * umask -- it used to DISCARD its argument and always answer 0.
 *
 *	mode_t umask(mode_t) { return 0; }
 *
 * with the comment "No such concept in plan9, but supposed to be always
 * successful". The first half is true of the KERNEL and false of this
 * library, and the second half is not what the call is for.
 *
 * ------------------------------------------------------------------
 * WHAT IT COST, AND HOW IT WAS FOUND.
 *
 * `run-builtins' in bash's own suite: **42 of its 225 differing lines**
 * are the umask block, and every one is the same shape --
 *
 *	< u=rwx,g=rwx,o=rwx          (ours, for every mask ever set)
 *	> u=rx,g=rx,o=rx             (expected)
 *	> u=rwx,g=rwx,o=rx
 *
 * because `umask 022' stored nothing and `umask -S' then read back a
 * mask of 0. *Twenty separate assertions, one missing variable.*
 *
 * ------------------------------------------------------------------
 * WHY STORING IT IS NOT "INVENTING SEMANTICS".
 *
 * That rule exists in this tree and is worth testing a change against.
 * It does not bite here, for a reason specific to where the mask is
 * applied: **libap is the code that chooses the permission it hands
 * `_CREATE'**, at exactly two user-facing sites --
 *
 *	fcntl/open.c    O_CREAT:  _CREATE(path, f, mode&0777)
 *	unistd/mkdir.c:           _CREATE(name, 0, DMDIR|(mode&0777))
 *
 * -- so a creation mask is something this library can honestly
 * implement, the way it already emulates `O_APPEND' with a seek. The
 * other `_CREATE' callers are internal (`/env/_fdinfo', `/env/_sighdlr',
 * `tmpfile', `access''s probe) or copy an existing file's mode
 * (`rename'), and POSIX does not put a umask on any of them.
 *
 * **And it composes with the file server rather than fighting it.**
 * Plan 9 hands out `perm & (dirperm | ~0666)' of its own accord, so the
 * result is the intersection of two masks -- and a umask may only ever
 * REMOVE permission bits, which is precisely its contract. Nothing here
 * can grant a bit the server would have withheld.
 *
 * ------------------------------------------------------------------
 * TWO LIMITS, BOTH DELIBERATE AND BOTH RECORDED RATHER THAN HIDDEN.
 *
 * 1. **The initial mask is 0, not 022.** POSIX leaves the initial value
 *    to the implementation, and 0 is what every program in this tree
 *    has been built and tested against. Starting at 022 would quietly
 *    change the permissions of every file every APE program creates,
 *    for no measured gain. *A conformance fix should not also be a
 *    default change.* So by default **nothing differs**: only a program
 *    that calls `umask()' itself sees any change at all.
 *
 * 2. **It does NOT survive `exec'.** POSIX says the mask is inherited
 *    across both fork and exec. Fork is fine -- Plan 9's fork copies
 *    the address space, so the static comes along. Exec replaces the
 *    image and loses it. Carrying it over would mean another
 *    `/env/' variable beside `_fdinfo' and `_sighdlr', which is the
 *    established idiom here and is a separate, larger change: it adds
 *    state to every exec in the tree. *Recorded as a known gap, not
 *    guessed at and not quietly skipped* -- `umask-test.c' section 4
 *    measures it rather than asserting it, so the next person reads a
 *    number instead of this paragraph.
 */

static mode_t theumask;		/* 0 at start; see limit 1 above */

mode_t
umask(mode_t m)
{
	mode_t old;

	old = theumask;
	theumask = m & 0777;
	return old;
}

/*
 * The creation sites ask for this rather than touching the static, so
 * the mask has one owner. Not static, and not in <sys/stat.h>: it is
 * internal to libap, so it is declared in ap/include/lib.h beside the
 * other `_' helpers.
 */
mode_t
_umaskbits(void)
{
	return theumask;
}

/*
 * Version marker, as `_getcwdmark' and `_printfmark' are for their
 * files. `pcc -o x x.c' relinks against the INSTALLED libap, so a test
 * built from a fresh pull can run days-old library code and report a
 * pass on it; a test that calls this will not LINK against a libap
 * predating the fix.
 */
int
_umaskmark(void)
{
	return 1;
}
