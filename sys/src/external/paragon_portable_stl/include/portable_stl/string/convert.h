// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="convert.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_CONVERT_H
#define PSTL_CONVERT_H

#include "../common/char8_t.h"
#include "../common/char_t.h"
#include "../error/portable_stl_error.h"
#include "../iterator/distance.h"
#include "../utility/expected/expected.h"
#include "unicode_helper.h"

namespace portable_stl {

template<> class unicode_helper<::portable_stl::char_t> {
public:
  template<class t_iterator>
  static ::portable_stl::expected<char32_t, ::portable_stl::portable_stl_error> toUTF32(
    t_iterator &it, t_iterator const &it_end) noexcept {
    if (it == it_end) {
      return ::portable_stl::unexpected<::portable_stl::portable_stl_error>{
        ::portable_stl::portable_stl_error::out_of_range};
    }
    char32_t out_value = static_cast<unsigned char>(*(it++));
    if (out_value > 0x7f) {
      out_value = '?';
    }
    return ::portable_stl::expected<char32_t, ::portable_stl::portable_stl_error>{out_value};
  }

  template<class t_iterator> static bool fromUTF32(t_iterator &it, char32_t const source) noexcept {
    if (source <= 0x7F) {
      *(it++) = static_cast<::portable_stl::char_t>(source);
    } else {
      *(it++) = '?';
      return false;
    }
    return true;
  }

  static ::portable_stl::size_t symbol_size(::portable_stl::char_t const current) noexcept {
    return 1U;
  }

  static ::portable_stl::size_t sequence_size(char32_t const source) noexcept {
    return 1U;
  }
};

template<> class unicode_helper<::portable_stl::pstl_char8_t> {
public:
  template<class t_iterator>
  static ::portable_stl::expected<char32_t, ::portable_stl::portable_stl_error> toUTF32(
    t_iterator &it, t_iterator const &it_end) noexcept {
    if (it == it_end) {
      return ::portable_stl::unexpected<::portable_stl::portable_stl_error>{
        ::portable_stl::portable_stl_error::out_of_range};
    }
    auto                   remaining_length = static_cast<::portable_stl::size_t>(::portable_stl::distance(it, it_end));
    auto                   symbol           = static_cast<::portable_stl::pstl_char8_t>(*(it++));
    ::portable_stl::size_t seq_length{symbol_size(symbol)};
    char32_t               out_value{0};
    if ((0U != seq_length) && (seq_length <= remaining_length)) {
      switch (seq_length) {
        case 6: {
          out_value = (symbol & 0x1U) << 30U;
          out_value += ((*(it++) & 0x3FU) << 24U);
          out_value += ((*(it++) & 0x3FU) << 18U);
          out_value += ((*(it++) & 0x3FU) << 12U);
          out_value += ((*(it++) & 0x3FU) << 6U);
          out_value += (*(it++) & 0x3FU);
          break;
        }
        case 5: {
          out_value = ((symbol & 0x3U) << 24U);
          out_value += ((*(it++) & 0x3FU) << 18U);
          out_value += ((*(it++) & 0x3FU) << 12U);
          out_value += ((*(it++) & 0x3FU) << 6U);
          out_value += (*(it++) & 0x3FU);
          break;
        }
        case 4: {
          out_value = ((symbol & 0x7U) << 18U);
          out_value += ((*(it++) & 0x3FU) << 12U);
          out_value += ((*(it++) & 0x3FU) << 6U);
          out_value += (*(it++) & 0x3FU);
          break;
        }
        case 3: {
          out_value = ((symbol & 0xFU) << 12U);
          out_value += ((*(it++) & 0x3FU) << 6U);
          out_value += (*(it++) & 0x3FU);
          break;
        }
        case 2: {
          out_value = ((symbol & 0x1FU) << 6U);
          out_value += (*(it++) & 0x3FU);
          break;
        }
        default: { // 1
          out_value = (symbol & 0x7FU);
          break;
        }
      }
    } else {
      return ::portable_stl::unexpected<::portable_stl::portable_stl_error>{
        ::portable_stl::portable_stl_error::length_error};
    }
    return ::portable_stl::expected<char32_t, ::portable_stl::portable_stl_error>{out_value};
  }

  template<class t_iterator> static bool fromUTF32(t_iterator &it, char32_t const source) noexcept {
    auto usrc = static_cast<uint32_t const>(source);
    if (usrc <= 0x7F) {
      *(it++) = static_cast<::portable_stl::pstl_char8_t>(usrc);
    } else if (usrc <= 0x7FF) {
      *(it++) = static_cast<::portable_stl::pstl_char8_t>(((usrc >> 6U) & 0x1FU) | 0xC0U);
      *(it++) = static_cast<::portable_stl::pstl_char8_t>((usrc & 0x3FU) | 0x80U);
    } else if (usrc <= 0xFFFF) {
      *(it++) = static_cast<::portable_stl::pstl_char8_t>(((usrc >> 12U) & 0xFU) | 0xE0U);
      *(it++) = static_cast<::portable_stl::pstl_char8_t>(((usrc >> 6U) & 0x3FU) | 0x80U);
      *(it++) = static_cast<::portable_stl::pstl_char8_t>((usrc & 0x3FU) | 0x80U);
    } else if (usrc <= 0x1CFFFF) { // More 0x10FFFF for future support extended Unicode
      *(it++) = static_cast<::portable_stl::pstl_char8_t>(((usrc >> 18U) & 0x7U) | 0xF0U);
      *(it++) = static_cast<::portable_stl::pstl_char8_t>(((usrc >> 12U) & 0x3FU) | 0x80U);
      *(it++) = static_cast<::portable_stl::pstl_char8_t>(((usrc >> 6U) & 0x3FU) | 0x80U);
      *(it++) = static_cast<::portable_stl::pstl_char8_t>((usrc & 0x3FU) | 0x80U);
    } else if (usrc <= 0x3FFFFFF) { // For future support extended Unicode
      *(it++) = static_cast<::portable_stl::pstl_char8_t>(((usrc >> 24U) & 0x3U) | 0xF8U);
      *(it++) = static_cast<::portable_stl::pstl_char8_t>(((usrc >> 18U) & 0x3FU) | 0x80U);
      *(it++) = static_cast<::portable_stl::pstl_char8_t>(((usrc >> 12U) & 0x3FU) | 0x80U);
      *(it++) = static_cast<::portable_stl::pstl_char8_t>(((usrc >> 6U) & 0x3FU) | 0x80U);
      *(it++) = static_cast<::portable_stl::pstl_char8_t>((usrc & 0x3FU) | 0x80U);
    } else if (usrc <= 0x4FFFFFFF) { // For future support extended Unicode
      *(it++) = static_cast<::portable_stl::pstl_char8_t>(((usrc >> 30U) & 0x1U) | 0xFCU);
      *(it++) = static_cast<::portable_stl::pstl_char8_t>(((usrc >> 24U) & 0x3FU) | 0x80U);
      *(it++) = static_cast<::portable_stl::pstl_char8_t>(((usrc >> 18U) & 0x3FU) | 0x80U);
      *(it++) = static_cast<::portable_stl::pstl_char8_t>(((usrc >> 12U) & 0x3FU) | 0x80U);
      *(it++) = static_cast<::portable_stl::pstl_char8_t>(((usrc >> 6U) & 0x3FU) | 0x80U);
      *(it++) = static_cast<::portable_stl::pstl_char8_t>((usrc & 0x3FU) | 0x80U);
    } else {
      *(it++) = '?';
      return false;
    }
    return true;
  }

  static ::portable_stl::size_t symbol_size(pstl_char8_t const current) noexcept {
    auto const symbol = static_cast<unsigned char const>(current);
    if (0 == (symbol & 0x80U)) {
      return 1U;
    } else if (0 != (symbol & 0x40U)) {
      if (0 == (symbol & 0x20U)) {
        return 2U;
      } else if (0 == (symbol & 0x10U)) {
        return 3U;
      } else if (0 == (symbol & 0x08U)) {
        return 4U;
      } else if (0 == (symbol & 0x04U)) {
        return 5U;
      } else if (0 == (symbol & 0x02U)) {
        return 6U;
      }
    }
    return 0U;
  }

  static ::portable_stl::size_t sequence_size(char32_t const source) noexcept {
    auto usrc = static_cast<uint32_t const>(source);
    if (usrc <= 0x7F) {
      return 1U;
    } else if (usrc <= 0x7FF) {
      return 2U;
    } else if (usrc <= 0xFFFF) {
      return 3U;
    } else if (usrc <= 0x1CFFFF) { // More 0x10FFFF for future support extended Unicode
      return 4U;
    } else if (usrc <= 0x3FFFFFF) { // For future support extended Unicode
      return 5U;
    } else if (usrc <= 0x4FFFFFFF) { // For future support extended Unicode
      return 6U;
    } else {
    }
    return 1U;
  }
};

template<> class unicode_helper<char16_t> {
public:
  template<class t_iterator>
  static ::portable_stl::expected<char32_t, ::portable_stl::portable_stl_error> toUTF32(
    t_iterator &it, t_iterator const &it_end) noexcept {
    if (it == it_end) {
      return ::portable_stl::unexpected<::portable_stl::portable_stl_error>{
        ::portable_stl::portable_stl_error::out_of_range};
    }
    auto                   remaining_length = static_cast<::portable_stl::size_t>(::portable_stl::distance(it, it_end));
    char16_t const         symbol           = *(it++);
    ::portable_stl::size_t seq_length{symbol_size(symbol)};
    char32_t               out_value{0};
    if ((0U != seq_length) && (seq_length <= remaining_length)) {
      switch (seq_length) {
        case 1: {
          out_value = static_cast<char32_t>(symbol);
          break;
        }
        default: {
          out_value = (((static_cast<char32_t>(symbol) & 0x3FFU) << 10U) + (static_cast<char32_t>(*(it++)) & 0x3FFU))
                    + 0x10000u;
          break;
        }
      }
    } else {
      return ::portable_stl::unexpected<::portable_stl::portable_stl_error>{
        ::portable_stl::portable_stl_error::length_error};
    }
    return ::portable_stl::expected<char32_t, ::portable_stl::portable_stl_error>{out_value};
  }

  template<class t_iterator> static bool fromUTF32(t_iterator &it, char32_t const source) noexcept {
    uint32_t usrc = static_cast<uint32_t>(source);
    if (usrc < 0x10000) {
      *(it++) = static_cast<char16_t>(usrc);
    } else if (usrc < 0x110000) {
      usrc -= 0x10000;
      *(it++) = ((usrc >> 10U) & 0x3FFU) | 0xD800U;
      *(it++) = (usrc & 0x3FFU) | 0xDC00U;
    } else {
      *(it++) = '?';
      return false;
    }
    return true;
  }

  static ::portable_stl::size_t symbol_size(char16_t const current) noexcept {
    auto const symbol = static_cast<unsigned short const>(current);
    if (symbol < 0xD800 || symbol > 0xDFFF) {
      return 1U;
    } else if (symbol < 0xDC00) {
      return 2U;
    }
    return 0U;
  }

  static ::portable_stl::size_t sequence_size(char32_t const source) noexcept {
    if (source < 0x10000) {
      return 1U;
    } else if (source < 0x110000) {
      return 2U;
    } else {
    }
    return 1U;
  }
};

template<> class unicode_helper<wchar_t> { // ucs2
public:
  template<class t_iterator>
  static ::portable_stl::expected<char32_t, ::portable_stl::portable_stl_error> toUTF32(
    t_iterator &it, t_iterator const &it_end) noexcept {
    if (it == it_end) {
      return ::portable_stl::unexpected<::portable_stl::portable_stl_error>{
        ::portable_stl::portable_stl_error::out_of_range};
    }
    return ::portable_stl::expected<char32_t, ::portable_stl::portable_stl_error>{static_cast<char32_t>(*(it++))};
  }

  template<class t_iterator> static bool fromUTF32(t_iterator &it, char32_t const source) noexcept {
    if (source < 0x10000) {
      *(it++) = static_cast<wchar_t>(source);
      return true;
    }
    *(it++) = '?';
    return false;
  }

  static ::portable_stl::size_t symbol_size(wchar_t const current) noexcept {
    return 1U;
  }

  static ::portable_stl::size_t sequence_size(char32_t const source) noexcept {
    return 1U;
  }
};

template<> class unicode_helper<char32_t> {
public:
  template<class t_iterator>
  static ::portable_stl::expected<char32_t, ::portable_stl::portable_stl_error> toUTF32(
    t_iterator &it, t_iterator const &it_end) noexcept {
    if (it == it_end) {
      return ::portable_stl::unexpected<::portable_stl::portable_stl_error>{
        ::portable_stl::portable_stl_error::out_of_range};
    }
    return ::portable_stl::expected<char32_t, ::portable_stl::portable_stl_error>{*(it++)};
  }

  template<class t_iterator> static bool fromUTF32(t_iterator &it, char32_t const source) noexcept {
    *(it++) = source;
    return true;
  }

  static ::portable_stl::size_t symbol_size(char32_t const current) noexcept {
    return 1U;
  }

  static ::portable_stl::size_t sequence_size(char32_t const source) noexcept {
    return 1U;
  }
};

template<class t_target_string, class t_source_iterator>
inline static bool convert(
  t_target_string &destination, t_source_iterator const &source_begin, t_source_iterator const &source_end) noexcept {
  using t_source_char_type =
    typename ::portable_stl::remove_cv<typename ::portable_stl::iterator_traits<t_source_iterator>::value_type>::type;
  using t_target_char_type = typename ::portable_stl::remove_cv<
    typename ::portable_stl::iterator_traits<decltype(destination.begin())>::value_type>::type;

  ::portable_stl::size_t out_length{0U};
  for (auto it = source_begin; it != source_end;) {
    auto symbol = unicode_helper<t_source_char_type>::toUTF32(it, source_end);
    if (!symbol) {
      return false;
    }
    out_length += unicode_helper<t_target_char_type>::sequence_size(symbol.value());
  }
  if (!destination.resize(out_length)) {
    return false;
  }
  auto target_it = destination.begin();
  for (auto it = source_begin; it != source_end;) {
    (void)unicode_helper<t_target_char_type>::fromUTF32(
      target_it, unicode_helper<t_source_char_type>::toUTF32(it, source_end).value());
  }
  return true;
}

template<class t_target_string, class t_source_string>
inline static bool convert(t_target_string &destination, t_source_string const &source) noexcept {
  return convert(destination, source.begin(), source.end());
}

template<class t_iterator>
inline static ::portable_stl::expected<char32_t, ::portable_stl::portable_stl_error> get_utf32(
  t_iterator &it, t_iterator const &it_end) noexcept {
  using t_char_type =
    typename ::portable_stl::remove_cv<typename ::portable_stl::iterator_traits<t_iterator>::value_type>::type;
  return unicode_helper<t_char_type>::toUTF32(it, it_end);
}

template<typename t_char_type, class t_iterator>
inline static bool put_utf32(t_iterator &it, char32_t const symbol) noexcept {
  return unicode_helper<t_char_type>::fromUTF32(it, symbol);
}

template<class t_target_iterator, class t_source_iterator>
inline static bool convert_sequence(t_target_iterator       &destination_it,
                                    t_source_iterator const &source_begin,
                                    t_source_iterator const &source_end) noexcept {
  using t_source_char_type =
    typename ::portable_stl::remove_cv<typename ::portable_stl::iterator_traits<t_source_iterator>::value_type>::type;
  using t_target_char_type =
    typename ::portable_stl::remove_cv<typename ::portable_stl::iterator_traits<t_target_iterator>::value_type>::type;

  for (auto it = source_begin; it != source_end;) {
    auto symbol = unicode_helper<t_source_char_type>::toUTF32(it, source_end);
    if (symbol) {
      (void)unicode_helper<t_target_char_type>::fromUTF32(destination_it, symbol.value());
    } else {
      return false;
    }
  }
  return true;
}

} // namespace portable_stl
#endif // PSTL_CONVERT_H
