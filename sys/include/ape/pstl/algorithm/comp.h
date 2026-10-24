// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="comp.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_COMP_H
#define PSTL_COMP_H

#include "../metaprogramming/type_traits/operation_traits.h"

namespace portable_stl {

namespace algorithm_helper {
  /**
   * @brief Internal equal_to
   */
  class equal_to_inter final {
  public:
    template<class t_type1, class t_type2> constexpr bool operator()(t_type1 const &left, t_type2 const &right) const {
      return left == right;
    }
  };

  // The definition is required because less is part of the ABI, but it's empty
  // because all comparisons should be transparent.
  template<class t_type1 = void, class t_type2 = t_type1> class less final {};

  template<> class less<void, void> final {
  public:
    template<class t_typep, class t_other_type>
    constexpr bool operator()(t_typep const &left, t_other_type const &right) const {
      return left < right;
    }
  };
} // namespace algorithm_helper

template<class t_type, class t_other_type>
  class desugars_to<::portable_stl::equal_tag, algorithm_helper::equal_to_inter, t_type, t_other_type> final {
  public:
    using type = ::portable_stl::true_type;
  };
} // namespace portable_stl

#endif // PSTL_COMP_H
