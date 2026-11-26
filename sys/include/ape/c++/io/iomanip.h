// ***************************************************************************
// * APExp minimal iostreams -- the parameterised manipulators.
// *
// * Project="APExp C++ library" File="io/iomanip.h"
// *
// * SPDX-License-Identifier: MIT
// ***************************************************************************
//
// `setw', `setfill', `setprecision', `setbase', `setiosflags',
// `resetiosflags'.  Each returns a small object with its own inserter and
// extractor, which is how a manipulator takes an argument at all.
//
// **`setfill' is templated on the character type and the others are
// not**, because only `setfill' carries one; writing all six as templates
// would make `std::setw(4)' ambiguous at every use.
//
// `get_money`, `put_money`, `get_time`, `put_time` are ABSENT: all four
// are defined in terms of locale facets, and a version of them that
// ignored the locale would answer plausibly and wrongly.  That is the
// stub-that-answers-the-wrong-thing family this tree keeps paying for,
// so they are a compile error instead.

#ifndef APEXP_STD_IO_IOMANIP_H
#define APEXP_STD_IO_IOMANIP_H

#include "istream.h"

namespace std {

namespace io_detail {

  struct setw_t final {
    ::std::streamsize m_n;
  };
  struct setprecision_t final {
    ::std::streamsize m_n;
  };
  struct setbase_t final {
    int m_base;
  };
  struct setiosflags_t final {
    ::std::ios_base::fmtflags m_mask;
  };
  struct resetiosflags_t final {
    ::std::ios_base::fmtflags m_mask;
  };
  template<class t_char> struct setfill_t final {
    t_char m_c;
  };

} // namespace io_detail

inline io_detail::setw_t setw(int in_n) {
  return io_detail::setw_t{static_cast<::std::streamsize>(in_n)};
}
inline io_detail::setprecision_t setprecision(int in_n) {
  return io_detail::setprecision_t{static_cast<::std::streamsize>(in_n)};
}
inline io_detail::setbase_t setbase(int in_base) {
  return io_detail::setbase_t{in_base};
}
inline io_detail::setiosflags_t setiosflags(::std::ios_base::fmtflags in_mask) {
  return io_detail::setiosflags_t{in_mask};
}
inline io_detail::resetiosflags_t resetiosflags(::std::ios_base::fmtflags in_mask) {
  return io_detail::resetiosflags_t{in_mask};
}
template<class t_char> inline io_detail::setfill_t<t_char> setfill(t_char in_c) {
  return io_detail::setfill_t<t_char>{in_c};
}

namespace io_detail {

  inline void apply(::std::ios_base &s, setw_t const &m) {
    s.width(m.m_n);
  }
  inline void apply(::std::ios_base &s, setprecision_t const &m) {
    s.precision(m.m_n);
  }
  inline void apply(::std::ios_base &s, setiosflags_t const &m) {
    s.setf(m.m_mask);
  }
  inline void apply(::std::ios_base &s, resetiosflags_t const &m) {
    s.unsetf(m.m_mask);
  }
  // An unrecognised base LEAVES THE FIELD ALONE, as [std.manip] says --
  // it does not clear it, which a `setf(0, basefield)' would do and
  // which would silently switch a hex stream to "no base set".
  inline void apply(::std::ios_base &s, setbase_t const &m) {
    ::std::ios_base::fmtflags f{};
    if (8 == m.m_base) {
      f = ::std::ios_base::oct;
    } else if (10 == m.m_base) {
      f = ::std::ios_base::dec;
    } else if (16 == m.m_base) {
      f = ::std::ios_base::hex;
    } else {
      return;
    }
    s.setf(f, ::std::ios_base::basefield);
  }

} // namespace io_detail

#define APEXP_IO_MANIP_INSERTER(T)                                                       \
  template<class t_char, class t_traits>                                                 \
  inline ::std::basic_ostream<t_char, t_traits> &operator<<(                             \
      ::std::basic_ostream<t_char, t_traits> &os, ::std::io_detail::T const &m) {        \
    ::std::io_detail::apply(os, m);                                                      \
    return os;                                                                           \
  }                                                                                      \
  template<class t_char, class t_traits>                                                 \
  inline ::std::basic_istream<t_char, t_traits> &operator>>(                             \
      ::std::basic_istream<t_char, t_traits> &is, ::std::io_detail::T const &m) {        \
    ::std::io_detail::apply(is, m);                                                      \
    return is;                                                                           \
  }

APEXP_IO_MANIP_INSERTER(setw_t)
APEXP_IO_MANIP_INSERTER(setprecision_t)
APEXP_IO_MANIP_INSERTER(setbase_t)
APEXP_IO_MANIP_INSERTER(setiosflags_t)
APEXP_IO_MANIP_INSERTER(resetiosflags_t)

#undef APEXP_IO_MANIP_INSERTER

// `setfill' needs the stream's own character type, so it goes through
// `basic_ios::fill' rather than `ios_base'.
template<class t_char, class t_traits>
inline ::std::basic_ostream<t_char, t_traits> &
operator<<(::std::basic_ostream<t_char, t_traits> &os,
           ::std::io_detail::setfill_t<t_char> const &m) {
  os.fill(m.m_c);
  return os;
}
template<class t_char, class t_traits>
inline ::std::basic_istream<t_char, t_traits> &
operator>>(::std::basic_istream<t_char, t_traits> &is,
           ::std::io_detail::setfill_t<t_char> const &m) {
  is.fill(m.m_c);
  return is;
}

} // namespace std

#endif // APEXP_STD_IO_IOMANIP_H
