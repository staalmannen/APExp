#!/usr/bin/env bash

if [[ $# -eq 0 ]]
then
    echo "Provide location of the original BaCon tar.gz package!"
    exit
fi

rm -rf SPECS
mkdir SPECS

rm -rf BUILD
mkdir BUILD

rm -rf BUILDROOT
mkdir BUILDROOT

rm -rf RPMS
mkdir RPMS

rm -rf SOURCES
mkdir SOURCES

rm -rf SRPMS
mkdir SRPMS

cp ./bacon.spec SPECS
cp ${1} SOURCES

cd SPECS
rpmbuild --define "_topdir ${PWD}/.." -bb bacon.spec
