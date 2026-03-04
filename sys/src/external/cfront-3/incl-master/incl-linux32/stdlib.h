/* @(#) stdlib.h 1.4 1/27/86 17:47:01 */
/*ident	"@(#)cfront:incl/stdlib.h	1.4"*/

extern "C" {
    
#ifndef __STDDEF_H
#include <stddef.h>
#endif
    
    void    abort(void);
    double  atof (const char*);
    int     atoi (const char*);
    long    atol (const char*);
    void*   calloc (size_t,size_t);
    void    exit (int);
    void    free (void*);
    char*   getenv (const char*);
    void*   malloc (size_t);
    int     rand ();
    void*   realloc (void*, size_t);
    void    srand  (unsigned);
    double  strtod (const char*, char**);
    long    strtol (const char*, char**, int);
    int     system (const char*);
}
