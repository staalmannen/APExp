/* strstream.h — string stream classes for cfront.
 * Adapted from AT&T C++ Language System 3.0.3. */
#ifndef STRSTREAMH
#define STRSTREAMH

#ifndef IOSTREAMH
#include <iostream.h>
#endif

class strstreambuf : public streambuf {
public:
                strstreambuf();
                strstreambuf(size_t);
                strstreambuf(void* (*a)(size_t), void (*f)(void*));
                strstreambuf(char* b, int size, char* pstart=0);
                strstreambuf(unsigned char* b, int size, unsigned char* pstart=0);
    int         pcount();
    void        freeze(int n=1);
    char*       str();
                ~strstreambuf();

    virtual int     doallocate();
    virtual int     overflow(int);
    virtual int     underflow();
    virtual streambuf* setbuf(char* p, int l);
    virtual streampos seekoff(streamoff, ios::seek_dir, int);

    int         isfrozen() { return froozen; }

private:
    void        init(char*, int, char*);
    void*       (*afct)(size_t);
    void        (*ffct)(void*);
    int         ignore_oflow;
    int         froozen;
    size_t      auto_extend;
};

class strstreambase : public virtual ios {
public:
    strstreambuf* rdbuf();
protected:
                strstreambase(char*, int, char*);
                strstreambase();
                ~strstreambase();
private:
    strstreambuf buf;
};

class istrstream : public strstreambase, public istream {
public:
                istrstream(char* str);
                istrstream(char* str, int size);
                istrstream(const char* str);
                istrstream(const char* str, int size);
                ~istrstream();
};

class ostrstream : public strstreambase, public ostream {
public:
                ostrstream(char* str, int size, int=ios::out);
                ostrstream();
                ~ostrstream();
    char*       str();
    int         pcount();
};

class strstream : public strstreambase, public iostream {
public:
                strstream();
                strstream(char* str, int size, int mode);
                ~strstream();
    char*       str();
};

#endif
