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

namespace portable_stl {

template<class t_allocator> class allocator_destructor {
  using t_alloc_traits = ::portable_stl::allocator_traits<t_allocator>;

public:
  using pointer   = typename t_alloc_traits::pointer;
  using size_type = typename t_alloc_traits::size_type;

private:
  t_allocator &m_alloc;
  size_type    m_size;

public:
  allocator_destructor(t_allocator &alloc, size_type sz) noexcept : m_alloc(alloc), m_size(sz) {
  }

  ::portable_stl::expected<void, ::portable_stl::int32_t> operator()(pointer ptr) noexcept {
    t_alloc_traits::deallocate(m_alloc, ptr, m_size);
    return {};
  }
};

} // namespace portable_stl

#endif // PSTL_ALLOCATOR_DESTRUCTOR_H
