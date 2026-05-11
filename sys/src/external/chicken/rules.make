# rules.make - basic build rules -*- Makefile -*-
#
# Copyright (c) 2008-2022, The CHICKEN Team
# Copyright (c) 2000-2007, Felix L. Winkelmann
# All rights reserved.
#
# Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following
# conditions are met:
#
#   Redistributions of source code must retain the above copyright notice, this list of conditions and the following
#     disclaimer. 
#   Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following
#     disclaimer in the documentation and/or other materials provided with the distribution. 
#   Neither the name of the author nor the names of its contributors may be used to endorse or promote
#     products derived from this software without specific prior written permission. 
#
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS
# OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY
# AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDERS OR
# CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
# CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
# SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
# THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
# OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
# POSSIBILITY OF SUCH DAMAGE.

VPATH=$(SRCDIR)

# Clear Make's default rules for C programs
.SUFFIXES:
%.o : %.c
%: %.o

# object files

LIBCHICKEN_SCHEME_OBJECTS_1 = \
       library eval read-syntax repl data-structures pathname port file \
       extras lolevel tcp srfi-4 continuation $(POSIXFILE) internal \
       irregex scheduler debugger-client profiler stub expand modules \
       chicken-syntax chicken-ffi-syntax build-version
LIBCHICKEN_OBJECTS_1 = $(LIBCHICKEN_SCHEME_OBJECTS_1) runtime
LIBCHICKEN_SHARED_OBJECTS = $(LIBCHICKEN_OBJECTS_1:=$(O))
LIBCHICKEN_STATIC_OBJECTS = $(LIBCHICKEN_OBJECTS_1:=-static$(O)) \
	eval-modules-static$(O)

COMPILER_OBJECTS_1 = \
	chicken batch-driver core optimizer lfa2 compiler-syntax scrutinizer support \
	c-platform c-backend user-pass
COMPILER_OBJECTS        = $(COMPILER_OBJECTS_1:=$(O))
COMPILER_STATIC_OBJECTS = $(COMPILER_OBJECTS_1:=-static$(O))

# "Utility programs" is arbitrary. It includes anything but the "chicken" binary.
# We can't use the INSTALLED_PROGRAMS below because of the possible $(EXE)
# suffix and other possible mangling requested by the user. (is this supported?)
UTILITY_PROGRAM_OBJECTS_1 = \
	csc csi chicken-install chicken-uninstall chicken-status chicken-profile

# Not all programs built are installed(?) This is the master list that takes
# care of which programs should actually be installed/uninstalled
INSTALLED_PROGRAMS = \
	$(CHICKEN_PROGRAM) $(CSI_PROGRAM) $(CHICKEN_PROFILE_PROGRAM) \
	$(CSC_PROGRAM) \
	$(CHICKEN_DO_PROGRAM) $(CHICKEN_STATUS_PROGRAM) \
	$(CHICKEN_INSTALL_PROGRAM) $(CHICKEN_UNINSTALL_PROGRAM)

# These generated files make up a bootstrapped distribution build.
# They are not cleaned by the 'clean' target, but only by 'spotless'.
DISTFILES = $(filter-out runtime.c,$(LIBCHICKEN_OBJECTS_1:=.c)) \
	$(UTILITY_PROGRAM_OBJECTS_1:=.c) \
	$(COMPILER_OBJECTS_1:=.c) \
	$(IMPORT_LIBRARIES:=.import.c) \
	$(DYNAMIC_IMPORT_LIBRARIES:=.import.scm) \
	$(foreach lib,$(DYNAMIC_CHICKEN_IMPORT_LIBRARIES),chicken.$(lib).import.scm) \
	$(foreach lib,$(DYNAMIC_CHICKEN_UNIT_IMPORT_LIBRARIES),chicken.$(lib).import.scm) \
	$(foreach lib,$(COMPILER_OBJECTS_1),chicken.compiler.$(lib).import.scm) \
	eval-modules.c posixunix.c posixwin.c
# Remove the duplicate $(POSIXFILE) entry:
DISTFILES := $(sort $(DISTFILES))

# library objects

## Any variable that starts with "declare-" is a meta-rule. When $(call)ed
## it produces output that represents an instantiated rule and recipe.
## This output then needs to be $(eval)ed in order to be added to the
## ruleset evaluated by Make.  This allows us to automatically generate
## similar rules for long lists of targets.

## Note: in some of the rules that follow it is important to add
## $(INCLUDES) last, because on raw mingw (using the DOS shell) the
## backslash in "-I.\" seems to be interpreted as a line-terminator.
## This may be caused by cmd.exe-stupidness or a bug in mingw32-make
## or some other obscure reason.

define declare-shared-library-object
$(1)$(O): $(1).c chicken.h $$(CHICKEN_CONFIG_H)
	$$(C_COMPILER) $$(C_COMPILER_OPTIONS) \
	  $$(C_COMPILER_COMPILE_OPTION) $$(C_COMPILER_OPTIMIZATION_OPTIONS) $$(C_COMPILER_SHARED_OPTIONS) \
	  $$(C_COMPILER_BUILD_RUNTIME_OPTIONS) $$< $$(C_COMPILER_OUTPUT) \
	  $$(INCLUDES)
endef

# The above meta-rule is reused in the setup API stuff below, so we alias it
declare-libchicken-object = $(declare-shared-library-object)

$(foreach obj, $(LIBCHICKEN_OBJECTS_1),\
          $(eval $(call declare-libchicken-object,$(obj))))

# static versions

define declare-static-library-object
$(1)-static$(O): $(1).c chicken.h $$(CHICKEN_CONFIG_H)
	$$(C_COMPILER) $$(C_COMPILER_OPTIONS) \
	  $$(C_COMPILER_COMPILE_OPTION) $$(C_COMPILER_OPTIMIZATION_OPTIONS) \
	  $$(C_COMPILER_STATIC_OPTIONS) \
	  $$(C_COMPILER_BUILD_RUNTIME_OPTIONS) $$< $$(C_COMPILER_OUTPUT) \
	  $$(INCLUDES)
endef

declare-static-libchicken-object = $(declare-static-library-object)

$(foreach obj, $(LIBCHICKEN_OBJECTS_1),\
          $(eval $(call declare-static-libchicken-object,$(obj))))

$(eval $(call declare-static-libchicken-object,eval-modules))

# import library objects

define declare-import-lib-object
$(1).import$(O): $(1).import.c chicken.h $$(CHICKEN_CONFIG_H)
	$$(C_COMPILER) $$(C_COMPILER_OPTIONS)  \
	  -DC_SHARED $$(C_COMPILER_COMPILE_OPTION) \
	  $$(C_COMPILER_OPTIMIZATION_OPTIONS) $$(C_COMPILER_SHARED_OPTIONS) \
	  $$(C_COMPILER_BUILD_RUNTIME_OPTIONS) $$< $$(C_COMPILER_OUTPUT) \
	  $$(INCLUDES)
endef

$(foreach obj,$(IMPORT_LIBRARIES),\
          $(eval $(call declare-import-lib-object,$(obj))))

# compiler objects

define declare-compiler-object
$(1)$(O): $(1).c chicken.h $$(CHICKEN_CONFIG_H)
	$$(C_COMPILER) $$(C_COMPILER_OPTIONS) \
	  $$(C_COMPILER_COMPILE_OPTION) $$(C_COMPILER_OPTIMIZATION_OPTIONS) $$(C_COMPILER_SHARED_OPTIONS) $$< \
	  $$(C_COMPILER_OUTPUT) $$(INCLUDES)
endef

$(foreach obj, $(COMPILER_OBJECTS_1),\
          $(eval $(call declare-compiler-object,$(obj))))

# static compiler objects

define declare-static-compiler-object
$(1)-static$(O): $(1).c chicken.h $$(CHICKEN_CONFIG_H)
	$$(C_COMPILER) $$(C_COMPILER_OPTIONS) \
	  $$(C_COMPILER_STATIC_OPTIONS) \
	  $$(C_COMPILER_COMPILE_OPTION) $$(C_COMPILER_OPTIMIZATION_OPTIONS) $$< $$(C_COMPILER_OUTPUT) \
	  $$(INCLUDES)
endef

$(foreach obj, $(COMPILER_OBJECTS_1),\
          $(eval $(call declare-static-compiler-object,$(obj))))

# program objects

define declare-utility-program-object
$(1)$(O): $(1).c chicken.h $$(CHICKEN_CONFIG_H)
	$$(C_COMPILER) $$(C_COMPILER_OPTIONS) $$(C_COMPILER_SHARED_OPTIONS) \
	  $$(C_COMPILER_COMPILE_OPTION) $$(C_COMPILER_OPTIMIZATION_OPTIONS) $$< $$(C_COMPILER_OUTPUT) \
	 $$(INCLUDES) 
endef

$(foreach obj, $(UTILITY_PROGRAM_OBJECTS_1),\
          $(eval $(call declare-utility-program-object,$(obj))))


# resource objects

%.rc.o: %.rc
	$(RC_COMPILER) $< $@

# libraries

.PHONY: libs

libs: $(TARGETLIBS)

lib$(PROGRAM_PREFIX)chicken$(PROGRAM_SUFFIX)$(SO): $(LIBCHICKEN_SHARED_OBJECTS)
	$(LINKER) $(LINKER_OPTIONS) $(LINKER_LINK_SHARED_LIBRARY_OPTIONS) $(LIBCHICKEN_SO_LINKER_OPTIONS) \
	  $(LINKER_OUTPUT) $^ $(LIBCHICKEN_SO_LIBRARIES)
ifdef USES_SONAME
	ln -sf $(LIBCHICKEN_SO_FILE) $(LIBCHICKEN_SO_FILE).$(BINARYVERSION)
endif

cyg$(PROGRAM_PREFIX)chicken$(PROGRAM_SUFFIX)-0.dll: $(LIBCHICKEN_SHARED_OBJECTS)
	$(LINKER) -shared -o $(LIBCHICKEN_SO_FILE) -Wl,--dll -Wl,--add-stdcall-alias \
	    -Wl,--enable-stdcall-fixup -Wl,--warn-unresolved-symbols \
	    -Wl,--dll-search-prefix=cyg -Wl,--allow-multiple-definition \
	    -Wl,--allow-shlib-undefined \
	    -Wl,--out-implib=libchicken.dll.a -Wl,--export-all-symbols \
	    -Wl,--enable-auto-import \
	    -Wl,--whole-archive $(LIBCHICKEN_SHARED_OBJECTS) \
	    -Wl,--no-whole-archive $(LIBCHICKEN_SO_LIBRARIES)

lib$(PROGRAM_PREFIX)chicken$(PROGRAM_SUFFIX)$(A): $(LIBCHICKEN_STATIC_OBJECTS)
	$(LIBRARIAN) $(LIBRARIAN_OPTIONS) $(LIBRARIAN_OUTPUT) $^

# import libraries and extensions

%.so: %.o $(LIBCHICKEN_SO_FILE)
	$(LINKER) $(LINKER_OPTIONS) $(LINKER_LINK_SHARED_DLOADABLE_OPTIONS) $< $(LINKER_OUTPUT_OPTION) $@ \
	  $(LINKER_LIBRARY_PREFIX)$(PROGRAM_PREFIX)chicken$(PROGRAM_SUFFIX)$(LINKER_LIBRARY_SUFFIX) \
	  $(LIBRARIES)

# executables

$(CHICKEN_SHARED_EXECUTABLE): $(COMPILER_OBJECTS) $(PRIMARY_LIBCHICKEN)
	$(LINKER) $(LINKER_OPTIONS) $(LINKER_EXECUTABLE_OPTIONS) $(COMPILER_OBJECTS) $(LINKER_OUTPUT) \
          $(LINKER_LIBRARY_PREFIX)$(PROGRAM_PREFIX)chicken$(PROGRAM_SUFFIX)$(LINKER_LIBRARY_SUFFIX) $(LINKER_LINK_SHARED_PROGRAM_OPTIONS) $(LIBRARIES)
	$(PREINSTALL_PROGRAM_FIXUP) $(CHICKEN_SHARED_EXECUTABLE)

define declare-program-from-object
$(1)-RC_FILE = $(if $(and $(RC_COMPILER),$(3)),$(2).rc$(O))

$(1): $(2)$(O) $$(PRIMARY_LIBCHICKEN) $$($(1)-RC_FILE)
	$$(LINKER) $$(LINKER_OPTIONS) $$(LINKER_EXECUTABLE_OPTIONS) $$< \
          $$($(1)-RC_FILE) $$(LINKER_OUTPUT) \
          $$(LINKER_LIBRARY_PREFIX)$$(PROGRAM_PREFIX)chicken$$(PROGRAM_SUFFIX)$$(LINKER_LIBRARY_SUFFIX) \
          $$(LINKER_LINK_SHARED_PROGRAM_OPTIONS) $$(LIBRARIES)
endef

# Unfortunately, we can't loop over INSTALLED_PROGRAMS here because of
# the possible name mangling and EXE suffixing in there :(
$(eval $(call declare-program-from-object,$(CSI_SHARED_EXECUTABLE),csi))
$(eval $(call declare-program-from-object,$(CHICKEN_INSTALL_PROGRAM)$(EXE),chicken-install,true))
$(eval $(call declare-program-from-object,$(CHICKEN_UNINSTALL_PROGRAM)$(EXE),chicken-uninstall,true))
$(eval $(call declare-program-from-object,$(CHICKEN_STATUS_PROGRAM)$(EXE),chicken-status))
$(eval $(call declare-program-from-object,$(CHICKEN_PROFILE_PROGRAM)$(EXE),chicken-profile))
$(eval $(call declare-program-from-object,$(CSC_PROGRAM)$(EXE),csc))

# static executables

$(CHICKEN_STATIC_EXECUTABLE): $(COMPILER_STATIC_OBJECTS) lib$(PROGRAM_PREFIX)chicken$(PROGRAM_SUFFIX)$(A)
	$(LINKER) $(LINKER_OPTIONS) $(LINKER_STATIC_OPTIONS) $(COMPILER_STATIC_OBJECTS) $(LINKER_OUTPUT) lib$(PROGRAM_PREFIX)chicken$(PROGRAM_SUFFIX)$(A) $(LIBRARIES)

define declare-static-program-from-object
$(1): $(2)$(O) lib$(PROGRAM_PREFIX)chicken$(PROGRAM_SUFFIX)$(A)
	$$(LINKER) $$(LINKER_OPTIONS) $$(LINKER_STATIC_OPTIONS) $$< $$(LINKER_OUTPUT) lib$(PROGRAM_PREFIX)chicken$(PROGRAM_SUFFIX)$(A) $$(LIBRARIES)
endef

$(eval $(call declare-program-from-object,$(CSI_STATIC_EXECUTABLE),csi))

# "chicken-do"

$(CHICKEN_DO_PROGRAM)$(EXE): $(SRCDIR)chicken-do.c chicken.h $(CHICKEN_CONFIG_H)
	$(C_COMPILER) $(C_COMPILER_OPTIONS) $(C_COMPILER_OPTIMIZATION_OPTIONS) $< -o $@

# scripts

$(CHICKEN_DEBUGGER_PROGRAM): $(SRCDIR)feathers$(SCRIPT_EXT).in
	$(GENERATE_DEBUGGER)


# installation

.PHONY: install uninstall install-libs
.PHONY: install-target install-dev install-bin install-other-files install-wrappers

install: $(TARGETS) install-target install-bin install-libs install-dev install-other-files

install-target: install-libs

install-libs:
	$(MAKEDIR_COMMAND) $(MAKEDIR_COMMAND_OPTIONS) "$(DESTDIR)$(ILIBDIR)"
ifneq ($(LIBCHICKEN_IMPORT_LIBRARY),) 
	$(INSTALL_PROGRAM) $(INSTALL_PROGRAM_STATIC_LIBRARY_OPTIONS) $(LIBCHICKEN_IMPORT_LIBRARY) "$(DESTDIR)$(ILIBDIR)"
endif
ifndef STATICBUILD
ifdef DLLSINPATH
	$(MAKEDIR_COMMAND) $(MAKEDIR_COMMAND_OPTIONS) "$(DESTDIR)$(IBINDIR)"
	$(INSTALL_PROGRAM) $(INSTALL_PROGRAM_SHARED_LIBRARY_OPTIONS) $(LIBCHICKEN_SO_FILE) "$(DESTDIR)$(IBINDIR)"
else
ifdef USES_SONAME
	$(INSTALL_PROGRAM) $(INSTALL_PROGRAM_SHARED_LIBRARY_OPTIONS) $(LIBCHICKEN_SO_FILE) "$(DESTDIR)$(ILIBDIR)$(SEP)$(LIBCHICKEN_SO_FILE).$(BINARYVERSION)"
	cd "$(DESTDIR)$(ILIBDIR)" && ln -sf $(LIBCHICKEN_SO_FILE).$(BINARYVERSION) lib$(PROGRAM_PREFIX)chicken$(PROGRAM_SUFFIX)$(SO)
else
	$(INSTALL_PROGRAM) $(INSTALL_PROGRAM_SHARED_LIBRARY_OPTIONS) $(LIBCHICKEN_SO_FILE) "$(DESTDIR)$(ILIBDIR)$(SEP)$(LIBCHICKEN_SO_FILE)"
endif
endif
endif

define NL


endef # A newline, used to inject recipe lines in a loop. Ugly, but necessary

install-dev: install-libs
	$(MAKEDIR_COMMAND) $(MAKEDIR_COMMAND_OPTIONS) "$(DESTDIR)$(ILIBDIR)"
	$(MAKEDIR_COMMAND) $(MAKEDIR_COMMAND_OPTIONS) "$(DESTDIR)$(ISHAREDIR)"
	$(MAKEDIR_COMMAND) $(MAKEDIR_COMMAND_OPTIONS) "$(DESTDIR)$(IEGGDIR)"
	$(MAKEDIR_COMMAND) $(MAKEDIR_COMMAND_OPTIONS) "$(DESTDIR)$(ICHICKENINCDIR)"
	$(MAKEDIR_COMMAND) $(MAKEDIR_COMMAND_OPTIONS) "$(DESTDIR)$(IDATADIR)"
	$(INSTALL_PROGRAM) $(INSTALL_PROGRAM_STATIC_LIBRARY_OPTIONS) lib$(PROGRAM_PREFIX)chicken$(PROGRAM_SUFFIX)$(A) "$(DESTDIR)$(ILIBDIR)"
ifneq ($(POSTINSTALL_STATIC_LIBRARY),true)
	$(POSTINSTALL_STATIC_LIBRARY) $(POSTINSTALL_STATIC_LIBRARY_FLAGS) "$(ILIBDIR)$(SEP)libchicken$(A)"
endif
	$(INSTALL_PROGRAM) $(INSTALL_PROGRAM_FILE_OPTIONS) $(SRCDIR)chicken.h "$(DESTDIR)$(ICHICKENINCDIR)"
	$(INSTALL_PROGRAM) $(INSTALL_PROGRAM_FILE_OPTIONS) $(CHICKEN_CONFIG_H) "$(DESTDIR)$(ICHICKENINCDIR)"
ifdef WINDOWS
	$(INSTALL_PROGRAM) $(INSTALL_PROGRAM_FILE_OPTIONS) $(SRCDIR)chicken.ico "$(DESTDIR)$(IDATADIR)"
	$(INSTALL_PROGRAM) $(INSTALL_PROGRAM_FILE_OPTIONS) $(SRCDIR)chicken.rc$(O) "$(DESTDIR)$(IDATADIR)"
endif
	$(INSTALL_PROGRAM) $(INSTALL_PROGRAM_FILE_OPTIONS) $(SRCDIR)types.db "$(DESTDIR)$(IEGGDIR)"

ifeq ($(NEEDS_RELINKING),yes)
install-bin:
	$(foreach prog,$(INSTALLED_PROGRAMS),\
		$(REMOVE_COMMAND) $(REMOVE_COMMAND_OPTIONS) $(prog)$(EXE) $(NL))

	$(REMOVE_COMMAND) $(REMOVE_COMMAND_OPTIONS) $(IMPORT_LIBRARIES:%=%.so)
	$(REMOVE_COMMAND) $(REMOVE_COMMAND_OPTIONS) $(IMPORT_LIBRARIES:%=%.import.so)
	$(REMOVE_COMMAND) $(REMOVE_COMMAND_OPTIONS) $(LIBCHICKEN_SO_FILE)
	"$(MAKE)" PLATFORM=$(PLATFORM) CONFIG=$(CONFIG) NEEDS_RELINKING=no RUNTIME_LINKER_PATH="$(LIBDIR)" install-bin
# Damn. What was this for, again?
#
# 	$(MAKE_WRITABLE_COMMAND) $(CHICKEN_PROGRAM)$(EXE) $(CSI_PROGRAM)$(EXE) $(CSC_PROGRAM)$(EXE) $(CHICKEN_PROFILE_PROGRAM)$(EXE)
# 	$(MAKE_WRITABLE_COMMAND) $(CHICKEN_INSTALL_PROGRAM)$(EXE)
# 	$(MAKE_WRITABLE_COMMAND) $(CHICKEN_UNINSTALL_PROGRAM)$(EXE)
# 	$(MAKE_WRITABLE_COMMAND) $(CHICKEN_STATUS_PROGRAM)$(EXE)
else
install-bin: $(TARGETS) install-libs install-dev
	$(MAKEDIR_COMMAND) $(MAKEDIR_COMMAND_OPTIONS) "$(DESTDIR)$(IBINDIR)"

	$(foreach prog,$(INSTALLED_PROGRAMS),\
		$(INSTALL_PROGRAM) $(INSTALL_PROGRAM_EXECUTABLE_OPTIONS) \
		$(prog)$(EXE) "$(DESTDIR)$(IBINDIR)" $(NL))

	$(INSTALL_PROGRAM) $(INSTALL_PROGRAM_EXECUTABLE_OPTIONS) $(CHICKEN_DEBUGGER_PROGRAM) "$(DESTDIR)$(IBINDIR)"

ifdef STATICBUILD
	$(foreach lib,$(IMPORT_LIBRARIES),\
		$(INSTALL_PROGRAM) $(INSTALL_PROGRAM_FILE_OPTIONS) \
		$(lib).import.scm "$(DESTDIR)$(IEGGDIR)" $(NL))
else
	$(foreach lib,$(IMPORT_LIBRARIES),\
		$(INSTALL_PROGRAM) $(INSTALL_PROGRAM_EXECUTABLE_OPTIONS) \
		$(lib).import.so "$(DESTDIR)$(IEGGDIR)" $(NL))
endif

ifneq ($(POSTINSTALL_PROGRAM),true)
ifndef STATICBUILD
	$(foreach prog,$(INSTALLED_PROGRAMS),\
		$(POSTINSTALL_PROGRAM) $(POSTINSTALL_PROGRAM_FLAGS) \
		"$(DESTDIR)$(IBINDIR)$(SEP)$(prog)" $(NL))

	$(foreach import-lib,$(IMPORT_LIBRARIES),\
		$(POSTINSTALL_PROGRAM) $(POSTINSTALL_PROGRAM_FLAGS) \
		"$(DESTDIR)$(IEGGDIR)$(SEP)$(import-lib).import.so" $(NL))
endif
endif
ifeq ($(CROSS_CHICKEN)$(DESTDIR),0)
	-$(IBINDIR)$(SEP)$(CHICKEN_INSTALL_PROGRAM) -defaults $(SRCDIR)setup.defaults -update-db
else
	@echo
	@echo "Warning: cannot run \`$(CHICKEN_INSTALL_PROGRAM) -update-db' when cross-compiling or DESTDIR is set"
	@echo
endif
endif
ifdef WINDOWS_SHELL
	$(INSTALL_PROGRAM) $(INSTALL_PROGRAM_EXECUTABLE_OPTIONS) $(SRCDIR)csibatch.bat "$(DESTDIR)$(IBINDIR)"
endif

install-other-files:
	$(MAKEDIR_COMMAND) $(MAKEDIR_COMMAND_OPTIONS) "$(DESTDIR)$(IMAN1DIR)"
	$(MAKEDIR_COMMAND) $(MAKEDIR_COMMAND_OPTIONS) "$(DESTDIR)$(IDOCDIR)"
	$(MAKEDIR_COMMAND) $(MAKEDIR_COMMAND_OPTIONS) "$(DESTDIR)$(IDATADIR)"

	$(INSTALL_PROGRAM) $(INSTALL_PROGRAM_FILE_OPTIONS) $(SRCDIR)chicken$(MAN) "$(DESTDIR)$(IMAN1DIR)$(SEP)$(CHICKEN_PROGRAM).1"
	$(INSTALL_PROGRAM) $(INSTALL_PROGRAM_FILE_OPTIONS) $(SRCDIR)csc$(MAN) "$(DESTDIR)$(IMAN1DIR)$(SEP)$(CSC_PROGRAM).1"
	$(INSTALL_PROGRAM) $(INSTALL_PROGRAM_FILE_OPTIONS) $(SRCDIR)csi$(MAN) "$(DESTDIR)$(IMAN1DIR)$(SEP)$(CSI_PROGRAM).1"
	$(INSTALL_PROGRAM) $(INSTALL_PROGRAM_FILE_OPTIONS) $(SRCDIR)chicken-do$(MAN) "$(DESTDIR)$(IMAN1DIR)$(SEP)$(CHICKEN_DO_PROGRAM).1"
	$(INSTALL_PROGRAM) $(INSTALL_PROGRAM_FILE_OPTIONS) $(SRCDIR)chicken-install$(MAN) "$(DESTDIR)$(IMAN1DIR)$(SEP)$(CHICKEN_INSTALL_PROGRAM).1"
	$(INSTALL_PROGRAM) $(INSTALL_PROGRAM_FILE_OPTIONS) $(SRCDIR)chicken-uninstall$(MAN) "$(DESTDIR)$(IMAN1DIR)$(SEP)$(CHICKEN_UNINSTALL_PROGRAM).1"
	$(INSTALL_PROGRAM) $(INSTALL_PROGRAM_FILE_OPTIONS) $(SRCDIR)chicken-status$(MAN) "$(DESTDIR)$(IMAN1DIR)$(SEP)$(CHICKEN_STATUS_PROGRAM).1"
	$(INSTALL_PROGRAM) $(INSTALL_PROGRAM_FILE_OPTIONS) $(SRCDIR)chicken-profile$(MAN) "$(DESTDIR)$(IMAN1DIR)$(SEP)$(CHICKEN_PROFILE_PROGRAM).1"
	$(INSTALL_PROGRAM) $(INSTALL_PROGRAM_FILE_OPTIONS) $(SRCDIR)feathers$(MAN) "$(DESTDIR)$(IMAN1DIR)$(SEP)$(CHICKEN_DEBUGGER_PROGRAM).1"

	$(MAKEDIR_COMMAND) $(MAKEDIR_COMMAND_OPTIONS) "$(DESTDIR)$(IDOCDIR)$(SEP)manual"
	-$(INSTALL_PROGRAM) $(INSTALL_PROGRAM_FILE_OPTIONS) $(SRCDIR)manual-html$(SEP)* "$(DESTDIR)$(IDOCDIR)$(SEP)manual"
	$(INSTALL_PROGRAM) $(INSTALL_PROGRAM_FILE_OPTIONS) $(SRCDIR)README "$(DESTDIR)$(IDOCDIR)"
	$(INSTALL_PROGRAM) $(INSTALL_PROGRAM_FILE_OPTIONS) $(SRCDIR)DEPRECATED "$(DESTDIR)$(IDOCDIR)"
	$(INSTALL_PROGRAM) $(INSTALL_PROGRAM_FILE_OPTIONS) $(SRCDIR)LICENSE "$(DESTDIR)$(IDOCDIR)"
	$(INSTALL_PROGRAM) $(INSTALL_PROGRAM_FILE_OPTIONS) $(SRCDIR)setup.defaults "$(DESTDIR)$(IDATADIR)"
	$(INSTALL_PROGRAM) $(INSTALL_PROGRAM_FILE_OPTIONS) $(SRCDIR)feathers.tcl "$(DESTDIR)$(IDATADIR)"

install-wrappers:
ifeq ($(WRAPPERDIR),)
	@echo 
	@echo Error: WRAPPERDIR is not set
	@echo
	@exit 1
endif
	$(foreach prg, $(INSTALLED_PROGRAMS), \
		$(CSI) -s $(SRCDIR)scripts$(SEP)make-wrapper.scm $(prg) "$(WRAPPERDIR)" $(NL))

uninstall:
	$(foreach prog,$(INSTALLED_PROGRAMS),\
		$(REMOVE_COMMAND) $(REMOVE_COMMAND_OPTIONS)\
		"$(DESTDIR)$(IBINDIR)$(SEP)$(prog)$(EXE)" $(NL))
	$(REMOVE_COMMAND) $(REMOVE_COMMAND_OPTIONS) "$(DESTDIR)$(IBINDIR)$(SEP)$(CHICKEN_DEBUGGER_PROGRAM)"
	$(REMOVE_COMMAND) $(REMOVE_COMMAND_OPTIONS) "$(DESTDIR)$(ILIBDIR)$(SEP)lib$(PROGRAM_PREFIX)chicken$(PROGRAM_SUFFIX)$(A)"
	$(REMOVE_COMMAND) $(REMOVE_COMMAND_OPTIONS) "$(DESTDIR)$(ILIBDIR)$(SEP)lib$(PROGRAM_PREFIX)chicken$(PROGRAM_SUFFIX)$(SO)"
ifdef USES_SONAME
	-$(REMOVE_COMMAND) $(REMOVE_COMMAND_OPTIONS) "$(DESTDIR)$(ILIBDIR)$(SEP)lib$(PROGRAM_PREFIX)chicken$(PROGRAM_SUFFIX)$(SO).$(BINARYVERSION)"
endif
ifdef WINDOWS
	$(REMOVE_COMMAND) $(REMOVE_COMMAND_OPTIONS) "$(DESTDIR)$(IBINDIR)$(SEP)lib$(PROGRAM_PREFIX)chicken$(PROGRAM_SUFFIX)$(SO)"
	$(REMOVE_COMMAND) $(REMOVE_COMMAND_OPTIONS) "$(DESTDIR)$(ILIBDIR)$(SEP)$(LIBCHICKEN_IMPORT_LIBRARY)"
endif
ifeq ($(PLATFORM),cygwin)
	$(REMOVE_COMMAND) $(REMOVE_COMMAND_OPTIONS) "$(DESTDIR)$(IBINDIR)$(SEP)cyg$(PROGRAM_PREFIX)chicken$(PROGRAM_SUFFIX)*"
endif

	$(REMOVE_COMMAND) $(REMOVE_COMMAND_OPTIONS) "$(DESTDIR)$(IMAN1DIR)$(SEP)$(CHICKEN_PROGRAM).1"
	$(REMOVE_COMMAND) $(REMOVE_COMMAND_OPTIONS) "$(DESTDIR)$(IMAN1DIR)$(SEP)$(CSC_PROGRAM).1"
	$(REMOVE_COMMAND) $(REMOVE_COMMAND_OPTIONS) "$(DESTDIR)$(IMAN1DIR)$(SEP)$(CSI_PROGRAM).1"
	$(REMOVE_COMMAND) $(REMOVE_COMMAND_OPTIONS) "$(DESTDIR)$(IMAN1DIR)$(SEP)$(CHICKEN_DO_PROGRAM).1"
	$(REMOVE_COMMAND) $(REMOVE_COMMAND_OPTIONS) "$(DESTDIR)$(IMAN1DIR)$(SEP)$(CHICKEN_INSTALL_PROGRAM).1"
	$(REMOVE_COMMAND) $(REMOVE_COMMAND_OPTIONS) "$(DESTDIR)$(IMAN1DIR)$(SEP)$(CHICKEN_UNINSTALL_PROGRAM).1"
	$(REMOVE_COMMAND) $(REMOVE_COMMAND_OPTIONS) "$(DESTDIR)$(IMAN1DIR)$(SEP)$(CHICKEN_STATUS_PROGRAM).1"
	$(REMOVE_COMMAND) $(REMOVE_COMMAND_OPTIONS) "$(DESTDIR)$(IMAN1DIR)$(SEP)$(CHICKEN_PROFILE_PROGRAM).1"
	$(REMOVE_COMMAND) $(REMOVE_COMMAND_OPTIONS) "$(DESTDIR)$(IMAN1DIR)$(SEP)$(CHICKEN_DEBUGGER_PROGRAM).1"

	$(REMOVE_COMMAND) $(REMOVE_COMMAND_OPTIONS) "$(DESTDIR)$(ICHICKENINCDIR)$(SEP)chicken.h"
	$(REMOVE_COMMAND) $(REMOVE_COMMAND_OPTIONS) "$(DESTDIR)$(ICHICKENINCDIR)$(SEP)$(CHICKEN_CONFIG_H)"
	$(REMOVE_COMMAND) $(REMOVE_COMMAND_RECURSIVE_OPTIONS) "$(DESTDIR)$(IDATADIR)"
	$(REMOVE_COMMAND) $(REMOVE_COMMAND_RECURSIVE_OPTIONS) "$(DESTDIR)$(IEGGDIR)"
ifdef WINDOWS_SHELL
	$(REMOVE_COMMAND) $(REMOVE_COMMAND_OPTIONS) "$(DESTDIR)$(IBINDIR)$(SEP)csibatch.bat"
endif

# build versioning

ifdef WINDOWS_SHELL
buildbranch:
	echo.$(BRANCHNAME)>buildbranch
buildid:
	echo.$(BUILD_ID)>buildid
else
.PHONY: identify-me

identify-me:
	@sh $(SRCDIR)identify.sh $(SRCDIR)

buildbranch: identify-me
buildid: identify-me
endif

# bootstrapping c sources

define declare-emitted-import-lib-dependency
.SECONDARY: $(1).import.scm
$(1).import.scm: $(2).c
endef

define declare-emitted-chicken-import-lib-dependency
$(call declare-emitted-import-lib-dependency,chicken.$(1),$(1))
endef

define declare-emitted-compiler-import-lib-dependency
$(call declare-emitted-import-lib-dependency,chicken.compiler.$(1),$(1))
endef

$(foreach lib, $(DYNAMIC_IMPORT_LIBRARIES),\
          $(eval $(call declare-emitted-import-lib-dependency,$(lib),$(lib))))

$(foreach lib, $(DYNAMIC_CHICKEN_UNIT_IMPORT_LIBRARIES),\
          $(eval $(call declare-emitted-chicken-import-lib-dependency,$(lib))))

$(foreach lib, $(COMPILER_OBJECTS_1),\
          $(eval $(call declare-emitted-compiler-import-lib-dependency,$(lib))))

# special cases for modules not corresponding directly to units
$(eval $(call declare-emitted-import-lib-dependency,chicken.errno,$(POSIXFILE)))
$(eval $(call declare-emitted-import-lib-dependency,chicken.file.posix,$(POSIXFILE)))
$(eval $(call declare-emitted-import-lib-dependency,chicken.time.posix,$(POSIXFILE)))
$(eval $(call declare-emitted-import-lib-dependency,chicken.process,$(POSIXFILE)))
$(eval $(call declare-emitted-import-lib-dependency,chicken.process.signal,$(POSIXFILE)))
$(eval $(call declare-emitted-import-lib-dependency,chicken.process-context.posix,$(POSIXFILE)))
$(eval $(call declare-emitted-import-lib-dependency,chicken.bitwise,library))
$(eval $(call declare-emitted-import-lib-dependency,chicken.blob,library))
$(eval $(call declare-emitted-import-lib-dependency,chicken.fixnum,library))
$(eval $(call declare-emitted-import-lib-dependency,chicken.flonum,library))
$(eval $(call declare-emitted-import-lib-dependency,chicken.gc,library))
$(eval $(call declare-emitted-import-lib-dependency,chicken.keyword,library))
$(eval $(call declare-emitted-import-lib-dependency,chicken.platform,library))
$(eval $(call declare-emitted-import-lib-dependency,chicken.plist,library))
$(eval $(call declare-emitted-import-lib-dependency,chicken.process-context,library))
$(eval $(call declare-emitted-import-lib-dependency,chicken.time,library))
$(eval $(call declare-emitted-import-lib-dependency,chicken.load,eval))
$(eval $(call declare-emitted-import-lib-dependency,chicken.format,extras))
$(eval $(call declare-emitted-import-lib-dependency,chicken.io,extras))
$(eval $(call declare-emitted-import-lib-dependency,chicken.pretty-print,extras))
$(eval $(call declare-emitted-import-lib-dependency,chicken.random,extras))
$(eval $(call declare-emitted-import-lib-dependency,chicken.locative,lolevel))
$(eval $(call declare-emitted-import-lib-dependency,chicken.memory,lolevel))
$(eval $(call declare-emitted-import-lib-dependency,chicken.memory.representation,lolevel))
$(eval $(call declare-emitted-import-lib-dependency,chicken.sort,data-structures))
$(eval $(call declare-emitted-import-lib-dependency,chicken.string,data-structures))

chicken.c: chicken.scm mini-srfi-1.scm \
		chicken.compiler.batch-driver.import.scm \
		chicken.compiler.c-platform.import.scm \
		chicken.compiler.support.import.scm \
		chicken.compiler.user-pass.import.scm \
		chicken.process-context.import.scm \
		chicken.string.import.scm
batch-driver.c: batch-driver.scm mini-srfi-1.scm \
		chicken.compiler.core.import.scm \
		chicken.compiler.compiler-syntax.import.scm \
		chicken.compiler.optimizer.import.scm \
		chicken.compiler.scrutinizer.import.scm \
		chicken.compiler.c-platform.import.scm \
		chicken.compiler.lfa2.import.scm \
		chicken.compiler.c-backend.import.scm \
		chicken.compiler.support.import.scm \
		chicken.compiler.user-pass.import.scm \
		chicken.format.import.scm \
		chicken.gc.import.scm \
		chicken.internal.import.scm \
		chicken.load.import.scm \
		chicken.pathname.import.scm \
		chicken.platform.import.scm \
		chicken.pretty-print.import.scm \
		chicken.process-context.import.scm \
		chicken.condition.import.scm \
		chicken.port.import.scm \
		chicken.string.import.scm \
		chicken.syntax.import.scm \
		chicken.time.import.scm
c-platform.c: c-platform.scm mini-srfi-1.scm \
		chicken.compiler.optimizer.import.scm \
		chicken.compiler.support.import.scm \
		chicken.compiler.core.import.scm \
		chicken.internal.import.scm
c-backend.c: c-backend.scm mini-srfi-1.scm \
		chicken.compiler.c-platform.import.scm \
		chicken.compiler.support.import.scm \
		chicken.compiler.core.import.scm \
		chicken.bitwise.import.scm \
		chicken.flonum.import.scm \
		chicken.foreign.import.scm \
		chicken.format.import.scm \
		chicken.internal.import.scm \
		chicken.sort.import.scm \
		chicken.string.import.scm \
		chicken.time.import.scm
core.c: core.scm mini-srfi-1.scm \
		chicken.compiler.scrutinizer.import.scm \
		chicken.compiler.support.import.scm \
		chicken.eval.import.scm \
		chicken.file.import.scm \
		chicken.fixnum.import.scm \
		chicken.format.import.scm \
		chicken.io.import.scm \
		chicken.keyword.import.scm \
		chicken.load.import.scm \
		chicken.pretty-print.import.scm \
		chicken.string.import.scm \
		chicken.syntax.import.scm
optimizer.c: optimizer.scm mini-srfi-1.scm \
		chicken.compiler.support.import.scm \
		chicken.fixnum.import.scm \
		chicken.internal.import.scm \
		chicken.sort.import.scm \
		chicken.string.import.scm
scheduler.c: scheduler.scm \
		chicken.fixnum.import.scm \
		chicken.format.import.scm \
		chicken.condition.import.scm
scrutinizer.c: scrutinizer.scm mini-srfi-1.scm \
		chicken.compiler.support.import.scm \
		chicken.fixnum.import.scm \
		chicken.format.import.scm \
		chicken.internal.import.scm \
		chicken.io.import.scm \
		chicken.pathname.import.scm \
		chicken.platform.import.scm \
		chicken.sort.import.scm \
		chicken.port.import.scm \
		chicken.pretty-print.import.scm \
		chicken.string.import.scm
lfa2.c: lfa2.scm mini-srfi-1.scm \
		chicken.compiler.support.import.scm \
		chicken.format.import.scm
compiler-syntax.c: compiler-syntax.scm mini-srfi-1.scm \
		chicken.compiler.support.import.scm \
		chicken.compiler.core.import.scm \
		chicken.fixnum.import.scm \
		chicken.format.import.scm \
		chicken.syntax.import.scm
chicken-ffi-syntax.c: chicken-ffi-syntax.scm \
		chicken.format.import.scm \
		chicken.internal.import.scm \
		chicken.string.import.scm
support.c: support.scm mini-srfi-1.scm \
		chicken.bitwise.import.scm \
		chicken.blob.import.scm \
		chicken.condition.import.scm \
		chicken.file.import.scm \
		chicken.fixnum.import.scm \
		chicken.foreign.import.scm \
		chicken.format.import.scm \
		chicken.internal.import.scm \
		chicken.io.import.scm \
		chicken.keyword.import.scm \
		chicken.pathname.import.scm \
		chicken.platform.import.scm \
		chicken.plist.import.scm \
		chicken.port.import.scm \
		chicken.pretty-print.import.scm \
		chicken.random.import.scm \
		chicken.sort.import.scm \
		chicken.string.import.scm \
		chicken.time.import.scm
modules.c: modules.scm \
		chicken.internal.import.scm \
		chicken.keyword.import.scm \
		chicken.base.import.scm \
		chicken.syntax.import.scm \
		chicken.load.import.scm \
		chicken.platform.import.scm
csc.c: csc.scm \
		chicken.file.import.scm \
		chicken.foreign.import.scm \
		chicken.format.import.scm \
		chicken.io.import.scm \
		chicken.pathname.import.scm \
		chicken.process.import.scm \
		chicken.process-context.import.scm \
		chicken.string.import.scm
csi.c: csi.scm \
		chicken.condition.import.scm \
		chicken.file.import.scm \
		chicken.foreign.import.scm \
		chicken.format.import.scm \
		chicken.gc.import.scm \
		chicken.internal.import.scm \
		chicken.io.import.scm \
		chicken.keyword.import.scm \
		chicken.load.import.scm \
		chicken.platform.import.scm \
		chicken.port.import.scm \
		chicken.pretty-print.import.scm \
		chicken.process.import.scm \
		chicken.process-context.import.scm \
		chicken.repl.import.scm \
		chicken.sort.import.scm \
		chicken.string.import.scm
chicken-profile.c: chicken-profile.scm \
		chicken.internal.import.scm \
		chicken.file.import.scm \
		chicken.file.posix.import.scm \
		chicken.fixnum.import.scm \
		chicken.process-context.import.scm \
		chicken.sort.import.scm \
		chicken.string.import.scm
chicken-status.c: chicken-status.scm \
		chicken.file.import.scm \
		chicken.file.posix.import.scm \
		chicken.fixnum.import.scm \
		chicken.foreign.import.scm \
		chicken.format.import.scm \
		chicken.irregex.import.scm \
		chicken.pathname.import.scm \
		chicken.port.import.scm \
		chicken.pretty-print.import.scm \
		chicken.process-context.import.scm \
		chicken.sort.import.scm \
		chicken.string.import.scm
chicken-install.c: chicken-install.scm \
		chicken.condition.import.scm \
		chicken.file.import.scm \
		chicken.file.posix.import.scm \
		chicken.fixnum.import.scm \
		chicken.foreign.import.scm \
		chicken.format.import.scm \
		chicken.internal.import.scm \
		chicken.io.import.scm \
		chicken.irregex.import.scm \
		chicken.pathname.import.scm \
		chicken.port.import.scm \
		chicken.pretty-print.import.scm \
		chicken.process.import.scm \
		chicken.process-context.import.scm \
		chicken.sort.import.scm \
		chicken.string.import.scm \
		chicken.tcp.import.scm
chicken-uninstall.c: chicken-uninstall.scm \
		chicken.file.import.scm \
		chicken.fixnum.import.scm \
		chicken.foreign.import.scm \
		chicken.format.import.scm \
		chicken.irregex.import.scm \
		chicken.pathname.import.scm \
		chicken.port.import.scm \
		chicken.process.import.scm \
		chicken.process-context.import.scm \
		chicken.string.import.scm
chicken-syntax.c: chicken-syntax.scm \
		chicken.fixnum.import.scm \
		chicken.platform.import.scm \
		chicken.internal.import.scm
srfi-4.c: srfi-4.scm \
		chicken.bitwise.import.scm \
		chicken.fixnum.import.scm \
		chicken.foreign.import.scm \
		chicken.gc.import.scm \
		chicken.platform.import.scm
posixunix.c: posixunix.scm \
		chicken.bitwise.import.scm \
		chicken.condition.import.scm \
		chicken.foreign.import.scm \
		chicken.memory.import.scm \
		chicken.pathname.import.scm \
		chicken.platform.import.scm \
		chicken.port.import.scm \
		chicken.process-context.import.scm \
		chicken.time.import.scm
posixwin.c: posixwin.scm \
		chicken.condition.import.scm \
		chicken.bitwise.import.scm \
		chicken.foreign.import.scm \
		chicken.memory.import.scm \
		chicken.pathname.import.scm \
		chicken.platform.import.scm \
		chicken.port.import.scm \
		chicken.process-context.import.scm \
		chicken.string.import.scm \
		chicken.time.import.scm
data-structures.c: data-structures.scm \
		chicken.condition.import.scm \
		chicken.fixnum.import.scm \
		chicken.foreign.import.scm
expand.c: expand.scm \
		chicken.blob.import.scm \
		chicken.condition.import.scm \
		chicken.fixnum.import.scm \
		chicken.keyword.import.scm \
		chicken.platform.import.scm \
		chicken.string.import.scm \
		chicken.internal.import.scm
extras.c: extras.scm \
		chicken.fixnum.import.scm \
		chicken.string.import.scm \
		chicken.time.import.scm
eval.c: eval.scm \
		chicken.blob.import.scm \
		chicken.condition.import.scm \
		chicken.fixnum.import.scm \
		chicken.foreign.import.scm \
		chicken.internal.import.scm \
		chicken.keyword.import.scm \
		chicken.syntax.import.scm \
		chicken.platform.import.scm
repl.c: repl.scm \
		chicken.eval.import.scm
file.c: file.scm \
		chicken.condition.import.scm \
		chicken.fixnum.import.scm \
		chicken.io.import.scm \
		chicken.irregex.import.scm \
		chicken.foreign.import.scm \
		chicken.pathname.import.scm \
		chicken.process-context.import.scm
lolevel.c: lolevel.scm \
		chicken.fixnum.import.scm \
		chicken.foreign.import.scm
pathname.c: pathname.scm \
		chicken.fixnum.import.scm \
		chicken.irregex.import.scm \
		chicken.platform.import.scm \
		chicken.string.import.scm
port.c: port.scm \
		chicken.fixnum.import.scm \
		chicken.io.import.scm
read-syntax.c: read-syntax.scm \
		chicken.internal.import.scm \
		chicken.platform.import.scm
tcp.c: tcp.scm \
		chicken.fixnum.import.scm \
		chicken.foreign.import.scm \
		chicken.port.import.scm \
		chicken.time.import.scm
eval-modules.c: eval-modules.scm $(DYNAMIC_IMPORT_LIBRARIES:=.import.scm) \
	$(foreach lib,$(DYNAMIC_CHICKEN_IMPORT_LIBRARIES),chicken.$(lib).import.scm) \
	$(foreach lib,$(DYNAMIC_CHICKEN_UNIT_IMPORT_LIBRARIES),$(lib).c)
continuation.c: continuation.scm \
		chicken.fixnum.import.scm
internal.c: internal.scm \
		chicken.fixnum.import.scm
irregex.c: irregex.scm \
		chicken.fixnum.import.scm \
		chicken.syntax.import.scm
profiler.c: profiler.scm \
		chicken.fixnum.import.scm
stub.c: stub.scm \
		chicken.platform.import.scm


define profile-flags
$(if $(filter $(basename $(1)),$(PROFILE_OBJECTS)),-profile)
endef

bootstrap-lib = $(CHICKEN) $(call profile-flags, $@) $< $(CHICKEN_LIBRARY_OPTIONS) -output-file $@

library.c: $(SRCDIR)library.scm
	$(bootstrap-lib) \
	-no-module-registration \
	-emit-import-library chicken.bitwise \
	-emit-import-library chicken.blob \
	-emit-import-library chicken.fixnum \
	-emit-import-library chicken.flonum \
	-emit-import-library chicken.gc \
	-emit-import-library chicken.keyword \
	-emit-import-library chicken.platform \
	-emit-import-library chicken.plist \
	-emit-import-library chicken.process-context
internal.c: $(SRCDIR)internal.scm $(SRCDIR)mini-srfi-1.scm
	$(bootstrap-lib) -emit-import-library chicken.internal
eval.c: $(SRCDIR)eval.scm $(SRCDIR)common-declarations.scm $(SRCDIR)mini-srfi-1.scm
	$(bootstrap-lib) \
	-emit-import-library chicken.eval \
	-emit-import-library chicken.load
read-syntax.c: $(SRCDIR)read-syntax.scm $(SRCDIR)common-declarations.scm
	$(bootstrap-lib) -emit-import-library chicken.read-syntax
repl.c: $(SRCDIR)repl.scm $(SRCDIR)common-declarations.scm
	$(bootstrap-lib) -emit-import-library chicken.repl
expand.c: $(SRCDIR)expand.scm $(SRCDIR)synrules.scm $(SRCDIR)common-declarations.scm
	$(bootstrap-lib) \
	-no-module-registration
modules.c: $(SRCDIR)modules.scm $(SRCDIR)common-declarations.scm $(SRCDIR)mini-srfi-1.scm
	$(bootstrap-lib)
extras.c: $(SRCDIR)extras.scm $(SRCDIR)common-declarations.scm
	$(bootstrap-lib) \
	-emit-import-library chicken.format \
	-emit-import-library chicken.io \
	-emit-import-library chicken.pretty-print \
	-emit-import-library chicken.random
posixunix.c: $(SRCDIR)posix.scm $(SRCDIR)posixunix.scm $(SRCDIR)posix-common.scm $(SRCDIR)common-declarations.scm
	$(bootstrap-lib) -feature platform-unix \
	-emit-import-library chicken.errno \
	-emit-import-library chicken.file.posix \
	-emit-import-library chicken.time.posix \
	-emit-import-library chicken.process \
	-emit-import-library chicken.process.signal \
	-emit-import-library chicken.process-context.posix \
	-no-module-registration
posixwin.c: $(SRCDIR)posix.scm $(SRCDIR)posixwin.scm $(SRCDIR)posix-common.scm $(SRCDIR)common-declarations.scm
	$(bootstrap-lib) -feature platform-windows \
	-emit-import-library chicken.errno \
	-emit-import-library chicken.file.posix \
	-emit-import-library chicken.time.posix \
	-emit-import-library chicken.process \
	-emit-import-library chicken.process.signal \
	-emit-import-library chicken.process-context.posix \
	-no-module-registration
irregex.c: $(SRCDIR)irregex.scm $(SRCDIR)irregex-core.scm $(SRCDIR)irregex-utils.scm $(SRCDIR)common-declarations.scm
	$(bootstrap-lib) -emit-import-library chicken.irregex
chicken-syntax.c: $(SRCDIR)chicken-syntax.scm $(SRCDIR)common-declarations.scm $(SRCDIR)mini-srfi-1.scm
	$(bootstrap-lib)
chicken-ffi-syntax.c: $(SRCDIR)chicken-ffi-syntax.scm $(SRCDIR)common-declarations.scm $(SRCDIR)mini-srfi-1.scm
	$(bootstrap-lib)
continuation.c: $(SRCDIR)continuation.scm $(SRCDIR)common-declarations.scm
	$(bootstrap-lib) -emit-import-library chicken.continuation
data-structures.c: $(SRCDIR)data-structures.scm $(SRCDIR)common-declarations.scm
	$(bootstrap-lib) \
	-emit-import-library chicken.sort \
	-emit-import-library chicken.string
pathname.c: $(SRCDIR)pathname.scm $(SRCDIR)common-declarations.scm
	$(bootstrap-lib) -emit-import-library chicken.pathname
port.c: $(SRCDIR)port.scm $(SRCDIR)common-declarations.scm
	$(bootstrap-lib) -emit-import-library chicken.port
file.c: $(SRCDIR)file.scm $(SRCDIR)common-declarations.scm
	$(bootstrap-lib) -emit-import-library chicken.file
lolevel.c: $(SRCDIR)lolevel.scm $(SRCDIR)common-declarations.scm
	$(bootstrap-lib) \
	-emit-import-library chicken.locative \
	-emit-import-library chicken.memory \
	-emit-import-library chicken.memory.representation
tcp.c: $(SRCDIR)tcp.scm $(SRCDIR)common-declarations.scm
	$(bootstrap-lib) -emit-import-library chicken.tcp
srfi-4.c: $(SRCDIR)srfi-4.scm $(SRCDIR)common-declarations.scm
	$(bootstrap-lib) -emit-import-library srfi-4
scheduler.c: $(SRCDIR)scheduler.scm $(SRCDIR)common-declarations.scm
	$(bootstrap-lib) 
profiler.c: $(SRCDIR)profiler.scm $(SRCDIR)common-declarations.scm
	$(bootstrap-lib) 
stub.c: $(SRCDIR)stub.scm $(SRCDIR)common-declarations.scm
	$(bootstrap-lib) 
debugger-client.c: $(SRCDIR)debugger-client.scm $(SRCDIR)common-declarations.scm dbg-stub.c
	$(bootstrap-lib)
build-version.c: $(SRCDIR)build-version.scm $(SRCDIR)buildversion buildbranch buildid
	$(bootstrap-lib)
eval-modules.c: $(SRCDIR)eval-modules.scm $(SRCDIR)common-declarations.scm
	$(bootstrap-lib)

define declare-bootstrap-import-lib
$(1).import.c: $$(SRCDIR)$(1).import.scm
	$$(CHICKEN) $$< $$(CHICKEN_IMPORT_LIBRARY_OPTIONS) -output-file $$@
endef

$(foreach obj, $(IMPORT_LIBRARIES),\
          $(eval $(call declare-bootstrap-import-lib,$(obj))))

# Bootstrap compiler objects

define declare-bootstrap-compiler-object
$(1).c: $$(SRCDIR)$(1).scm $$(SRCDIR)tweaks.scm
	$$(CHICKEN) $$< $$(CHICKEN_PROGRAM_OPTIONS) -emit-import-library chicken.compiler.$(1) \
		-output-file $$@ 
endef

$(foreach obj, $(COMPILER_OBJECTS_1),\
          $(eval $(call declare-bootstrap-compiler-object,$(obj))))

csi.c: $(SRCDIR)csi.scm $(SRCDIR)banner.scm $(SRCDIR)mini-srfi-1.scm
	$(CHICKEN) $< $(CHICKEN_PROGRAM_OPTIONS) -output-file $@
chicken-profile.c: $(SRCDIR)chicken-profile.scm $(SRCDIR)mini-srfi-1.scm
	$(CHICKEN) $< $(CHICKEN_PROGRAM_OPTIONS) -output-file $@ 
chicken-install.c: $(SRCDIR)chicken-install.scm $(SRCDIR)mini-srfi-1.scm $(SRCDIR)egg-compile.scm $(SRCDIR)egg-download.scm $(SRCDIR)egg-environment.scm $(SRCDIR)egg-information.scm
	$(CHICKEN) $< $(CHICKEN_PROGRAM_OPTIONS) -output-file $@ 
chicken-uninstall.c: $(SRCDIR)chicken-uninstall.scm $(SRCDIR)mini-srfi-1.scm $(SRCDIR)egg-environment.scm $(SRCDIR)egg-information.scm
	$(CHICKEN) $< $(CHICKEN_PROGRAM_OPTIONS) -output-file $@ 
chicken-status.c: $(SRCDIR)chicken-status.scm $(SRCDIR)mini-srfi-1.scm $(SRCDIR)egg-environment.scm $(SRCDIR)egg-information.scm
	$(CHICKEN) $< $(CHICKEN_PROGRAM_OPTIONS) -output-file $@ 
csc.c: $(SRCDIR)csc.scm $(SRCDIR)mini-srfi-1.scm $(SRCDIR)egg-environment.scm
	$(CHICKEN) $< $(CHICKEN_PROGRAM_OPTIONS) -output-file $@ 

# distribution files

.PHONY: distfiles dist html

distfiles: $(DISTFILES)

dist: distfiles html
	CSI=$(CSI) $(CSI) -s $(SRCDIR)scripts$(SEP)makedist.scm -platform $(PLATFORM) CHICKEN=$(CHICKEN)

# Jim's `manual-labor' must be installed (just run "chicken-install manual-labor")
html:
	$(MAKEDIR_COMMAND) $(MAKEDIR_COMMAND_OPTIONS) $(SRCDIR)manual-html
	manual-labor $(SRCDIR)manual $(SRCDIR)manual-html
	$(COPY_COMMAND) $(SRCDIR)chicken.png manual-html
	$(COPY_COMMAND) $(SRCDIR)manual.css manual-html
	$(COPY_COMMAND) $(SRCDIR)index.html manual-html

# cleaning up

.PHONY: clean spotless confclean testclean

BUILD_CONFIG_FILES = chicken-config.h chicken-defaults.h chicken-install.rc chicken-uninstall.rc

clean:
	-$(REMOVE_COMMAND) $(REMOVE_COMMAND_OPTIONS) $(PROGRAM_PREFIX)chicken$(PROGRAM_SUFFIX)$(EXE) $(PROGRAM_PREFIX)csi$(PROGRAM_SUFFIX)$(EXE) $(PROGRAM_PREFIX)csc$(PROGRAM_SUFFIX)$(EXE) \
	  $(CHICKEN_PROFILE_PROGRAM)$(EXE) \
	  $(CHICKEN_INSTALL_PROGRAM)$(EXE) \
	  $(CHICKEN_UNINSTALL_PROGRAM)$(EXE) \
	  $(CHICKEN_STATUS_PROGRAM)$(EXE) \
	  *$(O) \
	  $(CHICKEN_DO_PROGRAM)$(EXE) \
	  $(CHICKEN_DEBUGGER_PROGRAM) \
	  $(LIBCHICKEN_SO_FILE) \
	  $(PRIMARY_LIBCHICKEN) \
	  lib$(PROGRAM_PREFIX)chicken$(PROGRAM_SUFFIX)$(A) \
	  $(IMPORT_LIBRARIES:=.import.so) $(LIBCHICKEN_IMPORT_LIBRARY) \
	  $(foreach lib,$(DYNAMIC_IMPORT_LIBRARIES),chicken.$(lib).import.scm) \
	  $(BUILD_CONFIG_FILES)
ifdef USES_SONAME
	-$(REMOVE_COMMAND) $(REMOVE_COMMAND_OPTIONS) lib$(PROGRAM_PREFIX)chicken$(PROGRAM_SUFFIX).so.$(BINARYVERSION)
endif

confclean:
	-$(REMOVE_COMMAND) $(REMOVE_COMMAND_OPTIONS) $(BUILD_CONFIG_FILES)

spotless: clean testclean
	-$(REMOVE_COMMAND) $(REMOVE_COMMAND_OPTIONS) $(DISTFILES) \
	buildid buildbranch

testclean:
	-$(REMOVE_COMMAND) $(REMOVE_COMMAND_RECURSIVE_OPTIONS) \
	  $(SRCDIR)tests$(SEP)*.dll \
	  $(SRCDIR)tests$(SEP)*.import.scm \
	  $(SRCDIR)tests$(SEP)*.inline \
	  $(SRCDIR)tests$(SEP)*.link \
	  $(SRCDIR)tests$(SEP)*.o \
	  $(SRCDIR)tests$(SEP)*.obj \
	  $(SRCDIR)tests$(SEP)*.out \
	  $(SRCDIR)tests$(SEP)*.profile \
	  $(SRCDIR)tests$(SEP)*.redacted \
	  $(SRCDIR)tests$(SEP)*.so \
	  $(SRCDIR)tests$(SEP)tmp \
	  $(SRCDIR)tests$(SEP)tmp.c \
	  $(SRCDIR)tests$(SEP)empty-file \
	  $(SRCDIR)tests$(SEP)null \
	  $(SRCDIR)tests$(SEP)null.c \
	  $(SRCDIR)tests$(SEP)null.exe \
	  $(SRCDIR)tests$(SEP)test-repository \
	  $(SRCDIR)tests$(SEP)redact-gensyms

# run tests

.PHONY: check

export PROGRAM_PREFIX
export PROGRAM_SUFFIX

check: $(TARGETS)
ifndef WINDOWS_SHELL
	cd tests; sh runtests.sh
else
	cd tests & runtests.bat
endif

# benchmark

.PHONY: bench

bench: $(CHICKEN_SHARED_EXECUTABLE) $(CSI_SHARED_EXECUTABLE) $(CSC_PROGRAM)$(EXE)
	cd tests; echo >>bench.log; date >>bench.log; sh runbench.sh 2>&1 | tee -a bench.log


# build static bootstrapping chicken

.PHONY: boot-chicken bootclean

boot-chicken:
	"$(MAKE)" PLATFORM=$(PLATFORM) PREFIX=/nowhere CONFIG= \
	  CHICKEN=$(CHICKEN) PROGRAM_SUFFIX=-boot-stage1 STATICBUILD=1 \
	  C_COMPILER_OPTIMIZATION_OPTIONS="$(C_COMPILER_OPTIMIZATION_OPTIONS)" BUILDING_CHICKEN_BOOT=1 \
	  confclean chicken-boot-stage1$(EXE)
	"$(MAKE)" PLATFORM=$(PLATFORM) PREFIX=/nowhere CONFIG= \
	  CHICKEN=.$(SEP)chicken-boot-stage1$(EXE) PROGRAM_SUFFIX=-boot \
	  STATICBUILD=1 C_COMPILER_OPTIMIZATION_OPTIONS="$(C_COMPILER_OPTIMIZATION_OPTIONS)" \
	  touchfiles chicken-boot$(EXE) confclean

bootclean:
	-$(REMOVE_COMMAND) $(REMOVE_COMMAND_OPTIONS) \
	  $(SRCDIR)chicken-boot$(EXE) \
	  $(SRCDIR)chicken-boot-stage1$(EXE) \
	  $(SRCDIR)libchicken-boot$(A) \
	  $(SRCDIR)libchicken-boot-stage1$(A)

.PHONY: touchfiles

touchfiles:
ifdef WINDOWS_SHELL
	for %%x in (*.scm) do copy /b %%x +,,
else
	touch *.scm
endif
