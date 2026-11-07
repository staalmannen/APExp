// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="common_reference_with.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_COMMON_REFERENCE_WITH_H
#define PSTL_COMMON_REFERENCE_WITH_H

#include "../metaprogramming/logical_operator/conjunction.h"
#include "../metaprogramming/other_transformations/common_reference.h"
#include "../metaprogramming/other_transformations/void_t.h"
#include "convertible_to.h"
#include "same_as.h"

namespace std {

namespace concepts_helper {
  /**
   * @brief Implementation class.
   */
  template<class, class, class = void> class common_reference_with_impl final {
  public:
    /**
     * @brief Result.
     */
    using type = ::std::false_type;
  };

  /**
   * @brief Implementation class.
   *
   * @tparam t_type Tested type.
   * @tparam u_type Tested type.
   */
  template<class t_type, class u_type>
  class common_reference_with_impl<t_type,
                                   u_type,
                                   ::std::void_t<::std::common_reference_t<t_type, u_type>,
                                                          ::std::common_reference_t<u_type, t_type>>>
    final {
    /**
     * @brief Helper type alias.
     */
    using com_ref_t1 = ::std::common_reference_t<t_type, u_type>;
    /**
     * @brief Helper type alias.
     */
    using com_ref_t2 = ::std::common_reference_t<u_type, t_type>;

  public:
    /**
     * @brief Result.
     */
    using type = ::std::conjunction<::std::same_as<com_ref_t1, com_ref_t2>,
                                             ::std::convertible_to<t_type, com_ref_t1>,
                                             ::std::convertible_to<u_type, com_ref_t1>>;
  };
} // namespace concepts_helper

/**
 * @brief The concept common_reference_with<t_type, u_type> specifies that two types t_type and u_type share a
 * common reference type (as computed by common_reference_t) to which both can be converted.
 *
 * @tparam t_type Type to test.
 * @tparam u_type Type to test.
 */
template<class t_type, class u_type>
using common_reference_with = typename concepts_helper::common_reference_with_impl<t_type, u_type>::type;
} // namespace std

#endif /* PSTL_COMMON_REFERENCE_WITH_H */
