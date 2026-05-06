# Makefile for cfront-C4  (Linux / macOS development builds)
# For Plan9/APExp, use the mkfile at the repo root instead.
#
# Targets:
#   all      — build cfront binary
#   libC.a   — build cfront runtime library (requires cfront in PATH or CC set)
#   demo     — build and run hello/stream/generic demos
#   clean    — remove build artifacts

MSIZE =
CC    = cc
CCOMP = cc

# C++ compiler used to build the runtime library.
# Override with: make CXX=g++ libC.a
# or with a cfront wrapper: make CXX="./tools/cfront-cc-wrapper" libC.a
CXX   = g++

.PHONY: all libC.a demo clean always

all: cfront

cfront: always
	$(MAKE) CC="$(CCOMP)" MSIZE="$(MSIZE)" -C src

libC.a: cfront
	$(MAKE) CC="$(CXX)" CCOMP="$(CCOMP)" MSIZE="$(MSIZE)" -C lib/mk
	cp lib/mk/libC.a .

demo: cfront
	$(MAKE) MSIZE="$(MSIZE)" -C demo/hello
	$(MAKE) MSIZE="$(MSIZE)" -C demo/stream
	$(MAKE) MSIZE="$(MSIZE)" -C demo/generic

always:

clean:
	$(MAKE) -C src clean
	$(MAKE) -C lib/mk clean
	$(MAKE) -C demo/hello clean
	$(MAKE) -C demo/stream clean
	$(MAKE) -C demo/generic clean
	-rm -f libC.a
