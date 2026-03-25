/*******************************************************************/
/*  slibtool: a strong libtool implementation, written in C        */
/*  Copyright (C) 2016--2025  SysDeer Technologies, LLC            */
/*  Released under the Standard MIT License; see COPYING.SLIBTOOL. */
/*******************************************************************/

#ifndef SLIBTOOL_AR_IMPL_H
#define SLIBTOOL_AR_IMPL_H

#include "argv/argv.h"
#include <slibtool/slibtool.h>
#include <slibtool/slibtool_arbits.h>

/* decimal values in archive header are right padded with ascii spaces */
#define AR_DEC_PADDING (0x20)

/* archive file members are right padded as needed with ascii newline */
#define AR_OBJ_PADDING (0x0A)

/* initial number of elements in the transient, on-stack vector */
# define AR_STACK_VECTOR_ELEMENTS   (0x200)

extern const struct argv_option slbt_ar_options[];

struct ar_armaps_impl {
	struct ar_meta_armap_ref_32 *   armap_symrefs_32;
	struct ar_meta_armap_ref_64 *   armap_symrefs_64;
	struct ar_raw_armap_bsd_32      armap_bsd_32;
	struct ar_raw_armap_bsd_64      armap_bsd_64;
	struct ar_raw_armap_sysv_32     armap_sysv_32;
	struct ar_raw_armap_sysv_64     armap_sysv_64;
	struct ar_meta_armap_common_32  armap_common_32;
	struct ar_meta_armap_common_64  armap_common_64;
	uint64_t                        armap_nsyms;
};

struct slbt_archive_meta_impl {
	const struct slbt_driver_ctx *  dctx;
	struct slbt_archive_ctx *       actx;
	size_t                          ofmtattr;
	size_t                          nentries;
	size_t                          stblsize;
	size_t                          sreqsize;
	void *                          hdrinfov;
	char *                          namestrs;
	const char *                    symstrs;
	const char **                   symstrv;
	const char **                   mapstrv;
	off_t *                         offsetv;
	struct ar_meta_symbol_info *    syminfo;
	struct ar_meta_symbol_info **   syminfv;
	struct ar_meta_member_info **   memberv;
	struct ar_meta_member_info *    members;
	struct ar_armaps_impl           armaps;
	struct slbt_txtfile_ctx *       nminfo;
	struct slbt_archive_meta        armeta;
};

struct ar_meta_member_info * slbt_archive_member_from_offset(
	struct slbt_archive_meta_impl * meta,
	off_t                           offset);

int slbt_ar_parse_primary_armap_bsd_32(
	const struct slbt_driver_ctx *  dctx,
	struct slbt_archive_meta_impl * m);

int slbt_ar_parse_primary_armap_bsd_64(
	const struct slbt_driver_ctx *  dctx,
	struct slbt_archive_meta_impl * m);

int slbt_ar_parse_primary_armap_sysv_32(
	const struct slbt_driver_ctx *  dctx,
	struct slbt_archive_meta_impl * m);

int slbt_ar_parse_primary_armap_sysv_64(
	const struct slbt_driver_ctx *  dctx,
	struct slbt_archive_meta_impl * m);

int slbt_update_mapstrv(
	const struct slbt_driver_ctx *  dctx,
	struct slbt_archive_meta_impl * m);

int slbt_ar_update_syminfo(
	struct slbt_archive_ctx * actx);

int slbt_ar_update_syminfo_ex(
	struct slbt_archive_ctx * actx,
	int                       fdout);

static inline struct slbt_archive_meta_impl * slbt_archive_meta_ictx(const struct slbt_archive_meta * meta)
{
	uintptr_t addr;

	if (meta) {
		addr = (uintptr_t)meta - offsetof(struct slbt_archive_meta_impl,armeta);
		return (struct slbt_archive_meta_impl *)addr;
	}

	return 0;
}

#endif
