# Makefile.in: primary common build logic.
# this file is covered by COPYING.SOFORT.

.POSIX:

.SUFFIXES: .a .c .s .o .lo .ao

PACKAGE 		= slibtool
NICKNAME 		= slibtool
PROJECT_DIR 		= .
SOURCE_DIR 		= .
BUILD_DIR 		= /home/jens/Devel/APExp/sys/src/external/slibtool
GIT_REFERENCE_INDEX	=
CUSTOM_INSTALL_HEADERS  = no
AVOID_VERSION		= no

PKGNAME			= slibtool
PKGDESC			= a strong libtool implementation, written in C
PKGUSRC			= https://dl.foss21.org/slibtool/
PKGREPO			= https://git.foss21.org/slibtool
PKGPSRC			=
PKGDURL			=
PKGBUGS			=
PKGHOME			=
PKGDEFS			=
PKGLIBS			=

SRCINFO			= $(PROJECT_DIR)/project/srcdist/srcinfo.in
SRCSITE			= localhost

PGPRKEY			= !!VARIABLE_NOT_SET!!
PGPSKEY			= !!VARIABLE_NOT_SET!!

RAWBALL			=
RAWBALL_URL		=
RAWBALL_SHA256		=
MODBALL			=
MODBALL_URL		=
MODBALL_SHA256		=
SRCBALL			=
SRCBALL_URL		=
SRCBALL_SHA256		=

MAKE                    = make
MAKEMODE                = modern

BUILD 			=
HOST 			= x86_64-chimera-linux-musl
CCHOST 			= x86_64-chimera-linux-musl
CFGHOST 		=
TARGET 			=
ARCH 			=
COMPILER 		=
TOOLCHAIN		=
SYSROOT 		=
CROSS_COMPILE 		=
SHELL 			= /bin/sh

PREFIX 			= /usr/local
EXEC_PREFIX 		= /usr/local
BINDIR 			= /usr/local/bin
SBINDIR 		= /usr/local/sbin
LIBDIR 			= /usr/local/lib
INCLUDEDIR 		= /usr/local/include
OLDINCLUDEDIR 		= /usr/local/include
MANDIR 			= /usr/local/share/man
DOCDIR 			= /usr/local/share/doc/$(PACKAGE)
LIBEXECDIR 		= /usr/local/libexec

SYSCONFDIR		= /usr/local/etc
SHAREDSTATEDIR		= /usr/local/com
LOCALSTATEDIR		= /usr/local/var
RUNSTATEDIR		= /usr/local/var/run
DATAROOTDIR		= /usr/local/share
PKGDATADIR		= /usr/local/share/$(PACKAGE)
DATADIR			= /usr/local/share
INFODIR			= /usr/local/share/info
LOCALEDIR		= /usr/local/share/locale
HTMLDIR			= /usr/local/share/doc/$(PACKAGE)
DVIDIR			= /usr/local/share/doc/$(PACKAGE)
PDFDIR			= /usr/local/share/doc/$(PACKAGE)
PSDIR			= /usr/local/share/doc/$(PACKAGE)

TESTCFGDIR		=
TESTDATADIR		=

CFLAGS_COMMON 		+= $(_CFLAGS_std_c99) -D_XOPEN_SOURCE=700 -D_DEFAULT_SOURCE -D_BSD_SOURCE -I$(SOURCE_DIR)/src/internal -I$(SOURCE_DIR)/include -Ibuild
CFLAGS_DEBUG 		+=
CFLAGS_CMDLINE 		+=
CFLAGS_CONFIG 		+=
CFLAGS_SYSROOT 		+=
CFLAGS_SITE		+=
CFLAGS_PATH 		+=
CFLAGS_STRICT 		+=
CFLAGS_UTIL 		+=
CFLAGS_LAST 		+=
CFLAGS_ONCE 		+=

LDFLAGS_COMMON 		+= -Llib
LDFLAGS_DEBUG 		+=
LDFLAGS_CMDLINE 	+=
LDFLAGS_CONFIG 		+=
LDFLAGS_SYSROOT 	+=
LDFLAGS_PATH 		+=
LDFLAGS_STRICT 		+=
LDFLAGS_UTIL 		+=
LDFLAGS_LAST 		+=
LDFLAGS_ONCE 		+=

USER_CC                 =
USER_CPP                =
USER_CXX                =

NATIVE_HOST		= x86_64-chimera-linux-musl
NATIVE_CFGHOST		=
NATIVE_CFLAGS		= $(_NATIVE_CFLAGS_std_c99) -D_XOPEN_SOURCE=700
NATIVE_LDFLAGS		=

ALL_SHARED              = no
ALL_STATIC              = no
DISABLE_FRONTEND	= no
DISABLE_SHARED          = yes
DISABLE_STATIC          = yes

USE_CUSTOM_CFGDEFS      = yes
USE_CUSTOM_USRDEFS      =

SHARED_LIB_CMD          = $(CC) -shared -o
SHARED_LIB_LDFLAGS      = $(LDFLAGS_SHARED)

VERSION_OPT             = used

SHARED_LIBRARY_OPT      = disabled
STATIC_LIBRARY_OPT      = disabled

APP_FRONTEND_OPT        = enabled
APP_LINKING_OPT         = default

INSTALL_HEADERS_OPT     = default


all:
install:
shared:
static:

install-extras:
install-app-extras:

.cflags-host:
	@true : $(CFLAGS)

.cflags-native:
	@true : $(NATIVE_CFLAGS)

.ldflags-host:
	@true : $(LDFLAGS_APP)

.ldflags-native:
	@true : $(NATIVE_LDFLAGS)


include ./ccenv/host.mk
include ./ccenv/native.mk

include ./cfgdefs.mk
include ./usrdefs.mk

include $(PROJECT_DIR)/sofort/core/defs.mk
include $(PROJECT_DIR)/sofort/core/pkgconf.mk
include $(PROJECT_DIR)/sofort/core/version.mk
include $(PROJECT_DIR)/sofort/core/flavor.mk
include $(PROJECT_DIR)/sofort/core/infer.mk

include $(PROJECT_DIR)/project/osforce.mk
include $(PROJECT_DIR)/project/tree.mk
include $(PROJECT_DIR)/project/depends.mk
include $(PROJECT_DIR)/project/headers.mk
include $(PROJECT_DIR)/project/common.mk
include $(PROJECT_DIR)/project/arch.mk
include $(PROJECT_DIR)/project/extras.mk
include $(PROJECT_DIR)/project/overrides.mk

include ./testcfg.mk


all:		package-shared package-static app

install:	package-install-app
install:	package-install-extras
install:	install-libs

app:		app-tag

app.tag:
		cp $(PACKAGE_APP) $(APP)
		touch app.tag

install-libs:	package-install-shared
install-libs:	package-install-static

install-headers-default:
		mkdir -p $(DESTDIR)$(INCLUDEDIR)/$(PACKAGE)
		cp $(API_HEADERS) $(DESTDIR)$(INCLUDEDIR)/$(PACKAGE)

install-shared:	shared install-lib install-implib
install-shared: package-install-soname package-install-solink
install-shared: install-headers

install-lib:	shared
		mkdir -p $(DESTDIR)$(LIBDIR)
		cp $(SHARED_LIB) $(DESTDIR)$(LIBDIR)

install-static:	static install-headers
		mkdir -p $(DESTDIR)$(LIBDIR)
		cp $(STATIC_LIB) $(DESTDIR)$(LIBDIR)

install-app:	app install-app-extras
		mkdir -p $(DESTDIR)$(BINDIR)
		cp $(APP) $(DESTDIR)$(BINDIR)

install-static-app:	static-app install-app-extras
			mkdir -p $(DESTDIR)$(BINDIR)
			cp $(STATIC_APP) $(DESTDIR)$(BINDIR)/$(NICKNAME)$(OS_APP_SUFFIX)



shared:		shared-lib implib
shared:		package-shared-soname package-shared-solink

static:		static-lib

shared-lib:	shared-objs $(SHARED_LIB)

shared-soname:	shared-lib $(SHARED_SONAME)

shared-solink:	shared-lib $(SHARED_SOLINK)

static-lib:	static-objs $(STATIC_LIB)



default-app:	version.tag static-objs $(DEFAULT_APP)

shared-app:	version.tag shared $(SHARED_APP)

static-app:	version.tag static-objs $(STATIC_APP)



shared-objs:	dirs $(SHARED_OBJS)

static-objs:	dirs $(STATIC_OBJS)

app-objs:	dirs $(APP_OBJS)



$(APP_SRCS):	srcs.tag

$(COMMON_SRCS):	srcs.tag

$(APP_OBJS):	$(ALL_HEADERS) host.tag tree.tag

$(SHARED_OBJS):	$(ALL_HEADERS) host.tag tree.tag

$(STATIC_OBJS):	$(ALL_HEADERS) host.tag tree.tag


$(SHARED_LIB):	$(SHARED_OBJS)

$(STATIC_LIB):	$(STATIC_OBJS)

$(APP):		$(PACKAGE_APP)

$(DEFAULT_APP):	$(STATIC_OBJS) $(APP_OBJS)
		rm -f app.tag
		$(CC) -o $@ $(STATIC_OBJS) $(APP_OBJS) $(LDFLAGS_APP)

$(SHARED_APP):	$(DSO_REF_SOLINK) $(APP_OBJS) $(SHARED_SOLINK)
		rm -f app.tag
		$(CC) -o $@ $(APP_OBJS) $(LDFLAGS_APP) -l$(PACKAGE)

$(STATIC_APP):	$(STATIC_OBJS) $(APP_OBJS)
		rm -f app.tag
		$(CC) -static -o $@ $(STATIC_OBJS) $(APP_OBJS) $(LDFLAGS_STATIC)


dirs: 		dirs.tag

dirs.tag:
		mkdir -p build
		mkdir -p bin
		mkdir -p lib
		touch dirs.tag

host.tag:	Makefile
		rm -f host.tmp
		touch host.tmp
		mv host.tmp host.tag

version.tag:	$(GIT_REFERENCE_INDEX) dirs.tag
		$(PROJECT_DIR)/sofort/tools/version.sh	\
			-s $(SOURCE_DIR)		\
			-o build/$(PACKAGE)_version.h	\
			-p $(PACKAGE)
		touch version.tag

distclean:	clean
		rm -f ccenv/host.mk
		rm -f ccenv/native.mk
		rm -f cfgdefs.mk
		rm -f testcfg.mk
		rm -f usrdefs.mk
		rm -f config.log
		rm -f Makefile
		rmdir build ccenv bin lib 2>&1 || true

clean:		clean-implib
		rm -f tree.tag
		rm -f srcs.tag
		rm -f dirs.tag
		rm -f host.tag
		rm -f host.tmp
		rm -f version.tag
		rm -f app.tag
		rm -f $(SHARED_OBJS)
		rm -f $(STATIC_OBJS)
		rm -f $(APP_OBJS)
		rm -f $(SHARED_LIB)
		rm -f $(SHARED_SONAME)
		rm -f $(SHARED_SOLINK)
		rm -f $(STATIC_LIB)
		rm -f $(APP)
		rm -f $(DEFAULT_APP)
		rm -f $(SHARED_APP)
		rm -f $(STATIC_APP)
		rm -f build/$(PACKAGE)_version.h
		rm -f build/$(PACKAGE).pc


.PHONY:		package-app \
		all install shared static app \
		shared-objs shared-lib \
		shared-soname shared-solink \
		package-shared-soname package-shared-solink \
		static-objs static-lib \
		default-app shared-app static-app \
		install-shared install-static \
		install-soname install-solink \
		package-install-soname package-install-solink \
		install-headers install-app \
		install-headers-default install-headers-custom \
		clean distclean clean-implib version \
		.display .conf \
		.display-project .display-env .display-tools .display-flags \
		.display-pe .display-dirs .display-build \
		implib implib-ver implib-soname implib-solink \
		install-implib install-implib-ver \
		install-implib-soname install-implib-solink
