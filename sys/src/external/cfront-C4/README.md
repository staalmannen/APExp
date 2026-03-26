
cfront v"C4"
=========

The name "C4" indicate 2 major changes compared to the historical cfront-3 sources. 
The first major difference is that all cfront .cpp source files have been converted
to _readable_ .c files (using claude.ai). This is to avoid the annoying bootstrapping
issues when trying to build cfront on a system that lack a c++ compiler (like Plan9). 
As a general principle should transpilers that target the C language for portability 
also be implemented in C themselves (or offer translated files for an initial build). 
This represents the "C" part of the version name.

The "4" part of the version name represents the ambitions of the project. This is not
a mere historical preservation of the 1994 cfront-3 sources. The aim is to fix bugs 
(the initial C-translated sources also include a patch that should enable cfront on 
(64-bit operating systems, for example) and to expand the C++ compatibility of the 
transpiler. It might never be able to cover all of modern C++, but the ambition is to 
make it more capable than it currently is.

More realistically, cfront can provide a useful platform to compile historic C++
programs.


PS: a copy of cfront-3 sources was taken from github, which in turn were based on the 
cfront re-port for the 4th edition of plan9

    https://github.com/mingodad/cfront-3
    http://plan9.bell-labs.com/sources/extra/c++.2e.tgz
    http://9p.io/sources/contrib/john/package/packages/cfront.iso.bz2
    http://www.quintile.net/plan9/c++/c++src.tbz

PPS: features not implement in cfront 3.x

    Support for the `volatile' keyword.
    Support for the `signed' keyword.
    Support for wide character literals.
    Support for wide character strings.
    Exceptions.
    - Support for the `long long` type (done)



