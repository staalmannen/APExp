#ifndef __STDLIB_H
#define __STDLIB_H
#pragma lib "/$M/lib/ape/libap.a"

#include <stddef.h>

#define EXIT_FAILURE 1
#define EXIT_SUCCESS 0
#define MB_CUR_MAX 4
#define RAND_MAX 32767

typedef struct { int quot, rem; } div_t;
typedef struct { long quot, rem; } ldiv_t;

#ifdef __cplusplus
extern "C" {
#endif

extern double atof(const char *);
extern int atoi(const char *);
extern long int atol(const char *);
extern long long atoll(const char *);
extern double strtod(const char *, char **);
extern long int strtol(const char *, char **, int);
extern long double strtold(const char *, char **);
extern float strtof(const char *, char **);
extern unsigned long int strtoul(const char *, char **, int);
extern long long int strtoll(const char *, char **, int);
extern unsigned long long int strtoull(const char *, char **, int);
extern int rand(void);
extern void srand(unsigned int seed);
extern void *calloc(size_t, size_t);
extern void free(void *);
extern void *malloc(size_t);
extern void *realloc(void *, size_t);
extern _Noreturn void abort(void);
extern int atexit(void (*func)(void));
extern _Noreturn void exit(int);
extern char *getenv(const char *);
extern int putenv(char *);
extern int system(const char *);
extern void *bsearch(const void *, const void *, size_t, size_t, int (*)(const void *, const void *));
extern void qsort(void *, size_t, size_t, int (*)(const void *, const void *));
#undef abs
extern int abs(int);
extern div_t div(int, int);
extern long int labs(long int);
extern ldiv_t ldiv(long int, long int);
extern int mblen(const char *, size_t);
extern int mbtowc(wchar_t *, const char *, size_t);
extern int wctomb(char *, wchar_t);
extern size_t mbstowcs(wchar_t *, const char *, size_t);
extern size_t wcstombs(char *, const wchar_t *, size_t);

#include <bsd.h>

extern char *mktemp(char *);
extern int mkstemp(char *template);
extern int mkostemp(char *template, int);

/* from musl */
typedef struct { long long quot, rem; } lldiv_t;
extern int clearenv(void);
extern int setenv(const char *, const char *, int);
extern int unsetenv(const char *);
extern char *realpath(const char *, char *);
extern char *get_current_dir_name(void);
extern char *canonicalize_file_name(const char *);

extern char *mkdtemp(char *);

extern long long llabs(long long);
extern lldiv_t lldiv(long long, long long);

extern int at_quick_exit(void (*)(void));
extern _Noreturn void quick_exit(int);

/* musl and other ports */

extern int posix_memalign(void **, size_t, size_t);
extern void *aligned_alloc(size_t align, size_t len);
extern void *memalign(size_t align, size_t len);
extern void *reallocarray(void *ptr, size_t m, size_t n);

extern void qsort_r(void *base, size_t nel, size_t width,
    int (*cmp)(const void *, const void *, void *), void *arg);

extern long a64l(const char *s);
extern char *l64a(long x);

extern unsigned long truerand(void);

extern char *ecvt(double, int, int *, int *);
extern char *fcvt(double, int, int *, int *);
extern char *gcvt(double, int n, char *buf);

/*
 * `getrusage' and `uname' USED TO BE DECLARED HERE, and the two
 * declarations were worse than useless.
 *
 * <stdlib.h> defines neither `struct rusage' nor `struct utsname' and
 * includes neither header, so each struct named in those parameter
 * lists was a NEW, incomplete type scoped to the declaration --
 * distinct from the real one in <sys/resource.h> / <sys/utsname.h>.
 * Any translation unit that included <stdlib.h> and then the right
 * header got `conflicting types', and a C compiler stricter than
 * kencc refuses it outright. bacon includes both and that is what
 * stopped its build.
 *
 * POSIX puts them in <sys/resource.h> and <sys/utsname.h>, where both
 * are already declared correctly beside the struct they take, and
 * where libap's own `misc/getrusage.c' and `misc/uname.c' already get
 * them from. Nothing in the tree depended on this file for either.
 *
 * *This is the `Lock' bug in <qlock.h> a second time*: one name
 * declared twice, the two spellings not compatible, and kencc
 * tolerating what the standard forbids -- which is exactly why it
 * survived. `apehdr-sweep.py' cannot see this one: each header is
 * fine ALONE and only the COMBINATION conflicts.
 */

#include <sys/ioctl.h> /* ioctl */

#ifdef __cplusplus
}
#endif

#endif /* __STDLIB_H */
