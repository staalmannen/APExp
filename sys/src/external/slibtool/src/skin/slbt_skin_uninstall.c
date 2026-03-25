#include "slibtool_uninstall_impl.h"
#include "slibtool_visibility_impl.h"
#include "argv/argv.h"

const slbt_hidden struct argv_option slbt_uninstall_options[] = {
	{"help",	'h',TAG_UNINSTALL_HELP,ARGV_OPTARG_NONE,0,0,0,
			"display uninstall mode help"},

	{"version",	0,TAG_UNINSTALL_VERSION,ARGV_OPTARG_NONE,0,0,0,
			"display version information"},

	{"sysroot",	0,TAG_UNINSTALL_SYSROOT,ARGV_OPTARG_REQUIRED,0,0,"<sysroot>",
			"reference only: the target's sysroot directory"},

	{"force",	'f',TAG_UNINSTALL_FORCE,ARGV_OPTARG_NONE,0,0,0,
			"force file removal"},

	{"dir",		'd',TAG_UNINSTALL_RMDIR,ARGV_OPTARG_NONE,0,0,0,
			"remove empty directories"},

	{"recursive",	'r',TAG_UNINSTALL_RECURSIVE,ARGV_OPTARG_NONE,0,0,0,
			"remove directories recursively; "
			"passing this argument to slibtool is forbidden"},

	{"verbose",	'v',TAG_UNINSTALL_VERBOSE,ARGV_OPTARG_NONE,0,0,0,
			"spray the terminal with colorful information"},

	{0,0,0,0,0,0,0,0}
};
