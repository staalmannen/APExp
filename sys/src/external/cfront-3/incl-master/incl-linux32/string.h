/* @(#) string.h 1.3 1/27/86 17:47:04 */
/*ident	"@(#)cfront:incl/string.h	1.3"*/

extern  "C" {
    
#ifndef __STDDEF_H
#include <stddef.h>
#endif
    
    char
	*strcpy(char*, const char*),
	*strncpy(char*, const char*, size_t),
	*strcat(char*, const char*),
	*strncat(char*, const char*, size_t),
	*strchr(const char*, int),
	*strrchr(const char*, int),
	*strpbrk(const char*, const char*),
	*strtok(char*, const char*),
	*strdup(const char*);
    int
	strcmp(const char*, const char*),
	strncmp(const char*, const char*, size_t);
    size_t
	strlen(const char*),
	strspn(const char*, const char*),
	strcspn(const char*, const char*);
    void
	*memccpy(char *, const char *, int, int),
	*memchr(const void *, int, size_t),
	*memcpy(void *, const void *, size_t),
	*memset(void *, int, size_t);
    int memcmp(const void *, const void *, size_t);
}
