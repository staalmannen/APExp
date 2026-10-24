// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="dereferenceable.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_DEREFERENCEABLE_H
#define PSTL_DEREFERENCEABLE_H

#include "../metaprogramming/helper/integral_constant.h"
#include "../metaprogramming/other_transformations/enable_if_bool_constant.h"
#include "../metaprogramming/other_transformations/remove_cvref.h"
#include "../metaprogramming/other_transformations/type_identity.h"
#include "../metaprogramming/other_transformations/void_t.h"
#include "../metaprogramming/type_properties/is_lvalue_referenceable.h"
#include "../metaprogramming/type_relations/is_any_of.h"
#include "../utility/general/declval.h"

namespace portable_stl {
namespace concepts_helper {
  /**
   * @brief dereferenceable implementation.
   * @tparam t_type Tested type.
   */
  template<class, class = void> class dereferenceable_impl0 final {
  public:
    /**
     * @brief Result type.
     */
    using type = ::portable_stl::false_type;
  };

  /**
   * @brief dereferenceable implementation.
   * @tparam t_type Tested type.
   */
  template<class t_type>
  class dereferenceable_impl0<t_type, ::portable_stl::void_t<decltype(*::portable_stl::declval<t_type &>())>> final {
  public:
    /**
     * @brief Result type.
     */
    using type = ::portable_stl::is_lvalue_referenceable<decltype(*::portable_stl::declval<t_type &>())>;
  };

  /**
   * @brief Helper to handle void * type.
   * @tparam t_type
   */
  template<
    class t_type,
    class = ::portable_stl::
      is_any_of<::portable_stl::remove_cvref_t<t_type>, void *, void const *, void volatile *, void const volatile *>>
  class dereferenceable_impl final {
  public:
    /**
     * @brief Result type.
     */
    using type = typename dereferenceable_impl0<t_type>::type;
  };

  /**
   * @brief Helper to handle void * type.
   * @tparam t_type
   */
  template<class t_type> class dereferenceable_impl<t_type, ::portable_stl::true_type> final {
  public:
    /**
     * @brief Result type.
     */
    using type = ::portable_stl::false_type;
  };

} // namespace concepts_helper

/**
 * @brief The exposition-only 'concept' dereferenceable is satisfied if and only if the expression *declval<T&>()
 * is valid and has a referenceable type (in particular, not void)
 * @tparam t_type Tested type.
 */
template<class t_type>
using dereferenceable = typename ::portable_stl::concepts_helper::dereferenceable_impl<t_type>::type;
} // namespace portable_stl

#endif /* PSTL_DEREFERENCEABLE_H */
