/*******************************************************************/
/*  slibtool: a strong libtool implementation, written in C        */
/*  Copyright (C) 2016--2025  SysDeer Technologies, LLC            */
/*  Released under the Standard MIT License; see COPYING.SLIBTOOL. */
/*******************************************************************/

#include <stdint.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#include <slibtool/slibtool.h>
#include "slibtool_driver_impl.h"
#include "slibtool_mkdir_impl.h"
#include "slibtool_linkcmd_impl.h"
#include "slibtool_errinfo_impl.h"
#include "slibtool_ar_impl.h"

#define SLBT_ECTX_LIB_EXTRAS	26
#define SLBT_ECTX_SPARE_PTRS	16

static int slbt_ectx_free_exec_ctx_impl(
	struct slbt_exec_ctx_impl *	ictx,
	int				status);

static size_t slbt_parse_comma_separated_flags(
	const char *	str,
	int *		argc)
{
	const char * ch;

	for (ch=str; *ch; ch++)
		if (*ch == ',')
			(*argc)++;

	return ch - str;
}


static char * slbt_source_file(char ** argv)
{
	char **	parg;
	char *	ch;

	for (parg=argv; *parg; parg++)
		if ((ch = strrchr(*parg,'.')))
			if ((!(strcmp(++ch,"s")))
					|| (!(strcmp(ch,"S")))
					|| (!(strcmp(ch,"asm")))
					|| (!(strcmp(ch,"c")))
					|| (!(strcmp(ch,"cc")))
					|| (!(strcmp(ch,"cpp")))
					|| (!(strcmp(ch,"cxx"))))
				return *parg;
	return 0;
}


static int slbt_exec_ctx_tool_argc(char ** argv)
{
	char ** parg;

	if (!(parg = argv))
		return 0;

	for (; *parg; )
		parg++;

	return parg - argv + 1;
}


static struct slbt_exec_ctx_impl * slbt_exec_ctx_alloc(
	const struct slbt_driver_ctx *	dctx)
{
	struct slbt_driver_ctx_impl *   ctx;
	struct slbt_exec_ctx_impl *	ictx;
	size_t				size;
	size_t                          slen;
	size_t                          exts;
	int				argc;
	char *				args;
	char *				shadow;
	char *				csrc;
	char **				parg;
	struct slbt_archive_ctx **      dlactxv;
	size_t                          ndlopen;

	/* internal driver context for host-specific tool arguments */
	ctx = slbt_get_driver_ictx(dctx);

	/* initial buffer size (cargv, -Wc), .libs/.exe.wrapper */
	argc = 0;
	csrc = 0;
	size = 0;
	exts = 20;

	for (parg=dctx->x_cctx->x_cargv; *parg; parg++, argc++) {
		if (!(strncmp("-Wc,",*parg,4))) {
			size += slbt_parse_comma_separated_flags(
				&(*parg)[4],&argc) + 1;
		} else {
			size += strlen(*parg) + 1;
		}
	}

	/* argument transformation: assume for each argv member */
	if (dctx->x_cctx->x_shrext) {
		exts += argc * (strlen(dctx->x_cctx->x_shrext));
	}

	if (dctx->x_cctx->x_settings.fa_dsosuffix) {
		exts += argc * (strlen(dctx->x_cctx->x_settings.fa_dsosuffix));
	}

	size += argc * exts;

	/* buffer size (csrc, ldirname, lbasename, lobjname, aobjname, etc.) */
	if (dctx->x_cctx->x_libname) {
		slen  = strlen(dctx->x_cctx->x_libname);
		size += (strlen(".slibtool.expsyms.extension") + slen + exts + 1) * SLBT_ECTX_LIB_EXTRAS;

	} else if (dctx->x_cctx->x_output) {
		slen  = strlen(dctx->x_cctx->x_output);
		size += (strlen(".slibtool.expsyms.extension") + slen + exts + 1) * SLBT_ECTX_LIB_EXTRAS;

	} else if ((csrc = slbt_source_file(dctx->x_cctx->x_cargv))) {
		slen  = strlen(csrc);
		size += (strlen(".slibtool.expsyms.extension") + slen + exts + 1) * SLBT_ECTX_LIB_EXTRAS;
	} else {
		size += exts * SLBT_ECTX_LIB_EXTRAS;
	}

	/* -lsltdl (--prefer-sltdl impl.) */
	size += 8;

	/* string buffers: args, shadow */
	if (!(args = malloc(size)))
		return 0;

	if (!(shadow = malloc(size))) {
		free(args);
		return 0;
	}

	/* tool-specific argv: to simplify matters, be additive */
	argc += slbt_exec_ctx_tool_argc(ctx->host.ar_argv);
	argc += slbt_exec_ctx_tool_argc(ctx->host.as_argv);
	argc += slbt_exec_ctx_tool_argc(ctx->host.nm_argv);
	argc += slbt_exec_ctx_tool_argc(ctx->host.ranlib_argv);
	argc += slbt_exec_ctx_tool_argc(ctx->host.windres_argv);
	argc += slbt_exec_ctx_tool_argc(ctx->host.dlltool_argv);
	argc += slbt_exec_ctx_tool_argc(ctx->host.mdso_argv);

	/* argv transformation: .libs/libfoo.so --> -L.libs -lfoo */
	argc *= 2;

	/* argv ad-hoc extensions */
	argc += SLBT_ECTX_SPARE_PTRS;

	/* ctx alloc and vector alloc: argv, xargv, and altv, where we  */
	/* assume -Wl,--whole-archive arg -Wl,--no-whole-archive;      */
	/* and also dlargv for compiling dlunit.dlopen.c              */
	if (!(ictx = calloc(1,sizeof(*ictx)))) {
		free(args);
		free(shadow);
		return 0;
	}

	if (!(ictx->vbuffer = calloc(6*(argc+1),sizeof(char *)))) {
		free(args);
		free(shadow);
		free(ictx);
	}

	if ((ndlopen = (slbt_get_driver_ictx(dctx))->ndlopen)) {
		if (!(dlactxv = calloc(ndlopen+1,sizeof(*dlactxv)))) {
			free(ictx->vbuffer);
			free(ictx);
			free(args);
			free(shadow);
		}

		ictx->dlactxv = dlactxv;
	}

	/* all ready */
	ictx->dctx = dctx;
	ictx->args = args;
	ictx->argc = argc;

	ictx->size   = size;
	ictx->exts   = exts;
	ictx->shadow = shadow;

	ictx->ctx.x_csrc  = csrc;
	ictx->fdwrapper = (-1);

	ictx->ctx.x_envp  = slbt_driver_envp(dctx);

	return ictx;
}


int  slbt_ectx_get_exec_ctx(
	const struct slbt_driver_ctx *	dctx,
	struct slbt_exec_ctx **		ectx)
{
	struct slbt_exec_ctx_impl *	ictx;
	struct slbt_driver_ctx_impl *   idctx;
	const struct slbt_error_info**  errinfp;
	char **				parg;
	char **				src;
	char **				dst;
	char *				ch;
	char *				mark;
	const char *			dmark;
	const char *                    dsoext;
	char *				slash;
	char *                          arname;
	struct slbt_archive_ctx **      dlactxv;
	struct argv_entry *             dlentry;
	struct argv_entry **            dlopenv;
	bool                            fpreopen;
	const char *			arprefix;
	const char *			dsoprefix;
	const char *			impprefix;
	const char *			ref;
	int				i;

	/* internal driver context */
	idctx = slbt_get_driver_ictx(dctx);

	/* alloc */
	if (!(ictx = slbt_exec_ctx_alloc(dctx)))
		return SLBT_NESTED_ERROR(dctx);

	/* init with guard for later .lo check */
	ch                = ictx->args + strlen(".lo");
	ictx->ctx.x_argv    = ictx->vbuffer;
	ictx->ctx.x_xargv   = &ictx->ctx.x_argv [ictx->argc + 1];
	ictx->ctx.x_altv    = &ictx->ctx.x_xargv[ictx->argc + 1];
	ictx->dlargv      = &ictx->ctx.x_altv [ictx->argc + 1];

	/* <compiler> */
	ictx->ctx.x_compiler = dctx->x_cctx->x_cargv[0];
	ictx->ctx.x_cargv    = ictx->ctx.x_argv;

	/* ldirname, lbasename */
	ref = (dctx->x_cctx->x_output)
		? dctx->x_cctx->x_output
		: ictx->ctx.x_csrc;

	if (ref && !ictx->ctx.x_csrc && (mark = strrchr(ref,'/'))) {
		if (!(strncmp(ref,"../",3)))
			dmark = 0;
		else if (!(strncmp(ref,"./",2)))
			dmark = &ref[1];
		else
			dmark = strchr(ref,'/');

		for (; dmark; ) {
			if (!(strncmp(dmark,"/./",3))) {
				dmark = strchr(&dmark[2],'/');
			} else if (!(strncmp(dmark,"/../",4))) {
				ictx->ctx.x_ldirdepth = -1;
				dmark = 0;
			} else {
				for (; *dmark=='/'; )
					dmark++;

				ictx->ctx.x_ldirdepth++;
				dmark = strchr(dmark,'/');
			}
		}

		ictx->ctx.x_ldirname = ch;
		strcpy(ch,ref);
		ch += mark - ref;
		ch += sprintf(ch,"%s","/.libs/");
		ch++;

		ictx->ctx.x_lbasename = ch;
		ch += sprintf(ch,"%s",++mark);
		ch++;
	} else if (ref) {
		ictx->ctx.x_ldirname = ch;
		ch += sprintf(ch,"%s",".libs/");
		ch++;

		ictx->ctx.x_lbasename = ch;
		mark = strrchr(ref,'/');
		ch += sprintf(ch,"%s",mark ? ++mark : ref);
		ch++;
	}

	/* lbasename suffix */
	if (ref && (dctx->x_cctx->x_mode == SLBT_MODE_COMPILE)) {
		if ((ch[-4] == '.') && (ch[-3] == 'l') && (ch[-2] == 'o')) {
			ch[-3] = 'o';
			ch[-2] = 0;
			ch--;
		} else if (ictx->ctx.x_csrc) {
			if ((mark = strrchr(ictx->ctx.x_lbasename,'.'))) {
				ch    = mark;
				*++ch = 'o';
				*++ch = 0;
				ch++;
			}
		}
	}

	/* cargv, -Wc */
	for (i=0, parg=dctx->x_cctx->x_cargv; *parg; parg++, ch++) {
		if (!(strncmp("-Wc,",*parg,4))) {
			strcpy(ch,&(*parg)[4]);
			ictx->ctx.x_argv[i++] = ch;

			for (; *ch; ch++)
				if (*ch == ',') {
					*ch++ = 0;
					ictx->ctx.x_argv[i++] = ch;
				}
		} else {
			ictx->ctx.x_argv[i++] = ch;
			ch += sprintf(ch,"%s",*parg);
			ch += ictx->exts;
		}
	}

	/* placeholders for -DPIC, -fPIC, -c, -o, <output> */
	ictx->ctx.x_dpic = &ictx->ctx.x_argv[i++];
	ictx->ctx.x_fpic = &ictx->ctx.x_argv[i++];
	ictx->ctx.x_cass = &ictx->ctx.x_argv[i++];

	ictx->ctx.x_noundef = &ictx->ctx.x_argv[i++];
	ictx->ctx.x_soname  = &ictx->ctx.x_argv[i++];
	ictx->ctx.x_lsoname = &ictx->ctx.x_argv[i++];
	ictx->ctx.x_symdefs = &ictx->ctx.x_argv[i++];
	ictx->ctx.x_symfile = &ictx->ctx.x_argv[i++];
	ictx->ctx.x_explarg = &ictx->ctx.x_argv[i++];
	ictx->ctx.x_expsyms = &ictx->ctx.x_argv[i++];

	ictx->ctx.x_lout[0] = &ictx->ctx.x_argv[i++];
	ictx->ctx.x_lout[1] = &ictx->ctx.x_argv[i++];

	ictx->ctx.x_rpath[0] = &ictx->ctx.x_argv[i++];
	ictx->ctx.x_rpath[1] = &ictx->ctx.x_argv[i++];

	ictx->ctx.x_sentinel= &ictx->ctx.x_argv[i++];

	slbt_reset_placeholders(&ictx->ctx);

	/* dsoprefix */
	if (dctx->x_cctx->x_settings.fa_dsoprefix) {
		ictx->dsoprefix = ch;
		strcpy(ch,dctx->x_cctx->x_settings.fa_dsoprefix);
		ch += strlen(ch) + 1;
	}

	/* output file name */
	if (ref && ((dctx->x_cctx->x_mode == SLBT_MODE_COMPILE))) {
		*ictx->ctx.x_lout[0] = "-o";
		*ictx->ctx.x_lout[1] = ch;
		ictx->ctx.x_lobjname = ch;

		ch += sprintf(ch,"%s%s",
			ictx->ctx.x_ldirname,
			ictx->ctx.x_lbasename)
			+ 1;

		ictx->ctx.x_aobjname = ch;

		ch += sprintf(ch,"%s",ictx->ctx.x_ldirname);
		ch -= strlen(".libs/");
		ch += sprintf(ch,"%s",
			ictx->ctx.x_lbasename)
			+ 1;

		ictx->ctx.x_ltobjname = ch;
		strcpy(ch,ictx->ctx.x_aobjname);

		if ((mark = strrchr(ch,'.')))
			ch = mark + sprintf(mark,"%s",".lo")
				+ 1;
	}

	/* linking: arfilename, lafilename, laifilename, dsobasename, dsofilename, mapfilename */
	if (dctx->x_cctx->x_mode == SLBT_MODE_LINK && dctx->x_cctx->x_libname) {
		if (!(dsoext = dctx->x_cctx->x_shrext))
			dsoext = dctx->x_cctx->x_settings.fa_dsosuffix;

		/* arprefix, dsoprefix */
		if (dctx->x_cctx->x_drvflags & SLBT_DRIVER_MODULE) {
			ictx->ctx.x_sonameprefix = "";
			arprefix  = "";
			dsoprefix = "";
			impprefix = "";
		} else {
			ictx->ctx.x_sonameprefix = ictx->dsoprefix;
			arprefix  = dctx->x_cctx->x_settings.fa_arprefix;
			dsoprefix = dctx->x_cctx->x_settings.fa_dsoprefix;
			impprefix = dctx->x_cctx->x_settings.fa_impprefix;
		}

		/* arfilename */
		ictx->ctx.x_arfilename = ch;
		ch += sprintf(ch,"%s%s%s%s",
				ictx->ctx.x_ldirname,
				arprefix,
				dctx->x_cctx->x_libname,
				dctx->x_cctx->x_settings.fa_arsuffix);
		ch++;



		/* lafilename */
		ictx->ctx.x_lafilename = ch;
		ch += sprintf(ch,"%s%s%s.la",
				ictx->ctx.x_ldirname,
				dsoprefix,
				dctx->x_cctx->x_libname);
		ch++;


		/* laifilename */
		ictx->ctx.x_laifilename = ch;
		ch += sprintf(ch,"%s%s%s.lai",
				ictx->ctx.x_ldirname,
				dsoprefix,
				dctx->x_cctx->x_libname);
		ch++;


		/* dsobasename */
		ictx->ctx.x_dsobasename = ch;
		ch += sprintf(ch,"%s%s%s",
				ictx->ctx.x_ldirname,
				dsoprefix,
				dctx->x_cctx->x_libname);
		ch++;

		/* dsofilename */
		ictx->ctx.x_dsofilename = ch;
		ch += sprintf(ch,"%s%s%s%s",
				ictx->ctx.x_ldirname,
				dsoprefix,
				dctx->x_cctx->x_libname,
				dsoext);
		ch++;

		/* mapfilename */
		ictx->ctx.x_mapfilename = ch;
		ch += sprintf(ch,"%s%s%s%s%s%s",
				ictx->ctx.x_ldirname,
				dsoprefix,
				dctx->x_cctx->x_libname,
				dctx->x_cctx->x_release ? "-" : "",
				dctx->x_cctx->x_release ? dctx->x_cctx->x_release : "",
				dctx->x_cctx->x_settings.fa_mapsuffix);
		ch++;

		/* deffilename */
		ictx->ctx.x_deffilename = ch;
		ch += sprintf(ch,"%s%s%s%s%s%s.def",
				ictx->ctx.x_ldirname,
				dsoprefix,
				dctx->x_cctx->x_libname,
				dctx->x_cctx->x_release ? "-" : "",
				dctx->x_cctx->x_release ? dctx->x_cctx->x_release : "",
				dsoext);
		ch++;

		/* rpathfilename */
		ictx->ctx.x_rpathfilename = ch;
		ch += sprintf(ch,"%s%s%s%s.slibtool.rpath",
				ictx->ctx.x_ldirname,
				dsoprefix,
				dctx->x_cctx->x_libname,
				dsoext);
		ch++;

		/* default implib file name */
		ictx->ctx.x_dimpfilename = ch;
		ch += sprintf(ch,"%s%s%s%s",
				ictx->ctx.x_ldirname,
				impprefix,
				dctx->x_cctx->x_libname,
				dctx->x_cctx->x_settings.fa_impsuffix);
		ch++;


		/* primary implib file name */
		ictx->ctx.x_pimpfilename = ch;
		ch += sprintf(ch,"%s%s%s%s%s.%d%s",
				ictx->ctx.x_ldirname,
				impprefix,
				dctx->x_cctx->x_libname,
				dctx->x_cctx->x_release ? "-" : "",
				dctx->x_cctx->x_release ? dctx->x_cctx->x_release : "",
				dctx->x_cctx->x_verinfo.vi_major,
				dctx->x_cctx->x_settings.fa_impsuffix);
		ch++;

		/* versioned implib file name */
		ictx->ctx.x_vimpfilename = ch;
		ch += sprintf(ch,"%s%s%s%s%s.%d.%d.%d%s",
				ictx->ctx.x_ldirname,
				impprefix,
				dctx->x_cctx->x_libname,
				dctx->x_cctx->x_release ? "-" : "",
				dctx->x_cctx->x_release ? dctx->x_cctx->x_release : "",
				dctx->x_cctx->x_verinfo.vi_major,
				dctx->x_cctx->x_verinfo.vi_minor,
				dctx->x_cctx->x_verinfo.vi_revision,
				dctx->x_cctx->x_settings.fa_impsuffix);
		ch++;

		/* relfilename */
		if (dctx->x_cctx->x_release) {
			ictx->ctx.x_relfilename = ch;
			ch += dctx->x_cctx->x_verinfo.vi_verinfo
				? sprintf(ch,"%s%s%s-%s%s.%d.%d.%d%s",
					ictx->ctx.x_ldirname,
					dsoprefix,
					dctx->x_cctx->x_libname,
					dctx->x_cctx->x_release,
					dctx->x_cctx->x_settings.fa_osdsuffix,
					dctx->x_cctx->x_verinfo.vi_major,
					dctx->x_cctx->x_verinfo.vi_minor,
					dctx->x_cctx->x_verinfo.vi_revision,
					dctx->x_cctx->x_settings.fa_osdfussix)
				: sprintf(ch,"%s%s%s-%s%s",
					ictx->ctx.x_ldirname,
					dsoprefix,
					dctx->x_cctx->x_libname,
					dctx->x_cctx->x_release,
					dsoext);
			ch++;
		}

		/* dsorellnkname */
		if (dctx->x_cctx->x_release) {
			ictx->ctx.x_dsorellnkname = ch;
			ch += sprintf(ch,"%s%s%s-%s%s",
					ictx->ctx.x_ldirname,
					dsoprefix,
					dctx->x_cctx->x_libname,
					dctx->x_cctx->x_release,
					dsoext);
			ch++;
		}

		/* dlopensrc, dlopenobj */
		if (idctx->dlopenv) {
			ictx->ctx.x_dlopensrc = ch;
			ch += sprintf(ch,"%s%s%s.dlopen.c",
					ictx->ctx.x_ldirname,
					dsoprefix,
					dctx->x_cctx->x_libname);

			ch++;

			ictx->ctx.x_dlopenobj = ch;
			ch += sprintf(ch,"%s%s%s.dlopen.o",
					ictx->ctx.x_ldirname,
					dsoprefix,
					dctx->x_cctx->x_libname);

			ch++;

			ictx->ctx.x_dlpreopen = ch;
			ch += sprintf(ch,"%s%s%s.dlpreopen.a",
					ictx->ctx.x_ldirname,
					dsoprefix,
					dctx->x_cctx->x_libname);

			ch++;

			ictx->ctx.x_dlunit = ch;
			ch += sprintf(ch,"%s%s",
					dsoprefix,
					dctx->x_cctx->x_libname);

			ch++;
		}

	/* linking: exefilename */
	} else if (dctx->x_cctx->x_mode == SLBT_MODE_LINK) {
		ictx->ctx.x_exefilename = ch;

		if ((slash = strrchr(dctx->x_cctx->x_output,'/'))) {
			strcpy(ch,dctx->x_cctx->x_output);
			mark = ch + (slash - dctx->x_cctx->x_output);
			sprintf(++mark,".libs/%s",++slash);
			ch += strlen(ch) + 1;
		} else
			ch += sprintf(ch,".libs/%s",dctx->x_cctx->x_output) + 1;
	}

	/* dlopensrc, dlopenobj: executable program */
	if (idctx->dlopenv && !dctx->x_cctx->x_libname) {
		ictx->ctx.x_dlopensrc = ch;
		ch += sprintf(ch,"%s.dlopen.c",
				ictx->ctx.x_exefilename);

		ch++;

		ictx->ctx.x_dlopenobj = ch;
		ch += sprintf(ch,"%s.dlopen.o",
				ictx->ctx.x_exefilename);

		ch++;

		ictx->ctx.x_dlpreopen = ch;
		ch += sprintf(ch,"%s.dlpreopen.a",
				ictx->ctx.x_exefilename);

		ch++;

		ictx->ctx.x_dlunit = ch;
		ch += sprintf(ch,"%s",
				"@PROGRAM@");

		ch++;

		ictx->ctx.x_mapfilename = ch;
		ch += sprintf(ch,"%s%s",
				ictx->ctx.x_exefilename,
				dctx->x_cctx->x_settings.fa_mapsuffix);
		ch++;

	}

	/* -lsltdl (--prefer-sltdl impl.) */
	ictx->lsltdl = ch;
	strcpy(ch,"-lsltdl");
	ch += 8;

	/* dlopen, dlpreopen */
	if ((dlopenv = idctx->dlopenv), (dlactxv = ictx->dlactxv)) {
		if (slbt_ar_get_varchive_ctx(dctx,dlactxv) < 0)
			return slbt_ectx_free_exec_ctx_impl(
				ictx,
				SLBT_NESTED_ERROR(dctx));

		if (slbt_ar_update_syminfo(*dlactxv) < 0)
			return slbt_ectx_free_exec_ctx_impl(
				ictx,
				SLBT_NESTED_ERROR(dctx));

		dlactxv++;

		for (; *dlopenv; ) {
			dlentry  = *dlopenv;
			fpreopen = (dlentry->tag == TAG_DLPREOPEN);

			arname = ictx->sbuf;
			strcpy(arname,dlentry->arg);

			slbt_adjust_wrapper_argument(
				arname,true,
				".expsyms.a");

			errinfp = idctx->errinfp;

			if (slbt_ar_get_archive_ctx(dctx,arname,dlactxv) < 0) {
				if ((*errinfp)->esyscode != ENOENT)
					return slbt_ectx_free_exec_ctx_impl(
						ictx,
						SLBT_NESTED_ERROR(dctx));

				strcpy(arname,dlentry->arg);

				slbt_adjust_wrapper_argument(
					arname,true,
					dctx->x_cctx->x_settings.fa_arsuffix);

				if (slbt_ar_get_archive_ctx(dctx,arname,dlactxv) < 0)
					return slbt_ectx_free_exec_ctx_impl(
						ictx,
						SLBT_NESTED_ERROR(dctx));

				idctx->errinfp = errinfp;

				for (; *errinfp; )
					*errinfp++ = 0;

				fpreopen = true;
			}

			if (fpreopen) {
				if (slbt_ar_update_syminfo(*dlactxv) < 0)
					return slbt_ectx_free_exec_ctx_impl(
						ictx,
						SLBT_NESTED_ERROR(dctx));

				dlactxv++;
			} else {
				slbt_ar_free_archive_ctx(*dlactxv);
				*dlactxv = 0;
			}

			dlopenv++;
		}

		slbt_driver_set_ectx(
			dctx,0,
			ictx->ctx.x_ldirname);

		if (slbt_mkdir(dctx,ictx->ctx.x_ldirname) < 0)
			return slbt_ectx_free_exec_ctx_impl(
				ictx,
				SLBT_SYSTEM_ERROR(
					dctx));

		if (slbt_ar_create_dlsyms(
					ictx->dlactxv,
					ictx->ctx.x_dlunit,
					ictx->ctx.x_dlopensrc,
					0644) < 0)
				return slbt_ectx_free_exec_ctx_impl(
					ictx,
					SLBT_NESTED_ERROR(dctx));

		if (slbt_ar_merge_archives(ictx->dlactxv,&ictx->dlpreopen) < 0)
				return slbt_ectx_free_exec_ctx_impl(
					ictx,
					SLBT_NESTED_ERROR(dctx));

		if (slbt_ar_store_archive(ictx->dlpreopen,ictx->ctx.x_dlpreopen,0644) < 0)
				return slbt_ectx_free_exec_ctx_impl(
					ictx,
					SLBT_NESTED_ERROR(dctx));
	}

	/* vector of exported symbols (raw input via -export-symbols) */
	if (dctx->x_cctx->x_expsyms)
		if (slbt_lib_get_symlist_ctx(
				dctx,dctx->x_cctx->x_expsyms,
				&ictx->sctx) < 0)
			return SLBT_NESTED_ERROR(dctx);

	/* argument strings shadow copy */
	memcpy(ictx->shadow,ictx->args,ictx->size);

	/* compile mode: argument vector shadow copy */
	if (dctx->x_cctx->x_mode == SLBT_MODE_COMPILE)
		for (src=ictx->ctx.x_argv, dst=ictx->ctx.x_xargv; *src; src++, dst++)
			*dst = *src;

	/* save the full vector's lout, mout */
	ictx->lout[0] = ictx->ctx.x_lout[0];
	ictx->lout[1] = ictx->ctx.x_lout[1];

	ictx->mout[0] = ictx->ctx.x_mout[0];
	ictx->mout[1] = ictx->ctx.x_mout[1];

	/* all done */
	*ectx = &ictx->ctx;
	return 0;
}


static int slbt_ectx_free_exec_ctx_impl(
	struct slbt_exec_ctx_impl *	ictx,
	int				status)
{
	struct slbt_archive_ctx ** dlactxv;

	if (ictx->sctx)
		slbt_lib_free_symlist_ctx(ictx->sctx);

	if (ictx->fdwrapper >= 0)
		close(ictx->fdwrapper);

	if (ictx->dlactxv) {
		for (dlactxv=ictx->dlactxv; *dlactxv; dlactxv++)
			slbt_ar_free_archive_ctx(*dlactxv);

		free(ictx->dlactxv);
	}

	free(ictx->args);
	free(ictx->shadow);
	free(ictx->vbuffer);
	free (ictx);

	return status;
}


void slbt_ectx_free_exec_ctx(struct slbt_exec_ctx * ctx)
{
	struct slbt_exec_ctx_impl *	ictx;
	uintptr_t			addr;

	if (ctx) {
		addr = (uintptr_t)ctx - offsetof(struct slbt_exec_ctx_impl,ctx);
		ictx = (struct slbt_exec_ctx_impl *)addr;
		slbt_ectx_free_exec_ctx_impl(ictx,0);
	}
}


void slbt_ectx_reset_arguments(struct slbt_exec_ctx * ectx)
{
	struct slbt_exec_ctx_impl *	ictx;
	uintptr_t			addr;

	addr = (uintptr_t)ectx - offsetof(struct slbt_exec_ctx_impl,ctx);
	ictx = (struct slbt_exec_ctx_impl *)addr;
	memcpy(ictx->args,ictx->shadow,ictx->size);
}


void slbt_ectx_reset_argvector(struct slbt_exec_ctx * ectx)
{
	struct slbt_exec_ctx_impl *	ictx;
	uintptr_t			addr;
	char ** 			src;
	char ** 			dst;

	addr = (uintptr_t)ectx - offsetof(struct slbt_exec_ctx_impl,ctx);
	ictx = (struct slbt_exec_ctx_impl *)addr;

	for (src=ectx->x_xargv, dst=ectx->x_argv; *src; src++, dst++)
		*dst = *src;

	*dst = 0;

	ectx->x_lout[0] = ictx->lout[0];
	ectx->x_lout[1] = ictx->lout[1];

	ectx->x_mout[0] = ictx->mout[0];
	ectx->x_mout[1] = ictx->mout[1];
}


slbt_hidden void slbt_reset_placeholders(struct slbt_exec_ctx * ectx)
{
	struct slbt_exec_ctx_impl * ictx;

	ictx = slbt_get_exec_ictx(ectx);

	if (ictx->lout[0]) {
		ectx->x_lout[0] = ictx->lout[0];
		ectx->x_lout[1] = ictx->lout[1];
	}

	*ectx->x_dpic = "-USLIBTOOL_PLACEHOLDER_DPIC";
	*ectx->x_fpic = "-USLIBTOOL_PLACEHOLDER_FPIC";
	*ectx->x_cass = "-USLIBTOOL_PLACEHOLDER_COMPILE_ASSEMBLE";

	*ectx->x_noundef = "-USLIBTOOL_PLACEHOLDER_NO_UNDEFINED";
	*ectx->x_soname  = "-USLIBTOOL_PLACEHOLDER_SONAME";
	*ectx->x_lsoname = "-USLIBTOOL_PLACEHOLDER_LSONAME";
	*ectx->x_symdefs = "-USLIBTOOL_PLACEHOLDER_SYMDEF_SWITCH";
	*ectx->x_symfile = "-USLIBTOOL_PLACEHOLDER_SYMDEF_FILE";
	*ectx->x_explarg = "-USLIBTOOL_PLACEHOLDER_EXPSYMS_SWITCH";
	*ectx->x_expsyms = "-USLIBTOOL_PLACEHOLDER_EXPSYMS_FILE";

	*ectx->x_lout[0] = "-USLIBTOOL_PLACEHOLDER_OUTPUT_SWITCH";
	*ectx->x_lout[1] = "-USLIBTOOL_PLACEHOLDER_OUTPUT_FILE";

	*ectx->x_rpath[0] = "-USLIBTOOL_PLACEHOLDER_RPATH_SWITCH";
	*ectx->x_rpath[1] = "-USLIBTOOL_PLACEHOLDER_RPATH_DIR";

	ectx->x_mout[0]  = 0;
	ectx->x_mout[1]  = 0;

	*ectx->x_sentinel= 0;
}

slbt_hidden void slbt_disable_placeholders(struct slbt_exec_ctx * ectx)
{
	*ectx->x_dpic = 0;
	*ectx->x_fpic = 0;
	*ectx->x_cass = 0;

	*ectx->x_noundef = 0;
	*ectx->x_soname  = 0;
	*ectx->x_lsoname = 0;
	*ectx->x_symdefs = 0;
	*ectx->x_symfile = 0;
	*ectx->x_explarg = 0;
	*ectx->x_expsyms = 0;

	*ectx->x_lout[0] = 0;
	*ectx->x_lout[1] = 0;

	*ectx->x_rpath[0] = 0;
	*ectx->x_rpath[1] = 0;

	*ectx->x_sentinel= 0;
}
