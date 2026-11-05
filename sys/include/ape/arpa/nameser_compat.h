#ifndef _ARPA_NAMESER_COMPAT_H
#define _ARPA_NAMESER_COMPAT_H

/*
 * BIND 4's resolver names, which BIND 8 renamed to the `ns_' forms in
 * <arpa/nameser.h> and kept here for everything already written
 * against the old ones.  glibc, musl and the BSDs all ship this file
 * and all include it from <arpa/nameser.h> unconditionally, which is
 * what this tree does too -- so the names are reachable only by
 * including <arpa/nameser.h>, exactly as on a real system.
 *
 * WHERE IT CAME FROM.  php's `ext/standard/dns.c:341' is
 *
 *	typedef union {
 *		HEADER qb1;
 *		uint8_t qb2[65536];
 *	} querybuf;
 *
 * and answered `syntax error, last name: HEADER'.  `HEADER' is this
 * file's, and APExp had the `ns_' half of <arpa/nameser.h> and none of
 * the compat half.
 *
 * ***AND THE CAPABILITY BEHIND IT IS REAL, WHICH IS WHY THE ANSWER IS
 * TO ADD THE TYPE RATHER THAN TO SWITCH THE FEATURE OFF.***  php
 * reaches this block only when `HAVE_RES_SEARCH' and `HAVE_DN_EXPAND'
 * and `HAVE_DN_SKIPNAME' are all yes, and in this tree all three are
 * **defined for real** -- `lib/ap/network/res_aliases.c' has strong
 * `res_search' and `dn_expand' forwarders precisely because kencc has
 * no weak symbols, and `dn_skipname.c' defines its name directly.  *A
 * `config.h' claiming a name that is only DECLARED link-fails far from
 * the claim*, and that was the thing to check before believing the
 * three answers; they hold.
 *
 * ***THE `HEADER' BIT ORDER IS THE WIRE PROTOCOL'S AND SO IT IS
 * ENDIAN-CONDITIONAL.***  The flags occupy the third and fourth octets
 * of a DNS message and a C bit-field is laid out from the low end on a
 * little-endian machine, so the two arms below are the same twelve
 * bytes read the same way -- which is also why this is a bit-field
 * struct rather than two `uint8_t' and some macros: every caller,
 * php's included, reads `hp->ancount' and friends.  `__BYTE_ORDER'
 * comes from <_apetypes.h>, which <arpa/nameser.h> already reaches
 * through <stdint.h>; APExp targets four big-endian architectures, so
 * the second arm is not decoration.
 */

typedef struct {
	unsigned	id :16;		/* query identification number */
#if defined(__BYTE_ORDER) && defined(__BIG_ENDIAN) && \
    __BYTE_ORDER == __BIG_ENDIAN
			/* fields in third byte */
	unsigned	qr :1;		/* response flag */
	unsigned	opcode :4;	/* purpose of message */
	unsigned	aa :1;		/* authoritative answer */
	unsigned	tc :1;		/* truncated message */
	unsigned	rd :1;		/* recursion desired */
			/* fields in fourth byte */
	unsigned	ra :1;		/* recursion available */
	unsigned	unused :1;	/* unused bits (MBZ as of 4.9.3a3) */
	unsigned	ad :1;		/* authentic data from named */
	unsigned	cd :1;		/* checking disabled by resolver */
	unsigned	rcode :4;	/* response code */
#else
			/* fields in third byte */
	unsigned	rd :1;		/* recursion desired */
	unsigned	tc :1;		/* truncated message */
	unsigned	aa :1;		/* authoritative answer */
	unsigned	opcode :4;	/* purpose of message */
	unsigned	qr :1;		/* response flag */
			/* fields in fourth byte */
	unsigned	rcode :4;	/* response code */
	unsigned	cd :1;		/* checking disabled by resolver */
	unsigned	ad :1;		/* authentic data from named */
	unsigned	unused :1;	/* unused bits (MBZ as of 4.9.3a3) */
	unsigned	ra :1;		/* recursion available */
#endif
			/* remaining bytes */
	unsigned	qdcount :16;	/* number of question entries */
	unsigned	ancount :16;	/* number of answer entries */
	unsigned	nscount :16;	/* number of authority entries */
	unsigned	arcount :16;	/* number of resource entries */
} HEADER;

/*
 * The old spellings of the sizes, limits, opcodes, classes and types.
 * Each is the `ns_' name from <arpa/nameser.h>, so there is one set of
 * numbers and this file invents none of them.
 *
 * *The record-type list is as long as <arpa/nameser.h>'s and no
 * longer*: a `T_' alias for a type that header does not know would be
 * a number written here and nowhere else.
 */
#define PACKETSZ	NS_PACKETSZ
#define MAXDNAME	NS_MAXDNAME
#define MAXCDNAME	NS_MAXCDNAME
#define MAXLABEL	NS_MAXLABEL
#define HFIXEDSZ	NS_HFIXEDSZ
#define QFIXEDSZ	NS_QFIXEDSZ
#define RRFIXEDSZ	NS_RRFIXEDSZ
#define INT32SZ		NS_INT32SZ
#define INT16SZ		NS_INT16SZ
#define INADDRSZ	NS_INADDRSZ
#define IN6ADDRSZ	NS_IN6ADDRSZ
#define INDIR_MASK	NS_CMPRSFLGS
#define NAMESERVER_PORT	NS_DEFAULTPORT

#define T_A		ns_t_a
#define T_NS		ns_t_ns
#define T_CNAME		ns_t_cname
#define T_SOA		ns_t_soa
#define T_PTR		ns_t_ptr
#define T_MX		ns_t_mx
#define T_TXT		ns_t_txt
#define T_AAAA		ns_t_aaaa
#define T_SRV		ns_t_srv
#define T_ANY		ns_t_any

#define C_IN		ns_c_in
#define C_ANY		ns_c_any

/*
 * The BIND 4 accessors, which are <arpa/nameser.h>'s NS_GET/NS_PUT
 * under their old names and argument order.  php's `dns.c' reads a
 * response with twenty-three of these.
 */
#define GETSHORT	NS_GET16
#define GETLONG		NS_GET32
#define PUTSHORT	NS_PUT16
#define PUTLONG		NS_PUT32

#endif /* _ARPA_NAMESER_COMPAT_H */
