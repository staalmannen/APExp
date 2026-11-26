// ***************************************************************************
// * APExp minimal iostreams -- `basic_ios' and the flag manipulators.
// *
// * Project="APExp C++ library" File="io/basic_ios.h"
// *
// * SPDX-License-Identifier: MIT
// ***************************************************************************
//
// `basic_ios' holds the state bits, the fill character, the tied stream
// and the `rdbuf' pointer.  The flag manipulators (`hex', `left',
// `boolalpha', ...) live here because they are `ios_base &' in and out
// and so belong to neither direction.
//
// ***THE EXCEPTION MASK IS HONOURED AND THE DEFAULT IS `goodbit'.***  So
// nothing here throws unless a caller asks it to, which is what lets this
// stack sit on top of an exception-free library without the two
// conventions arguing.  `setstate' consults the mask only where the
// compiler says exceptions exist (`__EXCEPTIONS' for g++,
// `__EDG_EXCEPTIONS' / `__cpp_exceptions' for cpfe), and *where they do
// not, the mask is stored and not acted on* -- a difference that is
// documented rather than silent, because a caller who sets the mask and
// gets no throw would otherwise read the stream as always succeeding.

#ifndef APEXP_STD_IO_BASIC_IOS_H
#define APEXP_STD_IO_BASIC_IOS_H

#include "ios_base.h"
#include "streambuf.h"

#if defined(__cpp_exceptions) || defined(__EXCEPTIONS) || defined(__EDG_EXCEPTIONS)
#  define APEXP_IOS_CAN_THROW 1
#else
#  define APEXP_IOS_CAN_THROW 0
#endif

namespace std {

template<class t_char, class t_traits> class basic_ios : public ::std::ios_base {
public:
  using char_type   = t_char;
  using traits_type = t_traits;
  using int_type    = typename t_traits::int_type;
  using pos_type    = typename t_traits::pos_type;
  using off_type    = typename t_traits::off_type;

  explicit operator bool() const noexcept {
    return !this->fail();
  }
  bool operator!() const noexcept {
    return this->fail();
  }

  iostate rdstate() const noexcept {
    return m_state;
  }
  void clear(iostate in_state = goodbit) {
    m_state = (nullptr != m_buf) ? in_state : (in_state | badbit);
    this->check_exceptions();
  }
  void setstate(iostate in_state) {
    this->clear(m_state | in_state);
  }
  bool good() const noexcept { return goodbit == m_state; }
  bool eof() const noexcept { return 0U != (m_state & eofbit); }
  bool fail() const noexcept { return 0U != (m_state & (failbit | badbit)); }
  bool bad() const noexcept { return 0U != (m_state & badbit); }

  iostate exceptions() const noexcept {
    return m_except;
  }
  void exceptions(iostate in_except) {
    m_except = in_except;
    this->check_exceptions();
  }

  basic_ostream<t_char, t_traits> *tie() const noexcept {
    return m_tie;
  }
  basic_ostream<t_char, t_traits> *tie(basic_ostream<t_char, t_traits> *in_tie) noexcept {
    basic_ostream<t_char, t_traits> *const old{m_tie};
    m_tie = in_tie;
    return old;
  }

  basic_streambuf<t_char, t_traits> *rdbuf() const noexcept {
    return m_buf;
  }
  basic_streambuf<t_char, t_traits> *rdbuf(basic_streambuf<t_char, t_traits> *in_buf) {
    basic_streambuf<t_char, t_traits> *const old{m_buf};
    m_buf = in_buf;
    this->clear();
    return old;
  }

  char_type fill() const noexcept {
    return m_fill;
  }
  char_type fill(char_type in_fill) noexcept {
    char_type const old{m_fill};
    m_fill = in_fill;
    return old;
  }

  basic_ios &copyfmt(basic_ios const &other) {
    if (this != &other) {
      this->copyfmt_base(other);
      m_fill = other.m_fill;
      m_tie  = other.m_tie;
      this->exceptions(other.m_except);
    }
    return *this;
  }

  // `widen'/`narrow' with no locale: the identity for `char', and the
  // trivial conversion otherwise.  Enough for the digits and punctuation
  // the formatting code produces, which is all either is used for here.
  char narrow(char_type in_c, char in_dfault) const {
    int_type const v{traits_type::to_int_type(in_c)};
    if ((v >= 0) && (v < 128)) {
      return static_cast<char>(v);
    }
    return in_dfault;
  }
  char_type widen(char in_c) const {
    return traits_type::to_char_type(static_cast<int_type>(static_cast<unsigned char>(in_c)));
  }

protected:
  basic_ios() noexcept
      : ::std::ios_base{}, m_buf{nullptr}, m_tie{nullptr}, m_state{badbit},
        m_except{goodbit}, m_fill{static_cast<char_type>(' ')} {
  }
  explicit basic_ios(basic_streambuf<t_char, t_traits> *in_buf) : basic_ios{} {
    this->init(in_buf);
  }

public:
  // Virtual, as [ios] specifies: `basic_ostream' and `basic_istream'
  // derive from this virtually and a `delete' through either base has
  // to reach the right destructor.
  virtual ~basic_ios() = default;

protected:

  void init(basic_streambuf<t_char, t_traits> *in_buf) {
    m_buf    = in_buf;
    m_tie    = nullptr;
    m_state  = (nullptr != in_buf) ? goodbit : badbit;
    m_except = goodbit;
    m_fill   = static_cast<char_type>(' ');
  }

  void move_ios(basic_ios &other) noexcept {
    this->copyfmt_base(other);
    m_buf       = nullptr;
    m_tie       = other.m_tie;
    m_state     = other.m_state;
    m_except    = other.m_except;
    m_fill      = other.m_fill;
    other.m_tie = nullptr;
  }

private:
  void check_exceptions() const {
#if APEXP_IOS_CAN_THROW
    if (0U != (m_state & m_except)) {
      throw ::std::ios_base::failure{};
    }
#endif
  }

  basic_streambuf<t_char, t_traits> *m_buf;
  basic_ostream<t_char, t_traits>   *m_tie;
  iostate                            m_state;
  iostate                            m_except;
  char_type                          m_fill;
};

// ---- the flag manipulators ---------------------------------------------

inline ::std::ios_base &boolalpha(::std::ios_base &s) {
  s.setf(::std::ios_base::boolalpha);
  return s;
}
inline ::std::ios_base &noboolalpha(::std::ios_base &s) {
  s.unsetf(::std::ios_base::boolalpha);
  return s;
}
inline ::std::ios_base &showbase(::std::ios_base &s) {
  s.setf(::std::ios_base::showbase);
  return s;
}
inline ::std::ios_base &noshowbase(::std::ios_base &s) {
  s.unsetf(::std::ios_base::showbase);
  return s;
}
inline ::std::ios_base &showpoint(::std::ios_base &s) {
  s.setf(::std::ios_base::showpoint);
  return s;
}
inline ::std::ios_base &noshowpoint(::std::ios_base &s) {
  s.unsetf(::std::ios_base::showpoint);
  return s;
}
inline ::std::ios_base &showpos(::std::ios_base &s) {
  s.setf(::std::ios_base::showpos);
  return s;
}
inline ::std::ios_base &noshowpos(::std::ios_base &s) {
  s.unsetf(::std::ios_base::showpos);
  return s;
}
inline ::std::ios_base &skipws(::std::ios_base &s) {
  s.setf(::std::ios_base::skipws);
  return s;
}
inline ::std::ios_base &noskipws(::std::ios_base &s) {
  s.unsetf(::std::ios_base::skipws);
  return s;
}
inline ::std::ios_base &uppercase(::std::ios_base &s) {
  s.setf(::std::ios_base::uppercase);
  return s;
}
inline ::std::ios_base &nouppercase(::std::ios_base &s) {
  s.unsetf(::std::ios_base::uppercase);
  return s;
}
inline ::std::ios_base &unitbuf(::std::ios_base &s) {
  s.setf(::std::ios_base::unitbuf);
  return s;
}
inline ::std::ios_base &nounitbuf(::std::ios_base &s) {
  s.unsetf(::std::ios_base::unitbuf);
  return s;
}
inline ::std::ios_base &internal(::std::ios_base &s) {
  s.setf(::std::ios_base::internal, ::std::ios_base::adjustfield);
  return s;
}
inline ::std::ios_base &left(::std::ios_base &s) {
  s.setf(::std::ios_base::left, ::std::ios_base::adjustfield);
  return s;
}
inline ::std::ios_base &right(::std::ios_base &s) {
  s.setf(::std::ios_base::right, ::std::ios_base::adjustfield);
  return s;
}
inline ::std::ios_base &dec(::std::ios_base &s) {
  s.setf(::std::ios_base::dec, ::std::ios_base::basefield);
  return s;
}
inline ::std::ios_base &hex(::std::ios_base &s) {
  s.setf(::std::ios_base::hex, ::std::ios_base::basefield);
  return s;
}
inline ::std::ios_base &oct(::std::ios_base &s) {
  s.setf(::std::ios_base::oct, ::std::ios_base::basefield);
  return s;
}
inline ::std::ios_base &fixed(::std::ios_base &s) {
  s.setf(::std::ios_base::fixed, ::std::ios_base::floatfield);
  return s;
}
inline ::std::ios_base &scientific(::std::ios_base &s) {
  s.setf(::std::ios_base::scientific, ::std::ios_base::floatfield);
  return s;
}

} // namespace std

#endif // APEXP_STD_IO_BASIC_IOS_H
