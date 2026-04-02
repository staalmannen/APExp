#! /bin/sh
sed -n -f configpk.sed < ../configure.ac > tmp.sed
sed -f config.sed < ../configh.in > config.tmp
sed -f tmp.sed < config.tmp > config.h
rm tmp.sed config.tmp
