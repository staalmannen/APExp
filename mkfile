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

install:V:
	chmod +x mount-include
	./mount-include
	mkdir -p sys/man/1
	mkdir -p sys/man/3
	for (i in $_ARCHS)
		@{ mkdir -p $i/lib/ape/ ; mkdir -p $i/bin/ape }
	for (i in $DIRS)
		@{ cd $i; mk $target }

clean:V:
	for (i in $DIRS)
		@{ cd $i; mk $target }

nuke:V:
	for (i in $DIRS)
		@{ cd $i; mk $target }

