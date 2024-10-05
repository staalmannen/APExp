</$objtype/mkfile

DIRS=	sys/src/cmd\
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


#I noticed something weird where basic libc functions were missing/not linking. A temporary hack is to copy the host libs before building the new ones.

install:V:
	for (i in $_ARCHS)
		@{ mkdir -p $i/lib/ape/ ; mkdir -p $i/bin/ape }
	mkdir -p sys/man/1
	mkdir -p sys/man/3
	cp /$objtype/lib/ape/libap.a $objtype/lib/ape/
	rfork n
		chmod +x mount-include
		./mount-include
		for (i in $DIRS)
			@{ cd $i; mk $target }

clean:V:
	for (i in $DIRS)
		@{ cd $i; mk $target }

nuke:V:
	for (i in $DIRS)
		@{ cd $i; mk $target }

