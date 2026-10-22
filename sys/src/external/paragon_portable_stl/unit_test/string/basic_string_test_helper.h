// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="basic_string_test_helper.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_BASIC_STRING_TEST_HELPER_H
#define PSTL_BASIC_STRING_TEST_HELPER_H

#include "portable_stl/common/char_t.h"
#include "portable_stl/common/ptrdiff_t.h"
#include "portable_stl/common/size_t.h"
#include "portable_stl/string/basic_string.h"
#include "portable_stl/string/char_traits.h"

template<class t_type> class TestMemoryManagerAllocator {
public:
  using value_type      = t_type;
  using size_type       = ::portable_stl::size_t;
  using difference_type = ::portable_stl::ptrdiff_t;

  /**
   * @brief Remain number of successful allocation.
   */
  static std::int32_t m_counter_ok_allocation;

  constexpr TestMemoryManagerAllocator() noexcept                                        = default;
  constexpr TestMemoryManagerAllocator(TestMemoryManagerAllocator const &other) noexcept = default;
  template<class t_other>
  constexpr TestMemoryManagerAllocator(TestMemoryManagerAllocator<t_other> const &other) noexcept;

  ~TestMemoryManagerAllocator() noexcept = default;

  value_type *allocate(size_type n) const {
    if (m_counter_ok_allocation <= 0) {
      throw(static_cast<std::int32_t>(-1));
    }
    --m_counter_ok_allocation;
    auto *ptr = static_cast<value_type *>(::malloc(n * sizeof(value_type)));
    ::memset(ptr, '?', n * sizeof(value_type));
    return ptr;
  }

  void deallocate(value_type *p, size_type /*n*/) const {
    ::free(p);
  }
};

template<class t_type> class StateAllocator {
  std::int32_t m_data{0};

public:
  using value_type      = t_type;
  using size_type       = ::portable_stl::size_t;
  using difference_type = ::portable_stl::ptrdiff_t;

  constexpr StateAllocator() noexcept = default;
  constexpr explicit StateAllocator(std::int32_t value) noexcept : m_data(value) {
  }
  ~StateAllocator() noexcept = default;

  constexpr StateAllocator(StateAllocator const &other) noexcept = default;
  constexpr StateAllocator(StateAllocator &&other) noexcept      = default;

  StateAllocator &operator=(StateAllocator const &) & noexcept = default;
  StateAllocator &operator=(StateAllocator &&) & noexcept      = default;

  template<class t_other> constexpr StateAllocator(StateAllocator<t_other> const &other) noexcept;

  value_type *allocate(size_type n) const {
    return static_cast<value_type *>(::malloc(n * sizeof(value_type)));
  }

  void deallocate(value_type *p, size_type /*n*/) const {
    ::free(p);
  }

  std::int32_t getData() const noexcept {
    return m_data;
  }
};

template<class t_type> std::int32_t TestMemoryManagerAllocator<t_type>::m_counter_ok_allocation = 100;

/**
 * @brief Char type alias.
 */
using t_char_type = ::portable_stl::char_t;

/**
 * @brief Test memory manager.
 */
using TMManager = TestMemoryManagerAllocator<t_char_type>;

/**
 * @brief Alias for traits type.
 */
using TTraitsType = ::portable_stl::char_traits<t_char_type>;

/**
 * @brief Test string type with custom allocator.
 */
using TString = ::portable_stl::basic_string<t_char_type, TTraitsType, TMManager>;

/**
 * @brief String view alias for TString;
 */
using TStringView = typename TString::view_type;

namespace test_string_helper {

class SSO final {
public:
  SSO() : m_data(nullptr), m_size(0), m_capacity(0) {
  }
  void          *m_data;
  std::size_t    m_size;
  std::ptrdiff_t m_capacity;
};

constexpr static std::size_t const chars_in_SSO = sizeof(SSO) - 2;

#if defined(_WIN64) || defined(__x86_64__) || defined(__ppc64__) || defined(__aarch64__)
constexpr static t_char_type const test_string_max_SSO[chars_in_SSO + 1]  = "1234567890123456789012";
constexpr static t_char_type const test_string_of_a_SSO[chars_in_SSO + 1] = "aaaaaaaaaaaaaaaaaaaaaa";
#else
constexpr static t_char_type const test_string_max_SSO[chars_in_SSO + 1]  = "1234567890";
constexpr static t_char_type const test_string_of_a_SSO[chars_in_SSO + 1] = "aaaaaaaaaa";
#endif

constexpr static t_char_type const test_string1[] = "abcdef";
constexpr static t_char_type const test_string2[] = "12345678901234567890123456789012345678901234567890";
} // namespace test_string_helper

namespace test_string_helper {
static TString       s1(test_string_helper::test_string1);
static TString       s2(test_string_helper::test_string2);
static TString const cs1(test_string_helper::test_string1);
static TString const cs2(test_string_helper::test_string2);
} // namespace test_string_helper

#endif // PSTL_BASIC_STRING_TEST_HELPER_H
