// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="default_only.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_DEFAULT_ONLY_H
#define PSTL_DEFAULT_ONLY_H

#include <cstdint>

namespace test_common_helper {

class DefaultOnly final {
  std::int32_t m_data;

public:
  DefaultOnly() noexcept : m_data(-1) {
    ++count;
  }

  DefaultOnly(DefaultOnly const &)              = delete;
  DefaultOnly &operator=(DefaultOnly const &) & = delete;
  DefaultOnly(DefaultOnly &&)                   = delete;
  DefaultOnly &operator=(DefaultOnly &&)      & = delete;

  ~DefaultOnly() noexcept {
    m_data = 0;
    --count;
  }

  constexpr std::int32_t get_data() const noexcept {
    return m_data;
  }

  static std::int32_t count;
};

constexpr bool operator==(DefaultOnly const &x, DefaultOnly const &y) noexcept {
  return x.get_data() == y.get_data();
}

constexpr bool operator<(DefaultOnly const &x, DefaultOnly const &y) noexcept {
  return x.get_data() < y.get_data();
}

} // namespace test_common_helper

#endif // PSTL_DEFAULT_ONLY_H
