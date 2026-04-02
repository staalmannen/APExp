/*
 * builtin.c - Builtin functions and various utility procedures.
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
#if defined(HAVE_FCNTL_H)
#include <fcntl.h>
#endif
#include "random.h"

#if defined(HAVE_POPEN_H)
#include "popen.h"
#endif

#ifndef CHAR_BIT
# define CHAR_BIT 8
#endif

/* The extra casts work around common compiler bugs.  */
#define TYPE_SIGNED(t) (! ((t) 0 < (t) -1))
/* Note:  these assume that negative integers are represented internally
   via 2's complement, which is not mandated by C.  They also ignore the
   fact that signed integer arithmetic overflow can trigger exceptions,
   unlike unsigned which is guaranteed not to do so. */
#define TYPE_MINIMUM(t) ((t) (TYPE_SIGNED (t) \
			      ? ~ (uintmax_t) 0 << (sizeof (t) * CHAR_BIT - 1) \
			      : 0))
#define TYPE_MAXIMUM(t) ((t) (~ (t) 0 - TYPE_MINIMUM (t)))

#ifndef INTMAX_MIN
# define INTMAX_MIN TYPE_MINIMUM (intmax_t)
#endif
#ifndef UINTMAX_MAX
# define UINTMAX_MAX TYPE_MAXIMUM (uintmax_t)
#endif

#ifndef SIZE_MAX	/* C99 constant, can't rely on it everywhere */
#define SIZE_MAX ((size_t) -1)
#endif

/* Can declare these, since we always use the random shipped with gawk */
extern char *initstate(unsigned long seed, char *state, long n);
extern char *setstate(char *state);
extern long random(void);
extern void srandom(unsigned long seed);

extern NODE **args_array;
extern int max_args;
extern NODE **fields_arr;
extern bool output_is_tty;
extern FILE *output_fp;

static int gawk_system(const char *command);

#define POP_TWO_SCALARS(s1, s2) \
s2 = POP_SCALAR(); \
s1 = POP(); \
do { if (s1->type == Node_var_array) { \
DEREF(s2); \
fatal(_("attempt to use array `%s' in a scalar context"), array_vname(s1)); \
}} while (false)


/* check argument counts --- for use when called indirectly */

void
check_exact_args(int nargs, const char *fname, int count)
{
	if (nargs != count)
		fatal(_("%s: called with %d arguments"), fname, nargs);
}

void
check_args_min_max(int nargs, const char *fname, int min, int max)
{
	if (nargs < min || nargs > max)
		fatal(_("%s: called with %d arguments"), fname, nargs);
}

/*
 * Since we supply the version of random(), we know what
 * value to use here.
 */
#define GAWK_RANDOM_MAX 0x7fffffffL


/* wrerror --- handle a write or flush error */

static void
wrerror(FILE *fp, const char *from, struct redirect *rp)
{
	os_maybe_set_errno();

	/* for stdout, die with a real SIGPIPE, like other awks */
	if (fp == stdout && errno == EPIPE)
		die_via_sigpipe();

	/* otherwise die verbosely */
	if ((rp != NULL) ? is_non_fatal_redirect(rp->value, strlen(rp->value)) : is_non_fatal_std(fp))
		update_ERRNO_int(errno);
	else
		fatal(_("%s to \"%s\" failed: %s"), from,
			rp != NULL
				? rp->value
				: fp == stdout
					? _("standard output")
					: _("standard error"),
			errno ? strerror(errno) : _("reason unknown"));
}

/* efflush --- flush output with proper error handling */

void
efflush(FILE *fp, const char *from, struct redirect *rp)
{
	errno = 0;
	if (rp != NULL) {
		rp->output.gawk_fflush(fp, rp->output.opaque);
		if (rp->output.gawk_ferror(fp, rp->output.opaque))
			wrerror(fp, from, rp);
	} else {
		fflush(fp);
		if (ferror(fp))
			wrerror(fp, from, rp);
	}
}

/* efwrite --- like fwrite, but with error checking */

void
efwrite(const void *ptr,
	size_t size,
	size_t count,
	FILE *fp,
	const char *from,
	struct redirect *rp,
	bool flush)
{
	errno = 0;
	if (rp != NULL) {
		/*
		 * 7/2022: We need to also check ferror(); there can be times when write(2) fails but
		 * fwrite succeeds!  To do that, we make sure that rp->output.gawk_fwrite is not
		 * taken over by an extension before checking ferror().  From the bug report
		 * (https://lists.gnu.org/archive/html/bug-gawk/2022-07/msg00000.html):
		 *
		 * Minimal working example:
		 * yes | stdbuf -oL gawk '{print}' | head -n1 # Prints but hangs
		 * yes | stdbuf -o0 gawk '{print}' | head -n1 # OK
		 * yes | gawk '{print; fflush()}'  | head -n1 # OK
		 *
		 * After this change, all three work.
		 */
		bool err_on_write = (rp->output.gawk_fwrite(ptr, size, count, fp, rp->output.opaque) != count);
		bool err_on_fp = (rp->output.gawk_fwrite == gawk_fwrite && ferror(fp));

		if (err_on_write || err_on_fp) {
			wrerror(fp, from, rp);
			return;
		}
	} else if (fwrite(ptr, size, count, fp) != count || ferror(fp)) {
		wrerror(fp, from, rp);
		return;
	}
	if (flush
	  && ((fp == stdout && output_is_tty)
	      || (rp != NULL && (rp->flag & RED_FLUSH) != 0)))
		efflush(fp, from, rp);
}

/* do_exp --- exponential function */

NODE *
do_exp(int nargs)
{
	NODE *tmp;
	double d, res;

	check_exact_args(nargs, "exp", 1);

	tmp = POP_SCALAR();
	if (do_lint && (fixtype(tmp)->flags & NUMBER) == 0)
		lintwarn(_("%s: received non-numeric argument"), "exp");
	d = force_number(tmp)->numbr;
	DEREF(tmp);
	errno = 0;
	res = exp(d);
	if (errno == ERANGE)
		warning(_("exp: argument %g is out of range"), d);
	return make_number((AWKNUM) res);
}

/* stdfile --- return fp for a standard file */

/*
 * This function allows `fflush("/dev/stdout")' to work.
 * The other files will be available via getredirect().
 * /dev/stdin is not included, since fflush is only for output.
 */

static FILE *
stdfile(const char *name, size_t len)
{
	if (len == 11) {
		if (strncmp(name, "/dev/stderr", 11) == 0)
			return stderr;
		else if (strncmp(name, "/dev/stdout", 11) == 0)
			return stdout;
	}

	return NULL;
}

/* do_fflush --- flush output, either named file or pipe or everything */

NODE *
do_fflush(int nargs)
{
	struct redirect *rp;
	NODE *tmp;
	FILE *fp;
	int status = 0;
	const char *file;
	int len;

	/*
	 * November, 2012.
	 * It turns out that circa 2002, when BWK
	 * added fflush() and fflush("") to his awk, he made both of
	 * them flush everything.
	 *
	 * Now, with our inside agent getting ready to try to get fflush()
	 * standardized in POSIX, we are going to make our awk consistent
	 * with his.  This should not really affect anyone, as flushing
	 * everything also flushes stdout.
	 *
	 * So. Once upon a time:
	 * 	fflush()	--- flush stdout
	 * 	fflush("")	--- flush everything
	 * Now, both calls flush everything.
	 */

	check_args_min_max(nargs, "fflush", 0, 1);

	/* fflush() */
	if (nargs == 0) {
		status = flush_io();	// ERRNO updated
		return make_number((AWKNUM) status);
	}

	tmp = POP_STRING();
	if (do_lint && (fixtype(tmp)->flags & STRING) == 0)
		lintwarn(_("%s: received non-string argument"), "fflush");
	file = tmp->stptr;
	len = tmp->stlen;

	/* fflush("") */
	if (tmp->stlen == 0) {
		status = flush_io();	// ERRNO updated
		DEREF(tmp);
		return make_number((AWKNUM) status);
	}

	/* fflush("/some/path") */
	rp = getredirect(tmp->stptr, tmp->stlen);
	status = -1;
	if (rp != NULL) {
		if ((rp->flag & (RED_WRITE|RED_APPEND)) == 0) {
			if ((rp->flag & RED_PIPE) != 0)
				warning(_("fflush: cannot flush: pipe `%.*s' opened for reading, not writing"),
					len, file);
			else
				warning(_("fflush: cannot flush: file `%.*s' opened for reading, not writing"),
					len, file);
			DEREF(tmp);
			return make_number((AWKNUM) status);
		}
		fp = rp->output.fp;
		if (fp != NULL) {
			status = rp->output.gawk_fflush(fp, rp->output.opaque);

			if (status != 0) {
				if (! is_non_fatal_redirect(tmp->stptr, tmp->stlen))
					fatal(_("fflush: cannot flush file `%.*s': %s"),
						len, file, strerror(errno));
				update_ERRNO_int(errno);
			}
		} else if ((rp->flag & RED_TWOWAY) != 0)
				warning(_("fflush: cannot flush: two-way pipe `%.*s' has closed write end"),
					len, file);
	} else if ((fp = stdfile(tmp->stptr, tmp->stlen)) != NULL) {
		status = (non_fatal_flush_std_file(fp) == false);
	} else {
		status = -1;
		warning(_("fflush: `%.*s' is not an open file, pipe or co-process"), len, file);
	}
	DEREF(tmp);
	return make_number((AWKNUM) status);
}

/* strncasecmpmbs --- like strncasecmp (multibyte string version)  */

int
strncasecmpmbs(const unsigned char *s1, const unsigned char *s2, size_t n)
{
	size_t i1, i2, mbclen1, mbclen2, gap;
	char32_t wc1, wc2;
	mbstate_t mbs1, mbs2;

	memset(& mbs1, 0, sizeof(mbs1));
	memset(& mbs2, 0, sizeof(mbs2));

	for (i1 = i2 = 0 ; i1 < n && i2 < n ;i1 += mbclen1, i2 += mbclen2) {
		if (is_valid_character(s1[i1])) {
			mbclen1 = 1;
			wc1 = btowc_cache(s1[i1]);
		} else {
			mbclen1 = mbrtoc32(& wc1, (const char *)s1 + i1,
					  n - i1, & mbs1);
			if (mbclen1 == (size_t) -1 || mbclen1 == (size_t) -2 || mbclen1 == 0) {
				/* We treat it as a singlebyte character. */
				mbclen1 = 1;
				wc1 = btowc_cache(s1[i1]);
			}
		}
		if (is_valid_character(s2[i2])) {
			mbclen2 = 1;
			wc2 = btowc_cache(s2[i2]);
		} else {
			mbclen2 = mbrtoc32(& wc2, (const char *)s2 + i2,
					  n - i2, & mbs2);
			if (mbclen2 == (size_t) -1 || mbclen2 == (size_t) -2 || mbclen2 == 0) {
				/* We treat it as a singlebyte character. */
				mbclen2 = 1;
				wc2 = btowc_cache(s2[i2]);
			}
		}
		if ((gap = towlower(wc1) - towlower(wc2)) != 0)
			/* s1 and s2 are not equivalent. */
			return gap;
	}
	/* s1 and s2 are equivalent. */
	return 0;
}

/* Inspect the buffer `src' and write the index of each byte to `dest'.
   Caller must allocate `dest'.
   e.g. str = <mb1(1)>, <mb1(2)>, a, b, <mb2(1)>, <mb2(2)>, <mb2(3)>, c
        where mb(i) means the `i'-th byte of a multibyte character.
		dest =       1,        2, 1, 1,        1,        2,        3. 1
*/
static void
index_multibyte_buffer(char* src, char* dest, int len)
{
	int idx, prev_idx;
	mbstate_t mbs, prevs;

	memset(& prevs, 0, sizeof(mbstate_t));
	for (idx = prev_idx = 0 ; idx < len ; idx++) {
		size_t mbclen;
		mbs = prevs;
		mbclen = mbrlen(src + prev_idx, idx - prev_idx + 1, & mbs);
		if (mbclen == (size_t) -1 || mbclen == 1 || mbclen == 0) {
			/* singlebyte character.  */
			mbclen = 1;
			prev_idx = idx + 1;
		} else if (mbclen == (size_t) -2) {
			/* a part of a multibyte character.  */
			mbclen = idx - prev_idx + 1;
		} else if (mbclen > 1) {
			/* the end of a multibyte character.  */
			prev_idx = idx + 1;
			prevs = mbs;
		} else {
			/* Can't reach.  */
		}
		dest[idx] = mbclen;
    }
}

/* do_index --- find index of a string */

NODE *
do_index(int nargs)
{
	NODE *s1, *s2;
	const char *p1, *p2;
	size_t l1, l2;
	long ret;
	bool do_single_byte = false;
	mbstate_t mbs1, mbs2;

	check_exact_args(nargs, "index", 2);

	if (gawk_mb_cur_max > 1) {
		memset(& mbs1, 0, sizeof(mbstate_t));
		memset(& mbs2, 0, sizeof(mbstate_t));
	}

	POP_TWO_SCALARS(s1, s2);

	if (do_lint) {
		if ((fixtype(s1)->flags & (STRING|USER_INPUT)) == 0)
			lintwarn(_("%s: received non-string first argument"), "index");
		if ((fixtype(s2)->flags & (STRING|USER_INPUT)) == 0)
			lintwarn(_("%s: received non-string second argument"), "index");
	}

	s1 = force_string(s1);
	s2 = force_string(s2);

	p1 = s1->stptr;
	p2 = s2->stptr;
	l1 = s1->stlen;
	l2 = s2->stlen;
	ret = 0;

	/*
	 * Icky special case, index(foo, "") should return 1,
	 * since both bwk awk and mawk do, and since match("foo", "")
	 * returns 1. This makes index("", "") work, too, fwiw.
	 */
	if (l2 == 0) {
		ret = 1;
		goto out;
	}

	if (gawk_mb_cur_max > 1) {
		s1 = force_wstring(s1);
		s2 = force_wstring(s2);
		/*
		 * If we don't have valid wide character strings, use
		 * the real bytes.
		 */
		do_single_byte = ((s1->wstlen == 0 && s1->stlen > 0)
					|| (s2->wstlen == 0 && s2->stlen > 0));
	}

	/* IGNORECASE will already be false if posix */
	if (IGNORECASE) {
		while (l1 > 0) {
			if (l2 > l1)
				break;
			if (! do_single_byte && gawk_mb_cur_max > 1) {
				const char32_t *pos;

				pos = wcasestrstr(s1->wstptr, s1->wstlen, s2->wstptr, s2->wstlen);
				if (pos == NULL)
					ret = 0;
				else
					ret = pos - s1->wstptr + 1;	/* 1-based */
				goto out;
			} else {
				/*
				 * Could use tolower(*p1) == tolower(*p2) here.
				 * See discussion in eval.c as to why not.
				 */
				if (casetable[(unsigned char)*p1] == casetable[(unsigned char)*p2]
				    && (l2 == 1 || strncasecmp(p1, p2, l2) == 0)) {
					ret = 1 + s1->stlen - l1;
					break;
				}
				l1--;
				p1++;
			}
		}
	} else {
		while (l1 > 0) {
			if (l2 > l1)
				break;
			if (*p1 == *p2
			    && (l2 == 1 || (l2 > 0 && memcmp(p1, p2, l2) == 0))) {
				ret = 1 + s1->stlen - l1;
				break;
			}
			if (! do_single_byte && gawk_mb_cur_max > 1) {
				const char32_t *pos;

				pos = wstrstr(s1->wstptr, s1->wstlen, s2->wstptr, s2->wstlen);
				if (pos == NULL)
					ret = 0;
				else
					ret = pos - s1->wstptr + 1;	/* 1-based */
				goto out;
			} else {
				l1--;
				p1++;
			}
		}
	}
out:
	DEREF(s1);
	DEREF(s2);
	return make_number((AWKNUM) ret);
}

/* double_to_int --- convert double to int, used several places */

double
double_to_int(double d)
{
	if (d >= 0)
		d = floor(d);
	else
		d = ceil(d);
	return d;
}

/* do_int --- convert double to int for awk */

NODE *
do_int(int nargs)
{
	NODE *tmp;
	double d;

	check_exact_args(nargs, "int", 1);

	tmp = POP_SCALAR();
	if (do_lint && (fixtype(tmp)->flags & NUMBER) == 0)
		lintwarn(_("%s: received non-numeric argument"), "int");
	d = force_number(tmp)->numbr;
	d = double_to_int(d);
	DEREF(tmp);
	return make_number((AWKNUM) d);
}

/* do_isarray --- check if argument is array */

NODE *
do_isarray(int nargs)
{
	NODE *tmp;
	int ret = 1;

	check_exact_args(nargs, "isarray", 1);

	tmp = POP();

	if (tmp->type == Node_param_list) {
		tmp = GET_PARAM(tmp->param_cnt);
		if (tmp->type == Node_array_ref) {
			tmp = tmp->orig_array;
		}
	}

	if (tmp->type != Node_var_array) {
		ret = 0;
		// could be Node_var_new
		if (tmp->type == Node_val)
			DEREF(tmp);
	}
	return make_number((AWKNUM) ret);
}

/* do_length --- length of a string, array or $0 */

NODE *
do_length(int nargs)
{
	NODE *tmp;
	size_t len;

	check_exact_args(nargs, "length", 1);

	tmp = POP();

	// As of the 2024 POSIX standard, length(array) is standardized. Yay!
	if (tmp->type == Node_var_array) {
		unsigned long size;

		/*
		 * Support for deferred loading of array elements requires that
		 * we use the array length interface even though it isn't
		 * necessary for the built-in array types.
		 *
		 * 1/2015: The deferred arrays are gone, but this is probably
		 * still a good idea.
		 */

		size = assoc_length(tmp);
		return make_number(size);
	} else if (tmp->type == Node_var_new || tmp->type == Node_elem_new) {
		// this can happen from an indirect call
		DEREF(tmp);
		tmp = dupnode(Nnull_string);
	}

	assert(tmp->type == Node_val);

	if (do_lint && (fixtype(tmp)->flags & (STRING|USER_INPUT)) == 0)
		lintwarn(_("%s: received non-string argument"), "length");
	tmp = force_string(tmp);

	if (gawk_mb_cur_max > 1) {
		tmp = force_wstring(tmp);
		len = tmp->wstlen;
		/*
		 * If the bytes don't make a valid wide character
		 * string, fall back to the bytes themselves.
		 */
		 if (len == 0 && tmp->stlen > 0)
			 len = tmp->stlen;
	} else
		len = tmp->stlen;

	DEREF(tmp);
	return make_number((AWKNUM) len);
}

/* do_log --- the log function */

NODE *
do_log(int nargs)
{
	NODE *tmp;
	double d, arg;

	check_exact_args(nargs, "log", 1);

	tmp = POP_SCALAR();
	if (do_lint && (fixtype(tmp)->flags & NUMBER) == 0)
		lintwarn(_("%s: received non-numeric argument"), "log");
	arg = force_number(tmp)->numbr;
	if (arg < 0.0)
		warning(_("%s: received negative argument %g"), "log", arg);
	d = log(arg);
	DEREF(tmp);
	return make_number((AWKNUM) d);
}

/* do_sqrt --- do the sqrt function */

NODE *
do_sqrt(int nargs)
{
	NODE *tmp;
	double arg;

	check_exact_args(nargs, "sqrt", 1);

	tmp = POP_SCALAR();
	if (do_lint && (fixtype(tmp)->flags & NUMBER) == 0)
		lintwarn(_("%s: received non-numeric argument"), "sqrt");
	arg = (double) force_number(tmp)->numbr;
	DEREF(tmp);
	if (arg < 0.0)
		warning(_("%s: received negative argument %g"), "sqrt", arg);
	return make_number((AWKNUM) sqrt(arg));
}

/* do_substr --- do the substr function */

NODE *
do_substr(int nargs)
{
	NODE *t1;
	NODE *r;
	size_t indx;
	size_t length = 0;
	double d_index = 0, d_length = 0;
	size_t src_len;

	check_args_min_max(nargs, "substr", 2, 3);

	if (nargs == 3) {
		t1 = POP_NUMBER();
		if (do_lint && (fixtype(t1)->flags & NUMBER) == 0)
			lintwarn(_("%s: received non-numeric third argument"), "substr");
		d_length = get_number_d(t1);
		DEREF(t1);
	}

	t1 = POP_NUMBER();
	if (do_lint && (fixtype(t1)->flags & NUMBER) == 0)
		lintwarn(_("%s: received non-numeric second argument"), "substr");
	d_index = get_number_d(t1);
	DEREF(t1);

	t1 = POP_STRING();
	if (do_lint && (fixtype(t1)->flags & (STRING|USER_INPUT)) == 0)
		lintwarn(_("%s: received non-string first argument"), "substr");

	if (nargs == 3) {
		if (! (d_length >= 1)) {
			if (do_lint == DO_LINT_ALL)
				lintwarn(_("substr: length %g is not >= 1"), d_length);
			else if (do_lint == DO_LINT_INVALID && ! (d_length >= 0))
				lintwarn(_("substr: length %g is not >= 0"), d_length);
			DEREF(t1);
			/*
			 * Return explicit null string instead of doing
			 * dupnode(Nnull_string) so that if the result
			 * is checked with the combination of length()
			 * and lint, no error is reported about using
			 * an uninitialized value. Same thing later, too.
			 */
			return make_string("", 0);
		}
		if (do_lint) {
			if (double_to_int(d_length) != d_length)
				lintwarn(
			_("substr: non-integer length %g will be truncated"),
					d_length);

			if (d_length > (double) SIZE_MAX)
				lintwarn(
			_("substr: length %g too big for string indexing, truncating to %g"),
					d_length, (double) SIZE_MAX);
		}
		if (d_length < (double) SIZE_MAX)
			length = d_length;
		else
			length = SIZE_MAX;
	}

	/* the weird `! (foo)' tests help catch NaN values. */
	if (! (d_index >= 1)) {
		if (do_lint)
			lintwarn(_("substr: start index %g is invalid, using 1"),
				 d_index);
		d_index = 1;
	}
	if (do_lint && double_to_int(d_index) != d_index)
		lintwarn(_("substr: non-integer start index %g will be truncated"),
			 d_index);

	/* awk indices are from 1, C's are from 0 */
	if (d_index <= (double) SIZE_MAX)
		indx = d_index - 1;
	else
		indx = SIZE_MAX;

	if (nargs == 2) {	/* third arg. missing */
		/* use remainder of string */
		length = t1->stlen - indx;	/* default to bytes */
		if (gawk_mb_cur_max > 1) {
			t1 = force_wstring(t1);
			if (t1->wstlen > 0)	/* use length of wide char string if we have one */
				length = t1->wstlen - indx;
		}
		d_length = length;	/* set here in case used in diagnostics, below */
	}

	if (t1->stlen == 0) {
		/* substr("", 1, 0) produces a warning only if LINT_ALL */
		if (do_lint && (do_lint == DO_LINT_ALL || ((indx | length) != 0)))
			lintwarn(_("substr: source string is zero length"));
		DEREF(t1);
		return make_string("", 0);
	}

	/* get total len of input string, for following checks */
	if (gawk_mb_cur_max > 1) {
		t1 = force_wstring(t1);
		src_len = t1->wstlen;
	} else
		src_len = t1->stlen;

	if (indx >= src_len) {
		if (do_lint)
			lintwarn(_("substr: start index %g is past end of string"),
				d_index);
		DEREF(t1);
		return make_string("", 0);
	}
	if (length > src_len - indx) {
		if (do_lint)
			lintwarn(
	_("substr: length %g at start index %g exceeds length of first argument (%lu)"),
			d_length, d_index, (unsigned long int) src_len);
		length = src_len - indx;
	}

	/* force_wstring() already called */
	if (gawk_mb_cur_max == 1 || t1->wstlen == t1->stlen)
		/* single byte case */
		r = make_string(t1->stptr + indx, length);
	else {
		/* multibyte case, more work */
		size_t result;
		char32_t *wp;
		mbstate_t mbs;
		char *substr, *cp;

		/*
		 * Convert the wide chars in t1->wstptr back into m.b. chars.
		 * This is pretty grotty, but it's the most straightforward
		 * way to do things.
		 */
		memset(& mbs, 0, sizeof(mbs));
		emalloc(substr, char *, (length * gawk_mb_cur_max) + 1);
		wp = t1->wstptr + indx;
		for (cp = substr; length > 0; length--) {
			result = c32rtomb(cp, *wp, & mbs);
			if (result == (size_t) -1)	/* what to do? break seems best */
				break;
			cp += result;
			wp++;
		}
		*cp = '\0';
		r = make_str_node(substr, cp - substr, ALREADY_MALLOCED);
	}

	DEREF(t1);
	return r;
}

/* do_strftime --- format a time stamp */

NODE *
do_strftime(int nargs)
{
	NODE *t1, *t2, *t3, *ret;
	struct tm *tm;
	time_t fclock;
	double clock_val;
	char *bufp;
	size_t buflen, bufsize;
	char buf[BUFSIZ];
	const char *format;
	int formatlen;
	bool do_gmt;
	NODE *val = NULL;
	NODE *sub = NULL;
	char save = '\0';	// initialize to avoid compiler warnings
	static const time_t time_t_min = TYPE_MINIMUM(time_t);
	static const time_t time_t_max = TYPE_MAXIMUM(time_t);

	/* set defaults first */
	format = def_strftime_format;	/* traditional date format */
	formatlen = strlen(format);
	(void) time(& fclock);	/* current time of day */
	do_gmt = false;

	check_args_min_max(nargs, "strftime", 0, 3);

	if (PROCINFO_node != NULL) {
		sub = make_string("strftime", 8);
		val = in_array(PROCINFO_node, sub);
		unref(sub);

		if (val != NULL) {
			if (do_lint && (fixtype(val)->flags & (STRING|USER_INPUT)) == 0)
				lintwarn(_("strftime: format value in PROCINFO[\"strftime\"] has numeric type"));
			val = force_string(val);
			format = val->stptr;
			formatlen = val->stlen;
		}
	}

	t1 = t2 = t3 = NULL;
	if (nargs > 0) {	/* have args */
		NODE *tmp;

		if (nargs == 3) {
			t3 = POP_SCALAR();
			do_gmt = boolval(t3);
			// no lint check, we allow number or string to give us a boolean value
			DEREF(t3);
		}

		if (nargs >= 2) {
			t2 = POP_SCALAR();
			if (do_lint && (fixtype(t2)->flags & NUMBER) == 0)
				lintwarn(_("%s: received non-numeric second argument"), "strftime");
			(void) force_number(t2);
			clock_val = get_number_d(t2);
			fclock = (time_t) clock_val;
			/*
			 * Protect against negative value being assigned
			 * to unsigned time_t.
			 */
			if (clock_val < 0 && fclock > 0) {
				if (do_lint)
					lintwarn(_("strftime: second argument less than 0 or too big for time_t"));
				return make_string("", 0);
			}

			/* And check that the value is in range */
			if (clock_val < time_t_min || clock_val > time_t_max) {
				if (do_lint)
					lintwarn(_("strftime: second argument out of range for time_t"));
				return make_string("", 0);
			}

			DEREF(t2);
		}

		tmp = POP_SCALAR();
		if (do_lint && (fixtype(tmp)->flags & STRING) == 0)
			lintwarn(_("%s: received non-string first argument"), "strftime");

		t1 = force_string(tmp);
		format = t1->stptr;
		formatlen = t1->stlen;
		if (formatlen == 0) {
			if (do_lint)
				lintwarn(_("strftime: received empty format string"));
			DEREF(t1);
			return make_string("", 0);
		}
		str_terminate(t1, save);
	}

	if (do_gmt)
		tm = gmtime(& fclock);
	else
		tm = localtime(& fclock);

	if (tm == NULL) {
		ret = make_string("", 0);
		goto done;
	}

	bufp = buf;
	bufsize = sizeof(buf);
	for (;;) {
		*bufp = '\0';
		buflen = strftime(bufp, bufsize, format, tm);
		/*
		 * buflen can be zero EITHER because there's not enough
		 * room in the string, or because the control command
		 * goes to the empty string. Make a reasonable guess that
		 * if the buffer is 1024 times bigger than the length of the
		 * format string, it's not failing for lack of room.
		 * Thanks to Paul Eggert for pointing out this issue.
		 */
		if (buflen > 0 || bufsize >= 1024 * formatlen)
			break;
		bufsize *= 2;
		if (bufp == buf)
			emalloc(bufp, char *, bufsize);
		else
			erealloc(bufp, char *, bufsize);
	}
	ret = make_string(bufp, buflen);
	if (bufp != buf)
		efree(bufp);
done:
	if (t1) {
		str_restore(t1, save);
		DEREF(t1);
	}
	return ret;
}

/* do_systime --- get the time of day */

NODE *
do_systime(int nargs ATTRIBUTE_UNUSED)
{
	time_t lclock;

	check_exact_args(nargs, "systime", 0);

#ifdef HAVE_CLOCK_GETTIME
	struct timespec the_time;

	(void) clock_gettime(CLOCK_REALTIME, & the_time);
	lclock = the_time.tv_sec;
#elif defined(HAVE_GETTIMEOFDAY)
	struct timeval the_time;

	(void) gettimeofday(& the_time, NULL);
	lclock = the_time.tv_sec;
#else
	(void) time(& lclock);
#endif
	return make_number((AWKNUM) lclock);
}

/* do_mktime --- turn a time string into a timestamp */

NODE *
do_mktime(int nargs)
{
	NODE *t1, *t2;
	struct tm then;
	long year;
	int month, day, hour, minute, second, count;
	int dst = -1; /* default is unknown */
	time_t then_stamp;
	char save;
	bool do_gmt;

	check_args_min_max(nargs, "mktime", 1, 2);

	if (nargs == 2) {
		t2 = POP_SCALAR();
		do_gmt = boolval(t2);
		DEREF(t2);
	}
	else
		do_gmt = false;
	t1 = POP_SCALAR();
	if (do_lint && (fixtype(t1)->flags & STRING) == 0)
		lintwarn(_("%s: received non-string argument"), "mktime");
	t1 = force_string(t1);

	save = t1->stptr[t1->stlen];
	t1->stptr[t1->stlen] = '\0';

	count = sscanf(t1->stptr, "%ld %d %d %d %d %d %d",
		        & year, & month, & day,
			& hour, & minute, & second,
		        & dst);

	// 9/2021: I've been told that according to the ISO 8601-1:2019 spec,
	// hour cannot be 24. So the check for hour > 23 is valid.
	if (   do_lint /* Ready? Set! Go: */
	    && (   (second < 0 || second > 60)
		|| (minute < 0 || minute > 59)
		|| (hour < 0 || hour > 23)
		|| (day < 1 || day > 31)
		|| (month < 1 || month > 12) ))
			lintwarn(_("mktime: at least one of the values is out of the default range"));

	t1->stptr[t1->stlen] = save;
	DEREF(t1);

	if (count < 6
	    || month == INT_MIN
	    || year < INT_MIN + 1900
	    || year - 1900 > INT_MAX)
		return make_number((AWKNUM) -1);

	memset(& then, '\0', sizeof(then));
	then.tm_sec = second;
	then.tm_min = minute;
	then.tm_hour = hour;
	then.tm_mday = day;
	then.tm_mon = month - 1;
	then.tm_year = year - 1900;
	then.tm_isdst = dst;

	then_stamp = (do_gmt ? timegm(& then) : mktime(& then));
	return make_number((AWKNUM) then_stamp);
}

/* do_system --- run an external command */

NODE *
do_system(int nargs)
{
	NODE *tmp;
	AWKNUM ret = 0;		/* floating point on purpose, compat Unix awk */
	char *cmd;
	char save;
	int status;

	check_exact_args(nargs, "system", 1);

	if (do_sandbox)
		fatal(_("'system' function not allowed in sandbox mode"));

	(void) flush_io();     /* so output is synchronous with gawk's */
	tmp = POP_SCALAR();
	if (do_lint && (fixtype(tmp)->flags & STRING) == 0)
		lintwarn(_("%s: received non-string argument"), "system");
	cmd = force_string(tmp)->stptr;

	if (cmd && *cmd) {
		/* insure arg to system is zero-terminated */
		save = cmd[tmp->stlen];
		cmd[tmp->stlen] = '\0';

		os_restore_mode(fileno(stdin));

		status = gawk_system(cmd);
		/*
		 * 3/2016. What to do with ret? It's never simple.
		 * POSIX says to use the full return value. BWK awk
		 * divides the result by 256.  That normally gives the
		 * exit status but gives a weird result for death-by-signal.
		 * So we compromise as follows:
		 *
		 * 7/2025. BWK awk now does what we do to sanitize the
		 * status.  I removed the MinGW code for do_traditional
		 * since we no longer care about that option here.
		 */
		ret = status;
		if (status != -1 && ! do_posix)
			ret = sanitize_exit_status(status);

		if ((BINMODE & BINMODE_INPUT) != 0)
			os_setbinmode(fileno(stdin), O_BINARY);

		cmd[tmp->stlen] = save;
	}
	DEREF(tmp);
	return make_number((AWKNUM) ret);
}

/* do_print --- print items, separated by OFS, terminated with ORS */

void
do_print(int nargs, int redirtype)
{
	struct redirect *rp = NULL;
	int errflg = 0;
	FILE *fp = NULL;
	int i;
	NODE *redir_exp = NULL;
	NODE *tmp = NULL;

	assert(nargs <= max_args);

	if (redirtype != 0) {
		redir_exp = PEEK(nargs);
		redir_exp = elem_new_to_scalar(redir_exp);
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
				fatal(_("print: attempt to write to closed write end of two-way pipe"));
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

	for (i = 1; i <= nargs; i++) {
		tmp = args_array[i] = POP();
		if (tmp->type == Node_var_array) {
			while (--i > 0)
				DEREF(args_array[i]);
			fatal(_("attempt to use array `%s' in a scalar context"), array_vname(tmp));
		}
		// Let force_string_ofmt handle checking if things
		// are already valid.
		args_array[i] = force_string_ofmt(tmp);
		if (args_array[i] != tmp)
			DEREF(tmp);
	}

	if (redir_exp != NULL) {
		DEREF(redir_exp);
		decr_sp();
	}

	if (fp == NULL) {
		for (i = nargs; i > 0; i--)
			DEREF(args_array[i]);
		return;
	}

	for (i = nargs; i > 0; i--) {
		efwrite(args_array[i]->stptr, sizeof(char), args_array[i]->stlen, fp, "print", rp, false);
		DEREF(args_array[i]);
		if (i != 1 && OFSlen > 0)
			efwrite(OFS, sizeof(char), (size_t) OFSlen,
				fp, "print", rp, false);

	}
	if (ORSlen > 0)
		efwrite(ORS, sizeof(char), (size_t) ORSlen, fp, "print", rp, true);

	if (rp != NULL && (rp->flag & RED_TWOWAY) != 0)
		rp->output.gawk_fflush(rp->output.fp, rp->output.opaque);
}

/* do_print_rec --- special case printing of $0, for speed */

void
do_print_rec(int nargs, int redirtype)
{
	FILE *fp = NULL;
	NODE *f0;
	struct redirect *rp = NULL;
	int errflg = 0;
	NODE *redir_exp = NULL;

	assert(nargs == 0);
	if (redirtype != 0) {
		redir_exp = TOP();
		rp = redirect(redir_exp, redirtype, & errflg, true);
		if (rp != NULL) {
			if ((rp->flag & RED_TWOWAY) != 0 && rp->output.fp == NULL) {
				if (is_non_fatal_redirect(redir_exp->stptr, redir_exp->stlen)) {
					update_ERRNO_int(EBADF);
					return;
				}
				(void) close_rp(rp, CLOSE_ALL);
				fatal(_("print: attempt to write to closed write end of two-way pipe"));
			}
			fp = rp->output.fp;
		}
		DEREF(redir_exp);
		decr_sp();
	} else
		fp = output_fp;

	if (errflg) {
		update_ERRNO_int(errflg);
		return;
	}

	if (fp == NULL)
		return;

	if (! field0_valid || do_lint)	// lint check for field access in END
		(void) get_field(0L, NULL);

	f0 = fields_arr[0];

	if (do_lint && (f0->flags & NULL_FIELD) != 0)
		lintwarn(_("reference to uninitialized field `$%d'"), 0);

	efwrite(f0->stptr, sizeof(char), f0->stlen, fp, "print", rp, false);

	if (ORSlen > 0)
		efwrite(ORS, sizeof(char), (size_t) ORSlen, fp, "print", rp, true);

	if (rp != NULL && (rp->flag & RED_TWOWAY) != 0)
		rp->output.gawk_fflush(rp->output.fp, rp->output.opaque);
}


/* is_wupper --- function version of iswupper for passing function pointers */

static int
is_wupper(char32_t c)
{
	return iswupper(c);
}

/* is_wlower --- function version of iswlower for passing function pointers */

static int
is_wlower(char32_t c)
{
	return iswlower(c);
}

/* to_wupper --- function version of towupper for passing function pointers */

static int
to_wlower(char32_t c)
{
	return towlower(c);
}

/* to_wlower --- function version of towlower for passing function pointers */

static int
to_wupper(char32_t c)
{
	return towupper(c);
}

/* wide_change_case --- generic case converter for wide characters */

static void
wide_change_case(char32_t *wstr,
			size_t wlen,
			int (*is_x)(char32_t c),
			int (*to_y)(char32_t c))
{
	size_t i;
	char32_t *wcp;

	for (i = 0, wcp = wstr; i < wlen; i++, wcp++)
		if (is_x(*wcp))
			*wcp = to_y(*wcp);
}

/* wide_toupper --- map a wide string to upper case */

static void
wide_toupper(char32_t *wstr, size_t wlen)
{
	wide_change_case(wstr, wlen, is_wlower, to_wupper);
}

/* wide_tolower --- map a wide string to lower case */

static void
wide_tolower(char32_t *wstr, size_t wlen)
{
	wide_change_case(wstr, wlen, is_wupper, to_wlower);
}

/* do_tolower --- lower case a string */

NODE *
do_tolower(int nargs)
{
	NODE *t1, *t2;

	check_exact_args(nargs, "tolower", 1);

	t1 = POP_SCALAR();
	if (do_lint && (fixtype(t1)->flags & STRING) == 0)
		lintwarn(_("%s: received non-string argument"), "tolower");
	t1 = force_string(t1);
	t2 = make_string(t1->stptr, t1->stlen);

	if (gawk_mb_cur_max == 1) {
		unsigned char *cp, *cp2;

		for (cp = (unsigned char *)t2->stptr,
		     cp2 = (unsigned char *)(t2->stptr + t2->stlen);
			cp < cp2; cp++)
			if (isupper(*cp))
				*cp = tolower(*cp);
	} else {
		force_wstring(t2);
		wide_tolower(t2->wstptr, t2->wstlen);
		wstr2str(t2);
	}

	DEREF(t1);
	return t2;
}

/* do_toupper --- upper case a string */

NODE *
do_toupper(int nargs)
{
	NODE *t1, *t2;

	check_exact_args(nargs, "toupper", 1);

	t1 = POP_SCALAR();
	if (do_lint && (fixtype(t1)->flags & STRING) == 0)
		lintwarn(_("%s: received non-string argument"), "toupper");
	t1 = force_string(t1);
	t2 = make_string(t1->stptr, t1->stlen);

	if (gawk_mb_cur_max == 1) {
		unsigned char *cp, *cp2;

		for (cp = (unsigned char *)t2->stptr,
		     cp2 = (unsigned char *)(t2->stptr + t2->stlen);
			cp < cp2; cp++)
			if (islower(*cp))
				*cp = toupper(*cp);
	} else {
		force_wstring(t2);
		wide_toupper(t2->wstptr, t2->wstlen);
		wstr2str(t2);
	}

	DEREF(t1);
	return t2;
}

/* do_atan2 --- do the atan2 function */

NODE *
do_atan2(int nargs)
{
	NODE *t1, *t2;
	double d1, d2;

	check_exact_args(nargs, "atan2", 2);

	POP_TWO_SCALARS(t1, t2);
	if (do_lint) {
		if ((fixtype(t1)->flags & NUMBER) == 0)
			lintwarn(_("%s: received non-numeric first argument"), "atan2");
		if ((fixtype(t2)->flags & NUMBER) == 0)
			lintwarn(_("%s: received non-numeric second argument"), "atan2");
	}
	d1 = force_number(t1)->numbr;
	d2 = force_number(t2)->numbr;
	DEREF(t1);
	DEREF(t2);
	return make_number((AWKNUM) atan2(d1, d2));
}

/* do_sin --- do the sin function */

NODE *
do_sin(int nargs)
{
	NODE *tmp;
	double d;

	check_exact_args(nargs, "sin", 1);

	tmp = POP_SCALAR();
	if (do_lint && (fixtype(tmp)->flags & NUMBER) == 0)
		lintwarn(_("%s: received non-numeric argument"), "sin");
	d = sin((double) force_number(tmp)->numbr);
	DEREF(tmp);
	return make_number((AWKNUM) d);
}

/* do_cos --- do the cos function */

NODE *
do_cos(int nargs)
{
	NODE *tmp;
	double d;

	check_exact_args(nargs, "cos", 1);

	tmp = POP_SCALAR();
	if (do_lint && (fixtype(tmp)->flags & NUMBER) == 0)
		lintwarn(_("%s: received non-numeric argument"), "cos");
	d = cos((double) force_number(tmp)->numbr);
	DEREF(tmp);
	return make_number((AWKNUM) d);
}

/* do_rand --- do the rand function */

static bool firstrand = true;
/* Some systems require this array to be integer aligned. Sigh. */
#define SIZEOF_STATE 256
static uint32_t istate[SIZEOF_STATE/sizeof(uint32_t)];
static char *const state = (char *const) istate;

/* ARGSUSED */
NODE *
do_rand(int nargs ATTRIBUTE_UNUSED)
{
	double tmprand;

	check_exact_args(nargs, "rand", 0);

#define RAND_DIVISOR ((double)GAWK_RANDOM_MAX+1.0)
	if (firstrand) {
		(void) initstate((unsigned) 1, state, SIZEOF_STATE);
		/* don't need to srandom(1), initstate() does it for us. */
		firstrand = false;
		setstate(state);
	}
	/*
	 * Per historical practice and POSIX, return value N is
	 *
	 * 	0 <= n < 1
	 */
 	/*
	 * Date: Wed, 28 Aug 2013 17:52:46 -0700
	 * From: Bob Jewett <jewett@bill.scs.agilent.com>
	 *
 	 * Call random() twice to fill in more bits in the value
 	 * of the double.  Also, there is a bug in random() such
 	 * that when the values of successive values are combined
 	 * like (rand1*rand2)^2, (rand3*rand4)^2,  ...  the
 	 * resulting time series is not white noise.  The
 	 * following also seems to fix that bug.
 	 *
 	 * The add/subtract 0.5 keeps small bits from filling
 	 * below 2^-53 in the double, not that anyone should be
 	 * looking down there.
	 *
	 * Date: Wed, 25 Sep 2013 10:45:38 -0600 (MDT)
	 * From: "Nelson H. F. Beebe" <beebe@math.utah.edu>
	 * (4) The code is typical of many published fragments for converting
	 *     from integer to floating-point, and I discuss the serious pitfalls
	 *     in my book, because it leads to platform-dependent behavior at the
	 *     end points of the interval [0,1]
	 *
	 * (5) the documentation in the gawk info node says
	 *
	 *     `rand()'
	 * 	 Return a random number.  The values of `rand()' are uniformly
	 * 	 distributed between zero and one.  The value could be zero but is
	 * 	 never one.(1)
	 *
	 *     The division by RAND_DIVISOR may not guarantee that 1.0 is never
	 *     returned: the programmer forgot the platform-dependent issue of
	 *     rounding.
	 *
	 * For points 4 and 5, the safe way is a loop:
	 *
	 *         double
	 * 	   rand(void)		// return value in [0.0, 1.0)
	 *         {
	 * 	    value = internal_rand();
	 *
	 * 	    while (value == 1.0)
	 *                 value = internal_rand();
	 *
	 * 	    return (value);
	 *         }
 	 */

	do {
		long d1, d2;
		/*
		 * Do the calls in predictable order to avoid
		 * compiler differences in order of evaluation.
		 */
		d1 = random();
		d2 = random();
	 	tmprand = 0.5 + ( (d1/RAND_DIVISOR + d2) / RAND_DIVISOR );
		tmprand -= 0.5;
	} while (tmprand == 1.0);

 	return make_number((AWKNUM) tmprand);
}

/* do_srand --- seed the random number generator */

NODE *
do_srand(int nargs)
{
	NODE *tmp;
	static long save_seed = 1;
	long ret = save_seed;	/* SVR4 awk srand returns previous seed */

	if (firstrand) {
		(void) initstate((unsigned) 1, state, SIZEOF_STATE);
		/* don't need to srandom(1), we're changing the seed below */
		firstrand = false;
		(void) setstate(state);
	}

	check_args_min_max(nargs, "srand", 0, 1);

	if (nargs == 0)
		srandom((unsigned int) (save_seed = (unsigned long) time((time_t *) 0)));
	else {
		tmp = POP_SCALAR();
		if (do_lint && (fixtype(tmp)->flags & NUMBER) == 0)
			lintwarn(_("%s: received non-numeric argument"), "srand");
		srandom((unsigned int) (save_seed = (unsigned long) force_number(tmp)->numbr));
		DEREF(tmp);
	}
	return make_number((AWKNUM) ret);
}

/* do_match --- match a regexp, set RSTART and RLENGTH,
 * 	optional third arg is array filled with text of
 * 	subpatterns enclosed in parens and start and len info.
 */

NODE *
do_match(int nargs)
{
	NODE *tre, *t1, *dest, *it;
	int rstart, len, ii;
	int rlength;
	Regexp *rp;
	ssize_t s;
	char *start;
	char *buf = NULL;
	char buff[100];
	size_t amt, oldamt = 0, ilen, slen;
	char *subsepstr;
	size_t subseplen;

	check_args_min_max(nargs, "match", 2, 3);

	dest = NULL;
	if (nargs == 3) {	/* 3rd optional arg for the subpatterns */
		dest = POP_PARAM();
		if (dest->type != Node_var_array)
			fatal(_("match: third argument is not an array"));
		check_symtab_functab(dest, "match",
				_("%s: cannot use %s as third argument"));
		assoc_clear(dest);
	}
	tre = POP();
	rp = re_update(tre);
	t1 = POP_STRING();
	if (do_lint && (fixtype(t1)->flags & (STRING|USER_INPUT)) == 0)
		lintwarn(_("%s: received non-string first argument"), "match");

	rstart = research(rp, t1->stptr, 0, t1->stlen, RE_NEED_START|RE_NEED_SUB);
	if (rstart >= 0) {	/* match succeeded */
		size_t *wc_indices = NULL;

		rlength = REEND(rp, t1->stptr) - RESTART(rp, t1->stptr);	/* byte length */
		if (gawk_mb_cur_max > 1) {
			t1 = str2wstr(t1, & wc_indices);
			rlength = wc_indices[rstart + rlength] - wc_indices[rstart];
			rstart = wc_indices[rstart];
		}

		rstart++;	/* now it's 1-based indexing */

		/* Build the array only if the caller wants the optional subpatterns */
		if (dest != NULL) {
			subsepstr = SUBSEP_node->var_value->stptr;
			subseplen = SUBSEP_node->var_value->stlen;

			for (ii = 0; ii < NUMSUBPATS(rp, t1->stptr); ii++) {
				/*
				 * Loop over all the subpats; some of them may have
				 * matched even if all of them did not.
				 */
				if ((s = SUBPATSTART(rp, t1->stptr, ii)) != -1) {
					size_t subpat_start;
					size_t subpat_len;

					start = t1->stptr + s;
					subpat_start = s;
					subpat_len = len = SUBPATEND(rp, t1->stptr, ii) - s;
					if (gawk_mb_cur_max > 1) {
						subpat_start = wc_indices[s];
						subpat_len = wc_indices[s + len] - subpat_start;
					}

					it = make_string(start, len);
					it->flags |= USER_INPUT;
					assoc_set(dest, make_number((AWKNUM) (ii)), it);;

					sprintf(buff, "%d", ii);
					ilen = strlen(buff);
					amt = ilen + subseplen + strlen("length") + 1;

					if (oldamt == 0) {
						emalloc(buf, char *, amt);
					} else if (amt > oldamt) {
						erealloc(buf, char *, amt);
					}
					oldamt = amt;
					memcpy(buf, buff, ilen);
					memcpy(buf + ilen, subsepstr, subseplen);
					memcpy(buf + ilen + subseplen, "start", 6);

					slen = ilen + subseplen + 5;

					assoc_set(dest, make_string(buf, slen), make_number((AWKNUM) subpat_start + 1));

					memcpy(buf, buff, ilen);
					memcpy(buf + ilen, subsepstr, subseplen);
					memcpy(buf + ilen + subseplen, "length", 7);

					slen = ilen + subseplen + 6;

					assoc_set(dest, make_string(buf, slen), make_number((AWKNUM) subpat_len));
				}
			}

			efree(buf);
		}
		if (wc_indices != NULL)
			efree(wc_indices);
	} else {		/* match failed */
		rstart = 0;
		rlength = -1;
	}

	DEREF(t1);
	// Someone used $0 as the second parameter. We have to treat
	// it with extra TLC.
	if (tre->type == Node_dynregex
	    && tre->re_exp->valref > 1
	    && (tre->re_exp->flags & MALLOC) == 0) {
		unref(tre->re_exp);
		tre->re_exp = NULL;
	}
	unref(RSTART_node->var_value);
	RSTART_node->var_value = make_number((AWKNUM) rstart);
	unref(RLENGTH_node->var_value);
	RLENGTH_node->var_value = make_number((AWKNUM) rlength);
	return make_number((AWKNUM) rstart);
}

/* do_sub --- do the work for sub, gsub, and gensub */

/*
 * Gsub can be tricksy; particularly when handling the case of null strings.
 * The following awk code was useful in debugging problems.  It is too bad
 * that it does not readily translate directly into the C code, below.
 *
 * #! /usr/local/bin/mawk -f
 *
 * BEGIN {
 * 	true = 1; false = 0
 * 	print "--->", mygsub("abc", "b+", "FOO")
 * 	print "--->", mygsub("abc", "x*", "X")
 * 	print "--->", mygsub("abc", "b*", "X")
 * 	print "--->", mygsub("abc", "c", "X")
 * 	print "--->", mygsub("abc", "c+", "X")
 * 	print "--->", mygsub("abc", "x*$", "X")
 * }
 *
 * function mygsub(str, regex, replace,	origstr, newstr, eosflag, nonzeroflag)
 * {
 * 	origstr = str;
 * 	eosflag = nonzeroflag = false
 * 	while (match(str, regex)) {
 * 		if (RLENGTH > 0) {	# easy case
 * 			nonzeroflag = true
 * 			if (RSTART == 1) {	# match at front of string
 * 				newstr = newstr replace
 * 			} else {
 * 				newstr = newstr substr(str, 1, RSTART-1) replace
 * 			}
 * 			str = substr(str, RSTART+RLENGTH)
 * 		} else if (nonzeroflag) {
 * 			# last match was non-zero in length, and at the
 * 			# current character, we get a zero length match,
 * 			# which we don't really want, so skip over it
 * 			newstr = newstr substr(str, 1, 1)
 * 			str = substr(str, 2)
 * 			nonzeroflag = false
 * 		} else {
 * 			# 0-length match
 * 			if (RSTART == 1) {
 * 				newstr = newstr replace substr(str, 1, 1)
 * 				str = substr(str, 2)
 * 			} else {
 * 				return newstr str replace
 * 			}
 * 		}
 * 		if (length(str) == 0)
 * 			if (eosflag)
 * 				break
 * 			else
 * 				eosflag = true
 * 	}
 * 	if (length(str) > 0)
 * 		newstr = newstr str	# rest of string
 *
 * 	return newstr
 * }
 */

/*
 * 1/2004:  The gawk sub/gsub behavior dates from 1996, when we proposed it
 * for POSIX.  The proposal fell through the cracks, and the 2001 POSIX
 * standard chose a more simple behavior.
 *
 * The relevant text is to be found on lines 6394-6407 (pages 166, 167) of the
 * 2001 standard:
 *
 * sub(ere, repl[, in ])
 *  Substitute the string repl in place of the first instance of the
 *  extended regular expression ERE in string in and return the number of
 *  substitutions. An ampersand ('&') appearing in the string repl shall
 *  be replaced by the string from in that matches the ERE. An ampersand
 *  preceded with a backslash ('\') shall be interpreted as the literal
 *  ampersand character. An occurrence of two consecutive backslashes shall
 *  be interpreted as just a single literal backslash character. Any other
 *  occurrence of a backslash (for example, preceding any other character)
 *  shall be treated as a literal backslash character. Note that if repl is a
 *  string literal (the lexical token STRING; see Grammar (on page 170)), the
 *  handling of the ampersand character occurs after any lexical processing,
 *  including any lexical backslash escape sequence processing. If in is
 *  specified and it is not an lvalue (see Expressions in awk (on page 156)),
 *  the behavior is undefined. If in is omitted, awk shall use the current
 *  record ($0) in its place.
 *
 * 11/2010: The text in the 2008 standard is the same as just quoted.
 * However, POSIX behavior is now the default.  This can change the behavior
 * of awk programs.  The old behavior is not available.
 *
 * 7/2011: Reverted backslash handling to what it used to be. It was in
 * gawk for too long. Should have known better.
 *
 * 9/2023: Update for matches of null strings around multibyte characters.
 */

/*
 * NB: `howmany' conflicts with a SunOS 4.x macro in <sys/param.h>.
 */

NODE *
do_sub(int nargs, unsigned int flags)
{
	char *scan;
	char *bp, *cp;
	char *buf = NULL;
	size_t buflen;
	char *matchend;
	size_t len;
	char *matchstart;
	char *text;
	size_t textlen = 0;
	char *repl;
	char *replend;
	size_t repllen;
	int sofar;
	int ampersands;
	int matches = 0;
	Regexp *rp;
	NODE *rep_node;		/* replacement text */
	NODE *target;		/* string to make sub. in; $0 if none given */
	NODE *tmp;
	NODE **lhs = NULL;
	long how_many = 1;	/* one substitution for sub, also gensub default */
	bool global;
	long current;
	bool lastmatchnonzero;
	char *mb_indices = NULL;
	int searchflags = RE_NEED_START;

	if ((flags & GENSUB) != 0) {
		double d;
		NODE *glob_flag;

		check_exact_args(nargs, "gensub", 4);

		tmp = PEEK(3);
		rp = re_update(tmp);

		target = POP_STRING();	/* original string */

		glob_flag = POP_SCALAR();	/* value of global flag */
		if (   (glob_flag->flags & STRING) != 0
		    && glob_flag->stlen > 0
		    && (glob_flag->stptr[0] == 'g' || glob_flag->stptr[0] == 'G'))
			how_many = -1;
		else {
			(void) force_number(glob_flag);
			d = get_number_d(glob_flag);
			if (d < 1)
				how_many = 1;
			else if (d < (double) LONG_MAX)
				how_many = d;
			else
				how_many = LONG_MAX;
			if (d <= 0) {
				(void) force_string(glob_flag);
				warning(_("gensub: third argument `%.*s' treated as 1"),
						(int) glob_flag->stlen,
						glob_flag->stptr);
			}
		}
		DEREF(glob_flag);
		searchflags |= RE_NEED_SUB;
	} else {
		if ((flags & GSUB) != 0) {
			check_exact_args(nargs, "gsub", 3);
		} else {
			check_exact_args(nargs, "sub", 3);
		}

		/* take care of regexp early, in case re_update is fatal */

		tmp = PEEK(2);
		rp = re_update(tmp);

		if ((flags & GSUB) != 0)
			how_many = -1;

		/* original string */

		if ((flags & LITERAL) != 0)
			target = POP_STRING();
		else {
			lhs = POP_ADDRESS();
			target = force_string(*lhs);
		}
	}

	global = (how_many == -1);

	rep_node = POP_STRING();	/* replacement text */
	decr_sp();		/* regexp, already updated above */

	/* do the search early to avoid work on non-match */
	if (research(rp, target->stptr, 0, target->stlen, searchflags) == -1 ||
			RESTART(rp, target->stptr) > target->stlen)
		goto done;

	text = target->stptr;
	textlen = target->stlen;

	repl = rep_node->stptr;
	replend = repl + rep_node->stlen;
	repllen = replend - repl;

	ampersands = 0;

	/*
	 * Some systems' malloc() can't handle being called with an
	 * argument of zero.  Thus we have to have some special case
	 * code to check for `repllen == 0'.  This can occur for
	 * something like:
	 * 	sub(/foo/, "", mystring)
	 * for example.
	 */
	if (gawk_mb_cur_max > 1 && repllen > 0) {
		emalloc(mb_indices, char *, repllen * sizeof(char));
		index_multibyte_buffer(repl, mb_indices, repllen);
	}

	/* compute length of replacement string, number of ampersands */
	for (scan = repl; scan < replend; scan++) {
		if ((gawk_mb_cur_max == 1 || (repllen > 0 && mb_indices[scan - repl] == 1))
		    && (*scan == '&')) {
			repllen--;
			ampersands++;
		} else if (*scan == '\\') {
			if ((flags & GENSUB) != 0) {	/* gensub, behave sanely */
				if (isdigit((unsigned char) scan[1])) {
					ampersands++;
					scan++;
				} else {	/* \q for any q --> q */
					repllen--;
					scan++;
				}
			} else if (do_posix) {
				/* \& --> &, \\ --> \ */
				if (scan[1] == '&' || scan[1] == '\\') {
					repllen--;
					scan++;
				} /* else
					leave alone, it goes into the output */
			} else {
				/* gawk default behavior since 1996 */
				if (strncmp(scan, "\\\\\\&", 4) == 0
				    || strncmp(scan, "\\\\\\\\", 4) == 0) {	/* 2016: fixed */
					/* \\\& --> \& */
					/* \\\\ --> \\ */
					repllen -= 2;
					scan += 3;
				} else if (strncmp(scan, "\\\\&", 3) == 0) {
					/* \\& --> \<string> */
					ampersands++;
					repllen--;
					scan += 2;
				} else if (scan[1] == '&') {
					/* \& --> & */
					repllen--;
					scan++;
				} /* else
					leave alone, it goes into the output */
			}
		}
	}

	lastmatchnonzero = false;

	/* guesstimate how much room to allocate; +1 forces > 0 */
	buflen = textlen + (ampersands + 1) * repllen + 1;
	emalloc(buf, char *, buflen + 1);
	buf[buflen] = '\0';

	bp = buf;
	for (current = 1;; current++) {
		matches++;
		matchstart = target->stptr + RESTART(rp, target->stptr);
		matchend = target->stptr + REEND(rp, target->stptr);

		/*
		 * create the result, copying in parts of the original
		 * string. note that length of replacement string can
		 * vary since ampersand is actual text of regexp match.
		 */

		/*
		 * add 1 to len to handle "empty" case where
		 * matchend == matchstart and we force a match on a single
		 * char.  Use 'matchend - text' instead of 'matchstart - text'
		 * because we may not actually make any substitution depending
		 * on the 'global' and 'how_many' values.
		 */
		len = matchend - text + repllen
		      + ampersands * (matchend - matchstart) + 1;
		sofar = bp - buf;
		while (buflen < (sofar + len + 1)) {
			buflen *= 2;
			erealloc(buf, char *, buflen);
			bp = buf + sofar;
		}
		for (scan = text; scan < matchstart; scan++)
			*bp++ = *scan;
		if (global || current == how_many) {
			/*
			 * If the current match matched the null string,
			 * and the last match didn't and did a replacement,
			 * and the match of the null string is at the front of
			 * the text (meaning right after end of the previous
			 * replacement), then skip this one.
			 */
			if (matchstart == matchend
			    && lastmatchnonzero
			    && matchstart == text) {
				lastmatchnonzero = false;
				matches--;
				goto empty;
			}
			/*
			 * If replacing all occurrences, or this is the
			 * match we want, copy in the replacement text,
			 * making substitutions as we go.
			 */
			for (scan = repl; scan < replend; scan++)
				if (*scan == '&'
					/*
					 * Don't test repllen here. A simple "&" could
					 * end up with repllen == 0.
					 */
					&& (gawk_mb_cur_max == 1
						|| mb_indices[scan - repl] == 1)
				) {
						for (cp = matchstart; cp < matchend; cp++)
								*bp++ = *cp;
				} else if (*scan == '\\'
					&& (gawk_mb_cur_max == 1
						|| (repllen > 0 && mb_indices[scan - repl] == 1))
				) {
					if (flags & GENSUB) {	/* gensub, behave sanely */
						if (isdigit((unsigned char) scan[1])) {
							int dig = scan[1] - '0';
							if (dig < NUMSUBPATS(rp, target->stptr) && SUBPATSTART(rp, target->stptr, dig) != -1) {
								char *start, *end;

								start = target->stptr
								      + SUBPATSTART(rp, target->stptr, dig);
								end = target->stptr
								      + SUBPATEND(rp, target->stptr, dig);

								for (cp = start; cp < end; cp++)
									*bp++ = *cp;
							}
							scan++;
						} else if (scan+1 == replend) {
							*bp++ = *scan;
						} else	/* \q for any q --> q */
							*bp++ = *++scan;
					} else if (do_posix) {
						/* \& --> &, \\ --> \ */
						if (scan[1] == '&' || scan[1] == '\\')
							scan++;
						*bp++ = *scan;
					} else {
						/* gawk default behavior since 1996 */
						if (strncmp(scan, "\\\\\\&", 4) == 0
						    || strncmp(scan, "\\\\\\\\", 4) == 0) {	/* 2016: fixed */
							/* \\\& --> \& */
							/* \\\\ --> \\ */
							*bp++ = '\\';
							*bp++ = scan[3];
							scan += 3;
						} else if (strncmp(scan, "\\\\&", 3) == 0) {
							/* \\& --> \<string> */
							*bp++ = '\\';
							for (cp = matchstart; cp < matchend; cp++)
								*bp++ = *cp;
							scan += 2;
						} else if (scan[1] == '&') {
							/* \& --> & */
							*bp++ = '&';
							scan++;
						} else
							*bp++ = *scan;
					}
				} else
					*bp++ = *scan;
			if (matchstart != matchend)
				lastmatchnonzero = true;
		} else {
			/*
			 * don't want this match, skip over it by copying
			 * in current text.
			 */
			for (cp = matchstart; cp < matchend; cp++)
				*bp++ = *cp;
		}
	empty:
		/* catch the case of gsub(//, "blah", whatever), i.e. empty regexp */
		if (matchstart == matchend && matchend < text + textlen) {
			// copy in regular text
			if (gawk_mb_cur_max == 1) {
				*bp++ = *matchend;
				matchend++;
			} else {
				mbstate_t mbs;
				size_t i, j;

				memset(& mbs, 0, sizeof(mbs));
				j = mbrlen(matchend, (target->stptr + target->stlen) - matchend, & mbs);
				// FIXME: Error checking on the value of `j' would be a good idea....
				for (i = 0; i < j; i++)
					*bp++ = *matchend++;
			}
		}
		textlen = text + textlen - matchend;
		text = matchend;

#if 0
		if (bp - buf > sofar + len)
			fprintf(stderr, "debug: len = %zu, but used %ld\n", len, (long)((bp - buf) - (long)sofar));
#endif

		if ((current >= how_many && ! global)
		    || ((long) textlen <= 0 && matchstart == matchend)
		    || research(rp, target->stptr, text - target->stptr,
			    use_gnu_matchers ? textlen : target->stlen,
			    RE_NEED_START) == -1)
			break;

	}
	sofar = bp - buf;
	if (buflen < (sofar + textlen + 1)) {
		buflen = sofar + textlen + 1;
		erealloc(buf, char *, buflen);
		bp = buf + sofar;
	}
	/*
	 * Note that text == matchend, since that assignment is made before
	 * exiting the 'for' loop above. Thus we copy in the rest of the
	 * original string.
	 */
	for (scan = text; scan < text + textlen; scan++)
		*bp++ = *scan;
	*bp = '\0';
	textlen = bp - buf;

	if (mb_indices != NULL)
		efree(mb_indices);

done:
	DEREF(rep_node);

	if ((matches == 0 || (flags & LITERAL) != 0) && buf != NULL) {
		efree(buf);
		buf = NULL;
	}

	if (flags & GENSUB) {
		if (matches > 0) {
			/* return the result string */
			DEREF(target);
			assert(buf != NULL);
			return make_str_node(buf, textlen, ALREADY_MALLOCED);
		} else if ((target->flags & STRING) == 0) {
			/* return a copy of original string */
			NODE *copy = make_str_node(target->stptr, target->stlen, 0);
			DEREF(target);
			return copy;
		}

		/* return the original string */
		return target;
	}

	/* For a string literal, must not change the original string. */
	if ((flags & LITERAL) != 0)
		DEREF(target);
	else if (matches > 0) {
		/*
		 * 8/2021: There's a bit of a song and dance here.  If someone does
		 *
		 * 	x = @/abc/
		 * 	sub(/b/, "x", x)
		 *
		 * What should the type of x be after the call? Does it get converted
		 * to string? Or does it remain a regexp?  We've decided to let it
		 * remain a regexp. In that case, we have to update the compiled
		 * regular expression that it holds.
		 */
		bool is_regex = ((target->flags & REGEX) != 0);

		unref(*lhs);		// nuke original value
		if (is_regex)
			*lhs = make_typed_regex(buf, textlen);
		else
			*lhs = make_str_node(buf, textlen, ALREADY_MALLOCED);
	}

	return make_number((AWKNUM) matches);
}

/* call_sub --- call do_sub indirectly */

NODE *
call_sub(const char *name, int nargs)
{
	unsigned int flags = 0;
	NODE *regex, *replace, *glob_flag;
	NODE **lhs, *rhs;
	NODE *zero = make_number(0.0);
	NODE *result;
	const char *fname = name;

	if (fname[0] == 'a')	// awk::...
		fname += 5;

	if (fname[0] == 'g') {
		if (fname[1] == 'e')
			flags = GENSUB;
		else
			flags = GSUB;
	}

	bool need_free = false;
	if (flags == 0 || flags == GSUB) {
		/* sub or gsub */
		if (nargs != 2)
			fatal(_("%s: can be called indirectly only with two arguments"), name);

		replace = POP_STRING();
		regex = POP();	/* the regex */
		/*
		 * push regex
		 * push replace
		 * push $0
		 */
		if ((regex->flags & REGEX) != 0)
			regex = regex->typed_re;
		else {
			regex = make_regnode(Node_regex, regex);
			need_free = true;
		}
		PUSH(regex);
		PUSH(replace);
		lhs = r_get_field(zero, (Func_ptr *) 0, true);
		nargs++;
		PUSH_ADDRESS(lhs);
	} else {
		/* gensub */
		if (nargs < 3 || nargs > 4)
			fatal(_("indirect call to gensub requires three or four arguments"));

		if (nargs == 4)
			rhs = POP();
		else
			rhs = NULL;
		glob_flag = POP_STRING();
		replace = POP_STRING();
		regex = POP();	/* the regex */
		/*
		 * push regex
		 * push replace
		 * push glob_flag
		 * if (nargs = 3) {
		 *	 push $0
		 *	 nargs++
		 * }
		 */
		if ((regex->flags & REGEX) != 0)
			regex = regex->typed_re;
		else {
			regex = make_regnode(Node_regex, regex);
			need_free = true;
		}
		PUSH(regex);
		PUSH(replace);
		PUSH(glob_flag);
		if (rhs == NULL) {
			lhs = r_get_field(zero, (Func_ptr *) 0, true);
			rhs = *lhs;
			UPREF(rhs);
			PUSH(rhs);
			nargs++;
		}
		else
			PUSH(rhs);
	}

	unref(zero);
	result = do_sub(nargs, flags);

	if (need_free) {
		refree(regex->re_reg[0]);
		if (regex->re_reg[1] != NULL)
			refree(regex->re_reg[1]);
		freenode(regex);
	}

	if (flags != GENSUB)
		reset_record();
	return result;
}

/* call_match --- call do_match indirectly */

NODE *
call_match(int nargs)
{
	NODE *regex, *text, *array;
	NODE *result;

	if (nargs < 2 || nargs > 3)
		fatal(_("indirect call to match requires two or three arguments"));

	regex = text = array = NULL;
	if (nargs == 3)
		array = POP();
	regex = POP();
	text = POP();

	bool need_free = false;
	if ((regex->flags & REGEX) != 0)
		regex = regex->typed_re;
	else if (regex->type == Node_var_new || regex->type == Node_elem_new) {
		if (regex->type == Node_elem_new)
			elem_new_reset(regex);
		else if (regex->vname != NULL)
			efree(regex->vname);
		memset(regex, 0, sizeof(*regex));
		regex->type = Node_dynregex;
		regex->re_exp = dupnode(Nnull_string);
	} else {
		regex = make_regnode(Node_regex, regex);
		need_free = true;
	}

	if (text->type == Node_var_new || text->type == Node_elem_new) {
		if (text->type == Node_elem_new)
			elem_new_reset(text);
		else if (text->vname != NULL)
			efree(text->vname);
		text = dupnode(Nnull_string);
	}

	PUSH(text);
	PUSH(regex);

	if (array)
		PUSH(array);

	result = do_match(nargs);

	if (need_free) {
		refree(regex->re_reg[0]);
		if (regex->re_reg[1] != NULL)
			refree(regex->re_reg[1]);
		freenode(regex);
	}

	return result;
}

/* call_split_func --- call do_split or do_pat_split indirectly */

NODE *
call_split_func(const char *name, int nargs)
{
	NODE *regex, *seps;
	NODE *result;
	const char *fname = name;

	regex = seps = NULL;
	if (nargs < 2 || nargs > 4)
		fatal(_("indirect call to %s requires two to four arguments"),
				name);

	if (fname[0] == 'a')	// awk::...
		fname += 5;

	if (nargs == 4)
		seps = POP();

	bool need_free = false;
	if (nargs >= 3) {
		regex = POP_STRING();
		if ((regex->flags & REGEX) != 0)
			regex = regex->typed_re;
		else {
			regex = make_regnode(Node_regex, regex);
			need_free = true;
		}
	} else {
		if (fname[0] == 's') {
			regex = make_regnode(Node_regex, FS_node->var_value);
			regex->re_flags |= FS_DFLT;
		} else
			regex = make_regnode(Node_regex, FPAT_node->var_value);

		need_free = true;
		nargs++;
	}

	/* Don't need to pop the string or the data array */

	PUSH(regex);

	if (seps)
		PUSH(seps);

	result = (fname[0] == 's') ? do_split(nargs) : do_patsplit(nargs);

	if (need_free) {
		refree(regex->re_reg[0]);
		if (regex->re_reg[1] != NULL)
			refree(regex->re_reg[1]);
		freenode(regex);
	}

	return result;
}

/* make_integer - Convert an integer to a number node.  */

static NODE *
make_integer(uintmax_t n)
{
	n = adjust_uint(n);

	return make_number((AWKNUM) n);
}

/* do_lshift --- perform a << operation */

NODE *
do_lshift(int nargs)
{
	NODE *s1, *s2;
	uintmax_t uval, ushift, res;
	AWKNUM val, shift;

	check_exact_args(nargs, "lshift", 2);

	POP_TWO_SCALARS(s1, s2);
	if (do_lint) {
		if ((fixtype(s1)->flags & NUMBER) == 0)
			lintwarn(_("%s: received non-numeric first argument"), "lshift");
		if ((fixtype(s2)->flags & NUMBER) == 0)
			lintwarn(_("%s: received non-numeric second argument"), "lshift");
	}

	val = force_number(s1)->numbr;
	shift = force_number(s2)->numbr;
	if (val < 0 || shift < 0)
		fatal(_("lshift(%f, %f): negative values are not allowed"), val, shift);

	if (do_lint && (double_to_int(val) != val || double_to_int(shift) != shift))
		lintwarn(_("lshift(%f, %f): fractional values will be truncated"), val, shift);

	if (shift < sizeof(uintmax_t) * CHAR_BIT) {
		// within range
		uval = (uintmax_t) val;
		ushift = (uintmax_t) shift;

		res = uval << ushift;
	} else {
		// out of range
		if (do_lint)
			lintwarn(_("lshift(%f, %f): too large shift value returns zero"), val, shift);
		res = 0;
	}

	DEREF(s1);
	DEREF(s2);

	return make_integer(res);
}

/* do_rshift --- perform a >> operation */

NODE *
do_rshift(int nargs)
{
	NODE *s1, *s2;
	uintmax_t uval, ushift, res;
	AWKNUM val, shift;

	check_exact_args(nargs, "rshift", 2);

	POP_TWO_SCALARS(s1, s2);
	if (do_lint) {
		if ((fixtype(s1)->flags & NUMBER) == 0)
			lintwarn(_("%s: received non-numeric first argument"), "rshift");
		if ((fixtype(s2)->flags & NUMBER) == 0)
			lintwarn(_("%s: received non-numeric second argument"), "rshift");
	}

	val = force_number(s1)->numbr;
	shift = force_number(s2)->numbr;
	if (val < 0 || shift < 0)
		fatal(_("rshift(%f, %f): negative values are not allowed"), val, shift);

	if (do_lint && (double_to_int(val) != val || double_to_int(shift) != shift))
		lintwarn(_("rshift(%f, %f): fractional values will be truncated"), val, shift);

	if (shift < sizeof(uintmax_t) * CHAR_BIT) {
		// within range
		uval = (uintmax_t) val;
		ushift = (uintmax_t) shift;

		res = uval >> ushift;
	} else {
		// out of range
		if (do_lint)
			lintwarn(_("rshift(%f, %f): too large shift value returns zero"), val, shift);
		res = 0;
	}

	DEREF(s1);
	DEREF(s2);

	return make_integer(res);
}

/* do_and --- perform an & operation */

NODE *
do_and(int nargs)
{
	NODE *s1;
	uintmax_t res, uval;
	AWKNUM val;

	res = ~(uintmax_t) 0;	/* start off with all ones */
	if (nargs < 2)
		fatal(_("%s: called with less than two arguments"), "and");

	for (; nargs > 0; nargs--) {
		s1 = POP_SCALAR();
		if (do_lint && (fixtype(s1)->flags & NUMBER) == 0)
			lintwarn(_("%s: argument %d is non-numeric"), "and", nargs);

		val = force_number(s1)->numbr;
		if (val < 0)
			fatal(_("%s: argument %d negative value %g is not allowed"), "and", nargs, val);

		uval = (uintmax_t) val;
		res &= uval;

		DEREF(s1);
	}

	return make_integer(res);
}

/* do_or --- perform an | operation */

NODE *
do_or(int nargs)
{
	NODE *s1;
	uintmax_t res, uval;
	AWKNUM val;

	res = 0;
	if (nargs < 2)
		fatal(_("%s: called with less than two arguments"), "or");

	for (; nargs > 0; nargs--) {
		s1 = POP_SCALAR();
		if (do_lint && (fixtype(s1)->flags & NUMBER) == 0)
			lintwarn(_("%s: argument %d is non-numeric"), "or", nargs);

		val = force_number(s1)->numbr;
		if (val < 0)
			fatal(_("%s: argument %d negative value %g is not allowed"), "or", nargs, val);

		uval = (uintmax_t) val;
		res |= uval;

		DEREF(s1);
	}

	return make_integer(res);
}

/* do_xor --- perform an ^ operation */

NODE *
do_xor(int nargs)
{
	NODE *s1;
	uintmax_t res, uval;
	AWKNUM val;

	if (nargs < 2)
		fatal(_("%s: called with less than two arguments"), "xor");

	res = 0;	/* start with all zeroes */
	for (; nargs > 0; nargs--) {
		s1 = POP_SCALAR();
		if (do_lint && (fixtype(s1)->flags & NUMBER) == 0)
			lintwarn(_("%s: argument %d is non-numeric"), "xor", nargs);

		val = force_number(s1)->numbr;
		if (val < 0)
			fatal(_("%s: argument %d negative value %g is not allowed"), "xor", nargs, val);

		uval = (uintmax_t) val;
		res ^= uval;

		DEREF(s1);
	}

	return make_integer(res);
}

/* do_compl --- perform a ~ operation */

NODE *
do_compl(int nargs)
{
	NODE *tmp;
	double d;
	uintmax_t uval;

	check_exact_args(nargs, "compl", 1);

	tmp = POP_SCALAR();
	if (do_lint && (fixtype(tmp)->flags & NUMBER) == 0)
		lintwarn(_("%s: received non-numeric argument"), "compl");
	d = force_number(tmp)->numbr;
	DEREF(tmp);

	if (d < 0)
		fatal(_("compl(%f): negative value is not allowed"), d);

	if (do_lint && double_to_int(d) != d)
		lintwarn(_("compl(%f): fractional value will be truncated"), d);

	uval = (uintmax_t) d;
	uval = ~ uval;
	return make_integer(uval);
}

/* do_strtonum --- the strtonum function */

NODE *
do_strtonum(int nargs)
{
	NODE *tmp;
	AWKNUM d;

	check_exact_args(nargs, "strtonum", 1);

	tmp = fixtype(POP_SCALAR());
	if ((tmp->flags & NUMBER) != 0)
		d = (AWKNUM) tmp->numbr;
	else if (get_numbase(tmp->stptr, tmp->stlen, use_lc_numeric) != 10)
		d = nondec2awknum(tmp->stptr, tmp->stlen, NULL);
	else
		d = (AWKNUM) force_number(tmp)->numbr;

	DEREF(tmp);
	return make_number((AWKNUM) d);
}

/* nondec2awknum --- convert octal or hex value to double */

/*
 * Because of awk's concatenation rules and the way awk.y:yylex()
 * collects a number, this routine has to be willing to stop on the
 * first invalid character.
 */

AWKNUM
nondec2awknum(char *str, size_t len, char **endptr)
{
	AWKNUM retval = 0.0;
	char save;
	short val;
	char *start = str;
	size_t savelen = len;
	bool is_hex_float = false;

	if (len >= 2 && *str == '0' && (str[1] == 'x' || str[1] == 'X')) {
		/*
		 * User called strtonum("0x") or some such,
		 * so just quit early.
		 */
		if (len <= 2) {
			if (endptr)
				*endptr = start;
			return (AWKNUM) 0.0;
		}

		for (str += 2, len -= 2; len > 0; len--, str++) {
			switch (*str) {
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
				val = *str - '0';
				break;
			case 'a':
			case 'b':
			case 'c':
			case 'd':
			case 'e':
			case 'f':
				val = *str - 'a' + 10;
				break;
			case 'A':
			case 'B':
			case 'C':
			case 'D':
			case 'E':
			case 'F':
				val = *str - 'A' + 10;
				break;
			case 'p':
			case 'P':
			case '.':
				// restore the string
				str = start;
				len = savelen;
				is_hex_float = true;
				goto floating_point_hex;
			default:
				if (endptr)
					*endptr = str;
				goto done;
			}
			retval = (retval * 16) + val;
		}
		if (endptr)
			*endptr = str;
	} else if (len >= 1 && *str == '0') {
		int l;
		// preserve len in case we go to decimal
		for (l = len; l > 0; l--) {
			if (! isdigit((unsigned char) *str)) {
				if (endptr)
					*endptr = str;
				goto done;
			}
			else if (*str == '8' || *str == '9') {
				str = start;
				goto decimal;
			}
			retval = (retval * 8) + (*str - '0');
			str++;
		}
		if (endptr)
			*endptr = str;
	} else {
decimal:
floating_point_hex:
		save = str[len];
		str[len] = '\0';
		if (is_hex_float
		    && strchr(str, 'p') == NULL
		    && strchr(str, 'P') == NULL)
			fatal(_("hexadecimal floating point constants require an exponent"));
		retval = strtod(str, endptr);
		str[len] = save;
	}
done:
	return retval;
}

/* do_dcgettext, do_dcngettext --- handle i18n translations */

#if ENABLE_NLS && defined(LC_MESSAGES) && HAVE_DCGETTEXT

static int
localecategory_from_argument(NODE *t)
{
	static const struct category_table {
		int val;
		const char *name;
	} cat_tab[] = {
#ifdef LC_ALL
		{ LC_ALL,	"LC_ALL" },
#endif /* LC_ALL */
#ifdef LC_COLLATE
		{ LC_COLLATE,	"LC_COLLATE" },
#endif /* LC_COLLATE */
#ifdef LC_CTYPE
		{ LC_CTYPE,	"LC_CTYPE" },
#endif /* LC_CTYPE */
#ifdef LC_MESSAGES
		{ LC_MESSAGES,	"LC_MESSAGES" },
#endif /* LC_MESSAGES */
#ifdef LC_MONETARY
		{ LC_MONETARY,	"LC_MONETARY" },
#endif /* LC_MONETARY */
#ifdef LC_NUMERIC
		{ LC_NUMERIC,	"LC_NUMERIC" },
#endif /* LC_NUMERIC */
#ifdef LC_RESPONSE
		{ LC_RESPONSE,	"LC_RESPONSE" },
#endif /* LC_RESPONSE */
#ifdef LC_TIME
		{ LC_TIME,	"LC_TIME" },
#endif /* LC_TIME */
	};

	if (t != NULL) {
		int low, high, i, mid;
		char *category;
		int lc_cat = -1;

		char save = t->stptr[t->stlen];
		t->stptr[t->stlen] = '\0';
		category = t->stptr;

		/* binary search the table */
		low = 0;
		high = (sizeof(cat_tab) / sizeof(cat_tab[0])) - 1;
		while (low <= high) {
			mid = (low + high) / 2;
			i = strcmp(category, cat_tab[mid].name);

			if (i < 0)		/* category < mid */
				high = mid - 1;
			else if (i > 0)		/* category > mid */
				low = mid + 1;
			else {
				lc_cat = cat_tab[mid].val;
				break;
			}
		}
		t->stptr[t->stlen] = save;
		if (lc_cat == -1)	/* not there */
			fatal(_("dcgettext: `%s' is not a valid locale category"), category);

		return lc_cat;
	} else
		return LC_MESSAGES;
}

#endif

/*
 * awk usage is
 *
 * 	str = dcgettext(string [, domain [, category]])
 * 	str = dcngettext(string1, string2, number [, domain [, category]])
 *
 * Default domain is TEXTDOMAIN, default category is LC_MESSAGES.
 */

NODE *
do_dcgettext(int nargs)
{
	NODE *tmp, *t1, *t2 = NULL;
	char *string;
	char *the_result;
	size_t reslen;
#if ENABLE_NLS && defined(LC_MESSAGES) && HAVE_DCGETTEXT
	int lc_cat;
	char *domain;
	char save1 = '\0', save2 = '\0';

	check_args_min_max(nargs, "dcgettext", 1, 3);

	if (nargs == 3) {	/* third argument */
		tmp = POP_STRING();
		if (do_lint && (fixtype(tmp)->flags & STRING) == 0)
			lintwarn(_("%s: received non-string third argument"), "dcgettext");
		lc_cat = localecategory_from_argument(tmp);
		DEREF(tmp);
	} else
		lc_cat = LC_MESSAGES;

	if (nargs >= 2) {  /* second argument */
		t2 = POP_STRING();
		if (do_lint && (fixtype(t2)->flags & STRING) == 0)
			lintwarn(_("%s: received non-string second argument"), "dcgettext");
		domain = t2->stptr;
		str_terminate(t2, save2);
	} else
		domain = TEXTDOMAIN;
#else
	if (nargs == 3) {
		tmp = POP_STRING();
		if (do_lint && (fixtype(tmp)->flags & STRING) == 0)
			lintwarn(_("%s: received non-string third argument"), "dcgettext");
		DEREF(tmp);
	}
	if (nargs >= 2) {
		t2 = POP_STRING();
		if (do_lint && (fixtype(t2)->flags & STRING) == 0)
			lintwarn(_("%s: received non-string second argument"), "dcgettext");
		DEREF(t2);
	}
#endif

	t1 = POP_STRING();	/* first argument */
	if (do_lint && (fixtype(t1)->flags & STRING) == 0)
		lintwarn(_("%s: received non-string first argument"), "dcgettext");
	string = t1->stptr;

#if ENABLE_NLS && defined(LC_MESSAGES) && HAVE_DCGETTEXT
	str_terminate(t1, save1);
	the_result = dcgettext(domain, string, lc_cat);
	str_restore(t1, save1);
	if (t2 != NULL) {
		str_restore(t2, save2);
		DEREF(t2);
	}
	reslen = strlen(the_result);
#else
	the_result = string;
	reslen = t1->stlen;
#endif
	DEREF(t1);
	return make_string(the_result, reslen);
}


NODE *
do_dcngettext(int nargs)
{
	NODE *tmp, *t1, *t2, *t3;
	char *string1, *string2;
	unsigned long number;
	AWKNUM d;
	char *the_result;
	size_t reslen;

#if ENABLE_NLS && defined(LC_MESSAGES) && HAVE_DCGETTEXT
	int lc_cat;
	char *domain;
	char save = '\0', save1 = '\0', save2 = '\0';
	bool saved_end = false;

	check_args_min_max(nargs, "dcngettext", 3, 5);

	if (nargs == 5) {	/* fifth argument */
		tmp = POP_STRING();
		if (do_lint && (fixtype(tmp)->flags & STRING) == 0)
			lintwarn(_("%s: received non-string fifth argument"), "dcngettext");
		lc_cat = localecategory_from_argument(tmp);
		DEREF(tmp);
	} else
		lc_cat = LC_MESSAGES;

	t3 = NULL;
	if (nargs >= 4) {	/* fourth argument */
		t3 = POP_STRING();
		if (do_lint && (fixtype(t3)->flags & STRING) == 0)
			lintwarn(_("%s: received non-string fourth argument"), "dcngettext");
		domain = t3->stptr;
		save = domain[t3->stlen];
		domain[t3->stlen] = '\0';
		saved_end = true;
	} else
		domain = TEXTDOMAIN;
#else
	if (nargs == 5) {
		tmp = POP_STRING();
		if (do_lint && (fixtype(tmp)->flags & STRING) == 0)
			lintwarn(_("%s: received non-string fifth argument"), "dcngettext");
		DEREF(tmp);
	}
	if (nargs >= 4) {
		t3 = POP_STRING();
		if (do_lint && (fixtype(t3)->flags & STRING) == 0)
			lintwarn(_("%s: received non-string fourth argument"), "dcngettext");
		DEREF(t3);
	}
#endif

	t2 = POP_NUMBER();	/* third argument */
	if (do_lint && (fixtype(t2)->flags & NUMBER) == 0)
		lintwarn(_("%s: received non-numeric third argument"), "dcngettext");
	d = get_number_d(t2);
	DEREF(t2);

	number = (unsigned long) double_to_int(d);
	t2 = POP_STRING();	/* second argument */
	if (do_lint && (fixtype(t2)->flags & STRING) == 0)
		lintwarn(_("%s: received non-string second argument"), "dcngettext");
	string2 = t2->stptr;
	t1 = POP_STRING();	/* first argument */
	if (do_lint && (fixtype(t1)->flags & STRING) == 0)
		lintwarn(_("%s: received non-string first argument"), "dcngettext");
	string1 = t1->stptr;

#if ENABLE_NLS && defined(LC_MESSAGES) && HAVE_DCGETTEXT

	str_terminate(t1, save1);
	str_terminate(t2, save2);
	the_result = dcngettext(domain, string1, string2, number, lc_cat);
	reslen = strlen(the_result);
	str_restore(t1, save1);
	str_restore(t2, save2);
	if (saved_end)
		domain[t3->stlen] = save;
	if (t3 != NULL)
		DEREF(t3);
#else
	if (number == 1) {
		the_result = string1;
		reslen = t1->stlen;
	} else {
		the_result = string2;
		reslen = t2->stlen;
	}
#endif
	DEREF(t1);
	DEREF(t2);
	return make_string(the_result, reslen);
}

/* do_bindtextdomain --- set the directory for a text domain */

/*
 * awk usage is
 *
 * 	binding = bindtextdomain(dir [, domain])
 *
 * If dir is "", pass NULL to C version.
 * Default domain is TEXTDOMAIN.
 */

NODE *
do_bindtextdomain(int nargs)
{
	NODE *t1, *t2;
	const char *directory, *domain;
	const char *the_result;

	check_args_min_max(nargs, "bindtextdomain", 1, 2);

	t1 = t2 = NULL;
	/* set defaults */
	directory = NULL;
	domain = TEXTDOMAIN;
	char save = '\0', save1 = '\0';

	if (nargs == 2) {	/* second argument */
		t2 = POP_STRING();
		if (do_lint && (fixtype(t2)->flags & STRING) == 0)
			lintwarn(_("%s: received non-string second argument"), "bindtextdomain");
		domain = (const char *) t2->stptr;
		save = t2->stptr[t2->stlen];
		t2->stptr[t2->stlen] = '\0';
	}

	/* first argument */
	t1 = POP_STRING();
	if (do_lint && (fixtype(t1)->flags & STRING) == 0)
		lintwarn(_("%s: received non-string first argument"), "bindtextdomain");
	if (t1->stlen > 0) {
		directory = (const char *) t1->stptr;
		str_terminate(t1, save1);
	}

	the_result = bindtextdomain(domain, directory);
	if (directory)
		str_restore(t1, save1);

	DEREF(t1);
	if (t2 != NULL) {
		t2->stptr[t2->stlen] = save;
		DEREF(t2);
	}

	if (the_result == NULL)
		the_result = "";

	return make_string(the_result, strlen(the_result));
}

#ifdef SUPPLY_INTDIV
/* do_intdiv --- do integer division, return quotient and remainder in dest array */

/*
 * We define the semantics as:
 * 	numerator = int(numerator)
 *	denominator = int(denominator)
 *	quotient = int(numerator / denominator)
 *	remainder = int(numerator % denominator)
 */

NODE *
do_intdiv(int nargs)
{
	NODE *numerator, *denominator, *result;
	double num, denom, quotient, remainder;

	check_exact_args(nargs, "intdiv", 3);

	result = POP_PARAM();
	if (result->type != Node_var_array)
		fatal(_("intdiv: third argument is not an array"));
	assoc_clear(result);

	denominator = POP_SCALAR();
	numerator = POP_SCALAR();

	if (do_lint) {
		if ((fixtype(numerator)->flags & NUMBER) == 0)
			lintwarn(_("%s: received non-numeric first argument"), "intdiv");
		if ((fixtype(denominator)->flags & NUMBER) == 0)
			lintwarn(_("%s: received non-numeric second argument"), "intdiv");
	}

	(void) force_number(numerator);
	(void) force_number(denominator);
	num = double_to_int(get_number_d(numerator));
	denom = double_to_int(get_number_d(denominator));

	if (denom == 0.0)
		fatal(_("intdiv: division by zero attempted"));

	quotient = double_to_int(num / denom);
	/*
	 * FIXME: This code is duplicated, factor it out to a
	 * separate function.
	 */
#ifdef HAVE_FMOD
	remainder = fmod(num, denom);
#else	/* ! HAVE_FMOD */
	(void) modf(num / denom, & remainder);
	remainder = num - remainder * denom;
#endif	/* ! HAVE_FMOD */
	remainder = double_to_int(remainder);

	assoc_set(result, make_string("quotient", 8), make_number((AWKNUM) quotient));

	assoc_set(result, make_string("remainder", 9), make_number((AWKNUM) remainder));

	DEREF(denominator);
	DEREF(numerator);

	return make_number((AWKNUM) 0.0);
}
#endif /* SUPPLY_INTDIV */

/* do_typeof --- return a string with the type of the arg */

NODE *
do_typeof(int nargs)
{
	NODE *arg;
	const char *res = NULL;
	bool deref = true;
	NODE *dbg;

	check_args_min_max(nargs, "typeof", 1, 2);

	if (nargs == 2) {	/* 2nd optional arg for debugging */
		dbg = POP_PARAM();
		if (dbg->type != Node_var_array)
			fatal(_("typeof: second argument is not an array"));
		assoc_clear(dbg);
	}
	else
		dbg = NULL;
	arg = POP();

	if (arg->type == Node_param_list) {
		arg = GET_PARAM(arg->param_cnt);
		if (arg->type == Node_array_ref) {
			arg = arg->orig_array;
		}
	}

	switch (arg->type) {
	case Node_var_array:
		/* Node_var_array is never UPREF'ed */
		res = "array";
		deref = false;
		if (dbg) {
			assoc_set(dbg, make_string("array_type", 10), make_string(arg->array_funcs->name, strlen(arg->array_funcs->name)));
			if (arg == PROCINFO_node) {
				int i;
				for (i = 0; i < BLOCK_MAX; i++) {
					char *p;
					size_t nl = strlen(nextfree[i].name);
					/*
					 * save values before we create new
					 * array elements so that we have a
					 * snapshot at a consistent moment in
					 * time
					 */
					long hw = nextfree[i].highwater;
					long active;
#ifdef MEMDEBUG
					active = nextfree[i].active;
#else
					active = hw;
					{
						struct block_item *ip;
						for (ip = nextfree[i].freep; ip; ip = ip->freep)
							active--;
					}
#endif

#define SETVAL(X, V) {	\
	size_t l = nl + sizeof(#X);	\
	emalloc(p, char *, l+1);	\
	sprintf(p, "%s_" #X, nextfree[i].name);	\
	assoc_set(dbg, make_str_node(p, l, ALREADY_MALLOCED), make_number((AWKNUM) (V)));	\
}
					SETVAL(highwater, hw)
					SETVAL(active, active)
#undef SETVAL
				}
			}
		}
		break;
	case Node_var:
		/*
 		 * This can happen when a Node_elem_new gets turned into a Node_var.
		 * BEGIN {
		 * 	f(a["b"])
		 * 	print typeof(a["b"])
		 * }
		 *
		 * function f(x)
		 * {
		 * 	return x
		 * }
		 */
		arg = arg->var_value;
		// fall through
	case Node_val:
		switch (fixtype(arg)->flags & (STRING|NUMBER|USER_INPUT|REGEX|BOOLVAL)) {
		case NUMBER|BOOLVAL:
			res = "number|bool";
			break;
		case NUMBER:
			res = "number";
			break;
		case NUMBER|USER_INPUT:
			res = "strnum";
			break;
		case REGEX:
			res = "regexp";
			break;
		case STRING:
			res = "string";
			// fall through
		case NUMBER|STRING:
		{
			int flags = STRING|NUMBER|STRCUR|NUMCUR;

			if (   arg == Nnull_string		// unassigned scalar
			    || (arg->flags & NULL_FIELD) != 0	// unassigned field
			    || (arg->flags & flags) == flags) {	// Node_elem_new used as scalar value
				res = "unassigned";
				break;
			}
		}
			/* fall through */
		default:
			if (res == NULL) {
				warning(_("typeof detected invalid flags combination `%s'; please file a bug report"), flags2str(arg->flags));
				res = "unknown";
			}
			break;
		}
		if (dbg) {
			const char *s = flags2str(arg->flags);
			assoc_set(dbg, make_string("flags", 5), make_string(s, strlen(s)));
		}
		break;
	case Node_var_new:
		deref = false;
		// fall through
	case Node_elem_new:
		res = "untyped";
		break;
	case Node_array_ref:
		/*
		 *	function f(x) {
		 *	   print typeof(x)
		 *	   y = x
		 *	   print typeof(x)
		 *	}
		 *
		 *	BEGIN {
		 *	   print typeof(x)
		 *	   f(x)
		 *	}
		 */
		if (arg->orig_array->type == Node_var
		    && (arg->orig_array->var_value == Nnull_string
		        || (arg->orig_array->var_value->flags & NULL_FIELD) != 0)) {
			res = "unassigned";
		} else {
			res = "untyped";
		}
		deref = false;
		break;
	default:
		fatal(_("typeof: unknown argument type `%s'"),
				nodetype2str(arg->type));
		break;
	}

	if (deref)
		DEREF(arg);
	return make_string(res, strlen(res));
}

/* sanitize_exit_status --- convert a 16 bit Unix exit status into something reasonable */

int
sanitize_exit_status(int status)
{
	int ret = 0;

	if (WIFEXITED(status))
		ret = WEXITSTATUS(status); /* normal exit */
	else if (WIFSIGNALED(status)) {
		bool coredumped = false;
#ifdef WCOREDUMP
		coredumped = WCOREDUMP(status);
#endif
		/* use 256 since exit values are 8 bits */
		ret = WTERMSIG(status) + (coredumped ? 512 : 256);
	} else
		ret = 0;	/* shouldn't get here */

	return ret;
}

/* check_symtab_functab --- check if dest is SYMTAB or FUNCTAB, fatal if so */

void
check_symtab_functab(NODE *dest, const char *fname, const char *msg)
{
	if (dest == symbol_table)
		fatal(msg, fname, "SYMTAB");
	else if (dest == func_table)
		fatal(msg, fname, "FUNCTAB");
}

/* do_mkbool --- create boolean values */

NODE *
do_mkbool(int nargs)
{
	NODE *tmp;
	bool result;

	tmp = POP_SCALAR();
	result = boolval(tmp);
	DEREF(tmp);

	return make_bool_node(result);
}

/* gawk_system --- specialized version for gawk */

/*
 * 7/2025: This got messier because we need to ignore SIGINT and SIGQUIT
 * and block SIGCHLD while running (see the POSIX description of system()).
 * Blocking is only possible with the POSIX sigaction/sigprocmask APIs.
 * We do our best here, but it ain't pretty.
 */

int
gawk_system(const char *command)
{
#if defined(VMS) || defined(__MINGW32__)
	return system(command);
#else /* ! (defined(VMS) || defined(__MINGW32__)) */
	pid_t childpid;
	int status;

	// In the parent, before the fork
#ifdef HAVE_SIGPROCMASK
	sigset_t set, oldset;

	sigemptyset(& set);
	sigaddset(& set, SIGCHLD);
	sigprocmask(SIG_BLOCK, & set, & oldset);

	struct sigaction action, old_int_action, old_quit_action;

	sigemptyset(& action.sa_mask);
	action.sa_flags = 0;
	action.sa_handler = SIG_IGN;
	sigaction(SIGINT, & action, & old_int_action);
	sigaction(SIGQUIT, & action, & old_quit_action);
#else
	void (*istat)(int), (*qstat)(int);

	istat = signal(SIGINT, SIG_IGN);
	qstat = signal(SIGQUIT, SIG_IGN);
#endif

	if ((childpid = fork()) == 0) {
		// child
		set_sigpipe_to_default();
		// in the child, restore defaults
#ifdef HAVE_SIGPROCMASK
		sigprocmask(SIG_SETMASK, & oldset, NULL);
		sigaction(SIGINT, & old_int_action, NULL);
		sigaction(SIGQUIT, & old_quit_action, NULL);
#else
		istat = signal(SIGINT, istat);
		qstat = signal(SIGQUIT, qstat);
#endif
		execl("/bin/sh", "sh", "-c", command, NULL);
		_exit(errno == ENOENT ? 127 : 126);

		return 0;	// silence compiler warnings
	} else {
		// parent
		status = wait_any(childpid);

		// in the parent, restore stuff after getting the status
#ifdef HAVE_SIGPROCMASK
		sigprocmask(SIG_SETMASK, & oldset, NULL);
		sigaction(SIGINT, & old_int_action, NULL);
		sigaction(SIGQUIT, & old_quit_action, NULL);
#else
		istat = signal(SIGINT, istat);
		qstat = signal(SIGQUIT, qstat);
#endif

		return status;
	}
#endif /* ! (defined(VMS) || defined(__MINGW32__)) */
}

/* do_dump_node --- dump the offsets of the NODE struct */

NODE *
do_dump_node(int nargs)
{
	printf("MB_CUR_MAX = %u\n", (int) MB_CUR_MAX);
	printf("sizeof(int) = %zu\n", sizeof(int));
	printf("sizeof(long) = %zu\n", sizeof(long));
#ifdef HAVE_LONG_LONG_INT
	printf("sizeof(long long) = %zu\n", sizeof(long long));
#endif
	printf("sizeof(void *) = %zu\n", sizeof(void *));
	printf("\n");
	fflush(stdout);

	FILE *fp = popen("sort -n", "w");
	if (fp == NULL)
		return Nnull_string;

	fprintf(fp, "%zu\tarray_base\n", offsetof(NODE, array_base));
	fprintf(fp, "%zu\tarray_capacity\n", offsetof(NODE, array_capacity));
	fprintf(fp, "%zu\tarray_funcs\n", offsetof(NODE, array_funcs));
	fprintf(fp, "%zu\tarray_size\n", offsetof(NODE, array_size));
	fprintf(fp, "%zu\tbuckets\n", offsetof(NODE, buckets));
	fprintf(fp, "%zu\tcode_ptr\n", offsetof(NODE, code_ptr));
	fprintf(fp, "%zu\tcomment_type\n", offsetof(NODE, comment_type));
	fprintf(fp, "%zu\tcur_idx	\n", offsetof(NODE, cur_idx	));
	fprintf(fp, "%zu\tdup_ent\n", offsetof(NODE, dup_ent));
	fprintf(fp, "%zu\telemnew_parent\n", offsetof(NODE, elemnew_parent));
	fprintf(fp, "%zu\telemnew_vname\n", offsetof(NODE, elemnew_vname));
	fprintf(fp, "%zu\tflags\n", offsetof(NODE, flags));
	fprintf(fp, "%zu\tfor_array\n", offsetof(NODE, for_array));
	fprintf(fp, "%zu\tfor_list\n", offsetof(NODE, for_list));
	fprintf(fp, "%zu\tfor_list_size\n", offsetof(NODE, for_list_size));
	fprintf(fp, "%zu\tfparms\n", offsetof(NODE, fparms));
	fprintf(fp, "%zu\tfunc_node\n", offsetof(NODE, func_node));
	fprintf(fp, "%zu\tlnode\n", offsetof(NODE, lnode));
#ifdef HAVE_MPFR
	fprintf(fp, "%zu\tmpg_i\n", offsetof(NODE, mpg_i));
	fprintf(fp, "%zu\tmpg_numbr\n", offsetof(NODE, mpg_numbr));
#endif
	fprintf(fp, "%zu\tnodes\n", offsetof(NODE, nodes));
	fprintf(fp, "%zu\tnumbr\n", offsetof(NODE, numbr));
	fprintf(fp, "%zu\torig_array\n", offsetof(NODE, orig_array));
	fprintf(fp, "%zu\tparam\n", offsetof(NODE, param));
	fprintf(fp, "%zu\tparam_cnt\n", offsetof(NODE, param_cnt));
	fprintf(fp, "%zu\tparent_array\n", offsetof(NODE, parent_array));
	fprintf(fp, "%zu\tprev_array\n", offsetof(NODE, prev_array));
	fprintf(fp, "%zu\tprev_frame_size\n", offsetof(NODE, prev_frame_size));
	fprintf(fp, "%zu\tre_cnt\n", offsetof(NODE, re_cnt));
	fprintf(fp, "%zu\tre_exp\n", offsetof(NODE, re_exp));
	fprintf(fp, "%zu\tre_flags\n", offsetof(NODE, re_flags));
	fprintf(fp, "%zu\tre_reg\n", offsetof(NODE, re_reg));
	fprintf(fp, "%zu\tre_text\n", offsetof(NODE, re_text));
	fprintf(fp, "%zu\treti\n", offsetof(NODE, reti));
	fprintf(fp, "%zu\trnode\n", offsetof(NODE, rnode));
	fprintf(fp, "%zu\tstack\n", offsetof(NODE, stack));
	fprintf(fp, "%zu\tstfmt\n", offsetof(NODE, stfmt));
	fprintf(fp, "%zu\tstlen\n", offsetof(NODE, stlen));
	fprintf(fp, "%zu\tstptr\n", offsetof(NODE, stptr));
#ifdef HAVE_MPFR
	fprintf(fp, "%zu\tstrndmode\n", offsetof(NODE, strndmode));
#endif
	fprintf(fp, "%zu\ttable_size\n", offsetof(NODE, table_size));
	fprintf(fp, "%zu\ttype\n", offsetof(NODE, type));
	fprintf(fp, "%zu\ttyped_re\n", offsetof(NODE, typed_re));
	fprintf(fp, "%zu\tvalref\n", offsetof(NODE, valref));
	fprintf(fp, "%zu\tvar_assign\n", offsetof(NODE, var_assign));
	fprintf(fp, "%zu\tvar_update\n", offsetof(NODE, var_update));
	fprintf(fp, "%zu\tvar_value\n", offsetof(NODE, var_value));
	fprintf(fp, "%zu\tvname\n", offsetof(NODE, vname));
	fprintf(fp, "%zu\twstlen\n", offsetof(NODE, wstlen));
	fprintf(fp, "%zu\twstptr\n", offsetof(NODE, wstptr));
	fprintf(fp, "%zu\txarray\n", offsetof(NODE, xarray));

	pclose(fp);

	return Nnull_string;
}
