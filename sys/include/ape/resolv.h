#ifndef _RESOLV_H
#define _RESOLV_H

#include <stdint.h>
#include <sys/types.h>
#include <netinet/in.h>

/*
 * ***THE WIRE-FORMAT NAMES COME FROM HERE AND ARE NOT REPEATED, WHICH
 * THEY WERE.***  This header carried its own `MAXDNAME', `NS_PACKETSZ',
 * `T_A' ... `C_ANY' beside <arpa/nameser.h>'s -- **two definitions of
 * the same constant in two headers, with nothing making them agree**,
 * which is the `PATH_MAX' shape from this tree's own rules.  Nothing
 * noticed while no translation unit included both; php's
 * `ext/standard/dns.c' includes both and answered `Macro redefinition
 * of MAXDNAME' sixteen times.
 *
 * glibc's <resolv.h> includes <arpa/nameser.h> for exactly this
 * reason, so that is what happens here.  What stays below is the
 * resolver's own: the opcodes, the response codes, `RES_*', and the
 * record types and classes <arpa/nameser.h> does NOT know -- those are
 * still defined in one place, this one.
 */
#include <arpa/nameser.h>

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

/*
 * DNS record types <arpa/nameser.h> does not list.  T_A, T_NS,
 * T_CNAME, T_SOA, T_PTR, T_MX, T_TXT, T_AAAA, T_SRV and T_ANY are
 * <arpa/nameser_compat.h>'s, aliased to that header's `ns_t_' numbers.
 */
#define T_MD		3
#define T_MF		4
#define T_MB		7
#define T_MG		8
#define T_MR		9
#define T_NULL		10
#define T_WKS		11
#define T_HINFO		13
#define T_MINFO		14
#define T_NAPTR		35
#define T_OPT		41
#define T_TSIG		250
#define T_IXFR		251
#define T_AXFR		252
#define T_MAILB		253
#define T_MAILA		254

/* DNS record classes; C_IN and C_ANY likewise come from the compat header. */
#define C_CHAOS		3
#define C_HS		4

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

/* Plan9 kencc has no weak symbol support; aliases are provided
 * explicitly. Guarded, and with glibc's parameter names, for the reason
 * given in <features.h>: gnulib's libc-config.h defines this too, with
 * no guard, and cpp compares parameter lists as well as bodies. */
#ifndef weak_alias
#define weak_alias(name, aliasname) /* no weak alias on Plan9 */
#endif

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
/*
 * `lib/ap/network/dn_skipname.c' has defined this all along and no
 * header declared it -- the `asctime_r' shape again, and the same
 * consequence: every caller got an implicit `int'.  php's
 * `ext/standard/dns.c:996' is one.
 */
int dn_skipname(const unsigned char *, const unsigned char *);

int res_query(const char *, int, int, unsigned char *, int);
int res_search(const char *, int, int, unsigned char *, int);
int res_querydomain(const char *, const char *, int, int, unsigned char *, int);

#ifdef __cplusplus
}
#endif

#endif
