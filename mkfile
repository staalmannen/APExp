</$objtype/mkfile

APEXPROOT=.

DIRS= \
		sys/src/cmd\
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
# architecture directories. Those hold only build output -- `git
# ls-files amd64` is `amd64/include/ape` and nothing else, and
# .gitignore lists `*/bin/*` and `*/lib/*` -- so removing the two trees
# outright is safe, and `install` recreates them with its own mkdir -p.
#
# WHY IT USED TO STOP. Three separate things, and the middle one is the
# one that mattered:
#
#   - `rm` without -f fails on a name that is not there, and mk stops on
#     a non-zero exit. rc also leaves an unmatched glob ALONE rather
#     than expanding it to nothing, so `rm $j/lib/ape/*` on an arch that
#     was never built handed rm the literal `*` and failed on the first
#     one of the eleven.
#   - the second rm said `$i`, not `$j`. `$i` still held its value from
#     the loop ABOVE, so it read `rm sys/src/ape/cmd/bin/ape/*` --
#     eleven times, at a path in the SOURCE tree. It only ever errored
#     because that directory does not exist; the day something creates
#     one, a distclean would empty it.
#   - `$objtype/bin` was never cleaned at all, only `bin/ape`.
#
# The loop is over $_ARCHS, a literal list in this file, so the path can
# never come out as `/bin` however the variables are set -- which is the
# property that makes this safer than nuke rather than the -f. The `./`
# is the same idea said twice: with an empty $j it is `./bin`, which is
# not a directory here, and never `/bin`.
#
distclean:V:
	for (i in $DIRS)
		@{ cd $i; mk clean }
	for (j in $_ARCHS)
		@{ rm -rf ./$j/bin ./$j/lib }

nuke:V:
	for (i in $DIRS)
		@{ cd $i; mk $target }

