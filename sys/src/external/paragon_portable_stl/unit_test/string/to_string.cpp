// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="to_string.cpp"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#include <gtest/gtest.h>

#include "portable_stl/string/to_string.h"
#include "portable_stl/string/to_string2.h"

namespace test_string_helper {
template<class t_type> struct parse_integer_impl;

template<> struct parse_integer_impl<int> {
  template<class CharT> int operator()(std::basic_string<CharT> const &str) const {
    return std::stoi(str);
  }
};

template<> struct parse_integer_impl<long> {
  template<class CharT> long operator()(std::basic_string<CharT> const &str) const {
    return std::stol(str);
  }
};

template<> struct parse_integer_impl<long long> {
  template<class CharT> long long operator()(std::basic_string<CharT> const &str) const {
    return std::stoll(str);
  }
};

template<> struct parse_integer_impl<unsigned int> {
  template<class CharT> unsigned int operator()(std::basic_string<CharT> const &str) const {
    return static_cast<unsigned int>(std::stoul(str));
  }
};

template<> struct parse_integer_impl<unsigned long> {
  template<class CharT> unsigned long operator()(std::basic_string<CharT> const &str) const {
    return std::stoul(str);
  }
};

template<> struct parse_integer_impl<unsigned long long> {
  template<class CharT> unsigned long long operator()(std::basic_string<CharT> const &str) const {
    return std::stoull(str);
  }
};

template<class t_type, class CharT> t_type parse_integer(char *const c_str) {
  std::basic_string<CharT> str(c_str);
  return parse_integer_impl<t_type>()(str);
}
} // namespace test_string_helper

template<class t_type> void test_signed() {
  {
    ::portable_stl::string str = ::portable_stl::to_string(t_type(0));
    ASSERT_EQ(str.size(), 1);
    ASSERT_EQ(str[str.size()], 0);
    ASSERT_EQ(str, "0");
  }
  {
    ::portable_stl::string str = ::portable_stl::to_string(t_type(12345));
    ASSERT_EQ(str.size(), 5);
    ASSERT_EQ(str[str.size()], 0);
    ASSERT_EQ(str, "12345");
  }
  {
    ::portable_stl::string str = ::portable_stl::to_string(t_type(-12345));
    ASSERT_EQ(str.size(), 6);
    ASSERT_EQ(str[str.size()], 0);
    ASSERT_EQ(str, "-12345");
  }
  {
    ::portable_stl::string str = ::portable_stl::to_string(::portable_stl::numeric_limits<t_type>::max());

    EXPECT_EQ(str.size(), ::portable_stl::numeric_limits<t_type>::digits10 + 1) << str.c_str();
    t_type string_to_t_type_vale = test_string_helper::parse_integer<t_type, ::portable_stl::char_t>(str.data());
    EXPECT_EQ(::portable_stl::numeric_limits<t_type>::max(), string_to_t_type_vale);
  }
  {
    ::portable_stl::string str = ::portable_stl::to_string(::portable_stl::numeric_limits<t_type>::min());

    t_type string_to_t_type_vale = test_string_helper::parse_integer<t_type, ::portable_stl::char_t>(str.data());
    EXPECT_EQ(::portable_stl::numeric_limits<t_type>::min(), string_to_t_type_vale);
  }
}

template<class t_type> void test_unsigned() {
  {
    ::portable_stl::string str = ::portable_stl::to_string(t_type(0));
    ASSERT_EQ(str.size(), 1);
    ASSERT_EQ(str[str.size()], 0);
    ASSERT_EQ(str, "0");
  }
  {
    ::portable_stl::string str = ::portable_stl::to_string(t_type(12345));
    ASSERT_EQ(str.size(), 5);
    ASSERT_EQ(str[str.size()], 0);
    ASSERT_EQ(str, "12345");
  }
  {
    ::portable_stl::string str = ::portable_stl::to_string(::portable_stl::numeric_limits<t_type>::max());

    EXPECT_EQ(str.size(), ::portable_stl::numeric_limits<t_type>::digits10 + 1) << str.c_str();
    t_type string_to_t_type_vale = test_string_helper::parse_integer<t_type, ::portable_stl::char_t>(str.data());
    EXPECT_EQ(::portable_stl::numeric_limits<t_type>::max(), string_to_t_type_vale);
  }
}

TEST(string, to_string_integer) {
  static_cast<void>(test_info_);

  test_signed<std::int32_t>();
  test_signed<std::int64_t>();
  test_unsigned<std::uint32_t>();
  test_unsigned<std::uint64_t>();
}

template<class t_string, class t_type> void test_to_string2(t_type value, t_string const &ref) {
  auto str = ::portable_stl::to_string2<t_string>(value);
  ASSERT_EQ(str, ref);
}

TEST(string, to_string2_integer) {
  static_cast<void>(test_info_);

  test_to_string2<::portable_stl::string, int>(0, "0");
  test_to_string2<::portable_stl::string, int>(12345, "12345");
  test_to_string2<::portable_stl::string, int>(-12345, "-12345");
  test_to_string2<::portable_stl::string, int>(2147483647, "2147483647");
  test_to_string2<::portable_stl::string, int>(-2147483647, "-2147483647");
  test_to_string2<::portable_stl::string, unsigned int>(4294967295, "4294967295");
  test_to_string2<::portable_stl::string, long long>(9'223'372'036'854'775'807, "9223372036854775807");
  test_to_string2<::portable_stl::string, long long>(-9'223'372'036'854'775'807, "-9223372036854775807");

  test_to_string2<::portable_stl::wstring, int>(0, L"0");
  test_to_string2<::portable_stl::wstring, int>(12345, L"12345");
  test_to_string2<::portable_stl::wstring, int>(-12345, L"-12345");
  test_to_string2<::portable_stl::wstring, int>(2147483647, L"2147483647");
  test_to_string2<::portable_stl::wstring, int>(-2147483647, L"-2147483647");
  test_to_string2<::portable_stl::wstring, unsigned int>(4294967295, L"4294967295");
  test_to_string2<::portable_stl::wstring, long long>(9'223'372'036'854'775'807, L"9223372036854775807");
  test_to_string2<::portable_stl::wstring, long long>(-9'223'372'036'854'775'807, L"-9223372036854775807");

  test_to_string2<::portable_stl::u8string, int>(0, u8"0");
  test_to_string2<::portable_stl::u8string, int>(12345, u8"12345");
  test_to_string2<::portable_stl::u8string, int>(-12345, u8"-12345");
  test_to_string2<::portable_stl::u8string, int>(2147483647, u8"2147483647");
  test_to_string2<::portable_stl::u8string, int>(-2147483647, u8"-2147483647");
  test_to_string2<::portable_stl::u8string, unsigned int>(4294967295, u8"4294967295");
  test_to_string2<::portable_stl::u8string, long long>(9'223'372'036'854'775'807, u8"9223372036854775807");
  test_to_string2<::portable_stl::u8string, long long>(-9'223'372'036'854'775'807, u8"-9223372036854775807");

  test_to_string2<::portable_stl::u16string, int>(0, u"0");
  test_to_string2<::portable_stl::u16string, int>(12345, u"12345");
  test_to_string2<::portable_stl::u16string, int>(-12345, u"-12345");
  test_to_string2<::portable_stl::u16string, int>(2147483647, u"2147483647");
  test_to_string2<::portable_stl::u16string, int>(-2147483647, u"-2147483647");
  test_to_string2<::portable_stl::u16string, unsigned int>(4294967295, u"4294967295");
  test_to_string2<::portable_stl::u16string, long long>(9'223'372'036'854'775'807, u"9223372036854775807");
  test_to_string2<::portable_stl::u16string, long long>(-9'223'372'036'854'775'807, u"-9223372036854775807");

  test_to_string2<::portable_stl::u32string, int>(0, U"0");
  test_to_string2<::portable_stl::u32string, int>(12345, U"12345");
  test_to_string2<::portable_stl::u32string, int>(-12345, U"-12345");
  test_to_string2<::portable_stl::u32string, int>(2147483647, U"2147483647");
  test_to_string2<::portable_stl::u32string, int>(-2147483647, U"-2147483647");
  test_to_string2<::portable_stl::u32string, unsigned int>(4294967295, U"4294967295");
  test_to_string2<::portable_stl::u32string, long long>(9'223'372'036'854'775'807, U"9223372036854775807");
  test_to_string2<::portable_stl::u32string, long long>(-9'223'372'036'854'775'807, U"-9223372036854775807");
}

TEST(string, to_string2_float) {
  static_cast<void>(test_info_);

  test_to_string2<::portable_stl::string, float>(0.0f, "0");
  test_to_string2<::portable_stl::string, float>(-0.0f, "0");
  test_to_string2<::portable_stl::string, float>(0.1f, "0.1");
  test_to_string2<::portable_stl::string, float>(0.01f, "0.01");
  test_to_string2<::portable_stl::string, float>(0.001f, "0.001");
  test_to_string2<::portable_stl::string, float>(0.0001f, "0.0001");
  test_to_string2<::portable_stl::string, float>(0.00001f, "0.00001");
  test_to_string2<::portable_stl::string, float>(-0.00001f, "-0.00001");
  test_to_string2<::portable_stl::string, float>(-1.23456f, "-1.23456");
  test_to_string2<::portable_stl::string, float>(1.23456f, "1.23456");

  test_to_string2<::portable_stl::wstring, float>(0.0f, L"0");
  test_to_string2<::portable_stl::wstring, float>(-0.0f, L"0");
  test_to_string2<::portable_stl::wstring, float>(0.1f, L"0.1");
  test_to_string2<::portable_stl::wstring, float>(0.01f, L"0.01");
  test_to_string2<::portable_stl::wstring, float>(0.001f, L"0.001");
  test_to_string2<::portable_stl::wstring, float>(0.0001f, L"0.0001");
  test_to_string2<::portable_stl::wstring, float>(0.00001f, L"0.00001");
  test_to_string2<::portable_stl::wstring, float>(-0.00001f, L"-0.00001");
  test_to_string2<::portable_stl::wstring, float>(-1.23456f, L"-1.23456");
  test_to_string2<::portable_stl::wstring, float>(1.23456f, L"1.23456");

  test_to_string2<::portable_stl::u8string, float>(0.0f, u8"0");
  test_to_string2<::portable_stl::u8string, float>(-0.0f, u8"0");
  test_to_string2<::portable_stl::u8string, float>(0.1f, u8"0.1");
  test_to_string2<::portable_stl::u8string, float>(0.01f, u8"0.01");
  test_to_string2<::portable_stl::u8string, float>(0.001f, u8"0.001");
  test_to_string2<::portable_stl::u8string, float>(0.0001f, u8"0.0001");
  test_to_string2<::portable_stl::u8string, float>(0.00001f, u8"0.00001");
  test_to_string2<::portable_stl::u8string, float>(-0.00001f, u8"-0.00001");
  test_to_string2<::portable_stl::u8string, float>(-1.23456f, u8"-1.23456");
  test_to_string2<::portable_stl::u8string, float>(1.23456f, u8"1.23456");

  test_to_string2<::portable_stl::u16string, float>(0.0f, u"0");
  test_to_string2<::portable_stl::u16string, float>(-0.0f, u"0");
  test_to_string2<::portable_stl::u16string, float>(0.1f, u"0.1");
  test_to_string2<::portable_stl::u16string, float>(0.01f, u"0.01");
  test_to_string2<::portable_stl::u16string, float>(0.001f, u"0.001");
  test_to_string2<::portable_stl::u16string, float>(0.0001f, u"0.0001");
  test_to_string2<::portable_stl::u16string, float>(0.00001f, u"0.00001");
  test_to_string2<::portable_stl::u16string, float>(-0.00001f, u"-0.00001");
  test_to_string2<::portable_stl::u16string, float>(-1.23456f, u"-1.23456");
  test_to_string2<::portable_stl::u16string, float>(1.23456f, u"1.23456");

  test_to_string2<::portable_stl::u32string, float>(0.0f, U"0");
  test_to_string2<::portable_stl::u32string, float>(-0.0f, U"0");
  test_to_string2<::portable_stl::u32string, float>(0.1f, U"0.1");
  test_to_string2<::portable_stl::u32string, float>(0.01f, U"0.01");
  test_to_string2<::portable_stl::u32string, float>(0.001f, U"0.001");
  test_to_string2<::portable_stl::u32string, float>(0.0001f, U"0.0001");
  test_to_string2<::portable_stl::u32string, float>(0.00001f, U"0.00001");
  test_to_string2<::portable_stl::u32string, float>(-0.00001f, U"-0.00001");
  test_to_string2<::portable_stl::u32string, float>(-1.23456f, U"-1.23456");
  test_to_string2<::portable_stl::u32string, float>(1.23456f, U"1.23456");
}

TEST(string, to_string2_double) {
  static_cast<void>(test_info_);

  test_to_string2<::portable_stl::string, double>(0.0, "0");
  test_to_string2<::portable_stl::string, double>(-0.0, "0");
  test_to_string2<::portable_stl::string, double>(0.1, "0.1");
  test_to_string2<::portable_stl::string, double>(0.01, "0.01");
  test_to_string2<::portable_stl::string, double>(0.001, "0.001");
  test_to_string2<::portable_stl::string, double>(0.0001, "0.0001");
  test_to_string2<::portable_stl::string, double>(0.00001, "0.00001");
  test_to_string2<::portable_stl::string, double>(0.000001, "0.000001");
  test_to_string2<::portable_stl::string, double>(0.0000001, "0.0000001");
  test_to_string2<::portable_stl::string, double>(0.00000001, "0.00000001");
  test_to_string2<::portable_stl::string, double>(0.000000001, "0.000000001");
  test_to_string2<::portable_stl::string, double>(0.0000000001, "0.0000000001");
  test_to_string2<::portable_stl::string, double>(0.00000000001, "0.00000000001");
  test_to_string2<::portable_stl::string, double>(0.000000000001, "0.000000000001");
  test_to_string2<::portable_stl::string, double>(0.0000000000001, "0.0000000000001");
  test_to_string2<::portable_stl::string, double>(0.00000000000001, "0.00000000000001");
  test_to_string2<::portable_stl::string, double>(-0.00000000000001, "-0.00000000000001");
  test_to_string2<::portable_stl::string, double>(1.23456789012345, "1.23456789012345");
  test_to_string2<::portable_stl::string, double>(-1.23456789012345, "-1.23456789012345");
  test_to_string2<::portable_stl::string, double>(12.3456789012345, "12.3456789012345");
  test_to_string2<::portable_stl::string, double>(123.456789012345, "123.456789012345");
  test_to_string2<::portable_stl::string, double>(1234.56789012345, "1234.56789012345");
  test_to_string2<::portable_stl::string, double>(12345.6789012345, "12345.6789012345");
  test_to_string2<::portable_stl::string, double>(123456.789012345, "123456.789012345");
  test_to_string2<::portable_stl::string, double>(1234567.89012345, "1234567.89012345");
  test_to_string2<::portable_stl::string, double>(12345678.9012345, "12345678.9012345");
  test_to_string2<::portable_stl::string, double>(123456789.012345, "123456789.012345");
  test_to_string2<::portable_stl::string, double>(1234567890.12345, "1234567890.12345");
  test_to_string2<::portable_stl::string, double>(12345678901.2345, "12345678901.2345");
  test_to_string2<::portable_stl::string, double>(123456789012.345, "123456789012.345");
  test_to_string2<::portable_stl::string, double>(1234567890123.45, "1234567890123.45");
  test_to_string2<::portable_stl::string, double>(12345678901234.5, "12345678901234.5");
  test_to_string2<::portable_stl::string, double>(123456789012345.0, "123456789012345");
  test_to_string2<::portable_stl::string, double>(-123456789012345.0, "-123456789012345");

  test_to_string2<::portable_stl::string, double>(1E50, "100000000000000000000000000000000000000000000000000");

  test_to_string2<::portable_stl::wstring, double>(0.0, L"0");
  test_to_string2<::portable_stl::wstring, double>(-0.0, L"0");
  test_to_string2<::portable_stl::wstring, double>(0.1, L"0.1");
  test_to_string2<::portable_stl::wstring, double>(0.01, L"0.01");
  test_to_string2<::portable_stl::wstring, double>(0.001, L"0.001");
  test_to_string2<::portable_stl::wstring, double>(0.0001, L"0.0001");
  test_to_string2<::portable_stl::wstring, double>(0.00001, L"0.00001");
  test_to_string2<::portable_stl::wstring, double>(0.000001, L"0.000001");
  test_to_string2<::portable_stl::wstring, double>(0.0000001, L"0.0000001");
  test_to_string2<::portable_stl::wstring, double>(0.00000001, L"0.00000001");
  test_to_string2<::portable_stl::wstring, double>(0.000000001, L"0.000000001");
  test_to_string2<::portable_stl::wstring, double>(0.0000000001, L"0.0000000001");
  test_to_string2<::portable_stl::wstring, double>(0.00000000001, L"0.00000000001");
  test_to_string2<::portable_stl::wstring, double>(0.000000000001, L"0.000000000001");
  test_to_string2<::portable_stl::wstring, double>(0.0000000000001, L"0.0000000000001");
  test_to_string2<::portable_stl::wstring, double>(0.00000000000001, L"0.00000000000001");
  test_to_string2<::portable_stl::wstring, double>(-0.00000000000001, L"-0.00000000000001");
  test_to_string2<::portable_stl::wstring, double>(1.23456789012345, L"1.23456789012345");
  test_to_string2<::portable_stl::wstring, double>(-1.23456789012345, L"-1.23456789012345");
  test_to_string2<::portable_stl::wstring, double>(12.3456789012345, L"12.3456789012345");
  test_to_string2<::portable_stl::wstring, double>(123.456789012345, L"123.456789012345");
  test_to_string2<::portable_stl::wstring, double>(1234.56789012345, L"1234.56789012345");
  test_to_string2<::portable_stl::wstring, double>(12345.6789012345, L"12345.6789012345");
  test_to_string2<::portable_stl::wstring, double>(123456.789012345, L"123456.789012345");
  test_to_string2<::portable_stl::wstring, double>(1234567.89012345, L"1234567.89012345");
  test_to_string2<::portable_stl::wstring, double>(12345678.9012345, L"12345678.9012345");
  test_to_string2<::portable_stl::wstring, double>(123456789.012345, L"123456789.012345");
  test_to_string2<::portable_stl::wstring, double>(1234567890.12345, L"1234567890.12345");
  test_to_string2<::portable_stl::wstring, double>(12345678901.2345, L"12345678901.2345");
  test_to_string2<::portable_stl::wstring, double>(123456789012.345, L"123456789012.345");
  test_to_string2<::portable_stl::wstring, double>(1234567890123.45, L"1234567890123.45");
  test_to_string2<::portable_stl::wstring, double>(12345678901234.5, L"12345678901234.5");
  test_to_string2<::portable_stl::wstring, double>(123456789012345.0, L"123456789012345");
  test_to_string2<::portable_stl::wstring, double>(-123456789012345.0, L"-123456789012345");

  test_to_string2<::portable_stl::u8string, double>(0.0, u8"0");
  test_to_string2<::portable_stl::u8string, double>(-0.0, u8"0");
  test_to_string2<::portable_stl::u8string, double>(0.1, u8"0.1");
  test_to_string2<::portable_stl::u8string, double>(0.01, u8"0.01");
  test_to_string2<::portable_stl::u8string, double>(0.001, u8"0.001");
  test_to_string2<::portable_stl::u8string, double>(0.0001, u8"0.0001");
  test_to_string2<::portable_stl::u8string, double>(0.00001, u8"0.00001");
  test_to_string2<::portable_stl::u8string, double>(0.000001, u8"0.000001");
  test_to_string2<::portable_stl::u8string, double>(0.0000001, u8"0.0000001");
  test_to_string2<::portable_stl::u8string, double>(0.00000001, u8"0.00000001");
  test_to_string2<::portable_stl::u8string, double>(0.000000001, u8"0.000000001");
  test_to_string2<::portable_stl::u8string, double>(0.0000000001, u8"0.0000000001");
  test_to_string2<::portable_stl::u8string, double>(0.00000000001, u8"0.00000000001");
  test_to_string2<::portable_stl::u8string, double>(0.000000000001, u8"0.000000000001");
  test_to_string2<::portable_stl::u8string, double>(0.0000000000001, u8"0.0000000000001");
  test_to_string2<::portable_stl::u8string, double>(0.00000000000001, u8"0.00000000000001");
  test_to_string2<::portable_stl::u8string, double>(-0.00000000000001, u8"-0.00000000000001");
  test_to_string2<::portable_stl::u8string, double>(1.23456789012345, u8"1.23456789012345");
  test_to_string2<::portable_stl::u8string, double>(-1.23456789012345, u8"-1.23456789012345");
  test_to_string2<::portable_stl::u8string, double>(12.3456789012345, u8"12.3456789012345");
  test_to_string2<::portable_stl::u8string, double>(123.456789012345, u8"123.456789012345");
  test_to_string2<::portable_stl::u8string, double>(1234.56789012345, u8"1234.56789012345");
  test_to_string2<::portable_stl::u8string, double>(12345.6789012345, u8"12345.6789012345");
  test_to_string2<::portable_stl::u8string, double>(123456.789012345, u8"123456.789012345");
  test_to_string2<::portable_stl::u8string, double>(1234567.89012345, u8"1234567.89012345");
  test_to_string2<::portable_stl::u8string, double>(12345678.9012345, u8"12345678.9012345");
  test_to_string2<::portable_stl::u8string, double>(123456789.012345, u8"123456789.012345");
  test_to_string2<::portable_stl::u8string, double>(1234567890.12345, u8"1234567890.12345");
  test_to_string2<::portable_stl::u8string, double>(12345678901.2345, u8"12345678901.2345");
  test_to_string2<::portable_stl::u8string, double>(123456789012.345, u8"123456789012.345");
  test_to_string2<::portable_stl::u8string, double>(1234567890123.45, u8"1234567890123.45");
  test_to_string2<::portable_stl::u8string, double>(12345678901234.5, u8"12345678901234.5");
  test_to_string2<::portable_stl::u8string, double>(123456789012345.0, u8"123456789012345");
  test_to_string2<::portable_stl::u8string, double>(-123456789012345.0, u8"-123456789012345");

  test_to_string2<::portable_stl::u16string, double>(0.0, u"0");
  test_to_string2<::portable_stl::u16string, double>(-0.0, u"0");
  test_to_string2<::portable_stl::u16string, double>(0.1, u"0.1");
  test_to_string2<::portable_stl::u16string, double>(0.01, u"0.01");
  test_to_string2<::portable_stl::u16string, double>(0.001, u"0.001");
  test_to_string2<::portable_stl::u16string, double>(0.0001, u"0.0001");
  test_to_string2<::portable_stl::u16string, double>(0.00001, u"0.00001");
  test_to_string2<::portable_stl::u16string, double>(0.000001, u"0.000001");
  test_to_string2<::portable_stl::u16string, double>(0.0000001, u"0.0000001");
  test_to_string2<::portable_stl::u16string, double>(0.00000001, u"0.00000001");
  test_to_string2<::portable_stl::u16string, double>(0.000000001, u"0.000000001");
  test_to_string2<::portable_stl::u16string, double>(0.0000000001, u"0.0000000001");
  test_to_string2<::portable_stl::u16string, double>(0.00000000001, u"0.00000000001");
  test_to_string2<::portable_stl::u16string, double>(0.000000000001, u"0.000000000001");
  test_to_string2<::portable_stl::u16string, double>(0.0000000000001, u"0.0000000000001");
  test_to_string2<::portable_stl::u16string, double>(0.00000000000001, u"0.00000000000001");
  test_to_string2<::portable_stl::u16string, double>(-0.00000000000001, u"-0.00000000000001");
  test_to_string2<::portable_stl::u16string, double>(1.23456789012345, u"1.23456789012345");
  test_to_string2<::portable_stl::u16string, double>(-1.23456789012345, u"-1.23456789012345");
  test_to_string2<::portable_stl::u16string, double>(12.3456789012345, u"12.3456789012345");
  test_to_string2<::portable_stl::u16string, double>(123.456789012345, u"123.456789012345");
  test_to_string2<::portable_stl::u16string, double>(1234.56789012345, u"1234.56789012345");
  test_to_string2<::portable_stl::u16string, double>(12345.6789012345, u"12345.6789012345");
  test_to_string2<::portable_stl::u16string, double>(123456.789012345, u"123456.789012345");
  test_to_string2<::portable_stl::u16string, double>(1234567.89012345, u"1234567.89012345");
  test_to_string2<::portable_stl::u16string, double>(12345678.9012345, u"12345678.9012345");
  test_to_string2<::portable_stl::u16string, double>(123456789.012345, u"123456789.012345");
  test_to_string2<::portable_stl::u16string, double>(1234567890.12345, u"1234567890.12345");
  test_to_string2<::portable_stl::u16string, double>(12345678901.2345, u"12345678901.2345");
  test_to_string2<::portable_stl::u16string, double>(123456789012.345, u"123456789012.345");
  test_to_string2<::portable_stl::u16string, double>(1234567890123.45, u"1234567890123.45");
  test_to_string2<::portable_stl::u16string, double>(12345678901234.5, u"12345678901234.5");
  test_to_string2<::portable_stl::u16string, double>(123456789012345.0, u"123456789012345");
  test_to_string2<::portable_stl::u16string, double>(-123456789012345.0, u"-123456789012345");

  test_to_string2<::portable_stl::u32string, double>(0.0, U"0");
  test_to_string2<::portable_stl::u32string, double>(-0.0, U"0");
  test_to_string2<::portable_stl::u32string, double>(0.1, U"0.1");
  test_to_string2<::portable_stl::u32string, double>(0.01, U"0.01");
  test_to_string2<::portable_stl::u32string, double>(0.001, U"0.001");
  test_to_string2<::portable_stl::u32string, double>(0.0001, U"0.0001");
  test_to_string2<::portable_stl::u32string, double>(0.00001, U"0.00001");
  test_to_string2<::portable_stl::u32string, double>(0.000001, U"0.000001");
  test_to_string2<::portable_stl::u32string, double>(0.0000001, U"0.0000001");
  test_to_string2<::portable_stl::u32string, double>(0.00000001, U"0.00000001");
  test_to_string2<::portable_stl::u32string, double>(0.000000001, U"0.000000001");
  test_to_string2<::portable_stl::u32string, double>(0.0000000001, U"0.0000000001");
  test_to_string2<::portable_stl::u32string, double>(0.00000000001, U"0.00000000001");
  test_to_string2<::portable_stl::u32string, double>(0.000000000001, U"0.000000000001");
  test_to_string2<::portable_stl::u32string, double>(0.0000000000001, U"0.0000000000001");
  test_to_string2<::portable_stl::u32string, double>(0.00000000000001, U"0.00000000000001");
  test_to_string2<::portable_stl::u32string, double>(-0.00000000000001, U"-0.00000000000001");
  test_to_string2<::portable_stl::u32string, double>(1.23456789012345, U"1.23456789012345");
  test_to_string2<::portable_stl::u32string, double>(-1.23456789012345, U"-1.23456789012345");
  test_to_string2<::portable_stl::u32string, double>(12.3456789012345, U"12.3456789012345");
  test_to_string2<::portable_stl::u32string, double>(123.456789012345, U"123.456789012345");
  test_to_string2<::portable_stl::u32string, double>(1234.56789012345, U"1234.56789012345");
  test_to_string2<::portable_stl::u32string, double>(12345.6789012345, U"12345.6789012345");
  test_to_string2<::portable_stl::u32string, double>(123456.789012345, U"123456.789012345");
  test_to_string2<::portable_stl::u32string, double>(1234567.89012345, U"1234567.89012345");
  test_to_string2<::portable_stl::u32string, double>(12345678.9012345, U"12345678.9012345");
  test_to_string2<::portable_stl::u32string, double>(123456789.012345, U"123456789.012345");
  test_to_string2<::portable_stl::u32string, double>(1234567890.12345, U"1234567890.12345");
  test_to_string2<::portable_stl::u32string, double>(12345678901.2345, U"12345678901.2345");
  test_to_string2<::portable_stl::u32string, double>(123456789012.345, U"123456789012.345");
  test_to_string2<::portable_stl::u32string, double>(1234567890123.45, U"1234567890123.45");
  test_to_string2<::portable_stl::u32string, double>(12345678901234.5, U"12345678901234.5");
  test_to_string2<::portable_stl::u32string, double>(123456789012345.0, U"123456789012345");
  test_to_string2<::portable_stl::u32string, double>(-123456789012345.0, U"-123456789012345");
}
