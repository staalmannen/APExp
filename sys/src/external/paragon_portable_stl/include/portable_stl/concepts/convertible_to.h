// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="convertible_to.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_CONVERTIBLE_TO_H
#define PSTL_CONVERTIBLE_TO_H

#include "../metaprogramming/helper/integral_constant.h"
#include "../metaprogramming/logical_operator/conjunction.h"
#include "../metaprogramming/other_transformations/void_t.h"
#include "../metaprogramming/type_relations/is_convertible.h"
#include "../utility/general/declval.h"

namespace portable_stl {

namespace concepts_helper {
  /**
   * @brief Implementation class.
   */
  template<class, class, class = void> class convertible_to_impl final {
  public:
    /**
     * @brief Result.
     */
    using type = ::portable_stl::false_type;
  };

  /**
   * @brief Implementation class.
   *
   * @tparam t_from Tested type.
   * @tparam t_to Tested type.
   */
  template<class t_from, class t_to>
  class convertible_to_impl<t_from,
                            t_to,
                            ::portable_stl::void_t<decltype(static_cast<t_to>(portable_stl::declval<t_from>()))>>
    final {
  public:
    /**
     * @brief Result.
     */
    using type = ::portable_stl::is_convertible<t_from, t_to>;
  };
} // namespace concepts_helper

/**
 * @brief The 'concept' convertible_to<t_from, t_to> specifies that an expression of the same type and value category as
 * those of declval<t_from>() can be implicitly and explicitly converted to the type t_to, and the two forms of
 * conversion produce equal results.
 *
 * @tparam t_from The type to convert from.
 * @tparam t_to The type to convert to.
 */
template<class t_from, class t_to>
using convertible_to = typename ::portable_stl::concepts_helper::convertible_to_impl<t_from, t_to>::type;
} // namespace portable_stl

#endif /* PSTL_CONVERTIBLE_TO_H */
