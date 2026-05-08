/* iostream.h — C++ stream I/O for cfront.
 * Adapted from AT&T C++ Language System 3.0.3.
 * #pragma lib updated for APExp install layout. */
#ifndef IOSTREAMH
#define IOSTREAMH

#pragma lib "ape/libc++.a"

#include <stddef.h>
#include <stdarg.h>

#ifdef EOF
#  if EOF != -1
#    undef EOF
#    define EOF (-1)
#  endif
#else
#  define EOF (-1)
#endif

#ifndef NULL
#  define NULL 0
#endif

#define zapeof(c) ((c)&0377)

typedef long streampos;
typedef long streamoff;

class streambuf;
class ostream;

class ios {
public:
    enum io_state   { goodbit=0, eofbit=1, failbit=2, badbit=4, hardfail=0200 };
    enum open_mode  { in=1, out=2, ate=4, app=010, trunc=020,
                      nocreate=040, noreplace=0100 };
    enum seek_dir   { beg=0, cur=1, end=2 };
    enum            { skipws=01,
                      left=02, right=04, internal=010,
                      dec=020, oct=040, hex=0100,
                      showbase=0200, showpoint=0400, uppercase=01000,
                      showpos=02000,
                      scientific=04000, fixed=010000,
                      unitbuf=020000, stdio=040000 };

    static const long basefield;
    static const long adjustfield;
    static const long floatfield;

public:
                ios(streambuf*);
    virtual     ~ios();

    long        flags() const           { return x_flags; }
    long        flags(long f);
    long        setf(long setbits, long field);
    long        setf(long);
    long        unsetf(long);

    int         width() const           { return x_width; }
    int         width(int w)            { int i=x_width; x_width=w; return i; }

    ostream*    tie(ostream* s);
    ostream*    tie()                   { return x_tie; }
    char        fill(char);
    char        fill() const            { return x_fill; }
    int         precision(int);
    int         precision() const       { return x_precision; }

    int         rdstate() const         { return state; }
                operator void*() {
                    void* r;
                    if (state&(failbit|badbit|hardfail)) r=0; else r=this;
                    return r;
                }
                operator const void*() const {
                    const void* r;
                    if (state&(failbit|badbit|hardfail)) r=0; else r=this;
                    return r;
                }
    int         operator!() const { return state&(failbit|badbit|hardfail); }
    int         eof()  const      { return state&eofbit; }
    int         fail() const      { return state&(failbit|badbit|hardfail); }
    int         bad()  const      { return state&badbit; }
    int         good() const      { return state==0; }
    void        clear(int i=0) {
                    state = (i&0377)|(state&hardfail);
                    ispecial = (ispecial&~0377)|state;
                    ospecial = (ospecial&~0377)|state;
                }
    streambuf*  rdbuf() { return bp; }

    long&       iword(size_t);
    void*&      pword(size_t);
    static long bitalloc();
    static int  xalloc();

    static void sync_with_stdio();
    int         skip(int i);

protected:
    enum        { skipping=01000, tied=02000 };
    streambuf*  bp;
    void        setstate(int b) {
                    state |= (b&0377);
                    ispecial |= b&~skipping;
                    ispecial |= b;
                }
    int         state;
    int         ispecial;
    int         ospecial;
    int         isfx_special;
    int         osfx_special;
    int         delbuf;
    ostream*    x_tie;
    long        x_flags;
    short       x_precision;
    char        x_fill;
    short       x_width;
    static void (*stdioflush)();
    void        init(streambuf*);
                ios();
    int         assign_private;

public:
                ios(ios&);
    void        operator=(ios&);

private:
    static long nextbit;
    static long nextword;
    size_t      nuser;
    union ios_user_union* x_user;
    void        uresize(size_t);
};

class streambuf {
    short       alloc;
    short       x_unbuf;
    char*       x_base;
    char*       x_pbase;
    char*       x_pptr;
    char*       x_epptr;
    char*       x_gptr;
    char*       x_egptr;
    char*       x_eback;
    size_t      x_blen;
private:
                streambuf(streambuf&);
    void        operator=(streambuf&);
public:
    void        dbp();
protected:
    char*       base()   { return x_base; }
    char*       pbase()  { return x_pbase; }
    char*       pptr()   { return x_pptr; }
    char*       epptr()  { return x_epptr; }
    char*       gptr()   { return x_gptr; }
    char*       egptr()  { return x_egptr; }
    char*       eback()  { return x_eback; }
    char*       ebuf()   { return x_base+x_blen; }
    size_t      blen() const { return x_blen; }
    void        setp(char* p, char* ep) { x_pbase=x_pptr=p; x_epptr=ep; }
    void        setg(char* eb, char* g, char* eg) { x_eback=eb; x_gptr=g; x_egptr=eg; }
    void        pbump(size_t n) { x_pptr+=n; }
    void        gbump(size_t n) { x_gptr+=n; }
    void        setb(char* b, char* eb, int a=0) {
                    if (alloc && x_base) delete x_base;
                    x_base=b; x_blen=(eb>b)?(eb-b):0; alloc=a;
                }
    int         unbuffered() const      { return x_unbuf; }
    void        unbuffered(int unb)     { x_unbuf=(unb!=0); }
    int         allocate() {
                    int r;
                    if (x_base==0 && !unbuffered()) r=doallocate(); else r=0;
                    return r;
                }
    virtual int doallocate();
public:
    virtual int overflow(int c=EOF);
    virtual int underflow();
    virtual int pbackfail(int c);
    virtual int sync();
    virtual streampos seekoff(streamoff, ios::seek_dir, int=ios::in|ios::out);
    virtual streampos seekpos(streampos, int=ios::in|ios::out);
    virtual int xsputn(const char* s, int n);
    virtual int xsgetn(char* s, int n);

    int  in_avail()   { return x_gptr<x_egptr ? x_egptr-x_gptr : 0; }
    int  out_waiting() { int r; if (x_pptr) r=x_pptr-x_pbase; else r=0; return r; }
    int  sgetc()      { return (x_gptr>=x_egptr) ? underflow() : zapeof(*x_gptr); }
    int  snextc()     { return (++x_gptr>=x_egptr) ? x_snextc() : zapeof(*x_gptr); }
    int  sbumpc()     { return (x_gptr>=x_egptr && underflow()==EOF) ? EOF : zapeof(*x_gptr++); }

    int  sputbackc(char c);
    int  sungetc();
    int  sputc(int c) { return (x_pptr>=x_epptr) ? overflow(zapeof(c)) : zapeof(*x_pptr++=c); }
    int  sputn(const char* s, int n)   { return xsputn(s,n); }
    int  sgetn(char* s, int n)         { return xsgetn(s,n); }
    int  passthroughput();
    int  x_snextc();

                streambuf();
                streambuf(char* p, int l);
    virtual     ~streambuf();
    virtual streambuf* setbuf(char* p, int len);
    streampos   seekoff(streamoff o, int w, int m=ios::in|ios::out) {
                    return seekoff(o,(ios::seek_dir)w,m);
                }
    void        stossc()     { if (x_gptr<x_egptr) ++x_gptr; else underflow(); }
    int         optim_in_avail() { return x_gptr<x_egptr; }
    static void    flush_all();
    static void    _flush_all();
};

class ostream : virtual public ios {
public:
                ostream(streambuf*);
    virtual     ~ostream();

    ostream&    operator<<(char c);
    ostream&    operator<<(unsigned char c) { return (*this)<<(char)c; }
    ostream&    operator<<(signed char c)   { return (*this)<<(char)c; }
    ostream&    operator<<(const char* s);
    ostream&    operator<<(const unsigned char* s)
                    { return (*this)<<(const char*)s; }
    ostream&    operator<<(const signed char* s)
                    { return (*this)<<(const char*)s; }
    ostream&    operator<<(int n);
    ostream&    operator<<(unsigned int n);
    ostream&    operator<<(long n);
    ostream&    operator<<(unsigned long n);
    ostream&    operator<<(short n)          { return (*this)<<(int)n; }
    ostream&    operator<<(unsigned short n) { return (*this)<<(unsigned int)n; }
    ostream&    operator<<(double n);
    ostream&    operator<<(float n)          { return (*this)<<(double)n; }
    ostream&    operator<<(long double n);
    ostream&    operator<<(const void* p);
    ostream&    operator<<(streambuf*);

    ostream&    put(char c);
    ostream&    write(const char* s, int n);
    ostream&    write(const unsigned char* s, int n)
                    { return write((const char*)s, n); }
    ostream&    flush();
    ostream&    seekp(streampos);
    ostream&    seekp(streamoff, ios::seek_dir);
    streampos   tellp();

    ostream&    operator<<(ostream& (*f)(ostream&)) { return (*f)(*this); }
    ostream&    operator<<(ios& (*f)(ios&))          { (*f)(*this); return *this; }

protected:
                ostream();
    int         do_osfx();
};

class istream : virtual public ios {
public:
                istream(streambuf*);
    virtual     ~istream();

    istream&    operator>>(char& c);
    istream&    operator>>(unsigned char& c);
    istream&    operator>>(signed char& c) { return (*this)>>(char&)c; }
    istream&    operator>>(char* s);
    istream&    operator>>(unsigned char* s) { return (*this)>>(char*)s; }
    istream&    operator>>(signed char* s)   { return (*this)>>(char*)s; }
    istream&    operator>>(int& n);
    istream&    operator>>(unsigned int& n);
    istream&    operator>>(long& n);
    istream&    operator>>(unsigned long& n);
    istream&    operator>>(short& n);
    istream&    operator>>(unsigned short& n);
    istream&    operator>>(double& n);
    istream&    operator>>(float& n);
    istream&    operator>>(long double& n);
    istream&    operator>>(streambuf*);

    istream&    get(char& c);
    istream&    get(unsigned char& c);
    istream&    get(char* s, int n, char delim='\n');
    istream&    get(unsigned char* s, int n, char delim='\n')
                    { return get((char*)s,n,delim); }
    istream&    get(streambuf& sb, char delim='\n');
    istream&    getline(char* s, int n, char delim='\n');
    istream&    getline(unsigned char* s, int n, char delim='\n')
                    { return getline((char*)s,n,delim); }
    int         get();
    istream&    ignore(int n=1, int delim=EOF);
    istream&    read(char* s, int n);
    istream&    read(unsigned char* s, int n) { return read((char*)s,n); }
    int         peek();
    int         gcount()  const        { return x_gcount; }
    istream&    putback(char c);
    istream&    seekg(streampos);
    istream&    seekg(streamoff, ios::seek_dir);
    streampos   tellg();
    int         sync();

    istream&    operator>>(istream& (*f)(istream&)) { return (*f)(*this); }
    istream&    operator>>(ios& (*f)(ios&))          { (*f)(*this); return *this; }

protected:
                istream();
    int         x_gcount;
    int         do_ipfx(int);
};

class iostream : public istream, public ostream {
public:
                iostream(streambuf*);
    virtual     ~iostream();
protected:
                iostream();
};

/* withassign variants (used for cin/cout/cerr) */
class ostream_withassign : public ostream {
public:
                ostream_withassign();
                ~ostream_withassign();
    ostream_withassign& operator=(ios& s);
    ostream_withassign& operator=(streambuf* sb);
};

class istream_withassign : public istream {
public:
                istream_withassign();
                ~istream_withassign();
    istream_withassign& operator=(ios& s);
    istream_withassign& operator=(streambuf* sb);
};

class iostream_withassign : public iostream {
public:
                iostream_withassign();
                ~iostream_withassign();
    iostream_withassign& operator=(ios& s);
    iostream_withassign& operator=(streambuf* sb);
};

extern istream_withassign  cin;
extern ostream_withassign  cout;
extern ostream_withassign  cerr;
extern ostream_withassign  clog;

/* Manipulators */
extern ostream& endl(ostream&);
extern ostream& ends(ostream&);
extern ostream& flush(ostream&);
extern istream& ws(istream&);

extern ios&     dec(ios&);
extern ios&     hex(ios&);
extern ios&     oct(ios&);

/* Old-style stream compatibility */
typedef istream istream_withassign;

#endif
