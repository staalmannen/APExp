#ifndef _NETINET_ETHER_H
#define _NETINET_ETHER_H

#include <sys/types.h>

struct ether_addr {
	unsigned char ether_addr_octet[6];
};

#ifdef __cplusplus
extern "C" {
#endif

struct ether_addr	*ether_aton(const char *);
struct ether_addr	*ether_aton_r(const char *, struct ether_addr *);
char			*ether_ntoa(const struct ether_addr *);
char			*ether_ntoa_r(const struct ether_addr *, char *);

int	ether_line(const char *, struct ether_addr *, char *);
int	ether_ntohost(char *, const struct ether_addr *);
int	ether_hostton(const char *, struct ether_addr *);

#ifdef __cplusplus
}
#endif

#endif
