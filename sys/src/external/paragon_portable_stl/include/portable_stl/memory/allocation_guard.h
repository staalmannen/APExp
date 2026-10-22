// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="allocation_guard.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef ALLOCATION_GUARD_H
#define ALLOCATION_GUARD_H

#include "../utility/general/move.h"
#include "allocator_traits.h"
#include "../memory/addressof.h"

namespace portable_stl {

// Helper class to allocate memory using an Allocator in an exception safe
// manner.
//
// The intended usage of this class is as follows:
//
// 0
// 1     allocation_guard<SomeAllocator> guard(alloc, 10);
// 2     do_some_initialization_that_may_throw(guard.get());
// 3     save_allocated_pointer_in_a_noexcept_operation(guard.release_ptr());
// 4
//
// If line (2) throws an exception during initialization of the memory, the
// guard's destructor will be called, and the memory will be released using
// Allocator deallocation. Otherwise, we release the memory from the guard on
// line (3) in an operation that can't throw -- after that, the guard is not
// responsible for the memory anymore.
//
// This is similar to a unique_ptr, except it's easier to use with a
// custom allocator.
template<class t_allocator> struct allocation_guard {
  using t_pointer = typename ::portable_stl::allocator_traits<t_allocator>::pointer;
  using t_size    = typename ::portable_stl::allocator_traits<t_allocator>::size_type;

  template<class t_other_allocator> // we perform the allocator conversion inside the constructor
  explicit allocation_guard(t_other_allocator other_alloc, t_size num)
      : m_alloc(::portable_stl::move(other_alloc))
      , m_num(num)
      , m_ptr(
          ::portable_stl::allocator_traits<t_allocator>::allocate(m_alloc, m_num)) // initialization order is important
  {
  }

  ~allocation_guard() noexcept {
    destroy();
  }

  allocation_guard(allocation_guard const &) = delete;
  allocation_guard(allocation_guard &&other) noexcept
      : m_alloc(::portable_stl::move(other.m_alloc)), m_num(other.m_num), m_ptr(other.m_ptr) {
    other.m_ptr = nullptr;
  }

  allocation_guard &operator=(allocation_guard const &other) = delete;
  allocation_guard &operator=(allocation_guard &&other) noexcept {
    if (::portable_stl::addressof(other) != this) {
      destroy();

      m_alloc     = ::portable_stl::move(other.m_alloc);
      m_num       = other.m_num;
      m_ptr       = other.m_ptr;
      other.m_ptr = nullptr;
    }

    return *this;
  }

  t_pointer release_ptr() noexcept { // not called __release() because it's a keyword in objective-c++
    t_pointer tmp{m_ptr};
    m_ptr = nullptr;
    return tmp;
  }

  t_pointer get() const noexcept {
    return m_ptr;
  }

private:
  void destroy() noexcept {
    if (m_ptr != nullptr) {
      ::portable_stl::allocator_traits<t_allocator>::deallocate(m_alloc, m_ptr, m_num);
    }
  }

  t_allocator m_alloc;
  t_size      m_num;
  t_pointer   m_ptr;
};
} // namespace portable_stl

#endif // ALLOCATION_GUARD_H
