/* Beware - some guesswork in here */
#include <u.h>
#include <libc.h>
#include <ctype.h>
#include <bio.h>
#include "mkmk.h"

/*
 * Global hints are those needed by every file, even if it doesn't
 * include config.h, and thus they are passed on the command line.
 * Local hints are also passed on the command line, unless we are
 * in Autoconf mode, in which case they go into the config.h file.
 */
List *Glbhints = nil;
List *Lochints = nil;

typedef struct {
	char *name;
	char *macro;
} Macdef;

/*
 * any attempt to include these files requires the definition
 * of the given macro name or plan9's APE system will cause
 * a compilation error. This list is complete at the time or writing
 * but will become inaccurate with time.
 */
Macdef Filehints[] = {
	{ "bsd.h",		"_BSD_EXTENSION" },
	{ "netdb.h",		"_BSD_EXTENSION" },
	{ "select.h",		"_BSD_EXTENSION" },
	{ "sys/ioctl.h",	"_BSD_EXTENSION" },
	{ "sys/resource.h",	"_BSD_EXTENSION" },
	{ "sys/time.h",		"_BSD_EXTENSION" },
	{ "sys/select.h",	"_BSD_EXTENSION" },
	{ "sys/socket.h",	"_BSD_EXTENSION" },
	{ "sys/systime.h",	"_BSD_EXTENSION" },
	{ "sys/uio.h",		"_BSD_EXTENSION" },
	{ "regexp.h",		"_REGEXP_EXTENSION" },
	{ "u.h",		"_PLAN9_EXTENSION" },
	{ "cursor.h",		"_PLAN9_EXTENSION" },
	{ "draw.h",		"_PLAN9_EXTENSION" },
	{ "event.h",		"_PLAN9_EXTENSION" },
	{ "fmt.h",		"_PLAN9_EXTENSION" },
	{ "keyboard.h",		"_PLAN9_EXTENSION" },
	{ "lib9.h",		"_PLAN9_EXTENSION" },
	{ "lock.h",		"_PLAN9_EXTENSION" },
	{ "mouse.h",		"_PLAN9_EXTENSION" },
	{ "qlock.h",		"_PLAN9_EXTENSION" },
	{ "ar.h",		"_RESEARCH_SOURCE" },
	{ "libv.h",		"_RESEARCH_SOURCE" },
	{ "libl.h",		"_RESEARCH_SOURCE" },
	{ "error.h",		"_RESEARCH_SOURCE" },
	{ "inttypes.h",		"_SUSV2_SOURCE" },
	{ "fcntl.h",		"_POSIX_SOURCE" },
	{ "grp.h",		"_POSIX_SOURCE" },
	{ "pwd.h",		"_POSIX_SOURCE" },
	{ "unistd.h",		"_POSIX_SOURCE" },
};

/*
 * Arbitary defines that GNU Autoconf wants and we support.
 */
char *Wellknown[] = {
	{ "HAVE_WORKING_FORK" },		// yes our fork does work
	{ "STDC_HEADERS" },			// unistd, stdlib and some friends
	{ "TIME_WITH_SYS_TIME" },		// we have both time.h and sys/time.h
	{ "GETPGRP_VOID" },			// getgrp() returns a void
	{ "HAVE_UTIME_NULL" },			// utime() accepts nil for times
	{ "SELECT_TYPE_ARG234=fd_set" },	// the type of args for select()
	{ "_POSIX_SOURCE" },			// yes, we are POSIX compliant
	{ "HAVE_ANSI_COMPILER" },		// yes, we are ANSI compiliant too

};

static void
addhint(List **lp, char *macro, char *value)
{
	if(looksym(macro, nil) != nil)
		return;
	addlist(lp, macro);
	setsym(macro, value);
}

static char *
looktab(List **lp, char *macro, char **first, char **last)
{
	char **t;

	for(t = first; t < last; t++)
		if(strcmp(macro, *t) == 0){
			addhint(lp, macro, "1");
			return "1";
		}
	return nil;
}

/*
 * This could cause problems. we only realise we need _LIMITS_EXTENSION when
 * its already too late, we have included limits.h, without this macro active
 * and missed the extra info. If the extension macros are only used in the C code
 * all is well but if their value is test in #if statements then we are stuffed
 * we I only guess at "1" for each limit. I should probably parse the sys/limits.h
 * file when I detect the first preprocessor use of any of the #defines in it but
 * I have not been bitten by this yet.
 */
#include "syslimits.h"

static char *
extendedlimits(char *macro)
{
	char **t;

	for(t = Syslimits; t < &Syslimits[nelem(Syslimits)]; t++)
		if(strcmp(macro, *t) == 0){
			addhint(&Glbhints, "_LIMITS_EXTENSION", "1");
			return "1";
		}
	return nil;
}

/*
 * Found a HAVE_funcname or FUNC_funcname test, lookup funcname
 * in all the system libraries I expect to link with.
 */
static char *
function_name(char *macro, char *func)
{
	if(inlibrary(func) == 0)
		return nil;

	/*
	 * people tend to assume strdup() is part of POSIX
	 */
	if(strcmp(func, "strdup") == 0)
		addhint(&Glbhints, "_BSD_EXTENSION", "1");
	addhint(&Lochints, macro, "1");
	return "1";
}

/*
 * Found HAVE_file_H so we check the system include "file" exists
 */
static char *
incfile_exists(char *macro, char *str, List *incdirs)
{
	int rc;
	char *s;
	List *l;
	
	for (l = incdirs; l; l = l->next){
		s = emallocz(strlen(l->name)+strlen(str)+2, 0);
		strcpy(s, l->name);
		strcat(s, "/");
		strcat(s, str);
		rc = access(s, 4);
		free(s);
		if(rc != -1){
			addhint(&Lochints, macro, "1");
			return "1";
		}
	}
	return nil;
}

/*
 * I found an #if #elif or #ifdef referencing a macro which doesn't exist,
 * so I check to see if I think it "should" exist and define it if so.
 */
char *
macrohint(char *macro, List *incdirs)
{
	char *val, *s, *name;

	if((val = looktab(&Lochints, macro, Wellknown, &Wellknown[nelem(Wellknown)])) != nil)
		return val;

	if((val = extendedlimits(macro)) != nil)
		return val;

	if(strncmp(macro, "FUNC_", 5) == 0){
		name = estrdup(macro+5);
		for(s = name; *s; s++)
			*s = tolower(*s);
		val = function_name(macro, name);
		free(name);
		return val;
	}

	if(strncmp(macro, "HAVE_", 5) == 0){
		name = estrdup(macro+5);
	
		for(s = name; *s; s++)
			*s = tolower(*s);

		if((s = strrchr(name, '_')) != nil && strcmp(s, "_h") == 0){
			*s = '.';
			for(s = name; *s; s++)
				if(*s == '_')
					*s = '/';

			val = incfile_exists(macro, name, incdirs);
			free(name);
			return val;
		}

		val = function_name(macro, name);
		free(name);
		return val;
	}


	return nil;
}

/*
 * this inclide file has been used, check if we can 
 * infer any macros that need to be #define as a result.
 *
 * This is mainly for plan9 headers which raise an error if
 * the apropriate _XXXX_EXTENSION macro is not set when they are used.
 */
void
includehint(char *file)
{
	Macdef *nv;

	for(nv = Filehints; nv < &Filehints[nelem(Filehints)]; nv++)
		if(strcmp(file, nv->name) == 0){
			if(looksym(nv->name, nil) == nil)
				addhint(&Glbhints, nv->macro, "1");
			break;
		}
}

/*
 * assumes the GNU practice of naming 
 * packages directories e.g. make-3.78
 */
void
gnu_pkgvers(void)
{
	char buf[128], str[128], *ver, *pkg;

	getwd(buf, sizeof(buf));

	ver = nil;
	if((pkg = strrchr(buf, '/')) != nil){
		pkg++;
		if((ver = strchr(pkg, '-')) != nil)
			*ver++ = 0;
	}

	if(pkg)
		snprint(str, sizeof(str), "\"%s\"", pkg);
	else
		snprint(str, sizeof(str), "\"unknown\"");
	addhint(&Lochints, "PACKAGE", str);

	if(ver)
		snprint(str, sizeof(str), "\"%s\"", ver);
	else
		snprint(str, sizeof(str), "\"unknown\"");
	addhint(&Lochints, "VERSION", str);
}

