// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="input_or_output_iterator.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_INPUT_OR_OUTPUT_ITERATOR_H
#define PSTL_INPUT_OR_OUTPUT_ITERATOR_H

#include "../../metaprogramming/helper/integral_constant.h"
#include "../../metaprogramming/logical_operator/conjunction.h"
#include "../../metaprogramming/other_transformations/void_t.h"
#include "../../utility/general/declval.h"
#include "../concepts/weakly_incrementable.h"

namespace std {
namespace iterator_helper {
  /**
   * @brief Check if reference could be taken.
   * Primary template.
   */
  template<class, class = void> class can_reference final {
  public:
    /**
     * @brief Result type.
     */
    using type = ::std::false_type;
  };
  /**
   * @brief Check if reference could be taken.
   * @tparam t_type Tested type.
   */
  template<class t_type> class can_reference<t_type, ::std::void_t<t_type &>> final {
  public:
    /**
     * @brief Result type.
     */
    using type = ::std::true_type;
  };

  /**
   * @brief Specifies that objects of a type can be incremented and dereferenced.
   * Primary template.
   */
  template<class, class = void> class input_or_output_iterator_impl final {
  public:
    /**
     * @brief Result type.
     */
    using type = ::std::false_type;
  };

  /**
   * @brief Specifies that objects of a type can be incremented and dereferenced.
   * Primary template.
   */
  template<class t_type>
  class input_or_output_iterator_impl<t_type, ::std::void_t<decltype(*(::std::declval<t_type>()))>>
    final {
  public:
    /**
     * @brief Result type.
     */
    using type = ::std::conjunction<
      typename std::iterator_helper::can_reference<decltype(*(::std::declval<t_type>()))>::type,
      ::std::weakly_incrementable<t_type>>;
  };
} // namespace iterator_helper

/**
 * @brief The input_or_output_iterator 'concept' forms the basis of the iterator concept taxonomy; every iterator type
 * satisfies the input_or_output_iterator requirements.
 *
 * @tparam t_type Tested type.
 */
template<class t_type>
using input_or_output_iterator = typename ::std::iterator_helper::input_or_output_iterator_impl<t_type>::type;
} // namespace std

#endif /* PSTL_INPUT_OR_OUTPUT_ITERATOR_H */
