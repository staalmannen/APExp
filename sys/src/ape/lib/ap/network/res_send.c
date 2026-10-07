#include <resolv.h>
#include <string.h>

int __res_send(const unsigned char *msg, int msglen, unsigned char *answer, int anslen)
{
	int r;
	if (anslen < 512) {
		unsigned char buf[512];
		r = __res_send(msg, msglen, buf, sizeof buf);
		if (r >= 0) memcpy(answer, buf, r < anslen ? r : anslen);
		return r;
	}
	r = __res_msend(1, &msg, &msglen, &answer, &anslen, anslen);
	return r<0 || !anslen ? -1 : anslen;
}

/* kencc has no weak symbols, so this is a no-op -- but it used to
 * arrive from the PUBLIC <features.h>, where its parameter names
 * had to be kept matching an external package's to avoid a cpp
 * redefinition error. Supplied privately instead. */
#ifndef weak_alias
#define weak_alias(name, aliasname) /* no weak alias on Plan9 */
#endif

weak_alias(__res_send, res_send);
