// ***************************************************************************
// * APExp minimal iostreams -- `cin', `cout', `cerr', `clog'.
// *
// * Project="APExp C++ library" File="io/iostream.h"
// *
// * SPDX-License-Identifier: MIT
// ***************************************************************************
//
// ***WHY THESE ARE FUNCTION-LOCAL STATICS AND NOT OBJECTS IN A LIBRARY.***
//
// The standard puts `extern ostream cout;' in `<iostream>' and the object
// itself in the standard library, with a per-translation-unit
// `ios_base::Init' to order the construction.  **That shape cannot work
// here yet, and the reason is measurable rather than stylistic**:
// `rc/bin/ape/eccp''s munch pass finds static constructors by running
// `nm' over the OBJECT FILES on the link line, and an archive member is
// pulled only on demand -- *so a constructor inside a `libc++.a' would
// never be scanned and never registered in `_ctors[]'.*  The stream
// objects would be raw storage at the first `<<'.
//
// The standard's own `ios_base::Init' exists for the same ordering
// problem and solves it by putting the initialiser in the USER's
// translation unit, which munch does see.  A function-local static
// reaches the same place with less machinery: the object is constructed
// on first use, cpfe emits the guard, and `cxx-staticinit-test' section 3
// already measures that function-local statics work on this machine.
//
// **So `std::cout' is a reference, not an object.**  Every use spells the
// same -- `std::cout << x', `&std::cout', passing it as `ostream &' --
// and `&std::cout' is the same address in every translation unit, because
// they all name one function-local static.  What differs from the
// standard: `std::cout' has internal linkage per TU (one pointer-sized
// reference each) and `extern std::ostream cout;' written by hand in user
// code will not match.  *Nothing in a normal program can tell*, and the
// day `eccp' scans archives this becomes the ordinary arrangement.
//
// **Flushing at exit is NOT left to the destructor.**  A function-local
// static's destructor runs through `atexit', and the order against
// libap's own stdio teardown is not something this header can promise --
// so the four buffers ADOPT `stdin'/`stdout'/`stderr' rather than owning
// them, and libap's `exit' flushes those itself (`__stdio_exit', which is
// called before `_doatexits').  *Nothing here has to run at exit for the
// output to arrive*, which is the property worth having, given that a
// lost final buffer is exactly the lz4 EndMark shape.

#ifndef APEXP_STD_IO_IOSTREAM_H
#define APEXP_STD_IO_IOSTREAM_H

#include "fstream.h"
#include "sstream.h"

namespace std {

namespace io_detail {

  template<class t_char, class t_traits = ::std::char_traits<t_char>>
  class std_stream_set final {
  public:
    static ::std::basic_filebuf<t_char, t_traits> &in_buf() {
      static ::std::basic_filebuf<t_char, t_traits> b;
      static bool const once{nullptr != b.adopt(stdin, ::std::ios_base::in)};
      static_cast<void>(once);
      return b;
    }
    static ::std::basic_filebuf<t_char, t_traits> &out_buf() {
      static ::std::basic_filebuf<t_char, t_traits> b;
      static bool const once{nullptr != b.adopt(stdout, ::std::ios_base::out)};
      static_cast<void>(once);
      return b;
    }
    static ::std::basic_filebuf<t_char, t_traits> &err_buf() {
      static ::std::basic_filebuf<t_char, t_traits> b;
      static bool const once{nullptr != b.adopt(stderr, ::std::ios_base::out)};
      static_cast<void>(once);
      return b;
    }

    static ::std::basic_ostream<t_char, t_traits> &out() {
      static ::std::basic_ostream<t_char, t_traits> s{&out_buf()};
      return s;
    }
    // `cerr' is `unitbuf' by the standard, so a diagnostic is on the
    // file before the next statement runs -- which is the whole point of
    // it and the first thing lost by a naive copy of `cout'.
    static ::std::basic_ostream<t_char, t_traits> &err() {
      static ::std::basic_ostream<t_char, t_traits> s{&err_buf()};
      static bool const once{(s.setf(::std::ios_base::unitbuf), true)};
      static_cast<void>(once);
      return s;
    }
    static ::std::basic_ostream<t_char, t_traits> &log() {
      static ::std::basic_ostream<t_char, t_traits> s{&err_buf()};
      return s;
    }
    // `cin' is tied to `cout', so a prompt written without a newline is
    // flushed before the read blocks.
    static ::std::basic_istream<t_char, t_traits> &inp() {
      static ::std::basic_istream<t_char, t_traits> s{&in_buf()};
      static bool const once{(s.tie(&out()), true)};
      static_cast<void>(once);
      return s;
    }
  };

} // namespace io_detail

static ::std::istream &cin  = ::std::io_detail::std_stream_set<char>::inp();
static ::std::ostream &cout = ::std::io_detail::std_stream_set<char>::out();
static ::std::ostream &cerr = ::std::io_detail::std_stream_set<char>::err();
static ::std::ostream &clog = ::std::io_detail::std_stream_set<char>::log();

static ::std::wistream &wcin  = ::std::io_detail::std_stream_set<wchar_t>::inp();
static ::std::wostream &wcout = ::std::io_detail::std_stream_set<wchar_t>::out();
static ::std::wostream &wcerr = ::std::io_detail::std_stream_set<wchar_t>::err();
static ::std::wostream &wclog = ::std::io_detail::std_stream_set<wchar_t>::log();

} // namespace std

#endif // APEXP_STD_IO_IOSTREAM_H
