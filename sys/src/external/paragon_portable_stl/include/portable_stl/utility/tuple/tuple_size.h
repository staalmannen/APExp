// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="tuple_size.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_TUPLE_SIZE_H
#define PSTL_TUPLE_SIZE_H

#include "../../common/size_t.h"
#include "../../metaprogramming/cv_modifications/remove_cv.h"
#include "../../metaprogramming/helper/integral_constant.h"
#include "../../metaprogramming/logical_operator/negation.h"
#include "../../metaprogramming/other_transformations/enable_if_bool_constant.h"
#include "../../metaprogramming/other_transformations/void_t.h"
#include "../../metaprogramming/type_properties/is_const.h"
#include "../../metaprogramming/type_properties/is_volatile.h"
#include "fwd_decl_array.h"
#include "fwd_decl_tuple.h"

namespace portable_stl {

namespace tuple_helper {
  /**
   * @brief tuple_size wrapper class.
   * Forward declaration.
   * @tparam t_tuple Given tuple type.
   */
  template<class t_tuple> class tuple_size_wrapper;

  // // selected when tuple_size<_Tuple>::value isn't well-formed
  // template<class t_tuple, class = void> class tuple_size_sfinae final {};

  // // selected when tuple_size<_Tuple>::value is well-formed
  // template<class t_tuple>
  // class tuple_size_sfinae<t_tuple, ::portable_stl::void_t<typename tuple_size_wrapper<t_tuple>::value>> final {
  // public:
  //   /**
  //    * @brief Result type-value.
  //    */
  //   using value = typename tuple_size_wrapper<t_tuple>::value;
  // };

  /**
   * @brief Specialization for const tuples.
   * @tparam t_tuple Given tuple type.
   */
  template<class t_tuple> class tuple_size_wrapper<t_tuple const> final {
  public:
    /**
     * @brief Result type-value.
     */
    using value = typename tuple_size_wrapper<t_tuple>::value;
  };

  /**
   * @brief Specialization for tuples.
   * @tparam ...t_types Tuple types.
   */
  template<class... t_types> class tuple_size_wrapper<tuple<t_types...>> final {
  public:
    /**
     * @brief Result type-value.
     */
    using value = ::portable_stl::integral_constant<::portable_stl::size_t, sizeof...(t_types)>;
  };

  /**
   * @brief Specialization for arrays.
   * @tparam t_type Type of array elements.
   * @tparam t_size Size of array.
   */
  template<class t_type, ::portable_stl::size_t t_size>
  class tuple_size_wrapper<::portable_stl::array<t_type, t_size>> final {
  public:
    /**
     * @brief Result type-value.
     */
    using value = ::portable_stl::integral_constant<::portable_stl::size_t, t_size>;
  };
} // namespace tuple_helper

/**
 * @brief Provides access to the number of elements in a tuple as a compile-time constant expression.
 *
 * @tparam t_types Given types.
 */
template<class... t_types> using tuple_size = typename tuple_helper::tuple_size_wrapper<t_types...>::value;

} // namespace portable_stl

#endif /* PSTL_TUPLE_SIZE_H */
