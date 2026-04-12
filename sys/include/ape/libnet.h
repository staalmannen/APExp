#ifndef __LIBNET_H
#define __LIBNET_H

#pragma lib "/$M/lib/ape/libap.a"

#define NETPATHLEN 40

extern	int	net_accept(int, char*);
extern	int	announce(char*, char*);
extern	int	dial(char*, char*, char*, int*);
extern	int	hangup(int);
extern	int	net_listen(char*, char*);
extern	char*	netmkaddr(char*, char*, char*);
extern	int	net_reject(int, char*, char *);

extern char    dialerrstr[64];

#endif /* __LIBNET_H */
