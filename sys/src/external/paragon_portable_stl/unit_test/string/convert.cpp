// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="convert.cpp"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#include <gtest/gtest.h>

#include "portable_stl/string/convert.h"
#include "portable_stl/string/string.h"

namespace {
using test_ascii_string = ::portable_stl::string;
using test_ucs2_string  = ::portable_stl::wstring;
using test_utf8_string  = ::portable_stl::u8string;
using test_utf16_string = ::portable_stl::u16string;
using test_utf32_string = ::portable_stl::u32string;

using test_ascii_string_view = typename test_ascii_string::view_type;
using test_ucs2_string_view  = typename test_ucs2_string::view_type;
using test_utf8_string_view  = typename test_utf8_string::view_type;
using test_utf16_string_view = typename test_utf16_string::view_type;
using test_utf32_string_view = typename test_utf32_string::view_type;

test_ascii_string const source_ascii("abc123");
test_ascii_string const source_ascii_2("??????");
test_ascii_string const source_ascii_3("??????");
test_ucs2_string const  source_ucs2({u'a', u'b', u'c', u'1', u'2', u'3'});
test_ucs2_string const  source_ucs2_2({u'а', u'б', u'в', u'你', u'妮', u'腻'});
test_ucs2_string const  source_ucs2_3({u'а', u'б', u'?', u'?', u'妮', u'腻'});
test_utf8_string const  source_utf8(u8"abc123");
test_utf8_string const  source_utf8_2(u8"абв你妮腻");
test_utf8_string const  source_utf8_3(u8"аб😀🙏妮腻");
test_utf16_string const source_utf16(u"abc123");
test_utf16_string const source_utf16_2(u"абв你妮腻");
test_utf16_string const source_utf16_3(u"аб😀🙏妮腻");
test_utf32_string const source_utf32(U"abc123");
test_utf32_string const source_utf32_2(U"абв你妮腻");
test_utf32_string const source_utf32_3(U"аб😀🙏妮腻");

} // namespace

TEST(string_convert, from_string_to_ascii_1) {
  using t_dest_string = test_ascii_string;
  auto const &check   = source_ascii;
  {
    t_dest_string result;
    EXPECT_TRUE(::portable_stl::convert(result, source_ascii));
    EXPECT_TRUE(result == check);
  }
  {
    t_dest_string result;
    EXPECT_TRUE(::portable_stl::convert(result, source_ucs2));
    EXPECT_TRUE(result == check);
  }
  {
    t_dest_string result;
    EXPECT_TRUE(::portable_stl::convert(result, source_utf8));
    EXPECT_TRUE(result == check);
  }
  {
    t_dest_string result;
    EXPECT_TRUE(::portable_stl::convert(result, source_utf16));
    EXPECT_TRUE(result == check);
  }
  {
    t_dest_string result;
    EXPECT_TRUE(::portable_stl::convert(result, source_utf32));
    EXPECT_TRUE(result == check);
  }
}

TEST(string_convert, from_string_to_ascii_2) {
  using t_dest_string = test_ascii_string;
  auto const &check   = source_ascii_2;
  {
    t_dest_string result;
    EXPECT_TRUE(::portable_stl::convert(result, source_ascii_2));
    EXPECT_TRUE(result == check);
  }
  {
    t_dest_string result;
    EXPECT_TRUE(::portable_stl::convert(result, source_ucs2_2));
    EXPECT_TRUE(result == check);
  }
  {
    t_dest_string result;
    EXPECT_TRUE(::portable_stl::convert(result, source_utf8_2));
    EXPECT_TRUE(result == check);
  }
  {
    t_dest_string result;
    EXPECT_TRUE(::portable_stl::convert(result, source_utf16_2));
    EXPECT_TRUE(result == check);
  }
  {
    t_dest_string result;
    EXPECT_TRUE(::portable_stl::convert(result, source_utf32_2));
    EXPECT_TRUE(result == check);
  }
}

TEST(string_convert, from_string_to_ascii_3) {
  using t_dest_string = test_ascii_string;
  auto const &check   = source_ascii_3;
  {
    t_dest_string result;
    EXPECT_TRUE(::portable_stl::convert(result, source_ascii_3));
    EXPECT_TRUE(result == check);
  }
  {
    t_dest_string result;
    EXPECT_TRUE(::portable_stl::convert(result, source_ucs2_3));
    EXPECT_TRUE(result == check);
  }

  {
    t_dest_string result;
    EXPECT_TRUE(::portable_stl::convert(result, source_utf8_3));
    EXPECT_TRUE(result == check);
  }

  {
    t_dest_string result;
    EXPECT_TRUE(::portable_stl::convert(result, source_utf16_3));
    EXPECT_TRUE(result == check);
  }
  {
    t_dest_string result;
    EXPECT_TRUE(::portable_stl::convert(result, source_utf32_3));
    EXPECT_TRUE(result == check);
  }
}

TEST(string_convert, from_string_to_ucs2_1) {
  using t_dest_string = test_ucs2_string;
  auto const &check   = source_ucs2;
  {
    t_dest_string result;
    EXPECT_TRUE(::portable_stl::convert(result, source_ascii));
    EXPECT_TRUE(result == check);
  }
  {
    t_dest_string result;
    EXPECT_TRUE(::portable_stl::convert(result, source_ucs2));
    EXPECT_TRUE(result == check);
  }
  {
    t_dest_string result;
    EXPECT_TRUE(::portable_stl::convert(result, source_utf8));
    EXPECT_TRUE(result == check);
  }
  {
    t_dest_string result;
    EXPECT_TRUE(::portable_stl::convert(result, source_utf16));
    EXPECT_TRUE(result == check);
  }
  {
    t_dest_string result;
    EXPECT_TRUE(::portable_stl::convert(result, source_utf32));
    EXPECT_TRUE(result == check);
  }
}

TEST(string_convert, from_string_to_ucs2_2) {
  using t_dest_string = test_ucs2_string;
  auto const &check   = source_ucs2_2;
  {
    t_dest_string result;
    EXPECT_TRUE(::portable_stl::convert(result, source_ucs2_2));
    EXPECT_TRUE(result == check);
  }
  {
    t_dest_string result;
    EXPECT_TRUE(::portable_stl::convert(result, source_utf8_2));
    EXPECT_TRUE(result == check);
  }
  {
    t_dest_string result;
    EXPECT_TRUE(::portable_stl::convert(result, source_utf16_2));
    EXPECT_TRUE(result == check);
  }
  {
    t_dest_string result;
    EXPECT_TRUE(::portable_stl::convert(result, source_utf32_2));
    EXPECT_TRUE(result == check);
  }
}

TEST(string_convert, from_string_to_ucs2_3) {
  using t_dest_string = test_ucs2_string;
  auto const &check   = source_ucs2_3;
  {
    t_dest_string result;
    EXPECT_TRUE(::portable_stl::convert(result, source_ucs2_3));
    EXPECT_TRUE(result == check);
  }
  {
    t_dest_string result;
    EXPECT_TRUE(::portable_stl::convert(result, source_utf8_3));
    EXPECT_TRUE(result == check);
  }
  {
    t_dest_string result;
    EXPECT_TRUE(::portable_stl::convert(result, source_utf16_3));
    EXPECT_TRUE(result == check);
  }
  {
    t_dest_string result;
    EXPECT_TRUE(::portable_stl::convert(result, source_utf32_3));
    EXPECT_TRUE(result == check);
  }
}

TEST(string_convert, from_string_to_utf8_1) {
  using t_dest_string = test_utf8_string;
  auto const &check   = source_utf8;
  {
    t_dest_string result;
    EXPECT_TRUE(::portable_stl::convert(result, source_ascii));
    EXPECT_TRUE(result == check);
  }
  {
    t_dest_string result;
    EXPECT_TRUE(::portable_stl::convert(result, source_ucs2));
    EXPECT_TRUE(result == check);
  }
  {
    t_dest_string result;
    EXPECT_TRUE(::portable_stl::convert(result, source_utf8));
    EXPECT_TRUE(result == check);
  }
  {
    t_dest_string result;
    EXPECT_TRUE(::portable_stl::convert(result, source_utf16));
    EXPECT_TRUE(result == check);
  }
  {
    t_dest_string result;
    EXPECT_TRUE(::portable_stl::convert(result, source_utf32));
    EXPECT_TRUE(result == check);
  }
}

TEST(string_convert, from_string_to_utf8_2) {
  using t_dest_string = test_utf8_string;
  auto const &check   = source_utf8_2;
  {
    t_dest_string result;
    EXPECT_TRUE(::portable_stl::convert(result, source_ucs2_2));
    EXPECT_TRUE(result == check);
  }
  {
    t_dest_string result;
    EXPECT_TRUE(::portable_stl::convert(result, source_utf8_2));
    EXPECT_TRUE(result == check);
  }
  {
    t_dest_string result;
    EXPECT_TRUE(::portable_stl::convert(result, source_utf16_2));
    EXPECT_TRUE(result == check);
  }
  {
    t_dest_string result;
    EXPECT_TRUE(::portable_stl::convert(result, source_utf32_2));
    EXPECT_TRUE(result == check);
  }
}

TEST(string_convert, from_string_to_utf8_3) {
  using t_dest_string = test_utf8_string;
  auto const &check   = source_utf8_3;
  {
    t_dest_string result;
    EXPECT_TRUE(::portable_stl::convert(result, source_utf8_3));
    EXPECT_TRUE(result == check);
  }
  {
    t_dest_string result;
    EXPECT_TRUE(::portable_stl::convert(result, source_utf16_3));
    EXPECT_TRUE(result == check);
  }
  {
    t_dest_string result;
    EXPECT_TRUE(::portable_stl::convert(result, source_utf32_3));
    EXPECT_TRUE(result == check);
  }
}

TEST(string_convert, from_string_to_utf16_1) {
  using t_dest_string = test_utf16_string;
  auto const &check   = source_utf16;
  {
    t_dest_string result;
    EXPECT_TRUE(::portable_stl::convert(result, source_ascii));
    EXPECT_TRUE(result == check);
  }
  {
    t_dest_string result;
    EXPECT_TRUE(::portable_stl::convert(result, source_ucs2));
    EXPECT_TRUE(result == check);
  }
  {
    t_dest_string result;
    EXPECT_TRUE(::portable_stl::convert(result, source_utf8));
    EXPECT_TRUE(result == check);
  }
  {
    t_dest_string result;
    EXPECT_TRUE(::portable_stl::convert(result, source_utf16));
    EXPECT_TRUE(result == check);
  }
  {
    t_dest_string result;
    EXPECT_TRUE(::portable_stl::convert(result, source_utf32));
    EXPECT_TRUE(result == check);
  }
}

TEST(string_convert, from_string_to_utf16_2) {
  using t_dest_string = test_utf16_string;
  auto const &check   = source_utf16_2;
  {
    t_dest_string result;
    EXPECT_TRUE(::portable_stl::convert(result, source_ucs2_2));
    EXPECT_TRUE(result == check);
  }

  {
    t_dest_string result;
    EXPECT_TRUE(::portable_stl::convert(result, source_utf8_2));
    EXPECT_TRUE(result == check);
  }

  {
    t_dest_string result;
    EXPECT_TRUE(::portable_stl::convert(result, source_utf16_2));
    EXPECT_TRUE(result == check);
  }
  {
    t_dest_string result;
    EXPECT_TRUE(::portable_stl::convert(result, source_utf32_2));
    EXPECT_TRUE(result == check);
  }
}

TEST(string_convert, from_string_to_utf16_3) {
  using t_dest_string = test_utf16_string;
  auto const &check   = source_utf16_3;

  {
    t_dest_string result;
    EXPECT_TRUE(::portable_stl::convert(result, source_utf8_3));
    EXPECT_TRUE(result == check);
  }

  {
    t_dest_string result;
    EXPECT_TRUE(::portable_stl::convert(result, source_utf16_3));
    EXPECT_TRUE(result == check);
  }
  {
    t_dest_string result;
    EXPECT_TRUE(::portable_stl::convert(result, source_utf32_3));
    EXPECT_TRUE(result == check);
  }
}

TEST(string_convert, from_string_view_to_ascii_1) {
  using t_dest_string = test_ascii_string;
  auto const &check   = source_ascii;
  {
    t_dest_string result;
    EXPECT_TRUE(::portable_stl::convert(result, test_ascii_string_view{source_ascii}));
    EXPECT_TRUE(result == check);
  }
  {
    t_dest_string result;
    EXPECT_TRUE(::portable_stl::convert(result, test_ucs2_string_view{source_ucs2}));
    EXPECT_TRUE(result == check);
  }

  {
    t_dest_string result;
    EXPECT_TRUE(::portable_stl::convert(result, test_utf8_string_view{source_utf8}));
    EXPECT_TRUE(result == check);
  }

  {
    t_dest_string result;
    EXPECT_TRUE(::portable_stl::convert(result, test_utf16_string_view{source_utf16}));
    EXPECT_TRUE(result == check);
  }
  {
    t_dest_string result;
    EXPECT_TRUE(::portable_stl::convert(result, test_utf32_string_view{source_utf32}));
    EXPECT_TRUE(result == check);
  }
}

TEST(string_convert, from_string_view_to_ascii_2) {
  using t_dest_string = test_ascii_string;
  auto const &check   = source_ascii_2;
  {
    t_dest_string result;
    EXPECT_TRUE(::portable_stl::convert(result, test_ascii_string_view{source_ascii_2}));
    EXPECT_TRUE(result == check);
  }
  {
    t_dest_string result;
    EXPECT_TRUE(::portable_stl::convert(result, test_ucs2_string_view{source_ucs2_2}));
    EXPECT_TRUE(result == check);
  }

  {
    t_dest_string result;
    EXPECT_TRUE(::portable_stl::convert(result, test_utf8_string_view{source_utf8_2}));
    EXPECT_TRUE(result == check);
  }

  {
    t_dest_string result;
    EXPECT_TRUE(::portable_stl::convert(result, test_utf16_string_view{source_utf16_2}));
    EXPECT_TRUE(result == check);
  }
  {
    t_dest_string result;
    EXPECT_TRUE(::portable_stl::convert(result, test_utf32_string_view{source_utf32_2}));
    EXPECT_TRUE(result == check);
  }
}

TEST(string_convert, from_string_view_to_ascii_3) {
  using t_dest_string = test_ascii_string;
  auto const &check   = source_ascii_3;
  {
    t_dest_string result;
    EXPECT_TRUE(::portable_stl::convert(result, test_ascii_string_view{source_ascii_3}));
    EXPECT_TRUE(result == check);
  }
  {
    t_dest_string result;
    EXPECT_TRUE(::portable_stl::convert(result, test_ucs2_string_view{source_ucs2_3}));
    EXPECT_TRUE(result == check);
  }
  {
    t_dest_string result;
    EXPECT_TRUE(::portable_stl::convert(result, test_utf8_string_view{source_utf8_3}));
    EXPECT_TRUE(result == check);
  }
  {
    t_dest_string result;
    EXPECT_TRUE(::portable_stl::convert(result, test_utf16_string_view{source_utf16_3}));
    EXPECT_TRUE(result == check);
  }
  {
    t_dest_string result;
    EXPECT_TRUE(::portable_stl::convert(result, test_utf32_string_view{source_utf32_3}));
    EXPECT_TRUE(result == check);
  }
}

TEST(string_convert, from_string_view_to_ucs2_1) {
  using t_dest_string = test_ucs2_string;
  auto const &check   = source_ucs2;
  {
    t_dest_string result;
    EXPECT_TRUE(::portable_stl::convert(result, test_ascii_string_view{source_ascii}));
    EXPECT_TRUE(result == check);
  }
  {
    t_dest_string result;
    EXPECT_TRUE(::portable_stl::convert(result, test_ucs2_string_view{source_ucs2}));
    EXPECT_TRUE(result == check);
  }

  {
    t_dest_string result;
    EXPECT_TRUE(::portable_stl::convert(result, test_utf8_string_view{source_utf8}));
    EXPECT_TRUE(result == check);
  }

  {
    t_dest_string result;
    EXPECT_TRUE(::portable_stl::convert(result, test_utf16_string_view{source_utf16}));
    EXPECT_TRUE(result == check);
  }
  {
    t_dest_string result;
    EXPECT_TRUE(::portable_stl::convert(result, test_utf32_string_view{source_utf32}));
    EXPECT_TRUE(result == check);
  }
}

TEST(string_convert, from_string_view_to_ucs2_2) {
  using t_dest_string = test_ucs2_string;
  auto const &check   = source_ucs2_2;
  {
    t_dest_string result;
    EXPECT_TRUE(::portable_stl::convert(result, test_ucs2_string_view{source_ucs2_2}));
    EXPECT_TRUE(result == check);
  }
  {
    t_dest_string result;
    EXPECT_TRUE(::portable_stl::convert(result, test_utf8_string_view{source_utf8_2}));
    EXPECT_TRUE(result == check);
  }
  {
    t_dest_string result;
    EXPECT_TRUE(::portable_stl::convert(result, test_utf16_string_view{source_utf16_2}));
    EXPECT_TRUE(result == check);
  }
  {
    t_dest_string result;
    EXPECT_TRUE(::portable_stl::convert(result, test_utf32_string_view{source_utf32_2}));
    EXPECT_TRUE(result == check);
  }
}

TEST(string_convert, from_string_view_to_ucs2_3) {
  using t_dest_string = test_ucs2_string;
  auto const &check   = source_ucs2_3;
  {
    t_dest_string result;
    EXPECT_TRUE(::portable_stl::convert(result, test_ucs2_string_view{source_ucs2_3}));
    EXPECT_TRUE(result == check);
  }
  {
    t_dest_string result;
    EXPECT_TRUE(::portable_stl::convert(result, test_utf8_string_view{source_utf8_3}));
    EXPECT_TRUE(result == check);
  }
  {
    t_dest_string result;
    EXPECT_TRUE(::portable_stl::convert(result, test_utf16_string_view{source_utf16_3}));
    EXPECT_TRUE(result == check);
  }
  {
    t_dest_string result;
    EXPECT_TRUE(::portable_stl::convert(result, test_utf32_string_view{source_utf32_3}));
    EXPECT_TRUE(result == check);
  }
}

TEST(string_convert, from_string_view_to_utf8_1) {
  using t_dest_string = test_utf8_string;
  auto const &check   = source_utf8;
  {
    t_dest_string result;
    EXPECT_TRUE(::portable_stl::convert(result, test_ascii_string_view{source_ascii}));
    EXPECT_TRUE(result == check);
  }
  {
    t_dest_string result;
    EXPECT_TRUE(::portable_stl::convert(result, test_ucs2_string_view{source_ucs2}));
    EXPECT_TRUE(result == check);
  }
  {
    t_dest_string result;
    EXPECT_TRUE(::portable_stl::convert(result, test_utf8_string_view{source_utf8}));
    EXPECT_TRUE(result == check);
  }
  {
    t_dest_string result;
    EXPECT_TRUE(::portable_stl::convert(result, test_utf16_string_view{source_utf16}));
    EXPECT_TRUE(result == check);
  }
  {
    t_dest_string result;
    EXPECT_TRUE(::portable_stl::convert(result, test_utf32_string_view{source_utf32}));
    EXPECT_TRUE(result == check);
  }
}

TEST(string_convert, from_string_view_to_utf8_2) {
  using t_dest_string = test_utf8_string;
  auto const &check   = source_utf8_2;
  {
    t_dest_string result;
    EXPECT_TRUE(::portable_stl::convert(result, test_ucs2_string_view{source_ucs2_2}));
    EXPECT_TRUE(result == check);
  }
  {
    t_dest_string result;
    EXPECT_TRUE(::portable_stl::convert(result, test_utf8_string_view{source_utf8_2}));
    EXPECT_TRUE(result == check);
  }
  {
    t_dest_string result;
    EXPECT_TRUE(::portable_stl::convert(result, test_utf16_string_view{source_utf16_2}));
    EXPECT_TRUE(result == check);
  }
  {
    t_dest_string result;
    EXPECT_TRUE(::portable_stl::convert(result, test_utf32_string_view{source_utf32_2}));
    EXPECT_TRUE(result == check);
  }
}

TEST(string_convert, from_string_view_to_utf8_3) {
  using t_dest_string = test_utf8_string;
  auto const &check   = source_utf8_3;
  {
    t_dest_string result;
    EXPECT_TRUE(::portable_stl::convert(result, test_utf8_string_view{source_utf8_3}));
    EXPECT_TRUE(result == check);
  }
  {
    t_dest_string result;
    EXPECT_TRUE(::portable_stl::convert(result, test_utf16_string_view{source_utf16_3}));
    EXPECT_TRUE(result == check);
  }
  {
    t_dest_string result;
    EXPECT_TRUE(::portable_stl::convert(result, test_utf32_string_view{source_utf32_3}));
    EXPECT_TRUE(result == check);
  }
}

TEST(string_convert, from_string_view_to_utf16_1) {
  using t_dest_string = test_utf16_string;
  auto const &check   = source_utf16;
  {
    t_dest_string result;
    EXPECT_TRUE(::portable_stl::convert(result, test_ascii_string_view{source_ascii}));
    EXPECT_TRUE(result == check);
  }
  {
    t_dest_string result;
    EXPECT_TRUE(::portable_stl::convert(result, test_ucs2_string_view{source_ucs2}));
    EXPECT_TRUE(result == check);
  }
  {
    t_dest_string result;
    EXPECT_TRUE(::portable_stl::convert(result, test_utf8_string_view{source_utf8}));
    EXPECT_TRUE(result == check);
  }
  {
    t_dest_string result;
    EXPECT_TRUE(::portable_stl::convert(result, test_utf16_string_view{source_utf16}));
    EXPECT_TRUE(result == check);
  }
  {
    t_dest_string result;
    EXPECT_TRUE(::portable_stl::convert(result, test_utf32_string_view{source_utf32}));
    EXPECT_TRUE(result == check);
  }
}

TEST(string_convert, from_string_view_to_utf16_2) {
  using t_dest_string = test_utf16_string;
  auto const &check   = source_utf16_2;
  {
    t_dest_string result;
    EXPECT_TRUE(::portable_stl::convert(result, test_ucs2_string_view{source_ucs2_2}));
    EXPECT_TRUE(result == check);
  }
  {
    t_dest_string result;
    EXPECT_TRUE(::portable_stl::convert(result, test_utf8_string_view{source_utf8_2}));
    EXPECT_TRUE(result == check);
  }
  {
    t_dest_string result;
    EXPECT_TRUE(::portable_stl::convert(result, test_utf16_string_view{source_utf16_2}));
    EXPECT_TRUE(result == check);
  }
  {
    t_dest_string result;
    EXPECT_TRUE(::portable_stl::convert(result, test_utf32_string_view{source_utf32_2}));
    EXPECT_TRUE(result == check);
  }
}

TEST(string_convert, from_string_view_to_utf16_3) {
  using t_dest_string = test_utf16_string;
  auto const &check   = source_utf16_3;
  {
    t_dest_string result;
    EXPECT_TRUE(::portable_stl::convert(result, test_utf8_string_view{source_utf8_3}));
    EXPECT_TRUE(result == check);
  }
  {
    t_dest_string result;
    EXPECT_TRUE(::portable_stl::convert(result, test_utf16_string_view{source_utf16_3}));
    EXPECT_TRUE(result == check);
  }
  {
    t_dest_string result;
    EXPECT_TRUE(::portable_stl::convert(result, test_utf32_string_view{source_utf32_3}));
    EXPECT_TRUE(result == check);
  }
}
