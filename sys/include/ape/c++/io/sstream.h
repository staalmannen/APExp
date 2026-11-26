// ***************************************************************************
// * APExp minimal iostreams -- `basic_stringbuf' and the string streams.
// *
// * Project="APExp C++ library" File="io/sstream.h"
// *
// * SPDX-License-Identifier: MIT
// ***************************************************************************
//
// ***THE BUFFER IS A RAW ARRAY AND NOT A `basic_string', AND THAT IS
// FORCED BY THE LIBRARY RATHER THAN CHOSEN.***  portable_stl is
// exception-free by construction, so its growing operations report
// failure in their RETURN VALUE -- `vector::push_back' answers
// `expected<void, ...>'.  A `stringbuf' whose every `sputc' had to
// inspect an `expected' would either drop those results on the floor (the
// bug this library's convention exists to prevent) or thread an error
// channel through `overflow', which has nowhere to put one but
// `eof()'.
//
// So the buffer is `malloc'/`realloc' and the `expected' question is met
// exactly ONCE, in `str()', where a failure has somewhere to go.  *The
// conversion is at the boundary instead of in the inner loop*, which is
// also why `str()' is the only member that can report running out of
// memory.
//
// `str()' builds its result through `back_inserter', which is the idiom
// `to_string2.h' already uses for exactly this reason.

#ifndef APEXP_STD_IO_SSTREAM_H
#define APEXP_STD_IO_SSTREAM_H

#include "istream.h"
#include "../string/basic_string.h"
#include "../iterator/back_insert_iterator.h"
#include "../cstdlib.stdh"

namespace std {

template<class t_char, class t_traits>
class basic_stringbuf : public ::std::basic_streambuf<t_char, t_traits> {
public:
  using char_type   = t_char;
  using traits_type = t_traits;
  using int_type    = typename t_traits::int_type;
  using pos_type    = typename t_traits::pos_type;
  using off_type    = typename t_traits::off_type;
  using string_type = ::std::basic_string<t_char, t_traits>;

  explicit basic_stringbuf(::std::ios_base::openmode in_mode
                           = ::std::ios_base::in | ::std::ios_base::out)
      : m_buf{nullptr}, m_cap{0U}, m_len{0U}, m_mode{in_mode} {
    this->reset_areas();
  }

  explicit basic_stringbuf(string_type const        &in_s,
                           ::std::ios_base::openmode in_mode
                           = ::std::ios_base::in | ::std::ios_base::out)
      : m_buf{nullptr}, m_cap{0U}, m_len{0U}, m_mode{in_mode} {
    this->assign(in_s.data(), in_s.size());
  }

  ~basic_stringbuf() override {
    ::std::free(m_buf);
  }

  basic_stringbuf(basic_stringbuf const &)            = delete;
  basic_stringbuf &operator=(basic_stringbuf const &) = delete;

  // The one place an allocation failure in the LIBRARY can be reported.
  // A short result means the string could not be grown; the caller sees
  // a truncated string, which is the same thing every exception-free
  // path in this library does.
  string_type str() const {
    string_type result;
    auto        inserter = ::std::back_inserter(result);
    ::std::size_t const n{this->live_len()};
    for (::std::size_t i{0U}; i < n; ++i) {
      *inserter = m_buf[i];
      ++inserter;
    }
    return result;
  }

  void str(string_type const &in_s) {
    this->assign(in_s.data(), in_s.size());
  }

protected:
  int_type underflow() override {
    if (this->gptr() < this->egptr()) {
      return traits_type::to_int_type(*this->gptr());
    }
    // The put area may have grown since the get area was set.
    this->sync_get_area();
    if (this->gptr() < this->egptr()) {
      return traits_type::to_int_type(*this->gptr());
    }
    return traits_type::eof();
  }

  int_type pbackfail(int_type in_c = t_traits::eof()) override {
    if (this->gptr() <= this->eback()) {
      return traits_type::eof();
    }
    if (traits_type::eq_int_type(in_c, traits_type::eof())) {
      this->gbump(-1);
      return traits_type::not_eof(in_c);
    }
    if (traits_type::eq(traits_type::to_char_type(in_c), this->gptr()[-1])) {
      this->gbump(-1);
      return in_c;
    }
    if (0U == (m_mode & ::std::ios_base::out)) {
      return traits_type::eof();
    }
    this->gbump(-1);
    *this->gptr() = traits_type::to_char_type(in_c);
    return in_c;
  }

  int_type overflow(int_type in_c = t_traits::eof()) override {
    if (0U == (m_mode & ::std::ios_base::out)) {
      return traits_type::eof();
    }
    if (traits_type::eq_int_type(in_c, traits_type::eof())) {
      return traits_type::not_eof(in_c);
    }
    ::std::size_t const used{this->put_len()};
    if (used >= m_cap) {
      if (!this->grow(used + 1U)) {
        return traits_type::eof();
      }
    }
    m_buf[used] = traits_type::to_char_type(in_c);
    if ((used + 1U) > m_len) {
      m_len = used + 1U;
    }
    this->reset_put_area(used + 1U);
    return in_c;
  }

  ::std::streamsize xsputn(char_type const *in_s, ::std::streamsize in_n) override {
    if ((0U == (m_mode & ::std::ios_base::out)) || (in_n <= 0)) {
      return 0;
    }
    ::std::size_t const used{this->put_len()};
    ::std::size_t const want{used + static_cast<::std::size_t>(in_n)};
    if (want > m_cap) {
      if (!this->grow(want)) {
        return 0;
      }
    }
    traits_type::copy(m_buf + used, in_s, static_cast<::std::size_t>(in_n));
    if (want > m_len) {
      m_len = want;
    }
    this->reset_put_area(want);
    return in_n;
  }

  pos_type seekoff(off_type in_off, ::std::ios_base::seekdir in_way,
                   ::std::ios_base::openmode in_which
                   = ::std::ios_base::in | ::std::ios_base::out) override {
    this->sync_get_area();
    ::std::size_t const len{this->live_len()};
    off_type            base{0};
    if (::std::ios_base::cur == in_way) {
      base = (0U != (in_which & ::std::ios_base::in))
                 ? static_cast<off_type>(this->gptr() - this->eback())
                 : static_cast<off_type>(this->put_len());
    } else if (::std::ios_base::end == in_way) {
      base = static_cast<off_type>(len);
    }
    off_type const target{base + in_off};
    if ((target < 0) || (target > static_cast<off_type>(len))) {
      return static_cast<pos_type>(-1);
    }
    if (0U != (in_which & ::std::ios_base::in)) {
      this->setg(m_buf, m_buf + target, m_buf + len);
    }
    if (0U != (in_which & ::std::ios_base::out)) {
      this->reset_put_area(static_cast<::std::size_t>(target));
    }
    return static_cast<pos_type>(target);
  }

  pos_type seekpos(pos_type in_pos, ::std::ios_base::openmode in_which
                   = ::std::ios_base::in | ::std::ios_base::out) override {
    return this->seekoff(static_cast<off_type>(in_pos), ::std::ios_base::beg, in_which);
  }

private:
  ::std::size_t put_len() const {
    return (nullptr != this->pbase())
               ? static_cast<::std::size_t>(this->pptr() - this->pbase())
               : 0U;
  }
  ::std::size_t live_len() const {
    ::std::size_t const p{this->put_len()};
    return (p > m_len) ? p : m_len;
  }

  bool grow(::std::size_t in_want) {
    ::std::size_t newcap{(0U == m_cap) ? 64U : (m_cap * 2U)};
    while (newcap < in_want) {
      newcap *= 2U;
    }
    void *const p{::std::realloc(m_buf, newcap * sizeof(char_type))};
    if (nullptr == p) {
      return false;
    }
    m_buf = static_cast<char_type *>(p);
    m_cap = newcap;
    return true;
  }

  void assign(char_type const *in_s, ::std::size_t in_n) {
    if (in_n > m_cap) {
      if (!this->grow(in_n)) {
        return;
      }
    }
    if (in_n > 0U) {
      traits_type::copy(m_buf, in_s, in_n);
    }
    m_len = in_n;
    this->reset_areas();
  }

  void reset_areas() {
    if (0U != (m_mode & ::std::ios_base::in)) {
      this->setg(m_buf, m_buf, m_buf + m_len);
    } else {
      this->setg(nullptr, nullptr, nullptr);
    }
    if (0U != (m_mode & ::std::ios_base::out)) {
      ::std::size_t const start{(0U != (m_mode & ::std::ios_base::ate)) ? m_len : 0U};
      this->reset_put_area(start);
    } else {
      this->setp(nullptr, nullptr);
    }
  }

  // The put area is always `[m_buf, m_buf + m_cap)' with `pptr' at the
  // write position; `overflow' grows and re-points it.
  void reset_put_area(::std::size_t in_at) {
    if (0U == (m_mode & ::std::ios_base::out)) {
      return;
    }
    this->setp(m_buf, m_buf + m_cap);
    this->pbump(static_cast<int>(in_at));
  }

  void sync_get_area() {
    if (0U != (m_mode & ::std::ios_base::in)) {
      ::std::size_t const len{this->live_len()};
      ::std::size_t const at{(nullptr != this->eback())
                                 ? static_cast<::std::size_t>(this->gptr() - this->eback())
                                 : 0U};
      this->setg(m_buf, m_buf + ((at > len) ? len : at), m_buf + len);
    }
  }

  char_type                *m_buf;
  ::std::size_t             m_cap;
  ::std::size_t             m_len;
  ::std::ios_base::openmode m_mode;
};

template<class t_char, class t_traits>
class basic_istringstream : public ::std::basic_istream<t_char, t_traits> {
public:
  using string_type = ::std::basic_string<t_char, t_traits>;

  explicit basic_istringstream(::std::ios_base::openmode in_mode = ::std::ios_base::in)
      : ::std::basic_istream<t_char, t_traits>{&m_buf},
        m_buf{static_cast<::std::ios_base::openmode>(in_mode | ::std::ios_base::in)} {
    this->init(&m_buf);
  }
  explicit basic_istringstream(string_type const        &in_s,
                               ::std::ios_base::openmode in_mode = ::std::ios_base::in)
      : ::std::basic_istream<t_char, t_traits>{&m_buf},
        m_buf{in_s, static_cast<::std::ios_base::openmode>(in_mode | ::std::ios_base::in)} {
    this->init(&m_buf);
  }

  basic_stringbuf<t_char, t_traits> *rdbuf() const {
    return const_cast<basic_stringbuf<t_char, t_traits> *>(&m_buf);
  }
  string_type str() const { return m_buf.str(); }
  void        str(string_type const &in_s) { m_buf.str(in_s); }

private:
  basic_stringbuf<t_char, t_traits> m_buf;
};

template<class t_char, class t_traits>
class basic_ostringstream : public ::std::basic_ostream<t_char, t_traits> {
public:
  using string_type = ::std::basic_string<t_char, t_traits>;

  explicit basic_ostringstream(::std::ios_base::openmode in_mode = ::std::ios_base::out)
      : ::std::basic_ostream<t_char, t_traits>{&m_buf},
        m_buf{static_cast<::std::ios_base::openmode>(in_mode | ::std::ios_base::out)} {
    this->init(&m_buf);
  }
  explicit basic_ostringstream(string_type const        &in_s,
                               ::std::ios_base::openmode in_mode = ::std::ios_base::out)
      : ::std::basic_ostream<t_char, t_traits>{&m_buf},
        m_buf{in_s, static_cast<::std::ios_base::openmode>(in_mode | ::std::ios_base::out)} {
    this->init(&m_buf);
  }

  basic_stringbuf<t_char, t_traits> *rdbuf() const {
    return const_cast<basic_stringbuf<t_char, t_traits> *>(&m_buf);
  }
  string_type str() const { return m_buf.str(); }
  void        str(string_type const &in_s) { m_buf.str(in_s); }

private:
  basic_stringbuf<t_char, t_traits> m_buf;
};

template<class t_char, class t_traits>
class basic_stringstream : public ::std::basic_iostream<t_char, t_traits> {
public:
  using string_type = ::std::basic_string<t_char, t_traits>;

  explicit basic_stringstream(::std::ios_base::openmode in_mode
                              = ::std::ios_base::in | ::std::ios_base::out)
      : ::std::basic_iostream<t_char, t_traits>{&m_buf}, m_buf{in_mode} {
    this->init(&m_buf);
  }
  explicit basic_stringstream(string_type const        &in_s,
                              ::std::ios_base::openmode in_mode
                              = ::std::ios_base::in | ::std::ios_base::out)
      : ::std::basic_iostream<t_char, t_traits>{&m_buf}, m_buf{in_s, in_mode} {
    this->init(&m_buf);
  }

  basic_stringbuf<t_char, t_traits> *rdbuf() const {
    return const_cast<basic_stringbuf<t_char, t_traits> *>(&m_buf);
  }
  string_type str() const { return m_buf.str(); }
  void        str(string_type const &in_s) { m_buf.str(in_s); }

private:
  basic_stringbuf<t_char, t_traits> m_buf;
};

// ---- string insert/extract, which is what callers actually use ----------

template<class t_char, class t_traits>
inline ::std::basic_ostream<t_char, t_traits> &
operator<<(::std::basic_ostream<t_char, t_traits>    &os,
           ::std::basic_string<t_char, t_traits> const &s) {
  return os.pad_and_put(s.data(), static_cast<::std::streamsize>(s.size()));
}

template<class t_char, class t_traits>
inline ::std::basic_istream<t_char, t_traits> &
operator>>(::std::basic_istream<t_char, t_traits> &is,
           ::std::basic_string<t_char, t_traits>  &out_s) {
  typename ::std::basic_istream<t_char, t_traits>::sentry const sent{is};
  ::std::basic_string<t_char, t_traits>                         tmp;
  auto              inserter = ::std::back_inserter(tmp);
  ::std::streamsize n{0};
  if (static_cast<bool>(sent)) {
    ::std::streamsize const w{is.width()};
    for (;;) {
      if ((w > 0) && (n >= w)) {
        break;
      }
      typename t_traits::int_type const c{is.rdbuf()->sgetc()};
      if (t_traits::eq_int_type(c, t_traits::eof())) {
        is.setstate(::std::ios_base::eofbit);
        break;
      }
      if (::std::basic_istream<t_char, t_traits>::is_space(
              is.narrow(t_traits::to_char_type(c), ' '))) {
        break;
      }
      *inserter = t_traits::to_char_type(c);
      ++inserter;
      ++n;
      static_cast<void>(is.rdbuf()->sbumpc());
    }
  }
  // ***THE STRING IS ASSIGNED WHENEVER THE SENTRY SUCCEEDED, EVEN ON
  // FAILURE.***  [istream.extractors] says the extractor calls
  // `str.erase()' before extracting anything, so a failed extraction
  // leaves an EMPTY string and not the caller's old one.  Assigning
  // only on success is the plausible wrong version and it keeps stale
  // data in a variable the caller believes was just overwritten.
  if (static_cast<bool>(sent)) {
    out_s = tmp;
  }
  if (0 == n) {
    is.setstate(::std::ios_base::failbit);
  }
  is.width(0);
  return is;
}

// ***`getline' INTO A STRING HAS NO LENGTH LIMIT, which is the whole
// reason it exists*** -- the `t_char *' form is bounded by `width()' and
// this one is bounded by the line.  The delimiter is extracted and
// discarded, and an empty line is a SUCCESS that yields an empty string,
// which is the case a naive `0 == n -> failbit' gets wrong.
template<class t_char, class t_traits>
inline ::std::basic_istream<t_char, t_traits> &
getline(::std::basic_istream<t_char, t_traits> &is,
        ::std::basic_string<t_char, t_traits>  &out_s, t_char in_delim) {
  typename ::std::basic_istream<t_char, t_traits>::sentry const sent{is, true};
  ::std::basic_string<t_char, t_traits>                         tmp;
  auto inserter = ::std::back_inserter(tmp);
  bool any{false};
  if (static_cast<bool>(sent)) {
    for (;;) {
      typename t_traits::int_type const c{is.rdbuf()->sbumpc()};
      if (t_traits::eq_int_type(c, t_traits::eof())) {
        is.setstate(::std::ios_base::eofbit);
        break;
      }
      any = true;
      if (t_traits::eq(t_traits::to_char_type(c), in_delim)) {
        break;
      }
      *inserter = t_traits::to_char_type(c);
      ++inserter;
    }
  }
  // Same rule as the extractor above: `getline' erases first, so a
  // read at end of input empties the string rather than leaving it.
  if (static_cast<bool>(sent)) {
    out_s = tmp;
  }
  if (!any) {
    is.setstate(::std::ios_base::failbit);
  }
  return is;
}

template<class t_char, class t_traits>
inline ::std::basic_istream<t_char, t_traits> &
getline(::std::basic_istream<t_char, t_traits> &is,
        ::std::basic_string<t_char, t_traits>  &out_s) {
  return ::std::getline(is, out_s, is.widen('\n'));
}

} // namespace std

#endif // APEXP_STD_IO_SSTREAM_H
