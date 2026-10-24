// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="template_range_concept.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_TEMPLATE_RANGE_CONCEPT_H
#define PSTL_TEMPLATE_RANGE_CONCEPT_H

#include "../../iterator/concepts/input_iterator.h"
#include "../../metaprogramming/logical_operator/conjunction.h"
#include "../iterator_t.h"
#include "range.h"

namespace portable_stl {
namespace ranges {
  namespace ranges_helper {
    /**
     * @brief template_range_concept 'concept' implementation.
     * Primary template.
     * @tparam range_type Given range type.
     * @tparam iterator_constraint_concept Iterator concept like input_iterator<>.
     */
    template<class range_type, template<class> class iterator_constraint_concept, class = has_iterator_t<range_type>>
    class template_range_concept_impl final {
    public:
      /**
       * @brief Result type.
       */
      using type
        = ::portable_stl::conjunction<::portable_stl::ranges::range<range_type>,
                                      iterator_constraint_concept<::portable_stl::ranges::iterator_t<range_type>>>;
    };

    /**
     * @brief template_range_concept 'concept' implementation.
     * @tparam range_type Given range type.
     */
    template<class range_type, template<class> class iterator_constraint_concept>
    class template_range_concept_impl<range_type, iterator_constraint_concept, ::portable_stl::false_type> final {
    public:
      /**
       * @brief Result type.
       */
      using type = ::portable_stl::false_type;
    };
  } // namespace ranges_helper

  /**
   * @brief The input_range 'concept' is a refinement of range for which ranges::begin returns a model of
   * iterator_constraint_concept_concept.
   * @tparam range_type Given range type.
   */
  template<class range_type, template<class> class iterator_constraint_concept>
  using template_range_concept =
    typename ranges_helper::template_range_concept_impl<range_type, iterator_constraint_concept>::type;

} // namespace ranges
} // namespace portable_stl

#endif /* PSTL_TEMPLATE_RANGE_CONCEPT_H */
