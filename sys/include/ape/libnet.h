#ifndef __LIBNET_H
#define __LIBNET_H

#pragma lib "/$M/lib/ape/libap.a"

#define NETPATHLEN 40

/*
 * EXACTLY WHAT libap DEFINES, WHICH IS NOT WHAT THIS FILE USED TO SAY.
 *
 * `net_accept', `net_listen' and `net_reject' were declared here and
 * **defined nowhere in the tree and called nowhere in the tree** --
 * grep gives zero hits for all three outside this file. So every
 * program including <sys/socket.h>, which includes this header,
 * carried three promises libap cannot keep; the error arrived at the
 * LINK rather than at the call, which is the later and worse of the
 * two places for it. That is the `tcflush'/`IP_ADD_MEMBERSHIP' rule
 * with the sign flipped: a name a program can call and cannot link.
 *
 * `reject' IS DEFINED BY libap AND IS DELIBERATELY NOT DECLARED HERE,
 * WHICH COST A BUILD. `plan9/announce.c:139' defines
 * `reject(int, char*, char*)' and no header names it, so it is the
 * "capability present and not declared" shape -- and declaring it
 * broke flex at once:
 *
 *	flexdef.h:366 external redeclaration of: reject
 *	    EXTERN INT reject
 *	    EXTERN FUNC(INT, IND CHAR, IND CHAR) INT  libnet.h:36
 *
 * flex has `extern int reject;', a VARIABLE. **This header is reached
 * from <sys/socket.h>**, so anything it declares is surface for every
 * networked program in the tree, and `reject' is a name 210 files
 * under `external/' use -- gnulib spells two PARAMETERS with it
 * (`mbsspn(const char*, const char *reject)', `u8_strcspn').
 *
 * *The sweep that cleared it looked for `reject(' and could not match
 * a variable* -- which is the mistake this tree has already recorded
 * once, when a function-shaped grep missed `optind', `opterr',
 * `optarg' and `stdin'. **Sweep for the NAME, not for the shape you
 * expect it to have.**
 *
 * There is no Plan 9 `accept(int, char*)' or `listen(char*, char*)'
 * in libap: `network/accept.c' and `network/listen.c' are POSIX's,
 * declared by <sys/socket.h>. `Plan9libnet.h' claimed both and was
 * deleted -- see CLAUDE.md.
 */
extern	int	announce(char*, char*);
extern	int	dial(char*, char*, char*, int*);
extern	int	hangup(int);
extern	char*	netmkaddr(char*, char*, char*);

extern char    dialerrstr[64];

#endif /* __LIBNET_H */
