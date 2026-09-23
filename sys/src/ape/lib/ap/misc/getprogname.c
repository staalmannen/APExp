#include "/sys/include/ape/lib9.h"
/*
 * <string.h> is REQUIRED, not tidiness: lib9.h does not declare
 * strrchr, and in this tree a call with no prototype in scope has its
 * return value truncated to 32 bits -- a pointer that comes back half
 * right. It is the first invariant in CLAUDE.md and it has bitten
 * _callmain itself, two files away from here.
 */
#include <string.h>

/*
 * getprogname -- the short name of this program.
 *
 * WHAT IT USED TO BE, and why that was empty for everything:
 *
 *	const char *getprogname(void) { return argv0; }
 *
 * argv0 is lib9's global, and lib9 fills it from ARGBEGIN -- a Plan 9
 * idiom that no APE program executes. Nothing else set it either, so
 * it was NULL unless the program happened to call getopt_long. It is
 * now set in plan9/callmain.c, which every APE program passes through;
 * see the note there.
 *
 * THIS IS NOT COSMETIC. gnulib's error() is literally
 * `#define program_name getprogname ()' (gnulib/error.c:128), so every
 * GNU program in this tree -- tar, sed, awk, grep, m4, gettext -- was
 * printing its diagnostics with no name at all:
 *
 *	: This does not look like a tar archive
 *
 * where the same tar on any other system says "tar: ...". A message
 * that does not say which program produced it is most of the way to
 * useless in a pipeline, and a build log full of them cannot be read.
 *
 * THE BASENAME IS THE POINT, not a tidy-up. Every implementation this
 * is modelled on returns the last component -- BSD's, Solaris's
 * getexecname()+last_component, glibc's program_invocation_short_name,
 * and gnulib's own fallback in getprogname.c, which calls
 * last_component() in four of its five arms. Returning the full path
 * would make tar say "/bin/tar:" where the world says "tar:", and
 * tests that match diagnostics would fail on the difference.
 *
 * NEVER NULL. gnulib's fallback answers "?" when it cannot find a name
 * and the callers print it with %s; returning NULL here would leave
 * every one of them one printf away from a fault, for the sake of a
 * distinction none of them makes.
 */
const char *
getprogname(void)
{
	const char *p, *s;

	p = argv0;
	if(p == 0 || *p == '\0')
		return "?";
	s = strrchr(p, '/');
	if(s != 0 && s[1] != '\0')
		return s + 1;
	return p;
}
