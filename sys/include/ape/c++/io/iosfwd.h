// ***************************************************************************
// * APExp minimal iostreams.
// *
// * Project="APExp C++ library" File="io/iosfwd.h"
// *
// * SPDX-License-Identifier: MIT
// ***************************************************************************
//
// ---- WHAT THIS IS AND WHY IT IS HAND-WRITTEN ------------------------------
//
// portable_stl omits iostreams DELIBERATELY: it is exception-free and
// embedded-oriented, and iostreams drag in streambuf, the locale and facet
// machinery and `num_put'/`num_get'.  That omission is what gates re2c --
// five of the ten headers it wants are this stack.
//
// So this is a MINIMAL iostreams written for this tree rather than lifted:
// no `<locale>', no facets, no `codecvt', no `money_get'/`time_put'.
// Number formatting goes through `snprintf' and parsing through
// `strtol'/`strtod', which is what the C library already does correctly
// here and what every one of those facets would otherwise reimplement.
//
// **It is header-only, and that is forced rather than preferred.**
// `rc/bin/ape/eccp''s munch pass scans the OBJECT FILES on the link line
// with `nm' for `__sti__<tu>' -- *an archive member is pulled only on
// demand and is never scanned*, so a static constructor inside a
// `libc++.a' would never be registered and would never run.  The standard
// specifies `std::ios_base::Init' as an object declared in `<iostream>'
// for exactly this reason: the initialiser then lives in the USER's
// translation unit, which munch does see.  `io/iostream.h' uses that
// shape.  *A libc++ archive becomes possible the day eccp also scans the
// archives it links, and is not needed before then.*
//
// ---- WHAT IS DELIBERATELY ABSENT, so a reader does not over-read -----------
//
//   * `<locale>' and every facet.  `imbue' is accepted and ignored, which
//     is a stub that answers NOTHING TO DO rather than one that answers
//     failure -- there is one locale here and it is the C locale.
//   * `std::ios_base::failure' throwing by default.  The exception mask is
//     stored and honoured, and the default mask is `goodbit', so nothing
//     throws unless a caller asks for it.
//   * `wstring_convert', `codecvt'.  A `wchar_t' stream writes
//     `sizeof(wchar_t)' units; it does not transcode.
//
// `pos_type' is `char_traits<T>::pos_type', which this library makes
// `size_t' rather than `fpos<mbstate_t>'.  That is portable_stl's choice
// and it is kept rather than fought: nothing here needs a conversion
// state, and disagreeing with `char_traits' would be worse than
// disagreeing with the standard.

#ifndef APEXP_STD_IO_IOSFWD_H
#define APEXP_STD_IO_IOSFWD_H

#include "../common/size_t.h"
#include "../string/char_traits.h"

namespace std {

using streamoff  = ::std::int64_t;
using streamsize = ::std::int64_t;

class ios_base;

template<class t_char, class t_traits = ::std::char_traits<t_char>> class basic_ios;
template<class t_char, class t_traits = ::std::char_traits<t_char>> class basic_streambuf;
template<class t_char, class t_traits = ::std::char_traits<t_char>> class basic_ostream;
template<class t_char, class t_traits = ::std::char_traits<t_char>> class basic_istream;
template<class t_char, class t_traits = ::std::char_traits<t_char>> class basic_iostream;
template<class t_char, class t_traits = ::std::char_traits<t_char>> class basic_stringbuf;
template<class t_char, class t_traits = ::std::char_traits<t_char>> class basic_istringstream;
template<class t_char, class t_traits = ::std::char_traits<t_char>> class basic_ostringstream;
template<class t_char, class t_traits = ::std::char_traits<t_char>> class basic_stringstream;
template<class t_char, class t_traits = ::std::char_traits<t_char>> class basic_filebuf;
template<class t_char, class t_traits = ::std::char_traits<t_char>> class basic_ifstream;
template<class t_char, class t_traits = ::std::char_traits<t_char>> class basic_ofstream;
template<class t_char, class t_traits = ::std::char_traits<t_char>> class basic_fstream;

using ios        = basic_ios<char>;
using streambuf  = basic_streambuf<char>;
using ostream    = basic_ostream<char>;
using istream    = basic_istream<char>;
using iostream   = basic_iostream<char>;
using stringbuf  = basic_stringbuf<char>;
using istringstream = basic_istringstream<char>;
using ostringstream = basic_ostringstream<char>;
using stringstream  = basic_stringstream<char>;
using filebuf    = basic_filebuf<char>;
using ifstream   = basic_ifstream<char>;
using ofstream   = basic_ofstream<char>;
using fstream    = basic_fstream<char>;

using wios        = basic_ios<wchar_t>;
using wstreambuf  = basic_streambuf<wchar_t>;
using wostream    = basic_ostream<wchar_t>;
using wistream    = basic_istream<wchar_t>;
using wiostream   = basic_iostream<wchar_t>;
using wstringbuf  = basic_stringbuf<wchar_t>;
using wistringstream = basic_istringstream<wchar_t>;
using wostringstream = basic_ostringstream<wchar_t>;
using wstringstream  = basic_stringstream<wchar_t>;
using wfilebuf    = basic_filebuf<wchar_t>;
using wifstream   = basic_ifstream<wchar_t>;
using wofstream   = basic_ofstream<wchar_t>;
using wfstream    = basic_fstream<wchar_t>;

} // namespace std

#endif // APEXP_STD_IO_IOSFWD_H
