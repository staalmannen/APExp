#ifndef _ARPA_NAMESER_H
#define _ARPA_NAMESER_H

/* used in the buffer sizes, so that this header stands on its own. */
#include <stddef.h>

#include <stdint.h>
#include <sys/types.h>

/*
 * Byte sizes for DNS wire format fields.
 */
#define NS_INT8SZ	1
#define NS_INT16SZ	2
#define NS_INT32SZ	4

/*
 * DNS limits.
 */
#define NS_PACKETSZ	512	/* default UDP packet size */
#define NS_MAXDNAME	1025	/* max domain name (presentation) */
#define NS_MAXCDNAME	255	/* max compressed domain name */
#define NS_MAXLABEL	63	/* max label octets */
#define NS_MAXMSG	65535	/* max message size */
#define NS_MAXDNSRCH	6	/* max domains in search path */

/*
 * The fixed sizes of the wire format's own records, and the two
 * address sizes.  Added with <arpa/nameser_compat.h>, which aliases
 * each of them to its BIND 4 name -- so there is one set of numbers
 * and the compat header invents none.  They are the protocol's: a
 * header is 12 octets, a question's fixed part 4, a resource record's
 * 10, and 0xc0 is the two high bits that mark a compression pointer.
 */
#define NS_HFIXEDSZ	12	/* fixed data in header */
#define NS_QFIXEDSZ	4	/* fixed data in query */
#define NS_RRFIXEDSZ	10	/* fixed data in r record */
#define NS_INADDRSZ	4	/* IPv4 address */
#define NS_IN6ADDRSZ	16	/* IPv6 address */
#define NS_CMPRSFLGS	0xc0	/* flag bits indicating name compression */
#define NS_DEFAULTPORT	53	/* for both TCP and UDP */

/*
 * Macros to read big-endian 16- and 32-bit values from a pointer,
 * advancing the pointer past the consumed bytes.
 */
#define NS_GET16(s, cp) do { \
	const unsigned char *_t = (const unsigned char *)(cp); \
	(s) = ((uint16_t)_t[0] << 8) | (uint16_t)_t[1]; \
	(cp) += NS_INT16SZ; \
} while (0)

#define NS_GET32(l, cp) do { \
	const unsigned char *_t = (const unsigned char *)(cp); \
	(l) = ((uint32_t)_t[0] << 24) | ((uint32_t)_t[1] << 16) | \
	      ((uint32_t)_t[2] << 8)  | (uint32_t)_t[3]; \
	(cp) += NS_INT32SZ; \
} while (0)

#define NS_PUT16(s, cp) do { \
	unsigned char *_t = (unsigned char *)(cp); \
	_t[0] = (unsigned char)((s) >> 8); \
	_t[1] = (unsigned char)(s); \
	(cp) += NS_INT16SZ; \
} while (0)

#define NS_PUT32(l, cp) do { \
	unsigned char *_t = (unsigned char *)(cp); \
	_t[0] = (unsigned char)((l) >> 24); \
	_t[1] = (unsigned char)((l) >> 16); \
	_t[2] = (unsigned char)((l) >> 8); \
	_t[3] = (unsigned char)(l); \
	(cp) += NS_INT32SZ; \
} while (0)

/*
 * DNS message sections.
 */
typedef enum {
	ns_s_qd = 0,	/* Question */
	ns_s_zn = 0,	/* Zone (update) */
	ns_s_an = 1,	/* Answer */
	ns_s_pr = 1,	/* Prerequisites (update) */
	ns_s_ns = 2,	/* Authority */
	ns_s_ud = 2,	/* Update section */
	ns_s_ar = 3,	/* Additional */
	ns_s_max = 4
} ns_sect;

/*
 * Parsed DNS message handle.
 */
typedef struct {
	const unsigned char	*_msg, *_eom;
	uint16_t		_id, _flags;
	uint16_t		_counts[ns_s_max];
	const unsigned char	*_sections[ns_s_max];
	ns_sect			_sect;
	int			_rrnum;
	const unsigned char	*_msg_ptr;
} ns_msg;

/*
 * Parsed DNS resource record.
 */
typedef struct {
	char			name[NS_MAXDNAME];
	uint16_t		type;
	uint16_t		rr_class;
	uint32_t		ttl;
	uint16_t		rdlength;
	const unsigned char	*rdata;
} ns_rr;

/*
 * Flag data table (used internally by ns_parse.c).
 */
struct _ns_flagdata { int mask, shift; };
extern const struct _ns_flagdata _ns_flagdata[16];

/*
 * DNS record types.
 */
#define ns_t_a		1
#define ns_t_ns		2
#define ns_t_cname	5
#define ns_t_soa	6
#define ns_t_ptr	12
#define ns_t_mx		15
#define ns_t_txt	16
#define ns_t_aaaa	28
#define ns_t_srv	33
#define ns_t_any	255
typedef uint16_t ns_type;

/*
 * DNS record classes.
 */
#define ns_c_in		1
#define ns_c_any	255
typedef uint16_t ns_class;

/*
 * Functions.
 */
#ifdef __cplusplus
extern "C" {
#endif

int ns_initparse(const unsigned char *, int, ns_msg *);
int ns_skiprr(const unsigned char *, const unsigned char *, ns_sect, int);
int ns_parserr(ns_msg *, ns_sect, int, ns_rr *);
int ns_name_uncompress(const unsigned char *, const unsigned char *,
	const unsigned char *, char *, size_t);

unsigned ns_get16(const unsigned char *);
unsigned long ns_get32(const unsigned char *);
void ns_put16(unsigned, unsigned char *);
void ns_put32(unsigned long, unsigned char *);

#ifdef __cplusplus
}
#endif

/*
 * BIND 4's names, which this header's `ns_' forms replaced.  Included
 * unconditionally, as glibc, musl and the BSDs all do: `HEADER' and
 * `C_IN' are reachable by including <arpa/nameser.h> and by nothing
 * else, which is what portable code expects.
 */
#include <arpa/nameser_compat.h>

#endif
