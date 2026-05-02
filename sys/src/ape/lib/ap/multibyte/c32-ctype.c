#include <uchar.h>
#include <wchar.h>
#include <utf.h>

int c32isalnum(char32_t r) { return isalnumrune(r); }
int c32isalpha(char32_t r) { return isalpharune(r); }
int c32isblank(char32_t r) { return isblankrune(r); }
int c32iscntrl(char32_t r) { return iscntrlrune(r); }
int c32isdigit(char32_t r) { return isdigitrune(r); }
int c32isgraph(char32_t r) { return isgraphrune(r); }
int c32islower(char32_t r) { return islowerrune(r); }
int c32isprint(char32_t r) { return isprintrune(r); }
int c32ispunct(char32_t r) { return ispunctrune(r); }
int c32isspace(char32_t r) { return isspacerune(r); }
int c32isupper(char32_t r) { return isupperrune(r); }
int c32isxdigit(char32_t r) { return isxdigitrune(r); }
int c32width(char32_t r) { return wcwidth(r); }
