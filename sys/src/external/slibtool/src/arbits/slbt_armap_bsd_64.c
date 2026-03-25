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

slbt_hidden int slbt_ar_parse_primary_armap_bsd_64(
	const struct slbt_driver_ctx *  dctx,
	struct slbt_archive_meta_impl * m)
{
	struct ar_raw_armap_bsd_64 *    armap;
	struct ar_meta_member_info *    memberp;
	struct ar_meta_armap_common_64 *armapref;
	struct ar_meta_armap_ref_64 *   symrefs;
	uint64_t                        idx;
	uint64_t                        uref_hi;
	uint64_t                        uref_lo;
	uint32_t                        attr;
	uint64_t                        u64_lo;
	uint64_t                        u64_hi;
	uint64_t                        nsyms;
	uint64_t                        nstrs;
	uint64_t                        sizeofrefs_le;
	uint64_t                        sizeofrefs_be;
	uint64_t                        sizeofrefs;
	uint64_t                        sizeofstrs;
	const char *                    ch;
	const char *                    cap;
	unsigned char *                 uch;
	unsigned char                   (*mark)[0x08];

	armap   = &m->armaps.armap_bsd_64;
	memberp = m->memberv[0];

	mark = memberp->ar_object_data;

	armap->ar_size_of_refs = mark;
	uch = *mark++;

	armap->ar_first_name_offset = mark;

	u64_lo = (uch[3] << 24) + (uch[2] << 16) + (uch[1] << 8) + uch[0];
	u64_hi = (uch[7] << 24) + (uch[6] << 16) + (uch[5] << 8) + uch[4];

	sizeofrefs_le = u64_lo + (u64_hi << 32);

	u64_hi = (uch[0] << 24) + (uch[1] << 16) + (uch[2] << 8) + uch[3];
	u64_lo = (uch[4] << 24) + (uch[5] << 16) + (uch[6] << 8) + uch[7];

	sizeofrefs_be = (u64_hi << 32) + u64_lo;

	if (sizeofrefs_le < memberp->ar_object_size - sizeof(*mark)) {
		sizeofrefs = sizeofrefs_le;
		attr       = AR_ARMAP_ATTR_LE_64;

	} else if (sizeofrefs_be < memberp->ar_object_size - sizeof(*mark)) {
		sizeofrefs = sizeofrefs_be;
		attr       = AR_ARMAP_ATTR_BE_64;
	} else {
		return SLBT_CUSTOM_ERROR(
			dctx,
			SLBT_ERR_AR_INVALID_ARMAP_SIZE_OF_REFS);
	}

	nsyms  = sizeofrefs / sizeof(struct ar_raw_armap_ref_64);
	mark  += (sizeofrefs / sizeof(*mark));

	armap->ar_size_of_strs = mark;
	uch = *mark++;

	if (attr == AR_ARMAP_ATTR_LE_64) {
		u64_lo = (uch[3] << 24) + (uch[2] << 16) + (uch[1] << 8) + uch[0];
		u64_hi = (uch[7] << 24) + (uch[6] << 16) + (uch[5] << 8) + uch[4];
	} else {
		u64_hi = (uch[0] << 24) + (uch[1] << 16) + (uch[2] << 8) + uch[3];
		u64_lo = (uch[4] << 24) + (uch[5] << 16) + (uch[6] << 8) + uch[7];
	}

	sizeofstrs = u64_lo + (u64_hi << 32);
	m->symstrs = (const char *)mark;

	cap  = m->symstrs;
	cap += sizeofstrs;

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

		if (!ch[0] && ch[-1] && (nstrs < nsyms))
			nstrs++;
	}

	if (nstrs != nsyms)
		return SLBT_CUSTOM_ERROR(
			dctx,
			SLBT_ERR_AR_INVALID_ARMAP_STRING_TABLE);

	if (!(m->symstrv = calloc(nsyms + 1,sizeof(const char *))))
		return SLBT_SYSTEM_ERROR(dctx);

	if (!(m->armaps.armap_symrefs_64 = calloc(nsyms + 1,sizeof(*symrefs))))
		return SLBT_SYSTEM_ERROR(dctx);

	mark    = armap->ar_first_name_offset;
	symrefs = m->armaps.armap_symrefs_64;

	for (idx=0; idx<nsyms; idx++) {
		uch  = *mark++;

		if (attr == AR_ARMAP_ATTR_BE_64) {
			uref_hi = (uch[0] << 24) + (uch[1] << 16) + (uch[2] << 8) + uch[3];
			uref_lo = (uch[4] << 24) + (uch[5] << 16) + (uch[6] << 8) + uch[7];
		} else {
			uref_lo = (uch[3] << 24) + (uch[2] << 16) + (uch[1] << 8) + uch[0];
			uref_hi = (uch[7] << 24) + (uch[6] << 16) + (uch[5] << 8) + uch[4];
		}

		symrefs[idx].ar_name_offset = (uref_hi << 32) + uref_lo;

		uch  = *mark++;

		if (attr == AR_ARMAP_ATTR_BE_64) {
			uref_hi = (uch[0] << 24) + (uch[1] << 16) + (uch[2] << 8) + uch[3];
			uref_lo = (uch[4] << 24) + (uch[5] << 16) + (uch[6] << 8) + uch[7];
		} else {
			uref_lo = (uch[3] << 24) + (uch[2] << 16) + (uch[1] << 8) + uch[0];
			uref_hi = (uch[7] << 24) + (uch[6] << 16) + (uch[5] << 8) + uch[4];
		}

		symrefs[idx].ar_member_offset = (uref_hi << 32) + uref_lo;
	}

	armap->ar_string_table = m->symstrv;

	armapref = &m->armaps.armap_common_64;
	armapref->ar_member         = memberp;
	armapref->ar_symrefs        = symrefs;
	armapref->ar_armap_bsd      = armap;
	armapref->ar_armap_attr     = AR_ARMAP_ATTR_BSD | attr;
	armapref->ar_num_of_symbols = nsyms;
	armapref->ar_size_of_refs   = sizeofrefs;
	armapref->ar_size_of_strs   = sizeofstrs;
	armapref->ar_string_table   = m->symstrs;

	m->armaps.armap_nsyms = nsyms;

	m->armeta.a_armap_primary.ar_armap_common_64 = armapref;

	return 0;
}
