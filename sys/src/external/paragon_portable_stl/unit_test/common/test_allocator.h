// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="test_allocator.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_TEST_ALLOCATOR_H
#define PSTL_TEST_ALLOCATOR_H

#include <gtest/gtest.h>

#include "portable_stl/common/numeric_limits.h"
#include "portable_stl/language_support/logic_error.h"
#include "portable_stl/memory/construct_at.h"
#include "portable_stl/memory/to_address.h"
#include "portable_stl/metaprogramming/helper/integral_constant.h"
#include "portable_stl/metaprogramming/logical_operator/negation.h"
#include "portable_stl/metaprogramming/other_transformations/enable_if_bool_constant.h"
#include "portable_stl/metaprogramming/type_relations/is_same.h"

namespace test_allocator_helper {

template<class t_type> class TestSimpleAllocator {
  std::int32_t m_value{0};
  template<class t_other_type> friend class TestSimpleAllocator; // to access m_value
public:
  using value_type      = t_type;
  using size_type       = ::portable_stl::size_t;
  using difference_type = ::portable_stl::ptrdiff_t;

  /**
   * @brief Remain number of successful allocation.
   */
  static std::int32_t m_counter_ok_allocation;
  static std::int32_t m_counter_ok_construction;
  static std::int32_t m_construct_count;
  static std::int32_t m_destroy_count;
  static size_type    m_max_size;
  static void         resetStat() noexcept {
    m_counter_ok_allocation   = 10000;
    m_counter_ok_construction = 10000;
    m_construct_count         = 0;
    m_destroy_count           = 0;
    m_max_size                = 10000;
  }

  constexpr TestSimpleAllocator() noexcept : m_value(0) {
  }

  TestSimpleAllocator(std::int32_t value) noexcept : m_value(value) {
  }

  constexpr TestSimpleAllocator(TestSimpleAllocator const &other) noexcept = default;

  template<class t_other>
  TestSimpleAllocator(TestSimpleAllocator<t_other> const &other_alloc) noexcept : m_value(other_alloc.m_value) {
  }

  ~TestSimpleAllocator() noexcept = default;

  std::int32_t getValue() const noexcept {
    return m_value;
  }

  value_type *allocate(size_type n) const {
    if (m_counter_ok_allocation <= 0) {
      throw static_cast<std::int32_t>(-1);
    }
    --m_counter_ok_allocation;

    void *ptr = ::malloc(n * sizeof(value_type));
    ::memset(ptr, '?', n * sizeof(value_type));

    return static_cast<value_type *>(ptr);
  }

  void deallocate(value_type *p, size_type /*n*/) const {
    ::free(p);
  }

  template<class... t_args,
           class T = t_type,
           class   = ::portable_stl::enable_if_bool_constant_t<
               ::portable_stl::negation<::portable_stl::is_same<std::int32_t, T>>>>
  static void construct(t_type *location, t_args &&...args) {
    if (m_counter_ok_allocation <= 0) {
      throw ::portable_stl::logic_error<>{};
    }
    ::new (::portable_stl::voidify(*location)) t_type(::portable_stl::forward<t_args>(args)...);
    --m_counter_ok_construction;
    ++m_construct_count;
  }

  template<class T = t_type,
           class   = ::portable_stl::enable_if_bool_constant_t<
               ::portable_stl::negation<::portable_stl::is_same<std::int32_t, T>>>>
  static void destroy(t_type *location) {
    ++m_destroy_count;
    location->~t_type();
  }

  static size_type max_size() noexcept {
    return m_max_size;
  }
};

template<class t_type>
bool operator==(TestSimpleAllocator<t_type> const &alloc1, TestSimpleAllocator<t_type> const &alloc2) {
  return alloc1.getValue() == alloc2.getValue();
}

template<class t_type> std::int32_t TestSimpleAllocator<t_type>::m_counter_ok_allocation                       = 10000;
template<class t_type> std::int32_t TestSimpleAllocator<t_type>::m_counter_ok_construction                     = 10000;
template<class t_type> std::int32_t TestSimpleAllocator<t_type>::m_construct_count                             = 0;
template<class t_type> std::int32_t TestSimpleAllocator<t_type>::m_destroy_count                               = 0;
template<class t_type> typename TestSimpleAllocator<t_type>::size_type TestSimpleAllocator<t_type>::m_max_size = 10000U;

struct test_allocator_statistics {
  std::uint32_t m_time_to_throw   = 0U;
  std::uint32_t m_throw_after     = ::portable_stl::numeric_limits_helper::int_max_constant;
  std::uint32_t m_count           = 0U; // the number of active instances
  std::uint32_t m_alloc_count     = 0U; // the number of allocations not deallocating
  std::uint32_t m_allocated_size  = 0U; // the size of allocated elements
  std::uint32_t m_construct_count = 0U; // the number of times that ::construct was called
  std::uint32_t m_destroy_count   = 0U; // the number of times that ::destroy was called
  std::uint32_t m_copied          = 0U;
  std::uint32_t m_moved           = 0U;
  std::uint32_t m_converted       = 0U;

  void clear() {
    assert(m_count == 0U && "clearing leaking allocator data?");
    m_count           = 0U;
    m_time_to_throw   = 0U;
    m_alloc_count     = 0U;
    m_allocated_size  = 0U;
    m_construct_count = 0U;
    m_destroy_count   = 0U;
    m_throw_after     = ::portable_stl::numeric_limits_helper::int_max_constant;
    clear_ctor_counters();
  }

  void clear_ctor_counters() {
    m_copied    = 0U;
    m_moved     = 0U;
    m_converted = 0U;
  }
};

struct test_alloc_base {
  static std::int32_t const destructed_value = -1;
  static std::int32_t const moved_value      = ::portable_stl::numeric_limits_helper::int_max_constant;
};

template<class t_type> class test_allocator {
  std::int32_t               m_data{0}; // participates in equality
  std::int32_t               m_id{0};   // unique identifier, doesn't participate in equality
  test_allocator_statistics *m_stats{nullptr};

  template<class t_other_type> friend class test_allocator;

public:
  using size_type       = ::portable_stl::size_t;
  using difference_type = std::int32_t;
  using value_type      = t_type;
  using pointer         = value_type *;
  using const_pointer   = value_type const *;
  using reference       = typename std::add_lvalue_reference<value_type>::type;
  using const_reference = typename std::add_lvalue_reference<value_type const>::type;

  template<class t_other_type> struct rebind {
    using other = test_allocator<t_other_type>;
  };

  test_allocator() noexcept = default;

  explicit test_allocator(test_allocator_statistics *stats) noexcept : m_stats(stats) {
    if (m_stats != nullptr) {
      ++m_stats->m_count;
    }
  }

  explicit test_allocator(std::int32_t data) noexcept : m_data(data) {
  }

  explicit test_allocator(std::int32_t data, test_allocator_statistics *stats) noexcept : m_data(data), m_stats(stats) {
    if (stats != nullptr) {
      ++m_stats->m_count;
    }
  }

  explicit test_allocator(std::int32_t data, std::int32_t id) noexcept : m_data(data), m_id(id) {
  }

  explicit test_allocator(std::int32_t data, std::int32_t id, test_allocator_statistics *stats) noexcept
      : m_data(data), m_id(id), m_stats(stats) {
    if (m_stats != nullptr) {
      ++m_stats->m_count;
    }
  }

  test_allocator(test_allocator const &a) noexcept : m_data(a.m_data), m_id(a.m_id), m_stats(a.m_stats) {
    assert(a.m_data != test_alloc_base::destructed_value && a.m_id != test_alloc_base::destructed_value
           && "copying from destroyed allocator");
    if (m_stats != nullptr) {
      ++m_stats->m_count;
      ++m_stats->m_copied;
    }
  }

  test_allocator(test_allocator &&a) noexcept : m_data(a.m_data), m_id(a.m_id), m_stats(a.m_stats) {
    if (m_stats != nullptr) {
      ++m_stats->m_count;
      ++m_stats->m_moved;
    }
    assert(a.m_data != test_alloc_base::destructed_value && a.m_id != test_alloc_base::destructed_value
           && "moving from destroyed allocator");
    a.m_data = test_alloc_base::moved_value;
    a.m_id   = test_alloc_base::moved_value;
  }

  template<class t_other_type>
  test_allocator(test_allocator<t_other_type> const &a) noexcept : m_data(a.m_data), m_id(a.m_id), m_stats(a.m_stats) {
    if (m_stats != nullptr) {
      ++m_stats->m_count;
      ++m_stats->m_converted;
    }
  }

  ~test_allocator() noexcept {
    assert(m_data != test_alloc_base::destructed_value);
    assert(m_id != test_alloc_base::destructed_value);
    if (m_stats != nullptr) {
      --m_stats->m_count;
    }
    m_data = test_alloc_base::destructed_value;
    m_id   = test_alloc_base::destructed_value;
  }

  pointer address(reference x) const {
    return &x;
  }
  const_pointer address(const_reference x) const {
    return &x;
  }

  pointer allocate(size_type n, void const * = nullptr) {
    assert(m_data != test_alloc_base::destructed_value);
    if (m_stats != nullptr) {
      if (m_stats->m_time_to_throw >= m_stats->m_throw_after) {
        throw(std::bad_alloc());
      }
      ++m_stats->m_time_to_throw;
      ++m_stats->m_alloc_count;
      m_stats->m_allocated_size += n;
    }
    return std::allocator<value_type>().allocate(n);
  }

  void deallocate(pointer p, size_type s) {
    assert(m_data != test_alloc_base::destructed_value);
    if (m_stats != nullptr) {
      --m_stats->m_alloc_count;
      m_stats->m_allocated_size -= s;
    }
    std::allocator<value_type>().deallocate(p, s);
  }

  size_type max_size() const noexcept {
    return ::portable_stl::numeric_limits_helper::int_max_constant / sizeof(t_type);
  }

  template<class t_other_type> void construct(pointer p, t_other_type &&val) {
    if (m_stats != nullptr) {
      ++m_stats->m_construct_count;
    }
    ::portable_stl::construct_at(::portable_stl::to_address(p), std::forward<t_other_type>(val));
  }

  void destroy(pointer p) {
    if (m_stats != nullptr) {
      ++m_stats->m_destroy_count;
    }
    p->~t_type();
  }

  friend bool operator==(test_allocator const &x, test_allocator const &y) {
    return x.m_data == y.m_data;
  }

  friend bool operator!=(test_allocator const &x, test_allocator const &y) {
    return !(x == y);
  }

  std::int32_t get_data() const {
    return m_data;
  }
  std::int32_t get_id() const {
    return m_id;
  }
};

template<class t_type> class explicit_allocator {
public:
  using value_type = t_type;

  explicit_allocator() noexcept {
  }

  template<class t_other_type> explicit explicit_allocator(explicit_allocator<t_other_type>) noexcept {
  }

  t_type *allocate(std::size_t num) {
    return static_cast<t_type *>(std::allocator<t_type>().allocate(num));
  }

  void deallocate(t_type *ptr, std::size_t num) {
    std::allocator<t_type>().deallocate(ptr, num);
  }

  friend bool operator==(explicit_allocator, explicit_allocator) {
    return true;
  }
  friend bool operator!=(explicit_allocator x, explicit_allocator y) {
    return !(x == y);
  }
};

template<class t_type, bool POCCAValue> class MaybePOCCAAllocator final {
  std::int32_t m_id                 = 0;
  bool        *m_copy_assigned_into = nullptr;

  template<class, bool> friend class MaybePOCCAAllocator;

public:
  using propagate_on_container_copy_assignment = ::portable_stl::bool_constant<POCCAValue>;
  using value_type                             = t_type;

  template<class t_other_type> struct rebind {
    using other = MaybePOCCAAllocator<t_other_type, POCCAValue>;
  };

  MaybePOCCAAllocator() = default;
  MaybePOCCAAllocator(std::int32_t id, bool *copy_assigned_into) : m_id(id), m_copy_assigned_into(copy_assigned_into) {
  }

  template<class t_other_type>
  MaybePOCCAAllocator(MaybePOCCAAllocator<t_other_type, POCCAValue> const &other)
      : m_id(other.m_id), m_copy_assigned_into(other.m_copy_assigned_into) {
  }

  MaybePOCCAAllocator(MaybePOCCAAllocator const &) = default;
  MaybePOCCAAllocator &operator=(MaybePOCCAAllocator const &other) {
    m_id = other.id();
    if (m_copy_assigned_into) {
      *m_copy_assigned_into = true;
    }
    return *this;
  }

  t_type *allocate(std::size_t num) {
    return std::allocator<t_type>().allocate(num);
  }

  void deallocate(t_type *ptr, std::size_t num) {
    std::allocator<t_type>().deallocate(ptr, num);
  }

  constexpr std::int32_t id() const noexcept {
    return m_id;
  }

  template<class t_other_type>
  constexpr friend bool operator==(MaybePOCCAAllocator const                           &lhs,
                                   MaybePOCCAAllocator<t_other_type, POCCAValue> const &rhs) {
    return lhs.id() == rhs.id();
  }

  template<class t_other_type>
  constexpr friend bool operator!=(MaybePOCCAAllocator const                           &lhs,
                                   MaybePOCCAAllocator<t_other_type, POCCAValue> const &rhs) {
    return !(lhs == rhs);
  }
};

template<class T> using POCCAAllocator    = MaybePOCCAAllocator<T, /*POCCAValue = */ true>;
template<class T> using NonPOCCAAllocator = MaybePOCCAAllocator<T, /*POCCAValue = */ false>;

} // namespace test_allocator_helper

#endif // PSTL_TEST_ALLOCATOR_H
