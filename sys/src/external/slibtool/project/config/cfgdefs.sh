# in projects where [ $mb_use_custom_cfgdefs = yes ],
# cfgdefs.sh is invoked from within ./configure via
# . $mb_project_dir/project/cfgdefs.sh

# a successful return from cfgdefs.sh will be followed
# by a second invocation of the config_copy() function,
# reflecting any changes to common config variables
# made by cfgdefs.sh.

# finally, cfgdefs.sh may update the contents of the
# config-time generated cfgdefs.mk.


# sofort's config test framework
. "$mb_project_dir/sofort/cfgtest/cfgtest.sh"


# slibtool now provides a mechanism to specifiy the
# preferred ar(1), as(1), nm(1), and ranlib(1) to be
# invoked by slibtool(1) when used for native builds
# and when no other tool had been specified. These
# configure arguments only affect slibtool's runtime
# tool choices, and the configure arguments below
# accordingly refer to the preferred "host" (rather
# than "native") tools.

_mb_quotes='\"'

for arg ; do
	case "$arg" in
		--m4-dir=*)
                        m4_dir=${arg#*=}
			;;

		--with-preferred-host-ar=*)
                        slbt_preferred_host_ar=${_mb_quotes}${arg#*=}${_mb_quotes}
			;;

		--with-preferred-host-as=*)
                        slbt_preferred_host_as=${_mb_quotes}${arg#*=}${_mb_quotes}
			;;

		--with-preferred-host-nm=*)
                        slbt_preferred_host_nm=${_mb_quotes}${arg#*=}${_mb_quotes}
			;;

		--with-preferred-host-ranlib=*)
                        slbt_preferred_host_ranlib=${_mb_quotes}${arg#*=}${_mb_quotes}
			;;
		*)
			error_msg ${arg#}: "unsupported config argument."
			exit 2
	esac
done


cfgdefs_output_custom_defs()
{
	if [ -z "${m4_dir:-}" ]; then
		m4_dir="${mb_datadir}/${mb_package}"
	fi

	if [ $mb_cfgtest_cfgtype = 'host' ]; then
		cfgtest_cflags_append -DSLBT_PREFERRED_HOST_AR=${slbt_preferred_host_ar:-0}
		cfgtest_cflags_append -DSLBT_PREFERRED_HOST_AS=${slbt_preferred_host_as:-0}
		cfgtest_cflags_append -DSLBT_PREFERRED_HOST_NM=${slbt_preferred_host_nm:-0}
		cfgtest_cflags_append -DSLBT_PREFERRED_HOST_RANLIB=${slbt_preferred_host_ranlib:-0}

		cfgtest_newline
		cfgtest_comment '# m4,aux'
		mb_cfgtest_makevar='M4_DIR'
		cfgtest_makevar_set "$m4_dir"
	fi
}


cfgdefs_perform_common_tests()
{
	# headers
	cfgtest_header_presence 'sys/syscall.h'
}


cfgdefs_perform_target_tests()
{
	# init
	cfgtest_newline
	cfgtest_host_section

	# common tests
	cfgdefs_perform_common_tests

	# pretty cfgdefs.mk
	cfgtest_newline
}

# strict: some tests might fail
set +e

# target-specific tests
cfgdefs_perform_target_tests

# strict: restore mode
set -e

# cfgdefs.in --> cfgdefs.mk
cfgdefs_output_custom_defs

# all done
return 0
