#ifndef UTIL_H
#define UTIL_H

#include <stddef.h>

void *xmalloc(size_t n);
void *xrealloc(void *p, size_t n);
char *xstrdup(const char *s);
char *xstrndup(const char *s, size_t n);

int path_is_abs(const char *p);
char *path_join(const char *a, const char *b);
char *path_dir(const char *p);
char *path_norm(const char *p);
char *shell_escape(const char *s);

#endif
