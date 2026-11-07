// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="indirectly_readable.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_INDIRECTLY_READABLE_H
#define PSTL_INDIRECTLY_READABLE_H

#include "../../concepts/common_reference_with.h"
#include "../../concepts/same_as.h"
#include "../../metaprogramming/helper/integral_constant.h"
#include "../../metaprogramming/logical_operator/conjunction.h"
#include "../../metaprogramming/other_transformations/remove_cvref.h"
#include "../../metaprogramming/other_transformations/void_t.h"
#include "../iter_reference_t.h"
#include "../iter_rvalue_reference_t.h"
#include "../iter_value_t.h"

namespace std {

namespace iterator_helper {
  /**
   * @brief @brief The 'concept' indirectly_readable implementation.
   * Primary template.
   */
  template<class, class = void> class indirectly_readable_impl final {
  public:
    /**
     * @brief Result type.
     */
    using type = ::std::false_type;
  };

  /**
   * @brief @brief The 'concept' indirectly_readable implementation.
   * @tparam t_type Given type.
   */
  template<class t_type>
  class indirectly_readable_impl<t_type,
                                 ::std::void_t<::std::iter_value_t<t_type>,
                                                        ::std::iter_reference_t<t_type>,
                                                        ::std::iter_rvalue_reference_t<t_type>>>
    final {
  public:
    /**
     * @brief Result type.
     */
    using type = ::std::conjunction<
      ::std::same_as<::std::iter_reference_t<t_type const>, ::std::iter_reference_t<t_type>>,
      ::std::same_as<::std::iter_rvalue_reference_t<t_type const>,
                              ::std::iter_rvalue_reference_t<t_type>>,
      ::std::common_reference_with<::std::iter_reference_t<t_type> &&,
                                            ::std::iter_value_t<t_type> &>,
      ::std::common_reference_with<::std::iter_reference_t<t_type> &&,
                                            ::std::iter_rvalue_reference_t<t_type> &&>,
      ::std::common_reference_with<::std::iter_rvalue_reference_t<t_type> &&,
                                            ::std::iter_value_t<t_type> const &>>;
  };
} // namespace iterator_helper

/**
 * @brief The 'concept' indirectly_readable is modeled by types that are readable by applying operator*, such as
 * pointers, smart pointers, and input iterators. Given a value i of type I, I models indirectly_readable only if all
 * concepts it subsumes are modeled and the expression *i is equality-preserving.
 * @tparam t_type Given type.
 */
template<class t_type>
using indirectly_readable =
  typename ::std::iterator_helper::indirectly_readable_impl<::std::remove_cvref_t<t_type>>::type;
} // namespace std

#endif /* PSTL_INDIRECTLY_READABLE_H */
