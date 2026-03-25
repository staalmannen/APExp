# cfgfini.sh: require slibtool's --dumpmachine output to be
#             both accurate and complete also during the
#             toolchain's initial bootstrapping phase.
# invoked from within the project-agnostic configure script.

# this file is covered by COPYING.SLIBTOOL.

slibtool_cfgfini_error_msg()
{
	printf '%s\n' "$@" >&2
	printf '%s\n' "$@" >&3
}

slibtool_cfgfini()
{
	if [ "${mb_cchost_set:-}" = 'yes' ]; then
		return 0;

	elif [ -n "$ccenv_host_dumpmachine_switch" ]; then
		return 0;
	fi

	slibtool_cfgfini_error_msg
	slibtool_cfgfini_error_msg "$mb_package: the host compiler, \`$ccenv_host_cc\`, does not provide a -dumpmachine switch."
	slibtool_cfgfini_error_msg "$mb_package: please specify the host manually either by passing the --cchost argument to"
	slibtool_cfgfini_error_msg "             $mb_package's configure script, or by setting the CCHOST environment variable."
	slibtool_cfgfini_error_msg "$mb_package: this requirement aims to ensure a complete and accurate \`slibtool --dumpmachine\`"
	slibtool_cfgfini_error_msg "             output also during the toolchain's initial bootstrapping phase."
	slibtool_cfgfini_error_msg

	config_failure
}

slibtool_cfgfini
