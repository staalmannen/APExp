/*******************************************************************/
/*  slibtool: a strong libtool implementation, written in C        */
/*  Copyright (C) 2016--2025  SysDeer Technologies, LLC            */
/*  Released under the Standard MIT License; see COPYING.SLIBTOOL. */
/*******************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/stat.h>

#include <slibtool/slibtool.h>
#include "slibtool_driver_impl.h"
#include "slibtool_errinfo_impl.h"
#include "slibtool_linkcmd_impl.h"
#include "slibtool_mapfile_impl.h"
#include "slibtool_metafile_impl.h"
#include "slibtool_realpath_impl.h"
#include "slibtool_snprintf_impl.h"
#include "slibtool_visibility_impl.h"

slbt_hidden int slbt_get_deps_meta(
	const struct slbt_driver_ctx *	dctx,
	char *				libfilename,
	int				fexternal,
	struct slbt_deps_meta *		depsmeta)
{
	int			fdcwd;
	char *			ch;
	char *			cap;
	char *			base;
	size_t			libexlen;
	struct stat		st;
	struct slbt_map_info *	mapinfo;
	char			depfile[PATH_MAX];

	/* fdcwd */
	fdcwd = slbt_driver_fdcwd(dctx);

	/* -rpath */
	if (slbt_snprintf(depfile,sizeof(depfile),
				"%s.slibtool.rpath",
				libfilename) < 0)
		return SLBT_BUFFER_ERROR(dctx);

	/* -Wl,%s */
	if (!fstatat(fdcwd,depfile,&st,AT_SYMLINK_NOFOLLOW)) {
		depsmeta->infolen += st.st_size + 4;
		depsmeta->infolen++;
	}

	/* .deps */
	if (slbt_snprintf(depfile,sizeof(depfile),
				"%s.slibtool.deps",
				libfilename) < 0)
		return SLBT_BUFFER_ERROR(dctx);

	/* mapinfo */
	slbt_driver_set_ectx(
		dctx,0,
		depfile);

	if (!(mapinfo = slbt_map_file(fdcwd,depfile,SLBT_MAP_INPUT)))
		return (fexternal && (errno == ENOENT))
			? 0 : SLBT_SYSTEM_ERROR(dctx);

	/* copied length */
	depsmeta->infolen += mapinfo->size;
	depsmeta->infolen++;

	/* libexlen */
	libexlen = (base = strrchr(libfilename,'/'))
		? strlen(depfile) + 2 + (base - libfilename)
		: strlen(depfile) + 2;

	/* iterate */
	ch  = mapinfo->addr;
	cap = mapinfo->cap;

	for (; ch<cap; ) {
		if (*ch++ == '\n') {
			depsmeta->infolen += libexlen;
			depsmeta->depscnt++;
		}
	}

	slbt_unmap_file(mapinfo);

	return 0;
}


static int slbt_exec_link_normalize_dep_file(
	const struct slbt_driver_ctx *  dctx,
	int                             deps,
	char                            (*depfile)[PATH_MAX])
{
	int                             ret;
	int                             fdcwd;
	int                             fdtgt;
	char *                          dot;
	char *                          slash;
	const char *                    base;
	const char *                    mark;
	struct slbt_txtfile_ctx *       tctx;
	const char **                   pline;
	char *                          tgtmark;
	char *                          depmark;
	char *                          relmark;
	char *                          tgtnext;
	char *                          depnext;
	char                            tgtdir  [PATH_MAX];
	char                            tgtpath [PATH_MAX];
	char                            deppath [PATH_MAX];
	char                            pathbuf [PATH_MAX];
	char                            depsbuf [PATH_MAX];
	char                            basebuf [PATH_MAX];
	char                            relapath[PATH_MAX];

	/* fdcwd */
	fdcwd = slbt_driver_fdcwd(dctx);

	/* first-pass dependency file */
	if (slbt_impl_get_txtfile_ctx(dctx,*depfile,deps,&tctx) < 0)
		return SLBT_NESTED_ERROR(dctx);

	/* second-pass dependency file */
	dot = strrchr(*depfile,'.');
	strcpy(dot,".tmp2");

	slbt_driver_set_ectx(
		dctx,0,
		*depfile);

	if ((deps = openat(fdcwd,*depfile,O_RDWR|O_CREAT|O_TRUNC,0644)) < 0) {
		slbt_lib_free_txtfile_ctx(tctx);
		return SLBT_SYSTEM_ERROR(dctx);
	}

	/* fdtgt */
	strcpy(tgtdir,*depfile);

	if (!(slash = strrchr(tgtdir,'/')))
		slash = tgtdir;

	slash[0] = '\0';

	if ((slash = strrchr(tgtdir,'/'))) {
		slash[0] = '\0';
		slash++;
	} else {
		slash    = tgtdir;
		slash[0] = '.';
		slash[1] = '/';
		slash[2] = '\0';
	}

	if ((slash > tgtdir) && strcmp(slash,".libs")) {
		close(deps);
		slbt_lib_free_txtfile_ctx(tctx);

		return SLBT_CUSTOM_ERROR(
			dctx,
			SLBT_ERR_FLOW_ERROR);
	}

	if ((fdtgt = openat(fdcwd,tgtdir,O_DIRECTORY|O_CLOEXEC,0)) < 0) {
		close(deps);
		slbt_lib_free_txtfile_ctx(tctx);

		return SLBT_CUSTOM_ERROR(
			dctx,
			SLBT_ERR_FLOW_ERROR);
	}

	if (slbt_realpath(fdcwd,tgtdir,0,tgtpath,sizeof(tgtpath)) < 0) {
				close(fdtgt);
				close(deps);
				slbt_lib_free_txtfile_ctx(tctx);

				return SLBT_CUSTOM_ERROR(
					dctx,
					SLBT_ERR_FLOW_ERROR);
	}

	strcpy(pathbuf,tgtpath);

	/* normalize dependency lines as needed */
	for (pline=tctx->x_txtlinev; *pline; pline++) {
		if ((mark = *pline)) {
			if ((mark[0] == '-') && (mark[1] == 'L')) {
					mark = &mark[2];
					base = 0;

			} else if ((mark[0] == ':') && (mark[1] == ':')) {
					mark = &mark[2];
					base = mark;
			}

			if ((mark > *pline) && (mark[0] == '/'))
				mark = *pline;
		}

		if (mark > *pline) {
			if (slbt_realpath(
					fdtgt,mark,0,deppath,
					sizeof(deppath)) < 0)
				mark = *pline;

			else if ((tgtpath[0] != '/') || (deppath[0] != '/'))
				mark = 0;

			else
				strcpy(depsbuf,deppath);

			if ((mark > *pline) && base) {
				slash  = strrchr(deppath,'/');
				*slash = '\0';

				slash  = strrchr(deppath,'/');
				*slash = '\0';

				base  = basebuf;
				slash = &depsbuf[slash - deppath];

				strcpy(basebuf,++slash);
				strcpy(depsbuf,deppath);
			}
		}

		if (mark > *pline) {
			tgtmark = tgtpath;
			depmark = deppath;

			tgtnext = strchr(tgtmark,'/');
			depnext = strchr(depmark,'/');

			while (tgtnext && depnext) {
				*tgtnext = '\0';
				*depnext = '\0';

				if (strcmp(tgtmark,depmark)) {
					tgtnext = 0;
					depnext = 0;
				} else {
					tgtmark = &tgtnext[1];
					depmark = &depnext[1];

					if (*tgtmark && *depmark) {
						tgtnext = strchr(tgtmark,'/');
						depnext = strchr(depmark,'/');
					} else {
						tgtnext = 0;
						depnext = 0;
					}
				}
			}

			strcpy(tgtmark,&pathbuf[tgtmark-tgtpath]);
			strcpy(depmark,&depsbuf[depmark-deppath]);

			if ((tgtmark - tgtpath) == (depmark - deppath)) {
				mark = &depmark[strlen(tgtmark)];

				if ((mark[0] == '/') && !strncmp(tgtmark,depmark,mark-depmark))
					sprintf(relapath,"-L.%s",mark);
				else
					mark = relapath;
			} else {
				mark = relapath;
			}

			if (mark == relapath) {
				relmark = relapath;
				relmark += sprintf(relapath,"-L../");

				while ((tgtnext = strchr(tgtmark,'/'))) {
					tgtmark = &tgtnext[1];
					relmark += sprintf(relmark,"../");
				}

				strcpy(relmark,depmark);
			}

			if (base) {
				relapath[0] = ':';
				relapath[1] = ':';
			}

			mark = relapath;
		}

		if ((mark == relapath) && base) {
			ret =  slbt_dprintf(deps,"%s/%s\n",mark,base);

		} else if (mark) {
			ret = slbt_dprintf(deps,"%s\n",mark);

		} else {
			ret = (-1);
		}

		if (ret < 0) {
			close(deps);
			close(fdtgt);
			slbt_lib_free_txtfile_ctx(tctx);

			return mark
				? SLBT_SYSTEM_ERROR(dctx)
				: SLBT_NESTED_ERROR(dctx);
		}

		if (mark == relapath)
			strcpy(tgtpath,pathbuf);
	}

	close(fdtgt);
	slbt_lib_free_txtfile_ctx(tctx);

	return deps;
}


static int slbt_exec_link_compact_dep_file(
	const struct slbt_driver_ctx *  dctx,
	int                             deps,
	char                            (*depfile)[PATH_MAX])
{
	int                             fdcwd;
	struct slbt_txtfile_ctx *       tctx;
	const char **                   pline;
	const char **                   pcomp;
	const char *                    depline;
	char *                          dot;

	/* fdcwd */
	fdcwd = slbt_driver_fdcwd(dctx);

	/* second-pass dependency file */
	if (slbt_impl_get_txtfile_ctx(dctx,*depfile,deps,&tctx) < 0)
		return SLBT_NESTED_ERROR(dctx);

	/* second-pass dependency file */
	dot = strrchr(*depfile,'.');
	dot[0] = '\0';

	slbt_driver_set_ectx(
		dctx,0,
		*depfile);

	if ((deps = openat(fdcwd,*depfile,O_RDWR|O_CREAT|O_TRUNC,0644)) < 0) {
		slbt_lib_free_txtfile_ctx(tctx);
		return SLBT_SYSTEM_ERROR(dctx);
	}

	/* iterate, only write unique entries */
	for (pline=tctx->x_txtlinev; *pline; pline++) {
		depline = *pline;

		if ((depline[0] == '-') && (depline[1] == 'L'))
			for (pcomp=tctx->x_txtlinev; depline && pcomp<pline; pcomp++)
				if (!strcmp(*pcomp,depline))
					depline = 0;

		if (depline && (slbt_dprintf(deps,"%s\n",depline) < 0)) {
			close(deps);
			slbt_lib_free_txtfile_ctx(tctx);
			return SLBT_SYSTEM_ERROR(dctx);
		}
	}

	slbt_lib_free_txtfile_ctx(tctx);

	return deps;
}


static bool slbt_archive_is_convenience_library(int fdcwd, const char * arpath)
{
	int     fd;
	char    laipath[PATH_MAX];
	char *  dot;

	strcpy(laipath,arpath);
	dot = strrchr(laipath,'.');
	strcpy(dot,".lai");

	if ((fd = openat(fdcwd,laipath,O_RDONLY,0)) >= 0) {
		close(fd);
		return false;
	}

	return true;
}


slbt_hidden int slbt_exec_link_create_dep_file(
	const struct slbt_driver_ctx *	dctx,
	struct slbt_exec_ctx *		ectx,
	char **				altv,
	const char *			libfilename,
	bool				farchive)
{
	int			ret;
	int			deps;
	int			fdtmp;
	int			slen;
	int			fdcwd;
	char **			parg;
	char *			popt;
	char *			plib;
	char *			path;
	char *			mark;
	char *			base;
	size_t			size;
	bool                    fdep;
	char			deplib [PATH_MAX];
	char			deppref[PATH_MAX];
	char			reladir[PATH_MAX];
	char			depfile[PATH_MAX];
	char			pathbuf[PATH_MAX];
	struct stat		st;
	int			ldepth;
	int			fardep;
	int			fdyndep;
	struct slbt_map_info *  mapinfo;
	bool			is_reladir;

	/* fdcwd */
	fdcwd = slbt_driver_fdcwd(dctx);

	/* depfile */
	if (slbt_snprintf(depfile,sizeof(depfile),
			"%s.slibtool.deps.tmp1",
			libfilename) < 0)
		return SLBT_BUFFER_ERROR(dctx);

	strcpy(pathbuf,depfile);

	/* dependency prefix */
	if (depfile[0] == '/') {
		deppref[0] = '\0';
	} else {
		if ((mark = strrchr(depfile,'/')))
			*mark = 0;

		if (!mark)
			mark = depfile;

		if (slbt_realpath(fdcwd,depfile,0,reladir,sizeof(reladir)) < 0)
			return SLBT_SYSTEM_ERROR(dctx);

		if (slbt_realpath(fdcwd,"./",0,deppref,sizeof(deppref)) < 0)
			return SLBT_SYSTEM_ERROR(dctx);

		if (mark > depfile)
			*mark = '/';

		mark = &reladir[strlen(deppref)];
		*mark++ = '\0';

		if (strcmp(reladir,deppref))
			return SLBT_CUSTOM_ERROR(
				dctx,
				SLBT_ERR_FLOW_ERROR);

		if ((base = strrchr(mark,'/')))
			base++;

		if (!base)
			base = mark;

		if (strcmp(base,".libs"))
			return SLBT_CUSTOM_ERROR(
				dctx,
				SLBT_ERR_FLOW_ERROR);

		base = mark;
		mark = deppref;

		for (; base; ) {
			if ((base = strchr(base,'/'))) {
				mark += sprintf(mark,"../");
				base++;
			}
		}

		*mark = '\0';
	}

	/* deps */
	slbt_driver_set_ectx(
		dctx,0,
		depfile);

	if ((deps = openat(fdcwd,depfile,O_RDWR|O_CREAT|O_TRUNC,0644)) < 0)
		return SLBT_SYSTEM_ERROR(dctx);

	/* informational header */
	if (slbt_realpath(fdcwd,"./",0,reladir,sizeof(reladir)) < 0)
		return SLBT_SYSTEM_ERROR(dctx);

	if (slbt_dprintf(deps,
			"# makefile target: %s\n"
			"# slibtool target: %s\n"
			"# cprocess fdcwd:  %s\n",
			dctx->x_cctx->x_output,
			libfilename,
			reladir) < 0)
		return SLBT_SYSTEM_ERROR(dctx);

	fdep = 0;

	/* iterate */
	for (parg=altv; *parg; parg++) {
		popt    = 0;
		plib    = 0;
		path    = 0;
		mapinfo = 0;

		if (!strncmp(*parg,"-l",2)) {
			if (fdep) {
				if (slbt_dprintf(
						deps,
						"#\n# makefile target: %s\n",
						dctx->x_cctx->x_output) < 0)
					return SLBT_SYSTEM_ERROR(dctx);

				fdep = false;
			}

			popt = *parg;
			plib = popt + 2;

		} else if (!strncmp(*parg,"-L",2)) {
			if (fdep) {
				if (slbt_dprintf(
						deps,
						"#\n# makefile target: %s\n",
						dctx->x_cctx->x_output) < 0)
					return SLBT_SYSTEM_ERROR(dctx);

				fdep = false;
			}

			popt = *parg;
			path = popt + 2;

		} else if (!strncmp(*parg,"-f",2)) {
			(void)0;

		} else if ((popt = strrchr(*parg,'.')) && !strcmp(popt,".la")) {
			/* import dependency list */
			fdep = true;

			if ((base = strrchr(*parg,'/')))
				base++;
			else
				base = *parg;

			/* [relative .la directory] */
			if (base > *parg) {
				slen = slbt_snprintf(
					reladir,
					sizeof(reladir),
					"%s",*parg);

				if (slen < 0) {
					close(deps);
					return SLBT_BUFFER_ERROR(dctx);
				}

				is_reladir = true;
				reladir[base - *parg - 1] = 0;
			} else {
				is_reladir = false;
				reladir[0] = '.';
				reladir[1] = 0;
			}


			/* dynamic library dependency? */
			strcpy(depfile,*parg);
			mark = depfile + (base - *parg);
			size = sizeof(depfile) - (base - *parg);
			slen = slbt_snprintf(mark,size,".libs/%s",base);

			if (slen < 0) {
				close(deps);
				return SLBT_BUFFER_ERROR(dctx);
			}

			mark = strrchr(mark,'.');
			strcpy(mark,dctx->x_cctx->x_settings.fa_dsosuffix);

			fardep  = 0;
			fdyndep = !fstatat(fdcwd,depfile,&st,0);

			if (fdyndep && farchive) {
				mark = strrchr(mark,'.');
				strcpy(mark,dctx->x_cctx->x_settings.fa_arsuffix);

				if (fstatat(fdcwd,depfile,&st,0) < 0) {
					strcpy(mark,dctx->x_cctx->x_settings.fa_dsosuffix);
				} else {
					fdyndep = 0;
				}
			}

			/* [-L... as needed] */
			if (fdyndep && (ectx->x_ldirdepth >= 0)) {
				if (slbt_dprintf(deps,"-L") < 0) {
					close(deps);
					return SLBT_SYSTEM_ERROR(dctx);
				}

				for (ldepth=ectx->x_ldirdepth; ldepth; ldepth--) {
					if (slbt_dprintf(deps,"../") < 0) {
						close(deps);
						return SLBT_SYSTEM_ERROR(dctx);
					}
				}

				if (slbt_dprintf(deps,"%s%s.libs\n",
						 (is_reladir ? reladir : ""),
						 (is_reladir ? "/" : "")) < 0) {
					close(deps);
					return SLBT_SYSTEM_ERROR(dctx);
				}
			}

			/* -ldeplib */
			if (fdyndep) {
				*popt = 0;
				mark  = base;
				mark += strlen(dctx->x_cctx->x_settings.fa_dsoprefix);

				if (slbt_dprintf(deps,"-l%s\n",mark) < 0) {
					close(deps);
					return SLBT_SYSTEM_ERROR(dctx);
				}

				*popt = '.';
			} else {
				strcpy(depfile,*parg);

				slbt_adjust_wrapper_argument(
					depfile,true,
					dctx->x_cctx->x_settings.fa_arsuffix);


				fardep  = farchive;
				fardep |= !slbt_archive_is_convenience_library(fdcwd,depfile);
			}

			if (fardep) {
				if (slbt_dprintf(deps,"::") < 0) {
					close(deps);
					return SLBT_SYSTEM_ERROR(dctx);
				}

				for (ldepth=ectx->x_ldirdepth; ldepth; ldepth--) {
					if (slbt_dprintf(deps,"../") < 0) {
						close(deps);
						return SLBT_SYSTEM_ERROR(dctx);
					}
				}


				if (ectx->x_ldirdepth >= 0) {
					if (slbt_dprintf(deps,"%s\n",depfile) < 0) {
						close(deps);
						return SLBT_SYSTEM_ERROR(dctx);
					}
				} else {
					if (slbt_dprintf(deps,"::./%s\n",depfile) < 0) {
						close(deps);
						return SLBT_SYSTEM_ERROR(dctx);
					}
				}
			}

			/* [open dependency list] */
			strcpy(depfile,*parg);
			mark = depfile + (base - *parg);
			size = sizeof(depfile) - (base - *parg);
			slen = slbt_snprintf(mark,size,".libs/%s",base);

			if (slen < 0) {
				close(deps);
				return SLBT_BUFFER_ERROR(dctx);
			}

			mapinfo = 0;

			mark = strrchr(mark,'.');
			size = sizeof(depfile) - (mark - depfile);

			if (!fardep) {
				slen = slbt_snprintf(mark,size,
					"%s.slibtool.deps",
					dctx->x_cctx->x_settings.fa_dsosuffix);

				if (slen < 0) {
					close(deps);
					return SLBT_BUFFER_ERROR(dctx);
				}

				mapinfo = slbt_map_file(
					fdcwd,depfile,
					SLBT_MAP_INPUT);

				if (!mapinfo && (errno != ENOENT)) {
					close(deps);
					return SLBT_SYSTEM_ERROR(dctx);
				}
			}

			if (!mapinfo) {
				slen = slbt_snprintf(mark,size,
					".a.slibtool.deps");

				if (slen < 0) {
					close(deps);
					return SLBT_BUFFER_ERROR(dctx);
				}

				mapinfo = slbt_map_file(
					fdcwd,depfile,
					SLBT_MAP_INPUT);

				if (!mapinfo) {
					slbt_driver_set_ectx(
						dctx,0,
						depfile);

					strcpy(mark,".a.disabled");

					if (fstatat(fdcwd,depfile,&st,AT_SYMLINK_NOFOLLOW)) {
						close(deps);
						return SLBT_SYSTEM_ERROR(dctx);
					}
				}
			}

			/* [-l... as needed] */
			while (mapinfo && (mapinfo->mark < mapinfo->cap)) {
				ret = slbt_mapped_readline(
					dctx,mapinfo,
					deplib,sizeof(deplib));

				if (ret) {
					close(deps);
					return SLBT_NESTED_ERROR(dctx);
				}

				if ((deplib[0] == '-') && (deplib[1] == 'L') && (deplib[2] != '/')) {
					ret = slbt_dprintf(
						deps,"-L%s%s/%s",
						deppref,reladir,&deplib[2]);

				} else if ((deplib[0] == ':') && (deplib[1] == ':') && (deplib[2] != '/')) {
					ret = slbt_dprintf(
						deps,"::%s%s/%s",
						deppref,reladir,&deplib[2]);

				} else {
					ret = slbt_dprintf(
						deps,"%s",
						deplib);
				}

				if (ret < 0) {
					close(deps);
					return SLBT_SYSTEM_ERROR(dctx);
				}
			}

			if (mapinfo)
				slbt_unmap_file(mapinfo);
		}

		if (plib && (slbt_dprintf(deps,"-l%s\n",plib) < 0)) {
			close(deps);
			return SLBT_SYSTEM_ERROR(dctx);
		}

		if (path && (slbt_dprintf(deps,"-L%s\n",path) < 0)) {
			close(deps);
			return SLBT_SYSTEM_ERROR(dctx);
		}
	}

	if ((fdtmp = slbt_exec_link_normalize_dep_file(dctx,deps,&pathbuf)) < 0)
		return SLBT_NESTED_ERROR(dctx);

	close(deps);

	if ((deps = slbt_exec_link_compact_dep_file(dctx,fdtmp,&pathbuf)) < 0)
		return SLBT_NESTED_ERROR(dctx);

	close(deps);
	close(fdtmp);

	return 0;
}
