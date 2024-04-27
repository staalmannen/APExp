</$objtype/mkfile
DIRS=doc 

all:V:
	mk -f mkfile.libpcre
	mk -f mkfile.libpcreposix
	mk -f mkfile.pcregrep
	mv $O.out $O.pcregrep
	mk -f mkfile.pcretest
	for (i in $DIRS)
		@{ cd $i; mk }

install:V:
	mk -f mkfile.libpcre $target
	mk -f mkfile.libpcreposix $target
	mk -f mkfile.pcregrep $target
	mv $O.out $O.pcregrep
	mk -f mkfile.pcretest $target
	for (i in $DIRS)
		@{ cd $i; mk $target }
	mkdir -p /$objtype/lib/ape/pkgconfig
	cp libpcre.pc  /$objtype/lib/ape/pkgconfig/
	cp libpcreposix.pc  /$objtype/lib/ape/pkgconfig/
	chmod +x pcre-config
	cp pcre-config /rc/bin/ape

clean:V:
	mk -f mkfile.libpcre $target
	mk -f mkfile.libpcreposix $target
	mk -f mkfile.pcregrep $target
	rm -f $O.pcregrep
	mk -f mkfile.pcretest $target
	for (i in $DIRS)
		@{ cd $i; mk $target }

nuke:V:
	mk -f mkfile.libpcre $target
	mk -f mkfile.libpcreposix $target
	mk -f mkfile.pcregrep $target
	rm -f $O.pcregrep
	mk -f mkfile.pcretest $target
	for (i in $DIRS)
		@{ cd $i; mk $target }
	rm -f /$objtype/lib/ape/pkgconfig/libpcre.pc
	rm -f /$objtype/lib/ape/pkgconfig/libpcreposix.pc
	rm -f /rc/bin/ape/pcre-config

