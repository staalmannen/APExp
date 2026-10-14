// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="to_string.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_TO_STRING_H
#define PSTL_TO_STRING_H

// #include "../metaprogramming/primary_type/is_integral.h"
#include "../common/char_t.h"
#include "../common/size_t.h"
#include "../metaprogramming/type_properties/is_unsigned.h"
#include "string.h"

namespace portable_stl {

namespace string_helper {
  /**
   * @brief Generic implementation for arbitrary bases.
   *
   * @tparam t_type
   * @param value
   * @param base
   * @return unsigned
   */
  template<class t_type> unsigned int to_chars_len(t_type value, unsigned int base = 10U) noexcept {
    static_assert(::portable_stl::is_unsigned<t_type>{}(), "implementation bug");

    unsigned int        n{1};
    unsigned int const  b2{base * base};
    unsigned int const  b3{b2 * base};
    unsigned long const b4{b3 * base};
    for (;;) {
      if (value < base) {
        return n;
      }
      if (value < b2) {
        return n + 1U;
      }
      if (value < b3) {
        return n + 2U;
      }
      if (value < b4) {
        return n + 3U;
      }
      value /= b4;
      n += 4U;
    }
  }

  /**
   * @brief Write an unsigned integer value to the range [first,first+len).
   * The caller is required to provide a buffer of exactly the right size (which can be determined by the to_chars_len
   * function).
   *
   * @tparam t_type
   * @param first
   * @param len
   * @param value
   */
  template<class t_type> void to_chars_10_impl(::portable_stl::char_t *first, ::portable_stl::size_t len, t_type value) noexcept {
    static_assert(::portable_stl::is_unsigned<t_type>{}(), "implementation bug");

    constexpr ::portable_stl::char_t         digits[201] = "0001020304050607080910111213141516171819"
                                         "2021222324252627282930313233343536373839"
                                         "4041424344454647484950515253545556575859"
                                         "6061626364656667686970717273747576777879"
                                         "8081828384858687888990919293949596979899";
    ::portable_stl::size_t pos{len - 1U};
    while (value >= 100) {
      auto const num = (value % 100) * 2;
      value /= 100;
      first[pos]      = digits[num + 1U];
      first[pos - 1U] = digits[num];
      pos -= 2U;
    }
    if (value >= 10) {
      auto const num = value * 2;
      first[1]       = digits[num + 1U];
      first[0]       = digits[num];
    } else {
      first[0] = '0' + static_cast<::portable_stl::char_t>(value);
    }
  }
} // namespace string_helper

/**
 * @brief Converts a numeric value to ::string.
 * any 32-bit value fits in the SSO buffer
 *
 * @param value A numeric value to convert.
 * @return string A string holding the converted value.
 */
inline ::portable_stl::string to_string(int value) noexcept((sizeof(value) * 8) <= 32) {
  bool const         is_neg{value < 0};
  unsigned int const unsigned_value{is_neg ? static_cast<unsigned int>(~value) + 1U : static_cast<unsigned int>(value)};
  auto const         len = string_helper::to_chars_len(unsigned_value);
  ::portable_stl::string res_str;
  res_str.resize_and_overwrite(is_neg + len, [=](::portable_stl::string::iterator ptr, size_t num) {
    ptr[0] = '-';
    string_helper::to_chars_10_impl(ptr.base() + static_cast<int>(is_neg), len, unsigned_value);
    return num;
  });
  return res_str;
}

/**
 * @brief Converts a numeric value to ::string.
 * any 32-bit value fits in the SSO buffer
 *
 * @param value A numeric value to convert.
 * @return string A string holding the converted value.
 */
inline ::portable_stl::string to_string(unsigned int value) noexcept((sizeof(value) * 8) <= 32) {
  auto const             len = string_helper::to_chars_len(value);
  ::portable_stl::string res_str;
  res_str.resize_and_overwrite(len,
                               [value](::portable_stl::string::iterator ptr, ::portable_stl::string::size_type num) {
                                 string_helper::to_chars_10_impl(ptr.base(), num, value);
                                 return num;
                               });
  return res_str;
}

/**
 * @brief Converts a numeric value to ::string.
 * any 32-bit value fits in the SSO buffer
 *
 * @param value A numeric value to convert.
 * @return string A string holding the converted value.
 */
inline ::portable_stl::string to_string(long value) noexcept((sizeof(value) * 8) <= 32) {
  bool const             is_neg{value < 0};
  unsigned long const    unsigned_value{is_neg ? static_cast<unsigned long>(~value) + 1UL
                                               : static_cast<unsigned long>(value)};
  auto const             len = string_helper::to_chars_len(unsigned_value);
  ::portable_stl::string res_str;
  res_str.resize_and_overwrite(
    is_neg + len, [=](::portable_stl::string::iterator ptr, ::portable_stl::string::size_type num) {
      ptr[0] = '-';
      string_helper::to_chars_10_impl(ptr.base() + static_cast<int>(is_neg), len, unsigned_value);
      return num;
    });
  return res_str;
}

/**
 * @brief Converts a numeric value to ::string.
 * any 32-bit value fits in the SSO buffer
 *
 * @param value A numeric value to convert.
 * @return string A string holding the converted value.
 */
inline ::portable_stl::string to_string(unsigned long value) noexcept((sizeof(value) * 8) <= 32) {
  auto const             len = string_helper::to_chars_len(value);
  ::portable_stl::string res_str;
  res_str.resize_and_overwrite(len,
                               [value](::portable_stl::string::iterator ptr, ::portable_stl::string::size_type num) {
                                 string_helper::to_chars_10_impl(ptr.base(), num, value);
                                 return num;
                               });
  return res_str;
}

/**
 * @brief Converts a numeric value to ::string.
 *
 * @param value A numeric value to convert.
 * @return string A string holding the converted value.
 */
inline ::portable_stl::string to_string(long long value) {
  bool const               is_neg{value < 0};
  unsigned long long const unsigned_value{is_neg ? static_cast<unsigned long long>(~value) + 1ULL
                                                 : static_cast<unsigned long long>(value)};
  auto const               len = string_helper::to_chars_len(unsigned_value);
  ::portable_stl::string   res_str;
  res_str.resize_and_overwrite(
    is_neg + len, [=](::portable_stl::string::iterator ptr, ::portable_stl::string::size_type num) {
      ptr[0] = '-';
      string_helper::to_chars_10_impl(ptr.base() + static_cast<int>(is_neg), len, unsigned_value);
      return num;
    });
  return res_str;
}

/**
 * @brief Converts a numeric value to ::string.
 *
 * @param value A numeric value to convert.
 * @return string A string holding the converted value.
 */
inline ::portable_stl::string to_string(unsigned long long value) {
  auto const             len = string_helper::to_chars_len(value);
  ::portable_stl::string res_str;
  res_str.resize_and_overwrite(len, [value](string::iterator ptr, ::portable_stl::string::size_type num) {
    string_helper::to_chars_10_impl(ptr.base(), num, value);
    return num;
  });
  return res_str;
}

} // namespace portable_stl

#endif // PSTL_TO_STRING_H
