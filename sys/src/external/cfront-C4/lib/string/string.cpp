/* string.cpp — out-of-line definitions for the string class from h/string.h.
 * Only npos and the iostream operators live here; everything else is inline. */
#include <string.h>

const size_t string::npos = (size_t)-1;

#ifdef IOSTREAMH
#include <iostream.h>

ostream& operator<<(ostream& os, const string& s) {
    return os << s.c_str();
}

istream& operator>>(istream& is, string& s) {
    s.clear();
    char c;
    while (is.get(c) && c != ' ' && c != '\t' && c != '\n')
        s += c;
    return is;
}

istream& getline(istream& is, string& s, char delim) {
    s.clear();
    char c;
    while (is.get(c) && c != delim)
        s += c;
    return is;
}
#endif
