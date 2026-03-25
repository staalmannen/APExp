CFLAGS_SHARED_ATTR	+= -DSLBT_EXPORT
CFLAGS_STATIC_ATTR	+= -DSLBT_STATIC
CFLAGS_APP_ATTR		+= -DSLBT_APP

CFLAGS_MACHINE		:= -DSLBT_MACHINE=\"$(CC_HOST)\"
CFLAGS_PKGDATA		:= -DSLBT_PACKAGE_DATADIR=\"$(DATADIR)/$(PACKAGE)\"
CFLAGS_M4DIR		:= -DSLBT_PACKAGE_M4DIR=\"$(M4_DIR)\"

CFLAGS_CONFIG		+= $(CFLAGS_MACHINE)
CFLAGS_CONFIG		+= $(CFLAGS_PKGDATA)
CFLAGS_CONFIG		+= $(CFLAGS_M4DIR)
CFLAGS_CONFIG		+= $(CFLAGS_ATTR_VISIBILITY_HIDDEN)

src/driver/slbt_driver_ctx.o:	version.tag
src/driver/slbt_driver_ctx.lo:	version.tag

DBGNAME  = dlibtool
LEGABITS = clibtool
LEGADBGS = dclibtool
RAPUNZEL = rlibtool
RAPUNCEL = rclibtool
RAPUNDEL = rdlibtool
RAPUNJEL = rdclibtool
STOOLIE  = slibtoolize

install-app-extras: install-slibtoolize

install-app-extras:
	mkdir -p $(DESTDIR)$(BINDIR)

	rm -f bin/$(NICKNAME)-shared$(OS_APP_SUFFIX).tmp
	rm -f bin/$(NICKNAME)-static$(OS_APP_SUFFIX).tmp
	rm -f bin/$(NICKNAME)-ar$(OS_APP_SUFFIX).tmp

	rm -f bin/$(DBGNAME)$(OS_APP_SUFFIX).tmp
	rm -f bin/$(DBGNAME)-shared$(OS_APP_SUFFIX).tmp
	rm -f bin/$(DBGNAME)-static$(OS_APP_SUFFIX).tmp
	rm -f bin/$(DBGNAME)-ar$(OS_APP_SUFFIX).tmp

	rm -f bin/$(LEGABITS)$(OS_APP_SUFFIX).tmp
	rm -f bin/$(LEGABITS)-shared$(OS_APP_SUFFIX).tmp
	rm -f bin/$(LEGABITS)-static$(OS_APP_SUFFIX).tmp
	rm -f bin/$(LEGABITS)-ar$(OS_APP_SUFFIX).tmp

	rm -f bin/$(LEGADBGS)$(OS_APP_SUFFIX).tmp
	rm -f bin/$(LEGADBGS)-shared$(OS_APP_SUFFIX).tmp
	rm -f bin/$(LEGADBGS)-static$(OS_APP_SUFFIX).tmp
	rm -f bin/$(LEGADBGS)-ar$(OS_APP_SUFFIX).tmp

	rm -f bin/$(RAPUNZEL)$(OS_APP_SUFFIX).tmp
	rm -f bin/$(RAPUNCEL)$(OS_APP_SUFFIX).tmp
	rm -f bin/$(RAPUNDEL)$(OS_APP_SUFFIX).tmp
	rm -f bin/$(RAPUNJEL)$(OS_APP_SUFFIX).tmp

	rm -f bin/$(STOOLIE)$(OS_APP_SUFFIX).tmp

	ln -s ./$(NICKNAME)$(OS_APP_SUFFIX) bin/$(NICKNAME)-shared$(OS_APP_SUFFIX).tmp
	ln -s ./$(NICKNAME)$(OS_APP_SUFFIX) bin/$(NICKNAME)-static$(OS_APP_SUFFIX).tmp
	ln -s ./$(NICKNAME)$(OS_APP_SUFFIX) bin/$(NICKNAME)-ar$(OS_APP_SUFFIX).tmp

	ln -s ./$(NICKNAME)$(OS_APP_SUFFIX) bin/$(DBGNAME)$(OS_APP_SUFFIX).tmp
	ln -s ./$(NICKNAME)$(OS_APP_SUFFIX) bin/$(DBGNAME)-shared$(OS_APP_SUFFIX).tmp
	ln -s ./$(NICKNAME)$(OS_APP_SUFFIX) bin/$(DBGNAME)-static$(OS_APP_SUFFIX).tmp
	ln -s ./$(NICKNAME)$(OS_APP_SUFFIX) bin/$(DBGNAME)-ar$(OS_APP_SUFFIX).tmp

	ln -s ./$(NICKNAME)$(OS_APP_SUFFIX) bin/$(LEGABITS)$(OS_APP_SUFFIX).tmp
	ln -s ./$(NICKNAME)$(OS_APP_SUFFIX) bin/$(LEGABITS)-shared$(OS_APP_SUFFIX).tmp
	ln -s ./$(NICKNAME)$(OS_APP_SUFFIX) bin/$(LEGABITS)-static$(OS_APP_SUFFIX).tmp
	ln -s ./$(NICKNAME)$(OS_APP_SUFFIX) bin/$(LEGABITS)-ar$(OS_APP_SUFFIX).tmp

	ln -s ./$(NICKNAME)$(OS_APP_SUFFIX) bin/$(LEGADBGS)$(OS_APP_SUFFIX).tmp
	ln -s ./$(NICKNAME)$(OS_APP_SUFFIX) bin/$(LEGADBGS)-shared$(OS_APP_SUFFIX).tmp
	ln -s ./$(NICKNAME)$(OS_APP_SUFFIX) bin/$(LEGADBGS)-static$(OS_APP_SUFFIX).tmp
	ln -s ./$(NICKNAME)$(OS_APP_SUFFIX) bin/$(LEGADBGS)-ar$(OS_APP_SUFFIX).tmp

	ln -s ./$(NICKNAME)$(OS_APP_SUFFIX) bin/$(RAPUNZEL)$(OS_APP_SUFFIX).tmp
	ln -s ./$(NICKNAME)$(OS_APP_SUFFIX) bin/$(RAPUNCEL)$(OS_APP_SUFFIX).tmp
	ln -s ./$(NICKNAME)$(OS_APP_SUFFIX) bin/$(RAPUNDEL)$(OS_APP_SUFFIX).tmp
	ln -s ./$(NICKNAME)$(OS_APP_SUFFIX) bin/$(RAPUNJEL)$(OS_APP_SUFFIX).tmp

	ln -s ./$(NICKNAME)$(OS_APP_SUFFIX) bin/$(STOOLIE)$(OS_APP_SUFFIX).tmp

	mv bin/$(NICKNAME)-shared$(OS_APP_SUFFIX).tmp $(DESTDIR)$(BINDIR)/$(NICKNAME)-shared$(OS_APP_SUFFIX)
	mv bin/$(NICKNAME)-static$(OS_APP_SUFFIX).tmp $(DESTDIR)$(BINDIR)/$(NICKNAME)-static$(OS_APP_SUFFIX)
	mv bin/$(NICKNAME)-ar$(OS_APP_SUFFIX).tmp     $(DESTDIR)$(BINDIR)/$(NICKNAME)-ar$(OS_APP_SUFFIX)

	mv bin/$(DBGNAME)$(OS_APP_SUFFIX).tmp         $(DESTDIR)$(BINDIR)/$(DBGNAME)$(OS_APP_SUFFIX)
	mv bin/$(DBGNAME)-shared$(OS_APP_SUFFIX).tmp  $(DESTDIR)$(BINDIR)/$(DBGNAME)-shared$(OS_APP_SUFFIX)
	mv bin/$(DBGNAME)-static$(OS_APP_SUFFIX).tmp  $(DESTDIR)$(BINDIR)/$(DBGNAME)-static$(OS_APP_SUFFIX)
	mv bin/$(DBGNAME)-ar$(OS_APP_SUFFIX).tmp      $(DESTDIR)$(BINDIR)/$(DBGNAME)-ar$(OS_APP_SUFFIX)

	mv bin/$(LEGABITS)$(OS_APP_SUFFIX).tmp        $(DESTDIR)$(BINDIR)/$(LEGABITS)$(OS_APP_SUFFIX)
	mv bin/$(LEGABITS)-shared$(OS_APP_SUFFIX).tmp $(DESTDIR)$(BINDIR)/$(LEGABITS)-shared$(OS_APP_SUFFIX)
	mv bin/$(LEGABITS)-static$(OS_APP_SUFFIX).tmp $(DESTDIR)$(BINDIR)/$(LEGABITS)-static$(OS_APP_SUFFIX)
	mv bin/$(LEGABITS)-ar$(OS_APP_SUFFIX).tmp     $(DESTDIR)$(BINDIR)/$(LEGABITS)-ar$(OS_APP_SUFFIX)

	mv bin/$(LEGADBGS)$(OS_APP_SUFFIX).tmp        $(DESTDIR)$(BINDIR)/$(LEGADBGS)$(OS_APP_SUFFIX)
	mv bin/$(LEGADBGS)-shared$(OS_APP_SUFFIX).tmp $(DESTDIR)$(BINDIR)/$(LEGADBGS)-shared$(OS_APP_SUFFIX)
	mv bin/$(LEGADBGS)-static$(OS_APP_SUFFIX).tmp $(DESTDIR)$(BINDIR)/$(LEGADBGS)-static$(OS_APP_SUFFIX)
	mv bin/$(LEGADBGS)-ar$(OS_APP_SUFFIX).tmp     $(DESTDIR)$(BINDIR)/$(LEGADBGS)-ar$(OS_APP_SUFFIX)

	mv bin/$(RAPUNZEL)$(OS_APP_SUFFIX).tmp        $(DESTDIR)$(BINDIR)/$(RAPUNZEL)$(OS_APP_SUFFIX)
	mv bin/$(RAPUNCEL)$(OS_APP_SUFFIX).tmp        $(DESTDIR)$(BINDIR)/$(RAPUNCEL)$(OS_APP_SUFFIX)
	mv bin/$(RAPUNDEL)$(OS_APP_SUFFIX).tmp        $(DESTDIR)$(BINDIR)/$(RAPUNDEL)$(OS_APP_SUFFIX)
	mv bin/$(RAPUNJEL)$(OS_APP_SUFFIX).tmp        $(DESTDIR)$(BINDIR)/$(RAPUNJEL)$(OS_APP_SUFFIX)

	mv bin/$(STOOLIE)$(OS_APP_SUFFIX).tmp         $(DESTDIR)$(BINDIR)/$(STOOLIE)$(OS_APP_SUFFIX)

install-slibtoolize:
	mkdir -p $(DESTDIR)$(M4_DIR)
	mkdir -p $(DESTDIR)$(DATADIR)/$(PACKAGE)

	cp -p $(SOURCE_DIR)/m4/slibtool.m4            $(DESTDIR)$(M4_DIR)
	cp -p $(SOURCE_DIR)/m4/sltdl.m4               $(DESTDIR)$(M4_DIR)
	cp -p $(SOURCE_DIR)/aux/ltmain.sh             $(DESTDIR)$(DATADIR)/$(PACKAGE)
	cp -p $(SOURCE_DIR)/aux/slibtool.sh           $(DESTDIR)$(DATADIR)/$(PACKAGE)
	cp -p $(SOURCE_DIR)/aux/ar-lib                $(DESTDIR)$(DATADIR)/$(PACKAGE)
	cp -p $(SOURCE_DIR)/aux/sltdl.h.in            $(DESTDIR)$(DATADIR)/$(PACKAGE)
	cp -p $(SOURCE_DIR)/aux/sltdl.mk.in           $(DESTDIR)$(DATADIR)/$(PACKAGE)

.PHONY: install-slibtoolize
