#!/bin/sh
# Portable Object Compiler (c) 2019. All Rights Reserved.
# $Id: build-ips-objclibs.sh,v 1.6 2019/03/25 16:17:34 stes Exp $

case $# in
  2) REPO=$1;TARGET=$2 ;;
  *) echo "Usage: build-ips-objclibs.sh reponame archive.p5p";exit 0;;
esac

if [ -f $TARGET -o -f $TARGET.gz ]
then
  echo "$TARGET already exists";exit 0
fi

#RELOCDIR must have leading / as cwd may - and will - change in the Makefile
RELOCDIR=`pwd`/pkg/reloc
rm -rf $RELOCDIR
mkdir -p $RELOCDIR/usr

./configure OBJCDIR=/usr --prefix=$RELOCDIR/usr EXTRA_MFLAGS="-m32" LIB64NAME="lib"

make clean
make shlib
make installshlib

./configure OBJCDIR=/usr --prefix=$RELOCDIR/usr EXTRA_MFLAGS="-m64 -xcode=pic13" LIB64NAME="lib/amd64"

make clean
make shlib
make installshlib

cp pkg/objclibs.p5m objclibs.p5m.res
pkgsend publish -s $REPO -d $RELOCDIR objclibs.p5m.res
pkgrecv -s $REPO -d $TARGET -a pkg://stes/library/objclibs
gzip $TARGET

