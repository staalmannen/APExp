/*
 * printf.c - All the code for sprintf/printf.
 */

/*
 * Copyright (C) 1986, 1988, 1989, 1991-2026,
 * the Free Software Foundation, Inc.
 *
 * This file is part of GAWK, the GNU implementation of the
 * AWK Programming Language.
 *
 * GAWK is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * GAWK is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA
 */


#include "awk.h"

struct flags {
	bool left_just;
	bool alt;
	bool zero;
	bool space;
	bool plus;
	bool quote;
	bool have_prec;
	bool magic_posix_flag;
	char format;
	int base;
	int field_width;
	int precision;
	bool negative;
};

extern int max_args;
extern NODE **args_array;
extern FILE *output_fp;

#define DEFAULT_G_PRECISION 6

static size_t mbc_byte_count(const char *ptr, size_t numchars);
static size_t mbc_char_count(const char *ptr, size_t numbytes);
static void reverse(char *str);
static bool compute_zero_flag(struct flags *flags);
static void adjust_flags(struct flags *flags);
static char *add_thousands(const char *original);
static char *format_integer_digits(NODE *arg, struct flags *flags, bool *used_float);
static char *format_mpg_integer_digits(NODE *arg, struct flags *flags, bool *used_float);
static char *format_signed_integer(NODE *arg, struct flags *flags);
static char *format_unsigned_integer(NODE *arg, struct flags *flags);
static char *format_float(NODE *arg, struct flags *flags);
static char *format_out_of_range(NODE *arg, struct flags *flags);
static char *fill_to_field_width(char *startval, struct flags *flags, int fill);
static char *add_plus_or_space_and_fill(char *number_value, struct flags *flags);
static char *zero_fill_to_precision(char *number_value, struct flags *flags);
static char *add_alt_format(char *number_value, struct flags *flags);

#ifdef HAVE_MPFR

/*
 * mpz2mpfr --- convert an arbitrary-precision integer to a float
 *	without any loss of precision. The returned value is only
 * 	good for temporary use.
 */


static mpfr_ptr
mpz2mpfr(mpz_ptr zi)
{
	size_t prec;
	static mpfr_t mpfrval;
	static bool inited = false;
	int tval;

	/* estimate minimum precision for exact conversion */
	prec = mpz_sizeinbase(zi, 2);	/* most significant 1 bit position starting at 1 */
	prec -= (size_t) mpz_scan1(zi, 0);	/* least significant 1 bit index starting at 0 */
	if (prec < MPFR_PREC_MIN)
		prec = MPFR_PREC_MIN;
	else if (prec > MPFR_PREC_MAX)
		prec = MPFR_PREC_MAX;

	if (! inited) {
		mpfr_init2(mpfrval, prec);
		inited = true;
	} else
		mpfr_set_prec(mpfrval, prec);
	tval = mpfr_set_z(mpfrval, zi, ROUND_MODE);
	IEEE_FMT(mpfrval, tval);
	return mpfrval;
}
#endif

/*
 * format_args() formats arguments of sprintf,
 * and according to a fmt_string providing a format like in
 * printf family from C library.  Returns a string node whose value
 * is a formatted string.  Called by sprintf function.
 *
 * It is one of the uglier parts of gawk.  Thanks to Michal Jaegermann
 * for taming this beast and making it compatible with ANSI C.
 *
 * July 2024: Refactored into something (more) manageable.
 */

NODE *
format_args(
	const char *fmt_string,
	size_t n0,
	NODE *the_args[],
	long num_args)
{
/* copy 'l' bytes from 's' to 'obufout' checking for space in the process */
/* difference of pointers should be of ptrdiff_t type, but let us be kind */
#define bchunk(s, l) if (l) { \
	while ((l) > ofre) { \
		size_t olen = obufout - obuf; \
		erealloc(obuf, char *, osiz * 2); \
		ofre += osiz; \
		osiz *= 2; \
		obufout = obuf + olen; \
	} \
	memcpy(obufout, s, (size_t) (l)); \
	obufout += (l); \
	ofre -= (l); \
}

/* copy one byte from 's' to 'obufout' checking for space in the process */
#define bchunk_one(s) { \
	if (ofre < 1) { \
		size_t olen = obufout - obuf; \
		erealloc(obuf, char *, osiz * 2); \
		ofre += osiz; \
		osiz *= 2; \
		obufout = obuf + olen; \
	} \
	*obufout++ = *s; \
	--ofre; \
}

/* Is there space for something L big in the buffer? */
#define chksize(l)  if ((l) >= ofre) { \
	size_t olen = obufout - obuf; \
	size_t delta = osiz+l-ofre; \
	erealloc(obuf, char *, osiz + delta); \
	obufout = obuf + olen; \
	ofre += delta; \
	osiz += delta; \
}

	size_t cur_arg = 0;
	NODE *r = NULL;
	bool toofew = false;
	char *obuf, *obufout;
	size_t osiz, ofre, olen_final;
	const char *s0, *s1;
	int cs1;
	NODE *arg;
	long fw, prec, argnum;
	bool used_dollar;
	bool lj, alt, have_prec, need_format;
	long *cur = NULL;
	uintmax_t uval;
	int base;
	bool space_flag;
	bool plus_flag;

	struct {
		char *buf;
		size_t bufsize;
		char stackbuf[30];
	} cpbuf;
	char *cend = &cpbuf.stackbuf[sizeof(cpbuf.stackbuf)];
	char *cp;
	const char *fill;
	char signchar = '\0';
	size_t len;
	bool zero_flag = false;
	bool quote_flag = false;
	size_t copy_count, char_count;
	bool magic_posix_flag;
	struct flags flags;

	static const char sp[] = " ";
	static const char bad_modifiers[] = "DHhjLltwz";
	static bool warned[sizeof(bad_modifiers)-1];	// auto-init to zero

	bool modifier_seen[sizeof(bad_modifiers)-1];
#define modifier_index(c)  (strchr(bad_modifiers, c) - bad_modifiers)
	const char *formatted = NULL;

#define INITIAL_OUT_SIZE	64
	emalloc(obuf, char *, INITIAL_OUT_SIZE);
	obufout = obuf;
	osiz = INITIAL_OUT_SIZE;
	ofre = osiz - 1;

	cur_arg = 1;

	cpbuf.bufsize = sizeof(cpbuf.stackbuf);
	cpbuf.buf = cpbuf.stackbuf;

	/*
	 * Check first for use of `count$'.
	 * If plain argument retrieval was used earlier, choke.
	 *	Otherwise, return the requested argument.
	 * If not `count$' now, but it was used earlier, choke.
	 * If this format is more than total number of args, choke.
	 * Otherwise, return the current argument.
	 */
#define parse_next_arg() { \
	if (argnum > 0) { \
		if (cur_arg > 1) { \
			msg(_("fatal: must use `count$' on all formats or none")); \
			goto out; \
		} \
		arg = the_args[argnum]; \
	} else if (used_dollar) { \
		msg(_("fatal: must use `count$' on all formats or none")); \
		arg = 0; /* shutup the compiler */ \
		goto out; \
	} else if (cur_arg >= num_args) { \
		arg = 0; /* shutup the compiler */ \
		toofew = true; \
		break; \
	} else { \
		arg = the_args[cur_arg]; \
		cur_arg++; \
	} \
}

	need_format = false;
	used_dollar = false;

	s0 = s1 = fmt_string;
	while (n0-- > 0) {
		if (*s1 != '%') {
			s1++;
			continue;
		}
		need_format = true;
		bchunk(s0, s1 - s0);
		s0 = s1;
		cur = &fw;
		fw = 0;
		prec = 0;
		base = 0;
		argnum = 0;
		base = 0;
		have_prec = false;
		signchar = '\0';
		zero_flag = false;
		quote_flag = false;
		space_flag = false;
		plus_flag = false;

		lj = alt = false;
		memset(modifier_seen, 0, sizeof(modifier_seen));
		magic_posix_flag = false;
		fill = sp;
		cp = cend;
		s1++;
		memset(& flags, 0, sizeof(flags));

retry:
		if (n0-- == 0)	/* ran out early! */
			break;

		switch (cs1 = *s1++) {
		case (-1):	/* dummy case to allow for checking */
check_pos:
			if (cur != &fw)
				break;		/* reject as a valid format */
			goto retry;
		case '%':
			need_format = false;
			/*
			 * 29 Oct. 2002:
			 * The C99 standard pages 274 and 279 seem to imply that
			 * since there's no arg converted, the field width doesn't
			 * apply.  The code already was that way, but this
			 * comment documents it, at least in the code.
			 *
			 * 27 June 2024:
			 * This is still the case. The 2023 standard says you shouldn't
			 * have anything between the percents.
			 */
			if (do_lint) {
				const char *msg = NULL;

				if (fw != 0 && ! have_prec)
					msg = _("field width is ignored for `%%' specifier");
				else if (fw == 0 && have_prec)
					msg = _("precision is ignored for `%%' specifier");
				else if (fw && have_prec)
					msg = _("field width and precision are ignored for `%%' specifier");

				if (msg != NULL)
					lintwarn("%s", msg);
			}
			bchunk_one("%");
			s0 = s1;
			break;

		case '0':
			/*
			 * Only turn on zero_flag if we haven't seen
			 * the field width or precision yet.  Otherwise,
			 * screws up floating point formatting.
			 */
			if (cur == & fw)
				zero_flag = true;
			if (lj)
				goto retry;
			/* fall through */
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
			if (cur == NULL)
				break;
			if (prec >= 0)
				*cur = cs1 - '0';
			/*
			 * with a negative precision *cur is already set
			 * to -1, so it will remain negative, but we have
			 * to "eat" precision digits in any case
			 */
			while (n0 > 0 && *s1 >= '0' && *s1 <= '9') {
				--n0;
				*cur = *cur * 10 + *s1++ - '0';
			}
			if (prec < 0) 	/* negative precision is discarded */
				have_prec = false;
			if (cur == &prec)
				cur = NULL;
			if (n0 == 0)	/* badly formatted control string */
				continue;
			goto retry;
		case '$':
			if (do_traditional) {
				msg(_("fatal: `$' is not permitted in awk formats"));
				goto out;
			}

			if (cur == &fw) {
				argnum = fw;
				fw = 0;
				used_dollar = true;
				if (argnum <= 0) {
					msg(_("fatal: argument index with `$' must be > 0"));
					goto out;
				}
				if (argnum >= num_args) {
					msg(_("fatal: argument index %ld greater than total number of supplied arguments"), argnum);
					goto out;
				}
			} else {
				argnum = prec;
				prec = 0;
				used_dollar = true;
				if (argnum <= 0) {
					msg(_("fatal: argument index with `$' must be > 0"));
					goto out;
				}
				if (argnum >= num_args) {
					msg(_("fatal: argument index %ld greater than total number of supplied arguments"), argnum);
					goto out;
				}
			}

			goto retry;
		case '*':
			if (cur == NULL)
				break;
			if (! do_traditional && used_dollar && ! isdigit((unsigned char) *s1)) {
				fatal(_("must use `count$' on all formats or none"));
				break;	/* silence warnings */
			} else if (! do_traditional && isdigit((unsigned char) *s1)) {
				int val = 0;

				for (; n0 > 0 && *s1 && isdigit((unsigned char) *s1); s1++, n0--) {
					val *= 10;
					val += *s1 - '0';
				}
				if (*s1 != '$') {
					msg(_("fatal: no `$' supplied for positional field width or precision"));
					goto out;
				} else {
					s1++;
					n0--;
				}
				// val could be less than zero if someone provides a field width
				// so large that it causes integer overflow. Mainly fuzzers do this,
				// but let's try to be good anyway.
				if (val < 0 || val >= num_args) {
					toofew = true;
					break;
				}
				arg = the_args[val];
			} else {
				parse_next_arg();
			}
			(void) force_number(arg);
			*cur = get_number_si(arg);
			if (*cur < 0 && cur == &fw) {
				*cur = -*cur;
				lj = true;
			}
			if (cur == &prec) {
				if (*cur >= 0)
					have_prec = true;
				else
					have_prec = false;
				cur = NULL;
			}
			goto retry;
		case ' ':		/* print ' ' or '-' */
					/* 'space' flag is ignored */
					/* if '+' already present  */
			space_flag = true;
			if (signchar != '\0')
				goto check_pos;
			signchar = cs1;
			goto check_pos;
		case '+':		/* print '+' or '-' */
			plus_flag = true;
			signchar = cs1;
			goto check_pos;
		case '-':
			if (prec < 0)
				break;
			if (cur == &prec) {
				prec = -1;
				goto retry;
			}
			fill = sp;      /* if left justified then other */
			lj = true;	/* filling is ignored */
			goto check_pos;
		case '.':
			if (cur != &fw)
				break;
			cur = &prec;
			have_prec = true;
			goto retry;
		case '#':
			alt = true;
			goto check_pos;
		case '\'':
#if defined(HAVE_LOCALE_H)
			quote_flag = true;
			goto check_pos;
#else
			goto retry;
#endif
		case 'D':
		case 'H':
		case 'h':
		case 'j':
		case 'L':
		case 'l':
		case 't':
		case 'w':
		case 'z':
			if (modifier_seen[modifier_index(cs1)])
				break;
			else {
				int ind = modifier_index(cs1);

				if (do_lint && ! warned[ind]) {
					lintwarn(_("`%c' is meaningless in awk formats; ignored"), cs1);
					warned[ind] = true;
				}
				if (do_posix) {
					msg(_("fatal: `%c' is not permitted in POSIX awk formats"), cs1);
					goto out;
				}
			}
			modifier_seen[modifier_index(cs1)] = true;
			goto retry;

		case 'P':
			if (magic_posix_flag)
				break;
			magic_posix_flag = true;
			goto retry;
		case 'C':		// POSIX 2024 extension, undocumented for now
			cs1 = 'c';
			// FALL THROUGH
		case 'c':
			need_format = false;
			parse_next_arg();
			/* user input that looks numeric is numeric */
			fixtype(arg);
			if ((arg->flags & NUMBER) != 0) {
				uval = get_number_uj(arg);
				if (gawk_mb_cur_max > 1) {
					char buf[100];
					char32_t wc;
					mbstate_t mbs;
					size_t count;

					memset(& mbs, 0, sizeof(mbs));

					wc = uval;

					count = c32rtomb(buf, wc, & mbs);
					if (count == 0
					    || count == (size_t) -1) {
						if (do_lint)
							lintwarn(
						_("[s]printf: value %g is not a valid wide character"),
									arg->numbr);

						goto out0;
					}

					memcpy(cpbuf.buf, buf, count);
					prec = count;
					cp = cpbuf.buf;
					goto pr_tail;
				}
out0:
				;
				/* else,
					fall through */

				cpbuf.buf[0] = uval;
				prec = 1;
				cp = cpbuf.buf;
				goto pr_tail;
			}
			/*
			 * As per POSIX, only output the first character of a
			 * string value.  Thus, we ignore any provided
			 * precision, forcing it to 1.  (Didn't this
			 * used to work? 6/2003.)
			 */
			cp = arg->stptr;
			prec = 1;
			/*
			 * First character can be multiple bytes if
			 * it's a multibyte character. Grr.
			 */
			if (gawk_mb_cur_max > 1) {
				mbstate_t state;
				size_t count;

				memset(& state, 0, sizeof(state));
				count = mbrlen(cp, arg->stlen, & state);
				if (count != (size_t) -1 && count != (size_t) -2 && count > 0) {
					prec = count;
					/* may need to increase fw so that padding happens, see pr_tail code */
					if (fw > 0)
						fw += count - 1;
				}
			}
			goto pr_tail;
		case 'S':		// POSIX 2024 extension, undocumented for now
			cs1 = 's';
			// FALL THROUGH
		case 's':
			need_format = false;
			parse_next_arg();
			arg = force_string(arg);
			if (fw == 0 && ! have_prec)
				prec = arg->stlen;
			else {
				char_count = mbc_char_count(arg->stptr, arg->stlen);
				if (! have_prec || prec > char_count)
					prec = char_count;
			}
			cp = arg->stptr;
	pr_tail:
			if (! lj) {
				while (fw > prec) {
			    		bchunk_one(fill);
					fw--;
				}
			}
			copy_count = prec;
			if (fw == 0 && ! have_prec)
				;
			else if (gawk_mb_cur_max > 1) {
				if (cs1 == 's') {
					assert(cp == arg->stptr || cp == cpbuf.buf);
					copy_count = mbc_byte_count(arg->stptr, prec);
				}
				/* prec was set by code for %c */
				/* else
					copy_count = prec; */
			}
			bchunk(cp, copy_count);
			while (fw > prec) {
				bchunk_one(fill);
				fw--;
			}
			s0 = s1;
			break;

		case 'd':
		case 'i':
			need_format = false;
			parse_next_arg();
			(void) force_number(arg);
			base = 10;

#define set_flags() \
	flags.left_just = lj; \
	flags.alt = alt; \
	flags.zero = zero_flag; \
	flags.space = space_flag; \
	flags.plus = plus_flag; \
	flags.quote = quote_flag; \
	flags.have_prec = have_prec; \
	flags.format = cs1; \
	flags.base = base; \
	flags.field_width = fw; \
	flags.precision = prec; \
	flags.negative = false

			set_flags();
			adjust_flags(& flags);

			formatted = format_signed_integer(arg, & flags);
			len = strlen(formatted);
			chksize(len)
			strcpy(obufout, formatted);
			free((void *) formatted);

			ofre -= len;
			obufout += len;
			s0 = s1;
			break;

		case 'X':
		case 'x':
			base += 6;	/* FALL THROUGH */
		case 'u':
			base += 2;	/* FALL THROUGH */
		case 'o':
			base += 8;
			need_format = false;
			parse_next_arg();
			(void) force_number(arg);

			set_flags();
			adjust_flags(& flags);

			formatted = format_unsigned_integer(arg, & flags);
			len = strlen(formatted);
			chksize(len)
			strcpy(obufout, formatted);
			free((void *) formatted);

			ofre -= len;
			obufout += len;
			s0 = s1;
			break;

#if defined(PRINTF_HAS_A_FORMAT) && PRINTF_HAS_A_FORMAT == 1
		case 'A':
		case 'a':
		{
			static bool warned = false;

			if (do_lint && tolower(cs1) == 'a' && ! warned) {
				warned = true;
				lintwarn(_("%%%c format is POSIX standard but not portable to other awks"), cs1);
			}
			base = 6;
			goto format_float;
		}
#endif
		case 'F':
#if ! defined(PRINTF_HAS_F_FORMAT) || PRINTF_HAS_F_FORMAT != 1
			cs1 = 'f';
			/* FALL THROUGH */
#endif
		case 'g':
		case 'G':
		case 'e':
		case 'f':
		case 'E':
	format_float:
			base += 10;
			need_format = false;
			parse_next_arg();
			(void) force_number(arg);

			set_flags();
			adjust_flags(& flags);

			formatted = format_float(arg, & flags);
			len = strlen(formatted);
			chksize(len)
			strcpy(obufout, formatted);
			free((void *) formatted);

			ofre -= len;
			obufout += len;
			s0 = s1;
			break;
		default:
			if (do_lint && is_alpha(cs1))
				lintwarn(_("ignoring unknown format specifier character `%c': no argument converted"), cs1);
			break;
		}
		if (toofew) {
			msg("%s\n\t`%s'\n\t%*s%s",
			      _("fatal: not enough arguments to satisfy format string"),
			      fmt_string, (int) (s1 - fmt_string - 1), "",
			      _("^ ran out for this one"));
			goto out;
		}
	}
	if (do_lint) {
		if (need_format)
			lintwarn(
			_("[s]printf: format specifier does not have control letter"));
		if (cur_arg < num_args)
			lintwarn(
			_("too many arguments supplied for format string"));
	}
	bchunk(s0, s1 - s0);
	olen_final = obufout - obuf;
#define GIVE_BACK_SIZE (INITIAL_OUT_SIZE * 2)
	if (ofre > GIVE_BACK_SIZE)
		erealloc(obuf, char *, olen_final + 1);
	r = make_str_node(obuf, olen_final, ALREADY_MALLOCED);
	obuf = NULL;
out:
	if (cpbuf.buf != cpbuf.stackbuf)
		efree(cpbuf.buf);

	if (obuf != NULL)
		efree(obuf);

	if (r == NULL)
		gawk_exit(EXIT_FATAL);
	return r;
}


/* printf_common --- common code for sprintf and printf */

static NODE *
printf_common(int nargs)
{
	int i;
	NODE *r, *tmp;

	assert(nargs > 0 && nargs <= max_args);
	for (i = 1; i <= nargs; i++) {
		tmp = args_array[nargs - i] = POP();
		if (tmp->type == Node_var_array) {
			while (--i > 0)
				DEREF(args_array[nargs - i]);
			fatal(_("attempt to use array `%s' in a scalar context"), array_vname(tmp));
		}
	}

	args_array[0] = force_string(args_array[0]);
	if (do_lint && (fixtype(args_array[0])->flags & STRING) == 0)
		lintwarn(_("%s: received non-string format string argument"), "printf/sprintf");
	r = format_args(args_array[0]->stptr, args_array[0]->stlen, args_array, nargs);
	for (i = 0; i < nargs; i++)
		DEREF(args_array[i]);
	return r;
}

/* do_sprintf --- perform sprintf */

NODE *
do_sprintf(int nargs)
{
	NODE *r;

	if (nargs == 0)
		fatal(_("sprintf: no arguments"));

	r = printf_common(nargs);
	if (r == NULL)
		gawk_exit(EXIT_FATAL);
	return r;
}


/* do_printf --- perform printf, including redirection */

void
do_printf(int nargs, int redirtype)
{
	FILE *fp = NULL;
	NODE *tmp;
	struct redirect *rp = NULL;
	int errflg = 0;
	NODE *redir_exp = NULL;

	if (nargs == 0) {
		if (do_traditional) {
			if (do_lint)
				lintwarn(_("printf: no arguments"));
			if (redirtype != 0) {
				redir_exp = TOP();
				if (redir_exp->type != Node_val)
					fatal(_("attempt to use array `%s' in a scalar context"), array_vname(redir_exp));
				rp = redirect(redir_exp, redirtype, & errflg, true);
				DEREF(redir_exp);
				decr_sp();
			}
			return;	/* bwk accepts it silently */
		}
		fatal(_("printf: no arguments"));
	}

	if (redirtype != 0) {
		redir_exp = PEEK(nargs);
		if (redir_exp->type != Node_val)
			fatal(_("attempt to use array `%s' in a scalar context"), array_vname(redir_exp));
		rp = redirect(redir_exp, redirtype, & errflg, true);
		if (rp != NULL) {
			if ((rp->flag & RED_TWOWAY) != 0 && rp->output.fp == NULL) {
				if (is_non_fatal_redirect(redir_exp->stptr, redir_exp->stlen)) {
					update_ERRNO_int(EBADF);
					return;
				}
				(void) close_rp(rp, CLOSE_ALL);
				fatal(_("printf: attempt to write to closed write end of two-way pipe"));
			}
			fp = rp->output.fp;
		}
		else if (errflg) {
			update_ERRNO_int(errflg);
			return;
		}
	} else if (do_debug)	/* only the debugger can change the default output */
		fp = output_fp;
	else
		fp = stdout;

	tmp = printf_common(nargs);
	if (redir_exp != NULL) {
		DEREF(redir_exp);
		decr_sp();
	}
	if (tmp != NULL) {
		if (fp == NULL) {
			DEREF(tmp);
			return;
		}
		efwrite(tmp->stptr, sizeof(char), tmp->stlen, fp, "printf", rp, true);
		if (rp != NULL && (rp->flag & RED_TWOWAY) != 0)
			rp->output.gawk_fflush(rp->output.fp, rp->output.opaque);
		DEREF(tmp);
	} else
		gawk_exit(EXIT_FATAL);
}

/* format_integer_digits --- format just the actual value of an integer. caller frees return value */

static char *
format_integer_digits(NODE *arg, struct flags *flags, bool *used_float)
{
#define VALUE_SIZE 40
	char *buf = NULL;
	size_t buflen;
	static const char lchbuf[] = "0123456789abcdef";
	static const char Uchbuf[] = "0123456789ABCDEF";
	const char *chbuf;
	char *cp;
	bool quote_flag = false;
	uintmax_t uval;
	int i;
	double tmpval;

#define growbuffer(buf, buflen, cp) { \
		erealloc(buf, char *, buflen * 2); \
		cp = buf + buflen; \
		buflen *= 2; \
	}

#if defined(HAVE_LOCALE_H)
	quote_flag = (flags->quote && loc.thousands_sep[0] != '\0');
#endif
	emalloc(buf, char *, VALUE_SIZE);
	buflen = VALUE_SIZE;
	cp = buf;

	*used_float = false;
	tmpval = double_to_int(arg->numbr);
	if (flags->base == 10 && flags->format != 'u') {
		// signed decimal
		if (tmpval == -0)
			tmpval = 0;

		/*
		 * Use snprintf return value to tell if there
		 * is enough room in the buffer or not.
		 */
		while ((i = snprintf(buf, buflen, "%.0f", tmpval)) >= buflen) {
			if (i > 0)
				buflen += (i > buflen) ?  i : buflen;
			else
				buflen *= 2;
			assert(buflen > 0);
			erealloc(buf, char *, buflen);
		}
	} else {
		// octal or hex or unsigned decimal
		chbuf = (flags->format == 'X' ? Uchbuf : lchbuf);

		if (tmpval < 0) {
			uval = (uintmax_t) (intmax_t) tmpval;
			if ((AWKNUM)(intmax_t)uval != double_to_int(tmpval)) {
				flags->format = 'g';
				free((void *) buf);
				*used_float = true;

				return format_float(arg, flags);
			}
		} else {
			uval = (uintmax_t) tmpval;
			if ((AWKNUM)uval != double_to_int(tmpval)) {
				flags->format = 'g';
				free((void *) buf);
				*used_float = true;

				return format_float(arg, flags);
			}
		}

		// generate the digits backwards.
		do {
			if (cp >= buf + buflen)
				growbuffer(buf, buflen, cp);

			*cp++ = chbuf[uval % flags->base];
			uval /= flags->base;
		} while (uval > 0);
		*cp = '\0';

		// turn it back around
		reverse(buf);
	}

	if (flags->base == 10 && quote_flag) {
		char *with_commas = add_thousands(buf);

		free((void *) buf);
		buf = with_commas;
	}

	return buf;
}

/* format_signed_integer --- format a signed integer (decimal) value. caller frees return value */

static char *
format_signed_integer(NODE *arg, struct flags *flags)
{
	char *number_value;
	size_t val_len;
	char *buf1 = NULL;
	char fill = ' ';
	bool used_float = false;

	if (out_of_range(arg))
		return format_out_of_range(arg, flags);

	if (is_mpg_integer(arg) || is_mpg_float(arg))
		number_value = format_mpg_integer_digits(arg, flags, & used_float);
	else
		number_value = format_integer_digits(arg, flags, & used_float);	// just digits, possible leading '-'

	if (used_float)
		return number_value;

	val_len = strlen(number_value);

	// We now have the initial *integer* decimal value in hand.
	// If it's decimal, we've added commas if appropriate. If it's negative
	// and decimal, it has a minus sign.

	// check if negative
	flags->negative = (number_value[0] == '-');
	
	// The next step is deal with the rest of the printf flags.

	// add more output digits to match the precision
	if (flags->have_prec && flags->precision == 0 && is_zero(arg)) {
		/*
		 * No actual value. But if there is plus or space or wide
		 * field width or left just, we have to handle those.
		 */
		number_value[0] = '\0';		// value is empty

		return add_plus_or_space_and_fill(number_value, flags);
	} else if (flags->have_prec &&
			(val_len < flags->precision ||
			 (flags->negative && val_len - 1 < flags->precision))) {
		buf1 = zero_fill_to_precision(number_value, flags);
		val_len = strlen(buf1);

		if (val_len < flags->field_width)
			buf1 = fill_to_field_width(buf1, flags, ' ');

		return buf1;
	} else if (flags->field_width > val_len) {
		int fw = flags->field_width;
		size_t buflen = flags->field_width +
			(flags->negative || flags->plus || flags->space) + 1;
		char *cp;

		if (compute_zero_flag(flags))
			fill = '0';

		reverse(number_value);
		if (flags->negative) {
			number_value[val_len - 1] = '\0';	// will restore later.
			val_len--;
		}
		
		fw -= (flags->negative || flags->space || flags->plus);

		emalloc(buf1, char *, buflen);
		strcpy(buf1, number_value);
		free((void *) number_value);
		cp = buf1 + val_len;

		if (fill == '0')
			for (; fw > val_len; fw--)
				*cp++ = fill;

		if (flags->negative)
			*cp++ = '-';
		else if (flags->plus)
			*cp++ = '+';
		else if (flags->space)
			*cp++ = ' ';

		*cp = '\0';

		reverse(buf1);

		return fill_to_field_width(buf1, flags, ' ');
	} else if ((flags->plus || flags->space) && ! flags->negative) {
		emalloc(buf1, char *, val_len + 2);
		if (flags->plus) {
			sprintf(buf1, "+%s", number_value);
		} else {
			sprintf(buf1, " %s", number_value);
		}

		free((void *) number_value);
	} else
		buf1 = number_value;

	return buf1;
}

/* format_unsigned_integer --- format an unsigned integer value. caller frees return value */

static char *
format_unsigned_integer(NODE *arg, struct flags *flags)
{
	char *number_value;
	char *buf1 = NULL;
	char fill = ' ';
	size_t val_len;
	bool used_float = false;

	if (out_of_range(arg))
		return format_out_of_range(arg, flags);

	if (is_mpg_integer(arg) || is_mpg_float(arg))
		number_value = format_mpg_integer_digits(arg, flags, & used_float);
	else
		number_value = format_integer_digits(arg, flags, & used_float);	// just digits

	if (used_float)
		return number_value;

	val_len = strlen(number_value);

	// We now have the initial *integer* decimal, octal, or hex value in hand.
	// If it's decimal, we've added commas if appropriate.
	
	// The next step is deal with the rest of the printf flags.

	if (flags->have_prec && flags->precision == 0 && is_zero(arg)
		&& (! flags->alt || flags->base != 8)) {
			number_value[0] = '\0';

			if (flags->field_width > 0)
				number_value = fill_to_field_width(number_value, flags, ' ');

			return number_value;
	}

	// Add more output digits to match the precision
	if (flags->have_prec && val_len < flags->precision) {
		// we ignore flags->alt when there's a precision
		// also plus and space
		flags->plus = flags->space = false;
		buf1 = zero_fill_to_precision(number_value, flags);	// frees number_value
		val_len = strlen(buf1);
		number_value = buf1;
	}

	if (flags->alt && flags->base != 10 && ! is_zero(arg)) {
		buf1 = add_alt_format(number_value, flags);
		flags->alt = false;
	} else {
		buf1 = number_value;
	}
	val_len = strlen(buf1);

	// continue with buf1
	if (flags->field_width > val_len) {
		// pad the field if necessary
		// when there's a precision, field width padding with zeros is not done.
		if (compute_zero_flag(flags))
			fill = '0';

		buf1 = fill_to_field_width(buf1, flags, fill);
		val_len = strlen(buf1);
	}

	if (flags->alt && ! is_zero(arg)) {
		buf1 = add_alt_format(buf1, flags);
		val_len = strlen(buf1);
	}

	return buf1;
}

/* format_out_of_range --- format an out of range value as %g. caller frees return value */

static char *
format_out_of_range(NODE *arg, struct flags *flags)
{
	/*
	 * out of range - emergency use of %g format,
	 * or format NaN and INF values.
	 */

	// nan_inf_val points to a static buffer, don't free it.
	const char *nan_inf_val = format_nan_inf(arg, flags->format);

	if (do_posix || flags->magic_posix_flag || nan_inf_val == NULL) {
		if (do_lint && ! do_posix && ! flags->magic_posix_flag)
			lintwarn(_("[s]printf: value %g is out of range for `%%%c' format"),
						(double) arg->numbr,
						flags->format);

		if (strchr("aAeEfFgG", flags->format) == NULL)
			flags->format = 'g';

		return format_float(arg, flags);
	}

	if (do_lint)
		lintwarn(_("[s]printf: value %s is out of range for `%%%c' format"),
					nan_inf_val, flags->format);

	// A NaN or Inf, deal with a field width, if any
	size_t len = strlen(nan_inf_val);
	if (flags->field_width > len) {
		char *buf = estrdup(nan_inf_val, len);

		buf = fill_to_field_width(buf, flags, ' ');	// frees original

		return buf;
	}

	return estrdup(nan_inf_val, len);
}

/* compute_zero_flag --- return true if we want to fill with zeros */

static bool
compute_zero_flag(struct flags *flags)
{
	bool zero_flag;

	/*
	 * When to fill with zeroes is of course not simple.
	 * First: No zero fill if left-justifying.
	 * Next: There seem to be two cases:
	 * 	A '0' without a precision, e.g. %06d
	 * 	A precision with no field width, e.g. %.10d
	 * Any other case, we don't want to fill with zeroes.
	 */
	zero_flag = (! flags->left_just
		    && ((flags->zero && ! flags->have_prec)
			 || (flags->field_width == 0 && flags->have_prec)));

	return zero_flag;
}

/* format_mpg_integer_digits --- format an MPZ or MPFR integer. caller frees return value */

/*
 * It seems that mpfr_snprintf() doesn't exactly mimic snprintf() with respect
 * to all the flags and width and precision.  So we instead we simply generate
 * the digits and let the higher level code handle padding and so on.
 */

static char *
format_mpg_integer_digits(NODE *arg, struct flags *flags, bool *used_float)
{
#ifdef HAVE_MPFR
	mpz_ptr zi = NULL;
	mpfr_ptr mf = NULL;
	char *buf;
	size_t buflen;
	char cpbuf[30];
	int nc;
	bool quote_flag = false;

	*used_float = false;

#if defined(HAVE_LOCALE_H)
	quote_flag = (flags->quote && loc.thousands_sep[0] != '\0');
#endif

	if (is_zero(arg))
		return estrdup("0", 1);

	if (is_mpg_integer(arg)) {
		zi = arg->mpg_i;

		if (flags->format != 'd' && flags->format != 'i') {
			if (mpz_sgn(zi) <= 0) {
				/*
				 * Negative value or 0 requires special handling.
				 * Unlike MPFR, GMP does not allow conversion
				 * to (u)intmax_t. So we first convert GMP type to
				 * a MPFR type.
				 */
				mf = mpz2mpfr(zi);
				goto mpf1;
			}
		}


	} else if (is_mpg_float(arg)) {
		mf = arg->mpg_numbr;
		if (! mpfr_number_p(mf)) {
			cant_happen("%s", "format_mpg_integer called on nan or inf");
		}

		if (flags->format != 'd' && flags->format != 'i') {
mpf1:
			/*
			 * The output of printf("%#.0x", 0) is 0 instead of 0x, hence <= in
			 * the comparison below.
			 */
			if (mpfr_sgn(mf) <= 0) {
				if (! mpfr_fits_intmax_p(mf, ROUND_MODE)) {
					*used_float = true;

					return format_float(arg, flags);
				}
				goto fmt0;
			}
		}

		(void) mpfr_get_z(mpzval, mf, MPFR_RNDZ);	/* convert to GMP integer */
		zi = mpzval;
		// fall through
	}
fmt0:
	buflen = flags->field_width + flags->precision + 11;	/* 11 == slop */
	emalloc(buf, char *, buflen);


#if defined(LC_NUMERIC)
	if (quote_flag && ! use_lc_numeric)
		setlocale(LC_NUMERIC, "");
#endif

	sprintf(cpbuf, "%%Z%c", flags->format);
	while ((nc = mpfr_snprintf(buf, buflen, cpbuf, zi)) >= (int) buflen) {
		buflen *= 2;
		erealloc(buf, char *, buflen);
	}

#if defined(LC_NUMERIC)
	if (quote_flag && ! use_lc_numeric)
		setlocale(LC_NUMERIC, "C");
#endif

	if (quote_flag && flags->base == 10) {
		char *new_text = add_thousands(buf);

		free((void *) buf);
		buf = new_text;
	}

	return buf;
#else
	static char empty[] = "";
	cant_happen("%s", "trying to format GMP integer");
	return empty;
#endif
}


/* adjust_flags --- take care of conflicts between flags */

/*
 * The flag characters and their meanings are:
 * 
 * - The result of the conversion is left-justified within the field. (It is
 *   right-justified if this flag is not specified.)
 * 
 * + The result of a signed conversion always begins with a plus or minus
 *   sign. (It begins with a sign only when a value with a negative sign
 *   is converted if this flag is not specified.)
 *
 * space   If the first character of a signed conversion is not a sign,
 *   or if a signed conversion results in no characters, a space is prefixed
 *   to the result. If the space and + flags both appear, the space flag is ignored.
 * 
 * # The result is converted to an "alternative form". For o conversion,
 *   it increases the precision, if and only if necessary, to force the
 *   first digit of the result to be a zero (if the value and precision are
 *   both 0, a single 0 is printed). For b conversion, a nonzero result has
 *   0b prefixed to it. For the optional B conversion as described below,
 *   a nonzero result has 0B prefixed to it. For x (or X) conversion,
 *   a nonzero result has 0x (or 0X) prefixed to it. For a, A, e, E, f,
 *   F, g, and G conversions, the result of converting a floating-point
 *   number always contains a decimal-point character, even if no digits
 *   follow it. (Normally, a decimal-point character appears in the result of
 *   these conversions only if a digit follows it.) For g and G conversions,
 *   trailing zeros are not removed from the result. For other conversions,
 *   the behavior is undefined.
 * 
 * 0 For b, d, i, o, u, x, X, a, A, e, E, f, F, g, and G conversions,
 *   leading zeros (following any indication of sign or base) are used to
 *   pad to the field width rather than performing space padding, except
 *   when converting an infinity or NaN. If the 0 and - flags both appear,
 *   the 0 flag is ignored. For d, i, o, u, x, and X conversions, if a
 *   preision is specified, the 0 flag is ignored. For other conversions,
 *   the behavior is undefined.
 */

static void
adjust_flags(struct flags *flags)
{
	if (flags->base == 0)
		cant_happen("%s", "flags->base == 0");

	if (flags->base == 10 && strchr("cdisu", flags->format) != NULL)
		flags->alt = false;

	if (flags->field_width < 0) {
		flags->field_width = -flags->field_width;
		flags->left_just = true;
	}

	if (flags->base != 10) {
		flags->quote = false;
	}

	if (flags->plus)
		flags->space = false;

	if (strchr("diouxX", flags->format) != NULL && flags->have_prec)
		flags->zero = false;
}

/* format_float --- format a floating point number. caller frees return value */

/*
 * We let the C and MPFR libraries handle the quote flag, since they
 * know how to do it for the floating point formats.  Thus here we do NOT
 * set up a separate quote_flag variable based on the contents of the
 * struct locale loc.
 */

static char *
format_float(NODE *arg, struct flags *flags)
{
	char *buf;
	size_t buflen;
	char *cp;
	char cpbuf[100];
	
	double tmpval;
#ifdef HAVE_MPFR
	mpfr_ptr mf = NULL;
#endif
	int nc;
	bool mpfr_format = false;

	if (out_of_range(arg))
		return format_out_of_range(arg, flags);

	(void) force_number(arg);

	if (! is_mpg_number(arg))
		tmpval = arg->numbr;
#ifdef HAVE_MPFR
	else if (is_mpg_float(arg)) {
		mf = arg->mpg_numbr;
		mpfr_format = true;
	} else {
		/* arbitrary-precision integer, convert to MPFR float */
		assert(mf == NULL);
		mf = mpz2mpfr(arg->mpg_i);
		mpfr_format = true;
	}
#endif

	if (! flags->have_prec)
		flags->precision = DEFAULT_G_PRECISION;


	buflen = flags->field_width + flags->precision + 11;	/* 11 == slop */
	emalloc(buf, char *, buflen);

	int signchar = '\0';
	if (flags->plus)
		signchar = '+';
	else if (flags->space)
		signchar = ' ';

	cp = cpbuf;
	*cp++ = '%';
	if (flags->left_just)
		*cp++ = '-';
	if (signchar)
		*cp++ = signchar;
	if (flags->alt)
		*cp++ = '#';
	if (flags->zero)
		*cp++ = '0';
	if (flags->quote)
		*cp++ = '\'';

#if defined(LC_NUMERIC)
	if (flags->quote && ! use_lc_numeric)
		setlocale(LC_NUMERIC, "");
#endif

	if (mpfr_format) {
#ifdef HAVE_MPFR
		sprintf(cp, "*.*R*%c", flags->format);
		while ((nc = mpfr_snprintf(buf, buflen, cpbuf,
			     flags->field_width, flags->precision, ROUND_MODE, mf)) >= (int) buflen) {
			erealloc(buf, char *, buflen * 2);
			buflen *= 2;
		}
#else
		cant_happen("%s", "trying to format GMP/MPFR number");
#endif
	} else {
		if (flags->have_prec || tolower(flags->format) != 'a') {
			sprintf(cp, "*.*%c", flags->format);
			while ((nc = snprintf(buf, buflen, cpbuf,
				     flags->field_width, flags->precision,
				     (double) tmpval)) >= (int) buflen) {
				erealloc(buf, char *, buflen * 2);
				buflen *= 2;
			}
		} else {
			// For %a and %A, use the default precision if it
			// wasn't supplied by the user.
			sprintf(cp, "*%c", flags->format);
			while ((nc = snprintf(buf, buflen, cpbuf,
				     flags->field_width,
				     (double) tmpval)) >= (int) buflen) {
				erealloc(buf, char *, buflen * 2);
				buflen *= 2;
			}
		}
	}

#if defined(LC_NUMERIC)
	if (flags->quote && ! use_lc_numeric)
		setlocale(LC_NUMERIC, "C");
#endif

	return buf;
}

/* mbc_byte_count --- return number of bytes for corresponding numchars multibyte characters */

static size_t
mbc_byte_count(const char *ptr, size_t numchars)
{
	mbstate_t cur_state;
	size_t sum = 0;
	int mb_len;

	memset(& cur_state, 0, sizeof(cur_state));

	assert(gawk_mb_cur_max > 1);
	mb_len = mbrlen(ptr, numchars * gawk_mb_cur_max, &cur_state);
	if (mb_len <= 0)
		return numchars;	/* no valid m.b. char */

	/* Since we're restarting the loop from the beginning anyway, make
	   sure to reset mbstate to handle partial multibyte sequences on
	   UTF-16 systems. */
	memset(& cur_state, 0, sizeof(cur_state));

	for (; numchars > 0; numchars--) {
		mb_len = mbrlen(ptr, numchars * gawk_mb_cur_max, &cur_state);
		if (mb_len <= 0)
			break;
#ifdef __CYGWIN__
		/* Internal values used for UTF-8 or GB18030 input. */
		if (cur_state.__count == 4 || cur_state.__count == 18030)
		      /* Surrogate first half, the character has not been
			 fully consumed yet.  Make sure to read the MB chars
			 required to create the complete surrogate. */
		      ++numchars;
#endif
		sum += mb_len;
		ptr += mb_len;
	}

	return sum;
}

/* mbc_char_count --- return number of m.b. chars in string, up to numbytes bytes */

static size_t
mbc_char_count(const char *ptr, size_t numbytes)
{
	mbstate_t cur_state;
	size_t sum = 0;
	int mb_len;

	if (gawk_mb_cur_max == 1)
		return numbytes;

	memset(& cur_state, 0, sizeof(cur_state));

	mb_len = mbrlen(ptr, numbytes, &cur_state);
	if (mb_len <= 0)
		return numbytes;	/* no valid m.b. char */

	/* Since we're starting from the beginning anyway, make sure to
	   reset mbstate to handle partial multibyte sequences on UTF-16
	   systems. */
	memset(& cur_state, 0, sizeof(cur_state));

	while (numbytes > 0) {
		mb_len = mbrlen(ptr, numbytes, &cur_state);
		if (mb_len <= 0)
			break;
#ifdef __CYGWIN__
		/* Internal values used for UTF-8 or GB18030 input. */
		if (cur_state.__count == 4 || cur_state.__count == 18030)
			/* Surrogate first half, the character has not been
			   fully consumed yet.  Don't count the lone surrogate
			   half as full character. */
			;
		else
			sum++;
#else
		sum++;
#endif
		ptr += mb_len;
		numbytes -= mb_len;
	}

	return sum;
}

/* out_of_range --- return true if a value is out of range */

bool
out_of_range(NODE *n)
{
#ifdef HAVE_MPFR
	if (is_mpg_integer(n))
		return false;
	else if (is_mpg_float(n))
		return (! mpfr_number_p(n->mpg_numbr));
	else
#endif
		return (isnan(n->numbr) || isinf(n->numbr));
}

/* format_nan_inf --- format NaN and INF values. return value is to a static buffer */

char *
format_nan_inf(NODE *n, char format)
{
	static char buf[100];
	double val = n->numbr;
	enum possible { PLUS_NAN, MINUS_NAN, PLUS_INF, MINUS_INF, NONE } result = NONE;
	static const char *strings[] = { "+nan", "-nan", "+inf", "-inf" };

#ifdef HAVE_MPFR
	if (is_mpg_integer(n))
		return NULL;
	else if (is_mpg_float(n)) {
		if (mpfr_nan_p(n->mpg_numbr)) {
			result = (mpfr_signbit(n->mpg_numbr) != 0 ? MINUS_NAN : PLUS_NAN);
		} else if (mpfr_inf_p(n->mpg_numbr)) {
			result = (mpfr_signbit(n->mpg_numbr) != 0 ? MINUS_INF : PLUS_INF);
		} else
			return NULL;
	}
	/* else
		fallthrough */
#endif

	if (result == NONE) {
		if (isnan(val)) {
			result = (signbit(val) != 0 ? MINUS_NAN : PLUS_NAN);
		} else if (isinf(val)) {
			result = (val < 0 ? MINUS_INF : PLUS_INF);
		} else
			return NULL;
	}

	strcpy(buf, strings[(int) result]);

	if (isupper(format)) {
		int i;

		for (i = 0; buf[i] != '\0'; i++)
			buf[i] = toupper(buf[i]);
	}

	return buf;
}


/* reverse --- reverse the contents of a string in place */

static void
reverse(char *str)
{
	int i, j;
	char tmp;

	for (i = 0, j = strlen(str) - 1; j > i; i++, j--) {
		tmp = str[i];
		str[i] = str[j];
		str[j] = tmp;
	}
}

/* add_thousands --- add the thousands separator. caller frees the return value */

/*
 * Copy the source string into the destination string, backwards,
 * adding the thousands separator at the right points. Then reverse
 * the string when done. This gives us much cleaner code than trying
 * to work through the string backwards. (We tried it, it was yucky.)
 */

static char *
add_thousands(const char *original)
{
	size_t orig_len = strlen(original);
	size_t new_len = orig_len + 1;
	char *newbuf;
	const char *src;
	char *dest;

	emalloc(newbuf, char *, new_len);
	memset(newbuf, '\0', new_len);

#if defined(HAVE_LOCALE_H)
	new_len = orig_len + (orig_len * strlen(loc.thousands_sep)) + 1; 	// worst case
	erealloc(newbuf, char *, new_len);
	memset(newbuf, '\0', new_len);

	src = original + strlen(original) - 1;
	dest = newbuf;

	if (loc.decimal_point[0] != '\0') {
		const char *dec = NULL;

		if ((dec = strchr(original, loc.decimal_point[0])) != NULL) {
			while (src >= dec)
				*dest++ = *src--;
		}
	}


	int ii = 0;
	int jj = 0;
	do {
		*dest++ = *src--;
		if (loc.grouping[ii] && ++jj == loc.grouping[ii]) {
			if (src >= original) {	/* only add if more digits coming */
				const char *ts = loc.thousands_sep;
				int k;

				for (k = strlen(ts) - 1; k >= 0; k--)
					*dest++ = ts[k];
			}
			if (loc.grouping[ii+1] == 0)
				jj = 0;		/* keep using current val in loc.grouping[ii] */
			else if (loc.grouping[ii+1] == CHAR_MAX) {
				// copy in the rest and be done
				while (src >= original)
					*dest++ = *src--;
				break;
			} else {
				ii++;
				jj = 0;
			}
		}
	} while (src >= original);

	*dest++ = '\0';
	reverse(newbuf);
#else
	strcpy(newbuf, original);
#endif

	return newbuf;
}

/* fill_to_field_width --- handle justification and padding, frees startval if necessary, caller frees return */

static char *
fill_to_field_width(char *startval, struct flags *flags, int fill)
{
	size_t l = strlen(startval);
	char *buf;
	char *cp;
	int fw = flags->field_width;

	if (l >= fw)	// nothing to do
		return startval;

	emalloc(buf, char *, fw + 1);
	cp = buf;

	if (flags->left_just) {
		strcpy(buf, startval);
		cp += l;
		fw -= l;
		for (; fw > 0; fw--)
			*cp++ = fill;
		*cp = '\0';
	} else {
		for (; fw > l; fw--)
			*cp++ = fill;
		strcpy(cp, startval);
	}

	free((void *) startval);

	return buf;
}

/* add_plus_or_space_and_fill --- what it says */

static char *
add_plus_or_space_and_fill(char *number_value, struct flags *flags)
{
	char *buf1;
	char *cp;
	size_t buflen;
	int fw = flags->field_width;

	buflen = flags->field_width + strlen(number_value) +
		(flags->space || flags->plus || flags->negative) + 1;

	emalloc(buf1, char *, buflen);
	cp = buf1;

	if (flags->left_just) {
		if (flags->negative) {
			*cp++ = '-';
			fw--;
		} else if (flags->plus) {
			*cp++ = '+';
			fw--;
		} else if (flags->space) {
			*cp++ = ' ';
			fw--;
		}
		for (; fw > 0; fw--)
			*cp++ = ' ';
		*cp = '\0';
	} else if (fw > 0 || flags->plus || flags->space) {
		char final = ' ';
		if (flags->negative)
			final = '-';
		else if (flags->plus)
			final = '+';

		for (fw--; fw > 0; fw--)
			*cp++ = ' ';
		*cp++ = final;
		*cp = '\0';
	} else
		buf1[0] = '\0';

	strcat(buf1, number_value);

	free((void *) number_value);

	return buf1;

}

/* zero_fill_to_precision --- what it says */

static char *
zero_fill_to_precision(char *number_value, struct flags *flags)
{
	char *buf1;
	char *cp, *src;
	size_t buflen;
	int prec = flags->precision;
	size_t val_len = strlen(number_value);

	buflen = (flags->negative || flags->plus || flags->space) +
			flags->precision + 1;	// we know val_len < precision

	emalloc(buf1, char *, buflen);
	cp = buf1;
	src = number_value;

	if (flags->negative) {
		*cp++ = '-';
		src++;
		val_len--;
	} else if (flags->plus) {
		*cp++ = '+';
	} else if (flags->space) {
		*cp++ = ' ';
	}

	for (; prec > val_len; prec--)
		*cp++ = '0';

	strcpy(cp, src);
	free((void *) number_value);

	return buf1;
}

/* add_alt_format --- deal with zero padding and the alt flag */

static char *
add_alt_format(char *number_value, struct flags *flags)
{
	int fw;
	bool zero_flag;
	char *buf, *cp;
	size_t buflen;
	size_t val_len = strlen(number_value);

	assert(flags->alt);
	assert(flags->base != 10);

	zero_flag = compute_zero_flag(flags);

	buflen = flags->field_width;
	if (buflen < val_len)
		buflen = val_len;
	buflen += 3;

	emalloc(buf, char *, buflen);
	cp = buf;

	fw = flags->field_width;
	if (flags->base == 16) {
		*cp++ = '0';
		*cp++ = flags->format;
		fw -= 2;

		if (zero_flag) {
			fw -= val_len;
			for (; fw > 0; fw--)
				*cp++ = '0';
			// fall through
		}

		strcpy(cp, number_value);
	} else if (number_value[0] != '0') {
		sprintf(buf, "0%s", number_value);
	} else {
		strcpy(buf, number_value);
	}

	free((void *) number_value);

	return buf;
}

#if 0
// test program

int main(int argc, char **argv)
{
	struct lconv *l;

	setlocale(LC_ALL, "");
	l = localeconv();

	const char *new = add_thousands("12345678901234567890.54321", l);
	printf("%s\n", new);
	free((void*) new);

	new = add_thousands("12345678901234567890", l);
	printf("%s\n", new);
	free((void*) new);

	return 0;
}
#endif
