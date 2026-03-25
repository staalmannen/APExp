/*******************************************************************/
/*  slibtool: a strong libtool implementation, written in C        */
/*  Copyright (C) 2016--2025  SysDeer Technologies, LLC            */
/*  Released under the Standard MIT License; see COPYING.SLIBTOOL. */
/*******************************************************************/

#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

#include <slibtool/slibtool.h>
#include <slibtool/slibtool_arbits.h>
#include "slibtool_ar_impl.h"
#include "slibtool_driver_impl.h"
#include "slibtool_errinfo_impl.h"
#include "slibtool_visibility_impl.h"

slbt_hidden int slbt_ar_parse_primary_armap_sysv_32(
	const struct slbt_driver_ctx *  dctx,
	struct slbt_archive_meta_impl * m)
{
	struct ar_raw_armap_sysv_32 *   armap;
	struct ar_meta_member_info *    memberp;
	struct ar_meta_armap_common_32 *armapref;
	struct ar_meta_armap_ref_32 *   symrefs;
	uint32_t                        idx;
	uint32_t                        uref;
	uint32_t                        nsyms;
	uint32_t                        nstrs;
	const char *                    ch;
	const char *                    cap;
	unsigned char *                 uch;
	unsigned char                   (*mark)[0x04];

	armap   = &m->armaps.armap_sysv_32;
	memberp = m->memberv[0];

	mark = memberp->ar_object_data;

	armap->ar_num_of_syms = mark;
	uch = *mark++;

	armap->ar_first_ref_offset = mark;

	nsyms = (uch[0] << 24) + (uch[1] << 16) + (uch[2] << 8) + uch[3];
	mark += nsyms;

	if (memberp->ar_object_size < (sizeof(*mark) + (nsyms * sizeof(*mark))))
		return SLBT_CUSTOM_ERROR(
			dctx,
			SLBT_ERR_AR_INVALID_ARMAP_NUMBER_OF_SYMS);

	m->symstrs = (const char *)mark;

	cap  = memberp->ar_object_data;
	cap += memberp->ar_object_size;

	if ((cap == m->symstrs) && nsyms)
		return SLBT_CUSTOM_ERROR(
			dctx,
			SLBT_ERR_AR_INVALID_ARMAP_STRING_TABLE);

	if (nsyms && !m->symstrs[0])
		return SLBT_CUSTOM_ERROR(
			dctx,
			SLBT_ERR_AR_INVALID_ARMAP_STRING_TABLE);

	for (ch=&m->symstrs[1],nstrs=0; ch<cap; ch++) {
		if (!ch[0] && !ch[-1] && (nstrs < nsyms))
			return SLBT_CUSTOM_ERROR(
				dctx,
				SLBT_ERR_AR_INVALID_ARMAP_STRING_TABLE);

		if (!ch[0] && ch[-1])
			nstrs++;
	}

	if (nstrs != nsyms)
		return SLBT_CUSTOM_ERROR(
			dctx,
			SLBT_ERR_AR_INVALID_ARMAP_STRING_TABLE);

	if (cap[-1])
		return SLBT_CUSTOM_ERROR(
			dctx,
			SLBT_ERR_AR_INVALID_ARMAP_STRING_TABLE);

	if (!(m->symstrv = calloc(nsyms + 1,sizeof(const char *))))
		return SLBT_SYSTEM_ERROR(dctx);

	if (!(m->armaps.armap_symrefs_32 = calloc(nsyms + 1,sizeof(*symrefs))))
		return SLBT_SYSTEM_ERROR(dctx);

	mark    = armap->ar_first_ref_offset;
	symrefs = m->armaps.armap_symrefs_32;

	for (idx=0,uch=*mark; idx<nsyms; idx++,uch=*++mark) {
		uref = (uch[0] << 24) + (uch[1] << 16) + (uch[2] << 8) + uch[3];
		symrefs[idx].ar_member_offset = uref;
	}

	armap->ar_string_table = m->symstrv;

	armapref = &m->armaps.armap_common_32;
	armapref->ar_member         = memberp;
	armapref->ar_symrefs        = symrefs;
	armapref->ar_armap_sysv     = armap;
	armapref->ar_armap_attr     = AR_ARMAP_ATTR_SYSV | AR_ARMAP_ATTR_BE_32;
	armapref->ar_num_of_symbols = nsyms;
	armapref->ar_size_of_refs   = nsyms * sizeof(*mark);
	armapref->ar_size_of_strs   = cap - m->symstrs;
	armapref->ar_string_table   = m->symstrs;

	m->armaps.armap_nsyms = nsyms;

	m->armeta.a_armap_primary.ar_armap_common_32 = armapref;

	return 0;
}
