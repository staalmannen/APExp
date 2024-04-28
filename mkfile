</$objtype/mkfile

DIRS=	sys/src/cmd\
		sys/src/ape/lib\
		sys/src/ape/9src\
		sys/src/ape/cmd

_ARCHS=	386\
		68020\
		amd64\
		arm\
		arm64\
		mips\
		power\
		sparc\
		sparc64\
		spim

all:V:
	for (i in $DIRS)
		@{ cd $i; mk }

install:V:
	for (i in $_ARCHS)
		@{ cp $i/*.h /$i/ }
	dircp sys/include/ape /sys/include/ape
	dircp rc/bin/ape /rc/bin/ape
	for (i in $DIRS)
		@{ cd $i; mk $target }

clean:V:
	for (i in $DIRS)
		@{ cd $i; mk $target }

nuke:V:
	for (i in $DIRS)
		@{ cd $i; mk $target }

