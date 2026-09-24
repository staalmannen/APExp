</$objtype/mkfile

APEXPROOT=.

DIRS= \
		sys/src/cmd\
		sys/src/lib\
		sys/src/cmd2\
		sys/src/ape/9src\
		sys/src/ape/lib\
		sys/src/ape/cmd

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

clean:V:
	for (i in $DIRS)
		@{ cd $i; mk $target }

#
# distclean: mk clean, plus everything the build installs into the
# architecture directories.
#
# IT EMPTIES THOSE DIRECTORIES RATHER THAN REMOVING THEM, and that is
# not tidiness -- `apexp-sh' binds two of them:
#
#	bind -b $cputype/bin /bin
#	bind -b $cputype/bin/ape /bin
#
# A bind captures the DIRECTORY'S CHANNEL at bind time. `rm -rf' on it
# destroys the thing that channel names; `mk install' then mkdir's a
# NEW directory with a new qid, and the shell that is still running
# goes on looking at the removed one. Every lookup in that union
# component fails and falls through to the next -- the host's own
# /$objtype/bin.
#
# WHAT THAT LOOKS LIKE, and it looks like anything but a namespace
# problem: the very next native compile runs 9front's STOCK 6c instead
# of the one this tree just built, and dies on
#
#	vterm.h:258 vterm_internal.h:4 encoding.c:1 syntax error,
#	last name: bool
#
# -- `bool' being precisely what APExp's kencc adds and stock kencc has
# not. A library that built yesterday stops building, and nothing in
# the message is about binds.
#
# So: keep ./$j/bin, ./$j/bin/ape, ./$j/lib and ./$j/lib/ape
# themselves, and delete everything in them. `mk install' already does
# exactly this for lib/ape (`rm -f $objtype/lib/ape/*'); distclean was
# the outlier. rm's -f is what makes an unmatched glob silent, so an
# already-empty directory is not an error.
#
# CONFIRMED, and by the cleanest control available: the window was
# killed, a fresh apexp-sh started, and `mk install' run again with NO
# other change -- and it built. Only the namespace differed. So the
# stale bind is the cause rather than a plausible story about one.
#
# THE WORKAROUND IS THAT SAME FRESH apexp-sh, which rebinds whatever
# exists now, and it is worth knowing independently of this rule: any
# `rm -rf' of a bound directory, by any means, leaves a window whose
# /bin is quietly the host's.
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

