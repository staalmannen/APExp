// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="common_range.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_COMMON_RANGE_H
#define PSTL_COMMON_RANGE_H

#include "../../concepts/same_as.h"
#include "../../iterator/concepts/input_iterator.h"
#include "../../metaprogramming/logical_operator/conjunction.h"
#include "../iterator_t.h"
#include "../sentinel_t.h"
#include "range.h"

namespace portable_stl {
namespace ranges {
  namespace ranges_helper {
    /**
     * @brief common_range 'concept' implementation.
     * Primary template.
     * @tparam range_type Given range type.
     * @tparam common_range_concept Iterator concept like input_iterator<>.
     */
    template<class range_type,
             class = ::portable_stl::conjunction<has_iterator_t<range_type>, has_sentinel_t<range_type>>>
    class common_range_impl final {
    public:
      /**
       * @brief Result type.
       */
      using type = ::portable_stl::conjunction<::portable_stl::ranges::range<range_type>,
                                               ::portable_stl::same_as<::portable_stl::ranges::iterator_t<range_type>,
                                                                       ::portable_stl::ranges::sentinel_t<range_type>>>;
    };

    /**
     * @brief common_range 'concept' implementation.
     * @tparam range_type Given range type.
     */
    template<class range_type> class common_range_impl<range_type, ::portable_stl::false_type> final {
    public:
      /**
       * @brief Result type.
       */
      using type = ::portable_stl::false_type;
    };
  } // namespace ranges_helper

  /**
   * @brief The input_range 'concept' is a refinement of range for which ranges::begin returns a model of
   * common_range_concept_concept.
   * @tparam range_type Given range type.
   */
  template<class range_type> using common_range = typename ranges_helper::common_range_impl<range_type>::type;

} // namespace ranges
} // namespace portable_stl

#endif /* PSTL_COMMON_RANGE_H */
