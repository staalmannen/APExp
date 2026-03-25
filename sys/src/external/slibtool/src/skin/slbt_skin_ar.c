#include "slibtool_driver_impl.h"
#include "slibtool_visibility_impl.h"
#include "argv/argv.h"

const slbt_hidden struct argv_option slbt_ar_options[] = {
	{"version",	0,TAG_AR_VERSION,ARGV_OPTARG_NONE,0,0,0,
			"show version information"},

	{"help",	'h',TAG_AR_HELP,ARGV_OPTARG_NONE,0,0,0,
			"display ar mode help"},

	{"Wcheck",	0,TAG_AR_CHECK,ARGV_OPTARG_NONE,
			ARGV_OPTION_HYBRID_ONLY,
			"[ARCHIVE-FILE]",0,
			"verify that each %s is a valid archive; "
			"supported variants are BSD, SysV, and PE/COFF"},

	{"Wmerge",	0,TAG_AR_MERGE,ARGV_OPTARG_NONE,
			ARGV_OPTION_HYBRID_ONLY,
			"[ARCHIVE-FILE]",0,
			"merge one or more archive files; "
			"the name of the new archive, which may be the same "
			"as one of the input archives, shall be specified "
			"via the -Woutput switch; order of archive members "
			"shall be retained, and symbol maps shall be "
			"merged as well as normalized."},

	{"Woutput",	0,TAG_AR_OUTPUT,ARGV_OPTARG_REQUIRED,
			ARGV_OPTION_HYBRID_ONLY|ARGV_OPTION_HYBRID_SPACE,
			0,0,
			"specify the name of the archive to be created "
			"(or replaced) as a result of a -Wmerge operation."},

	{"Wprint",	0,TAG_AR_PRINT,ARGV_OPTARG_OPTIONAL,
			ARGV_OPTION_HYBRID_EQUAL|ARGV_OPTION_HYBRID_COMMA,
			"members|symbols",0,
			"print out information pertaining to each archive file "
			"and its various internal elements"},

	{"Wmapfile",	0,TAG_AR_MAPFILE,ARGV_OPTARG_NONE,
			ARGV_OPTION_HYBRID_ONLY,
			0,0,
			"print out a (sorted) map file "
			"(aka symbol file, aka version script), "
			"including either all armap symbols (if no regex filter was "
			"specified), or otherwise only the symbols that match the "
			"specified regex filter."},

	{"Wregex",	0,TAG_AR_REGEX,ARGV_OPTARG_REQUIRED,
			ARGV_OPTION_HYBRID_ONLY|ARGV_OPTION_HYBRID_SPACE,
			0,"<regexp>",
			"filter armap symbols using the specified %s."},

	{"Wdlunit",	0,TAG_AR_DLUNIT,ARGV_OPTARG_REQUIRED,
			ARGV_OPTION_HYBRID_ONLY|ARGV_OPTION_HYBRID_SPACE,
			0,"<dlunit>",
			"consider %s to be the name of "
			"the dynamic library (libfoo), the program (foo), "
			"or the loaded module (foo) for which "
			"a compatible dlsym vtable should be created."},

	{"Wdlsyms",	0,TAG_AR_DLSYMS,ARGV_OPTARG_NONE,
			ARGV_OPTION_HYBRID_ONLY,
			0,0,
			"print out a compatible dlsyms vtable."},

	{"Wnosort",	0,TAG_AR_NOSORT,ARGV_OPTARG_NONE,
			ARGV_OPTION_HYBRID_ONLY,
			0,0,
			"do not sort the symbol list; "
			"affected switches are -Wprint=symbols and -Wmapfile."},

	{"Wpretty",	0,TAG_AR_PRETTY,ARGV_OPTARG_REQUIRED,
			ARGV_OPTION_HYBRID_EQUAL,
			"posix|yaml|hexdata",0,
			"select the pretty printer to be used: "
			"'posix' for ar(1) compatible output; "
			"'yaml' for yaml-formatted data; and "
			"'hexdata' for yaml-formatted data with additional "
			"hexdump output"},

	{"Wposix",	0,TAG_AR_POSIX,ARGV_OPTARG_NONE,
			ARGV_OPTION_HYBRID_ONLY,0,0,
			"a shorthand for -Wpretty=posix"},

	{"Wyaml",	0,TAG_AR_YAML,ARGV_OPTARG_NONE,
			ARGV_OPTION_HYBRID_ONLY,0,0,
			"a shorthand for -Wpretty=yaml"},

	{"Wverbose",	0,TAG_AR_VERBOSE,ARGV_OPTARG_NONE,
			ARGV_OPTION_HYBRID_ONLY,0,0,
			"produce verbose output; "
			"in combination with -Wpretty=posix, this will result "
			"in `ar(1) -tv` compatible output."},

	{0,0,0,0,0,0,0,0}
};
