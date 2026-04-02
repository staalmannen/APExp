/*
 * ordchr.c - Builtin functions that provide ord() and chr() functions.
 *
 * Arnold Robbins
 * arnold@skeeve.com
 * 8/2001
 * Revised 6/2004
 * Revised 5/2012
 * Revised 6/2025
 * Revised 12/2025
 */

/*
 * Copyright (C) 2001, 2004, 2011, 2012, 2013, 2018, 2020, 2021, 2025,
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

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <wchar.h>
#include <langinfo.h>

#include <sys/types.h>
#include <sys/stat.h>

#include "gawkapi.h"

#include "gettext.h"
#define _(msgid)  gettext(msgid)
#define N_(msgid) msgid

#ifndef __MINGW32__
#if defined(HAVE_UCHAR_H) && defined(HAVE_MBRTOC32) && defined(HAVE_C32RTOMB)
#include <uchar.h>
#else
#define char32_t wchar_t
#define mbrtoc32 mbrtowc
#define c32rtomb wcrtomb
#endif
#endif /* __MINGW32__ */

static const gawk_api_t *api;	/* for convenience macros to work */
static awk_ext_id_t ext_id;
static const char *ext_version = "ordchr extension: version 2.0";
static awk_bool_t (*init_func)(void) = NULL;

int plugin_is_GPL_compatible;

/*  do_ord --- return numeric value of first char of string */

static awk_value_t *
do_ord(int nargs, awk_value_t *result, struct awk_ext_func *unused)
{
	awk_value_t str;
	double ret = 0xFFFD;	// unicode bad char
	mbstate_t mbs;
	const char *src;

	assert(result != NULL);

	memset(& mbs, 0, sizeof(mbs));

	if (get_argument(0, AWK_STRING, & str)) {
		if (MB_CUR_MAX == 1) {
			ret = str.str_value.str[0] & 0xff;
		} else {
			char32_t wc;
			size_t res;

			src = str.str_value.str;
			res = mbrtoc32(& wc, src, MB_CUR_MAX, & mbs);
			if (res == 0 || res == (size_t) -1 || res == (size_t) -2) {
				// mimic gawk's behavior
				char *codeset = nl_langinfo(CODESET);
				if (strcmp(codeset, "UTF-8") == 0)
					ret = 0xFFFD;	// unicode bad char
				else
					ret = wc;
			} else
				ret = wc;
		}
	} else if (do_lint)
		lintwarn(ext_id, _("ord: first argument is not a string"));

	/* Set the return value */
	return make_number(ret, result);
}

/*  do_chr --- turn numeric value into a string */

static awk_value_t *
do_chr(int nargs, awk_value_t *result, struct awk_ext_func *unused)
{
	awk_value_t num;
	unsigned int ret = 0;
	double val = 0.0;
	char32_t wc = 0;
	char buf[20] = { '\0', '\0' };

	assert(result != NULL);

	if (get_argument(0, AWK_NUMBER, & num)) {
		val = num.num_value;
		ret = val;	/* convert to int */
		if (MB_CUR_MAX == 1) {
			buf[0] = ret & 0xff;
			goto done;
		} else {
			wc = ret;
		}
	} else if (do_lint)
		lintwarn(ext_id, _("chr: first argument is not a number"));

	mbstate_t mbs;
	size_t res;

	memset(& mbs, 0, sizeof(mbs));
	res = c32rtomb(buf, wc,  & mbs);
	if (res == 0 || res == (size_t)-1 || res == (size_t) -2)
		buf[0] = buf[1] = '\0';

done:
	/* Set the return value */
	return make_const_string(buf, strlen(buf), result);
}

static awk_ext_func_t func_table[] = {
	{ "ord", do_ord, 1, 1, awk_false, NULL },
	{ "chr", do_chr, 1, 1, awk_false, NULL },
};

/* define the dl_load function using the boilerplate macro */

dl_load_func(func_table, ord_chr, "")
