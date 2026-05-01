#ifndef _UNICTYPE_H
#define _UNICTYPE_H

#include <unitypes.h>

int uc_is_alpha(ucs4_t r);
int uc_is_digit(ucs4_t r);
int uc_is_lower(ucs4_t r);
int uc_is_upper(ucs4_t r);
int uc_is_space(ucs4_t r);
int uc_is_punct(ucs4_t r);
int uc_is_graph(ucs4_t r);
int uc_is_print(ucs4_t r);

#endif
