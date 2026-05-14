/*
 * Strong aliases for resolver functions.
 * Plan9 kencc has no weak symbol support, so weak_alias() is a no-op.
 * This file provides explicit forwarding definitions for the aliased names,
 * plus stubs for net/if functions not yet implemented on Plan9.
 */
#include <resolv.h>
#include <netdb.h>
#include <net/if.h>
#include <string.h>
#include <errno.h>
#include "lookup.h"

int res_mkquery(int op, const char *dname, int class, int type,
	const unsigned char *data, int datalen,
	const unsigned char *newrr, unsigned char *buf, int buflen)
{
	return __res_mkquery(op, dname, class, type, data, datalen,
		newrr, buf, buflen);
}

int res_send(const unsigned char *msg, int msglen, unsigned char *answer, int anslen)
{
	return __res_send(msg, msglen, answer, anslen);
}

/* __res_msend: public wrapper over __res_msend_rc that reads /etc/resolv.conf */
int __res_msend(int nqueries, const unsigned char *const *queries, const int *qlens,
	unsigned char *const *answers, int *alens, int asize)
{
	struct resolvconf conf;
	if (__get_resolv_conf(&conf, 0, 0) < 0) return -1;
	return __res_msend_rc(nqueries, queries, qlens, answers, alens, asize, &conf);
}

int dn_expand(const unsigned char *base, const unsigned char *end,
	const unsigned char *src, char *dest, int space)
{
	return __dn_expand(base, end, src, dest, space);
}

int res_search(const char *name, int class, int type, unsigned char *dest, int len)
{
	return res_query(name, class, type, dest, len);
}

void setnetent(int x)
{
	sethostent(x);
}

void endnetent(void)
{
	endhostent();
}

/* if_nametoindex / if_indextoname stubs (IPv6 link-local scope) */
unsigned int if_nametoindex(const char *name)
{
	(void)name;
	errno = ENXIO;
	return 0;
}

char *if_indextoname(unsigned int index, char *buf)
{
	(void)index; (void)buf;
	errno = ENXIO;
	return 0;
}

struct if_nameindex *if_nameindex(void)
{
	errno = ENOSYS;
	return 0;
}

void if_freenameindex(struct if_nameindex *p)
{
	(void)p;
}
