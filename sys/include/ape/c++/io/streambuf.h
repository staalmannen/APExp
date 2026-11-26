// ***************************************************************************
// * APExp minimal iostreams -- `basic_streambuf'.
// *
// * Project="APExp C++ library" File="io/streambuf.h"
// *
// * SPDX-License-Identifier: MIT
// ***************************************************************************
//
// The buffer abstraction every stream sits on: a get area
// (`eback'/`gptr'/`egptr') and a put area (`pbase'/`pptr'/`epptr'), with
// the derived class supplying `underflow'/`overflow' when one runs out.
//
// **The default virtuals answer "nothing there" and not "failure"**,
// which is the distinction this tree's notes put first: `underflow'
// returns `eof()' because a base `streambuf' genuinely has no characters,
// and `sync' returns 0 because it genuinely has nothing to flush.  A base
// `overflow' DOES return `eof()', and that is not the same family -- a
// character offered to a buffer with nowhere to put it is a real failure.

#ifndef APEXP_STD_IO_STREAMBUF_H
#define APEXP_STD_IO_STREAMBUF_H

#include "ios_base.h"

namespace std {

template<class t_char, class t_traits> class basic_streambuf {
public:
  using char_type   = t_char;
  using traits_type = t_traits;
  using int_type    = typename t_traits::int_type;
  using pos_type    = typename t_traits::pos_type;
  using off_type    = typename t_traits::off_type;

  virtual ~basic_streambuf() = default;

  // ---- the public interface, all non-virtual --------------------------

  ::std::streamsize in_avail() {
    if (m_gcur < m_gend) {
      return static_cast<::std::streamsize>(m_gend - m_gcur);
    }
    return this->showmanyc();
  }

  int_type snextc() {
    if (traits_type::eq_int_type(this->sbumpc(), traits_type::eof())) {
      return traits_type::eof();
    }
    return this->sgetc();
  }

  int_type sbumpc() {
    if (m_gcur < m_gend) {
      return traits_type::to_int_type(*m_gcur++);
    }
    return this->uflow();
  }

  int_type sgetc() {
    if (m_gcur < m_gend) {
      return traits_type::to_int_type(*m_gcur);
    }
    return this->underflow();
  }

  ::std::streamsize sgetn(char_type *out_s, ::std::streamsize in_n) {
    return this->xsgetn(out_s, in_n);
  }

  int_type sputbackc(char_type in_c) {
    if ((m_gbeg < m_gcur) && traits_type::eq(in_c, m_gcur[-1])) {
      return traits_type::to_int_type(*--m_gcur);
    }
    return this->pbackfail(traits_type::to_int_type(in_c));
  }

  int_type sungetc() {
    if (m_gbeg < m_gcur) {
      return traits_type::to_int_type(*--m_gcur);
    }
    return this->pbackfail();
  }

  int_type sputc(char_type in_c) {
    if (m_pcur < m_pend) {
      *m_pcur++ = in_c;
      return traits_type::to_int_type(in_c);
    }
    return this->overflow(traits_type::to_int_type(in_c));
  }

  ::std::streamsize sputn(char_type const *in_s, ::std::streamsize in_n) {
    return this->xsputn(in_s, in_n);
  }

  int pubsync() {
    return this->sync();
  }

  basic_streambuf *pubsetbuf(char_type *in_s, ::std::streamsize in_n) {
    return this->setbuf(in_s, in_n);
  }

  pos_type pubseekoff(off_type in_off, ::std::ios_base::seekdir in_way,
                      ::std::ios_base::openmode in_which
                      = ::std::ios_base::in | ::std::ios_base::out) {
    return this->seekoff(in_off, in_way, in_which);
  }

  pos_type pubseekpos(pos_type in_pos,
                      ::std::ios_base::openmode in_which
                      = ::std::ios_base::in | ::std::ios_base::out) {
    return this->seekpos(in_pos, in_which);
  }

protected:
  basic_streambuf() noexcept
      : m_gbeg{nullptr}, m_gcur{nullptr}, m_gend{nullptr},
        m_pbeg{nullptr}, m_pcur{nullptr}, m_pend{nullptr} {
  }

  char_type *eback() const noexcept { return m_gbeg; }
  char_type *gptr() const noexcept { return m_gcur; }
  char_type *egptr() const noexcept { return m_gend; }
  void gbump(int in_n) noexcept { m_gcur += in_n; }
  void setg(char_type *in_beg, char_type *in_cur, char_type *in_end) noexcept {
    m_gbeg = in_beg;
    m_gcur = in_cur;
    m_gend = in_end;
  }

  char_type *pbase() const noexcept { return m_pbeg; }
  char_type *pptr() const noexcept { return m_pcur; }
  char_type *epptr() const noexcept { return m_pend; }
  void pbump(int in_n) noexcept { m_pcur += in_n; }
  void setp(char_type *in_beg, char_type *in_end) noexcept {
    m_pbeg = in_beg;
    m_pcur = in_beg;
    m_pend = in_end;
  }

  // ---- the virtuals ----------------------------------------------------

  virtual ::std::streamsize showmanyc() {
    return 0;
  }

  virtual int_type underflow() {
    return traits_type::eof();
  }

  virtual int_type uflow() {
    if (traits_type::eq_int_type(this->underflow(), traits_type::eof())) {
      return traits_type::eof();
    }
    return traits_type::to_int_type(*m_gcur++);
  }

  virtual int_type pbackfail(int_type = t_traits::eof()) {
    return traits_type::eof();
  }

  virtual ::std::streamsize xsgetn(char_type *out_s, ::std::streamsize in_n) {
    ::std::streamsize done{0};
    while (done < in_n) {
      if (m_gcur < m_gend) {
        ::std::streamsize chunk{static_cast<::std::streamsize>(m_gend - m_gcur)};
        if (chunk > (in_n - done)) {
          chunk = in_n - done;
        }
        traits_type::copy(out_s + done, m_gcur, static_cast<::std::size_t>(chunk));
        m_gcur += chunk;
        done += chunk;
      } else {
        int_type const c{this->uflow()};
        if (traits_type::eq_int_type(c, traits_type::eof())) {
          break;
        }
        out_s[done++] = traits_type::to_char_type(c);
      }
    }
    return done;
  }

  virtual int_type overflow(int_type = t_traits::eof()) {
    return traits_type::eof();
  }

  virtual ::std::streamsize xsputn(char_type const *in_s, ::std::streamsize in_n) {
    ::std::streamsize done{0};
    while (done < in_n) {
      if (m_pcur < m_pend) {
        ::std::streamsize chunk{static_cast<::std::streamsize>(m_pend - m_pcur)};
        if (chunk > (in_n - done)) {
          chunk = in_n - done;
        }
        traits_type::copy(m_pcur, in_s + done, static_cast<::std::size_t>(chunk));
        m_pcur += chunk;
        done += chunk;
      } else {
        if (traits_type::eq_int_type(this->overflow(traits_type::to_int_type(in_s[done])),
                                     traits_type::eof())) {
          break;
        }
        ++done;
      }
    }
    return done;
  }

  virtual int sync() {
    return 0;
  }

  virtual basic_streambuf *setbuf(char_type *, ::std::streamsize) {
    return this;
  }

  virtual pos_type seekoff(off_type, ::std::ios_base::seekdir,
                           ::std::ios_base::openmode
                           = ::std::ios_base::in | ::std::ios_base::out) {
    return static_cast<pos_type>(-1);
  }

  virtual pos_type seekpos(pos_type, ::std::ios_base::openmode
                           = ::std::ios_base::in | ::std::ios_base::out) {
    return static_cast<pos_type>(-1);
  }

private:
  char_type *m_gbeg;
  char_type *m_gcur;
  char_type *m_gend;
  char_type *m_pbeg;
  char_type *m_pcur;
  char_type *m_pend;
};

} // namespace std

#endif // APEXP_STD_IO_STREAMBUF_H
