/* string.h — basic string class for cfront-compiled C++ programs.
 * Self-contained: implementation is fully inline so no separate .cpp needed.
 * Also declares C string functions via extern "C" for convenience. */
#ifndef __STRING_H
#define __STRING_H

#pragma lib "ape/libc++.a"

#include <stddef.h>

extern "C" {
    size_t strlen(const char*);
    char*  strcpy(char*, const char*);
    char*  strncpy(char*, const char*, size_t);
    char*  strcat(char*, const char*);
    int    strcmp(const char*, const char*);
    int    strncmp(const char*, const char*, size_t);
    char*  strchr(const char*, int);
    char*  strrchr(const char*, int);
    char*  strstr(const char*, const char*);
    void*  memcpy(void*, const void*, size_t);
    void*  memmove(void*, const void*, size_t);
    void*  memset(void*, int, size_t);
    int    memcmp(const void*, const void*, size_t);
}

class string {
    char*  _p;
    size_t _n;
    size_t _cap;

    void _reserve(size_t n) {
        if (n <= _cap) return;
        size_t nc = _cap ? _cap + (_cap >> 1) + 1 : 16;
        while (nc < n) nc += nc >> 1;
        char* np = new char[nc + 1];
        if (_p) { memcpy(np, _p, _n); delete[] _p; }
        np[_n] = '\0'; _p = np; _cap = nc;
    }

    void _init(const char* s, size_t n) {
        _p = 0; _n = 0; _cap = 0;
        if (n) {
            _p = new char[n + 1];
            memcpy(_p, s, n); _p[n] = '\0';
            _n = _cap = n;
        }
    }

public:
    static const size_t npos;  /* = (size_t)-1 */

    string() : _p(0), _n(0), _cap(0) {}

    string(const char* s) : _p(0), _n(0), _cap(0) {
        if (s) _init(s, strlen(s));
    }

    string(const char* s, size_t n) : _p(0), _n(0), _cap(0) {
        if (s && n) _init(s, n);
    }

    string(size_t n, char c) : _p(0), _n(0), _cap(0) {
        if (n) {
            _p = new char[n + 1];
            memset(_p, c, n); _p[n] = '\0';
            _n = _cap = n;
        }
    }

    string(const string& s) : _p(0), _n(0), _cap(0) {
        if (s._n) _init(s._p, s._n);
    }

    ~string() { delete[] _p; }

    string& operator=(const string& s) {
        if (this != &s) { delete[] _p; _p=0; _n=_cap=0; if (s._n) _init(s._p,s._n); }
        return *this;
    }

    string& operator=(const char* s) {
        delete[] _p; _p=0; _n=_cap=0;
        if (s) _init(s, strlen(s));
        return *this;
    }

    /* Iterators — range-for over chars */
    char*       begin()       { return _p; }
    const char* begin() const { return _p ? _p : ""; }
    char*       end()         { return _p + _n; }
    const char* end()   const { return _p + _n; }

    /* Capacity */
    size_t size()     const { return _n; }
    size_t length()   const { return _n; }
    size_t capacity() const { return _cap; }
    int    empty()    const { return _n == 0; }

    void reserve(size_t n) { _reserve(n); }

    void resize(size_t n, char c = '\0') {
        if (n > _n) {
            _reserve(n);
            memset(_p + _n, c, n - _n);
        }
        _n = n;
        if (_p) _p[_n] = '\0';
    }

    /* Access */
    char&       operator[](size_t i)       { return _p[i]; }
    const char& operator[](size_t i) const { return _p[i]; }
    char&       at(size_t i)               { return _p[i]; }
    const char& at(size_t i)         const { return _p[i]; }
    char&       front()                    { return _p[0]; }
    const char& front()              const { return _p[0]; }
    char&       back()                     { return _p[_n-1]; }
    const char& back()               const { return _p[_n-1]; }
    const char* c_str() const { return _p ? _p : ""; }
    const char* data()  const { return _p; }

    /* Modifiers */
    string& operator+=(const string& s) {
        size_t nn = _n + s._n;
        _reserve(nn);
        memcpy(_p + _n, s._p, s._n); _n = nn; _p[_n] = '\0';
        return *this;
    }

    string& operator+=(const char* s) {
        if (!s) return *this;
        size_t sn = strlen(s);
        size_t nn = _n + sn;
        _reserve(nn);
        memcpy(_p + _n, s, sn); _n = nn; _p[_n] = '\0';
        return *this;
    }

    string& operator+=(char c) {
        _reserve(_n + 1);
        _p[_n++] = c; _p[_n] = '\0';
        return *this;
    }

    void push_back(char c) { (*this) += c; }

    void clear() {
        _n = 0;
        if (_p) _p[0] = '\0';
    }

    string& append(const string& s) { return (*this) += s; }
    string& append(const char* s)   { return (*this) += s; }
    string& append(const char* s, size_t n) {
        _reserve(_n + n);
        memcpy(_p + _n, s, n); _n += n; _p[_n] = '\0';
        return *this;
    }
    string& append(size_t n, char c) {
        _reserve(_n + n);
        memset(_p + _n, c, n); _n += n; _p[_n] = '\0';
        return *this;
    }

    /* Search */
    size_t find(const string& s, size_t pos=0) const {
        return find(s._p, pos, s._n);
    }
    size_t find(const char* s, size_t pos=0) const {
        return find(s, pos, s ? strlen(s) : 0);
    }
    size_t find(const char* s, size_t pos, size_t n) const {
        if (!_p || !s || pos > _n) return npos;
        for (size_t i=pos; i+n<=_n; i++)
            if (memcmp(_p+i, s, n)==0) return i;
        return npos;
    }
    size_t find(char c, size_t pos=0) const {
        for (size_t i=pos; i<_n; i++)
            if (_p[i]==c) return i;
        return npos;
    }

    size_t rfind(char c, size_t pos=npos) const {
        size_t i = (pos==npos || pos>=_n) ? _n : pos+1;
        while (i--) if (_p[i]==c) return i;
        return npos;
    }

    /* Substring */
    string substr(size_t pos=0, size_t len=npos) const {
        if (pos > _n) return string();
        size_t n = (len==npos || pos+len>_n) ? _n-pos : len;
        return string(_p+pos, n);
    }

    /* Comparison */
    int compare(const string& s) const {
        int r = memcmp(_p ? _p : "", s._p ? s._p : "", _n<s._n ? _n : s._n);
        if (r) return r;
        return (_n<s._n) ? -1 : (_n>s._n) ? 1 : 0;
    }
    int compare(const char* s) const {
        if (!s) return _n ? 1 : 0;
        return strcmp(_p ? _p : "", s);
    }
};

/* string global operators */
inline string operator+(const string& a, const string& b)
    { string r=a; r+=b; return r; }
inline string operator+(const string& a, const char* b)
    { string r=a; r+=b; return r; }
inline string operator+(const char* a, const string& b)
    { string r=a; r+=b; return r; }
inline string operator+(const string& a, char c)
    { string r=a; r+=c; return r; }

inline int operator==(const string& a, const string& b) { return a.compare(b)==0; }
inline int operator!=(const string& a, const string& b) { return a.compare(b)!=0; }
inline int operator< (const string& a, const string& b) { return a.compare(b)< 0; }
inline int operator> (const string& a, const string& b) { return a.compare(b)> 0; }
inline int operator<=(const string& a, const string& b) { return a.compare(b)<=0; }
inline int operator>=(const string& a, const string& b) { return a.compare(b)>=0; }

inline int operator==(const string& a, const char* b) { return a.compare(b)==0; }
inline int operator!=(const string& a, const char* b) { return a.compare(b)!=0; }
inline int operator==(const char* a, const string& b) { return b.compare(a)==0; }
inline int operator!=(const char* a, const string& b) { return b.compare(a)!=0; }

/* Stream I/O */
#ifdef IOSTREAMH
extern ostream& operator<<(ostream&, const string&);
extern istream& operator>>(istream&, string&);
extern istream& getline(istream&, string&, char delim='\n');
#endif

/* npos defined in string.cpp */

#endif
