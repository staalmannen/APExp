/*******************************************************************/
/*  slibtool: a strong libtool implementation, written in C        */
/*  Copyright (C) 2016--2025  SysDeer Technologies, LLC            */
/*  Released under the Standard MIT License; see COPYING.SLIBTOOL. */
/*******************************************************************/

#include <string.h>
#include "slibtool_visibility_impl.h"

slbt_hidden int slbt_coff_qsort_strcmp(const void * a, const void * b)
{
	const char *    dot;
	const char *    mark;
	const char *    stra;
	const char *    strb;
	const char **   pstra;
	const char **   pstrb;
	char            strbufa[4096];
	char            strbufb[4096];

	pstra = (const char **)a;
	pstrb = (const char **)b;

	stra  = *pstra;
	strb  = *pstrb;

	if (!strncmp(*pstra,".weak.",6)) {
		stra = strbufa;
		mark = &(*pstra)[6];
		dot  = strchr(mark,'.');

		strncpy(strbufa,mark,dot-mark);
		strbufa[dot-mark] = '\0';
	}

	if (!strncmp(*pstrb,".weak.",6)) {
		strb = strbufb;
		mark = &(*pstrb)[6];
		dot  = strchr(mark,'.');

		strncpy(strbufb,mark,dot-mark);
		strbufb[dot-mark] = '\0';
	}

	return strcmp(stra,strb);
}
