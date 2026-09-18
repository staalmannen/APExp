/*
	local limits
*/

#undef	ARG_MAX
#define	ARG_MAX		65536
#undef	CHILD_MAX
#define	CHILD_MAX	128
#undef	OPEN_MAX
#define	OPEN_MAX	256
#undef	LINK_MAX
#define	LINK_MAX	1
/*
 * NAME_MAX AND PATH_MAX ARE SET HERE, AND THIS FILE WINS.
 *
 * `limits_generic.h` (the content of <limits.h>) ends with
 * `#include <sys/limits.h>`, so every `#undef`/`#define` pair in this
 * file overrides what it just set, three lines further down the same
 * translation unit. Editing the values there and reading the result
 * measured nothing: `deeppath-test` printed 1023 and 27 from a build
 * whose limits.h said 4096 and 255, and the header marker in it said
 * `<limits.h> came from THIS TREE` -- which is how the override was
 * found, by the marker answering the question truthfully and the
 * numbers still disagreeing.
 *
 * 27 was the old Plan 9 directory-entry name length and is simply wrong
 * now: <dirent.h> gives `struct dirent` a `d_name[MAXNAMLEN+1]` with
 * MAXNAMLEN 255, so libap has always returned names this said were
 * impossible.
 *
 * 1023 is a real wall rather than a wrong number. musl's `realpath()`
 * declares `char stack[PATH_MAX+1]`, and Tcl's normalizer and directory
 * walker each declare `char buf[MAXPATHLEN]`. Plan 9 has no inherent
 * path limit -- 9P walks one element at a time and never carries a
 * whole path -- so 4096, Linux's value, is what portable code is tested
 * against.
 *
 * The rule: when a constant is wrong, grep for EVERY definition of it.
 * This one had two, in files that include each other.
 */
#undef	NAME_MAX
#define	NAME_MAX	255
#undef	PATH_MAX
#define	PATH_MAX	4096
#undef	MAXPATHLEN
#define	MAXPATHLEN	PATH_MAX
#undef	NGROUPS_MAX
#define	NGROUPS_MAX	32
#undef	MAX_CANON
#define	MAX_CANON	1023
#undef	MAX_INPUT
#define	MAX_INPUT	1023
#undef	PIPE_BUF
#define	PIPE_BUF	8192

#define	_POSIX_SAVED_IDS		1
#define	_POSIX_CHOWN_RESTRICTED		1
#define	_POSIX_NO_TRUNC			1
