#!/bin/sh
# Portable Object Compiler (c) 2019. All Rights Reserved.
# $Id: build-ips-objc.sh,v 1.11 2019/03/27 12:07:32 stes Exp $

case $# in
  2) REPO=$1;TARGET=$2 ;;
  *) echo "Usage: build-ips-objc.sh reponame archive.p5p";exit 0;;
esac

if [ -f $TARGET -o -f $TARGET.gz ]
then
  echo "$TARGET already exists";exit 0
fi

#RELOCDIR must have leading / as cwd may - and will - change in the Makefile
RELOCDIR=`pwd`/pkg/reloc

rm -rf $RELOCDIR
mkdir -p $RELOCDIR/usr

# on Solaris we can build a 32bit or 64bit compiler (objc1 executable)
# but in most cases 32bit is sufficient so build for package 32bit 
# but also a 64bit runtime (can be used with -m64 to create ELF64 binaries)
# this means that by default the objc will create ELF32 (unless -m64 is used)

./configure OBJCDIR=/usr --prefix=$RELOCDIR/usr EXTRA_MFLAGS="-m32" LIB64NAME="lib"

make clean
make compiler
make install

./configure OBJCDIR=/usr --prefix=$RELOCDIR/usr EXTRA_MFLAGS="-m64" LIB64NAME="lib/amd64"

make clean
make runtime
make installruntime

cp pkg/objc.p5m objc.p5m.res
pkgsend publish -s $REPO -d $RELOCDIR objc.p5m.res
pkgrecv -s $REPO -d $TARGET -a pkg://stes/developer/objc
gzip $TARGET

