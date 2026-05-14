#ifndef _RESOLV_H
#define _RESOLV_H

#include <stdint.h>
#include <sys/types.h>
#include <netinet/in.h>

#define MAXDNAME	1025
#define MAXCDNAME	255
#define MAXLABEL	63
#define NS_MAXDNAME	1025
#define NS_MAXCDNAME	255
#define NS_MAXLABEL	63
#define NS_PACKETSZ	512
#define NS_MAXMSG	65535

/* DNS opcodes */
#define QUERY		0
#define IQUERY		1
#define STATUS		2
#define NS_NOTIFY_OP	4

/* DNS response codes */
#define NOERROR		0
#define FORMERR		1
#define SERVFAIL	2
#define NXDOMAIN	3
#define NOTIMP		4
#define REFUSED		5

/* DNS record types */
#define T_A		1
#define T_NS		2
#define T_MD		3
#define T_MF		4
#define T_CNAME		5
#define T_SOA		6
#define T_MB		7
#define T_MG		8
#define T_MR		9
#define T_NULL		10
#define T_WKS		11
#define T_PTR		12
#define T_HINFO		13
#define T_MINFO		14
#define T_MX		15
#define T_TXT		16
#define T_AAAA		28
#define T_SRV		33
#define T_NAPTR		35
#define T_OPT		41
#define T_TSIG		250
#define T_IXFR		251
#define T_AXFR		252
#define T_MAILB		253
#define T_MAILA		254
#define T_ANY		255

/* DNS record classes */
#define C_IN		1
#define C_CHAOS		3
#define C_HS		4
#define C_ANY		255

/* Resolver options */
#define RES_INIT	0x00000001
#define RES_DEBUG	0x00000002
#define RES_USEVC	0x00000004
#define RES_RECURSE	0x00000040
#define RES_DEFNAMES	0x00000080
#define RES_STAYOPEN	0x00000010
#define RES_DNSRCH	0x00000200
#define MAXNS		3
#define MAXDFLSRCH	3

struct __res_state {
	int		retrans;
	int		retry;
	unsigned long	options;
	int		nscount;
	struct sockaddr_in nsaddr_list[MAXNS];
	unsigned short	id;
	char		*dnsrch[MAXDFLSRCH+1];
	char		defdname[256];
	unsigned long	pfcode;
	unsigned	ndots:4, nsort:4;
	unsigned char	unused[3];
	struct {
		struct in_addr	addr;
		uint32_t	mask;
	} sort_list[10];
};

typedef struct __res_state *res_state;

/* Plan9 kencc has no weak symbol support; aliases are provided explicitly */
#define weak_alias(old, new) /* no weak alias on Plan9 */

#ifdef __cplusplus
extern "C" {
#endif

int __res_mkquery(int, const char *, int, int, const unsigned char *, int,
	const unsigned char *, unsigned char *, int);
int res_mkquery(int, const char *, int, int, const unsigned char *, int,
	const unsigned char *, unsigned char *, int);

int __res_send(const unsigned char *, int, unsigned char *, int);
int res_send(const unsigned char *, int, unsigned char *, int);

int __res_msend(int, const unsigned char *const *, const int *,
	unsigned char *const *, int *, int);

int res_init(void);
struct __res_state *__res_state(void);

int __dn_expand(const unsigned char *, const unsigned char *,
	const unsigned char *, char *, int);
int dn_expand(const unsigned char *, const unsigned char *,
	const unsigned char *, char *, int);

int res_query(const char *, int, int, unsigned char *, int);
int res_search(const char *, int, int, unsigned char *, int);
int res_querydomain(const char *, const char *, int, int, unsigned char *, int);

#ifdef __cplusplus
}
#endif

#endif
