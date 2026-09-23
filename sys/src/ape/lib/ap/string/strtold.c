/*
 * strtold -- long double is double here, so this is strtod.
 *
 * kencc has no extended precision: `sub.c's simplet() maps
 * BDOUBLE|BLONG to types[TDOUBLE]', so `long double' IS `double' on
 * every architecture this tree builds for. That is recorded in
 * CLAUDE.md as a compiler fact and is what perl's config.h had to be
 * corrected to say.
 *
 * WHAT WAS HERE BEFORE was a third copy of the old APE parser -- the
 * same 100 lines as strtod.c and strtof.c, with the same bug in each.
 * It accumulated digits in a double and multiplied by pow10(exp), two
 * roundings and neither of them the one the standard asks for;
 * sys/lib/tests/strtod-xcheck.c measured the strtod copy at 148018 of
 * 199887 round-trips wrong. Forwarding to the one correct parser is
 * not a shortcut: on this platform it is what the function MEANS, and
 * three copies of a parser is three places for the next bug to live.
 *
 * If a target ever arrives with real 80-bit long double, this stays
 * correct and stops being maximally precise, and the compiler note
 * above is where to start.
 */

#include <stdlib.h>

long double
strtold(const char *cp, char **endptr)
{
	return strtod(cp, endptr);
}
