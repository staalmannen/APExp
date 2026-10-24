// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="is_transparent.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_IS_TRANSPARENT_H
#define PSTL_IS_TRANSPARENT_H

#include "../metaprogramming/helper/integral_constant.h"
#include "../metaprogramming/other_transformations/void_t.h"
namespace portable_stl {

namespace functional_helper {
  template<class t_type, class, class = void> class is_transparent final {
  public:
    using type = ::portable_stl::false_type;
  };

  template<class t_type, class t_other_type>
  class is_transparent<t_type, t_other_type, ::portable_stl::void_t<typename t_type::is_transparent>> final {
  public:
    using type = ::portable_stl::true_type;
  };
} // namespace functional_helper

/**
 * @brief Used in map
 *
 * @tparam t_type
 * @tparam t_other_type
 */
template<class t_type, class t_other_type>
using is_transparent = typename functional_helper::is_transparent<t_type, t_other_type>::type;
} // namespace portable_stl

#endif // PSTL_IS_TRANSPARENT_H
