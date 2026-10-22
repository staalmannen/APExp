// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="vector_test_helper.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_VECTOR_TEST_HELPER_H
#define PSTL_VECTOR_TEST_HELPER_H

#include <cstdint>
#include <utility>
#include "assert.h"

#include "portable_stl/language_support/logic_error.h"
#include "portable_stl/iterator/distance.h"

namespace test_vector_helper {

class NotConstructible {
public:
  NotConstructible(NotConstructible const &)            = delete;
  NotConstructible &operator=(NotConstructible const &) = delete;
};

inline bool operator==(NotConstructible const &, NotConstructible const &) {
  return true;
}

class TrivialMoveOnly final {
  std::int32_t m_data;

public:
  TrivialMoveOnly(int data = 1) : m_data(data) {
  }

  TrivialMoveOnly(TrivialMoveOnly const &)            = delete;
  TrivialMoveOnly &operator=(TrivialMoveOnly const &) = delete;

  TrivialMoveOnly(TrivialMoveOnly &&)            = default;
  TrivialMoveOnly &operator=(TrivialMoveOnly &&) = default;

  constexpr int get() const {
    return m_data;
  }

  friend constexpr bool operator==(TrivialMoveOnly const &x, TrivialMoveOnly const &y) {
    return x.m_data == y.m_data;
  }
  friend constexpr bool operator!=(TrivialMoveOnly const &x, TrivialMoveOnly const &y) {
    return x.m_data != y.m_data;
  }
  friend constexpr bool operator<(TrivialMoveOnly const &x, TrivialMoveOnly const &y) {
    return x.m_data < y.m_data;
  }
  friend constexpr bool operator<=(TrivialMoveOnly const &x, TrivialMoveOnly const &y) {
    return x.m_data <= y.m_data;
  }
  friend constexpr bool operator>(TrivialMoveOnly const &x, TrivialMoveOnly const &y) {
    return x.m_data > y.m_data;
  }
  friend constexpr bool operator>=(TrivialMoveOnly const &x, TrivialMoveOnly const &y) {
    return x.m_data >= y.m_data;
  }

  TrivialMoveOnly operator+(TrivialMoveOnly const &x) const {
    return TrivialMoveOnly(m_data + x.m_data);
  }
  TrivialMoveOnly operator*(TrivialMoveOnly const &x) const {
    return TrivialMoveOnly(m_data * x.m_data);
  }

  template<class T> friend void operator,(TrivialMoveOnly const &, T) = delete;

  template<class T> friend void operator,(T, TrivialMoveOnly const &) = delete;
};

class ThrowSometime final {
  std::int32_t m_data;

  void checkThrow() {
    if ((m_construct_count + 1) >= m_throw_on_construct) {
      throw ::portable_stl::logic_error<>{};
    }
    ++m_construct_count;
  }

public:
  static std::int32_t m_throw_on_construct;
  static std::int32_t m_construct_count;
  static std::int32_t m_destruct_count;
  static void         setThrowOnConstruction(std::int32_t value) noexcept {
    m_construct_count    = 0;
    m_destruct_count     = 0;
    m_throw_on_construct = value;
  }

  explicit ThrowSometime(std::int32_t value = 3) : m_data(value) {
    checkThrow();
  }
  ThrowSometime(ThrowSometime const &other) : m_data(other.getData()) {
    checkThrow();
  }
  ThrowSometime &operator=(ThrowSometime const &other) {
    m_data = other.getData();
    return *this;
  }
  ThrowSometime(ThrowSometime &&other) : m_data(std::move(other.m_data)) {
    checkThrow();
  }
  ~ThrowSometime() noexcept {
    ++m_destruct_count;
    m_data = -1;
  }
  std::int32_t getData() const noexcept {
    return m_data;
  }
};

class ThrowCopyMove final {
  std::int32_t m_data;

public:
  ThrowCopyMove() : m_data(0) {
  }
  ThrowCopyMove(std::int32_t data) : m_data(data) {
  }
  ThrowCopyMove(ThrowCopyMove const &other) : m_data(other.m_data) {
    if (m_throw_on_copy) {
      throw ::portable_stl::logic_error<>{};
    }
  }
  ThrowCopyMove(ThrowCopyMove &&other) : m_data(std::move(other.m_data)) {
    if (m_throw_on_move) {
      throw ::portable_stl::logic_error<>{};
    }
  }
  ThrowCopyMove &operator=(ThrowCopyMove const &other) {
    m_data = other.m_data;
    if (m_throw_on_copy) {
      throw ::portable_stl::logic_error<>{};
    }
    return *this;
  }
  ThrowCopyMove &operator=(ThrowCopyMove &&other) {
    m_data = std::move(other.m_data);
    if (m_throw_on_move) {
      throw ::portable_stl::logic_error<>{};
    }
    return *this;
  }

  static bool m_throw_on_copy;
  static bool m_throw_on_move;

  std::int32_t getData() const noexcept {
    return m_data;
  }
};

// [test cases]

template<class t_vector>
void ctor_size(typename t_vector::size_type             num,
               typename t_vector::allocator_type const &alloc = typename t_vector::allocator_type()) {
  {
    t_vector vec(num);
    ASSERT_EQ(num, vec.size());
    ASSERT_EQ(typename t_vector::allocator_type(), vec.get_allocator());
    for (typename t_vector::const_iterator i{vec.cbegin()}, e{vec.cend()}; i != e; ++i) {
      ASSERT_EQ(*i, typename t_vector::value_type());
    }
  }
  {
    t_vector vec(num, alloc);
    ASSERT_EQ(num, vec.size());
    ASSERT_EQ(alloc, vec.get_allocator());
    for (typename t_vector::const_iterator i{vec.cbegin()}, e{vec.cend()}; i != e; ++i) {
      ASSERT_EQ(*i, typename t_vector::value_type());
    }
  }
}

template<class t_vector, class t_iterator> void ctor_iter_iter(t_iterator first, t_iterator last) {
  {
    t_vector vec(first, last);
    ASSERT_EQ(static_cast<std::size_t>(::portable_stl::distance(first, last)), vec.size());
    for (typename t_vector::const_iterator i{vec.cbegin()}, e{vec.cend()}; i != e; ++i, ++first) {
      ASSERT_EQ(*i, *first);
    }
  }
  // Test with an empty range
  {
    t_vector vec(first, first);
    assert(vec.empty());
  }
}

template<class t_vector, class t_iterator, class t_allocator>
void ctor_iter_iter_alloc(t_iterator first, t_iterator last, t_allocator const &alloc) {
  {
    auto alloc_data = alloc.get_data();

    t_vector vec(first, last, alloc);
    ASSERT_EQ(alloc_data, vec.get_allocator().get_data());
    ASSERT_EQ(static_cast<std::size_t>(::portable_stl::distance(first, last)), vec.size());
    for (typename t_vector::const_iterator i{vec.cbegin()}, e{vec.cend()}; i != e; ++i, ++first) {
      ASSERT_EQ(*i, *first);
    }
  }
  // Test with an empty range
  {
    t_vector vec(first, first);
    assert(vec.empty());
  }
}

class LessAndEqComp final {
  std::int32_t m_value;

public:
  LessAndEqComp(std::int32_t value) : m_value(value) {
  }

  std::int32_t getValue() const noexcept {
    return m_value;
  }
};

bool operator<(LessAndEqComp const &lhs, LessAndEqComp const &rhs) noexcept;

bool operator==(LessAndEqComp const &lhs, LessAndEqComp const &rhs) noexcept;

template<class t_vector> void test_constructor_copy(t_vector const &vec0) {
  typename t_vector::size_type old_size{vec0.size()};
  t_vector                     vec(vec0);
  EXPECT_EQ(old_size, vec.size());
  EXPECT_EQ(vec0, vec);
}

template<class t_vector>
void test_constructor_copy_alloc(t_vector const &vec0, typename t_vector::allocator_type const &alloc) {
  typename t_vector::size_type old_size{vec0.size()};
  t_vector                     vec(vec0, alloc);
  EXPECT_EQ(old_size, vec.size());
  EXPECT_EQ(vec0, vec);
}
} // namespace test_vector_helper

#endif // PSTL_VECTOR_TEST_HELPER_H
