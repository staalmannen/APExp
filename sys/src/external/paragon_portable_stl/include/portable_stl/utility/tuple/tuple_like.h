// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="tuple_like.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_TUPLE_LIKE_H
#define PSTL_TUPLE_LIKE_H

#include "../../common/size_t.h"
#include "../../metaprogramming/helper/integral_constant.h"
#include "../../metaprogramming/other_transformations/remove_cvref.h"
#include "fwd_decl_array.h"
#include "fwd_decl_tuple.h"

namespace portable_stl {
namespace tuple_helper {

  /**
   * @brief tuple_like default implementation.
   * Primary template.
   */
  template<class> class tuple_like_impl final {
  public:
    /**
     * @brief Result type.
     */
    using type = ::portable_stl::false_type;
  };

  /**
   * @brief tuple_like implementation for tuples.
   * @tparam t_types Tuple types.
   */
  template<class... t_types> class tuple_like_impl<::portable_stl::tuple<t_types...>> final {
  public:
    /**
     * @brief Result type.
     */
    using type = ::portable_stl::true_type;
  };

  /**
   * @brief tuple_like implementation for arrays.
   * 
   * @tparam t_type Type of array elements.
   * @tparam t_size Size of array.
   */
  template<class t_type, ::portable_stl::size_t t_size>
  class tuple_like_impl<::portable_stl::array<t_type, t_size>> final {
  public:
    /**
     * @brief Result type.
     */
    using type = ::portable_stl::true_type;
  };

  /**
   * @brief A type t_types models and satisfies the exposition-only 'concept' tuple-like if remove_cvref_t<T> is a
   * specialization of array, pair, tuple, or ranges::subrange.
   * 
   * tuple-like types implement the tuple protocol, i.e., such types can be used with ::get, ::tuple_element and
   * ::tuple_size. Elements of tuple-like types can be bound with structured binding.
   * @tparam t_type Given type.
   */
  template<class t_type> using tuple_like = typename tuple_like_impl<::portable_stl::remove_cvref_t<t_type>>::type;

} // namespace tuple_helper
} // namespace portable_stl

#endif /* PSTL_TUPLE_LIKE_H */
