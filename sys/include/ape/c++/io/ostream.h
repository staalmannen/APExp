// ***************************************************************************
// * APExp minimal iostreams -- `basic_ostream'.
// *
// * Project="APExp C++ library" File="io/ostream.h"
// *
// * SPDX-License-Identifier: MIT
// ***************************************************************************
//
// ---- HOW NUMBERS ARE FORMATTED, AND WHY NOT A FACET -----------------------
//
// The standard routes every arithmetic inserter through `num_put', a
// locale facet.  There is no `<locale>' here, so each one builds a
// `printf' conversion specifier from the format flags and calls
// `snprintf' -- which is the SAME C library function every `num_put'
// implementation ends up calling, reached directly instead of through
// three virtual dispatches and a facet lookup.
//
// **`snprintf' and not `sprintf', and the buffer is sized from
// `numeric_limits'** rather than from a round number: 64 bits of octal
// is 22 digits, a `long double' in `%f' at precision 60 is far longer,
// so the width and precision are CLAMPED and the overflow case pads by
// hand.  *A formatter that can be made to overrun by a `setw' is a bug
// a caller controls*, which is the worst kind.
//
// **The padding is done here and not by `%*d'.**  `printf''s own width
// cannot express `internal' adjustment (sign or base prefix left, digits
// right), and more importantly `ios_base::width' is consumed by every
// inserter whether it pads or not -- a rule `%*d' has no way to carry.
//
// ***THE WIDE CASE WIDENS ASCII RATHER THAN CALLING A WIDE printf.***
// Every character `snprintf' can produce for a number is ASCII, so the
// narrow result is converted one character at a time through
// `traits_type::to_char_type'.  That is exact for every encoding this
// tree supports and needs no `swprintf', which APE does not uniformly
// have.

#ifndef APEXP_STD_IO_OSTREAM_H
#define APEXP_STD_IO_OSTREAM_H

#include "basic_ios.h"
#include "../common/numeric_limits.h"
#include "../cstdio.stdh"
#include "../cstring.stdh"

namespace std {

namespace io_detail {

  // Longest thing any inserter below can produce before padding: a
  // `long double' in `%f' with the precision clamped to
  // APEXP_IO_MAX_PRECISION, plus sign, point and exponent.
  constexpr int max_precision = 512;
  constexpr ::std::size_t numbuf_size
      = static_cast<::std::size_t>(::std::numeric_limits<long double>::max_exponent10)
        + static_cast<::std::size_t>(max_precision) + 64U;

  // Build a printf specifier for an integer from the format flags.
  // `in_length' is the length modifier ("", "l", "ll", "z").
  inline void int_spec(char *out_spec, ::std::ios_base::fmtflags in_flags,
                       char const *in_length, bool in_signed) {
    char *p{out_spec};
    *p++ = '%';
    if (0U != (in_flags & ::std::ios_base::showpos)) {
      *p++ = '+';
    }
    if (0U != (in_flags & ::std::ios_base::showbase)) {
      *p++ = '#';
    }
    char const *q{in_length};
    while ('\0' != *q) {
      *p++ = *q++;
    }
    ::std::ios_base::fmtflags const base{in_flags & ::std::ios_base::basefield};
    if (::std::ios_base::oct == base) {
      *p++ = 'o';
    } else if (::std::ios_base::hex == base) {
      *p++ = (0U != (in_flags & ::std::ios_base::uppercase)) ? 'X' : 'x';
    } else {
      *p++ = in_signed ? 'd' : 'u';
    }
    *p = '\0';
  }

  inline void float_spec(char *out_spec, ::std::ios_base::fmtflags in_flags,
                         int in_prec, bool in_long) {
    char *p{out_spec};
    *p++ = '%';
    if (0U != (in_flags & ::std::ios_base::showpos)) {
      *p++ = '+';
    }
    if (0U != (in_flags & ::std::ios_base::showpoint)) {
      *p++ = '#';
    }
    *p++ = '.';
    // precision, decimal, at most three digits (clamped by the caller)
    if (in_prec >= 100) {
      *p++ = static_cast<char>('0' + (in_prec / 100));
    }
    if (in_prec >= 10) {
      *p++ = static_cast<char>('0' + ((in_prec / 10) % 10));
    }
    *p++ = static_cast<char>('0' + (in_prec % 10));
    if (in_long) {
      *p++ = 'L';
    }
    ::std::ios_base::fmtflags const ff{in_flags & ::std::ios_base::floatfield};
    bool const                      up{0U != (in_flags & ::std::ios_base::uppercase)};
    if (::std::ios_base::fixed == ff) {
      *p++ = up ? 'F' : 'f';
    } else if (::std::ios_base::scientific == ff) {
      *p++ = up ? 'E' : 'e';
    } else {
      *p++ = up ? 'G' : 'g';
    }
    *p = '\0';
  }

} // namespace io_detail

template<class t_char, class t_traits>
class basic_ostream : virtual public ::std::basic_ios<t_char, t_traits> {
public:
  using char_type   = t_char;
  using traits_type = t_traits;
  using int_type    = typename t_traits::int_type;
  using pos_type    = typename t_traits::pos_type;
  using off_type    = typename t_traits::off_type;

  // ---- sentry ---------------------------------------------------------
  //
  // Flushes the tied stream and reports whether the stream is usable.
  // Its destructor flushes when `unitbuf' is set, which is what makes
  // `cerr' unbuffered in practice.
  class sentry {
  public:
    explicit sentry(basic_ostream &in_os) : m_os{in_os}, m_ok{false} {
      if (in_os.good()) {
        if (nullptr != in_os.tie()) {
          in_os.tie()->flush();
        }
        m_ok = in_os.good();
      }
    }
    ~sentry() {
      if (m_ok && (0U != (m_os.flags() & ::std::ios_base::unitbuf)) && !m_os.bad()) {
        if (nullptr != m_os.rdbuf()) {
          if (0 != m_os.rdbuf()->pubsync()) {
            m_os.setstate(::std::ios_base::badbit);
          }
        }
      }
    }
    explicit operator bool() const noexcept {
      return m_ok;
    }
    sentry(sentry const &)            = delete;
    sentry &operator=(sentry const &) = delete;

  private:
    basic_ostream &m_os;
    bool           m_ok;
  };

  explicit basic_ostream(::std::basic_streambuf<t_char, t_traits> *in_buf) {
    this->init(in_buf);
  }
  ~basic_ostream() override = default;

  // ---- arithmetic inserters -------------------------------------------

  basic_ostream &operator<<(bool in_v) {
    if (0U != (this->flags() & ::std::ios_base::boolalpha)) {
      return this->put_ascii(in_v ? "true" : "false");
    }
    return this->put_integer(static_cast<unsigned long long>(in_v ? 1U : 0U), "ll", false);
  }
  basic_ostream &operator<<(short in_v) {
    return this->put_integer(static_cast<long long>(in_v), "ll", true);
  }
  basic_ostream &operator<<(unsigned short in_v) {
    return this->put_integer(static_cast<unsigned long long>(in_v), "ll", false);
  }
  basic_ostream &operator<<(int in_v) {
    return this->put_integer(static_cast<long long>(in_v), "ll", true);
  }
  basic_ostream &operator<<(unsigned int in_v) {
    return this->put_integer(static_cast<unsigned long long>(in_v), "ll", false);
  }
  basic_ostream &operator<<(long in_v) {
    return this->put_integer(static_cast<long long>(in_v), "ll", true);
  }
  basic_ostream &operator<<(unsigned long in_v) {
    return this->put_integer(static_cast<unsigned long long>(in_v), "ll", false);
  }
  basic_ostream &operator<<(long long in_v) {
    return this->put_integer(in_v, "ll", true);
  }
  basic_ostream &operator<<(unsigned long long in_v) {
    return this->put_integer(in_v, "ll", false);
  }
  basic_ostream &operator<<(float in_v) {
    return this->put_float(static_cast<double>(in_v), false);
  }
  basic_ostream &operator<<(double in_v) {
    return this->put_float(in_v, false);
  }
  basic_ostream &operator<<(long double in_v) {
    return this->put_long_double(in_v);
  }
  basic_ostream &operator<<(void const *in_v) {
    char buf[64];
    ::std::snprintf(buf, sizeof(buf), "%p", in_v);
    return this->put_ascii(buf);
  }
  basic_ostream &operator<<(::std::nullptr_t) {
    return this->put_ascii("nullptr");
  }

  basic_ostream &operator<<(::std::basic_streambuf<t_char, t_traits> *in_sb) {
    sentry const s{*this};
    if (!static_cast<bool>(s)) {
      return *this;
    }
    if (nullptr == in_sb) {
      this->setstate(::std::ios_base::badbit);
      return *this;
    }
    ::std::streamsize n{0};
    for (;;) {
      int_type const c{in_sb->sbumpc()};
      if (traits_type::eq_int_type(c, traits_type::eof())) {
        break;
      }
      if (traits_type::eq_int_type(this->rdbuf()->sputc(traits_type::to_char_type(c)),
                                   traits_type::eof())) {
        this->setstate(::std::ios_base::badbit);
        break;
      }
      ++n;
    }
    if (0 == n) {
      this->setstate(::std::ios_base::failbit);
    }
    return *this;
  }

  // ---- manipulator hooks ----------------------------------------------

  basic_ostream &operator<<(basic_ostream &(*in_f)(basic_ostream &)) {
    return in_f(*this);
  }
  basic_ostream &operator<<(::std::basic_ios<t_char, t_traits> &(*in_f)(
      ::std::basic_ios<t_char, t_traits> &)) {
    in_f(*this);
    return *this;
  }
  basic_ostream &operator<<(::std::ios_base &(*in_f)(::std::ios_base &)) {
    in_f(*this);
    return *this;
  }

  // ---- unformatted output ---------------------------------------------

  basic_ostream &put(char_type in_c) {
    sentry const s{*this};
    if (static_cast<bool>(s)) {
      if (traits_type::eq_int_type(this->rdbuf()->sputc(in_c), traits_type::eof())) {
        this->setstate(::std::ios_base::badbit);
      }
    } else {
      this->setstate(::std::ios_base::badbit);
    }
    return *this;
  }

  basic_ostream &write(char_type const *in_s, ::std::streamsize in_n) {
    sentry const s{*this};
    if (static_cast<bool>(s)) {
      if (this->rdbuf()->sputn(in_s, in_n) != in_n) {
        this->setstate(::std::ios_base::badbit);
      }
    } else {
      this->setstate(::std::ios_base::badbit);
    }
    return *this;
  }

  basic_ostream &flush() {
    if (nullptr != this->rdbuf()) {
      if (0 != this->rdbuf()->pubsync()) {
        this->setstate(::std::ios_base::badbit);
      }
    }
    return *this;
  }

  pos_type tellp() {
    if (this->fail()) {
      return static_cast<pos_type>(-1);
    }
    return this->rdbuf()->pubseekoff(0, ::std::ios_base::cur, ::std::ios_base::out);
  }
  basic_ostream &seekp(pos_type in_pos) {
    if (!this->fail()) {
      if (static_cast<pos_type>(-1)
          == this->rdbuf()->pubseekpos(in_pos, ::std::ios_base::out)) {
        this->setstate(::std::ios_base::failbit);
      }
    }
    return *this;
  }
  basic_ostream &seekp(off_type in_off, ::std::ios_base::seekdir in_way) {
    if (!this->fail()) {
      if (static_cast<pos_type>(-1)
          == this->rdbuf()->pubseekoff(in_off, in_way, ::std::ios_base::out)) {
        this->setstate(::std::ios_base::failbit);
      }
    }
    return *this;
  }

  // ---- the one primitive everything above shares ----------------------
  //
  // Writes `in_n' characters with the current width, fill and adjustment,
  // then CLEARS the width -- which the standard requires of every
  // formatted output and is the easiest rule to lose when each inserter
  // pads for itself.
  basic_ostream &pad_and_put(char_type const *in_s, ::std::streamsize in_n,
                             ::std::streamsize in_internal_prefix = 0) {
    sentry const s{*this};
    if (!static_cast<bool>(s)) {
      this->setstate(::std::ios_base::badbit);
      this->width(0);
      return *this;
    }
    ::std::streamsize const w{this->width()};
    ::std::streamsize const padding{(w > in_n) ? (w - in_n) : 0};
    ::std::ios_base::fmtflags const adjust{this->flags() & ::std::ios_base::adjustfield};

    bool ok{true};
    if ((padding > 0) && (::std::ios_base::left != adjust)
        && (::std::ios_base::internal != adjust)) {
      ok = this->fill_n(padding);
    }
    if (ok && (::std::ios_base::internal == adjust) && (padding > 0)) {
      // sign or base prefix first, then the fill, then the digits
      ok = (this->rdbuf()->sputn(in_s, in_internal_prefix) == in_internal_prefix);
      if (ok) {
        ok = this->fill_n(padding);
      }
      if (ok) {
        ok = (this->rdbuf()->sputn(in_s + in_internal_prefix, in_n - in_internal_prefix)
              == (in_n - in_internal_prefix));
      }
    } else if (ok) {
      ok = (this->rdbuf()->sputn(in_s, in_n) == in_n);
    }
    if (ok && (padding > 0) && (::std::ios_base::left == adjust)) {
      ok = this->fill_n(padding);
    }
    if (!ok) {
      this->setstate(::std::ios_base::badbit);
    }
    this->width(0);
    return *this;
  }

protected:
  basic_ostream() = default;

private:
  bool fill_n(::std::streamsize in_n) {
    char_type const f{this->fill()};
    for (::std::streamsize i{0}; i < in_n; ++i) {
      if (traits_type::eq_int_type(this->rdbuf()->sputc(f), traits_type::eof())) {
        return false;
      }
    }
    return true;
  }

  // Widen an ASCII buffer into char_type and emit it with padding.
  basic_ostream &put_ascii(char const *in_s, ::std::streamsize in_internal_prefix = 0) {
    ::std::size_t const n{::std::strlen(in_s)};
    char_type           wide[io_detail::numbuf_size];
    ::std::size_t const lim{(n < io_detail::numbuf_size) ? n : (io_detail::numbuf_size - 1U)};
    for (::std::size_t i{0U}; i < lim; ++i) {
      wide[i] = this->widen(in_s[i]);
    }
    return this->pad_and_put(wide, static_cast<::std::streamsize>(lim), in_internal_prefix);
  }

  // How many leading characters are the sign and/or base prefix, which
  // `internal' adjustment keeps to the left of the fill.
  static ::std::streamsize prefix_len(char const *in_s) {
    ::std::streamsize n{0};
    if (('+' == in_s[0]) || ('-' == in_s[0])) {
      ++n;
    }
    if (('0' == in_s[n]) && (('x' == in_s[n + 1]) || ('X' == in_s[n + 1]))) {
      n += 2;
    }
    return n;
  }

  template<class t_int>
  basic_ostream &put_integer(t_int in_v, char const *in_length, bool in_signed) {
    char spec[16];
    char buf[io_detail::numbuf_size];
    io_detail::int_spec(spec, this->flags(), in_length, in_signed);
    ::std::snprintf(buf, sizeof(buf), spec, in_v);
    return this->put_ascii(buf, prefix_len(buf));
  }

  basic_ostream &put_float(double in_v, bool in_long) {
    char spec[16];
    char buf[io_detail::numbuf_size];
    int  prec{static_cast<int>(this->precision())};
    if (prec < 0) {
      prec = 0;
    }
    if (prec > io_detail::max_precision) {
      prec = io_detail::max_precision;
    }
    io_detail::float_spec(spec, this->flags(), prec, in_long);
    ::std::snprintf(buf, sizeof(buf), spec, in_v);
    return this->put_ascii(buf, prefix_len(buf));
  }

  basic_ostream &put_long_double(long double in_v) {
    char spec[16];
    char buf[io_detail::numbuf_size];
    int  prec{static_cast<int>(this->precision())};
    if (prec < 0) {
      prec = 0;
    }
    if (prec > io_detail::max_precision) {
      prec = io_detail::max_precision;
    }
    io_detail::float_spec(spec, this->flags(), prec, true);
    ::std::snprintf(buf, sizeof(buf), spec, in_v);
    return this->put_ascii(buf, prefix_len(buf));
  }
};

// ---- character and string inserters, as free functions ------------------

template<class t_char, class t_traits>
inline basic_ostream<t_char, t_traits> &operator<<(basic_ostream<t_char, t_traits> &os,
                                                   t_char                           c) {
  return os.pad_and_put(&c, 1);
}

template<class t_char, class t_traits>
inline basic_ostream<t_char, t_traits> &operator<<(basic_ostream<t_char, t_traits> &os,
                                                   t_char const                    *s) {
  ::std::streamsize const n{static_cast<::std::streamsize>(t_traits::length(s))};
  return os.pad_and_put(s, n);
}

// `char' into a wide stream is widened, as [ostream.inserters.character]
// requires.
template<class t_traits>
inline basic_ostream<wchar_t, t_traits> &operator<<(basic_ostream<wchar_t, t_traits> &os,
                                                    char                              c) {
  wchar_t const w{os.widen(c)};
  return os.pad_and_put(&w, 1);
}

template<class t_traits>
inline basic_ostream<char, t_traits> &operator<<(basic_ostream<char, t_traits> &os,
                                                 signed char                    c) {
  return os.pad_and_put(reinterpret_cast<char const *>(&c), 1);
}
template<class t_traits>
inline basic_ostream<char, t_traits> &operator<<(basic_ostream<char, t_traits> &os,
                                                 unsigned char                  c) {
  return os.pad_and_put(reinterpret_cast<char const *>(&c), 1);
}
template<class t_traits>
inline basic_ostream<char, t_traits> &operator<<(basic_ostream<char, t_traits> &os,
                                                 signed char const             *s) {
  return os << reinterpret_cast<char const *>(s);
}
template<class t_traits>
inline basic_ostream<char, t_traits> &operator<<(basic_ostream<char, t_traits> &os,
                                                 unsigned char const           *s) {
  return os << reinterpret_cast<char const *>(s);
}

// ---- the output manipulators --------------------------------------------

template<class t_char, class t_traits>
inline basic_ostream<t_char, t_traits> &endl(basic_ostream<t_char, t_traits> &os) {
  os.put(os.widen('\n'));
  os.flush();
  return os;
}

template<class t_char, class t_traits>
inline basic_ostream<t_char, t_traits> &ends(basic_ostream<t_char, t_traits> &os) {
  os.put(t_char());
  return os;
}

template<class t_char, class t_traits>
inline basic_ostream<t_char, t_traits> &flush(basic_ostream<t_char, t_traits> &os) {
  os.flush();
  return os;
}

} // namespace std

#endif // APEXP_STD_IO_OSTREAM_H
