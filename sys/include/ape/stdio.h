#ifndef	_STDIO_H_
#define	_STDIO_H_
#pragma lib "/$M/lib/ape/libap.a"

/*
 * pANS stdio.h
 */
#include <stdarg.h>
#include <stddef.h>
#include <sys/types.h>

/* Include musl-compatible stdio internal definitions */
#include "stdio_impl.h"

/* FILE is now the musl struct _IO_FILE */
typedef struct _IO_FILE FILE;

typedef long long fpos_t;
#ifndef NULL
#ifdef __cplusplus
#define NULL 0
#else
#define NULL ((void*)0)
#endif
#endif

/*
 * Third arg of setvbuf
 */
#define	_IOFBF	1			/* block-buffered */
#define	_IOLBF	2			/* line-buffered */
#define	_IONBF	3			/* unbuffered */
#define	BUFSIZ	4096			/* size of setbuf buffer */
#define	EOF	(-1)			/* returned on end of file */
#define	FOPEN_MAX	90		/* max files open */
#define	FILENAME_MAX	BUFSIZ		/* silly filename length */
#define	L_tmpnam	20		/* sizeof "/tmp/abcdefghij9999 */
#define	L_cuserid	32		/* maximum size user name */
#define	L_ctermid	32		/* size of name of controlling tty */
#define	SEEK_CUR	1
#define	SEEK_END	2
#define	SEEK_SET	0
#define	TMP_MAX		64		/* very hard to set correctly */

/* stdin, stdout, stderr are now extern pointers to static FILE objects in stdio.c */
extern FILE *stdin;
extern FILE *stdout;
extern FILE *stderr;

#define	_IO_CHMASK	0377		/* mask for 8 bit characters */

#ifdef __cplusplus
extern "C" {
#endif

extern int remove(const char *);
extern int rename(const char *, const char *);
extern FILE *tmpfile(void);
extern char *tmpnam(char *);
extern int fclose(FILE *);
extern int fflush(FILE *);
extern FILE *fopen(const char *, const char *);
extern FILE *freopen(const char *, const char *, FILE *);
extern int setbuf(FILE *, char *);
extern int setvbuf(FILE *, char *, int, size_t);
extern int fprintf(FILE *, const char *, ...);
extern int fscanf(FILE *, const char *, ...);
extern int printf(const char *, ...);
extern int scanf(const char *, ...);
extern int sprintf(char *, const char *, ...);
extern int snprintf(char *, size_t, const char *, ...);
extern int vsnprintf(char *, size_t, const char *, va_list);
extern int sscanf(const char *, const char *, ...);
extern int vfprintf(FILE *, const char *, va_list);
extern int vprintf(const char *, va_list);
extern int vsprintf(char *, const char *, va_list);
extern int vfscanf(FILE *, const char *, va_list);
extern int fgetc(FILE *);
extern char *fgets(char *, int, FILE *);
extern int fputc(int, FILE *);
extern int fputs(const char *, FILE *);
extern int getc(FILE *);
extern int getchar(void);
#define	getchar()	getc(stdin)
extern char *gets(char *);
extern int putc(int, FILE *);
extern int putchar(int);
#define	putchar(c)	putc(c, stdout)
extern int puts(const char *);
extern int ungetc(int, FILE *);
extern size_t fread(void *, size_t, size_t, FILE *);
extern size_t fwrite(const void *, size_t, size_t, FILE *);
extern int fgetpos(FILE *, fpos_t *);
extern int fseek(FILE *, long, int);
extern int fseeko(FILE *, off_t, int);
extern int fsetpos(FILE *, const fpos_t *);
extern long ftell(FILE *);
extern off_t ftello(FILE *);
extern void rewind(FILE *);
extern void clearerr(FILE *);


extern int feof(FILE *);
extern int ferror(FILE *);
extern void perror(const char *);

extern int fileno(FILE *);
extern FILE* fdopen(int, const char*);
extern char *ctermid(char *);

extern char *tmpnam_r(char *);
extern char *ctermid_r(char *);

extern FILE *popen(char *, char *);
extern int	pclose(FILE *);

/* from musl libc */
extern int asprintf(char**, const char *, ...);
extern int vasprintf(char **, const char *, va_list);

/* GNU extensions */
extern char *asnprintf(char *, size_t *, const char *, ...);
extern char *vasnprintf(char *, size_t *, const char *, va_list);
extern size_t _fpending(FILE *);
extern size_t __fpending(FILE *);

extern FILE *fmemopen(void *, size_t, const char *);
extern FILE *open_memstream(char **, size_t *);

extern ssize_t getdelim(char **, size_t *, int, FILE *);
extern ssize_t getline (char **, size_t *, FILE *);

extern int dprintf(int, const char *, ...);
extern int vdprintf(int, const char *, va_list);

extern double pow10(int n);                                   /* stdio/pow10.c why not in math?*/
extern void setlinebuf(FILE *f);

extern void flockfile(FILE *);
extern void funlockfile(FILE *);
extern int ftrylockfile(FILE *);

#ifdef __cplusplus
}
#endif

#endif
