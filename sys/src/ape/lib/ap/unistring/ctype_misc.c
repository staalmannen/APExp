#include <unictype.h>
#include <utf.h>

int uc_is_alpha(ucs4_t r) { return isalpharune(r); }
int uc_is_digit(ucs4_t r) { return isdigitrune(r); }
int uc_is_lower(ucs4_t r) { return islowerrune(r); }
int uc_is_upper(ucs4_t r) { return isupperrune(r); }
int uc_is_space(ucs4_t r) { return isspacerune(r); }
int uc_is_punct(ucs4_t r) { return ispunctrune(r); }
int uc_is_graph(ucs4_t r) { return isgraphrune(r); }
int uc_is_print(ucs4_t r) { return isprintrune(r); }
