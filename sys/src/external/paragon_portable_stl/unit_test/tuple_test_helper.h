// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="tuple_test_helper.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_TUPLE_TEST_HELPER_H
#define PSTL_TUPLE_TEST_HELPER_H

#include "gtest/gtest.h"
#include <cstdint>
#include <utility>

#include "portable_stl/utility/tuple/tuple.h"

namespace test_tuple_helper {

constexpr std::int32_t val_2{2};
constexpr std::int32_t val_3{3};
constexpr std::int32_t val_4{4};
constexpr std::int32_t val_5{5};

/**
 * @brief Test class for convertion.
 */
class BaseExpl_tpl_helper {
  /**
   * @brief Data.
   */
  std::int32_t m_value;

public:
  /**
   * @brief Construct a new BaseExpl_tpl_helper object
   * @param value
   */
  explicit BaseExpl_tpl_helper(std::int32_t const value) noexcept : m_value(value) {
  }
  /**
   * @brief Get the Value object
   * @return std::int32_t
   */
  std::int32_t getValue() const noexcept {
    return m_value;
  }
  /**
   * @brief Set the Value object
   * @param value
   */
  void setValue(std::int32_t const value) noexcept {
    m_value = value;
  }
};

/**
 * @brief Test class for convertion.
 */
class DerivedExpl_tpl_helper final : public BaseExpl_tpl_helper {
public:
  /**
   * @brief Ctor.
   */
  using BaseExpl_tpl_helper::BaseExpl_tpl_helper;
};

/**
 * @brief Test class.
 */
class HasImplicitCtor final {
  /**
   * @brief Data.
   */
  std::int32_t m_value;

public:
  /**
   * @brief Construct a new Has Implicit Ctor object
   * @param value
   */
  HasImplicitCtor(std::int32_t const value) noexcept : m_value(value) {
  }
  /**
   * @brief Get the Value object
   * @return std::int32_t
   */
  std::int32_t getValue() const noexcept {
    return m_value;
  }
};

/**
 * @brief Comparison opeartor.
 *
 * @param x
 * @param y
 * @return true
 * @return false
 */
bool operator==(HasImplicitCtor const &x, HasImplicitCtor const &y) noexcept;

/**
 * @brief Test class.
 */
class HasExplicitCtor final {
  /**
   * @brief Data.
   */
  std::int32_t m_value;

public:
  /**
   * @brief Construct a new Has Explicit Ctor object
   * @param value
   */
  explicit HasExplicitCtor(std::int32_t const value) noexcept : m_value(value) {
  }
  /**
   * @brief Get the Value object
   * @return std::int32_t
   */
  std::int32_t getValue() const noexcept {
    return m_value;
  }
};

/**
 * @brief Comparison opeartor.
 *
 * @param x
 * @param y
 * @return true
 * @return false
 */
bool operator==(HasExplicitCtor const &x, HasExplicitCtor const &y) noexcept;

/**
 * @brief Test class.
 */
class MoveOnly final {
  /**
   * @brief Data.
   */
  std::int32_t m_data;

public:
  /**
   * @brief
   * @param value
   */
  constexpr MoveOnly(std::int32_t const value = 1) noexcept : m_data(value) {
  }
  /**
   * @brief Construct a new Move Only object
   */
  MoveOnly(MoveOnly const &)              = delete;
  /**
   * @brief
   * @return MoveOnly&
   */
  MoveOnly &operator=(MoveOnly const &) & = delete;
  /**
   * @brief Construct a new Move Only object
   * @param x
   */
  MoveOnly(MoveOnly &&x) noexcept : m_data(std::move(x.m_data)) {
    x.m_data = 0;
  }
  /**
   * @brief Move.
   * @param x
   * @return MoveOnly&
   */
  MoveOnly &operator=(MoveOnly &&x) & noexcept {
    m_data   = std::move(x.m_data);
    x.m_data = 0;
    return *this;
  }
  /**
   * @brief Destroy the Move Only object
   */
  ~MoveOnly() = default;

  /**
   * @brief Get the m_data
   * @return constexpr std::int32_t
   */
  constexpr std::int32_t getData() const noexcept {
    return m_data;
  }
};

/**
 * @brief Comparison opeartor.
 *
 * @param x
 * @param y
 * @return true
 * @return false
 */
constexpr bool operator==(MoveOnly const &x, MoveOnly const &y) noexcept {
  return x.getData() == y.getData();
}

/**
 * @brief Test class.
 */
class DefaultOnly final {
  /**
   * @brief Data.
   */
  std::int32_t m_data;

public:
  /**
   * @brief Construct a new Default Only object
   */
  DefaultOnly() noexcept : m_data(-1) {
  }
  /**
   * @brief Construct a new Default Only object
   */
  DefaultOnly(DefaultOnly const &)              = delete;
  /**
   * @brief
   * @return DefaultOnly&
   */
  DefaultOnly &operator=(DefaultOnly const &) & = delete;
  /**
   * @brief Move ctor.
   */
  DefaultOnly(DefaultOnly &&)                   = delete;
  /**
   * @brief Move.
   * @return DefaultOnly&
   */
  DefaultOnly &operator=(DefaultOnly &&)      & = delete;

  /**
   * @brief Destroy the Default Only object
   */
  ~DefaultOnly() {
    m_data = 0;
  }
  /**
   * @brief Get the Data object
   * @return std::int32_t
   */
  std::int32_t getData() const noexcept {
    return m_data;
  }
};

/**
 * @brief Comparison opeartor.
 *
 * @param x
 * @param y
 * @return true
 * @return false
 */
bool operator==(DefaultOnly const &x, DefaultOnly const &y) noexcept;
/**
 * @brief Comparison opeartor.
 *
 * @param x
 * @param y
 * @return true
 * @return false
 */
bool operator<(DefaultOnly const &x, DefaultOnly const &y) noexcept;

/**
 * @brief Test class derived from allocator_arg_t.
 */
class DerivedFromAllocatorArgT : public ::portable_stl::allocator_arg_t {};

/**
 * @brief Test allocator.
 * @tparam t_type
 */
template<class t_type> class A1 final {
  /**
   * @brief Data.
   */
  std::int32_t m_id;

public:
  /**
   * @brief Construct a new A1 object
   * @param id
   */
  explicit A1(std::int32_t const id = 0) noexcept : m_id(id) {
  }

  /**
   * @brief Get the Id object
   * @return std::int32_t
   */
  std::int32_t getId() const noexcept {
    return m_id;
  }
};

/**
 * @brief Test allocator.
 * @tparam t_type
 */
template<class t_type> class A2 final {
  /**
   * @brief Data.
   */
  std::int32_t m_id;

public:
  /**
   * @brief Construct a new A2 object
   * @param id
   */
  explicit A2(std::int32_t const id = 0) noexcept : m_id(id) {
  }
};

/**
 * @brief Comparison opeartor.
 * @tparam t_type
 * @tparam t_other_type
 * @param x
 * @param y
 * @return true
 * @return false
 */
template<class t_type, class t_other_type>
inline bool operator==(const A2<t_type> &x, const A2<t_other_type> &y) noexcept;

/**
 * @brief Comparison opeartor.
 * @tparam t_type
 * @tparam t_other_type
 * @param x
 * @param y
 * @return true
 * @return false
 */
template<class t_type, class t_other_type>
inline bool operator!=(const A2<t_type> &x, const A2<t_other_type> &y) noexcept;

/**
 * @brief Test class.
 */
class alloc_first final {
  /**
   * @brief Data.
   */
  std::int32_t m_data;

public:
  /**
   * @brief Statistic member.
   */
  static bool allocator_constructed;

  /**
   * @brief Allocator type.
   */
  using allocator_type = A1<std::int32_t>;

  /**
   * @brief Constructor.
   */
  alloc_first() noexcept : m_data(0) {
  }
  /**
   * @brief Constructor.
   * @param d
   */
  alloc_first(std::int32_t const d) noexcept : m_data(d) {
  }
  /**
   * @brief Constructor.
   * @param a
   */
  alloc_first(::portable_stl::allocator_arg_t, const A1<std::int32_t> &a) : m_data(0) {
    EXPECT_EQ(val_5, a.getId());
    allocator_constructed = true;
  }
  /**
   * @brief Constructor.
   * @param a
   * @param d
   */
  alloc_first(::portable_stl::allocator_arg_t, const A1<std::int32_t> &a, std::int32_t d) : m_data(d) {
    EXPECT_EQ(val_5, a.getId());
    allocator_constructed = true;
  }
  /**
   * @brief Constructor.
   * @param a
   * @param d
   */
  alloc_first(::portable_stl::allocator_arg_t, const A1<std::int32_t> &a, alloc_first const &d) : m_data(d.m_data) {
    EXPECT_EQ(val_5, a.getId());
    allocator_constructed = true;
  }
  /**
   * @brief Constructor copy.
   */
  alloc_first(alloc_first const &) = default;
  // clang-format off
  /**
   * @brief Copy.
   * @return alloc_first& 
   */
  alloc_first &operator=(alloc_first const &) & = default;
  // clang-format on
  /**
   * @brief Constructor move.
   */
  alloc_first(alloc_first &&)      = default;
  // clang-format off
  /**
   * @brief Move.
   * @return alloc_first& 
   */
  alloc_first &operator=(alloc_first &&) & = default;
  // clang-format on
  /**
   * @brief Destructor.
   */
  ~alloc_first() {
    m_data = -1;
  }
  /**
   * @brief Get m_data.
   * @return std::int32_t
   */
  std::int32_t getData() const noexcept {
    return m_data;
  }
};

/**
 * @brief Comparison opeartor.
 * @param x
 * @param y
 * @return true
 * @return false
 */
bool operator==(alloc_first const &x, alloc_first const &y) noexcept;

/**
 * @brief Comparison opeartor.
 * @param x
 * @param y
 * @return true
 * @return false
 */
bool operator<(alloc_first const &x, alloc_first const &y) noexcept;

/**
 * @brief Test class.
 */
class alloc_last final {
  /**
   * @brief Data.
   */
  std::int32_t m_data;

public:
  /**
   * @brief Statistic member.
   */
  static bool allocator_constructed;

  /**
   * @brief Allocator type.
   */
  using allocator_type = A1<std::int32_t>;

  /**
   * @brief Constructor.
   */
  alloc_last() noexcept : m_data(0) {
  }
  /**
   * @brief Constructor.
   * @param d
   */
  alloc_last(std::int32_t const d) noexcept : m_data(d) {
  }
  /**
   * @brief Constructor.
   * @param a
   */
  alloc_last(const A1<std::int32_t> &a) : m_data(0) {
    EXPECT_EQ(val_5, a.getId());
    allocator_constructed = true;
  }

  /**
   * @brief Constructor.
   * @param d
   * @param a
   */
  alloc_last(std::int32_t const d, const A1<std::int32_t> &a) : m_data(d) {
    EXPECT_EQ(val_5, a.getId());
    allocator_constructed = true;
  }

  /**
   * @brief Constructor.
   * @param d
   * @param a
   */
  alloc_last(alloc_last const &d, const A1<std::int32_t> &a) : m_data(d.m_data) {
    EXPECT_EQ(val_5, a.getId());
    allocator_constructed = true;
  }

  /**
   * @brief Constructor copy.
   */
  alloc_last(alloc_last const &) = default;
  // clang-format off
  /**
   * @brief 
   * @return alloc_last& 
   */
  alloc_last &operator=(alloc_last const &) & = default;
  // clang-format on
  /**
   * @brief Constructor move.
   */
  alloc_last(alloc_last &&)      = default;
  // clang-format off
  /**
   * @brief 
   * @return alloc_last& 
   */
  alloc_last &operator=(alloc_last &&) & = default;
  // clang-format on
  /**
   * @brief Destructor.
   */
  ~alloc_last() {
    m_data = -1;
  }
  /**
   * @brief Get m_data.
   * @return std::int32_t
   */
  std::int32_t getData() const noexcept {
    return m_data;
  }
};

/**
 * @brief
 *
 * @param x
 * @param y
 * @return true
 * @return false
 */
bool operator==(alloc_last const &x, alloc_last const &y) noexcept;

/**
 * @brief
 *
 * @param x
 * @param y
 * @return true
 * @return false
 */
bool operator<(alloc_last const &x, alloc_last const &y) noexcept;

} // namespace test_tuple_helper

#endif /* PSTL_TUPLE_TEST_HELPER_H */
