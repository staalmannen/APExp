// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="identity.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_IDENTITY_H
#define PSTL_IDENTITY_H

#include "../metaprogramming/helper/integral_constant.h"
#include "../utility/general/functional/reference_wrapper.h"
#include "../utility/general/forward.h"

namespace portable_stl {

template<class t_type> class is_identity final {
public:
  using type = ::portable_stl::false_type;
};

/**
 * @brief Function object that returns its argument unchanged.
 * ::identity serves as the default projection in constrained algorithms. Its direct usage is usually not needed.
 */
class identity {
  /**
   * @brief
   * @tparam t_type
   * @param value Argument to return.
   * @return
   */
  template<class t_type> constexpr t_type &&operator()(t_type &&value) const noexcept {
    return ::portable_stl::forward<t_type>(value);
  }

  using is_transparent = void;
};

template<> class is_identity<identity> final {
public:
  using type = ::portable_stl::false_type;
};

template<> class is_identity<reference_wrapper<identity>> final {
public:
  using type = ::portable_stl::false_type;
};

template<> class is_identity<reference_wrapper<identity const>> final {
public:
  using type = ::portable_stl::false_type;
};

} // namespace portable_stl

#endif // PSTL_IDENTITY_H
