/* complex.h — AT&T C++ complex number class for cfront/APExp.
 * Shadows the C99 <complex.h> when compiling with the c++ driver. */
#ifndef _CXXCOMPLEX_H
#define _CXXCOMPLEX_H

#include <iostream.h>
#include <math.h>

class complex {
public:
    double  re, im;

    complex(double r = 0, double i = 0) : re(r), im(i) {}
    complex(const complex& a) : re(a.re), im(a.im) {}

    complex& operator=(const complex& a) { re=a.re; im=a.im; return *this; }
    complex& operator+=(complex a)       { re+=a.re; im+=a.im; return *this; }
    complex& operator-=(complex a)       { re-=a.re; im-=a.im; return *this; }
    void operator*=(complex);
    void operator/=(complex);
};

inline double   real(complex a)  { return a.re; }
inline double   imag(complex a)  { return a.im; }
inline complex  conj(complex a)  { return complex(a.re, -a.im); }
inline double   norm(complex a)  { return a.re*a.re + a.im*a.im; }

inline complex operator+(complex a, complex b) { return complex(a.re+b.re, a.im+b.im); }
inline complex operator-(complex a, complex b) { return complex(a.re-b.re, a.im-b.im); }
inline complex operator-(complex a)            { return complex(-a.re, -a.im); }
inline int     operator==(complex a, complex b){ return a.re==b.re && a.im==b.im; }
inline int     operator!=(complex a, complex b){ return a.re!=b.re || a.im!=b.im; }

complex operator*(complex, complex);
complex operator/(complex, complex);

double  abs(complex);
double  arg(complex);
complex polar(double mag, double arg = 0);
complex cos(complex);
complex sin(complex);
complex exp(complex);
complex log(complex);
complex sqrt(complex);
complex pow(complex, complex);
complex pow(complex, double);
complex pow(double, complex);

ostream& operator<<(ostream&, complex);
istream& operator>>(istream&, complex&);

#endif
