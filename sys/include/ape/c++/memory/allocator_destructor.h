// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="allocator_destructor.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_ALLOCATOR_DESTRUCTOR_H
#define PSTL_ALLOCATOR_DESTRUCTOR_H

#include "allocator_traits.h"

namespace std {

template<class t_allocator> class allocator_destructor {
  using t_alloc_traits = ::std::allocator_traits<t_allocator>;

public:
  using pointer   = typename t_alloc_traits::pointer;
  using size_type = typename t_alloc_traits::size_type;

private:
  t_allocator &m_alloc;
  size_type    m_size;

public:
  allocator_destructor(t_allocator &alloc, size_type sz) noexcept : m_alloc(alloc), m_size(sz) {
  }

  ::std::expected<void, ::std::int32_t> operator()(pointer ptr) noexcept {
    t_alloc_traits::deallocate(m_alloc, ptr, m_size);
    return {};
  }
};

} // namespace std

#endif // PSTL_ALLOCATOR_DESTRUCTOR_H
