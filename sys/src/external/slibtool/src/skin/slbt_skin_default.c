#include "slibtool_driver_impl.h"
#include "slibtool_visibility_impl.h"
#include "argv/argv.h"

const slbt_hidden struct argv_option slbt_default_options[] = {
	{"version",		0,TAG_VERSION,ARGV_OPTARG_NONE,0,0,0,
				"show version information."},

	{"help",		'h',TAG_HELP,ARGV_OPTARG_OPTIONAL,0,0,0,
				"show usage information."},

	{"help-all",		'h',TAG_HELP_ALL,ARGV_OPTARG_NONE,0,0,0,
				"show comprehensive help information."},

	{"heuristics",		0,TAG_HEURISTICS,ARGV_OPTARG_OPTIONAL,0,0,"<path>",
				"enable/disable creation of shared/static libraries "
				"by parsing a project-specific shell script, "
				"the %s of which is either provided via this "
				"command-line argument, or detected by the program."},

	{"mkvars",		0,TAG_MKVARS,ARGV_OPTARG_REQUIRED,0,0,"<makefile>",
				"obtain information about the current build project "
				"from the specified %s."},

	{"mode",		0,TAG_MODE,ARGV_OPTARG_REQUIRED,0,
				"clean|compile|execute|finish"
				"|install|link|uninstall|ar"
				"|stoolie|slibtoolize",0,
				"set the execution mode, where <mode> "
				"is one of {%s}. of the above modes, "
				"'finish' is not needed and is therefore "
				"a no-op; 'clean' is currently not implemented, "
				"however its addition is expected before the "
				"next major release."},

	{"print-aux-dir",	0,TAG_PRINT_AUX_DIR,ARGV_OPTARG_NONE,
				ARGV_OPTION_HYBRID_ONLY,0,0,
				"print the directory of the package-installed, "
				"backward-compatible ltmain.sh and slibtool.sh; "
				"for additional information, see the slibtoolize(1) "
				"manual page."},

	{"print-m4-dir",	0,TAG_PRINT_M4_DIR,ARGV_OPTARG_NONE,
				ARGV_OPTION_HYBRID_ONLY,0,0,
				"print the directory of the package-installed slibtool.m4; "
				"for additional information, see the slibtoolize(1) "
				"manual page."},

	{"print-shared-ext",	0,TAG_PRINT_SHARED_EXT,ARGV_OPTARG_NONE,
				ARGV_OPTION_HYBRID_ONLY,0,0,
				"print the shared library extension for the specified "
				"(or otherwise detected) host."},

	{"print-static-ext",	0,TAG_PRINT_STATIC_EXT,ARGV_OPTARG_NONE,
				ARGV_OPTION_HYBRID_ONLY,0,0,
				"print the static library extension for the specified "
				"(or otherwise detected) host."},

	{"finish",		0,TAG_FINISH,ARGV_OPTARG_NONE,0,0,0,
				"same as --mode=finish"},

	{"dry-run",		'n',TAG_DRY_RUN,ARGV_OPTARG_NONE,0,0,0,
				"do not spawn any processes, "
				"do not make any changes to the file system."},

	{"tag",			0,TAG_TAG,ARGV_OPTARG_REQUIRED,0,
				"CC|CXX|FC|F77|ASM|NASM|RC|disable-static|disable-shared",0,
				"a universal playground game; "
				"currently accepted tags are {%s}."},

	{"config",		0,TAG_CONFIG,ARGV_OPTARG_NONE,0,0,0,
				"print a compatible --config output"},

	{"info",		0,TAG_INFO,ARGV_OPTARG_NONE,0,0,0,
				"display detected (or cached) environment information."},

	{"rosylee",		0,TAG_INFO,ARGV_OPTARG_NONE,0,0,0,
				"synonym for --info"},

	{"valerius",		0,TAG_INFO,ARGV_OPTARG_NONE,0,0,0,
				"alternative for --rosylee"},

	{"debug",		0,TAG_DEBUG,ARGV_OPTARG_NONE,0,0,0,
				"display internal debug information."},

	{"features",		0,TAG_FEATURES,ARGV_OPTARG_NONE,0,0,0,
				"show feature information."},

	{"dumpmachine",		0,TAG_DUMPMACHINE,ARGV_OPTARG_NONE,0,0,0,
				"print the cached result of the native compiler's "
				"-dumpmachine output (bootstrapping: print the cached, "
				"manual setting of CCHOST)."},

	{"legabits",		0,TAG_LEGABITS,ARGV_OPTARG_OPTIONAL,0,
				"enabled|disabled",0,
				"enable/disable legacy bits, i.e. "
				"the installation of an .la wrapper "
				"along with its associated shared library "
				"and/or static archive. option syntax is "
				"--legabits[=%s]"},

	{"ccwrap",		0,TAG_CCWRAP,ARGV_OPTARG_REQUIRED,0,0,
				"<program>",
				"use %s as a compiler driver wrapper; "
				"for the purpose of compatibility, "
				"this switch may be omitted for known "
				"wrappers (ccache, compiler, distcc, "
				"and purify) when immediately followed "
				"by the compiler argument."},

	{"no-warnings",		0,TAG_WARNINGS,ARGV_OPTARG_NONE,0,0,0,""},

	{"preserve-dup-deps",	0,TAG_DEPS,ARGV_OPTARG_NONE,0,0,0,
				"leave the dependency list alone."},

	{"annotate",		0,TAG_ANNOTATE,ARGV_OPTARG_REQUIRED,0,
				"always|never|minimal|full",0,
				"modify default annotation options; "
				"the defautls are full annotation when "
				"stdout is a tty, and no annotation "
				"at all otherwise; accepted modes "
				"are {%s}."},

	{"quiet",		0,TAG_SILENT,ARGV_OPTARG_NONE,0,0,0,
				"do not say anything."},

	{"silent",		0,TAG_SILENT,ARGV_OPTARG_NONE,0,0,0,
				"say absolutely nothing."},

	{"verbose",		0,TAG_VERBOSE,ARGV_OPTARG_NONE,0,0,0,
				"generate lots of informational messages "
				"that nobody can understand."},

	{"host",		0,TAG_HOST,ARGV_OPTARG_REQUIRED,0,0,"<host>",
				"set an explicit (cross-)host."},

	{"flavor",		0,TAG_FLAVOR,ARGV_OPTARG_REQUIRED,0,
				"bsd|cygwin|darwin|linux|midipix|mingw",
				0,"explicitly specify the host's flavor; "
				"currently accepted flavors are {%s}."},

	{"ar",			0,TAG_AR,ARGV_OPTARG_REQUIRED,0,0,"<ar>",
				"explicitly specify the archiver to be used."},

	{"as",			0,TAG_AS,ARGV_OPTARG_REQUIRED,0,0,"<as>",
				"explicitly specify the assembler to be used (with dlltool)."},

	{"nm",			0,TAG_NM,ARGV_OPTARG_REQUIRED,0,0,"<nm>",
				"explicitly specify the name mangler to be used."},

	{"ranlib",		0,TAG_RANLIB,ARGV_OPTARG_REQUIRED,0,0,"<ranlib>",
				"explicitly specify the librarian to be used."},

	{"dlltool",		0,TAG_DLLTOOL,ARGV_OPTARG_REQUIRED,0,0,"<dlltool>",
				"explicitly specify the PE import library generator "
				"to be used."},

	{"mdso",		0,TAG_MDSO,ARGV_OPTARG_REQUIRED,0,0,"<mdso>",
				"explicitly specify the PE custom import library "
				"generator to be used."},

	{"windres",		0,TAG_WINDRES,ARGV_OPTARG_REQUIRED,0,0,"<windres>",
				"explicitly specify the PE resource compiler "
				"to be used."},

	{"implib",		0,TAG_IMPLIB,ARGV_OPTARG_REQUIRED,0,
				"idata|dsodeps",0,
				"PE import libraries should either use the legacy "
				"format (.idata section) and be generated by dlltool, "
				"or the custom format (.dsodeps section) and be "
				"generated by mdso."},

	{"warnings",		0,TAG_WARNINGS,ARGV_OPTARG_REQUIRED,0,
				"all|none|error",0,
				"set the warning reporting level; "
				"accepted levels are {%s}."},

	{"W",			0,TAG_WARNINGS,ARGV_OPTARG_REQUIRED,
				ARGV_OPTION_HYBRID_ONLY|ARGV_OPTION_HYBRID_JOINED,
				"all|none|error","",
				"convenient shorthands for the above."},

	{"output",		'o',TAG_OUTPUT,ARGV_OPTARG_REQUIRED,0,0,"<file>",
				"write output to %s."},

	{"target",		0,TAG_TARGET,ARGV_OPTARG_REQUIRED,
				ARGV_OPTION_HYBRID_SPACE,0,"<target>",
				"set an explicit (cross-)target, then pass it to "
				"the compiler."},

	{"R",			0,TAG_LDRPATH,ARGV_OPTARG_REQUIRED,
				ARGV_OPTION_HYBRID_ONLY|ARGV_OPTION_HYBRID_CIRCUS,0,0,
				"encode library path into the executable image "
				"[currently a no-op]"},

	{"bindir",		0,TAG_BINDIR,ARGV_OPTARG_REQUIRED,
				ARGV_OPTION_HYBRID_ONLY|ARGV_OPTION_HYBRID_SPACE,0,0,
				"override destination directory when installing "
				"PE shared libraries. Not needed, ignored for "
				"compatibility."},

	{"shrext",		0,TAG_SHREXT,ARGV_OPTARG_REQUIRED,
				ARGV_OPTION_HYBRID_ONLY|ARGV_OPTION_HYBRID_SPACE,0,0,
				"shared library extention, including the dot, that "
				"should override the default for the target system. "
				"regardless of build target and type (native/cross), "
				"you should never need to use this option."},

	{"rpath",		0,TAG_RPATH,ARGV_OPTARG_REQUIRED,
				ARGV_OPTION_HYBRID_ONLY|ARGV_OPTION_HYBRID_SPACE,0,0,
				"where a library should eventually be "
				"installed, relative to $(DESTDIR)$(PREFIX)"},

	{"sysroot",		0,TAG_SYSROOT,ARGV_OPTARG_REQUIRED,0,0,"<sysroot>",
				"an absolute sysroot path to pass to the compiler "
				"or linker driver."},

	{"release",		0,TAG_RELEASE,ARGV_OPTARG_REQUIRED,
				ARGV_OPTION_HYBRID_ONLY|ARGV_OPTION_HYBRID_SPACE,0,0,
				"specify release information; this will result "
				"in the generation of libfoo-x.y.z.so, "
				"followed by the creation of libfoo.so "
				"as a symlink thereto."},

	{"objectlist",		0,TAG_OBJECTLIST,ARGV_OPTARG_REQUIRED,
				ARGV_OPTION_HYBRID_ONLY|ARGV_OPTION_HYBRID_SPACE,
				0,"<file>",
				"add the object listed in %s to the object vector}."},

	{"dlopen",		0,TAG_DLOPEN,ARGV_OPTARG_REQUIRED,
				ARGV_OPTION_HYBRID_ONLY|ARGV_OPTION_HYBRID_SPACE,
				0,"<module>",
				"create and link into the dynamic library, dynamic module, "
				"or executable program a minimal, backward-compatible dlsyms "
				"vtable. On modern systems, this has the same effect as "
				"``-dlpreopen force``."},

	{"dlpreopen",		0,TAG_DLPREOPEN,ARGV_OPTARG_REQUIRED,
				ARGV_OPTION_HYBRID_ONLY|ARGV_OPTION_HYBRID_SPACE,
				0,"<FILE>",
				"Link the specified %s into the generated library "
				"or executable, and make it available to the compiled "
				"shared library, dynamic module, or executable program "
				"via a backward-compatible dlsymas vtable. The special "
				"arguments 'self' and 'force' can be used to request "
				"that symbols from the executable program be added "
				"to the vtable, and that a vtable always be created, "
				"respectively."},

	{"export-dynamic",	0,TAG_EXPORT_DYNAMIC,ARGV_OPTARG_NONE,
				ARGV_OPTION_HYBRID_ONLY,0,0,
				"allow symbols in the output file to be resolved via dlsym()."},

	{"export-symbols",	0,TAG_EXPSYMS_FILE,ARGV_OPTARG_REQUIRED,
				ARGV_OPTION_HYBRID_ONLY|ARGV_OPTION_HYBRID_SPACE,
				0,"<symfile>",
				"only export the symbols that are listed in %s."},

	{"export-symbols-regex",0,TAG_EXPSYMS_REGEX,ARGV_OPTARG_REQUIRED,
				ARGV_OPTION_HYBRID_ONLY|ARGV_OPTION_HYBRID_SPACE,
				0,"<regex>",
				"only export symbols mathing the regex expression %s."},

	{"module",		0,TAG_MODULE,ARGV_OPTARG_NONE,
				ARGV_OPTION_HYBRID_ONLY,0,0,
				"create a shared object that will only be "
				"loaded at runtime via dlopen(3). the shared "
				"object name need not follow the platform's "
				"library naming conventions."},

	{"all-static",		0,TAG_ALL_STATIC,ARGV_OPTARG_NONE,
				ARGV_OPTION_HYBRID_ONLY,0,0,
				"for programs, create a zero-dependency, "
				"statically linked binary; for libraries, "
				"only create an archive of non-pic objects."},

	{"disable-static",	0,TAG_DISABLE_STATIC,ARGV_OPTARG_NONE,
				ARGV_OPTION_HYBRID_ONLY,0,0,
				"for libraries, only create a shared library, "
				"and accordingly do not create an archive "
				"containing the individual object files."},

	{"disable-shared",	0,TAG_DISABLE_SHARED,ARGV_OPTARG_NONE,
				ARGV_OPTION_HYBRID_ONLY,0,0,
				"for libraries, only create an archive "
				"containing the individual object files, and "
				"accordingly do not create a shared library."},

	{"avoid-version",	0,TAG_AVOID_VERSION,ARGV_OPTARG_NONE,
				ARGV_OPTION_HYBRID_ONLY,0,0,
				"do not store version information, "
				"do not create version-specific symlinks."},

	{"version-info",	0,TAG_VERSION_INFO,ARGV_OPTARG_REQUIRED,
				ARGV_OPTION_HYBRID_ONLY|ARGV_OPTION_HYBRID_SPACE,0,
				"<current>[:<revision>[:<age>]]",
				"specify version information using a %s syntax."},

	{"version-number",	0,TAG_VERSION_NUMBER,ARGV_OPTARG_REQUIRED,
				ARGV_OPTION_HYBRID_ONLY|ARGV_OPTION_HYBRID_SPACE,0,
				"<major>[:<minor>[:<revision>]]",
				"specify version information using a %s syntax."},

	{"no-suppress",		0,TAG_NO_SUPPRESS,ARGV_OPTARG_NONE,
				ARGV_OPTION_HYBRID_ONLY,0,0,
				"transparently forward all "
				"compiler-generated output."},

	{"no-install",		0,TAG_NO_INSTALL,ARGV_OPTARG_NONE,
				ARGV_OPTION_HYBRID_ONLY,0,0,
				"consider the executable image wrapper "
				"to be optional "
				"[currently a no-op]."},

	{"prefer-pic",		0,TAG_PREFER_PIC,ARGV_OPTARG_NONE,
				ARGV_OPTION_HYBRID_ONLY,0,0,
				"pick on non-PIC objects."},

	{"prefer-non-pic",	0,TAG_PREFER_NON_PIC,ARGV_OPTARG_NONE,
				ARGV_OPTION_HYBRID_ONLY,0,0,
				"pick on PIC objects."},

	{"shared",		0,TAG_SHARED,ARGV_OPTARG_NONE,
				ARGV_OPTION_HYBRID_ONLY,0,0,
				"only build .libs/srcfile.o"},

	{"static",		0,TAG_STATIC,ARGV_OPTARG_NONE,
				ARGV_OPTION_HYBRID_ONLY,0,0,
				"only build ./srcfile.o"},

	{"static-libtool-libs",	0,TAG_STATIC_LIBTOOL_LIBS,ARGV_OPTARG_NONE,
				ARGV_OPTION_HYBRID_ONLY,0,0,
				"statically link libtool libraries "
				"[currently a no-op]"},

	{"prefer-sltdl",	0,TAG_PREFER_SLTDL,ARGV_OPTARG_NONE,
				0,0,0,
				"prefer the use of libsltdl over the system's "
				"ltdl library, specifically by substituting "
				"-lltdl linker arguments with -lsltdl ones."},

	{"Wc",			0,TAG_COMPILER_FLAG,ARGV_OPTARG_REQUIRED,
				ARGV_OPTION_HYBRID_ONLY|ARGV_OPTION_HYBRID_COMMA,
				0,"<flag>[,<flag]...",
				"pass comma-separated flags to the compiler; "
				"syntax: -Wc,%s"},

	{"Xcompiler",		0,TAG_VERBATIM_FLAG,ARGV_OPTARG_REQUIRED,
				ARGV_OPTION_HYBRID_ONLY|ARGV_OPTION_HYBRID_SPACE,
				0,"<flag>",
				"pass a raw flag to the compiler."},

	{"Xlinker",		0,TAG_VERBATIM_FLAG,ARGV_OPTARG_REQUIRED,
				ARGV_OPTION_HYBRID_ONLY|ARGV_OPTION_HYBRID_SPACE,
				0,"<flag>",
				"pass a raw flag to the compiler linker-driver."},

	{"XCClinker",		0,TAG_VERBATIM_FLAG,ARGV_OPTARG_REQUIRED,
				ARGV_OPTION_HYBRID_ONLY|ARGV_OPTION_HYBRID_SPACE,
				0,"<flag>",
				"pass a raw flag to the compiler linker-driver."},

	{"weak",		0,TAG_WEAK,ARGV_OPTARG_REQUIRED,
				ARGV_OPTION_HYBRID_ONLY|ARGV_OPTION_HYBRID_SPACE,
				0,"<LIBNAME>",
				"hint only, currently a no-op."},

	{"no-undefined",	0,TAG_NO_UNDEFINED,ARGV_OPTARG_NONE,
				ARGV_OPTION_HYBRID_ONLY,0,0,
				"disallow unresolved references."},

	{"thread-safe",		0,TAG_THREAD_SAFE,ARGV_OPTARG_NONE,
				ARGV_OPTION_HYBRID_ONLY,0,0,
				"sleep tight, your threads are now safe."},

	{0,0,0,0,0,0,0,0}
};
