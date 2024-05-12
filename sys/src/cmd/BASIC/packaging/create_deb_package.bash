#!/usr/bin/env bash

if [[ $# -eq 0 ]]
then
    echo "Provide version number!"
    exit
fi

cp ../CHANGES doc-pak/changelog
gzip -9 doc-pak/changelog

cp description-pak ..
cp -a doc-pak ..

cd ..
autoconf
./configure --prefix=/usr
make clean
make
sudo checkinstall --install=no --type=debian --pkgname=bacon --pkgversion=$1 --pkgrelease=1 --pkggroup=devel --pkglicense=MIT --maintainer="Peter van Eerten \<peter@basic-converter.org\>" --provides=bacon --requires=enscript,xterm,indent,flex
cd -

rm doc-pak/changelog.gz
rm ../description-pak
rm -r ../doc-pak
