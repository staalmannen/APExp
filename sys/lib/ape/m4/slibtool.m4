###############################################################################
#                                                                             #
#   slibtool.m4: native slibtool integration for autoconf-based projects      #
#                                                                             #
#   Copyright (C) 2016--2025  SysDeer Technologies, LLC                       #
#                                                                             #
#   Permission is hereby granted, free of charge, to any person obtaining     #
#   a copy of this software and associated documentation files (the           #
#   "Software"), to deal in the Software without restriction, including       #
#   without limitation the rights to use, copy, modify, merge, publish,       #
#   distribute, sublicense, and/or sell copies of the Software, and to        #
#   permit persons to whom the Software is furnished to do so, subject to     #
#   the following conditions:                                                 #
#                                                                             #
#   The above copyright notice and this permission notice shall be included   #
#   in all copies or substantial portions of the Software.                    #
#                                                                             #
#   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS   #
#   OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF                #
#   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.    #
#   IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY      #
#   CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,      #
#   TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE         #
#   SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                    #
#                                                                             #
###############################################################################



# _SLIBTOOL_DEFAULTS
# ------------------
AC_DEFUN([_SLIBTOOL_DEFAULTS],[
AC_BEFORE([$0],[SLIBTOOL_INIT])
AC_BEFORE([$0],[_SLIBTOOL_ARGUMENT_HANDLING])

# slibtool: implementation defaults
# ---------------------------------
slibtool_enable_shared_default='yes'
slibtool_enable_static_default='yes'
slibtool_enable_dlopen_default='yes'
slibtool_enable_win32_dll_default='yes'
slibtool_enable_fast_install_default='yes'
slibtool_pic_mode_default='default'
slibtool_sysroot_default=
])

# slibtool: refined logic for ar, nm, ranlib, etc.
#
m4_ifdef([SLIBTOOL_INIT],[],[
#
m4_ifdef([AC_PROG_AR],     [m4_undefine([AC_PROG_AR])])
m4_ifdef([AM_PROG_AR],     [m4_undefine([AM_PROG_AR])])

m4_ifdef([AC_PROG_NM],     [m4_undefine([AC_PROG_NM])])
m4_ifdef([AM_PROG_NM],     [m4_undefine([AM_PROG_NM])])

m4_ifdef([AC_PROG_RC],     [m4_undefine([AC_PROG_RC])])
m4_ifdef([LT_PROG_RC],     [m4_undefine([LT_PROG_RC])])

m4_ifdef([AC_PROG_RANLIB], [m4_undefine([AC_PROG_RANLIB])])
m4_ifdef([AM_PROG_RANLIB], [m4_undefine([AM_PROG_RANLIB])])

m4_ifdef([AC_PROG_LEX],    [m4_undefine([AC_PROG_LEX])])
m4_ifdef([AM_PROG_LEX],    [m4_undefine([AM_PROG_LEX])])

m4_ifdef([LT_LIB_M],       [m4_undefine([LT_LIB_M])])
m4_ifdef([LT_LIB_DLLOAD],  [m4_undefine([LT_LIB_DLLOAD])])
])

# _SLIBTOOL_CONVENIENCE
# ---------------------
AC_DEFUN([LT_DEVAL],[$1]=[$2])

# _SLIBTOOL_ARGUMENT_HANDLING
# ---------------------------
AC_DEFUN([_SLIBTOOL_ARGUMENT_HANDLING],[
AC_BEFORE([$0],[_SLIBTOOL_ARG_ENABLE])
AC_BEFORE([$0],[_SLIBTOOL_ARG_WITH])

# slibtool: argument handling
# ---------------------------
slibtool_arg_enable()
{
	case "${enableval}" in
		'yes')
			slbt_eval_expr="${slbt_var}='yes'"
			eval $slbt_eval_expr
			;;

		'no')
			slbt_eval_expr="${slbt_var}='no'"
			eval $slbt_eval_expr
			;;

		*)
			slbt_package="${PACKAGE:-default}"

			slbt_eval_expr="${slbt_var}='no'"
			eval $slbt_eval_expr

			slbt_cfg_ifs="${IFS}"
			IFS="${PATH_SEPARATOR}${IFS}"

			for slbt_pkg in ${enableval}; do
				if [[ "_${slbt_pkg}" = "_${slbt_package}" ]]; then
					slbt_eval_expr="${slbt_var}='yes'"
					eval $slbt_eval_expr
				fi
			done

			IFS="${slbt_cfg_ifs}"
			unset slbt_cfg_ifs
			;;
	esac
}


slibtool_arg_with()
{
	case "${slbt_var}" in
		'slibtool_sysroot')
			case "${withval}" in
				'yes')
					slbt_eval_expr="${slbt_var}='yes'"
					eval $slbt_eval_expr
					;;

				'no')
					slbt_eval_expr="${slbt_var}='no'"
					eval $slbt_eval_expr
					;;

				*)
					slbt_eval_expr="${slbt_var}=${withval}"
					eval $slbt_eval_expr
					;;
			esac

			;;

		*)
			enableval="${withval}"
			slibtool_arg_enable
			;;
	esac
}
])


# _SLIBTOOL_ARG_ENABLE(_feature_,_help_string_,_var_)
# ---------------------------------------------------
AC_DEFUN([_SLIBTOOL_ARG_ENABLE],[
AC_ARG_ENABLE($1,
[AS_HELP_STRING([--enable-]$1[@<:@=PKGS@:>@],$2  @<:@default=[$]$3_default@:>@)],[
  slbt_var=$3
  slibtool_arg_enable],[dnl
$3=[$]$3_default])
])


# _SLIBTOOL_ARG_WITH(_feature_,_help_string_,_var_)
# -------------------------------------------------
AC_DEFUN([_SLIBTOOL_ARG_WITH],[
AC_ARG_WITH($1,
[AS_HELP_STRING([--with-]$1[@<:@=PKGS@:>@],$2  @<:@default=[$]$3_default@:>@)],[
  slbt_var=$3
  slibtool_arg_with],[dnl
$3=[$]$3_default])
])


# _SLIBTOOL_SET_FLAVOR
# --------------------
AC_DEFUN([_SLIBTOOL_SET_FLAVOR],[
AC_BEFORE([$0],[SLIBTOOL_INIT])

# slibtool: set SLIBTOOL to the default/package-default/user-requested flavor
# ---------------------------------------------------------------------------
slibtool_set_flavor()
{
	_slibtool="${SLIBTOOL:-slibtool}"

	_slibtool_util="${_slibtool%% *}"
	_slibtool_util="${_slibtool_util%-shared}"
	_slibtool_util="${_slibtool_util%-static}"

	case "${_slibtool}" in
		*' '*)
			_slibtool_args="${_slibtool#* }"
			_slibtool_args="${_slibtool_args%--prefer-sltdl}"
			_slibtool_args="${_slibtool_args% }"
			;;
		*)
			_slibtool_args=
			;;
	esac

	if [[ "${_slibtool_util%/*}" = "${_slibtool_util}" ]]; then
		_slibtool_path=
	else
		_slibtool_path="${_slibtool_util%/*}/"
	fi

	case "${_slibtool_util##*/}" in
		'rlibtool')
			_slibtool_util="${_slibtool_path}"'slibtool'
			;;

		'rclibtool')
			_slibtool_util="${_slibtool_path}"'clibtool'
			;;

		'rdlibtool')
			_slibtool_util="${_slibtool_path}"'dlibtool'
			;;

		'rdclibtool')
			_slibtool_util="${_slibtool_path}"'dclibtool'
			;;
	esac

	case "_${slibtool_enable_shared}_${slibtool_enable_static}" in
		'_yes_yes')
			SLIBTOOL="${_slibtool_util}${_slibtool_args:+ }${_slibtool_args}"
			;;

		'_yes_no')
			SLIBTOOL="${_slibtool_util}-shared${_slibtool_args:+ }${_slibtool_args}"
			;;

		'_no_yes')
			SLIBTOOL="${_slibtool_util}-static${_slibtool_args:+ }${_slibtool_args}"
			;;

		'_no_no')
			SLIBTOOL='false'
			;;

		*)
			SLIBTOOL='false'
			slibtool_enable_shared='no'
			slibtool_enable_static='no'
			;;
	esac

	case "_${slibtool_sysroot}" in
		'_')
			;;

		'_yes'|'_no')
			slibtool_err_arg=[$with_sysroot]
			slibtool_err_msg='slibtool: the command-line --sysroot argument is always respected.'
			AC_MSG_RESULT([slibtool: --with-sysroot=$slibtool_err_arg])
			AC_MSG_ERROR([$slibtool_err_msg])
			;;

		_/*)
			SLIBTOOL_SYSROOT="--sysroot=${slibtool_sysroot}"
			SLIBTOOL="${SLIBTOOL} ${SLIBTOOL_SYSROOT}"
			;;

		*)
			slibtool_err_arg=[$with_sysroot]
			slibtool_err_msg='slibtool: relative sysroot paths are not supported.'
			AC_MSG_RESULT([slibtool: --with-sysroot=$slibtool_err_arg])
			AC_MSG_ERROR([$slibtool_err_msg])
			;;
	esac

	case "_${slibtool_prefer_sltdl:-}" in
		'_yes')
			SLIBTOOL="${SLIBTOOL} --prefer-sltdl"
			;;
	esac

	# drop-in replacement
	enable_shared=${slibtool_enable_shared}
	enable_static=${slibtool_enable_static}
	enable_dlopen=${slibtool_enable_dlopen}
	enable_win32_dll=${slibtool_enable_win32_dll}
	enable_fast_install=${slibtool_enable_fast_install}
	pic_mode=${slibtool_pic_mode}

	# suffix variables
	if [[ -n "${host}" ]]; then
		shrext_cmds="$($_slibtool -print-shared-ext --host=${host})"
		libext="$($_slibtool -print-static-ext --host=${host})"
		libext="${libext#[.]}"
	else
		shrext_cmds="$($_slibtool -print-shared-ext)"
		libext="$($_slibtool -print-static-ext)"
		libext="${libext#[.]}"
	fi
}
])


# SLIBTOOL_ENABLE_SHARED
# ----------------------
AC_DEFUN([SLIBTOOL_ENABLE_SHARED],[
AC_BEFORE([$0],[SLIBTOOL_INIT])

# slibtool: SLIBTOOL_ENABLE_SHARED
# --------------------------------
slibtool_options="${slibtool_options:-}"
slibtool_options="${slibtool_options} shared"
])


# SLIBTOOL_ENABLE_STATIC
# ----------------------
AC_DEFUN([SLIBTOOL_ENABLE_STATIC],[
AC_BEFORE([$0],[SLIBTOOL_INIT])

# slibtool: SLIBTOOL_ENABLE_STATIC
# --------------------------------
slibtool_options="${slibtool_options:-}"
slibtool_options="${slibtool_options} static"
])


# SLIBTOOL_DISABLE_SHARED
# -----------------------
AC_DEFUN([SLIBTOOL_DISABLE_SHARED],[
AC_BEFORE([$0],[SLIBTOOL_INIT])

# slibtool: SLIBTOOL_DISABLE_SHARED
# ---------------------------------
slibtool_options="${slibtool_options:-}"
slibtool_options="${slibtool_options} disable-shared"
])


# SLIBTOOL_DISABLE_STATIC
# -----------------------
AC_DEFUN([SLIBTOOL_DISABLE_STATIC],[
AC_BEFORE([$0],[SLIBTOOL_INIT])

# slibtool: SLIBTOOL_DISABLE_STATIC
# ---------------------------------
slibtool_options="${slibtool_options:-}"
slibtool_options="${slibtool_options} disable-static"
])


# SLIBTOOL_PROG_AR
# ----------------
AC_DEFUN([SLIBTOOL_PROG_AR],[

# slibtool: SLIBTOOL_PROG_AR
# --------------------------
if [[ -n "${host_alias}" ]]; then
	AC_CHECK_PROG([AR],"${host_alias}-"[ar],"${host_alias}-"[ar])
fi

if [[ -n "${host}" ]] && [[ "${host}" != "${host_alias:-}" ]] &&  [[ -z "${AR}" ]]; then
	AC_CHECK_PROG([AR],"${host}-"[ar],"${host}-"[ar])
fi

if [[ -n "${host}" ]] &&  [[ -z "${AR}" ]]; then
	AC_CHECK_PROG([AR],[llvm-ar],[llvm-ar])
fi

if [[ "${host:-x}" = "${build:-x}" ]]; then
	AC_CHECK_PROG([AR],[ar],[ar])
fi
])


# SLIBTOOL_PROG_RANLIB
# --------------------
AC_DEFUN([SLIBTOOL_PROG_RANLIB],[

# slibtool: SLIBTOOL_PROG_RANLIB
# ------------------------------
if [[ -n "${host_alias}" ]]; then
	AC_CHECK_PROG([RANLIB],"${host_alias}-"[ranlib],"${host_alias}-"[ranlib])
fi

if [[ -n "${host}" ]] && [[ "${host}" != "${host_alias:-}" ]] &&  [[ -z "${RANLIB}" ]]; then
	AC_CHECK_PROG([RANLIB],"${host}-"[ranlib],"${host}-"[ranlib])
fi

if [[ -n "${host}" ]] &&  [[ -z "${RANLIB}" ]]; then
	AC_CHECK_PROG([RANLIB],[llvm-ranlib],[llvm-ranlib])
fi

if [[ "${host:-x}" = "${build:-x}" ]]; then
	AC_CHECK_PROG([RANLIB],[ranlib],[ranlib])
fi
])


# SLIBTOOL_PROG_NM
# ----------------
AC_DEFUN([SLIBTOOL_PROG_NM],[

# slibtool: SLIBTOOL_PROG_NM
# --------------------------
if [[ -n "${host_alias}" ]]; then
	AC_CHECK_PROG([NM],"${host_alias}-"[nm],"${host_alias}-"[nm])
fi

if [[ -n "${host}" ]] && [[ "${host}" != "${host_alias:-}" ]] &&  [[ -z "${NM}" ]]; then
	AC_CHECK_PROG([NM],"${host}-"[nm],"${host}-"[nm])
fi

if [[ -n "${host}" ]] &&  [[ -z "${NM}" ]]; then
	AC_CHECK_PROG([NM],[llvm-nm],[llvm-nm])
fi

if [[ "${host:-x}" = "${build:-x}" ]]; then
	AC_CHECK_PROG([NM],[nm],[nm])
fi
])


# SLIBTOOL_PROG_RC
# ----------------
AC_DEFUN([SLIBTOOL_PROG_RC],[

# slibtool: SLIBTOOL_PROG_RC
# --------------------------
if [[ -n "${host_alias}" ]]; then
	AC_CHECK_PROG([RC],"${host_alias}-"[windres],"${host_alias}-"[windres])
fi

if [[ -n "${host}" ]] && [[ "${host}" != "${host_alias:-}" ]] &&  [[ -z "${RC}" ]]; then
	AC_CHECK_PROG([RC],"${host}-"[windres],"${host}-"[windres])
fi

if [[ -n "${host}" ]] &&  [[ -z "${RC}" ]]; then
	AC_CHECK_PROG([RC],[llvm-windres],[llvm-windres])
fi

if [[ "${host:-x}" = "${build:-x}" ]]; then
	AC_CHECK_PROG([RC],[windres],[windres])
fi
])


# SLIBTOOL_PROG_LEX
# -----------------
AC_DEFUN([SLIBTOOL_PROG_LEX],[

# slibtool: SLIBTOOL_PROG_LEX
# ---------------------------
if [[ -n "${LEX}" ]]; then
	AC_CHECK_PROG([LEX],[flex])
fi

if [[ -z "${LEX}" ]]; then
	AC_CHECK_PROG([LEX],[flex],[flex])
fi

if [[ -z "${LEX}" ]]; then
	AC_CHECK_PROG([LEX],[lex],[lex])
fi

slibtool_lex_output_root="${ac_cv_prog_lex_root:-lex.yy}"

AC_SUBST([LEX])
AC_SUBST([LEXLIB])
AC_SUBST([LEX_OUTPUT_ROOT],["${slibtool_lex_output_root}"])
])


# SLIBTOOL_LFLAG_LIBM
# -------------------
AC_DEFUN([SLIBTOOL_LFLAG_LIBM],[

# slibtool: SLIBTOOL_LFLAG_LIBM
# -----------------------------
LT_DEVAL([LIBM],[-lm])
AC_SUBST([LIBM])
])


# SLIBTOOL_LFLAG_LTDL
# -------------------
AC_DEFUN([SLIBTOOL_LFLAG_LTDL],[

# slibtool: SLIBTOOL_LFLAG_LTDL
# -----------------------------
# (always use the system lib[s]ltdl)
])


# SLIBTOOL_INIT(_options_)
# ------------------------
AC_DEFUN([SLIBTOOL_INIT],[
AC_BEFORE([SLIBTOOL_LANG])
AC_REQUIRE([SLIBTOOL_PREREQ])
AC_REQUIRE([_SLIBTOOL_DEFAULTS])
AC_REQUIRE([_SLIBTOOL_SLTDL_OPTION])
AC_REQUIRE([_SLIBTOOL_SET_FLAVOR])
AC_REQUIRE([_SLIBTOOL_ARGUMENT_HANDLING])


# slibtool: tame legacy early invocation
AC_DEFUN([AC_PROG_LEX])
AC_DEFUN([AM_PROG_LEX])

AC_DEFUN([AC_PROG_RANLIB])
AC_DEFUN([AM_PROG_RANLIB])


# slibtool: package defaults
# ---------------------
slbt_cfg_ifs="${IFS}"
IFS="${PATH_SEPARATOR}${IFS}"

for slbt_opt in $@ ${slibtool_options:-}; do
	case "${slbt_opt}" in
		'shared')
			slibtool_enable_shared_default='yes'
			;;

		'disable-shared')
			slibtool_enable_shared_default='no'
			;;

		'static')
			slibtool_enable_static_default='yes'
			;;

		'disable-static')
			slibtool_enable_static_default='no'
			;;

		'dlopen')
			slibtool_enable_dlopen_default='yes'
			;;

		'disable-dlopen')
			slibtool_enable_dlopen_default='no'
			;;

		'win32-dll')
			slibtool_enable_win32_dll_default='yes'
			;;

		'disable-win32-dll')
			slibtool_enable_win32_dll_default='no'
			;;

		'fast-install')
			slibtool_enable_fast_install_default='yes'
			;;

		'disable-fast-install')
			slibtool_enable_fast_install_default='no'
			;;

		'pic-only')
			slibtool_pic_mode_default='yes'
			;;

		'no-pic')
			slibtool_pic_mode_default='no'
			;;
	esac
done

IFS="${slbt_cfg_ifs}"
unset slbt_cfg_ifs


# slibtool: features and argument handline
# ----------------------------------------
_SLIBTOOL_ARG_ENABLE([shared],[build shared libraries],[slibtool_enable_shared])
_SLIBTOOL_ARG_ENABLE([static],[build static libraries],[slibtool_enable_static])
_SLIBTOOL_ARG_ENABLE([dlopen],[allow -dlopen and -dlpreopen],[slibtool_enable_dlopen])
_SLIBTOOL_ARG_ENABLE([win32-dll],[natively support win32 dll's],[slibtool_enable_win32_dll])
_SLIBTOOL_ARG_ENABLE([fast-install],[optimize for fast installation],[slibtool_enable_fast_install])
_SLIBTOOL_ARG_WITH([pic],[override defaults for pic object usage],[slibtool_pic_mode])
_SLIBTOOL_ARG_WITH([sysroot],[absolute path to the target's sysroot],[slibtool_sysroot])


# slibtool: set flavor
# --------------------
slibtool_set_flavor
LIBTOOL='$(SLIBTOOL)'
SLIBTOOL="${SLIBTOOL}${SLIBTOOL_FLAGS:+ }${SLIBTOOL_FLAGS}"

AC_SUBST([LIBTOOL])
AC_SUBST([SLIBTOOL])
AC_SUBST([SLIBTOOL_FLAGS])
AC_SUBST([SLIBTOOL_SYSROOT])

AC_SUBST([LIBLTDL])
AC_SUBST([LTDLINCL])
AC_SUBST([LTDLDEPS])
])


# SLIBTOOL_LANG(_language_)
# -------------------------
AC_DEFUN([SLIBTOOL_LANG],[
AC_REQUIRE([SLIBTOOL_PREREQ])

# slibtool: SLIBTOOL_LANG(C)
m4_if([$1],[C],[
AC_PROG_CC
AC_PROG_CPP
])


m4_if([$1],[C++],[
# slibtool: SLIBTOOL_LANG(C++)
AC_PROG_CC
AC_PROG_CPP
AC_PROG_CXX
AC_PROG_CXXCPP
])

m4_if([$1],[Fortran 77],[
# slibtool: SLIBTOOL_LANG(Fortran 77)
AC_PROG_FC
AC_PROG_F77
])
])


# produce a backward compatible slibtool.cfg
AC_CONFIG_COMMANDS_PRE(
	AC_CONFIG_FILES(
		[slibtool.cfg:Makefile],
		[rm -f slibtool.cfg || exit 2;]
		[_slibtool="${SLIBTOOL:-slibtool}";]
		[${_slibtool%% *} --mkvars=Makefile --config \
			${slibtool_prefer_sltdl_switch:-}     \
			> slibtool.cfg]))

# optionally create libtool as a symlink to slibtool.sh
AC_CONFIG_COMMANDS_PRE(
	[if [[ -s slibtool.sh ]]; then
		ln -f -s slibtool.sh libtool || exit 2
	fi])


# SLIBTOOL_PREREQ(_version_)
# --------------------------
AC_DEFUN([SLIBTOOL_PREREQ],[

AC_PROG_AWK
AC_PROG_LEX
AC_PROG_SED
AC_PROG_YACC

AC_PROG_AR
AC_PROG_NM
AC_PROG_RANLIB

AC_PROG_LN_S
AC_PROG_MKDIR_P
])


# SLIBTOOL_OUTPUT
# ---------------
AC_DEFUN([SLIBTOOL_OUTPUT],[
_slibtool_cmd="${SLIBTOOL:-slibtool}"
_slibtool_cmd="${_slibtool_cmd%% *}"
_slibtool_aux_dir=$("${_slibtool_cmd}" -print-aux-dir)
cp -p "${_slibtool_aux_dir}/slibtool.sh" 'libtool'
])

# drop-in replacement
# -------------------
AC_DEFUN([LT_INIT],             [SLIBTOOL_INIT($@)])
AC_DEFUN([LT_LANG],             [SLIBTOOL_LANG($@)])
AC_DEFUN([LT_PREREQ],           [SLIBTOOL_PREREQ($@)])
AC_DEFUN([LT_OUTPUT],           [SLIBTOOL_OUTPUT($@)])

AC_DEFUN([AC_PROG_LIBTOOL],     [SLIBTOOL_INIT($@)])
AC_DEFUN([AM_PROG_LIBTOOL],     [SLIBTOOL_INIT($@)])

AC_DEFUN([AC_PROG_AR],          [SLIBTOOL_PROG_AR($@)])
AC_DEFUN([AM_PROG_AR],          [SLIBTOOL_PROG_AR($@)])

AC_DEFUN([AC_PROG_NM],          [SLIBTOOL_PROG_NM($@)])
AC_DEFUN([AM_PROG_NM],          [SLIBTOOL_PROG_NM($@)])

AC_DEFUN([AC_PROG_RC],          [SLIBTOOL_PROG_RC($@)])
AC_DEFUN([LT_PROG_RC],          [SLIBTOOL_PROG_RC($@)])

AC_DEFUN([AC_PROG_RANLIB],      [SLIBTOOL_PROG_RANLIB($@)])
AC_DEFUN([AM_PROG_RANLIB],      [SLIBTOOL_PROG_RANLIB($@)])

AC_DEFUN([AC_PROG_LEX],         [SLIBTOOL_PROG_LEX($@)])
AC_DEFUN([AM_PROG_LEX],         [SLIBTOOL_PROG_LEX($@)])

AC_DEFUN([AC_ENABLE_SHARED],    [SLIBTOOL_ENABLE_SHARED($@)])
AC_DEFUN([AM_ENABLE_SHARED],    [SLIBTOOL_ENABLE_SHARED($@)])

AC_DEFUN([AC_ENABLE_STATIC],    [SLIBTOOL_ENABLE_STATIC($@)])
AC_DEFUN([AM_ENABLE_STATIC],    [SLIBTOOL_ENABLE_STATIC($@)])

AC_DEFUN([AC_DISABLE_SHARED],   [SLIBTOOL_DISABLE_SHARED($@)])
AC_DEFUN([AM_DISABLE_SHARED],   [SLIBTOOL_DISABLE_SHARED($@)])

AC_DEFUN([AC_DISABLE_STATIC],   [SLIBTOOL_DISABLE_STATIC($@)])
AC_DEFUN([AM_DISABLE_STATIC],   [SLIBTOOL_DISABLE_STATIC($@)])

AC_DEFUN([LT_LIB_M],            [SLIBTOOL_LFLAG_LIBM($@)])
AC_DEFUN([LT_LIB_DLLOAD],       [SLIBTOOL_LFLAG_LTDL($@)])

AC_DEFUN([LTDL_INIT],           [SLTDL_INIT($@)])

# deprecated and no-op macros
# ---------------------------
AC_DEFUN([AC_LIBTOOL_DLOPEN],[])
AC_DEFUN([AC_LIBTOOL_WIN32_DLL],[])
AC_DEFUN([AC_DISABLE_FAST_INSTALL],[])
AC_DEFUN([AC_LIBTOOL_PROG_COMPILER_PIC],[])

AC_DEFUN([LT_PATH_AR],[])
AC_DEFUN([LT_PATH_AS],[])
AC_DEFUN([LT_PATH_LD],[])
AC_DEFUN([LT_PATH_NM],[])
AC_DEFUN([LT_PATH_RANLIB],[])
AC_DEFUN([LT_CONFIG_LTDL_DIR],[])
