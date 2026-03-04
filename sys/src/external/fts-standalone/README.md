# fts-standalone

Standalone library for fts functions.

From `man 3 fts`: The fts functions are provided for traversing file
hierarchies.  A simple overview is that the fts_open() function returns
a "handle" on a file hierarchy, which is then supplied to the other fts
functions.  The function fts_read() returns a pointer to a structure
describing one of the files in the file hierarchy.  The function
fts_children() returns a pointer to a linked list of structures,  each
of which describes one of the files contained in a directory in the
hierarchy.  fts conforms to 4.4BSD.

fts is usually provided by the system's libc, as glibc and uClibc do.
However, musl does not and hence the need for a standalone version.
This code was adopted from OpenBSD 5.7 and modified slightly to build
in Linux.  

Maintainer: Anthony G. Basile <blueness@gentoo.org>

## Build Status
[![Status](https://travis-ci.org/blueness/fts-standalone.png)](https://travis-ci.org/blueness/fts-standalone)
