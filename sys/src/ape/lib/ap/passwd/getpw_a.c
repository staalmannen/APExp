#include <string.h>
#include <unistd.h>
#include <pwd.h>
#include <errno.h>
#include <stdlib.h>

/*
 * Native Plan 9 implementation of __getpw_a.
 * getlogin() wraps Plan 9's getuser() via unistd.h.
 */
int __getpw_a(const char *name, uid_t uid, struct passwd *pw, char **buf, size_t *size, struct passwd **res)
{
	const char *user;
	size_t len;

	user = getlogin();
	if(user == NULL)
		user = "none";

	if(name != NULL && strcmp(name, user) != 0) {
		*res = NULL;
		return 0;
	}

	len = strlen(user) + 1;
	if(len > *size || !*buf) {
		char *tmp = realloc(*buf, len);
		if(!tmp) return errno;
		*buf = tmp;
		*size = len;
	}

	strcpy(*buf, user);
	pw->pw_name = *buf;
	pw->pw_passwd = "x";
	pw->pw_uid = 0;
	pw->pw_gid = 0;
	pw->pw_gecos = pw->pw_name;
	pw->pw_dir = "/usr/glenda";
	pw->pw_shell = "/bin/rc";

	*res = pw;
	return 0;
}
