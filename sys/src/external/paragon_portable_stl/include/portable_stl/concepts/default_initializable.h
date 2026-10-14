// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="default_initializable.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_DEFAULT_INITIALIZABLE_H
#define PSTL_DEFAULT_INITIALIZABLE_H

#include "../metaprogramming/helper/integral_constant.h"
#include "../metaprogramming/other_transformations/void_t.h"
#include "../utility/general/declval.h"
#include "constructible_from.h"

namespace portable_stl {
namespace concepts_helper {
  /**
   * @brief Helper class.
   * @tparam t_type Given type.
   */
  template<class t_type, class = ::portable_stl::void_t<decltype(::new t_type)>>
  class default_initializable_impl2 final {};

  /**
   * @brief default_initializable implementation step.
   * Primary template.
   * @tparam t_type Given type.
   */
  template<class t_type, class = void> class default_initializable_impl final {
  public:
    /**
     * @brief Result type.
     */
    using type = ::portable_stl::false_type;
  };

  /**
   * @brief default_initializable implementation step.
   *
   * @tparam t_type Given type.
   */
  template<class t_type>
  class default_initializable_impl<t_type,
                                   ::portable_stl::void_t<decltype(t_type{}), default_initializable_impl2<t_type>>>
    final {
  public:
    /**
     * @brief Result type.
     */
    using type = ::portable_stl::constructible_from<t_type>;
  };
} // namespace concepts_helper

/**
 * @brief The default_initializable 'concept' checks whether variables of type t_type can be:
 * value-initialized (t_type ( ) is well-formed);
 * direct-list-initialized from an empty initializer list (t_type { } is well-formed);
 * default-initialized (t_type t ; is well-formed).
 *
 * @tparam t_type Given type.
 */
template<class t_type>
using default_initializable = typename ::portable_stl::concepts_helper::default_initializable_impl<t_type>::type;

} // namespace portable_stl

#endif /* PSTL_DEFAULT_INITIALIZABLE_H */
