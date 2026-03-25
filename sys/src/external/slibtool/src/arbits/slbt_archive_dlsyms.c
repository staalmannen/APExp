/*******************************************************************/
/*  slibtool: a strong libtool implementation, written in C        */
/*  Copyright (C) 2016--2025  SysDeer Technologies, LLC            */
/*  Released under the Standard MIT License; see COPYING.SLIBTOOL. */
/*******************************************************************/

#include <slibtool/slibtool.h>
#include "slibtool_ar_impl.h"
#include "slibtool_driver_impl.h"
#include "slibtool_snprintf_impl.h"
#include "slibtool_errinfo_impl.h"

static const char * slbt_strong_symname(
	const char *    symname,
	bool            fcoff,
	char            (*strbuf)[4096])
{
	const char *    dot;
	const char *    mark;
	char *          sym;

	if (fcoff) {
		if (!strncmp(symname,"__imp_",6))
			return 0;

		if (strncmp(symname,".weak.",6))
			return symname;

		sym  = *strbuf;
		mark = &symname[6];
		dot  = strchr(mark,'.');

		strncpy(sym,mark,dot-mark);
		sym[dot-mark] = '\0';

		return sym;
	}

	return symname;
}


static int slbt_ar_dlsyms_define_by_type(
	int                                 fdout,
	const char *                        arname,
	struct slbt_archive_meta_impl *     mctx,
	const char *                        desc,
	const char                          stype)
{
	uint64_t      idx;
	uint64_t      nsyms;
	bool          fcoff;
	const char *  symname;
	char          strbuf[4096];

	for (idx=0,nsyms=0; idx<mctx->armaps.armap_nsyms; idx++)
		if (mctx->syminfv[idx]->ar_symbol_type[0] == stype)
			nsyms++;

	if (nsyms == 0)
		return 0;

	fcoff  = slbt_host_objfmt_is_coff(mctx->dctx);
	fcoff |= (mctx->ofmtattr & AR_OBJECT_ATTR_COFF);

	if (slbt_dprintf(fdout,"/* %s (%s) */\n",desc,arname) < 0)
		return SLBT_SYSTEM_ERROR(mctx->dctx);

	for (idx=0; idx<mctx->armaps.armap_nsyms; idx++)
		if (mctx->syminfv[idx]->ar_symbol_type[0] == stype)
			if ((symname = slbt_strong_symname(
					mctx->syminfv[idx]->ar_symbol_name,
					fcoff,&strbuf)))
				if (slbt_dprintf(fdout,
						(stype == 'T')
							? "extern int %s();\n"
							: "extern char %s[];\n",
						symname) < 0)
					return SLBT_SYSTEM_ERROR(mctx->dctx);

	if (slbt_dprintf(fdout,"\n") < 0)
		return SLBT_SYSTEM_ERROR(mctx->dctx);

	return 0;
}

static int slbt_ar_dlsyms_get_max_len_by_type(
	int                                 mlen,
	struct slbt_archive_meta_impl *     mctx,
	const char                          stype)
{
	int           len;
	uint64_t      idx;
	bool          fcoff;
	const char *  symname;
	char          strbuf[4096];

	fcoff  = slbt_host_objfmt_is_coff(mctx->dctx);
	fcoff |= (mctx->ofmtattr & AR_OBJECT_ATTR_COFF);

	for (idx=0; idx<mctx->armaps.armap_nsyms; idx++)
		if (mctx->syminfv[idx]->ar_symbol_type[0] == stype)
			if ((symname = slbt_strong_symname(
					mctx->syminfv[idx]->ar_symbol_name,
					fcoff,&strbuf)))
				if ((len = strlen(symname)) > mlen)
					mlen = len;

	return mlen;
}

static int slbt_ar_dlsyms_add_by_type(
	int                                 fdout,
	struct slbt_archive_meta_impl *     mctx,
	const char *                        fmt,
	const char                          stype,
	char                                (*namebuf)[4096])
{
	uint64_t      idx;
	uint64_t      nsyms;
	bool          fcoff;
	const char *  symname;
	char          strbuf[4096];

	nsyms   = 0;
	symname = *namebuf;

	fcoff  = slbt_host_objfmt_is_coff(mctx->dctx);
	fcoff |= (mctx->ofmtattr & AR_OBJECT_ATTR_COFF);

	for (idx=0; idx<mctx->armaps.armap_nsyms; idx++)
		if (mctx->syminfv[idx]->ar_symbol_type[0] == stype)
			nsyms++;

	if (nsyms == 0)
		return 0;

	if (slbt_dprintf(fdout,"\n") < 0)
		return SLBT_SYSTEM_ERROR(mctx->dctx);

	for (idx=0; idx<mctx->armaps.armap_nsyms; idx++) {
		if (mctx->syminfv[idx]->ar_symbol_type[0] == stype) {
			symname = slbt_strong_symname(
				mctx->syminfv[idx]->ar_symbol_name,
				fcoff,&strbuf);

			if (symname) {
				if (slbt_snprintf(*namebuf,sizeof(*namebuf),
						"%s\",",symname) < 0)
					return SLBT_SYSTEM_ERROR(mctx->dctx);

				if (slbt_dprintf(fdout,fmt,
						*namebuf,
						(stype == 'T') ? "&" : "",
						symname) < 0)
					return SLBT_NESTED_ERROR(mctx->dctx);
			}
		}
	}

	return 0;
}


static int slbt_ar_output_dlsyms_impl(
	int                                 fdout,
	const struct slbt_driver_ctx *      dctx,
	struct slbt_archive_ctx **          arctxv,
	const char *                        dsounit)
{
	int                                 ret;
	int                                 idx;
	unsigned                            len;
	unsigned                            cmp;
	const char *                        arname;
	const char *                        soname;
	struct slbt_archive_ctx *           actx;
	struct slbt_archive_ctx **          parctx;
	struct slbt_archive_ctx_impl *      ictx;
	struct slbt_archive_meta_impl *     mctx;
	const struct slbt_source_version *  verinfo;
	char                                dlsymfmt[32];
	char                                cline[6][73];
	char                                symname[4096];

	/* init */
	actx    = arctxv[0];
	verinfo = slbt_api_source_version();

	/* preamble */
	memset(cline[0],'*',72);
	memset(cline[1],' ',72);
	memset(cline[2],' ',72);
	memset(cline[3],' ',72);
	memset(cline[4],'*',72);

	memset(cline[5],0,72);
	cline[5][0] = '\n';

	len = snprintf(&cline[1][3],69,
		"backward-compatible dlsym table");

	cline[1][3+len] = ' ';

	len = snprintf(&cline[2][3],69,
		"Generated by %s (slibtool %d.%d.%d)",
		dctx->x_program,
		verinfo->v_major,verinfo->v_minor,verinfo->v_revision);

	cline[2][3+len] = ' ';

	len = snprintf(&cline[3][3],69,
		"[commit reference: %s]",
		verinfo->v_commit);

	cline[3][3+len] = ' ';

	for (idx=0; idx<5; idx++) {
		cline[idx][0] = '/';
		cline[idx][1] = '*';

		cline[idx][70] = '*';
		cline[idx][71] = '/';

		cline[idx][72] = '\n';
	}

	if (slbt_dprintf(fdout,"%s",&cline[0]) < 0)
		return SLBT_SYSTEM_ERROR(dctx);

	if (slbt_dprintf(fdout,
			"#ifdef __cplusplus\n"
			"extern \"C\" {\n"
			"#endif\n\n") < 0)
		return SLBT_SYSTEM_ERROR(dctx);

	/* declarations */
	for (parctx=arctxv; *parctx; parctx++) {
		actx   = *parctx;
		ictx   = slbt_get_archive_ictx(actx);
		mctx   = slbt_archive_meta_ictx(ictx->meta);

		if ((arname = strrchr(*actx->x_path,'/')))
			arname++;

		if (!arname)
			arname = *actx->x_path;

		ret  = slbt_ar_dlsyms_define_by_type(fdout,arname,mctx,"Data Symbols: Absolute Values",     'A');
		ret |= slbt_ar_dlsyms_define_by_type(fdout,arname,mctx,"Data Symbols: BSS Section",         'B');
		ret |= slbt_ar_dlsyms_define_by_type(fdout,arname,mctx,"Data Symbols: Common Section",      'C');
		ret |= slbt_ar_dlsyms_define_by_type(fdout,arname,mctx,"Data Symbols: Initialized Data",    'D');

		ret |= slbt_ar_dlsyms_define_by_type(fdout,arname,mctx,"Data Symbols: Small Globals",       'G');
		ret |= slbt_ar_dlsyms_define_by_type(fdout,arname,mctx,"Data Symbols: Indirect References", 'I');
		ret |= slbt_ar_dlsyms_define_by_type(fdout,arname,mctx,"Data Symbols: Read-Only Section",   'R');

		ret |= slbt_ar_dlsyms_define_by_type(fdout,arname,mctx,"Data Symbols: Small Objects",       'S');
		ret |= slbt_ar_dlsyms_define_by_type(fdout,arname,mctx,"Data Symbols: Weak Symbols",        'W');

		ret |= slbt_ar_dlsyms_define_by_type(fdout,arname,mctx,"Text Section: Public Interfaces",   'T');

		if (ret < 0)
			return SLBT_NESTED_ERROR(dctx);

	}

	/* vtable struct definition */
	if (slbt_dprintf(fdout,
			"/* name-address Public ABI struct definition */\n"
			"struct lt_dlsym_symdef {\n"
			"\tconst char *   dlsym_name;\n"
			"\tvoid *         dlsym_addr;\n"
			"};\n\n") < 0)
		return SLBT_NESTED_ERROR(dctx);

	soname = (strcmp(dsounit,"@PROGRAM@")) ? dsounit : "_PROGRAM_";

	if (slbt_dprintf(fdout,
			"/* dlsym vtable */\n"
			"extern const struct lt_dlsym_symdef "
			"lt_%s_LTX_preloaded_symbols[];\n\n"
			"const struct lt_dlsym_symdef "
			"lt_%s_LTX_preloaded_symbols[] = {\n",
			soname,soname) < 0)
		return SLBT_NESTED_ERROR(dctx);

	/* align dlsym_name and dlsym_addr columsn (because we can) */
	for (parctx=arctxv,len=0; *parctx; parctx++) {
		actx = *parctx;
		ictx = slbt_get_archive_ictx(actx);
		mctx = slbt_archive_meta_ictx(ictx->meta);

		if ((arname = strrchr(*actx->x_path,'/')))
			arname++;

		if (!arname)
			arname = *actx->x_path;

		if (len < (cmp = strlen(arname)))
			len = cmp;

		len  = slbt_ar_dlsyms_get_max_len_by_type(len,mctx,'A');
		len  = slbt_ar_dlsyms_get_max_len_by_type(len,mctx,'B');
		len  = slbt_ar_dlsyms_get_max_len_by_type(len,mctx,'C');
		len  = slbt_ar_dlsyms_get_max_len_by_type(len,mctx,'D');

		len  = slbt_ar_dlsyms_get_max_len_by_type(len,mctx,'G');
		len  = slbt_ar_dlsyms_get_max_len_by_type(len,mctx,'I');
		len  = slbt_ar_dlsyms_get_max_len_by_type(len,mctx,'R');

		len  = slbt_ar_dlsyms_get_max_len_by_type(len,mctx,'S');
		len  = slbt_ar_dlsyms_get_max_len_by_type(len,mctx,'T');
		len  = slbt_ar_dlsyms_get_max_len_by_type(len,mctx,'W');
	}

	/* quote, comma */
	len += 2;

	if (len >= sizeof(symname))
		return SLBT_CUSTOM_ERROR(
			dctx,
			SLBT_ERR_FLOW_ERROR);

	/* aligned print format */
	snprintf(dlsymfmt,sizeof(dlsymfmt),"\t{\"%%-%ds %%s%%s},\n",len);

	/* dso unit */
	if (slbt_snprintf(symname,sizeof(symname),"%s\",",dsounit) < 0)
		return SLBT_SYSTEM_ERROR(dctx);

	if (slbt_dprintf(fdout,dlsymfmt,symname,"","0") < 0)
		return SLBT_NESTED_ERROR(dctx);

	/* (-dlopen force) */
	if (!arctxv[0]->x_meta->a_memberv)
		if (!strcmp(*arctxv[0]->x_path,"@PROGRAM@"))
			arctxv++;

	/* at long last */
	for (parctx=arctxv; *parctx; parctx++) {
		actx = *parctx;
		ictx = slbt_get_archive_ictx(actx);
		mctx = slbt_archive_meta_ictx(ictx->meta);

		if ((arname = strrchr(*actx->x_path,'/')))
			arname++;

		if (!arname)
			arname = *actx->x_path;

		if (slbt_dprintf(fdout,"\n") < 0)
			return SLBT_NESTED_ERROR(mctx->dctx);

		if (slbt_snprintf(symname,sizeof(symname),"%s\",",arname) < 0)
			return SLBT_SYSTEM_ERROR(mctx->dctx);

		if (slbt_dprintf(fdout,dlsymfmt,symname,"","0") < 0)
			return SLBT_NESTED_ERROR(mctx->dctx);

		ret  = slbt_ar_dlsyms_add_by_type(fdout,mctx,dlsymfmt,'A',&symname);
		ret |= slbt_ar_dlsyms_add_by_type(fdout,mctx,dlsymfmt,'B',&symname);
		ret |= slbt_ar_dlsyms_add_by_type(fdout,mctx,dlsymfmt,'C',&symname);
		ret |= slbt_ar_dlsyms_add_by_type(fdout,mctx,dlsymfmt,'D',&symname);

		ret |= slbt_ar_dlsyms_add_by_type(fdout,mctx,dlsymfmt,'G',&symname);
		ret |= slbt_ar_dlsyms_add_by_type(fdout,mctx,dlsymfmt,'I',&symname);
		ret |= slbt_ar_dlsyms_add_by_type(fdout,mctx,dlsymfmt,'R',&symname);

		ret |= slbt_ar_dlsyms_add_by_type(fdout,mctx,dlsymfmt,'S',&symname);
		ret |= slbt_ar_dlsyms_add_by_type(fdout,mctx,dlsymfmt,'S',&symname);
		ret |= slbt_ar_dlsyms_add_by_type(fdout,mctx,dlsymfmt,'T',&symname);

		if (ret < 0)
			return SLBT_NESTED_ERROR(dctx);
	}

	/* null-terminate the vtable */
	if (slbt_dprintf(fdout,"\n\t{%d,%*c%d}\n",0,len,' ',0) < 0)
		return SLBT_NESTED_ERROR(mctx->dctx);

	/* close vtable, wrap translation unit */
	if (slbt_dprintf(fdout,
			"};\n\n"
			"#ifdef __cplusplus\n"
			"}\n"
			"#endif\n") < 0)
		return SLBT_SYSTEM_ERROR(dctx);

	return 0;
}


static int slbt_ar_create_dlsyms_impl(
	struct slbt_archive_ctx **        arctxv,
	const char *                      dlunit,
	const char *                      path,
	mode_t                            mode)
{
	int                               ret;
	struct slbt_archive_ctx **        actx;
	struct slbt_exec_ctx *            ectx;
	struct slbt_archive_meta_impl *   mctx;
	const struct slbt_driver_ctx *    dctx;
	struct slbt_fd_ctx                fdctx;
	int                               fdout;

	mctx = slbt_archive_meta_ictx(arctxv[0]->x_meta);
	dctx = mctx->dctx;
	ectx = 0;

	if (slbt_lib_get_driver_fdctx(dctx,&fdctx) < 0)
		return SLBT_NESTED_ERROR(dctx);

	if (path) {
		slbt_driver_set_ectx(dctx,0,path);

		if ((fdout = openat(
				fdctx.fdcwd,path,
				O_WRONLY|O_CREAT|O_TRUNC,
				mode)) < 0)
			return SLBT_SYSTEM_ERROR(dctx);
	} else {
		fdout = fdctx.fdout;
	}

	for (actx=arctxv; *actx; actx++) {
		mctx = slbt_archive_meta_ictx((*actx)->x_meta);

		if (!mctx->syminfo && !ectx)
			if (slbt_ectx_get_exec_ctx(dctx,&ectx) < 0)
				return SLBT_NESTED_ERROR(dctx);

		if (!mctx->syminfo)
			if (slbt_ar_update_syminfo(*actx) < 0)
				return SLBT_NESTED_ERROR(dctx);
	}

	if (ectx)
		slbt_ectx_free_exec_ctx(ectx);

	ret = slbt_ar_output_dlsyms_impl(
		fdout,dctx,arctxv,dlunit);

	if (path) {
		close(fdout);
	}

	return ret;
}


int slbt_ar_create_dlsyms(
	struct slbt_archive_ctx **  arctxv,
	const char *                dlunit,
	const char *                path,
	mode_t                      mode)
{
	return slbt_ar_create_dlsyms_impl(arctxv,dlunit,path,mode);
}
