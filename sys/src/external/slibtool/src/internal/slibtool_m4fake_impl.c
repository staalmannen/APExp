/*******************************************************************/
/*  slibtool: a strong libtool implementation, written in C        */
/*  Copyright (C) 2016--2025  SysDeer Technologies, LLC            */
/*  Released under the Standard MIT License; see COPYING.SLIBTOOL. */
/*******************************************************************/

#include <string.h>
#include <limits.h>

#include <slibtool/slibtool.h>
#include "slibtool_driver_impl.h"
#include "slibtool_snprintf_impl.h"
#include "slibtool_errinfo_impl.h"
#include "slibtool_visibility_impl.h"
#include "slibtool_m4fake_impl.h"

slbt_hidden int slbt_m4fake_expand_cmdarg(
	const struct slbt_driver_ctx *  dctx,
	struct slbt_txtfile_ctx *       sctx,
	const char *                    cmdname,
	char                            (*argbuf)[PATH_MAX])
{
	const char **             pline;
	size_t                    slen;
	const char *              mark;
	const char *              match;
	const char *              cap;
	int                       fquote;
	char                      varbuf[PATH_MAX];
	char                      strbuf[PATH_MAX];

	memset(*argbuf,0,sizeof(*argbuf));

	slen  = strlen(cmdname);
	pline = sctx->x_txtlinev;
	match = 0;

	for (; !match && *pline; ) {
		if (!strncmp(*pline,cmdname,slen)) {
			if ((*pline)[slen] == '(') {
				mark  = &(*pline)[slen];
				cap   = ++mark;

				for (fquote=0; !match && *cap; ) {
					if (*cap == '[')
						fquote++;

					else if ((*cap == ']') && fquote)
						fquote--;

					else if ((*cap == ')') && !fquote)
						match = cap;

					if (!match)
						cap++;
				}

				if (!match)
					return SLBT_CUSTOM_ERROR(
						dctx,
						SLBT_ERR_FLOW_ERROR);
			}
		}

		if (!match)
			pline++;
	}

	if (!match)
		return 0;

	strncpy(strbuf,mark,cap-mark);
	strbuf[cap-mark] = '\0';

	mark = strbuf;
	slen = strlen(mark);

	if ((mark[0] == '[') && (mark[--slen] == ']')) {
		strcpy(*argbuf,++mark);
		(*argbuf)[--slen] = '\0';
		return 0;
	}

	if (slbt_snprintf(
			varbuf,sizeof(varbuf),
			"AC_DEFUN([%s],",
			strbuf) < 0)
		return SLBT_BUFFER_ERROR(dctx);

	slen = strlen(varbuf);

	for (--pline; pline >= sctx->x_txtlinev; pline--) {
		if (!strncmp(*pline,varbuf,slen)) {
			mark  = &(*pline)[slen];
			cap   = mark;
			match = 0;

			for (fquote=0; !match && *cap; ) {
				if (*cap == '[')
					fquote++;

				else if ((*cap == ']') && fquote)
					fquote--;

				else if ((*cap == ')') && !fquote)
					match = cap;

				if (!match)
					cap++;
			}

			if (!match)
				return SLBT_CUSTOM_ERROR(
					dctx,
					SLBT_ERR_FLOW_ERROR);

			strncpy(strbuf,mark,cap-mark);
			strbuf[cap-mark] = '\0';

			mark = strbuf;
			slen = strlen(mark);

			if ((mark[0] == '[') && (mark[--slen] == ']')) {
				strcpy(*argbuf,++mark);
				(*argbuf)[--slen] = '\0';
				return 0;
			}

			if (slbt_snprintf(
					varbuf,sizeof(varbuf),
					"AC_DEFUN([%s],",
					strbuf) < 0)
				return SLBT_BUFFER_ERROR(dctx);

			slen = strlen(varbuf);
		}
	}

	strcpy(*argbuf,strbuf);

	return 0;
}
