/* iomanip.h — parameterised stream manipulators for cfront.
 * Adapted from AT&T C++ Language System 3.0.3.
 * Uses the name2() macro from generic.h; #pragma lib updated for APExp. */
#ifndef IOMANIPH
#define IOMANIPH

#pragma lib "ape/libc++.a"

#ifndef IOSTREAMH
#include <iostream.h>
#endif

/* Pull in name2() for the SMANIP/OMANIP/IMANIP family */
#ifndef GENERICH
#define GENERICH 1
#define __name2(a,b) a ## b
#define name2(a,b)   __name2(a,b)
#endif

#define SMANIP(T)  name2(smanip_,T)
#define SAPP(T)    name2(sapply_,T)
#define IMANIP(T)  name2(imanip_,T)
#define OMANIP(T)  name2(omanip_,T)
#define IOMANIP(T) name2(iomanip_,T)
#define IAPP(T)    name2(iapply_,T)
#define OAPP(T)    name2(oapply_,T)
#define IOAPP(T)   name2(ioapply_,T)

#define IOMANIPdeclare(T)                                                   \
class SMANIP(T) {                                                           \
    ios& (*fct)(ios&,T); T arg;                                            \
public:                                                                     \
    SMANIP(T)(ios& (*f)(ios&,T), T a) : fct(f), arg(a) {}                 \
    friend istream& operator>>(istream& i, const SMANIP(T)& m) {           \
        ios* s=&i; (*m.fct)(*s,m.arg); return i; }                        \
    friend ostream& operator<<(ostream& o, const SMANIP(T)& m) {           \
        ios* s=&o; (*m.fct)(*s,m.arg); return o; }                        \
};                                                                          \
class SAPP(T) {                                                             \
    ios& (*fct)(ios&,T);                                                   \
public:                                                                     \
    SAPP(T)(ios& (*f)(ios&,T)) : fct(f) {}                                \
    SMANIP(T) operator()(T a) { return SMANIP(T)(fct,a); }                \
};                                                                          \
class OMANIP(T) {                                                           \
    ostream& (*fct)(ostream&,T); T arg;                                    \
public:                                                                     \
    OMANIP(T)(ostream& (*f)(ostream&,T), T a) : fct(f), arg(a) {}        \
    friend ostream& operator<<(ostream& s, const OMANIP(T)& m) {           \
        return (*m.fct)(s,m.arg); }                                        \
};                                                                          \
class OAPP(T) {                                                             \
    ostream& (*fct)(ostream&,T);                                           \
public:                                                                     \
    OAPP(T)(ostream& (*f)(ostream&,T)) : fct(f) {}                        \
    OMANIP(T) operator()(T a) { return OMANIP(T)(fct,a); }                \
};                                                                          \
class IMANIP(T) {                                                           \
    istream& (*fct)(istream&,T); T arg;                                    \
public:                                                                     \
    IMANIP(T)(istream& (*f)(istream&,T), T a) : fct(f), arg(a) {}        \
    friend istream& operator>>(istream& s, const IMANIP(T)& m) {           \
        return (*m.fct)(s,m.arg); }                                        \
};                                                                          \
class IAPP(T) {                                                             \
    istream& (*fct)(istream&,T);                                           \
public:                                                                     \
    IAPP(T)(istream& (*f)(istream&,T)) : fct(f) {}                        \
    IMANIP(T) operator()(T a) { return IMANIP(T)(fct,a); }                \
};                                                                          \
class IOMANIP(T) {                                                          \
    iostream& (*fct)(iostream&,T); T arg;                                  \
public:                                                                     \
    IOMANIP(T)(iostream& (*f)(iostream&,T), T a) : fct(f), arg(a) {}     \
    friend istream& operator>>(iostream& s, const IOMANIP(T)& m) {         \
        return (*m.fct)(s,m.arg); }                                        \
    friend ostream& operator<<(iostream& s, const IOMANIP(T)& m) {         \
        return (*m.fct)(s,m.arg); }                                        \
};                                                                          \
class IOAPP(T) {                                                            \
    iostream& (*fct)(iostream&,T);                                         \
public:                                                                     \
    IOAPP(T)(iostream& (*f)(iostream&,T)) : fct(f) {}                     \
    IOMANIP(T) operator()(T a) { return IOMANIP(T)(fct,a); }              \
};

IOMANIPdeclare(int)
IOMANIPdeclare(long)

SMANIP(int)  setbase(int b);
SMANIP(long) resetiosflags(long b);
SMANIP(long) setiosflags(long b);
SMANIP(int)  setfill(int f);
SMANIP(int)  setprecision(int p);
SMANIP(int)  setw(int w);

#endif
