/*******************************************************************/
/*  slibtool: a strong libtool implementation, written in C        */
/*  Copyright (C) 2016--2025  SysDeer Technologies, LLC            */
/*  Released under the Standard MIT License; see COPYING.SLIBTOOL. */
/*******************************************************************/

#include <time.h>
#include <stdio.h>
#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
#include <sys/mman.h>
#include <sys/types.h>

#include <slibtool/slibtool.h>
#include <slibtool/slibtool_arbits.h>
#include "slibtool_ar_impl.h"
#include "slibtool_driver_impl.h"
#include "slibtool_errinfo_impl.h"

/* anonymous fun */
#ifndef MAP_ANONYMOUS
#define MAP_ANONYMOUS MAP_ANON
#endif

/* time stamp format specifier */
#define PPRII64 "%"PRIi64

/* file size format specifier */
#define PPRIU64 "%"PRIu64

/* dlopen self/force */
static const char slbt_ar_self_dlunit[] = "@PROGRAM@";

struct armap_buffer_32 {
	uint32_t        moffset;
	const char *    symname;
	uint32_t        baseidx;
};

struct armap_buffer_64 {
	uint64_t        moffset;
	const char *    symname;
	uint64_t        baseidx;
};

static const char ar_signature[] = AR_SIGNATURE;

static int slbt_create_anonymous_archive_ctx(
	const struct slbt_driver_ctx *	dctx,
	size_t                          size,
	struct slbt_archive_ctx **	pctx)
{
	struct slbt_archive_ctx_impl *	ctx;

	if (!(ctx = calloc(1,sizeof(*ctx))))
		return SLBT_BUFFER_ERROR(dctx);

	ctx->map.map_size = size;
	ctx->map.map_addr = mmap(
		0,size,
		PROT_READ|PROT_WRITE,
		MAP_PRIVATE|MAP_ANONYMOUS,
		-1,0);

	if (ctx->map.map_addr == MAP_FAILED) {
		free(ctx);
		return SLBT_SYSTEM_ERROR(dctx);
	}

	ctx->dctx       = dctx;
	ctx->actx.x_map	= &ctx->map;

	*pctx = &ctx->actx;

	return 0;
}

static off_t slbt_armap_write_be_32(unsigned char * mark, uint32_t val)
{
	mark[0] = val >> 24;
	mark[1] = val >> 16;
	mark[2] = val >> 8;
	mark[3] = val;

	return sizeof(uint32_t);
}

static off_t slbt_armap_write_le_32(unsigned char * mark, uint32_t val)
{
	mark[0] = val;
	mark[1] = val >> 8;
	mark[2] = val >> 16;
	mark[3] = val >> 24;

	return sizeof(uint32_t);
}

static off_t slbt_armap_write_be_64(unsigned char * mark, uint64_t val)
{
	slbt_armap_write_be_32(&mark[0],val >> 32);
	slbt_armap_write_be_32(&mark[4],val);

	return sizeof(uint64_t);
}

static off_t slbt_armap_write_le_64(unsigned char * mark, uint64_t val)
{
	slbt_armap_write_be_32(&mark[0],val);
	slbt_armap_write_be_32(&mark[4],val >> 32);

	return sizeof(uint64_t);
}


static int slbt_ar_merge_archives_fail(
	struct slbt_archive_ctx *   arctx,
	struct armap_buffer_32 *    bsdmap32,
	struct armap_buffer_64 *    bsdmap64,
	int                         ret)
{
	if (bsdmap32)
		free(bsdmap32);

	if (bsdmap64)
		free(bsdmap64);

	if (arctx)
		slbt_ar_free_archive_ctx(arctx);

	return ret;
}


int slbt_ar_merge_archives(
	struct slbt_archive_ctx * const arctxv[],
	struct slbt_archive_ctx **      arctxm)
{
	struct slbt_archive_ctx * const *       arctxp;
	struct slbt_archive_ctx *               arctx;

	const struct slbt_driver_ctx *          dctx;
	const struct slbt_archive_meta *        meta;

	struct ar_raw_file_header *             arhdr;
	struct ar_meta_member_info **           memberp;
	struct ar_meta_member_info *            meminfo;

	struct ar_meta_member_info *            armap;
	struct ar_meta_member_info *            arnames;

	const struct ar_meta_armap_common_32 *  armap32;
	const struct ar_meta_armap_common_64 *  armap64;
	const struct ar_meta_armap_ref_32 *     symref32;
	const struct ar_meta_armap_ref_64 *     symref64;

	struct armap_buffer_32 *                bsdmap32;
	struct armap_buffer_64 *                bsdmap64;
	struct armap_buffer_32 *                bsdsort32;
	struct armap_buffer_64 *                bsdsort64;

	size_t                                  nbytes;
	ssize_t                                 nwritten;

	uint32_t                                mapattr;
	uint64_t                                nmembers;
	uint64_t                                nsymrefs;

	uint64_t                                sarmap;
	uint64_t                                sarname;
	uint64_t                                sarchive;
	uint64_t                                smembers;
	uint64_t                                ssymrefs;
	uint64_t                                ssymstrs;
	uint64_t                                snamestrs;

	int64_t                                 omembers;
	int64_t                                 osymrefs;
	int64_t                                 onamestrs;
	int64_t                                 omemfixup;
	int64_t                                 atint;
	int64_t                                 aroff;

	char *                                  base;
	unsigned char *                         ubase;

	char *                                  ch;
	unsigned char *                         uch;

	char *                                  namebase;
	char *                                  namestr;
	char *                                  strtbl;

	uint64_t                                idx;
	uint64_t                                mapidx;
	uint64_t                                cmpidx;

	off_t (*armap_write_uint32)(
		unsigned char *,
		uint32_t);

	off_t (*armap_write_uint64)(
		unsigned char *,
		uint64_t);

	/* init */
	nmembers = nsymrefs = ssymstrs = mapattr   = 0;
	sarchive = smembers = ssymrefs = snamestrs = 0;
	omembers = osymrefs = onamestrs = 0;

	if (!arctxv || !arctxv[0])
		return -1;

	if (!(dctx = slbt_get_archive_ictx(arctxv[0])->dctx))
		return -1;

	/* determine armap type and size of archive elements */
	for (armap=0,arnames=0,arctxp=arctxv; *arctxp; arctxp++) {
		if (slbt_get_archive_ictx(*arctxp)->dctx != dctx)
			return SLBT_CUSTOM_ERROR(
				dctx,
				SLBT_ERR_AR_DRIVER_MISMATCH);

		meta    = (*arctxp)->x_meta;
		armap32 = meta->a_armap_primary.ar_armap_common_32;
		armap64 = meta->a_armap_primary.ar_armap_common_64;

		for (memberp=meta->a_memberv; memberp && *memberp; memberp++) {
			meminfo = *memberp;

			switch (meminfo->ar_member_attr) {
				case AR_MEMBER_ATTR_ARMAP:
					if (armap32) {
						if (mapattr == 0) {
							armap   = meminfo;
							mapattr = armap32->ar_armap_attr;
						} else if (mapattr != armap32->ar_armap_attr) {
							return SLBT_CUSTOM_ERROR(
								dctx,
								SLBT_ERR_AR_ARMAP_MISMATCH);
						}

						nsymrefs += armap32->ar_num_of_symbols;
						ssymstrs += armap32->ar_size_of_strs;

					} else if (armap64) {
						if (mapattr == 0) {
							armap   = meminfo;
							mapattr = armap64->ar_armap_attr;
						} else if (mapattr != armap64->ar_armap_attr) {
							return SLBT_CUSTOM_ERROR(
								dctx,
								SLBT_ERR_AR_ARMAP_MISMATCH);
						}

						nsymrefs += armap64->ar_num_of_symbols;
					}

					break;

				case AR_MEMBER_ATTR_LINKINFO:
					break;

				case AR_MEMBER_ATTR_NAMESTRS:
					if (!arnames)
						arnames = meminfo;

					break;

				default:
					smembers += sizeof(struct ar_raw_file_header);
					smembers += meminfo->ar_file_header.ar_file_size;
					smembers += 1;
					smembers |= 1;
					smembers ^= 1;
					nmembers++;

					break;
			}
		}

		snamestrs += (slbt_archive_meta_ictx(meta))->sreqsize;
	}

	/* armap size */
	if (sarmap = 0, sarname = 0, (mapattr == 0)) {
		(void)0;

	} else if (mapattr & AR_ARMAP_ATTR_SYSV) {
		if (mapattr & (AR_ARMAP_ATTR_LE_32|AR_ARMAP_ATTR_BE_32)) {
			sarmap += sizeof(uint32_t);
			sarmap += sizeof(uint32_t) * nsymrefs;
		} else {
			sarmap += sizeof(uint64_t);
			sarmap += sizeof(uint64_t) * nsymrefs;
		}

	} else if (mapattr & AR_ARMAP_ATTR_BSD) {
		if (mapattr & (AR_ARMAP_ATTR_LE_32|AR_ARMAP_ATTR_BE_32)) {
			sarmap += 2 * sizeof(uint32_t);
			sarmap += 2 * sizeof(uint32_t) * nsymrefs;
		} else {
			sarmap += 2 * sizeof(uint64_t);
			sarmap += 2 * sizeof(uint64_t) * nsymrefs;
		}

		sarname += armap->ar_file_header.ar_file_size;
		sarname -= armap->ar_object_size;
	} else {
		return SLBT_CUSTOM_ERROR(dctx,SLBT_ERR_FLOW_ERROR);
	}

	ssymstrs += 1;
	ssymstrs |= 1;
	ssymstrs ^= 1;

	/* (debugging) */
	(void)nmembers;

	/* long-names member alignment */
	snamestrs += 1;
	snamestrs |= 1;
	snamestrs ^= 1;

	/* archive size */
	sarchive  = sizeof(struct ar_raw_signature);
	sarchive += armap   ? sizeof(struct ar_raw_file_header) : 0;
	sarchive += arnames ? sizeof(struct ar_raw_file_header) : 0;
	sarchive += sarname;
	sarchive += sarmap;
	sarchive += ssymstrs;
	sarchive += snamestrs;
	sarchive += smembers;

	/* offset from archive base to first public member */
	omembers  = sarchive;
	omembers -= smembers;


	/* create in-memory archive */
	if (slbt_create_anonymous_archive_ctx(dctx,sarchive,&arctx) < 0)
		return SLBT_NESTED_ERROR(dctx);


	/* get ready for writing */
	base  = arctx->x_map->map_addr;
	ubase = arctx->x_map->map_addr;


	/* archive header */
	ch = base;
	memcpy(ch,ar_signature,sizeof(struct ar_raw_signature));
	ch += sizeof(struct ar_raw_signature);


	/* armap header */
	if (armap) {
		arhdr = (struct ar_raw_file_header *)ch;
		memcpy(arhdr,armap->ar_member_data,sizeof(*arhdr)+sarname);

		nwritten = armap->ar_file_header.ar_time_date_stamp
				? sprintf(arhdr->ar_time_date_stamp,PPRII64,(atint = time(0)))
				: 0;

		if (nwritten < 0)
			return slbt_ar_merge_archives_fail(
				arctx,0,0,
				SLBT_SYSTEM_ERROR(dctx));

		for (nbytes=nwritten; nbytes < sizeof(arhdr->ar_time_date_stamp); nbytes++)
			arhdr->ar_time_date_stamp[nbytes] = AR_DEC_PADDING;

		nwritten = sprintf(
			arhdr->ar_file_size,PPRIU64,
			sarname + sarmap + ssymstrs);

		if (nwritten < 0)
			return slbt_ar_merge_archives_fail(
				arctx,0,0,
				SLBT_SYSTEM_ERROR(dctx));

		for (nbytes=nwritten; nbytes < sizeof(arhdr->ar_file_size); nbytes++)
			arhdr->ar_file_size[nbytes] = AR_DEC_PADDING;
	}


	/* arnames header (sysv only) */
	if (arnames) {
		ch  = base;
		ch += omembers;
		ch -= snamestrs;
		ch -= sizeof(struct ar_raw_file_header);

		namebase  = ch;
		namebase += sizeof(struct ar_raw_file_header);

		memset(namebase,0,snamestrs);
		namestr = namebase;

		arhdr = (struct ar_raw_file_header *)ch;
		memcpy(arhdr,arnames->ar_member_data,sizeof(*arhdr));

		nwritten = arnames->ar_file_header.ar_time_date_stamp
				? sprintf(arhdr->ar_time_date_stamp,PPRII64,(atint = time(0)))
				: 0;

		if (nwritten < 0)
			return slbt_ar_merge_archives_fail(
				arctx,0,0,
				SLBT_SYSTEM_ERROR(dctx));

		for (nbytes=nwritten; nbytes < sizeof(arhdr->ar_time_date_stamp); nbytes++)
			arhdr->ar_time_date_stamp[nbytes] = AR_DEC_PADDING;

		nwritten = sprintf(
			arhdr->ar_file_size,PPRIU64,
			snamestrs);

		if (nwritten < 0)
			return slbt_ar_merge_archives_fail(
				arctx,0,0,
				SLBT_SYSTEM_ERROR(dctx));

		for (nbytes=nwritten; nbytes < sizeof(arhdr->ar_file_size); nbytes++)
			arhdr->ar_file_size[nbytes] = AR_DEC_PADDING;
	}


	/* armap data (preparation) */
	armap_write_uint32 = 0;
	armap_write_uint64 = 0;

	bsdmap32 = 0;
	bsdmap64 = 0;

	if (mapattr & AR_ARMAP_ATTR_BE_32)
		armap_write_uint32 = slbt_armap_write_be_32;

	else if (mapattr & AR_ARMAP_ATTR_LE_32)
		armap_write_uint32 = slbt_armap_write_le_32;

	else if (mapattr & AR_ARMAP_ATTR_BE_64)
		armap_write_uint64 = slbt_armap_write_be_64;

	else if (mapattr & AR_ARMAP_ATTR_LE_64)
		armap_write_uint64 = slbt_armap_write_le_64;

	uch  = ubase;
	uch += sizeof(struct ar_raw_signature);
	uch += sizeof(struct ar_raw_file_header);
	uch += sarname;

	if (mapattr & AR_ARMAP_ATTR_SYSV) {
		if (armap_write_uint32) {
			uch += armap_write_uint32(uch,nsymrefs);

			ch  = base;
			ch += uch - ubase;
			ch += sizeof(uint32_t) * nsymrefs;
		} else {
			uch += armap_write_uint64(uch,nsymrefs);

			ch  = base;
			ch += uch - ubase;
			ch += sizeof(uint64_t) * nsymrefs;
		}

	} else if (mapattr & AR_ARMAP_ATTR_BSD) {
		strtbl  = base;
		strtbl += omembers;
		strtbl -= ssymstrs;

		memset(strtbl,0,ssymstrs);

		if (armap_write_uint32) {
			if (!(bsdmap32 = calloc(2*nsymrefs,sizeof(struct armap_buffer_32))))
				return slbt_ar_merge_archives_fail(
					arctx,0,0,
					SLBT_SYSTEM_ERROR(dctx));

			bsdsort32 = &bsdmap32[nsymrefs];

		} else {
			if (!(bsdmap64 = calloc(2*nsymrefs,sizeof(struct armap_buffer_64))))
				return slbt_ar_merge_archives_fail(
					arctx,0,0,
					SLBT_SYSTEM_ERROR(dctx));

			bsdsort64 = &bsdmap64[nsymrefs];
		}
	}

	/* main iteration (armap data, long-names, public members) */
	for (mapidx=0,arctxp=arctxv; *arctxp; arctxp++) {
		meta    = (*arctxp)->x_meta;
		armap32 = meta->a_armap_primary.ar_armap_common_32;
		armap64 = meta->a_armap_primary.ar_armap_common_64;

		if ((memberp = meta->a_memberv)) {
			for (omemfixup=0; *memberp && !omemfixup; memberp++) {
				meminfo = *memberp;

				switch (meminfo->ar_member_attr) {
					case AR_MEMBER_ATTR_ARMAP:
					case AR_MEMBER_ATTR_LINKINFO:
					case AR_MEMBER_ATTR_NAMESTRS:
						break;

					default:
						omemfixup  = (int64_t)meminfo->ar_member_data;
						omemfixup -= (int64_t)meta->r_archive.map_addr;
						break;
				}
			}
		}

		for (memberp=meta->a_memberv; memberp && *memberp; memberp++) {
			meminfo = *memberp;

			switch (meminfo->ar_member_attr) {
				case AR_MEMBER_ATTR_ARMAP:
					if (armap32 && (mapattr & AR_ARMAP_ATTR_SYSV)) {
						symref32 = armap32->ar_symrefs;

						for (idx=0; idx<armap32->ar_num_of_symbols; idx++) {
							uch += armap_write_uint32(
								uch,
								symref32[idx].ar_member_offset + omembers - omemfixup);

							strcpy(ch,&armap32->ar_string_table[symref32[idx].ar_name_offset]);
							ch += strlen(ch);
							ch++;
						}

					} else if (armap64 && (mapattr & AR_ARMAP_ATTR_SYSV)) {
						symref64 = armap64->ar_symrefs;

						for (idx=0; idx<armap64->ar_num_of_symbols; idx++) {
							uch += armap_write_uint64(
								uch,
								symref64[idx].ar_member_offset + omembers - omemfixup);

							strcpy(ch,&armap64->ar_string_table[symref64[idx].ar_name_offset]);
							ch += strlen(ch);
							ch++;
						}

					} else if (armap32 && (mapattr & AR_ARMAP_ATTR_BSD)) {
						symref32 = armap32->ar_symrefs;

						for (idx=0; idx<armap32->ar_num_of_symbols; idx++) {
							bsdmap32[mapidx].moffset  = symref32[idx].ar_member_offset;
							bsdmap32[mapidx].moffset += omembers - omemfixup;

							bsdmap32[mapidx].symname  = armap32->ar_string_table;
							bsdmap32[mapidx].symname += symref32[idx].ar_name_offset;

							mapidx++;
						}

					} else if (armap64 && (mapattr & AR_ARMAP_ATTR_BSD)) {
						symref64 = armap64->ar_symrefs;

						for (idx=0; idx<armap64->ar_num_of_symbols; idx++) {
							bsdmap64[mapidx].moffset  = symref64[idx].ar_member_offset;
							bsdmap64[mapidx].moffset += omembers - omemfixup;

							bsdmap64[mapidx].symname  = armap64->ar_string_table;
							bsdmap64[mapidx].symname += symref64[idx].ar_name_offset;

							mapidx++;
						}
					}

					break;

				case AR_MEMBER_ATTR_LINKINFO:
					break;

				case AR_MEMBER_ATTR_NAMESTRS:
					break;

				default:
					arhdr = meminfo->ar_member_data;

					memcpy(
						&base[omembers],arhdr,
						sizeof(*arhdr) + meminfo->ar_file_header.ar_file_size);

					if (meminfo->ar_file_header.ar_header_attr & AR_HEADER_ATTR_SYSV) {
						if (meminfo->ar_file_header.ar_header_attr & AR_HEADER_ATTR_NAME_REF) {
							nwritten = sprintf(
								&base[omembers],"/"PPRII64,
								(aroff = namestr - namebase));

							if (nwritten < 0)
								SLBT_SYSTEM_ERROR(dctx);

							for (nbytes=nwritten; nbytes < sizeof(arhdr->ar_file_id); nbytes++)
								base[omembers + nbytes] = AR_DEC_PADDING;

							strcpy(namestr,meminfo->ar_file_header.ar_member_name);
							namestr += strlen(namestr);
							*namestr++ = '/';
							*namestr++ = AR_OBJ_PADDING;
						}
					}

					omembers += sizeof(*arhdr);
					omembers += meminfo->ar_file_header.ar_file_size;
					omembers += 1;
					omembers |= 1;
					omembers ^= 1;
					break;
			}
		}
	}

	/* bsd variant: also sort the string table (because we can:=)) */
	if (bsdmap32) {
		for (mapidx=0; mapidx<nsymrefs; mapidx++)
			for (cmpidx=0; cmpidx<nsymrefs; cmpidx++)
				if (strcmp(bsdmap32[cmpidx].symname,bsdmap32[mapidx].symname) < 0)
					bsdmap32[mapidx].baseidx++;

		/* a symbol might be present in more than one member; */
		/* see whether ar_member_offset has already been set) */
		for (mapidx=0,ch=strtbl; mapidx<nsymrefs; mapidx++) {
			idx = bsdmap32[mapidx].baseidx;

			for (; bsdsort32[idx].moffset; )
				idx++;

			bsdsort32[idx].moffset = bsdmap32[mapidx].moffset;
			bsdsort32[idx].symname = bsdmap32[mapidx].symname;
		}

		uch += armap_write_uint32(uch,2*sizeof(uint32_t)*nsymrefs);

		for (mapidx=0,ch=strtbl; mapidx<nsymrefs; mapidx++) {
			uch += armap_write_uint32(uch,ch-strtbl);
			uch += armap_write_uint32(uch,bsdsort32[mapidx].moffset);

			strcpy(ch,bsdsort32[mapidx].symname);
			ch += strlen(ch);
			ch++;
		}

		uch += armap_write_uint32(uch,ssymstrs);

		free(bsdmap32);

	} else if (bsdmap64) {
		for (mapidx=0; mapidx<nsymrefs; mapidx++)
			for (cmpidx=0; cmpidx<nsymrefs; cmpidx++)
				if (strcmp(bsdmap64[cmpidx].symname,bsdmap64[mapidx].symname) < 0)
					bsdmap64[mapidx].baseidx++;

		/* a symbol might be present in more than one member; */
		/* see whether ar_member_offset has already been set) */
		for (mapidx=0,ch=strtbl; mapidx<nsymrefs; mapidx++) {
			idx = bsdmap64[mapidx].baseidx;

			for (; bsdsort64[idx].moffset; )
				idx++;

			bsdsort64[idx].moffset = bsdmap64[mapidx].moffset;
			bsdsort64[idx].symname = bsdmap64[mapidx].symname;
		}

		uch += armap_write_uint64(uch,2*sizeof(uint64_t)*nsymrefs);

		for (mapidx=0,ch=strtbl; mapidx<nsymrefs; mapidx++) {
			uch += armap_write_uint64(uch,ch-strtbl);
			uch += armap_write_uint64(uch,bsdsort64[mapidx].moffset);

			strcpy(ch,bsdsort64[mapidx].symname);
			ch += strlen(ch);
			ch++;
		}

		uch += armap_write_uint64(uch,ssymstrs);

		free(bsdmap64);
	}

	struct slbt_archive_ctx_impl * ictx;
	ictx = slbt_get_archive_ictx(arctx);

	if (slbt_ar_get_archive_meta(dctx,arctx->x_map,&ictx->meta) < 0)
		return slbt_ar_merge_archives_fail(
			arctx,0,0,
			SLBT_NESTED_ERROR(dctx));

	ictx->actx.x_meta = ictx->meta;

	*arctxm = arctx;

	return 0;
}


int slbt_ar_get_varchive_ctx(
	const struct slbt_driver_ctx *	dctx,
	struct slbt_archive_ctx **	pctx)
{
	struct slbt_archive_ctx *       ctx;
	struct slbt_archive_ctx_impl *  ictx;
	void *                          base;
	size_t                          size;

	size = sizeof(struct ar_raw_signature);

	if (slbt_create_anonymous_archive_ctx(dctx,size,&ctx) < 0)
		return SLBT_NESTED_ERROR(dctx);

	ictx = slbt_get_archive_ictx(ctx);

	base = ctx->x_map->map_addr;
	memcpy(base,ar_signature,size);

	if (slbt_ar_get_archive_meta(dctx,ctx->x_map,&ictx->meta) < 0) {
		slbt_ar_free_archive_ctx(ctx);
		return SLBT_NESTED_ERROR(dctx);
	}

	ictx->path       = slbt_ar_self_dlunit;
	ictx->actx.x_meta  = ictx->meta;
	ictx->actx.x_path  = &ictx->path;

	*pctx = ctx;

	return 0;
}
