#include <unistd.h>
#include <string.h>
#include <errno.h>

/*
 * confstr - get configuration-defined string values.
 * Only _CS_PATH is commonly needed (by system() and popen()).
 * Others return empty string which is the POSIX-compliant
 * "not defined" response.
 */

#ifndef _CS_PATH
#define _CS_PATH 0
#endif

size_t
confstr(int name, char *buf, size_t len)
{
	const char *val;

	switch(name){
	case _CS_PATH:
		val = "/bin:/usr/bin";
		break;
	default:
		/* not defined: return 0 with no error per POSIX */
		if(buf != NULL && len > 0)
			buf[0] = '\0';
		return 0;
	}

	if(buf != NULL && len > 0){
		strncpy(buf, val, len - 1);
		buf[len - 1] = '\0';
	}
	return strlen(val) + 1;
}
