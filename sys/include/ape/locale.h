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

/* from musl */
#include <nl_types.h>
extern int catclose(nl_catd);
extern int cmp(void,void);
extern char *catgets(nl_catd, int, int, const char *);
extern nl_catd catopen(const char *, int);
static ssize_t vstrfmon_l(char *, size_t, locale_t, const char *, va_list);
extern ssize_t strfmon_l(char *, size_t, locale_t, const char *, ...);
extern ssize_t strfmon(char *, size_t, const char *, ...);
extern float strtof_l(const char *, char **, locale_t);
extern double strtod_l(const char *, char **, locale_t);
extern long double strtold_l(const char *, char **, locale_t);




#ifdef __cplusplus
}
#endif

#endif /* __LOCALE */
