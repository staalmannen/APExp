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

namespace portable_stl {

namespace concepts_helper {
  /**
   * @brief Implementation class.
   */
  template<class, class, class = void> class common_reference_with_impl final {
  public:
    /**
     * @brief Result.
     */
    using type = ::portable_stl::false_type;
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
                                   ::portable_stl::void_t<::portable_stl::common_reference_t<t_type, u_type>,
                                                          ::portable_stl::common_reference_t<u_type, t_type>>>
    final {
    /**
     * @brief Helper type alias.
     */
    using com_ref_t1 = ::portable_stl::common_reference_t<t_type, u_type>;
    /**
     * @brief Helper type alias.
     */
    using com_ref_t2 = ::portable_stl::common_reference_t<u_type, t_type>;

  public:
    /**
     * @brief Result.
     */
    using type = ::portable_stl::conjunction<::portable_stl::same_as<com_ref_t1, com_ref_t2>,
                                             ::portable_stl::convertible_to<t_type, com_ref_t1>,
                                             ::portable_stl::convertible_to<u_type, com_ref_t1>>;
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
} // namespace portable_stl

#endif /* PSTL_COMMON_REFERENCE_WITH_H */
