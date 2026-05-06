/* new.h — operator new/delete declarations for cfront-compiled C++ programs. */
#ifndef __NEW_H
#define __NEW_H

#pragma lib "ape/libc++.a"

#include <stddef.h>

extern void* operator new(size_t);
extern void  operator delete(void*);

/* placement new — does not require libc++.a */
inline void* operator new(size_t, void* __p) { return __p; }

extern void (*set_new_handler(void(*)()))();

#endif
