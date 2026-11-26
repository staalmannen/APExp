// ***************************************************************************
// * APExp minimal iostreams -- `basic_filebuf' and the file streams.
// *
// * Project="APExp C++ library" File="io/fstream.h"
// *
// * SPDX-License-Identifier: MIT
// ***************************************************************************
//
// ***THE BUFFER IS A `FILE *' AND NOT A DESCRIPTOR, AND THAT IS A CHOICE
// WITH A REASON.***  libap's stdio is musl's and already buffers, picks a
// sensible block size, and knows this platform's quirks -- `/dev/cons'
// answering `S_ISREG' with `FD_ISTTY' unset among them.  A `filebuf' over
// `read'/`write' would reimplement all of that in C++ and get the second
// one wrong, which is how this tree's `select()' regression started.
//
// So `basic_filebuf' keeps ONE character of get area, enough for
// `sputbackc' to be legal, and hands everything else to `fread'/`fwrite'.
// The cost is one extra copy on bulk reads; the gain is that every
// platform question is answered in one place.
//
// **`sync' calls `fflush' and NOT `fsync'.**  Those are different
// questions -- flushing stdio's buffer into the file against flushing the
// file onto the disk -- and `pubsync' is specified as the first.  The
// distinction is not academic here: `fsync' answering failure is what
// made `xz' delete every file it wrote this release.

#ifndef APEXP_STD_IO_FSTREAM_H
#define APEXP_STD_IO_FSTREAM_H

#include "istream.h"
#include "../cstdio.stdh"

namespace std {

template<class t_char, class t_traits>
class basic_filebuf : public ::std::basic_streambuf<t_char, t_traits> {
public:
  using char_type   = t_char;
  using traits_type = t_traits;
  using int_type    = typename t_traits::int_type;
  using pos_type    = typename t_traits::pos_type;
  using off_type    = typename t_traits::off_type;

  basic_filebuf() : m_file{nullptr}, m_owned{false}, m_mode{0U} {
    this->setg(m_getbuf, m_getbuf + 1, m_getbuf + 1);
  }
  ~basic_filebuf() override {
    static_cast<void>(this->close());
  }

  basic_filebuf(basic_filebuf const &)            = delete;
  basic_filebuf &operator=(basic_filebuf const &) = delete;

  bool is_open() const noexcept {
    return nullptr != m_file;
  }

  basic_filebuf *open(char const *in_name, ::std::ios_base::openmode in_mode) {
    if (this->is_open()) {
      return nullptr;
    }
    char const *const mode{mode_string(in_mode)};
    if (nullptr == mode) {
      return nullptr;
    }
    m_file = ::std::fopen(in_name, mode);
    if (nullptr == m_file) {
      return nullptr;
    }
    m_owned = true;
    m_mode  = in_mode;
    if (0U != (in_mode & ::std::ios_base::ate)) {
      if (0 != ::std::fseek(m_file, 0L, SEEK_END)) {
        static_cast<void>(this->close());
        return nullptr;
      }
    }
    return this;
  }

  // Adopt an existing `FILE *' without owning it.  This is how
  // `<iostream>' wraps `stdin'/`stdout'/`stderr', and it is not in the
  // standard because the standard has no `FILE *' to adopt.
  basic_filebuf *adopt(::std::FILE *in_f, ::std::ios_base::openmode in_mode) {
    if (this->is_open() || (nullptr == in_f)) {
      return nullptr;
    }
    m_file  = in_f;
    m_owned = false;
    m_mode  = in_mode;
    return this;
  }

  basic_filebuf *close() {
    if (nullptr == m_file) {
      return nullptr;
    }
    ::std::FILE *const f{m_file};
    bool const         owned{m_owned};
    m_file  = nullptr;
    m_owned = false;
    this->setg(m_getbuf, m_getbuf + 1, m_getbuf + 1);
    if (owned) {
      if (0 != ::std::fclose(f)) {
        return nullptr;
      }
    } else {
      static_cast<void>(::std::fflush(f));
    }
    return this;
  }

protected:
  int_type underflow() override {
    if (this->gptr() < this->egptr()) {
      return traits_type::to_int_type(*this->gptr());
    }
    if (nullptr == m_file) {
      return traits_type::eof();
    }
    char_type c{};
    if (1U != ::std::fread(&c, sizeof(char_type), 1U, m_file)) {
      return traits_type::eof();
    }
    m_getbuf[0] = c;
    this->setg(m_getbuf, m_getbuf, m_getbuf + 1);
    return traits_type::to_int_type(c);
  }

  int_type pbackfail(int_type in_c = t_traits::eof()) override {
    if (nullptr == m_file) {
      return traits_type::eof();
    }
    if (this->gptr() > this->eback()) {
      this->gbump(-1);
      if (!traits_type::eq_int_type(in_c, traits_type::eof())) {
        *this->gptr() = traits_type::to_char_type(in_c);
      }
      return traits_type::not_eof(in_c);
    }
    // Nothing in the one-character get area: fall back on the file.
    if (traits_type::eq_int_type(in_c, traits_type::eof())) {
      return traits_type::eof();
    }
    if (0 != ::std::fseek(m_file, -static_cast<long>(sizeof(char_type)), SEEK_CUR)) {
      return traits_type::eof();
    }
    return in_c;
  }

  ::std::streamsize xsgetn(char_type *out_s, ::std::streamsize in_n) override {
    ::std::streamsize done{0};
    // Drain the pushback character first, or a `sputbackc' before a
    // `read' would be silently lost.
    while ((done < in_n) && (this->gptr() < this->egptr())) {
      out_s[done++] = *this->gptr();
      this->gbump(1);
    }
    if ((done < in_n) && (nullptr != m_file)) {
      done += static_cast<::std::streamsize>(
          ::std::fread(out_s + done, sizeof(char_type),
                       static_cast<::std::size_t>(in_n - done), m_file));
    }
    return done;
  }

  int_type overflow(int_type in_c = t_traits::eof()) override {
    if (nullptr == m_file) {
      return traits_type::eof();
    }
    if (traits_type::eq_int_type(in_c, traits_type::eof())) {
      return traits_type::not_eof(in_c);
    }
    char_type const c{traits_type::to_char_type(in_c)};
    if (1U != ::std::fwrite(&c, sizeof(char_type), 1U, m_file)) {
      return traits_type::eof();
    }
    return in_c;
  }

  ::std::streamsize xsputn(char_type const *in_s, ::std::streamsize in_n) override {
    if (nullptr == m_file) {
      return 0;
    }
    return static_cast<::std::streamsize>(
        ::std::fwrite(in_s, sizeof(char_type), static_cast<::std::size_t>(in_n), m_file));
  }

  int sync() override {
    if (nullptr == m_file) {
      return -1;
    }
    return (0 == ::std::fflush(m_file)) ? 0 : -1;
  }

  pos_type seekoff(off_type in_off, ::std::ios_base::seekdir in_way,
                   ::std::ios_base::openmode
                   = ::std::ios_base::in | ::std::ios_base::out) override {
    if (nullptr == m_file) {
      return static_cast<pos_type>(-1);
    }
    int whence{SEEK_SET};
    if (::std::ios_base::cur == in_way) {
      whence = SEEK_CUR;
      // A character sitting in the pushback area has already been read
      // from the file, so `ftell' is ahead of the stream's own position.
      in_off -= static_cast<off_type>(this->egptr() - this->gptr());
    } else if (::std::ios_base::end == in_way) {
      whence = SEEK_END;
    }
    if (0 != ::std::fseek(m_file, static_cast<long>(in_off * static_cast<off_type>(sizeof(char_type))),
                          whence)) {
      return static_cast<pos_type>(-1);
    }
    this->setg(m_getbuf, m_getbuf + 1, m_getbuf + 1);
    long const p{::std::ftell(m_file)};
    if (p < 0L) {
      return static_cast<pos_type>(-1);
    }
    return static_cast<pos_type>(static_cast<off_type>(p) / static_cast<off_type>(sizeof(char_type)));
  }

  pos_type seekpos(pos_type in_pos, ::std::ios_base::openmode in_which
                   = ::std::ios_base::in | ::std::ios_base::out) override {
    return this->seekoff(static_cast<off_type>(in_pos), ::std::ios_base::beg, in_which);
  }

private:
  // `fopen' modes, table-free so that an unrepresentable combination
  // answers `nullptr' rather than something close.
  static char const *mode_string(::std::ios_base::openmode in_m) {
    bool const rd{0U != (in_m & ::std::ios_base::in)};
    bool const wr{0U != (in_m & ::std::ios_base::out)};
    bool const ap{0U != (in_m & ::std::ios_base::app)};
    bool const tr{0U != (in_m & ::std::ios_base::trunc)};
    bool const bi{0U != (in_m & ::std::ios_base::binary)};

    char const *base{nullptr};
    if (rd && !wr && !ap && !tr) {
      base = bi ? "rb" : "r";
    } else if (!rd && wr && ap) {
      base = bi ? "ab" : "a";
    } else if (!rd && wr) {
      base = bi ? "wb" : "w"; // trunc is implied and allowed
    } else if (rd && wr && ap) {
      base = bi ? "a+b" : "a+";
    } else if (rd && wr && tr) {
      base = bi ? "w+b" : "w+";
    } else if (rd && wr) {
      base = bi ? "r+b" : "r+";
    }
    return base;
  }

  ::std::FILE              *m_file;
  bool                      m_owned;
  ::std::ios_base::openmode m_mode;
  char_type                 m_getbuf[1];
};

namespace io_detail {
  // A `basic_ios' cannot be initialised before its own base, so each
  // stream below holds the buffer in a base class that runs first.  The
  // obvious `: basic_istream{&m_buf}' with `m_buf' a member is
  // use-before-init, and it is the kind that works by accident because
  // nothing dereferences the pointer until later.
  // ***THE MEMBER IS `m_fb' AND NOT `m_buf' BECAUSE `basic_ios' HAS
  // AN `m_buf' OF ITS OWN.***  Both are bases of the stream classes
  // below, so an unqualified `m_buf' is ambiguous -- and the base's
  // is PRIVATE, which does not help: access is checked after lookup,
  // so a private member of one base still hides nothing and still
  // collides.  The string streams escape it only because their buffer
  // is a MEMBER, which hides the base's name rather than competing
  // with it.
  template<class t_char, class t_traits> struct filebuf_holder {
    ::std::basic_filebuf<t_char, t_traits> m_fb;
  };
} // namespace io_detail

template<class t_char, class t_traits>
class basic_ifstream : private io_detail::filebuf_holder<t_char, t_traits>,
                       public ::std::basic_istream<t_char, t_traits> {
  using holder = io_detail::filebuf_holder<t_char, t_traits>;

public:
  basic_ifstream() : ::std::basic_istream<t_char, t_traits>{&this->m_fb} {
  }
  explicit basic_ifstream(char const               *in_name,
                          ::std::ios_base::openmode in_mode = ::std::ios_base::in)
      : ::std::basic_istream<t_char, t_traits>{&this->m_fb} {
    this->open(in_name, in_mode);
  }

  ::std::basic_filebuf<t_char, t_traits> *rdbuf() const {
    return const_cast<::std::basic_filebuf<t_char, t_traits> *>(&this->m_fb);
  }
  bool is_open() const { return this->m_fb.is_open(); }
  void open(char const *in_name, ::std::ios_base::openmode in_mode = ::std::ios_base::in) {
    if (nullptr == this->m_fb.open(in_name, in_mode | ::std::ios_base::in)) {
      this->setstate(::std::ios_base::failbit);
    } else {
      this->clear();
    }
  }
  void close() {
    if (nullptr == this->m_fb.close()) {
      this->setstate(::std::ios_base::failbit);
    }
  }
};

template<class t_char, class t_traits>
class basic_ofstream : private io_detail::filebuf_holder<t_char, t_traits>,
                       public ::std::basic_ostream<t_char, t_traits> {
  using holder = io_detail::filebuf_holder<t_char, t_traits>;

public:
  basic_ofstream() : ::std::basic_ostream<t_char, t_traits>{&this->m_fb} {
  }
  explicit basic_ofstream(char const               *in_name,
                          ::std::ios_base::openmode in_mode = ::std::ios_base::out)
      : ::std::basic_ostream<t_char, t_traits>{&this->m_fb} {
    this->open(in_name, in_mode);
  }

  ::std::basic_filebuf<t_char, t_traits> *rdbuf() const {
    return const_cast<::std::basic_filebuf<t_char, t_traits> *>(&this->m_fb);
  }
  bool is_open() const { return this->m_fb.is_open(); }
  void open(char const *in_name, ::std::ios_base::openmode in_mode = ::std::ios_base::out) {
    if (nullptr == this->m_fb.open(in_name, in_mode | ::std::ios_base::out)) {
      this->setstate(::std::ios_base::failbit);
    } else {
      this->clear();
    }
  }
  void close() {
    if (nullptr == this->m_fb.close()) {
      this->setstate(::std::ios_base::failbit);
    }
  }
};

template<class t_char, class t_traits>
class basic_fstream : private io_detail::filebuf_holder<t_char, t_traits>,
                      public ::std::basic_iostream<t_char, t_traits> {
  using holder = io_detail::filebuf_holder<t_char, t_traits>;

public:
  basic_fstream() : ::std::basic_iostream<t_char, t_traits>{&this->m_fb} {
  }
  explicit basic_fstream(char const               *in_name,
                         ::std::ios_base::openmode in_mode
                         = ::std::ios_base::in | ::std::ios_base::out)
      : ::std::basic_iostream<t_char, t_traits>{&this->m_fb} {
    this->open(in_name, in_mode);
  }

  ::std::basic_filebuf<t_char, t_traits> *rdbuf() const {
    return const_cast<::std::basic_filebuf<t_char, t_traits> *>(&this->m_fb);
  }
  bool is_open() const { return this->m_fb.is_open(); }
  void open(char const               *in_name,
            ::std::ios_base::openmode in_mode
            = ::std::ios_base::in | ::std::ios_base::out) {
    if (nullptr == this->m_fb.open(in_name, in_mode)) {
      this->setstate(::std::ios_base::failbit);
    } else {
      this->clear();
    }
  }
  void close() {
    if (nullptr == this->m_fb.close()) {
      this->setstate(::std::ios_base::failbit);
    }
  }
};

} // namespace std

#endif // APEXP_STD_IO_FSTREAM_H
