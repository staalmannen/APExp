// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="emplaceable.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_EMPLACEABLE_H
#define PSTL_EMPLACEABLE_H

#include <cstdint>
#include <cmath>

namespace test_common_helper {
class Emplaceable {
  std::int32_t m_int;
  double       m_double;

public:
  Emplaceable() noexcept : m_int(0), m_double(0.0) {
  }

  Emplaceable(std::int32_t i, double d) noexcept : m_int(i), m_double(d) {
  }

  Emplaceable(Emplaceable const &)              = delete;
  Emplaceable &operator=(Emplaceable const &) & = delete;

  Emplaceable(Emplaceable &&other) noexcept : m_int(other.m_int), m_double(other.m_double) {
    other.m_int    = 0;
    other.m_double = 0.0;
  }

  Emplaceable &operator=(Emplaceable &&other) & noexcept {
    m_int          = other.m_int;
    other.m_int    = 0;
    m_double       = other.m_double;
    other.m_double = 0.0;
    return *this;
  }

  bool operator==(Emplaceable const &x) const noexcept {
    return (m_int == x.m_int) && (std::fabs(m_double - x.m_double) < std::numeric_limits<double>::epsilon());
  }

  bool operator<(Emplaceable const &x) const noexcept {
    return (m_int < x.m_int) || ((m_int == x.m_int) && (m_double < x.m_double));
  }

  std::int32_t get() const noexcept {
    return m_int;
  }
};
} // namespace test_common_helper

#endif // PSTL_EMPLACEABLE_H
