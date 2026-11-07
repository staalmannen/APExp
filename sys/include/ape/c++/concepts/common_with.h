// ***************************************************************************
// * Copyright (c) 2024-2025 Paragon Software Group
// *
// * Project="Paragon Portable STL" File="common_with.h"
// * 
// * This program and the accompanying materials are made available under the
// * terms of the MIT License which is available at
// * https://opensource.org/licenses/MIT.
// * 
// * SPDX-License-Identifier: MIT
// ***************************************************************************
#ifndef PSTL_COMMON_WITH_H
#define PSTL_COMMON_WITH_H

#include "../common/size_t.h"
#include "../metaprogramming/logical_operator/conjunction.h"
#include "../metaprogramming/other_transformations/common_reference.h"
#include "../metaprogramming/other_transformations/is_detected.h"
#include "../metaprogramming/reference_modifications/add_lvalue_reference.h"
#include "../utility/general/declval.h"
#include "common_reference_with.h"
#include "same_as.h"

namespace std {
namespace concepts_helper {
  /**
   * @brief Helper class tot check base requirements for tested types.
   *
   * @tparam t_type1 Tested type.
   * @tparam t_type2 Tested type.
   */
  template<class t_type1, class t_type2> class common_with_req final {
    /**
     * @brief Test function.
     *
     * @tparam T1
     * @tparam T2
     * @return ::std::true_type
     */
    template<class T1, class T2>
    static auto test(
      ::std::size_t) -> decltype(static_cast<::std::common_type_t<T1, T2>>(::std::declval<T1>()),
                                          static_cast<::std::common_type_t<T1, T2>>(::std::declval<T2>()),
                                          ::std::true_type{});

    /**
     * @brief Test function.
     * @return ::std::false_type
     */
    template<class, class> static auto test(...) -> ::std::false_type;

  public:
    /**
     * @brief Result type.
     */
    using type = decltype(test<t_type1, t_type2>(0U));
  };

  /**
   * @brief Implementation of the 'concept' common_with.
   * Primary template.
   * @tparam t_type1 Tested type.
   * @tparam t_type2 Tested type.
   */
  template<class t_type1, class t_type2, class = typename common_with_req<t_type1, t_type2>::type>
  class common_with_impl final {
  public:
    /**
     * @brief Result type.
     */
    using type = ::std::conjunction<
      ::std::same_as<::std::common_type_t<t_type1, t_type2>, ::std::common_type_t<t_type2, t_type1>>,
      ::std::common_reference_with<::std::add_lvalue_reference_t<t_type1 const>,
                                            ::std::add_lvalue_reference_t<t_type2 const>>,
      ::std::common_reference_with<
        ::std::add_lvalue_reference_t<::std::common_type_t<t_type1, t_type2>>,
        ::std::common_reference_t<::std::add_lvalue_reference_t<t_type1 const>,
                                           ::std::add_lvalue_reference_t<t_type2 const>>>>;
  };

  /**
   * @brief Implementation of the 'concept' common_with.
   *
   * @tparam t_type1 Tested type.
   * @tparam t_type2 Tested type.
   */
  template<class t_type1, class t_type2> class common_with_impl<t_type1, t_type2, ::std::false_type> final {
  public:
    /**
     * @brief Result type.
     */
    using type = ::std::false_type;
  };
} // namespace concepts_helper

/**
 * @brief The 'concept' common_with<t_type1, t_type2> specifies that two types t_type1 and t_type2 share a common type
 * (as computed by common_type_t) to which both can be converted.
 *
 * @tparam t_type1 Tested type.
 * @tparam t_type2 Tested type.
 */
template<class t_type1, class t_type2>
using common_with = typename concepts_helper::common_with_impl<t_type1, t_type2>::type;

} // namespace std

#endif /* PSTL_COMMON_WITH_H */
