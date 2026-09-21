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
distclean:V:
	for (i in $DIRS)
		@{ cd $i; mk clean }
	for (j in $_ARCHS)
		@{ rm -rf ./$j/bin ./$j/lib }

nuke:V:
	for (i in $DIRS)
		@{ cd $i; mk $target }

