#ifndef _MONETARY_H
#define _MONETARY_H

#ifdef __cplusplus
extern "C" {
#endif

#include <features.h>
#include <alltypes.h>

ssize_t strfmon(char *, size_t, const char *, ...);
ssize_t strfmon_l(char *, size_t, locale_t, const char *, ...);

#ifdef __cplusplus
}
#endif

#endif
