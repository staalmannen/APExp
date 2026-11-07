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

namespace std {
namespace iterator_helper {

  /**
   * @brief Helper 'predicate' to check to_address invoke.
   * Used with is_detected<>.
   * @tparam t_type Tested type.
   */
  template<class t_type>
  using to_address_call_pred = decltype(::std::to_address(::std::declval<t_type const &>()));

  /**
   * @brief Helper 'predicate' to check iter_reference_t type.
   * Used with is_detected<>.
   * @tparam t_type Tested type.
   */
  template<class t_type> using iter_reference_t_pred = typename ::std::iter_reference_t<t_type>;

  /**
   * @brief contiguous_iterator 'concept' implementation.
   * Primary template.
   * @tparam iterator_t Given iterator type.
   */
  template<class iterator_t,
           class = ::std::conjunction<
             ::std::iterator_helper::has_iterator_concept_type<iterator_t>, // requirement
             ::std::is_detected<to_address_call_pred, iterator_t>,      // requirement
             ::std::is_detected<iter_reference_t_pred, iterator_t>      // requirement
             >>
  class contiguous_iterator_impl final {
  public:
    /**
     * @brief Result.
     */
    using type = ::std::conjunction<
      ::std::random_access_iterator<iterator_t>,
      ::std::derived_from<iterator_helper::iter_concept<iterator_t>, ::std::contiguous_iterator_tag>,
      ::std::is_lvalue_reference<::std::iter_reference_t<iterator_t>>,
      ::std::same_as<::std::iter_value_t<iterator_t>,
                              ::std::remove_cvref_t<::std::iter_reference_t<iterator_t>>>,
      ::std::same_as<decltype(::std::to_address(::std::declval<iterator_t const &>())),
                              ::std::add_pointer_t<::std::iter_reference_t<iterator_t>>>>;
  };

  /**
   * @brief contiguous_iterator 'concept' implementation.
   * @tparam iterator_t Given iterator type.
   */
  template<class iterator_t> class contiguous_iterator_impl<iterator_t, ::std::false_type> final {
  public:
    /**
     * @brief Result.
     */
    using type = ::std::false_type;
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

} // namespace std

#endif /* PSTL_CONTIGUOUS_ITERATOR_H */
