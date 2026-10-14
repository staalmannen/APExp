// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="counter.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_COUNTER_H
#define PSTL_COUNTER_H

#include <cstdint>
#include <utility>

namespace test_common_helper {

class Counter_base {
public:
  static std::int32_t gConstructed;
};

template<typename t_type> class Counter : public Counter_base {
public:
  Counter() : m_data() {
    ++gConstructed;
  }
  Counter(t_type const &data) : m_data(data) {
    ++gConstructed;
  }
  Counter(Counter const &rhs) : m_data(rhs.m_data) {
    ++gConstructed;
  }
  Counter &operator=(Counter const &rhs) {
    m_data = rhs.m_data;
    return *this;
  }
  Counter(Counter &&rhs) : m_data(std::move(rhs.m_data)) {
    ++gConstructed;
  }
  Counter &operator=(Counter &&rhs) {
    m_data = std::move(rhs.m_data);
    return *this;
  }
  ~Counter() {
    --gConstructed;
  }

  t_type const &get() const {
    return m_data;
  }

  bool operator==(Counter const &x) const {
    return m_data == x.m_data;
  }
  bool operator<(Counter const &x) const {
    return m_data < x.m_data;
  }

private:
  t_type m_data;
};

} // namespace test_common_helper

#endif // PSTL_COUNTER_H
