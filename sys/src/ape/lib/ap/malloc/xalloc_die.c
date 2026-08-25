/*
 * xalloc_die lives alone in this file on purpose.
 *
 * gnulib documents xalloc_die as replaceable: a program that wants its
 * own diagnostic, or wants to clean up before exiting, defines its own.
 * GNU patch is one -- src/util.c has a version that reports the program
 * name and the file being patched.
 *
 * A replaceable definition has to be the only thing in its object file.
 * While it sat in xmalloc.c, any program that both defined its own
 * xalloc_die and called any other member of the family dragged in the
 * whole object, and the linker saw the symbol twice:
 *
 *   xalloc_die: /amd64/lib/ape/libap.a(xmemdup): redefinition: xalloc_die
 *
 * Note the name in parentheses is the symbol the linker was resolving,
 * not the archive member -- 6l builds that string with the symbol name
 * (obj.c, "snprint(pname, ..., \"%s(%s)\", file, s->name)"). So the
 * message names xmemdup, while the member it pulled in was xmalloc.
 *
 * Alone here, the object is pulled in only when nothing else has
 * defined xalloc_die, which is exactly the intended behaviour. gnulib
 * keeps it in its own module, xalloc-die.c, for the same reason.
 */

#include <stdlib.h>
#include <stdio.h>
#include <xalloc.h>

void
xalloc_die(void)
{
	fputs("memory exhausted\n", stderr);
	exit(1);
}
