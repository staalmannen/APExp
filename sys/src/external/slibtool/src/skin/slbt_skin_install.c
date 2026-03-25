#include "slibtool_install_impl.h"
#include "slibtool_visibility_impl.h"
#include "argv/argv.h"

const slbt_hidden struct argv_option slbt_install_options[] = {
	{"help",	'h',TAG_INSTALL_HELP,ARGV_OPTARG_NONE,0,0,0,
			"display install mode help"},

	{"sysroot",	0,TAG_INSTALL_SYSROOT,ARGV_OPTARG_REQUIRED,0,0,"<sysroot>",
			"reference only: the target's sysroot directory"},

	{0,		'c',TAG_INSTALL_COPY,ARGV_OPTARG_NONE,0,0,0,
			"copy"},

	{0,		'f',TAG_INSTALL_FORCE,ARGV_OPTARG_NONE,0,0,0,
			"force copy"},

	{0,		'd',TAG_INSTALL_MKDIR,ARGV_OPTARG_NONE,0,0,0,
			"create directories"},

	{0,		'D',TAG_INSTALL_TARGET_MKDIR,ARGV_OPTARG_NONE,0,0,0,
			"create target directories"},

	{0,		's',TAG_INSTALL_STRIP,ARGV_OPTARG_NONE,0,0,0,
			"strip symbols"},

	{0,		'p',TAG_INSTALL_PRESERVE,ARGV_OPTARG_NONE,0,0,0,
			"preserve symbols"},

	{0,		'o',TAG_INSTALL_USER,ARGV_OPTARG_REQUIRED,0,0,"<user>",
			"set %s ownership"},

	{0,		'g',TAG_INSTALL_GROUP,ARGV_OPTARG_REQUIRED,0,0,"<group>",
			"set %s ownership"},

	{0,		'm',TAG_INSTALL_MODE,ARGV_OPTARG_REQUIRED,0,0,"<mode>",
			"set permissions to %s"},

	{0,		't',TAG_INSTALL_DSTDIR,ARGV_OPTARG_REQUIRED,0,0,"<dstdir>",
			"install to %s"},

	{0,0,0,0,0,0,0,0}
};
