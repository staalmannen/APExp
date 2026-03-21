#ifndef __STRING_H_
#define __STRING_H_
#pragma lib "/$M/lib/ape/libap.a"

#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void *memcpy(void *, const void *, size_t);
extern void *memccpy(void*, void*, int, size_t);
extern void *memmove(void *, const void *, size_t);
extern char *strcpy(char *, const char *);
extern char *strncpy(char *, const char *, size_t);
extern char *strcat(char *, const char *);
extern char *strncat(char *, const char *, size_t);
extern int memcmp(const void *, const void *, size_t);
extern int strcmp(const char *, const char *);
extern int strcoll(const char *, const char *);
extern int strverscmp(const char *, const char *);
extern char *strdup(const char*);
extern char *strndup(const char*, size_t);
extern int strncmp(const char *, const char *, size_t);
extern size_t strxfrm(char *, const char *, size_t);
extern void *memchr(const void *, int, size_t);
extern char *strchr(const char *, int);
extern size_t strcspn(const char *, const char *);
extern char *strpbrk(const char *, const char *);
extern char *strrchr(const char *, int);
extern size_t strspn(const char *, const char *);
extern char *strstr(const char *, const char *);
extern char *strtok(char *, const char *);
extern void *memset(void *, int, size_t);
extern char *strerror(int);
extern size_t strlen(const char *);
extern size_t strnlen(const char *, size_t);

extern char *strtok_r(char *, const char *, char **);

#include <bsd.h>

/* from musl */
extern char *strchrnul(const char*, int);
#define __strchrnul strchrnul
extern int strerror_r(int, char *, size_t);

void *memmem(const void *, size_t, const void *, size_t);
void *memrchr(const void *, int, size_t);
char *stpcpy(char *, const char *);
char *stpncpy(char *, const char *, size_t);
char *strsignal(int);
char *strsep(char **, const char *);
char *strcasestr(const char *, const char *);
char *strfry(char *);
void *mempcpy(void *, const void *, size_t);


#ifdef __cplusplus
}
#endif

#endif
