#include "lib.h"
#include "sys9.h"
#include <stdlib.h>
/*
 * For memset's prototype below, and it is not optional.
 *
 * kencc's sizeof yields TULONG, which is 32-bit on amd64 (see the note
 * in cc/com.c's OSIZE case). It widens to a 64-bit size_t at the call
 * site only "when the prototype is visible". Without <string.h> here,
 * memset had no prototype, so sizeof(privates) was written into the
 * argument slot as four bytes while memset -- compiled against a real
 * size_t -- read eight:
 *
 *	memset(c=0xfefefefe00000000, n=0xfefefefe00000080)
 *
 * 0x80 is the 128 that was meant; 0xfefefefe is whatever the stack held
 * above it. memset then ran until it reached the guard page:
 *
 *	mkbuiltins: suicide: sys: trap: fault write addr=0x7ffffffff000
 *
 * Every APE program starts through _callmain, so this was latent in all
 * of them and fired only when that garbage happened to be nonzero --
 * which is why it showed up on a fresh 9front and not on a machine that
 * had been building for a while, and why the programs that hit it
 * (mkbuiltins, objc, cfront) are the ones the build invokes with very
 * long command lines. argv and the environment sit at the top of the
 * stack, so their size decides what lands in that slot.
 */
#include <string.h>

/*
 * The definition lives here rather than in misc/getopt_long.c, where it
 * used to, for a linking reason: _callmain is in every APE binary and
 * getopt_long is not, so a program that never parsed an option would
 * not have pulled the object in at all.
 */
char *argv0 = NULL;

extern	void _envsetup(void);
extern	char **environ;
extern	int *_errnoloc;

void **_privates;
int _nprivates;
char *_plan9err;

enum{
	NPRIVATES=16,
};

#pragma profile off

void
_callmain(int (*f)(int, char**), int argc, char *arg0)
{
	int errno;
	char err[ERRMAX];
	void *privates[NPRIVATES];

	memset(privates, 0, sizeof(privates));
	err[0] = '\0';
	_privates = privates;
	_nprivates = NPRIVATES;
	_errnoloc = &errno;
	_plan9err = &err[0];

	/*
	 * argv0 is set HERE because this is the only place that always
	 * runs. It is lib9's global, and lib9 fills it from ARGBEGIN --
	 * an rc-and-Plan-9 idiom no APE program ever executes, so for
	 * every program in this tree it stayed as getopt_long.c left it:
	 * NULL, or argv[0] only if the program happened to call
	 * getopt_long.
	 *
	 * That is what getprogname() returns, and gnulib's error() IS
	 * getprogname() (gnulib/error.c:128), so every GNU program built
	 * here printed its diagnostics with an EMPTY program name:
	 *
	 *	: This does not look like a tar archive
	 *
	 * where GNU tar on any other system says "tar:". One assignment,
	 * and it covers every caller rather than each program setting its
	 * own.
	 */
	argv0 = arg0;

	exit(f(argc, &arg0));
}

int
_apemain(int argc, char **argv)
{
	_envsetup();
	extern int main(int, char**, char**);
	return main(argc, argv, environ);
}

#pragma profile on
