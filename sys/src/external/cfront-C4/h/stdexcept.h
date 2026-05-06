/* stdexcept.h — standard exception classes for cfront-compiled C++ programs.
 * Uses cfront's try/catch/throw support (setjmp/longjmp based). */
#ifndef __STDEXCEPT_H
#define __STDEXCEPT_H

#pragma lib "ape/libc++.a"

extern "C" { size_t strlen(const char*); char* strcpy(char*, const char*); }
#include <new.h>

class exception {
public:
             exception() {}
    virtual ~exception() {}
    virtual const char* what() const { return "exception"; }
};

class logic_error : public exception {
    char* _msg;
public:
    logic_error(const char* msg) {
        size_t n = strlen(msg);
        _msg = new char[n+1]; strcpy(_msg, msg);
    }
    logic_error(const logic_error& e) {
        size_t n = strlen(e._msg);
        _msg = new char[n+1]; strcpy(_msg, e._msg);
    }
    virtual ~logic_error() { delete[] _msg; }
    virtual const char* what() const { return _msg; }
};

class runtime_error : public exception {
    char* _msg;
public:
    runtime_error(const char* msg) {
        size_t n = strlen(msg);
        _msg = new char[n+1]; strcpy(_msg, msg);
    }
    runtime_error(const runtime_error& e) {
        size_t n = strlen(e._msg);
        _msg = new char[n+1]; strcpy(_msg, e._msg);
    }
    virtual ~runtime_error() { delete[] _msg; }
    virtual const char* what() const { return _msg; }
};

class invalid_argument : public logic_error {
public:
    invalid_argument(const char* msg) : logic_error(msg) {}
};

class out_of_range : public logic_error {
public:
    out_of_range(const char* msg) : logic_error(msg) {}
};

class length_error : public logic_error {
public:
    length_error(const char* msg) : logic_error(msg) {}
};

class overflow_error : public runtime_error {
public:
    overflow_error(const char* msg) : runtime_error(msg) {}
};

class range_error : public runtime_error {
public:
    range_error(const char* msg) : runtime_error(msg) {}
};

class bad_alloc : public exception {
public:
    bad_alloc() {}
    virtual const char* what() const { return "bad_alloc"; }
};

#endif
