#ifndef __LOCALE
#define __LOCALE
#pragma lib "/$M/lib/ape/libap.a"

#include <alltypes.h>
#include <stddef.h>
#include <langinfo.h>

#define LC_ALL		0
#define LC_COLLATE	1
#define LC_CTYPE	2
#define LC_MONETARY	3
#define LC_NUMERIC	4
#define LC_TIME		5

struct lconv {
	/* C89 / POSIX.1 members */
	char *decimal_point;
	char *thousands_sep;
	char *grouping;
	char *int_curr_symbol;
	char *currency_symbol;
	char *mon_decimal_point;
	char *mon_thousands_sep;
	char *mon_grouping;
	char *positive_sign;
	char *negative_sign;
	char int_frac_digits;
	char frac_digits;
	char p_cs_precedes;
	char p_sep_by_space;
	char n_cs_precedes;
	char n_sep_by_space;
	char p_sign_posn;
	char n_sign_posn;
	/* C99 / POSIX.1-2001 additions */
	char int_p_cs_precedes;
	char int_p_sep_by_space;
	char int_n_cs_precedes;
	char int_n_sep_by_space;
	char int_p_sign_posn;
	char int_n_sign_posn;
};

#ifdef __cplusplus
extern "C" {
#endif

extern char *setlocale(int, const char *);
extern struct lconv *localeconv(void);

/* from gnulib */
#define LC_MESSAGES 1729

/* from musl.

   Two declarations that used to be here were file-local helpers inside
   musl's own sources, hoisted into this header along with the real
   entry points:

     extern int cmp(void,void);
     static ssize_t vstrfmon_l(char *, size_t, locale_t, const char *, va_list);

   cmp is the static bsearch comparator in locale/catgets.c, and
   vstrfmon_l is the static worker in locale/strfmon.c. Neither belongs
   in a public header, and cmp was actively harmful: <locale.h> is
   included by almost everything, cmp is an ordinary name for a local
   comparison function, and any program that defines its own gets

     seq.c:439 external redeclaration of: cmp
       STATIC FUNC(IND CONST CHAR, VLONG, IND CONST CHAR, VLONG) INT
       EXTERN FUNC(VOID, VOID) INT  /sys/include/ape/locale.h:57
     seq.c:439 function inconsistently declared: cmp

   It was not a valid declaration either -- "(void,void)" is two void
   parameters -- and vstrfmon_l named va_list without <stdarg.h>, so
   anything that had actually used it would not have compiled. */
#include <nl_types.h> /* catgets catclose catopen */
extern void freelocale(locale_t);
extern ssize_t strfmon_l(char *, size_t, locale_t, const char *, ...);
extern ssize_t strfmon(char *, size_t, const char *, ...);
extern float strtof_l(const char *, char **, locale_t);
extern double strtod_l(const char *, char **, locale_t);
extern size_t strftime_l(char *, size_t, const char *, const struct tm *, locale_t);
extern long double strtold_l(const char *, char **, locale_t);

/* other hacks */
#ifndef SETLOCALE_NULL_MAX
#define SETLOCALE_NULL_MAX 256+1
#endif

extern locale_t newlocale(int, const char *, locale_t);


#ifdef __cplusplus
}
#endif

#endif /* __LOCALE */
