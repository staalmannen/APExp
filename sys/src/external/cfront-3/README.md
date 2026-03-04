
cfront v3
=========

This is a project for a self education and historical research of the
C++ compiler. 

A cfront compiler can help to get a concrete understanding how
vtbls, class objects and so on really look like.

Additionally cfront can provide a useful platform to compile historic C++
programs.


PS: a sources was taken from the cfront re-port for the 4th edition of plan9
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

## Notes

Fix the issues of compilation under Ubuntu.

    # Ubuntu package needed:
    sudo apt install byacc

    # Build
    make

    # Demo
    make demo

    # Build itself (bootstrap)
    make cfront_c

    # Clean
    make clean

The extension `.C` was changed to `.cpp` to allow build on operating systems with case insensitive filesystems (OSX, WINDOWS).

I've included the generated parser so you don't need `yacc/byacc` installed to build it.

To build on OSX and Windows under MSYS2 <s>I still need some hack fixes not included here yet</s> (pull requests are wellcome).

It can build itself through valgrind without any invalid memory access (of course it leaks memory as usual for this kind of software and it's epoch).

### Added a github workflow to build on linux for 32/64 bits, cross compile for Windows with mingw64 also native OSX see the output at https://github.com/mingodad/cfront-3/actions for binaries

