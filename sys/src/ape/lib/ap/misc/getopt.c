#include	<stdlib.h>
#include	<string.h>
#include	<stdio.h>
#define ERR(str, chr)       if(opterr){fprintf(stderr, "%s%s%c\n", argv[0], str, chr);}
int     opterr = 1;
int     optind = 1;
int	optopt;
char    *optarg;

/*
 * POSIX: int getopt(int, char * const [], const char *).
 *
 * This definition was `(int, char **, char *)', which agreed with
 * <bsd.h> and disagreed with <getopt.h>, where the same function was
 * already declared correctly. TWO declarations of one name that do
 * not match, in two installed headers -- the `Lock' and `PATH_MAX'
 * shape, and the together-case of `apehdr-sweep' is what reported it.
 *
 * Callers are unaffected: `char **' converts to `char * const *'
 * because the const is at the FIRST level of the pointed-to type
 * (C11 6.5.16.1), which is why every program on every system passes
 * main's `argv' to glibc's identically-declared getopt. The body
 * never writes through argv -- `&argv[i][j]' through `char * const'
 * is still a `char *', which is what `optarg' wants.
 */
int
getopt(int argc, char * const argv[], const char *opts)
{
	static int sp = 1;
	register c;
	register char *cp;

	if (sp == 1)
		if (optind >= argc ||
		   argv[optind][0] != '-' || argv[optind][1] == '\0')
			return EOF;
		else if (strcmp(argv[optind], "--") == 0) {
			optind++;
			return EOF;
		}
	optopt = c = argv[optind][sp];
	if (c == ':' || (cp=strchr(opts, c)) == NULL) {
		ERR (": illegal option -- ", c);
		if (argv[optind][++sp] == '\0') {
			optind++;
			sp = 1;
		}
		return '?';
	}
	if (*++cp == ':') {
		if (argv[optind][sp+1] != '\0')
			optarg = &argv[optind++][sp+1];
		else if (++optind >= argc) {
			ERR (": option requires an argument -- ", c);
			sp = 1;
			return '?';
		} else
			optarg = argv[optind++];
		sp = 1;
	} else {
		if (argv[optind][++sp] == '\0') {
			sp = 1;
			optind++;
		}
		optarg = NULL;
	}
	return c;
}
