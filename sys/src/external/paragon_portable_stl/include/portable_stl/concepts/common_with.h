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

namespace portable_stl {
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
     * @return ::portable_stl::true_type
     */
    template<class T1, class T2>
    static auto test(
      ::portable_stl::size_t) -> decltype(static_cast<::portable_stl::common_type_t<T1, T2>>(::portable_stl::declval<T1>()),
                                          static_cast<::portable_stl::common_type_t<T1, T2>>(::portable_stl::declval<T2>()),
                                          ::portable_stl::true_type{});

    /**
     * @brief Test function.
     * @return ::portable_stl::false_type
     */
    template<class, class> static auto test(...) -> ::portable_stl::false_type;

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
    using type = ::portable_stl::conjunction<
      ::portable_stl::same_as<::portable_stl::common_type_t<t_type1, t_type2>, ::portable_stl::common_type_t<t_type2, t_type1>>,
      ::portable_stl::common_reference_with<::portable_stl::add_lvalue_reference_t<t_type1 const>,
                                            ::portable_stl::add_lvalue_reference_t<t_type2 const>>,
      ::portable_stl::common_reference_with<
        ::portable_stl::add_lvalue_reference_t<::portable_stl::common_type_t<t_type1, t_type2>>,
        ::portable_stl::common_reference_t<::portable_stl::add_lvalue_reference_t<t_type1 const>,
                                           ::portable_stl::add_lvalue_reference_t<t_type2 const>>>>;
  };

  /**
   * @brief Implementation of the 'concept' common_with.
   *
   * @tparam t_type1 Tested type.
   * @tparam t_type2 Tested type.
   */
  template<class t_type1, class t_type2> class common_with_impl<t_type1, t_type2, ::portable_stl::false_type> final {
  public:
    /**
     * @brief Result type.
     */
    using type = ::portable_stl::false_type;
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

} // namespace portable_stl

#endif /* PSTL_COMMON_WITH_H */
