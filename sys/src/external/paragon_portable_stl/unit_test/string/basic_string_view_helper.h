// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="basic_string_view_helper.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_BASIC_STRING_VIEW_HELPER_H
#define PSTL_BASIC_STRING_VIEW_HELPER_H

#include <memory>

namespace test_basic_string_view_helper {

/**
 * @brief Helper to check equality both side.
 *
 * @tparam S
 * @tparam T
 * @param lhs
 * @param rhs
 * @return true
 * @return false
 */
template<class S, class T> bool check_equal(S lhs, T rhs) {
  return (lhs == rhs) && (rhs == lhs);
}

/**
 * @brief Helper to check not equality both side.
 *
 * @tparam S
 * @tparam T
 * @param lhs
 * @param rhs
 * @return true
 * @return false
 */
template<class S, class T> bool check_not_equal(S lhs, T rhs) {
  return (lhs != rhs) && (rhs != lhs);
}

/**
 * @brief Helper to check operator greater than or equal both side.
 *
 * @tparam S
 * @tparam T
 * @param lhs
 * @param rhs
 * @param x
 * @param y
 */
template<class S, class T> void check_ge(S lhs, T rhs, bool x, bool y) {
  ASSERT_TRUE((lhs >= rhs) == x);
  ASSERT_TRUE((rhs >= lhs) == y);
}

/**
 * @brief Helper to check operator greater than both side.
 *
 * @tparam S
 * @tparam T
 * @param lhs
 * @param rhs
 * @param x
 * @param y
 */
template<class S, class T> void check_gt(S lhs, T rhs, bool x, bool y) {
  ASSERT_TRUE((lhs > rhs) == x);
  ASSERT_TRUE((rhs > lhs) == y);
}

/**
 * @brief Helper to check operator less than or equal both side.
 *
 * @tparam S
 * @tparam T
 * @param lhs
 * @param rhs
 * @param x
 * @param y
 */
template<class S, class T> void check_le(S lhs, T rhs, bool x, bool y) {
  ASSERT_TRUE((lhs <= rhs) == x);
  ASSERT_TRUE((rhs <= lhs) == y);
}

/**
 * @brief Helper to check operator less than both side.
 *
 * @tparam S
 * @tparam T
 * @param lhs
 * @param rhs
 * @param x
 * @param y
 */
template<class S, class T> void check_lt(S lhs, T rhs, bool x, bool y) {
  ASSERT_TRUE((lhs < rhs) == x);
  ASSERT_TRUE((rhs < lhs) == y);
}

/**
 * @brief Helper to check find given char from given pos position.
 *
 * @tparam t_string_view
 * @param sv
 * @param chr
 * @param pos
 * @param expected_pos
 */
template<class t_string_view>
void check_find(t_string_view const                    &sv,
                typename t_string_view::const_reference chr,
                typename t_string_view::size_type       pos,
                typename t_string_view::size_type       expected_pos) {
  ASSERT_EQ(sv.find(chr, pos), expected_pos);
  if (expected_pos != t_string_view::npos) {
    ASSERT_TRUE(pos <= expected_pos && expected_pos + 1 <= sv.size());
  }
}

/**
 * @brief Helper to check find given char from start position
 *
 * @tparam t_string_view
 * @param sv
 * @param chr
 * @param expected_pos
 */
template<class t_string_view>
void check_find(t_string_view const                    &sv,
                typename t_string_view::const_reference chr,
                typename t_string_view::size_type       expected_pos) {
  ASSERT_EQ(sv.find(chr), expected_pos);
  if (expected_pos != t_string_view::npos) {
    ASSERT_TRUE(expected_pos + 1 <= sv.size());
  }
}

/**
 * @brief Helper to check find given string from given pos position.
 *
 * @tparam t_string_view
 * @param sv
 * @param str
 * @param pos
 * @param expected_pos
 */
template<class t_string_view>
void check_find(t_string_view const              &sv,
                t_string_view const              &str,
                typename t_string_view::size_type pos,
                typename t_string_view::size_type expected_pos) {
  ASSERT_EQ(sv.find(str, pos), expected_pos);
  if (expected_pos != t_string_view::npos) {
    ASSERT_TRUE(pos <= expected_pos && expected_pos + str.size() <= sv.size());
  }
}

/**
 * @brief Helper to check find given string from start(0) position.
 *
 * @tparam t_string_view
 * @param sv
 * @param str
 * @param expected_pos
 */
template<class t_string_view>
void check_find(t_string_view const &sv, t_string_view const &str, typename t_string_view::size_type expected_pos) {
  ASSERT_EQ(sv.find(str), expected_pos);
  if (expected_pos != t_string_view::npos) {
    ASSERT_TRUE((0 <= expected_pos) && ((expected_pos + str.size()) <= sv.size()));
  }
}

/**
 * @brief Helper to check find given pointer from given pos position.
 *
 * @tparam t_string_view
 * @param s
 * @param str
 * @param pos
 * @param expected_pos
 */
template<class t_string_view>
void check_find(t_string_view const                  &sv,
                typename t_string_view::const_pointer str,
                typename t_string_view::size_type     pos,
                typename t_string_view::size_type     expected_pos) {
  ASSERT_EQ(sv.find(str, pos), expected_pos);
}

/**
 * @brief Helper to check find given pointer from start(0) position.
 *
 * @tparam t_string_view
 * @param sv
 * @param str
 * @param expected_pos
 */
template<class t_string_view>
void check_find(
  t_string_view const &sv, typename t_string_view::const_pointer str, typename t_string_view::size_type expected_pos) {
  ASSERT_EQ(sv.find(str), expected_pos);
}

/**
 * @brief Helper to check find given substring [str, str+num) from pos position
 *
 * @tparam t_string_view
 * @param sv
 * @param str
 * @param pos
 * @param num
 * @param expected_pos
 */
template<class t_string_view>
void check_find(t_string_view const                  &sv,
                typename t_string_view::const_pointer str,
                typename t_string_view::size_type     pos,
                typename t_string_view::size_type     num,
                typename t_string_view::size_type     expected_pos) {
  ASSERT_EQ(sv.find(str, pos, num), expected_pos);
  if (expected_pos != t_string_view::npos) {
    ASSERT_TRUE(pos <= expected_pos && expected_pos + num <= sv.size());
  }
}

/**
 * @brief Helper to check rfind given char till pos position
 *
 * @tparam t_string_view
 * @param sv
 * @param chr
 * @param pos
 * @param expected_pos
 */
template<class t_string_view>
void check_rfind(t_string_view const                    &sv,
                 typename t_string_view::const_reference chr,
                 typename t_string_view::size_type       pos,
                 typename t_string_view::size_type       expected_pos) {
  ASSERT_EQ(sv.rfind(chr, pos), expected_pos);
  if (expected_pos != t_string_view::npos) {
    ASSERT_TRUE((expected_pos <= pos) && ((expected_pos + 1) <= sv.size()));
  }
}

/**
 * @brief Helper to check rfind given char
 *
 * @tparam t_string_view
 * @param sv
 * @param chr
 * @param expected_pos
 */
template<class t_string_view>
void check_rfind(t_string_view const                    &sv,
                 typename t_string_view::const_reference chr,
                 typename t_string_view::size_type       expected_pos) {
  ASSERT_EQ(sv.rfind(chr), expected_pos);
}

template<class t_string_view>
void check_rfind(t_string_view const              &sv,
                 t_string_view const              &str,
                 typename t_string_view::size_type pos,
                 typename t_string_view::size_type expected_pos) {
  ASSERT_EQ(sv.rfind(str, pos), expected_pos);
  if (expected_pos != t_string_view::npos) {
    ASSERT_TRUE(expected_pos <= pos && expected_pos + str.size() <= sv.size());
  }
}

template<class t_string_view>
void check_rfind(t_string_view const &sv, t_string_view const &str, typename t_string_view::size_type expected_pos) {
  ASSERT_EQ(sv.rfind(str), expected_pos);
  if (expected_pos != t_string_view::npos) {
    ASSERT_TRUE((0 <= expected_pos) && ((expected_pos + str.size()) <= sv.size()));
  }
}

template<class t_string_view>
void check_rfind(t_string_view const                  &sv,
                 typename t_string_view::const_pointer str,
                 typename t_string_view::size_type     pos,
                 typename t_string_view::size_type     num,
                 typename t_string_view::size_type     expected_pos) {
  ASSERT_EQ(sv.rfind(str, pos, num), expected_pos);
  if (expected_pos != t_string_view::npos) {
    ASSERT_TRUE((expected_pos <= pos) && ((expected_pos + num) <= sv.size()));
  }
}

template<class t_string_view>
void check_rfind(t_string_view const                  &sv,
                 typename t_string_view::const_pointer str,
                 typename t_string_view::size_type     pos,
                 typename t_string_view::size_type     expected_pos) {
  ASSERT_EQ(sv.rfind(str, pos), expected_pos);
}

template<class t_string_view>
void check_rfind(
  t_string_view const &sv, typename t_string_view::const_pointer str, typename t_string_view::size_type expected_pos) {
  ASSERT_EQ(sv.rfind(str), expected_pos);
}

template<class t_string_view>
void check_find_first_of(t_string_view const                    &sv,
                         typename t_string_view::const_reference chr,
                         typename t_string_view::size_type       pos,
                         typename t_string_view::size_type       expected_pos) {
  ASSERT_EQ(sv.find_first_of(chr, pos), expected_pos);
  if (expected_pos != t_string_view::npos) {
    ASSERT_TRUE((pos <= expected_pos) && (expected_pos < sv.size()));
  }
}

template<class t_string_view>
void check_find_first_of(t_string_view const                    &sv,
                         typename t_string_view::const_reference chr,
                         typename t_string_view::size_type       expected_pos) {
  ASSERT_EQ(sv.find_first_of(chr), expected_pos);
  if (expected_pos != t_string_view::npos) {
    ASSERT_TRUE(expected_pos < sv.size());
  }
}

template<class t_string_view>
void check_find_first_of(t_string_view const              &sv,
                         t_string_view const              &str,
                         typename t_string_view::size_type pos,
                         typename t_string_view::size_type expected_pos) {
  ASSERT_EQ(sv.find_first_of(str, pos), expected_pos);
  if (expected_pos != t_string_view::npos) {
    ASSERT_TRUE((pos <= expected_pos) && (expected_pos < sv.size()));
  }
}

template<class t_string_view>
void check_find_first_of(
  t_string_view const &sv, t_string_view const &str, typename t_string_view::size_type expected_pos) {
  ASSERT_EQ(sv.find_first_of(str), expected_pos);
  if (expected_pos != t_string_view::npos) {
    ASSERT_TRUE(expected_pos < sv.size());
  }
}

template<class t_string_view>
void check_find_first_of(t_string_view const                  &sv,
                         typename t_string_view::const_pointer str,
                         typename t_string_view::size_type     pos,
                         typename t_string_view::size_type     num,
                         typename t_string_view::size_type     expected_pos) {
  ASSERT_EQ(sv.find_first_of(str, pos, num), expected_pos);
  if (expected_pos != t_string_view::npos) {
    ASSERT_TRUE((pos <= expected_pos) && (expected_pos < sv.size()));
  }
}

template<class t_string_view>
void check_find_first_of(t_string_view const                  &sv,
                         typename t_string_view::const_pointer str,
                         typename t_string_view::size_type     pos,
                         typename t_string_view::size_type     expected_pos) {
  ASSERT_EQ(sv.find_first_of(str, pos), expected_pos);
  if (expected_pos != t_string_view::npos) {
    ASSERT_TRUE((pos <= expected_pos) && (expected_pos < sv.size()));
  }
}

template<class t_string_view>
void check_find_first_of(
  t_string_view const &sv, typename t_string_view::const_pointer str, typename t_string_view::size_type expected_pos) {
  ASSERT_EQ(sv.find_first_of(str), expected_pos);
  if (expected_pos != t_string_view::npos) {
    ASSERT_TRUE(expected_pos < sv.size());
  }
}

template<class t_string_view>
void check_find_last_of(t_string_view const                    &sv,
                        typename t_string_view::const_reference chr,
                        typename t_string_view::size_type       pos,
                        typename t_string_view::size_type       expected_pos) {
  ASSERT_EQ(sv.find_last_of(chr, pos), expected_pos);
  if (expected_pos != t_string_view::npos) {
    ASSERT_TRUE((expected_pos <= pos) && (expected_pos < sv.size()));
  }
}

template<class t_string_view>
void check_find_last_of(t_string_view const                    &sv,
                        typename t_string_view::const_reference chr,
                        typename t_string_view::size_type       expected_pos) {
  ASSERT_EQ(sv.find_last_of(chr), expected_pos);
  if (expected_pos != t_string_view::npos) {
    ASSERT_TRUE(expected_pos < sv.size());
  }
}

template<class t_string_view>
void check_find_last_of(t_string_view const              &sv,
                        t_string_view const              &str,
                        typename t_string_view::size_type pos,
                        typename t_string_view::size_type expected_pos) {
  ASSERT_EQ(sv.find_last_of(str, pos), expected_pos);
  if (expected_pos != t_string_view::npos) {
    ASSERT_TRUE((expected_pos <= pos) && (expected_pos < sv.size()));
  }
}

template<class t_string_view>
void check_find_last_of(
  t_string_view const &sv, t_string_view const &str, typename t_string_view::size_type expected_pos) {
  ASSERT_EQ(sv.find_last_of(str), expected_pos);
  if (expected_pos != t_string_view::npos) {
    ASSERT_TRUE(expected_pos < sv.size());
  }
}

template<class t_string_view>
void check_find_last_of(t_string_view const                  &sv,
                        typename t_string_view::const_pointer str,
                        typename t_string_view::size_type     pos,
                        typename t_string_view::size_type     expected_pos) {
  ASSERT_EQ(sv.find_last_of(str, pos), expected_pos);
  if (expected_pos != t_string_view::npos) {
    ASSERT_TRUE((expected_pos <= pos) && (expected_pos < sv.size()));
  }
}

template<class t_string_view>
void check_find_last_of(
  t_string_view const &sv, typename t_string_view::const_pointer str, typename t_string_view::size_type expected_pos) {
  ASSERT_EQ(sv.find_last_of(str), expected_pos);
  if (expected_pos != t_string_view::npos) {
    ASSERT_TRUE(expected_pos < sv.size());
  }
}

template<class t_string_view>
void check_find_last_of(t_string_view const                  &sv,
                        typename t_string_view::const_pointer str,
                        typename t_string_view::size_type     pos,
                        typename t_string_view::size_type     num,
                        typename t_string_view::size_type     expected_pos) {
  ASSERT_EQ(sv.find_last_of(str, pos, num), expected_pos);
  if (expected_pos != t_string_view::npos) {
    ASSERT_TRUE((expected_pos <= pos) && (expected_pos < sv.size()));
  }
}

template<class t_string_view>
void check_find_first_not_of(t_string_view const                    &sv,
                             typename t_string_view::const_reference chr,
                             typename t_string_view::size_type       pos,
                             typename t_string_view::size_type       expected_pos) {
  ASSERT_EQ(sv.find_first_not_of(chr, pos), expected_pos);
  if (expected_pos != t_string_view::npos) {
    ASSERT_TRUE((pos <= expected_pos) && (expected_pos < sv.size()));
  }
}

template<class t_string_view>
void check_find_first_not_of(t_string_view const                    &sv,
                             typename t_string_view::const_reference chr,
                             typename t_string_view::size_type       expected_pos) {
  ASSERT_EQ(sv.find_first_not_of(chr), expected_pos);
  if (expected_pos != t_string_view::npos) {
    ASSERT_TRUE(expected_pos < sv.size());
  }
}

template<class t_string_view>
void check_find_first_not_of(t_string_view const                  &sv,
                             typename t_string_view::const_pointer str,
                             typename t_string_view::size_type     pos,
                             typename t_string_view::size_type     num,
                             typename t_string_view::size_type     expected_pos) {
  ASSERT_EQ(sv.find_first_not_of(str, pos, num), expected_pos);
  if (expected_pos != t_string_view::npos) {
    ASSERT_TRUE((pos <= expected_pos) && (expected_pos < sv.size()));
  }
}

template<class t_string_view>
void check_find_first_not_of(t_string_view const                  &sv,
                             typename t_string_view::const_pointer str,
                             typename t_string_view::size_type     pos,
                             typename t_string_view::size_type     expected_pos) {
  ASSERT_EQ(sv.find_first_not_of(str, pos), expected_pos);
  if (expected_pos != t_string_view::npos) {
    ASSERT_TRUE((pos <= expected_pos) && (expected_pos < sv.size()));
  }
}

template<class t_string_view>
void check_find_first_not_of(
  t_string_view const &sv, typename t_string_view::const_pointer str, typename t_string_view::size_type expected_pos) {
  ASSERT_EQ(sv.find_first_not_of(str), expected_pos);
  if (expected_pos != t_string_view::npos) {
    ASSERT_TRUE(expected_pos < sv.size());
  }
}

template<class t_string_view>
void check_find_first_not_of(t_string_view const              &sv,
                             t_string_view const              &str,
                             typename t_string_view::size_type pos,
                             typename t_string_view::size_type expected_pos) {
  ASSERT_EQ(sv.find_first_not_of(str, pos), expected_pos);
  if (expected_pos != t_string_view::npos) {
    ASSERT_TRUE((pos <= expected_pos) && (expected_pos < sv.size()));
  }
}

template<class t_string_view>
void check_find_first_not_of(
  t_string_view const &sv, t_string_view const &str, typename t_string_view::size_type expected_pos) {
  ASSERT_EQ(sv.find_first_not_of(str), expected_pos);
  if (expected_pos != t_string_view::npos) {
    ASSERT_TRUE(expected_pos < sv.size());
  }
}

template<class t_string_view>
void check_find_last_not_of(t_string_view const                    &sv,
                            typename t_string_view::const_reference chr,
                            typename t_string_view::size_type       pos,
                            typename t_string_view::size_type       expected_pos) {
  ASSERT_EQ(sv.find_last_not_of(chr, pos), expected_pos);
  if (expected_pos != t_string_view::npos) {
    ASSERT_TRUE((expected_pos <= pos) && (expected_pos < sv.size()));
  }
}

template<class t_string_view>
void check_find_last_not_of(t_string_view const                    &sv,
                            typename t_string_view::const_reference chr,
                            typename t_string_view::size_type       expected_pos) {
  ASSERT_EQ(sv.find_last_not_of(chr), expected_pos);
  if (expected_pos != t_string_view::npos) {
    ASSERT_TRUE(expected_pos < sv.size());
  }
}

template<class t_string_view>
void check_find_last_not_of(t_string_view const                  &sv,
                            typename t_string_view::const_pointer str,
                            typename t_string_view::size_type     pos,
                            typename t_string_view::size_type     num,
                            typename t_string_view::size_type     expected_pos) {
  ASSERT_EQ(sv.find_last_not_of(str, pos, num), expected_pos);
  if (expected_pos != t_string_view::npos) {
    ASSERT_TRUE((expected_pos <= pos) && (expected_pos < sv.size()));
  }
}

template<class t_string_view>
void check_find_last_not_of(t_string_view const                  &sv,
                            typename t_string_view::const_pointer str,
                            typename t_string_view::size_type     pos,
                            typename t_string_view::size_type     expected_pos) {
  ASSERT_EQ(sv.find_last_not_of(str, pos), expected_pos);
  if (expected_pos != t_string_view::npos) {
    ASSERT_TRUE((expected_pos <= pos) && (expected_pos < sv.size()));
  }
}

template<class t_string_view>
void check_find_last_not_of(
  t_string_view const &sv, typename t_string_view::const_pointer str, typename t_string_view::size_type expected_pos) {
  ASSERT_EQ(sv.find_last_not_of(str), expected_pos);
  if (expected_pos != t_string_view::npos) {
    ASSERT_TRUE(expected_pos < sv.size());
  }
}

template<class t_string_view>
void check_find_last_not_of(t_string_view const              &sv,
                            t_string_view const              &str,
                            typename t_string_view::size_type pos,
                            typename t_string_view::size_type expected_pos) {
  ASSERT_EQ(sv.find_last_not_of(str, pos), expected_pos);
  if (expected_pos != t_string_view::npos) {
    ASSERT_TRUE((expected_pos <= pos) && (expected_pos < sv.size()));
  }
}

template<class t_string_view>
void check_find_last_not_of(
  t_string_view const &sv, t_string_view const &str, typename t_string_view::size_type expected_pos) {
  ASSERT_EQ(sv.find_last_not_of(str), expected_pos);
  if (expected_pos != t_string_view::npos) {
    ASSERT_TRUE(expected_pos < sv.size());
  }
}

template<typename t_string_view>
void check_remove_prefix(typename t_string_view::const_pointer str, std::size_t len) {
  {
    t_string_view sv1(str);
    ASSERT_EQ(len, sv1.size());
    if (0 != len) {
      ASSERT_EQ(str, sv1.data());
    }

    if (len > 0) {
      sv1.remove_prefix(1);
      ASSERT_EQ(len - 1, sv1.size());
      if (0 != len - 1) {
        ASSERT_EQ(str + 1, sv1.data());
      }

      sv1.remove_prefix(len - 1);
    }

    ASSERT_TRUE(sv1.size() == 0);
    sv1.remove_prefix(0);
    ASSERT_TRUE(sv1.size() == 0);
  }
}

template<typename t_string_view>
void check_remove_suffix(typename t_string_view::const_pointer str, std::size_t len) {
  {
    t_string_view sv1(str);
    ASSERT_EQ(len, sv1.size());
    if (0 != len) {
      ASSERT_EQ(str, sv1.data());
    }

    if (len > 0) {
      sv1.remove_suffix(1);
      ASSERT_EQ(len - 1, sv1.size());
      if (0 != len - 1) {
        ASSERT_EQ(str, sv1.data());
      }
      sv1.remove_suffix(len - 1);
    }

    ASSERT_EQ(0, sv1.size());
    sv1.remove_suffix(0);
    ASSERT_EQ(0, sv1.size());
  }
}

template<typename t_string_view> void check_swap(typename t_string_view::const_pointer str, size_t len) {
  t_string_view sv1(str);
  t_string_view sv2;

  ASSERT_EQ(len, sv1.size());
  if (0 != len) {
    ASSERT_EQ(str, sv1.data());
  }
  ASSERT_EQ(0, sv2.size());

  sv1.swap(sv2);
  ASSERT_EQ(0, sv1.size());
  ASSERT_EQ(len, sv2.size());
  if (0 != len) {
    ASSERT_EQ(str, sv2.data());
  }
}

} // namespace test_basic_string_view_helper

#endif // PSTL_BASIC_STRING_VIEW_HELPER_H
