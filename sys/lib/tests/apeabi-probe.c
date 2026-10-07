/*
 * apeabi-probe -- which APE structs does `-J' MOVE?
 *
 * TWO COMPILES AND A DIFF, on the VM:
 *
 *   pcc -c    -a apeabi-probe.c > /tmp/abi-old.acid
 *   pcc -c -J -a apeabi-probe.c > /tmp/abi-new.acid
 *   diff /tmp/abi-old.acid /tmp/abi-new.acid
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
