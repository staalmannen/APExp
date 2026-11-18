</$objtype/mkfile

APEXPROOT=.

#
# ORDER IS LOAD-BEARING AT THE END OF THIS LIST.  `sys/src/ape/c++'
# holds what needs a C++ compiler, so it must come after
# `sys/src/ape/lib' (which builds libedg.a) and after
# `sys/src/ape/cmd' (which builds cpfe).  Nothing in it is enabled
# yet -- its own `DIRS' is empty and says why -- so it is in the list
# before its first port rather than with it: *a dispatcher added in
# the same round as the thing it dispatches leaves neither
# attributable.*
#
DIRS= \
		sys/src/cmd\
		sys/src/lib\
		sys/src/cmd2\
		sys/src/ape/9src\
		sys/src/ape/lib\
		sys/src/ape/cmd\
		sys/src/ape/c++

_ARCHS=	386\
		68020\
		amd64\
		arm\
		arm64\
		mips\
		power\
		power64\
		sparc\
		sparc64\
		spim

all:V:

install:V:
	rm -f $objtype/lib/ape/*
	for (i in $_ARCHS)
		@{ mkdir -p $i/lib/ape/ ; mkdir -p $i/bin/ape }
	rfork n
		chmod +x mount-include
		./mount-include
		for (i in $DIRS)
			@{ cd $i; mk $target }

# build and install only the libraries
# this is especially interesting when setting up
# a cross compiler with APExp where you don't need.
# all the binaries that cannot be executed on the host.
#
lib:V:
	mk -f sys/src/lib/mkfile install
	mk -f sys/src/ape/lib/mkfile install

all-lib:V:
	for (i in $_ARCHS)
		@{ echo "\n compiling architecture=$i \n" ; objtype=$i mk lib }

clean:V:
	for (i in $DIRS)
		@{ cd $i; mk $target }

#
# distclean: mk clean, plus everything the build installs into the
# architecture directories.
#
distclean:V:
	for (i in $DIRS)
		@{ cd $i; mk clean }
	for (j in $_ARCHS)
		for (k in bin lib)
			if (test -d ./$j/$k) @{
				cd ./$j/$k
				for (f in *)
					if (! ~ $f ape)
						rm -rf $f
				if (test -d ape) @{
					cd ape
					for (g in *)
						rm -rf $g
				}
			}

nuke:V:
	for (i in $DIRS)
		@{ cd $i; mk $target }

