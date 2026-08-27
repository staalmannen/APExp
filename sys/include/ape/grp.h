#ifndef __GRP
#define __GRP

/* POSIX: <grp.h> defines size_t and gid_t, so that this header stands on its own. */
#include <stddef.h>

#pragma lib "/$M/lib/ape/libap.a"
#include <sys/types.h>

struct	group {
	char	*gr_name;
	char	*gr_passwd;
	gid_t	gr_gid;
	char	**gr_mem;
};

#ifdef __cplusplus
extern "C" {
#endif

extern struct group *getgrgid(gid_t);
extern struct group *getgrnam(const char *);
extern int getgrgid_r(gid_t, struct group *, char *, size_t, struct group **);
extern int getgrnam_r(const char *, struct group *, char *, size_t, struct group **);

extern int initgroups(const char *, gid_t);

extern struct group *getgrent(void);
extern void setgrent(void);
extern void endgrent(void);

#ifdef __cplusplus
}
#endif

#endif
