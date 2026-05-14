#ifndef _NET_IF_H
#define _NET_IF_H

#include <sys/types.h>
#include <sys/socket.h>

#define IF_NAMESIZE	16
#define IFNAMSIZ	IF_NAMESIZE

struct if_nameindex {
	unsigned int	if_index;
	char		*if_name;
};

#ifdef __cplusplus
extern "C" {
#endif

unsigned int		if_nametoindex(const char *);
char			*if_indextoname(unsigned int, char *);
struct if_nameindex	*if_nameindex(void);
void			if_freenameindex(struct if_nameindex *);

#ifdef __cplusplus
}
#endif

#endif
