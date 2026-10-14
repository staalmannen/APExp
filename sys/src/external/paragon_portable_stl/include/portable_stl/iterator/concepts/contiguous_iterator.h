// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="contiguous_iterator.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_CONTIGUOUS_ITERATOR_H
#define PSTL_CONTIGUOUS_ITERATOR_H

#include "../../concepts/derived_from.h"
#include "../../concepts/same_as.h"
#include "../../memory/to_address.h"
#include "../../metaprogramming/logical_operator/conjunction.h"
#include "../../metaprogramming/other_transformations/enable_if_bool_constant.h"
#include "../../metaprogramming/other_transformations/is_detected.h"
#include "../../metaprogramming/other_transformations/remove_cvref.h"
#include "../../metaprogramming/other_transformations/void_t.h"
#include "../../metaprogramming/pointer_modifications/add_pointer.h"
#include "../../metaprogramming/primary_type/is_lvalue_reference.h"
#include "../contiguous_iterator_tag.h"
#include "../iter_reference_t.h"
#include "iter_concept.h"
#include "random_access_iterator.h"

namespace portable_stl {
namespace iterator_helper {

  /**
   * @brief Helper 'predicate' to check to_address invoke.
   * Used with is_detected<>.
   * @tparam t_type Tested type.
   */
  template<class t_type>
  using to_address_call_pred = decltype(::portable_stl::to_address(::portable_stl::declval<t_type const &>()));

  /**
   * @brief Helper 'predicate' to check iter_reference_t type.
   * Used with is_detected<>.
   * @tparam t_type Tested type.
   */
  template<class t_type> using iter_reference_t_pred = typename ::portable_stl::iter_reference_t<t_type>;

  /**
   * @brief contiguous_iterator 'concept' implementation.
   * Primary template.
   * @tparam iterator_t Given iterator type.
   */
  template<class iterator_t,
           class = ::portable_stl::conjunction<
             ::portable_stl::iterator_helper::has_iterator_concept_type<iterator_t>, // requirement
             ::portable_stl::is_detected<to_address_call_pred, iterator_t>,      // requirement
             ::portable_stl::is_detected<iter_reference_t_pred, iterator_t>      // requirement
             >>
  class contiguous_iterator_impl final {
  public:
    /**
     * @brief Result.
     */
    using type = ::portable_stl::conjunction<
      ::portable_stl::random_access_iterator<iterator_t>,
      ::portable_stl::derived_from<iterator_helper::iter_concept<iterator_t>, ::portable_stl::contiguous_iterator_tag>,
      ::portable_stl::is_lvalue_reference<::portable_stl::iter_reference_t<iterator_t>>,
      ::portable_stl::same_as<::portable_stl::iter_value_t<iterator_t>,
                              ::portable_stl::remove_cvref_t<::portable_stl::iter_reference_t<iterator_t>>>,
      ::portable_stl::same_as<decltype(::portable_stl::to_address(::portable_stl::declval<iterator_t const &>())),
                              ::portable_stl::add_pointer_t<::portable_stl::iter_reference_t<iterator_t>>>>;
  };

  /**
   * @brief contiguous_iterator 'concept' implementation.
   * @tparam iterator_t Given iterator type.
   */
  template<class iterator_t> class contiguous_iterator_impl<iterator_t, ::portable_stl::false_type> final {
  public:
    /**
     * @brief Result.
     */
    using type = ::portable_stl::false_type;
  };
} // namespace iterator_helper

/**
 * @brief The contiguous_iterator 'concept' refines random_access_iterator by providing a guarantee the denoted elements
 * are stored contiguously in the memory.
 *
 * @tparam iterator_t Given iterator type.
 */
template<class iterator_t>
using contiguous_iterator = typename iterator_helper::contiguous_iterator_impl<iterator_t>::type;

} // namespace portable_stl

#endif /* PSTL_CONTIGUOUS_ITERATOR_H */
