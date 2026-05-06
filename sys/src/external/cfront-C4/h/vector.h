/* vector.h — resizable array template for cfront-compiled C++ programs.
 * Provides begin()/end() iterators, so range-for works:
 *   vector<int> v; ... for (int x : v) { ... }
 * All member functions are inline so no separate .cpp is needed. */
#ifndef __VECTOR_H
#define __VECTOR_H

#pragma lib "ape/libc++.a"

#include <stddef.h>
#include <new.h>

template <class T>
class vector {
    T*     _p;
    size_t _n;
    size_t _cap;

    void _grow(size_t mincap) {
        size_t nc = _cap ? _cap + (_cap >> 1) + 1 : 8;
        while (nc < mincap) nc += nc >> 1;
        T* np = new T[nc];
        for (size_t i = 0; i < _n; i++) np[i] = _p[i];
        delete[] _p;
        _p = np; _cap = nc;
    }

public:
    typedef T*       iterator;
    typedef const T* const_iterator;

    vector() : _p(0), _n(0), _cap(0) {}

    vector(size_t n) : _p(0), _n(0), _cap(0) {
        if (n) { _p = new T[n]; _n = _cap = n; }
    }

    vector(size_t n, const T& x) : _p(0), _n(0), _cap(0) {
        if (n) {
            _p = new T[n]; _n = _cap = n;
            for (size_t i = 0; i < n; i++) _p[i] = x;
        }
    }

    vector(const vector<T>& v) : _p(0), _n(0), _cap(0) {
        if (v._n) {
            _p = new T[v._n]; _n = _cap = v._n;
            for (size_t i = 0; i < _n; i++) _p[i] = v._p[i];
        }
    }

    ~vector() { delete[] _p; }

    vector<T>& operator=(const vector<T>& v) {
        if (this != &v) {
            delete[] _p; _p = 0; _n = _cap = 0;
            if (v._n) {
                _p = new T[v._n]; _n = _cap = v._n;
                for (size_t i = 0; i < _n; i++) _p[i] = v._p[i];
            }
        }
        return *this;
    }

    /* Iterators — these are what range-for uses */
    T*       begin()       { return _p; }
    const T* begin() const { return _p; }
    T*       end()         { return _p + _n; }
    const T* end()   const { return _p + _n; }

    /* Capacity */
    size_t size()     const { return _n; }
    size_t capacity() const { return _cap; }
    int    empty()    const { return _n == 0; }

    void reserve(size_t n) { if (n > _cap) _grow(n); }

    void resize(size_t n) {
        if (n > _cap) _grow(n);
        _n = n;
    }

    void resize(size_t n, const T& x) {
        size_t old = _n;
        resize(n);
        for (size_t i = old; i < _n; i++) _p[i] = x;
    }

    /* Element access */
    T&       operator[](size_t i)       { return _p[i]; }
    const T& operator[](size_t i) const { return _p[i]; }
    T&       at(size_t i)               { return _p[i]; }
    const T& at(size_t i)         const { return _p[i]; }
    T&       front()                    { return _p[0]; }
    const T& front()              const { return _p[0]; }
    T&       back()                     { return _p[_n-1]; }
    const T& back()               const { return _p[_n-1]; }

    /* Modifiers */
    void push_back(const T& x) {
        if (_n >= _cap) _grow(_n + 1);
        _p[_n++] = x;
    }

    void pop_back() { if (_n) --_n; }

    void clear() { _n = 0; }

    iterator insert(iterator pos, const T& x) {
        size_t idx = pos - _p;
        if (_n >= _cap) _grow(_n + 1);
        for (size_t i = _n; i > idx; i--) _p[i] = _p[i-1];
        _p[idx] = x; ++_n;
        return _p + idx;
    }

    iterator erase(iterator pos) {
        size_t idx = pos - _p;
        for (size_t i = idx; i+1 < _n; i++) _p[i] = _p[i+1];
        --_n;
        return _p + idx;
    }

    iterator erase(iterator first, iterator last) {
        size_t i = first - _p;
        size_t j = last  - _p;
        size_t d = j - i;
        for (; j < _n; i++, j++) _p[i] = _p[j];
        _n -= d;
        return _p + (first - _p);
    }
};

#endif
