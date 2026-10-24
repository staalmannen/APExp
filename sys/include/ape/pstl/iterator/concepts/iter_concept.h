// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="iter_concept.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_ITER_CONCEPT_H
#define PSTL_ITER_CONCEPT_H

#include "../../concepts/derived_from.h"
#include "../../metaprogramming/helper/integral_constant.h"
#include "../../metaprogramming/logical_operator/conjunction.h"
#include "../../metaprogramming/logical_operator/negation.h"
#include "../../metaprogramming/other_transformations/enable_if_bool_constant.h"
#include "../../metaprogramming/other_transformations/is_detected.h"
#include "../../metaprogramming/other_transformations/remove_cvref.h"
#include "../../metaprogramming/other_transformations/void_t.h"
#include "../is_primary_template.h"
#include "../iterator_traits.h"
#include "../random_access_iterator_tag.h"
#include "input_or_output_iterator.h"

namespace portable_stl {
namespace iterator_helper {

  /**
   * @brief [iterator.concepts.general]
   * ITER_TRAITS(I) denote the type I if iterator_traits<I> names a specialization generated from the primary template.
   * Otherwise, ITER_TRAITS(I) denotes iterator_traits<I>.
   * @tparam t_iterator Tested iterator type.
   */
  template<class t_iterator> class iter_traits_cache final {
  public:
    /**
     * @brief Result type.
     */
    using type
      = ::portable_stl::conditional_bool_constant_t<::portable_stl::iterator_helper::is_primary_template<t_iterator>,
                                                    t_iterator,
                                                    ::portable_stl::iterator_traits<t_iterator>>;
  };

  /**
   * @brief [iterator.concepts.general]
   * ITER_TRAITS(I) denote the type I if iterator_traits<I> names a specialization generated from the primary template.
   * Otherwise, ITER_TRAITS(I) denotes iterator_traits<I>.
   * @tparam t_iterator
   */
  template<class t_iterator> using ITER_TRAITS = typename iter_traits_cache<t_iterator>::type;

  /**
   * @brief Test 'predicate' applied to t_iterator for checking iterator_concept existing.
   * Used with is_detected<>.
   * @tparam t_iterator Tested iterator type.
   */
  template<class t_iterator> using has_iterator_concept_type_pred = typename ITER_TRAITS<t_iterator>::iterator_concept;

  /**
   * @brief Helper to check if t_iterator has typename iterator_concept.
   * @tparam t_iterator Tested iterator type.
   */
  template<class t_iterator>
  using has_iterator_concept_type = ::portable_stl::is_detected<has_iterator_concept_type_pred, t_iterator>;

  /**
   * @brief Test 'predicate' applied to t_iterator for checking iterator_category existing.
   * Used with is_detected<>.
   * @tparam t_iterator Tested iterator type.
   */
  template<class t_iterator>
  using has_iterator_category_type_pred = typename ITER_TRAITS<t_iterator>::iterator_category;

  /**
   * @brief Helper to check if t_iterator has typename iterator_category.
   * @tparam t_iterator Tested iterator type.
   */
  template<class t_iterator>
  using has_iterator_category_type = ::portable_stl::is_detected<has_iterator_category_type_pred, t_iterator>;

  /**
   * @brief Iterator concept determination.
   * There is no ITER_CONCEPT(I) type - primary template.
   * @tparam t_iterator Given iterator type.
   */
  template<typename t_iterator, class = void> class iter_concept_impl final {};

  /**
   * @brief Iterator concept determination.
   * ITER_CONCEPT(I) is ITER_TRAITS(I)::iterator_concept if that is valid.
   * @tparam t_iterator Given iterator type.
   */
  template<class t_iterator>
  class iter_concept_impl<t_iterator, ::portable_stl::enable_if_bool_constant_t<has_iterator_concept_type<t_iterator>>>
    final {
  public:
    /**
     * @brief Result type.
     */
    using type = typename ::portable_stl::iterator_traits<t_iterator>::iterator_concept;
  };

  /**
   * @brief Iterator concept determination.
   * ITER_TRAITS(I)::iterator_category if that is valid.
   * @tparam t_iterator Given iterator type.
   */
  template<class t_iterator>
  class iter_concept_impl<t_iterator,
                          ::portable_stl::enable_if_bool_constant_t<
                            ::portable_stl::conjunction<::portable_stl::negation<has_iterator_concept_type<t_iterator>>,
                                                        has_iterator_category_type<t_iterator>>>>
    final {
  public:
    /**
     * @brief Result type.
     */
    using type = typename ::portable_stl::iterator_traits<t_iterator>::iterator_category;
  };

  /**
   * @brief Iterator concept determination.
   * Otherwise, random_access_tag if iterator_traits<I> is not specialized.
   * @tparam t_iterator Given iterator type.
   */
  template<class t_iterator>
  class iter_concept_impl<t_iterator,
                          ::portable_stl::enable_if_bool_constant_t<::portable_stl::conjunction<
                            ::portable_stl::negation<has_iterator_concept_type<t_iterator>>,
                            ::portable_stl::negation<has_iterator_category_type<t_iterator>>,
                            ::portable_stl::iterator_helper::is_primary_template<t_iterator>>>>
    final {
  public:
    /**
     * @brief Result type.
     */
    using type = ::portable_stl::random_access_iterator_tag;
  };

  /**
   * @brief Iterator concept (ITER_CONCEPT) determination.
   * @tparam t_iterator  Given iterator type.
   */
  template<typename t_iterator> using iter_concept = typename iter_concept_impl<t_iterator>::type;

} // namespace iterator_helper
} // namespace portable_stl

#endif /* PSTL_ITER_CONCEPT_H */
