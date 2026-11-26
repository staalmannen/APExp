// ***************************************************************************
// * APExp minimal iostreams -- `basic_istream'.
// *
// * Project="APExp C++ library" File="io/istream.h"
// *
// * SPDX-License-Identifier: MIT
// ***************************************************************************
//
// Parsing goes through `strtoll'/`strtoull'/`strtold' for the same reason
// output goes through `snprintf': that is what `num_get' would call.
//
// **The extractor reads into a staging buffer FIRST and converts after**,
// rather than driving `strtol' over the streambuf.  A converter needs to
// look ahead one character past the number and then put it back, and
// `sputbackc' is only guaranteed for the character just read -- so the
// buffered form is the one whose pushback is always legal.  The buffer is
// bounded and an over-long run of digits sets `failbit' rather than
// truncating silently.
//
// ***`gcount' COUNTS WHAT THE LAST UNFORMATTED CALL EXTRACTED***, which
// includes a delimiter that was consumed and discarded.  Getting that
// wrong makes `getline' look like it dropped a character on every empty
// line, and nothing else in the stream would say so.

#ifndef APEXP_STD_IO_ISTREAM_H
#define APEXP_STD_IO_ISTREAM_H

#include "ostream.h"
#include "../cstdlib.stdh"

namespace std {

template<class t_char, class t_traits>
class basic_istream : virtual public ::std::basic_ios<t_char, t_traits> {
public:
  using char_type   = t_char;
  using traits_type = t_traits;
  using int_type    = typename t_traits::int_type;
  using pos_type    = typename t_traits::pos_type;
  using off_type    = typename t_traits::off_type;

  class sentry {
  public:
    explicit sentry(basic_istream &in_is, bool in_noskipws = false)
        : m_is{in_is}, m_ok{false} {
      if (!in_is.good()) {
        in_is.setstate(::std::ios_base::failbit);
        return;
      }
      if (nullptr != in_is.tie()) {
        in_is.tie()->flush();
      }
      if (!in_noskipws && (0U != (in_is.flags() & ::std::ios_base::skipws))) {
        for (;;) {
          int_type const c{in_is.rdbuf()->sgetc()};
          if (traits_type::eq_int_type(c, traits_type::eof())) {
            in_is.setstate(::std::ios_base::eofbit | ::std::ios_base::failbit);
            return;
          }
          if (!basic_istream::is_space(in_is.narrow(traits_type::to_char_type(c), '?'))) {
            break;
          }
          static_cast<void>(in_is.rdbuf()->sbumpc());
        }
      }
      m_ok = true;
    }
    explicit operator bool() const noexcept {
      return m_ok;
    }
    sentry(sentry const &)            = delete;
    sentry &operator=(sentry const &) = delete;

  private:
    basic_istream &m_is;
    bool           m_ok;
  };

  explicit basic_istream(::std::basic_streambuf<t_char, t_traits> *in_buf) : m_gcount{0} {
    this->init(in_buf);
  }
  ~basic_istream() override = default;

  ::std::streamsize gcount() const noexcept {
    return m_gcount;
  }

  // ---- arithmetic extractors ------------------------------------------

  basic_istream &operator>>(bool &out_v) {
    if (0U != (this->flags() & ::std::ios_base::boolalpha)) {
      char      buf[8];
      int const r{this->scan_token(buf, sizeof(buf))};
      if (scan_none == r) {
        return *this;
      }
      if (scan_ok != r) {
        out_v = false;
        return *this;
      }
      if (0 == ::std::strcmp(buf, "true")) {
        out_v = true;
      } else if (0 == ::std::strcmp(buf, "false")) {
        out_v = false;
      } else {
        this->setstate(::std::ios_base::failbit);
        out_v = false;
      }
      return *this;
    }
    unsigned long long v{0U};
    int const          r{this->scan_unsigned(v)};
    if (scan_ok == r) {
      out_v = (0U != v);
    } else if (scan_bad == r) {
      out_v = false;
    }
    return *this;
  }
  basic_istream &operator>>(short &out_v) { return this->get_signed(out_v); }
  basic_istream &operator>>(int &out_v) { return this->get_signed(out_v); }
  basic_istream &operator>>(long &out_v) { return this->get_signed(out_v); }
  basic_istream &operator>>(long long &out_v) { return this->get_signed(out_v); }
  basic_istream &operator>>(unsigned short &out_v) { return this->get_unsigned(out_v); }
  basic_istream &operator>>(unsigned int &out_v) { return this->get_unsigned(out_v); }
  basic_istream &operator>>(unsigned long &out_v) { return this->get_unsigned(out_v); }
  basic_istream &operator>>(unsigned long long &out_v) { return this->get_unsigned(out_v); }
  basic_istream &operator>>(float &out_v) { return this->get_float(out_v); }
  basic_istream &operator>>(double &out_v) { return this->get_float(out_v); }
  basic_istream &operator>>(long double &out_v) { return this->get_float(out_v); }

  basic_istream &operator>>(void *&out_v) {
    char      buf[64];
    int const r{this->scan_token(buf, sizeof(buf))};
    if (scan_none == r) {
      return *this;
    }
    void *p{nullptr};
    if ((scan_ok != r) || (1 != ::std::sscanf(buf, "%p", &p))) {
      this->setstate(::std::ios_base::failbit);
      out_v = nullptr;
      return *this;
    }
    out_v = p;
    return *this;
  }

  basic_istream &operator>>(basic_istream &(*in_f)(basic_istream &)) {
    return in_f(*this);
  }
  basic_istream &operator>>(::std::basic_ios<t_char, t_traits> &(*in_f)(
      ::std::basic_ios<t_char, t_traits> &)) {
    in_f(*this);
    return *this;
  }
  basic_istream &operator>>(::std::ios_base &(*in_f)(::std::ios_base &)) {
    in_f(*this);
    return *this;
  }

  // ---- unformatted input ----------------------------------------------

  int_type get() {
    m_gcount = 0;
    sentry const s{*this, true};
    if (!static_cast<bool>(s)) {
      return traits_type::eof();
    }
    int_type const c{this->rdbuf()->sbumpc()};
    if (traits_type::eq_int_type(c, traits_type::eof())) {
      this->setstate(::std::ios_base::eofbit | ::std::ios_base::failbit);
    } else {
      m_gcount = 1;
    }
    return c;
  }

  basic_istream &get(char_type &out_c) {
    int_type const c{this->get()};
    if (!traits_type::eq_int_type(c, traits_type::eof())) {
      out_c = traits_type::to_char_type(c);
    }
    return *this;
  }

  basic_istream &get(char_type *out_s, ::std::streamsize in_n) {
    return this->get(out_s, in_n, this->widen('\n'));
  }

  basic_istream &get(char_type *out_s, ::std::streamsize in_n, char_type in_delim) {
    m_gcount = 0;
    sentry const s{*this, true};
    if (static_cast<bool>(s) && (in_n > 0)) {
      while (m_gcount < (in_n - 1)) {
        int_type const c{this->rdbuf()->sgetc()};
        if (traits_type::eq_int_type(c, traits_type::eof())) {
          this->setstate(::std::ios_base::eofbit);
          break;
        }
        if (traits_type::eq(traits_type::to_char_type(c), in_delim)) {
          break;
        }
        out_s[m_gcount++] = traits_type::to_char_type(c);
        static_cast<void>(this->rdbuf()->sbumpc());
      }
    }
    if (in_n > 0) {
      out_s[m_gcount] = char_type();
    }
    if (0 == m_gcount) {
      this->setstate(::std::ios_base::failbit);
    }
    return *this;
  }

  basic_istream &getline(char_type *out_s, ::std::streamsize in_n) {
    return this->getline(out_s, in_n, this->widen('\n'));
  }

  // ***THE DELIMITER IS COUNTED IN `gcount' AND NOT STORED.***  Three
  // outcomes have to stay distinct: the delimiter was found (extracted,
  // counted, discarded), the buffer filled first (`failbit'), and end of
  // file (`eofbit', and `failbit' only if nothing was read).
  basic_istream &getline(char_type *out_s, ::std::streamsize in_n, char_type in_delim) {
    m_gcount = 0;
    sentry const s{*this, true};
    bool         got_delim{false};
    bool         overflowed{false};
    if (static_cast<bool>(s) && (in_n > 0)) {
      for (;;) {
        int_type const c{this->rdbuf()->sgetc()};
        if (traits_type::eq_int_type(c, traits_type::eof())) {
          this->setstate(::std::ios_base::eofbit);
          break;
        }
        if (traits_type::eq(traits_type::to_char_type(c), in_delim)) {
          static_cast<void>(this->rdbuf()->sbumpc());
          ++m_gcount;
          got_delim = true;
          break;
        }
        if (m_gcount >= (in_n - 1)) {
          overflowed = true;
          break;
        }
        out_s[m_gcount++] = traits_type::to_char_type(c);
        static_cast<void>(this->rdbuf()->sbumpc());
      }
    }
    ::std::streamsize const stored{got_delim ? (m_gcount - 1) : m_gcount};
    if (in_n > 0) {
      out_s[stored] = char_type();
    }
    if (overflowed) {
      this->setstate(::std::ios_base::failbit);
    } else if (0 == m_gcount) {
      this->setstate(::std::ios_base::failbit);
    }
    return *this;
  }

  basic_istream &read(char_type *out_s, ::std::streamsize in_n) {
    m_gcount = 0;
    sentry const s{*this, true};
    if (static_cast<bool>(s)) {
      m_gcount = this->rdbuf()->sgetn(out_s, in_n);
      if (m_gcount != in_n) {
        this->setstate(::std::ios_base::eofbit | ::std::ios_base::failbit);
      }
    } else {
      this->setstate(::std::ios_base::failbit);
    }
    return *this;
  }

  ::std::streamsize readsome(char_type *out_s, ::std::streamsize in_n) {
    m_gcount = 0;
    sentry const s{*this, true};
    if (static_cast<bool>(s)) {
      ::std::streamsize avail{this->rdbuf()->in_avail()};
      if (avail < 0) {
        this->setstate(::std::ios_base::eofbit);
      } else if (avail > 0) {
        if (avail > in_n) {
          avail = in_n;
        }
        m_gcount = this->rdbuf()->sgetn(out_s, avail);
      }
    }
    return m_gcount;
  }

  basic_istream &ignore(::std::streamsize in_n = 1,
                        int_type          in_delim = t_traits::eof()) {
    m_gcount = 0;
    sentry const s{*this, true};
    if (static_cast<bool>(s)) {
      while (m_gcount < in_n) {
        int_type const c{this->rdbuf()->sbumpc()};
        if (traits_type::eq_int_type(c, traits_type::eof())) {
          this->setstate(::std::ios_base::eofbit);
          break;
        }
        ++m_gcount;
        if (traits_type::eq_int_type(c, in_delim)) {
          break;
        }
      }
    }
    return *this;
  }

  int_type peek() {
    m_gcount = 0;
    sentry const s{*this, true};
    if (!static_cast<bool>(s)) {
      return traits_type::eof();
    }
    int_type const c{this->rdbuf()->sgetc()};
    if (traits_type::eq_int_type(c, traits_type::eof())) {
      this->setstate(::std::ios_base::eofbit);
    }
    return c;
  }

  basic_istream &putback(char_type in_c) {
    m_gcount = 0;
    this->clear(this->rdstate() & ~::std::ios_base::eofbit);
    sentry const s{*this, true};
    if (!static_cast<bool>(s)
        || traits_type::eq_int_type(this->rdbuf()->sputbackc(in_c), traits_type::eof())) {
      this->setstate(::std::ios_base::badbit);
    }
    return *this;
  }

  basic_istream &unget() {
    m_gcount = 0;
    this->clear(this->rdstate() & ~::std::ios_base::eofbit);
    sentry const s{*this, true};
    if (!static_cast<bool>(s)
        || traits_type::eq_int_type(this->rdbuf()->sungetc(), traits_type::eof())) {
      this->setstate(::std::ios_base::badbit);
    }
    return *this;
  }

  int sync() {
    if (nullptr == this->rdbuf()) {
      return -1;
    }
    if (-1 == this->rdbuf()->pubsync()) {
      this->setstate(::std::ios_base::badbit);
      return -1;
    }
    return 0;
  }

  pos_type tellg() {
    if (this->fail()) {
      return static_cast<pos_type>(-1);
    }
    return this->rdbuf()->pubseekoff(0, ::std::ios_base::cur, ::std::ios_base::in);
  }
  basic_istream &seekg(pos_type in_pos) {
    this->clear(this->rdstate() & ~::std::ios_base::eofbit);
    if (!this->fail()) {
      if (static_cast<pos_type>(-1)
          == this->rdbuf()->pubseekpos(in_pos, ::std::ios_base::in)) {
        this->setstate(::std::ios_base::failbit);
      }
    }
    return *this;
  }
  basic_istream &seekg(off_type in_off, ::std::ios_base::seekdir in_way) {
    this->clear(this->rdstate() & ~::std::ios_base::eofbit);
    if (!this->fail()) {
      if (static_cast<pos_type>(-1)
          == this->rdbuf()->pubseekoff(in_off, in_way, ::std::ios_base::in)) {
        this->setstate(::std::ios_base::failbit);
      }
    }
    return *this;
  }

  // Used by the free `operator>>' for strings and characters.
  static bool is_space(char in_c) {
    return (' ' == in_c) || ('\t' == in_c) || ('\n' == in_c) || ('\r' == in_c)
           || ('\v' == in_c) || ('\f' == in_c);
  }

  // Reads one whitespace-delimited token as ASCII.
  //
  // ***THREE OUTCOMES AND NOT TWO, BECAUSE C++11 CHANGED THE RULE.***
  // `scan_none' means the SENTRY failed -- the stream was already
  // unusable, no conversion was attempted, and [istream.formatted.reqmts]
  // leaves the caller's value untouched.  `scan_bad' means the sentry
  // succeeded and the conversion did not, and since C++11
  // [facet.num.get.virtuals] requires the value to be set to ZERO.
  // *The C++98 rule was "leave it alone" in both cases*, and a
  // two-valued return cannot tell them apart -- which is exactly what
  // this file did until the `-DREFERENCE' arm of
  // `cxx-iostream-test.cpp' disagreed with it on the first run.
  static constexpr int scan_none = 0;
  static constexpr int scan_ok   = 1;
  static constexpr int scan_bad  = 2;

  int scan_token(char *out_buf, ::std::size_t in_cap) {
    sentry const s{*this};
    if (!static_cast<bool>(s)) {
      return scan_none;
    }
    ::std::size_t n{0U};
    for (;;) {
      int_type const c{this->rdbuf()->sgetc()};
      if (traits_type::eq_int_type(c, traits_type::eof())) {
        this->setstate(::std::ios_base::eofbit);
        break;
      }
      char const nc{this->narrow(traits_type::to_char_type(c), ' ')};
      if (is_space(nc)) {
        break;
      }
      if (n >= (in_cap - 1U)) {
        this->setstate(::std::ios_base::failbit);
        return scan_bad;
      }
      out_buf[n++] = nc;
      static_cast<void>(this->rdbuf()->sbumpc());
    }
    out_buf[n] = '\0';
    if (0U == n) {
      this->setstate(::std::ios_base::failbit);
      return scan_bad;
    }
    return scan_ok;
  }

protected:
  basic_istream() : m_gcount{0} {
  }

private:
  int scan_signed(long long &out_v) {
    char      buf[64];
    int const r{this->scan_token(buf, sizeof(buf))};
    if (scan_ok != r) {
      return r;
    }
    char     *endp{nullptr};
    int const base{this->conv_base()};
    long long const v{::std::strtoll(buf, &endp, base)};
    if ((endp == buf) || ('\0' != *endp)) {
      this->setstate(::std::ios_base::failbit);
      return scan_bad;
    }
    out_v = v;
    return scan_ok;
  }

  int scan_unsigned(unsigned long long &out_v) {
    char      buf[64];
    int const r{this->scan_token(buf, sizeof(buf))};
    if (scan_ok != r) {
      return r;
    }
    char     *endp{nullptr};
    int const base{this->conv_base()};
    unsigned long long const v{::std::strtoull(buf, &endp, base)};
    if ((endp == buf) || ('\0' != *endp)) {
      this->setstate(::std::ios_base::failbit);
      return scan_bad;
    }
    out_v = v;
    return scan_ok;
  }

  int conv_base() const {
    ::std::ios_base::fmtflags const b{this->flags() & ::std::ios_base::basefield};
    if (::std::ios_base::oct == b) {
      return 8;
    }
    if (::std::ios_base::hex == b) {
      return 16;
    }
    if (::std::ios_base::dec == b) {
      return 10;
    }
    return 0; // no basefield set: let strtoll sniff the prefix
  }

  template<class t_int> basic_istream &get_signed(t_int &out_v) {
    long long v{0};
    int const r{this->scan_signed(v)};
    if (scan_ok == r) {
      out_v = static_cast<t_int>(v);
    } else if (scan_bad == r) {
      out_v = 0;
    }
    return *this;
  }
  template<class t_int> basic_istream &get_unsigned(t_int &out_v) {
    unsigned long long v{0U};
    int const          r{this->scan_unsigned(v)};
    if (scan_ok == r) {
      out_v = static_cast<t_int>(v);
    } else if (scan_bad == r) {
      out_v = 0;
    }
    return *this;
  }
  template<class t_float> basic_istream &get_float(t_float &out_v) {
    char      buf[512];
    int const r{this->scan_token(buf, sizeof(buf))};
    if (scan_none == r) {
      return *this;
    }
    if (scan_bad == r) {
      out_v = 0;
      return *this;
    }
    char             *endp{nullptr};
    long double const v{::std::strtold(buf, &endp)};
    if ((endp == buf) || ('\0' != *endp)) {
      this->setstate(::std::ios_base::failbit);
      out_v = 0;
      return *this;
    }
    out_v = static_cast<t_float>(v);
    return *this;
  }

  ::std::streamsize m_gcount;
};

// ---- character and string extractors ------------------------------------

template<class t_char, class t_traits>
inline basic_istream<t_char, t_traits> &operator>>(basic_istream<t_char, t_traits> &is,
                                                   t_char                          &out_c) {
  typename basic_istream<t_char, t_traits>::sentry const s{is};
  if (static_cast<bool>(s)) {
    typename t_traits::int_type const c{is.rdbuf()->sbumpc()};
    if (t_traits::eq_int_type(c, t_traits::eof())) {
      is.setstate(::std::ios_base::eofbit | ::std::ios_base::failbit);
    } else {
      out_c = t_traits::to_char_type(c);
    }
  }
  return is;
}

// ***`width()' IS THE ONLY BOUND A `t_char *' EXTRACTOR HAS***, so a
// zero width reads until whitespace with nothing stopping it.  That is
// the standard's behaviour and it is the reason this overload is a
// hazard in every implementation; it is here because code uses it, with
// the width honoured exactly.
template<class t_char, class t_traits>
inline basic_istream<t_char, t_traits> &operator>>(basic_istream<t_char, t_traits> &is,
                                                   t_char                          *out_s) {
  typename basic_istream<t_char, t_traits>::sentry const s{is};
  ::std::streamsize n{0};
  if (static_cast<bool>(s)) {
    ::std::streamsize const w{is.width()};
    for (;;) {
      if ((w > 0) && (n >= (w - 1))) {
        break;
      }
      typename t_traits::int_type const c{is.rdbuf()->sgetc()};
      if (t_traits::eq_int_type(c, t_traits::eof())) {
        is.setstate(::std::ios_base::eofbit);
        break;
      }
      char const nc{is.narrow(t_traits::to_char_type(c), ' ')};
      if (basic_istream<t_char, t_traits>::is_space(nc)) {
        break;
      }
      out_s[n++] = t_traits::to_char_type(c);
      static_cast<void>(is.rdbuf()->sbumpc());
    }
  }
  out_s[n] = t_char();
  if (0 == n) {
    is.setstate(::std::ios_base::failbit);
  }
  is.width(0);
  return is;
}

// ---- the input manipulator ----------------------------------------------

template<class t_char, class t_traits>
inline basic_istream<t_char, t_traits> &ws(basic_istream<t_char, t_traits> &is) {
  typename basic_istream<t_char, t_traits>::sentry const s{is, true};
  if (static_cast<bool>(s)) {
    for (;;) {
      typename t_traits::int_type const c{is.rdbuf()->sgetc()};
      if (t_traits::eq_int_type(c, t_traits::eof())) {
        is.setstate(::std::ios_base::eofbit);
        break;
      }
      if (!basic_istream<t_char, t_traits>::is_space(
              is.narrow(t_traits::to_char_type(c), '?'))) {
        break;
      }
      static_cast<void>(is.rdbuf()->sbumpc());
    }
  }
  return is;
}

template<class t_char, class t_traits>
class basic_iostream : public basic_istream<t_char, t_traits>,
                       public basic_ostream<t_char, t_traits> {
public:
  using char_type   = t_char;
  using traits_type = t_traits;
  using int_type    = typename t_traits::int_type;
  using pos_type    = typename t_traits::pos_type;
  using off_type    = typename t_traits::off_type;

  explicit basic_iostream(::std::basic_streambuf<t_char, t_traits> *in_buf)
      : basic_istream<t_char, t_traits>{in_buf}, basic_ostream<t_char, t_traits>{in_buf} {
  }
  ~basic_iostream() override = default;

protected:
  basic_iostream() = default;
};

} // namespace std

#endif // APEXP_STD_IO_ISTREAM_H
