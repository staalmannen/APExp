# cfgtest.sh: sofort's config test framework,
# for use from within a project's custom cfgdefs.sh.

# this file is covered by COPYING.SOFORT.

# in the common scenario, host-specific tests are preceded
# by a single invocation of cfgtest_host_section, whereas
# native (build) system tests are preceded by the invocation
# of cfgtest_native_section.

# cfgdefs fraework variables:
# mb_cfgtest_cc:      the compiler used for the current test
# mb_cfgtest_pkgconf: the pkgconf utility used for the current test
# mb_cfgtest_cflags:  the compiler flags used for the current test
# mb_cfgtest_ldflags: the linker flags used for the current test
# mb_cfgtest_cfgtype: the type of the current test (host/native)
# mb_cfgtest_makevar: the make variable affected by the current test
# mb_cfgtest_headers: headers for ad-hoc inclusion with the current test
# mb_cfgtest_attr:    if supported, the compiler-specific attribute definition

# cfgtest_function_presence() input variables:
# mb_cfgtest_fnname:  function name (i.e. memcmp)
# mb_cfgtest_fntype:  function type (i.e. int)
# mb_cfgtest_fnargs:  function args (i.e. const void *, const void *, size_t)
# mb_cfgtest_fnincs:  function incs (i.e. string.h,stddef.h,stdlib.h)

# special values:
# mb_cfgtest_makevar: when set to '@' (or not set), results of the current
#                       test shall not be appended to cfgdefs.mk.

cfgtest_newline()
{
	printf '\n' >> $mb_pwd/cfgdefs.mk
}


cfgtest_comment()
{
	mb_internal_str='#'

	for mb_internal_arg ; do
		mb_internal_str="$mb_internal_str $mb_internal_arg"
	done

	printf '%s\n' "$mb_internal_str" >> $mb_pwd/cfgdefs.mk
}


cfgtest_host_section()
{
	mb_cfgtest_cc="$ccenv_host_cc"
	mb_cfgtest_pkgconf="${ccenv_host_pkgconf:-false}"
	mb_cfgtest_cfgtype='host'
	mb_cfgtest_stdin_input=${ccenv_host_stdin_input:-}
	mb_cfgtest_environment=${ccenv_host_cc_environment:-}

	mb_cfgtest_cflags=$(${mb_make} -n -f "$mb_pwd/Makefile.tmp" \
		OS_DSO_EXRULES=default                              \
		OS_SONAME=symlink                                   \
		OS_ARCHIVE_EXT='.a'                                 \
		.cflags-host)

	mb_cfgtest_cflags="${mb_cfgtest_cflags#*: }"

	mb_cfgtest_ldflags=$(${mb_make} -n -f "$mb_pwd/Makefile.tmp" \
		OS_DSO_EXRULES=default                               \
		OS_SONAME=symlink                                    \
		OS_ARCHIVE_EXT='.a'                                  \
		.ldflags-host)

	mb_cfgtest_ldflags="${mb_cfgtest_ldflags#*: }"
}


cfgtest_native_section()
{
	mb_cfgtest_cc="$ccenv_native_cc"
	mb_cfgtest_pkgconf="${ccenv_native_pkgconf:-false}"
	mb_cfgtest_cfgtype='native'
	mb_cfgtest_stdin_input=${ccenv_native_stdin_input:-}
	mb_cfgtest_environment=${ccenv_native_cc_environment:-}

	mb_cfgtest_cflags=$(${mb_make} -n -f "$mb_pwd/Makefile.tmp" \
		OS_DSO_EXRULES=default                              \
		OS_SONAME=symlink                                   \
		OS_ARCHIVE_EXT='.a'                                 \
		.cflags-native)

	mb_cfgtest_cflags="${mb_cfgtest_cflags#*: }"

	mb_cfgtest_ldflags=$(${mb_make} -n -f "$mb_pwd/Makefile.tmp" \
		OS_DSO_EXRULES=default                               \
		OS_SONAME=symlink                                    \
		OS_ARCHIVE_EXT='.a'                                  \
		.ldflags-native)

	mb_cfgtest_ldflags="${mb_cfgtest_ldflags#*: }"
}


cfgtest_prolog()
{
	cfgtest_line_dots='...........................'
	cfgtest_line_dots="${cfgtest_line_dots}${cfgtest_line_dots}"
	cfgtest_tool_desc=" == trying ${mb_cfgtest_cfgtype} ${1}: ${2}"
	cfgtest_tool_dlen="${#cfgtest_line_dots}"

	printf '\n%s\n' '________________________' >&3
	printf "cfgtest: probing for ${mb_cfgtest_cfgtype} ${1}: ${2}\n\n" >&3

	if [ "${cfgtest_silent:-}" != 'yes' ]; then
		printf "%${cfgtest_tool_dlen}.${cfgtest_tool_dlen}s" \
			"${cfgtest_tool_desc}  ${mb_line_dots}"
	fi
}


cfgtest_epilog()
{
	cfgtest_line_dots='...............'
	cfgtest_tool_dlen="$((${#cfgtest_line_dots} - ${#2}))"

	if [ "${cfgtest_silent:-}" != 'yes' ]; then
		printf "%${cfgtest_tool_dlen}.${cfgtest_tool_dlen}s  %s.\n" \
			"${cfgtest_line_dots}" "${2}"
	fi

	if [ "${1}" = 'snippet' ] && [ -f 'a.out' ]; then
		rm -f 'a.out'
	fi

	if [ "$mb_cfgtest_stdin_input" = 'no' ]; then
		rm 'cfgtest_c3RyaWN0X21vZGUK.c'
	fi

	if [ "${1}" = 'snippet' ] && [ "${2}" = '(error)' ]; then
		printf '\n\ncfgtest: the %s compiler %s %s.\n' \
			"$mb_cfgtest_cfgtype"                 \
			'failed to compile the above code'   \
			"${1}" >&3
		printf '%s\n' '------------------------' >&3
		return 1
	fi

	if [ "${1}" = 'attr' ] && [ "${2}" = '(error)' ]; then
		printf '\n\ncfgtest: the %s compiler %s _%s_ attribute.\n' \
			"$mb_cfgtest_cfgtype"                             \
			'does not appear to support the'                 \
			"${3}" >&3
		printf '%s\n' '------------------------' >&3
		return 1
	fi

	if [ "${1}" = 'builtin' ] && [ "${2}" = '(error)' ]; then
		rm -f 'a.out'
		rm -f 'cfgtest_c3RyaWN0X21vZGUK.c'

		printf '\n\ncfgtest: the %s compiler %s %s builtin.\n' \
			"$mb_cfgtest_cfgtype"                         \
			'does not appear to provide the'             \
			"__builtin_${3}()" >&3
		printf '%s\n' '------------------------' >&3
		return 1
	fi

	if [ "${1}" = 'fnapi' ] && [ "${2}" = '(error)' ]; then
		rm -f 'a.out'
		rm -f 'cfgtest_c3RyaWN0X21vZGUK.c'

		printf '\n\ncfgtest: %s compiler: the function %s %s %s.\n' \
			"$mb_cfgtest_cfgtype"                      \
			"${3}" 'is either not present'             \
			'or does not match the provided signature' \
			>&3
		printf '%s\n' '------------------------' >&3
		return 1
	fi

	if [ "${2}" = '-----' ] || [ "${2}" = '(missing)' ]; then
		printf '\n\ncfgtest: %s %s is missing or cannot be found.\n' "${1}" "${3}" >&3
		printf '%s\n' '------------------------' >&3
		return 1
	elif [ "${1}" = 'size-of-type' ] && [ "${2}" = '(error)' ]; then
		printf '\n\ncfgtest: could not determine size of type `%s.\n' "${3}'" >&3
		printf '%s\n' '------------------------' >&3
		return 1
	elif [ "${1}" = 'switch' ] && [ "${2}" = '(error)' ]; then
		printf '\n\ncfgtest: the switch `%s is not supported by the %s compiler.\n' \
			"${3}'" "$mb_cfgtest_cfgtype" >&3
		printf '%s\n' '------------------------' >&3
		return 1
	elif [ "${2}" = '(error)' ]; then
		printf '\n\ncfgtest: %s `%s is not defined or cannot be used.\n' "${1}" "${3}'" >&3
		printf '%s\n' '------------------------' >&3
		return 1
	fi
}


cfgtest_entity_size_prolog()
{
	cfgtest_line_dots='.......................'
	cfgtest_line_dots="${cfgtest_line_dots}${cfgtest_line_dots}"
	cfgtest_tool_desc=" == checking size of ${mb_cfgtest_cfgtype} type: ${@}"
	cfgtest_tool_dlen="${#cfgtest_line_dots}"

	printf '\n%s\n' '________________________' >&3
	printf "cfgtest: checking size of ${mb_cfgtest_cfgtype} type: ${@}\n\n" >&3

	printf "%${cfgtest_tool_dlen}.${cfgtest_tool_dlen}s" \
		"${cfgtest_tool_desc}  ${mb_line_dots}"
}


cfgtest_makevar_set()
{
	if [ -n "${@}" ]; then
		mb_internal_str='= '
	else
		mb_internal_str='='
	fi

	printf '%-25s%s%s\n' "$mb_cfgtest_makevar" "$mb_internal_str" "${@}" \
		>> $mb_pwd/cfgdefs.mk

	unset cfgtest_internal_unit_test
}


cfgtest_makevar_append()
{
	mb_internal_str='+='

	for mb_internal_arg ; do
		if ! [ -z "$mb_internal_arg" ]; then
			mb_internal_str="$mb_internal_str $mb_internal_arg"
		fi
	done

	if [ "${mb_cfgtest_makevar:-@}" != '@' ]; then
		printf '%-24s%s\n' "$mb_cfgtest_makevar" "$mb_internal_str" \
			>> $mb_pwd/cfgdefs.mk
	fi

	unset cfgtest_internal_unit_test
}


cfgtest_cflags_append()
{
	if [ $mb_cfgtest_cfgtype = 'host' ]; then
		mb_internal_makevar='CFLAGS_CONFIG'
	else
		mb_internal_makevar='NATIVE_CFLAGS'
	fi

	mb_cfgtest_makevar_saved=$mb_cfgtest_makevar
	mb_cfgtest_makevar=$mb_internal_makevar

	cfgtest_makevar_append "$@"
	mb_cfgtest_makevar=$mb_cfgtest_makevar_saved
}


cfgtest_ldflags_append()
{
	if [ $mb_cfgtest_cfgtype = 'host' ]; then
		mb_internal_makevar='LDFLAGS_CONFIG'
	else
		mb_internal_makevar='NATIVE_LDFLAGS'
	fi

	mb_cfgtest_makevar_saved=$mb_cfgtest_makevar
	mb_cfgtest_makevar=$mb_internal_makevar

	cfgtest_makevar_append "$@"
	mb_cfgtest_makevar=$mb_cfgtest_makevar_saved
}


cfgtest_common_init()
{
	# cfgtest variables
	cfgtest_type="${1:-}"

	if [ "$mb_cfgtest_stdin_input" = 'no' ]; then
		if [ "$cfgtest_type" = 'lib' ]; then
			cfgtest_fmt='%s cfgtest_c3RyaWN0X21vZGUK.c -o a.out'
		elif [ "$cfgtest_type" = 'ldflag' ]; then
			cfgtest_fmt='%s cfgtest_c3RyaWN0X21vZGUK.c -o a.out'
		else
			cfgtest_fmt='%s -c cfgtest_c3RyaWN0X21vZGUK.c -o a.out'
		fi
	elif [ "$cfgtest_type" = 'asm' ]; then
		cfgtest_fmt='%s -c -xc - -o a.out'
	elif [ "$cfgtest_type" = 'attr' ]; then
		cfgtest_fmt='%s -c -xc - -o a.out -Werror'
	elif [ "$cfgtest_type" = 'builtin' ]; then
		cfgtest_fmt='%s -xc - -o a.out -Werror -Wl,--no-undefined'
	elif [ "$cfgtest_type" = 'fnapi' ]; then
		cfgtest_fmt='%s -xc - -o a.out -Werror -Wl,--no-undefined'
	elif [ "$cfgtest_type" = 'lib' ]; then
		cfgtest_fmt='%s -xc - -o a.out'
	elif [ "$cfgtest_type" = 'ldflag' ]; then
		cfgtest_fmt='%s -xc - -o a.out'
	else
		cfgtest_fmt='%s -S -xc - -o -'
	fi


	if [ "$cfgtest_type" = 'lib' ]; then
		cfgtest_cmd=$(printf "$cfgtest_fmt %s %s %s" \
			"$mb_cfgtest_cc"                     \
			"$mb_cfgtest_cflags"                 \
			"$mb_cfgtest_ldflags"                \
			"$cfgtest_libs")

	elif [ "$cfgtest_type" = 'ldflag' ]; then
		cfgtest_cmd=$(printf "$cfgtest_fmt %s %s %s" \
			"$mb_cfgtest_cc"                     \
			"$mb_cfgtest_cflags"                 \
			"$mb_cfgtest_ldflags"                \
			"$cfgtest_switches")

	elif [ "$cfgtest_type" = 'switch' ]; then
		cfgtest_cmd=$(printf "$cfgtest_fmt %s %s" \
			"$mb_cfgtest_cc"                  \
			"$mb_cfgtest_cflags"              \
			"$cfgtest_switches")
	else
		cfgtest_cmd=$(printf "$cfgtest_fmt %s" \
			"$mb_cfgtest_cc"               \
			"$mb_cfgtest_cflags")
	fi


	if [ -n "$mb_cfgtest_headers" ]; then
		cfgtest_inc=$(printf '#include <%s>\n' $mb_cfgtest_headers)
		cfgtest_src=$(printf '%s\n_\n' "$cfgtest_inc" \
			| m4 -D_="$cfgtest_code_snippet")
	else
		cfgtest_inc=
		cfgtest_src="$cfgtest_code_snippet"
	fi


	# config.log
	printf "$cfgtest_fmt" "$mb_cfgtest_cc" >&3

	for cfgtest_cflag in $(printf '%s' "$mb_cfgtest_cflags"); do
		printf ' \\\n\t%s' "$cfgtest_cflag" >&3
	done

	for cfgtest_ldflag in $(printf '%s' "$mb_cfgtest_ldflags"); do
		printf ' \\\n\t%s' "$cfgtest_ldflag" >&3
	done

	if [ "$cfgtest_type" = 'lib' ]; then
		for cfgtest_lib in $(printf '%s' "$cfgtest_libs"); do
			printf ' \\\n\t%s' "$cfgtest_lib" >&3
		done

	elif [ "$cfgtest_type" = 'switch' ] || [ "$cfgtest_type" = 'ldflag' ]; then
		for cfgtest_switch in $(printf '%s' "$cfgtest_switches"); do
			printf ' \\\n\t%s' "$cfgtest_switch" >&3
		done
	fi

	if [ "$cfgtest_type" = 'builtin' ] || [ "$cfgtest_type" = 'fnapi' ]; then
		printf ' \\\n'                   >&3
		printf '<< _SRCEOF\n'            >&3
		cat 'cfgtest_c3RyaWN0X21vZGUK.c' >&3
		printf '_SRCEOF\n\n\n'           >&3
	else
		printf ' \\\n'                           >&3
		printf '<< _SRCEOF\n%s\n' "$cfgtest_src" >&3
		printf '_SRCEOF\n\n\n'                   >&3
	fi

	if [ "$mb_cfgtest_stdin_input" = 'no' ]; then
		printf '%s' "$cfgtest_src" > 'cfgtest_c3RyaWN0X21vZGUK.c'
		cfgtest_src=
	fi
}


cfgtest_header_presence()
{
	#init
	cfgtest_prolog 'header' "${1}"

	cfgtest_code_snippet=$(printf '#include <%s>\n' "${1}")
	cfgtest_code_onedecl='int fn(void){return 0;}'

	cfgtest_code_snippet=$(printf '%s\n%s\n' \
			"$cfgtest_code_snippet"   \
			"$cfgtest_code_onedecl")

	cfgtest_common_init

	# execute
	printf '%s\n' "$cfgtest_src"                \
		| eval $(printf '%s' "$cfgtest_cmd") \
		> /dev/null 2>&3                      \
	|| cfgtest_epilog 'header' '-----' "<${1}>"    \
	|| return

	# result
	mb_internal_str=$(printf '%s%s' '-DHAVE_' "${1}"  \
			| sed -e 's/\./_/g' -e 's@/@_@g'  \
			| tr "[:lower:]" "[:upper:]")

	if [ -z ${cfgtest_internal_unit_test:-} ]; then
		cfgtest_cflags_append "$mb_internal_str"
	else
		cfgtest_makevar_append "$mb_internal_str"
	fi

	printf 'cfgtest: %s header <%s> was found and may be included.\n' \
		"$mb_cfgtest_cfgtype" "${1}" >&3
	printf '%s\n' '------------------------' >&3

	cfgtest_epilog 'header' "${1}"
}


cfgtest_header_absence()
{
	#init
	cfgtest_prolog 'header absence' "${1}"

	cfgtest_code_snippet=$(printf '#include <%s>\n' "${1}")
	cfgtest_code_onedecl='int fn(void){return 0;}'

	cfgtest_code_snippet=$(printf '%s\n%s\n' \
			"$cfgtest_code_snippet"   \
			"$cfgtest_code_onedecl")

	cfgtest_common_init

	# execute
	printf '%s\n' "$cfgtest_src"                \
		| eval $(printf '%s' "$cfgtest_cmd") \
		> /dev/null 2>&3                      \
	&& printf 'cfgtest: %s header <%s>: no error.' \
		"$mb_cfgtest_cfgtype" "${1}" >&3        \
	&& cfgtest_epilog 'header' "${1}"                \
	&& return

	# result
	mb_internal_str=$(printf '%s%s' '-DHAVE_NO_' "$@" \
			| sed -e 's/\./_/g' -e 's@/@_@g'  \
			| tr "[:lower:]" "[:upper:]")

	if [ -z ${cfgtest_internal_unit_test:-} ]; then
		cfgtest_cflags_append "$mb_internal_str"
	else
		cfgtest_makevar_append "$mb_internal_str"
	fi

	printf 'cfgtest: %s header <%s> may not be included.\n' \
		"$mb_cfgtest_cfgtype" "${1}" >&3
	printf '%s\n' '------------------------' >&3

	cfgtest_epilog 'header' '-----' "${1}"
}


cfgtest_interface_presence()
{
	# init
	cfgtest_prolog 'interface' "${1}"

	cfgtest_code_snippet=$(printf 'void (*addr)() = (void (*)())&%s;\n' "${1}")

	cfgtest_common_init

	# execute
	printf '%s\n' "$cfgtest_src"                  \
		| eval $(printf '%s' "$cfgtest_cmd")   \
		> /dev/null 2>&3                        \
	|| cfgtest_epilog 'interface' '(error)' "${1}"   \
	|| return

	# result
	mb_internal_str=$(printf '%s%s' '-DHAVE_' "$@"  \
			| sed -e 's/\./_/g'             \
			| tr "[:lower:]" "[:upper:]")

	if [ -z ${cfgtest_internal_unit_test:-} ]; then
		cfgtest_cflags_append "$mb_internal_str"
	else
		cfgtest_makevar_append "$mb_internal_str"
	fi

	printf 'cfgtest: %s interface `%s'"'"' is available.\n' \
		"$mb_cfgtest_cfgtype" "${1}" >&3
	printf '%s\n' '------------------------' >&3

	cfgtest_epilog 'interface' "${1}"

	return 0
}


cfgtest_decl_presence()
{
	# init
	cfgtest_prolog 'decl' "${1}"

	cfgtest_code_snippet=$(printf 'void * any = (void *)(%s);' "${1}")

	cfgtest_common_init

	# execute
	printf '%s\n' "$cfgtest_src"                \
		| eval $(printf '%s' "$cfgtest_cmd") \
		> /dev/null 2>&3                      \
	|| cfgtest_epilog 'decl' '(error)' "${1}"      \
	|| return

	# does the argument solely consist of the macro or enum member name?
	mb_internal_str=$(printf '%s' "$@" | tr -d '[a-z][A-Z][0-9][_]')

	if [ -n "$mb_internal_str" ]; then
		cfgtest_epilog 'decl' '(defined)'
		return 0
	fi

	# result
	mb_internal_str=$(printf '%s%s' '-DHAVE_DECL_' "$@"  \
			| sed -e 's/\./_/g'                  \
			| tr "[:lower:]" "[:upper:]")

	if [ -z ${cfgtest_internal_unit_test:-} ]; then
		cfgtest_cflags_append "$mb_internal_str"
	else
		cfgtest_makevar_append "$mb_internal_str"
	fi

	printf 'cfgtest: `%s'"'"' is defined for the %s system.\n' \
		"${1}" "$mb_cfgtest_cfgtype" >&3
	printf '%s\n' '------------------------' >&3

	cfgtest_epilog 'decl' '(defined)'

	return 0
}


cfgtest_type_size()
{
	cfgtest_entity_size_prolog "$@"

	mb_internal_size=''
	mb_internal_test='char x[(sizeof(%s) == %s) ? 1 : -1];'

	for mb_internal_guess in 8 4 2 1 16 32 64 128; do
		if [ -z $mb_internal_size ]; then
			printf '# guess %s ===>\n' "$mb_internal_guess" >&3

			mb_internal_type="$@"

			cfgtest_code_snippet=$(printf "$mb_internal_test" \
				"$mb_internal_type" "$mb_internal_guess")

			cfgtest_common_init

			printf '%s\n' "$cfgtest_src"                \
				| eval $(printf '%s' "$cfgtest_cmd") \
				> /dev/null 2>&3                      \
			&& mb_internal_size=$mb_internal_guess

			printf '\n' >&3
		fi
	done

	# unrecognized type, or type size not within range
	if [ -z $mb_internal_size ]; then
		cfgtest_epilog 'size-of-type' '(error)' "@"
		return 1
	fi

	# -DSIZEOF_TYPE=SIZE
	mb_internal_str=$(printf '%s%s=%s' '-DSIZEOF_'        \
				"$mb_internal_type"           \
				"$mb_internal_size"           \
			| sed -e 's/\ /_/g' -e 's/*/P/g'      \
			| tr "[:lower:]" "[:upper:]")

	if [ -z ${cfgtest_internal_unit_test:-} ]; then
		cfgtest_cflags_append "$mb_internal_str"
	else
		cfgtest_makevar_append "$mb_internal_str"
	fi

	printf 'cfgtest: size of type `%s'"'"' determined to be %s\n' \
		"${@}" "$mb_internal_size" >&3
	printf '%s\n' '------------------------' >&3

	cfgtest_epilog 'size-of-type' "$mb_internal_size"

	return 0
}


cfgtest_attr_visibility()
{
	# init
	cfgtest_prolog 'compiler visibility attr' "${1}"

	cfgtest_attr_syntax='__attribute__((__visibility__("'"${1}"'")))'
	cfgtest_code_snippet="$cfgtest_attr_syntax"' int f_'"${1}"'(void);'

	cfgtest_common_init 'attr'

	# execute
	printf '%s\n' "$cfgtest_src"                \
		| eval $(printf '%s' "$cfgtest_cmd") \
		> /dev/null 2>&3                      \
	|| cfgtest_epilog 'attr' '(error)' "${1}"      \
	|| return

	# result
	mb_cfgtest_attr=$(printf '__attribute__\\(\\(__visibility__\\(\\"%s\\"\\)\\)\\)' "${1}")

	printf 'cfgtest: %s compiler: above attribute is supported; see also ccenv/%s.mk.\n\n' \
		"$mb_cfgtest_cfgtype" "$mb_cfgtest_cfgtype" >&3

	cfgtest_epilog 'attr' '(ok)'

	return 0
}


cfgtest_attr_presence()
{
	# init
	cfgtest_attr="${1}"
	cfgtest_prolog 'compiler attribute:' "${1}"

	case "${cfgtest_attr}" in
		visibility)
			cfgtest_attr_syntax='__attribute__((__visibility__("hidden")))'
			cfgtest_code_snippet="int f_${cfgtest_attr}(int, long, char *, ...) ${cfgtest_attr_syntax};"
			mb_cfgtest_attr='__attribute__\(\(__visibility__\(v\)\)\)'
			;;

		nonnull)
			cfgtest_attr_syntax='__attribute__((__nonnull__(3)))'
			cfgtest_code_snippet="int f_${cfgtest_attr}(int, long, char *, ...) ${cfgtest_attr_syntax};"
			mb_cfgtest_attr='__attribute__\(\(__nonnull__\(x\)\)\)'
			;;

		format)
			cfgtest_attr_syntax='__attribute__((__format__(__printf__, 3, 4)))'
			cfgtest_code_snippet="int f_snprintf(char *, unsigned long, const char *, ...) ${cfgtest_attr_syntax};"
			mb_cfgtest_attr='__attribute__\(\(__format__\(a,s,c\)\)\)'
			;;

		malloc)
			cfgtest_attr_syntax='__attribute__((__malloc__))'
			cfgtest_code_snippet="void * f_malloc(unsigned long) ${cfgtest_attr_syntax};"
			mb_cfgtest_attr='__attribute__\(\(__malloc__\)\)'
			;;

		*)
			cfgtest_attr_syntax="__attribute__((__${cfgtest_attr}__))"
			cfgtest_code_snippet="int f_${cfgtest_attr}(int, ...) ${cfgtest_attr_syntax};"
			mb_cfgtest_attr='__attribute__\(\(__nonnull__\(x\)\)\)'
			mb_cfgtest_attr=$(printf '__attribute__\\(\\(__%s__\\)\\)' "${cfgtest_attr}")
			;;
	esac

	cfgtest_common_init 'attr'

	# execute
	printf '%s\n' "$cfgtest_src"                      \
		| eval $(printf '%s' "$cfgtest_cmd")       \
		> /dev/null 2>&3                            \
	|| cfgtest_epilog 'attr' '(error)' "${cfgtest_attr}" \
	|| return

	# result
	printf 'cfgtest: %s compiler: above attribute is supported; see also ccenv/%s.mk.\n\n' \
		"$mb_cfgtest_cfgtype" "$mb_cfgtest_cfgtype" >&3

	cfgtest_epilog 'attr' '(ok)'

	return 0
}


cfgtest_builtin_presence()
{
	# init
	cfgtest_builtin="${1}"

	case "${cfgtest_builtin}" in
		__builtin_*)
			cfgtest_builtin="${cfgtest_builtin#__builtin_*}"
			;;
	esac

	cfgtest_prolog 'compiler builtin:' "${1}"

	# template
	case "${cfgtest_builtin}" in
		*_overflow | *_overflow_p)
			cfgtest_builtin_group='overflow'
			;;

		ffs   | clz   | ctz   | clrsb   | popcount   | parity  | \
		ffsl  | clzl  | ctzl  | clrsbl  | popcountl  | parityl |  \
		ffsll | clzll | ctzll | clrsbll | popcountll | parityll)
			cfgtest_builtin_group='bitops'
			;;

		expect | prefetch | choose_expr)
			cfgtest_builtin_group='other'
			;;

		*)
			cfgtest_epilog 'builtin' '(error)' "${cfgtest_builtin}"
			return 1;
			;;
	esac

	cfgtest_m4_template_dir="${mb_project_dir}/sofort/cfgtest/snippets/builtins"
	cfgtest_m4_template="${cfgtest_m4_template_dir}/${cfgtest_builtin_group}.m4"

	m4 '-D_BUILTIN='"${cfgtest_builtin}"             \
		"${mb_project_dir}/sofort/core/modern.m4" \
		"${cfgtest_m4_template}"                   \
		> 'cfgtest_c3RyaWN0X21vZGUK.c'

	cfgtest_common_init 'builtin'

	# execute
	cat 'cfgtest_c3RyaWN0X21vZGUK.c'                        \
		| eval $(printf '%s' "$cfgtest_cmd")             \
		> /dev/null 2>&3                                  \
	|| cfgtest_epilog 'builtin' '(error)' "${cfgtest_builtin}" \
	|| return

	# result
	printf 'cfgtest: %s compiler: above builtin is supported; see also ccenv/%s.mk.\n\n' \
		"$mb_cfgtest_cfgtype" "$mb_cfgtest_cfgtype" >&3

	cfgtest_epilog 'builtin' '(ok)'

	return 0
}


cfgtest_function_presence()
{
	# init
	cfgtest_fnname="${mb_cfgtest_fnname}"

	cfgtest_prolog 'function presence:' "${cfgtest_fnname}"

	# template
	cfgtest_m4_template_dir="${mb_project_dir}/sofort/cfgtest/snippets/funcs"
	cfgtest_m4_template="${cfgtest_m4_template_dir}/fnapi.m4"

	m4                                           \
		'-D_FUNCNAME='"${mb_cfgtest_fnname}"  \
		'-D_FUNCTYPE='"${mb_cfgtest_fntype}"   \
		'-D_FUNCARGS='"${mb_cfgtest_fnargs}"    \
		'-D_FUNCINCS='"${mb_cfgtest_fnincs}"     \
		"${mb_project_dir}/sofort/core/modern.m4" \
		"${cfgtest_m4_template}"                   \
		> 'cfgtest_c3RyaWN0X21vZGUK.c'

	cfgtest_common_init 'fnapi'

	# execute
	cat 'cfgtest_c3RyaWN0X21vZGUK.c'                        \
		| eval $(printf '%s' "$cfgtest_cmd")             \
		> /dev/null 2>&3                                  \
	|| cfgtest_epilog 'fnapi' '(error)' "${cfgtest_fnname}"    \
	|| return

	# result
	printf 'cfgtest: %s compiler: above function is present with a matching signature; see also ccenv/%s.mk.\n\n' \
		"$mb_cfgtest_cfgtype" "$mb_cfgtest_cfgtype" >&3

	cfgtest_epilog 'fnapi' '(ok)'

	return 0
}


cfgtest_code_snippet_asm()
{
	# init
	cfgtest_prolog 'support of code snippet' '<...>'

	cfgtest_code_snippet="$@"

	cfgtest_common_init 'asm'

	# execute
	printf '%s\n' "$cfgtest_src"                \
		| eval $(printf '%s' "$cfgtest_cmd") \
		> /dev/null 2>&3                      \
	|| cfgtest_epilog 'snippet' '(error)'          \
	|| return

	# result
	printf 'cfgtest: %s compiler: above code snippet compiled successfully.\n\n' \
		"$mb_cfgtest_cfgtype" >&3

	cfgtest_epilog 'snippet' '(ok)'

	return 0
}


cfgtest_macro_definition()
{
	# init
	cfgtest_prolog 'macro definition' "${1}"

	cfgtest_code_snippet=$(printf '%s\n'      \
		"#ifndef ${1}"                     \
		"#error macro ${1} is not defined." \
		"#endif")

	cfgtest_common_init 'macro'

	# execute
	printf '%s\n' "$cfgtest_src"                \
		| eval $(printf '%s' "$cfgtest_cmd") \
		> /dev/null 2>&3                      \
	|| cfgtest_epilog 'macro' '(error)' "${1}"     \
	|| return

	# result
	printf 'cfgtest: %s compiler: above macro definition test compiled successfully.\n\n' \
		"$mb_cfgtest_cfgtype" >&3

	cfgtest_epilog 'macro' '(defined)'

	return 0
}


cfgtest_library_presence()
{
	# init
	cfgtest_libs=
	cfgtest_spc=

	for cfgtest_lib in ${@}; do
		cfgtest_libs="$cfgtest_libs$cfgtest_spc$cfgtest_lib"
		cfgtest_spc=' '
	done

	if [ "${1}" = "$cfgtest_libs" ]; then
		cfgtest_prolog 'library' "${1#*-l}"
	else
		cfgtest_prolog 'lib module' '(see config.log)'
	fi

	if [ "$mb_cfgtest_environment" = 'freestanding' ]; then
		if [ -z "ccenv_cc_underscore" ]; then
			cfgtest_code_snippet='int start(void){return 0;}'
		else
			cfgtest_code_snippet='int _start(void){return 0;}'
		fi
	else
		cfgtest_code_snippet='int main(void){return 0;}'
	fi

	cfgtest_common_init 'lib'

	# execute
	printf '%s\n' "$cfgtest_src"                \
		| eval $(printf '%s' "$cfgtest_cmd") \
		> /dev/null 2>&3                      \
	|| cfgtest_epilog 'library' '-----' "$@"       \
	|| return 1

	# result
	printf 'cfgtest: `%s'"'"' was accepted by the linker driver.\n' \
		"$cfgtest_libs" >&3
	printf '%s\n' '------------------------' >&3

	cfgtest_epilog 'library' '(present)'

	return 0
}


cfgtest_package_exists()
{
	# init
	cfgtest_pkg=

	for cfgtest_arg in ${@}; do
		case "$cfgtest_arg" in
			-*)
				;;

			*)
				cfgtest_pkg="$cfgtest_arg"
				;;
		esac
	done

	cfgtest_prolog 'package' "$cfgtest_pkg"

	# execute
	"$mb_cfgtest_pkgconf" "${@}"                         \
		> /dev/null 2>&3                              \
	|| cfgtest_epilog 'package' '(missing)' "$cfgtest_pkg" \
	|| return 1

	# result
	printf 'cfgtest: package `%s'"'"' was found.\n' \
		"$cfgtest_pkg" >&3
	printf '%s\n' '------------------------' >&3

	cfgtest_epilog 'package' '(exists)' "$cfgtest_pkg"

	return 0
}


cfgtest_package_config()
{
	# init
	if ! cfgtest_package_exists "${@}"; then
		return 0
	fi

	cfgtest_pkg=

	for cfgtest_arg in ${@}; do
		case "$cfgtest_arg" in
			-*)
				;;

			*)
				cfgtest_pkg="$cfgtest_arg"
				;;
		esac
	done

	cfgtest_makevar_prefix=
	cfgtest_pkgconf_prefix=

	if [ "$mb_cfgtest_cfgtype" = 'native' ]; then
		cfgtest_makevar_prefix='_NATIVE'
	else
		if [ -n "${mb_sysroot}" ]; then
			cfgtest_pkgconf_prefix="--define-variable=prefix=${mb_sysroot}"
		fi
	fi

	cfgtest_newline
	cfgtest_comment 'package config:' "$cfgtest_pkg"

	# foo.pc
	cfgtest_pkgconf_path=$("$mb_cfgtest_pkgconf" \
			--path "${@}"                 \
		2>/dev/null || true)

	if [ -z "$cfgtest_pkgconf_path" ]; then
		cfgtest_pkgconf_path=$("$mb_cfgtest_pkgconf" \
				--debug "${@}" 2>&1           \
				| grep ".pc'$"                 \
				| head -n1                      \
			|| true)

		cfgtest_pkgconf_path="${cfgtest_pkgconf_path##* \'}"
		cfgtest_pkgconf_path="${cfgtest_pkgconf_path%%\'}"
	fi

	mb_cfgtest_makevar=$(printf '%s_PKGCONF_%s'             \
			"$cfgtest_makevar_prefix" "$cfgtest_pkg" \
		| tr '[[:lower:]]' '[[:upper:]]'                  \
		| sed -e 's/-/_/g')

	cfgtest_makevar_set "$cfgtest_pkgconf_path"

	# --cflags
	cfgtest_pkgconf_path=$("$mb_cfgtest_pkgconf" \
			"$cfgtest_pkgconf_prefix"     \
			--cflags "${@}"                \
		| sed 's/[ \t]*$//')

	mb_cfgtest_makevar=$(printf '%s_CFLAGS_%s'              \
			"$cfgtest_makevar_prefix" "$cfgtest_pkg" \
		| tr '[[:lower:]]' '[[:upper:]]'                  \
		| sed -e 's/-/_/g')

	cfgtest_makevar_set "$cfgtest_pkgconf_path"

	# --ldflags
	cfgtest_pkgconf_path=$("$mb_cfgtest_pkgconf" \
			"$cfgtest_pkgconf_prefix"     \
			--libs "${@}"                  \
		| sed 's/[ \t]*$//')

	mb_cfgtest_makevar=$(printf '%s_LDFLAGS_%s'             \
			"$cfgtest_makevar_prefix" "$cfgtest_pkg" \
		| tr '[[:lower:]]' '[[:upper:]]'                  \
		| sed -e 's/-/_/g')

	cfgtest_makevar_set "$cfgtest_pkgconf_path"

	return 0
}


cfgtest_compiler_switch()
{
	# init
	cfgtest_switches=
	cfgtest_spc=

	for cfgtest_switch in $(printf '%s' "${@}"); do
		cfgtest_switches="$cfgtest_switches$cfgtest_spc$cfgtest_switch"
		cfgtest_spc=' '
	done

	if [ -n "${cfgtest_switch_arg:-}" ]; then
		cfgtest_prolog 'compiler switch' "${cfgtest_switches%=*}"

	elif [ "${1}" = "$cfgtest_switches" ]; then
		cfgtest_prolog 'compiler switch' "$cfgtest_switches"

	else
		cfgtest_prolog 'compiler switch combination' "$cfgtest_switches"
	fi

	case "${1}" in
		-Wl,*)
			if [ "$mb_cfgtest_environment" = 'freestanding' ]; then
				cfgtest_switches="$cfgtest_switches -nostdlib -nostartfiles"

				if [ -z "ccenv_cc_underscore" ]; then
					cfgtest_code_snippet='int start(void){return 0;}'
				else
					cfgtest_code_snippet='int _start(void){return 0;}'
				fi
			else
				cfgtest_code_snippet='int main(void){return 0;}'
			fi

			cfgtest_common_init 'ldflag'
			;;

		*)
			cfgtest_code_snippet='int fn(void){return 0;}'
			cfgtest_common_init 'switch'
			;;
	esac

	# execute
	printf '%s\n' "$cfgtest_src"                \
		| eval $(printf '%s' "$cfgtest_cmd") \
		> /dev/null 2>&3                      \
	|| cfgtest_epilog 'switch' '(error)' "$@"      \
	|| return 1

	# result
	printf 'cfgtest: the switch `%s was accepted by the compiler.\n' \
		"$cfgtest_switches'" >&3
	printf '%s\n' '------------------------' >&3

	cfgtest_epilog 'switch' '(accepted)'

	return 0
}


cfgtest_compiler_switch_arg()
{
	cfgtest_switch_arg='yes'

	if cfgtest_compiler_switch "${@}"; then
		cfgtest_ret=0
	else
		cfgtest_ret=1
	fi

	unset cfgtest_switch_arg

	return $cfgtest_ret
}


cfgtest_unit_header_presence()
{
	cfgtest_internal_unit_test='unit_test'
	cfgtest_header_presence "$@" || return 1
	return 0
}


cfgtest_unit_header_absence()
{
	cfgtest_internal_unit_test='unit_test'
	cfgtest_header_absence "$@" || return 1
	return 0
}


cfgtest_unit_interface_presence()
{
	cfgtest_internal_unit_test='unit_test'
	cfgtest_interface_presence "$@" || return 1
	return 0
}


cfgtest_unit_decl_presence()
{
	cfgtest_internal_unit_test='unit_test'
	cfgtest_decl_presence "$@" || return 1
	return 0
}


cfgtest_unit_type_size()
{
	cfgtest_internal_unit_test='unit_test'
	cfgtest_type_size "$@" || return 1
	return 0
}
