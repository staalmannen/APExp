/* utility.h — pair<T,U> and swap for cfront-compiled C++ programs. */
#ifndef __UTILITY_H
#define __UTILITY_H

template <class T, class U>
struct pair {
    T first;
    U second;

    pair() {}
    pair(const T& a, const U& b) : first(a), second(b) {}

    template <class T2, class U2>
    pair(const pair<T2,U2>& p) : first(p.first), second(p.second) {}
};

template <class T, class U>
inline pair<T,U> make_pair(const T& a, const U& b) { return pair<T,U>(a,b); }

template <class T, class U>
inline int operator==(const pair<T,U>& a, const pair<T,U>& b)
    { return a.first==b.first && a.second==b.second; }

template <class T, class U>
inline int operator<(const pair<T,U>& a, const pair<T,U>& b)
    { return a.first<b.first || (!(b.first<a.first) && a.second<b.second); }

/* swap — also used internally by algorithm.h */
template <class T>
inline void swap(T& a, T& b) { T t=a; a=b; b=t; }

#endif
