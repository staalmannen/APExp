# This Makefile is used to create several test cases for Tcl's load
# command.  It also illustrates how to take advantage of configuration
# exported by Tcl to set up Makefiles for shared libraries.

CC = cc
LIBS =			-L/home/jens/Devel/APExp/sys/src/external/tcl/unix -ltclstub -ldl -lz  -lpthread 
AC_FLAGS =		-DPACKAGE_NAME=\"tcl\" -DPACKAGE_TARNAME=\"tcl\" -DPACKAGE_VERSION=\"9.0\" -DPACKAGE_STRING=\"tcl\ 9.0\" -DPACKAGE_BUGREPORT=\"\" -DPACKAGE_URL=\"\" -DHAVE_STDIO_H=1 -DHAVE_STDLIB_H=1 -DHAVE_STRING_H=1 -DHAVE_INTTYPES_H=1 -DHAVE_STDINT_H=1 -DHAVE_STRINGS_H=1 -DHAVE_SYS_STAT_H=1 -DHAVE_SYS_TYPES_H=1 -DHAVE_UNISTD_H=1 -DHAVE_SYS_TIME_H=1 -DSTDC_HEADERS=1 -DHAVE_SYS_PARAM_H=1 -DTCL_CFGVAL_ENCODING=\"utf-8\" -D_REENTRANT=1 -D_THREAD_SAFE=1 -DHAVE_PTHREAD_ATTR_SETSTACKSIZE=1 -DHAVE_PTHREAD_ATFORK=1 -DSTATIC_BUILD=1 -DMODULE_SCOPE=extern\ __attribute__\(\(__visibility__\(\"hidden\"\)\)\) -DHAVE_HIDDEN=1 -DTCL_CFG_DO64BIT=1 -DHAVE_CAST_TO_UNION=1 -DHAVE_VFORK=1 -DHAVE_POSIX_SPAWNP=1 -DHAVE_POSIX_SPAWN_FILE_ACTIONS_ADDDUP2=1 -DHAVE_POSIX_SPAWNATTR_SETFLAGS=1 -DTCL_SHLIB_EXT=\".so\" -DNDEBUG=1 -DTCL_CFG_OPTIMIZED=1 -DMP_PREC=4 -D_LARGEFILE64_SOURCE=1 -DTCL_WIDE_INT_IS_LONG=1 -DHAVE_GETCWD=1 -DHAVE_MKSTEMP=1 -DHAVE_WAITPID=1 -DNO_GETWD=1 -DHAVE_GETNAMEINFO=1 -DHAVE_GETADDRINFO=1 -DHAVE_FREEADDRINFO=1 -DHAVE_GAI_STRERROR=1 -DHAVE_STRUCT_ADDRINFO=1 -DHAVE_STRUCT_IN6_ADDR=1 -DHAVE_STRUCT_SOCKADDR_IN6=1 -DHAVE_STRUCT_SOCKADDR_STORAGE=1 -DHAVE_GETPWUID_R_5=1 -DHAVE_GETPWUID_R=1 -DHAVE_GETPWNAM_R_5=1 -DHAVE_GETPWNAM_R=1 -DHAVE_GETGRGID_R_5=1 -DHAVE_GETGRGID_R=1 -DHAVE_GETGRNAM_R_5=1 -DHAVE_GETGRNAM_R=1 -DHAVE_DECL_GETHOSTBYNAME_R=1 -DHAVE_GETHOSTBYNAME_R_6=1 -DHAVE_GETHOSTBYNAME_R=1 -DHAVE_DECL_GETHOSTBYADDR_R=1 -DHAVE_GETHOSTBYADDR_R_8=1 -DHAVE_GETHOSTBYADDR_R=1 -DHAVE_TERMIOS_H=1 -DHAVE_SYS_IOCTL_H=1 -DHAVE_PSELECT=1 -DHAVE_SYS_EPOLL_H=1 -DNOTIFIER_EPOLL=1 -DHAVE_SYS_EVENTFD_H=1 -DHAVE_EVENTFD=1 -DHAVE_SYS_TIME_H=1 -DHAVE_GMTIME_R=1 -DHAVE_LOCALTIME_R=1 -DHAVE_TM_GMTOFF=1 -DHAVE_TIMEZONE_VAR=1 -DHAVE_STRUCT_STAT_ST_BLOCKS=1 -DHAVE_STRUCT_STAT_ST_BLKSIZE=1 -DHAVE_STRUCT_STAT_ST_RDEV=1 -DHAVE_BLKCNT_T=1 -DHAVE_INTPTR_T=1 -DHAVE_UINTPTR_T=1 -DNO_UNION_WAIT=1 -DHAVE_SIGNED_CHAR=1 -DHAVE_LANGINFO=1 -DHAVE_CFMAKERAW=1 -DHAVE_MKSTEMPS=1 -DHAVE_SYS_IOCTL_H=1 -DTCL_UNLOAD_DLLS=1 -DHAVE_CPUID=1 -DZIPFS_BUILD=2
SHLIB_LD =		${CC} ${CFLAGS} ${LDFLAGS} -shared
SHLIB_CFLAGS =		-fPIC -fno-common
SHLIB_LD_LIBS =		${LIBS}
SHLIB_SUFFIX =		.so
DLTEST_LD =		${SHLIB_LD}
DLTEST_SUFFIX =		
SRC_DIR =		/home/jens/Devel/APExp/sys/src/external/tcl/unix/dltest
BUILD_DIR =		.
TCL_VERSION=		9.0

CFLAGS_DEBUG		= -g
CFLAGS_OPTIMIZE		= -O2
CFLAGS			= $(CFLAGS_OPTIMIZE)  -pipe -m64 -finput-charset=UTF-8  -DTCL_NO_DEPRECATED=1 -Wall -Wextra -Wc++-compat -Wconversion -Werror
LDFLAGS_DEBUG		= 
LDFLAGS_OPTIMIZE	= 
LDFLAGS			= $(LDFLAGS_OPTIMIZE)  -Wl,--export-dynamic 

CC_SWITCHES = $(CFLAGS) -I${SRC_DIR}/../../generic \
	${SHLIB_CFLAGS} -DUSE_TCL_STUBS ${AC_FLAGS}

all: embtest tcl9pkga${SHLIB_SUFFIX} tcl9pkgb${SHLIB_SUFFIX} tcl9pkgc${SHLIB_SUFFIX} \
	tcl9pkgd${SHLIB_SUFFIX} tcl9pkge${SHLIB_SUFFIX} tcl9pkgt${SHLIB_SUFFIX} tcl9pkgua${SHLIB_SUFFIX} \
	tcl9pkgooa${SHLIB_SUFFIX} pkga${SHLIB_SUFFIX} pkgb${SHLIB_SUFFIX} pkgc${SHLIB_SUFFIX}  pkgt${SHLIB_SUFFIX}
	@if test -n "$(DLTEST_SUFFIX)"; then $(MAKE) dltest_suffix; fi
	@touch ../dltest.marker

dltest_suffix: tcl9pkga${DLTEST_SUFFIX} tcl9pkgb${DLTEST_SUFFIX} tcl9pkgc${DLTEST_SUFFIX} \
	tcl9pkgd${DLTEST_SUFFIX} tcl9pkge${DLTEST_SUFFIX} tcl9pkgt${DLTEST_SUFFIX} tcl9pkgua${DLTEST_SUFFIX} \
	tcl9pkgooa${DLTEST_SUFFIX} pkga${DLTEST_SUFFIX} pkgb${DLTEST_SUFFIX} pkgc${DLTEST_SUFFIX} pkgt${DLTEST_SUFFIX}
	@touch ../dltest.marker

embtest.o: $(SRC_DIR)/embtest.c
	$(CC) -c $(CC_SWITCHES) $(SRC_DIR)/embtest.c

pkgπ.o: $(SRC_DIR)/pkgπ.c
	$(CC) -c $(CC_SWITCHES) $(SRC_DIR)/pkgπ.c

pkga.o: $(SRC_DIR)/pkga.c
	$(CC) -c $(CC_SWITCHES) $(SRC_DIR)/pkga.c

pkgb.o: $(SRC_DIR)/pkgb.c
	$(CC) -c $(CC_SWITCHES) $(SRC_DIR)/pkgb.c

pkgc.o: $(SRC_DIR)/pkgc.c
	$(CC) -c $(CC_SWITCHES) $(SRC_DIR)/pkgc.c

pkgt.o: $(SRC_DIR)/pkgt.c
	$(CC) -c $(CC_SWITCHES) $(SRC_DIR)/pkgt.c

tcl8pkga.o: $(SRC_DIR)/pkga.c
	$(CC) -o $@ -c $(CC_SWITCHES) -DTCL_MAJOR_VERSION=8 $(SRC_DIR)/pkga.c

tcl8pkgb.o: $(SRC_DIR)/pkgb.c
	$(CC) -o $@ -c $(CC_SWITCHES) -DTCL_MAJOR_VERSION=8 $(SRC_DIR)/pkgb.c

tcl8pkgc.o: $(SRC_DIR)/pkgc.c
	$(CC) -o $@ -c $(CC_SWITCHES) -DTCL_MAJOR_VERSION=8 $(SRC_DIR)/pkgc.c

tcl8pkgt.o: $(SRC_DIR)/pkgt.c
	$(CC) -o $@ -c $(CC_SWITCHES) -DTCL_MAJOR_VERSION=8 $(SRC_DIR)/pkgt.c

pkgd.o: $(SRC_DIR)/pkgd.c
	$(CC) -c $(CC_SWITCHES) $(SRC_DIR)/pkgd.c

pkge.o: $(SRC_DIR)/pkge.c
	$(CC) -c $(CC_SWITCHES) $(SRC_DIR)/pkge.c

pkgua.o: $(SRC_DIR)/pkgua.c
	$(CC) -c $(CC_SWITCHES) $(SRC_DIR)/pkgua.c

pkgooa.o: $(SRC_DIR)/pkgooa.c
	$(CC) -c $(CC_SWITCHES) $(SRC_DIR)/pkgooa.c

embtest: embtest.o
	$(CC) $(CC_SWITCHES) -o $@ embtest.o ${SHLIB_LD_LIBS}

tcl9pkgπ${SHLIB_SUFFIX}: pkgπ.o
	${SHLIB_LD} -o $@ pkgπ.o ${SHLIB_LD_LIBS}

tcl9pkga${SHLIB_SUFFIX}: pkga.o
	${SHLIB_LD} -o $@ pkga.o ${SHLIB_LD_LIBS}

tcl9pkgb${SHLIB_SUFFIX}: pkgb.o
	${SHLIB_LD} -o $@ pkgb.o ${SHLIB_LD_LIBS}

tcl9pkgc${SHLIB_SUFFIX}: pkgc.o
	${SHLIB_LD} -o $@ pkgc.o ${SHLIB_LD_LIBS}

tcl9pkgt${SHLIB_SUFFIX}: pkgt.o
	${SHLIB_LD} -o $@ pkgt.o ${SHLIB_LD_LIBS}

pkga${SHLIB_SUFFIX}: tcl8pkga.o
	${SHLIB_LD} -o $@ tcl8pkga.o ${SHLIB_LD_LIBS}

pkgb${SHLIB_SUFFIX}: tcl8pkgb.o
	${SHLIB_LD} -o $@ tcl8pkgb.o ${SHLIB_LD_LIBS}

pkgc${SHLIB_SUFFIX}: tcl8pkgc.o
	${SHLIB_LD} -o $@ tcl8pkgc.o ${SHLIB_LD_LIBS}

pkgt${SHLIB_SUFFIX}: tcl8pkgt.o
	${SHLIB_LD} -o $@ tcl8pkgt.o ${SHLIB_LD_LIBS}

tcl9pkgd${SHLIB_SUFFIX}: pkgd.o
	${SHLIB_LD} -o $@ pkgd.o ${SHLIB_LD_LIBS}

tcl9pkge${SHLIB_SUFFIX}: pkge.o
	${SHLIB_LD} -o $@ pkge.o ${SHLIB_LD_LIBS}

tcl9pkgua${SHLIB_SUFFIX}: pkgua.o
	${SHLIB_LD} -o $@ pkgua.o ${SHLIB_LD_LIBS}

tcl9pkgooa${SHLIB_SUFFIX}: pkgooa.o
	${SHLIB_LD} -o $@ pkgooa.o ${SHLIB_LD_LIBS}

tcl9pkgπ${DLTEST_SUFFIX}: pkgπ.o
	${DLTEST_LD} -o $@ pkgπ.o ${SHLIB_LD_LIBS}

tcl9pkga${DLTEST_SUFFIX}: pkga.o
	${DLTEST_LD} -o $@ pkga.o ${SHLIB_LD_LIBS}

tcl9pkgb${DLTEST_SUFFIX}: pkgb.o
	${DLTEST_LD} -o $@ pkgb.o ${SHLIB_LD_LIBS}

tcl9pkgc${DLTEST_SUFFIX}: pkgc.o
	${DLTEST_LD} -o $@ pkgc.o ${SHLIB_LD_LIBS}

tcl9pkgt${DLTEST_SUFFIX}: pkgt.o
	${DLTEST_LD} -o $@ pkgt.o ${SHLIB_LD_LIBS}

pkga${DLTEST_SUFFIX}: tcl8pkga.o
	${DLTEST_LD} -o $@ tcl8pkga.o ${SHLIB_LD_LIBS}

pkgb${DLTEST_SUFFIX}: tcl8pkgb.o
	${DLTEST_LD} -o $@ tcl8pkgb.o ${SHLIB_LD_LIBS}

pkgc${DLTEST_SUFFIX}: tcl8pkgc.o
	${DLTEST_LD} -o $@ tcl8pkgc.o ${SHLIB_LD_LIBS}

pkgt${DLTEST_SUFFIX}: tcl8pkgt.o
	${DLTEST_LD} -o $@ tcl8pkgt.o ${SHLIB_LD_LIBS}

tcl9pkgd${DLTEST_SUFFIX}: pkgd.o
	${DLTEST_LD} -o $@ pkgd.o ${SHLIB_LD_LIBS}

tcl9pkge${DLTEST_SUFFIX}: pkge.o
	${DLTEST_LD} -o $@ pkge.o ${SHLIB_LD_LIBS}

tcl9pkgua${DLTEST_SUFFIX}: pkgua.o
	${DLTEST_LD} -o $@ pkgua.o ${SHLIB_LD_LIBS}

tcl9pkgooa${DLTEST_SUFFIX}: pkgooa.o
	${DLTEST_LD} -o $@ pkgooa.o ${SHLIB_LD_LIBS}

clean:
	rm -f embtest *.o lib.exp ../dltest.marker
	@if test "$(SHLIB_SUFFIX)" != ""; then \
	    echo "rm -f *${SHLIB_SUFFIX}" ; \
	    rm -f *${SHLIB_SUFFIX} ; \
	fi
	@if test "$(DLTEST_SUFFIX)" != ""; then \
	    echo "rm -f *${DLTEST_SUFFIX}" ; \
	    rm -f *${DLTEST_SUFFIX} ; \
	fi

distclean: clean
	rm -f Makefile
