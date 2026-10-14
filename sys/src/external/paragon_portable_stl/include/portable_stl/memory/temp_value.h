// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="temp_value.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_TEMP_VALUE_H
#define PSTL_TEMP_VALUE_H

#include "allocator_traits.h"
#include "addressof.h"
#include "../utility/general/forward.h"

namespace portable_stl {

template<class t_type, class t_allocator> class temp_value final {
  public:
  using t_allocator_traits = ::portable_stl::allocator_traits<t_allocator>;

  union {
    t_type m_value;
  };
  t_allocator &m_alloc;

  t_type *addr() noexcept{
    return ::portable_stl::addressof(m_value);
  }

  t_type &get()  noexcept {
    return *addr();
  }

  template<class... t_args> temp_value(t_allocator &alloc, t_args &&...args) : m_alloc(alloc) {
    t_allocator_traits::construct(m_alloc, addr(), ::portable_stl::forward<t_args>(args)...);
  }

  ~temp_value() {
    t_allocator_traits::destroy(m_alloc, addr());
  }
};
} // namespace portable_stl

#endif // PSTL_TEMP_VALUE_H
