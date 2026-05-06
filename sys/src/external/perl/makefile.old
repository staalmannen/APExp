# Makefile
# This file is derived from Makefile.SH.  Any changes made here will
# be lost the next time you run Configure.
#  Makefile is used to generate makefile.  The only difference
#  is that makefile has the dependencies filled in at the end.

CC = cc
LD = cc

LDFLAGS =  -fstack-protector-strong -L/usr/local/lib
CLDFLAGS =  -fstack-protector-strong -L/usr/local/lib

mallocsrc = 
mallocobj = 
LNS = /usr/bin/ln -s
# NOTE: some systems don't grok "cp -f". XXX Configure test needed?
CPS = cp
RMS = rm -f
ranlib = :
ECHO = echo

# The following are mentioned only to make metaconfig include the
# appropriate questions in Configure.  If you want to change these,
# edit config.sh instead, or specify --man1dir=/wherever on
# installman commandline.
bin = /usr/local/bin
scriptdir = /usr/local/bin
shrpdir = /usr/local/lib/perl5/5.42.2/x86_64-linux/CORE
privlib = /usr/local/lib/perl5/5.42.2
man1dir =  
man1ext = 0
man3dir =  
man3ext = 0

# The following are used to build and install shared libraries for
# dynamic loading.
LDDLFLAGS = -shared -O2 -L/usr/local/lib -fstack-protector-strong
SHRPLDFLAGS = $(LDDLFLAGS)
CCDLFLAGS = -Wl,-E
DLSUFFIX = .so
PLDLFLAGS = 
LIBPERL = libperl.a
LLIBPERL= $(LIBPERL)
SHRPENV = 

# Static targets are ordinarily built without CCCDLFLAGS.  However,
# if building a shared libperl.so that might later be linked into
# another application, then it might be appropriate to also build static
# extensions (usually just DynaLoader) with relocatable code (e.g. -fPIC
# for GNU cc).
STATIC_LDFLAGS = CCCDLFLAGS=

# The following is used to include the current directory in
# the dynamic loader path you are building a shared libperl.
LDLIBPTH = 

# Sometimes running an executable is an adventure.
RUN = 

# When cross-compiling we want to use a (mini)perl built for the host, not the target
HOST_PERL = 
HOST_GENERATE = 
SYSTEM_PERL = perl

# These variables may need to be manually set for non-Unix systems.
AR = /usr/bin/ar
HOST_EXE_EXT = 
EXE_EXT = 
LIB_EXT = .a
OBJ_EXT = .o

# Macros to invoke a copy of miniperl during the build.  Targets which
# are built using these macros should depend on $(MINIPERL_EXE)
MINIPERL_EXE = miniperl$(EXE_EXT)
MINIPERL = $(LDLIBPTH) ./miniperl$(EXE_EXT) -Ilib

# Macros to invoke sort the MANIFEST during build
MANIFEST_SRT = MANIFEST.srt

# Macros to invoke a copy of our fully operational perl during the build.
PERL_EXE = perl$(EXE_EXT)
RUN_PERL = $(LDLIBPTH) $(RUN) ./perl$(EXE_EXT) -Ilib -I.
# Macros to run our tests
RUN_TESTS = $(LDLIBPTH) ./runtests

dynamic_ext =   lib/auto/B/B.so lib/auto/Compress/Raw/Bzip2/Bzip2.so lib/auto/Compress/Raw/Zlib/Zlib.so lib/auto/Cwd/Cwd.so lib/auto/Data/Dumper/Dumper.so lib/auto/Devel/PPPort/PPPort.so lib/auto/Devel/Peek/Peek.so lib/auto/Digest/MD5/MD5.so lib/auto/Digest/SHA/SHA.so lib/auto/Encode/Encode.so lib/auto/Fcntl/Fcntl.so lib/auto/File/DosGlob/DosGlob.so lib/auto/File/Glob/Glob.so lib/auto/Filter/Util/Call/Call.so lib/auto/Hash/Util/Util.so lib/auto/Hash/Util/FieldHash/FieldHash.so lib/auto/I18N/Langinfo/Langinfo.so lib/auto/IO/IO.so lib/auto/IPC/SysV/SysV.so lib/auto/List/Util/Util.so lib/auto/MIME/Base64/Base64.so lib/auto/Math/BigInt/FastCalc/FastCalc.so lib/auto/Opcode/Opcode.so lib/auto/POSIX/POSIX.so lib/auto/PerlIO/encoding/encoding.so lib/auto/PerlIO/mmap/mmap.so lib/auto/PerlIO/via/via.so lib/auto/SDBM_File/SDBM_File.so lib/auto/Socket/Socket.so lib/auto/Storable/Storable.so lib/auto/Sys/Hostname/Hostname.so lib/auto/Sys/Syslog/Syslog.so lib/auto/Time/HiRes/HiRes.so lib/auto/Time/Piece/Piece.so lib/auto/Unicode/Collate/Collate.so lib/auto/Unicode/Normalize/Normalize.so lib/auto/XS/APItest/APItest.so lib/auto/XS/Typemap/Typemap.so lib/auto/attributes/attributes.so lib/auto/mro/mro.so lib/auto/re/re.so lib/auto/threads/threads.so lib/auto/threads/shared/shared.so
dynamic_ext_re = lib/auto/re/re.so
static_ext =  
nonxs_ext =   cpan/Archive-Tar/pm_to_blib dist/Attribute-Handlers/pm_to_blib cpan/AutoLoader/pm_to_blib cpan/CPAN/pm_to_blib cpan/CPAN-Meta/pm_to_blib cpan/CPAN-Meta-Requirements/pm_to_blib cpan/CPAN-Meta-YAML/pm_to_blib dist/Carp/pm_to_blib cpan/Config-Perl-V/pm_to_blib dist/Devel-SelfStubber/pm_to_blib cpan/Digest/pm_to_blib dist/Dumpvalue/pm_to_blib dist/Env/pm_to_blib ext/Errno/pm_to_blib dist/Exporter/pm_to_blib dist/ExtUtils-CBuilder/pm_to_blib cpan/ExtUtils-Constant/pm_to_blib cpan/ExtUtils-Install/pm_to_blib cpan/ExtUtils-MakeMaker/pm_to_blib cpan/ExtUtils-Manifest/pm_to_blib ext/ExtUtils-Miniperl/pm_to_blib cpan/ExtUtils-PL2Bat/pm_to_blib dist/ExtUtils-ParseXS/pm_to_blib cpan/File-Fetch/pm_to_blib ext/File-Find/pm_to_blib cpan/File-Path/pm_to_blib cpan/File-Temp/pm_to_blib ext/FileCache/pm_to_blib dist/Filter-Simple/pm_to_blib dist/FindBin/pm_to_blib cpan/Getopt-Long/pm_to_blib cpan/HTTP-Tiny/pm_to_blib dist/I18N-Collate/pm_to_blib dist/I18N-LangTags/pm_to_blib cpan/IO-Compress/pm_to_blib cpan/IO-Socket-IP/pm_to_blib cpan/IO-Zlib/pm_to_blib cpan/IPC-Cmd/pm_to_blib ext/IPC-Open3/pm_to_blib cpan/JSON-PP/pm_to_blib dist/Locale-Maketext/pm_to_blib cpan/Locale-Maketext-Simple/pm_to_blib cpan/Math-BigInt/pm_to_blib dist/Math-Complex/pm_to_blib cpan/Memoize/pm_to_blib dist/Module-CoreList/pm_to_blib cpan/Module-Load/pm_to_blib cpan/Module-Load-Conditional/pm_to_blib cpan/Module-Loaded/pm_to_blib cpan/Module-Metadata/pm_to_blib cpan/NEXT/pm_to_blib dist/Net-Ping/pm_to_blib cpan/Params-Check/pm_to_blib cpan/Perl-OSType/pm_to_blib ext/PerlIO-scalar/pm_to_blib cpan/PerlIO-via-QuotedPrint/pm_to_blib cpan/Pod-Checker/pm_to_blib cpan/Pod-Escapes/pm_to_blib ext/Pod-Functions/pm_to_blib ext/Pod-Html/pm_to_blib cpan/Pod-Perldoc/pm_to_blib cpan/Pod-Simple/pm_to_blib cpan/Pod-Usage/pm_to_blib dist/Safe/pm_to_blib dist/Search-Dict/pm_to_blib dist/SelfLoader/pm_to_blib cpan/Term-ANSIColor/pm_to_blib cpan/Term-Cap/pm_to_blib dist/Term-Complete/pm_to_blib dist/Term-ReadLine/pm_to_blib cpan/Term-Table/pm_to_blib dist/Test/pm_to_blib cpan/Test-Harness/pm_to_blib cpan/Test-Simple/pm_to_blib dist/Text-Abbrev/pm_to_blib cpan/Text-Balanced/pm_to_blib cpan/Text-ParseWords/pm_to_blib cpan/Text-Tabs/pm_to_blib dist/Thread-Queue/pm_to_blib dist/Thread-Semaphore/pm_to_blib dist/Tie-File/pm_to_blib ext/Tie-Hash-NamedCapture/pm_to_blib ext/Tie-Memoize/pm_to_blib cpan/Tie-RefHash/pm_to_blib cpan/Time-Local/pm_to_blib dist/XSLoader/pm_to_blib cpan/autodie/pm_to_blib dist/autouse/pm_to_blib dist/base/pm_to_blib cpan/bignum/pm_to_blib dist/constant/pm_to_blib dist/encoding-warnings/pm_to_blib cpan/experimental/pm_to_blib dist/if/pm_to_blib dist/lib/pm_to_blib cpan/libnet/pm_to_blib cpan/parent/pm_to_blib cpan/perlfaq/pm_to_blib cpan/podlators/pm_to_blib cpan/version/pm_to_blib
ext = $(dynamic_ext) $(static_ext) $(nonxs_ext)
DYNALOADER = DynaLoader$(OBJ_EXT)

libs = -lpthread -ldl -lm -lcrypt -lutil -lc 

public = $(PERL_EXE) utilities

shellflags = 

# The /dev/tty or the moral equivalent.
devtty = /dev/tty

# This is set to  MAKE=make if your make command doesn't
# do it for you.
#

# Mention gmake here so it gets probed for by Configure.

# If you're going to use valgrind and it can't be invoked as plain valgrind
# then you'll need to change this, or override it on the make command line.
VALGRIND ?= valgrind
VG_TEST  ?= ./perl -e 1 2>/dev/null

DTRACE =  
DTRACE_H = 

DTRACE_PERLLIB_O =  # "dtrace -G" output for perllib_objs
DTRACE_MINI_O    =     # "dtrace -G" output for common and mini
DTRACE_MAIN_O    =     # "dtrace -G" output for perlmain.o

FIRSTMAKEFILE = makefile

# Any special object files needed by this architecture, e.g. os2/os2.obj
ARCHOBJS = 

.SUFFIXES: .c $(OBJ_EXT) .i .s .c.depends

# grrr
SHELL = /bin/sh

# how to tr(anslate) newlines
TRNL = '\n'

OPTIMIZE = -O2

EXTRAS = 

INSTALLPREFIXEXP = /usr/local


CCCMD    = sh $(shellflags) cflags "optimize='$(OPTIMIZE)'" $@

CCCMDSRC = sh $(shellflags) cflags "optimize='$(OPTIMIZE)'" $<

CONFIGPM_FROM_CONFIG_SH = lib/Config.pm lib/Config_heavy.pl
CONFIGPM = $(CONFIGPM_FROM_CONFIG_SH) lib/Config_git.pl

CONFIGPOD = lib/Config.pod

CONFIGH = config.h

private = preplibrary $(CONFIGPM) $(CONFIGPOD) git_version.h lib/buildcustomize.pl

# Files to be built with variable substitution before miniperl
# is available.
sh = Makefile.SH cflags.SH config_h.SH makedepend.SH myconfig.SH runtests.SH pod/Makefile.SH

shextract = Makefile cflags config.h makedepend myconfig runtests pod/Makefile

addedbyconf = UU $(shextract)

# Unicode data files generated by mktables
unidatafiles = lib/unicore/Decomposition.pl lib/unicore/TestProp.pl \
	lib/unicore/CombiningClass.pl lib/unicore/Name.pl \
	lib/unicore/UCD.pl lib/unicore/Name.pm \
	lib/unicore/Heavy.pl lib/unicore/mktables.lst

# Directories of Unicode data files generated by mktables
unidatadirs = lib/unicore/To lib/unicore/lib

h = \
    EXTERN.h INTERN.h XSUB.h \
    av.h cop.h cv.h dosish.h embed.h form.h gv.h handy.h hv.h hv_func.h \
    iperlsys.h keywords.h l1_char_class_tab.h mg.h mydtrace.h op.h \
    op_reg_common.h opcode.h pad.h patchlevel.h perl.h perlapi.h perly.h pp.h \
    proto.h regcomp.h regcomp_internal.h regexp.h regexp_constants.h scope.h \
    sv.h thread.h unixish.h utf8.h util.h warnings.h \
    $(CONFIGH)

c_base = \
    av.c builtin.c caretx.c class.c deb.c doio.c doop.c dquote.c dump.c \
    globals.c gv.c hv.c keywords.c locale.c mathoms.c mg.c mro_core.c \
    numeric.c op.c pad.c peep.c perl.c perlio.c perly.c \
    pp.c pp_ctl.c pp_hot.c pp_pack.c pp_sort.c pp_sys.c \
    reentr.c regcomp.c regcomp_debug.c regcomp_invlist.c regcomp_study.c \
    regcomp_trie.c regexec.c run.c scope.c sv.c taint.c time64.c toke.c \
    universal.c utf8.c util.c \
    $(mallocsrc)

mini_only_src  = opmini.c perlmini.c universalmini.c
mini_only_objs = opmini$(OBJ_EXT) perlmini$(OBJ_EXT) universalmini$(OBJ_EXT)
main_only_objs = op$(OBJ_EXT) perl$(OBJ_EXT) universal$(OBJ_EXT)

c = $(c_base) miniperlmain.c $(mini_only_src)

# split the objects into 3 exclusive sets: those used by both miniperl and
# perl, and those used by just one or the other. Doesn't include the
# actual perl(mini)main.o, nor any dtrace objects.

common_objs = \
    av$(OBJ_EXT) builtin$(OBJ_EXT) caretx$(OBJ_EXT) class$(OBJ_EXT) \
    deb$(OBJ_EXT) doio$(OBJ_EXT) doop$(OBJ_EXT) dquote$(OBJ_EXT) \
    dump$(OBJ_EXT) globals$(OBJ_EXT) gv$(OBJ_EXT) hv$(OBJ_EXT) \
    keywords$(OBJ_EXT) locale$(OBJ_EXT) mathoms$(OBJ_EXT) mg$(OBJ_EXT) \
    mro_core$(OBJ_EXT) numeric$(OBJ_EXT) pad$(OBJ_EXT) peep$(OBJ_EXT) \
    perlio$(OBJ_EXT) perly$(OBJ_EXT) pp$(OBJ_EXT) pp_ctl$(OBJ_EXT) \
    pp_hot$(OBJ_EXT) pp_pack$(OBJ_EXT) pp_sort$(OBJ_EXT) pp_sys$(OBJ_EXT) \
    reentr$(OBJ_EXT) regcomp$(OBJ_EXT) regcomp_debug$(OBJ_EXT) \
    regcomp_invlist$(OBJ_EXT) regcomp_study$(OBJ_EXT) regcomp_trie$(OBJ_EXT) \
    regexec$(OBJ_EXT) run$(OBJ_EXT) scope$(OBJ_EXT) sv$(OBJ_EXT) \
    taint$(OBJ_EXT) time64$(OBJ_EXT) toke$(OBJ_EXT) utf8$(OBJ_EXT) \
    util$(OBJ_EXT) \
    $(mallocobj) $(ARCHOBJS)

miniperl_objs_nodt = $(mini_only_objs) $(common_objs) miniperlmain$(OBJ_EXT)
perllib_objs_nodt  = $(main_only_objs) $(common_objs)


miniperl_objs = $(miniperl_objs_nodt) $(DTRACE_MINI_O)
perllib_objs  = $(perllib_objs_nodt) $(DTRACE_PERLLIB_O)
perlmain_objs = perlmain$(OBJ_EXT) $(DTRACE_MAIN_O)

miniperl_dep = $(miniperl_objs)
perllib_dep = $(perllib_objs)
perlmain_dep = $(perlmain_objs)


perltoc_pod_prereqs = extra.pods pod/perl5422delta.pod pod/perlapi.pod pod/perlintern.pod pod/perlmodlib.pod pod/perluniprops.pod
generated_pods = pod/perltoc.pod $(perltoc_pod_prereqs)
generated_headers = uudmap.h bitcount.h mg_data.h

lintflags = \
    -b \
    -n \
    -p \
    -Ncheck=%all \
    -Nlevel=4 \
    -errchk=parentheses \
    -errhdr=%all \
    -errfmt=src \
    -errtags \
    -erroff=E_ASSIGN_NARROW_CONV \
    -erroff=E_BAD_PTR_CAST \
    -erroff=E_BAD_PTR_CAST_ALIGN \
    -erroff=E_BAD_PTR_INT_COMBINATION \
    -erroff=E_BAD_SIGN_EXTEND \
    -erroff=E_BLOCK_DECL_UNUSED \
    -erroff=E_CASE_FALLTHRU \
    -erroff=E_CONST_EXPR \
    -erroff=E_CONSTANT_CONDITION \
    -erroff=E_END_OF_LOOP_CODE_NOT_REACHED \
    -erroff=E_EQUALITY_NOT_ASSIGNMENT \
    -erroff=E_EXPR_NULL_EFFECT \
    -erroff=E_FALSE_LOGICAL_EXPR \
    -erroff=E_INCL_NUSD \
    -erroff=E_LOOP_EMPTY \
    -erroff=E_MAIN_PARAM \
    -erroff=E_POINTER_TO_OBJECT \
    -erroff=E_PTRDIFF_OVERFLOW \
    -erroff=E_SHIFT_CNT_NEG_TOO_BIG_L \
    -erroff=E_STATIC_UNUSED \
    -erroff=E_TRUE_LOGICAL_EXPR

.c$(OBJ_EXT): 
	@echo `$(CCCMD)` $(PLDLFLAGS) $*.c
	@`$(CCCMD)` $(PLDLFLAGS) $*.c

.c.i:
	@echo `$(CCCMDSRC)` -E $*.c \> $*.i
	@`$(CCCMDSRC)` -E $*.c > $*.i

.c.s:
	@echo `$(CCCMDSRC)` -S $*.c
	@`$(CCCMDSRC)` -S $*.c

all: $(FIRSTMAKEFILE) $(MINIPERL_EXE) $(generated_pods) $(private) $(unidatafiles) $(public) $(dynamic_ext) $(nonxs_ext) extras.make $(MANIFEST_SRT) common_build
	@echo " ";
	@echo "	Everything is up to date. Type '$(MAKE) test' to run test suite."

$(MANIFEST_SRT):	MANIFEST $(PERL_EXE)
	@$(RUN_PERL) Porting/manisort -q || (echo "WARNING: re-sorting MANIFEST"; \
	    $(RUN_PERL) Porting/manisort -q -o MANIFEST; sh -c true)
	@touch $(MANIFEST_SRT)

.PHONY: all utilities

# Both git_version.h and lib/Config_git.pl are built
# by make_patchnum.pl.
git_version.h: lib/Config_git.pl

lib/Config_git.pl: $(MINIPERL_EXE) make_patchnum.pl
	$(MINIPERL) make_patchnum.pl

# make sure that we recompile perl.c if the git version changes
perl$(OBJ_EXT): git_version.h

utils/Makefile: $(MINIPERL_EXE) $(CONFIGPM) utils/Makefile.PL
	$(MINIPERL) utils/Makefile.PL

utilities:	utils/Makefile $(MINIPERL_EXE) $(CONFIGPM) lib/auto/Cwd/Cwd$(DLSUFFIX) FORCE
	@echo " "; echo "	Making utilities"; cd utils; $(LDLIBPTH) $(MAKE) all


# This is now done by installman only if you actually want the man pages.
#	@echo " "; echo "	Making docs"; cd pod; $(MAKE) all;

# Phony target to force checking subdirectories.
# Apparently some makes require an action for the FORCE target.
.PHONY: FORCE
FORCE:
	@sh -c true

opmini.c: op.c
	$(RMS) opmini.c
	$(LNS) op.c opmini.c

opmini$(OBJ_EXT): opmini.c
	echo @`$(CCCMD)` $(PLDLFLAGS) -DPERL_IS_MINIPERL -DPERL_EXTERNAL_GLOB opmini.c
	@`$(CCCMD)` $(PLDLFLAGS) -DPERL_IS_MINIPERL -DPERL_EXTERNAL_GLOB opmini.c

perlmini.c: perl.c
	$(RMS) perlmini.c
	$(LNS) perl.c perlmini.c

perlmini$(OBJ_EXT): perlmini.c
	echo @`$(CCCMD)` $(PLDLFLAGS) -DPERL_IS_MINIPERL -DPERL_EXTERNAL_GLOB perlmini.c
	@`$(CCCMD)` $(PLDLFLAGS) -DPERL_IS_MINIPERL -DPERL_EXTERNAL_GLOB perlmini.c

universalmini.c: universal.c
	$(RMS) universalmini.c
	$(LNS) universal.c universalmini.c

universalmini$(OBJ_EXT): universalmini.c
	echo @`$(CCCMD)` $(PLDLFLAGS) -DPERL_IS_MINIPERL -DPERL_EXTERNAL_GLOB universalmini.c
	@`$(CCCMD)` $(PLDLFLAGS) -DPERL_IS_MINIPERL -DPERL_EXTERNAL_GLOB universalmini.c

cygwin.c: cygwin/cygwin.c
	$(LNS) cygwin/cygwin.c

globals$(OBJ_EXT): $(generated_headers)

uudmap.h mg_data.h: bitcount.h

generate_uudmap$(OBJ_EXT): mg_raw.h

bitcount.h: generate_uudmap$(HOST_EXE_EXT)
	 ./generate_uudmap$(HOST_EXE_EXT) $(generated_headers)
	-@for f in $(generated_headers); do \
	    : $$f; \
	done

generate_uudmap$(HOST_EXE_EXT): generate_uudmap$(OBJ_EXT)
	$(CC) -o generate_uudmap$(EXE_EXT) $(LDFLAGS) generate_uudmap$(OBJ_EXT) $(libs)

perlmain.c: $(MINIPERL_EXE) ext/ExtUtils-Miniperl/pm_to_blib
	$(MINIPERL) -MExtUtils::Miniperl -e 'writemain(\"perlmain.c", @ARGV)' DynaLoader $(static_ext)

# The file ext.libs is a list of libraries that must be linked in
# for static extensions, e.g. -lm -lgdbm, etc.  The individual
# static extension Makefile's add to it.
ext.libs: $(static_ext)
	-@test -f ext.libs || touch ext.libs

$(LIBPERL): $& $(perllib_dep) $(DYNALOADER) $(LIBPERLEXPORT)
	rm -f $(LIBPERL)
	$(AR) rc $(LIBPERL) $(perllib_objs) $(DYNALOADER)
	@$(ranlib) $(LIBPERL)

# How to build executables.

# The $& notation tells Sequent machines that it can do a parallel make,
# and is harmless otherwise.
# The miniperl -w -MExporter line is a basic cheap test to catch errors
# before make goes on to run preplibrary and then MakeMaker on extensions.
# This is very handy because later errors are often caused by miniperl
# build problems but that's not obvious to the novice.
# The Module used here must not depend on Config or any extensions.

# The seemingly cranky ordering of having $(MINIPERL_EXE) depend on
# lib/buildcustomize.pl despite the reality that lib/buildcustomize.pl needs
# miniperl to exist first permits us to
# a) have one rule generate both miniperl and lib/buildcustomize.pl
#    (so that lib/buildcustomize.pl is always available. This simplifies things)
# b) have the rest of the Makefile depend on the more obvious $(MINIPERL_EXE)

$(MINIPERL_EXE): lib/buildcustomize.pl
	@touch $(MINIPERL_EXE)

lib/buildcustomize.pl: $& $(miniperl_dep) write_buildcustomize.pl
	-@rm -f miniperl.xok
	$(CC) $(CLDFLAGS) -o $(MINIPERL_EXE) \
	    $(miniperl_objs) $(libs)
	$(LDLIBPTH) ./miniperl$(HOST_EXE_EXT) -w -Ilib -Idist/Exporter/lib -MExporter -e '<?>' || sh -c 'echo >&2 Failed to build miniperl.  Please run make minitest; exit 1'
	$(MINIPERL) -f write_buildcustomize.pl

$(PERL_EXE): $& $(perlmain_dep) $(LIBPERL) $(static_ext) ext.libs $(PERLEXPORT) write_buildcustomize.pl
	-@rm -f miniperl.xok
	$(SHRPENV) $(CC) -o perl $(CLDFLAGS) $(CCDLFLAGS) $(perlmain_objs) $(static_ext) $(LLIBPERL) `cat ext.libs` $(libs)

.PHONY: makeppport
makeppport: $(MINIPERL_EXE) $(CONFIGPM) $(nonxs_ext)
	$(MINIPERL) mkppport


.PHONY: preplibrary common_build
preplibrary: $(MINIPERL_EXE) $(CONFIGPM) $(PREPLIBRARY_LIBPERL)

$(CONFIGPM_FROM_CONFIG_SH): $(CONFIGPOD)

$(CONFIGPOD): config.sh $(MINIPERL_EXE) configpm Porting/Glossary lib/Config_git.pl
	$(MINIPERL) configpm

unidatafiles $(unidatafiles) pod/perluniprops.pod: uni.data

uni.data: $(MINIPERL_EXE) $(CONFIGPM) lib/unicore/mktables $(nonxs_ext)
	$(MINIPERL) lib/unicore/mktables -C lib/unicore -P pod -maketest -makenormtest -makelist -p
#	Commented out so always runs, mktables looks at far more files than we
#	can in this makefile to decide if needs to run or not
#	touch uni.data

# $(PERL_EXE) and ext because pod_lib.pl needs Digest::MD5
# But also this ensures that all extensions are built before we try to scan
# them, which picks up Devel::PPPort's documentation.
pod/perltoc.pod: $(perltoc_pod_prereqs) $(PERL_EXE) $(ext) pod/buildtoc
	$(RUN_PERL) -f pod/buildtoc -q

pod/perlapi.pod: pod/perlintern.pod

pod/perlintern.pod: $(MINIPERL_EXE) autodoc.pl embed.fnc
	$(MINIPERL) autodoc.pl

pod/perlmodlib.pod: $(MINIPERL_EXE) pod/perlmodlib.PL MANIFEST
	$(MINIPERL) pod/perlmodlib.PL -q

pod/perl5422delta.pod: pod/perldelta.pod
	$(RMS) pod/perl5422delta.pod
	$(LNS) perldelta.pod pod/perl5422delta.pod

extra.pods: $(MINIPERL_EXE)
	-@test ! -f extra.pods || rm -f `cat extra.pods`
	-@rm -f extra.pods
	-@for x in `grep -l '^=[a-z]' README.* | grep -v README.vms` ; do \
	    nx=`echo $$x | sed -e "s/README\.//"`; \
	    $(LNS) ../$$x "pod/perl"$$nx".pod" ; \
	    echo "pod/perl"$$nx".pod" >> extra.pods ; \
	done

extras.make: $(PERL_EXE)
	-@test ! -s extras.lst || PATH="`pwd`:${PATH}" PERL5LIB="`pwd`/lib" $(RUN_PERL) -MCPAN -e '@ARGV&&make(@ARGV)' `cat extras.lst`

extras.test: $(PERL_EXE)
	-@test ! -s extras.lst || PATH="`pwd`:${PATH}" PERL5LIB="`pwd`/lib" $(RUN_PERL) -MCPAN -e '@ARGV&&test(@ARGV)' `cat extras.lst`

extras.install: $(PERL_EXE)
	-@test ! -s extras.lst || PATH="`pwd`:${PATH}" PERL5LIB="`pwd`/lib" $(RUN_PERL) -MCPAN -e '@ARGV&&install(@ARGV)' `cat extras.lst`

.PHONY: install install-strip install-all install-verbose install-silent \
	no-install install.perl install.man install.html

# Set this to an empty string to avoid an attempt of rebuild before install
INSTALL_DEPENDENCE = all

no_install no-install: install-notify

install: install-all

install_all install-all: $(INSTALL_DEPENDENCE) installperl all installman
	$(RUN_PERL) installperl --destdir=$(DESTDIR)  $(INSTALLFLAGS) $(STRIPFLAGS)
	$(RUN_PERL) installman --destdir=$(DESTDIR) 
	-@test ! -s extras.lst || PATH="`pwd`:${PATH}" PERL5LIB="`pwd`/lib" $(RUN_PERL) -Ilib -MCPAN -e '@ARGV&&install(@ARGV)' `cat extras.lst`

install_notify install-notify: $(INSTALL_DEPENDENCE) installperl all installman
	$(RUN_PERL) installperl --destdir=$(DESTDIR) --notify $(INSTALLFLAGS) $(STRIPFLAGS)
	$(RUN_PERL) installman --destdir=$(DESTDIR) --notify

install_silent install-silent: $(INSTALL_DEPENDENCE) installperl all installman
	$(RUN_PERL) installperl --destdir=$(DESTDIR) --silent $(INSTALLFLAGS) $(STRIPFLAGS)
	$(RUN_PERL) installman --destdir=$(DESTDIR) --silent
	-@test ! -s extras.lst || PATH="`pwd`:${PATH}" PERL5LIB="`pwd`/lib" $(RUN_PERL) -Ilib -MCPAN -e '@ARGV&&install(@ARGV)' `cat extras.lst`

install_strip install-strip: $(INSTALL_DEPENDENCE) installperl all installman
	$(RUN_PERL) installperl --destdir=$(DESTDIR) --strip $(INSTALLFLAGS) $(STRIPFLAGS)
	$(RUN_PERL) installman --destdir=$(DESTDIR) --strip
	-@test ! -s extras.lst || PATH="`pwd`:${PATH}" PERL5LIB="`pwd`/lib" $(RUN_PERL) -Ilib -MCPAN -e '@ARGV&&install(@ARGV)' `cat extras.lst`

install_verbose install-verbose: $(INSTALL_DEPENDENCE) installperl all installman
	$(RUN_PERL) installperl --destdir=$(DESTDIR) --verbose $(INSTALLFLAGS) $(STRIPFLAGS)
	$(RUN_PERL) installman --destdir=$(DESTDIR) --verbose
	-@test ! -s extras.lst || PATH="`pwd`:${PATH}" PERL5LIB="`pwd`/lib" $(RUN_PERL) -Ilib -MCPAN -e '@ARGV&&install(@ARGV)' `cat extras.lst`
install.perl:	$(INSTALL_DEPENDENCE) installperl
	$(RUN_PERL) installperl --destdir=$(DESTDIR) $(INSTALLFLAGS) $(STRIPFLAGS)
	-@test ! -s extras.lst || PATH="`pwd`:\${PATH}" PERL5LIB="`pwd`/lib" \$(RUN_PERL) -Ilib -MCPAN -e '@ARGV&&install(@ARGV)' `cat extras.lst`

install.man:	all installman
	$(RUN_PERL) installman --destdir=$(DESTDIR) $(INSTALLFLAGS)

# XXX Experimental. Hardwired values, but useful for testing.
# Eventually Configure could ask for some of these values.
install.html: all installhtml
	-@test -f README.vms && cd vms && $(LNS) ../README.vms README_vms.pod && cd ..
	$(RUN_PERL) installhtml   \
      --podroot=. --podpath=. --recurse  \
      --htmldir=$(privlib)/html   \
      --splithead=pod/perlipc     \
      --splititem=pod/perlfunc    \
      --ignore=Porting/Maintainers.pm,Porting/pumpkin.pod,Porting/repository.pod \
      --verbose

# I now supply perly.c with the kits, so the following section is
# used only if you force bison to run by saying
# 	make regen_perly
# You normally shouldn't remake perly.[ch].

.PHONY: regen_perly

run_byacc run-byacc:
	@echo "run_byacc is obsolete; try 'make regen_perly' instead"

# this outputs perly.h, perly.act and perly.tab
regen_perly regen-perly:
	perl regen_perly.pl

# We don't want to regenerate perly.c and perly.h, but they might
# appear out-of-date after a patch is applied or a new distribution is
# made.
perly.c: perly.y
	-@sh -c true

perly.h: perly.y
	-@sh -c true

SYM  = globvar.sym perlio.sym

SYMH = perlvars.h intrpvar.h

CHMOD_W = chmod +w

# The following files are generated automatically
#	embed.pl:	proto.h embed.h embedvar.h
#	opcode.pl:	opcode.h opnames.h pp_proto.h
#	regcomp.pl:	regnodes.h
#	warnings.pl:	warnings.h lib/warnings.pm
#	feature.pl:	feature.h lib/feature.pm
#	locale.pl:	locale_table.h
# The correct versions should be already supplied with the perl kit,
# in case you don't have perl available.
# To force them to be regenerated, run
#       perl regen.pl
# with your existing copy of perl
# (make regen_headers is kept for backwards compatibility)

.PHONY: regen_headers regen_all

regen:	FORCE
	-perl regen.pl

regen_headers regen-headers:	FORCE
	-perl regen.pl -v

regen_meta regen-meta:  META.yml META.json

META.yml:   FORCE
	PATH="`pwd`:${PATH}" PERL5LIB="`pwd`/lib" $(RUN_PERL) Porting/makemeta -y

META.json:   FORCE
	PATH="`pwd`:${PATH}" PERL5LIB="`pwd`/lib" $(RUN_PERL) Porting/makemeta -j


regen_all regen-all: regen regen_meta

.PHONY:	manisort manicheck

manisort:	FORCE
	@perl Porting/manisort -q || (echo "WARNING: re-sorting MANIFEST"; \
		perl Porting/manisort -q -o MANIFEST; sh -c true)

manicheck:	FORCE
	perl Porting/manicheck

# Extensions:
# Names added to $(dynamic_ext) or $(static_ext) or $(nonxs_ext) will
# automatically get built.  There should ordinarily be no need to change
# any of this part of makefile.
#
# The dummy dependency is a place holder in case $(dynamic_ext) or
# $(static_ext) is empty.
#
# DynaLoader may be needed for extensions that use Makefile.PL.

$(DYNALOADER):	$(MINIPERL_EXE) lib/buildcustomize.pl preplibrary FORCE $(nonxs_ext)
	$(MINIPERL) make_ext.pl $@ $(MAKE_EXT_ARGS) MAKE="$(MAKE)" LIBPERL_A=$(LIBPERL) LINKTYPE=static $(STATIC_LDFLAGS)

d_dummy $(dynamic_ext):	$(MINIPERL_EXE) lib/buildcustomize.pl preplibrary makeppport $(DYNALOADER) FORCE $(PERLEXPORT) $(LIBPERL)
	$(MINIPERL) make_ext.pl $@ $(MAKE_EXT_ARGS) MAKE="$(MAKE)" LIBPERL_A=$(LIBPERL) LINKTYPE=dynamic

s_dummy $(static_ext):	$(MINIPERL_EXE) lib/buildcustomize.pl preplibrary makeppport $(DYNALOADER) FORCE
	$(MINIPERL) make_ext.pl $@ $(MAKE_EXT_ARGS) MAKE="$(MAKE)" LIBPERL_A=$(LIBPERL) LINKTYPE=static $(STATIC_LDFLAGS)

n_dummy $(nonxs_ext):	$(MINIPERL_EXE) lib/buildcustomize.pl preplibrary FORCE
	$(MINIPERL) make_ext.pl $@ $(MAKE_EXT_ARGS) MAKE="$(MAKE)" LIBPERL_A=$(LIBPERL)

cpan/Pod-Simple/pm_to_blib: dist/if/pm_to_blib
ext/Pod-Functions/pm_to_blib: cpan/Pod-Simple/pm_to_blib cpan/Pod-Escapes/pm_to_blib pod/perlfunc.pod
cpan/IO-Compress/pm_to_blib: dist/lib/pm_to_blib

lib/auto/Math/BigInt/FastCalc/FastCalc.so: lib/auto/List/Util/Util.so
lib/auto/Unicode/Normalize/Normalize.so: uni.data

.PHONY: printconfig
printconfig:
	@eval `$(RUN_PERL) -V:$(CONFIGVAR)`; echo $$$(CONFIGVAR)

.PHONY: clean _tidy _mopup _cleaner1 _cleaner2 \
	realclean _realcleaner clobber _clobber \
	distclean veryclean _verycleaner

clean:		realclean

realclean:	_realcleaner _mopup
	@echo "Note that '$(MAKE) realclean' does not delete config.sh or Policy.sh"

_clobber:
	-@rm -f Cross/run-* Cross/to-* Cross/from-* Cross/mkdir
	-rm -rf host
	rm -f t/test_state
	rm -f config.sh cppstdin Policy.sh extras.lst
	rm -f $(MANIFEST_SRT)

clobber:	_realcleaner _mopup _clobber

distclean:	clobber

# Like distclean but also removes emacs backups and *.orig.
veryclean:	_verycleaner _mopup _clobber
	-@rm -f Obsolete Wanted

# Do not 'make _mopup' directly.
_mopup:
	rm -f *$(OBJ_EXT) *$(LIB_EXT) all perlmain.c $(mini_only_src) generate_uudmap$(EXE_EXT) $(generated_headers)
	-rmdir .depending
	-rm *.depends makedepend_file
	-@test -f extra.pods && rm -f `cat extra.pods`
	-@test -f vms/README_vms.pod && rm -f vms/README_vms.pod
	-rm -f perl.exp ext.libs $(generated_pods) uni.data $(mini_only_objs) pod/roffitall
	-rm -f perl.export perl.dll perl.libexp perl.map perl.def
	-rm -f *perl.xok
	-rm -f cygwin.c libperl*.def libperl*.dll cygperl*.dll *.exe.stackdump
	-rm -f $(PERL_EXE) $(MINIPERL_EXE) $(LIBPERL) libperl.*
	-rm -f config.arch config.over $(DTRACE_H)

_cleaner1:
	-cd os2; rm -f Makefile
	-cd pod; $(LDLIBPTH) $(MAKE) $(CLEAN)
	-cd utils; $(LDLIBPTH) $(MAKE) $(CLEAN)
	-@if test -f $(MINIPERL_EXE) ; then \
	for x in $(DYNALOADER) $(dynamic_ext) $(static_ext) $(nonxs_ext) ; do \
	$(MINIPERL) make_ext.pl --target=$(CLEAN) $$x MAKE="$(MAKE)" ; \
	done ; \
	else \
	sh $(CLEAN).sh ; \
	fi
	rm -f realclean.sh veryclean.sh
	-rm -f `grep -v ^# mkppport.lst | grep . | sed -e 's/$$/\/ppport.h/'`

# Dear POSIX, thanks for making the default to xargs to be
# run once if nothing is passed in. It is such a great help.

# Some systems do not support "?", so keep these files separate.

# The Time::HiRes Makefile *should* remove dist/Time-HiRes/xdefine for 'clean',
# but it's possible to get a rebuilt checkout into a state where it can't run
# distclean, and can't recover until the file is gone.
# There's no harm in adding it to the top level 'distclean' target - it should
# anyway by then, and miniperl is long gone.
# Add new rules before that line - the next line (rm -f so_locations ...) is
# used as a placeholder by a regen script.
_cleaner2:
	-rm -f core.*perl.*.? t/core.perl.*.? .?*.c
	rm -f core *perl.core t/core t/*perl.core core.* t/core.*
	rm -f t/$(PERL_EXE) t/rantests
	rm -rf t/tmp*
	rm -rf $(addedbyconf)
	rm -f $(FIRSTMAKEFILE) $(FIRSTMAKEFILE).old makefile.old utils/Makefile
	rm -f $(private)
	rm -rf $(unidatafiles) $(unidatadirs)
	rm -rf lib/auto
	rm -f lib/.exists lib/*/.exists lib/*/*/.exists
	rm -f h2ph.man
	rm -rf .config
	rm -f preload
	rm -f pod2htmd.tmp
	rm -rf pod/perlfunc pod/perlipc
	-rmdir ext/B/lib
	-rm -f dist/Time-HiRes/xdefine
	rm -f so_locations $(LIBPERL_NONSHR)
	-rmdir lib/version lib/threads lib/inc/ExtUtils lib/inc lib/encoding
	-rmdir lib/autodie/exception lib/autodie/Scope lib/autodie lib/XS
	-rmdir lib/Win32API lib/VMS lib/Unicode/Collate/Locale
	-rmdir lib/Unicode/Collate/CJK lib/Unicode/Collate lib/Tie/Hash
	-rmdir lib/Thread lib/Text lib/Test2/Workflow/Task lib/Test2/Workflow
	-rmdir lib/Test2/Util/Table lib/Test2/Util lib/Test2/Tools
	-rmdir lib/Test2/Require lib/Test2/Plugin
	-rmdir lib/Test2/Manual/Tooling/Plugin lib/Test2/Manual/Tooling
	-rmdir lib/Test2/Manual/Testing lib/Test2/Manual/Anatomy
	-rmdir lib/Test2/Manual lib/Test2/IPC/Driver lib/Test2/IPC
	-rmdir lib/Test2/Hub/Interceptor lib/Test2/Hub lib/Test2/Formatter
	-rmdir lib/Test2/EventFacet/Info lib/Test2/EventFacet
	-rmdir lib/Test2/Event/TAP lib/Test2/Event lib/Test2/Compare
	-rmdir lib/Test2/Bundle lib/Test2/AsyncSubtest/Event
	-rmdir lib/Test2/AsyncSubtest lib/Test2/API/InterceptResult
	-rmdir lib/Test2/API lib/Test2 lib/Test/use lib/Test/Tester
	-rmdir lib/Test/Builder/Tester lib/Test/Builder lib/Test
	-rmdir lib/Term/Table lib/Term lib/TAP/Parser/YAMLish
	-rmdir lib/TAP/Parser/SourceHandler lib/TAP/Parser/Scheduler
	-rmdir lib/TAP/Parser/Result lib/TAP/Parser/Iterator lib/TAP/Parser
	-rmdir lib/TAP/Harness lib/TAP/Formatter/File
	-rmdir lib/TAP/Formatter/Console lib/TAP/Formatter lib/TAP
	-rmdir lib/Sys/Syslog lib/Sys lib/Sub lib/Search lib/Scalar/List
	-rmdir lib/Scalar lib/Pod/Text lib/Pod/Simple lib/Pod/Perldoc
	-rmdir lib/Pod/Html lib/PerlIO/via lib/PerlIO lib/Perl lib/Parse/CPAN
	-rmdir lib/Parse lib/Params lib/Net/FTP lib/Module/Load
	-rmdir lib/Module/CoreList lib/Module lib/Memoize lib/Math/BigRat
	-rmdir lib/Math/BigInt lib/Math/BigFloat lib/Math lib/MIME
	-rmdir lib/Locale/Maketext lib/Locale lib/List/Util lib/List
	-rmdir lib/JSON/PP lib/JSON lib/IPC lib/IO/Uncompress/Adapter
	-rmdir lib/IO/Uncompress lib/IO/Socket lib/IO/Compress/Zlib
	-rmdir lib/IO/Compress/Zip lib/IO/Compress/Gzip lib/IO/Compress/Base
	-rmdir lib/IO/Compress/Adapter lib/IO/Compress lib/IO
	-rmdir lib/I18N/LangTags lib/I18N lib/Hash/Util lib/Hash lib/HTTP
	-rmdir lib/Getopt/Long lib/Filter/Util lib/Filter lib/File/Spec
	-rmdir lib/ExtUtils/Typemaps lib/ExtUtils/ParseXS
	-rmdir lib/ExtUtils/MakeMaker/version lib/ExtUtils/MakeMaker
	-rmdir lib/ExtUtils/Liblist lib/ExtUtils/Constant lib/ExtUtils/Command
	-rmdir lib/ExtUtils/CBuilder/Platform/Windows
	-rmdir lib/ExtUtils/CBuilder/Platform lib/ExtUtils/CBuilder
	-rmdir lib/Exporter lib/Encode/Unicode lib/Encode/MIME/Header
	-rmdir lib/Encode/MIME lib/Encode/KR lib/Encode/JP lib/Encode/CN
	-rmdir lib/Encode lib/Digest lib/Devel lib/Data lib/Config/Perl
	-rmdir lib/Compress/Raw lib/Compress lib/Carp lib/CPAN/Plugin
	-rmdir lib/CPAN/Meta/Requirements lib/CPAN/Meta/History lib/CPAN/Meta
	-rmdir lib/CPAN/LWP lib/CPAN/Kwalify lib/CPAN/HTTP lib/CPAN/FTP
	-rmdir lib/CPAN/Exception lib/CPAN/API lib/CPAN lib/Attribute
	-rmdir lib/Archive/Tar lib/Archive lib/App/Prove/State/Result
	-rmdir lib/App/Prove/State lib/App/Prove lib/App lib/Amiga

_realcleaner:
	@$(LDLIBPTH) $(MAKE) _cleaner1 CLEAN=distclean
	@$(LDLIBPTH) $(MAKE) _cleaner2

_verycleaner:
	@$(LDLIBPTH) $(MAKE) _cleaner1 CLEAN=veryclean
	@$(LDLIBPTH) $(MAKE) _cleaner2
	-rm -f *~ *.orig */*~ */*.orig */*/*~ */*/*.orig

.PHONY: lint
lint: $(c)
	rm -f *.ln
	lint $(lintflags) -DPERL_CORE -D_REENTRANT -DDEBUGGING -D_LARGEFILE_SOURCE -D_FILE_OFFSET_BITS=64 $(c)

cscopeflags = -Rb  # Recursive, build-only.

.PHONY:	cscope
# To query the cscope.out "cscope -dLnsymbol" where n = 0 means uses,
# 1 = definitions, 2 = callees, 3 = callers, for example
# "cscope -dL1Perl_mg_set" or run cscope interactively (no arguments).
cscope.out cscope: $(c) $(h)
	cscope $(cscopeflags)

# Need to unset during recursion to go out of loop.
# The README below ensures that the dependency list is never empty and
# that when MAKEDEPEND is empty $(FIRSTMAKEFILE) doesn't need rebuilding.

MAKEDEPEND = Makefile makedepend_file makedepend

$(FIRSTMAKEFILE):	README $(MAKEDEPEND)
	$(MAKE) depend MAKEDEPEND=

Makefile: Makefile.SH config.sh
	$(SHELL) Makefile.SH

cflags: cflags.SH config.sh
	$(SHELL) cflags.SH

config.h: config_h.SH config.sh
	$(SHELL) config_h.SH

makedepend: makedepend.SH config.sh
	$(SHELL) makedepend.SH

myconfig: myconfig.SH config.sh
	$(SHELL) myconfig.SH

runtests: runtests.SH config.sh
	$(SHELL) runtests.SH

pod/Makefile: pod/Makefile.SH config.sh
	$(SHELL) pod/Makefile.SH

.PHONY: depend
depend: makedepend $(DTRACE_H) $(generated_headers)
	sh ./makedepend MAKE="$(MAKE)" cflags

.c.c.depends:
	sh ./makedepend_file $< $@ cflags

.PHONY: test check test_prep test_prep_nodll test_prep_pre \
	test_prep_reonly test_tty test-tty test_notty test-notty \
	test_harness test_harness_notty minitest test-reonly _test

# The _test target is there just for Test::Smoke, which does a make test_prep
# always before invoking this target, thus preventing checking again
_test:
	$(RUN_TESTS) choose

# Cannot delegate rebuilding of t/perl to make
# to allow interlaced test and minitest

# Architecture-neutral stuff:

test_prep_pre: preplibrary utilities $(nonxs_ext)
test_prep test-prep: test_prep_pre $(MINIPERL_EXE) $(unidatafiles) $(PERL_EXE) \
	$(dynamic_ext) $(TEST_PERL_DLL) runtests $(generated_pods) common_build
	cd t && (rm -f $(PERL_EXE); $(LNS) ../$(PERL_EXE) $(PERL_EXE))

test_prep_reonly: $(MINIPERL_EXE) $(PERL_EXE) $(dynamic_ext_re) $(TEST_PERL_DLL)
	$(MINIPERL) make_ext.pl $(dynamic_ext_re) MAKE="$(MAKE)" LIBPERL_A=$(LIBPERL) LINKTYPE=dynamic
	cd t && (rm -f $(PERL_EXE); $(LNS) ../$(PERL_EXE) $(PERL_EXE))

test check: test_prep
	$(RUN_TESTS) choose

test_tty test-tty: test_prep
	$(RUN_TESTS) tty

test_notty test-notty: test_prep
	$(RUN_TESTS) no-tty

# Targets for valgrind testing:

test.valgrind check.valgrind:	test_prep
	@echo "Checking usemymalloc='n' in config.sh..."
	@grep "^usemymalloc="    config.sh
	@grep "^usemymalloc='n'" config.sh >/dev/null || exit 1
	@echo "And of course you have to have valgrind..."
	$(VALGRIND) $(VG_TEST) || exit 1
	PERL_VALGRIND=1 VALGRIND='$(VALGRIND)' TESTFILE=harness $(RUN_TESTS) choose

# minitest can't depend on lib/Config.pm because that might be where miniperl
# is crashing.
minitest_prep: $(MINIPERL_EXE)
	-@test -f lib/Config.pm || $(MAKE) lib/Config.pm $(unidatafiles)
	@echo " "
	@echo "You may see some irrelevant test failures if you have been unable"
	@echo "to build lib/Config.pm, or the Unicode data files."
	@echo " "
	cd t && (rm -f $(PERL_EXE); $(LNS) ../$(MINIPERL_EXE) $(PERL_EXE))

MINITEST_TESTS = base/*.t comp/*.t cmd/*.t run/*.t io/*.t re/*.t opbasic/*.t op/*.t uni/*.t perf/*.t

minitest: minitest_prep
	cd t && $(RUN_PERL) TEST $(MINITEST_TESTS) <$(devtty)

minitest-notty minitest_notty: minitest_prep
	cd t && PERL_SKIP_TTY_TEST=1 $(RUN_PERL) TEST $(MINITEST_TESTS)

# Test via harness

test_harness test-harness: test_prep
	TESTFILE=harness $(RUN_TESTS) choose

test_harness_notty: test_prep
	HARNESS_NOTTY=1 TESTFILE=harness $(RUN_TESTS) choose

test_reonly test-reonly: test_prep_reonly
	TEST_ARGS='re/*.t ../ext/re/t/*.t' PERL_TEST_HARNESS_ASAP=1 TESTFILE=harness $(RUN_TESTS) choose


# Porting tests (well-formedness of pod, manifest, etc)

test_porting test-porting: test_prep
	TEST_ARGS='porting/*.t lib/diagnostics.t' TESTFILE=harness $(RUN_TESTS) choose


# intended as a common way to add dependencies to test-prep and all
common_build: 


# Handy way to run perlbug -ok without having to install and run the
# installed perlbug. We don't re-run the tests here - we trust the user.
# Please *don't* use this unless all tests pass.
# If you want to report test failures, use "make nok" instead.

.PHONY: ok okfile oknack okfilenack nok nokfile noknack nokfilenack

ok:	utilities
	$(RUN_PERL) utils/perlbug -ok -s '(UNINSTALLED)'

okfile:	utilities
	$(RUN_PERL) utils/perlbug -ok -s '(UNINSTALLED)' -F perl.ok

oknack:	utilities
	$(RUN_PERL) utils/perlbug -ok -s '(UNINSTALLED)' -A

okfilenack:	utilities
	$(RUN_PERL) utils/perlbug -ok -s '(UNINSTALLED)' -F perl.ok -A

nok:	utilities
	$(RUN_PERL) utils/perlbug -nok -s '(UNINSTALLED)'

nokfile:	utilities
	$(RUN_PERL) utils/perlbug -nok -s '(UNINSTALLED)' -F perl.nok

noknack:	utilities
	$(RUN_PERL) utils/perlbug -nok -s '(UNINSTALLED)' -A

nokfilenack:	utilities
	$(RUN_PERL) utils/perlbug -nok -s '(UNINSTALLED)' -F perl.nok -A

.PHONY: clist hlist

clist:	$(c)
	echo $(c) | tr ' ' $(TRNL) >.clist

hlist:  $(h)
	echo $(h) | tr ' ' $(TRNL) >.hlist

.PHONY: distcheck
distcheck: FORCE
	perl '-MExtUtils::Manifest=&fullcheck' -e 'fullcheck()'

.PHONY: ctags

TAGS: $(c_base) $(h)
	etags $(c_base) $(h)

ctags:
	ctags -N --languages=c --langmap=c:+.h.inc  --exclude=opmini.c --exclude=perlmini.c --exclude=universalmini.c *.c *.h *.inc

# AUTOMATICALLY GENERATED MAKE DEPENDENCIES--PUT NOTHING BELOW THIS LINE
# If this runs make out of memory, delete /usr/include lines.
