#ifndef STR_H
#define STR_H

#include <stddef.h>

struct Str {
	char *s;
	size_t len;
	size_t cap;
};

void str_init(struct Str *b);
void str_free(struct Str *b);
int str_add(struct Str *b, const char *s);
int str_addc(struct Str *b, char c);
char *str_finish(struct Str *b);

char *str_trim(char *s);
char *str_join_space(const char *a, const char *b);

#endif
