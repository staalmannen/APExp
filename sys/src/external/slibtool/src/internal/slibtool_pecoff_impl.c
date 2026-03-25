/*******************************************************************/
/*  slibtool: a strong libtool implementation, written in C        */
/*  Copyright (C) 2016--2025  SysDeer Technologies, LLC            */
/*  Released under the Standard MIT License; see COPYING.SLIBTOOL. */
/*******************************************************************/

#include <string.h>

#include "slibtool_visibility_impl.h"

slbt_hidden int slbt_is_strong_coff_symbol(const char * sym)
{
	return strncmp(sym,"__imp_",6)
		&& strncmp(sym,".weak.",6)
		&& strncmp(sym,".refptr.",8);
}
