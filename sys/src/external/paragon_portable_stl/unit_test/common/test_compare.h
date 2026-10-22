// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="test_compare.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_TEST_COMPARE_H
#define PSTL_TEST_COMPARE_H

namespace test_common_helper {

template<class t_type> class test_equal_to final {
  std::int32_t m_data;

public:
  explicit test_equal_to() : m_data(0) {
  }

  explicit test_equal_to(std::int32_t data) : m_data(data) {
  }

  bool operator()(t_type const &lhv, t_type const &rhv) const {
    return lhv == rhv;
  }

  bool cmp_impl(test_equal_to const &other) const noexcept {
    return m_data == other.m_data;
  }
};

template<class t_type> bool operator==(test_equal_to<t_type> const &lhv, test_equal_to<t_type> const &rhv) {
  return lhv.cmp_impl(rhv);
}

template<class t_type> class test_less final {
  std::int32_t m_data;

public:
  explicit test_less() : m_data(0) {
  }

  explicit test_less(std::int32_t data) : m_data(data) {
  }

  bool operator()(t_type const &lhv, t_type const &rhv) const {
    return lhv < rhv;
  }

  bool cmp_impl(test_less const &other) const noexcept {
    return m_data == other.m_data;
  }
};

template<class t_type> bool operator==(test_less<t_type> const &lhv, test_less<t_type> const &rhv) {
  return lhv.cmp_impl(rhv);
}
} // namespace test_common_helper
#endif // PSTL_TEST_COMPARE_H
