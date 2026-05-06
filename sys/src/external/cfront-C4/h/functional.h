/* functional.h — function objects for cfront-compiled C++ programs.
 * Provides the comparison predicates needed by algorithm.h (sort, etc.). */
#ifndef __FUNCTIONAL_H
#define __FUNCTIONAL_H

template <class T>
struct less {
    int operator()(const T& a, const T& b) const { return a < b; }
};

template <class T>
struct greater {
    int operator()(const T& a, const T& b) const { return a > b; }
};

template <class T>
struct less_equal {
    int operator()(const T& a, const T& b) const { return a <= b; }
};

template <class T>
struct greater_equal {
    int operator()(const T& a, const T& b) const { return a >= b; }
};

template <class T>
struct equal_to {
    int operator()(const T& a, const T& b) const { return a == b; }
};

template <class T>
struct not_equal_to {
    int operator()(const T& a, const T& b) const { return a != b; }
};

template <class T>
struct plus {
    T operator()(const T& a, const T& b) const { return a + b; }
};

template <class T>
struct minus {
    T operator()(const T& a, const T& b) const { return a - b; }
};

template <class T>
struct negate {
    T operator()(const T& a) const { return -a; }
};

#endif
