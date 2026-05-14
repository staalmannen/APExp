/*
 * __res_msend_rc -- send multiple DNS queries and collect replies
 *
 * Sends nqueries UDP DNS packets to each nameserver listed in conf->ns,
 * matches replies by the 2-byte DNS transaction ID at the start of each
 * packet, and fills answers[i]/alens[i] with the response.
 *
 * Returns 0 if at least one answer was received, -1 if none.
 */

#include <sys/socket.h>
#include <netinet/in.h>
#include <poll.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <time.h>
#include "lookup.h"

/* Maximum intermediate receive buffer size (DNS UDP limit) */
#define DNS_BUFSZ 512

int
__res_msend_rc(int nqueries,
               const unsigned char *const *queries, const int *qlens,
               unsigned char *const *answers, int *alens, int asize,
               const struct resolvconf *conf)
{
	int fd = -1;
	int i, j, a;
	int answered;
	int total_answered;
	unsigned char rbuf[DNS_BUFSZ];
	struct sockaddr_in sin;
	struct sockaddr_in6 sin6;
	struct sockaddr *sa;
	socklen_t salen;
	struct pollfd pfd;
	int timeout_ms;
	ssize_t rlen;
	int ret = -1;

	/* Zero out alens */
	for (i = 0; i < nqueries; i++)
		alens[i] = 0;

	total_answered = 0;

	/* Outer loop: attempts */
	for (a = 0; a < (int)conf->attempts; a++) {
		/* Inner loop: nameservers */
		for (j = 0; j < (int)conf->nns; j++) {
			int family = conf->ns[j].family;

			/* Build sockaddr */
			if (family == AF_INET) {
				memset(&sin, 0, sizeof sin);
				sin.sin_family = AF_INET;
				sin.sin_port = htons(53);
				memcpy(&sin.sin_addr, conf->ns[j].addr, 4);
				sa = (struct sockaddr *)&sin;
				salen = sizeof sin;
			} else if (family == AF_INET6) {
				memset(&sin6, 0, sizeof sin6);
				sin6.sin6_family = AF_INET6;
				sin6.sin6_port = htons(53);
				sin6.sin6_scope_id = conf->ns[j].scopeid;
				memcpy(&sin6.sin6_addr, conf->ns[j].addr, 16);
				sa = (struct sockaddr *)&sin6;
				salen = sizeof sin6;
			} else {
				continue;
			}

			/* Open a UDP socket */
			fd = socket(family, SOCK_DGRAM, 0);
			if (fd < 0)
				continue;

			/* Connect so we can use send/recv */
			if (connect(fd, sa, salen) < 0) {
				close(fd);
				fd = -1;
				continue;
			}

			/* Send all unanswered queries */
			for (i = 0; i < nqueries; i++) {
				if (alens[i] > 0)
					continue; /* already answered */
				send(fd, queries[i], qlens[i], 0);
			}

			/* Poll loop: receive replies until timeout */
			timeout_ms = (int)(conf->timeout * 1000);

			for (;;) {
				answered = 0;
				for (i = 0; i < nqueries; i++)
					if (alens[i] > 0) answered++;
				if (answered == nqueries)
					break; /* all done */

				pfd.fd = fd;
				pfd.events = POLLIN;
				pfd.revents = 0;

				if (poll(&pfd, 1, timeout_ms) <= 0)
					break; /* timeout or error */

				rlen = recv(fd, rbuf, sizeof rbuf, 0);
				if (rlen < 2)
					continue;

				/* Match by DNS transaction ID (first 2 bytes) */
				for (i = 0; i < nqueries; i++) {
					if (alens[i] > 0)
						continue;
					if (qlens[i] >= 2 &&
					    rbuf[0] == queries[i][0] &&
					    rbuf[1] == queries[i][1]) {
						int copy = (int)rlen < asize ? (int)rlen : asize;
						memcpy(answers[i], rbuf, copy);
						alens[i] = copy;
						total_answered++;
						break;
					}
				}
			}

			close(fd);
			fd = -1;

			if (total_answered == nqueries)
				goto done;
		}
	}

done:
	if (fd >= 0)
		close(fd);

	/* Return 0 if we got at least one answer */
	for (i = 0; i < nqueries; i++) {
		if (alens[i] > 0)
			return 0;
	}
	return -1;
}
