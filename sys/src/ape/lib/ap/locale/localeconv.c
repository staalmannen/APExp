#include <locale.h>
#include <limits.h>

/*
 * Plan9 kencc does not support C99 designated initialisers (.member = val)
 * in struct literals, so we use positional initialisation in the exact
 * order that struct lconv is declared in <locale.h>.
 *
 * Member order (must match locale.h exactly):
 *   decimal_point, thousands_sep, grouping,
 *   int_curr_symbol, currency_symbol,
 *   mon_decimal_point, mon_thousands_sep, mon_grouping,
 *   positive_sign, negative_sign,
 *   int_frac_digits, frac_digits,
 *   p_cs_precedes, p_sep_by_space, n_cs_precedes, n_sep_by_space,
 *   p_sign_posn, n_sign_posn,
 *   int_p_cs_precedes, int_p_sep_by_space,
 *   int_n_cs_precedes, int_n_sep_by_space,
 *   int_p_sign_posn, int_n_sign_posn
 */
static struct lconv posix_lconv = {
	".",		/* decimal_point */
	"",		/* thousands_sep */
	"",		/* grouping */
	"",		/* int_curr_symbol */
	"",		/* currency_symbol */
	"",		/* mon_decimal_point */
	"",		/* mon_thousands_sep */
	"",		/* mon_grouping */
	"",		/* positive_sign */
	"",		/* negative_sign */
	CHAR_MAX,	/* int_frac_digits */
	CHAR_MAX,	/* frac_digits */
	CHAR_MAX,	/* p_cs_precedes */
	CHAR_MAX,	/* p_sep_by_space */
	CHAR_MAX,	/* n_cs_precedes */
	CHAR_MAX,	/* n_sep_by_space */
	CHAR_MAX,	/* p_sign_posn */
	CHAR_MAX,	/* n_sign_posn */
	CHAR_MAX,	/* int_p_cs_precedes */
	CHAR_MAX,	/* int_p_sep_by_space */
	CHAR_MAX,	/* int_n_cs_precedes */
	CHAR_MAX,	/* int_n_sep_by_space */
	CHAR_MAX,	/* int_p_sign_posn */
	CHAR_MAX,	/* int_n_sign_posn */
};

struct lconv *localeconv(void)
{
	return &posix_lconv;
}
