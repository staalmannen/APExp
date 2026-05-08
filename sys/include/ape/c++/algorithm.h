/* algorithm.h — generic algorithms for cfront-compiled C++ programs.
 * All functions are inline templates; no separate .cpp needed. */
#ifndef __ALGORITHM_H
#define __ALGORITHM_H

#include <utility.h>   /* for swap() */
#include <functional.h> /* for less<T> */

/* ---- min / max ---- */

template <class T>
inline const T& min(const T& a, const T& b) { return b < a ? b : a; }

template <class T>
inline const T& max(const T& a, const T& b) { return a < b ? b : a; }

template <class T, class Cmp>
inline const T& min(const T& a, const T& b, Cmp cmp) { return cmp(b,a) ? b : a; }

template <class T, class Cmp>
inline const T& max(const T& a, const T& b, Cmp cmp) { return cmp(a,b) ? b : a; }

/* ---- find ---- */

template <class Iter, class T>
inline Iter find(Iter first, Iter last, const T& val) {
    while (first != last && !(*first == val)) ++first;
    return first;
}

template <class Iter, class Pred>
inline Iter find_if(Iter first, Iter last, Pred pred) {
    while (first != last && !pred(*first)) ++first;
    return first;
}

/* ---- count ---- */

template <class Iter, class T>
inline size_t count(Iter first, Iter last, const T& val) {
    size_t n = 0;
    while (first != last) { if (*first == val) ++n; ++first; }
    return n;
}

/* ---- copy ---- */

template <class In, class Out>
inline Out copy(In first, In last, Out dest) {
    while (first != last) { *dest = *first; ++first; ++dest; }
    return dest;
}

template <class In, class Out>
inline Out copy_backward(In first, In last, Out dest) {
    while (first != last) { --last; --dest; *dest = *last; }
    return dest;
}

/* ---- fill ---- */

template <class Iter, class T>
inline void fill(Iter first, Iter last, const T& val) {
    while (first != last) { *first = val; ++first; }
}

template <class Iter, class Size, class T>
inline void fill_n(Iter first, Size n, const T& val) {
    while (n--) { *first = val; ++first; }
}

/* ---- for_each ---- */

template <class Iter, class Fn>
inline Fn for_each(Iter first, Iter last, Fn f) {
    while (first != last) { f(*first); ++first; }
    return f;
}

/* ---- reverse ---- */

template <class Iter>
inline void reverse(Iter first, Iter last) {
    while (first != last && first != --last)
        swap(*first++, *last);
}

/* ---- sort (introsort-style quicksort for random-access iterators) ---- */

template <class Iter, class Cmp>
inline void _insertion_sort(Iter first, Iter last, Cmp cmp) {
    for (Iter i=first+1; i!=last; ++i) {
        typename Iter::value_type val = *i;  /* works for pointer iterators too */
        Iter j = i;
        while (j != first && cmp(val, *(j-1))) { *j = *(j-1); --j; }
        *j = val;
    }
}

/* insertion_sort for raw pointer iterators (no value_type) */
template <class T, class Cmp>
inline void _ptr_insertion_sort(T* first, T* last, Cmp cmp) {
    for (T* i=first+1; i!=last; ++i) {
        T val = *i; T* j = i;
        while (j != first && cmp(val, *(j-1))) { *j = *(j-1); --j; }
        *j = val;
    }
}

template <class T, class Cmp>
inline T* _median3(T* a, T* b, T* c, Cmp cmp) {
    if (cmp(*a,*b)) {
        if (cmp(*b,*c)) return b;
        return cmp(*a,*c) ? c : a;
    }
    if (cmp(*a,*c)) return a;
    return cmp(*b,*c) ? c : b;
}

template <class T, class Cmp>
void _qsort(T* first, T* last, Cmp cmp) {
    while (last - first > 16) {
        T* mid  = first + (last - first) / 2;
        T* pivot = _median3(first, mid, last-1, cmp);
        swap(*pivot, *(last-1));
        T* p = first, *q = last-2;
        for (;;) {
            while (cmp(*p, *(last-1))) ++p;
            while (q > first && cmp(*(last-1), *q)) --q;
            if (p >= q) break;
            swap(*p++, *q--);
        }
        swap(*p, *(last-1));
        if (p - first < last - p - 1) {
            _qsort(first, p, cmp);
            first = p + 1;
        } else {
            _qsort(p + 1, last, cmp);
            last = p;
        }
    }
    if (last - first > 1) _ptr_insertion_sort(first, last, cmp);
}

template <class T>
inline void sort(T* first, T* last) {
    _qsort(first, last, less<T>());
}

template <class T, class Cmp>
inline void sort(T* first, T* last, Cmp cmp) {
    _qsort(first, last, cmp);
}

/* ---- equal ---- */

template <class In1, class In2>
inline int equal(In1 first1, In1 last1, In2 first2) {
    while (first1 != last1) {
        if (!(*first1 == *first2)) return 0;
        ++first1; ++first2;
    }
    return 1;
}

/* ---- lower_bound / upper_bound (binary search on sorted range) ---- */

template <class T, class U>
inline T* lower_bound(T* first, T* last, const U& val) {
    while (first < last) {
        T* mid = first + (last - first) / 2;
        if (*mid < val) first = mid + 1; else last = mid;
    }
    return first;
}

template <class T, class U>
inline T* upper_bound(T* first, T* last, const U& val) {
    while (first < last) {
        T* mid = first + (last - first) / 2;
        if (!(val < *mid)) first = mid + 1; else last = mid;
    }
    return first;
}

#endif
