// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="input_iterator.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_INPUT_ITERATOR_H
#define PSTL_INPUT_ITERATOR_H

#include "../../concepts/derived_from.h"
#include "../../metaprogramming/helper/integral_constant.h"
#include "../../metaprogramming/logical_operator/conjunction.h"
#include "../../metaprogramming/other_transformations/void_t.h"
#include "../input_iterator_tag.h"
#include "indirectly_readable.h"
#include "input_or_output_iterator.h"
#include "iter_concept.h"

namespace portable_stl {
namespace iterator_helper {
  /**
   * @brief input_iterator implementation.
   * Primary template.
   */
  template<class, class = void> class input_iterator_impl final {
  public:
    /**
     * @brief Result type.
     */
    using type = ::portable_stl::false_type;
  };

  /**
   * @brief input_iterator implementation.
   * @tparam iterator_t Given type.
   */
  template<class iterator_t>
  class input_iterator_impl<iterator_t,
                            ::portable_stl::void_t<::portable_stl::iterator_helper::iter_concept<iterator_t>>>
    final {
  public:
    /**
     * @brief Result type.
     */
    using type = ::portable_stl::conjunction<
      ::portable_stl::input_or_output_iterator<iterator_t>,
      ::portable_stl::indirectly_readable<iterator_t>,
      derived_from<::portable_stl::iterator_helper::iter_concept<iterator_t>, ::portable_stl::input_iterator_tag>>;
  };
} // namespace iterator_helper

/**
 * @brief The input_iterator 'concept' is a refinement of input_or_output_iterator, adding the requirement that the
 * referenced values can be read (via indirectly_readable) and the requirement that the iterator concept tag be present.
 *
 * @tparam iterator_t Given type.
 */
template<class iterator_t> using input_iterator = typename iterator_helper::input_iterator_impl<iterator_t>::type;
} // namespace portable_stl

#endif /* PSTL_INPUT_ITERATOR_H */
