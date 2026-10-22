// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="move_only.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_MOVE_ONLY_H
#define PSTL_MOVE_ONLY_H

namespace test_common_helper {
class MoveOnly final {
  std::int32_t m_data;

public:
  constexpr MoveOnly(std::int32_t data = 1) noexcept : m_data(data) {
  }

  MoveOnly(MoveOnly const &)            = delete;
  MoveOnly &operator=(MoveOnly const &) = delete;

  MoveOnly(MoveOnly &&x) noexcept : m_data(x.m_data) {
    x.m_data = 0;
  }

  MoveOnly &operator=(MoveOnly &&x) noexcept {
    m_data   = x.m_data;
    x.m_data = 0;
    return *this;
  }

  constexpr std::int32_t getData() const noexcept {
    return m_data;
  }

  MoveOnly operator+(MoveOnly const &x) const {
    return MoveOnly(m_data + x.m_data);
  }

  MoveOnly operator*(MoveOnly const &x) const {
    return MoveOnly(m_data * x.m_data);
  }

  template<class T> friend void operator,(MoveOnly const &, T) = delete;

  template<class T> friend void operator,(T, MoveOnly const &) = delete;
};

constexpr static bool operator==(MoveOnly const &x, MoveOnly const &y) noexcept {
  return x.getData() == y.getData();
}

// static bool operator!=(MoveOnly const &x, MoveOnly const &y) noexcept {
//   return x.getData() != y.getData();
// }

constexpr static bool operator<(MoveOnly const &x, MoveOnly const &y) noexcept {
  return x.getData() < y.getData();
}

constexpr static bool operator<=(MoveOnly const &x, MoveOnly const &y) noexcept {
  return x.getData() <= y.getData();
}

constexpr static bool operator>(MoveOnly const &x, MoveOnly const &y) noexcept {
  return x.getData() > y.getData();
}

constexpr static bool operator>=(MoveOnly const &x, MoveOnly const &y) noexcept {
  return x.getData() >= y.getData();
}
} // namespace test_common_helper

#endif // PSTL_MOVE_ONLY_H
