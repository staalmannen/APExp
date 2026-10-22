// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="char_traits.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_CHAR_TRAITS_H
#define PSTL_CHAR_TRAITS_H

#include "../algorithm/copy_n.h"
#include "../algorithm/fill_n.h"
#include "../common/char8_t.h"
#include "../common/char_t.h"
#include "../common/cstdint.h"
#include "../common/size_t.h"
#include "../compare/strong_ordering.h"
#include "../memory/memcmp.h"
#include "../memory/memcpy.h"
#include "../memory/memmove.h"
#include "../memory/wmemcmp.h"
#include "builtin_char_memchr.h"
#include "builtin_strlen.h"
#include "builtin_wcslen.h"
#include "builtin_wmemchr.h"

namespace portable_stl {

/**
 * @brief The char_traits class is a traits class template that abstracts basic character and string operations for a
 * given character type.
 *
 * @tparam t_char_type Given character type.
 */
template<class t_char_type> class char_traits final {
public:
  /**
   * @brief Given character type.
   *
   */
  using char_type = t_char_type;

  /**
   * @brief Shall be able to represent all of the valid characters converted from the corresponding char_type values, as
   * well as an end-of-file value, eof().
   */
  using int_type            = ::portable_stl::int32_t;
  using off_type            = ::portable_stl::int64_t;
  using pos_type            = ::portable_stl::size_t;
  using state_type          = ::portable_stl::uint32_t;
  using comparison_category = ::portable_stl::strong_ordering;

  /**
   * @brief Assigns rhv to lhv, behaves identically to lhv = rhv.
   *
   * @param lhv Character to assign to.
   * @param rhv Character value to assign.
   */
  constexpr inline static void assign(char_type &lhv, char_type const &rhv) noexcept {
    lhv = rhv;
  }

  /**
   * @brief Assigns rhv to each character in count characters in the character sequence pointed to by ptr.
   *
   * @param ptr Pointer to a character sequence to assign to.
   * @param count The length of the character sequence.
   * @param rhv Character value to assign.
   * @return char_type*
   */
  inline static char_type *assign(char_type *ptr, ::portable_stl::size_t count, char_type rhv) noexcept {
    for (::portable_stl::size_t pos{0ULL}; pos < count; ++pos) {
      assign(ptr[pos], rhv);
    }
    return ptr;
  }

  /**
   * @brief Compares a and b for equality.
   *
   * @param a Characte values to compare.
   * @param b Characte values to compare.
   * @return true if a == b,
   * @return false if !(a == b).
   */
  constexpr inline static bool eq(char_type const a, char_type const b) noexcept {
    return a == b;
  }

  /**
   * @brief Compares a and b in such a way that they are totally ordered.
   *
   * @param a Characte values to compare.
   * @param b Characte values to compare.
   * @return true if a < b,
   * @return false if !(a < b).
   */
  constexpr inline static bool lt(char_type const a, char_type const b) noexcept {
    return a < b;
  }

  /**
   * @brief Copies count characters from the character string pointed to by src to the character string pointed to by
   * dest.
   *
   * @param dest Pointer to a character string to copy to.
   * @param src Pointer to a character string to copy from.
   * @param count The number of characters to copy.
   * @return dest.
   */
  inline static char_type *move(char_type *dest, char_type const *src, ::portable_stl::size_t count) noexcept {
    if (0 == count) {
      return dest;
    }
    char_type *ret = dest;
    if (dest < src) {
      for (; count; --count, ++dest, ++src) {
        assign(*dest, *src);
      }
    } else if (src < dest) {
      dest += count;
      src += count;
      for (; count; --count) {
        assign(*--dest, *--src);
      }
    }
    return ret;
  }

  /**
   * @brief Copies count characters from the character string pointed to by src to the character string pointed to by
   * dest.
   *
   * @param dest Pointer to a character string to copy to.
   * @param src Pointer to a character string to copy from.
   * @param count The number of characters to copy.
   * @return constexpr char_type*
   */
  inline static char_type *copy(char_type *dest, char_type const *src, ::portable_stl::size_t count) noexcept {
    char_type *ret = dest;
    for (; count; --count, ++dest, ++src) {
      assign(*dest, *src);
    }
    return ret;
  }

  /**
   * @brief Compares the first count characters of the character strings s1 and s2.
   * The comparison is done lexicographically.
   * If count is zero, strings are considered equal.
   *
   * @param s1 	Pointer to character strings to compare.
   * @param s2 	Pointer to character strings to compare.
   * @param count 	The number of characters to compare from each character string.
   * @return -1 if s1 is less than s2,
   * @return 0 if s1 is equal to s2,
   * @return 1 if s1 is greater than s2.
   */
  inline static ::portable_stl::int32_t compare(
    char_type const *const s1, char_type const *const s2, ::portable_stl::size_t const count) noexcept {
    for (::portable_stl::size_t pos{0}; pos < count; ++pos) {
      if (lt(s1[pos], s2[pos])) {
        return -1;
      }
      if (lt(s2[pos], s1[pos])) {
        return 1;
      }
    }
    return 0;
  }

  /**
   * @brief Returns the length of the character sequence pointed to by s, that is, the position of the terminating null
   * character (char_type()).
   *
   * @param seq_ptr Pointer to a character sequence to return length of.
   * @return The length of character sequence pointed to by s.
   */
  inline static ::portable_stl::size_t length(char_type const *const seq_ptr) noexcept {
    t_char_type const      eos{0};
    ::portable_stl::size_t position{0};
    while (!eq(seq_ptr[position], eos)) {
      ++position;
    }
    return position;
  }

  /**
   * @brief Searches for character ch within the first count characters of the sequence pointed to by ptr.
   *
   * @param ptr Pointer to a character string to search.
   * @param count  	The number of characters to analyze.
   * @param ch 	The character to search for.
   * @return A pointer to the first character in the range specified by [ptr, ptr + count) that compares equal to ch, or
   * a null pointer if not found.
   */
  inline static char_type const *find(
    char_type const *ptr, ::portable_stl::size_t count, char_type const &ch) noexcept {
    for (::portable_stl::size_t pos{0}; pos < count; ++pos) {
      if (eq(ptr[pos], ch)) {
        return &(ptr[pos]);
      }
    }
    return nullptr;
  }

  /**
   * @brief Converts c to char_type. If there is no equivalent char_type value (such as when c is a copy of the eof()
   * value), the result is unspecified.
   *
   * @param value Value to convert.
   * @return A value equivalent to c.
   */
  constexpr inline static char_type to_char_type(int_type value) noexcept {
    return static_cast<char_type>(value);
  }

  /**
   * @brief Converts c to int_type.
   *
   * @param chr Value to convert.
   * @return A value equivalent to c.
   */
  constexpr inline static int_type to_int_type(char_type chr) noexcept {
    return static_cast<int_type>(chr);
  }

  /**
   * @brief Checks whether two values of type int_type are equal.
   *
   * @param c1 Value to compare.
   * @param c2 Value to compare.
   * @return true if c1 is equal to c2,
   * @return false otherwise.
   */
  constexpr inline static bool eq_int_type(int_type c1, int_type c2) noexcept {
    return c1 == c2;
  }

  /**
   * @brief Returns a value not equivalent to any valid value of type char_type.
   *
   * @return constexpr int_type
   */
  constexpr inline static int_type eof() noexcept {
    return -1;
  }

  /**
   * @brief Given e, produces a suitable value that is not equivalent to eof.
   * This function is typically used when a value other than eof needs to be returned, such as in implementations of
   * ::basic_streambuf::overflow().
   *
   * @param e Value to analyze.
   * @return e if e and eof value are not equivalent, or some other non-eof value otherwise.
   */
  constexpr inline static int_type not_eof(int_type e) noexcept {
    return eq_int_type(e, eof()) ? ~eof() : e;
  }
};

/**
 * @brief char_traits specialization for char
 */
template<> class char_traits<::portable_stl::char_t> final {
public:
  using char_type           = ::portable_stl::char_t;
  using int_type            = ::portable_stl::int32_t;
  using off_type            = ::portable_stl::int64_t;
  using pos_type            = ::portable_stl::size_t;
  using state_type          = ::portable_stl::uint32_t;
  using comparison_category = ::portable_stl::strong_ordering;

  constexpr inline static void assign(char_type &lhv, char_type const &rhv) noexcept {
    lhv = rhv;
  }

  constexpr inline static bool eq(char_type lhv, char_type rhv) noexcept {
    return lhv == rhv;
  }

  constexpr inline static bool lt(char_type lhv, char_type rhv) noexcept {
    return static_cast<unsigned char>(lhv) < static_cast<unsigned char>(rhv);
  }

  inline static ::portable_stl::int32_t compare(
    char_type const *s1, char_type const *s2, ::portable_stl::size_t count) noexcept {
    if (0 == count) {
      return 0;
    }
    return ::portable_stl::memcmp(s1, s2, count);
  }

  inline static ::portable_stl::size_t length(char_type const *seq_ptr) noexcept {
    return ::portable_stl::string_helper::builtin_strlen(seq_ptr);
  }

  inline static char_type const *find(
    char_type const *ptr, ::portable_stl::size_t count, char_type const &ch) noexcept {
    if (0 == count) {
      return nullptr;
    }
    return ::portable_stl::string_helper::builtin_char_memchr(ptr, ch, count);
  }

  inline static char_type *move(
    char_type *const dest, char_type const *const src, ::portable_stl::size_t const count) noexcept {
    return static_cast<char_type *>(::portable_stl::memmove(dest, src, count * sizeof(char_type)));
  }

  inline static char_type *copy(
    char_type *const dest, char_type const *const src, ::portable_stl::size_t const count) noexcept {
    // _LIBCPP_ASSERT_NON_OVERLAPPING_RANGES(!::__is_pointer_in_range(dest, dest + count, src),
    //                                       "char_traits::copy: source and destination ranges overlap");
    ::portable_stl::copy_n(src, count, dest);
    return dest;
  }

  inline static char_type *assign(char_type *ptr, ::portable_stl::size_t const count, char_type const &a) noexcept {
    ::portable_stl::fill_n(ptr, count, a);
    return ptr;
  }

  constexpr inline static int_type not_eof(int_type e) noexcept {
    return eq_int_type(e, eof()) ? ~eof() : e;
  }

  constexpr inline static char_type to_char_type(int_type c) noexcept {
    return char_type(c);
  }

  constexpr inline static int_type to_int_type(char_type c) noexcept {
    return int_type(static_cast<unsigned char>(c));
  }

  constexpr inline static bool eq_int_type(int_type lhv, int_type rhv) noexcept {
    return lhv == rhv;
  }

  constexpr inline static int_type eof() noexcept {
    return -1;
  }
};

/**
 * @brief char_traits specialization for wchar_t
 */
template<> class char_traits<wchar_t> final {
public:
  using char_type           = wchar_t;
  using int_type            = ::portable_stl::int32_t; // wint_t
  using off_type            = ::portable_stl::int64_t;
  using pos_type            = ::portable_stl::size_t;
  using state_type          = ::portable_stl::uint32_t;
  using comparison_category = ::portable_stl::strong_ordering;

  constexpr inline static void assign(char_type &lhv, char_type const &rhv) noexcept {
    lhv = rhv;
  }

  constexpr inline static bool eq(char_type lhv, char_type rhv) noexcept {
    return lhv == rhv;
  }

  constexpr inline static bool lt(char_type lhv, char_type rhv) noexcept {
    return lhv < rhv;
  }

  // __constexpr_memcmp requires a trivially lexicographically comparable type, but char is not when char is a signed
  // type (from clang)
  inline static ::portable_stl::int32_t compare(
    char_type const *s1, char_type const *s2, ::portable_stl::size_t count) noexcept {
    if (0 == count) {
      return 0;
    }
    return ::portable_stl::wmemcmp(s1, s2, count);
  }

  inline static ::portable_stl::size_t length(char_type const *seq_ptr) noexcept {
    return ::portable_stl::string_helper::builtin_wcslen(seq_ptr);
  }

  inline static char_type const *find(
    char_type const *ptr, ::portable_stl::size_t count, char_type const &ch) noexcept {
    if (0 == count) {
      return nullptr;
    }
    return ::portable_stl::string_helper::builtin_wmemchr(ptr, ch, count);
  }

  inline static char_type *move(
    char_type *const dest, char_type const *const src, ::portable_stl::size_t const count) noexcept {
    return static_cast<char_type *>(::portable_stl::memmove(dest, src, count * sizeof(char_type)));
  }

  inline static char_type *copy(
    char_type *const dest, char_type const *const src, ::portable_stl::size_t const count) noexcept {
    // _LIBCPP_ASSERT_NON_OVERLAPPING_RANGES(!::__is_pointer_in_range(dest, dest + count, src),
    //                                       "char_traits::copy: source and destination ranges overlap");
    ::portable_stl::copy_n(src, count, dest);
    return dest;
  }

  inline static char_type *assign(char_type *ptr, ::portable_stl::size_t const count, char_type const &a) noexcept {
    ::portable_stl::fill_n(ptr, count, a);
    return ptr;
  }

  constexpr inline static int_type not_eof(int_type e) noexcept {
    return eq_int_type(e, eof()) ? ~eof() : e;
  }

  constexpr inline static char_type to_char_type(int_type c) noexcept {
    return char_type(c);
  }

  constexpr inline static int_type to_int_type(char_type c) noexcept {
    return int_type(c);
  }

  constexpr inline static bool eq_int_type(int_type lhv, int_type rhv) noexcept {
    return lhv == rhv;
  }

  constexpr inline static int_type eof() noexcept {
    return -1;
  }
};

/**
 * @brief char_traits specialization for pstl_char8_t
 */
template<> class char_traits<::portable_stl::pstl_char8_t> final {
public:
  using char_type           = ::portable_stl::pstl_char8_t;
  using int_type            = ::portable_stl::uint32_t;
  using off_type            = ::portable_stl::int64_t;
  using pos_type            = ::portable_stl::size_t;
  using state_type          = ::portable_stl::uint32_t;
  using comparison_category = ::portable_stl::strong_ordering;

  constexpr inline static void assign(char_type &lhv, char_type const &rhv) noexcept {
    lhv = rhv;
  }

  constexpr inline static bool eq(char_type lhv, char_type rhv) noexcept {
    return lhv == rhv;
  }

  constexpr inline static bool lt(char_type lhv, char_type rhv) noexcept {
    return lhv < rhv;
  }

  inline static ::portable_stl::int32_t compare(
    char_type const *s1, char_type const *s2, ::portable_stl::size_t count) noexcept {
    if (0 == count) {
      return 0;
    }
    return ::portable_stl::memcmp(s1, s2, count);
  }

  inline static ::portable_stl::size_t length(char_type const *seq_ptr) noexcept {
    ::portable_stl::size_t len{0U};
    for (; !eq(*seq_ptr, char_type(0)); ++seq_ptr) {
      ++len;
    }
    return len;
  }

  inline static char_type const *find(
    char_type const *ptr, ::portable_stl::size_t count, char_type const &ch) noexcept {
    for (; count > 0U; --count) {
      if (eq(*ptr, ch)) {
        return ptr;
      }
      ++ptr;
    }
    return nullptr;
  }

  inline static char_type *move(
    char_type *const dest, char_type const *const src, ::portable_stl::size_t const count) noexcept {
    return static_cast<char_type *>(::portable_stl::memmove(dest, src, count * sizeof(char_type)));
  }

  inline static char_type *copy(
    char_type *const dest, char_type const *const src, ::portable_stl::size_t const count) noexcept {
    // _LIBCPP_ASSERT_NON_OVERLAPPING_RANGES(!::__is_pointer_in_range(dest, dest + count, src),
    //                                       "char_traits::copy: source and destination ranges overlap");
    ::portable_stl::copy_n(src, count, dest);
    return dest;
  }

  inline static char_type *assign(char_type *ptr, ::portable_stl::size_t const count, char_type const &a) noexcept {
    ::portable_stl::fill_n(ptr, count, a);
    return ptr;
  }

  constexpr inline static int_type not_eof(int_type e) noexcept {
    return eq_int_type(e, eof()) ? ~eof() : e;
  }

  constexpr inline static char_type to_char_type(int_type c) noexcept {
    return char_type(c);
  }

  constexpr inline static int_type to_int_type(char_type c) noexcept {
    return int_type(c);
  }

  constexpr inline static bool eq_int_type(int_type lhv, int_type rhv) noexcept {
    return lhv == rhv;
  }

  constexpr inline static int_type eof() noexcept {
    return static_cast<int_type>(-1);
  }
};
} // namespace portable_stl

#endif // PSTL_CHAR_TRAITS_H
