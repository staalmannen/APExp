/*
 * apeabi-probe -- which APE structs does `-J' MOVE?
 *
 * TWO COMPILES AND A DIFF, on the VM:
 *
 *   pcc -c -9 -a apeabi-probe.c > /tmp/abi-old.acid
 *   pcc -c    -a apeabi-probe.c > /tmp/abi-new.acid
 *   diff /tmp/abi-old.acid /tmp/abi-new.acid
 *
 * **AND THERE ARE TWO AXES NOW, which the one command above does not
 * distinguish.** The `-J'/`-9' pair below is the layout RULE that is
 * already in the tree. The open question is the bit-field allocation
 * change, and its two sides are two different COMPILERS -- HEAD's
 * `pcc' and a patched one -- with the same flags:
 *
 *   # before the sualign patch
 *   pcc -c -a apeabi-probe.c > /tmp/abi-bf-before.acid
 *   # after rebuilding sys/src/cmd
 *   pcc -c -a apeabi-probe.c > /tmp/abi-bf-after.acid
 *   diff /tmp/abi-bf-before.acid /tmp/abi-bf-after.acid
 *
 * The `before' side has to be taken FIRST and kept, because once the
 * compiler is rebuilt there is no flag that asks for the old
 * allocation -- `-9' is the old TAIL-PADDING rule and the bit-field
 * line was never gated on `conformalign' at all. *An irreversible
 * change takes its own baseline with it*, which is the reason `-9'
 * exists and the same reason this file gives for it below.
 *
 * **Conforming layout is the DEFAULT now, so the flags have swapped
 * round**: plain `pcc' conforms and `-9' asks for the 9front rule.
 * The answer this probe gave when it was first run is recorded in
 * CLAUDE.md -- sixteen structs, the socket family and the lock family
 * and `termios', with nothing in the stdio/stat core moving -- and
 * that diff is what the default was turned on against.
 *
 * `-c' is not optional: with `-a' the compiler writes acid to stdout
 * and never produces the object, so without it pcc goes on to link an
 * object that does not exist. And `-a' itself only reaches the
 * compiler on a pcc that names the letter -- the first attempt at
 * this answered **`cc: flag -a ignored`** and quietly compiled
 * normally, because pcc's ARGBEGIN listed neither `a' nor `Z'. On an
 * older pcc, `pcc -c -W0,-a' passes it through by hand.
 *
 * `-a' makes the compiler emit acid definitions, which carry each
 * struct's SIZE and every member's OFFSET -- it is what `mkone's
 * `%.acid' rule uses. So the diff is a complete list, from the
 * compiler itself, of everything whose layout `-J' changes inside the
 * APE world. **An empty diff would mean -J is free; a long one is the
 * cost, named struct by struct, before a single object is rebuilt.**
 *
 * ------------------------------------------------------------------
 * WHY THIS HAS TO BE MEASURED BEFORE THE TREE-WIDE BUILD.
 *
 * `-J' is all-or-nothing for a linked world: it moves `FILE',
 * `struct stat' and `DIR' as readily as anything else, and a package
 * built with it against a libap built without it disagrees about them
 * **silently, with no link error, because every symbol still
 * resolves**. The failure arrives as a wrong field, later, somewhere
 * else.
 *
 * AND THE FIRST ATTEMPT AT THE `old' SIDE OF THIS DIFF WOULD HAVE
 * MEASURED NOTHING, which is worth more than the diff. `pcc' used to
 * append `-J' to the compiler UNCONDITIONALLY (commented `old/new
 * decl mixture hack', a no-op in stock cc because nothing reads
 * debug['J']), so once -J meant conforming layout, the `without'
 * compile had it on too and the diff would have come back EMPTY --
 * reading exactly like a flag that costs nothing. Fixed in pcc.c;
 * **a run of this probe on a pcc predating that fix is void**, and
 * the two files being byte-identical is how it would show.
 *
 * AND THE OBVIOUS WAY TO TURN IT ON DOES NOT WORK. Putting `-J' in
 * `sys/src/ape/config's CFLAGS reaches **32 of 137** mkfiles: the
 * other 105 ASSIGN `CFLAGS=' outright rather than appending
 * `$CFLAGS', and `cmd/cfront/mkfile:52' is one of them. Putting it on
 * `CC' is no better -- 59 mkfiles reassign that too. *The two
 * variables a build system offers for exactly this both have holes,
 * and either one would have produced the silent split rather than a
 * clean change.*
 *
 * So the mechanism has to be `pcc' itself, which every APE compile
 * runs however the mkfile spells `$CC' -- and that is a decision to
 * take with this diff in hand, not before it.
 *
 * ------------------------------------------------------------------
 * WHAT IS INCLUDED AND WHAT IS LEFT OUT.
 *
 * The ABI-bearing headers: the types that cross a library boundary,
 * get embedded in another struct, or are written to disk. Headers
 * that only declare functions add nothing to an acid dump.
 *
 * `<regex.h>' is here and `<pcre2posix.h>' is NOT, deliberately: they
 * define `regex_t' and `regmatch_t' as ALTERNATIVES and no program
 * includes both, which `apehdr-sweep's together case already records.
 * `<curses.h>' and friends are out because they want `bool' as a
 * keyword and this file has to compile under both compilers.
 *
 * ------------------------------------------------------------------
 * THE BIT-FIELD SECTION, AND WHY IT HAD TO BE ADDED BEFORE THE PROBE
 * COULD PRICE THE CHANGE IT WAS BEING REACHED FOR.
 *
 * The open kencc question is no longer `-J' -- it is the ONE
 * non-conformance `-J' deliberately did not fix: kencc allocates a
 * bit field in a whole `tfield' unit and does NOT let a following
 * ordinary member share the container's tail, which is MSVC's rule
 * (measured on the VM: `struct{unsigned x:1; char c;}' gives `c' at
 * 4 and sizeof 8, against gcc's 1 and 4). EDG's generated C is sized
 * for the shared-container rule in 958 places, which is what makes
 * that gap worth closing.
 *
 * **The thirty-one headers above contain NOT ONE BIT FIELD.** So the
 * acid diff for that change -- which is HEAD's `pcc' against a
 * patched one, a different axis from `-J' against `-9' -- would have
 * come back EMPTY, and an empty diff here reads exactly like a change
 * that costs nothing. *That is the void-measurement shape this file's
 * own header already records for a `pcc' that appended `-J' to both
 * sides.* An instrument has to include the thing it is measuring.
 *
 * FOUR PUBLIC APE HEADERS CONTAIN A BIT FIELD AT ALL, swept rather
 * than recalled, and only TWO of them move -- because the rule only
 * bites when the member AFTER the group is small enough to sit in the
 * container's tail at its OWN alignment:
 *
 *   resolv.h    `unsigned ndots:4, nsort:4;' then
 *               `unsigned char unused[3];'   -- 3 free bytes, a char
 *               array needs 1-byte alignment: MOVES, and everything
 *               after it (`sort_list') with it. *Written expecting
 *               the shared container* -- it is glibc's own layout.
 *   curl.h      `unsigned int includeSubDomains:1;' then
 *               `char expire[18];'           -- MOVES, same shape.
 *   fenv_arch.h `__opcode:11; __unused4:5;' then
 *               `unsigned int __data_offset;' -- does NOT move: an
 *               `int' wants 4-byte alignment and only 2 bytes of the
 *               container remain, so gcc puts it at the next unit too.
 *   obstack.h   three 1-bit fields are the LAST members, nothing
 *               follows, and the struct's alignment is a pointer's
 *               8 either way -- does NOT move.
 *
 * `iostream.h' matched a looser grep and is a FALSE HIT; it is named
 * here so the next sweep does not re-find it.
 *
 * **And the public headers are a LOWER BOUND, which is the honest
 * limit of this probe.** The change reaches every APE compile, so any
 * struct in libap's own sources or in any package under `external/'
 * with a bit-field group followed by a small member moves too, and no
 * acid dump of this translation unit can see those. What it does give
 * is the public surface -- the part that crosses a library boundary
 * and so fails SILENTLY -- named struct by struct.
 *
 * `<curl/curl.h>' is behind `-DAPEABI_CURL' rather than included
 * outright: curl is an OPTIONAL app, its header is not core APE, and
 * a probe that fails to compile measures nothing at all. Take it with
 * the flag when curl is installed.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <setjmp.h>
#include <signal.h>
#include <time.h>
#include <errno.h>
#include <locale.h>
#include <limits.h>
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>
#include <pwd.h>
#include <grp.h>
#include <utime.h>
#include <wchar.h>
#include <wctype.h>
#include <regex.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/times.h>
#include <sys/wait.h>
#include <sys/resource.h>
#include <sys/utsname.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <termios.h>
#include <pthread.h>

/* the four bit-field headers; see the header note above */
#include <fenv.h>
#include <obstack.h>
#include <resolv.h>
#ifdef APEABI_CURL
#include <curl/curl.h>
#endif

/*
 * The acid dump only describes types the translation unit actually
 * USES, so each one is named by an object. A pointer would not do it:
 * the compiler emits a definition for a struct it has laid out, and
 * laying it out is what declaring an instance forces.
 */
struct stat		_abi_stat;
struct dirent		_abi_dirent;
struct tm		_abi_tm;
struct timeval		_abi_timeval;
struct timespec		_abi_timespec;
struct tms		_abi_tms;
struct rusage		_abi_rusage;
struct utsname		_abi_utsname;
struct passwd		_abi_passwd;
struct group		_abi_group;
struct utimbuf		_abi_utimbuf;
struct sockaddr		_abi_sockaddr;
struct sockaddr_in	_abi_sockaddr_in;
struct sockaddr_in6	_abi_sockaddr_in6;
struct in_addr		_abi_in_addr;
struct in6_addr		_abi_in6_addr;
struct ip_mreq		_abi_ip_mreq;
struct hostent		_abi_hostent;
struct servent		_abi_servent;
struct protoent		_abi_protoent;
struct addrinfo		_abi_addrinfo;
struct termios		_abi_termios;
struct sigaction	_abi_sigaction;
struct lconv		_abi_lconv;
struct div_t_holder	{ div_t d; ldiv_t l; lldiv_t ll; };
struct div_t_holder	_abi_divs;
FILE			*_abi_filep;
FILE			_abi_file;
DIR			*_abi_dirp;
jmp_buf			_abi_jmpbuf;
sigjmp_buf		_abi_sigjmpbuf;
fd_set			_abi_fdset;
regex_t			_abi_regex;
regmatch_t		_abi_regmatch;
mbstate_t		_abi_mbstate;
pthread_t		_abi_pthread;
pthread_attr_t		_abi_pthread_attr;
pthread_mutex_t		_abi_pthread_mutex;
pthread_cond_t		_abi_pthread_cond;
pthread_rwlock_t	_abi_pthread_rwlock;
sigset_t		_abi_sigset;

/* the bit-field bearers */
fenv_t			_abi_fenv;
struct obstack		_abi_obstack;
struct __res_state	_abi_res_state;
#ifdef APEABI_CURL
struct curl_hstsentry	_abi_hstsentry;
#endif

/*
 * A CONTROL OF THE RULE, not of the headers -- the four shapes the
 * question turns on, so one acid dump says which allocation rule the
 * compiler in front of it follows even if a header above is absent or
 * has changed. These are deliberately NOT a second copy of any
 * header's struct: each isolates one case.
 *
 *   `_abi_bf_shares'   8 bits then a char array that FITS the tail.
 *                      kencc today: `c' at 4, sizeof 8.
 *                      gcc/EDG:     `c' at 1, sizeof 4.
 *                      This is `resolv.h's shape and the one that
 *                      decides the change.
 *   `_abi_bf_aligned'  16 bits then an `int', which cannot share a
 *                      4-byte container at its own alignment.
 *                      BOTH rules answer 4 and 8 -- `fenv_arch.h's
 *                      shape, and it must NOT move. *A section that
 *                      stays still is what separates the rule from a
 *                      compiler that merely stopped padding.*
 *   `_abi_bf_trailing' a group with nothing after it -- `obstack.h's
 *                      shape; must not move either.
 *   `_abi_bf_split'    two groups of different base types, which is
 *                      where a container is CLOSED for a reason other
 *                      than an ordinary member following it.
 *
 * MEASURED ON gcc, so the reference is a number and not a claim --
 * `offsetof(c)' / `sizeof' for the four in order:
 *
 *   shares    1 / 4      aligned   4 / 8
 *   trailing      16     split     1 / 4
 *
 * `split' answering 1 is worth noticing: gcc shares the container
 * ACROSS base types, so a `short' group after an `unsigned' one is
 * not a boundary. That is reported rather than asserted -- it is a
 * third rule, distinct from both of the two in frame, and nothing
 * here depends on which way kencc answers it.
 *
 * Predicted for HEAD's `pcc', written down before the run: `shares'
 * 4/8, `aligned' 4/8, `trailing' 16, `split' unknown. So `aligned'
 * and `trailing' must be IDENTICAL in the two acid dumps and
 * `shares' must move; a diff in which `aligned' also moved would mean
 * the patch changed more than the sharing rule.
 */
struct _abi_bf_shares   { unsigned a:4, b:4; unsigned char c[3]; };
struct _abi_bf_aligned  { unsigned a:11, b:5; unsigned int c; };
struct _abi_bf_trailing { void *p; unsigned a:1, b:1, c:1; };
struct _abi_bf_split    { unsigned a:3; unsigned short b:3; char c; };

struct _abi_bf_shares   _abi_bf_shares;
struct _abi_bf_aligned  _abi_bf_aligned;
struct _abi_bf_trailing _abi_bf_trailing;
struct _abi_bf_split    _abi_bf_split;

int
main(void)
{
	/*
	 * Nothing is printed. The whole output is the acid dump that
	 * `-a' writes to stdout, so this program is never run -- only
	 * compiled, twice.
	 */
	return 0;
}
