// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="tuple_make.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_TUPLE_MAKE_H
#define PSTL_TUPLE_MAKE_H

#include "fwd_decl_tuple.h"
#include "../../utility/general/functional/reference_wrapper.h"
#include "../../utility/general/forward.h"
#include "../../metaprogramming/other_transformations/decay.h"

namespace portable_stl {
namespace tuple_helper {
  /**
   * @brief make_tuple_unref_wrap_t implementation.
   * @tparam t_type Given types.
   */
  template<class t_type> class make_tuple_unref_wrap final { // leave unchanged if not a reference_wrapper
  public:
    /**
     * @brief Result type.
     */
    using type = t_type;
  };

  /**
   * @brief make_tuple_unref_wrap_t implementation.
   * @tparam t_type Given types.
   */
  template<class t_type>
  class make_tuple_unref_wrap<::portable_stl::reference_wrapper<t_type>>
    final { // make a reference from a reference_wrapper
  public:
    /**
     * @brief Result type.
     */
    using type = t_type &;
  };

  /**
   * @brief Decay, then unwrap a reference_wrapper.
   * @tparam t_type Given types.
   */
  template<class t_type>
  using make_tuple_unref_wrap_t = typename make_tuple_unref_wrap<::portable_stl::decay_t<t_type>>::type;
} // namespace tuple_helper

/**
 * @brief Creates a tuple object of the type defined by the argument types.
 * VTypes gets using make_tuple_unref_wrap_t
 * @tparam t_types Given types..
 * @param args Zero or more arguments to construct the tuple from.
 * @return A tuple object containing the given values, created as if by tuple<VTypes...>(forward<t_types>(t)...).
 */
template<class... t_types>
constexpr tuple<tuple_helper::make_tuple_unref_wrap_t<t_types>...> make_tuple(
  t_types &&...args) { // make tuple from elements
  /**
   * @brief Result tuple type.
   */
  using t_tuple = ::portable_stl::tuple<tuple_helper::make_tuple_unref_wrap_t<t_types>...>;
  return t_tuple(::portable_stl::forward<t_types>(args)...);
}
} // namespace portable_stl

#endif /* PSTL_TUPLE_MAKE_H */
