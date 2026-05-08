/* stdiostream.h — stdio-based stream buffer and stream classes.
 * AT&T C++ Language System 3.0 / cfront-C4, adapted for APExp. */
#ifndef _STDIOSTREAM_H
#define _STDIOSTREAM_H

#include <stdio.h>
#include <iostream.h>

class stdiobuf : public streambuf {
public:
    FILE*       fp;
    int         last_op;
    char        buf[1];

    stdiobuf(FILE* f);
    ~stdiobuf();
    int         overflow(int c = EOF);
    int         underflow();
    int         pbackfail(int c);
    int         sync();
    streampos   seekoff(streamoff, ios::seek_dir, int = ios::in|ios::out);
};

class stdiostream : public iostream {
    stdiobuf    buf;
public:
    stdiostream(FILE* f);
    ~stdiostream();
    stdiobuf*   rdbuf();
};

#endif
