#include <unictype.h>
#include <utf.h>

int uc_is_alpha(Rune r) { return isalpharune(r); }
int uc_is_digit(Rune r) { return isdigitrune(r); }
int uc_is_lower(Rune r) { return islowerrune(r); }
int uc_is_upper(Rune r) { return isupperrune(r); }
int uc_is_space(Rune r) { return isspacerune(r); }
int uc_is_punct(Rune r) { return ispunctrune(r); }
int uc_is_graph(Rune r) { return isgraphrune(r); }
int uc_is_print(Rune r) { return isprintrune(r); }
