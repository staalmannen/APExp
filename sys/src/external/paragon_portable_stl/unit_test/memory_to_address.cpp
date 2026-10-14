// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="memory_to_address.cpp"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************

#include <gtest/gtest.h>

#include "portable_stl/memory/pointer_traits.h"
#include "portable_stl/memory/to_address.h"

namespace memory_to_address_tests_helper {

/**
 * @brief Simple empty type.
 */
struct Irrelevant;

/**
 * @brief Test type for to_address.
 */
class FancyPtrClass1 final {
  /**
   * @brief Internal pointer.
   */
  std::int32_t *m_ptr;

public:
  /**
   * @brief element_type alias.
   */
  using element_type = Irrelevant;
  /**
   * @brief Ctor.
   * @param ptr
   */
  constexpr explicit FancyPtrClass1(std::int32_t *ptr) noexcept : m_ptr(ptr) {
  }
  /**
   * @brief
   * @return
   */
  constexpr std::int32_t *operator->() const noexcept {
    return m_ptr;
  }
};

/**
 * @brief Test type for to_address.
 */
class FancyPtrClass2 final {
  /**
   * @brief Internal pointer.
   */
  FancyPtrClass1 m_ptr;

public:
  /**
   * @brief element_type alias.
   */
  using element_type = Irrelevant;
  /**
   * @brief Ctor.
   * @param ptr
   */
  constexpr explicit FancyPtrClass2(std::int32_t *ptr) noexcept : m_ptr(ptr) {
  }
  /**
   * @brief
   * @return
   */
  constexpr FancyPtrClass1 operator->() const noexcept {
    return m_ptr;
  }
};

/**
 * @brief Test type for to_address.
 */
class FancyPtrClass3 final {
public:
  /**
   * @brief Ctor.
   * @param ptr
   */
  constexpr explicit FancyPtrClass3(std::int32_t *ptr) noexcept : m_ptr(ptr) {
  }
  /**
   * @brief Internal pointer.
   */
  std::int32_t *m_ptr;
};

/**
 * @brief Test type for to_address.
 */
class FancyPtrClass4 final {
public:
  /**
   * @brief Ctor.
   * @param ptr
   */
  constexpr explicit FancyPtrClass4(std::int32_t *ptr) noexcept : m_ptr(ptr) {
  }
  /**
   * @brief
   * @return
   */
  std::int32_t *operator->() const; // should never be called
  /**
   * @brief Internal pointer.
   */
  std::int32_t *m_ptr;
};

/**
 * @brief Test type for to_address.
 */
class FancyPtrClass5 final {
public:
  /**
   * @brief element_type alias.
   */
  using element_type = Irrelevant;
  /**
   * @brief
   * @return
   */
  std::int32_t const *const &operator->() const noexcept;
};

/**
 * @brief Test type for to_address.
 */
class FancyPtrClass6 final {};
} // namespace memory_to_address_tests_helper

/**
 * @brief pointer_traits stecialization for FancyPtrClass3
 * @tparam
 */
template<> class portable_stl::pointer_traits<memory_to_address_tests_helper::FancyPtrClass3> final {
public:
  /**
   * @brief
   * @param ptr
   * @return constexpr int*
   */
  constexpr static std::int32_t *to_address(memory_to_address_tests_helper::FancyPtrClass3 const &ptr) noexcept {
    return ptr.m_ptr;
  }
};

/**
 * @brief pointer_traits stecialization for FancyPtrClass4
 * @tparam
 */
template<> class portable_stl::pointer_traits<memory_to_address_tests_helper::FancyPtrClass4> final {
public:
  /**
   * @brief
   * @param ptr
   * @return
   */
  constexpr static std::int32_t *to_address(memory_to_address_tests_helper::FancyPtrClass4 const &ptr) noexcept {
    return ptr.m_ptr;
  }
};

/**
 * @brief pointer_traits stecialization for FancyPtrClass6
 * @tparam
 */
template<> class portable_stl::pointer_traits<memory_to_address_tests_helper::FancyPtrClass6> final {
public:
  /**
   * @brief
   * @return std::int32_t const* const&
   */
  static std::int32_t const *const &to_address(memory_to_address_tests_helper::FancyPtrClass6 const &) noexcept;
};

// from clang
TEST(memory_to_address, to_address) {
  static_cast<void>(test_info_);

  std::int32_t int_val{0};
  {
    EXPECT_TRUE(noexcept(::portable_stl::to_address(&int_val)));
    EXPECT_EQ(&int_val, ::portable_stl::to_address(&int_val));
  }
  {
    memory_to_address_tests_helper::FancyPtrClass1 ptr_obj{&int_val};
    EXPECT_TRUE(noexcept(::portable_stl::to_address(ptr_obj)));
    EXPECT_EQ(&int_val, ::portable_stl::to_address(ptr_obj));
  }
  {
    memory_to_address_tests_helper::FancyPtrClass2 ptr_obj{&int_val};
    EXPECT_TRUE(noexcept(::portable_stl::to_address(ptr_obj)));
    EXPECT_EQ(&int_val, ::portable_stl::to_address(ptr_obj));
  }
  {
    memory_to_address_tests_helper::FancyPtrClass3 ptr_obj{&int_val};
    EXPECT_TRUE(noexcept(::portable_stl::to_address(ptr_obj)));
    EXPECT_EQ(&int_val, ::portable_stl::to_address(ptr_obj));
  }
  {
    memory_to_address_tests_helper::FancyPtrClass4 ptr_obj{&int_val};
    EXPECT_TRUE(noexcept(::portable_stl::to_address(ptr_obj)));
    EXPECT_EQ(&int_val, ::portable_stl::to_address(ptr_obj));
  }

  {
    EXPECT_TRUE(
      (std::is_same<decltype(portable_stl::to_address(std::declval<std::int32_t const *>())), std::int32_t const *>{}));
  }
  {
    EXPECT_TRUE(
      (std::is_same<decltype(portable_stl::to_address(std::declval<memory_to_address_tests_helper::FancyPtrClass5>())),
                    std::int32_t const *>{}));
  }
  {
    EXPECT_TRUE(
      (std::is_same<decltype(portable_stl::to_address(std::declval<memory_to_address_tests_helper::FancyPtrClass6>())),
                    std::int32_t const *>{}));
  }
}
