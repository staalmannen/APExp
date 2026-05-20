#include <grp.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stdio.h>

/*
 * getgrgid_r / getgrnam_r — reentrant group lookup.
 *
 * Plan9 has no /etc/group in the traditional sense, but we support
 * the Plan9 group file format via getgrent(). We implement the _r
 * variants by iterating through all groups and copying the match
 * into the caller-supplied buffer.
 */

static int
getgr_r(const char *name, gid_t gid, int bygid,
        struct group *grp, char *buf, size_t buflen,
        struct group **result)
{
	struct group *g;
	char **mem;
	char *p;
	size_t n, total;
	int i, nmem;

	*result = NULL;
	setgrent();
	while((g = getgrent()) != NULL) {
		if(bygid ? (g->gr_gid == gid) : (strcmp(g->gr_name, name) == 0))
			break;
	}
	if(g == NULL) {
		endgrent();
		return 0;
	}

	/* count members */
	for(nmem = 0; g->gr_mem[nmem] != NULL; nmem++)
		;

	/* compute needed buffer size:
	 * gr_name\0 + gr_passwd\0 + each member\0 + pointer array */
	total = strlen(g->gr_name) + 1
	      + strlen(g->gr_passwd) + 1;
	for(i = 0; i < nmem; i++)
		total += strlen(g->gr_mem[i]) + 1;
	total += (nmem + 1) * sizeof(char *);
	/* align pointer array */
	total = (total + sizeof(char*) - 1) & ~(sizeof(char*) - 1);

	if(buflen < total) {
		endgrent();
		*result = NULL;
		return ERANGE;
	}

	/* lay out: pointer array first (aligned), then strings */
	mem = (char **)buf;
	p = buf + (nmem + 1) * sizeof(char *);

	n = strlen(g->gr_name) + 1;
	memcpy(p, g->gr_name, n);
	grp->gr_name = p; p += n;

	n = strlen(g->gr_passwd) + 1;
	memcpy(p, g->gr_passwd, n);
	grp->gr_passwd = p; p += n;

	grp->gr_gid = g->gr_gid;

	for(i = 0; i < nmem; i++) {
		n = strlen(g->gr_mem[i]) + 1;
		memcpy(p, g->gr_mem[i], n);
		mem[i] = p; p += n;
	}
	mem[nmem] = NULL;
	grp->gr_mem = mem;

	endgrent();
	*result = grp;
	return 0;
}

int
getgrgid_r(gid_t gid, struct group *grp, char *buf, size_t buflen,
           struct group **result)
{
	return getgr_r(NULL, gid, 1, grp, buf, buflen, result);
}

int
getgrnam_r(const char *name, struct group *grp, char *buf, size_t buflen,
           struct group **result)
{
	return getgr_r(name, 0, 0, grp, buf, buflen, result);
}
