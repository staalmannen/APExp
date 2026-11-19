#ifndef __LIBV_H
#define __LIBV_H

#pragma lib "/$M/lib/ape/libap.a"

#ifdef __cplusplus
extern "C" {
#endif

extern void	srand(unsigned int);
extern int	rand(void);
extern int	nrand(int);
extern long	lrand(void);
extern double	frand(void);

/*
 * `const char *' since this round: `<unistd.h>' declares it too (where
 * every portable caller looks for it) and the two must agree, or a C++
 * TU including both sees two overloads of an `extern "C"' function.
 * gnulib's own prototype is the `const' one.
 */
extern char	*getpass(const char *);
extern int	tty_echoon(int);
extern int	tty_echooff(int);

extern int	min(int, int);
extern int	max(int, int);

extern void	_perror(char *);
extern char	*_progname;

extern int	nap(int);

extern char	*setfields(char *);
extern int getfields(char *, char **, int, int, char *); // getfields from lib9
extern int	getfields3(char *, char **, int); //old getfields from libv
extern int	getmfields(char *, char **, int);


#ifdef __cplusplus
};
#endif

#endif /* __LIBV_H */
