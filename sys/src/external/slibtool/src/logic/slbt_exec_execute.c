/*******************************************************************/
/*  slibtool: a strong libtool implementation, written in C        */
/*  Copyright (C) 2016--2025  SysDeer Technologies, LLC            */
/*  Released under the Standard MIT License; see COPYING.SLIBTOOL. */
/*******************************************************************/

#include <string.h>
#include <stdbool.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/stat.h>

#include <slibtool/slibtool.h>
#include "slibtool_spawn_impl.h"
#include "slibtool_driver_impl.h"
#include "slibtool_snprintf_impl.h"
#include "slibtool_errinfo_impl.h"


/*******************************************************************/
/* --mode=execute: wrapper script and execution argument vector    */
/*                                                                 */
/* The purpose of executable wrapper scripts is to properly handle */
/* one common scenario where:                                      */
/*                                                                 */
/* (1) a build project would entail both executable programs and   */
/*     dynamically linked libraries; and                           */
/*                                                                 */
/* (2) one or more of the project's executable programs would have */
/*     one or more of the project's libraries as a dynamic runtime */
/*     dependency.                                                 */
/*                                                                 */
/* Since the project's dependency libraries are not yet installed, */
/* correct resolution of a program's dynamic library dependencies  */
/* must depend on an appropriate setting of the LD_LIBRARY_PATH    */
/* encironment variable (on Linxu or Midipix) or an equivalent     */
/* environment variable on any of the other supported platforms.   */
/*                                                                 */
/* Here, too, there are two distinct cases:                        */
/*                                                                 */
/* (a) the executable wrapper script is directly invoked from the  */
/*     shell command line or otherwise; or                         */
/*                                                                 */
/* (b) the build target associated with the executable program is  */
/*     an argument passed to `slibtool --mode=execute` either as   */
/*     the name of the program to be executed (and thus as the     */
/*     first non-slibtool argument) or for processing by another   */
/*     program.                                                    */
/*                                                                 */
/* The first case is handled entirely from within the executable   */
/* wrapper script. The load environment variable is set based on   */
/* the path that was stored in it by slibtool at link time, and    */
/* the real executable is then exec'ed.                            */
/*                                                                 */
/* In the second case, slibtool would start by testing whether the */
/* first non-slibtool argument is the wrapper script of a newly    */
/* built executable program. If it is, then slibtool would invoke  */
/* the wrapper script rather than the executable program, and add  */
/* the path to the executable to the argument vector before all    */
/* other arguments, makign it ${1} from the wrapper script's point */
/* of view. Then again, and irrespective of the previous step,     */
/* slibtool will replace any remaining command-line argument which */
/* points to a build target associated with a newly built program  */
/* with the path to the program itself (that is, the one located   */
/* under the internal .libs/ directory).                           */
/*                                                                 */
/* For the sake of consistency and robustness, wrapper scripts are */
/* created at link time for _all_ executable programs, including   */
/* those programs which appear to have system libraries as their   */
/* sole dynamic library dependencies.                              */
/*******************************************************************/


static int slbt_argument_is_an_executable_wrapper_script(
	const struct slbt_driver_ctx *  dctx,
	const char *                    arg,
	char                            (*altarg)[PATH_MAX])
{
	int           fdcwd;
	const char *  base;
	char *        mark;
	struct stat   st;

	/* the extra characters: .libs/.exe.wrapper */
	if (strlen(arg) > (PATH_MAX - 20))
		return SLBT_BUFFER_ERROR(dctx);

	/* path/to/progname --> path/to/.libs/progname.exe.wapper */
	if ((base = strrchr(arg,'/')))
		base++;

	if (!base)
		base = arg;

	mark  = *altarg;
	mark += base - arg;

	strcpy(*altarg,arg);
	mark += sprintf(mark,".libs/%s",base);
	strcpy(mark,".exe.wrapper");

	/* not an executable wrapper script? */
	fdcwd = slbt_driver_fdcwd(dctx);

	slbt_driver_set_ectx(
		dctx,0,
		*altarg);

	if (fstatat(fdcwd,*altarg,&st,0) < 0)
		return (errno == ENOENT)
			? 0 : SLBT_SYSTEM_ERROR(dctx);

	/* path/to/.libs/progname.exe.wapper --> path/to/.libs/progname */
	*mark = '\0';

	return 1;
}


int slbt_exec_execute(const struct slbt_driver_ctx * dctx)
{
	int			ret;
	char **                 parg;
	char **                 aarg;
	char *			program;
	char *                  exeref;
	char			wrapper[PATH_MAX];
	char			exeprog[PATH_MAX];
	char			argbuf [PATH_MAX];
	struct slbt_exec_ctx *	ectx;

	/* dry run */
	if (dctx->x_cctx->x_drvflags & SLBT_DRIVER_DRY_RUN)
		return 0;

	/* context */
	if (slbt_ectx_get_exec_ctx(dctx,&ectx) < 0)
		return SLBT_NESTED_ERROR(dctx);

	slbt_disable_placeholders(ectx);

	/* original and alternate argument vectors */
	parg = ectx->x_cargv;
	aarg = ectx->x_altv;

	/* program (first non-slibtool argument) */
	if (!(program = ectx->x_cargv[0]))
		return SLBT_CUSTOM_ERROR(
			dctx,
			SLBT_ERR_FLOW_ERROR);

	/* init the wrapper argument based on the first qualifying argument */
	for (exeref=0; !exeref && *parg; parg++) {
		strcpy(argbuf,*parg);

		if ((ret = slbt_argument_is_an_executable_wrapper_script(
				dctx,argbuf,&exeprog)) < 0) {
			return SLBT_NESTED_ERROR(dctx);

		} else if (ret == 1) {
			if (slbt_snprintf(
					wrapper,sizeof(wrapper),
					"%s.exe.wrapper",exeprog) < 0)
				return SLBT_BUFFER_ERROR(dctx);

			exeref  = *parg;
			*aarg++ = wrapper;
		} else {
			strcpy(*parg,argbuf);
		}
	}

	/* transform in place as needed all arguments */
	for (parg=ectx->x_cargv; *parg; parg++) {
		if ((ret = slbt_argument_is_an_executable_wrapper_script(
				dctx,*parg,&argbuf)) < 0) {
			return SLBT_NESTED_ERROR(dctx);

		} else if (ret == 1) {
			strcpy(*parg,argbuf);
			*aarg++ = *parg;
		} else {
			*aarg++ = *parg;
		}
	}

	*aarg = 0;

	/* execute mode */
	ectx->x_program = ectx->x_altv[0];
	ectx->x_argv    = ectx->x_altv;

	/* step output */
	if (!(dctx->x_cctx->x_drvflags & SLBT_DRIVER_SILENT)) {
		if (slbt_output_execute(ectx)) {
			slbt_ectx_free_exec_ctx(ectx);
			return SLBT_NESTED_ERROR(dctx);
		}
	}

	execvp(ectx->x_altv[0],ectx->x_altv);

	slbt_ectx_free_exec_ctx(ectx);
	return SLBT_SYSTEM_ERROR(dctx);
}
