/*******************************************************************/
/*  slibtool: a strong libtool implementation, written in C        */
/*  Copyright (C) 2016--2025  SysDeer Technologies, LLC            */
/*  Released under the Standard MIT License; see COPYING.SLIBTOOL. */
/*******************************************************************/

#include <stdint.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>

#include <slibtool/slibtool.h>
#include "slibtool_version.h"
#include "slibtool_driver_impl.h"
#include "slibtool_objlist_impl.h"
#include "slibtool_errinfo_impl.h"
#include "slibtool_visibility_impl.h"
#include "slibtool_stoolie_impl.h"
#include "slibtool_ar_impl.h"
#include "argv/argv.h"

static char * slbt_default_cargv[] = {"cc",0};

slbt_hidden int slbt_split_argv(
	char **				argv,
	uint64_t			flags,
	struct slbt_split_vector *	sargv,
	struct slbt_obj_list **		aobjlistv,
	int				fderr,
	int				fdcwd)
{
	int				i;
	int				argc;
	int				objc;
	const char *			program;
	char *				compiler;
	char *				csysroot;
	char **				dargv;
	char **				targv;
	char **				cargv;
	char **				objp;
	struct slbt_obj_list *		objlistv;
	struct slbt_obj_list *		objlistp;
	char *				dst;
	bool				flast;
	bool				fcopy;
	bool				altmode;
	bool				execmode;
	size_t				size;
	const char *			base;
	struct argv_meta *		meta;
	struct argv_entry *		entry;
	struct argv_entry *		mode;
	struct argv_entry *		help;
	struct argv_entry *		version;
	struct argv_entry *		info;
	struct argv_entry *		config;
	struct argv_entry *		finish;
	struct argv_entry *		features;
	struct argv_entry *		ccwrap;
	struct argv_entry *		dumpmachine;
	struct argv_entry *		printdir;
	struct argv_entry *		printext;
	struct argv_entry *		aropt;
	struct argv_entry *		stoolieopt;
	const struct argv_option **	popt;
	const struct argv_option **	optout;
	const struct argv_option *	optv[SLBT_OPTV_ELEMENTS];
	struct argv_ctx			ctx = {ARGV_VERBOSITY_NONE,
						ARGV_MODE_SCAN,
						0,0,0,0,0,0,0,0};

	program = slbt_program_name(argv[0]);

	/* missing arguments? */
	if ((altmode = (flags & SLBT_DRIVER_MODE_AR))) {
		slbt_optv_init(slbt_ar_options,optv);
	} else if ((altmode = (flags & SLBT_DRIVER_MODE_STOOLIE))) {
		slbt_optv_init(slbt_stoolie_options,optv);
	} else {
		slbt_optv_init(slbt_default_options,optv);
	}


	if (!argv[1] && !altmode && (flags & SLBT_DRIVER_VERBOSITY_USAGE))
		return slbt_driver_usage(
			fderr,program,
			0,optv,0,sargv,0,
			!!getenv("NO_COLOR"));

	/* initial argv scan: ... --mode=xxx ... <compiler> ... */
	slbt_argv_scan(argv,optv,&ctx,0);

	/* invalid slibtool arguments? */
	if (ctx.erridx && !ctx.unitidx && altmode) {
		if (flags & SLBT_DRIVER_VERBOSITY_ERRORS)
			slbt_argv_get(
				argv,optv,
				slbt_argv_flags(flags),
				fderr);
		return -1;
	}

	/* error possibly due to an altmode argument? */
	if (ctx.erridx && !ctx.unitidx)
		ctx.unitidx = ctx.erridx;

	/* obtain slibtool's own arguments */
	if (ctx.unitidx) {
		compiler = argv[ctx.unitidx];
		argv[ctx.unitidx] = 0;

		meta = slbt_argv_get(argv,optv,ARGV_VERBOSITY_NONE,fderr);
		argv[ctx.unitidx] = compiler;
	} else {
		meta = slbt_argv_get(argv,optv,ARGV_VERBOSITY_NONE,fderr);
	}

	if (!meta) {
		if (flags & SLBT_DRIVER_VERBOSITY_ERRORS)
			slbt_argv_get(
				argv,optv,
				slbt_argv_flags(flags),
				fderr);
		return -1;
	}

	/* missing all of --mode, --help, --version, --info, --config, --dumpmachine, --features, and --finish? */
	/* as well as -print-aux-dir and -print-m4-dir? */
	mode = help = version = info = config = finish = features = ccwrap = dumpmachine = printdir = printext = aropt = stoolieopt = 0;

	/* --mode=execute implies -- right after the executable path argument */
	execmode = false;

	for (entry=meta->entries; entry->fopt; entry++)
		if (entry->tag == TAG_MODE)
			mode = entry;
		else if (entry->tag == TAG_HELP)
			help = entry;
		else if (entry->tag == TAG_VERSION)
			version = entry;
		else if (entry->tag == TAG_INFO)
			info = entry;
		else if (entry->tag == TAG_CONFIG)
			config = entry;
		else if (entry->tag == TAG_FINISH)
			finish = entry;
		else if (entry->tag == TAG_FEATURES)
			features = entry;
		else if (entry->tag == TAG_CCWRAP)
			ccwrap = entry;
		else if (entry->tag == TAG_DUMPMACHINE)
			dumpmachine = entry;
		else if (entry->tag == TAG_PRINT_AUX_DIR)
			printdir = entry;
		else if (entry->tag == TAG_PRINT_M4_DIR)
			printdir = entry;
		else if (entry->tag == TAG_PRINT_SHARED_EXT)
			printext = entry;
		else if (entry->tag == TAG_PRINT_STATIC_EXT)
			printext = entry;

	/* alternate execusion mode? */
	if (!altmode && mode && !strcmp(mode->arg,"ar"))
		aropt = mode;

	if (!altmode && mode && !strcmp(mode->arg,"stoolie"))
		stoolieopt = mode;

	if (!altmode && mode && !strcmp(mode->arg,"slibtoolize"))
		stoolieopt = mode;

	if (mode && !strcmp(mode->arg,"execute"))
		execmode = true;

	/* release temporary argv meta context */
	slbt_argv_free(meta);

	/* error not due to an altmode argument? */
	if (!aropt && !stoolieopt && ctx.erridx && (ctx.erridx == ctx.unitidx)) {
		if (flags & SLBT_DRIVER_VERBOSITY_ERRORS)
			slbt_argv_get(
				argv,optv,
				slbt_argv_flags(flags),
				fderr);
		return -1;
	}

	if (!mode && !help && !version && !info && !config && !finish && !features && !dumpmachine && !printdir && !printext && !altmode) {
		slbt_dprintf(fderr,
			"%s: error: --mode must be specified.\n",
			program);
		return -1;
	}

	/* missing compiler? */
	if (!ctx.unitidx && !help && !info && !config && !version && !finish && !features && !dumpmachine && !printdir && !printext) {
		if (!altmode && !aropt && !stoolieopt) {
			if (flags & SLBT_DRIVER_VERBOSITY_ERRORS)
				slbt_dprintf(fderr,
					"%s: error: <compiler> is missing.\n",
					program);
			return -1;
		}
	}

	/* clone and normalize the argv vector */
	for (argc=0,size=0,dargv=argv; *dargv; argc++,dargv++)
		size += strlen(*dargv) + 1;

	if (!(sargv->dargv = calloc(argc+1,sizeof(char *))))
		return -1;

	else if (!(sargv->dargs = calloc(1,size+1)))
		return -1;

	else if (!(*aobjlistv = calloc(argc,sizeof(**aobjlistv)))) {
		free(sargv->dargv);
		free(sargv->dargs);
		return -1;
	}

	objlistv = *aobjlistv;
	objlistp = objlistv;
	csysroot = 0;

	for (i=0,flast=false,dargv=sargv->dargv,dst=sargv->dargs; i<argc; i++) {
		if ((fcopy = (flast || altmode || aropt || stoolieopt))) {
			(void)0;

		} else if (i == 0) {
			fcopy = true;

		} else if (!strcmp(argv[i],"--")) {
			flast = true;
			fcopy = true;

		} else if (!strcmp(argv[i],"-I")) {
			*dargv++ = dst;
			*dst++ = '-';
			*dst++ = 'I';
			strcpy(dst,argv[++i]);
			dst += strlen(dst)+1;

		} else if (!strncmp(argv[i],"-I",2)) {
			fcopy = true;

		} else if (!strcmp(argv[i],"-l")) {
			*dargv++ = dst;
			*dst++ = '-';
			*dst++ = 'l';
			strcpy(dst,argv[++i]);
			dst += strlen(dst)+1;

		} else if (!strncmp(argv[i],"-l",2)) {
			fcopy = true;

		} else if (!strcmp(argv[i],"--library")) {
			*dargv++ = dst;
			*dst++ = '-';
			*dst++ = 'l';
			strcpy(dst,argv[++i]);
			dst += strlen(dst)+1;

		} else if (!strncmp(argv[i],"--library=",10)) {
			*dargv++ = dst;
			*dst++ = '-';
			*dst++ = 'l';
			strcpy(dst,&argv[++i][10]);
			dst += strlen(dst)+1;

		} else if (!strcmp(argv[i],"-L")) {
			*dargv++ = dst;
			*dst++ = '-';
			*dst++ = 'L';
			strcpy(dst,argv[++i]);
			dst += strlen(dst)+1;

		} else if (!strncmp(argv[i],"-L",2)) {
			fcopy = true;

		} else if (!strcmp(argv[i],"-Xlinker")) {
			*dargv++ = dst;
			*dst++ = '-';
			*dst++ = 'W';
			*dst++ = 'l';
			*dst++ = ',';
			strcpy(dst,argv[++i]);
			dst += strlen(dst)+1;

		} else if (!strcmp(argv[i],"--library-path")) {
			*dargv++ = dst;
			*dst++ = '-';
			*dst++ = 'L';
			strcpy(dst,argv[++i]);
			dst += strlen(dst)+1;

		} else if (!strncmp(argv[i],"--library-path=",15)) {
			*dargv++ = dst;
			*dst++ = '-';
			*dst++ = 'L';
			strcpy(dst,&argv[i][15]);
			dst += strlen(dst)+1;

		} else if (!strcmp(argv[i],"--sysroot") && (i<ctx.unitidx)) {
			*dargv++ = dst;
			csysroot = dst;
			strcpy(dst,argv[i]);
			dst[9] = '=';
			strcpy(&dst[10],argv[++i]);
			dst += strlen(dst)+1;
			ctx.unitidx--;

		} else if (!strncmp(argv[i],"--sysroot=",10) && (i<ctx.unitidx)) {
			*dargv++ = dst;
			csysroot = dst;
			strcpy(dst,argv[i]);
			dst += strlen(dst)+1;

		} else if (!strcmp(argv[i],"-objectlist")) {
			*dargv++ = dst;
			strcpy(dst,argv[i++]);
			dst += strlen(dst)+1;

			objlistp->name = dst;
			objlistp++;
			fcopy = true;

		} else {
			fcopy = true;

			if (execmode)
				flast = true;
		}

		if (fcopy) {
			*dargv++ = dst;
			strcpy(dst,argv[i]);
			dst += strlen(dst)+1;
		}
	}

	/* update argc,argv */
	argc = dargv - sargv->dargv;
	argv = sargv->dargv;

	/* iterate through the object list vector: map, parse, store */
	for (objlistp=objlistv; objlistp->name; objlistp++)
		if (slbt_objlist_read(fdcwd,objlistp) < 0)
			return -1;

	for (objc=0,objlistp=objlistv; objlistp->name; objlistp++)
		objc += objlistp->objc;

	/* allocate split vectors, account for cargv's added sysroot */
	if ((sargv->targv = calloc(objc + 2*(argc+3),sizeof(char *))))
		sargv->cargv = sargv->targv + argc + 2;
	else
		return -1;

	/* --features and no <compiler>? */
	if (ctx.unitidx) {
		(void)0;

	} else if (help || version || features || info || config || dumpmachine || printdir || printext || altmode) {
		for (i=0; i<argc; i++)
			sargv->targv[i] = argv[i];

		sargv->cargv = altmode ? sargv->targv : slbt_default_cargv;

		return 0;
	}

	/* --mode=ar and no ar-specific arguments? */
	if (aropt && !ctx.unitidx)
		ctx.unitidx = argc;

	/* --mode=slibtoolize and no slibtoolize-specific arguments? */
	if (stoolieopt && !ctx.unitidx)
		ctx.unitidx = argc;

	/* split vectors: slibtool's own options */
	for (i=0; i<ctx.unitidx; i++)
		sargv->targv[i] = argv[i];

	/* split vector marks */
	targv = sargv->targv + i;
	cargv = sargv->cargv;

	/* known wrappers */
	if (ctx.unitidx && !ccwrap && !aropt && !stoolieopt) {
		if ((base = strrchr(argv[i],'/')))
			base++;
		else if ((base = strrchr(argv[i],'\\')))
			base++;
		else
			base = argv[i];

		if (!strcmp(base,"ccache")
				|| !strcmp(base,"distcc")
				|| !strcmp(base,"compiler")
				|| !strcmp(base,"purify")) {
			*targv++ = "--ccwrap";
			*targv++ = argv[i++];
		}
	}

	/* split vectors: legacy mixture */
	for (optout=optv; optout[0] && (optout[0]->tag != TAG_OUTPUT); optout++)
		(void)0;

	/* compiler, archiver, etc. */
	if (altmode) {
		i = 0;
	} else if (aropt) {
		*cargv++ = argv[0];
	} else if (stoolieopt) {
		*cargv++ = argv[0];
	} else {
		*cargv++ = argv[i++];
	}

	/* sysroot */
	if (csysroot)
		*cargv++ = csysroot;

	/* remaining vector */
	for (objlistp=objlistv; i<argc; i++) {
		if (aropt && (i >= ctx.unitidx)) {
			*cargv++ = argv[i];

		} else if (stoolieopt && (i >= ctx.unitidx)) {
			*cargv++ = argv[i];

		} else if (argv[i][0] != '-') {
			if (argv[i+1] && (argv[i+1][0] == '+')
					&& (argv[i+1][1] == '=')
					&& (argv[i+1][2] == 0)
					&& !(strrchr(argv[i],'.')))
				/* libfoo_la_LDFLAGS += -Wl,.... */
				i++;
			else
				*cargv++ = argv[i];

		/* must capture -objectlist prior to -o */
		} else if (!(strcmp("objectlist",&argv[i][1]))) {
			for (objp=objlistp->objv; *objp; objp++)
				*cargv++ = *objp;

			i++;
			objlistp++;

		} else if (argv[i][1] == 'o') {
			*targv++ = argv[i];

			if (argv[i][2] == 0)
				*targv++ = argv[++i];
		} else if ((argv[i][1] == 'W')  && (argv[i][2] == 'c')) {
			*cargv++ = argv[i];

		} else if (!(strcmp("Xcompiler",&argv[i][1]))) {
			*cargv++ = argv[++i];

		} else if (!(strcmp("XCClinker",&argv[i][1]))) {
			*cargv++ = argv[++i];

		} else if ((argv[i][1] == 'R')  && (argv[i][2] == 0)) {
			*targv++ = argv[i++];
			*targv++ = argv[i];

		} else if (argv[i][1] == 'R') {
			*targv++ = argv[i];

		} else if (!(strncmp("-target=",&argv[i][1],8))) {
			*cargv++ = argv[i];
			*targv++ = argv[i];

		} else if (!(strcmp("-target",&argv[i][1]))) {
			*cargv++ = argv[i];
			*targv++ = argv[i++];

			*cargv++ = argv[i];
			*targv++ = argv[i];

		} else if (!(strcmp("target",&argv[i][1]))) {
			*cargv++ = argv[i];
			*targv++ = argv[i++];

			*cargv++ = argv[i];
			*targv++ = argv[i];

		} else if (!(strncmp("-sysroot=",&argv[i][1],9))) {
			*cargv++ = argv[i];
			*targv++ = argv[i];

		} else if (!(strcmp("-sysroot",&argv[i][1]))) {
			*cargv++ = argv[i];
			*targv++ = argv[i++];

			*cargv++ = argv[i];
			*targv++ = argv[i];

		} else if (!(strcmp("bindir",&argv[i][1]))) {
			*targv++ = argv[i++];
			*targv++ = argv[i];

		} else if (!(strcmp("shrext",&argv[i][1]))) {
			*targv++ = argv[i++];
			*targv++ = argv[i];

		} else if (!(strcmp("rpath",&argv[i][1]))) {
			*targv++ = argv[i++];
			*targv++ = argv[i];

		} else if (!(strcmp("release",&argv[i][1]))) {
			*targv++ = argv[i++];
			*targv++ = argv[i];

		} else if (!(strcmp("weak",&argv[i][1]))) {
			*targv++ = argv[i++];
			*targv++ = argv[i];

		} else if (!(strcmp("static-libtool-libs",&argv[i][1]))) {
			*targv++ = argv[i];

		} else if (!(strcmp("export-dynamic",&argv[i][1]))) {
			*targv++ = argv[i];

		} else if (!(strcmp("export-symbols",&argv[i][1]))) {
			*targv++ = argv[i++];
			*targv++ = argv[i];

		} else if (!(strcmp("export-symbols-regex",&argv[i][1]))) {
			*targv++ = argv[i++];
			*targv++ = argv[i];

		} else if (!(strcmp("version-info",&argv[i][1]))) {
			*targv++ = argv[i++];
			*targv++ = argv[i];

		} else if (!(strcmp("version-number",&argv[i][1]))) {
			*targv++ = argv[i++];
			*targv++ = argv[i];

		} else if (!(strcmp("dlopen",&argv[i][1]))) {
			if (!argv[i+1])
				return -1;

			*targv++ = argv[i++];
			*targv++ = argv[i];

		} else if (!(strcmp("dlpreopen",&argv[i][1]))) {
			if (!argv[i+1])
				return -1;

			if (strcmp(argv[i+1],"self") && strcmp(argv[i+1],"force")) {
				*cargv++ = argv[i];
				*targv++ = argv[i++];

				*cargv++ = argv[i];
				*targv++ = argv[i];
			} else {
				*targv++ = argv[i++];
				*targv++ = argv[i];
			}
		} else {
			for (popt=optout; popt[0] && popt[0]->long_name; popt++)
				if (!(strcmp(popt[0]->long_name,&argv[i][1])))
					break;

			if (popt[0] && popt[0]->long_name)
				*targv++ = argv[i];
			else
				*cargv++ = argv[i];
		}
	}

	return 0;
}
