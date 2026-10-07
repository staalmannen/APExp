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
 * `reject' is the other half of the same defect and points the other
 * way: `plan9/announce.c:139' DEFINES `reject(int, char*, char*)' and
 * no header declared it, so libap held a function nothing could call
 * with its arguments checked -- the "capability present and not
 * declared" shape this tree has now met six times. Declared here
 * because this is the header its definition's own file includes.
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
extern	int	reject(int, char*, char*);

extern char    dialerrstr[64];

#endif /* __LIBNET_H */
