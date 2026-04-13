/* @(#) stdio.h 1.8 1/31/86 13:40:51 */
/*ident	"@(#)cfront:incl/stdio.h	1.8"*/

#ifndef __CF_STDDEF_H
#define __CF_STDDEF_H

#if defined(_WIN32) && !defined(_WIN64)
    typedef int ssize_t;
    typedef unsigned int size_t;
#elif defined(_WIN64)
    typedef long long ssize_t;
    typedef unsigned long long size_t;
#else //UNIX
#if __SIZEOF_LONG__ == __SIZEOF_INT__
    typedef int ssize_t;
    typedef unsigned int size_t;
#else
    typedef long ssize_t;
    typedef unsigned long size_t;
#endif
#endif

#endif //__CF_STDDEF_H
