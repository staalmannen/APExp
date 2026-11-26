// ***************************************************************************
// * APExp minimal iostreams -- `ios_base'.
// *
// * Project="APExp C++ library" File="io/ios_base.h"
// *
// * SPDX-License-Identifier: MIT
// ***************************************************************************
//
// The non-template base: format flags, field width, precision, the state
// bits and the open modes.  See `io/iosfwd.h' for what this stack leaves
// out and why.
//
// **`imbue' and `getloc' are absent rather than stubbed.**  A stub
// returning a fabricated `locale' would be the stub-that-answers-the-
// wrong-thing family this tree keeps hitting; code that really wants a
// locale should fail to compile here rather than silently get the C one
// under another name.

#ifndef APEXP_STD_IO_IOS_BASE_H
#define APEXP_STD_IO_IOS_BASE_H

#include "iosfwd.h"
#include "../language_support/runtime_error.h"

namespace std {

class ios_base {
public:
  // ***`failure' CARRIES NO MESSAGE, AND THAT IS THE LIBRARY'S SHAPE
  // RATHER THAN A SHORTCUT.***  portable_stl's `runtime_error' is
  // `runtime_error_impl<>' and has no `(char const *)' constructor --
  // an open item in 0.6's inventory -- so every one of the nine
  // `<stdexcept>' classes answers a fixed string from `what()'.  A
  // message member here would make `failure' the only one that
  // differs, which is worse than matching them; it becomes real the
  // round those constructors do.
  class failure : public ::std::runtime_error {
  public:
    failure() noexcept                   = default;
    failure(failure const &) noexcept    = default;
    ~failure() noexcept override         = default;
    char const *what() const noexcept override {
      return "ios_base::failure";
    }
  };

  using fmtflags = unsigned int;

  static constexpr fmtflags boolalpha   = 0x0001;
  static constexpr fmtflags dec         = 0x0002;
  static constexpr fmtflags fixed       = 0x0004;
  static constexpr fmtflags hex         = 0x0008;
  static constexpr fmtflags internal    = 0x0010;
  static constexpr fmtflags left        = 0x0020;
  static constexpr fmtflags oct         = 0x0040;
  static constexpr fmtflags right       = 0x0080;
  static constexpr fmtflags scientific  = 0x0100;
  static constexpr fmtflags showbase    = 0x0200;
  static constexpr fmtflags showpoint   = 0x0400;
  static constexpr fmtflags showpos     = 0x0800;
  static constexpr fmtflags skipws      = 0x1000;
  static constexpr fmtflags unitbuf     = 0x2000;
  static constexpr fmtflags uppercase   = 0x4000;

  static constexpr fmtflags adjustfield = left | right | internal;
  static constexpr fmtflags basefield   = dec | oct | hex;
  static constexpr fmtflags floatfield  = scientific | fixed;

  using iostate = unsigned int;
  static constexpr iostate goodbit = 0x0;
  static constexpr iostate badbit  = 0x1;
  static constexpr iostate eofbit  = 0x2;
  static constexpr iostate failbit = 0x4;

  using openmode = unsigned int;
  static constexpr openmode app    = 0x01;
  static constexpr openmode ate    = 0x02;
  static constexpr openmode binary = 0x04;
  static constexpr openmode in     = 0x08;
  static constexpr openmode out    = 0x10;
  static constexpr openmode trunc  = 0x20;

  using seekdir = int;
  static constexpr seekdir beg = 0;
  static constexpr seekdir cur = 1;
  static constexpr seekdir end = 2;

  fmtflags flags() const noexcept {
    return m_flags;
  }
  fmtflags flags(fmtflags in_flags) noexcept {
    fmtflags const old{m_flags};
    m_flags = in_flags;
    return old;
  }
  fmtflags setf(fmtflags in_flags) noexcept {
    fmtflags const old{m_flags};
    m_flags |= in_flags;
    return old;
  }
  fmtflags setf(fmtflags in_flags, fmtflags in_mask) noexcept {
    fmtflags const old{m_flags};
    m_flags = (m_flags & ~in_mask) | (in_flags & in_mask);
    return old;
  }
  void unsetf(fmtflags in_mask) noexcept {
    m_flags &= ~in_mask;
  }

  ::std::streamsize precision() const noexcept {
    return m_precision;
  }
  ::std::streamsize precision(::std::streamsize in_prec) noexcept {
    ::std::streamsize const old{m_precision};
    m_precision = in_prec;
    return old;
  }
  ::std::streamsize width() const noexcept {
    return m_width;
  }
  ::std::streamsize width(::std::streamsize in_width) noexcept {
    ::std::streamsize const old{m_width};
    m_width = in_width;
    return old;
  }

protected:
  ios_base() noexcept : m_flags{skipws | dec}, m_precision{6}, m_width{0} {
  }
  ~ios_base() = default;

  // Not copyable, as the standard requires.
  ios_base(ios_base const &)            = delete;
  ios_base &operator=(ios_base const &) = delete;

  void copyfmt_base(ios_base const &other) noexcept {
    m_flags     = other.m_flags;
    m_precision = other.m_precision;
    m_width     = other.m_width;
  }

private:
  fmtflags          m_flags;
  ::std::streamsize m_precision;
  ::std::streamsize m_width;
};

} // namespace std

#endif // APEXP_STD_IO_IOS_BASE_H
