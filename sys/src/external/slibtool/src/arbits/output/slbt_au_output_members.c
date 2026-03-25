/*******************************************************************/
/*  slibtool: a strong libtool implementation, written in C        */
/*  Copyright (C) 2016--2025  SysDeer Technologies, LLC            */
/*  Released under the Standard MIT License; see COPYING.SLIBTOOL. */
/*******************************************************************/

#include <time.h>
#include <locale.h>
#include <inttypes.h>
#include <slibtool/slibtool.h>
#include <slibtool/slibtool_output.h>
#include "slibtool_driver_impl.h"
#include "slibtool_dprintf_impl.h"
#include "slibtool_errinfo_impl.h"
#include "slibtool_ar_impl.h"

#define SLBT_PRETTY_FLAGS       (SLBT_PRETTY_YAML      \
	                         | SLBT_PRETTY_POSIX    \
	                         | SLBT_PRETTY_HEXDATA)

#define PPRIU64 "%"PRIu64

const char slbt_ar_perm_strs[8][4] = {
	{'-','-','-','\0'},
	{'-','-','x','\0'},
	{'-','w','-','\0'},
	{'-','w','x','\0'},
	{'r','-','-','\0'},
	{'r','-','x','\0'},
	{'r','w','-','\0'},
	{'r','w','x','\0'}
};

static unsigned slbt_au_output_decimal_len_from_val(size_t val, unsigned min)
{
	unsigned ret;

	for (ret=0; val; ret++)
		val /= 10;

	return (ret > min) ? ret : min;
}

static int slbt_au_output_one_member_posix(
	int                             fdout,
	struct ar_meta_member_info *    memberp)
{
	return slbt_dprintf(
		fdout,"%s\n",
		memberp->ar_file_header.ar_member_name);
}

static int slbt_au_output_one_member_posix_verbose(
	int                             fdout,
	struct ar_meta_member_info *    memberp,
	const char *                    fmtstr,
	locale_t                        arlocale)
{
	unsigned    ownerbits;
	unsigned    groupbits;
	unsigned    worldbits;
	time_t      artimeval;
	struct tm   artimeloc;
	char        artimestr[64] = {0};

	ownerbits = (memberp->ar_file_header.ar_file_mode & 0700) >> 6;
	groupbits = (memberp->ar_file_header.ar_file_mode & 0070) >> 3;
	worldbits = (memberp->ar_file_header.ar_file_mode & 0007);
	artimeval = memberp->ar_file_header.ar_time_date_stamp;

	if (localtime_r(&artimeval,&artimeloc))
		strftime_l(
			artimestr,sizeof(artimestr),
			"%b %e %H:%M %Y",&artimeloc,
			arlocale);

	return slbt_dprintf(
		fdout,fmtstr,
		slbt_ar_perm_strs[ownerbits],
		slbt_ar_perm_strs[groupbits],
		slbt_ar_perm_strs[worldbits],
		memberp->ar_file_header.ar_uid,
		memberp->ar_file_header.ar_gid,
		memberp->ar_object_size,
		artimestr,
		memberp->ar_file_header.ar_member_name);
}

static int slbt_au_output_members_posix(
	const struct slbt_driver_ctx *  dctx,
	const struct slbt_archive_meta * meta,
	const struct slbt_fd_ctx *       fdctx)
{
	struct ar_meta_member_info **   memberp;
	int                             fdout;
	size_t                          testval;
	size_t                          sizelen;
	size_t                          uidlen;
	size_t                          gidlen;
	locale_t                        arloc;
	char                            fmtstr[64];

	fdout = fdctx->fdout;
	arloc = 0;

	if (dctx->x_cctx->x_fmtflags & SLBT_PRETTY_VERBOSE) {
		for (sizelen=0,memberp=meta->a_memberv; *memberp; memberp++)
			if ((testval = memberp[0]->ar_object_size) > sizelen)
				sizelen = testval;

		for (uidlen=0,memberp=meta->a_memberv; *memberp; memberp++)
			if ((testval = memberp[0]->ar_file_header.ar_uid) > uidlen)
				uidlen = testval;

		for (gidlen=0,memberp=meta->a_memberv; *memberp; memberp++)
			if ((testval = memberp[0]->ar_file_header.ar_gid) > gidlen)
				gidlen = testval;

		sizelen = slbt_au_output_decimal_len_from_val(sizelen,6);
		uidlen  = slbt_au_output_decimal_len_from_val(uidlen,1);
		gidlen  = slbt_au_output_decimal_len_from_val(gidlen,1);
		arloc   = newlocale(LC_ALL,setlocale(LC_ALL,0),0);

		sprintf(
			fmtstr,
			"%%s%%s%%s "
			"%%"   PPRIU64 "u"
			"/%%-" PPRIU64 "u "
			"%%"   PPRIU64 "u "
			"%%s "
			"%%s\n",
			uidlen,
			gidlen,
			sizelen);
	}

	for (memberp=meta->a_memberv; *memberp; memberp++) {
		switch ((*memberp)->ar_member_attr) {
			case AR_MEMBER_ATTR_ARMAP:
			case AR_MEMBER_ATTR_LINKINFO:
			case AR_MEMBER_ATTR_NAMESTRS:
				break;

			default:
				if (arloc) {
					if (slbt_au_output_one_member_posix_verbose(
							fdout,*memberp,fmtstr,arloc) < 0)
						return SLBT_SYSTEM_ERROR(dctx);
				} else {
					if (slbt_au_output_one_member_posix(
							fdout,*memberp) < 0)
						return SLBT_SYSTEM_ERROR(dctx);
				}
		}
	}

	if (arloc)
		freelocale(arloc);

	return 0;
}

static int slbt_au_output_one_member_yaml(
	int                             fdout,
	struct ar_meta_member_info *    memberp)
{
	return slbt_dprintf(
		fdout,
		"    - [ member: %s ]\n",
		memberp->ar_file_header.ar_member_name);
}

static int slbt_au_output_one_member_yaml_verbose(
	int                             fdout,
	struct ar_meta_member_info *    memberp,
	locale_t                        arlocale)
{
	time_t      artimeval;
	struct tm   artimeloc;
	char        artimestr[64] = {0};

	artimeval = memberp->ar_file_header.ar_time_date_stamp;

	if (localtime_r(&artimeval,&artimeloc))
		strftime_l(
			artimestr,sizeof(artimestr),
			"%Y/%m/%d @ %H:%M",&artimeloc,
			arlocale);

	return slbt_dprintf(
		fdout,
		"    - Member:\n"
		"      - [ name:       " "%s"    " ]\n"
		"      - [ timestamp:  " "%s"    " ]\n"
		"      - [ filesize:   " PPRIU64 " ]\n"
		"      - [ uid:        " "%d"    " ]\n"
		"      - [ gid:        " "%d"    " ]\n"
		"      - [ mode:       " "%d"    " ]\n\n",
		memberp->ar_file_header.ar_member_name,
		artimestr,
		memberp->ar_object_size,
		memberp->ar_file_header.ar_uid,
		memberp->ar_file_header.ar_gid,
		memberp->ar_file_header.ar_file_mode);
}

static int slbt_au_output_members_yaml(
	const struct slbt_driver_ctx *  dctx,
	const struct slbt_archive_meta * meta,
	const struct slbt_fd_ctx *       fdctx)
{
	struct ar_meta_member_info **   memberp;
	int                             fdout;
	locale_t                        arloc;

	fdout = fdctx->fdout;
	arloc = 0;

	if (dctx->x_cctx->x_fmtflags & SLBT_PRETTY_VERBOSE) {
		arloc   = newlocale(LC_ALL,setlocale(LC_ALL,0),0);
	}

	if (slbt_dprintf(fdctx->fdout,"  - Members:\n") < 0)
		return SLBT_SYSTEM_ERROR(dctx);

	for (memberp=meta->a_memberv; *memberp; memberp++) {
		switch ((*memberp)->ar_member_attr) {
			case AR_MEMBER_ATTR_ARMAP:
			case AR_MEMBER_ATTR_LINKINFO:
			case AR_MEMBER_ATTR_NAMESTRS:
				break;

			default:
				if (arloc) {
					if (slbt_au_output_one_member_yaml_verbose(
							fdout,*memberp,arloc) < 0)
						return SLBT_SYSTEM_ERROR(dctx);
				} else {
					if (slbt_au_output_one_member_yaml(
							fdout,*memberp) < 0)
						return SLBT_SYSTEM_ERROR(dctx);
				}
		}
	}

	if (arloc)
		freelocale(arloc);

	return 0;
}

int slbt_au_output_members(const struct slbt_archive_meta * meta)
{
	const struct slbt_driver_ctx *  dctx;
	struct slbt_fd_ctx              fdctx;

	dctx = (slbt_archive_meta_ictx(meta))->dctx;

	if (slbt_lib_get_driver_fdctx(dctx,&fdctx) < 0)
		return SLBT_NESTED_ERROR(dctx);

	if (!meta->a_memberv)
		return 0;

	switch (dctx->x_cctx->x_fmtflags & SLBT_PRETTY_FLAGS) {
		case SLBT_PRETTY_YAML:
			return slbt_au_output_members_yaml(
				dctx,meta,&fdctx);

		case SLBT_PRETTY_POSIX:
			return slbt_au_output_members_posix(
				dctx,meta,&fdctx);

		default:
			return slbt_au_output_members_yaml(
				dctx,meta,&fdctx);
	}
}
