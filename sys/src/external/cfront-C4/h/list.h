/* list.h — doubly-linked list template for cfront-compiled C++ programs.
 * Provides begin()/end() with proper bidirectional iterators.
 * All member functions are inline so no separate .cpp is needed. */
#ifndef __LIST_H
#define __LIST_H

#pragma lib "ape/libc++.a"

#include <stddef.h>
#include <new.h>

template <class T>
class list {
    struct Node {
        T     val;
        Node* next;
        Node* prev;
        Node(const T& v, Node* n, Node* p) : val(v), next(n), prev(p) {}
    };

    Node*  _head;
    Node*  _tail;
    size_t _n;

public:
    class iterator {
        Node* _p;
    public:
        iterator(Node* p = 0) : _p(p) {}
        T&         operator*()             { return _p->val; }
        T*         operator->()            { return &_p->val; }
        iterator&  operator++()            { _p=_p->next; return *this; }
        iterator   operator++(int)         { iterator t=*this; ++*this; return t; }
        iterator&  operator--()            { _p=_p->prev; return *this; }
        iterator   operator--(int)         { iterator t=*this; --*this; return t; }
        int        operator==(const iterator& o) const { return _p==o._p; }
        int        operator!=(const iterator& o) const { return _p!=o._p; }
    };

    class const_iterator {
        const Node* _p;
    public:
        const_iterator(const Node* p = 0) : _p(p) {}
        const T&          operator*()  const           { return _p->val; }
        const T*          operator->() const           { return &_p->val; }
        const_iterator&   operator++()                 { _p=_p->next; return *this; }
        const_iterator    operator++(int)              { const_iterator t=*this; ++*this; return t; }
        const_iterator&   operator--()                 { _p=_p->prev; return *this; }
        int               operator==(const const_iterator& o) const { return _p==o._p; }
        int               operator!=(const const_iterator& o) const { return _p!=o._p; }
    };

    list() : _head(0), _tail(0), _n(0) {}

    list(const list<T>& l) : _head(0), _tail(0), _n(0) {
        for (Node* p=l._head; p; p=p->next) push_back(p->val);
    }

    ~list() { clear(); }

    list<T>& operator=(const list<T>& l) {
        if (this != &l) {
            clear();
            for (Node* p=l._head; p; p=p->next) push_back(p->val);
        }
        return *this;
    }

    iterator       begin()       { return iterator(_head); }
    const_iterator begin() const { return const_iterator(_head); }
    iterator       end()         { return iterator(0); }
    const_iterator end()   const { return const_iterator(0); }

    size_t size()  const { return _n; }
    int    empty() const { return _n == 0; }

    T&       front()       { return _head->val; }
    const T& front() const { return _head->val; }
    T&       back()        { return _tail->val; }
    const T& back()  const { return _tail->val; }

    void push_back(const T& x) {
        Node* n = new Node(x, 0, _tail);
        if (_tail) _tail->next = n; else _head = n;
        _tail = n; ++_n;
    }

    void push_front(const T& x) {
        Node* n = new Node(x, _head, 0);
        if (_head) _head->prev = n; else _tail = n;
        _head = n; ++_n;
    }

    void pop_back() {
        if (!_tail) return;
        Node* n = _tail; _tail = _tail->prev;
        if (_tail) _tail->next = 0; else _head = 0;
        delete n; --_n;
    }

    void pop_front() {
        if (!_head) return;
        Node* n = _head; _head = _head->next;
        if (_head) _head->prev = 0; else _tail = 0;
        delete n; --_n;
    }

    iterator insert(iterator pos, const T& x) {
        /* pos==end() → push_back */
        if (!pos._p) { push_back(x); return iterator(_tail); }
        Node* next = pos._p;
        Node* prev = next->prev;
        Node* n    = new Node(x, next, prev);
        if (prev) prev->next = n; else _head = n;
        next->prev = n; ++_n;
        return iterator(n);
    }

    iterator erase(iterator pos) {
        Node* n    = pos._p;
        Node* nx   = n->next;
        if (n->prev) n->prev->next = nx; else _head = nx;
        if (nx)      nx->prev      = n->prev; else _tail = n->prev;
        delete n; --_n;
        return iterator(nx);
    }

    void clear() {
        Node* p = _head;
        while (p) { Node* nx=p->next; delete p; p=nx; }
        _head = _tail = 0; _n = 0;
    }

    void remove(const T& x) {
        for (Node* p=_head; p; ) {
            Node* nx = p->next;
            if (p->val == x) erase(iterator(p));
            p = nx;
        }
    }
};

#endif
